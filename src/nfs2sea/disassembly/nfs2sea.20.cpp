#include "nfs2sea.h"
#include <lib/thread.h>

namespace nfs2sea
{

/* align: skip 0x90 */
void Application::sub_489be4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00489be4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00489be5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00489be6  81ec04010000           -sub esp, 0x104
    (cpu.esp) -= x86::reg32(x86::sreg32(260 /*0x104*/));
    // 00489bec  8b9c2410010000         -mov ebx, dword ptr [esp + 0x110]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(272) /* 0x110 */);
    // 00489bf3  8b942414010000         -mov edx, dword ptr [esp + 0x114]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 00489bfa  833dfc9a4d0002         +cmp dword ptr [0x4d9afc], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5085948) /* 0x4d9afc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00489c01  0f8c8b000000           -jl 0x489c92
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00489c92;
    }
    // 00489c07  833df89a4d0000         +cmp dword ptr [0x4d9af8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5085944) /* 0x4d9af8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00489c0e  750a                   -jne 0x489c1a
    if (!cpu.flags.zf)
    {
        goto L_0x00489c1a;
    }
    // 00489c10  e853e7ffff             -call 0x488368
    cpu.esp -= 4;
    sub_488368(app, cpu);
    if (cpu.terminate) return;
    // 00489c15  a3f89a4d00             -mov dword ptr [0x4d9af8], eax
    app->getMemory<x86::reg32>(x86::reg32(5085944) /* 0x4d9af8 */) = cpu.eax;
L_0x00489c1a:
    // 00489c1a  a1f89a4d00             -mov eax, dword ptr [0x4d9af8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5085944) /* 0x4d9af8 */);
    // 00489c1f  e894e7ffff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 00489c24  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00489c26  746a                   -je 0x489c92
    if (cpu.flags.zf)
    {
        goto L_0x00489c92;
    }
    // 00489c28  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00489c2a  7c23                   -jl 0x489c4f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00489c4f;
    }
    // 00489c2c  83fb50                 +cmp ebx, 0x50
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(80 /*0x50*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00489c2f  7d1e                   -jge 0x489c4f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00489c4f;
    }
    // 00489c31  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00489c33  7c1a                   -jl 0x489c4f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00489c4f;
    }
    // 00489c35  83fa19                 +cmp edx, 0x19
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
    // 00489c38  7d15                   -jge 0x489c4f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00489c4f;
    }
    // 00489c3a  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00489c41  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00489c43  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00489c46  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00489c48  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 00489c4a  a3089b4d00             -mov dword ptr [0x4d9b08], eax
    app->getMemory<x86::reg32>(x86::reg32(5085960) /* 0x4d9b08 */) = cpu.eax;
L_0x00489c4f:
    // 00489c4f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00489c50  8d842420010000         -lea eax, [esp + 0x120]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(288) /* 0x120 */);
    // 00489c57  8d9c2404010000         -lea ebx, [esp + 0x104]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 00489c5e  8b94241c010000         -mov edx, dword ptr [esp + 0x11c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(284) /* 0x11c */);
    // 00489c65  89842404010000         -mov dword ptr [esp + 0x104], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */) = cpu.eax;
    // 00489c6c  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00489c70  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00489c72  e87d5f0100             -call 0x49fbf4
    cpu.esp -= 4;
    sub_49fbf4(app, cpu);
    if (cpu.terminate) return;
    // 00489c77  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00489c7b  89bc2404010000         -mov dword ptr [esp + 0x104], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */) = cpu.edi;
    // 00489c82  e829000000             -call 0x489cb0
    cpu.esp -= 4;
    sub_489cb0(app, cpu);
    if (cpu.terminate) return;
    // 00489c87  a1f89a4d00             -mov eax, dword ptr [0x4d9af8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5085944) /* 0x4d9af8 */);
    // 00489c8c  e83fe7ffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 00489c91  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00489c92:
    // 00489c92  81c404010000           -add esp, 0x104
    (cpu.esp) += x86::reg32(x86::sreg32(260 /*0x104*/));
    // 00489c98  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489c99  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489c9a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_489cb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00489cb0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00489cb1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489cb2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00489cb3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00489cb4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00489cb5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00489cb6  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00489cb9  8b1d089b4d00           -mov ebx, dword ptr [0x4d9b08]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5085960) /* 0x4d9b08 */);
    // 00489cbf  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00489cc1  833dfc9a4d0002         +cmp dword ptr [0x4d9afc], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5085948) /* 0x4d9afc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00489cc8  7d10                   -jge 0x489cda
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00489cda;
    }
L_0x00489cca:
    // 00489cca  8b1d089b4d00           -mov ebx, dword ptr [0x4d9b08]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5085960) /* 0x4d9b08 */);
    // 00489cd0  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00489cd3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489cd4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489cd5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489cd6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489cd7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489cd8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489cd9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00489cda:
    // 00489cda  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00489cdc  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00489cde  49                     -dec ecx
    (cpu.ecx)--;
    // 00489cdf  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00489ce1  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00489ce3  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 00489ce5  49                     -dec ecx
    (cpu.ecx)--;
    // 00489ce6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00489ce8  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 00489ceb  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00489ced  30c9                   -xor cl, cl
    cpu.cl ^= x86::reg8(x86::sreg8(cpu.cl));
    // 00489cef  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00489cf1  7ed7                   -jle 0x489cca
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00489cca;
    }
L_0x00489cf3:
    // 00489cf3  8b1d089b4d00           -mov ebx, dword ptr [0x4d9b08]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5085960) /* 0x4d9b08 */);
    // 00489cf9  80f90e                 +cmp cl, 0xe
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(14 /*0xe*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00489cfc  7441                   -je 0x489d3f
    if (cpu.flags.zf)
    {
        goto L_0x00489d3f;
    }
    // 00489cfe  8a0e                   -mov cl, byte ptr [esi]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi);
    // 00489d00  80f920                 +cmp cl, 0x20
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(32 /*0x20*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00489d03  7245                   -jb 0x489d4a
    if (cpu.flags.cf)
    {
        goto L_0x00489d4a;
    }
    // 00489d05  e8fa000000             -call 0x489e04
    cpu.esp -= 4;
    sub_489e04(app, cpu);
    if (cpu.terminate) return;
    // 00489d0a  8b1d089b4d00           -mov ebx, dword ptr [0x4d9b08]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5085960) /* 0x4d9b08 */);
    // 00489d10  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 00489d12  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 00489d14  a00d9b4d00             -mov al, byte ptr [0x4d9b0d]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5085965) /* 0x4d9b0d */);
    // 00489d19  88ca                   -mov dl, cl
    cpu.dl = cpu.cl;
    // 00489d1b  83c302                 -add ebx, 2
    (cpu.ebx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00489d1e  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 00489d21  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00489d23  8b15049b4d00           -mov edx, dword ptr [0x4d9b04]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5085956) /* 0x4d9b04 */);
    // 00489d29  6689441afe             -mov word ptr [edx + ebx - 2], ax
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(-2) /* -0x2 */ + cpu.ebx * 1) = cpu.ax;
L_0x00489d2e:
    // 00489d2e  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 00489d31  46                     -inc esi
    (cpu.esi)++;
    // 00489d32  47                     -inc edi
    (cpu.edi)++;
    // 00489d33  891d089b4d00           -mov dword ptr [0x4d9b08], ebx
    app->getMemory<x86::reg32>(x86::reg32(5085960) /* 0x4d9b08 */) = cpu.ebx;
    // 00489d39  39ef                   +cmp edi, ebp
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
    // 00489d3b  7d8d                   -jge 0x489cca
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00489cca;
    }
    // 00489d3d  ebb4                   -jmp 0x489cf3
    goto L_0x00489cf3;
L_0x00489d3f:
    // 00489d3f  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00489d41  30c9                   +xor cl, cl
    cpu.clear_co();
    cpu.set_szp((cpu.cl ^= x86::reg8(x86::sreg8(cpu.cl))));
    // 00489d43  a20d9b4d00             -mov byte ptr [0x4d9b0d], al
    app->getMemory<x86::reg8>(x86::reg32(5085965) /* 0x4d9b0d */) = cpu.al;
    // 00489d48  ebe4                   -jmp 0x489d2e
    goto L_0x00489d2e;
L_0x00489d4a:
    // 00489d4a  88ca                   -mov dl, cl
    cpu.dl = cpu.cl;
    // 00489d4c  80ea08                 -sub dl, 8
    (cpu.dl) -= x86::reg8(x86::sreg8(8 /*0x8*/));
    // 00489d4f  80fa04                 +cmp dl, 4
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
    // 00489d52  77da                   -ja 0x489d2e
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00489d2e;
    }
    // 00489d54  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00489d56  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 00489d58  ff24859c9c4800         -jmp dword ptr [eax*4 + 0x489c9c]
    cpu.ip = app->getMemory<x86::reg32>(4758684 + cpu.eax * 4); goto dynamic_jump;
  case 0x00489d5f:
    // 00489d5f  83fb02                 +cmp ebx, 2
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
    // 00489d62  7cca                   -jl 0x489d2e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00489d2e;
    }
    // 00489d64  83eb02                 +sub ebx, 2
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
    // 00489d67  ebc5                   -jmp 0x489d2e
    goto L_0x00489d2e;
  case 0x00489d69:
    // 00489d69  803d0e9b4d0001         +cmp byte ptr [0x4d9b0e], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5085966) /* 0x4d9b0e */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00489d70  76bc                   -jbe 0x489d2e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00489d2e;
    }
    // 00489d72  bda0000000             -mov ebp, 0xa0
    cpu.ebp = 160 /*0xa0*/;
    // 00489d77  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00489d79  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00489d7b  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00489d7e  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00489d80  0fafe8                 -imul ebp, eax
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 00489d83  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00489d85  29ea                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00489d87  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00489d89  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00489d8c  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00489d8e  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00489d90  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00489d92  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00489d94  8a1d0e9b4d00           -mov bl, byte ptr [0x4d9b0e]
    cpu.bl = app->getMemory<x86::reg8>(x86::reg32(5085966) /* 0x4d9b0e */);
    // 00489d9a  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00489d9d  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00489d9f  40                     -inc eax
    (cpu.eax)++;
    // 00489da0  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 00489da3  01c0                   +add eax, eax
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00489da5  8d1c28                 -lea ebx, [eax + ebp]
    cpu.ebx = x86::reg32(cpu.eax + cpu.ebp * 1);
    // 00489da8  eb84                   -jmp 0x489d2e
    goto L_0x00489d2e;
  case 0x00489daa:
    // 00489daa  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00489dac  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00489dae  bba0000000             -mov ebx, 0xa0
    cpu.ebx = 160 /*0xa0*/;
    // 00489db3  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00489db6  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00489db8  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00489dbb  69dba0000000           +imul ebx, ebx, 0xa0
    {
        x86::sreg64 tmp = x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(160 /*0xa0*/));
        cpu.ebx = static_cast<x86::reg32>(static_cast<x86::sreg32>(tmp));
        cpu.flags.of = cpu.flags.cf = (tmp != x86::sreg64(x86::sreg32(cpu.ebx)));
    }
    // 00489dc1  891d089b4d00           -mov dword ptr [0x4d9b08], ebx
    app->getMemory<x86::reg32>(x86::reg32(5085960) /* 0x4d9b08 */) = cpu.ebx;
    // 00489dc7  e838000000             -call 0x489e04
    cpu.esp -= 4;
    sub_489e04(app, cpu);
    if (cpu.terminate) return;
    // 00489dcc  8b1d089b4d00           -mov ebx, dword ptr [0x4d9b08]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5085960) /* 0x4d9b08 */);
    // 00489dd2  e957ffffff             -jmp 0x489d2e
    goto L_0x00489d2e;
  case 0x00489dd7:
    // 00489dd7  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00489dd9  8a1d0c9b4d00           -mov bl, byte ptr [0x4d9b0c]
    cpu.bl = app->getMemory<x86::reg8>(x86::reg32(5085964) /* 0x4d9b0c */);
    // 00489ddf  69dba0000000           +imul ebx, ebx, 0xa0
    {
        x86::sreg64 tmp = x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(160 /*0xa0*/));
        cpu.ebx = static_cast<x86::reg32>(static_cast<x86::sreg32>(tmp));
        cpu.flags.of = cpu.flags.cf = (tmp != x86::sreg64(x86::sreg32(cpu.ebx)));
    }
    // 00489de5  e944ffffff             -jmp 0x489d2e
    goto L_0x00489d2e;
  case 0x00489dea:
    // 00489dea  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00489dec  e897000000             -call 0x489e88
    cpu.esp -= 4;
    sub_489e88(app, cpu);
    if (cpu.terminate) return;
    // 00489df1  8a1d0c9b4d00           -mov bl, byte ptr [0x4d9b0c]
    cpu.bl = app->getMemory<x86::reg8>(x86::reg32(5085964) /* 0x4d9b0c */);
    // 00489df7  69dba0000000           +imul ebx, ebx, 0xa0
    {
        x86::sreg64 tmp = x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(160 /*0xa0*/));
        cpu.ebx = static_cast<x86::reg32>(static_cast<x86::sreg32>(tmp));
        cpu.flags.of = cpu.flags.cf = (tmp != x86::sreg64(x86::sreg32(cpu.ebx)));
    }
    // 00489dfd  e92cffffff             -jmp 0x489d2e
    goto L_0x00489d2e;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x8b 0xc0 */
void Application::sub_489e04(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00489e04  813d089b4d00a00f0000   +cmp dword ptr [0x4d9b08], 0xfa0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5085960) /* 0x4d9b08 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4000 /*0xfa0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00489e0e  7d01                   -jge 0x489e11
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00489e11;
    }
    // 00489e10  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00489e11:
    // 00489e11  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00489e12  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00489e13  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00489e14  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489e15  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00489e16  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00489e18  b919000000             -mov ecx, 0x19
    cpu.ecx = 25 /*0x19*/;
    // 00489e1d  8a150c9b4d00           -mov dl, byte ptr [0x4d9b0c]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5085964) /* 0x4d9b0c */);
    // 00489e23  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00489e25  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00489e2c  49                     -dec ecx
    (cpu.ecx)--;
    // 00489e2d  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00489e2f  8d1c8d00000000         -lea ebx, [ecx*4]
    cpu.ebx = x86::reg32(cpu.ecx * 4);
    // 00489e36  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00489e39  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00489e3b  8b0d049b4d00           -mov ecx, dword ptr [0x4d9b04]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5085956) /* 0x4d9b04 */);
    // 00489e41  42                     -inc edx
    (cpu.edx)++;
    // 00489e42  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00489e44  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00489e4b  8b35049b4d00           -mov esi, dword ptr [0x4d9b04]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5085956) /* 0x4d9b04 */);
    // 00489e51  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00489e53  c1e305                 -shl ebx, 5
    cpu.ebx <<= 5 /*0x5*/ % 32;
    // 00489e56  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00489e59  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00489e5b  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00489e5d  e89efcffff             -call 0x489b00
    cpu.esp -= 4;
    sub_489b00(app, cpu);
    if (cpu.terminate) return;
    // 00489e62  a1049b4d00             -mov eax, dword ptr [0x4d9b04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5085956) /* 0x4d9b04 */);
    // 00489e67  baa0000000             -mov edx, 0xa0
    cpu.edx = 160 /*0xa0*/;
    // 00489e6c  05000f0000             -add eax, 0xf00
    (cpu.eax) += x86::reg32(x86::sreg32(3840 /*0xf00*/));
    // 00489e71  bf000f0000             -mov edi, 0xf00
    cpu.edi = 3840 /*0xf00*/;
    // 00489e76  e811e6ffff             -call 0x48848c
    cpu.esp -= 4;
    sub_48848c(app, cpu);
    if (cpu.terminate) return;
    // 00489e7b  893d089b4d00           -mov dword ptr [0x4d9b08], edi
    app->getMemory<x86::reg32>(x86::reg32(5085960) /* 0x4d9b08 */) = cpu.edi;
    // 00489e81  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489e82  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489e83  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489e84  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489e85  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489e86  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_489e88(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00489e88  833dfc9a4d0002         +cmp dword ptr [0x4d9afc], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5085948) /* 0x4d9afc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00489e8f  7c46                   -jl 0x489ed7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00489ed7;
    }
    // 00489e91  833df89a4d0000         +cmp dword ptr [0x4d9af8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5085944) /* 0x4d9af8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00489e98  750a                   -jne 0x489ea4
    if (!cpu.flags.zf)
    {
        goto L_0x00489ea4;
    }
    // 00489e9a  e8c9e4ffff             -call 0x488368
    cpu.esp -= 4;
    sub_488368(app, cpu);
    if (cpu.terminate) return;
    // 00489e9f  a3f89a4d00             -mov dword ptr [0x4d9af8], eax
    app->getMemory<x86::reg32>(x86::reg32(5085944) /* 0x4d9af8 */) = cpu.eax;
L_0x00489ea4:
    // 00489ea4  a1f89a4d00             -mov eax, dword ptr [0x4d9af8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5085944) /* 0x4d9af8 */);
    // 00489ea9  e80ae5ffff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 00489eae  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00489eb0  7425                   -je 0x489ed7
    if (cpu.flags.zf)
    {
        goto L_0x00489ed7;
    }
    // 00489eb2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00489eb3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00489eb5:
    // 00489eb5  8b15049b4d00           -mov edx, dword ptr [0x4d9b04]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5085956) /* 0x4d9b04 */);
    // 00489ebb  c7040200000000         -mov dword ptr [edx + eax], 0
    app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 1) = 0 /*0x0*/;
    // 00489ec2  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00489ec5  3da00f0000             +cmp eax, 0xfa0
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4000 /*0xfa0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00489eca  7ce9                   -jl 0x489eb5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00489eb5;
    }
    // 00489ecc  a1f89a4d00             -mov eax, dword ptr [0x4d9af8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5085944) /* 0x4d9af8 */);
    // 00489ed1  e8fae4ffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 00489ed6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00489ed7:
    // 00489ed7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_489ed8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00489ed8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00489ed9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00489edb  833df89a4d0000         +cmp dword ptr [0x4d9af8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5085944) /* 0x4d9af8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00489ee2  750a                   -jne 0x489eee
    if (!cpu.flags.zf)
    {
        goto L_0x00489eee;
    }
    // 00489ee4  e87fe4ffff             -call 0x488368
    cpu.esp -= 4;
    sub_488368(app, cpu);
    if (cpu.terminate) return;
    // 00489ee9  a3f89a4d00             -mov dword ptr [0x4d9af8], eax
    app->getMemory<x86::reg32>(x86::reg32(5085944) /* 0x4d9af8 */) = cpu.eax;
L_0x00489eee:
    // 00489eee  a1f89a4d00             -mov eax, dword ptr [0x4d9af8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5085944) /* 0x4d9af8 */);
    // 00489ef3  e8c0e4ffff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 00489ef8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00489efa  7419                   -je 0x489f15
    if (cpu.flags.zf)
    {
        goto L_0x00489f15;
    }
    // 00489efc  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00489efe  7c0b                   -jl 0x489f0b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00489f0b;
    }
    // 00489f00  83fa18                 +cmp edx, 0x18
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00489f03  7f06                   -jg 0x489f0b
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00489f0b;
    }
    // 00489f05  88150c9b4d00           -mov byte ptr [0x4d9b0c], dl
    app->getMemory<x86::reg8>(x86::reg32(5085964) /* 0x4d9b0c */) = cpu.dl;
L_0x00489f0b:
    // 00489f0b  a1f89a4d00             -mov eax, dword ptr [0x4d9af8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5085944) /* 0x4d9af8 */);
    // 00489f10  e8bbe4ffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
L_0x00489f15:
    // 00489f15  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489f16  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_489f18(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00489f18  a20d9b4d00             -mov byte ptr [0x4d9b0d], al
    app->getMemory<x86::reg8>(x86::reg32(5085965) /* 0x4d9b0d */) = cpu.al;
    // 00489f1d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_489f20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00489f20  83f801                 +cmp eax, 1
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
    // 00489f23  7d01                   -jge 0x489f26
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00489f26;
    }
    // 00489f25  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00489f26:
    // 00489f26  a20e9b4d00             -mov byte ptr [0x4d9b0e], al
    app->getMemory<x86::reg8>(x86::reg32(5085966) /* 0x4d9b0e */) = cpu.al;
    // 00489f2b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_489f2c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00489f2c  c1e00f                 -shl eax, 0xf
    cpu.eax <<= 15 /*0xf*/ % 32;
    // 00489f2f  0500000b00             -add eax, 0xb0000
    (cpu.eax) += x86::reg32(x86::sreg32(720896 /*0xb0000*/));
    // 00489f34  a3049b4d00             -mov dword ptr [0x4d9b04], eax
    app->getMemory<x86::reg32>(x86::reg32(5085956) /* 0x4d9b04 */) = cpu.eax;
    // 00489f39  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_489f3c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00489f3c  c60000                 -mov byte ptr [eax], 0
    app->getMemory<x86::reg8>(cpu.eax) = 0 /*0x0*/;
    // 00489f3f  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
    // 00489f42  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_489f50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00489f50  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00489f51  bad0df4c00             -mov edx, 0x4cdfd0
    cpu.edx = 5038032 /*0x4cdfd0*/;
    // 00489f56  e805000000             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 00489f5b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489f5c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_489f60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00489f60  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00489f61  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489f62  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00489f64  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00489f66  e865040000             -call 0x48a3d0
    cpu.esp -= 4;
    sub_48a3d0(app, cpu);
    if (cpu.terminate) return;
    // 00489f6b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00489f6d  7508                   -jne 0x489f77
    if (!cpu.flags.zf)
    {
        goto L_0x00489f77;
    }
L_0x00489f6f:
    // 00489f6f  b8feffffff             -mov eax, 0xfffffffe
    cpu.eax = 4294967294 /*0xfffffffe*/;
    // 00489f74  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489f75  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489f76  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00489f77:
    // 00489f77  8b15e8894d00           -mov edx, dword ptr [0x4d89e8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5081576) /* 0x4d89e8 */);
    // 00489f7d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00489f7f  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00489f81  e826020000             -call 0x48a1ac
    cpu.esp -= 4;
    sub_48a1ac(app, cpu);
    if (cpu.terminate) return;
    // 00489f86  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00489f88  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00489f8a  7405                   -je 0x489f91
    if (cpu.flags.zf)
    {
        goto L_0x00489f91;
    }
    // 00489f8c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00489f8e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489f8f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489f90  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00489f91:
    // 00489f91  bae0df4c00             -mov edx, 0x4cdfe0
    cpu.edx = 5038048 /*0x4cdfe0*/;
    // 00489f96  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00489f98  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00489f9a  e831040000             -call 0x48a3d0
    cpu.esp -= 4;
    sub_48a3d0(app, cpu);
    if (cpu.terminate) return;
    // 00489f9f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00489fa1  74cc                   -je 0x489f6f
    if (cpu.flags.zf)
    {
        goto L_0x00489f6f;
    }
    // 00489fa3  8b15e8894d00           -mov edx, dword ptr [0x4d89e8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5081576) /* 0x4d89e8 */);
    // 00489fa9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00489fab  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00489fad  e8fa010000             -call 0x48a1ac
    cpu.esp -= 4;
    sub_48a1ac(app, cpu);
    if (cpu.terminate) return;
    // 00489fb2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00489fb4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00489fb6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489fb7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489fb8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_489fbc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00489fbc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00489fbd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489fbe  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00489fbf  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00489fc1  baecdf4c00             -mov edx, 0x4cdfec
    cpu.edx = 5038060 /*0x4cdfec*/;
    // 00489fc6  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00489fc8  e803040000             -call 0x48a3d0
    cpu.esp -= 4;
    sub_48a3d0(app, cpu);
    if (cpu.terminate) return;
    // 00489fcd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00489fcf  7509                   -jne 0x489fda
    if (!cpu.flags.zf)
    {
        goto L_0x00489fda;
    }
    // 00489fd1  b8feffffff             -mov eax, 0xfffffffe
    cpu.eax = 4294967294 /*0xfffffffe*/;
    // 00489fd6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489fd7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489fd8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489fd9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00489fda:
    // 00489fda  8b15e8894d00           -mov edx, dword ptr [0x4d89e8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5081576) /* 0x4d89e8 */);
    // 00489fe0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00489fe2  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00489fe4  e8c3010000             -call 0x48a1ac
    cpu.esp -= 4;
    sub_48a1ac(app, cpu);
    if (cpu.terminate) return;
    // 00489fe9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489fea  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489feb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489fec  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_489ff0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00489ff0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00489ff1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489ff2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00489ff3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00489ff4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00489ff5  83ec50                 -sub esp, 0x50
    (cpu.esp) -= x86::reg32(x86::sreg32(80 /*0x50*/));
    // 00489ff8  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00489ffa  bef4df4c00             -mov esi, 0x4cdff4
    cpu.esi = 5038068 /*0x4cdff4*/;
    // 00489fff  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0048a001  e8b6ffffff             -call 0x489fbc
    cpu.esp -= 4;
    sub_489fbc(app, cpu);
    if (cpu.terminate) return;
    // 0048a006  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0048a007:
    // 0048a007  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0048a009  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0048a00b  3c00                   +cmp al, 0
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
    // 0048a00d  7410                   -je 0x48a01f
    if (cpu.flags.zf)
    {
        goto L_0x0048a01f;
    }
    // 0048a00f  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0048a012  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0048a015  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0048a018  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0048a01b  3c00                   +cmp al, 0
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
    // 0048a01d  75e8                   -jne 0x48a007
    if (!cpu.flags.zf)
    {
        goto L_0x0048a007;
    }
L_0x0048a01f:
    // 0048a01f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a020  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0048a022  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0048a024  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0048a029  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048a02a  2bc9                   +sub ecx, ecx
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
    // 0048a02c  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0048a02d  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 0048a02f  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0048a031  4f                     -dec edi
    (cpu.edi)--;
L_0x0048a032:
    // 0048a032  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0048a034  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0048a036  3c00                   +cmp al, 0
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
    // 0048a038  7410                   -je 0x48a04a
    if (cpu.flags.zf)
    {
        goto L_0x0048a04a;
    }
    // 0048a03a  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0048a03d  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0048a040  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0048a043  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0048a046  3c00                   +cmp al, 0
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
    // 0048a048  75e8                   -jne 0x48a032
    if (!cpu.flags.zf)
    {
        goto L_0x0048a032;
    }
L_0x0048a04a:
    // 0048a04a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a04b  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0048a04d  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048a04f  e87c030000             -call 0x48a3d0
    cpu.esp -= 4;
    sub_48a3d0(app, cpu);
    if (cpu.terminate) return;
    // 0048a054  83c450                 -add esp, 0x50
    (cpu.esp) += x86::reg32(x86::sreg32(80 /*0x50*/));
    // 0048a057  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a058  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a059  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a05a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a05b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a05c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48a060(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048a060  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048a061  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048a062  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048a063  83ec50                 -sub esp, 0x50
    (cpu.esp) -= x86::reg32(x86::sreg32(80 /*0x50*/));
    // 0048a066  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0048a068  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0048a06a  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0048a06c  e84bffffff             -call 0x489fbc
    cpu.esp -= 4;
    sub_489fbc(app, cpu);
    if (cpu.terminate) return;
    // 0048a071  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0048a072:
    // 0048a072  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0048a074  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0048a076  3c00                   +cmp al, 0
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
    // 0048a078  7410                   -je 0x48a08a
    if (cpu.flags.zf)
    {
        goto L_0x0048a08a;
    }
    // 0048a07a  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0048a07d  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0048a080  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0048a083  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0048a086  3c00                   +cmp al, 0
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
    // 0048a088  75e8                   -jne 0x48a072
    if (!cpu.flags.zf)
    {
        goto L_0x0048a072;
    }
L_0x0048a08a:
    // 0048a08a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a08b  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048a08d  7464                   -je 0x48a0f3
    if (cpu.flags.zf)
    {
        goto L_0x0048a0f3;
    }
    // 0048a08f  bef8df4c00             -mov esi, 0x4cdff8
    cpu.esi = 5038072 /*0x4cdff8*/;
L_0x0048a094:
    // 0048a094  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0048a096  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048a097  2bc9                   +sub ecx, ecx
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
    // 0048a099  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0048a09a  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 0048a09c  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0048a09e  4f                     -dec edi
    (cpu.edi)--;
L_0x0048a09f:
    // 0048a09f  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0048a0a1  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0048a0a3  3c00                   +cmp al, 0
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
    // 0048a0a5  7410                   -je 0x48a0b7
    if (cpu.flags.zf)
    {
        goto L_0x0048a0b7;
    }
    // 0048a0a7  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0048a0aa  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0048a0ad  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0048a0b0  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0048a0b3  3c00                   +cmp al, 0
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
    // 0048a0b5  75e8                   -jne 0x48a09f
    if (!cpu.flags.zf)
    {
        goto L_0x0048a09f;
    }
L_0x0048a0b7:
    // 0048a0b7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a0b8  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0048a0ba  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0048a0bc  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0048a0c1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048a0c2  2bc9                   +sub ecx, ecx
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
    // 0048a0c4  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0048a0c5  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 0048a0c7  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0048a0c9  4f                     -dec edi
    (cpu.edi)--;
L_0x0048a0ca:
    // 0048a0ca  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0048a0cc  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0048a0ce  3c00                   +cmp al, 0
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
    // 0048a0d0  7410                   -je 0x48a0e2
    if (cpu.flags.zf)
    {
        goto L_0x0048a0e2;
    }
    // 0048a0d2  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0048a0d5  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0048a0d8  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0048a0db  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0048a0de  3c00                   +cmp al, 0
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
    // 0048a0e0  75e8                   -jne 0x48a0ca
    if (!cpu.flags.zf)
    {
        goto L_0x0048a0ca;
    }
L_0x0048a0e2:
    // 0048a0e2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a0e3  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0048a0e5  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048a0e7  e8e4020000             -call 0x48a3d0
    cpu.esp -= 4;
    sub_48a3d0(app, cpu);
    if (cpu.terminate) return;
    // 0048a0ec  83c450                 +add esp, 0x50
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(80 /*0x50*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048a0ef  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a0f0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a0f1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a0f2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048a0f3:
    // 0048a0f3  befcdf4c00             -mov esi, 0x4cdffc
    cpu.esi = 5038076 /*0x4cdffc*/;
    // 0048a0f8  eb9a                   -jmp 0x48a094
    goto L_0x0048a094;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48a0fc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048a0fc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048a0fd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048a0fe  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048a0ff  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048a101  e8b6feffff             -call 0x489fbc
    cpu.esp -= 4;
    sub_489fbc(app, cpu);
    if (cpu.terminate) return;
    // 0048a106  baf4df4c00             -mov edx, 0x4cdff4
    cpu.edx = 5038068 /*0x4cdff4*/;
    // 0048a10b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048a10d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048a10f  e8bc020000             -call 0x48a3d0
    cpu.esp -= 4;
    sub_48a3d0(app, cpu);
    if (cpu.terminate) return;
    // 0048a114  8b15e8894d00           -mov edx, dword ptr [0x4d89e8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5081576) /* 0x4d89e8 */);
    // 0048a11a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048a11c  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048a11e  e889000000             -call 0x48a1ac
    cpu.esp -= 4;
    sub_48a1ac(app, cpu);
    if (cpu.terminate) return;
    // 0048a123  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a124  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a125  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a126  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48a128(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048a128  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048a129  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048a12a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048a12b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048a12d  e88afeffff             -call 0x489fbc
    cpu.esp -= 4;
    sub_489fbc(app, cpu);
    if (cpu.terminate) return;
    // 0048a132  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0048a137  ba00e04c00             -mov edx, 0x4ce000
    cpu.edx = 5038080 /*0x4ce000*/;
    // 0048a13c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048a13e  e88d020000             -call 0x48a3d0
    cpu.esp -= 4;
    sub_48a3d0(app, cpu);
    if (cpu.terminate) return;
    // 0048a143  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a144  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a145  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a146  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48a148(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048a148  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048a149  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048a14a  bb08e04c00             -mov ebx, 0x4ce008
    cpu.ebx = 5038088 /*0x4ce008*/;
    // 0048a14f  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 0048a154  e8a70e0000             -call 0x48b000
    cpu.esp -= 4;
    sub_48b000(app, cpu);
    if (cpu.terminate) return;
    // 0048a159  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a15a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a15b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48a15c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048a15c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048a15d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048a15e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048a160  a1e8894d00             -mov eax, dword ptr [0x4d89e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5081576) /* 0x4d89e8 */);
    // 0048a165  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048a167  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048a16a  c1e202                 +shl edx, 2
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
    // 0048a16d  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0048a16f  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 0048a172  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048a174  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048a176  e831000000             -call 0x48a1ac
    cpu.esp -= 4;
    sub_48a1ac(app, cpu);
    if (cpu.terminate) return;
    // 0048a17b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048a17d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048a17f  741e                   -je 0x48a19f
    if (cpu.flags.zf)
    {
        goto L_0x0048a19f;
    }
    // 0048a181  83f802                 +cmp eax, 2
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
    // 0048a184  7419                   -je 0x48a19f
    if (cpu.flags.zf)
    {
        goto L_0x0048a19f;
    }
    // 0048a186  83f8ff                 +cmp eax, -1
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
    // 0048a189  7414                   -je 0x48a19f
    if (cpu.flags.zf)
    {
        goto L_0x0048a19f;
    }
    // 0048a18b  83f801                 +cmp eax, 1
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
    // 0048a18e  740a                   -je 0x48a19a
    if (cpu.flags.zf)
    {
        goto L_0x0048a19a;
    }
    // 0048a190  83f805                 +cmp eax, 5
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
    // 0048a193  7405                   -je 0x48a19a
    if (cpu.flags.zf)
    {
        goto L_0x0048a19a;
    }
    // 0048a195  83f80a                 +cmp eax, 0xa
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
    // 0048a198  7c0a                   -jl 0x48a1a4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048a1a4;
    }
L_0x0048a19a:
    // 0048a19a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048a19c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a19d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a19e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048a19f:
    // 0048a19f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048a1a1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a1a2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a1a3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048a1a4:
    // 0048a1a4  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 0048a1a9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a1aa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a1ab  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48a1ac(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048a1ac  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048a1ad  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048a1ae  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048a1af  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048a1b0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048a1b1  83ec40                 -sub esp, 0x40
    (cpu.esp) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0048a1b4  89442438               -mov dword ptr [esp + 0x38], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 0048a1b8  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0048a1ba  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048a1bc  8b1d149b4d00           -mov ebx, dword ptr [0x4d9b14]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5085972) /* 0x4d9b14 */);
    // 0048a1c2  8954243c               -mov dword ptr [esp + 0x3c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.edx;
    // 0048a1c6  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0048a1c8  7518                   -jne 0x48a1e2
    if (!cpu.flags.zf)
    {
        goto L_0x0048a1e2;
    }
    // 0048a1ca  8b15e8894d00           -mov edx, dword ptr [0x4d89e8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5081576) /* 0x4d89e8 */);
    // 0048a1d0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048a1d2  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048a1d5  c1e202                 +shl edx, 2
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
    // 0048a1d8  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0048a1da  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 0048a1dd  a3149b4d00             -mov dword ptr [0x4d9b14], eax
    app->getMemory<x86::reg32>(x86::reg32(5085972) /* 0x4d9b14 */) = cpu.eax;
L_0x0048a1e2:
    // 0048a1e2  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0048a1e4  8935109c4d00           -mov dword ptr [0x4d9c10], esi
    app->getMemory<x86::reg32>(x86::reg32(5086224) /* 0x4d9c10 */) = cpu.esi;
    // 0048a1ea  a1c4155600             -mov eax, dword ptr [0x5615c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5641668) /* 0x5615c4 */);
    // 0048a1ef  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048a1f1  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0048a1f5  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0048a1f7  48                     -dec eax
    (cpu.eax)--;
    // 0048a1f8  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0048a1fa  89442434               -mov dword ptr [esp + 0x34], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.eax;
L_0x0048a1fe:
    // 0048a1fe  8b7c242c               -mov edi, dword ptr [esp + 0x2c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0048a202  a1c4155600             -mov eax, dword ptr [0x5615c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5641668) /* 0x5615c4 */);
    // 0048a207  39f8                   +cmp eax, edi
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
    // 0048a209  7c0e                   -jl 0x48a219
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048a219;
    }
    // 0048a20b  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0048a210  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0048a213  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a214  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a215  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a216  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a217  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a218  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048a219:
    // 0048a219  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0048a21b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048a21d  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0048a222  e8f980ffff             -call 0x482320
    cpu.esp -= 4;
    sub_482320(app, cpu);
    if (cpu.terminate) return;
    // 0048a227  8b442438               -mov eax, dword ptr [esp + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0048a22b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0048a22d  01eb                   -add ebx, ebp
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0048a22f  e8cc120000             -call 0x48b500
    cpu.esp -= 4;
    sub_48b500(app, cpu);
    if (cpu.terminate) return;
    // 0048a234  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048a236  0f846b010000           -je 0x48a3a7
    if (cpu.flags.zf)
    {
        goto L_0x0048a3a7;
    }
    // 0048a23c  ff442434               -inc dword ptr [esp + 0x34]
    (app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */))++;
    // 0048a240  8a242c                 -mov ah, byte ptr [esp + ebp]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esp + cpu.ebp * 1);
    // 0048a243  45                     -inc ebp
    (cpu.ebp)++;
    // 0048a244  80fc20                 +cmp ah, 0x20
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(32 /*0x20*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048a247  0f8384000000           -jae 0x48a2d1
    if (!cpu.flags.cf)
    {
        goto L_0x0048a2d1;
    }
    // 0048a24d  c6442cff5f             -mov byte ptr [esp + ebp - 1], 0x5f
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(-1) /* -0x1 */ + cpu.ebp * 1) = 95 /*0x5f*/;
L_0x0048a252:
    // 0048a252  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0048a254:
    // 0048a254  8b54243c               -mov edx, dword ptr [esp + 0x3c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0048a258  89442430               -mov dword ptr [esp + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 0048a25c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048a25e  0f8489000000           -je 0x48a2ed
    if (cpu.flags.zf)
    {
        goto L_0x0048a2ed;
    }
L_0x0048a264:
    // 0048a264  30ff                   -xor bh, bh
    cpu.bh ^= x86::reg8(x86::sreg8(cpu.bh));
    // 0048a266  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0048a268  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0048a26a  883c2c                 -mov byte ptr [esp + ebp], bh
    app->getMemory<x86::reg8>(cpu.esp + cpu.ebp * 1) = cpu.bh;
L_0x0048a26d:
    // 0048a26d  8b0d149c4d00           -mov ecx, dword ptr [0x4d9c14]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5086228) /* 0x4d9c14 */);
    // 0048a273  49                     -dec ecx
    (cpu.ecx)--;
    // 0048a274  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048a276  0f8cc1000000           -jl 0x48a33d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048a33d;
    }
    // 0048a27c  6bd90c                 -imul ebx, ecx, 0xc
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(12 /*0xc*/)));
    // 0048a27f  01f3                   -add ebx, esi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.esi));
L_0x0048a281:
    // 0048a281  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0048a283  8b931c9b4d00           -mov edx, dword ptr [ebx + 0x4d9b1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5085980) /* 0x4d9b1c */);
    // 0048a289  e8e3de0000             -call 0x498171
    cpu.esp -= 4;
    sub_498171(app, cpu);
    if (cpu.terminate) return;
    // 0048a28e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048a290  0f849b000000           -je 0x48a331
    if (cpu.flags.zf)
    {
        goto L_0x0048a331;
    }
    // 0048a296  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0048a298  0f8e64000000           -jle 0x48a302
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048a302;
    }
    // 0048a29e  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0048a2a3:
    // 0048a2a3  8b1d189c4d00           -mov ebx, dword ptr [0x4d9c18]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5086232) /* 0x4d9c18 */);
    // 0048a2a9  09c3                   -or ebx, eax
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0048a2ab  a1149b4d00             -mov eax, dword ptr [0x4d9b14]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5085972) /* 0x4d9b14 */);
    // 0048a2b0  891d189c4d00           -mov dword ptr [0x4d9c18], ebx
    app->getMemory<x86::reg32>(x86::reg32(5086232) /* 0x4d9c18 */) = cpu.ebx;
    // 0048a2b6  e8f980ffff             -call 0x4823b4
    cpu.esp -= 4;
    sub_4823b4(app, cpu);
    if (cpu.terminate) return;
    // 0048a2bb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048a2bd  0f8d43000000           -jge 0x48a306
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048a306;
    }
L_0x0048a2c3:
    // 0048a2c3  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 0048a2c8  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0048a2cb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a2cc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a2cd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a2ce  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a2cf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a2d0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048a2d1:
    // 0048a2d1  80fc30                 +cmp ah, 0x30
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048a2d4  0f8278ffffff           -jb 0x48a252
    if (cpu.flags.cf)
    {
        goto L_0x0048a252;
    }
    // 0048a2da  80fc39                 +cmp ah, 0x39
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(57 /*0x39*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048a2dd  0f876fffffff           -ja 0x48a252
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0048a252;
    }
    // 0048a2e3  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048a2e8  e967ffffff             -jmp 0x48a254
    goto L_0x0048a254;
L_0x0048a2ed:
    // 0048a2ed  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048a2ef  0f846fffffff           -je 0x48a264
    if (cpu.flags.zf)
    {
        goto L_0x0048a264;
    }
    // 0048a2f5  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0048a2f9  8944243c               -mov dword ptr [esp + 0x3c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.eax;
    // 0048a2fd  e962ffffff             -jmp 0x48a264
    goto L_0x0048a264;
L_0x0048a302:
    // 0048a302  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0048a304  eb9d                   -jmp 0x48a2a3
    goto L_0x0048a2a3;
L_0x0048a306:
    // 0048a306  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 0048a30d  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048a30f  8b14851c9b4d00         -mov edx, dword ptr [eax*4 + 0x4d9b1c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5085980) /* 0x4d9b1c */ + cpu.eax * 4);
    // 0048a316  8b0485249b4d00         -mov eax, dword ptr [eax*4 + 0x4d9b24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5085988) /* 0x4d9b24 */ + cpu.eax * 4);
    // 0048a31d  8915109c4d00           -mov dword ptr [0x4d9c10], edx
    app->getMemory<x86::reg32>(x86::reg32(5086224) /* 0x4d9c10 */) = cpu.edx;
    // 0048a323  e85c070100             -call 0x49aa84
    cpu.esp -= 4;
    sub_49aa84(app, cpu);
    if (cpu.terminate) return;
    // 0048a328  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0048a32b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a32c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a32d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a32e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a32f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a330  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048a331:
    // 0048a331  49                     -dec ecx
    (cpu.ecx)--;
    // 0048a332  83eb0c                 -sub ebx, 0xc
    (cpu.ebx) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0048a335  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048a337  0f8d44ffffff           -jge 0x48a281
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048a281;
    }
L_0x0048a33d:
    // 0048a33d  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048a340  47                     -inc edi
    (cpu.edi)++;
    // 0048a341  83fe08                 +cmp esi, 8
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
    // 0048a344  0f8c23ffffff           -jl 0x48a26d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048a26d;
    }
    // 0048a34a  8b74243c               -mov esi, dword ptr [esp + 0x3c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0048a34e  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048a350  7455                   -je 0x48a3a7
    if (cpu.flags.zf)
    {
        goto L_0x0048a3a7;
    }
    // 0048a352  837c243000             +cmp dword ptr [esp + 0x30], 0
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
    // 0048a357  754e                   -jne 0x48a3a7
    if (!cpu.flags.zf)
    {
        goto L_0x0048a3a7;
    }
    // 0048a359  833d189c4d0000         +cmp dword ptr [0x4d9c18], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5086232) /* 0x4d9c18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048a360  7445                   -je 0x48a3a7
    if (cpu.flags.zf)
    {
        goto L_0x0048a3a7;
    }
    // 0048a362  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048a364  e81b070100             -call 0x49aa84
    cpu.esp -= 4;
    sub_49aa84(app, cpu);
    if (cpu.terminate) return;
    // 0048a369  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048a36b  83f80a                 +cmp eax, 0xa
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
    // 0048a36e  7c4e                   -jl 0x48a3be
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048a3be;
    }
    // 0048a370  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x0048a375:
    // 0048a375  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 0048a37c  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048a37e  8b04851c9b4d00         -mov eax, dword ptr [eax*4 + 0x4d9b1c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5085980) /* 0x4d9b1c */ + cpu.eax * 4);
    // 0048a385  a3109c4d00             -mov dword ptr [0x4d9c10], eax
    app->getMemory<x86::reg32>(x86::reg32(5086224) /* 0x4d9c10 */) = cpu.eax;
L_0x0048a38a:
    // 0048a38a  a1149b4d00             -mov eax, dword ptr [0x4d9b14]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5085972) /* 0x4d9b14 */);
    // 0048a38f  e82080ffff             -call 0x4823b4
    cpu.esp -= 4;
    sub_4823b4(app, cpu);
    if (cpu.terminate) return;
    // 0048a394  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048a396  0f8c27ffffff           -jl 0x48a2c3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048a2c3;
    }
    // 0048a39c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048a39e  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0048a3a1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a3a2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a3a3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a3a4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a3a5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a3a6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048a3a7:
    // 0048a3a7  83fd29                 +cmp ebp, 0x29
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(41 /*0x29*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048a3aa  0f8c4efeffff           -jl 0x48a1fe
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048a1fe;
    }
    // 0048a3b0  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0048a3b5  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0048a3b8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a3b9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a3ba  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a3bb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a3bc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a3bd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048a3be:
    // 0048a3be  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048a3c0  7c04                   -jl 0x48a3c6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048a3c6;
    }
    // 0048a3c2  7db1                   -jge 0x48a375
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048a375;
    }
    // 0048a3c4  ebc4                   -jmp 0x48a38a
    goto L_0x0048a38a;
L_0x0048a3c6:
    // 0048a3c6  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 0048a3cb  ebbd                   -jmp 0x48a38a
    goto L_0x0048a38a;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48a3d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048a3d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048a3d1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048a3d2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048a3d3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048a3d4  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048a3d7  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0048a3d9  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0048a3dc  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0048a3de  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048a3e0  49                     -dec ecx
    (cpu.ecx)--;
    // 0048a3e1  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0048a3e3  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0048a3e5  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0048a3e7  49                     -dec ecx
    (cpu.ecx)--;
    // 0048a3e8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048a3ea  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0048a3ec  89150c9c4d00           -mov dword ptr [0x4d9c0c], edx
    app->getMemory<x86::reg32>(x86::reg32(5086220) /* 0x4d9c0c */) = cpu.edx;
    // 0048a3f2  83f931                 +cmp ecx, 0x31
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(49 /*0x31*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048a3f5  0f8fb5000000           -jg 0x48a4b0
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048a4b0;
    }
    // 0048a3fb  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0048a3fd  7407                   -je 0x48a406
    if (cpu.flags.zf)
    {
        goto L_0x0048a406;
    }
    // 0048a3ff  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048a401  e85a080000             -call 0x48ac60
    cpu.esp -= 4;
    sub_48ac60(app, cpu);
    if (cpu.terminate) return;
L_0x0048a406:
    // 0048a406  a1e8894d00             -mov eax, dword ptr [0x4d89e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5081576) /* 0x4d89e8 */);
    // 0048a40b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048a40d  b90a000000             -mov ecx, 0xa
    cpu.ecx = 10 /*0xa*/;
    // 0048a412  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048a415  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0048a417  e8987fffff             -call 0x4823b4
    cpu.esp -= 4;
    sub_4823b4(app, cpu);
    if (cpu.terminate) return;
    // 0048a41c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048a41e  0f8c8c000000           -jl 0x48a4b0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048a4b0;
    }
    // 0048a424  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048a426  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 0048a429  e812080000             -call 0x48ac40
    cpu.esp -= 4;
    sub_48ac40(app, cpu);
    if (cpu.terminate) return;
    // 0048a42e  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0048a430  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048a432  e8c90b0000             -call 0x48b000
    cpu.esp -= 4;
    sub_48b000(app, cpu);
    if (cpu.terminate) return;
    // 0048a437  bb10e04c00             -mov ebx, 0x4ce010
    cpu.ebx = 5038096 /*0x4ce010*/;
    // 0048a43c  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0048a441  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048a443  e8b80b0000             -call 0x48b000
    cpu.esp -= 4;
    sub_48b000(app, cpu);
    if (cpu.terminate) return;
    // 0048a448  a1c4155600             -mov eax, dword ptr [0x5615c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5641668) /* 0x5615c4 */);
    // 0048a44d  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048a44f  a1e8894d00             -mov eax, dword ptr [0x4d89e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5081576) /* 0x4d89e8 */);
    // 0048a454  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048a456  b905000000             -mov ecx, 5
    cpu.ecx = 5 /*0x5*/;
    // 0048a45b  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048a45e  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0048a460  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0048a462  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
L_0x0048a464:
    // 0048a464  a1c4155600             -mov eax, dword ptr [0x5615c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5641668) /* 0x5615c4 */);
    // 0048a469  39f8                   +cmp eax, edi
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
    // 0048a46b  7d4d                   -jge 0x48a4ba
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048a4ba;
    }
    // 0048a46d  833d0c9c4d0000         +cmp dword ptr [0x4d9c0c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5086220) /* 0x4d9c0c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048a474  7544                   -jne 0x48a4ba
    if (!cpu.flags.zf)
    {
        goto L_0x0048a4ba;
    }
    // 0048a476  bb84205600             -mov ebx, 0x562084
    cpu.ebx = 5644420 /*0x562084*/;
    // 0048a47b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048a47d  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0048a482  e8997effff             -call 0x482320
    cpu.esp -= 4;
    sub_482320(app, cpu);
    if (cpu.terminate) return;
    // 0048a487  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0048a489  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048a48b  01f3                   -add ebx, esi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0048a48d  e86e100000             -call 0x48b500
    cpu.esp -= 4;
    sub_48b500(app, cpu);
    if (cpu.terminate) return;
    // 0048a492  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048a494  30e4                   +xor ah, ah
    cpu.clear_co();
    cpu.set_szp((cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah))));
    // 0048a496  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0048a499  88a684205600           -mov byte ptr [esi + 0x562084], ah
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5644420) /* 0x562084 */) = cpu.ah;
    // 0048a49f  b884205600             -mov eax, 0x562084
    cpu.eax = 5644420 /*0x562084*/;
    // 0048a4a4  e8c8dc0000             -call 0x498171
    cpu.esp -= 4;
    sub_498171(app, cpu);
    if (cpu.terminate) return;
    // 0048a4a9  a30c9c4d00             -mov dword ptr [0x4d9c0c], eax
    app->getMemory<x86::reg32>(x86::reg32(5086220) /* 0x4d9c0c */) = cpu.eax;
    // 0048a4ae  ebb4                   -jmp 0x48a464
    goto L_0x0048a464;
L_0x0048a4b0:
    // 0048a4b0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048a4b2  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048a4b5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a4b6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a4b7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a4b8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a4b9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048a4ba:
    // 0048a4ba  833d0c9c4d0000         +cmp dword ptr [0x4d9c0c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5086220) /* 0x4d9c0c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048a4c1  74ed                   -je 0x48a4b0
    if (cpu.flags.zf)
    {
        goto L_0x0048a4b0;
    }
    // 0048a4c3  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048a4c8  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048a4cb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a4cc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a4cd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a4ce  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a4cf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48a4d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048a4d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048a4d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048a4d2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048a4d3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048a4d4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048a4d5  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048a4d7  833d149b4d0000         +cmp dword ptr [0x4d9b14], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5085972) /* 0x4d9b14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048a4de  7518                   -jne 0x48a4f8
    if (!cpu.flags.zf)
    {
        goto L_0x0048a4f8;
    }
    // 0048a4e0  8b15e8894d00           -mov edx, dword ptr [0x4d89e8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5081576) /* 0x4d89e8 */);
    // 0048a4e6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048a4e8  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048a4eb  c1e202                 +shl edx, 2
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
    // 0048a4ee  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0048a4f0  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 0048a4f3  a3149b4d00             -mov dword ptr [0x4d9b14], eax
    app->getMemory<x86::reg32>(x86::reg32(5085972) /* 0x4d9b14 */) = cpu.eax;
L_0x0048a4f8:
    // 0048a4f8  8b15e8894d00           -mov edx, dword ptr [0x4d89e8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5081576) /* 0x4d89e8 */);
    // 0048a4fe  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0048a505  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048a507  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048a509  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048a50c  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048a50e  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0048a510  e89f7effff             -call 0x4823b4
    cpu.esp -= 4;
    sub_4823b4(app, cpu);
    if (cpu.terminate) return;
    // 0048a515  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048a517  7d08                   -jge 0x48a521
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048a521;
    }
L_0x0048a519:
    // 0048a519  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048a51b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a51c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a51d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a51e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a51f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a520  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048a521:
    // 0048a521  bb14e04c00             -mov ebx, 0x4ce014
    cpu.ebx = 5038100 /*0x4ce014*/;
    // 0048a526  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 0048a52b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048a52d  e8ce0a0000             -call 0x48b000
    cpu.esp -= 4;
    sub_48b000(app, cpu);
    if (cpu.terminate) return;
    // 0048a532  8b15e8894d00           -mov edx, dword ptr [0x4d89e8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5081576) /* 0x4d89e8 */);
    // 0048a538  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0048a53f  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048a541  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048a543  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048a546  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048a548  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0048a54a  e8657effff             -call 0x4823b4
    cpu.esp -= 4;
    sub_4823b4(app, cpu);
    if (cpu.terminate) return;
    // 0048a54f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048a551  7cc6                   -jl 0x48a519
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048a519;
    }
    // 0048a553  8b1d189b4d00           -mov ebx, dword ptr [0x4d9b18]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5085976) /* 0x4d9b18 */);
    // 0048a559  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0048a55b  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048a55d  49                     -dec ecx
    (cpu.ecx)--;
    // 0048a55e  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0048a560  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0048a562  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0048a564  49                     -dec ecx
    (cpu.ecx)--;
    // 0048a565  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0048a567  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048a569  e8920a0000             -call 0x48b000
    cpu.esp -= 4;
    sub_48b000(app, cpu);
    if (cpu.terminate) return;
    // 0048a56e  a1149b4d00             -mov eax, dword ptr [0x4d9b14]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5085972) /* 0x4d9b14 */);
    // 0048a573  e83c7effff             -call 0x4823b4
    cpu.esp -= 4;
    sub_4823b4(app, cpu);
    if (cpu.terminate) return;
    // 0048a578  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048a57a  7c9d                   -jl 0x48a519
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048a519;
    }
    // 0048a57c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048a57e  ba18e04c00             -mov edx, 0x4ce018
    cpu.edx = 5038104 /*0x4ce018*/;
    // 0048a583  e8b8060000             -call 0x48ac40
    cpu.esp -= 4;
    sub_48ac40(app, cpu);
    if (cpu.terminate) return;
    // 0048a588  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048a58a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048a58c  e83ffeffff             -call 0x48a3d0
    cpu.esp -= 4;
    sub_48a3d0(app, cpu);
    if (cpu.terminate) return;
    // 0048a591  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048a593  7484                   -je 0x48a519
    if (cpu.flags.zf)
    {
        goto L_0x0048a519;
    }
    // 0048a595  8b15e8894d00           -mov edx, dword ptr [0x4d89e8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5081576) /* 0x4d89e8 */);
    // 0048a59b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048a59d  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048a59f  e808fcffff             -call 0x48a1ac
    cpu.esp -= 4;
    sub_48a1ac(app, cpu);
    if (cpu.terminate) return;
    // 0048a5a4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048a5a6  0f856dffffff           -jne 0x48a519
    if (!cpu.flags.zf)
    {
        goto L_0x0048a519;
    }
    // 0048a5ac  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048a5b1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a5b2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a5b3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a5b4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a5b5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a5b6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48a5b8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048a5b8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048a5b9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048a5ba  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048a5bb  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048a5bd  ba1ce04c00             -mov edx, 0x4ce01c
    cpu.edx = 5038108 /*0x4ce01c*/;
    // 0048a5c2  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048a5c4  e807feffff             -call 0x48a3d0
    cpu.esp -= 4;
    sub_48a3d0(app, cpu);
    if (cpu.terminate) return;
    // 0048a5c9  8b15e8894d00           -mov edx, dword ptr [0x4d89e8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5081576) /* 0x4d89e8 */);
    // 0048a5cf  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048a5d1  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048a5d3  e8d4fbffff             -call 0x48a1ac
    cpu.esp -= 4;
    sub_48a1ac(app, cpu);
    if (cpu.terminate) return;
    // 0048a5d8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a5d9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a5da  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a5db  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_48a5e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048a5e0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048a5e1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048a5e3  833d1c9c4d0000         +cmp dword ptr [0x4d9c1c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5086236) /* 0x4d9c1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048a5ea  7416                   -je 0x48a602
    if (cpu.flags.zf)
    {
        goto L_0x0048a602;
    }
L_0x0048a5ec:
    // 0048a5ec  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048a5ee  42                     -inc edx
    (cpu.edx)++;
    // 0048a5ef  e88c060000             -call 0x48ac80
    cpu.esp -= 4;
    sub_48ac80(app, cpu);
    if (cpu.terminate) return;
    // 0048a5f4  83fa10                 +cmp edx, 0x10
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
    // 0048a5f7  7d09                   -jge 0x48a602
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048a602;
    }
    // 0048a5f9  833d1c9c4d0000         +cmp dword ptr [0x4d9c1c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5086236) /* 0x4d9c1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048a600  75ea                   -jne 0x48a5ec
    if (!cpu.flags.zf)
    {
        goto L_0x0048a5ec;
    }
L_0x0048a602:
    // 0048a602  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a603  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48a604(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048a604  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048a605  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048a607  a1249c4d00             -mov eax, dword ptr [0x4d9c24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */);
    // 0048a60c  e8a7ddffff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 0048a611  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 0048a618  8b88c0205600           -mov ecx, dword ptr [eax + 0x5620c0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5644480) /* 0x5620c0 */);
    // 0048a61e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048a620  750c                   -jne 0x48a62e
    if (!cpu.flags.zf)
    {
        goto L_0x0048a62e;
    }
    // 0048a622  a1249c4d00             -mov eax, dword ptr [0x4d9c24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */);
    // 0048a627  e8a4ddffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0048a62c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a62d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048a62e:
    // 0048a62e  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 0048a630  8b15209c4d00           -mov edx, dword ptr [0x4d9c20]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5086240) /* 0x4d9c20 */);
    // 0048a636  b800215600             -mov eax, 0x562100
    cpu.eax = 5644544 /*0x562100*/;
    // 0048a63b  e850dcffff             -call 0x488290
    cpu.esp -= 4;
    sub_488290(app, cpu);
    if (cpu.terminate) return;
    // 0048a640  a1249c4d00             -mov eax, dword ptr [0x4d9c24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */);
    // 0048a645  e886ddffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0048a64a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a64b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48a64c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048a64c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048a64d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048a64e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048a64f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048a650  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048a651  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048a652  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048a654  a1249c4d00             -mov eax, dword ptr [0x4d9c24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */);
    // 0048a659  e85addffff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 0048a65e  837b0800               +cmp dword ptr [ebx + 8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048a662  7518                   -jne 0x48a67c
    if (!cpu.flags.zf)
    {
        goto L_0x0048a67c;
    }
    // 0048a664  8d7318                 -lea esi, [ebx + 0x18]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 0048a667  8d6b14                 -lea ebp, [ebx + 0x14]
    cpu.ebp = x86::reg32(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 0048a66a  8d7b2c                 -lea edi, [ebx + 0x2c]
    cpu.edi = x86::reg32(cpu.ebx + x86::reg32(44) /* 0x2c */);
L_0x0048a66d:
    // 0048a66d  8b5310                 -mov edx, dword ptr [ebx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 0048a670  81fa00020000           +cmp edx, 0x200
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(512 /*0x200*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048a676  0f8cbb000000           -jl 0x48a737
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048a737;
    }
L_0x0048a67c:
    // 0048a67c  8dbb3c020000           -lea edi, [ebx + 0x23c]
    cpu.edi = x86::reg32(cpu.ebx + x86::reg32(572) /* 0x23c */);
    // 0048a682  8dab38020000           -lea ebp, [ebx + 0x238]
    cpu.ebp = x86::reg32(cpu.ebx + x86::reg32(568) /* 0x238 */);
    // 0048a688  8db350020000           -lea esi, [ebx + 0x250]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(592) /* 0x250 */);
L_0x0048a68e:
    // 0048a68e  83bb2c02000000         +cmp dword ptr [ebx + 0x22c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(556) /* 0x22c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048a695  0f854c010000           -jne 0x48a7e7
    if (!cpu.flags.zf)
    {
        goto L_0x0048a7e7;
    }
    // 0048a69b  8b9334020000           -mov edx, dword ptr [ebx + 0x234]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(564) /* 0x234 */);
    // 0048a6a1  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048a6a3  0f8e3e010000           -jle 0x48a7e7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048a7e7;
    }
    // 0048a6a9  8b8330020000           -mov eax, dword ptr [ebx + 0x230]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(560) /* 0x230 */);
    // 0048a6af  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048a6b1  81fa00020000           +cmp edx, 0x200
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(512 /*0x200*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048a6b7  0f8e03010000           -jle 0x48a7c0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048a7c0;
    }
    // 0048a6bd  ba00020000             -mov edx, 0x200
    cpu.edx = 512 /*0x200*/;
    // 0048a6c2  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
L_0x0048a6c4:
    // 0048a6c4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048a6c5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048a6c6  c7833c02000000000000   -mov dword ptr [ebx + 0x23c], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(572) /* 0x23c */) = 0 /*0x0*/;
    // 0048a6d0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048a6d1  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0048a6d3  c7834002000000000000   -mov dword ptr [ebx + 0x240], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(576) /* 0x240 */) = 0 /*0x0*/;
    // 0048a6dd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048a6de  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0048a6e1  c7834402000000000000   -mov dword ptr [ebx + 0x244], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(580) /* 0x244 */) = 0 /*0x0*/;
    // 0048a6eb  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048a6ec  c7834802000000000000   -mov dword ptr [ebx + 0x248], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(584) /* 0x248 */) = 0 /*0x0*/;
    // 0048a6f6  2eff15b8454c00         -call dword ptr cs:[0x4c45b8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998584) /* 0x4c45b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048a6fd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048a6ff  0f84c6000000           -je 0x48a7cb
    if (cpu.flags.zf)
    {
        goto L_0x0048a7cb;
    }
    // 0048a705  8b8338020000           -mov eax, dword ptr [ebx + 0x238]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(568) /* 0x238 */);
    // 0048a70b  8b9334020000           -mov edx, dword ptr [ebx + 0x234]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(564) /* 0x234 */);
    // 0048a711  8b8b38020000           -mov ecx, dword ptr [ebx + 0x238]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(568) /* 0x238 */);
    // 0048a717  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0048a719  8b8330020000           -mov eax, dword ptr [ebx + 0x230]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(560) /* 0x230 */);
    // 0048a71f  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048a721  899334020000           -mov dword ptr [ebx + 0x234], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(564) /* 0x234 */) = cpu.edx;
    // 0048a727  25ff010000             +and eax, 0x1ff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(511 /*0x1ff*/))));
    // 0048a72c  898330020000           -mov dword ptr [ebx + 0x230], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(560) /* 0x230 */) = cpu.eax;
    // 0048a732  e957ffffff             -jmp 0x48a68e
    goto L_0x0048a68e;
L_0x0048a737:
    // 0048a737  8b430c                 -mov eax, dword ptr [ebx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 0048a73a  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048a73c  25ff010000             -and eax, 0x1ff
    cpu.eax &= x86::reg32(x86::sreg32(511 /*0x1ff*/));
    // 0048a741  8b530c                 -mov edx, dword ptr [ebx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 0048a744  39d0                   +cmp eax, edx
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
    // 0048a746  7d4e                   -jge 0x48a796
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048a796;
    }
L_0x0048a748:
    // 0048a748  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0048a74a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048a74b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048a74c  c7431800000000         -mov dword ptr [ebx + 0x18], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 0048a753  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048a754  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 0048a756  c7431c00000000         -mov dword ptr [ebx + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 0048a75d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048a75e  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0048a761  c7432000000000         -mov dword ptr [ebx + 0x20], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 0048a768  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048a769  c7432400000000         -mov dword ptr [ebx + 0x24], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 0048a770  2eff1534454c00         -call dword ptr cs:[0x4c4534]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998452) /* 0x4c4534 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048a777  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048a779  7422                   -je 0x48a79d
    if (cpu.flags.zf)
    {
        goto L_0x0048a79d;
    }
    // 0048a77b  8b4314                 -mov eax, dword ptr [ebx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 0048a77e  8b4b10                 -mov ecx, dword ptr [ebx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 0048a781  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048a783  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0048a786  894b10                 -mov dword ptr [ebx + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0048a789  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048a78b  0f84dcfeffff           -je 0x48a66d
    if (cpu.flags.zf)
    {
        goto L_0x0048a66d;
    }
    // 0048a791  e9e6feffff             -jmp 0x48a67c
    goto L_0x0048a67c;
L_0x0048a796:
    // 0048a796  ba00020000             -mov edx, 0x200
    cpu.edx = 512 /*0x200*/;
    // 0048a79b  ebab                   -jmp 0x48a748
    goto L_0x0048a748;
L_0x0048a79d:
    // 0048a79d  2eff15c4444c00         -call dword ptr cs:[0x4c44c4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998340) /* 0x4c44c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048a7a4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048a7a6  750c                   -jne 0x48a7b4
    if (!cpu.flags.zf)
    {
        goto L_0x0048a7b4;
    }
L_0x0048a7a8:
    // 0048a7a8  c7430801000000         -mov dword ptr [ebx + 8], 1
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = 1 /*0x1*/;
    // 0048a7af  e9c8feffff             -jmp 0x48a67c
    goto L_0x0048a67c;
L_0x0048a7b4:
    // 0048a7b4  3de5030000             +cmp eax, 0x3e5
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(997 /*0x3e5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048a7b9  74ed                   -je 0x48a7a8
    if (cpu.flags.zf)
    {
        goto L_0x0048a7a8;
    }
    // 0048a7bb  e9bcfeffff             -jmp 0x48a67c
    goto L_0x0048a67c;
L_0x0048a7c0:
    // 0048a7c0  8b9334020000           -mov edx, dword ptr [ebx + 0x234]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(564) /* 0x234 */);
    // 0048a7c6  e9f9feffff             -jmp 0x48a6c4
    goto L_0x0048a6c4;
L_0x0048a7cb:
    // 0048a7cb  2eff15c4444c00         -call dword ptr cs:[0x4c44c4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998340) /* 0x4c44c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048a7d2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048a7d4  7407                   -je 0x48a7dd
    if (cpu.flags.zf)
    {
        goto L_0x0048a7dd;
    }
    // 0048a7d6  3de5030000             +cmp eax, 0x3e5
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(997 /*0x3e5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048a7db  750a                   -jne 0x48a7e7
    if (!cpu.flags.zf)
    {
        goto L_0x0048a7e7;
    }
L_0x0048a7dd:
    // 0048a7dd  c7832c02000001000000   -mov dword ptr [ebx + 0x22c], 1
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(556) /* 0x22c */) = 1 /*0x1*/;
L_0x0048a7e7:
    // 0048a7e7  a1249c4d00             -mov eax, dword ptr [0x4d9c24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */);
    // 0048a7ec  e8dfdbffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0048a7f1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a7f2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a7f3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a7f4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a7f5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a7f6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a7f7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48a7f8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048a7f8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048a7f9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048a7fa  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048a7fb  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048a7fe  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048a800  a1249c4d00             -mov eax, dword ptr [0x4d9c24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */);
    // 0048a805  e8aedbffff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 0048a80a  837b0800               +cmp dword ptr [ebx + 8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048a80e  751e                   -jne 0x48a82e
    if (!cpu.flags.zf)
    {
        goto L_0x0048a82e;
    }
L_0x0048a810:
    // 0048a810  83bb2c02000000         +cmp dword ptr [ebx + 0x22c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(556) /* 0x22c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048a817  0f856e000000           -jne 0x48a88b
    if (!cpu.flags.zf)
    {
        goto L_0x0048a88b;
    }
L_0x0048a81d:
    // 0048a81d  a1249c4d00             -mov eax, dword ptr [0x4d9c24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */);
    // 0048a822  e8a9dbffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0048a827  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048a82a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a82b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a82c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a82d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048a82e:
    // 0048a82e  8b4328                 -mov eax, dword ptr [ebx + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */);
    // 0048a831  e866daffff             -call 0x48829c
    cpu.esp -= 4;
    sub_48829c(app, cpu);
    if (cpu.terminate) return;
    // 0048a836  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048a838  74d6                   -je 0x48a810
    if (cpu.flags.zf)
    {
        goto L_0x0048a810;
    }
    // 0048a83a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048a83c  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048a840  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048a841  8d4318                 -lea eax, [ebx + 0x18]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 0048a844  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048a845  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0048a848  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048a849  2eff15e4444c00         -call dword ptr cs:[0x4c44e4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998372) /* 0x4c44e4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048a850  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048a852  7418                   -je 0x48a86c
    if (cpu.flags.zf)
    {
        goto L_0x0048a86c;
    }
    // 0048a854  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048a855  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048a859  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048a85b  750a                   -jne 0x48a867
    if (!cpu.flags.zf)
    {
        goto L_0x0048a867;
    }
L_0x0048a85d:
    // 0048a85d  c7430800000000         -mov dword ptr [ebx + 8], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0048a864  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a865  eba9                   -jmp 0x48a810
    goto L_0x0048a810;
L_0x0048a867:
    // 0048a867  017310                 +add dword ptr [ebx + 0x10], esi
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048a86a  ebf1                   -jmp 0x48a85d
    goto L_0x0048a85d;
L_0x0048a86c:
    // 0048a86c  2eff15c4444c00         -call dword ptr cs:[0x4c44c4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998340) /* 0x4c44c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048a873  3de5030000             +cmp eax, 0x3e5
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(997 /*0x3e5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048a878  750a                   -jne 0x48a884
    if (!cpu.flags.zf)
    {
        goto L_0x0048a884;
    }
    // 0048a87a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048a87f  894308                 -mov dword ptr [ebx + 8], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0048a882  eb8c                   -jmp 0x48a810
    goto L_0x0048a810;
L_0x0048a884:
    // 0048a884  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0048a886  894308                 -mov dword ptr [ebx + 8], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0048a889  eb85                   -jmp 0x48a810
    goto L_0x0048a810;
L_0x0048a88b:
    // 0048a88b  8b834c020000           -mov eax, dword ptr [ebx + 0x24c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(588) /* 0x24c */);
    // 0048a891  e806daffff             -call 0x48829c
    cpu.esp -= 4;
    sub_48829c(app, cpu);
    if (cpu.terminate) return;
    // 0048a896  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048a898  7483                   -je 0x48a81d
    if (cpu.flags.zf)
    {
        goto L_0x0048a81d;
    }
    // 0048a89a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048a89c  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048a8a0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048a8a1  8d833c020000           -lea eax, [ebx + 0x23c]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(572) /* 0x23c */);
    // 0048a8a7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048a8a8  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0048a8ab  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048a8ac  2eff15e4444c00         -call dword ptr cs:[0x4c44e4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998372) /* 0x4c44e4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048a8b3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048a8b5  743c                   -je 0x48a8f3
    if (cpu.flags.zf)
    {
        goto L_0x0048a8f3;
    }
    // 0048a8b7  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0048a8ba  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048a8bc  741a                   -je 0x48a8d8
    if (cpu.flags.zf)
    {
        goto L_0x0048a8d8;
    }
    // 0048a8be  299334020000           -sub dword ptr [ebx + 0x234], edx
    (app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(564) /* 0x234 */)) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048a8c4  8b8330020000           -mov eax, dword ptr [ebx + 0x230]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(560) /* 0x230 */);
    // 0048a8ca  030424                 -add eax, dword ptr [esp]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
    // 0048a8cd  25ff010000             -and eax, 0x1ff
    cpu.eax &= x86::reg32(x86::sreg32(511 /*0x1ff*/));
    // 0048a8d2  898330020000           -mov dword ptr [ebx + 0x230], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(560) /* 0x230 */) = cpu.eax;
L_0x0048a8d8:
    // 0048a8d8  c7832c02000000000000   -mov dword ptr [ebx + 0x22c], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(556) /* 0x22c */) = 0 /*0x0*/;
    // 0048a8e2  a1249c4d00             -mov eax, dword ptr [0x4d9c24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */);
    // 0048a8e7  e8e4daffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0048a8ec  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048a8ef  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a8f0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a8f1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a8f2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048a8f3:
    // 0048a8f3  2eff15c4444c00         -call dword ptr cs:[0x4c44c4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998340) /* 0x4c44c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048a8fa  3de5030000             +cmp eax, 0x3e5
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(997 /*0x3e5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048a8ff  751c                   -jne 0x48a91d
    if (!cpu.flags.zf)
    {
        goto L_0x0048a91d;
    }
    // 0048a901  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0048a906:
    // 0048a906  89832c020000           -mov dword ptr [ebx + 0x22c], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(556) /* 0x22c */) = cpu.eax;
    // 0048a90c  a1249c4d00             -mov eax, dword ptr [0x4d9c24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */);
    // 0048a911  e8badaffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0048a916  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048a919  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a91a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a91b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a91c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048a91d:
    // 0048a91d  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0048a91f  ebe5                   -jmp 0x48a906
    goto L_0x0048a906;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48a924(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048a924  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048a925  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048a926  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048a927  81ec84000000           -sub esp, 0x84
    (cpu.esp) -= x86::reg32(x86::sreg32(132 /*0x84*/));
    // 0048a92d  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0048a932  a1209c4d00             -mov eax, dword ptr [0x4d9c20]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5086240) /* 0x4d9c20 */);
    // 0048a937  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0048a93a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0048a93c:
    // 0048a93c  8b90c0205600           -mov edx, dword ptr [eax + 0x5620c0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5644480) /* 0x5620c0 */);
    // 0048a942  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048a944  7422                   -je 0x48a968
    if (cpu.flags.zf)
    {
        goto L_0x0048a968;
    }
    // 0048a946  837a0800               +cmp dword ptr [edx + 8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048a94a  7408                   -je 0x48a954
    if (cpu.flags.zf)
    {
        goto L_0x0048a954;
    }
    // 0048a94c  41                     -inc ecx
    (cpu.ecx)++;
    // 0048a94d  8b5a28                 -mov ebx, dword ptr [edx + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(40) /* 0x28 */);
    // 0048a950  895c8cfc               -mov dword ptr [esp + ecx*4 - 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(-4) /* -0x4 */ + cpu.ecx * 4) = cpu.ebx;
L_0x0048a954:
    // 0048a954  83ba2c02000000         +cmp dword ptr [edx + 0x22c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(556) /* 0x22c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048a95b  740b                   -je 0x48a968
    if (cpu.flags.zf)
    {
        goto L_0x0048a968;
    }
    // 0048a95d  41                     -inc ecx
    (cpu.ecx)++;
    // 0048a95e  8b924c020000           -mov edx, dword ptr [edx + 0x24c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(588) /* 0x24c */);
    // 0048a964  89548cfc               -mov dword ptr [esp + ecx*4 - 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(-4) /* -0x4 */ + cpu.ecx * 4) = cpu.edx;
L_0x0048a968:
    // 0048a968  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048a96b  83f840                 +cmp eax, 0x40
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
    // 0048a96e  75cc                   -jne 0x48a93c
    if (!cpu.flags.zf)
    {
        goto L_0x0048a93c;
    }
    // 0048a970  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0048a972  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048a974  e8cfd9ffff             -call 0x488348
    cpu.esp -= 4;
    sub_488348(app, cpu);
    if (cpu.terminate) return;
    // 0048a979  81c484000000           -add esp, 0x84
    (cpu.esp) += x86::reg32(x86::sreg32(132 /*0x84*/));
    // 0048a97f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a980  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a981  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a982  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48a984(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048a984  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048a985  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048a986  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048a987  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048a988  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048a989  e8eed8ffff             -call 0x48827c
    cpu.esp -= 4;
    sub_48827c(app, cpu);
    if (cpu.terminate) return;
    // 0048a98e  a3209c4d00             -mov dword ptr [0x4d9c20], eax
    app->getMemory<x86::reg32>(x86::reg32(5086240) /* 0x4d9c20 */) = cpu.eax;
    // 0048a993  833d1c9c4d0000         +cmp dword ptr [0x4d9c1c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5086236) /* 0x4d9c1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048a99a  0f8479000000           -je 0x48aa19
    if (cpu.flags.zf)
    {
        goto L_0x0048aa19;
    }
    // 0048a9a0  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x0048a9a2:
    // 0048a9a2  e87dffffff             -call 0x48a924
    cpu.esp -= 4;
    sub_48a924(app, cpu);
    if (cpu.terminate) return;
    // 0048a9a7  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
L_0x0048a9a9:
    // 0048a9a9  8b9ec0205600           -mov ebx, dword ptr [esi + 0x5620c0]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5644480) /* 0x5620c0 */);
    // 0048a9af  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0048a9b1  7456                   -je 0x48aa09
    if (cpu.flags.zf)
    {
        goto L_0x0048aa09;
    }
    // 0048a9b3  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048a9b5  e83efeffff             -call 0x48a7f8
    cpu.esp -= 4;
    sub_48a7f8(app, cpu);
    if (cpu.terminate) return;
    // 0048a9ba  3b3b                   +cmp edi, dword ptr [ebx]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048a9bc  743c                   -je 0x48a9fa
    if (cpu.flags.zf)
    {
        goto L_0x0048a9fa;
    }
    // 0048a9be  a1249c4d00             -mov eax, dword ptr [0x4d9c24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */);
    // 0048a9c3  e8f0d9ffff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 0048a9c8  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0048a9ca  83f803                 +cmp eax, 3
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
    // 0048a9cd  7362                   -jae 0x48aa31
    if (!cpu.flags.cf)
    {
        goto L_0x0048aa31;
    }
    // 0048a9cf  83f802                 +cmp eax, 2
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
    // 0048a9d2  751a                   -jne 0x48a9ee
    if (!cpu.flags.zf)
    {
        goto L_0x0048a9ee;
    }
    // 0048a9d4  6a0a                   -push 0xa
    app->getMemory<x86::reg32>(cpu.esp-4) = 10 /*0xa*/;
    cpu.esp -= 4;
    // 0048a9d6  8b5304                 -mov edx, dword ptr [ebx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0048a9d9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048a9da  2eff152c454c00         -call dword ptr cs:[0x4c452c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998444) /* 0x4c452c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048a9e1  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048a9e3  e810feffff             -call 0x48a7f8
    cpu.esp -= 4;
    sub_48a7f8(app, cpu);
    if (cpu.terminate) return;
    // 0048a9e8  897b0c                 -mov dword ptr [ebx + 0xc], edi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 0048a9eb  897b10                 -mov dword ptr [ebx + 0x10], edi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.edi;
L_0x0048a9ee:
    // 0048a9ee  893b                   -mov dword ptr [ebx], edi
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edi;
    // 0048a9f0  a1249c4d00             -mov eax, dword ptr [0x4d9c24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */);
    // 0048a9f5  e8d6d9ffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
L_0x0048a9fa:
    // 0048a9fa  3bbec0205600           +cmp edi, dword ptr [esi + 0x5620c0]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5644480) /* 0x5620c0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048aa00  7407                   -je 0x48aa09
    if (cpu.flags.zf)
    {
        goto L_0x0048aa09;
    }
    // 0048aa02  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048aa04  e843fcffff             -call 0x48a64c
    cpu.esp -= 4;
    sub_48a64c(app, cpu);
    if (cpu.terminate) return;
L_0x0048aa09:
    // 0048aa09  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048aa0c  83fe40                 +cmp esi, 0x40
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(64 /*0x40*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048aa0f  7598                   -jne 0x48a9a9
    if (!cpu.flags.zf)
    {
        goto L_0x0048a9a9;
    }
    // 0048aa11  3b3d1c9c4d00           +cmp edi, dword ptr [0x4d9c1c]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5086236) /* 0x4d9c1c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048aa17  7589                   -jne 0x48a9a2
    if (!cpu.flags.zf)
    {
        goto L_0x0048a9a2;
    }
L_0x0048aa19:
    // 0048aa19  a1209c4d00             -mov eax, dword ptr [0x4d9c20]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5086240) /* 0x4d9c20 */);
    // 0048aa1e  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0048aa20  e833d9ffff             -call 0x488358
    cpu.esp -= 4;
    sub_488358(app, cpu);
    if (cpu.terminate) return;
    // 0048aa25  891d209c4d00           -mov dword ptr [0x4d9c20], ebx
    app->getMemory<x86::reg32>(x86::reg32(5086240) /* 0x4d9c20 */) = cpu.ebx;
    // 0048aa2b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048aa2c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048aa2d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048aa2e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048aa2f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048aa30  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048aa31:
    // 0048aa31  7642                   -jbe 0x48aa75
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0048aa75;
    }
    // 0048aa33  83f804                 +cmp eax, 4
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
    // 0048aa36  75b6                   -jne 0x48a9ee
    if (!cpu.flags.zf)
    {
        goto L_0x0048a9ee;
    }
    // 0048aa38  6a0f                   -push 0xf
    app->getMemory<x86::reg32>(cpu.esp-4) = 15 /*0xf*/;
    cpu.esp -= 4;
    // 0048aa3a  8b5304                 -mov edx, dword ptr [ebx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0048aa3d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048aa3e  2eff152c454c00         -call dword ptr cs:[0x4c452c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998444) /* 0x4c452c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048aa45  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048aa47  e8acfdffff             -call 0x48a7f8
    cpu.esp -= 4;
    sub_48a7f8(app, cpu);
    if (cpu.terminate) return;
    // 0048aa4c  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0048aa4f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048aa50  2eff1528444c00         -call dword ptr cs:[0x4c4428]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998184) /* 0x4c4428 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048aa57  8b4328                 -mov eax, dword ptr [ebx + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */);
    // 0048aa5a  e8f9d8ffff             -call 0x488358
    cpu.esp -= 4;
    sub_488358(app, cpu);
    if (cpu.terminate) return;
    // 0048aa5f  8b834c020000           -mov eax, dword ptr [ebx + 0x24c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(588) /* 0x24c */);
    // 0048aa65  e8eed8ffff             -call 0x488358
    cpu.esp -= 4;
    sub_488358(app, cpu);
    if (cpu.terminate) return;
    // 0048aa6a  89bec0205600           -mov dword ptr [esi + 0x5620c0], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5644480) /* 0x5620c0 */) = cpu.edi;
    // 0048aa70  e979ffffff             -jmp 0x48a9ee
    goto L_0x0048a9ee;
L_0x0048aa75:
    // 0048aa75  6a05                   -push 5
    app->getMemory<x86::reg32>(cpu.esp-4) = 5 /*0x5*/;
    cpu.esp -= 4;
    // 0048aa77  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0048aa7a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048aa7b  2eff152c454c00         -call dword ptr cs:[0x4c452c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998444) /* 0x4c452c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048aa82  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048aa84  e86ffdffff             -call 0x48a7f8
    cpu.esp -= 4;
    sub_48a7f8(app, cpu);
    if (cpu.terminate) return;
    // 0048aa89  89bb30020000           -mov dword ptr [ebx + 0x230], edi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(560) /* 0x230 */) = cpu.edi;
    // 0048aa8f  89bb34020000           -mov dword ptr [ebx + 0x234], edi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(564) /* 0x234 */) = cpu.edi;
    // 0048aa95  e954ffffff             -jmp 0x48a9ee
    goto L_0x0048a9ee;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48aa9c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048aa9c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048aa9e  7c10                   -jl 0x48aab0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048aab0;
    }
    // 0048aaa0  83f810                 +cmp eax, 0x10
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
    // 0048aaa3  7d0b                   -jge 0x48aab0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048aab0;
    }
    // 0048aaa5  833c85c020560000       +cmp dword ptr [eax*4 + 0x5620c0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5644480) /* 0x5620c0 */ + cpu.eax * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048aaad  7504                   -jne 0x48aab3
    if (!cpu.flags.zf)
    {
        goto L_0x0048aab3;
    }
    // 0048aaaf  90                     -nop 
    ;
L_0x0048aab0:
    // 0048aab0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048aab2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048aab3:
    // 0048aab3  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048aab8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48aabc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048aabc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048aabd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048aabe  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048aabf  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048aac1  833d249c4d0000         +cmp dword ptr [0x4d9c24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048aac8  750a                   -jne 0x48aad4
    if (!cpu.flags.zf)
    {
        goto L_0x0048aad4;
    }
    // 0048aaca  e899d8ffff             -call 0x488368
    cpu.esp -= 4;
    sub_488368(app, cpu);
    if (cpu.terminate) return;
    // 0048aacf  a3249c4d00             -mov dword ptr [0x4d9c24], eax
    app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */) = cpu.eax;
L_0x0048aad4:
    // 0048aad4  a1249c4d00             -mov eax, dword ptr [0x4d9c24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */);
    // 0048aad9  e8dad8ffff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 0048aade  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048aae0  e8b7ffffff             -call 0x48aa9c
    cpu.esp -= 4;
    sub_48aa9c(app, cpu);
    if (cpu.terminate) return;
    // 0048aae5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048aae7  750e                   -jne 0x48aaf7
    if (!cpu.flags.zf)
    {
        goto L_0x0048aaf7;
    }
L_0x0048aae9:
    // 0048aae9  a1249c4d00             -mov eax, dword ptr [0x4d9c24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */);
    // 0048aaee  e8ddd8ffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0048aaf3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048aaf4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048aaf5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048aaf6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048aaf7:
    // 0048aaf7  8b0495c0205600         -mov eax, dword ptr [edx*4 + 0x5620c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5644480) /* 0x5620c0 */ + cpu.edx * 4);
    // 0048aafe  6a05                   -push 5
    app->getMemory<x86::reg32>(cpu.esp-4) = 5 /*0x5*/;
    cpu.esp -= 4;
    // 0048ab00  8b5804                 -mov ebx, dword ptr [eax + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048ab03  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048ab04  2eff1554444c00         -call dword ptr cs:[0x4c4454]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998228) /* 0x4c4454 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048ab0b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048ab0d  75da                   -jne 0x48aae9
    if (!cpu.flags.zf)
    {
        goto L_0x0048aae9;
    }
    // 0048ab0f  e834d9ffff             -call 0x488448
    cpu.esp -= 4;
    sub_488448(app, cpu);
    if (cpu.terminate) return;
    // 0048ab14  a1249c4d00             -mov eax, dword ptr [0x4d9c24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */);
    // 0048ab19  e8b2d8ffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0048ab1e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ab1f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ab20  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ab21  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48ab24(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048ab24  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048ab25  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048ab26  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048ab27  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048ab29  833d249c4d0000         +cmp dword ptr [0x4d9c24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048ab30  750a                   -jne 0x48ab3c
    if (!cpu.flags.zf)
    {
        goto L_0x0048ab3c;
    }
    // 0048ab32  e831d8ffff             -call 0x488368
    cpu.esp -= 4;
    sub_488368(app, cpu);
    if (cpu.terminate) return;
    // 0048ab37  a3249c4d00             -mov dword ptr [0x4d9c24], eax
    app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */) = cpu.eax;
L_0x0048ab3c:
    // 0048ab3c  a1249c4d00             -mov eax, dword ptr [0x4d9c24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */);
    // 0048ab41  e872d8ffff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 0048ab46  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048ab48  e84fffffff             -call 0x48aa9c
    cpu.esp -= 4;
    sub_48aa9c(app, cpu);
    if (cpu.terminate) return;
    // 0048ab4d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048ab4f  750e                   -jne 0x48ab5f
    if (!cpu.flags.zf)
    {
        goto L_0x0048ab5f;
    }
L_0x0048ab51:
    // 0048ab51  a1249c4d00             -mov eax, dword ptr [0x4d9c24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */);
    // 0048ab56  e875d8ffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0048ab5b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ab5c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ab5d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ab5e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048ab5f:
    // 0048ab5f  8b0495c0205600         -mov eax, dword ptr [edx*4 + 0x5620c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5644480) /* 0x5620c0 */ + cpu.edx * 4);
    // 0048ab66  6a06                   -push 6
    app->getMemory<x86::reg32>(cpu.esp-4) = 6 /*0x6*/;
    cpu.esp -= 4;
    // 0048ab68  8b5804                 -mov ebx, dword ptr [eax + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048ab6b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048ab6c  2eff1554444c00         -call dword ptr cs:[0x4c4454]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998228) /* 0x4c4454 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048ab73  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048ab75  75da                   -jne 0x48ab51
    if (!cpu.flags.zf)
    {
        goto L_0x0048ab51;
    }
    // 0048ab77  e8ccd8ffff             -call 0x488448
    cpu.esp -= 4;
    sub_488448(app, cpu);
    if (cpu.terminate) return;
    // 0048ab7c  a1249c4d00             -mov eax, dword ptr [0x4d9c24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */);
    // 0048ab81  e84ad8ffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0048ab86  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ab87  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ab88  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ab89  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48ab8c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048ab8c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048ab8d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048ab8e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048ab8f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048ab90  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048ab93  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048ab95  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0048ab9a  833d249c4d0000         +cmp dword ptr [0x4d9c24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048aba1  750a                   -jne 0x48abad
    if (!cpu.flags.zf)
    {
        goto L_0x0048abad;
    }
    // 0048aba3  e8c0d7ffff             -call 0x488368
    cpu.esp -= 4;
    sub_488368(app, cpu);
    if (cpu.terminate) return;
    // 0048aba8  a3249c4d00             -mov dword ptr [0x4d9c24], eax
    app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */) = cpu.eax;
L_0x0048abad:
    // 0048abad  a1249c4d00             -mov eax, dword ptr [0x4d9c24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */);
    // 0048abb2  e801d8ffff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 0048abb7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048abb9  e8defeffff             -call 0x48aa9c
    cpu.esp -= 4;
    sub_48aa9c(app, cpu);
    if (cpu.terminate) return;
    // 0048abbe  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048abc0  7514                   -jne 0x48abd6
    if (!cpu.flags.zf)
    {
        goto L_0x0048abd6;
    }
    // 0048abc2  a1249c4d00             -mov eax, dword ptr [0x4d9c24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */);
    // 0048abc7  e804d8ffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0048abcc  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048abce  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048abd1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048abd2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048abd3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048abd4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048abd5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048abd6:
    // 0048abd6  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0048abd8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048abd9  8b0495c0205600         -mov eax, dword ptr [edx*4 + 0x5620c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5644480) /* 0x5620c0 */ + cpu.edx * 4);
    // 0048abe0  8b7004                 -mov esi, dword ptr [eax + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048abe3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048abe4  2eff157c444c00         -call dword ptr cs:[0x4c447c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998268) /* 0x4c447c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048abeb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048abed  751f                   -jne 0x48ac0e
    if (!cpu.flags.zf)
    {
        goto L_0x0048ac0e;
    }
    // 0048abef  f6042480               +test byte ptr [esp], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp) & 128 /*0x80*/));
    // 0048abf3  7432                   -je 0x48ac27
    if (cpu.flags.zf)
    {
        goto L_0x0048ac27;
    }
    // 0048abf5  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0048abfa  a1249c4d00             -mov eax, dword ptr [0x4d9c24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */);
    // 0048abff  e8ccd7ffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0048ac04  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048ac06  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048ac09  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ac0a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ac0b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ac0c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ac0d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048ac0e:
    // 0048ac0e  e835d8ffff             -call 0x488448
    cpu.esp -= 4;
    sub_488448(app, cpu);
    if (cpu.terminate) return;
    // 0048ac13  a1249c4d00             -mov eax, dword ptr [0x4d9c24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */);
    // 0048ac18  e8b3d7ffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0048ac1d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048ac1f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048ac22  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ac23  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ac24  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ac25  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ac26  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048ac27:
    // 0048ac27  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048ac29  a1249c4d00             -mov eax, dword ptr [0x4d9c24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */);
    // 0048ac2e  e89dd7ffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0048ac33  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048ac35  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048ac38  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ac39  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ac3a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ac3b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ac3c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48ac40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048ac40  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048ac41  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048ac43  e854feffff             -call 0x48aa9c
    cpu.esp -= 4;
    sub_48aa9c(app, cpu);
    if (cpu.terminate) return;
    // 0048ac48  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048ac4a  7502                   -jne 0x48ac4e
    if (!cpu.flags.zf)
    {
        goto L_0x0048ac4e;
    }
    // 0048ac4c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ac4d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048ac4e:
    // 0048ac4e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048ac4f  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 0048ac54  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048ac56  e8a9f9ffff             -call 0x48a604
    cpu.esp -= 4;
    sub_48a604(app, cpu);
    if (cpu.terminate) return;
    // 0048ac5b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ac5c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ac5d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48ac60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048ac60  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048ac61  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048ac63  e834feffff             -call 0x48aa9c
    cpu.esp -= 4;
    sub_48aa9c(app, cpu);
    if (cpu.terminate) return;
    // 0048ac68  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048ac6a  7502                   -jne 0x48ac6e
    if (!cpu.flags.zf)
    {
        goto L_0x0048ac6e;
    }
    // 0048ac6c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ac6d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048ac6e:
    // 0048ac6e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048ac6f  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 0048ac74  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048ac76  e889f9ffff             -call 0x48a604
    cpu.esp -= 4;
    sub_48a604(app, cpu);
    if (cpu.terminate) return;
    // 0048ac7b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ac7c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ac7d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48ac80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048ac80  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048ac81  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048ac82  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048ac84  833d249c4d0000         +cmp dword ptr [0x4d9c24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048ac8b  0f8480000000           -je 0x48ad11
    if (cpu.flags.zf)
    {
        goto L_0x0048ad11;
    }
L_0x0048ac91:
    // 0048ac91  a1249c4d00             -mov eax, dword ptr [0x4d9c24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */);
    // 0048ac96  e81dd7ffff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 0048ac9b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048ac9d  e8fafdffff             -call 0x48aa9c
    cpu.esp -= 4;
    sub_48aa9c(app, cpu);
    if (cpu.terminate) return;
    // 0048aca2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048aca4  0f8476000000           -je 0x48ad20
    if (cpu.flags.zf)
    {
        goto L_0x0048ad20;
    }
    // 0048acaa  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048acab  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048acac  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048acad  8d1c8d00000000         -lea ebx, [ecx*4]
    cpu.ebx = x86::reg32(cpu.ecx * 4);
    // 0048acb4  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 0048acb9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048acbb  8bb3c0205600           -mov esi, dword ptr [ebx + 0x5620c0]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5644480) /* 0x5620c0 */);
    // 0048acc1  e83ef9ffff             -call 0x48a604
    cpu.esp -= 4;
    sub_48a604(app, cpu);
    if (cpu.terminate) return;
    // 0048acc6  a1249c4d00             -mov eax, dword ptr [0x4d9c24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */);
    // 0048accb  e800d7ffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0048acd0  8bbbc0205600           -mov edi, dword ptr [ebx + 0x5620c0]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5644480) /* 0x5620c0 */);
    // 0048acd6  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0048acd8  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0048acda  7418                   -je 0x48acf4
    if (cpu.flags.zf)
    {
        goto L_0x0048acf4;
    }
    // 0048acdc  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
L_0x0048ace1:
    // 0048ace1  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048ace3  e824d3ffff             -call 0x48800c
    cpu.esp -= 4;
    sub_48800c(app, cpu);
    if (cpu.terminate) return;
    // 0048ace8  83bac020560000         +cmp dword ptr [edx + 0x5620c0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5644480) /* 0x5620c0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048acef  75f0                   -jne 0x48ace1
    if (!cpu.flags.zf)
    {
        goto L_0x0048ace1;
    }
    // 0048acf1  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x0048acf4:
    // 0048acf4  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048acf6  e87180ffff             -call 0x482d6c
    cpu.esp -= 4;
    sub_482d6c(app, cpu);
    if (cpu.terminate) return;
    // 0048acfb  ff0d1c9c4d00           -dec dword ptr [0x4d9c1c]
    (app->getMemory<x86::reg32>(x86::reg32(5086236) /* 0x4d9c1c */))--;
    // 0048ad01  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ad02  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ad03  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ad04  8b151c9c4d00           -mov edx, dword ptr [0x4d9c1c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5086236) /* 0x4d9c1c */);
    // 0048ad0a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048ad0c  7429                   -je 0x48ad37
    if (cpu.flags.zf)
    {
        goto L_0x0048ad37;
    }
    // 0048ad0e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ad0f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ad10  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048ad11:
    // 0048ad11  e852d6ffff             -call 0x488368
    cpu.esp -= 4;
    sub_488368(app, cpu);
    if (cpu.terminate) return;
    // 0048ad16  a3249c4d00             -mov dword ptr [0x4d9c24], eax
    app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */) = cpu.eax;
    // 0048ad1b  e971ffffff             -jmp 0x48ac91
    goto L_0x0048ac91;
L_0x0048ad20:
    // 0048ad20  a1249c4d00             -mov eax, dword ptr [0x4d9c24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */);
    // 0048ad25  e8a6d6ffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0048ad2a  8b151c9c4d00           -mov edx, dword ptr [0x4d9c1c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5086236) /* 0x4d9c1c */);
    // 0048ad30  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048ad32  7403                   -je 0x48ad37
    if (cpu.flags.zf)
    {
        goto L_0x0048ad37;
    }
    // 0048ad34  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ad35  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ad36  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048ad37:
    // 0048ad37  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048ad39  e8c6f8ffff             -call 0x48a604
    cpu.esp -= 4;
    sub_48a604(app, cpu);
    if (cpu.terminate) return;
    // 0048ad3e  a1249c4d00             -mov eax, dword ptr [0x4d9c24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */);
    // 0048ad43  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048ad45  e89ad6ffff             -call 0x4883e4
    cpu.esp -= 4;
    sub_4883e4(app, cpu);
    if (cpu.terminate) return;
    // 0048ad4a  890d249c4d00           -mov dword ptr [0x4d9c24], ecx
    app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */) = cpu.ecx;
    // 0048ad50  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ad51  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ad52  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48ad54(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048ad54  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048ad55  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048ad56  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048ad57  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048ad58  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048ad59  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0048ad5c  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048ad5e  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0048ad60  83f8ff                 +cmp eax, -1
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
    // 0048ad63  752e                   -jne 0x48ad93
    if (!cpu.flags.zf)
    {
        goto L_0x0048ad93;
    }
    // 0048ad65  be0f000000             -mov esi, 0xf
    cpu.esi = 15 /*0xf*/;
    // 0048ad6a  8b15fc205600           -mov edx, dword ptr [0x5620fc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5644540) /* 0x5620fc */);
    // 0048ad70  b83c000000             -mov eax, 0x3c
    cpu.eax = 60 /*0x3c*/;
    // 0048ad75  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048ad77  7412                   -je 0x48ad8b
    if (cpu.flags.zf)
    {
        goto L_0x0048ad8b;
    }
L_0x0048ad79:
    // 0048ad79  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048ad7b  7c0e                   -jl 0x48ad8b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048ad8b;
    }
    // 0048ad7d  8b88bc205600           -mov ecx, dword ptr [eax + 0x5620bc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5644476) /* 0x5620bc */);
    // 0048ad83  83e804                 -sub eax, 4
    (cpu.eax) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048ad86  4e                     -dec esi
    (cpu.esi)--;
    // 0048ad87  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048ad89  75ee                   -jne 0x48ad79
    if (!cpu.flags.zf)
    {
        goto L_0x0048ad79;
    }
L_0x0048ad8b:
    // 0048ad8b  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048ad8d  0f8ccf000000           -jl 0x48ae62
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048ae62;
    }
L_0x0048ad93:
    // 0048ad93  ff051c9c4d00           -inc dword ptr [0x4d9c1c]
    (app->getMemory<x86::reg32>(x86::reg32(5086236) /* 0x4d9c1c */))++;
    // 0048ad99  833d1c9c4d0001         +cmp dword ptr [0x4d9c1c], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5086236) /* 0x4d9c1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048ada0  0f84ca000000           -je 0x48ae70
    if (cpu.flags.zf)
    {
        goto L_0x0048ae70;
    }
L_0x0048ada6:
    // 0048ada6  bb00030000             -mov ebx, 0x300
    cpu.ebx = 768 /*0x300*/;
    // 0048adab  ba50040000             -mov edx, 0x450
    cpu.edx = 1104 /*0x450*/;
    // 0048adb0  b824e04c00             -mov eax, 0x4ce024
    cpu.eax = 5038116 /*0x4ce024*/;
    // 0048adb5  e84e7bffff             -call 0x482908
    cpu.esp -= 4;
    sub_482908(app, cpu);
    if (cpu.terminate) return;
    // 0048adba  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048adbc  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048adbe  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0048adc0  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048adc2  c7400800000000         -mov dword ptr [eax + 8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0048adc9  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048adcb  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0048adcd  897804                 -mov dword ptr [eax + 4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 0048add0  2eff152c444c00         -call dword ptr cs:[0x4c442c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998188) /* 0x4c442c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048add7  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048add9  c7430c00000000         -mov dword ptr [ebx + 0xc], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 0048ade0  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048ade2  c7431000000000         -mov dword ptr [ebx + 0x10], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 0048ade9  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0048adeb  c7832c02000000000000   -mov dword ptr [ebx + 0x22c], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(556) /* 0x22c */) = 0 /*0x0*/;
    // 0048adf5  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048adf7  894328                 -mov dword ptr [ebx + 0x28], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 0048adfa  2eff152c444c00         -call dword ptr cs:[0x4c442c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998188) /* 0x4c442c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048ae01  c7833002000000000000   -mov dword ptr [ebx + 0x230], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(560) /* 0x230 */) = 0 /*0x0*/;
    // 0048ae0b  ba14000000             -mov edx, 0x14
    cpu.edx = 20 /*0x14*/;
    // 0048ae10  89834c020000           -mov dword ptr [ebx + 0x24c], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(588) /* 0x24c */) = cpu.eax;
    // 0048ae16  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0048ae18  c7833402000000000000   -mov dword ptr [ebx + 0x234], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(564) /* 0x234 */) = 0 /*0x0*/;
    // 0048ae22  e865d6ffff             -call 0x48848c
    cpu.esp -= 4;
    sub_48848c(app, cpu);
    if (cpu.terminate) return;
    // 0048ae27  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0048ae29  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048ae2a  ba19000000             -mov edx, 0x19
    cpu.edx = 25 /*0x19*/;
    // 0048ae2f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048ae30  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0048ae34  2eff1540454c00         -call dword ptr cs:[0x4c4540]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998464) /* 0x4c4540 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048ae3b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048ae3d  7505                   -jne 0x48ae44
    if (!cpu.flags.zf)
    {
        goto L_0x0048ae44;
    }
    // 0048ae3f  e804d6ffff             -call 0x488448
    cpu.esp -= 4;
    sub_488448(app, cpu);
    if (cpu.terminate) return;
L_0x0048ae44:
    // 0048ae44  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0048ae49  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048ae4b  892cb5c0205600         -mov dword ptr [esi*4 + 0x5620c0], ebp
    app->getMemory<x86::reg32>(x86::reg32(5644480) /* 0x5620c0 */ + cpu.esi * 4) = cpu.ebp;
    // 0048ae52  e8adf7ffff             -call 0x48a604
    cpu.esp -= 4;
    sub_48a604(app, cpu);
    if (cpu.terminate) return;
    // 0048ae57  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048ae59  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0048ae5c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ae5d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ae5e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ae5f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ae60  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ae61  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048ae62:
    // 0048ae62  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0048ae67  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0048ae6a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ae6b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ae6c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ae6d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ae6e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ae6f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048ae70:
    // 0048ae70  b8e0a54800             -mov eax, 0x48a5e0
    cpu.eax = 4761056 /*0x48a5e0*/;
    // 0048ae75  e866ae0000             -call 0x495ce0
    cpu.esp -= 4;
    sub_495ce0(app, cpu);
    if (cpu.terminate) return;
    // 0048ae7a  833d249c4d0000         +cmp dword ptr [0x4d9c24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048ae81  750a                   -jne 0x48ae8d
    if (!cpu.flags.zf)
    {
        goto L_0x0048ae8d;
    }
    // 0048ae83  e8e0d4ffff             -call 0x488368
    cpu.esp -= 4;
    sub_488368(app, cpu);
    if (cpu.terminate) return;
    // 0048ae88  a3249c4d00             -mov dword ptr [0x4d9c24], eax
    app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */) = cpu.eax;
L_0x0048ae8d:
    // 0048ae8d  6800215600             -push 0x562100
    app->getMemory<x86::reg32>(cpu.esp-4) = 5644544 /*0x562100*/;
    cpu.esp -= 4;
    // 0048ae92  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 0048ae97  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0048ae9c  b884a94800             -mov eax, 0x48a984
    cpu.eax = 4761988 /*0x48a984*/;
    // 0048aea1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048aea3  e8a8d0ffff             -call 0x487f50
    cpu.esp -= 4;
    sub_487f50(app, cpu);
    if (cpu.terminate) return;
    // 0048aea8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048aeaa  0f85f6feffff           -jne 0x48ada6
    if (!cpu.flags.zf)
    {
        goto L_0x0048ada6;
    }
    // 0048aeb0  a1249c4d00             -mov eax, dword ptr [0x4d9c24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */);
    // 0048aeb5  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048aeb7  e828d5ffff             -call 0x4883e4
    cpu.esp -= 4;
    sub_4883e4(app, cpu);
    if (cpu.terminate) return;
    // 0048aebc  890d249c4d00           -mov dword ptr [0x4d9c24], ecx
    app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */) = cpu.ecx;
    // 0048aec2  a11c9c4d00             -mov eax, dword ptr [0x4d9c1c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5086236) /* 0x4d9c1c */);
    // 0048aec7  ff0d1c9c4d00           -dec dword ptr [0x4d9c1c]
    (app->getMemory<x86::reg32>(x86::reg32(5086236) /* 0x4d9c1c */))--;
    // 0048aecd  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0048aed2  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0048aed5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048aed6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048aed7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048aed8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048aed9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048aeda  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48aedc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048aedc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048aedd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048aede  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048aedf  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0048aee2  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048aee4  8b1485c0205600         -mov edx, dword ptr [eax*4 + 0x5620c0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5644480) /* 0x5620c0 */ + cpu.eax * 4);
    // 0048aeeb  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048aeed  7407                   -je 0x48aef6
    if (cpu.flags.zf)
    {
        goto L_0x0048aef6;
    }
    // 0048aeef  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0048aef2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048aef3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048aef4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048aef5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048aef6:
    // 0048aef6  40                     -inc eax
    (cpu.eax)++;
    // 0048aef7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048aef8  6830e04c00             -push 0x4ce030
    app->getMemory<x86::reg32>(cpu.esp-4) = 5038128 /*0x4ce030*/;
    cpu.esp -= 4;
    // 0048aefd  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048af01  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048af02  e86a9affff             -call 0x484971
    cpu.esp -= 4;
    sub_484971(app, cpu);
    if (cpu.terminate) return;
    // 0048af07  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0048af0a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048af0b  6880000040             -push 0x40000080
    app->getMemory<x86::reg32>(cpu.esp-4) = 1073741952 /*0x40000080*/;
    cpu.esp -= 4;
    // 0048af10  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 0048af12  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048af13  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048af14  68000000c0             -push 0xc0000000
    app->getMemory<x86::reg32>(cpu.esp-4) = 3221225472 /*0xc0000000*/;
    cpu.esp -= 4;
    // 0048af19  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0048af1d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048af1e  2eff1530444c00         -call dword ptr cs:[0x4c4430]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998192) /* 0x4c4430 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048af25  83f8ff                 +cmp eax, -1
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
    // 0048af28  7410                   -je 0x48af3a
    if (cpu.flags.zf)
    {
        goto L_0x0048af3a;
    }
    // 0048af2a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048af2c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048af2e  e821feffff             -call 0x48ad54
    cpu.esp -= 4;
    sub_48ad54(app, cpu);
    if (cpu.terminate) return;
    // 0048af33  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0048af36  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048af37  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048af38  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048af39  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048af3a:
    // 0048af3a  e809d5ffff             -call 0x488448
    cpu.esp -= 4;
    sub_488448(app, cpu);
    if (cpu.terminate) return;
    // 0048af3f  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0048af42  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048af43  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048af44  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048af45  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48af48(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048af48  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048af49  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048af4b  833d249c4d0000         +cmp dword ptr [0x4d9c24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048af52  750a                   -jne 0x48af5e
    if (!cpu.flags.zf)
    {
        goto L_0x0048af5e;
    }
    // 0048af54  e80fd4ffff             -call 0x488368
    cpu.esp -= 4;
    sub_488368(app, cpu);
    if (cpu.terminate) return;
    // 0048af59  a3249c4d00             -mov dword ptr [0x4d9c24], eax
    app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */) = cpu.eax;
L_0x0048af5e:
    // 0048af5e  a1249c4d00             -mov eax, dword ptr [0x4d9c24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */);
    // 0048af63  e850d4ffff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 0048af68  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048af6a  e82dfbffff             -call 0x48aa9c
    cpu.esp -= 4;
    sub_48aa9c(app, cpu);
    if (cpu.terminate) return;
    // 0048af6f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048af71  740b                   -je 0x48af7e
    if (cpu.flags.zf)
    {
        goto L_0x0048af7e;
    }
    // 0048af73  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048af75  e822030000             -call 0x48b29c
    cpu.esp -= 4;
    sub_48b29c(app, cpu);
    if (cpu.terminate) return;
    // 0048af7a  39d0                   +cmp eax, edx
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
    // 0048af7c  7d10                   -jge 0x48af8e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048af8e;
    }
L_0x0048af7e:
    // 0048af7e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048af80  a1249c4d00             -mov eax, dword ptr [0x4d9c24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */);
    // 0048af85  e846d4ffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0048af8a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048af8c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048af8d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048af8e:
    // 0048af8e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048af90  e86b000000             -call 0x48b000
    cpu.esp -= 4;
    sub_48b000(app, cpu);
    if (cpu.terminate) return;
    // 0048af95  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048af97  a1249c4d00             -mov eax, dword ptr [0x4d9c24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */);
    // 0048af9c  e82fd4ffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0048afa1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048afa3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048afa4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48afa8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048afa8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048afa9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048afaa  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048afac  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0048afae  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0048afb0  e8e7faffff             -call 0x48aa9c
    cpu.esp -= 4;
    sub_48aa9c(app, cpu);
    if (cpu.terminate) return;
    // 0048afb5  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048afb7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048afb9  742d                   -je 0x48afe8
    if (cpu.flags.zf)
    {
        goto L_0x0048afe8;
    }
    // 0048afbb  031dc0155600           -add ebx, dword ptr [0x5615c0]
    (cpu.ebx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5641664) /* 0x5615c0 */)));
L_0x0048afc1:
    // 0048afc1  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048afc3  e8d4020000             -call 0x48b29c
    cpu.esp -= 4;
    sub_48b29c(app, cpu);
    if (cpu.terminate) return;
    // 0048afc8  39d0                   +cmp eax, edx
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
    // 0048afca  7d11                   -jge 0x48afdd
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048afdd;
    }
    // 0048afcc  3b1dc0155600           +cmp ebx, dword ptr [0x5615c0]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5641664) /* 0x5615c0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048afd2  7e09                   -jle 0x48afdd
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048afdd;
    }
    // 0048afd4  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0048afd6  e84573ffff             -call 0x482320
    cpu.esp -= 4;
    sub_482320(app, cpu);
    if (cpu.terminate) return;
    // 0048afdb  ebe4                   -jmp 0x48afc1
    goto L_0x0048afc1;
L_0x0048afdd:
    // 0048afdd  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048afdf  e8b8020000             -call 0x48b29c
    cpu.esp -= 4;
    sub_48b29c(app, cpu);
    if (cpu.terminate) return;
    // 0048afe4  39d0                   +cmp eax, edx
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
    // 0048afe6  7d05                   -jge 0x48afed
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048afed;
    }
L_0x0048afe8:
    // 0048afe8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048afea  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048afeb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048afec  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048afed:
    // 0048afed  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0048afef  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048aff1  e80a000000             -call 0x48b000
    cpu.esp -= 4;
    sub_48b000(app, cpu);
    if (cpu.terminate) return;
    // 0048aff6  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048aff8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048affa  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048affb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048affc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48b000(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b000  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048b001  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048b002  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048b003  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048b004  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048b006  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0048b008  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0048b00a  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0048b00c  833d249c4d0000         +cmp dword ptr [0x4d9c24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048b013  750a                   -jne 0x48b01f
    if (!cpu.flags.zf)
    {
        goto L_0x0048b01f;
    }
    // 0048b015  e84ed3ffff             -call 0x488368
    cpu.esp -= 4;
    sub_488368(app, cpu);
    if (cpu.terminate) return;
    // 0048b01a  a3249c4d00             -mov dword ptr [0x4d9c24], eax
    app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */) = cpu.eax;
L_0x0048b01f:
    // 0048b01f  a1249c4d00             -mov eax, dword ptr [0x4d9c24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */);
    // 0048b024  e88fd3ffff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 0048b029  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048b02b  e86cfaffff             -call 0x48aa9c
    cpu.esp -= 4;
    sub_48aa9c(app, cpu);
    if (cpu.terminate) return;
    // 0048b030  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048b032  0f84b1000000           -je 0x48b0e9
    if (cpu.flags.zf)
    {
        goto L_0x0048b0e9;
    }
    // 0048b038  8b048dc0205600         -mov eax, dword ptr [ecx*4 + 0x5620c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5644480) /* 0x5620c0 */ + cpu.ecx * 4);
    // 0048b03f  8bb034020000           -mov esi, dword ptr [eax + 0x234]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(564) /* 0x234 */);
    // 0048b045  01d6                   -add esi, edx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048b047  81fe00020000           +cmp esi, 0x200
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(512 /*0x200*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048b04d  7e0b                   -jle 0x48b05a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048b05a;
    }
    // 0048b04f  ba00020000             -mov edx, 0x200
    cpu.edx = 512 /*0x200*/;
    // 0048b054  2b9034020000           -sub edx, dword ptr [eax + 0x234]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(564) /* 0x234 */)));
L_0x0048b05a:
    // 0048b05a  8b048dc0205600         -mov eax, dword ptr [ecx*4 + 0x5620c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5644480) /* 0x5620c0 */ + cpu.ecx * 4);
    // 0048b061  8b9830020000           -mov ebx, dword ptr [eax + 0x230]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(560) /* 0x230 */);
    // 0048b067  8b8034020000           -mov eax, dword ptr [eax + 0x234]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(564) /* 0x234 */);
    // 0048b06d  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048b06f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048b071  25ff010000             -and eax, 0x1ff
    cpu.eax &= x86::reg32(x86::sreg32(511 /*0x1ff*/));
    // 0048b076  8d1c10                 -lea ebx, [eax + edx]
    cpu.ebx = x86::reg32(cpu.eax + cpu.edx * 1);
    // 0048b079  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0048b07b  81fb00020000           +cmp ebx, 0x200
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
    // 0048b081  7e0b                   -jle 0x48b08e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048b08e;
    }
    // 0048b083  be00020000             -mov esi, 0x200
    cpu.esi = 512 /*0x200*/;
    // 0048b088  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0048b08a  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0048b08c  29f7                   -sub edi, esi
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x0048b08e:
    // 0048b08e  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048b090  7418                   -je 0x48b0aa
    if (cpu.flags.zf)
    {
        goto L_0x0048b0aa;
    }
    // 0048b092  8b148dc0205600         -mov edx, dword ptr [ecx*4 + 0x5620c0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5644480) /* 0x5620c0 */ + cpu.ecx * 4);
    // 0048b099  81c250020000           -add edx, 0x250
    (cpu.edx) += x86::reg32(x86::sreg32(592 /*0x250*/));
    // 0048b09f  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0048b0a1  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048b0a3  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048b0a5  e856eaffff             -call 0x489b00
    cpu.esp -= 4;
    sub_489b00(app, cpu);
    if (cpu.terminate) return;
L_0x0048b0aa:
    // 0048b0aa  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0048b0ac  7417                   -je 0x48b0c5
    if (cpu.flags.zf)
    {
        goto L_0x0048b0c5;
    }
    // 0048b0ae  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0048b0b0  8b148dc0205600         -mov edx, dword ptr [ecx*4 + 0x5620c0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5644480) /* 0x5620c0 */ + cpu.ecx * 4);
    // 0048b0b7  8d042e                 -lea eax, [esi + ebp]
    cpu.eax = x86::reg32(cpu.esi + cpu.ebp * 1);
    // 0048b0ba  81c250020000           -add edx, 0x250
    (cpu.edx) += x86::reg32(x86::sreg32(592 /*0x250*/));
    // 0048b0c0  e83beaffff             -call 0x489b00
    cpu.esp -= 4;
    sub_489b00(app, cpu);
    if (cpu.terminate) return;
L_0x0048b0c5:
    // 0048b0c5  8b048dc0205600         -mov eax, dword ptr [ecx*4 + 0x5620c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5644480) /* 0x5620c0 */ + cpu.ecx * 4);
    // 0048b0cc  8d143e                 -lea edx, [esi + edi]
    cpu.edx = x86::reg32(cpu.esi + cpu.edi * 1);
    // 0048b0cf  8ba834020000           -mov ebp, dword ptr [eax + 0x234]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(564) /* 0x234 */);
    // 0048b0d5  01d5                   -add ebp, edx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048b0d7  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0048b0dc  89a834020000           -mov dword ptr [eax + 0x234], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(564) /* 0x234 */) = cpu.ebp;
    // 0048b0e2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048b0e4  e81bf5ffff             -call 0x48a604
    cpu.esp -= 4;
    sub_48a604(app, cpu);
    if (cpu.terminate) return;
L_0x0048b0e9:
    // 0048b0e9  a1249c4d00             -mov eax, dword ptr [0x4d9c24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */);
    // 0048b0ee  e8ddd2ffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0048b0f3  8d043e                 -lea eax, [esi + edi]
    cpu.eax = x86::reg32(cpu.esi + cpu.edi * 1);
    // 0048b0f6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b0f7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b0f8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b0f9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b0fa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48b0fc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b0fc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048b0fd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048b0fe  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048b0ff  83ec1c                 -sub esp, 0x1c
    (cpu.esp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0048b102  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048b104  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0048b106  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0048b108  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0048b10a  833d249c4d0000         +cmp dword ptr [0x4d9c24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048b111  750a                   -jne 0x48b11d
    if (!cpu.flags.zf)
    {
        goto L_0x0048b11d;
    }
    // 0048b113  e850d2ffff             -call 0x488368
    cpu.esp -= 4;
    sub_488368(app, cpu);
    if (cpu.terminate) return;
    // 0048b118  a3249c4d00             -mov dword ptr [0x4d9c24], eax
    app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */) = cpu.eax;
L_0x0048b11d:
    // 0048b11d  a1249c4d00             -mov eax, dword ptr [0x4d9c24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */);
    // 0048b122  e891d2ffff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 0048b127  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048b129  e86ef9ffff             -call 0x48aa9c
    cpu.esp -= 4;
    sub_48aa9c(app, cpu);
    if (cpu.terminate) return;
    // 0048b12e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048b130  7513                   -jne 0x48b145
    if (!cpu.flags.zf)
    {
        goto L_0x0048b145;
    }
L_0x0048b132:
    // 0048b132  a1249c4d00             -mov eax, dword ptr [0x4d9c24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */);
    // 0048b137  e894d2ffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0048b13c  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0048b13f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b140  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b141  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b142  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0048b145:
    // 0048b145  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0048b147  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048b148  8b04b5c0205600         -mov eax, dword ptr [esi*4 + 0x5620c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5644480) /* 0x5620c0 */ + cpu.esi * 4);
    // 0048b14f  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048b152  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048b153  2eff1584444c00         -call dword ptr cs:[0x4c4484]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998276) /* 0x4c4484 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048b15a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048b15c  745c                   -je 0x48b1ba
    if (cpu.flags.zf)
    {
        goto L_0x0048b1ba;
    }
    // 0048b15e  804c240801             -or byte ptr [esp + 8], 1
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 0048b163  6681642408fdb0         -and word ptr [esp + 8], 0xb0fd
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(8) /* 0x8 */) &= x86::reg16(x86::sreg16(45309 /*0xb0fd*/));
    // 0048b16a  83ff10                 +cmp edi, 0x10
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
    // 0048b16d  7f07                   -jg 0x48b176
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048b176;
    }
    // 0048b16f  8b3cbd289c4d00         -mov edi, dword ptr [edi*4 + 0x4d9c28]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5086248) /* 0x4d9c28 */ + cpu.edi * 4);
L_0x0048b176:
    // 0048b176  8a44242c               -mov al, byte ptr [esp + 0x2c]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0048b17a  0405                   -add al, 5
    (cpu.al) += x86::reg8(x86::sreg8(5 /*0x5*/));
    // 0048b17c  897c2404               -mov dword ptr [esp + 4], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 0048b180  88442412               -mov byte ptr [esp + 0x12], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(18) /* 0x12 */) = cpu.al;
    // 0048b184  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0048b186  764a                   -jbe 0x48b1d2
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0048b1d2;
    }
    // 0048b188  83fb01                 +cmp ebx, 1
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
    // 0048b18b  7545                   -jne 0x48b1d2
    if (!cpu.flags.zf)
    {
        goto L_0x0048b1d2;
    }
    // 0048b18d  c644241402             -mov byte ptr [esp + 0x14], 2
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */) = 2 /*0x2*/;
L_0x0048b192:
    // 0048b192  83fd01                 +cmp ebp, 1
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
    // 0048b195  7343                   -jae 0x48b1da
    if (!cpu.flags.cf)
    {
        goto L_0x0048b1da;
    }
L_0x0048b197:
    // 0048b197  30c9                   -xor cl, cl
    cpu.cl ^= x86::reg8(x86::sreg8(cpu.cl));
    // 0048b199  884c2413               -mov byte ptr [esp + 0x13], cl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(19) /* 0x13 */) = cpu.cl;
L_0x0048b19d:
    // 0048b19d  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0048b19f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048b1a0  8b04b5c0205600         -mov eax, dword ptr [esi*4 + 0x5620c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5644480) /* 0x5620c0 */ + cpu.esi * 4);
    // 0048b1a7  8b5804                 -mov ebx, dword ptr [eax + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048b1aa  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048b1ab  2eff153c454c00         -call dword ptr cs:[0x4c453c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998460) /* 0x4c453c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048b1b2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048b1b4  0f8578ffffff           -jne 0x48b132
    if (!cpu.flags.zf)
    {
        goto L_0x0048b132;
    }
L_0x0048b1ba:
    // 0048b1ba  e889d2ffff             -call 0x488448
    cpu.esp -= 4;
    sub_488448(app, cpu);
    if (cpu.terminate) return;
    // 0048b1bf  a1249c4d00             -mov eax, dword ptr [0x4d9c24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */);
    // 0048b1c4  e807d2ffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0048b1c9  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0048b1cc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b1cd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b1ce  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b1cf  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0048b1d2:
    // 0048b1d2  30f6                   +xor dh, dh
    cpu.clear_co();
    cpu.set_szp((cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh))));
    // 0048b1d4  88742414               -mov byte ptr [esp + 0x14], dh
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.dh;
    // 0048b1d8  ebb8                   -jmp 0x48b192
    goto L_0x0048b192;
L_0x0048b1da:
    // 0048b1da  7707                   -ja 0x48b1e3
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0048b1e3;
    }
    // 0048b1dc  c644241301             -mov byte ptr [esp + 0x13], 1
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(19) /* 0x13 */) = 1 /*0x1*/;
    // 0048b1e1  ebba                   -jmp 0x48b19d
    goto L_0x0048b19d;
L_0x0048b1e3:
    // 0048b1e3  83fd03                 +cmp ebp, 3
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048b1e6  75af                   -jne 0x48b197
    if (!cpu.flags.zf)
    {
        goto L_0x0048b197;
    }
    // 0048b1e8  c644241302             -mov byte ptr [esp + 0x13], 2
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(19) /* 0x13 */) = 2 /*0x2*/;
    // 0048b1ed  ebae                   -jmp 0x48b19d
    goto L_0x0048b19d;
}

/* align: skip 0x90 */
void Application::sub_48b1f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b1f0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048b1f1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048b1f3  833d249c4d0000         +cmp dword ptr [0x4d9c24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048b1fa  750a                   -jne 0x48b206
    if (!cpu.flags.zf)
    {
        goto L_0x0048b206;
    }
    // 0048b1fc  e867d1ffff             -call 0x488368
    cpu.esp -= 4;
    sub_488368(app, cpu);
    if (cpu.terminate) return;
    // 0048b201  a3249c4d00             -mov dword ptr [0x4d9c24], eax
    app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */) = cpu.eax;
L_0x0048b206:
    // 0048b206  a1249c4d00             -mov eax, dword ptr [0x4d9c24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */);
    // 0048b20b  e8a8d1ffff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 0048b210  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048b212  e885f8ffff             -call 0x48aa9c
    cpu.esp -= 4;
    sub_48aa9c(app, cpu);
    if (cpu.terminate) return;
    // 0048b217  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048b219  741b                   -je 0x48b236
    if (cpu.flags.zf)
    {
        goto L_0x0048b236;
    }
    // 0048b21b  8b1495c0205600         -mov edx, dword ptr [edx*4 + 0x5620c0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5644480) /* 0x5620c0 */ + cpu.edx * 4);
    // 0048b222  8b9234020000           -mov edx, dword ptr [edx + 0x234]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(564) /* 0x234 */);
    // 0048b228  a1249c4d00             -mov eax, dword ptr [0x4d9c24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */);
    // 0048b22d  e89ed1ffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0048b232  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048b234  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b235  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048b236:
    // 0048b236  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048b238  a1249c4d00             -mov eax, dword ptr [0x4d9c24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */);
    // 0048b23d  e88ed1ffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0048b242  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048b244  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b245  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48b248(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b248  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048b249  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048b24b  833d249c4d0000         +cmp dword ptr [0x4d9c24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048b252  750a                   -jne 0x48b25e
    if (!cpu.flags.zf)
    {
        goto L_0x0048b25e;
    }
    // 0048b254  e80fd1ffff             -call 0x488368
    cpu.esp -= 4;
    sub_488368(app, cpu);
    if (cpu.terminate) return;
    // 0048b259  a3249c4d00             -mov dword ptr [0x4d9c24], eax
    app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */) = cpu.eax;
L_0x0048b25e:
    // 0048b25e  a1249c4d00             -mov eax, dword ptr [0x4d9c24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */);
    // 0048b263  e850d1ffff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 0048b268  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048b26a  e82df8ffff             -call 0x48aa9c
    cpu.esp -= 4;
    sub_48aa9c(app, cpu);
    if (cpu.terminate) return;
    // 0048b26f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048b271  7418                   -je 0x48b28b
    if (cpu.flags.zf)
    {
        goto L_0x0048b28b;
    }
    // 0048b273  8b1495c0205600         -mov edx, dword ptr [edx*4 + 0x5620c0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5644480) /* 0x5620c0 */ + cpu.edx * 4);
    // 0048b27a  8b5210                 -mov edx, dword ptr [edx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0048b27d  a1249c4d00             -mov eax, dword ptr [0x4d9c24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */);
    // 0048b282  e849d1ffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0048b287  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048b289  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b28a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048b28b:
    // 0048b28b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048b28d  a1249c4d00             -mov eax, dword ptr [0x4d9c24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */);
    // 0048b292  e839d1ffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0048b297  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048b299  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b29a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48b29c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b29c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048b29d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048b29f  833d249c4d0000         +cmp dword ptr [0x4d9c24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048b2a6  750a                   -jne 0x48b2b2
    if (!cpu.flags.zf)
    {
        goto L_0x0048b2b2;
    }
    // 0048b2a8  e8bbd0ffff             -call 0x488368
    cpu.esp -= 4;
    sub_488368(app, cpu);
    if (cpu.terminate) return;
    // 0048b2ad  a3249c4d00             -mov dword ptr [0x4d9c24], eax
    app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */) = cpu.eax;
L_0x0048b2b2:
    // 0048b2b2  a1249c4d00             -mov eax, dword ptr [0x4d9c24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */);
    // 0048b2b7  e8fcd0ffff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 0048b2bc  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048b2be  e8d9f7ffff             -call 0x48aa9c
    cpu.esp -= 4;
    sub_48aa9c(app, cpu);
    if (cpu.terminate) return;
    // 0048b2c3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048b2c5  7426                   -je 0x48b2ed
    if (cpu.flags.zf)
    {
        goto L_0x0048b2ed;
    }
    // 0048b2c7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048b2c8  8b1495c0205600         -mov edx, dword ptr [edx*4 + 0x5620c0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5644480) /* 0x5620c0 */ + cpu.edx * 4);
    // 0048b2cf  b800020000             -mov eax, 0x200
    cpu.eax = 512 /*0x200*/;
    // 0048b2d4  8b9a34020000           -mov ebx, dword ptr [edx + 0x234]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(564) /* 0x234 */);
    // 0048b2da  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048b2dc  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048b2de  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b2df  a1249c4d00             -mov eax, dword ptr [0x4d9c24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */);
    // 0048b2e4  e8e7d0ffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0048b2e9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048b2eb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b2ec  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048b2ed:
    // 0048b2ed  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048b2ef  a1249c4d00             -mov eax, dword ptr [0x4d9c24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */);
    // 0048b2f4  e8d7d0ffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0048b2f9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048b2fb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b2fc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48b300(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b300  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048b301  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048b302  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048b303  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048b304  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048b306  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0048b308  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0048b30a  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0048b30c  833d249c4d0000         +cmp dword ptr [0x4d9c24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048b313  750a                   -jne 0x48b31f
    if (!cpu.flags.zf)
    {
        goto L_0x0048b31f;
    }
    // 0048b315  e84ed0ffff             -call 0x488368
    cpu.esp -= 4;
    sub_488368(app, cpu);
    if (cpu.terminate) return;
    // 0048b31a  a3249c4d00             -mov dword ptr [0x4d9c24], eax
    app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */) = cpu.eax;
L_0x0048b31f:
    // 0048b31f  a1249c4d00             -mov eax, dword ptr [0x4d9c24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */);
    // 0048b324  e88fd0ffff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 0048b329  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048b32b  e86cf7ffff             -call 0x48aa9c
    cpu.esp -= 4;
    sub_48aa9c(app, cpu);
    if (cpu.terminate) return;
    // 0048b330  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048b332  0f846e000000           -je 0x48b3a6
    if (cpu.flags.zf)
    {
        goto L_0x0048b3a6;
    }
    // 0048b338  8b048dc0205600         -mov eax, dword ptr [ecx*4 + 0x5620c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5644480) /* 0x5620c0 */ + cpu.ecx * 4);
    // 0048b33f  8b7010                 -mov esi, dword ptr [eax + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0048b342  39f2                   +cmp edx, esi
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
    // 0048b344  7e02                   -jle 0x48b348
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048b348;
    }
    // 0048b346  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
L_0x0048b348:
    // 0048b348  8b048dc0205600         -mov eax, dword ptr [ecx*4 + 0x5620c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5644480) /* 0x5620c0 */ + cpu.ecx * 4);
    // 0048b34f  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0048b352  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048b354  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0048b356  81fb00020000           +cmp ebx, 0x200
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
    // 0048b35c  7e14                   -jle 0x48b372
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048b372;
    }
    // 0048b35e  bf00020000             -mov edi, 0x200
    cpu.edi = 512 /*0x200*/;
    // 0048b363  8b700c                 -mov esi, dword ptr [eax + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0048b366  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048b368  29f7                   -sub edi, esi
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0048b36a  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0048b36c  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0048b36e  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048b370  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
L_0x0048b372:
    // 0048b372  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048b374  7418                   -je 0x48b38e
    if (cpu.flags.zf)
    {
        goto L_0x0048b38e;
    }
    // 0048b376  8b048dc0205600         -mov eax, dword ptr [ecx*4 + 0x5620c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5644480) /* 0x5620c0 */ + cpu.ecx * 4);
    // 0048b37d  8d502c                 -lea edx, [eax + 0x2c]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(44) /* 0x2c */);
    // 0048b380  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0048b383  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0048b385  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048b387  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0048b389  e872e7ffff             -call 0x489b00
    cpu.esp -= 4;
    sub_489b00(app, cpu);
    if (cpu.terminate) return;
L_0x0048b38e:
    // 0048b38e  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0048b390  7414                   -je 0x48b3a6
    if (cpu.flags.zf)
    {
        goto L_0x0048b3a6;
    }
    // 0048b392  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0048b394  8b048dc0205600         -mov eax, dword ptr [ecx*4 + 0x5620c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5644480) /* 0x5620c0 */ + cpu.ecx * 4);
    // 0048b39b  8d142e                 -lea edx, [esi + ebp]
    cpu.edx = x86::reg32(cpu.esi + cpu.ebp * 1);
    // 0048b39e  83c02c                 -add eax, 0x2c
    (cpu.eax) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 0048b3a1  e85ae7ffff             -call 0x489b00
    cpu.esp -= 4;
    sub_489b00(app, cpu);
    if (cpu.terminate) return;
L_0x0048b3a6:
    // 0048b3a6  a1249c4d00             -mov eax, dword ptr [0x4d9c24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */);
    // 0048b3ab  e820d0ffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0048b3b0  8d043e                 -lea eax, [esi + edi]
    cpu.eax = x86::reg32(cpu.esi + cpu.edi * 1);
    // 0048b3b3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b3b4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b3b5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b3b6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b3b7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48b3b8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b3b8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048b3b9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048b3bb  833d249c4d0000         +cmp dword ptr [0x4d9c24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048b3c2  750a                   -jne 0x48b3ce
    if (!cpu.flags.zf)
    {
        goto L_0x0048b3ce;
    }
    // 0048b3c4  e89fcfffff             -call 0x488368
    cpu.esp -= 4;
    sub_488368(app, cpu);
    if (cpu.terminate) return;
    // 0048b3c9  a3249c4d00             -mov dword ptr [0x4d9c24], eax
    app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */) = cpu.eax;
L_0x0048b3ce:
    // 0048b3ce  a1249c4d00             -mov eax, dword ptr [0x4d9c24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */);
    // 0048b3d3  e8e0cfffff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 0048b3d8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048b3da  e821ffffff             -call 0x48b300
    cpu.esp -= 4;
    sub_48b300(app, cpu);
    if (cpu.terminate) return;
    // 0048b3df  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048b3e1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048b3e3  750e                   -jne 0x48b3f3
    if (!cpu.flags.zf)
    {
        goto L_0x0048b3f3;
    }
    // 0048b3e5  a1249c4d00             -mov eax, dword ptr [0x4d9c24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */);
    // 0048b3ea  e8e1cfffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0048b3ef  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048b3f1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b3f2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048b3f3:
    // 0048b3f3  8b148dc0205600         -mov edx, dword ptr [ecx*4 + 0x5620c0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5644480) /* 0x5620c0 */ + cpu.ecx * 4);
    // 0048b3fa  294210                 -sub dword ptr [edx + 0x10], eax
    (app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */)) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0048b3fd  8b148dc0205600         -mov edx, dword ptr [ecx*4 + 0x5620c0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5644480) /* 0x5620c0 */ + cpu.ecx * 4);
    // 0048b404  03420c                 -add eax, dword ptr [edx + 0xc]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 0048b407  25ff010000             -and eax, 0x1ff
    cpu.eax &= x86::reg32(x86::sreg32(511 /*0x1ff*/));
    // 0048b40c  89420c                 -mov dword ptr [edx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0048b40f  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0048b414  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048b416  e8e9f1ffff             -call 0x48a604
    cpu.esp -= 4;
    sub_48a604(app, cpu);
    if (cpu.terminate) return;
    // 0048b41b  a1249c4d00             -mov eax, dword ptr [0x4d9c24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */);
    // 0048b420  e8abcfffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0048b425  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048b427  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b428  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48b42c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b42c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048b42d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048b42e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048b430  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0048b432  833d249c4d0000         +cmp dword ptr [0x4d9c24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048b439  750a                   -jne 0x48b445
    if (!cpu.flags.zf)
    {
        goto L_0x0048b445;
    }
    // 0048b43b  e828cfffff             -call 0x488368
    cpu.esp -= 4;
    sub_488368(app, cpu);
    if (cpu.terminate) return;
    // 0048b440  a3249c4d00             -mov dword ptr [0x4d9c24], eax
    app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */) = cpu.eax;
L_0x0048b445:
    // 0048b445  a1249c4d00             -mov eax, dword ptr [0x4d9c24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */);
    // 0048b44a  e869cfffff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 0048b44f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048b451  e846f6ffff             -call 0x48aa9c
    cpu.esp -= 4;
    sub_48aa9c(app, cpu);
    if (cpu.terminate) return;
    // 0048b456  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048b458  7435                   -je 0x48b48f
    if (cpu.flags.zf)
    {
        goto L_0x0048b48f;
    }
    // 0048b45a  8d1c8d00000000         -lea ebx, [ecx*4]
    cpu.ebx = x86::reg32(cpu.ecx * 4);
L_0x0048b461:
    // 0048b461  8b83c0205600           -mov eax, dword ptr [ebx + 0x5620c0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5644480) /* 0x5620c0 */);
    // 0048b467  3b5010                 +cmp edx, dword ptr [eax + 0x10]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048b46a  7e09                   -jle 0x48b475
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048b475;
    }
    // 0048b46c  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0048b46e  e8ad6effff             -call 0x482320
    cpu.esp -= 4;
    sub_482320(app, cpu);
    if (cpu.terminate) return;
    // 0048b473  ebec                   -jmp 0x48b461
    goto L_0x0048b461;
L_0x0048b475:
    // 0048b475  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0048b477  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048b479  e83affffff             -call 0x48b3b8
    cpu.esp -= 4;
    sub_48b3b8(app, cpu);
    if (cpu.terminate) return;
    // 0048b47e  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048b480  a1249c4d00             -mov eax, dword ptr [0x4d9c24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */);
    // 0048b485  e846cfffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0048b48a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048b48c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b48d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b48e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048b48f:
    // 0048b48f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048b491  a1249c4d00             -mov eax, dword ptr [0x4d9c24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */);
    // 0048b496  e835cfffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0048b49b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048b49d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b49e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b49f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48b4a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b4a0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048b4a1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048b4a3  833d249c4d0000         +cmp dword ptr [0x4d9c24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048b4aa  750a                   -jne 0x48b4b6
    if (!cpu.flags.zf)
    {
        goto L_0x0048b4b6;
    }
    // 0048b4ac  e8b7ceffff             -call 0x488368
    cpu.esp -= 4;
    sub_488368(app, cpu);
    if (cpu.terminate) return;
    // 0048b4b1  a3249c4d00             -mov dword ptr [0x4d9c24], eax
    app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */) = cpu.eax;
L_0x0048b4b6:
    // 0048b4b6  a1249c4d00             -mov eax, dword ptr [0x4d9c24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */);
    // 0048b4bb  e8f8ceffff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 0048b4c0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048b4c2  e8d5f5ffff             -call 0x48aa9c
    cpu.esp -= 4;
    sub_48aa9c(app, cpu);
    if (cpu.terminate) return;
    // 0048b4c7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048b4c9  740c                   -je 0x48b4d7
    if (cpu.flags.zf)
    {
        goto L_0x0048b4d7;
    }
    // 0048b4cb  8b048dc0205600         -mov eax, dword ptr [ecx*4 + 0x5620c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5644480) /* 0x5620c0 */ + cpu.ecx * 4);
    // 0048b4d2  3b5010                 +cmp edx, dword ptr [eax + 0x10]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048b4d5  7e10                   -jle 0x48b4e7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048b4e7;
    }
L_0x0048b4d7:
    // 0048b4d7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048b4d9  a1249c4d00             -mov eax, dword ptr [0x4d9c24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */);
    // 0048b4de  e8edceffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0048b4e3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048b4e5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b4e6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048b4e7:
    // 0048b4e7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048b4e9  e8cafeffff             -call 0x48b3b8
    cpu.esp -= 4;
    sub_48b3b8(app, cpu);
    if (cpu.terminate) return;
    // 0048b4ee  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048b4f0  a1249c4d00             -mov eax, dword ptr [0x4d9c24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5086244) /* 0x4d9c24 */);
    // 0048b4f5  e8d6ceffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0048b4fa  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048b4fc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b4fd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48b500(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b500  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048b501  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048b502  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048b504  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0048b506  e891f5ffff             -call 0x48aa9c
    cpu.esp -= 4;
    sub_48aa9c(app, cpu);
    if (cpu.terminate) return;
    // 0048b50b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048b50d  7434                   -je 0x48b543
    if (cpu.flags.zf)
    {
        goto L_0x0048b543;
    }
    // 0048b50f  8b1dc0155600           -mov ebx, dword ptr [0x5615c0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5641664) /* 0x5615c0 */);
    // 0048b515  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048b517  8d0cb500000000         -lea ecx, [esi*4]
    cpu.ecx = x86::reg32(cpu.esi * 4);
L_0x0048b51e:
    // 0048b51e  8b81c0205600           -mov eax, dword ptr [ecx + 0x5620c0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5644480) /* 0x5620c0 */);
    // 0048b524  3b5010                 +cmp edx, dword ptr [eax + 0x10]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048b527  7e11                   -jle 0x48b53a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048b53a;
    }
    // 0048b529  3b1dc0155600           +cmp ebx, dword ptr [0x5615c0]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5641664) /* 0x5615c0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048b52f  7e09                   -jle 0x48b53a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048b53a;
    }
    // 0048b531  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0048b533  e8e86dffff             -call 0x482320
    cpu.esp -= 4;
    sub_482320(app, cpu);
    if (cpu.terminate) return;
    // 0048b538  ebe4                   -jmp 0x48b51e
    goto L_0x0048b51e;
L_0x0048b53a:
    // 0048b53a  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0048b53c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048b53e  e875feffff             -call 0x48b3b8
    cpu.esp -= 4;
    sub_48b3b8(app, cpu);
    if (cpu.terminate) return;
L_0x0048b543:
    // 0048b543  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b544  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b545  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_48b550(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b550  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048b552  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048b554  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048b556  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048b558  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048b55a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048b55c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048b55e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048b560  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048b561  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048b562  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048b565  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048b567  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048b568  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048b56c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048b56d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048b56e  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0048b572  e8797d0300             -call 0x4c32f0
    cpu.esp -= 4;
    sub_4c32f0(app, cpu);
    if (cpu.terminate) return;
    // 0048b577  8b1d3c1b5600           -mov ebx, dword ptr [0x561b3c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5643068) /* 0x561b3c */);
    // 0048b57d  43                     -inc ebx
    (cpu.ebx)++;
    // 0048b57e  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0048b581  891d3c1b5600           -mov dword ptr [0x561b3c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5643068) /* 0x561b3c */) = cpu.ebx;
    // 0048b587  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048b58a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b58b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b58c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48b560(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0048b560;
    // 0048b550  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048b552  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048b554  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048b556  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048b558  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048b55a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048b55c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0048b55e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
L_entry_0x0048b560:
    // 0048b560  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048b561  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048b562  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048b565  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048b567  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048b568  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048b56c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048b56d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048b56e  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0048b572  e8797d0300             -call 0x4c32f0
    cpu.esp -= 4;
    sub_4c32f0(app, cpu);
    if (cpu.terminate) return;
    // 0048b577  8b1d3c1b5600           -mov ebx, dword ptr [0x561b3c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5643068) /* 0x561b3c */);
    // 0048b57d  43                     -inc ebx
    (cpu.ebx)++;
    // 0048b57e  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0048b581  891d3c1b5600           -mov dword ptr [0x561b3c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5643068) /* 0x561b3c */) = cpu.ebx;
    // 0048b587  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048b58a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b58b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b58c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48b590(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b590  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048b591  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048b592  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048b593  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048b594  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048b597  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048b599  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0048b59c  8b5024                 -mov edx, dword ptr [eax + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 0048b59f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048b5a0  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048b5a4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048b5a6  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048b5a7  8b5e18                 -mov ebx, dword ptr [esi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0048b5aa  8a8663040000           -mov al, byte ptr [esi + 0x463]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1123) /* 0x463 */);
    // 0048b5b0  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048b5b2  48                     -dec eax
    (cpu.eax)--;
    // 0048b5b3  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0048b5b6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048b5b7  8b4e1c                 -mov ecx, dword ptr [esi + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0048b5ba  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048b5bc  e883180000             -call 0x48ce44
    cpu.esp -= 4;
    sub_48ce44(app, cpu);
    if (cpu.terminate) return;
    // 0048b5c1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048b5c3  7408                   -je 0x48b5cd
    if (cpu.flags.zf)
    {
        goto L_0x0048b5cd;
    }
L_0x0048b5c5:
    // 0048b5c5  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048b5c8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b5c9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b5ca  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b5cb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b5cc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048b5cd:
    // 0048b5cd  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0048b5d0  8b5e24                 -mov ebx, dword ptr [esi + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 0048b5d3  80e4b7                 -and ah, 0xb7
    cpu.ah &= x86::reg8(x86::sreg8(183 /*0xb7*/));
    // 0048b5d6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048b5d7  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0048b5db  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048b5dc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048b5de  8b4e1c                 -mov ecx, dword ptr [esi + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0048b5e1  8a8663040000           -mov al, byte ptr [esi + 0x463]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1123) /* 0x463 */);
    // 0048b5e7  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048b5e9  48                     -dec eax
    (cpu.eax)--;
    // 0048b5ea  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0048b5ed  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048b5ee  8b5e18                 -mov ebx, dword ptr [esi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0048b5f1  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048b5f3  e84c180000             -call 0x48ce44
    cpu.esp -= 4;
    sub_48ce44(app, cpu);
    if (cpu.terminate) return;
    // 0048b5f8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048b5fa  7531                   -jne 0x48b62d
    if (!cpu.flags.zf)
    {
        goto L_0x0048b62d;
    }
    // 0048b5fc  f644240140             +test byte ptr [esp + 1], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */) & 64 /*0x40*/));
    // 0048b601  746c                   -je 0x48b66f
    if (cpu.flags.zf)
    {
        goto L_0x0048b66f;
    }
    // 0048b603  804c240508             -or byte ptr [esp + 5], 8
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(5) /* 0x5 */) |= x86::reg8(x86::sreg8(8 /*0x8*/));
L_0x0048b608:
    // 0048b608  8b6e24                 -mov ebp, dword ptr [esi + 0x24]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 0048b60b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048b60c  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048b610  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048b611  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048b613  8b4e1c                 -mov ecx, dword ptr [esi + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0048b616  8a8663040000           -mov al, byte ptr [esi + 0x463]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1123) /* 0x463 */);
    // 0048b61c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048b61e  48                     -dec eax
    (cpu.eax)--;
    // 0048b61f  8b5e18                 -mov ebx, dword ptr [esi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0048b622  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048b623  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0048b626  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048b628  e817180000             -call 0x48ce44
    cpu.esp -= 4;
    sub_48ce44(app, cpu);
    if (cpu.terminate) return;
L_0x0048b62d:
    // 0048b62d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048b62f  7594                   -jne 0x48b5c5
    if (!cpu.flags.zf)
    {
        goto L_0x0048b5c5;
    }
    // 0048b631  80be6304000001         +cmp byte ptr [esi + 0x463], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1123) /* 0x463 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048b638  768b                   -jbe 0x48b5c5
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0048b5c5;
    }
    // 0048b63a  8a7c2405               -mov bh, byte ptr [esp + 5]
    cpu.bh = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(5) /* 0x5 */);
    // 0048b63e  80e7b7                 -and bh, 0xb7
    cpu.bh &= x86::reg8(x86::sreg8(183 /*0xb7*/));
    // 0048b641  8b5624                 -mov edx, dword ptr [esi + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 0048b644  887c2405               -mov byte ptr [esp + 5], bh
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(5) /* 0x5 */) = cpu.bh;
    // 0048b648  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048b649  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048b64d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048b64e  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0048b651  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048b652  8b5e18                 -mov ebx, dword ptr [esi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0048b655  8b4e1c                 -mov ecx, dword ptr [esi + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0048b658  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048b659  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048b65b  c6866304000001         -mov byte ptr [esi + 0x463], 1
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1123) /* 0x463 */) = 1 /*0x1*/;
    // 0048b662  e8dd170000             -call 0x48ce44
    cpu.esp -= 4;
    sub_48ce44(app, cpu);
    if (cpu.terminate) return;
    // 0048b667  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048b66a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b66b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b66c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b66d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b66e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048b66f:
    // 0048b66f  804c240540             +or byte ptr [esp + 5], 0x40
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.esp + x86::reg32(5) /* 0x5 */) |= x86::reg8(x86::sreg8(64 /*0x40*/))));
    // 0048b674  eb92                   -jmp 0x48b608
    goto L_0x0048b608;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48b678(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b678  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048b679  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048b67a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048b67b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048b67d  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0048b67f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048b681  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0048b683  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048b684  c7036c000000           -mov dword ptr [ebx], 0x6c
    app->getMemory<x86::reg32>(cpu.ebx) = 108 /*0x6c*/;
    // 0048b68a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048b68c  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0048b68e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048b68f  ff5064                 -call dword ptr [eax + 0x64]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048b692  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048b694  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0048b69a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048b69c  7408                   -je 0x48b6a6
    if (cpu.flags.zf)
    {
        goto L_0x0048b6a6;
    }
    // 0048b69e  81fac2010000           +cmp edx, 0x1c2
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(450 /*0x1c2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048b6a4  7406                   -je 0x48b6ac
    if (cpu.flags.zf)
    {
        goto L_0x0048b6ac;
    }
L_0x0048b6a6:
    // 0048b6a6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048b6a8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b6a9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b6aa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b6ab  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048b6ac:
    // 0048b6ac  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048b6ad  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0048b6af  ff506c                 -call dword ptr [eax + 0x6c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(108) /* 0x6c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048b6b2  8b9644040000           -mov edx, dword ptr [esi + 0x444]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1092) /* 0x444 */);
    // 0048b6b8  39d7                   +cmp edi, edx
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
    // 0048b6ba  7418                   -je 0x48b6d4
    if (cpu.flags.zf)
    {
        goto L_0x0048b6d4;
    }
    // 0048b6bc  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048b6be  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048b6bf  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 0048b6c1  ff5260                 -call dword ptr [edx + 0x60]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(96) /* 0x60 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048b6c4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048b6c6  740c                   -je 0x48b6d4
    if (cpu.flags.zf)
    {
        goto L_0x0048b6d4;
    }
    // 0048b6c8  8b8644040000           -mov eax, dword ptr [esi + 0x444]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1092) /* 0x444 */);
    // 0048b6ce  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048b6cf  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0048b6d1  ff526c                 -call dword ptr [edx + 0x6c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(108) /* 0x6c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0048b6d4:
    // 0048b6d4  8b8e48040000           -mov ecx, dword ptr [esi + 0x448]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1096) /* 0x448 */);
    // 0048b6da  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048b6dc  741a                   -je 0x48b6f8
    if (cpu.flags.zf)
    {
        goto L_0x0048b6f8;
    }
    // 0048b6de  39cf                   +cmp edi, ecx
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
    // 0048b6e0  7416                   -je 0x48b6f8
    if (cpu.flags.zf)
    {
        goto L_0x0048b6f8;
    }
    // 0048b6e2  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048b6e3  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0048b6e5  ff5260                 -call dword ptr [edx + 0x60]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(96) /* 0x60 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048b6e8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048b6ea  740c                   -je 0x48b6f8
    if (cpu.flags.zf)
    {
        goto L_0x0048b6f8;
    }
    // 0048b6ec  8b8648040000           -mov eax, dword ptr [esi + 0x448]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1096) /* 0x448 */);
    // 0048b6f2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048b6f3  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0048b6f5  ff526c                 -call dword ptr [edx + 0x6c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(108) /* 0x6c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0048b6f8:
    // 0048b6f8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048b6f9  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0048b6fb  ff5060                 -call dword ptr [eax + 0x60]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(96) /* 0x60 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048b6fe  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048b700  0f85b2000000           -jne 0x48b7b8
    if (!cpu.flags.zf)
    {
        goto L_0x0048b7b8;
    }
    // 0048b706  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048b708  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0048b70a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048b70b  c7036c000000           -mov dword ptr [ebx], 0x6c
    app->getMemory<x86::reg32>(cpu.ebx) = 108 /*0x6c*/;
    // 0048b711  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048b713  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0048b715  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048b716  ff5064                 -call dword ptr [eax + 0x64]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048b719  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048b71b  81e2ffff0000           +and edx, 0xffff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/))));
    // 0048b721  7434                   -je 0x48b757
    if (cpu.flags.zf)
    {
        goto L_0x0048b757;
    }
    // 0048b723  a1bc944d00             -mov eax, dword ptr [0x4d94bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5084348) /* 0x4d94bc */);
    // 0048b728  e8a3ccffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0048b72d  e89ec60100             -call 0x4a7dd0
    cpu.esp -= 4;
    sub_4a7dd0(app, cpu);
    if (cpu.terminate) return;
    // 0048b732  a1bc944d00             -mov eax, dword ptr [0x4d94bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5084348) /* 0x4d94bc */);
    // 0048b737  e87cccffff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 0048b73c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048b73e  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0048b740  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048b741  c7036c000000           -mov dword ptr [ebx], 0x6c
    app->getMemory<x86::reg32>(cpu.ebx) = 108 /*0x6c*/;
    // 0048b747  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048b749  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0048b74b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048b74c  ff5064                 -call dword ptr [eax + 0x64]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(100) /* 0x64 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048b74f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048b751  81e2ffff0000           +and edx, 0xffff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/))));
L_0x0048b757:
    // 0048b757  0f8549ffffff           -jne 0x48b6a6
    if (!cpu.flags.zf)
    {
        goto L_0x0048b6a6;
    }
    // 0048b75d  837e2400               +cmp dword ptr [esi + 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048b761  7519                   -jne 0x48b77c
    if (!cpu.flags.zf)
    {
        goto L_0x0048b77c;
    }
L_0x0048b763:
    // 0048b763  833dec8f4d0000         +cmp dword ptr [0x4d8fec], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5083116) /* 0x4d8fec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048b76a  0f8436ffffff           -je 0x48b6a6
    if (cpu.flags.zf)
    {
        goto L_0x0048b6a6;
    }
    // 0048b770  ff15ec8f4d00           -call dword ptr [0x4d8fec]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5083116) /* 0x4d8fec */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048b776  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048b778  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b779  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b77a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b77b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048b77c:
    // 0048b77c  8d5630                 -lea edx, [esi + 0x30]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(48) /* 0x30 */);
    // 0048b77f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048b780  6800010000             -push 0x100
    app->getMemory<x86::reg32>(cpu.esp-4) = 256 /*0x100*/;
    cpu.esp -= 4;
    // 0048b785  66c78632040000ffff     -mov word ptr [esi + 0x432], 0xffff
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(1074) /* 0x432 */) = 65535 /*0xffff*/;
    // 0048b78e  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048b790  8b4624                 -mov eax, dword ptr [esi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 0048b793  66c786300400000001     -mov word ptr [esi + 0x430], 0x100
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(1072) /* 0x430 */) = 256 /*0x100*/;
    // 0048b79c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048b79e  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 0048b7a0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048b7a1  ff5318                 -call dword ptr [ebx + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048b7a4  8b4e24                 -mov ecx, dword ptr [esi + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 0048b7a7  8b8644040000           -mov eax, dword ptr [esi + 0x444]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1092) /* 0x444 */);
    // 0048b7ad  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048b7ae  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0048b7b0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048b7b1  ff527c                 -call dword ptr [edx + 0x7c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(124) /* 0x7c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048b7b4  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0048b7b6  ebab                   -jmp 0x48b763
    goto L_0x0048b763;
L_0x0048b7b8:
    // 0048b7b8  bac2010000             -mov edx, 0x1c2
    cpu.edx = 450 /*0x1c2*/;
    // 0048b7bd  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048b7bf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b7c0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b7c1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b7c2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48b7c4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b7c4  3b05141b5600           +cmp eax, dword ptr [0x561b14]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5643028) /* 0x561b14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048b7ca  7401                   -je 0x48b7cd
    if (cpu.flags.zf)
    {
        goto L_0x0048b7cd;
    }
    // 0048b7cc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048b7cd:
    // 0048b7cd  a1341b5600             -mov eax, dword ptr [0x561b34]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643060) /* 0x561b34 */);
    // 0048b7d2  0102                   -add dword ptr [edx], eax
    (app->getMemory<x86::reg32>(cpu.edx)) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048b7d4  a1381b5600             -mov eax, dword ptr [0x561b38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643064) /* 0x561b38 */);
    // 0048b7d9  0103                   -add dword ptr [ebx], eax
    (app->getMemory<x86::reg32>(cpu.ebx)) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048b7db  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48b7dc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b7dc  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048b7dd  3b05141b5600           +cmp eax, dword ptr [0x561b14]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5643028) /* 0x561b14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048b7e3  7402                   -je 0x48b7e7
    if (cpu.flags.zf)
    {
        goto L_0x0048b7e7;
    }
    // 0048b7e5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b7e6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048b7e7:
    // 0048b7e7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048b7e8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048b7e9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048b7ea  a1341b5600             -mov eax, dword ptr [0x561b34]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643060) /* 0x561b34 */);
    // 0048b7ef  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 0048b7f1  8b7204                 -mov esi, dword ptr [edx + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048b7f4  8b7a08                 -mov edi, dword ptr [edx + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0048b7f7  8b6a0c                 -mov ebp, dword ptr [edx + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0048b7fa  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048b7fc  a1381b5600             -mov eax, dword ptr [0x561b38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643064) /* 0x561b38 */);
    // 0048b801  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 0048b803  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048b805  a1341b5600             -mov eax, dword ptr [0x561b34]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643060) /* 0x561b34 */);
    // 0048b80a  897204                 -mov dword ptr [edx + 4], esi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 0048b80d  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048b80f  a1381b5600             -mov eax, dword ptr [0x561b38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643064) /* 0x561b38 */);
    // 0048b814  897a08                 -mov dword ptr [edx + 8], edi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 0048b817  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048b819  896a0c                 -mov dword ptr [edx + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 0048b81c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b81d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b81e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b81f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b820  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48b824(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b824  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048b825  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048b826  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048b828  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048b82a  7410                   -je 0x48b83c
    if (cpu.flags.zf)
    {
        goto L_0x0048b83c;
    }
L_0x0048b82c:
    // 0048b82c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048b82e  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0048b830  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0048b832  21c8                   -and eax, ecx
    cpu.eax &= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048b834  42                     -inc edx
    (cpu.edx)++;
    // 0048b835  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048b837  75f3                   -jne 0x48b82c
    if (!cpu.flags.zf)
    {
        goto L_0x0048b82c;
    }
    // 0048b839  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x0048b83c:
    // 0048b83c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048b83e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b83f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b840  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48b844(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b844  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048b845  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048b846  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048b847  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048b84a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048b84c  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0048b84e  f6430510               +test byte ptr [ebx + 5], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5) /* 0x5 */) & 16 /*0x10*/));
    // 0048b852  0f844a010000           -je 0x48b9a2
    if (cpu.flags.zf)
    {
        goto L_0x0048b9a2;
    }
    // 0048b858  837b5410               +cmp dword ptr [ebx + 0x54], 0x10
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(84) /* 0x54 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048b85c  0f8440010000           -je 0x48b9a2
    if (cpu.flags.zf)
    {
        goto L_0x0048b9a2;
    }
    // 0048b862  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048b864  8a4354                 -mov al, byte ptr [ebx + 0x54]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(84) /* 0x54 */);
    // 0048b867  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x0048b86b:
    // 0048b86b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048b86d  0f8cdd000000           -jl 0x48b950
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048b950;
    }
    // 0048b873  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0048b87a  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048b87c  8b6e10                 -mov ebp, dword ptr [esi + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0048b87f  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0048b882  8b4b0c                 -mov ecx, dword ptr [ebx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 0048b885  890c28                 -mov dword ptr [eax + ebp], ecx
    app->getMemory<x86::reg32>(cpu.eax + cpu.ebp * 1) = cpu.ecx;
    // 0048b888  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0048b88b  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048b88d  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 0048b890  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 0048b893  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0048b896  894d04                 -mov dword ptr [ebp + 4], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0048b899  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0048b89c  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048b89e  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 0048b8a1  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 0048b8a4  8a4b54                 -mov cl, byte ptr [ebx + 0x54]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(84) /* 0x54 */);
    // 0048b8a7  884d12                 -mov byte ptr [ebp + 0x12], cl
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(18) /* 0x12 */) = cpu.cl;
    // 0048b8aa  8b6e10                 -mov ebp, dword ptr [esi + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0048b8ad  8a4c2404               -mov cl, byte ptr [esp + 4]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048b8b1  884c2813               -mov byte ptr [eax + ebp + 0x13], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(19) /* 0x13 */ + cpu.ebp * 1) = cpu.cl;
    // 0048b8b5  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0048b8b8  66c74401100100         -mov word ptr [ecx + eax + 0x10], 1
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(16) /* 0x10 */ + cpu.eax * 1) = 1 /*0x1*/;
    // 0048b8bf  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0048b8c2  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048b8c4  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 0048b8c7  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 0048b8ca  8b0d6c9c4d00           -mov ecx, dword ptr [0x4d9c6c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5086316) /* 0x4d9c6c */);
    // 0048b8d0  894d0c                 -mov dword ptr [ebp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0048b8d3  f6430604               +test byte ptr [ebx + 6], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(6) /* 0x6 */) & 4 /*0x4*/));
    // 0048b8d7  740b                   -je 0x48b8e4
    if (cpu.flags.zf)
    {
        goto L_0x0048b8e4;
    }
    // 0048b8d9  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0048b8dc  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048b8de  8b4318                 -mov eax, dword ptr [ebx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 0048b8e1  894108                 -mov dword ptr [ecx + 8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.eax;
L_0x0048b8e4:
    // 0048b8e4  f6430420               +test byte ptr [ebx + 4], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */) & 32 /*0x20*/));
    // 0048b8e8  741b                   -je 0x48b905
    if (cpu.flags.zf)
    {
        goto L_0x0048b905;
    }
    // 0048b8ea  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0048b8f1  8d0c02                 -lea ecx, [edx + eax]
    cpu.ecx = x86::reg32(cpu.edx + cpu.eax * 1);
    // 0048b8f4  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 0048b8f7  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0048b8fa  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048b8fc  30ed                   -xor ch, ch
    cpu.ch ^= x86::reg8(x86::sreg8(cpu.ch));
    // 0048b8fe  8a4b14                 -mov cl, byte ptr [ebx + 0x14]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 0048b901  66014810               -add word ptr [eax + 0x10], cx
    (app->getMemory<x86::reg16>(cpu.eax + x86::reg32(16) /* 0x10 */)) += x86::reg16(x86::sreg16(cpu.cx));
L_0x0048b905:
    // 0048b905  f6430480               +test byte ptr [ebx + 4], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */) & 128 /*0x80*/));
    // 0048b909  7411                   -je 0x48b91c
    if (cpu.flags.zf)
    {
        goto L_0x0048b91c;
    }
    // 0048b90b  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0048b912  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0048b915  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048b917  804c810c01             -or byte ptr [ecx + eax*4 + 0xc], 1
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */ + cpu.eax * 4) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x0048b91c:
    // 0048b91c  f6430440               +test byte ptr [ebx + 4], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */) & 64 /*0x40*/));
    // 0048b920  7411                   -je 0x48b933
    if (cpu.flags.zf)
    {
        goto L_0x0048b933;
    }
    // 0048b922  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0048b929  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0048b92c  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048b92e  804c810c02             -or byte ptr [ecx + eax*4 + 0xc], 2
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */ + cpu.eax * 4) |= x86::reg8(x86::sreg8(2 /*0x2*/));
L_0x0048b933:
    // 0048b933  f6430401               +test byte ptr [ebx + 4], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */) & 1 /*0x1*/));
    // 0048b937  7417                   -je 0x48b950
    if (cpu.flags.zf)
    {
        goto L_0x0048b950;
    }
    // 0048b939  f6436a20               +test byte ptr [ebx + 0x6a], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(106) /* 0x6a */) & 32 /*0x20*/));
    // 0048b93d  7411                   -je 0x48b950
    if (cpu.flags.zf)
    {
        goto L_0x0048b950;
    }
    // 0048b93f  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0048b946  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0048b949  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048b94b  804c810c04             -or byte ptr [ecx + eax*4 + 0xc], 4
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */ + cpu.eax * 4) |= x86::reg8(x86::sreg8(4 /*0x4*/));
L_0x0048b950:
    // 0048b950  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0048b952  7447                   -je 0x48b99b
    if (cpu.flags.zf)
    {
        goto L_0x0048b99b;
    }
    // 0048b954  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048b956  7c1e                   -jl 0x48b976
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048b976;
    }
    // 0048b958  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0048b95f  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048b961  8a9660040000           -mov dl, byte ptr [esi + 0x460]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1120) /* 0x460 */);
    // 0048b967  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0048b96a  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 0048b96c  755b                   -jne 0x48b9c9
    if (!cpu.flags.zf)
    {
        goto L_0x0048b9c9;
    }
    // 0048b96e  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0048b971  8064020cef             -and byte ptr [edx + eax + 0xc], 0xef
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */ + cpu.eax * 1) &= x86::reg8(x86::sreg8(239 /*0xef*/));
L_0x0048b976:
    // 0048b976  80be5d04000000         +cmp byte ptr [esi + 0x45d], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1117) /* 0x45d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048b97d  740c                   -je 0x48b98b
    if (cpu.flags.zf)
    {
        goto L_0x0048b98b;
    }
    // 0048b97f  8b430c                 -mov eax, dword ptr [ebx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 0048b982  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0048b985  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0048b988  894618                 -mov dword ptr [esi + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.eax;
L_0x0048b98b:
    // 0048b98b  8b4354                 -mov eax, dword ptr [ebx + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(84) /* 0x54 */);
    // 0048b98e  89461c                 -mov dword ptr [esi + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0048b991  8a442404               -mov al, byte ptr [esp + 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048b995  88865c040000           -mov byte ptr [esi + 0x45c], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1116) /* 0x45c */) = cpu.al;
L_0x0048b99b:
    // 0048b99b  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048b99e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b99f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b9a0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b9a1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048b9a2:
    // 0048b9a2  8b4358                 -mov eax, dword ptr [ebx + 0x58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(88) /* 0x58 */);
    // 0048b9a5  e87afeffff             -call 0x48b824
    cpu.esp -= 4;
    sub_48b824(app, cpu);
    if (cpu.terminate) return;
    // 0048b9aa  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048b9ac  8b435c                 -mov eax, dword ptr [ebx + 0x5c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(92) /* 0x5c */);
    // 0048b9af  e870feffff             -call 0x48b824
    cpu.esp -= 4;
    sub_48b824(app, cpu);
    if (cpu.terminate) return;
    // 0048b9b4  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048b9b6  8b4360                 -mov eax, dword ptr [ebx + 0x60]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(96) /* 0x60 */);
    // 0048b9b9  e866feffff             -call 0x48b824
    cpu.esp -= 4;
    sub_48b824(app, cpu);
    if (cpu.terminate) return;
    // 0048b9be  01c1                   +add ecx, eax
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
    // 0048b9c0  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0048b9c4  e9a2feffff             -jmp 0x48b86b
    goto L_0x0048b86b;
L_0x0048b9c9:
    // 0048b9c9  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0048b9cc  804c020c10             +or byte ptr [edx + eax + 0xc], 0x10
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */ + cpu.eax * 1) |= x86::reg8(x86::sreg8(16 /*0x10*/))));
    // 0048b9d1  eba3                   -jmp 0x48b976
    goto L_0x0048b976;
}

/* align: skip 0x90 */
void Application::sub_48b9d4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b9d4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048b9d5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048b9d6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048b9d7  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0048b9da  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048b9dc  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0048b9de  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0048b9e0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048b9e1  8b15241b5600           -mov edx, dword ptr [0x561b24]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5643044) /* 0x561b24 */);
    // 0048b9e7  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048b9e8  2eff15bc434c00         -call dword ptr cs:[0x4c43bc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998076) /* 0x4c43bc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048b9ef  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048b9f3  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 0048b9f6  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048b9f8  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 0048b9fa  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048b9fe  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048ba02  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0048ba04  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 0048ba06  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0048ba09  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ba0a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ba0b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ba0c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48ba10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048ba10  a1241b5600             -mov eax, dword ptr [0x561b24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643044) /* 0x561b24 */);
    // 0048ba15  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48ba18(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048ba18  a13c1b5600             -mov eax, dword ptr [0x561b3c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5643068) /* 0x561b3c */);
    // 0048ba1d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48ba20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048ba20  a1d0165600             -mov eax, dword ptr [0x5616d0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5641936) /* 0x5616d0 */);
    // 0048ba25  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48ba28(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048ba28  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048ba29  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048ba2a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048ba2c  7414                   -je 0x48ba42
    if (cpu.flags.zf)
    {
        goto L_0x0048ba42;
    }
    // 0048ba2e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048ba30  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048ba31  8b15241b5600           -mov edx, dword ptr [0x561b24]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5643044) /* 0x561b24 */);
    // 0048ba37  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048ba38  2eff150c444c00         -call dword ptr cs:[0x4c440c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998156) /* 0x4c440c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048ba3f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ba40  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ba41  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048ba42:
    // 0048ba42  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 0048ba47  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048ba48  8b15241b5600           -mov edx, dword ptr [0x561b24]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5643044) /* 0x561b24 */);
    // 0048ba4e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048ba4f  2eff150c444c00         -call dword ptr cs:[0x4c440c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998156) /* 0x4c440c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048ba56  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ba57  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ba58  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48ba5c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048ba5c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048ba5d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048ba5e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048ba5f  6850d44800             -push 0x48d450
    app->getMemory<x86::reg32>(cpu.esp-4) = 4772944 /*0x48d450*/;
    cpu.esp -= 4;
    // 0048ba64  e881780300             -call 0x4c32ea
    cpu.esp -= 4;
    sub_4c32ea(app, cpu);
    if (cpu.terminate) return;
    // 0048ba69  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ba6a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ba6b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48ba6c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048ba6c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048ba6d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048ba6e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048ba6f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048ba70  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048ba71  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048ba72  81ecd8020000           -sub esp, 0x2d8
    (cpu.esp) -= x86::reg32(x86::sreg32(728 /*0x2d8*/));
    // 0048ba78  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048ba7a  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0048ba7c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048ba7e  7505                   -jne 0x48ba85
    if (!cpu.flags.zf)
    {
        goto L_0x0048ba85;
    }
    // 0048ba80  bbd0165600             -mov ebx, 0x5616d0
    cpu.ebx = 5641936 /*0x5616d0*/;
L_0x0048ba85:
    // 0048ba85  833dbc944d0000         +cmp dword ptr [0x4d94bc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5084348) /* 0x4d94bc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048ba8c  750a                   -jne 0x48ba98
    if (!cpu.flags.zf)
    {
        goto L_0x0048ba98;
    }
    // 0048ba8e  e8d5c8ffff             -call 0x488368
    cpu.esp -= 4;
    sub_488368(app, cpu);
    if (cpu.terminate) return;
    // 0048ba93  a3bc944d00             -mov dword ptr [0x4d94bc], eax
    app->getMemory<x86::reg32>(x86::reg32(5084348) /* 0x4d94bc */) = cpu.eax;
L_0x0048ba98:
    // 0048ba98  ba20215600             -mov edx, 0x562120
    cpu.edx = 5644576 /*0x562120*/;
    // 0048ba9d  a120215600             -mov eax, dword ptr [0x562120]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5644576) /* 0x562120 */);
    // 0048baa2  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048baa5  8b7a08                 -mov edi, dword ptr [edx + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0048baa8  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048baaa  8b6a0c                 -mov ebp, dword ptr [edx + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0048baad  09f8                   -or eax, edi
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edi));
    // 0048baaf  8a15a4894d00           -mov dl, byte ptr [0x4d89a4]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5081508) /* 0x4d89a4 */);
    // 0048bab5  09e8                   -or eax, ebp
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebp));
    // 0048bab7  f6c280                 +test dl, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 128 /*0x80*/));
    // 0048baba  7521                   -jne 0x48badd
    if (!cpu.flags.zf)
    {
        goto L_0x0048badd;
    }
    // 0048babc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048babe  740e                   -je 0x48bace
    if (cpu.flags.zf)
    {
        goto L_0x0048bace;
    }
    // 0048bac0  ba20215600             -mov edx, 0x562120
    cpu.edx = 5644576 /*0x562120*/;
    // 0048bac5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048bac7  e894faffff             -call 0x48b560
    cpu.esp -= 4;
    sub_48b560(app, cpu);
    if (cpu.terminate) return;
    // 0048bacc  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x0048bace:
    // 0048bace  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048bad0  750b                   -jne 0x48badd
    if (!cpu.flags.zf)
    {
        goto L_0x0048badd;
    }
    // 0048bad2  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048bad4  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048bad6  e885faffff             -call 0x48b560
    cpu.esp -= 4;
    sub_48b560(app, cpu);
    if (cpu.terminate) return;
    // 0048badb  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x0048badd:
    // 0048badd  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048badf  0f8420010000           -je 0x48bc05
    if (cpu.flags.zf)
    {
        goto L_0x0048bc05;
    }
L_0x0048bae5:
    // 0048bae5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048bae6  6828064e00             -push 0x4e0628
    app->getMemory<x86::reg32>(cpu.esp-4) = 5113384 /*0x4e0628*/;
    cpu.esp -= 4;
    // 0048baeb  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0048baed  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048baee  ff10                   -call dword ptr [eax]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048baf0  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048baf2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048baf3  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0048baf5  81e7ffff0000           -and edi, 0xffff
    cpu.edi &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0048bafb  ff5008                 -call dword ptr [eax + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048bafe  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0048bb00  0f853e010000           -jne 0x48bc44
    if (!cpu.flags.zf)
    {
        goto L_0x0048bc44;
    }
    // 0048bb06  b86c010000             -mov eax, 0x16c
    cpu.eax = 364 /*0x16c*/;
    // 0048bb0b  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0048bb0d  8984246c010000         -mov dword ptr [esp + 0x16c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(364) /* 0x16c */) = cpu.eax;
    // 0048bb14  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0048bb17  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048bb18  8d942470010000         -lea edx, [esp + 0x170]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(368) /* 0x170 */);
    // 0048bb1f  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0048bb21  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048bb22  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 0048bb24  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048bb25  ff562c                 -call dword ptr [esi + 0x2c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048bb28  8ab42473010000         -mov dh, byte ptr [esp + 0x173]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(371) /* 0x173 */);
    // 0048bb2f  893d6c9c4d00           -mov dword ptr [0x4d9c6c], edi
    app->getMemory<x86::reg32>(x86::reg32(5086316) /* 0x4d9c6c */) = cpu.edi;
    // 0048bb35  f6c608                 +test dh, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & 8 /*0x8*/));
    // 0048bb38  740a                   -je 0x48bb44
    if (cpu.flags.zf)
    {
        goto L_0x0048bb44;
    }
    // 0048bb3a  c7056c9c4d0008000000   -mov dword ptr [0x4d9c6c], 8
    app->getMemory<x86::reg32>(x86::reg32(5086316) /* 0x4d9c6c */) = 8 /*0x8*/;
L_0x0048bb44:
    // 0048bb44  f684247201000008       +test byte ptr [esp + 0x172], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(370) /* 0x172 */) & 8 /*0x8*/));
    // 0048bb4c  7407                   -je 0x48bb55
    if (cpu.flags.zf)
    {
        goto L_0x0048bb55;
    }
    // 0048bb4e  800d6d9c4d0008         -or byte ptr [0x4d9c6d], 8
    app->getMemory<x86::reg8>(x86::reg32(5086317) /* 0x4d9c6d */) |= x86::reg8(x86::sreg8(8 /*0x8*/));
L_0x0048bb55:
    // 0048bb55  f684247001000001       +test byte ptr [esp + 0x170], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(368) /* 0x170 */) & 1 /*0x1*/));
    // 0048bb5d  7407                   -je 0x48bb66
    if (cpu.flags.zf)
    {
        goto L_0x0048bb66;
    }
    // 0048bb5f  800d6c9c4d0020         -or byte ptr [0x4d9c6c], 0x20
    app->getMemory<x86::reg8>(x86::reg32(5086316) /* 0x4d9c6c */) |= x86::reg8(x86::sreg8(32 /*0x20*/));
L_0x0048bb66:
    // 0048bb66  8a942470010000         -mov dl, byte ptr [esp + 0x170]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(368) /* 0x170 */);
    // 0048bb6d  f6c201                 +test dl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 1 /*0x1*/));
    // 0048bb70  0f85c0000000           -jne 0x48bc36
    if (!cpu.flags.zf)
    {
        goto L_0x0048bc36;
    }
L_0x0048bb76:
    // 0048bb76  f684247001000040       +test byte ptr [esp + 0x170], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(368) /* 0x170 */) & 64 /*0x40*/));
    // 0048bb7e  7407                   -je 0x48bb87
    if (cpu.flags.zf)
    {
        goto L_0x0048bb87;
    }
    // 0048bb80  800d6c9c4d0040         -or byte ptr [0x4d9c6c], 0x40
    app->getMemory<x86::reg8>(x86::reg32(5086316) /* 0x4d9c6c */) |= x86::reg8(x86::sreg8(64 /*0x40*/));
L_0x0048bb87:
    // 0048bb87  f684247301000004       +test byte ptr [esp + 0x173], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(371) /* 0x173 */) & 4 /*0x4*/));
    // 0048bb8f  7407                   -je 0x48bb98
    if (cpu.flags.zf)
    {
        goto L_0x0048bb98;
    }
    // 0048bb91  800d6c9c4d0080         -or byte ptr [0x4d9c6c], 0x80
    app->getMemory<x86::reg8>(x86::reg32(5086316) /* 0x4d9c6c */) |= x86::reg8(x86::sreg8(128 /*0x80*/));
L_0x0048bb98:
    // 0048bb98  f684247101000002       +test byte ptr [esp + 0x171], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(369) /* 0x171 */) & 2 /*0x2*/));
    // 0048bba0  7407                   -je 0x48bba9
    if (cpu.flags.zf)
    {
        goto L_0x0048bba9;
    }
    // 0048bba2  800d6d9c4d0001         -or byte ptr [0x4d9c6d], 1
    app->getMemory<x86::reg8>(x86::reg32(5086317) /* 0x4d9c6d */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x0048bba9:
    // 0048bba9  f684247301000080       +test byte ptr [esp + 0x173], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(371) /* 0x173 */) & 128 /*0x80*/));
    // 0048bbb1  7407                   -je 0x48bbba
    if (cpu.flags.zf)
    {
        goto L_0x0048bbba;
    }
    // 0048bbb3  800d6d9c4d0004         -or byte ptr [0x4d9c6d], 4
    app->getMemory<x86::reg8>(x86::reg32(5086317) /* 0x4d9c6d */) |= x86::reg8(x86::sreg8(4 /*0x4*/));
L_0x0048bbba:
    // 0048bbba  f684247301000001       +test byte ptr [esp + 0x173], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(371) /* 0x173 */) & 1 /*0x1*/));
    // 0048bbc2  7411                   -je 0x48bbd5
    if (cpu.flags.zf)
    {
        goto L_0x0048bbd5;
    }
    // 0048bbc4  f684247901000002       +test byte ptr [esp + 0x179], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(377) /* 0x179 */) & 2 /*0x2*/));
    // 0048bbcc  7407                   -je 0x48bbd5
    if (cpu.flags.zf)
    {
        goto L_0x0048bbd5;
    }
    // 0048bbce  800d6d9c4d0002         -or byte ptr [0x4d9c6d], 2
    app->getMemory<x86::reg8>(x86::reg32(5086317) /* 0x4d9c6d */) |= x86::reg8(x86::sreg8(2 /*0x2*/));
L_0x0048bbd5:
    // 0048bbd5  f68424f001000010       +test byte ptr [esp + 0x1f0], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(496) /* 0x1f0 */) & 16 /*0x10*/));
    // 0048bbdd  7407                   -je 0x48bbe6
    if (cpu.flags.zf)
    {
        goto L_0x0048bbe6;
    }
    // 0048bbdf  800d6c9c4d0010         -or byte ptr [0x4d9c6c], 0x10
    app->getMemory<x86::reg8>(x86::reg32(5086316) /* 0x4d9c6c */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
L_0x0048bbe6:
    // 0048bbe6  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0048bbe8  893de0cc4d00           -mov dword ptr [0x4dcce0], edi
    app->getMemory<x86::reg32>(x86::reg32(5098720) /* 0x4dcce0 */) = cpu.edi;
L_0x0048bbee:
    // 0048bbee  833b00                 +cmp dword ptr [ebx], 0
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
    // 0048bbf1  7463                   -je 0x48bc56
    if (cpu.flags.zf)
    {
        goto L_0x0048bc56;
    }
    // 0048bbf3  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0048bbf8:
    // 0048bbf8  81c4d8020000           -add esp, 0x2d8
    (cpu.esp) += x86::reg32(x86::sreg32(728 /*0x2d8*/));
    // 0048bbfe  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bbff  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bc00  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bc01  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bc02  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bc03  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bc04  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048bc05:
    // 0048bc05  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 0048bc0a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048bc0c  e84ff9ffff             -call 0x48b560
    cpu.esp -= 4;
    sub_48b560(app, cpu);
    if (cpu.terminate) return;
    // 0048bc11  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048bc13  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048bc15  0f85cafeffff           -jne 0x48bae5
    if (!cpu.flags.zf)
    {
        goto L_0x0048bae5;
    }
    // 0048bc1b  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 0048bc1d  b83ce04c00             -mov eax, 0x4ce03c
    cpu.eax = 5038140 /*0x4ce03c*/;
    // 0048bc22  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048bc24  7509                   -jne 0x48bc2f
    if (!cpu.flags.zf)
    {
        goto L_0x0048bc2f;
    }
L_0x0048bc26:
    // 0048bc26  a3e0cc4d00             -mov dword ptr [0x4dcce0], eax
    app->getMemory<x86::reg32>(x86::reg32(5098720) /* 0x4dcce0 */) = cpu.eax;
    // 0048bc2b  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0048bc2d  ebc9                   -jmp 0x48bbf8
    goto L_0x0048bbf8;
L_0x0048bc2f:
    // 0048bc2f  b854e04c00             -mov eax, 0x4ce054
    cpu.eax = 5038164 /*0x4ce054*/;
    // 0048bc34  ebf0                   -jmp 0x48bc26
    goto L_0x0048bc26;
L_0x0048bc36:
    // 0048bc36  f6c202                 +test dl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 2 /*0x2*/));
    // 0048bc39  0f8437ffffff           -je 0x48bb76
    if (cpu.flags.zf)
    {
        goto L_0x0048bb76;
    }
    // 0048bc3f  e976ffffff             -jmp 0x48bbba
    goto L_0x0048bbba;
L_0x0048bc44:
    // 0048bc44  b858e04c00             -mov eax, 0x4ce058
    cpu.eax = 5038168 /*0x4ce058*/;
    // 0048bc49  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048bc4b  7518                   -jne 0x48bc65
    if (!cpu.flags.zf)
    {
        goto L_0x0048bc65;
    }
L_0x0048bc4d:
    // 0048bc4d  a3e0cc4d00             -mov dword ptr [0x4dcce0], eax
    app->getMemory<x86::reg32>(x86::reg32(5098720) /* 0x4dcce0 */) = cpu.eax;
    // 0048bc52  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0048bc54  7498                   -je 0x48bbee
    if (cpu.flags.zf)
    {
        goto L_0x0048bbee;
    }
L_0x0048bc56:
    // 0048bc56  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048bc58  81c4d8020000           +add esp, 0x2d8
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(728 /*0x2d8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048bc5e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bc5f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bc60  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bc61  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bc62  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bc63  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bc64  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048bc65:
    // 0048bc65  b854e04c00             -mov eax, 0x4ce054
    cpu.eax = 5038164 /*0x4ce054*/;
    // 0048bc6a  ebe1                   -jmp 0x48bc4d
    goto L_0x0048bc4d;
}

/* align: skip  */
void Application::sub_48bc6c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048bc6c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048bc6d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048bc6e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048bc6f  81ecd8020000           -sub esp, 0x2d8
    (cpu.esp) -= x86::reg32(x86::sreg32(728 /*0x2d8*/));
    // 0048bc75  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048bc77  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0048bc79  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0048bc7b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048bc7d  7505                   -jne 0x48bc84
    if (!cpu.flags.zf)
    {
        goto L_0x0048bc84;
    }
    // 0048bc7f  bed0165600             -mov esi, 0x5616d0
    cpu.esi = 5641936 /*0x5616d0*/;
L_0x0048bc84:
    // 0048bc84  833e00                 +cmp dword ptr [esi], 0
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
    // 0048bc87  750e                   -jne 0x48bc97
    if (!cpu.flags.zf)
    {
        goto L_0x0048bc97;
    }
L_0x0048bc89:
    // 0048bc89  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048bc8b  81c4d8020000           -add esp, 0x2d8
    (cpu.esp) += x86::reg32(x86::sreg32(728 /*0x2d8*/));
    // 0048bc91  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bc92  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bc93  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bc94  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0048bc97:
    // 0048bc97  b96c010000             -mov ecx, 0x16c
    cpu.ecx = 364 /*0x16c*/;
    // 0048bc9c  898c246c010000         -mov dword ptr [esp + 0x16c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(364) /* 0x16c */) = cpu.ecx;
    // 0048bca3  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 0048bca6  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 0048bca8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048bca9  8d8c2470010000         -lea ecx, [esp + 0x170]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(368) /* 0x170 */);
    // 0048bcb0  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0048bcb2  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048bcb3  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0048bcb5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048bcb6  ff522c                 -call dword ptr [edx + 0x2c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(44) /* 0x2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048bcb9  66a9ffff               +test ax, 0xffff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & 65535 /*0xffff*/));
    // 0048bcbd  75ca                   -jne 0x48bc89
    if (!cpu.flags.zf)
    {
        goto L_0x0048bc89;
    }
    // 0048bcbf  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0048bcc1  740a                   -je 0x48bccd
    if (cpu.flags.zf)
    {
        goto L_0x0048bccd;
    }
    // 0048bcc3  8b8424a8010000         -mov eax, dword ptr [esp + 0x1a8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(424) /* 0x1a8 */);
    // 0048bcca  894500                 -mov dword ptr [ebp], eax
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
L_0x0048bccd:
    // 0048bccd  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0048bccf  7409                   -je 0x48bcda
    if (cpu.flags.zf)
    {
        goto L_0x0048bcda;
    }
    // 0048bcd1  8b8424ac010000         -mov eax, dword ptr [esp + 0x1ac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(428) /* 0x1ac */);
    // 0048bcd8  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
L_0x0048bcda:
    // 0048bcda  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0048bcdc  7411                   -je 0x48bcef
    if (cpu.flags.zf)
    {
        goto L_0x0048bcef;
    }
    // 0048bcde  f684247301000008       +test byte ptr [esp + 0x173], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(371) /* 0x173 */) & 8 /*0x8*/));
    // 0048bce6  745c                   -je 0x48bd44
    if (cpu.flags.zf)
    {
        goto L_0x0048bd44;
    }
    // 0048bce8  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0048bced:
    // 0048bced  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
L_0x0048bcef:
    // 0048bcef  83bc24e802000000       +cmp dword ptr [esp + 0x2e8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(744) /* 0x2e8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048bcf7  742d                   -je 0x48bd26
    if (cpu.flags.zf)
    {
        goto L_0x0048bd26;
    }
    // 0048bcf9  6888d44800             -push 0x48d488
    app->getMemory<x86::reg32>(cpu.esp-4) = 4773000 /*0x48d488*/;
    cpu.esp -= 4;
    // 0048bcfe  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048bd00  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048bd01  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048bd02  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0048bd04  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0048bd06  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0048bd08  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048bd09  890d38215600           -mov dword ptr [0x562138], ecx
    app->getMemory<x86::reg32>(x86::reg32(5644600) /* 0x562138 */) = cpu.ecx;
    // 0048bd0f  890d30215600           -mov dword ptr [0x562130], ecx
    app->getMemory<x86::reg32>(x86::reg32(5644592) /* 0x562130 */) = cpu.ecx;
    // 0048bd15  ff5220                 -call dword ptr [edx + 0x20]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048bd18  8b9424e8020000         -mov edx, dword ptr [esp + 0x2e8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(744) /* 0x2e8 */);
    // 0048bd1f  a130215600             -mov eax, dword ptr [0x562130]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5644592) /* 0x562130 */);
    // 0048bd24  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
L_0x0048bd26:
    // 0048bd26  833d3821560000         +cmp dword ptr [0x562138], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5644600) /* 0x562138 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048bd2d  0f8e56ffffff           -jle 0x48bc89
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048bc89;
    }
    // 0048bd33  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048bd38  81c4d8020000           -add esp, 0x2d8
    (cpu.esp) += x86::reg32(x86::sreg32(728 /*0x2d8*/));
    // 0048bd3e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bd3f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bd40  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bd41  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0048bd44:
    // 0048bd44  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0048bd46  eba5                   -jmp 0x48bced
    goto L_0x0048bced;
}

/* align: skip  */
void Application::sub_48bd48(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048bd48  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048bd49  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048bd4a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048bd4b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048bd4c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048bd4d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048bd4e  8b3de0cc4d00           -mov edi, dword ptr [0x4dcce0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5098720) /* 0x4dcce0 */);
    // 0048bd54  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048bd56  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048bd58  7505                   -jne 0x48bd5f
    if (!cpu.flags.zf)
    {
        goto L_0x0048bd5f;
    }
    // 0048bd5a  bed0165600             -mov esi, 0x5616d0
    cpu.esi = 5641936 /*0x5616d0*/;
L_0x0048bd5f:
    // 0048bd5f  833e00                 +cmp dword ptr [esi], 0
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
    // 0048bd62  7521                   -jne 0x48bd85
    if (!cpu.flags.zf)
    {
        goto L_0x0048bd85;
    }
    // 0048bd64  b87ce04c00             -mov eax, 0x4ce07c
    cpu.eax = 5038204 /*0x4ce07c*/;
    // 0048bd69  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048bd6b  7511                   -jne 0x48bd7e
    if (!cpu.flags.zf)
    {
        goto L_0x0048bd7e;
    }
L_0x0048bd6d:
    // 0048bd6d  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048bd6f  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0048bd71  893de0cc4d00           -mov dword ptr [0x4dcce0], edi
    app->getMemory<x86::reg32>(x86::reg32(5098720) /* 0x4dcce0 */) = cpu.edi;
    // 0048bd77  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bd78  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bd79  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bd7a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bd7b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bd7c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bd7d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048bd7e:
    // 0048bd7e  b854e04c00             -mov eax, 0x4ce054
    cpu.eax = 5038164 /*0x4ce054*/;
    // 0048bd83  ebe8                   -jmp 0x48bd6d
    goto L_0x0048bd6d;
L_0x0048bd85:
    // 0048bd85  83be5404000000         +cmp dword ptr [esi + 0x454], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1108) /* 0x454 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048bd8c  751f                   -jne 0x48bdad
    if (!cpu.flags.zf)
    {
        goto L_0x0048bdad;
    }
    // 0048bd8e  b89ce04c00             -mov eax, 0x4ce09c
    cpu.eax = 5038236 /*0x4ce09c*/;
    // 0048bd93  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048bd95  74d6                   -je 0x48bd6d
    if (cpu.flags.zf)
    {
        goto L_0x0048bd6d;
    }
    // 0048bd97  b854e04c00             -mov eax, 0x4ce054
    cpu.eax = 5038164 /*0x4ce054*/;
    // 0048bd9c  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048bd9e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048bda0  893de0cc4d00           -mov dword ptr [0x4dcce0], edi
    app->getMemory<x86::reg32>(x86::reg32(5098720) /* 0x4dcce0 */) = cpu.edi;
    // 0048bda6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bda7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bda8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bda9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bdaa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bdab  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bdac  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048bdad:
    // 0048bdad  80be5d04000000         +cmp byte ptr [esi + 0x45d], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1117) /* 0x45d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048bdb4  744f                   -je 0x48be05
    if (cpu.flags.zf)
    {
        goto L_0x0048be05;
    }
    // 0048bdb6  b811000000             -mov eax, 0x11
    cpu.eax = 17 /*0x11*/;
    // 0048bdbb  8b1d709c4d00           -mov ebx, dword ptr [0x4d9c70]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5086320) /* 0x4d9c70 */);
    // 0048bdc1  893de0cc4d00           -mov dword ptr [0x4dcce0], edi
    app->getMemory<x86::reg32>(x86::reg32(5098720) /* 0x4dcce0 */) = cpu.edi;
    // 0048bdc7  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0048bdc9  7405                   -je 0x48bdd0
    if (cpu.flags.zf)
    {
        goto L_0x0048bdd0;
    }
    // 0048bdcb  b851000000             -mov eax, 0x51
    cpu.eax = 81 /*0x51*/;
L_0x0048bdd0:
    // 0048bdd0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048bdd1  8bae54040000           -mov ebp, dword ptr [esi + 0x454]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1108) /* 0x454 */);
    // 0048bdd7  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 0048bdd9  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048bdda  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 0048bddc  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048bddd  ff5150                 -call dword ptr [ecx + 0x50]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(80) /* 0x50 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048bde0  25ffff0000             +and eax, 0xffff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/))));
    // 0048bde5  742b                   -je 0x48be12
    if (cpu.flags.zf)
    {
        goto L_0x0048be12;
    }
    // 0048bde7  b810e14c00             -mov eax, 0x4ce110
    cpu.eax = 5038352 /*0x4ce110*/;
    // 0048bdec  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048bdee  0f85ba000000           -jne 0x48beae
    if (!cpu.flags.zf)
    {
        goto L_0x0048beae;
    }
    // 0048bdf4  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048bdf6  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0048bdf8  893de0cc4d00           -mov dword ptr [0x4dcce0], edi
    app->getMemory<x86::reg32>(x86::reg32(5098720) /* 0x4dcce0 */) = cpu.edi;
    // 0048bdfe  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bdff  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048be00  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048be01  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048be02  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048be03  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048be04  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048be05:
    // 0048be05  b808000000             -mov eax, 8
    cpu.eax = 8 /*0x8*/;
    // 0048be0a  893de0cc4d00           -mov dword ptr [0x4dcce0], edi
    app->getMemory<x86::reg32>(x86::reg32(5098720) /* 0x4dcce0 */) = cpu.edi;
    // 0048be10  ebbe                   -jmp 0x48bdd0
    goto L_0x0048bdd0;
L_0x0048be12:
    // 0048be12  6888d44800             -push 0x48d488
    app->getMemory<x86::reg32>(cpu.esp-4) = 4773000 /*0x48d488*/;
    cpu.esp -= 4;
    // 0048be17  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048be18  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048be1a  a338215600             -mov dword ptr [0x562138], eax
    app->getMemory<x86::reg32>(x86::reg32(5644600) /* 0x562138 */) = cpu.eax;
    // 0048be1f  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0048be21  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0048be23  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0048be25  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048be26  ff5220                 -call dword ptr [edx + 0x20]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048be29  25ffff0000             +and eax, 0xffff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/))));
    // 0048be2e  7423                   -je 0x48be53
    if (cpu.flags.zf)
    {
        goto L_0x0048be53;
    }
    // 0048be30  b8b8e04c00             -mov eax, 0x4ce0b8
    cpu.eax = 5038264 /*0x4ce0b8*/;
    // 0048be35  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048be37  0f8430ffffff           -je 0x48bd6d
    if (cpu.flags.zf)
    {
        goto L_0x0048bd6d;
    }
    // 0048be3d  b854e04c00             -mov eax, 0x4ce054
    cpu.eax = 5038164 /*0x4ce054*/;
    // 0048be42  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048be44  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048be46  893de0cc4d00           -mov dword ptr [0x4dcce0], edi
    app->getMemory<x86::reg32>(x86::reg32(5098720) /* 0x4dcce0 */) = cpu.edi;
    // 0048be4c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048be4d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048be4e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048be4f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048be50  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048be51  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048be52  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048be53:
    // 0048be53  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0048be56  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048be58  740e                   -je 0x48be68
    if (cpu.flags.zf)
    {
        goto L_0x0048be68;
    }
    // 0048be5a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048be5c  e80b6fffff             -call 0x482d6c
    cpu.esp -= 4;
    sub_482d6c(app, cpu);
    if (cpu.terminate) return;
    // 0048be61  c7461000000000         -mov dword ptr [esi + 0x10], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
L_0x0048be68:
    // 0048be68  a138215600             -mov eax, dword ptr [0x562138]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5644600) /* 0x562138 */);
    // 0048be6d  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0048be70  83f810                 +cmp eax, 0x10
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
    // 0048be73  7d07                   -jge 0x48be7c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048be7c;
    }
    // 0048be75  c7460810000000         -mov dword ptr [esi + 8], 0x10
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = 16 /*0x10*/;
L_0x0048be7c:
    // 0048be7c  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0048be7f  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0048be86  bb00030000             -mov ebx, 0x300
    cpu.ebx = 768 /*0x300*/;
    // 0048be8b  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048be8d  b8dce04c00             -mov eax, 0x4ce0dc
    cpu.eax = 5038300 /*0x4ce0dc*/;
    // 0048be92  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0048be95  e86e6affff             -call 0x482908
    cpu.esp -= 4;
    sub_482908(app, cpu);
    if (cpu.terminate) return;
    // 0048be9a  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0048be9d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048be9f  7523                   -jne 0x48bec4
    if (!cpu.flags.zf)
    {
        goto L_0x0048bec4;
    }
    // 0048bea1  b8e8e04c00             -mov eax, 0x4ce0e8
    cpu.eax = 5038312 /*0x4ce0e8*/;
    // 0048bea6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048bea8  0f84bffeffff           -je 0x48bd6d
    if (cpu.flags.zf)
    {
        goto L_0x0048bd6d;
    }
L_0x0048beae:
    // 0048beae  b854e04c00             -mov eax, 0x4ce054
    cpu.eax = 5038164 /*0x4ce054*/;
    // 0048beb3  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048beb5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048beb7  893de0cc4d00           -mov dword ptr [0x4dcce0], edi
    app->getMemory<x86::reg32>(x86::reg32(5098720) /* 0x4dcce0 */) = cpu.edi;
    // 0048bebd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bebe  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bebf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bec0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bec1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bec2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bec3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048bec4:
    // 0048bec4  6888d44800             -push 0x48d488
    app->getMemory<x86::reg32>(cpu.esp-4) = 4773000 /*0x48d488*/;
    cpu.esp -= 4;
    // 0048bec9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048beca  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0048becc  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048becd  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0048becf  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0048bed1  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0048bed3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048bed4  892d34215600           -mov dword ptr [0x562134], ebp
    app->getMemory<x86::reg32>(x86::reg32(5644596) /* 0x562134 */) = cpu.ebp;
    // 0048beda  892d38215600           -mov dword ptr [0x562138], ebp
    app->getMemory<x86::reg32>(x86::reg32(5644600) /* 0x562138 */) = cpu.ebp;
    // 0048bee0  ff5220                 -call dword ptr [edx + 0x20]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048bee3  c7462800030000         -mov dword ptr [esi + 0x28], 0x300
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = 768 /*0x300*/;
    // 0048beea  c7462c00010000         -mov dword ptr [esi + 0x2c], 0x100
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */) = 256 /*0x100*/;
    // 0048bef1  a138215600             -mov eax, dword ptr [0x562138]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5644600) /* 0x562138 */);
    // 0048bef6  8a965d040000           -mov dl, byte ptr [esi + 0x45d]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1117) /* 0x45d */);
    // 0048befc  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0048beff  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 0048bf01  7539                   -jne 0x48bf3c
    if (!cpu.flags.zf)
    {
        goto L_0x0048bf3c;
    }
    // 0048bf03  837e0400               +cmp dword ptr [esi + 4], 0
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
    // 0048bf07  7533                   -jne 0x48bf3c
    if (!cpu.flags.zf)
    {
        goto L_0x0048bf3c;
    }
    // 0048bf09  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048bf0a  8d4e04                 -lea ecx, [esi + 4]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0048bf0d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048bf0e  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0048bf10  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048bf11  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0048bf13  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048bf14  ff5210                 -call dword ptr [edx + 0x10]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048bf17  8b8e54040000           -mov ecx, dword ptr [esi + 0x454]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1108) /* 0x454 */);
    // 0048bf1d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048bf1e  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0048bf21  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048bf22  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0048bf24  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048bf25  ff5220                 -call dword ptr [edx + 0x20]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048bf28  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048bf2d  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0048bf2f  893de0cc4d00           -mov dword ptr [0x4dcce0], edi
    app->getMemory<x86::reg32>(x86::reg32(5098720) /* 0x4dcce0 */) = cpu.edi;
    // 0048bf35  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bf36  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bf37  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bf38  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bf39  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bf3a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bf3b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048bf3c:
    // 0048bf3c  c7460400000000         -mov dword ptr [esi + 4], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0048bf43  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048bf48  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0048bf4a  893de0cc4d00           -mov dword ptr [0x4dcce0], edi
    app->getMemory<x86::reg32>(x86::reg32(5098720) /* 0x4dcce0 */) = cpu.edi;
    // 0048bf50  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bf51  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bf52  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bf53  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bf54  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bf55  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bf56  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48bf58(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048bf58  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048bf59  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048bf5a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048bf5b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048bf5c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048bf5d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048bf5e  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048bf60  83b84404000000         +cmp dword ptr [eax + 0x444], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1092) /* 0x444 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048bf67  740c                   -je 0x48bf75
    if (cpu.flags.zf)
    {
        goto L_0x0048bf75;
    }
    // 0048bf69  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0048bf6b  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048bf6d  7406                   -je 0x48bf75
    if (cpu.flags.zf)
    {
        goto L_0x0048bf75;
    }
    // 0048bf6f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048bf70  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0048bf72  ff5228                 -call dword ptr [edx + 0x28]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(40) /* 0x28 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0048bf75:
    // 0048bf75  8bb350040000           -mov esi, dword ptr [ebx + 0x450]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1104) /* 0x450 */);
    // 0048bf7b  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048bf7d  7407                   -je 0x48bf86
    if (cpu.flags.zf)
    {
        goto L_0x0048bf86;
    }
    // 0048bf7f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048bf81  e802c60100             -call 0x4a8588
    cpu.esp -= 4;
    sub_4a8588(app, cpu);
    if (cpu.terminate) return;
L_0x0048bf86:
    // 0048bf86  8bbb4c040000           -mov edi, dword ptr [ebx + 0x44c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1100) /* 0x44c */);
    // 0048bf8c  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0048bf8e  7407                   -je 0x48bf97
    if (cpu.flags.zf)
    {
        goto L_0x0048bf97;
    }
    // 0048bf90  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048bf92  e8f1c50100             -call 0x4a8588
    cpu.esp -= 4;
    sub_4a8588(app, cpu);
    if (cpu.terminate) return;
L_0x0048bf97:
    // 0048bf97  c7835004000000000000   -mov dword ptr [ebx + 0x450], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1104) /* 0x450 */) = 0 /*0x0*/;
    // 0048bfa1  8bab48040000           -mov ebp, dword ptr [ebx + 0x448]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1096) /* 0x448 */);
    // 0048bfa7  c7834c04000000000000   -mov dword ptr [ebx + 0x44c], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1100) /* 0x44c */) = 0 /*0x0*/;
    // 0048bfb1  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0048bfb3  7409                   -je 0x48bfbe
    if (cpu.flags.zf)
    {
        goto L_0x0048bfbe;
    }
    // 0048bfb5  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0048bfb7  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048bfb9  e87a100000             -call 0x48d038
    cpu.esp -= 4;
    sub_48d038(app, cpu);
    if (cpu.terminate) return;
L_0x0048bfbe:
    // 0048bfbe  8b8344040000           -mov eax, dword ptr [ebx + 0x444]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1092) /* 0x444 */);
    // 0048bfc4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048bfc6  7520                   -jne 0x48bfe8
    if (!cpu.flags.zf)
    {
        goto L_0x0048bfe8;
    }
L_0x0048bfc8:
    // 0048bfc8  c7834804000000000000   -mov dword ptr [ebx + 0x448], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1096) /* 0x448 */) = 0 /*0x0*/;
    // 0048bfd2  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048bfd7  c7834404000000000000   -mov dword ptr [ebx + 0x444], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1092) /* 0x444 */) = 0 /*0x0*/;
    // 0048bfe1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bfe2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bfe3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bfe4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bfe5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bfe6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bfe7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048bfe8:
    // 0048bfe8  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048bfea  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048bfec  e847100000             -call 0x48d038
    cpu.esp -= 4;
    sub_48d038(app, cpu);
    if (cpu.terminate) return;
    // 0048bff1  ebd5                   -jmp 0x48bfc8
    goto L_0x0048bfc8;
}

/* align: skip 0x90 */
void Application::sub_48bff4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048bff4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048bff5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048bff6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048bff7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048bff8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048bff9  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048bffa  81ec44030000           -sub esp, 0x344
    (cpu.esp) -= x86::reg32(x86::sreg32(836 /*0x344*/));
    // 0048c000  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048c002  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048c004  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048c006  7505                   -jne 0x48c00d
    if (!cpu.flags.zf)
    {
        goto L_0x0048c00d;
    }
    // 0048c008  bed0165600             -mov esi, 0x5616d0
    cpu.esi = 5641936 /*0x5616d0*/;
L_0x0048c00d:
    // 0048c00d  a1bc944d00             -mov eax, dword ptr [0x4d94bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5084348) /* 0x4d94bc */);
    // 0048c012  e8a1c3ffff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 0048c017  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048c019  ba6c010000             -mov edx, 0x16c
    cpu.edx = 364 /*0x16c*/;
    // 0048c01e  e835ffffff             -call 0x48bf58
    cpu.esp -= 4;
    sub_48bf58(app, cpu);
    if (cpu.terminate) return;
    // 0048c023  8994246c010000         -mov dword ptr [esp + 0x16c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(364) /* 0x16c */) = cpu.edx;
    // 0048c02a  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0048c02d  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0048c02f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048c030  8d942470010000         -lea edx, [esp + 0x170]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(368) /* 0x170 */);
    // 0048c037  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0048c039  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048c03a  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0048c03c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048c03d  ff512c                 -call dword ptr [ecx + 0x2c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048c040  8aa637040000           -mov ah, byte ptr [esi + 0x437]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1079) /* 0x437 */);
    // 0048c046  80fc01                 +cmp ah, 1
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
    // 0048c049  0f8340010000           -jae 0x48c18f
    if (!cpu.flags.cf)
    {
        goto L_0x0048c18f;
    }
    // 0048c04f  c6863704000001         -mov byte ptr [esi + 0x437], 1
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1079) /* 0x437 */) = 1 /*0x1*/;
L_0x0048c056:
    // 0048c056  f68424f001000010       +test byte ptr [esp + 0x1f0], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(496) /* 0x1f0 */) & 16 /*0x10*/));
    // 0048c05e  0f8462010000           -je 0x48c1c6
    if (cpu.flags.zf)
    {
        goto L_0x0048c1c6;
    }
    // 0048c064  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
L_0x0048c066:
    // 0048c066  888660040000           -mov byte ptr [esi + 0x460], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1120) /* 0x460 */) = cpu.al;
    // 0048c06c  f684247301000008       +test byte ptr [esp + 0x173], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(371) /* 0x173 */) & 8 /*0x8*/));
    // 0048c074  0f8453010000           -je 0x48c1cd
    if (cpu.flags.zf)
    {
        goto L_0x0048c1cd;
    }
    // 0048c07a  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
L_0x0048c07c:
    // 0048c07c  8aae5e040000           -mov ch, byte ptr [esi + 0x45e]
    cpu.ch = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1118) /* 0x45e */);
    // 0048c082  888662040000           -mov byte ptr [esi + 0x462], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1122) /* 0x462 */) = cpu.al;
    // 0048c088  84ed                   +test ch, ch
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & cpu.ch));
    // 0048c08a  0f8544010000           -jne 0x48c1d4
    if (!cpu.flags.zf)
    {
        goto L_0x0048c1d4;
    }
    // 0048c090  80be3604000000         +cmp byte ptr [esi + 0x436], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1078) /* 0x436 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048c097  740e                   -je 0x48c0a7
    if (cpu.flags.zf)
    {
        goto L_0x0048c0a7;
    }
    // 0048c099  c6863504000001         -mov byte ptr [esi + 0x435], 1
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1077) /* 0x435 */) = 1 /*0x1*/;
    // 0048c0a0  c6863404000001         -mov byte ptr [esi + 0x434], 1
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1076) /* 0x434 */) = 1 /*0x1*/;
L_0x0048c0a7:
    // 0048c0a7  81fed0165600           +cmp esi, 0x5616d0
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5641936 /*0x5616d0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048c0ad  7503                   -jne 0x48c0b2
    if (!cpu.flags.zf)
    {
        goto L_0x0048c0b2;
    }
    // 0048c0af  80cf02                 -or bh, 2
    cpu.bh |= x86::reg8(x86::sreg8(2 /*0x2*/));
L_0x0048c0b2:
    // 0048c0b2  80be6304000001         +cmp byte ptr [esi + 0x463], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1123) /* 0x463 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048c0b9  762f                   -jbe 0x48c0ea
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0048c0ea;
    }
    // 0048c0bb  80be3504000000         +cmp byte ptr [esi + 0x435], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1077) /* 0x435 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048c0c2  0f8430010000           -je 0x48c1f8
    if (cpu.flags.zf)
    {
        goto L_0x0048c1f8;
    }
L_0x0048c0c8:
    // 0048c0c8  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0048c0cd:
    // 0048c0cd  80be6004000000         +cmp byte ptr [esi + 0x460], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1120) /* 0x460 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048c0d4  0f8532010000           -jne 0x48c20c
    if (!cpu.flags.zf)
    {
        goto L_0x0048c20c;
    }
    // 0048c0da  80be6204000000         +cmp byte ptr [esi + 0x462], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1122) /* 0x462 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048c0e1  0f8425010000           -je 0x48c20c
    if (cpu.flags.zf)
    {
        goto L_0x0048c20c;
    }
L_0x0048c0e7:
    // 0048c0e7  80cf08                 -or bh, 8
    cpu.bh |= x86::reg8(x86::sreg8(8 /*0x8*/));
L_0x0048c0ea:
    // 0048c0ea  8b7e24                 -mov edi, dword ptr [esi + 0x24]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 0048c0ed  8d4630                 -lea eax, [esi + 0x30]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(48) /* 0x30 */);
    // 0048c0f0  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0048c0f2  0f852e010000           -jne 0x48c226
    if (!cpu.flags.zf)
    {
        goto L_0x0048c226;
    }
    // 0048c0f8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048c0f9  8d7e24                 -lea edi, [esi + 0x24]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 0048c0fc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048c0fd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048c0fe  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 0048c100  6a44                   -push 0x44
    app->getMemory<x86::reg32>(cpu.esp-4) = 68 /*0x44*/;
    cpu.esp -= 4;
    // 0048c102  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 0048c104  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048c105  ff5114                 -call dword ptr [ecx + 0x14]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0048c108:
    // 0048c108  66c786300400000000     -mov word ptr [esi + 0x430], 0
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(1072) /* 0x430 */) = 0 /*0x0*/;
    // 0048c111  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0048c113  66c78632040000ff00     -mov word ptr [esi + 0x432], 0xff
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(1074) /* 0x432 */) = 255 /*0xff*/;
    // 0048c11c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048c11e  c6865f04000000         -mov byte ptr [esi + 0x45f], 0
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1119) /* 0x45f */) = 0 /*0x0*/;
    // 0048c125  e866f4ffff             -call 0x48b590
    cpu.esp -= 4;
    sub_48b590(app, cpu);
    if (cpu.terminate) return;
    // 0048c12a  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048c12c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048c12e  0f8507010000           -jne 0x48c23b
    if (!cpu.flags.zf)
    {
        goto L_0x0048c23b;
    }
    // 0048c134  c6865f04000001         -mov byte ptr [esi + 0x45f], 1
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1119) /* 0x45f */) = 1 /*0x1*/;
L_0x0048c13b:
    // 0048c13b  c6863704000002         -mov byte ptr [esi + 0x437], 2
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1079) /* 0x437 */) = 2 /*0x2*/;
    // 0048c142  8a8637040000           -mov al, byte ptr [esi + 0x437]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1079) /* 0x437 */);
    // 0048c148  888663040000           -mov byte ptr [esi + 0x463], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1123) /* 0x463 */) = cpu.al;
    // 0048c14e  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0048c150  7409                   -je 0x48c15b
    if (cpu.flags.zf)
    {
        goto L_0x0048c15b;
    }
    // 0048c152  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0048c154  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048c156  e8dd0e0000             -call 0x48d038
    cpu.esp -= 4;
    sub_48d038(app, cpu);
    if (cpu.terminate) return;
L_0x0048c15b:
    // 0048c15b  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0048c15d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048c15f  e82cf4ffff             -call 0x48b590
    cpu.esp -= 4;
    sub_48b590(app, cpu);
    if (cpu.terminate) return;
    // 0048c164  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x0048c166:
    // 0048c166  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0048c168  0f8534010000           -jne 0x48c2a2
    if (!cpu.flags.zf)
    {
        goto L_0x0048c2a2;
    }
    // 0048c16e  b898e14c00             -mov eax, 0x4ce198
    cpu.eax = 5038488 /*0x4ce198*/;
    // 0048c173  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048c175  0f850e010000           -jne 0x48c289
    if (!cpu.flags.zf)
    {
        goto L_0x0048c289;
    }
    // 0048c17b  a3e0cc4d00             -mov dword ptr [0x4dcce0], eax
    app->getMemory<x86::reg32>(x86::reg32(5098720) /* 0x4dcce0 */) = cpu.eax;
    // 0048c180  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048c182  81c444030000           -add esp, 0x344
    (cpu.esp) += x86::reg32(x86::sreg32(836 /*0x344*/));
    // 0048c188  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c189  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c18a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c18b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c18c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c18d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c18e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048c18f:
    // 0048c18f  80fc02                 +cmp ah, 2
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
    // 0048c192  0f86befeffff           -jbe 0x48c056
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0048c056;
    }
    // 0048c198  b874e14c00             -mov eax, 0x4ce174
    cpu.eax = 5038452 /*0x4ce174*/;
    // 0048c19d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048c19f  751e                   -jne 0x48c1bf
    if (!cpu.flags.zf)
    {
        goto L_0x0048c1bf;
    }
L_0x0048c1a1:
    // 0048c1a1  a3e0cc4d00             -mov dword ptr [0x4dcce0], eax
    app->getMemory<x86::reg32>(x86::reg32(5098720) /* 0x4dcce0 */) = cpu.eax;
    // 0048c1a6  a1bc944d00             -mov eax, dword ptr [0x4d94bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5084348) /* 0x4d94bc */);
    // 0048c1ab  e820c2ffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0048c1b0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048c1b2  81c444030000           +add esp, 0x344
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(836 /*0x344*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048c1b8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c1b9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c1ba  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c1bb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c1bc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c1bd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c1be  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048c1bf:
    // 0048c1bf  b854e04c00             -mov eax, 0x4ce054
    cpu.eax = 5038164 /*0x4ce054*/;
    // 0048c1c4  ebdb                   -jmp 0x48c1a1
    goto L_0x0048c1a1;
L_0x0048c1c6:
    // 0048c1c6  30c0                   +xor al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al ^= x86::reg8(x86::sreg8(cpu.al))));
    // 0048c1c8  e999feffff             -jmp 0x48c066
    goto L_0x0048c066;
L_0x0048c1cd:
    // 0048c1cd  30c0                   +xor al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al ^= x86::reg8(x86::sreg8(cpu.al))));
    // 0048c1cf  e9a8feffff             -jmp 0x48c07c
    goto L_0x0048c07c;
L_0x0048c1d4:
    // 0048c1d4  c6863604000000         -mov byte ptr [esi + 0x436], 0
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1078) /* 0x436 */) = 0 /*0x0*/;
    // 0048c1db  c6863504000001         -mov byte ptr [esi + 0x435], 1
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1077) /* 0x435 */) = 1 /*0x1*/;
    // 0048c1e2  c6863704000002         -mov byte ptr [esi + 0x437], 2
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1079) /* 0x437 */) = 2 /*0x2*/;
    // 0048c1e9  80cf2a                 +or bh, 0x2a
    cpu.clear_co();
    cpu.set_szp((cpu.bh |= x86::reg8(x86::sreg8(42 /*0x2a*/))));
    // 0048c1ec  c6866304000001         -mov byte ptr [esi + 0x463], 1
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1123) /* 0x463 */) = 1 /*0x1*/;
    // 0048c1f3  e9affeffff             -jmp 0x48c0a7
    goto L_0x0048c0a7;
L_0x0048c1f8:
    // 0048c1f8  80be3404000000         +cmp byte ptr [esi + 0x434], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1076) /* 0x434 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048c1ff  0f85c3feffff           -jne 0x48c0c8
    if (!cpu.flags.zf)
    {
        goto L_0x0048c0c8;
    }
    // 0048c205  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0048c207  e9c1feffff             -jmp 0x48c0cd
    goto L_0x0048c0cd;
L_0x0048c20c:
    // 0048c20c  80be5e04000000         +cmp byte ptr [esi + 0x45e], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1118) /* 0x45e */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048c213  7408                   -je 0x48c21d
    if (cpu.flags.zf)
    {
        goto L_0x0048c21d;
    }
L_0x0048c215:
    // 0048c215  80cf40                 +or bh, 0x40
    cpu.clear_co();
    cpu.set_szp((cpu.bh |= x86::reg8(x86::sreg8(64 /*0x40*/))));
    // 0048c218  e9cdfeffff             -jmp 0x48c0ea
    goto L_0x0048c0ea;
L_0x0048c21d:
    // 0048c21d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048c21f  74f4                   -je 0x48c215
    if (cpu.flags.zf)
    {
        goto L_0x0048c215;
    }
    // 0048c221  e9c1feffff             -jmp 0x48c0e7
    goto L_0x0048c0e7;
L_0x0048c226:
    // 0048c226  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048c227  6800010000             -push 0x100
    app->getMemory<x86::reg32>(cpu.esp-4) = 256 /*0x100*/;
    cpu.esp -= 4;
    // 0048c22c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048c22e  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048c230  8b0f                   -mov ecx, dword ptr [edi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi);
    // 0048c232  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048c233  ff5118                 -call dword ptr [ecx + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048c236  e9cdfeffff             -jmp 0x48c108
    goto L_0x0048c108;
L_0x0048c23b:
    // 0048c23b  8d8c24d8020000         -lea ecx, [esp + 0x2d8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(728) /* 0x2d8 */);
    // 0048c242  bd6c000000             -mov ebp, 0x6c
    cpu.ebp = 108 /*0x6c*/;
    // 0048c247  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048c248  89ac24dc020000         -mov dword ptr [esp + 0x2dc], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(732) /* 0x2dc */) = cpu.ebp;
    // 0048c24f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048c250  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0048c252  ff5258                 -call dword ptr [edx + 0x58]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048c255  f684244203000020       +test byte ptr [esp + 0x342], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(834) /* 0x342 */) & 32 /*0x20*/));
    // 0048c25d  7415                   -je 0x48c274
    if (cpu.flags.zf)
    {
        goto L_0x0048c274;
    }
    // 0048c25f  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
    // 0048c261  88865f040000           -mov byte ptr [esi + 0x45f], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1119) /* 0x45f */) = cpu.al;
    // 0048c267  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0048c269  0f85ccfeffff           -jne 0x48c13b
    if (!cpu.flags.zf)
    {
        goto L_0x0048c13b;
    }
    // 0048c26f  e9f2feffff             -jmp 0x48c166
    goto L_0x0048c166;
L_0x0048c274:
    // 0048c274  30c0                   -xor al, al
    cpu.al ^= x86::reg8(x86::sreg8(cpu.al));
    // 0048c276  88865f040000           -mov byte ptr [esi + 0x45f], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1119) /* 0x45f */) = cpu.al;
    // 0048c27c  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0048c27e  0f85b7feffff           -jne 0x48c13b
    if (!cpu.flags.zf)
    {
        goto L_0x0048c13b;
    }
    // 0048c284  e9ddfeffff             -jmp 0x48c166
    goto L_0x0048c166;
L_0x0048c289:
    // 0048c289  b854e04c00             -mov eax, 0x4ce054
    cpu.eax = 5038164 /*0x4ce054*/;
    // 0048c28e  a3e0cc4d00             -mov dword ptr [0x4dcce0], eax
    app->getMemory<x86::reg32>(x86::reg32(5098720) /* 0x4dcce0 */) = cpu.eax;
    // 0048c293  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048c295  81c444030000           -add esp, 0x344
    (cpu.esp) += x86::reg32(x86::sreg32(836 /*0x344*/));
    // 0048c29b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c29c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c29d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c29e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c29f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c2a0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c2a1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048c2a2:
    // 0048c2a2  837e0400               +cmp dword ptr [esi + 4], 0
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
    // 0048c2a6  7413                   -je 0x48c2bb
    if (cpu.flags.zf)
    {
        goto L_0x0048c2bb;
    }
    // 0048c2a8  80be5d04000000         +cmp byte ptr [esi + 0x45d], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1117) /* 0x45d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048c2af  750a                   -jne 0x48c2bb
    if (!cpu.flags.zf)
    {
        goto L_0x0048c2bb;
    }
    // 0048c2b1  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0048c2b4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048c2b5  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0048c2b7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048c2b8  ff5070                 -call dword ptr [eax + 0x70]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0048c2bb:
    // 0048c2bb  8d8424d8020000         -lea eax, [esp + 0x2d8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(728) /* 0x2d8 */);
    // 0048c2c2  b96c000000             -mov ecx, 0x6c
    cpu.ecx = 108 /*0x6c*/;
    // 0048c2c7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048c2c8  898c24dc020000         -mov dword ptr [esp + 0x2dc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(732) /* 0x2dc */) = cpu.ecx;
    // 0048c2cf  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048c2d0  8b17                   -mov edx, dword ptr [edi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi);
    // 0048c2d2  8d9c24e0020000         -lea ebx, [esp + 0x2e0]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(736) /* 0x2e0 */);
    // 0048c2d9  ff5258                 -call dword ptr [edx + 0x58]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048c2dc  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0048c2e1  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048c2e3  8b560c                 -mov edx, dword ptr [esi + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0048c2e6  e859f5ffff             -call 0x48b844
    cpu.esp -= 4;
    sub_48b844(app, cpu);
    if (cpu.terminate) return;
    // 0048c2eb  8a8663040000           -mov al, byte ptr [esi + 0x463]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1123) /* 0x463 */);
    // 0048c2f1  89be44040000           -mov dword ptr [esi + 0x444], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1092) /* 0x444 */) = cpu.edi;
    // 0048c2f7  3c01                   +cmp al, 1
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
    // 0048c2f9  0f8602010000           -jbe 0x48c401
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0048c401;
    }
    // 0048c2ff  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048c301  e8660d0000             -call 0x48d06c
    cpu.esp -= 4;
    sub_48d06c(app, cpu);
    if (cpu.terminate) return;
L_0x0048c306:
    // 0048c306  898648040000           -mov dword ptr [esi + 0x448], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1096) /* 0x448 */) = cpu.eax;
L_0x0048c30c:
    // 0048c30c  83be4404000000         +cmp dword ptr [esi + 0x444], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1092) /* 0x444 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048c313  745a                   -je 0x48c36f
    if (cpu.flags.zf)
    {
        goto L_0x0048c36f;
    }
    // 0048c315  c78424d80200006c000000 -mov dword ptr [esp + 0x2d8], 0x6c
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(728) /* 0x2d8 */) = 108 /*0x6c*/;
    // 0048c320  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0048c323  8d8c24d8020000         -lea ecx, [esp + 0x2d8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(728) /* 0x2d8 */);
    // 0048c32a  898424e8020000         -mov dword ptr [esp + 0x2e8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(744) /* 0x2e8 */) = cpu.eax;
    // 0048c331  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048c332  8b8644040000           -mov eax, dword ptr [esi + 0x444]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1092) /* 0x444 */);
    // 0048c338  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048c339  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0048c33b  ff5258                 -call dword ptr [edx + 0x58]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048c33e  8b8644040000           -mov eax, dword ptr [esi + 0x444]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1092) /* 0x444 */);
    // 0048c344  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048c345  8b942400030000         -mov edx, dword ptr [esp + 0x300]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(768) /* 0x300 */);
    // 0048c34c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048c34e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048c34f  8b9c24f0020000         -mov ebx, dword ptr [esp + 0x2f0]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(752) /* 0x2f0 */);
    // 0048c356  8a8e5c040000           -mov cl, byte ptr [esi + 0x45c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1116) /* 0x45c */);
    // 0048c35c  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 0048c35e  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0048c361  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0048c364  e8ffc00100             -call 0x4a8468
    cpu.esp -= 4;
    sub_4a8468(app, cpu);
    if (cpu.terminate) return;
    // 0048c369  89864c040000           -mov dword ptr [esi + 0x44c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1100) /* 0x44c */) = cpu.eax;
L_0x0048c36f:
    // 0048c36f  83be4804000000         +cmp dword ptr [esi + 0x448], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1096) /* 0x448 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048c376  0f84f6000000           -je 0x48c472
    if (cpu.flags.zf)
    {
        goto L_0x0048c472;
    }
    // 0048c37c  c78424d80200006c000000 -mov dword ptr [esp + 0x2d8], 0x6c
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(728) /* 0x2d8 */) = 108 /*0x6c*/;
    // 0048c387  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0048c38a  8d9424d8020000         -lea edx, [esp + 0x2d8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(728) /* 0x2d8 */);
    // 0048c391  898424e8020000         -mov dword ptr [esp + 0x2e8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(744) /* 0x2e8 */) = cpu.eax;
    // 0048c398  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048c399  8b8648040000           -mov eax, dword ptr [esi + 0x448]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1096) /* 0x448 */);
    // 0048c39f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048c3a0  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0048c3a2  ff5158                 -call dword ptr [ecx + 0x58]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048c3a5  8bbe48040000           -mov edi, dword ptr [esi + 0x448]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1096) /* 0x448 */);
    // 0048c3ab  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048c3ac  8bac2400030000         -mov ebp, dword ptr [esp + 0x300]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(768) /* 0x300 */);
    // 0048c3b3  8b9c24ec020000         -mov ebx, dword ptr [esp + 0x2ec]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(748) /* 0x2ec */);
    // 0048c3ba  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048c3bb  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0048c3be  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048c3c0  6afe                   -push -2
    app->getMemory<x86::reg32>(cpu.esp-4) = -2 /*-0x2*/;
    cpu.esp -= 4;
    // 0048c3c2  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0048c3c5  8a8e5c040000           -mov cl, byte ptr [esi + 0x45c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1116) /* 0x45c */);
    // 0048c3cb  e898c00100             -call 0x4a8468
    cpu.esp -= 4;
    sub_4a8468(app, cpu);
    if (cpu.terminate) return;
    // 0048c3d0  898650040000           -mov dword ptr [esi + 0x450], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1104) /* 0x450 */) = cpu.eax;
L_0x0048c3d6:
    // 0048c3d6  a1bc944d00             -mov eax, dword ptr [0x4d94bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5084348) /* 0x4d94bc */);
    // 0048c3db  e8f0bfffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0048c3e0  833dec8f4d0000         +cmp dword ptr [0x4d8fec], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5083116) /* 0x4d8fec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048c3e7  7406                   -je 0x48c3ef
    if (cpu.flags.zf)
    {
        goto L_0x0048c3ef;
    }
    // 0048c3e9  ff15ec8f4d00           -call dword ptr [0x4d8fec]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5083116) /* 0x4d8fec */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0048c3ef:
    // 0048c3ef  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048c3f4  81c444030000           -add esp, 0x344
    (cpu.esp) += x86::reg32(x86::sreg32(836 /*0x344*/));
    // 0048c3fa  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c3fb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c3fc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c3fd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c3fe  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c3ff  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c400  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048c401:
    // 0048c401  80be3604000000         +cmp byte ptr [esi + 0x436], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1078) /* 0x436 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048c408  0f85fefeffff           -jne 0x48c30c
    if (!cpu.flags.zf)
    {
        goto L_0x0048c30c;
    }
    // 0048c40e  80be3704000001         +cmp byte ptr [esi + 0x437], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1079) /* 0x437 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048c415  0f86f1feffff           -jbe 0x48c30c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0048c30c;
    }
    // 0048c41b  80be3504000000         +cmp byte ptr [esi + 0x435], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1077) /* 0x435 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048c422  742b                   -je 0x48c44f
    if (cpu.flags.zf)
    {
        goto L_0x0048c44f;
    }
L_0x0048c424:
    // 0048c424  8b9e48040000           -mov ebx, dword ptr [esi + 0x448]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1096) /* 0x448 */);
    // 0048c42a  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0048c42c  0f85dafeffff           -jne 0x48c30c
    if (!cpu.flags.zf)
    {
        goto L_0x0048c30c;
    }
    // 0048c432  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048c433  6840080000             -push 0x840
    app->getMemory<x86::reg32>(cpu.esp-4) = 2112 /*0x840*/;
    cpu.esp -= 4;
    // 0048c438  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048c439  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048c43b  8b4e1c                 -mov ecx, dword ptr [esi + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0048c43e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048c43f  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0048c442  8b5e18                 -mov ebx, dword ptr [esi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0048c445  e8fa090000             -call 0x48ce44
    cpu.esp -= 4;
    sub_48ce44(app, cpu);
    if (cpu.terminate) return;
    // 0048c44a  e9b7feffff             -jmp 0x48c306
    goto L_0x0048c306;
L_0x0048c44f:
    // 0048c44f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048c451  6840400000             -push 0x4040
    app->getMemory<x86::reg32>(cpu.esp-4) = 16448 /*0x4040*/;
    cpu.esp -= 4;
    // 0048c456  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048c458  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048c45a  8b4e1c                 -mov ecx, dword ptr [esi + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 0048c45d  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048c45f  8b5e18                 -mov ebx, dword ptr [esi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0048c462  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0048c465  e8da090000             -call 0x48ce44
    cpu.esp -= 4;
    sub_48ce44(app, cpu);
    if (cpu.terminate) return;
    // 0048c46a  898648040000           -mov dword ptr [esi + 0x448], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1096) /* 0x448 */) = cpu.eax;
    // 0048c470  ebb2                   -jmp 0x48c424
    goto L_0x0048c424;
L_0x0048c472:
    // 0048c472  80be3704000001         +cmp byte ptr [esi + 0x437], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1079) /* 0x437 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048c479  0f8657ffffff           -jbe 0x48c3d6
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0048c3d6;
    }
    // 0048c47f  8b4e20                 -mov ecx, dword ptr [esi + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 0048c482  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0048c485  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0048c487  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0048c48a  8a9e5c040000           -mov bl, byte ptr [esi + 0x45c]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1116) /* 0x45c */);
    // 0048c490  bfcc904d00             -mov edi, 0x4d90cc
    cpu.edi = 5083340 /*0x4d90cc*/;
    // 0048c495  e8c6120000             -call 0x48d760
    cpu.esp -= 4;
    sub_48d760(app, cpu);
    if (cpu.terminate) return;
    // 0048c49a  b90e000000             -mov ecx, 0xe
    cpu.ecx = 14 /*0xe*/;
    // 0048c49f  898650040000           -mov dword ptr [esi + 0x450], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1104) /* 0x450 */) = cpu.eax;
    // 0048c4a5  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048c4a7  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048c4a9  e928ffffff             -jmp 0x48c3d6
    goto L_0x0048c3d6;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48c4b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048c4b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048c4b1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048c4b2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048c4b3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048c4b4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048c4b5  81ec8c040000           -sub esp, 0x48c
    (cpu.esp) -= x86::reg32(x86::sreg32(1164 /*0x48c*/));
    // 0048c4bb  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048c4bd  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0048c4bf  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0048c4c1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048c4c3  7505                   -jne 0x48c4ca
    if (!cpu.flags.zf)
    {
        goto L_0x0048c4ca;
    }
    // 0048c4c5  bbd0165600             -mov ebx, 0x5616d0
    cpu.ebx = 5641936 /*0x5616d0*/;
L_0x0048c4ca:
    // 0048c4ca  ba6c000000             -mov edx, 0x6c
    cpu.edx = 108 /*0x6c*/;
    // 0048c4cf  8d8c2400040000         -lea ecx, [esp + 0x400]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(1024) /* 0x400 */);
    // 0048c4d6  89942400040000         -mov dword ptr [esp + 0x400], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1024) /* 0x400 */) = cpu.edx;
    // 0048c4dd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048c4de  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0048c4e0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048c4e1  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0048c4e3  ff5230                 -call dword ptr [edx + 0x30]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(48) /* 0x30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048c4e6  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0048c4e8  80bb5d04000000         +cmp byte ptr [ebx + 0x45d], 0
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
    // 0048c4ef  0f84f0010000           -je 0x48c6e5
    if (cpu.flags.zf)
    {
        goto L_0x0048c6e5;
    }
    // 0048c4f5  837b1000               +cmp dword ptr [ebx + 0x10], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048c4f9  0f843f010000           -je 0x48c63e
    if (cpu.flags.zf)
    {
        goto L_0x0048c63e;
    }
    // 0048c4ff  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048c501  0f8c45010000           -jl 0x48c64c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048c64c;
    }
    // 0048c507  3b7308                 +cmp esi, dword ptr [ebx + 8]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048c50a  7c02                   -jl 0x48c50e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048c50e;
    }
    // 0048c50c  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x0048c50e:
    // 0048c50e  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 0048c515  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0048c517  8b5310                 -mov edx, dword ptr [ebx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 0048c51a  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0048c51d  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048c51f  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048c522  89942488040000         -mov dword ptr [esp + 0x488], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1160) /* 0x488 */) = cpu.edx;
    // 0048c529  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048c52b  8b28                   -mov ebp, dword ptr [eax]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax);
    // 0048c52d  8a5012                 -mov dl, byte ptr [eax + 0x12]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(18) /* 0x12 */);
    // 0048c530  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0048c533  89942484040000         -mov dword ptr [esp + 0x484], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1156) /* 0x484 */) = cpu.edx;
    // 0048c53a  8984247c040000         -mov dword ptr [esp + 0x47c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1148) /* 0x47c */) = cpu.eax;
L_0x0048c541:
    // 0048c541  837b2400               +cmp dword ptr [ebx + 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048c545  7433                   -je 0x48c57a
    if (cpu.flags.zf)
    {
        goto L_0x0048c57a;
    }
    // 0048c547  ba00040000             -mov edx, 0x400
    cpu.edx = 1024 /*0x400*/;
    // 0048c54c  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0048c54e  e839bfffff             -call 0x48848c
    cpu.esp -= 4;
    sub_48848c(app, cpu);
    if (cpu.terminate) return;
    // 0048c553  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0048c555  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048c556  6800010000             -push 0x100
    app->getMemory<x86::reg32>(cpu.esp-4) = 256 /*0x100*/;
    cpu.esp -= 4;
    // 0048c55b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048c55d  8b4324                 -mov eax, dword ptr [ebx + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */);
    // 0048c560  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048c562  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0048c564  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048c565  ff5118                 -call dword ptr [ecx + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048c568  66c783300400000000     -mov word ptr [ebx + 0x430], 0
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(1072) /* 0x430 */) = 0 /*0x0*/;
    // 0048c571  66c78332040000ff00     -mov word ptr [ebx + 0x432], 0xff
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(1074) /* 0x432 */) = 255 /*0xff*/;
L_0x0048c57a:
    // 0048c57a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048c57c  8b8c2480040000         -mov ecx, dword ptr [esp + 0x480]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1152) /* 0x480 */);
    // 0048c583  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048c584  8b8c248c040000         -mov ecx, dword ptr [esp + 0x48c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1164) /* 0x48c */);
    // 0048c58b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048c58c  8b8c2494040000         -mov ecx, dword ptr [esp + 0x494]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1172) /* 0x494 */);
    // 0048c593  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048c594  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0048c596  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048c597  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0048c599  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048c59a  ff5254                 -call dword ptr [edx + 0x54]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(84) /* 0x54 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048c59d  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0048c5a2  89842480040000         -mov dword ptr [esp + 0x480], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1152) /* 0x480 */) = cpu.eax;
    // 0048c5a9  b86c000000             -mov eax, 0x6c
    cpu.eax = 108 /*0x6c*/;
    // 0048c5ae  8d8c2400040000         -lea ecx, [esp + 0x400]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(1024) /* 0x400 */);
    // 0048c5b5  89842400040000         -mov dword ptr [esp + 0x400], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1024) /* 0x400 */) = cpu.eax;
    // 0048c5bc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048c5bd  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0048c5bf  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048c5c0  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0048c5c2  ff5230                 -call dword ptr [edx + 0x30]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(48) /* 0x30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048c5c5  8b94240c040000         -mov edx, dword ptr [esp + 0x40c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1036) /* 0x40c */);
    // 0048c5cc  39d5                   +cmp ebp, edx
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
    // 0048c5ce  0f82a3000000           -jb 0x48c677
    if (cpu.flags.cf)
    {
        goto L_0x0048c677;
    }
    // 0048c5d4  895314                 -mov dword ptr [ebx + 0x14], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */) = cpu.edx;
L_0x0048c5d7:
    // 0048c5d7  8b842488040000         -mov eax, dword ptr [esp + 0x488]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1160) /* 0x488 */);
    // 0048c5de  8b8c2408040000         -mov ecx, dword ptr [esp + 0x408]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1032) /* 0x408 */);
    // 0048c5e5  39c8                   +cmp eax, ecx
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
    // 0048c5e7  0f82a3000000           -jb 0x48c690
    if (cpu.flags.cf)
    {
        goto L_0x0048c690;
    }
    // 0048c5ed  894b18                 -mov dword ptr [ebx + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */) = cpu.ecx;
L_0x0048c5f0:
    // 0048c5f0  83bc248004000000       +cmp dword ptr [esp + 0x480], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1152) /* 0x480 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048c5f8  0f85b2000000           -jne 0x48c6b0
    if (!cpu.flags.zf)
    {
        goto L_0x0048c6b0;
    }
    // 0048c5fe  8b842484040000         -mov eax, dword ptr [esp + 0x484]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1156) /* 0x484 */);
    // 0048c605  3b842454040000         +cmp eax, dword ptr [esp + 0x454]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1108) /* 0x454 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048c60c  0f859e000000           -jne 0x48c6b0
    if (!cpu.flags.zf)
    {
        goto L_0x0048c6b0;
    }
    // 0048c612  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
L_0x0048c617:
    // 0048c617  8b842454040000         -mov eax, dword ptr [esp + 0x454]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1108) /* 0x454 */);
    // 0048c61e  89431c                 -mov dword ptr [ebx + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0048c621  6800000080             -push 0x80000000
    app->getMemory<x86::reg32>(cpu.esp-4) = 2147483648 /*0x80000000*/;
    cpu.esp -= 4;
    // 0048c626  89730c                 -mov dword ptr [ebx + 0xc], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 0048c629  2eff1570434c00         -call dword ptr cs:[0x4c4370]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998000) /* 0x4c4370 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048c630  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048c632  81c48c040000           -add esp, 0x48c
    (cpu.esp) += x86::reg32(x86::sreg32(1164 /*0x48c*/));
    // 0048c638  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c639  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c63a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c63b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c63c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c63d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048c63e:
    // 0048c63e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048c640  81c48c040000           -add esp, 0x48c
    (cpu.esp) += x86::reg32(x86::sreg32(1164 /*0x48c*/));
    // 0048c646  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c647  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c648  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c649  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c64a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c64b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048c64c:
    // 0048c64c  bd80020000             -mov ebp, 0x280
    cpu.ebp = 640 /*0x280*/;
    // 0048c651  b8e0010000             -mov eax, 0x1e0
    cpu.eax = 480 /*0x1e0*/;
    // 0048c656  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 0048c65b  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0048c65d  89842488040000         -mov dword ptr [esp + 0x488], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1160) /* 0x488 */) = cpu.eax;
    // 0048c664  89942484040000         -mov dword ptr [esp + 0x484], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1156) /* 0x484 */) = cpu.edx;
    // 0048c66b  898c247c040000         -mov dword ptr [esp + 0x47c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1148) /* 0x47c */) = cpu.ecx;
    // 0048c672  e9cafeffff             -jmp 0x48c541
    goto L_0x0048c541;
L_0x0048c677:
    // 0048c677  896b14                 -mov dword ptr [ebx + 0x14], ebp
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */) = cpu.ebp;
    // 0048c67a  8b84240c040000         -mov eax, dword ptr [esp + 0x40c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1036) /* 0x40c */);
    // 0048c681  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0048c683  d1e8                   +shr eax, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 0048c685  898364040000           -mov dword ptr [ebx + 0x464], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1124) /* 0x464 */) = cpu.eax;
    // 0048c68b  e947ffffff             -jmp 0x48c5d7
    goto L_0x0048c5d7;
L_0x0048c690:
    // 0048c690  894318                 -mov dword ptr [ebx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0048c693  8bac2488040000         -mov ebp, dword ptr [esp + 0x488]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1160) /* 0x488 */);
    // 0048c69a  8b842408040000         -mov eax, dword ptr [esp + 0x408]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1032) /* 0x408 */);
    // 0048c6a1  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0048c6a3  d1e8                   +shr eax, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 0048c6a5  898368040000           -mov dword ptr [ebx + 0x468], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1128) /* 0x468 */) = cpu.eax;
    // 0048c6ab  e940ffffff             -jmp 0x48c5f0
    goto L_0x0048c5f0;
L_0x0048c6b0:
    // 0048c6b0  81bc2480040000e1000000 +cmp dword ptr [esp + 0x480], 0xe1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1152) /* 0x480 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(225 /*0xe1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048c6bb  750a                   -jne 0x48c6c7
    if (!cpu.flags.zf)
    {
        goto L_0x0048c6c7;
    }
    // 0048c6bd  bfffffffff             -mov edi, 0xffffffff
    cpu.edi = 4294967295 /*0xffffffff*/;
    // 0048c6c2  e950ffffff             -jmp 0x48c617
    goto L_0x0048c617;
L_0x0048c6c7:
    // 0048c6c7  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0048c6c9  0f8548ffffff           -jne 0x48c617
    if (!cpu.flags.zf)
    {
        goto L_0x0048c617;
    }
    // 0048c6cf  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 0048c6d6  8b5310                 -mov edx, dword ptr [ebx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 0048c6d9  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0048c6db  804c820f80             +or byte ptr [edx + eax*4 + 0xf], 0x80
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.edx + x86::reg32(15) /* 0xf */ + cpu.eax * 4) |= x86::reg8(x86::sreg8(128 /*0x80*/))));
    // 0048c6e0  e932ffffff             -jmp 0x48c617
    goto L_0x0048c617;
L_0x0048c6e5:
    // 0048c6e5  8d84246c040000         -lea eax, [esp + 0x46c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(1132) /* 0x46c */);
    // 0048c6ec  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048c6ed  8b8b54040000           -mov ecx, dword ptr [ebx + 0x454]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1108) /* 0x454 */);
    // 0048c6f3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048c6f4  2eff15bc434c00         -call dword ptr cs:[0x4c43bc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998076) /* 0x4c43bc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048c6fb  8d84246c040000         -lea eax, [esp + 0x46c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(1132) /* 0x46c */);
    // 0048c702  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048c703  8bbb54040000           -mov edi, dword ptr [ebx + 0x454]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1108) /* 0x454 */);
    // 0048c709  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048c70a  2eff159c434c00         -call dword ptr cs:[0x4c439c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998044) /* 0x4c439c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048c711  8d842474040000         -lea eax, [esp + 0x474]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(1140) /* 0x474 */);
    // 0048c718  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048c719  8b8354040000           -mov eax, dword ptr [ebx + 0x454]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1108) /* 0x454 */);
    // 0048c71f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048c720  2eff159c434c00         -call dword ptr cs:[0x4c439c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998044) /* 0x4c439c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048c727  81bb6404000078ecffff   +cmp dword ptr [ebx + 0x464], 0xffffec78
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1124) /* 0x464 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294962296 /*0xffffec78*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048c731  7d1e                   -jge 0x48c751
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048c751;
    }
    // 0048c733  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048c735  2eff15cc434c00         -call dword ptr cs:[0x4c43cc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998092) /* 0x4c43cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048c73c  8b4b14                 -mov ecx, dword ptr [ebx + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 0048c73f  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048c741  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048c743  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048c746  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048c748  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0048c74a  8984246c040000         -mov dword ptr [esp + 0x46c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1132) /* 0x46c */) = cpu.eax;
L_0x0048c751:
    // 0048c751  81bb6804000078ecffff   +cmp dword ptr [ebx + 0x468], 0xffffec78
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1128) /* 0x468 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294962296 /*0xffffec78*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048c75b  7d1e                   -jge 0x48c77b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048c77b;
    }
    // 0048c75d  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0048c75f  2eff15cc434c00         -call dword ptr cs:[0x4c43cc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998092) /* 0x4c43cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048c766  8b5318                 -mov edx, dword ptr [ebx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 0048c769  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048c76b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048c76d  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048c770  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048c772  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0048c774  89842470040000         -mov dword ptr [esp + 0x470], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1136) /* 0x470 */) = cpu.eax;
L_0x0048c77b:
    // 0048c77b  8b84246c040000         -mov eax, dword ptr [esp + 0x46c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1132) /* 0x46c */);
    // 0048c782  8b4b14                 -mov ecx, dword ptr [ebx + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 0048c785  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048c787  89842474040000         -mov dword ptr [esp + 0x474], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1140) /* 0x474 */) = cpu.eax;
    // 0048c78e  8b842470040000         -mov eax, dword ptr [esp + 0x470]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1136) /* 0x470 */);
    // 0048c795  034318                 -add eax, dword ptr [ebx + 0x18]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */)));
    // 0048c798  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048c79a  8984247c040000         -mov dword ptr [esp + 0x47c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1148) /* 0x47c */) = cpu.eax;
    // 0048c7a1  6af0                   -push -0x10
    app->getMemory<x86::reg32>(cpu.esp-4) = -16 /*-0x10*/;
    cpu.esp -= 4;
    // 0048c7a3  8b8354040000           -mov eax, dword ptr [ebx + 0x454]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1108) /* 0x454 */);
    // 0048c7a9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048c7aa  2eff15d0434c00         -call dword ptr cs:[0x4c43d0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998096) /* 0x4c43d0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048c7b1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048c7b2  8d842474040000         -lea eax, [esp + 0x474]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(1140) /* 0x474 */);
    // 0048c7b9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048c7ba  2eff1588434c00         -call dword ptr cs:[0x4c4388]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998024) /* 0x4c4388 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048c7c1  8b842478040000         -mov eax, dword ptr [esp + 0x478]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1144) /* 0x478 */);
    // 0048c7c8  8b942470040000         -mov edx, dword ptr [esp + 0x470]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1136) /* 0x470 */);
    // 0048c7cf  6a14                   -push 0x14
    app->getMemory<x86::reg32>(cpu.esp-4) = 20 /*0x14*/;
    cpu.esp -= 4;
    // 0048c7d1  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048c7d3  8b8c2470040000         -mov ecx, dword ptr [esp + 0x470]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1136) /* 0x470 */);
    // 0048c7da  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048c7db  8b84247c040000         -mov eax, dword ptr [esp + 0x47c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1148) /* 0x47c */);
    // 0048c7e2  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048c7e4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048c7e5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048c7e6  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048c7e7  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048c7e9  8b9354040000           -mov edx, dword ptr [ebx + 0x454]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1108) /* 0x454 */);
    // 0048c7ef  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048c7f0  2eff1500444c00         -call dword ptr cs:[0x4c4400]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998144) /* 0x4c4400 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048c7f7  8d84246c040000         -lea eax, [esp + 0x46c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(1132) /* 0x46c */);
    // 0048c7fe  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048c7ff  8b8b54040000           -mov ecx, dword ptr [ebx + 0x454]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1108) /* 0x454 */);
    // 0048c805  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048c806  2eff15bc434c00         -call dword ptr cs:[0x4c43bc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998076) /* 0x4c43bc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048c80d  8d84246c040000         -lea eax, [esp + 0x46c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(1132) /* 0x46c */);
    // 0048c814  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048c815  8bbb54040000           -mov edi, dword ptr [ebx + 0x454]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1108) /* 0x454 */);
    // 0048c81b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048c81c  2eff159c434c00         -call dword ptr cs:[0x4c439c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998044) /* 0x4c439c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048c823  8d842474040000         -lea eax, [esp + 0x474]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(1140) /* 0x474 */);
    // 0048c82a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048c82b  8b8354040000           -mov eax, dword ptr [ebx + 0x454]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1108) /* 0x454 */);
    // 0048c831  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048c832  2eff159c434c00         -call dword ptr cs:[0x4c439c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998044) /* 0x4c439c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048c839  8b842474040000         -mov eax, dword ptr [esp + 0x474]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1140) /* 0x474 */);
    // 0048c840  8b94246c040000         -mov edx, dword ptr [esp + 0x46c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1132) /* 0x46c */);
    // 0048c847  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048c849  894314                 -mov dword ptr [ebx + 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0048c84c  8b842478040000         -mov eax, dword ptr [esp + 0x478]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1144) /* 0x478 */);
    // 0048c853  8b8c2470040000         -mov ecx, dword ptr [esp + 0x470]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1136) /* 0x470 */);
    // 0048c85a  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048c85c  894318                 -mov dword ptr [ebx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0048c85f  8b84246c040000         -mov eax, dword ptr [esp + 0x46c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1132) /* 0x46c */);
    // 0048c866  898364040000           -mov dword ptr [ebx + 0x464], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1124) /* 0x464 */) = cpu.eax;
    // 0048c86c  8b842470040000         -mov eax, dword ptr [esp + 0x470]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1136) /* 0x470 */);
    // 0048c873  898368040000           -mov dword ptr [ebx + 0x468], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1128) /* 0x468 */) = cpu.eax;
    // 0048c879  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0048c87b  7520                   -jne 0x48c89d
    if (!cpu.flags.zf)
    {
        goto L_0x0048c89d;
    }
    // 0048c87d  8b842454040000         -mov eax, dword ptr [esp + 0x454]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1108) /* 0x454 */);
L_0x0048c884:
    // 0048c884  89431c                 -mov dword ptr [ebx + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0048c887  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 0048c88c  89730c                 -mov dword ptr [ebx + 0xc], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 0048c88f  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048c891  81c48c040000           +add esp, 0x48c
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1164 /*0x48c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0048c897  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c898  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c899  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c89a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c89b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c89c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048c89d:
    // 0048c89d  a1a0894d00             -mov eax, dword ptr [0x4d89a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5081504) /* 0x4d89a0 */);
    // 0048c8a2  ebe0                   -jmp 0x48c884
    goto L_0x0048c884;
}

/* align: skip  */
void Application::sub_48c8a4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048c8a4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048c8a5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048c8a7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048c8a9  7505                   -jne 0x48c8b0
    if (!cpu.flags.zf)
    {
        goto L_0x0048c8b0;
    }
    // 0048c8ab  bbd0165600             -mov ebx, 0x5616d0
    cpu.ebx = 5641936 /*0x5616d0*/;
L_0x0048c8b0:
    // 0048c8b0  833b00                 +cmp dword ptr [ebx], 0
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
    // 0048c8b3  7450                   -je 0x48c905
    if (cpu.flags.zf)
    {
        goto L_0x0048c905;
    }
    // 0048c8b5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048c8b6  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048c8b7  a1bc944d00             -mov eax, dword ptr [0x4d94bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5084348) /* 0x4d94bc */);
    // 0048c8bc  e8f7baffff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 0048c8c1  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048c8c3  e890f6ffff             -call 0x48bf58
    cpu.esp -= 4;
    sub_48bf58(app, cpu);
    if (cpu.terminate) return;
    // 0048c8c8  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0048c8ca  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048c8cb  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0048c8cd  ff5208                 -call dword ptr [edx + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048c8d0  8b4b10                 -mov ecx, dword ptr [ebx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 0048c8d3  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048c8d5  7407                   -je 0x48c8de
    if (cpu.flags.zf)
    {
        goto L_0x0048c8de;
    }
    // 0048c8d7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048c8d9  e88e64ffff             -call 0x482d6c
    cpu.esp -= 4;
    sub_482d6c(app, cpu);
    if (cpu.terminate) return;
L_0x0048c8de:
    // 0048c8de  c7431000000000         -mov dword ptr [ebx + 0x10], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 0048c8e5  c7430400000000         -mov dword ptr [ebx + 4], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0048c8ec  c7432400000000         -mov dword ptr [ebx + 0x24], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 0048c8f3  a1bc944d00             -mov eax, dword ptr [0x4d94bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5084348) /* 0x4d94bc */);
    // 0048c8f8  c70300000000           -mov dword ptr [ebx], 0
    app->getMemory<x86::reg32>(cpu.ebx) = 0 /*0x0*/;
    // 0048c8fe  e8cdbaffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0048c903  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c904  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0048c905:
    // 0048c905  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c906  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48c908(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048c908  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048c909  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048c90a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048c90c  7505                   -jne 0x48c913
    if (!cpu.flags.zf)
    {
        goto L_0x0048c913;
    }
    // 0048c90e  b8d0165600             -mov eax, 0x5616d0
    cpu.eax = 5641936 /*0x5616d0*/;
L_0x0048c913:
    // 0048c913  8b9054040000           -mov edx, dword ptr [eax + 0x454]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1108) /* 0x454 */);
    // 0048c919  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048c91a  2eff15fc434c00         -call dword ptr cs:[0x4c43fc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998140) /* 0x4c43fc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048c921  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c922  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c923  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48c924(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048c924  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048c925  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048c926  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048c929  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048c92b  7505                   -jne 0x48c932
    if (!cpu.flags.zf)
    {
        goto L_0x0048c932;
    }
    // 0048c92d  b8d0165600             -mov eax, 0x5616d0
    cpu.eax = 5641936 /*0x5616d0*/;
L_0x0048c932:
    // 0048c932  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0048c934  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048c936  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048c937  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0048c939  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048c93a  ff5140                 -call dword ptr [ecx + 0x40]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(64) /* 0x40 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048c93d  66a9ffff               +test ax, 0xffff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & 65535 /*0xffff*/));
    // 0048c941  7509                   -jne 0x48c94c
    if (!cpu.flags.zf)
    {
        goto L_0x0048c94c;
    }
    // 0048c943  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0048c946  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048c949  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c94a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c94b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048c94c:
    // 0048c94c  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0048c951  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048c954  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c955  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c956  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48c958(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048c958  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048c959  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048c95a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048c95c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048c95e  7505                   -jne 0x48c965
    if (!cpu.flags.zf)
    {
        goto L_0x0048c965;
    }
    // 0048c960  b9d0165600             -mov ecx, 0x5616d0
    cpu.ecx = 5641936 /*0x5616d0*/;
L_0x0048c965:
    // 0048c965  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048c967  e830030000             -call 0x48cc9c
    cpu.esp -= 4;
    sub_48cc9c(app, cpu);
    if (cpu.terminate) return;
    // 0048c96c  8b9944040000           -mov ebx, dword ptr [ecx + 0x444]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1092) /* 0x444 */);
    // 0048c972  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0048c974  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048c976  7420                   -je 0x48c998
    if (cpu.flags.zf)
    {
        goto L_0x0048c998;
    }
    // 0048c978  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0048c97d:
    // 0048c97d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048c97e  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048c980  8b9144040000           -mov edx, dword ptr [ecx + 0x444]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1092) /* 0x444 */);
    // 0048c986  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048c987  ff532c                 -call dword ptr [ebx + 0x2c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(44) /* 0x2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048c98a  66a9ffff               +test ax, 0xffff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & 65535 /*0xffff*/));
    // 0048c98e  750c                   -jne 0x48c99c
    if (!cpu.flags.zf)
    {
        goto L_0x0048c99c;
    }
    // 0048c990  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048c995  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c996  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c997  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048c998:
    // 0048c998  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0048c99a  ebe1                   -jmp 0x48c97d
    goto L_0x0048c97d;
L_0x0048c99c:
    // 0048c99c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048c99e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c99f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c9a0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48c9a4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048c9a4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048c9a5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048c9a6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048c9a8  7505                   -jne 0x48c9af
    if (!cpu.flags.zf)
    {
        goto L_0x0048c9af;
    }
    // 0048c9aa  b8d0165600             -mov eax, 0x5616d0
    cpu.eax = 5641936 /*0x5616d0*/;
L_0x0048c9af:
    // 0048c9af  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0048c9b1  8b8044040000           -mov eax, dword ptr [eax + 0x444]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1092) /* 0x444 */);
    // 0048c9b7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048c9b8  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0048c9ba  ff5248                 -call dword ptr [edx + 0x48]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(72) /* 0x48 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048c9bd  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0048c9c2  3d1c027688             +cmp eax, 0x8876021c
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2289435164 /*0x8876021c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048c9c7  7408                   -je 0x48c9d1
    if (cpu.flags.zf)
    {
        goto L_0x0048c9d1;
    }
    // 0048c9c9  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048c9ce  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c9cf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c9d0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048c9d1:
    // 0048c9d1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048c9d3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c9d4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c9d5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48c9d8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048c9d8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048c9d9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048c9da  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048c9dd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048c9df  7505                   -jne 0x48c9e6
    if (!cpu.flags.zf)
    {
        goto L_0x0048c9e6;
    }
    // 0048c9e1  b8d0165600             -mov eax, 0x5616d0
    cpu.eax = 5641936 /*0x5616d0*/;
L_0x0048c9e6:
    // 0048c9e6  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0048c9e8  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048c9ea  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048c9eb  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0048c9ed  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048c9ee  ff5144                 -call dword ptr [ecx + 0x44]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(68) /* 0x44 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048c9f1  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0048c9f4  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048c9f7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c9f8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c9f9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48c9fc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048c9fc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048c9fd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048c9ff  7505                   -jne 0x48ca06
    if (!cpu.flags.zf)
    {
        goto L_0x0048ca06;
    }
    // 0048ca01  b8d0165600             -mov eax, 0x5616d0
    cpu.eax = 5641936 /*0x5616d0*/;
L_0x0048ca06:
    // 0048ca06  83fa02                 +cmp edx, 2
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
    // 0048ca09  7512                   -jne 0x48ca1d
    if (!cpu.flags.zf)
    {
        goto L_0x0048ca1d;
    }
    // 0048ca0b  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 0048ca10  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048ca12  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048ca14  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048ca15  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0048ca17  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048ca18  ff5158                 -call dword ptr [ecx + 0x58]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048ca1b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ca1c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048ca1d:
    // 0048ca1d  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0048ca22  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048ca24  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048ca26  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048ca27  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0048ca29  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048ca2a  ff5158                 -call dword ptr [ecx + 0x58]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048ca2d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ca2e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48ca30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048ca30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048ca31  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048ca33  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048ca35  7505                   -jne 0x48ca3c
    if (!cpu.flags.zf)
    {
        goto L_0x0048ca3c;
    }
    // 0048ca37  bbd0165600             -mov ebx, 0x5616d0
    cpu.ebx = 5641936 /*0x5616d0*/;
L_0x0048ca3c:
    // 0048ca3c  837b2400               +cmp dword ptr [ebx + 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048ca40  0f8476000000           -je 0x48cabc
    if (cpu.flags.zf)
    {
        goto L_0x0048cabc;
    }
    // 0048ca46  837b1c08               +cmp dword ptr [ebx + 0x1c], 8
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048ca4a  7f70                   -jg 0x48cabc
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048cabc;
    }
    // 0048ca4c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048ca4d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048ca4e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048ca4f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048ca50  8b832e040000           -mov eax, dword ptr [ebx + 0x42e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1070) /* 0x42e */);
    // 0048ca56  8b9330040000           -mov edx, dword ptr [ebx + 0x430]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1072) /* 0x430 */);
    // 0048ca5c  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0048ca5f  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0048ca62  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0048ca64  42                     -inc edx
    (cpu.edx)++;
    // 0048ca65  3d00010000             +cmp eax, 0x100
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
    // 0048ca6a  7d3a                   -jge 0x48caa6
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048caa6;
    }
    // 0048ca6c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048ca6e  7e36                   -jle 0x48caa6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048caa6;
    }
    // 0048ca70  8d348500000000         -lea esi, [eax*4]
    cpu.esi = x86::reg32(cpu.eax * 4);
    // 0048ca77  8d4b30                 -lea ecx, [ebx + 0x30]
    cpu.ecx = x86::reg32(cpu.ebx + x86::reg32(48) /* 0x30 */);
    // 0048ca7a  01ce                   -add esi, ecx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048ca7c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048ca7d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048ca7e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048ca7f  8b4b24                 -mov ecx, dword ptr [ebx + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */);
    // 0048ca82  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048ca84  8b39                   -mov edi, dword ptr [ecx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx);
    // 0048ca86  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048ca87  ff5718                 -call dword ptr [edi + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048ca8a  80bb5d04000000         +cmp byte ptr [ebx + 0x45d], 0
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
    // 0048ca91  7513                   -jne 0x48caa6
    if (!cpu.flags.zf)
    {
        goto L_0x0048caa6;
    }
    // 0048ca93  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048ca94  6800010000             -push 0x100
    app->getMemory<x86::reg32>(cpu.esp-4) = 256 /*0x100*/;
    cpu.esp -= 4;
    // 0048ca99  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048ca9b  8b4324                 -mov eax, dword ptr [ebx + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */);
    // 0048ca9e  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048caa0  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0048caa2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048caa3  ff5210                 -call dword ptr [edx + 0x10]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0048caa6:
    // 0048caa6  66c783300400000001     -mov word ptr [ebx + 0x430], 0x100
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(1072) /* 0x430 */) = 256 /*0x100*/;
    // 0048caaf  66c78332040000ffff     -mov word ptr [ebx + 0x432], 0xffff
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(1074) /* 0x432 */) = 65535 /*0xffff*/;
    // 0048cab8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cab9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048caba  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cabb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0048cabc:
    // 0048cabc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cabd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48cac0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048cac0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048cac1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048cac2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048cac3  81ec00040000           -sub esp, 0x400
    (cpu.esp) -= x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 0048cac9  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0048cacb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048cacd  7505                   -jne 0x48cad4
    if (!cpu.flags.zf)
    {
        goto L_0x0048cad4;
    }
    // 0048cacf  b8d0165600             -mov eax, 0x5616d0
    cpu.eax = 5641936 /*0x5616d0*/;
L_0x0048cad4:
    // 0048cad4  8b5024                 -mov edx, dword ptr [eax + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 0048cad7  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048cad9  7454                   -je 0x48cb2f
    if (cpu.flags.zf)
    {
        goto L_0x0048cb2f;
    }
    // 0048cadb  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 0048cadd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048cade  6800010000             -push 0x100
    app->getMemory<x86::reg32>(cpu.esp-4) = 256 /*0x100*/;
    cpu.esp -= 4;
    // 0048cae3  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048cae5  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048cae7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048cae9  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 0048caeb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048caec  ff5210                 -call dword ptr [edx + 0x10]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048caef  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0048caf1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0048caf3:
    // 0048caf3  0fb63484               -movzx esi, byte ptr [esp + eax*4]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.esp + cpu.eax * 4));
    // 0048caf7  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048caf9  c1e610                 -shl esi, 0x10
    cpu.esi <<= 16 /*0x10*/ % 32;
    // 0048cafc  8a5c8401               -mov bl, byte ptr [esp + eax*4 + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */ + cpu.eax * 4);
    // 0048cb00  81ce000000ff           -or esi, 0xff000000
    cpu.esi |= x86::reg32(x86::sreg32(4278190080 /*0xff000000*/));
    // 0048cb06  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 0048cb09  8a548402               -mov dl, byte ptr [esp + eax*4 + 2]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(2) /* 0x2 */ + cpu.eax * 4);
    // 0048cb0d  09de                   -or esi, ebx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048cb0f  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0048cb15  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048cb18  09f2                   -or edx, esi
    cpu.edx |= x86::reg32(x86::sreg32(cpu.esi));
    // 0048cb1a  40                     -inc eax
    (cpu.eax)++;
    // 0048cb1b  8951fc                 -mov dword ptr [ecx - 4], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 0048cb1e  3d00010000             +cmp eax, 0x100
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
    // 0048cb23  7cce                   -jl 0x48caf3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048caf3;
    }
    // 0048cb25  81c400040000           -add esp, 0x400
    (cpu.esp) += x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 0048cb2b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cb2c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cb2d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cb2e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048cb2f:
    // 0048cb2f  ba00040000             -mov edx, 0x400
    cpu.edx = 1024 /*0x400*/;
    // 0048cb34  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048cb36  e851b9ffff             -call 0x48848c
    cpu.esp -= 4;
    sub_48848c(app, cpu);
    if (cpu.terminate) return;
    // 0048cb3b  81c400040000           -add esp, 0x400
    (cpu.esp) += x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 0048cb41  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cb42  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cb43  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cb44  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48cb48(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048cb48  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048cb49  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048cb4a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048cb4b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048cb4c  83ec6c                 -sub esp, 0x6c
    (cpu.esp) -= x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 0048cb4f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048cb51  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0048cb53  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0048cb55  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048cb57  7505                   -jne 0x48cb5e
    if (!cpu.flags.zf)
    {
        goto L_0x0048cb5e;
    }
    // 0048cb59  bed0165600             -mov esi, 0x5616d0
    cpu.esi = 5641936 /*0x5616d0*/;
L_0x0048cb5e:
    // 0048cb5e  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0048cb60  7408                   -je 0x48cb6a
    if (cpu.flags.zf)
    {
        goto L_0x0048cb6a;
    }
    // 0048cb62  3bbe3c040000           +cmp edi, dword ptr [esi + 0x43c]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1084) /* 0x43c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048cb68  7429                   -je 0x48cb93
    if (cpu.flags.zf)
    {
        goto L_0x0048cb93;
    }
L_0x0048cb6a:
    // 0048cb6a  83be3c04000000         +cmp dword ptr [esi + 0x43c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1084) /* 0x43c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048cb71  7407                   -je 0x48cb7a
    if (cpu.flags.zf)
    {
        goto L_0x0048cb7a;
    }
    // 0048cb73  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048cb75  e822010000             -call 0x48cc9c
    cpu.esp -= 4;
    sub_48cc9c(app, cpu);
    if (cpu.terminate) return;
L_0x0048cb7a:
    // 0048cb7a  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0048cb7c  751c                   -jne 0x48cb9a
    if (!cpu.flags.zf)
    {
        goto L_0x0048cb9a;
    }
L_0x0048cb7e:
    // 0048cb7e  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0048cb80  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048cb85  892df8894d00           -mov dword ptr [0x4d89f8], ebp
    app->getMemory<x86::reg32>(x86::reg32(5081592) /* 0x4d89f8 */) = cpu.ebp;
L_0x0048cb8b:
    // 0048cb8b  83c46c                 +add esp, 0x6c
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
    // 0048cb8e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cb8f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cb90  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cb91  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cb92  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048cb93:
    // 0048cb93  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048cb98  ebf1                   -jmp 0x48cb8b
    goto L_0x0048cb8b;
L_0x0048cb9a:
    // 0048cb9a  a1bc944d00             -mov eax, dword ptr [0x4d94bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5084348) /* 0x4d94bc */);
    // 0048cb9f  e814b8ffff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 0048cba4  80be5d04000000         +cmp byte ptr [esi + 0x45d], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1117) /* 0x45d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048cbab  756c                   -jne 0x48cc19
    if (!cpu.flags.zf)
    {
        goto L_0x0048cc19;
    }
L_0x0048cbad:
    // 0048cbad  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0048cbaf  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0048cbb1  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048cbb3  e8c0eaffff             -call 0x48b678
    cpu.esp -= 4;
    sub_48b678(app, cpu);
    if (cpu.terminate) return;
    // 0048cbb8  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x0048cbba:
    // 0048cbba  2eff15f8444c00         -call dword ptr cs:[0x4c44f8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998392) /* 0x4c44f8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048cbc1  a3809c4d00             -mov dword ptr [0x4d9c80], eax
    app->getMemory<x86::reg32>(x86::reg32(5086336) /* 0x4d9c80 */) = cpu.eax;
    // 0048cbc6  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0048cbc8  745f                   -je 0x48cc29
    if (cpu.flags.zf)
    {
        goto L_0x0048cc29;
    }
    // 0048cbca  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0048cbcf  8b157c9c4d00           -mov edx, dword ptr [0x4d9c7c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5086332) /* 0x4d9c7c */);
    // 0048cbd5  a3749c4d00             -mov dword ptr [0x4d9c74], eax
    app->getMemory<x86::reg32>(x86::reg32(5086324) /* 0x4d9c74 */) = cpu.eax;
    // 0048cbda  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048cbdc  7408                   -je 0x48cbe6
    if (cpu.flags.zf)
    {
        goto L_0x0048cbe6;
    }
    // 0048cbde  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048cbe0  890d7c9c4d00           -mov dword ptr [0x4d9c7c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5086332) /* 0x4d9c7c */) = cpu.ecx;
L_0x0048cbe6:
    // 0048cbe6  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0048cbeb  c7864004000000000000   -mov dword ptr [esi + 0x440], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1088) /* 0x440 */) = 0 /*0x0*/;
    // 0048cbf5  a1bc944d00             -mov eax, dword ptr [0x4d94bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5084348) /* 0x4d94bc */);
    // 0048cbfa  c7863c04000000000000   -mov dword ptr [esi + 0x43c], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1084) /* 0x43c */) = 0 /*0x0*/;
    // 0048cc04  e8c7b7ffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0048cc09  891df8894d00           -mov dword ptr [0x4d89f8], ebx
    app->getMemory<x86::reg32>(x86::reg32(5081592) /* 0x4d89f8 */) = cpu.ebx;
    // 0048cc0f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048cc11  83c46c                 -add esp, 0x6c
    (cpu.esp) += x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 0048cc14  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cc15  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cc16  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cc17  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cc18  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048cc19:
    // 0048cc19  e85a58ffff             -call 0x482478
    cpu.esp -= 4;
    sub_482478(app, cpu);
    if (cpu.terminate) return;
    // 0048cc1e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048cc20  758b                   -jne 0x48cbad
    if (!cpu.flags.zf)
    {
        goto L_0x0048cbad;
    }
    // 0048cc22  bbadcbea00             -mov ebx, 0xeacbad
    cpu.ebx = 15387565 /*0xeacbad*/;
    // 0048cc27  eb91                   -jmp 0x48cbba
    goto L_0x0048cbba;
L_0x0048cc29:
    // 0048cc29  833d7c9c4d0000         +cmp dword ptr [0x4d9c7c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5086332) /* 0x4d9c7c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048cc30  750a                   -jne 0x48cc3c
    if (!cpu.flags.zf)
    {
        goto L_0x0048cc3c;
    }
    // 0048cc32  c7057c9c4d0001000000   -mov dword ptr [0x4d9c7c], 1
    app->getMemory<x86::reg32>(x86::reg32(5086332) /* 0x4d9c7c */) = 1 /*0x1*/;
L_0x0048cc3c:
    // 0048cc3c  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0048cc40  898640040000           -mov dword ptr [esi + 0x440], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1088) /* 0x440 */) = cpu.eax;
    // 0048cc46  89be3c040000           -mov dword ptr [esi + 0x43c], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1084) /* 0x43c */) = cpu.edi;
    // 0048cc4c  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0048cc4e  0f842affffff           -je 0x48cb7e
    if (cpu.flags.zf)
    {
        goto L_0x0048cb7e;
    }
    // 0048cc54  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0048cc58  8a8e5d040000           -mov cl, byte ptr [esi + 0x45d]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1117) /* 0x45d */);
    // 0048cc5e  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0048cc62  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 0048cc64  7529                   -jne 0x48cc8f
    if (!cpu.flags.zf)
    {
        goto L_0x0048cc8f;
    }
    // 0048cc66  3bbe44040000           +cmp edi, dword ptr [esi + 0x444]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1092) /* 0x444 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048cc6c  7521                   -jne 0x48cc8f
    if (!cpu.flags.zf)
    {
        goto L_0x0048cc8f;
    }
    // 0048cc6e  8b442454               -mov eax, dword ptr [esp + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 0048cc72  8b9e64040000           -mov ebx, dword ptr [esi + 0x464]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1124) /* 0x464 */);
    // 0048cc78  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 0048cc7b  0fafd8                 -imul ebx, eax
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0048cc7e  8b8668040000           -mov eax, dword ptr [esi + 0x468]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1128) /* 0x468 */);
    // 0048cc84  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0048cc87  8b7c2424               -mov edi, dword ptr [esp + 0x24]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0048cc8b  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048cc8d  01fb                   +add ebx, edi
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
L_0x0048cc8f:
    // 0048cc8f  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048cc91  e85eb80100             -call 0x4a84f4
    cpu.esp -= 4;
    sub_4a84f4(app, cpu);
    if (cpu.terminate) return;
    // 0048cc96  e9e3feffff             -jmp 0x48cb7e
    goto L_0x0048cb7e;
}

/* align: skip 0x90 */
void Application::sub_48cc9c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048cc9c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048cc9d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048cc9e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048cc9f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048cca1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048cca3  7505                   -jne 0x48ccaa
    if (!cpu.flags.zf)
    {
        goto L_0x0048ccaa;
    }
    // 0048cca5  bbd0165600             -mov ebx, 0x5616d0
    cpu.ebx = 5641936 /*0x5616d0*/;
L_0x0048ccaa:
    // 0048ccaa  8b933c040000           -mov edx, dword ptr [ebx + 0x43c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1084) /* 0x43c */);
    // 0048ccb0  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048ccb2  750c                   -jne 0x48ccc0
    if (!cpu.flags.zf)
    {
        goto L_0x0048ccc0;
    }
    // 0048ccb4  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0048ccb6  8935f8894d00           -mov dword ptr [0x4d89f8], esi
    app->getMemory<x86::reg32>(x86::reg32(5081592) /* 0x4d89f8 */) = cpu.esi;
    // 0048ccbc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ccbd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ccbe  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ccbf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048ccc0:
    // 0048ccc0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048ccc1  8b8b40040000           -mov ecx, dword ptr [ebx + 0x440]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1088) /* 0x440 */);
    // 0048ccc7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048ccc8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048ccca  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 0048cccc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048cccd  ff9280000000           -call dword ptr [edx + 0x80]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(128) /* 0x80 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048ccd3  c7833c04000000000000   -mov dword ptr [ebx + 0x43c], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1084) /* 0x43c */) = 0 /*0x0*/;
    // 0048ccdd  c7834004000000000000   -mov dword ptr [ebx + 0x440], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1088) /* 0x440 */) = 0 /*0x0*/;
    // 0048cce7  2eff15f8444c00         -call dword ptr cs:[0x4c44f8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998392) /* 0x4c44f8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048ccee  8b1d809c4d00           -mov ebx, dword ptr [0x4d9c80]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5086336) /* 0x4d9c80 */);
    // 0048ccf4  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048ccf6  8b1d789c4d00           -mov ebx, dword ptr [0x4d9c78]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5086328) /* 0x4d9c78 */);
    // 0048ccfc  a3749c4d00             -mov dword ptr [0x4d9c74], eax
    app->getMemory<x86::reg32>(x86::reg32(5086324) /* 0x4d9c74 */) = cpu.eax;
    // 0048cd01  39d8                   +cmp eax, ebx
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
    // 0048cd03  7e05                   -jle 0x48cd0a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048cd0a;
    }
    // 0048cd05  a3789c4d00             -mov dword ptr [0x4d9c78], eax
    app->getMemory<x86::reg32>(x86::reg32(5086328) /* 0x4d9c78 */) = cpu.eax;
L_0x0048cd0a:
    // 0048cd0a  a1bc944d00             -mov eax, dword ptr [0x4d94bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5084348) /* 0x4d94bc */);
    // 0048cd0f  e8bcb6ffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0048cd14  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cd15  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0048cd17  8935f8894d00           -mov dword ptr [0x4d89f8], esi
    app->getMemory<x86::reg32>(x86::reg32(5081592) /* 0x4d89f8 */) = cpu.esi;
    // 0048cd1d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cd1e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cd1f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cd20  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48cd24(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048cd24  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048cd25  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048cd26  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048cd27  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048cd28  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048cd29  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048cd2a  83ec6c                 -sub esp, 0x6c
    (cpu.esp) -= x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 0048cd2d  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048cd2f  8b903c040000           -mov edx, dword ptr [eax + 0x43c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1084) /* 0x43c */);
    // 0048cd35  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048cd37  750f                   -jne 0x48cd48
    if (!cpu.flags.zf)
    {
        goto L_0x0048cd48;
    }
    // 0048cd39  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048cd3e  83c46c                 -add esp, 0x6c
    (cpu.esp) += x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 0048cd41  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cd42  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cd43  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cd44  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cd45  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cd46  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cd47  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048cd48:
    // 0048cd48  8b8e40040000           -mov ecx, dword ptr [esi + 0x440]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1088) /* 0x440 */);
    // 0048cd4e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048cd4f  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0048cd51  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048cd52  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0048cd54  ff9080000000           -call dword ptr [eax + 0x80]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048cd5a  2eff15f8444c00         -call dword ptr cs:[0x4c44f8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998392) /* 0x4c44f8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048cd61  8b1d809c4d00           -mov ebx, dword ptr [0x4d9c80]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5086336) /* 0x4d9c80 */);
    // 0048cd67  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048cd69  8b1d789c4d00           -mov ebx, dword ptr [0x4d9c78]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5086328) /* 0x4d9c78 */);
    // 0048cd6f  a3749c4d00             -mov dword ptr [0x4d9c74], eax
    app->getMemory<x86::reg32>(x86::reg32(5086324) /* 0x4d9c74 */) = cpu.eax;
    // 0048cd74  39d8                   +cmp eax, ebx
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
    // 0048cd76  7e05                   -jle 0x48cd7d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048cd7d;
    }
    // 0048cd78  a3789c4d00             -mov dword ptr [0x4d9c78], eax
    app->getMemory<x86::reg32>(x86::reg32(5086328) /* 0x4d9c78 */) = cpu.eax;
L_0x0048cd7d:
    // 0048cd7d  a1bc944d00             -mov eax, dword ptr [0x4d94bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5084348) /* 0x4d94bc */);
    // 0048cd82  e849b6ffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0048cd87  a1bc944d00             -mov eax, dword ptr [0x4d94bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5084348) /* 0x4d94bc */);
    // 0048cd8c  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0048cd8e  e825b6ffff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 0048cd93  2eff15f8444c00         -call dword ptr cs:[0x4c44f8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998392) /* 0x4c44f8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048cd9a  a3809c4d00             -mov dword ptr [0x4d9c80], eax
    app->getMemory<x86::reg32>(x86::reg32(5086336) /* 0x4d9c80 */) = cpu.eax;
    // 0048cd9f  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0048cda1  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048cda3  e8d0e8ffff             -call 0x48b678
    cpu.esp -= 4;
    sub_48b678(app, cpu);
    if (cpu.terminate) return;
    // 0048cda8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048cdaa  7516                   -jne 0x48cdc2
    if (!cpu.flags.zf)
    {
        goto L_0x0048cdc2;
    }
    // 0048cdac  8b6c2424               -mov ebp, dword ptr [esp + 0x24]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0048cdb0  3bae40040000           +cmp ebp, dword ptr [esi + 0x440]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1088) /* 0x440 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048cdb6  743e                   -je 0x48cdf6
    if (cpu.flags.zf)
    {
        goto L_0x0048cdf6;
    }
    // 0048cdb8  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048cdb9  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 0048cdbb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048cdbc  ff9080000000           -call dword ptr [eax + 0x80]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0048cdc2:
    // 0048cdc2  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048cdc4  a1bc944d00             -mov eax, dword ptr [0x4d94bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5084348) /* 0x4d94bc */);
    // 0048cdc9  898e40040000           -mov dword ptr [esi + 0x440], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1088) /* 0x440 */) = cpu.ecx;
    // 0048cdcf  890d749c4d00           -mov dword ptr [0x4d9c74], ecx
    app->getMemory<x86::reg32>(x86::reg32(5086324) /* 0x4d9c74 */) = cpu.ecx;
    // 0048cdd5  898e3c040000           -mov dword ptr [esi + 0x43c], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1084) /* 0x43c */) = cpu.ecx;
    // 0048cddb  e8f0b5ffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0048cde0  a1008a4d00             -mov eax, dword ptr [0x4d8a00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5081600) /* 0x4d8a00 */);
    // 0048cde5  e82e3cffff             -call 0x480a18
    cpu.esp -= 4;
    sub_480a18(app, cpu);
    if (cpu.terminate) return;
    // 0048cdea  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048cdec  83c46c                 -add esp, 0x6c
    (cpu.esp) += x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 0048cdef  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cdf0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cdf1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cdf2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cdf3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cdf4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cdf5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048cdf6:
    // 0048cdf6  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048cdfb  89be3c040000           -mov dword ptr [esi + 0x43c], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1084) /* 0x43c */) = cpu.edi;
    // 0048ce01  83c46c                 -add esp, 0x6c
    (cpu.esp) += x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 0048ce04  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ce05  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ce06  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ce07  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ce08  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ce09  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ce0a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48ce0c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048ce0c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048ce0d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048ce0e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048ce0f  83ec6c                 -sub esp, 0x6c
    (cpu.esp) -= x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 0048ce12  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048ce14  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0048ce16  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048ce18  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048ce1a  e859e8ffff             -call 0x48b678
    cpu.esp -= 4;
    sub_48b678(app, cpu);
    if (cpu.terminate) return;
    // 0048ce1f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048ce21  7507                   -jne 0x48ce2a
    if (!cpu.flags.zf)
    {
        goto L_0x0048ce2a;
    }
    // 0048ce23  83c46c                 -add esp, 0x6c
    (cpu.esp) += x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 0048ce26  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ce27  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ce28  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ce29  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048ce2a:
    // 0048ce2a  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0048ce2e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048ce2f  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0048ce31  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048ce32  ff9080000000           -call dword ptr [eax + 0x80]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048ce38  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048ce3d  83c46c                 -add esp, 0x6c
    (cpu.esp) += x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 0048ce40  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ce41  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ce42  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ce43  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48ce44(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048ce44  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048ce45  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048ce46  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048ce47  83ec7c                 -sub esp, 0x7c
    (cpu.esp) -= x86::reg32(x86::sreg32(124 /*0x7c*/));
    // 0048ce4a  8b8c248c000000         -mov ecx, dword ptr [esp + 0x8c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 0048ce51  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048ce53  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0048ce55  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0048ce57  8b9c2494000000         -mov ebx, dword ptr [esp + 0x94]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */);
    // 0048ce5e  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048ce60  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048ce62  89442478               -mov dword ptr [esp + 0x78], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */) = cpu.eax;
    // 0048ce66  89542474               -mov dword ptr [esp + 0x74], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */) = cpu.edx;
    // 0048ce6a  ba6c000000             -mov edx, 0x6c
    cpu.edx = 108 /*0x6c*/;
    // 0048ce6f  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0048ce71  e816b6ffff             -call 0x48848c
    cpu.esp -= 4;
    sub_48848c(app, cpu);
    if (cpu.terminate) return;
    // 0048ce76  b86c000000             -mov eax, 0x6c
    cpu.eax = 108 /*0x6c*/;
    // 0048ce7b  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0048ce80  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0048ce83  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0048ce87  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048ce89  7e10                   -jle 0x48ce9b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048ce9b;
    }
    // 0048ce8b  b821000000             -mov eax, 0x21
    cpu.eax = 33 /*0x21*/;
    // 0048ce90  894c2414               -mov dword ptr [esp + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 0048ce94  80cb18                 -or bl, 0x18
    cpu.bl |= x86::reg8(x86::sreg8(24 /*0x18*/));
    // 0048ce97  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x0048ce9b:
    // 0048ce9b  f6c702                 +test bh, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 2 /*0x2*/));
    // 0048ce9e  7443                   -je 0x48cee3
    if (cpu.flags.zf)
    {
        goto L_0x0048cee3;
    }
L_0x0048cea0:
    // 0048cea0  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048cea2  8d442478               -lea eax, [esp + 0x78]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 0048cea6  895c246c               -mov dword ptr [esp + 0x6c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */) = cpu.ebx;
    // 0048ceaa  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048ceab  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048ceaf  8b9c2480000000         -mov ebx, dword ptr [esp + 0x80]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 0048ceb6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048ceb7  8bac2484000000         -mov ebp, dword ptr [esp + 0x84]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */);
    // 0048cebe  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0048cec0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048cec1  ff5318                 -call dword ptr [ebx + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048cec4  25ffff0000             +and eax, 0xffff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/))));
    // 0048cec9  0f8548010000           -jne 0x48d017
    if (!cpu.flags.zf)
    {
        goto L_0x0048d017;
    }
    // 0048cecf  837c247400             +cmp dword ptr [esp + 0x74], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048ced4  755c                   -jne 0x48cf32
    if (!cpu.flags.zf)
    {
        goto L_0x0048cf32;
    }
    // 0048ced6  8b442474               -mov eax, dword ptr [esp + 0x74]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 0048ceda  83c47c                 -add esp, 0x7c
    (cpu.esp) += x86::reg32(x86::sreg32(124 /*0x7c*/));
    // 0048cedd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cede  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cedf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cee0  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x0048cee3:
    // 0048cee3  f6c704                 +test bh, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 4 /*0x4*/));
    // 0048cee6  75b8                   -jne 0x48cea0
    if (!cpu.flags.zf)
    {
        goto L_0x0048cea0;
    }
    // 0048cee8  8a642404               -mov ah, byte ptr [esp + 4]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048ceec  8b942490000000         -mov edx, dword ptr [esp + 0x90]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(144) /* 0x90 */);
    // 0048cef3  897c2408               -mov dword ptr [esp + 8], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 0048cef7  80cc06                 -or ah, 6
    cpu.ah |= x86::reg8(x86::sreg8(6 /*0x6*/));
    // 0048cefa  896c240c               -mov dword ptr [esp + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 0048cefe  88642404               -mov byte ptr [esp + 4], ah
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ah;
    // 0048cf02  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048cf04  7f9a                   -jg 0x48cea0
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048cea0;
    }
    // 0048cf06  7598                   -jne 0x48cea0
    if (!cpu.flags.zf)
    {
        goto L_0x0048cea0;
    }
    // 0048cf08  8a542405               -mov dl, byte ptr [esp + 5]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(5) /* 0x5 */);
    // 0048cf0c  bf20000000             -mov edi, 0x20
    cpu.edi = 32 /*0x20*/;
    // 0048cf11  8d6c2448               -lea ebp, [esp + 0x48]
    cpu.ebp = x86::reg32(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0048cf15  80ca10                 +or dl, 0x10
    cpu.clear_co();
    cpu.set_szp((cpu.dl |= x86::reg8(x86::sreg8(16 /*0x10*/))));
    // 0048cf18  897c2448               -mov dword ptr [esp + 0x48], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */) = cpu.edi;
    // 0048cf1c  88542405               -mov byte ptr [esp + 5], dl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(5) /* 0x5 */) = cpu.dl;
    // 0048cf20  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048cf21  8b8644040000           -mov eax, dword ptr [esi + 0x444]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1092) /* 0x444 */);
    // 0048cf27  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048cf28  8b38                   -mov edi, dword ptr [eax]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax);
    // 0048cf2a  ff5754                 -call dword ptr [edi + 0x54]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(84) /* 0x54 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048cf2d  e96effffff             -jmp 0x48cea0
    goto L_0x0048cea0;
L_0x0048cf32:
    // 0048cf32  a1bc944d00             -mov eax, dword ptr [0x4d94bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5084348) /* 0x4d94bc */);
    // 0048cf37  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0048cf39  e87ab4ffff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 0048cf3e  8b542474               -mov edx, dword ptr [esp + 0x74]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 0048cf42  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048cf44  e82fe7ffff             -call 0x48b678
    cpu.esp -= 4;
    sub_48b678(app, cpu);
    if (cpu.terminate) return;
    // 0048cf49  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048cf4b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048cf4d  7516                   -jne 0x48cf65
    if (!cpu.flags.zf)
    {
        goto L_0x0048cf65;
    }
    // 0048cf4f  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0048cf53  8b442474               -mov eax, dword ptr [esp + 0x74]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 0048cf57  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048cf58  8b7c2478               -mov edi, dword ptr [esp + 0x78]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 0048cf5c  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048cf5e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048cf5f  ff9080000000           -call dword ptr [eax + 0x80]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0048cf65:
    // 0048cf65  a1bc944d00             -mov eax, dword ptr [0x4d94bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5084348) /* 0x4d94bc */);
    // 0048cf6a  e861b4ffff             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0048cf6f  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0048cf71  0f8585000000           -jne 0x48cffc
    if (!cpu.flags.zf)
    {
        goto L_0x0048cffc;
    }
L_0x0048cf77:
    // 0048cf77  ba6c000000             -mov edx, 0x6c
    cpu.edx = 108 /*0x6c*/;
    // 0048cf7c  8b442474               -mov eax, dword ptr [esp + 0x74]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 0048cf80  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0048cf83  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 0048cf85  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0048cf87  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048cf88  8b4c2478               -mov ecx, dword ptr [esp + 0x78]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 0048cf8c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048cf8d  ff5358                 -call dword ptr [ebx + 0x58]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048cf90  bb20000000             -mov ebx, 0x20
    cpu.ebx = 32 /*0x20*/;
    // 0048cf95  8b442474               -mov eax, dword ptr [esp + 0x74]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 0048cf99  895c2448               -mov dword ptr [esp + 0x48], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */) = cpu.ebx;
    // 0048cf9d  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 0048cf9f  8d442448               -lea eax, [esp + 0x48]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0048cfa3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048cfa4  8b742478               -mov esi, dword ptr [esp + 0x78]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 0048cfa8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048cfa9  ff5354                 -call dword ptr [ebx + 0x54]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(84) /* 0x54 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048cfac  837c245408             +cmp dword ptr [esp + 0x54], 8
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048cfb1  7777                   -ja 0x48d02a
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0048d02a;
    }
    // 0048cfb3  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
    // 0048cfb8  8b9c2498000000         -mov ebx, dword ptr [esp + 0x98]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(152) /* 0x98 */);
    // 0048cfbf  8954246c               -mov dword ptr [esp + 0x6c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */) = cpu.edx;
    // 0048cfc3  89542470               -mov dword ptr [esp + 0x70], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */) = cpu.edx;
    // 0048cfc7  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0048cfc9  740f                   -je 0x48cfda
    if (cpu.flags.zf)
    {
        goto L_0x0048cfda;
    }
    // 0048cfcb  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048cfcc  8b7c2478               -mov edi, dword ptr [esp + 0x78]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 0048cfd0  8b442478               -mov eax, dword ptr [esp + 0x78]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 0048cfd4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048cfd5  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048cfd7  ff507c                 -call dword ptr [eax + 0x7c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(124) /* 0x7c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0048cfda:
    // 0048cfda  8b442474               -mov eax, dword ptr [esp + 0x74]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 0048cfde  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 0048cfe0  8d44246c               -lea eax, [esp + 0x6c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(108) /* 0x6c */);
    // 0048cfe4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048cfe5  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 0048cfe7  8b6c247c               -mov ebp, dword ptr [esp + 0x7c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 0048cfeb  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048cfec  ff5374                 -call dword ptr [ebx + 0x74]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(116) /* 0x74 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048cfef  8b442474               -mov eax, dword ptr [esp + 0x74]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 0048cff3  83c47c                 -add esp, 0x7c
    (cpu.esp) += x86::reg32(x86::sreg32(124 /*0x7c*/));
    // 0048cff6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cff7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cff8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048cff9  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x0048cffc:
    // 0048cffc  80be5f04000000         +cmp byte ptr [esi + 0x45f], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1119) /* 0x45f */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048d003  0f856effffff           -jne 0x48cf77
    if (!cpu.flags.zf)
    {
        goto L_0x0048cf77;
    }
    // 0048d009  8b6c2474               -mov ebp, dword ptr [esp + 0x74]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 0048d00d  8b442474               -mov eax, dword ptr [esp + 0x74]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 0048d011  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048d012  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048d014  ff5008                 -call dword ptr [eax + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0048d017:
    // 0048d017  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048d019  89442474               -mov dword ptr [esp + 0x74], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */) = cpu.eax;
    // 0048d01d  8b442474               -mov eax, dword ptr [esp + 0x74]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 0048d021  83c47c                 -add esp, 0x7c
    (cpu.esp) += x86::reg32(x86::sreg32(124 /*0x7c*/));
    // 0048d024  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d025  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d026  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d027  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x0048d02a:
    // 0048d02a  31ed                   +xor ebp, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp))));
    // 0048d02c  896c246c               -mov dword ptr [esp + 0x6c], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */) = cpu.ebp;
    // 0048d030  896c2470               -mov dword ptr [esp + 0x70], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */) = cpu.ebp;
    // 0048d034  eba4                   -jmp 0x48cfda
    goto L_0x0048cfda;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48d038(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048d038  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048d039  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048d03b  7505                   -jne 0x48d042
    if (!cpu.flags.zf)
    {
        goto L_0x0048d042;
    }
    // 0048d03d  b8d0165600             -mov eax, 0x5616d0
    cpu.eax = 5641936 /*0x5616d0*/;
L_0x0048d042:
    // 0048d042  3b903c040000           +cmp edx, dword ptr [eax + 0x43c]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1084) /* 0x43c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048d048  7408                   -je 0x48d052
    if (cpu.flags.zf)
    {
        goto L_0x0048d052;
    }
    // 0048d04a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048d04b  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0048d04d  ff5008                 -call dword ptr [eax + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048d050  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d051  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048d052:
    // 0048d052  e845fcffff             -call 0x48cc9c
    cpu.esp -= 4;
    sub_48cc9c(app, cpu);
    if (cpu.terminate) return;
    // 0048d057  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048d058  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0048d05a  ff5008                 -call dword ptr [eax + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048d05d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d05e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48d060(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048d060  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048d061  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048d062  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048d063  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0048d065  ff5260                 -call dword ptr [edx + 0x60]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(96) /* 0x60 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048d068  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d069  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d06a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48d06c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048d06c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048d06d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048d06e  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048d071  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048d073  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0048d076  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0048d078  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0048d07d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048d07e  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048d082  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0048d086  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048d087  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0048d089  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048d08a  ff5130                 -call dword ptr [ecx + 0x30]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(48) /* 0x30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048d08d  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0048d090  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048d093  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d094  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d095  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48d098(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048d098  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048d099  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048d09a  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048d09d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048d09f  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0048d0a2  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0048d0a4  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0048d0a9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048d0aa  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048d0ae  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0048d0b2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048d0b3  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0048d0b5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048d0b6  ff5130                 -call dword ptr [ecx + 0x30]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(48) /* 0x30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048d0b9  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0048d0bc  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048d0bf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d0c0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d0c1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48d0c4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048d0c4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048d0c5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048d0c6  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048d0c9  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048d0cb  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0048d0ce  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0048d0d0  b900000200             -mov ecx, 0x20000
    cpu.ecx = 131072 /*0x20000*/;
    // 0048d0d5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048d0d6  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048d0da  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0048d0de  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048d0df  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0048d0e1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048d0e2  ff5130                 -call dword ptr [ecx + 0x30]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(48) /* 0x30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048d0e5  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0048d0e8  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048d0eb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d0ec  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d0ed  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48d0f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048d0f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048d0f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048d0f2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048d0f3  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x0048d0f5:
    // 0048d0f5  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0048d0f7  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0048d0f9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048d0fa  ff5034                 -call dword ptr [eax + 0x34]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048d0fd  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0048d102  3d1c027688             +cmp eax, 0x8876021c
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2289435164 /*0x8876021c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048d107  74ec                   -je 0x48d0f5
    if (cpu.flags.zf)
    {
        goto L_0x0048d0f5;
    }
    // 0048d109  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d10a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d10b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d10c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48d110(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048d110  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048d111  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048d112  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048d113  83ec6c                 -sub esp, 0x6c
    (cpu.esp) -= x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 0048d116  8bac2480000000         -mov ebp, dword ptr [esp + 0x80]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 0048d11d  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0048d11f  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0048d121  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0048d123  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 0048d125  ba6c000000             -mov edx, 0x6c
    cpu.edx = 108 /*0x6c*/;
    // 0048d12a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048d12b  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0048d12f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048d130  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0048d132  ff5258                 -call dword ptr [edx + 0x58]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048d135  66a9ffff               +test ax, 0xffff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & 65535 /*0xffff*/));
    // 0048d139  0f8575000000           -jne 0x48d1b4
    if (!cpu.flags.zf)
    {
        goto L_0x0048d1b4;
    }
    // 0048d13f  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048d141  7406                   -je 0x48d149
    if (cpu.flags.zf)
    {
        goto L_0x0048d149;
    }
    // 0048d143  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048d147  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
L_0x0048d149:
    // 0048d149  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0048d14b  7406                   -je 0x48d153
    if (cpu.flags.zf)
    {
        goto L_0x0048d153;
    }
    // 0048d14d  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048d151  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
L_0x0048d153:
    // 0048d153  8b74247c               -mov esi, dword ptr [esp + 0x7c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 0048d157  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048d159  7406                   -je 0x48d161
    if (cpu.flags.zf)
    {
        goto L_0x0048d161;
    }
    // 0048d15b  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0048d15f  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
L_0x0048d161:
    // 0048d161  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0048d163  7407                   -je 0x48d16c
    if (cpu.flags.zf)
    {
        goto L_0x0048d16c;
    }
    // 0048d165  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0048d169  894500                 -mov dword ptr [ebp], eax
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
L_0x0048d16c:
    // 0048d16c  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0048d16e  740f                   -je 0x48d17f
    if (cpu.flags.zf)
    {
        goto L_0x0048d17f;
    }
    // 0048d170  837c245410             +cmp dword ptr [esp + 0x54], 0x10
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048d175  7411                   -je 0x48d188
    if (cpu.flags.zf)
    {
        goto L_0x0048d188;
    }
    // 0048d177  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048d179  8a442454               -mov al, byte ptr [esp + 0x54]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 0048d17d  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
L_0x0048d17f:
    // 0048d17f  83c46c                 -add esp, 0x6c
    (cpu.esp) += x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 0048d182  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d183  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d184  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d185  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0048d188:
    // 0048d188  8b442458               -mov eax, dword ptr [esp + 0x58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 0048d18c  e893e6ffff             -call 0x48b824
    cpu.esp -= 4;
    sub_48b824(app, cpu);
    if (cpu.terminate) return;
    // 0048d191  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048d193  8b44245c               -mov eax, dword ptr [esp + 0x5c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 0048d197  e888e6ffff             -call 0x48b824
    cpu.esp -= 4;
    sub_48b824(app, cpu);
    if (cpu.terminate) return;
    // 0048d19c  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048d19e  8b442460               -mov eax, dword ptr [esp + 0x60]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 0048d1a2  e87de6ffff             -call 0x48b824
    cpu.esp -= 4;
    sub_48b824(app, cpu);
    if (cpu.terminate) return;
    // 0048d1a7  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048d1a9  8933                   -mov dword ptr [ebx], esi
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.esi;
    // 0048d1ab  83c46c                 -add esp, 0x6c
    (cpu.esp) += x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 0048d1ae  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d1af  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d1b0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d1b1  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0048d1b4:
    // 0048d1b4  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048d1b6  7406                   -je 0x48d1be
    if (cpu.flags.zf)
    {
        goto L_0x0048d1be;
    }
    // 0048d1b8  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
L_0x0048d1be:
    // 0048d1be  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0048d1c0  7406                   -je 0x48d1c8
    if (cpu.flags.zf)
    {
        goto L_0x0048d1c8;
    }
    // 0048d1c2  c70700000000           -mov dword ptr [edi], 0
    app->getMemory<x86::reg32>(cpu.edi) = 0 /*0x0*/;
L_0x0048d1c8:
    // 0048d1c8  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0048d1ca  7406                   -je 0x48d1d2
    if (cpu.flags.zf)
    {
        goto L_0x0048d1d2;
    }
    // 0048d1cc  c70300000000           -mov dword ptr [ebx], 0
    app->getMemory<x86::reg32>(cpu.ebx) = 0 /*0x0*/;
L_0x0048d1d2:
    // 0048d1d2  8b4c247c               -mov ecx, dword ptr [esp + 0x7c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 0048d1d6  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048d1d8  7406                   -je 0x48d1e0
    if (cpu.flags.zf)
    {
        goto L_0x0048d1e0;
    }
    // 0048d1da  c70100000000           -mov dword ptr [ecx], 0
    app->getMemory<x86::reg32>(cpu.ecx) = 0 /*0x0*/;
L_0x0048d1e0:
    // 0048d1e0  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0048d1e2  749b                   -je 0x48d17f
    if (cpu.flags.zf)
    {
        goto L_0x0048d17f;
    }
    // 0048d1e4  c7450000000000         -mov dword ptr [ebp], 0
    app->getMemory<x86::reg32>(cpu.ebp) = 0 /*0x0*/;
    // 0048d1eb  83c46c                 -add esp, 0x6c
    (cpu.esp) += x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 0048d1ee  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d1ef  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d1f0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d1f1  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_48d1f4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048d1f4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048d1f5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048d1f6  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048d1f9  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0048d1fb  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048d1fc  6838064e00             -push 0x4e0638
    app->getMemory<x86::reg32>(cpu.esp-4) = 5113400 /*0x4e0638*/;
    cpu.esp -= 4;
    // 0048d201  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0048d203  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048d204  ff11                   -call dword ptr [ecx]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048d206  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0048d209  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048d20b  7506                   -jne 0x48d213
    if (!cpu.flags.zf)
    {
        goto L_0x0048d213;
    }
    // 0048d20d  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048d210  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d211  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d212  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048d213:
    // 0048d213  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048d214  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048d216  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0048d218  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048d219  ff9094000000           -call dword ptr [eax + 0x94]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(148) /* 0x94 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048d21f  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048d223  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048d227  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048d228  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048d22a  ff5008                 -call dword ptr [eax + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048d22d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d22e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048d231  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d232  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d233  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48d234(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048d234  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048d235  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048d236  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048d239  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0048d23b  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048d23c  6838064e00             -push 0x4e0638
    app->getMemory<x86::reg32>(cpu.esp-4) = 5113400 /*0x4e0638*/;
    cpu.esp -= 4;
    // 0048d241  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0048d243  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048d244  ff11                   -call dword ptr [ecx]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048d246  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0048d249  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048d24b  7506                   -jne 0x48d253
    if (!cpu.flags.zf)
    {
        goto L_0x0048d253;
    }
    // 0048d24d  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048d250  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d251  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d252  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048d253:
    // 0048d253  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048d254  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048d256  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0048d258  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048d259  ff9098000000           -call dword ptr [eax + 0x98]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(152) /* 0x98 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048d25f  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048d263  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048d267  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048d268  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048d26a  ff5008                 -call dword ptr [eax + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048d26d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d26e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048d271  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d272  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d273  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48d274(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048d274  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048d275  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048d276  83ec74                 -sub esp, 0x74
    (cpu.esp) -= x86::reg32(x86::sreg32(116 /*0x74*/));
    // 0048d279  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048d27b  bf64000000             -mov edi, 0x64
    cpu.edi = 100 /*0x64*/;
    // 0048d280  8b842484000000         -mov eax, dword ptr [esp + 0x84]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */);
    // 0048d287  895c2468               -mov dword ptr [esp + 0x68], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */) = cpu.ebx;
    // 0048d28b  89542464               -mov dword ptr [esp + 0x64], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */) = cpu.edx;
    // 0048d28f  89442450               -mov dword ptr [esp + 0x50], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */) = cpu.eax;
    // 0048d293  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048d295  8b842480000000         -mov eax, dword ptr [esp + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 0048d29c  8954246c               -mov dword ptr [esp + 0x6c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */) = cpu.edx;
    // 0048d2a0  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0048d2a2  8d542464               -lea edx, [esp + 0x64]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 0048d2a6  89442470               -mov dword ptr [esp + 0x70], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */) = cpu.eax;
    // 0048d2aa  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048d2ac  893c24                 -mov dword ptr [esp], edi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edi;
    // 0048d2af  e828e5ffff             -call 0x48b7dc
    cpu.esp -= 4;
    sub_48b7dc(app, cpu);
    if (cpu.terminate) return;
    // 0048d2b4  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0048d2b6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048d2b7  6800040001             -push 0x1000400
    app->getMemory<x86::reg32>(cpu.esp-4) = 16778240 /*0x1000400*/;
    cpu.esp -= 4;
    // 0048d2bc  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048d2be  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048d2c0  8d442474               -lea eax, [esp + 0x74]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 0048d2c4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048d2c5  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 0048d2c7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048d2c8  ff5214                 -call dword ptr [edx + 0x14]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048d2cb  66a9ffff               +test ax, 0xffff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & 65535 /*0xffff*/));
    // 0048d2cf  750d                   -jne 0x48d2de
    if (!cpu.flags.zf)
    {
        goto L_0x0048d2de;
    }
    // 0048d2d1  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048d2d6  83c474                 -add esp, 0x74
    (cpu.esp) += x86::reg32(x86::sreg32(116 /*0x74*/));
    // 0048d2d9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d2da  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d2db  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0048d2de:
    // 0048d2de  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048d2e0  83c474                 -add esp, 0x74
    (cpu.esp) += x86::reg32(x86::sreg32(116 /*0x74*/));
    // 0048d2e3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d2e4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d2e5  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_48d2e8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048d2e8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048d2e9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048d2ea  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048d2eb  81ec8c000000           -sub esp, 0x8c
    (cpu.esp) -= x86::reg32(x86::sreg32(140 /*0x8c*/));
    // 0048d2f1  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048d2f3  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0048d2f5  898c2484000000         -mov dword ptr [esp + 0x84], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */) = cpu.ecx;
    // 0048d2fc  8b8424b4000000         -mov eax, dword ptr [esp + 0xb4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(180) /* 0xb4 */);
    // 0048d303  8bac249c000000         -mov ebp, dword ptr [esp + 0x9c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */);
    // 0048d30a  897c2468               -mov dword ptr [esp + 0x68], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */) = cpu.edi;
    // 0048d30e  01fd                   -add ebp, edi
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edi));
    // 0048d310  8bbc2484000000         -mov edi, dword ptr [esp + 0x84]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */);
    // 0048d317  89542464               -mov dword ptr [esp + 0x64], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */) = cpu.edx;
    // 0048d31b  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048d31d  8b9424a8000000         -mov edx, dword ptr [esp + 0xa8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(168) /* 0xa8 */);
    // 0048d324  897c246c               -mov dword ptr [esp + 0x6c], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */) = cpu.edi;
    // 0048d328  89542478               -mov dword ptr [esp + 0x78], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */) = cpu.edx;
    // 0048d32c  8b9424a4000000         -mov edx, dword ptr [esp + 0xa4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(164) /* 0xa4 */);
    // 0048d333  8bbc24b0000000         -mov edi, dword ptr [esp + 0xb0]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(176) /* 0xb0 */);
    // 0048d33a  89542474               -mov dword ptr [esp + 0x74], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */) = cpu.edx;
    // 0048d33e  8b9424a8000000         -mov edx, dword ptr [esp + 0xa8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(168) /* 0xa8 */);
    // 0048d345  896c2470               -mov dword ptr [esp + 0x70], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */) = cpu.ebp;
    // 0048d349  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0048d34b  8bac24ac000000         -mov ebp, dword ptr [esp + 0xac]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(172) /* 0xac */);
    // 0048d352  89942480000000         -mov dword ptr [esp + 0x80], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */) = cpu.edx;
    // 0048d359  8b9424a4000000         -mov edx, dword ptr [esp + 0xa4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(164) /* 0xa4 */);
    // 0048d360  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0048d362  bb00000001             -mov ebx, 0x1000000
    cpu.ebx = 16777216 /*0x1000000*/;
    // 0048d367  8954247c               -mov dword ptr [esp + 0x7c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */) = cpu.edx;
    // 0048d36b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048d36d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048d36f  83e203                 -and edx, 3
    cpu.edx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0048d372  898c2488000000         -mov dword ptr [esp + 0x88], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */) = cpu.ecx;
    // 0048d379  83fa03                 +cmp edx, 3
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
    // 0048d37c  0f859f000000           -jne 0x48d421
    if (!cpu.flags.zf)
    {
        goto L_0x0048d421;
    }
    // 0048d382  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
L_0x0048d387:
    // 0048d387  a804                   +test al, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 4 /*0x4*/));
    // 0048d389  7403                   -je 0x48d38e
    if (cpu.flags.zf)
    {
        goto L_0x0048d38e;
    }
    // 0048d38b  80c902                 -or cl, 2
    cpu.cl |= x86::reg8(x86::sreg8(2 /*0x2*/));
L_0x0048d38e:
    // 0048d38e  a808                   +test al, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 8 /*0x8*/));
    // 0048d390  7403                   -je 0x48d395
    if (cpu.flags.zf)
    {
        goto L_0x0048d395;
    }
    // 0048d392  80c904                 -or cl, 4
    cpu.cl |= x86::reg8(x86::sreg8(4 /*0x4*/));
L_0x0048d395:
    // 0048d395  a810                   +test al, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 16 /*0x10*/));
    // 0048d397  7403                   -je 0x48d39c
    if (cpu.flags.zf)
    {
        goto L_0x0048d39c;
    }
    // 0048d399  80cf80                 -or bh, 0x80
    cpu.bh |= x86::reg8(x86::sreg8(128 /*0x80*/));
L_0x0048d39c:
    // 0048d39c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048d39e  7424                   -je 0x48d3c4
    if (cpu.flags.zf)
    {
        goto L_0x0048d3c4;
    }
    // 0048d3a0  ba64000000             -mov edx, 0x64
    cpu.edx = 100 /*0x64*/;
    // 0048d3a5  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0048d3a7  e8e0b0ffff             -call 0x48848c
    cpu.esp -= 4;
    sub_48848c(app, cpu);
    if (cpu.terminate) return;
    // 0048d3ac  b864000000             -mov eax, 0x64
    cpu.eax = 100 /*0x64*/;
    // 0048d3b1  80cf08                 -or bh, 8
    cpu.bh |= x86::reg8(x86::sreg8(8 /*0x8*/));
    // 0048d3b4  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0048d3b7  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0048d3b9  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0048d3bd  89842488000000         -mov dword ptr [esp + 0x88], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */) = cpu.eax;
L_0x0048d3c4:
    // 0048d3c4  8d542464               -lea edx, [esp + 0x64]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 0048d3c8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048d3ca  e80de4ffff             -call 0x48b7dc
    cpu.esp -= 4;
    sub_48b7dc(app, cpu);
    if (cpu.terminate) return;
    // 0048d3cf  8d542474               -lea edx, [esp + 0x74]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 0048d3d3  8b8424a0000000         -mov eax, dword ptr [esp + 0xa0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(160) /* 0xa0 */);
    // 0048d3da  8b8c2488000000         -mov ecx, dword ptr [esp + 0x88]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */);
    // 0048d3e1  e8f6e3ffff             -call 0x48b7dc
    cpu.esp -= 4;
    sub_48b7dc(app, cpu);
    if (cpu.terminate) return;
    // 0048d3e6  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048d3e7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048d3e8  8d44246c               -lea eax, [esp + 0x6c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(108) /* 0x6c */);
    // 0048d3ec  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048d3ed  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048d3ee  8d842484000000         -lea eax, [esp + 0x84]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(132) /* 0x84 */);
    // 0048d3f5  8b9424b0000000         -mov edx, dword ptr [esp + 0xb0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(176) /* 0xb0 */);
    // 0048d3fc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048d3fd  8b9c24b4000000         -mov ebx, dword ptr [esp + 0xb4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(180) /* 0xb4 */);
    // 0048d404  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 0048d406  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048d407  ff5214                 -call dword ptr [edx + 0x14]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048d40a  66a9ffff               +test ax, 0xffff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & 65535 /*0xffff*/));
    // 0048d40e  7531                   -jne 0x48d441
    if (!cpu.flags.zf)
    {
        goto L_0x0048d441;
    }
    // 0048d410  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048d415  81c48c000000           -add esp, 0x8c
    (cpu.esp) += x86::reg32(x86::sreg32(140 /*0x8c*/));
    // 0048d41b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d41c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d41d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d41e  c21c00                 -ret 0x1c
    cpu.esp += 4+28 /*0x1c*/;
    return;
L_0x0048d421:
    // 0048d421  a802                   +test al, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 2 /*0x2*/));
    // 0048d423  740a                   -je 0x48d42f
    if (cpu.flags.zf)
    {
        goto L_0x0048d42f;
    }
    // 0048d425  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 0048d42a  e958ffffff             -jmp 0x48d387
    goto L_0x0048d387;
L_0x0048d42f:
    // 0048d42f  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 0048d431  0f8450ffffff           -je 0x48d387
    if (cpu.flags.zf)
    {
        goto L_0x0048d387;
    }
    // 0048d437  b940000000             -mov ecx, 0x40
    cpu.ecx = 64 /*0x40*/;
    // 0048d43c  e946ffffff             -jmp 0x48d387
    goto L_0x0048d387;
L_0x0048d441:
    // 0048d441  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048d443  81c48c000000           -add esp, 0x8c
    (cpu.esp) += x86::reg32(x86::sreg32(140 /*0x8c*/));
    // 0048d449  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d44a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d44b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d44c  c21c00                 -ret 0x1c
    cpu.esp += 4+28 /*0x1c*/;
    return;
}

/* align: skip 0x90 */
void Application::sub_48d450(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048d450  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048d451  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048d452  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048d453  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0048d456  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0048d45a  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0048d45e  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0048d460  be50b54800             -mov esi, 0x48b550
    cpu.esi = 4765008 /*0x48b550*/;
    // 0048d465  8b4c242c               -mov ecx, dword ptr [esp + 0x2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0048d469  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0048d46a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0048d46b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0048d46c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0048d46d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048d46f  7502                   -jne 0x48d473
    if (!cpu.flags.zf)
    {
        goto L_0x0048d473;
    }
    // 0048d471  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
L_0x0048d473:
    // 0048d473  8b5c2428               -mov ebx, dword ptr [esp + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0048d477  ffd1                   -call ecx
    cpu.ip = cpu.ecx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048d479  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048d47e  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0048d481  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d482  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d483  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d484  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x90 */
void Application::sub_48d488(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048d488  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048d489  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048d48a  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048d48e  8b5354                 -mov edx, dword ptr [ebx + 0x54]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(84) /* 0x54 */);
    // 0048d491  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0048d495  83fa10                 +cmp edx, 0x10
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
    // 0048d498  744a                   -je 0x48d4e4
    if (cpu.flags.zf)
    {
        goto L_0x0048d4e4;
    }
    // 0048d49a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048d49c  8a4354                 -mov al, byte ptr [ebx + 0x54]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(84) /* 0x54 */);
L_0x0048d49f:
    // 0048d49f  83f810                 +cmp eax, 0x10
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
    // 0048d4a2  7360                   -jae 0x48d504
    if (!cpu.flags.cf)
    {
        goto L_0x0048d504;
    }
    // 0048d4a4  83f808                 +cmp eax, 8
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
    // 0048d4a7  0f8380000000           -jae 0x48d52d
    if (!cpu.flags.cf)
    {
        goto L_0x0048d52d;
    }
L_0x0048d4ad:
    // 0048d4ad  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048d4af  7429                   -je 0x48d4da
    if (cpu.flags.zf)
    {
        goto L_0x0048d4da;
    }
    // 0048d4b1  837e1000               +cmp dword ptr [esi + 0x10], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048d4b5  0f8495000000           -je 0x48d550
    if (cpu.flags.zf)
    {
        goto L_0x0048d550;
    }
    // 0048d4bb  a138215600             -mov eax, dword ptr [0x562138]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5644600) /* 0x562138 */);
    // 0048d4c0  3b4608                 +cmp eax, dword ptr [esi + 8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048d4c3  0f8d87000000           -jge 0x48d550
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048d550;
    }
    // 0048d4c9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048d4cb  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048d4cd  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048d4cf  e870e3ffff             -call 0x48b844
    cpu.esp -= 4;
    sub_48b844(app, cpu);
    if (cpu.terminate) return;
L_0x0048d4d4:
    // 0048d4d4  ff0538215600           -inc dword ptr [0x562138]
    (app->getMemory<x86::reg32>(x86::reg32(5644600) /* 0x562138 */))++;
L_0x0048d4da:
    // 0048d4da  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048d4df  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d4e0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d4e1  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0048d4e4:
    // 0048d4e4  8b4358                 -mov eax, dword ptr [ebx + 0x58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(88) /* 0x58 */);
    // 0048d4e7  e838e3ffff             -call 0x48b824
    cpu.esp -= 4;
    sub_48b824(app, cpu);
    if (cpu.terminate) return;
    // 0048d4ec  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048d4ee  8b435c                 -mov eax, dword ptr [ebx + 0x5c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(92) /* 0x5c */);
    // 0048d4f1  e82ee3ffff             -call 0x48b824
    cpu.esp -= 4;
    sub_48b824(app, cpu);
    if (cpu.terminate) return;
    // 0048d4f6  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048d4f8  8b4360                 -mov eax, dword ptr [ebx + 0x60]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(96) /* 0x60 */);
    // 0048d4fb  e824e3ffff             -call 0x48b824
    cpu.esp -= 4;
    sub_48b824(app, cpu);
    if (cpu.terminate) return;
    // 0048d500  01d0                   +add eax, edx
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
    // 0048d502  eb9b                   -jmp 0x48d49f
    goto L_0x0048d49f;
L_0x0048d504:
    // 0048d504  7709                   -ja 0x48d50f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0048d50f;
    }
    // 0048d506  800d3021560004         +or byte ptr [0x562130], 4
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(x86::reg32(5644592) /* 0x562130 */) |= x86::reg8(x86::sreg8(4 /*0x4*/))));
    // 0048d50d  eb9e                   -jmp 0x48d4ad
    goto L_0x0048d4ad;
L_0x0048d50f:
    // 0048d50f  83f818                 +cmp eax, 0x18
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
    // 0048d512  7299                   -jb 0x48d4ad
    if (cpu.flags.cf)
    {
        goto L_0x0048d4ad;
    }
    // 0048d514  7709                   -ja 0x48d51f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0048d51f;
    }
    // 0048d516  800d3021560008         +or byte ptr [0x562130], 8
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(x86::reg32(5644592) /* 0x562130 */) |= x86::reg8(x86::sreg8(8 /*0x8*/))));
    // 0048d51d  eb8e                   -jmp 0x48d4ad
    goto L_0x0048d4ad;
L_0x0048d51f:
    // 0048d51f  83f820                 +cmp eax, 0x20
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
    // 0048d522  7589                   -jne 0x48d4ad
    if (!cpu.flags.zf)
    {
        goto L_0x0048d4ad;
    }
    // 0048d524  800d3021560010         +or byte ptr [0x562130], 0x10
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(x86::reg32(5644592) /* 0x562130 */) |= x86::reg8(x86::sreg8(16 /*0x10*/))));
    // 0048d52b  eb80                   -jmp 0x48d4ad
    goto L_0x0048d4ad;
L_0x0048d52d:
    // 0048d52d  770c                   -ja 0x48d53b
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0048d53b;
    }
    // 0048d52f  800d3021560001         +or byte ptr [0x562130], 1
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(x86::reg32(5644592) /* 0x562130 */) |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 0048d536  e972ffffff             -jmp 0x48d4ad
    goto L_0x0048d4ad;
L_0x0048d53b:
    // 0048d53b  83f80f                 +cmp eax, 0xf
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
    // 0048d53e  0f8569ffffff           -jne 0x48d4ad
    if (!cpu.flags.zf)
    {
        goto L_0x0048d4ad;
    }
    // 0048d544  800d3021560002         +or byte ptr [0x562130], 2
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(x86::reg32(5644592) /* 0x562130 */) |= x86::reg8(x86::sreg8(2 /*0x2*/))));
    // 0048d54b  e95dffffff             -jmp 0x48d4ad
    goto L_0x0048d4ad;
L_0x0048d550:
    // 0048d550  837e1000               +cmp dword ptr [esi + 0x10], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048d554  0f847affffff           -je 0x48d4d4
    if (cpu.flags.zf)
    {
        goto L_0x0048d4d4;
    }
    // 0048d55a  a138215600             -mov eax, dword ptr [0x562138]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5644600) /* 0x562138 */);
    // 0048d55f  3b4608                 +cmp eax, dword ptr [esi + 8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048d562  0f8c6cffffff           -jl 0x48d4d4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048d4d4;
    }
    // 0048d568  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048d56a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d56b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d56c  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_48d56f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048d56f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048d570  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0048d572  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048d573  88d6                   -mov dh, dl
    cpu.dh = cpu.dl;
    // 0048d575  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 0048d578  88f2                   -mov dl, dh
    cpu.dl = cpu.dh;
    // 0048d57a  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 0048d57d  88f2                   -mov dl, dh
    cpu.dl = cpu.dh;
    // 0048d57f  e80cb10100             -call 0x4a8690
    cpu.esp -= 4;
    sub_4a8690(app, cpu);
    if (cpu.terminate) return;
    // 0048d584  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d585  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d586  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_48d590(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048d590  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048d591  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048d592  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048d593  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0048d596  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0048d59a  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0048d59c  895c241c               -mov dword ptr [esp + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 0048d5a0  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0048d5a2  7444                   -je 0x48d5e8
    if (cpu.flags.zf)
    {
        goto L_0x0048d5e8;
    }
L_0x0048d5a4:
    // 0048d5a4  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0048d5a8  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0048d5aa  7547                   -jne 0x48d5f3
    if (!cpu.flags.zf)
    {
        goto L_0x0048d5f3;
    }
    // 0048d5ac  c744241c08000000       -mov dword ptr [esp + 0x1c], 8
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = 8 /*0x8*/;
L_0x0048d5b4:
    // 0048d5b4  8b6c241c               -mov ebp, dword ptr [esp + 0x1c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
L_0x0048d5b8:
    // 0048d5b8  a160b04d00             -mov eax, dword ptr [0x4db060]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5091424) /* 0x4db060 */);
    // 0048d5bd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048d5bf  741e                   -je 0x48d5df
    if (cpu.flags.zf)
    {
        goto L_0x0048d5df;
    }
    // 0048d5c1  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0048d5c5  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048d5c7  7c14                   -jl 0x48d5dd
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048d5dd;
    }
    // 0048d5c9  81fa00400000           +cmp edx, 0x4000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16384 /*0x4000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048d5cf  7f0c                   -jg 0x48d5dd
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048d5dd;
    }
    // 0048d5d1  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0048d5d3  7c08                   -jl 0x48d5dd
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048d5dd;
    }
    // 0048d5d5  81ff00200000           +cmp edi, 0x2000
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8192 /*0x2000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048d5db  7e22                   -jle 0x48d5ff
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048d5ff;
    }
L_0x0048d5dd:
    // 0048d5dd  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0048d5df:
    // 0048d5df  83c420                 +add esp, 0x20
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
    // 0048d5e2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d5e3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d5e4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d5e5  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0048d5e8:
    // 0048d5e8  a1a0894d00             -mov eax, dword ptr [0x4d89a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5081504) /* 0x4d89a0 */);
    // 0048d5ed  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0048d5f1  ebb1                   -jmp 0x48d5a4
    goto L_0x0048d5a4;
L_0x0048d5f3:
    // 0048d5f3  83fb0f                 +cmp ebx, 0xf
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
    // 0048d5f6  75bc                   -jne 0x48d5b4
    if (!cpu.flags.zf)
    {
        goto L_0x0048d5b4;
    }
    // 0048d5f8  bd10000000             -mov ebp, 0x10
    cpu.ebp = 16 /*0x10*/;
    // 0048d5fd  ebb9                   -jmp 0x48d5b8
    goto L_0x0048d5b8;
L_0x0048d5ff:
    // 0048d5ff  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0048d603  e838b10100             -call 0x4a8740
    cpu.esp -= 4;
    sub_4a8740(app, cpu);
    if (cpu.terminate) return;
    // 0048d608  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048d60a  74d3                   -je 0x48d5df
    if (cpu.flags.zf)
    {
        goto L_0x0048d5df;
    }
    // 0048d60c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048d60e  0fafc5                 -imul eax, ebp
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 0048d611  83c007                 -add eax, 7
    (cpu.eax) += x86::reg32(x86::sreg32(7 /*0x7*/));
    // 0048d614  24f8                   -and al, 0xf8
    cpu.al &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 0048d616  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048d618  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048d61b  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0048d61d  0fafc5                 -imul eax, ebp
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 0048d620  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 0048d623  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048d625  0fafd7                 -imul edx, edi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 0048d628  8b74241c               -mov esi, dword ptr [esp + 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0048d62c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048d62d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048d62e  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0048d632  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0048d636  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048d637  684ce34c00             -push 0x4ce34c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5038924 /*0x4ce34c*/;
    cpu.esp -= 4;
    // 0048d63c  8d442410               -lea eax, [esp + 0x10]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0048d640  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048d641  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0048d643  e82973ffff             -call 0x484971
    cpu.esp -= 4;
    sub_484971(app, cpu);
    if (cpu.terminate) return;
    // 0048d648  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0048d64b  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0048d64d  83c248                 -add edx, 0x48
    (cpu.edx) += x86::reg32(x86::sreg32(72 /*0x48*/));
    // 0048d650  e8a752ffff             -call 0x4828fc
    cpu.esp -= 4;
    sub_4828fc(app, cpu);
    if (cpu.terminate) return;
    // 0048d655  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0048d659  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048d65b  7521                   -jne 0x48d67e
    if (!cpu.flags.zf)
    {
        goto L_0x0048d67e;
    }
    // 0048d65d  837c243000             +cmp dword ptr [esp + 0x30], 0
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
    // 0048d662  0f8475ffffff           -je 0x48d5dd
    if (cpu.flags.zf)
    {
        goto L_0x0048d5dd;
    }
    // 0048d668  ff05108a4d00           -inc dword ptr [0x4d8a10]
    (app->getMemory<x86::reg32>(x86::reg32(5081616) /* 0x4d8a10 */))++;
    // 0048d66e  e83959ffff             -call 0x482fac
    cpu.esp -= 4;
    sub_482fac(app, cpu);
    if (cpu.terminate) return;
    // 0048d673  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048d675  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0048d678  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d679  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d67a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d67b  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0048d67e:
    // 0048d67e  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 0048d680  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048d682  0f8455ffffff           -je 0x48d5dd
    if (cpu.flags.zf)
    {
        goto L_0x0048d5dd;
    }
    // 0048d688  ba48000000             -mov edx, 0x48
    cpu.edx = 72 /*0x48*/;
    // 0048d68d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048d68f  e8f8adffff             -call 0x48848c
    cpu.esp -= 4;
    sub_48848c(app, cpu);
    if (cpu.terminate) return;
    // 0048d694  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0048d698  8d5638                 -lea edx, [esi + 0x38]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(56) /* 0x38 */);
    // 0048d69b  e8a0b00100             -call 0x4a8740
    cpu.esp -= 4;
    sub_4a8740(app, cpu);
    if (cpu.terminate) return;
    // 0048d6a0  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
    // 0048d6a3  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0048d6a8  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 0048d6aa  66897a06               -mov word ptr [edx + 6], di
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(6) /* 0x6 */) = cpu.di;
    // 0048d6ae  09c1                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0048d6b0  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0048d6b4  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 0048d6b6  66894204               -mov word ptr [edx + 4], ax
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ax;
    // 0048d6ba  c706444e4957           -mov dword ptr [esi], 0x57494e44
    app->getMemory<x86::reg32>(cpu.esi) = 1464421956 /*0x57494e44*/;
    // 0048d6c0  897e08                 -mov dword ptr [esi + 8], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 0048d6c3  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0048d6c7  897e18                 -mov dword ptr [esi + 0x18], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 0048d6ca  894628                 -mov dword ptr [esi + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 0048d6cd  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0048d6d1  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0048d6d4  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0048d6d7  8a44241c               -mov al, byte ptr [esp + 0x1c]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0048d6db  88461c                 -mov byte ptr [esi + 0x1c], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.al;
    // 0048d6de  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048d6e0  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0048d6e2  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0048d6e4  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0048d6e9  895620                 -mov dword ptr [esi + 0x20], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 0048d6ec  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0048d6f0  88461d                 -mov byte ptr [esi + 0x1d], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(29) /* 0x1d */) = cpu.al;
    // 0048d6f3  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 0048d6f8  e8b7890000             -call 0x4960b4
    cpu.esp -= 4;
    sub_4960b4(app, cpu);
    if (cpu.terminate) return;
    // 0048d6fd  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0048d701  bb03000000             -mov ebx, 3
    cpu.ebx = 3 /*0x3*/;
    // 0048d706  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0048d708  89462c                 -mov dword ptr [esi + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0048d70b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048d70d  e8a2890000             -call 0x4960b4
    cpu.esp -= 4;
    sub_4960b4(app, cpu);
    if (cpu.terminate) return;
    // 0048d712  8b5e2c                 -mov ebx, dword ptr [esi + 0x2c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */);
    // 0048d715  894630                 -mov dword ptr [esi + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 0048d718  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0048d71a  0f84bdfeffff           -je 0x48d5dd
    if (cpu.flags.zf)
    {
        goto L_0x0048d5dd;
    }
    // 0048d720  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048d722  0f84b5feffff           -je 0x48d5dd
    if (cpu.flags.zf)
    {
        goto L_0x0048d5dd;
    }
    // 0048d728  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0048d72c  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0048d72f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d730  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d731  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048d732  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48d738(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048d738  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0048d73a  e851feffff             -call 0x48d590
    cpu.esp -= 4;
    sub_48d590(app, cpu);
    if (cpu.terminate) return;
    // 0048d73f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48d740(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048d740  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048d742  e849feffff             -call 0x48d590
    cpu.esp -= 4;
    sub_48d590(app, cpu);
    if (cpu.terminate) return;
    // 0048d747  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
