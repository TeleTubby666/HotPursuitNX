#include "nfs2sea.h"
#include <lib/thread.h>

namespace nfs2sea
{

/* align: skip  */
void Application::sub_4baa94(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004baa94);
    // 004baa94  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004baa96  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004baa99  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004baa9f  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004baaa2  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004baaa5  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004baaab  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004baaad  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004baab0  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004baab6  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004baab9  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004baabc  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004baac2  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004baac4  8b5c0e01               -mov ebx, dword ptr [esi + ecx + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.ecx * 1);
    // 004baac8  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004baace  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004baad1  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004baad3  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004baad5  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004baadb  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004baade  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004baae4  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004baae6  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004baae8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4baae9(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004baae9);
    // 004baae9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004baaeb  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004baaee  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004baaf4  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004baaf7  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004baafa  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004bab00  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004bab02  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004bab05  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004bab0b  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004bab0e  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004bab11  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004bab17  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004bab19  8b5c0e01               -mov ebx, dword ptr [esi + ecx + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.ecx * 1);
    // 004bab1d  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004bab23  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004bab26  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004bab28  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004bab2a  81e2fcfcfcfc           -and edx, 0xfcfcfcfc
    cpu.edx &= x86::reg32(x86::sreg32(4244438268 /*0xfcfcfcfc*/));
    // 004bab30  c1ea02                 -shr edx, 2
    cpu.edx >>= 2 /*0x2*/ % 32;
    // 004bab33  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004bab39  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004bab3b  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004bab3d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4bab40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bab40);
    // 004bab40  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bab41  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004bab43  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bab45  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004bab47  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004bab49  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004bab4b  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004bab4e  c1e810                 +shr eax, 0x10
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
    // 004bab51  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004bab53  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004bab55  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bab56  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4bab60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bab60);
    // 004bab60  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bab61  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bab62  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004bab64  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004bab66  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bab68  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004bab6a  7e28                   -jle 0x4bab94
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bab94;
    }
L_0x004bab6c:
    // 004bab6c  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004bab6e  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004bab70  d900                   -fld dword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax)));
    // 004bab72  d802                   -fadd dword ptr [edx]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edx));
    // 004bab74  d94004                 -fld dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */)));
    // 004bab77  d84204                 -fadd dword ptr [edx + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */));
    // 004bab7a  d94008                 -fld dword ptr [eax + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */)));
    // 004bab7d  d84208                 -fadd dword ptr [edx + 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */));
    // 004bab80  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004bab82  8d400c                 -lea eax, [eax + 0xc]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004bab85  d91b                   -fstp dword ptr [ebx]
    app->getMemory<float>(cpu.ebx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bab87  d95b04                 -fstp dword ptr [ebx + 4]
    app->getMemory<float>(cpu.ebx + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bab8a  d95b08                 -fstp dword ptr [ebx + 8]
    app->getMemory<float>(cpu.ebx + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bab8d  83c10c                 +add ecx, 0xc
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
    // 004bab90  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004bab91  75d9                   -jne 0x4bab6c
    if (!cpu.flags.zf)
    {
        goto L_0x004bab6c;
    }
    // 004bab93  90                     -nop 
    ;
L_0x004bab94:
    // 004bab94  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bab95  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bab96  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4bab98(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bab98);
    // 004bab98  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bab99  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bab9a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004bab9c  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004bab9e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004baba0  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004baba2  7e28                   -jle 0x4babcc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004babcc;
    }
L_0x004baba4:
    // 004baba4  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004baba6  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004baba8  d900                   -fld dword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax)));
    // 004babaa  d822                   -fsub dword ptr [edx]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.edx));
    // 004babac  d94004                 -fld dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */)));
    // 004babaf  d86204                 -fsub dword ptr [edx + 4]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */));
    // 004babb2  d94008                 -fld dword ptr [eax + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */)));
    // 004babb5  d86208                 -fsub dword ptr [edx + 8]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */));
    // 004babb8  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004babba  8d400c                 -lea eax, [eax + 0xc]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004babbd  d91b                   -fstp dword ptr [ebx]
    app->getMemory<float>(cpu.ebx) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004babbf  d95b04                 -fstp dword ptr [ebx + 4]
    app->getMemory<float>(cpu.ebx + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004babc2  d95b08                 -fstp dword ptr [ebx + 8]
    app->getMemory<float>(cpu.ebx + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004babc5  83c10c                 +add ecx, 0xc
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
    // 004babc8  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004babc9  75d9                   -jne 0x4baba4
    if (!cpu.flags.zf)
    {
        goto L_0x004baba4;
    }
    // 004babcb  90                     -nop 
    ;
L_0x004babcc:
    // 004babcc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004babcd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004babce  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4babd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004babd0);
    // 004babd0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004babd1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004babd3  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004babd7  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004babd9  7e25                   -jle 0x4bac00
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bac00;
    }
    // 004babdb  d9442408               -fld dword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)));
L_0x004babdf:
    // 004babdf  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 004babe1  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004babe3  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004babe5  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 004babe8  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004babea  d95804                 -fstp dword ptr [eax + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004babed  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 004babf0  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004babf2  83c00c                 -add eax, 0xc
    (cpu.eax) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004babf5  83c20c                 +add edx, 0xc
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004babf8  d958fc                 +fstp dword ptr [eax - 4]
    app->getMemory<float>(cpu.eax + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004babfb  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004babfc  75e1                   -jne 0x4babdf
    if (!cpu.flags.zf)
    {
        goto L_0x004babdf;
    }
    // 004babfe  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x004bac00:
    // 004bac00  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bac01  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_4bac04(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bac04);
    // 004bac04  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004bac07  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 004bac09  d820                   -fsub dword ptr [eax]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.eax));
    // 004bac0b  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bac0e  d94204                 -fld dword ptr [edx + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 004bac11  d86004                 -fsub dword ptr [eax + 4]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */));
    // 004bac14  d95c2404               -fstp dword ptr [esp + 4]
    app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bac18  d94208                 -fld dword ptr [edx + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(8) /* 0x8 */)));
    // 004bac1b  d86008                 -fsub dword ptr [eax + 8]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(8) /* 0x8 */));
    // 004bac1e  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004bac20  d95c2408               -fstp dword ptr [esp + 8]
    app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bac24  e83b16feff             -call 0x49c264
    cpu.esp -= 4;
    sub_49c264(app, cpu);
    if (cpu.terminate) return;
    // 004bac29  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004bac2c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4bac2e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bac2e);
    // 004bac2e  f644240b80             +test byte ptr [esp + 0xb], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(11) /* 0xb */) & 128 /*0x80*/));
    // 004bac33  7420                   -je 0x4bac55
    if (cpu.flags.zf)
    {
        goto L_0x004bac55;
    }
    // 004bac35  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004bac39  25ffffff7f             -and eax, 0x7fffffff
    cpu.eax &= x86::reg32(x86::sreg32(2147483647 /*0x7fffffff*/));
    // 004bac3e  0b442404               +or eax, dword ptr [esp + 4]
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */)))));
    // 004bac42  7411                   -je 0x4bac55
    if (cpu.flags.zf)
    {
        goto L_0x004bac55;
    }
    // 004bac44  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 004bac46  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004bac4a  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004bac4e  e87a590000             -call 0x4c05cd
    cpu.esp -= 4;
    sub_4c05cd(app, cpu);
    if (cpu.terminate) return;
    // 004bac53  eb06                   -jmp 0x4bac5b
    goto L_0x004bac5b;
L_0x004bac55:
    // 004bac55  dd442404               -fld qword ptr [esp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp + x86::reg32(4) /* 0x4 */)));
    // 004bac59  d9fa                   -fsqrt 
    cpu.fpu.st(0) = cpu.fpu.sqrt(cpu.fpu.st(0));
L_0x004bac5b:
    // 004bac5b  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_4bac5e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bac5e);
    // 004bac5e  b003                   -mov al, 3
    cpu.al = 3 /*0x3*/;
    // 004bac60  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bac61  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004bac63  d9e4                   -ftst 
    cpu.fpu.compare(cpu.fpu.st(0), 0.0);
    // 004bac65  83ec10                 +sub esp, 0x10
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004bac68  9b                     -wait 
    /*nothing*/;
    // 004bac69  dd7df8                 -fnstsw word ptr [ebp - 8]
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.fpu.status.word;
    // 004bac6c  9b                     -wait 
    /*nothing*/;
    // 004bac6d  668745f8               -xchg word ptr [ebp - 8], ax
    {
        x86::reg16 tmp = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
        app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ax;
        cpu.ax = tmp;
    }
    // 004bac71  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004bac72  7319                   -jae 0x4bac8d
    if (!cpu.flags.cf)
    {
        goto L_0x004bac8d;
    }
    // 004bac74  dd5df0                 -fstp qword ptr [ebp - 0x10]
    app->getMemory<double>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bac77  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004bac7a  3c03                   +cmp al, 3
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
    // 004bac7c  7403                   -je 0x4bac81
    if (cpu.flags.zf)
    {
        goto L_0x004bac81;
    }
    // 004bac7e  dd5df0                 +fstp qword ptr [ebp - 0x10]
    app->getMemory<double>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x004bac81:
    // 004bac81  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 004bac84  e844590000             -call 0x4c05cd
    cpu.esp -= 4;
    sub_4c05cd(app, cpu);
    if (cpu.terminate) return;
    // 004bac89  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
    // 004bac8b  eb04                   -jmp 0x4bac91
    goto L_0x004bac91;
L_0x004bac8d:
    // 004bac8d  d9fa                   -fsqrt 
    cpu.fpu.st(0) = cpu.fpu.sqrt(cpu.fpu.st(0));
    // 004bac8f  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
L_0x004bac91:
    // 004bac91  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004bac93  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bac94  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bac60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bac60);
    goto L_entry_0x004bac60;
    // 004bac5e  b003                   -mov al, 3
    cpu.al = 3 /*0x3*/;
L_entry_0x004bac60:
    // 004bac60  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bac61  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004bac63  d9e4                   -ftst 
    cpu.fpu.compare(cpu.fpu.st(0), 0.0);
    // 004bac65  83ec10                 +sub esp, 0x10
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004bac68  9b                     -wait 
    /*nothing*/;
    // 004bac69  dd7df8                 -fnstsw word ptr [ebp - 8]
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.fpu.status.word;
    // 004bac6c  9b                     -wait 
    /*nothing*/;
    // 004bac6d  668745f8               -xchg word ptr [ebp - 8], ax
    {
        x86::reg16 tmp = app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
        app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ax;
        cpu.ax = tmp;
    }
    // 004bac71  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004bac72  7319                   -jae 0x4bac8d
    if (!cpu.flags.cf)
    {
        goto L_0x004bac8d;
    }
    // 004bac74  dd5df0                 -fstp qword ptr [ebp - 0x10]
    app->getMemory<double>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bac77  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004bac7a  3c03                   +cmp al, 3
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
    // 004bac7c  7403                   -je 0x4bac81
    if (cpu.flags.zf)
    {
        goto L_0x004bac81;
    }
    // 004bac7e  dd5df0                 +fstp qword ptr [ebp - 0x10]
    app->getMemory<double>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x004bac81:
    // 004bac81  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 004bac84  e844590000             -call 0x4c05cd
    cpu.esp -= 4;
    sub_4c05cd(app, cpu);
    if (cpu.terminate) return;
    // 004bac89  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
    // 004bac8b  eb04                   -jmp 0x4bac91
    goto L_0x004bac91;
L_0x004bac8d:
    // 004bac8d  d9fa                   -fsqrt 
    cpu.fpu.st(0) = cpu.fpu.sqrt(cpu.fpu.st(0));
    // 004bac8f  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
L_0x004bac91:
    // 004bac91  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004bac93  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bac94  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bac95(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bac95);
    // 004bac95  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bac96  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bac97  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004bac99  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004bac9b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004bac9d:
    // 004bac9d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004bac9f  763a                   -jbe 0x4bacdb
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004bacdb;
    }
    // 004baca1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004baca3  e821010000             -call 0x4badc9
    cpu.esp -= 4;
    sub_4badc9(app, cpu);
    if (cpu.terminate) return;
    // 004baca8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bacaa  752f                   -jne 0x4bacdb
    if (!cpu.flags.zf)
    {
        goto L_0x004bacdb;
    }
    // 004bacac  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004bacae  e816010000             -call 0x4badc9
    cpu.esp -= 4;
    sub_4badc9(app, cpu);
    if (cpu.terminate) return;
    // 004bacb3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bacb5  7524                   -jne 0x4bacdb
    if (!cpu.flags.zf)
    {
        goto L_0x004bacdb;
    }
    // 004bacb7  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004bacb9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004bacbb  e888590000             -call 0x4c0648
    cpu.esp -= 4;
    sub_4c0648(app, cpu);
    if (cpu.terminate) return;
    // 004bacc0  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004bacc2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bacc4  753e                   -jne 0x4bad04
    if (!cpu.flags.zf)
    {
        goto L_0x004bad04;
    }
    // 004bacc6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004bacc8  e838010000             -call 0x4bae05
    cpu.esp -= 4;
    sub_4bae05(app, cpu);
    if (cpu.terminate) return;
    // 004baccd  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004baccf  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004bacd1  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004bacd2  e82e010000             -call 0x4bae05
    cpu.esp -= 4;
    sub_4bae05(app, cpu);
    if (cpu.terminate) return;
    // 004bacd7  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004bacd9  ebc2                   -jmp 0x4bac9d
    goto L_0x004bac9d;
L_0x004bacdb:
    // 004bacdb  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004bacdd  7623                   -jbe 0x4bad02
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004bad02;
    }
    // 004bacdf  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004bace1  e8e3000000             -call 0x4badc9
    cpu.esp -= 4;
    sub_4badc9(app, cpu);
    if (cpu.terminate) return;
    // 004bace6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bace8  750b                   -jne 0x4bacf5
    if (!cpu.flags.zf)
    {
        goto L_0x004bacf5;
    }
    // 004bacea  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004bacec  e8d8000000             -call 0x4badc9
    cpu.esp -= 4;
    sub_4badc9(app, cpu);
    if (cpu.terminate) return;
    // 004bacf1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bacf3  740d                   -je 0x4bad02
    if (cpu.flags.zf)
    {
        goto L_0x004bad02;
    }
L_0x004bacf5:
    // 004bacf5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bacf7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004bacf9  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 004bacfb  8a16                   -mov dl, byte ptr [esi]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi);
    // 004bacfd  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004bacff  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bad00  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bad01  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bad02:
    // 004bad02  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x004bad04:
    // 004bad04  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bad05  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bad06  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bad07(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bad07);
    // 004bad07  e9b7b8feff             -jmp 0x4a65c3
    return sub_4a65c3(app, cpu);
}

/* align: skip  */
void Application::sub_4bad0c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bad0c);
    // 004bad0c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bad0d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bad0e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bad0f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bad10  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bad11  833d34945b0000         +cmp dword ptr [0x5b9434], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(6001716) /* 0x5b9434 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bad18  0f85a5000000           -jne 0x4badc3
    if (!cpu.flags.zf)
    {
        goto L_0x004badc3;
    }
    // 004bad1e  8b3d05db4d00           -mov edi, dword ptr [0x4ddb05]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5102341) /* 0x4ddb05 */);
    // 004bad24  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004bad26  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 004bad28  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x004bad2a:
    // 004bad2a  3a10                   +cmp dl, byte ptr [eax]
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.eax)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004bad2c  7412                   -je 0x4bad40
    if (cpu.flags.zf)
    {
        goto L_0x004bad40;
    }
L_0x004bad2e:
    // 004bad2e  8a30                   -mov dh, byte ptr [eax]
    cpu.dh = app->getMemory<x86::reg8>(cpu.eax);
    // 004bad30  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004bad33  38f2                   +cmp dl, dh
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.dh));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004bad35  7404                   -je 0x4bad3b
    if (cpu.flags.zf)
    {
        goto L_0x004bad3b;
    }
    // 004bad37  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004bad39  ebf3                   -jmp 0x4bad2e
    goto L_0x004bad2e;
L_0x004bad3b:
    // 004bad3b  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004bad3c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004bad3e  ebea                   -jmp 0x4bad2a
    goto L_0x004bad2a;
L_0x004bad40:
    // 004bad40  29f8                   +sub eax, edi
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004bad42  7505                   -jne 0x4bad49
    if (!cpu.flags.zf)
    {
        goto L_0x004bad49;
    }
    // 004bad44  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004bad49:
    // 004bad49  e875b8feff             -call 0x4a65c3
    cpu.esp -= 4;
    sub_4a65c3(app, cpu);
    if (cpu.terminate) return;
    // 004bad4e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004bad50  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004bad52  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bad54  7468                   -je 0x4badbe
    if (cpu.flags.zf)
    {
        goto L_0x004badbe;
    }
    // 004bad56  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004bad58  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004bad5b  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bad5e  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004bad60  e85eb8feff             -call 0x4a65c3
    cpu.esp -= 4;
    sub_4a65c3(app, cpu);
    if (cpu.terminate) return;
    // 004bad65  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bad67  744e                   -je 0x4badb7
    if (cpu.flags.zf)
    {
        goto L_0x004badb7;
    }
    // 004bad69  a334945b00             -mov dword ptr [0x5b9434], eax
    app->getMemory<x86::reg32>(x86::reg32(6001716) /* 0x5b9434 */) = cpu.eax;
    // 004bad6e  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004bad70  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004bad72  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x004bad74:
    // 004bad74  803800                 +cmp byte ptr [eax], 0
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
    // 004bad77  7419                   -je 0x4bad92
    if (cpu.flags.zf)
    {
        goto L_0x004bad92;
    }
    // 004bad79  8b1534945b00           -mov edx, dword ptr [0x5b9434]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6001716) /* 0x5b9434 */);
    // 004bad7f  891c11                 -mov dword ptr [ecx + edx], ebx
    app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 1) = cpu.ebx;
L_0x004bad82:
    // 004bad82  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004bad84  40                     -inc eax
    (cpu.eax)++;
    // 004bad85  8813                   -mov byte ptr [ebx], dl
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.dl;
    // 004bad87  43                     -inc ebx
    (cpu.ebx)++;
    // 004bad88  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 004bad8a  75f6                   -jne 0x4bad82
    if (!cpu.flags.zf)
    {
        goto L_0x004bad82;
    }
    // 004bad8c  83c104                 +add ecx, 4
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
    // 004bad8f  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004bad90  ebe2                   -jmp 0x4bad74
    goto L_0x004bad74;
L_0x004bad92:
    // 004bad92  8b1534945b00           -mov edx, dword ptr [0x5b9434]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6001716) /* 0x5b9434 */);
    // 004bad98  c7041100000000         -mov dword ptr [ecx + edx], 0
    app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 1) = 0 /*0x0*/;
    // 004bad9f  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bada2  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004bada4  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004bada6  891530945b00           -mov dword ptr [0x5b9430], edx
    app->getMemory<x86::reg32>(x86::reg32(6001712) /* 0x5b9430 */) = cpu.edx;
    // 004badac  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004badae  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004badb0  e87a78fdff             -call 0x49262f
    cpu.esp -= 4;
    sub_49262f(app, cpu);
    if (cpu.terminate) return;
    // 004badb5  eb07                   -jmp 0x4badbe
    goto L_0x004badbe;
L_0x004badb7:
    // 004badb7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004badb9  e83a07ffff             -call 0x4ab4f8
    cpu.esp -= 4;
    sub_4ab4f8(app, cpu);
    if (cpu.terminate) return;
L_0x004badbe:
    // 004badbe  e8dc580000             -call 0x4c069f
    cpu.esp -= 4;
    sub_4c069f(app, cpu);
    if (cpu.terminate) return;
L_0x004badc3:
    // 004badc3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004badc4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004badc5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004badc6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004badc7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004badc8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4badc9(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004badc9);
    // 004badc9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004badca  803800                 +cmp byte ptr [eax], 0
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
    // 004badcd  7507                   -jne 0x4badd6
    if (!cpu.flags.zf)
    {
        goto L_0x004badd6;
    }
    // 004badcf  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004badd4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004badd5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004badd6:
    // 004badd6  833dd0a35b0000         +cmp dword ptr [0x5ba3d0], 0
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
    // 004baddd  7422                   -je 0x4bae01
    if (cpu.flags.zf)
    {
        goto L_0x004bae01;
    }
    // 004baddf  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004bade1  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004bade3  8a92d5a35b00           -mov dl, byte ptr [edx + 0x5ba3d5]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(6005717) /* 0x5ba3d5 */);
    // 004bade9  80e201                 -and dl, 1
    cpu.dl &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004badec  81e2ff000000           +and edx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004badf2  740d                   -je 0x4bae01
    if (cpu.flags.zf)
    {
        goto L_0x004bae01;
    }
    // 004badf4  80780100               +cmp byte ptr [eax + 1], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004badf8  7507                   -jne 0x4bae01
    if (!cpu.flags.zf)
    {
        goto L_0x004bae01;
    }
    // 004badfa  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 004badff  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bae00  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bae01:
    // 004bae01  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bae03  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bae04  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bae05(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bae05);
    // 004bae05  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bae06  833dd0a35b0000         +cmp dword ptr [0x5ba3d0], 0
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
    // 004bae0d  7420                   -je 0x4bae2f
    if (cpu.flags.zf)
    {
        goto L_0x004bae2f;
    }
    // 004bae0f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004bae11  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004bae13  8a92d5a35b00           -mov dl, byte ptr [edx + 0x5ba3d5]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(6005717) /* 0x5ba3d5 */);
    // 004bae19  80e201                 -and dl, 1
    cpu.dl &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004bae1c  81e2ff000000           +and edx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004bae22  740b                   -je 0x4bae2f
    if (cpu.flags.zf)
    {
        goto L_0x004bae2f;
    }
    // 004bae24  80780100               +cmp byte ptr [eax + 1], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004bae28  7405                   -je 0x4bae2f
    if (cpu.flags.zf)
    {
        goto L_0x004bae2f;
    }
    // 004bae2a  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004bae2d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bae2e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bae2f:
    // 004bae2f  40                     -inc eax
    (cpu.eax)++;
    // 004bae30  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bae31  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bae32(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bae32);
    // 004bae32  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bae33  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bae34  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bae35  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bae36  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bae37  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bae38  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bae3b  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004bae3d  833d38945b0000         +cmp dword ptr [0x5b9438], 0
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
    // 004bae44  7505                   -jne 0x4bae4b
    if (!cpu.flags.zf)
    {
        goto L_0x004bae4b;
    }
    // 004bae46  e819010000             -call 0x4baf64
    cpu.esp -= 4;
    sub_4baf64(app, cpu);
    if (cpu.terminate) return;
L_0x004bae4b:
    // 004bae4b  8b3538945b00           -mov esi, dword ptr [0x5b9438]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(6001720) /* 0x5b9438 */);
    // 004bae51  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004bae53  743d                   -je 0x4bae92
    if (cpu.flags.zf)
    {
        goto L_0x004bae92;
    }
    // 004bae55  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bae57  7439                   -je 0x4bae92
    if (cpu.flags.zf)
    {
        goto L_0x004bae92;
    }
    // 004bae59  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004bae5b  e854010000             -call 0x4bafb4
    cpu.esp -= 4;
    sub_4bafb4(app, cpu);
    if (cpu.terminate) return;
    // 004bae60  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004bae62  01c0                   +add eax, eax
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
    // 004bae64  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004bae67  eb23                   -jmp 0x4bae8c
    goto L_0x004bae8c;
L_0x004bae69:
    // 004bae69  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 004bae6b  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004bae6d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004bae6f  e84b590000             -call 0x4c07bf
    cpu.esp -= 4;
    sub_4c07bf(app, cpu);
    if (cpu.terminate) return;
    // 004bae74  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bae76  7511                   -jne 0x4bae89
    if (!cpu.flags.zf)
    {
        goto L_0x004bae89;
    }
    // 004bae78  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004bae7b  66833c013d             +cmp word ptr [ecx + eax], 0x3d
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ecx + cpu.eax * 1);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(61 /*0x3d*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004bae80  7507                   -jne 0x4bae89
    if (!cpu.flags.zf)
    {
        goto L_0x004bae89;
    }
    // 004bae82  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004bae85  01c8                   +add eax, ecx
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
    // 004bae87  eb0b                   -jmp 0x4bae94
    goto L_0x004bae94;
L_0x004bae89:
    // 004bae89  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004bae8c:
    // 004bae8c  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 004bae8e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004bae90  75d7                   -jne 0x4bae69
    if (!cpu.flags.zf)
    {
        goto L_0x004bae69;
    }
L_0x004bae92:
    // 004bae92  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004bae94:
    // 004bae94  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bae97  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bae98  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bae99  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bae9a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bae9b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bae9c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bae9d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bae9e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bae9e);
    // 004bae9e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bae9f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004baea0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004baea1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004baea2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004baea3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004baea4  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004baea6  66813d0ddb4d000080     +cmp word ptr [0x4ddb0d], 0x8000
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5102349) /* 0x4ddb0d */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(32768 /*0x8000*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004baeaf  730e                   -jae 0x4baebf
    if (!cpu.flags.cf)
    {
        goto L_0x004baebf;
    }
    // 004baeb1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004baeb2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004baeb3  2eff1584654c00         -call dword ptr cs:[0x4c6584]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006724) /* 0x4c6584 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004baeba  e99c000000             -jmp 0x4baf5b
    goto L_0x004baf5b;
L_0x004baebf:
    // 004baebf  e8f0000000             -call 0x4bafb4
    cpu.esp -= 4;
    sub_4bafb4(app, cpu);
    if (cpu.terminate) return;
    // 004baec4  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004baec6  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004baec9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004baecb  e8f3b6feff             -call 0x4a65c3
    cpu.esp -= 4;
    sub_4a65c3(app, cpu);
    if (cpu.terminate) return;
    // 004baed0  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004baed2  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004baed4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004baed6  0f847f000000           -je 0x4baf5b
    if (cpu.flags.zf)
    {
        goto L_0x004baf5b;
    }
    // 004baedc  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004baede  7504                   -jne 0x4baee4
    if (!cpu.flags.zf)
    {
        goto L_0x004baee4;
    }
    // 004baee0  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 004baee2  eb1d                   -jmp 0x4baf01
    goto L_0x004baf01;
L_0x004baee4:
    // 004baee4  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004baee6  e8c9000000             -call 0x4bafb4
    cpu.esp -= 4;
    sub_4bafb4(app, cpu);
    if (cpu.terminate) return;
    // 004baeeb  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004baeed  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004baef0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004baef2  e8ccb6feff             -call 0x4a65c3
    cpu.esp -= 4;
    sub_4a65c3(app, cpu);
    if (cpu.terminate) return;
    // 004baef7  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004baef9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004baefb  7504                   -jne 0x4baf01
    if (!cpu.flags.zf)
    {
        goto L_0x004baf01;
    }
    // 004baefd  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004baeff  eb1e                   -jmp 0x4baf1f
    goto L_0x004baf1f;
L_0x004baf01:
    // 004baf01  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004baf04  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004baf06  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004baf08  e8ba000000             -call 0x4bafc7
    cpu.esp -= 4;
    sub_4bafc7(app, cpu);
    if (cpu.terminate) return;
    // 004baf0d  83f8ff                 +cmp eax, -1
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
    // 004baf10  7516                   -jne 0x4baf28
    if (!cpu.flags.zf)
    {
        goto L_0x004baf28;
    }
    // 004baf12  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004baf14  e8df05ffff             -call 0x4ab4f8
    cpu.esp -= 4;
    sub_4ab4f8(app, cpu);
    if (cpu.terminate) return;
    // 004baf19  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004baf1b  7407                   -je 0x4baf24
    if (cpu.flags.zf)
    {
        goto L_0x004baf24;
    }
L_0x004baf1d:
    // 004baf1d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x004baf1f:
    // 004baf1f  e8d405ffff             -call 0x4ab4f8
    cpu.esp -= 4;
    sub_4ab4f8(app, cpu);
    if (cpu.terminate) return;
L_0x004baf24:
    // 004baf24  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004baf26  eb33                   -jmp 0x4baf5b
    goto L_0x004baf5b;
L_0x004baf28:
    // 004baf28  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004baf2a  7410                   -je 0x4baf3c
    if (cpu.flags.zf)
    {
        goto L_0x004baf3c;
    }
    // 004baf2c  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004baf2e  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004baf30  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004baf32  e890000000             -call 0x4bafc7
    cpu.esp -= 4;
    sub_4bafc7(app, cpu);
    if (cpu.terminate) return;
    // 004baf37  83f8ff                 +cmp eax, -1
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
    // 004baf3a  74e1                   -je 0x4baf1d
    if (cpu.flags.zf)
    {
        goto L_0x004baf1d;
    }
L_0x004baf3c:
    // 004baf3c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004baf3d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004baf3e  2eff1580654c00         -call dword ptr cs:[0x4c6580]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006720) /* 0x4c6580 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004baf45  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004baf47  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004baf49  e8aa05ffff             -call 0x4ab4f8
    cpu.esp -= 4;
    sub_4ab4f8(app, cpu);
    if (cpu.terminate) return;
    // 004baf4e  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004baf50  7407                   -je 0x4baf59
    if (cpu.flags.zf)
    {
        goto L_0x004baf59;
    }
    // 004baf52  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004baf54  e89f05ffff             -call 0x4ab4f8
    cpu.esp -= 4;
    sub_4ab4f8(app, cpu);
    if (cpu.terminate) return;
L_0x004baf59:
    // 004baf59  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x004baf5b:
    // 004baf5b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004baf5e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004baf5f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004baf60  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004baf61  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004baf62  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004baf63  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4baf64(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004baf64);
    // 004baf64  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004baf65  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004baf66  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004baf67  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004baf68  8b3534945b00           -mov esi, dword ptr [0x5b9434]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(6001716) /* 0x5b9434 */);
    // 004baf6e  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004baf70  743d                   -je 0x4bafaf
    if (cpu.flags.zf)
    {
        goto L_0x004bafaf;
    }
L_0x004baf72:
    // 004baf72  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004baf74  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004baf77  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004baf79  7434                   -je 0x4bafaf
    if (cpu.flags.zf)
    {
        goto L_0x004bafaf;
    }
    // 004baf7b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004baf7d  e8a554ffff             -call 0x4b0427
    cpu.esp -= 4;
    sub_4b0427(app, cpu);
    if (cpu.terminate) return;
    // 004baf82  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004baf85  8d041b                 -lea eax, [ebx + ebx]
    cpu.eax = x86::reg32(cpu.ebx + cpu.ebx * 1);
    // 004baf88  e836b6feff             -call 0x4a65c3
    cpu.esp -= 4;
    sub_4a65c3(app, cpu);
    if (cpu.terminate) return;
    // 004baf8d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004baf8f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004baf91  74df                   -je 0x4baf72
    if (cpu.flags.zf)
    {
        goto L_0x004baf72;
    }
    // 004baf93  e8b154ffff             -call 0x4b0449
    cpu.esp -= 4;
    sub_4b0449(app, cpu);
    if (cpu.terminate) return;
    // 004baf98  83f8ff                 +cmp eax, -1
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
    // 004baf9b  7409                   -je 0x4bafa6
    if (cpu.flags.zf)
    {
        goto L_0x004bafa6;
    }
    // 004baf9d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004baf9f  e8a1590000             -call 0x4c0945
    cpu.esp -= 4;
    sub_4c0945(app, cpu);
    if (cpu.terminate) return;
    // 004bafa4  ebcc                   -jmp 0x4baf72
    goto L_0x004baf72;
L_0x004bafa6:
    // 004bafa6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004bafa8  e84b05ffff             -call 0x4ab4f8
    cpu.esp -= 4;
    sub_4ab4f8(app, cpu);
    if (cpu.terminate) return;
    // 004bafad  ebc3                   -jmp 0x4baf72
    goto L_0x004baf72;
L_0x004bafaf:
    // 004bafaf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bafb0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bafb1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bafb2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bafb3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bafb4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bafb4);
    // 004bafb4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bafb5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x004bafb7:
    // 004bafb7  66833800               +cmp word ptr [eax], 0
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
    // 004bafbb  7404                   -je 0x4bafc1
    if (cpu.flags.zf)
    {
        goto L_0x004bafc1;
    }
    // 004bafbd  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004bafbe  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004bafbf  ebf6                   -jmp 0x4bafb7
    goto L_0x004bafb7;
L_0x004bafc1:
    // 004bafc1  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004bafc3  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004bafc5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bafc6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bafc7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bafc7);
    // 004bafc7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bafc8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bafc9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bafca  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bafcb  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004bafce  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004bafcf  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004bafd1  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004bafd5  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004bafd7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bafd9  0f8472000000           -je 0x4bb051
    if (cpu.flags.zf)
    {
        goto L_0x004bb051;
    }
L_0x004bafdf:
    // 004bafdf  837c240400             +cmp dword ptr [esp + 4], 0
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
    // 004bafe4  0f8689000000           -jbe 0x4bb073
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004bb073;
    }
    // 004bafea  668b4d00               -mov cx, word ptr [ebp]
    cpu.cx = app->getMemory<x86::reg16>(cpu.ebp);
    // 004bafee  6685c9                 +test cx, cx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.cx & cpu.cx));
    // 004baff1  7421                   -je 0x4bb014
    if (cpu.flags.zf)
    {
        goto L_0x004bb014;
    }
    // 004baff3  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004baff5  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004baff9  6689ca                 -mov dx, cx
    cpu.dx = cpu.cx;
    // 004baffc  e8ff0a0000             -call 0x4bbb00
    cpu.esp -= 4;
    sub_4bbb00(app, cpu);
    if (cpu.terminate) return;
    // 004bb001  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004bb003  83f8ff                 +cmp eax, -1
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
    // 004bb006  0f8469000000           -je 0x4bb075
    if (cpu.flags.zf)
    {
        goto L_0x004bb075;
    }
    // 004bb00c  3b442404               +cmp eax, dword ptr [esp + 4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bb010  7761                   -ja 0x4bb073
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004bb073;
    }
    // 004bb012  eb08                   -jmp 0x4bb01c
    goto L_0x004bb01c;
L_0x004bb014:
    // 004bb014  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004bb017  c60000                 -mov byte ptr [eax], 0
    app->getMemory<x86::reg8>(cpu.eax) = 0 /*0x0*/;
    // 004bb01a  eb57                   -jmp 0x4bb073
    goto L_0x004bb073;
L_0x004bb01c:
    // 004bb01c  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004bb020  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 004bb023  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004bb025  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004bb026  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004bb028  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004bb02a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bb02b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004bb02d  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004bb030  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bb032  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004bb034  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004bb037  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004bb039  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb03a  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004bb03b  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004bb03e  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004bb040  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004bb044  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 004bb046  29d0                   +sub eax, edx
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
    // 004bb048  893c24                 -mov dword ptr [esp], edi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edi;
    // 004bb04b  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004bb04f  eb8e                   -jmp 0x4bafdf
    goto L_0x004bafdf;
L_0x004bb051:
    // 004bb051  66837d0000             +cmp word ptr [ebp], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ebp);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004bb056  741b                   -je 0x4bb073
    if (cpu.flags.zf)
    {
        goto L_0x004bb073;
    }
    // 004bb058  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004bb05a  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004bb05e  668b5500               -mov dx, word ptr [ebp]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ebp);
    // 004bb062  e8990a0000             -call 0x4bbb00
    cpu.esp -= 4;
    sub_4bbb00(app, cpu);
    if (cpu.terminate) return;
    // 004bb067  83f8ff                 +cmp eax, -1
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
    // 004bb06a  7409                   -je 0x4bb075
    if (cpu.flags.zf)
    {
        goto L_0x004bb075;
    }
    // 004bb06c  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004bb06f  01c3                   +add ebx, eax
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
    // 004bb071  ebde                   -jmp 0x4bb051
    goto L_0x004bb051;
L_0x004bb073:
    // 004bb073  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x004bb075:
    // 004bb075  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004bb078  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb079  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb07a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb07b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb07c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bb07d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bb07d);
    // 004bb07d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bb07e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bb07f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bb080  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004bb082  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004bb084  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004bb086  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004bb087  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004bb089  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004bb08b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bb08c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004bb08e  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004bb091  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004bb093  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004bb095  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004bb098  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004bb09a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb09b  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004bb09c  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004bb09e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb09f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb0a0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb0a1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bb0a2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bb0a2);
    // 004bb0a2  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bb0a3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bb0a4  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x004bb0a6:
    // 004bb0a6  668b0a                 -mov cx, word ptr [edx]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx);
    // 004bb0a9  42                     -inc edx
    (cpu.edx)++;
    // 004bb0aa  42                     -inc edx
    (cpu.edx)++;
    // 004bb0ab  668908                 -mov word ptr [eax], cx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.cx;
    // 004bb0ae  40                     -inc eax
    (cpu.eax)++;
    // 004bb0af  40                     -inc eax
    (cpu.eax)++;
    // 004bb0b0  6685c9                 +test cx, cx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.cx & cpu.cx));
    // 004bb0b3  75f1                   -jne 0x4bb0a6
    if (!cpu.flags.zf)
    {
        goto L_0x004bb0a6;
    }
    // 004bb0b5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004bb0b7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb0b8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb0b9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bb0ba(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bb0ba);
    // 004bb0ba  663d6100               +cmp ax, 0x61
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(97 /*0x61*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004bb0be  7209                   -jb 0x4bb0c9
    if (cpu.flags.cf)
    {
        goto L_0x004bb0c9;
    }
    // 004bb0c0  663d7a00               +cmp ax, 0x7a
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(122 /*0x7a*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004bb0c4  7703                   -ja 0x4bb0c9
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004bb0c9;
    }
    // 004bb0c6  83e820                 -sub eax, 0x20
    (cpu.eax) -= x86::reg32(x86::sreg32(32 /*0x20*/));
L_0x004bb0c9:
    // 004bb0c9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bb0ca(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bb0ca);
    // 004bb0ca  83e804                 -sub eax, 4
    (cpu.eax) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bb0cd  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004bb0cf  24fe                   -and al, 0xfe
    cpu.al &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 004bb0d1  83e804                 -sub eax, 4
    (cpu.eax) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bb0d4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bb0d5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bb0d5);
    // 004bb0d5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bb0d6  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bb0d7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bb0d8  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bb0db  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004bb0dd  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004bb0df  ff1574ed4d00           -call dword ptr [0x4ded74]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107060) /* 0x4ded74 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bb0e5  b838db4d00             -mov eax, 0x4ddb38
    cpu.eax = 5102392 /*0x4ddb38*/;
    // 004bb0ea  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 004bb0ec  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bb0ee  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 004bb0f0  6689d0                 -mov ax, dx
    cpu.ax = cpu.dx;
    // 004bb0f3  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004bb0f5  e815000000             -call 0x4bb10f
    cpu.esp -= 4;
    sub_4bb10f(app, cpu);
    if (cpu.terminate) return;
    // 004bb0fa  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bb0fc  0f85a8010000           -jne 0x4bb2aa
    if (!cpu.flags.zf)
    {
        return sub_4bb2aa(app, cpu);
    }
    // 004bb102  ff157ced4d00           -call dword ptr [0x4ded7c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107068) /* 0x4ded7c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bb108  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004bb10a  e9a3010000             -jmp 0x4bb2b2
    return sub_4bb2b2(app, cpu);
}

/* align: skip  */
void Application::sub_4bb10f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bb10f);
    // 004bb10f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bb110  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bb111  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bb112  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004bb115  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004bb116  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004bb118  8d430b                 -lea eax, [ebx + 0xb]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(11) /* 0xb */);
    // 004bb11b  24f8                   -and al, 0xf8
    cpu.al &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 004bb11d  39d8                   +cmp eax, ebx
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
    // 004bb11f  7307                   -jae 0x4bb128
    if (!cpu.flags.cf)
    {
        goto L_0x004bb128;
    }
    // 004bb121  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004bb126  eb0a                   -jmp 0x4bb132
    goto L_0x004bb132;
L_0x004bb128:
    // 004bb128  83f810                 +cmp eax, 0x10
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
    // 004bb12b  7305                   -jae 0x4bb132
    if (!cpu.flags.cf)
    {
        goto L_0x004bb132;
    }
    // 004bb12d  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
L_0x004bb132:
    // 004bb132  8d57fc                 -lea edx, [edi - 4]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(-4) /* -0x4 */);
    // 004bb135  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004bb139  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 004bb13b  80e2fe                 -and dl, 0xfe
    cpu.dl &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 004bb13e  39d0                   +cmp eax, edx
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
    // 004bb140  0f86fc000000           -jbe 0x4bb242
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004bb242;
    }
    // 004bb146  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004bb14a  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004bb14c  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
L_0x004bb14e:
    // 004bb14e  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 004bb150  8b2b                   -mov ebp, dword ptr [ebx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx);
    // 004bb152  83fdff                 +cmp ebp, -1
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
    // 004bb155  750a                   -jne 0x4bb161
    if (!cpu.flags.zf)
    {
        goto L_0x004bb161;
    }
    // 004bb157  bd02000000             -mov ebp, 2
    cpu.ebp = 2 /*0x2*/;
    // 004bb15c  e940010000             -jmp 0x4bb2a1
    goto L_0x004bb2a1;
L_0x004bb161:
    // 004bb161  f7c501000000           +test ebp, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & 1 /*0x1*/));
    // 004bb167  0f85ce000000           -jne 0x4bb23b
    if (!cpu.flags.zf)
    {
        goto L_0x004bb23b;
    }
    // 004bb16d  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004bb170  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004bb174  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004bb177  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 004bb179  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004bb17d  b838db4d00             -mov eax, 0x4ddb38
    cpu.eax = 5102392 /*0x4ddb38*/;
    // 004bb182  663b1424               +cmp dx, word ptr [esp]
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(app->getMemory<x86::reg16>(cpu.esp)));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004bb186  751d                   -jne 0x4bb1a5
    if (!cpu.flags.zf)
    {
        goto L_0x004bb1a5;
    }
    // 004bb188  8b3538db4d00           -mov esi, dword ptr [0x4ddb38]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5102392) /* 0x4ddb38 */);
    // 004bb18e  eb0f                   -jmp 0x4bb19f
    goto L_0x004bb19f;
L_0x004bb190:
    // 004bb190  39fe                   +cmp esi, edi
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
    // 004bb192  7708                   -ja 0x4bb19c
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004bb19c;
    }
    // 004bb194  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004bb196  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004bb198  39f8                   +cmp eax, edi
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
    // 004bb19a  7709                   -ja 0x4bb1a5
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004bb1a5;
    }
L_0x004bb19c:
    // 004bb19c  8b7608                 -mov esi, dword ptr [esi + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
L_0x004bb19f:
    // 004bb19f  837e0800               +cmp dword ptr [esi + 8], 0
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
    // 004bb1a3  75eb                   -jne 0x4bb190
    if (!cpu.flags.zf)
    {
        goto L_0x004bb190;
    }
L_0x004bb1a5:
    // 004bb1a5  8b560c                 -mov edx, dword ptr [esi + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004bb1a8  39d3                   +cmp ebx, edx
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
    // 004bb1aa  7506                   -jne 0x4bb1b2
    if (!cpu.flags.zf)
    {
        goto L_0x004bb1b2;
    }
    // 004bb1ac  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004bb1af  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x004bb1b2:
    // 004bb1b2  3b29                   +cmp ebp, dword ptr [ecx]
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
    // 004bb1b4  720b                   -jb 0x4bb1c1
    if (cpu.flags.cf)
    {
        goto L_0x004bb1c1;
    }
    // 004bb1b6  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004bb1b8  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004bb1ba  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004bb1bc  83f810                 +cmp eax, 0x10
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
    // 004bb1bf  7334                   -jae 0x4bb1f5
    if (!cpu.flags.cf)
    {
        goto L_0x004bb1f5;
    }
L_0x004bb1c1:
    // 004bb1c1  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004bb1c5  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004bb1c9  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004bb1cc  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bb1ce  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004bb1d2  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004bb1d5  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004bb1d9  0128                   -add dword ptr [eax], ebp
    (app->getMemory<x86::reg32>(cpu.eax)) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004bb1db  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004bb1de  48                     -dec eax
    (cpu.eax)--;
    // 004bb1df  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 004bb1e1  89461c                 -mov dword ptr [esi + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004bb1e4  881561945b00           -mov byte ptr [0x5b9461], dl
    app->getMemory<x86::reg8>(x86::reg32(6001761) /* 0x5b9461 */) = cpu.dl;
    // 004bb1ea  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004bb1ec  39d5                   +cmp ebp, edx
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
    // 004bb1ee  7240                   -jb 0x4bb230
    if (cpu.flags.cf)
    {
        goto L_0x004bb230;
    }
    // 004bb1f0  e9aa000000             -jmp 0x4bb29f
    goto L_0x004bb29f;
L_0x004bb1f5:
    // 004bb1f5  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004bb1f7  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004bb1f9  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004bb1fd  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004bb200  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004bb204  894308                 -mov dword ptr [ebx + 8], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004bb207  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004bb20b  895808                 -mov dword ptr [eax + 8], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004bb20e  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004bb212  895804                 -mov dword ptr [eax + 4], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004bb215  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004bb219  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 004bb21b  8b3a                   -mov edi, dword ptr [edx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx);
    // 004bb21d  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004bb21f  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bb221  30e4                   +xor ah, ah
    cpu.clear_co();
    cpu.set_szp((cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah))));
    // 004bb223  893a                   -mov dword ptr [edx], edi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.edi;
    // 004bb225  882561945b00           -mov byte ptr [0x5b9461], ah
    app->getMemory<x86::reg8>(x86::reg32(6001761) /* 0x5b9461 */) = cpu.ah;
    // 004bb22b  e971000000             -jmp 0x4bb2a1
    goto L_0x004bb2a1;
L_0x004bb230:
    // 004bb230  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bb232  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004bb234  01eb                   +add ebx, ebp
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004bb236  e913ffffff             -jmp 0x4bb14e
    goto L_0x004bb14e;
L_0x004bb23b:
    // 004bb23b  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 004bb240  eb5f                   -jmp 0x4bb2a1
    goto L_0x004bb2a1;
L_0x004bb242:
    // 004bb242  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004bb244  83fa10                 +cmp edx, 0x10
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
    // 004bb247  7256                   -jb 0x4bb29f
    if (cpu.flags.cf)
    {
        goto L_0x004bb29f;
    }
    // 004bb249  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004bb24b  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004bb24f  80cb01                 -or bl, 1
    cpu.bl |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004bb252  80ca01                 -or dl, 1
    cpu.dl |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004bb255  8919                   -mov dword ptr [ecx], ebx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.ebx;
    // 004bb257  8d1c01                 -lea ebx, [ecx + eax]
    cpu.ebx = x86::reg32(cpu.ecx + cpu.eax * 1);
    // 004bb25a  b838db4d00             -mov eax, 0x4ddb38
    cpu.eax = 5102392 /*0x4ddb38*/;
    // 004bb25f  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004bb263  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 004bb265  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 004bb267  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 004bb26a  6639da                 +cmp dx, bx
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(cpu.bx));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004bb26d  751d                   -jne 0x4bb28c
    if (!cpu.flags.zf)
    {
        goto L_0x004bb28c;
    }
    // 004bb26f  8b3538db4d00           -mov esi, dword ptr [0x4ddb38]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5102392) /* 0x4ddb38 */);
    // 004bb275  eb0f                   -jmp 0x4bb286
    goto L_0x004bb286;
L_0x004bb277:
    // 004bb277  39fe                   +cmp esi, edi
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
    // 004bb279  7708                   -ja 0x4bb283
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004bb283;
    }
    // 004bb27b  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004bb27d  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004bb27f  39f8                   +cmp eax, edi
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
    // 004bb281  7709                   -ja 0x4bb28c
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004bb28c;
    }
L_0x004bb283:
    // 004bb283  8b7608                 -mov esi, dword ptr [esi + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
L_0x004bb286:
    // 004bb286  837e0800               +cmp dword ptr [esi + 8], 0
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
    // 004bb28a  75eb                   -jne 0x4bb277
    if (!cpu.flags.zf)
    {
        goto L_0x004bb277;
    }
L_0x004bb28c:
    // 004bb28c  8b7e18                 -mov edi, dword ptr [esi + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004bb28f  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004bb293  47                     -inc edi
    (cpu.edi)++;
    // 004bb294  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bb297  897e18                 -mov dword ptr [esi + 0x18], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 004bb29a  e85902ffff             -call 0x4ab4f8
    cpu.esp -= 4;
    sub_4ab4f8(app, cpu);
    if (cpu.terminate) return;
L_0x004bb29f:
    // 004bb29f  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x004bb2a1:
    // 004bb2a1  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004bb2a3  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004bb2a6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb2a7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb2a8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb2a9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bb2aa(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bb2aa);
    // 004bb2aa  ff157ced4d00           -call dword ptr [0x4ded7c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107068) /* 0x4ded7c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bb2b0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bb2b2  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bb2b5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb2b6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb2b7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb2b8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bb2b2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bb2b2);
    goto L_entry_0x004bb2b2;
    // 004bb2aa  ff157ced4d00           -call dword ptr [0x4ded7c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107068) /* 0x4ded7c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bb2b0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_entry_0x004bb2b2:
    // 004bb2b2  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bb2b5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb2b6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb2b7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb2b8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4bb2c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bb2c0);
    // 004bb2c0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bb2c1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004bb2c3  e8cc71fcff             -call 0x482494
    cpu.esp -= 4;
    sub_482494(app, cpu);
    if (cpu.terminate) return;
    // 004bb2c8  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004bb2cb  e8e09dfcff             -call 0x4850b0
    cpu.esp -= 4;
    sub_4850b0(app, cpu);
    if (cpu.terminate) return;
    // 004bb2d0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb2d1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4bb2d4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bb2d4);
    // 004bb2d4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bb2d5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004bb2d7  e8b871fcff             -call 0x482494
    cpu.esp -= 4;
    sub_482494(app, cpu);
    if (cpu.terminate) return;
    // 004bb2dc  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004bb2df  e87c81fcff             -call 0x483460
    cpu.esp -= 4;
    sub_483460(app, cpu);
    if (cpu.terminate) return;
    // 004bb2e4  e8d371fcff             -call 0x4824bc
    cpu.esp -= 4;
    sub_4824bc(app, cpu);
    if (cpu.terminate) return;
    // 004bb2e9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb2ea  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4bb2ec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bb2ec);
    // 004bb2ec  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bb2ed  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bb2ee  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bb2ef  81ec40010000           -sub esp, 0x140
    (cpu.esp) -= x86::reg32(x86::sreg32(320 /*0x140*/));
    // 004bb2f5  8bbc2454010000         -mov edi, dword ptr [esp + 0x154]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(340) /* 0x154 */);
    // 004bb2fc  8984242c010000         -mov dword ptr [esp + 0x12c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(300) /* 0x12c */) = cpu.eax;
    // 004bb303  8994243c010000         -mov dword ptr [esp + 0x13c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(316) /* 0x13c */) = cpu.edx;
    // 004bb30a  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004bb30c  898c2438010000         -mov dword ptr [esp + 0x138], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(312) /* 0x138 */) = cpu.ecx;
    // 004bb313  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004bb318  e8635dfeff             -call 0x4a1080
    cpu.esp -= 4;
    sub_4a1080(app, cpu);
    if (cpu.terminate) return;
    // 004bb31d  89842430010000         -mov dword ptr [esp + 0x130], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(304) /* 0x130 */) = cpu.eax;
    // 004bb324  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bb326  8b942450010000         -mov edx, dword ptr [esp + 0x150]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(336) /* 0x150 */);
    // 004bb32d  e84e5dfeff             -call 0x4a1080
    cpu.esp -= 4;
    sub_4a1080(app, cpu);
    if (cpu.terminate) return;
    // 004bb332  8b842438010000         -mov eax, dword ptr [esp + 0x138]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(312) /* 0x138 */);
    // 004bb339  8b0de8ab4d00           -mov ecx, dword ptr [0x4dabe8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5090280) /* 0x4dabe8 */);
    // 004bb33f  8b1d84ab4d00           -mov ebx, dword ptr [0x4dab84]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5090180) /* 0x4dab84 */);
    // 004bb345  e8d674fdff             -call 0x492820
    cpu.esp -= 4;
    sub_492820(app, cpu);
    if (cpu.terminate) return;
    // 004bb34a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004bb34c  89842434010000         -mov dword ptr [esp + 0x134], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(308) /* 0x134 */) = cpu.eax;
    // 004bb353  8d8424b4000000         -lea eax, [esp + 0xb4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(180) /* 0xb4 */);
    // 004bb35a  e8d18cfeff             -call 0x4a4030
    cpu.esp -= 4;
    sub_4a4030(app, cpu);
    if (cpu.terminate) return;
    // 004bb35f  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004bb361  e84abefcff             -call 0x4871b0
    cpu.esp -= 4;
    sub_4871b0(app, cpu);
    if (cpu.terminate) return;
    // 004bb366  b880f34d00             -mov eax, 0x4df380
    cpu.eax = 5108608 /*0x4df380*/;
    // 004bb36b  e8f0bcfcff             -call 0x487060
    cpu.esp -= 4;
    sub_487060(app, cpu);
    if (cpu.terminate) return;
    // 004bb370  8b842450010000         -mov eax, dword ptr [esp + 0x150]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(336) /* 0x150 */);
    // 004bb377  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004bb379  8b8c2438010000         -mov ecx, dword ptr [esp + 0x138]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(312) /* 0x138 */);
    // 004bb380  89842424010000         -mov dword ptr [esp + 0x124], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(292) /* 0x124 */) = cpu.eax;
    // 004bb387  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004bb388  8b842440010000         -mov eax, dword ptr [esp + 0x140]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(320) /* 0x140 */);
    // 004bb38f  8b942440010000         -mov edx, dword ptr [esp + 0x140]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(320) /* 0x140 */);
    // 004bb396  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004bb398  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 004bb39a  8984242c010000         -mov dword ptr [esp + 0x12c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(300) /* 0x12c */) = cpu.eax;
    // 004bb3a1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004bb3a3  b878b24d00             -mov eax, 0x4db278
    cpu.eax = 5091960 /*0x4db278*/;
    // 004bb3a8  e8d3570000             -call 0x4c0b80
    cpu.esp -= 4;
    sub_4c0b80(app, cpu);
    if (cpu.terminate) return;
    // 004bb3ad  ff1540ac4d00           -call dword ptr [0x4dac40]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5090368) /* 0x4dac40 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bb3b3  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004bb3b5  8b94243c010000         -mov edx, dword ptr [esp + 0x13c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(316) /* 0x13c */);
    // 004bb3bc  e8e771fcff             -call 0x4825a8
    cpu.esp -= 4;
    sub_4825a8(app, cpu);
    if (cpu.terminate) return;
    // 004bb3c1  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 004bb3c3  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004bb3c5  8b8c2450010000         -mov ecx, dword ptr [esp + 0x150]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(336) /* 0x150 */);
    // 004bb3cc  e8effeffff             -call 0x4bb2c0
    cpu.esp -= 4;
    sub_4bb2c0(app, cpu);
    if (cpu.terminate) return;
    // 004bb3d1  e8be70fcff             -call 0x482494
    cpu.esp -= 4;
    sub_482494(app, cpu);
    if (cpu.terminate) return;
    // 004bb3d6  b8000000ff             -mov eax, 0xff000000
    cpu.eax = 4278190080 /*0xff000000*/;
    // 004bb3db  8b9c2438010000         -mov ebx, dword ptr [esp + 0x138]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(312) /* 0x138 */);
    // 004bb3e2  e88572fcff             -call 0x48266c
    cpu.esp -= 4;
    sub_48266c(app, cpu);
    if (cpu.terminate) return;
    // 004bb3e7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004bb3e8  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004bb3ea  8b842440010000         -mov eax, dword ptr [esp + 0x140]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(320) /* 0x140 */);
    // 004bb3f1  e82ad2fcff             -call 0x488620
    cpu.esp -= 4;
    sub_488620(app, cpu);
    if (cpu.terminate) return;
    // 004bb3f6  b80000aaff             -mov eax, 0xffaa0000
    cpu.eax = 4289331200 /*0xffaa0000*/;
    // 004bb3fb  8b8c2424010000         -mov ecx, dword ptr [esp + 0x124]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(292) /* 0x124 */);
    // 004bb402  8b9c2428010000         -mov ebx, dword ptr [esp + 0x128]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(296) /* 0x128 */);
    // 004bb409  e85e72fcff             -call 0x48266c
    cpu.esp -= 4;
    sub_48266c(app, cpu);
    if (cpu.terminate) return;
    // 004bb40e  8d5504                 -lea edx, [ebp + 4]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 004bb411  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004bb412  83e904                 -sub ecx, 4
    (cpu.ecx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bb415  8b842440010000         -mov eax, dword ptr [esp + 0x140]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(320) /* 0x140 */);
    // 004bb41c  83eb05                 -sub ebx, 5
    (cpu.ebx) -= x86::reg32(x86::sreg32(5 /*0x5*/));
    // 004bb41f  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bb422  e8b9570000             -call 0x4c0be0
    cpu.esp -= 4;
    sub_4c0be0(app, cpu);
    if (cpu.terminate) return;
    // 004bb427  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004bb42c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004bb42e  e83972fcff             -call 0x48266c
    cpu.esp -= 4;
    sub_48266c(app, cpu);
    if (cpu.terminate) return;
    // 004bb433  e828b1fcff             -call 0x486560
    cpu.esp -= 4;
    sub_486560(app, cpu);
    if (cpu.terminate) return;
    // 004bb438  8b84242c010000         -mov eax, dword ptr [esp + 0x12c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(300) /* 0x12c */);
    // 004bb43f  8d5509                 -lea edx, [ebp + 9]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(9) /* 0x9 */);
    // 004bb442  e895580000             -call 0x4c0cdc
    cpu.esp -= 4;
    sub_4c0cdc(app, cpu);
    if (cpu.terminate) return;
    // 004bb447  ff1544ac4d00           -call dword ptr [0x4dac44]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5090372) /* 0x4dac44 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bb44d  b878b24d00             -mov eax, 0x4db278
    cpu.eax = 5091960 /*0x4db278*/;
    // 004bb452  e8d9580000             -call 0x4c0d30
    cpu.esp -= 4;
    sub_4c0d30(app, cpu);
    if (cpu.terminate) return;
    // 004bb457  e86070fcff             -call 0x4824bc
    cpu.esp -= 4;
    sub_4824bc(app, cpu);
    if (cpu.terminate) return;
L_0x004bb45c:
    // 004bb45c  ff1548ac4d00           -call dword ptr [0x4dac48]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5090376) /* 0x4dac48 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bb462  85f8                   +test eax, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.edi));
    // 004bb464  75f6                   -jne 0x4bb45c
    if (!cpu.flags.zf)
    {
        goto L_0x004bb45c;
    }
L_0x004bb466:
    // 004bb466  e8cdb9fcff             -call 0x486e38
    cpu.esp -= 4;
    sub_486e38(app, cpu);
    if (cpu.terminate) return;
    // 004bb46b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004bb46d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004bb46f  ff1548ac4d00           -call dword ptr [0x4dac48]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5090376) /* 0x4dac48 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bb475  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004bb477  21fe                   -and esi, edi
    cpu.esi &= x86::reg32(x86::sreg32(cpu.edi));
    // 004bb479  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004bb47b  0f8497000000           -je 0x4bb518
    if (cpu.flags.zf)
    {
        goto L_0x004bb518;
    }
L_0x004bb481:
    // 004bb481  80c920                 -or cl, 0x20
    cpu.cl |= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 004bb484  83e601                 -and esi, 1
    cpu.esi &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 004bb487  83f979                 +cmp ecx, 0x79
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(121 /*0x79*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bb48a  7505                   -jne 0x4bb491
    if (!cpu.flags.zf)
    {
        goto L_0x004bb491;
    }
    // 004bb48c  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
L_0x004bb491:
    // 004bb491  8b842450010000         -mov eax, dword ptr [esp + 0x150]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(336) /* 0x150 */);
    // 004bb498  8b8c243c010000         -mov ecx, dword ptr [esp + 0x13c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(316) /* 0x13c */);
    // 004bb49f  8b9c2438010000         -mov ebx, dword ptr [esp + 0x138]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(312) /* 0x138 */);
    // 004bb4a6  8b94243c010000         -mov edx, dword ptr [esp + 0x13c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(316) /* 0x13c */);
    // 004bb4ad  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004bb4af  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004bb4b1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004bb4b2  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 004bb4b4  b878b24d00             -mov eax, 0x4db278
    cpu.eax = 5091960 /*0x4db278*/;
    // 004bb4b9  e8c2560000             -call 0x4c0b80
    cpu.esp -= 4;
    sub_4c0b80(app, cpu);
    if (cpu.terminate) return;
    // 004bb4be  ff153cac4d00           -call dword ptr [0x4dac3c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5090364) /* 0x4dac3c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bb4c4  8b94243c010000         -mov edx, dword ptr [esp + 0x13c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(316) /* 0x13c */);
    // 004bb4cb  8b842434010000         -mov eax, dword ptr [esp + 0x134]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(308) /* 0x134 */);
    // 004bb4d2  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 004bb4d4  e8fbfdffff             -call 0x4bb2d4
    cpu.esp -= 4;
    sub_4bb2d4(app, cpu);
    if (cpu.terminate) return;
    // 004bb4d9  ff1544ac4d00           -call dword ptr [0x4dac44]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5090372) /* 0x4dac44 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bb4df  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004bb4e1  e8e2bcfcff             -call 0x4871c8
    cpu.esp -= 4;
    sub_4871c8(app, cpu);
    if (cpu.terminate) return;
    // 004bb4e6  8d8424b4000000         -lea eax, [esp + 0xb4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(180) /* 0xb4 */);
    // 004bb4ed  e8628bfeff             -call 0x4a4054
    cpu.esp -= 4;
    sub_4a4054(app, cpu);
    if (cpu.terminate) return;
    // 004bb4f2  8b842434010000         -mov eax, dword ptr [esp + 0x134]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(308) /* 0x134 */);
    // 004bb4f9  e8a278fcff             -call 0x482da0
    cpu.esp -= 4;
    sub_482da0(app, cpu);
    if (cpu.terminate) return;
    // 004bb4fe  8b842430010000         -mov eax, dword ptr [esp + 0x130]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(304) /* 0x130 */);
    // 004bb505  e8765bfeff             -call 0x4a1080
    cpu.esp -= 4;
    sub_4a1080(app, cpu);
    if (cpu.terminate) return;
    // 004bb50a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004bb50c  81c440010000           -add esp, 0x140
    (cpu.esp) += x86::reg32(x86::sreg32(320 /*0x140*/));
    // 004bb512  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb513  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb514  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb515  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004bb518:
    // 004bb518  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004bb51a  0f8561ffffff           -jne 0x4bb481
    if (!cpu.flags.zf)
    {
        goto L_0x004bb481;
    }
    // 004bb520  e941ffffff             -jmp 0x4bb466
    goto L_0x004bb466;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4bb528(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bb528);
    // 004bb528  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bb529  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bb52a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bb52b  833d5cab4d0000         +cmp dword ptr [0x4dab5c], 0
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
    // 004bb532  7410                   -je 0x4bb544
    if (cpu.flags.zf)
    {
        goto L_0x004bb544;
    }
    // 004bb534  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bb536  e8ade6fcff             -call 0x489be8
    cpu.esp -= 4;
    sub_489be8(app, cpu);
    if (cpu.terminate) return;
    // 004bb53b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bb53d  7442                   -je 0x4bb581
    if (cpu.flags.zf)
    {
        goto L_0x004bb581;
    }
    // 004bb53f  e8786ffcff             -call 0x4824bc
    cpu.esp -= 4;
    sub_4824bc(app, cpu);
    if (cpu.terminate) return;
L_0x004bb544:
    // 004bb544  a180ab4d00             -mov eax, dword ptr [0x4dab80]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090176) /* 0x4dab80 */);
    // 004bb549  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004bb54b  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004bb54e  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004bb550  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004bb552  8d58f8                 -lea ebx, [eax - 8]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(-8) /* -0x8 */);
    // 004bb555  a17cab4d00             -mov eax, dword ptr [0x4dab7c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090172) /* 0x4dab7c */);
    // 004bb55a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004bb55c  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004bb55f  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004bb561  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004bb563  6a07                   -push 7
    app->getMemory<x86::reg32>(cpu.esp-4) = 7 /*0x7*/;
    cpu.esp -= 4;
    // 004bb565  6a18                   -push 0x18
    app->getMemory<x86::reg32>(cpu.esp-4) = 24 /*0x18*/;
    cpu.esp -= 4;
    // 004bb567  8d50b0                 -lea edx, [eax - 0x50]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(-80) /* -0x50 */);
    // 004bb56a  b9a0000000             -mov ecx, 0xa0
    cpu.ecx = 160 /*0xa0*/;
    // 004bb56f  b8401d4d00             -mov eax, 0x4d1d40
    cpu.eax = 5053760 /*0x4d1d40*/;
    // 004bb574  e873fdffff             -call 0x4bb2ec
    cpu.esp -= 4;
    sub_4bb2ec(app, cpu);
    if (cpu.terminate) return;
    // 004bb579  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bb57b  751a                   -jne 0x4bb597
    if (!cpu.flags.zf)
    {
        goto L_0x004bb597;
    }
    // 004bb57d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb57e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb57f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb580  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bb581:
    // 004bb581  a1a0b64d00             -mov eax, dword ptr [0x4db6a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093024) /* 0x4db6a0 */);
    // 004bb586  e8bde9fcff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 004bb58b  a1a0b64d00             -mov eax, dword ptr [0x4db6a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093024) /* 0x4db6a0 */);
    // 004bb590  e8cbe9fcff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 004bb595  ebad                   -jmp 0x4bb544
    goto L_0x004bb544;
L_0x004bb597:
    // 004bb597  e809f8fdff             -call 0x49ada5
    cpu.esp -= 4;
    sub_49ada5(app, cpu);
    if (cpu.terminate) return;
    // 004bb59c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb59d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb59e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb59f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bb5a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bb5a0);
    // 004bb5a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bb5a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bb5a2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bb5a3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bb5a4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bb5a5  81ec28010000           -sub esp, 0x128
    (cpu.esp) -= x86::reg32(x86::sreg32(296 /*0x128*/));
    // 004bb5ab  89842424010000         -mov dword ptr [esp + 0x124], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(292) /* 0x124 */) = cpu.eax;
    // 004bb5b2  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004bb5b4  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004bb5b9  e8c25afeff             -call 0x4a1080
    cpu.esp -= 4;
    sub_4a1080(app, cpu);
    if (cpu.terminate) return;
    // 004bb5be  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004bb5c0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bb5c2  ba0a000000             -mov edx, 0xa
    cpu.edx = 10 /*0xa*/;
    // 004bb5c7  e8b45afeff             -call 0x4a1080
    cpu.esp -= 4;
    sub_4a1080(app, cpu);
    if (cpu.terminate) return;
    // 004bb5cc  8b0de8ab4d00           -mov ecx, dword ptr [0x4dabe8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5090280) /* 0x4dabe8 */);
    // 004bb5d2  8b1d84ab4d00           -mov ebx, dword ptr [0x4dab84]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5090180) /* 0x4dab84 */);
    // 004bb5d8  a17cab4d00             -mov eax, dword ptr [0x4dab7c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090172) /* 0x4dab7c */);
    // 004bb5dd  e83e72fdff             -call 0x492820
    cpu.esp -= 4;
    sub_492820(app, cpu);
    if (cpu.terminate) return;
    // 004bb5e2  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004bb5e4  8d8424b4000000         -lea eax, [esp + 0xb4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(180) /* 0xb4 */);
    // 004bb5eb  e8408afeff             -call 0x4a4030
    cpu.esp -= 4;
    sub_4a4030(app, cpu);
    if (cpu.terminate) return;
    // 004bb5f0  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004bb5f2  e8b9bbfcff             -call 0x4871b0
    cpu.esp -= 4;
    sub_4871b0(app, cpu);
    if (cpu.terminate) return;
    // 004bb5f7  b880f34d00             -mov eax, 0x4df380
    cpu.eax = 5108608 /*0x4df380*/;
    // 004bb5fc  e85fbafcff             -call 0x487060
    cpu.esp -= 4;
    sub_487060(app, cpu);
    if (cpu.terminate) return;
    // 004bb601  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004bb603  e8a06ffcff             -call 0x4825a8
    cpu.esp -= 4;
    sub_4825a8(app, cpu);
    if (cpu.terminate) return;
    // 004bb608  8b1580ab4d00           -mov edx, dword ptr [0x4dab80]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090176) /* 0x4dab80 */);
    // 004bb60e  b878b24d00             -mov eax, 0x4db278
    cpu.eax = 5091960 /*0x4db278*/;
    // 004bb613  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bb614  8d5af6                 -lea ebx, [edx - 0xa]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(-10) /* -0xa */);
    // 004bb617  8b0d7cab4d00           -mov ecx, dword ptr [0x4dab7c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5090172) /* 0x4dab7c */);
    // 004bb61d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004bb61f  e85c550000             -call 0x4c0b80
    cpu.esp -= 4;
    sub_4c0b80(app, cpu);
    if (cpu.terminate) return;
    // 004bb624  ff1540ac4d00           -call dword ptr [0x4dac40]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5090368) /* 0x4dac40 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bb62a  8b1d80ab4d00           -mov ebx, dword ptr [0x4dab80]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5090176) /* 0x4dab80 */);
    // 004bb630  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004bb632  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004bb634  83eb0a                 -sub ebx, 0xa
    (cpu.ebx) -= x86::reg32(x86::sreg32(10 /*0xa*/));
    // 004bb637  e884fcffff             -call 0x4bb2c0
    cpu.esp -= 4;
    sub_4bb2c0(app, cpu);
    if (cpu.terminate) return;
    // 004bb63c  e8536efcff             -call 0x482494
    cpu.esp -= 4;
    sub_482494(app, cpu);
    if (cpu.terminate) return;
    // 004bb641  b8000000ff             -mov eax, 0xff000000
    cpu.eax = 4278190080 /*0xff000000*/;
    // 004bb646  b90a000000             -mov ecx, 0xa
    cpu.ecx = 10 /*0xa*/;
    // 004bb64b  e81c70fcff             -call 0x48266c
    cpu.esp -= 4;
    sub_48266c(app, cpu);
    if (cpu.terminate) return;
    // 004bb650  8b1d7cab4d00           -mov ebx, dword ptr [0x4dab7c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5090172) /* 0x4dab7c */);
    // 004bb656  8b1580ab4d00           -mov edx, dword ptr [0x4dab80]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090176) /* 0x4dab80 */);
    // 004bb65c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004bb65d  83ea0a                 -sub edx, 0xa
    (cpu.edx) -= x86::reg32(x86::sreg32(10 /*0xa*/));
    // 004bb660  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bb662  e8b9cffcff             -call 0x488620
    cpu.esp -= 4;
    sub_488620(app, cpu);
    if (cpu.terminate) return;
    // 004bb667  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004bb66c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004bb66e  e8f96ffcff             -call 0x48266c
    cpu.esp -= 4;
    sub_48266c(app, cpu);
    if (cpu.terminate) return;
    // 004bb673  e8e8aefcff             -call 0x486560
    cpu.esp -= 4;
    sub_486560(app, cpu);
    if (cpu.terminate) return;
    // 004bb678  8b1580ab4d00           -mov edx, dword ptr [0x4dab80]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5090176) /* 0x4dab80 */);
    // 004bb67e  8b842424010000         -mov eax, dword ptr [esp + 0x124]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(292) /* 0x124 */);
    // 004bb685  83ea09                 -sub edx, 9
    (cpu.edx) -= x86::reg32(x86::sreg32(9 /*0x9*/));
    // 004bb688  e84f560000             -call 0x4c0cdc
    cpu.esp -= 4;
    sub_4c0cdc(app, cpu);
    if (cpu.terminate) return;
    // 004bb68d  ff1544ac4d00           -call dword ptr [0x4dac44]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5090372) /* 0x4dac44 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bb693  e8246efcff             -call 0x4824bc
    cpu.esp -= 4;
    sub_4824bc(app, cpu);
    if (cpu.terminate) return;
    // 004bb698  e81f6efcff             -call 0x4824bc
    cpu.esp -= 4;
    sub_4824bc(app, cpu);
    if (cpu.terminate) return;
    // 004bb69d  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004bb69f  e86c7dfcff             -call 0x483410
    cpu.esp -= 4;
    sub_483410(app, cpu);
    if (cpu.terminate) return;
    // 004bb6a4  e8eb6dfcff             -call 0x482494
    cpu.esp -= 4;
    sub_482494(app, cpu);
    if (cpu.terminate) return;
    // 004bb6a9  ff153cac4d00           -call dword ptr [0x4dac3c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5090364) /* 0x4dac3c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bb6af  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004bb6b1  8b1d80ab4d00           -mov ebx, dword ptr [0x4dab80]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5090176) /* 0x4dab80 */);
    // 004bb6b7  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004bb6b9  83eb0a                 -sub ebx, 0xa
    (cpu.ebx) -= x86::reg32(x86::sreg32(10 /*0xa*/));
    // 004bb6bc  e813fcffff             -call 0x4bb2d4
    cpu.esp -= 4;
    sub_4bb2d4(app, cpu);
    if (cpu.terminate) return;
    // 004bb6c1  ff1544ac4d00           -call dword ptr [0x4dac44]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5090372) /* 0x4dac44 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bb6c7  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004bb6c9  e8fabafcff             -call 0x4871c8
    cpu.esp -= 4;
    sub_4871c8(app, cpu);
    if (cpu.terminate) return;
    // 004bb6ce  8d8424b4000000         -lea eax, [esp + 0xb4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(180) /* 0xb4 */);
    // 004bb6d5  e87a89feff             -call 0x4a4054
    cpu.esp -= 4;
    sub_4a4054(app, cpu);
    if (cpu.terminate) return;
    // 004bb6da  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004bb6dc  e8bf76fcff             -call 0x482da0
    cpu.esp -= 4;
    sub_482da0(app, cpu);
    if (cpu.terminate) return;
    // 004bb6e1  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004bb6e3  e89859feff             -call 0x4a1080
    cpu.esp -= 4;
    sub_4a1080(app, cpu);
    if (cpu.terminate) return;
    // 004bb6e8  81c428010000           -add esp, 0x128
    (cpu.esp) += x86::reg32(x86::sreg32(296 /*0x128*/));
    // 004bb6ee  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb6ef  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb6f0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb6f1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb6f2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb6f3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bb6f4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bb6f4);
    // 004bb6f4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bb6f5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bb6f6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bb6f7  a180ab4d00             -mov eax, dword ptr [0x4dab80]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090176) /* 0x4dab80 */);
    // 004bb6fc  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004bb6fe  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004bb701  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004bb703  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004bb705  8d58f8                 -lea ebx, [eax - 8]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(-8) /* -0x8 */);
    // 004bb708  a17cab4d00             -mov eax, dword ptr [0x4dab7c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090172) /* 0x4dab7c */);
    // 004bb70d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004bb70f  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004bb712  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004bb714  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004bb716  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004bb718  6a18                   -push 0x18
    app->getMemory<x86::reg32>(cpu.esp-4) = 24 /*0x18*/;
    cpu.esp -= 4;
    // 004bb71a  8d9070ffffff           -lea edx, [eax - 0x90]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(-144) /* -0x90 */);
    // 004bb720  b920010000             -mov ecx, 0x120
    cpu.ecx = 288 /*0x120*/;
    // 004bb725  b84c1d4d00             -mov eax, 0x4d1d4c
    cpu.eax = 5053772 /*0x4d1d4c*/;
    // 004bb72a  e8bdfbffff             -call 0x4bb2ec
    cpu.esp -= 4;
    sub_4bb2ec(app, cpu);
    if (cpu.terminate) return;
    // 004bb72f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb730  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb731  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb732  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4bb740(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bb740);
    // 004bb740  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bb741  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bb742  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004bb745  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004bb748  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004bb74a  e801560000             -call 0x4c0d50
    cpu.esp -= 4;
    sub_4c0d50(app, cpu);
    if (cpu.terminate) return;
    // 004bb74f  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004bb751  e8fa550000             -call 0x4c0d50
    cpu.esp -= 4;
    sub_4c0d50(app, cpu);
    if (cpu.terminate) return;
    // 004bb756  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb757  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb758  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bb759(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bb759);
    // 004bb759  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bb75a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bb75b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bb75c  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004bb75e  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004bb760  8b5810                 -mov ebx, dword ptr [eax + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004bb763  3b5a04                 +cmp ebx, dword ptr [edx + 4]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bb766  730c                   -jae 0x4bb774
    if (!cpu.flags.cf)
    {
        goto L_0x004bb774;
    }
    // 004bb768  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004bb76a  8d7301                 -lea esi, [ebx + 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004bb76d  8932                   -mov dword ptr [edx], esi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.esi;
    // 004bb76f  880b                   -mov byte ptr [ebx], cl
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.cl;
    // 004bb771  ff4010                 -inc dword ptr [eax + 0x10]
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */))++;
L_0x004bb774:
    // 004bb774  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb775  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb776  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb777  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bb778(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bb778);
    // 004bb778  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bb779  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004bb77c  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004bb77e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bb780  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004bb782  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004bb784  48                     -dec eax
    (cpu.eax)--;
    // 004bb785  b959b74b00             -mov ecx, 0x4bb759
    cpu.ecx = 4962137 /*0x4bb759*/;
    // 004bb78a  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004bb78e  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004bb790  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 004bb793  e8607affff             -call 0x4b31f8
    cpu.esp -= 4;
    sub_4b31f8(app, cpu);
    if (cpu.terminate) return;
    // 004bb798  c6040600               -mov byte ptr [esi + eax], 0
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 0 /*0x0*/;
    // 004bb79c  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004bb79f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb7a0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bb7a1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bb7a1);
    // 004bb7a1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bb7a2  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bb7a3  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bb7a4  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bb7a7  8d442420               -lea eax, [esp + 0x20]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004bb7ab  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 004bb7ad  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004bb7b1  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004bb7b5  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004bb7b8  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004bb7bc  e8b7ffffff             -call 0x4bb778
    cpu.esp -= 4;
    sub_4bb778(app, cpu);
    if (cpu.terminate) return;
    // 004bb7c1  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bb7c4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb7c5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb7c6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb7c7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bb7c8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bb7c8);
    // 004bb7c8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bb7c9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bb7ca  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bb7cb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bb7cc  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bb7cf  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004bb7d1  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004bb7d3  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 004bb7d5  eb01                   -jmp 0x4bb7d8
    goto L_0x004bb7d8;
L_0x004bb7d7:
    // 004bb7d7  43                     -inc ebx
    (cpu.ebx)++;
L_0x004bb7d8:
    // 004bb7d8  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004bb7da  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 004bb7dc  40                     -inc eax
    (cpu.eax)++;
    // 004bb7dd  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 004bb7df  75f6                   -jne 0x4bb7d7
    if (!cpu.flags.zf)
    {
        goto L_0x004bb7d7;
    }
    // 004bb7e1  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004bb7e3  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004bb7e7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004bb7e8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bb7e9  a1ac064e00             -mov eax, dword ptr [0x4e06ac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5113516) /* 0x4e06ac */);
    // 004bb7ee  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bb7ef  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004bb7f2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bb7f3  2eff15e4654c00         -call dword ptr cs:[0x4c65e4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006820) /* 0x4c65e4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bb7fa  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004bb7fc  e97ce7feff             -jmp 0x4a9f7d
    return sub_4a9f7d(app, cpu);
}

/* align: skip  */
void Application::sub_4bb801(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bb801);
    // 004bb801  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bb802  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bb803  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004bb805  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004bb807  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 004bb809  e8b974ffff             -call 0x4b2cc7
    cpu.esp -= 4;
    sub_4b2cc7(app, cpu);
    if (cpu.terminate) return;
    // 004bb80e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bb810  7509                   -jne 0x4bb81b
    if (!cpu.flags.zf)
    {
        goto L_0x004bb81b;
    }
    // 004bb812  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004bb814  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004bb816  e8adffffff             -call 0x4bb7c8
    cpu.esp -= 4;
    sub_4bb7c8(app, cpu);
    if (cpu.terminate) return;
L_0x004bb81b:
    // 004bb81b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb81c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb81d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bb81e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bb81e);
    // 004bb81e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bb81f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bb820  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004bb822  8b15ecda4d00           -mov edx, dword ptr [0x4ddaec]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5102316) /* 0x4ddaec */);
    // 004bb828  83c203                 -add edx, 3
    (cpu.edx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004bb82b  80e2fc                 -and dl, 0xfc
    cpu.dl &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 004bb82e  e8ba74ffff             -call 0x4b2ced
    cpu.esp -= 4;
    sub_4b2ced(app, cpu);
    if (cpu.terminate) return;
    // 004bb833  39c2                   +cmp edx, eax
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
    // 004bb835  7316                   -jae 0x4bb84d
    if (!cpu.flags.cf)
    {
        goto L_0x004bb84d;
    }
    // 004bb837  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bb838  e8ff74ffff             -call 0x4b2d3c
    cpu.esp -= 4;
    sub_4b2d3c(app, cpu);
    if (cpu.terminate) return;
    // 004bb83d  a1ecda4d00             -mov eax, dword ptr [0x4ddaec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5102316) /* 0x4ddaec */);
    // 004bb842  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004bb845  24fc                   -and al, 0xfc
    cpu.al &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 004bb847  29c4                   +sub esp, eax
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004bb849  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004bb84b  eb02                   -jmp 0x4bb84f
    goto L_0x004bb84f;
L_0x004bb84d:
    // 004bb84d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004bb84f:
    // 004bb84f  8b15ecda4d00           -mov edx, dword ptr [0x4ddaec]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5102316) /* 0x4ddaec */);
    // 004bb855  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004bb857  a3f0da4d00             -mov dword ptr [0x4ddaf0], eax
    app->getMemory<x86::reg32>(x86::reg32(5102320) /* 0x4ddaf0 */) = cpu.eax;
    // 004bb85c  e897550000             -call 0x4c0df8
    cpu.esp -= 4;
    sub_4c0df8(app, cpu);
    if (cpu.terminate) return;
    // 004bb861  8b15dca45b00           -mov edx, dword ptr [0x5ba4dc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(6005980) /* 0x5ba4dc */);
    // 004bb867  a1d8a45b00             -mov eax, dword ptr [0x5ba4d8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(6005976) /* 0x5ba4d8 */);
    // 004bb86c  e85f7bfaff             -call 0x4633d0
    cpu.esp -= 4;
    sub_4633d0(app, cpu);
    if (cpu.terminate) return;
    // 004bb871  e8c20ffeff             -call 0x49c838
    cpu.esp -= 4;
    sub_49c838(app, cpu);
    if (cpu.terminate) return;
    // 004bb876  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004bb878  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb879  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb87a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bb87b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bb87b);
    // 004bb87b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bb87c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bb87d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bb87e  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004bb881  c7442408000000c0       -mov dword ptr [esp + 8], 0xc0000000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = 3221225472 /*0xc0000000*/;
    // 004bb889  c744240c7e015041       -mov dword ptr [esp + 0xc], 0x4150017e
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = 1095762302 /*0x4150017e*/;
    // 004bb891  c7042400000080         -mov dword ptr [esp], 0x80000000
    app->getMemory<x86::reg32>(cpu.esp) = 2147483648 /*0x80000000*/;
    // 004bb898  c7442404ffff4741       -mov dword ptr [esp + 4], 0x4147ffff
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = 1095237631 /*0x4147ffff*/;
    // 004bb8a0  803d3db54d0003         +cmp byte ptr [0x4db53d], 3
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5092669) /* 0x4db53d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(3 /*0x3*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004bb8a7  7249                   -jb 0x4bb8f2
    if (cpu.flags.cf)
    {
        goto L_0x004bb8f2;
    }
    // 004bb8a9  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004bb8ad  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004bb8b1  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 004bb8b4  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004bb8b8  e83d550000             -call 0x4c0dfa
    cpu.esp -= 4;
    sub_4c0dfa(app, cpu);
    if (cpu.terminate) return;
    // 004bb8bd  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 004bb8c0  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004bb8c4  e8f4580000             -call 0x4c11bd
    cpu.esp -= 4;
    sub_4c11bd(app, cpu);
    if (cpu.terminate) return;
    // 004bb8c9  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004bb8cb  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004bb8cd  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004bb8d1  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004bb8d5  e826570000             -call 0x4c1000
    cpu.esp -= 4;
    sub_4c1000(app, cpu);
    if (cpu.terminate) return;
    // 004bb8da  bb3a8c30e2             -mov ebx, 0xe2308c3a
    cpu.ebx = 3794832442 /*0xe2308c3a*/;
    // 004bb8df  b98e79453e             -mov ecx, 0x3e45798e
    cpu.ecx = 1044740494 /*0x3e45798e*/;
    // 004bb8e4  e8715a0000             -call 0x4c135a
    cpu.esp -= 4;
    sub_4c135a(app, cpu);
    if (cpu.terminate) return;
    // 004bb8e9  7e07                   -jle 0x4bb8f2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bb8f2;
    }
    // 004bb8eb  800da0014e0001         -or byte ptr [0x4e01a0], 1
    app->getMemory<x86::reg8>(x86::reg32(5112224) /* 0x4e01a0 */) |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x004bb8f2:
    // 004bb8f2  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004bb8f5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb8f6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb8f7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb8f8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4bb900(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bb900);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 004bb900  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004bb901  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bb902  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bb903  83ec24                 -sub esp, 0x24
    (cpu.esp) -= x86::reg32(x86::sreg32(36 /*0x24*/));
    // 004bb906  db7c240c               -fstp xword ptr [esp + 0xc]
    app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bb90a  db3c24                 -fstp xword ptr [esp]
    app->getMemory<x86::IEEEf80>(cpu.esp) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bb90d  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004bb911  01c9                   +add ecx, ecx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004bb913  0f83d7010000           -jae 0x4bbaf0
    if (!cpu.flags.cf)
    {
        goto L_0x004bbaf0;
    }
    // 004bb919  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004bb91d  01c0                   +add eax, eax
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
    // 004bb91f  0f83cb010000           -jae 0x4bbaf0
    if (!cpu.flags.cf)
    {
        goto L_0x004bbaf0;
    }
    // 004bb925  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004bb929  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004bb92d  81e1ff7f0000           +and ecx, 0x7fff
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(32767 /*0x7fff*/))));
    // 004bb933  0f84b7010000           -je 0x4bbaf0
    if (cpu.flags.zf)
    {
        goto L_0x004bbaf0;
    }
    // 004bb939  25ff7f0000             +and eax, 0x7fff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(32767 /*0x7fff*/))));
    // 004bb93e  0f84ac010000           -je 0x4bbaf0
    if (cpu.flags.zf)
    {
        goto L_0x004bbaf0;
    }
    // 004bb944  81f9ff7f0000           +cmp ecx, 0x7fff
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
    // 004bb94a  0f84a0010000           -je 0x4bbaf0
    if (cpu.flags.zf)
    {
        goto L_0x004bbaf0;
    }
    // 004bb950  3dff7f0000             +cmp eax, 0x7fff
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
    // 004bb955  0f8495010000           -je 0x4bbaf0
    if (cpu.flags.zf)
    {
        goto L_0x004bbaf0;
    }
    // 004bb95b  db6c240c               -fld xword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 004bb95f  d9e1                   -fabs 
    cpu.fpu.st(0) = cpu.fpu.abs(cpu.fpu.st(0));
    // 004bb961  db2c24                 -fld xword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.esp)));
    // 004bb964  d9e1                   -fabs 
    cpu.fpu.st(0) = cpu.fpu.abs(cpu.fpu.st(0));
    // 004bb966  d97c2418               -fnstcw word ptr [esp + 0x18]
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.fpu.control.word;
    // 004bb96a  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004bb96e  81ca3f030000           -or edx, 0x33f
    cpu.edx |= x86::reg32(x86::sreg32(831 /*0x33f*/));
    // 004bb974  81e2fff30000           -and edx, 0xf3ff
    cpu.edx &= x86::reg32(x86::sreg32(62463 /*0xf3ff*/));
    // 004bb97a  8954241c               -mov dword ptr [esp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004bb97e  d96c241c               -fldcw word ptr [esp + 0x1c]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004bb982  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004bb984  d8d1                   +fcom st(1)
    cpu.fpu.compare(cpu.fpu.st(0), x86::Float(cpu.fpu.st(1)));
    // 004bb986  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004bb987  dfe0                   -fnstsw ax
    cpu.ax = cpu.fpu.status.word;
    // 004bb989  9e                     +sahf 
    cpu.flags.lo = 0x02 | (cpu.ah & 0xD7);
    // 004bb98a  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb98b  7203                   -jb 0x4bb990
    if (cpu.flags.cf)
    {
        goto L_0x004bb990;
    }
    // 004bb98d  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004bb98f  42                     -inc edx
    (cpu.edx)++;
L_0x004bb990:
    // 004bb990  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004bb991  b80f000000             -mov eax, 0xf
    cpu.eax = 15 /*0xf*/;
    // 004bb996  e8105b0000             -call 0x4c14ab
    cpu.esp -= 4;
    sub_4c14ab(app, cpu);
    if (cpu.terminate) return;
    // 004bb99b  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb99c  d905c44c4e00           -fld dword ptr [0x4e4cc4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5131460) /* 0x4e4cc4 */)));
    // 004bb9a2  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004bb9a4  db5c2420               -fistp dword ptr [esp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 004bb9a8  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004bb9ac  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
    // 004bb9af  db442420               -fild dword ptr [esp + 0x20]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */))));
    // 004bb9b3  d80dc84c4e00           -fmul dword ptr [0x4e4cc8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5131464) /* 0x4e4cc8 */));
    // 004bb9b9  d9c1                   -fld st(1)
    cpu.fpu.push(x86::Float(cpu.fpu.st(1)));
    // 004bb9bb  d8e1                   -fsub st(1)
    cpu.fpu.st(0) -= x86::Float(cpu.fpu.st(1));
    // 004bb9bd  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004bb9bf  deca                   -fmulp st(2)
    cpu.fpu.st(2) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004bb9c1  dd05804c4e00           -fld qword ptr [0x4e4c80]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(5131392) /* 0x4e4c80 */)));
    // 004bb9c7  dec2                   -faddp st(2)
    cpu.fpu.st(2) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004bb9c9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004bb9ca  b80f000000             -mov eax, 0xf
    cpu.eax = 15 /*0xf*/;
    // 004bb9cf  e8d75a0000             -call 0x4c14ab
    cpu.esp -= 4;
    sub_4c14ab(app, cpu);
    if (cpu.terminate) return;
    // 004bb9d4  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bb9d5  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004bb9d7  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004bb9d9  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004bb9db  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004bb9dd  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004bb9df  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004bb9e1  db2dfe4c4e00           -fld xword ptr [0x4e4cfe]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(x86::reg32(5131518) /* 0x4e4cfe */)));
    // 004bb9e7  db2df44c4e00           -fld xword ptr [0x4e4cf4]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(x86::reg32(5131508) /* 0x4e4cf4 */)));
    // 004bb9ed  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004bb9ef  d8ca                   -fmul st(2)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(2));
    // 004bb9f1  db2dea4c4e00           -fld xword ptr [0x4e4cea]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(x86::reg32(5131498) /* 0x4e4cea */)));
    // 004bb9f7  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004bb9f9  d8cb                   -fmul st(3)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(3));
    // 004bb9fb  db2de04c4e00           -fld xword ptr [0x4e4ce0]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(x86::reg32(5131488) /* 0x4e4ce0 */)));
    // 004bba01  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004bba03  d8cd                   -fmul st(5)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(5));
    // 004bba05  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004bba07  decc                   -fmulp st(4)
    cpu.fpu.st(4) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004bba09  db2dd64c4e00           -fld xword ptr [0x4e4cd6]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(x86::reg32(5131478) /* 0x4e4cd6 */)));
    // 004bba0f  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004bba11  dec4                   -faddp st(4)
    cpu.fpu.st(4) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004bba13  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004bba17  db2dcc4c4e00           -fld xword ptr [0x4e4ccc]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(x86::reg32(5131468) /* 0x4e4ccc */)));
    // 004bba1d  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004bba1f  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004bba22  d8ce                   -fmul st(6)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(6));
    // 004bba24  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004bba26  01c0                   +add eax, eax
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
    // 004bba28  d8cd                   +fmul st(5)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(5));
    // 004bba2a  d9cb                   +fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004bba2c  11d2                   -adc edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004bba2e  decd                   -fmulp st(5)
    cpu.fpu.st(5) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004bba30  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004bba32  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004bba36  d8cd                   -fmul st(5)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(5));
    // 004bba38  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004bba3a  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004bba3d  decd                   -fmulp st(5)
    cpu.fpu.st(5) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004bba3f  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004bba41  dec3                   -faddp st(3)
    cpu.fpu.st(3) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004bba43  01c0                   +add eax, eax
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
    // 004bba45  dec1                   +faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004bba47  11d2                   +adc edx, edx
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004bba49  dec2                   +faddp st(2)
    cpu.fpu.st(2) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004bba4b  dec1                   +faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004bba4d  d8c9                   +fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004bba4f  dec1                   +faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004bba51  dba9084d4e00           +fld xword ptr [ecx + 0x4e4d08]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.ecx + x86::reg32(5131528) /* 0x4e4d08 */)));
    // 004bba57  dec1                   +faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004bba59  ff2495904c4e00         -jmp dword ptr [edx*4 + 0x4e4c90]
    cpu.ip = app->getMemory<x86::reg32>(5131408 + cpu.edx * 4); goto dynamic_jump;
  case 0x004bba60:
    // 004bba60  d96c2418               -fldcw word ptr [esp + 0x18]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004bba64  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 004bba67  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bba68  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bba69  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bba6a  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004bba6b:
    // 004bba6b  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 004bba6d  d96c2418               -fldcw word ptr [esp + 0x18]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004bba71  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 004bba74  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bba75  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bba76  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bba77  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004bba78:
    // 004bba78  db2db04c4e00           -fld xword ptr [0x4e4cb0]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(x86::reg32(5131440) /* 0x4e4cb0 */)));
    // 004bba7e  dee1                   -fsubrp st(1)
    cpu.fpu.st(1) = cpu.fpu.st(0) - x86::Float(cpu.fpu.st(1));
    cpu.fpu.pop();
    // 004bba80  d96c2418               -fldcw word ptr [esp + 0x18]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004bba84  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 004bba87  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bba88  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bba89  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bba8a  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004bba8b:
    // 004bba8b  db2db04c4e00           -fld xword ptr [0x4e4cb0]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(x86::reg32(5131440) /* 0x4e4cb0 */)));
    // 004bba91  dee1                   -fsubrp st(1)
    cpu.fpu.st(1) = cpu.fpu.st(0) - x86::Float(cpu.fpu.st(1));
    cpu.fpu.pop();
    // 004bba93  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 004bba95  d96c2418               -fldcw word ptr [esp + 0x18]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004bba99  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 004bba9c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bba9d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bba9e  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bba9f  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004bbaa0:
    // 004bbaa0  db2dba4c4e00           -fld xword ptr [0x4e4cba]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(x86::reg32(5131450) /* 0x4e4cba */)));
    // 004bbaa6  dee1                   -fsubrp st(1)
    cpu.fpu.st(1) = cpu.fpu.st(0) - x86::Float(cpu.fpu.st(1));
    cpu.fpu.pop();
    // 004bbaa8  d96c2418               -fldcw word ptr [esp + 0x18]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004bbaac  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 004bbaaf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbab0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbab1  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbab2  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004bbab3:
    // 004bbab3  db2dba4c4e00           -fld xword ptr [0x4e4cba]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(x86::reg32(5131450) /* 0x4e4cba */)));
    // 004bbab9  dee1                   -fsubrp st(1)
    cpu.fpu.st(1) = cpu.fpu.st(0) - x86::Float(cpu.fpu.st(1));
    cpu.fpu.pop();
    // 004bbabb  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 004bbabd  d96c2418               -fldcw word ptr [esp + 0x18]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004bbac1  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 004bbac4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbac5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbac6  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbac7  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004bbac8:
    // 004bbac8  db2dba4c4e00           -fld xword ptr [0x4e4cba]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(x86::reg32(5131450) /* 0x4e4cba */)));
    // 004bbace  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004bbad0  d96c2418               -fldcw word ptr [esp + 0x18]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004bbad4  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 004bbad7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbad8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbad9  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbada  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004bbadb:
    // 004bbadb  db2dba4c4e00           -fld xword ptr [0x4e4cba]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(x86::reg32(5131450) /* 0x4e4cba */)));
    // 004bbae1  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004bbae3  d9e0                   -fchs 
    cpu.fpu.st(0) = -cpu.fpu.st(0);
    // 004bbae5  d96c2418               -fldcw word ptr [esp + 0x18]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004bbae9  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 004bbaec  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbaed  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbaee  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbaef  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bbaf0:
    // 004bbaf0  db2c24                 -fld xword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.esp)));
    // 004bbaf3  db6c240c               -fld xword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<x86::IEEEf80>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 004bbaf7  d9f3                   -fpatan 
    cpu.fpu.st(1) = cpu.fpu.atan(cpu.fpu.st(0), cpu.fpu.st(1));
    cpu.fpu.pop();
    // 004bbaf9  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 004bbafc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbafd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbafe  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbaff  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::sub_4bbb00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bbb00);
    // 004bbb00  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bbb01  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bbb02  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bbb04  742a                   -je 0x4bbb30
    if (cpu.flags.zf)
    {
        goto L_0x004bbb30;
    }
    // 004bbb06  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004bbb08  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004bbb0a  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004bbb0c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004bbb0d  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004bbb0f  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004bbb13  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004bbb14  6800020000             -push 0x200
    app->getMemory<x86::reg32>(cpu.esp-4) = 512 /*0x200*/;
    cpu.esp -= 4;
    // 004bbb19  8b156c0a4e00           -mov edx, dword ptr [0x4e0a6c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5114476) /* 0x4e0a6c */);
    // 004bbb1f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bbb20  2eff15dc654c00         -call dword ptr cs:[0x4c65dc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006812) /* 0x4c65dc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bbb27  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bbb29  7505                   -jne 0x4bbb30
    if (!cpu.flags.zf)
    {
        goto L_0x004bbb30;
    }
    // 004bbb2b  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
L_0x004bbb30:
    // 004bbb30  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bbb33  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbb34  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bbb35(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bbb35);
    // 004bbb35  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bbb36  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bbb37  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bbb38  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bbb39  83ec28                 -sub esp, 0x28
    (cpu.esp) -= x86::reg32(x86::sreg32(40 /*0x28*/));
    // 004bbb3c  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004bbb3e  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004bbb40  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004bbb42  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 004bbb44  8d4c2401               -lea ecx, [esp + 1]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(1) /* 0x1 */);
    // 004bbb48  881424                 -mov byte ptr [esp], dl
    app->getMemory<x86::reg8>(cpu.esp) = cpu.dl;
L_0x004bbb4b:
    // 004bbb4b  8d5c2424               -lea ebx, [esp + 0x24]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004bbb4f  897c2424               -mov dword ptr [esp + 0x24], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edi;
    // 004bbb53  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004bbb55  f733                   -div dword ptr [ebx]
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = app->getMemory<x86::reg32>(cpu.ebx);
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004bbb57  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004bbb59  8a8254094e00           -mov al, byte ptr [edx + 0x4e0954]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5114196) /* 0x4e0954 */);
    // 004bbb5f  8801                   -mov byte ptr [ecx], al
    app->getMemory<x86::reg8>(cpu.ecx) = cpu.al;
    // 004bbb61  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004bbb65  41                     -inc ecx
    (cpu.ecx)++;
    // 004bbb66  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bbb68  75e1                   -jne 0x4bbb4b
    if (!cpu.flags.zf)
    {
        goto L_0x004bbb4b;
    }
L_0x004bbb6a:
    // 004bbb6a  49                     -dec ecx
    (cpu.ecx)--;
    // 004bbb6b  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 004bbb6d  8806                   -mov byte ptr [esi], al
    app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
    // 004bbb6f  46                     -inc esi
    (cpu.esi)++;
    // 004bbb70  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 004bbb72  75f6                   -jne 0x4bbb6a
    if (!cpu.flags.zf)
    {
        goto L_0x004bbb6a;
    }
    // 004bbb74  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004bbb76  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 004bbb79  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbb7a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbb7b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbb7c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbb7d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bbb7e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bbb7e);
    // 004bbb7e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bbb7f  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004bbb81  83fb0a                 +cmp ebx, 0xa
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10 /*0xa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bbb84  750a                   -jne 0x4bbb90
    if (!cpu.flags.zf)
    {
        goto L_0x004bbb90;
    }
    // 004bbb86  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bbb88  7d06                   -jge 0x4bbb90
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bbb90;
    }
    // 004bbb8a  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 004bbb8c  c6022d                 -mov byte ptr [edx], 0x2d
    app->getMemory<x86::reg8>(cpu.edx) = 45 /*0x2d*/;
    // 004bbb8f  42                     -inc edx
    (cpu.edx)++;
L_0x004bbb90:
    // 004bbb90  e8a0ffffff             -call 0x4bbb35
    cpu.esp -= 4;
    sub_4bbb35(app, cpu);
    if (cpu.terminate) return;
    // 004bbb95  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004bbb97  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbb98  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bbb99(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bbb99);
    // 004bbb99  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bbb9a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bbb9b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bbb9c  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004bbb9d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bbb9e  83ec44                 -sub esp, 0x44
    (cpu.esp) -= x86::reg32(x86::sreg32(68 /*0x44*/));
    // 004bbba1  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004bbba3  8954243c               -mov dword ptr [esp + 0x3c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.edx;
    // 004bbba7  8d7c2434               -lea edi, [esp + 0x34]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004bbbab  8d6c2401               -lea ebp, [esp + 1]
    cpu.ebp = x86::reg32(cpu.esp + x86::reg32(1) /* 0x1 */);
    // 004bbbaf  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004bbbb1  89542440               -mov dword ptr [esp + 0x40], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.edx;
    // 004bbbb5  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004bbbb7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004bbbb9  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 004bbbbb  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004bbbbc  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004bbbbd  895c2424               -mov dword ptr [esp + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 004bbbc1  89542428               -mov dword ptr [esp + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 004bbbc5  882424                 -mov byte ptr [esp], ah
    app->getMemory<x86::reg8>(cpu.esp) = cpu.ah;
L_0x004bbbc8:
    // 004bbbc8  8d7c242c               -lea edi, [esp + 0x2c]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004bbbcc  8d742434               -lea esi, [esp + 0x34]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004bbbd0  8d5c2424               -lea ebx, [esp + 0x24]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004bbbd4  8d442434               -lea eax, [esp + 0x34]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004bbbd8  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004bbbdb  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004bbbdd  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004bbbe0  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004bbbe2  e81e5f0000             -call 0x4c1b05
    cpu.esp -= 4;
    sub_4c1b05(app, cpu);
    if (cpu.terminate) return;
    // 004bbbe7  895604                 -mov dword ptr [esi + 4], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004bbbea  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 004bbbec  894f04                 -mov dword ptr [edi + 4], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004bbbef  891f                   -mov dword ptr [edi], ebx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.ebx;
    // 004bbbf1  8b5c242c               -mov ebx, dword ptr [esp + 0x2c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004bbbf5  8a837c094e00           -mov al, byte ptr [ebx + 0x4e097c]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5114236) /* 0x4e097c */);
    // 004bbbfb  884500                 -mov byte ptr [ebp], al
    app->getMemory<x86::reg8>(cpu.ebp) = cpu.al;
    // 004bbbfe  8b5c2434               -mov ebx, dword ptr [esp + 0x34]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004bbc02  45                     -inc ebp
    (cpu.ebp)++;
    // 004bbc03  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004bbc05  75c1                   -jne 0x4bbbc8
    if (!cpu.flags.zf)
    {
        goto L_0x004bbbc8;
    }
    // 004bbc07  837c243800             +cmp dword ptr [esp + 0x38], 0
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
    // 004bbc0c  75ba                   -jne 0x4bbbc8
    if (!cpu.flags.zf)
    {
        goto L_0x004bbbc8;
    }
L_0x004bbc0e:
    // 004bbc0e  8b5c2440               -mov ebx, dword ptr [esp + 0x40]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 004bbc12  4d                     -dec ebp
    (cpu.ebp)--;
    // 004bbc13  8d7301                 -lea esi, [ebx + 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004bbc16  8a4500                 -mov al, byte ptr [ebp]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp);
    // 004bbc19  89742440               -mov dword ptr [esp + 0x40], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.esi;
    // 004bbc1d  8803                   -mov byte ptr [ebx], al
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.al;
    // 004bbc1f  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 004bbc21  75eb                   -jne 0x4bbc0e
    if (!cpu.flags.zf)
    {
        goto L_0x004bbc0e;
    }
    // 004bbc23  8b44243c               -mov eax, dword ptr [esp + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 004bbc27  83c444                 -add esp, 0x44
    (cpu.esp) += x86::reg32(x86::sreg32(68 /*0x44*/));
    // 004bbc2a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbc2b  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004bbc2c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbc2d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbc2e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbc2f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bbc30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bbc30);
    // 004bbc30  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bbc31  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bbc32  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bbc33  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004bbc34  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004bbc37  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004bbc39  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004bbc3b  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004bbc3d  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 004bbc3f  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004bbc41  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004bbc42  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004bbc43  83fb0a                 +cmp ebx, 0xa
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10 /*0xa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bbc46  752d                   -jne 0x4bbc75
    if (!cpu.flags.zf)
    {
        goto L_0x004bbc75;
    }
    // 004bbc48  f644240780             +test byte ptr [esp + 7], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp + x86::reg32(7) /* 0x7 */) & 128 /*0x80*/));
    // 004bbc4d  7426                   -je 0x4bbc75
    if (cpu.flags.zf)
    {
        goto L_0x004bbc75;
    }
    // 004bbc4f  c6022d                 -mov byte ptr [edx], 0x2d
    app->getMemory<x86::reg8>(cpu.edx) = 45 /*0x2d*/;
    // 004bbc52  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004bbc55  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004bbc59  f7d2                   -not edx
    cpu.edx = ~cpu.edx;
    // 004bbc5b  f7d6                   -not esi
    cpu.esi = ~cpu.esi;
    // 004bbc5d  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004bbc60  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 004bbc64  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 004bbc67  8d5101                 -lea edx, [ecx + 1]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 004bbc6a  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004bbc6b  893c24                 -mov dword ptr [esp], edi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edi;
    // 004bbc6e  7501                   -jne 0x4bbc71
    if (!cpu.flags.zf)
    {
        goto L_0x004bbc71;
    }
    // 004bbc70  46                     -inc esi
    (cpu.esi)++;
L_0x004bbc71:
    // 004bbc71  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
L_0x004bbc75:
    // 004bbc75  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004bbc77  e81dffffff             -call 0x4bbb99
    cpu.esp -= 4;
    sub_4bbb99(app, cpu);
    if (cpu.terminate) return;
    // 004bbc7c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004bbc7e  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004bbc81  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004bbc82  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbc83  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbc84  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbc85  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bbc86(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bbc86);
    // 004bbc86  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bbc87  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bbc88  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bbc89  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bbc8a  83ec28                 -sub esp, 0x28
    (cpu.esp) -= x86::reg32(x86::sreg32(40 /*0x28*/));
    // 004bbc8d  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004bbc8f  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004bbc91  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004bbc93  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 004bbc95  8d4c2401               -lea ecx, [esp + 1]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(1) /* 0x1 */);
    // 004bbc99  881424                 -mov byte ptr [esp], dl
    app->getMemory<x86::reg8>(cpu.esp) = cpu.dl;
L_0x004bbc9c:
    // 004bbc9c  8d5c2424               -lea ebx, [esp + 0x24]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004bbca0  897c2424               -mov dword ptr [esp + 0x24], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edi;
    // 004bbca4  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004bbca6  f733                   -div dword ptr [ebx]
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = app->getMemory<x86::reg32>(cpu.ebx);
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004bbca8  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 004bbcaa  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004bbcae  8a92a4094e00           -mov dl, byte ptr [edx + 0x4e09a4]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5114276) /* 0x4e09a4 */);
    // 004bbcb4  8811                   -mov byte ptr [ecx], dl
    app->getMemory<x86::reg8>(cpu.ecx) = cpu.dl;
    // 004bbcb6  41                     -inc ecx
    (cpu.ecx)++;
    // 004bbcb7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bbcb9  75e1                   -jne 0x4bbc9c
    if (!cpu.flags.zf)
    {
        goto L_0x004bbc9c;
    }
L_0x004bbcbb:
    // 004bbcbb  49                     -dec ecx
    (cpu.ecx)--;
    // 004bbcbc  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 004bbcbe  8806                   -mov byte ptr [esi], al
    app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
    // 004bbcc0  46                     -inc esi
    (cpu.esi)++;
    // 004bbcc1  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 004bbcc3  75f6                   -jne 0x4bbcbb
    if (!cpu.flags.zf)
    {
        goto L_0x004bbcbb;
    }
    // 004bbcc5  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004bbcc7  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 004bbcca  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbccb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbccc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbccd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbcce  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bbccf(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bbccf);
    // 004bbccf  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bbcd0  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004bbcd2  83fb0a                 +cmp ebx, 0xa
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10 /*0xa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bbcd5  750a                   -jne 0x4bbce1
    if (!cpu.flags.zf)
    {
        goto L_0x004bbce1;
    }
    // 004bbcd7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bbcd9  7d06                   -jge 0x4bbce1
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bbce1;
    }
    // 004bbcdb  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 004bbcdd  c6022d                 -mov byte ptr [edx], 0x2d
    app->getMemory<x86::reg8>(cpu.edx) = 45 /*0x2d*/;
    // 004bbce0  42                     -inc edx
    (cpu.edx)++;
L_0x004bbce1:
    // 004bbce1  e8a0ffffff             -call 0x4bbc86
    cpu.esp -= 4;
    sub_4bbc86(app, cpu);
    if (cpu.terminate) return;
    // 004bbce6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004bbce8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbce9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bbcea(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bbcea);
    // 004bbcea  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bbceb  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bbcec  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bbced  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bbcee  ff1574ed4d00           -call dword ptr [0x4ded74]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107060) /* 0x4ded74 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bbcf4  a138db4d00             -mov eax, dword ptr [0x4ddb38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5102392) /* 0x4ddb38 */);
    // 004bbcf9  e9a2000000             -jmp 0x4bbda0
    return sub_4bbda0(app, cpu);
}

/* align: skip  */
void Application::sub_4bbcfe(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bbcfe);
    // 004bbcfe  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bbcff  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bbd00  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bbd01  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bbd02  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bbd03  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004bbd05  6800800000             -push 0x8000
    app->getMemory<x86::reg32>(cpu.esp-4) = 32768 /*0x8000*/;
    cpu.esp -= 4;
    // 004bbd0a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004bbd0c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004bbd0d  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004bbd10  2eff15c8654c00         -call dword ptr cs:[0x4c65c8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006792) /* 0x4c65c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bbd17  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bbd19  7507                   -jne 0x4bbd22
    if (!cpu.flags.zf)
    {
        goto L_0x004bbd22;
    }
    // 004bbd1b  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004bbd20  eb36                   -jmp 0x4bbd58
    goto L_0x004bbd58;
L_0x004bbd22:
    // 004bbd22  3b1d3cdb4d00           +cmp ebx, dword ptr [0x4ddb3c]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5102396) /* 0x4ddb3c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bbd28  751c                   -jne 0x4bbd46
    if (!cpu.flags.zf)
    {
        goto L_0x004bbd46;
    }
    // 004bbd2a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004bbd2c  7408                   -je 0x4bbd36
    if (cpu.flags.zf)
    {
        goto L_0x004bbd36;
    }
    // 004bbd2e  89353cdb4d00           -mov dword ptr [0x4ddb3c], esi
    app->getMemory<x86::reg32>(x86::reg32(5102396) /* 0x4ddb3c */) = cpu.esi;
    // 004bbd34  eb10                   -jmp 0x4bbd46
    goto L_0x004bbd46;
L_0x004bbd36:
    // 004bbd36  a138db4d00             -mov eax, dword ptr [0x4ddb38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5102392) /* 0x4ddb38 */);
    // 004bbd3b  893540db4d00           -mov dword ptr [0x4ddb40], esi
    app->getMemory<x86::reg32>(x86::reg32(5102400) /* 0x4ddb40 */) = cpu.esi;
    // 004bbd41  a33cdb4d00             -mov dword ptr [0x4ddb3c], eax
    app->getMemory<x86::reg32>(x86::reg32(5102396) /* 0x4ddb3c */) = cpu.eax;
L_0x004bbd46:
    // 004bbd46  3b1db4675b00           +cmp ebx, dword ptr [0x5b67b4]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5990324) /* 0x5b67b4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bbd4c  7508                   -jne 0x4bbd56
    if (!cpu.flags.zf)
    {
        goto L_0x004bbd56;
    }
    // 004bbd4e  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004bbd50  893db4675b00           -mov dword ptr [0x5b67b4], edi
    app->getMemory<x86::reg32>(x86::reg32(5990324) /* 0x5b67b4 */) = cpu.edi;
L_0x004bbd56:
    // 004bbd56  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004bbd58:
    // 004bbd58  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbd59  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbd5a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbd5b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbd5c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbd5d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bbd5e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bbd5e);
    // 004bbd5e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bbd5f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004bbd60  8b5804                 -mov ebx, dword ptr [eax + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004bbd63  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004bbd66  e893ffffff             -call 0x4bbcfe
    cpu.esp -= 4;
    sub_4bbcfe(app, cpu);
    if (cpu.terminate) return;
    // 004bbd6b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bbd6d  7516                   -jne 0x4bbd85
    if (!cpu.flags.zf)
    {
        goto L_0x004bbd85;
    }
    // 004bbd6f  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004bbd71  7508                   -jne 0x4bbd7b
    if (!cpu.flags.zf)
    {
        goto L_0x004bbd7b;
    }
    // 004bbd73  891538db4d00           -mov dword ptr [0x4ddb38], edx
    app->getMemory<x86::reg32>(x86::reg32(5102392) /* 0x4ddb38 */) = cpu.edx;
    // 004bbd79  eb03                   -jmp 0x4bbd7e
    goto L_0x004bbd7e;
L_0x004bbd7b:
    // 004bbd7b  895308                 -mov dword ptr [ebx + 8], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.edx;
L_0x004bbd7e:
    // 004bbd7e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004bbd80  7403                   -je 0x4bbd85
    if (cpu.flags.zf)
    {
        goto L_0x004bbd85;
    }
    // 004bbd82  895a04                 -mov dword ptr [edx + 4], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ebx;
L_0x004bbd85:
    // 004bbd85  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbd86  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbd87  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bbd88(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bbd88);
L_0x004bbd88:
    // 004bbd88  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004bbd8a  8b5024                 -mov edx, dword ptr [eax + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 004bbd8d  83e92c                 -sub ecx, 0x2c
    (cpu.ecx) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004bbd90  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 004bbd92  8b5808                 -mov ebx, dword ptr [eax + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004bbd95  39f1                   +cmp ecx, esi
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
    // 004bbd97  7505                   -jne 0x4bbd9e
    if (!cpu.flags.zf)
    {
        goto L_0x004bbd9e;
    }
    // 004bbd99  e8c0ffffff             -call 0x4bbd5e
    cpu.esp -= 4;
    sub_4bbd5e(app, cpu);
    if (cpu.terminate) return;
L_0x004bbd9e:
    // 004bbd9e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004bbda0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bbda2  75e4                   -jne 0x4bbd88
    if (!cpu.flags.zf)
    {
        goto L_0x004bbd88;
    }
    // 004bbda4  ff157ced4d00           -call dword ptr [0x4ded7c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107068) /* 0x4ded7c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bbdaa  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bbdac  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbdad  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbdae  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbdaf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbdb0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bbda0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bbda0);
    goto L_entry_0x004bbda0;
L_0x004bbd88:
    // 004bbd88  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004bbd8a  8b5024                 -mov edx, dword ptr [eax + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 004bbd8d  83e92c                 -sub ecx, 0x2c
    (cpu.ecx) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 004bbd90  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 004bbd92  8b5808                 -mov ebx, dword ptr [eax + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004bbd95  39f1                   +cmp ecx, esi
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
    // 004bbd97  7505                   -jne 0x4bbd9e
    if (!cpu.flags.zf)
    {
        goto L_0x004bbd9e;
    }
    // 004bbd99  e8c0ffffff             -call 0x4bbd5e
    cpu.esp -= 4;
    sub_4bbd5e(app, cpu);
    if (cpu.terminate) return;
L_0x004bbd9e:
    // 004bbd9e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_entry_0x004bbda0:
    // 004bbda0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bbda2  75e4                   -jne 0x4bbd88
    if (!cpu.flags.zf)
    {
        goto L_0x004bbd88;
    }
    // 004bbda4  ff157ced4d00           -call dword ptr [0x4ded7c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5107068) /* 0x4ded7c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bbdaa  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bbdac  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbdad  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbdae  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbdaf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbdb0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_4bbdb4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bbdb4);
    // 004bbdb4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bbdb5  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004bbdb7  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004bbdb8  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bbdb9  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004bbdbc  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004bbdbf  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004bbdc2  8b451c                 -mov eax, dword ptr [ebp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 004bbdc5  8b5520                 -mov edx, dword ptr [ebp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 004bbdc8  8b5d18                 -mov ebx, dword ptr [ebp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 004bbdcb  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004bbdcd  891ddc094e00           -mov dword ptr [0x4e09dc], ebx
    app->getMemory<x86::reg32>(x86::reg32(5114332) /* 0x4e09dc */) = cpu.ebx;
    // 004bbdd3  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004bbdd6  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp);
    // 004bbdd9  83f901                 +cmp ecx, 1
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
    // 004bbddc  7e7a                   -jle 0x4bbe58
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bbe58;
    }
    // 004bbdde  83e901                 -sub ecx, 1
    (cpu.ecx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004bbde1:
    // 004bbde1  db05de094e00           -fild dword ptr [0x4e09de]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5114334) /* 0x4e09de */))));
    // 004bbde7  d904ae                 -fld dword ptr [esi + ebp*4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + cpu.ebp * 4)));
    // 004bbdea  d944ae04               -fld dword ptr [esi + ebp*4 + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ebp * 4)));
    // 004bbdee  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004bbdf1  03da                   +add ebx, edx
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004bbdf3  13e8                   -adc ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 004bbdf5  891ddc094e00           -mov dword ptr [0x4e09dc], ebx
    app->getMemory<x86::reg32>(x86::reg32(5114332) /* 0x4e09dc */) = cpu.ebx;
    // 004bbdfb  db05de094e00           -fild dword ptr [0x4e09de]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5114334) /* 0x4e09de */))));
    // 004bbe01  d904ae                 -fld dword ptr [esi + ebp*4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + cpu.ebp * 4)));
    // 004bbe04  d944ae04               -fld dword ptr [esi + ebp*4 + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ebp * 4)));
    // 004bbe08  d9cd                   -fxch st(5)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(5);
        cpu.fpu.st(5) = tmp;
    }
    // 004bbe0a  d80dd8094e00           -fmul dword ptr [0x4e09d8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5114328) /* 0x4e09d8 */));
    // 004bbe10  d905d4094e00           -fld dword ptr [0x4e09d4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5114324) /* 0x4e09d4 */)));
    // 004bbe16  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004bbe18  d80dd8094e00           -fmul dword ptr [0x4e09d8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5114328) /* 0x4e09d8 */));
    // 004bbe1e  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004bbe20  dceb                   -fsub st(3), st(0)
    cpu.fpu.st(3) -= x86::Float(cpu.fpu.st(0));
    // 004bbe22  d905d4094e00           -fld dword ptr [0x4e09d4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5114324) /* 0x4e09d4 */)));
    // 004bbe28  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004bbe2a  dcea                   -fsub st(2), st(0)
    cpu.fpu.st(2) -= x86::Float(cpu.fpu.st(0));
    // 004bbe2c  d9cc                   -fxch st(4)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(4);
        cpu.fpu.st(4) = tmp;
    }
    // 004bbe2e  dece                   -fmulp st(6)
    cpu.fpu.st(6) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004bbe30  03da                   +add ebx, edx
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004bbe32  decc                   +fmulp st(4)
    cpu.fpu.st(4) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004bbe34  dec9                   +fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004bbe36  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004bbe38  decc                   +fmulp st(4)
    cpu.fpu.st(4) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004bbe3a  d9ca                   +fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004bbe3c  dec1                   +faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004bbe3e  d9c9                   +fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004bbe40  dec2                   +faddp st(2)
    cpu.fpu.st(2) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004bbe42  13e8                   -adc ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 004bbe44  891ddc094e00           -mov dword ptr [0x4e09dc], ebx
    app->getMemory<x86::reg32>(x86::reg32(5114332) /* 0x4e09dc */) = cpu.ebx;
    // 004bbe4a  d95ff8                 -fstp dword ptr [edi - 8]
    app->getMemory<float>(cpu.edi + x86::reg32(-8) /* -0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bbe4d  d95ffc                 -fstp dword ptr [edi - 4]
    app->getMemory<float>(cpu.edi + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bbe50  83e902                 +sub ecx, 2
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
    // 004bbe53  7f8c                   -jg 0x4bbde1
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004bbde1;
    }
    // 004bbe55  83c101                 -add ecx, 1
    (cpu.ecx) += x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004bbe58:
    // 004bbe58  83f900                 +cmp ecx, 0
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bbe5b  7e36                   -jle 0x4bbe93
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bbe93;
    }
    // 004bbe5d  db05de094e00           -fild dword ptr [0x4e09de]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5114334) /* 0x4e09de */))));
    // 004bbe63  d905d4094e00           -fld dword ptr [0x4e09d4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5114324) /* 0x4e09d4 */)));
    // 004bbe69  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004bbe6b  d80dd8094e00           -fmul dword ptr [0x4e09d8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5114328) /* 0x4e09d8 */));
    // 004bbe71  dce9                   -fsub st(1), st(0)
    cpu.fpu.st(1) -= x86::Float(cpu.fpu.st(0));
    // 004bbe73  d84cae04               -fmul dword ptr [esi + ebp*4 + 4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ebp * 4));
    // 004bbe77  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004bbe79  d80cae                 -fmul dword ptr [esi + ebp*4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + cpu.ebp * 4));
    // 004bbe7c  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004bbe7e  03da                   +add ebx, edx
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004bbe80  13e8                   -adc ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 004bbe82  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bbe85  891ddc094e00           -mov dword ptr [0x4e09dc], ebx
    app->getMemory<x86::reg32>(x86::reg32(5114332) /* 0x4e09dc */) = cpu.ebx;
    // 004bbe8b  d95ffc                 -fstp dword ptr [edi - 4]
    app->getMemory<float>(cpu.edi + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bbe8e  83e901                 +sub ecx, 1
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
    // 004bbe91  7fc5                   -jg 0x4bbe58
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004bbe58;
    }
L_0x004bbe93:
    // 004bbe93  8bcd                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004bbe95  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbe96  8b5518                 -mov edx, dword ptr [ebp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 004bbe99  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 004bbe9b  8b5514                 -mov edx, dword ptr [ebp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004bbe9e  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 004bbea0  61                     -popal 
    {
        cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
        cpu.esi = app->getMemory<x86::reg32>(cpu.esp + 4);
        cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + 8);
        // skip esp
        cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + 16);
        cpu.edx = app->getMemory<x86::reg32>(cpu.esp + 20);
        cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + 24);
        cpu.eax = app->getMemory<x86::reg32>(cpu.esp + 28);
        cpu.esp += 32;
    }
    // 004bbea1  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbea2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4bbea4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bbea4);
    // 004bbea4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bbea5  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004bbea7  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004bbea8  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bbea9  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004bbeac  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004bbeaf  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004bbeb2  8b451c                 -mov eax, dword ptr [ebp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 004bbeb5  8b5520                 -mov edx, dword ptr [ebp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 004bbeb8  8b5d18                 -mov ebx, dword ptr [ebp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 004bbebb  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004bbebd  891dec094e00           -mov dword ptr [0x4e09ec], ebx
    app->getMemory<x86::reg32>(x86::reg32(5114348) /* 0x4e09ec */) = cpu.ebx;
    // 004bbec3  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004bbec6  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp);
    // 004bbec9  eb06                   -jmp 0x4bbed1
    goto L_0x004bbed1;
L_0x004bbecb:
    // 004bbecb  d95ff8                 -fstp dword ptr [edi - 8]
    app->getMemory<float>(cpu.edi + x86::reg32(-8) /* -0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bbece  d95ffc                 -fstp dword ptr [edi - 4]
    app->getMemory<float>(cpu.edi + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
L_0x004bbed1:
    // 004bbed1  db05ee094e00           -fild dword ptr [0x4e09ee]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5114350) /* 0x4e09ee */))));
    // 004bbed7  d905e4094e00           -fld dword ptr [0x4e09e4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5114340) /* 0x4e09e4 */)));
    // 004bbedd  d904ee                 -fld dword ptr [esi + ebp*8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + cpu.ebp * 8)));
    // 004bbee0  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004bbee2  d80de8094e00           -fmul dword ptr [0x4e09e8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5114344) /* 0x4e09e8 */));
    // 004bbee8  d944ee04               -fld dword ptr [esi + ebp*8 + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ebp * 8)));
    // 004bbeec  d944ee08               -fld dword ptr [esi + ebp*8 + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(8) /* 0x8 */ + cpu.ebp * 8)));
    // 004bbef0  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004bbef2  dceb                   -fsub st(3), st(0)
    cpu.fpu.st(3) -= x86::Float(cpu.fpu.st(0));
    // 004bbef4  dcca                   -fmul st(2), st(0)
    cpu.fpu.st(2) *= cpu.fpu.st(0);
    // 004bbef6  d944ee0c               -fld dword ptr [esi + ebp*8 + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(12) /* 0xc */ + cpu.ebp * 8)));
    // 004bbefa  d9cc                   -fxch st(4)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(4);
        cpu.fpu.st(4) = tmp;
    }
    // 004bbefc  dccd                   -fmul st(5), st(0)
    cpu.fpu.st(5) *= cpu.fpu.st(0);
    // 004bbefe  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004bbf01  03da                   +add ebx, edx
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004bbf03  deca                   +fmulp st(2)
    cpu.fpu.st(2) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004bbf05  13e8                   -adc ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 004bbf07  891dec094e00           -mov dword ptr [0x4e09ec], ebx
    app->getMemory<x86::reg32>(x86::reg32(5114348) /* 0x4e09ec */) = cpu.ebx;
    // 004bbf0d  decb                   -fmulp st(3)
    cpu.fpu.st(3) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004bbf0f  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004bbf11  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004bbf13  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004bbf15  dec2                   -faddp st(2)
    cpu.fpu.st(2) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004bbf17  83e901                 +sub ecx, 1
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
    // 004bbf1a  7faf                   -jg 0x4bbecb
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004bbecb;
    }
    // 004bbf1c  d95ff8                 -fstp dword ptr [edi - 8]
    app->getMemory<float>(cpu.edi + x86::reg32(-8) /* -0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bbf1f  d95ffc                 -fstp dword ptr [edi - 4]
    app->getMemory<float>(cpu.edi + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bbf22  8bcd                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004bbf24  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbf25  8b5518                 -mov edx, dword ptr [ebp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 004bbf28  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 004bbf2a  8b5514                 -mov edx, dword ptr [ebp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004bbf2d  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 004bbf2f  61                     -popal 
    {
        cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
        cpu.esi = app->getMemory<x86::reg32>(cpu.esp + 4);
        cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + 8);
        // skip esp
        cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + 16);
        cpu.edx = app->getMemory<x86::reg32>(cpu.esp + 20);
        cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + 24);
        cpu.eax = app->getMemory<x86::reg32>(cpu.esp + 28);
        cpu.esp += 32;
    }
    // 004bbf30  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbf31  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4bbf34(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bbf34);
    // 004bbf34  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bbf35  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004bbf37  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004bbf38  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bbf39  bbffff0000             -mov ebx, 0xffff
    cpu.ebx = 65535 /*0xffff*/;
    // 004bbf3e  0f6edb                 -movd mm3, ebx
    cpu.mmx.mm3 = { _mm_cvtsi32_si128(cpu.ebx) };
    // 004bbf41  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004bbf44  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004bbf47  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004bbf4a  8b451c                 -mov eax, dword ptr [ebp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 004bbf4d  8b5520                 -mov edx, dword ptr [ebp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 004bbf50  8b5d18                 -mov ebx, dword ptr [ebp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 004bbf53  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004bbf55  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004bbf58  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp);
    // 004bbf5b  0f6ecb                 -movd mm1, ebx
    cpu.mmx.mm1 = { _mm_cvtsi32_si128(cpu.ebx) };
    // 004bbf5e  0f6ed3                 -movd mm2, ebx
    cpu.mmx.mm2 = { _mm_cvtsi32_si128(cpu.ebx) };
    // 004bbf61  0f72d110               -psrld mm1, 0x10
    cpu.mmx.mm1 = { _mm_srli_epi32(cpu.mmx.mm1, 16 /*0x10*/) };
    // 004bbf65  0febca                 -por mm1, mm2
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm2) };
    // 004bbf68  0fefcb                 -pxor mm1, mm3
    cpu.mmx.mm1 = { _mm_xor_si128(cpu.mmx.mm1, cpu.mmx.mm3) };
    // 004bbf6b  4a                     -dec edx
    (cpu.edx)--;
    // 004bbf6c  0f6ee2                 -movd mm4, edx
    cpu.mmx.mm4 = { _mm_cvtsi32_si128(cpu.edx) };
    // 004bbf6f  42                     -inc edx
    (cpu.edx)++;
    // 004bbf70  0f6eea                 -movd mm5, edx
    cpu.mmx.mm5 = { _mm_cvtsi32_si128(cpu.edx) };
    // 004bbf73  0f72d410               -psrld mm4, 0x10
    cpu.mmx.mm4 = { _mm_srli_epi32(cpu.mmx.mm4, 16 /*0x10*/) };
    // 004bbf77  0febe5                 -por mm4, mm5
    cpu.mmx.mm4 = { _mm_or_si128(cpu.mmx.mm4, cpu.mmx.mm5) };
    // 004bbf7a  0fefe3                 -pxor mm4, mm3
    cpu.mmx.mm4 = { _mm_xor_si128(cpu.mmx.mm4, cpu.mmx.mm3) };
L_0x004bbf7d:
    // 004bbf7d  0f60443500             -punpcklbw mm0, dword ptr [ebp + esi]
    cpu.mmx.mm0 = { _mm_unpacklo_epi8(cpu.mmx.mm0, x86::from_reg64(app->getMemory<x86::reg64>(cpu.ebp + cpu.esi * 1))) };
    // 004bbf82  0f6fd1                 -movq mm2, mm1
    cpu.mmx.mm2 = cpu.mmx.mm1;
    // 004bbf85  0f71d201               -psrlw mm2, 1
    cpu.mmx.mm2 = { _mm_srli_epi16(cpu.mmx.mm2, 1 /*0x1*/) };
    // 004bbf89  0ff5c2                 -pmaddwd mm0, mm2
    cpu.mmx.mm0 = { _mm_madd_epi16(cpu.mmx.mm0, cpu.mmx.mm2) };
    // 004bbf8c  0f73d017               -psrlq mm0, 0x17
    cpu.mmx.mm0 = { _mm_srli_epi64(cpu.mmx.mm0, 23 /*0x17*/) };
    // 004bbf90  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bbf91  0f7ec1                 -movd ecx, mm0
    cpu.ecx = _mm_cvtsi128_si32(cpu.mmx.mm0);
    // 004bbf94  0ffdcc                 -paddw mm1, mm4
    cpu.mmx.mm1 = { _mm_add_epi16(cpu.mmx.mm1, cpu.mmx.mm4) };
    // 004bbf97  880f                   -mov byte ptr [edi], cl
    app->getMemory<x86::reg8>(cpu.edi) = cpu.cl;
    // 004bbf99  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbf9a  03da                   +add ebx, edx
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004bbf9c  13e8                   -adc ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 004bbf9e  83c701                 +add edi, 1
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004bbfa1  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004bbfa2  7fd9                   -jg 0x4bbf7d
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004bbf7d;
    }
    // 004bbfa4  8bcd                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004bbfa6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbfa7  8b5518                 -mov edx, dword ptr [ebp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 004bbfaa  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 004bbfac  8b5514                 -mov edx, dword ptr [ebp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004bbfaf  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 004bbfb1  61                     -popal 
    {
        cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
        cpu.esi = app->getMemory<x86::reg32>(cpu.esp + 4);
        cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + 8);
        // skip esp
        cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + 16);
        cpu.edx = app->getMemory<x86::reg32>(cpu.esp + 20);
        cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + 24);
        cpu.eax = app->getMemory<x86::reg32>(cpu.esp + 28);
        cpu.esp += 32;
    }
    // 004bbfb2  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bbfb3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bbfb4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bbfb4);
    // 004bbfb4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bbfb5  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004bbfb7  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004bbfb8  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bbfb9  bbffff0000             -mov ebx, 0xffff
    cpu.ebx = 65535 /*0xffff*/;
    // 004bbfbe  0f6ee3                 -movd mm4, ebx
    cpu.mmx.mm4 = { _mm_cvtsi32_si128(cpu.ebx) };
    // 004bbfc1  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004bbfc4  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004bbfc7  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004bbfca  8b451c                 -mov eax, dword ptr [ebp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 004bbfcd  8b5520                 -mov edx, dword ptr [ebp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 004bbfd0  8b5d18                 -mov ebx, dword ptr [ebp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 004bbfd3  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004bbfd5  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004bbfd8  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp);
    // 004bbfdb  0f6ed3                 -movd mm2, ebx
    cpu.mmx.mm2 = { _mm_cvtsi32_si128(cpu.ebx) };
    // 004bbfde  0f6edb                 -movd mm3, ebx
    cpu.mmx.mm3 = { _mm_cvtsi32_si128(cpu.ebx) };
    // 004bbfe1  0f72d210               -psrld mm2, 0x10
    cpu.mmx.mm2 = { _mm_srli_epi32(cpu.mmx.mm2, 16 /*0x10*/) };
    // 004bbfe5  0febd3                 -por mm2, mm3
    cpu.mmx.mm2 = { _mm_or_si128(cpu.mmx.mm2, cpu.mmx.mm3) };
    // 004bbfe8  0fefd4                 -pxor mm2, mm4
    cpu.mmx.mm2 = { _mm_xor_si128(cpu.mmx.mm2, cpu.mmx.mm4) };
    // 004bbfeb  0f6fea                 -movq mm5, mm2
    cpu.mmx.mm5 = cpu.mmx.mm2;
    // 004bbfee  0f73f220               -psllq mm2, 0x20
    cpu.mmx.mm2 = { _mm_slli_epi64(cpu.mmx.mm2, 32 /*0x20*/) };
    // 004bbff2  0febd5                 -por mm2, mm5
    cpu.mmx.mm2 = { _mm_or_si128(cpu.mmx.mm2, cpu.mmx.mm5) };
    // 004bbff5  4a                     -dec edx
    (cpu.edx)--;
    // 004bbff6  0f6eea                 -movd mm5, edx
    cpu.mmx.mm5 = { _mm_cvtsi32_si128(cpu.edx) };
    // 004bbff9  42                     -inc edx
    (cpu.edx)++;
    // 004bbffa  0f6ef2                 -movd mm6, edx
    cpu.mmx.mm6 = { _mm_cvtsi32_si128(cpu.edx) };
    // 004bbffd  0f72d510               -psrld mm5, 0x10
    cpu.mmx.mm5 = { _mm_srli_epi32(cpu.mmx.mm5, 16 /*0x10*/) };
    // 004bc001  0febee                 -por mm5, mm6
    cpu.mmx.mm5 = { _mm_or_si128(cpu.mmx.mm5, cpu.mmx.mm6) };
    // 004bc004  0fefec                 -pxor mm5, mm4
    cpu.mmx.mm5 = { _mm_xor_si128(cpu.mmx.mm5, cpu.mmx.mm4) };
    // 004bc007  0f6fe5                 -movq mm4, mm5
    cpu.mmx.mm4 = cpu.mmx.mm5;
    // 004bc00a  0f73f520               -psllq mm5, 0x20
    cpu.mmx.mm5 = { _mm_slli_epi64(cpu.mmx.mm5, 32 /*0x20*/) };
    // 004bc00e  0febec                 -por mm5, mm4
    cpu.mmx.mm5 = { _mm_or_si128(cpu.mmx.mm5, cpu.mmx.mm4) };
L_0x004bc011:
    // 004bc011  0f6e0c6e               -movd mm1, dword ptr [esi + ebp*2]
    cpu.mmx.mm1 = { _mm_loadu_si32(&app->getMemory<x86::reg32>(cpu.esi + cpu.ebp * 2)) };
    // 004bc015  0f6fda                 -movq mm3, mm2
    cpu.mmx.mm3 = cpu.mmx.mm2;
    // 004bc018  0f71d301               -psrlw mm3, 1
    cpu.mmx.mm3 = { _mm_srli_epi16(cpu.mmx.mm3, 1 /*0x1*/) };
    // 004bc01c  0f604c6e02             -punpcklbw mm1, dword ptr [esi + ebp*2 + 2]
    cpu.mmx.mm1 = { _mm_unpacklo_epi8(cpu.mmx.mm1, x86::from_reg64(app->getMemory<x86::reg64>(cpu.esi + x86::reg32(2) /* 0x2 */ + cpu.ebp * 2))) };
    // 004bc021  0f60c1                 -punpcklbw mm0, mm1
    cpu.mmx.mm0 = { _mm_unpacklo_epi8(cpu.mmx.mm0, cpu.mmx.mm1) };
    // 004bc024  0ff5c3                 -pmaddwd mm0, mm3
    cpu.mmx.mm0 = { _mm_madd_epi16(cpu.mmx.mm0, cpu.mmx.mm3) };
    // 004bc027  0f72e017               -psrad mm0, 0x17
    cpu.mmx.mm0 = { _mm_srai_epi32(cpu.mmx.mm0, 23 /*0x17*/) };
    // 004bc02b  0ffdd5                 -paddw mm2, mm5
    cpu.mmx.mm2 = { _mm_add_epi16(cpu.mmx.mm2, cpu.mmx.mm5) };
    // 004bc02e  0f6bc1                 -packssdw mm0, mm1
    { __m128i _packed = _mm_packs_epi32(cpu.mmx.mm0, cpu.mmx.mm1); cpu.mmx.mm0 = {_mm_unpacklo_epi32(_packed, _mm_srli_si128(_packed, 8))}; }
    // 004bc031  0f63c1                 -packsswb mm0, mm1
    { __m128i _packed = _mm_packs_epi16(cpu.mmx.mm0, cpu.mmx.mm1); cpu.mmx.mm0 = {_mm_unpacklo_epi32(_packed, _mm_srli_si128(_packed, 8))}; }
    // 004bc034  03da                   +add ebx, edx
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004bc036  0f7e07                 -movd dword ptr [edi], mm0
    _mm_storeu_si32(&app->getMemory<x86::reg32>(cpu.edi), cpu.mmx.mm0);
    // 004bc039  13e8                   -adc ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 004bc03b  83c702                 +add edi, 2
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004bc03e  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004bc03f  7fd0                   -jg 0x4bc011
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004bc011;
    }
    // 004bc041  8bcd                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004bc043  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc044  8b5518                 -mov edx, dword ptr [ebp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 004bc047  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 004bc049  8b5514                 -mov edx, dword ptr [ebp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004bc04c  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 004bc04e  61                     -popal 
    {
        cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
        cpu.esi = app->getMemory<x86::reg32>(cpu.esp + 4);
        cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + 8);
        // skip esp
        cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + 16);
        cpu.edx = app->getMemory<x86::reg32>(cpu.esp + 20);
        cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + 24);
        cpu.eax = app->getMemory<x86::reg32>(cpu.esp + 28);
        cpu.esp += 32;
    }
    // 004bc04f  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc050  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_4bc054(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bc054);
    // 004bc054  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bc055  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004bc057  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004bc058  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bc059  bbffff0000             -mov ebx, 0xffff
    cpu.ebx = 65535 /*0xffff*/;
    // 004bc05e  0f6edb                 -movd mm3, ebx
    cpu.mmx.mm3 = { _mm_cvtsi32_si128(cpu.ebx) };
    // 004bc061  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004bc064  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004bc067  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004bc06a  8b451c                 -mov eax, dword ptr [ebp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 004bc06d  8b5520                 -mov edx, dword ptr [ebp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 004bc070  8b5d18                 -mov ebx, dword ptr [ebp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 004bc073  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004bc075  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004bc078  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp);
    // 004bc07b  0f6ecb                 -movd mm1, ebx
    cpu.mmx.mm1 = { _mm_cvtsi32_si128(cpu.ebx) };
    // 004bc07e  0f6ed3                 -movd mm2, ebx
    cpu.mmx.mm2 = { _mm_cvtsi32_si128(cpu.ebx) };
    // 004bc081  0f72d110               -psrld mm1, 0x10
    cpu.mmx.mm1 = { _mm_srli_epi32(cpu.mmx.mm1, 16 /*0x10*/) };
    // 004bc085  0febca                 -por mm1, mm2
    cpu.mmx.mm1 = { _mm_or_si128(cpu.mmx.mm1, cpu.mmx.mm2) };
    // 004bc088  0fefcb                 -pxor mm1, mm3
    cpu.mmx.mm1 = { _mm_xor_si128(cpu.mmx.mm1, cpu.mmx.mm3) };
    // 004bc08b  4a                     -dec edx
    (cpu.edx)--;
    // 004bc08c  0f6ee2                 -movd mm4, edx
    cpu.mmx.mm4 = { _mm_cvtsi32_si128(cpu.edx) };
    // 004bc08f  42                     -inc edx
    (cpu.edx)++;
    // 004bc090  0f6eea                 -movd mm5, edx
    cpu.mmx.mm5 = { _mm_cvtsi32_si128(cpu.edx) };
    // 004bc093  0f72d410               -psrld mm4, 0x10
    cpu.mmx.mm4 = { _mm_srli_epi32(cpu.mmx.mm4, 16 /*0x10*/) };
    // 004bc097  0febe5                 -por mm4, mm5
    cpu.mmx.mm4 = { _mm_or_si128(cpu.mmx.mm4, cpu.mmx.mm5) };
    // 004bc09a  0fefe3                 -pxor mm4, mm3
    cpu.mmx.mm4 = { _mm_xor_si128(cpu.mmx.mm4, cpu.mmx.mm3) };
L_0x004bc09d:
    // 004bc09d  0f6e046e               -movd mm0, dword ptr [esi + ebp*2]
    cpu.mmx.mm0 = { _mm_loadu_si32(&app->getMemory<x86::reg32>(cpu.esi + cpu.ebp * 2)) };
    // 004bc0a1  0f6fd1                 -movq mm2, mm1
    cpu.mmx.mm2 = cpu.mmx.mm1;
    // 004bc0a4  0f71d201               -psrlw mm2, 1
    cpu.mmx.mm2 = { _mm_srli_epi16(cpu.mmx.mm2, 1 /*0x1*/) };
    // 004bc0a8  0ff5c2                 -pmaddwd mm0, mm2
    cpu.mmx.mm0 = { _mm_madd_epi16(cpu.mmx.mm0, cpu.mmx.mm2) };
    // 004bc0ab  0f73d00f               -psrlq mm0, 0xf
    cpu.mmx.mm0 = { _mm_srli_epi64(cpu.mmx.mm0, 15 /*0xf*/) };
    // 004bc0af  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bc0b0  0f7ec1                 -movd ecx, mm0
    cpu.ecx = _mm_cvtsi128_si32(cpu.mmx.mm0);
    // 004bc0b3  0ffdcc                 -paddw mm1, mm4
    cpu.mmx.mm1 = { _mm_add_epi16(cpu.mmx.mm1, cpu.mmx.mm4) };
    // 004bc0b6  66890f                 -mov word ptr [edi], cx
    app->getMemory<x86::reg16>(cpu.edi) = cpu.cx;
    // 004bc0b9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc0ba  03da                   +add ebx, edx
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004bc0bc  13e8                   -adc ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 004bc0be  83c702                 +add edi, 2
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004bc0c1  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004bc0c2  7fd9                   -jg 0x4bc09d
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004bc09d;
    }
    // 004bc0c4  8bcd                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004bc0c6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc0c7  8b5518                 -mov edx, dword ptr [ebp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 004bc0ca  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 004bc0cc  8b5514                 -mov edx, dword ptr [ebp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004bc0cf  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 004bc0d1  61                     -popal 
    {
        cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
        cpu.esi = app->getMemory<x86::reg32>(cpu.esp + 4);
        cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + 8);
        // skip esp
        cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + 16);
        cpu.edx = app->getMemory<x86::reg32>(cpu.esp + 20);
        cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + 24);
        cpu.eax = app->getMemory<x86::reg32>(cpu.esp + 28);
        cpu.esp += 32;
    }
    // 004bc0d2  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc0d3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bc0d4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bc0d4);
    // 004bc0d4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bc0d5  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004bc0d7  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004bc0d8  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bc0d9  bbffff0000             -mov ebx, 0xffff
    cpu.ebx = 65535 /*0xffff*/;
    // 004bc0de  0f6ee3                 -movd mm4, ebx
    cpu.mmx.mm4 = { _mm_cvtsi32_si128(cpu.ebx) };
    // 004bc0e1  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004bc0e4  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004bc0e7  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004bc0ea  8b451c                 -mov eax, dword ptr [ebp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 004bc0ed  8b5520                 -mov edx, dword ptr [ebp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 004bc0f0  8b5d18                 -mov ebx, dword ptr [ebp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 004bc0f3  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004bc0f5  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004bc0f8  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp);
    // 004bc0fb  0f6ed3                 -movd mm2, ebx
    cpu.mmx.mm2 = { _mm_cvtsi32_si128(cpu.ebx) };
    // 004bc0fe  0f6edb                 -movd mm3, ebx
    cpu.mmx.mm3 = { _mm_cvtsi32_si128(cpu.ebx) };
    // 004bc101  0f72d210               -psrld mm2, 0x10
    cpu.mmx.mm2 = { _mm_srli_epi32(cpu.mmx.mm2, 16 /*0x10*/) };
    // 004bc105  0febd3                 -por mm2, mm3
    cpu.mmx.mm2 = { _mm_or_si128(cpu.mmx.mm2, cpu.mmx.mm3) };
    // 004bc108  0fefd4                 -pxor mm2, mm4
    cpu.mmx.mm2 = { _mm_xor_si128(cpu.mmx.mm2, cpu.mmx.mm4) };
    // 004bc10b  0f6fea                 -movq mm5, mm2
    cpu.mmx.mm5 = cpu.mmx.mm2;
    // 004bc10e  0f73f220               -psllq mm2, 0x20
    cpu.mmx.mm2 = { _mm_slli_epi64(cpu.mmx.mm2, 32 /*0x20*/) };
    // 004bc112  0febd5                 -por mm2, mm5
    cpu.mmx.mm2 = { _mm_or_si128(cpu.mmx.mm2, cpu.mmx.mm5) };
    // 004bc115  4a                     -dec edx
    (cpu.edx)--;
    // 004bc116  0f6eea                 -movd mm5, edx
    cpu.mmx.mm5 = { _mm_cvtsi32_si128(cpu.edx) };
    // 004bc119  42                     -inc edx
    (cpu.edx)++;
    // 004bc11a  0f6ef2                 -movd mm6, edx
    cpu.mmx.mm6 = { _mm_cvtsi32_si128(cpu.edx) };
    // 004bc11d  0f72d510               -psrld mm5, 0x10
    cpu.mmx.mm5 = { _mm_srli_epi32(cpu.mmx.mm5, 16 /*0x10*/) };
    // 004bc121  0febee                 -por mm5, mm6
    cpu.mmx.mm5 = { _mm_or_si128(cpu.mmx.mm5, cpu.mmx.mm6) };
    // 004bc124  0fefec                 -pxor mm5, mm4
    cpu.mmx.mm5 = { _mm_xor_si128(cpu.mmx.mm5, cpu.mmx.mm4) };
    // 004bc127  0f6fe5                 -movq mm4, mm5
    cpu.mmx.mm4 = cpu.mmx.mm5;
    // 004bc12a  0f73f520               -psllq mm5, 0x20
    cpu.mmx.mm5 = { _mm_slli_epi64(cpu.mmx.mm5, 32 /*0x20*/) };
    // 004bc12e  0febec                 -por mm5, mm4
    cpu.mmx.mm5 = { _mm_or_si128(cpu.mmx.mm5, cpu.mmx.mm4) };
L_0x004bc131:
    // 004bc131  0f6e04ae               -movd mm0, dword ptr [esi + ebp*4]
    cpu.mmx.mm0 = { _mm_loadu_si32(&app->getMemory<x86::reg32>(cpu.esi + cpu.ebp * 4)) };
    // 004bc135  0f6144ae04             -punpcklwd mm0, dword ptr [esi + ebp*4 + 4]
    cpu.mmx.mm0 = { _mm_unpacklo_epi16(cpu.mmx.mm0, x86::from_reg64(app->getMemory<x86::reg64>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ebp * 4))) };
    // 004bc13a  0f6fda                 -movq mm3, mm2
    cpu.mmx.mm3 = cpu.mmx.mm2;
    // 004bc13d  0f71d301               -psrlw mm3, 1
    cpu.mmx.mm3 = { _mm_srli_epi16(cpu.mmx.mm3, 1 /*0x1*/) };
    // 004bc141  0ff5c3                 -pmaddwd mm0, mm3
    cpu.mmx.mm0 = { _mm_madd_epi16(cpu.mmx.mm0, cpu.mmx.mm3) };
    // 004bc144  0f72e00f               -psrad mm0, 0xf
    cpu.mmx.mm0 = { _mm_srai_epi32(cpu.mmx.mm0, 15 /*0xf*/) };
    // 004bc148  0ffdd5                 -paddw mm2, mm5
    cpu.mmx.mm2 = { _mm_add_epi16(cpu.mmx.mm2, cpu.mmx.mm5) };
    // 004bc14b  0f6bc1                 -packssdw mm0, mm1
    { __m128i _packed = _mm_packs_epi32(cpu.mmx.mm0, cpu.mmx.mm1); cpu.mmx.mm0 = {_mm_unpacklo_epi32(_packed, _mm_srli_si128(_packed, 8))}; }
    // 004bc14e  03da                   +add ebx, edx
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004bc150  0f7e07                 -movd dword ptr [edi], mm0
    _mm_storeu_si32(&app->getMemory<x86::reg32>(cpu.edi), cpu.mmx.mm0);
    // 004bc153  13e8                   -adc ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 004bc155  83c704                 +add edi, 4
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
    // 004bc158  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004bc159  7fd6                   -jg 0x4bc131
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004bc131;
    }
    // 004bc15b  8bcd                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004bc15d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc15e  8b5518                 -mov edx, dword ptr [ebp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 004bc161  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 004bc163  8b5514                 -mov edx, dword ptr [ebp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004bc166  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 004bc168  61                     -popal 
    {
        cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
        cpu.esi = app->getMemory<x86::reg32>(cpu.esp + 4);
        cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + 8);
        // skip esp
        cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + 16);
        cpu.edx = app->getMemory<x86::reg32>(cpu.esp + 20);
        cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + 24);
        cpu.eax = app->getMemory<x86::reg32>(cpu.esp + 28);
        cpu.esp += 32;
    }
    // 004bc169  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc16a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4bc170(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bc170);
    // 004bc170  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bc171  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004bc175  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bc176  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004bc17a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bc17b  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004bc180  e8b35a0000             -call 0x4c1c38
    cpu.esp -= 4;
    sub_4c1c38(app, cpu);
    if (cpu.terminate) return;
    // 004bc185  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc186  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4bc190(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bc190);
    // 004bc190  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bc191  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004bc193  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004bc197  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004bc19b  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 004bc1a1  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004bc1a5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bc1a6  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004bc1a8  e8575b0000             -call 0x4c1d04
    cpu.esp -= 4;
    sub_4c1d04(app, cpu);
    if (cpu.terminate) return;
    // 004bc1ad  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc1ae  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4bc1c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bc1c0);
    // 004bc1c0  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004bc1c4  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004bc1c8  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 004bc1ce  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004bc1d3  e8845c0000             -call 0x4c1e5c
    cpu.esp -= 4;
    sub_4c1e5c(app, cpu);
    if (cpu.terminate) return;
    // 004bc1d8  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4bc1e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bc1e0);
    // 004bc1e0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bc1e1  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004bc1e5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bc1e6  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004bc1ea  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bc1eb  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 004bc1f0  e8435a0000             -call 0x4c1c38
    cpu.esp -= 4;
    sub_4c1c38(app, cpu);
    if (cpu.terminate) return;
    // 004bc1f5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc1f6  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4bc200(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bc200);
    // 004bc200  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bc201  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004bc203  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004bc207  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004bc20b  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 004bc211  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004bc215  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bc216  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004bc218  e8e75a0000             -call 0x4c1d04
    cpu.esp -= 4;
    sub_4c1d04(app, cpu);
    if (cpu.terminate) return;
    // 004bc21d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc21e  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4bc230(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bc230);
    // 004bc230  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004bc234  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004bc238  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 004bc23e  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 004bc243  e8145c0000             -call 0x4c1e5c
    cpu.esp -= 4;
    sub_4c1e5c(app, cpu);
    if (cpu.terminate) return;
    // 004bc248  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4bc250(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bc250);
    // 004bc250  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bc253  b880ffffff             -mov eax, 0xffffff80
    cpu.eax = 4294967168 /*0xffffff80*/;
    // 004bc258  dd056c1d4d00           -fld qword ptr [0x4d1d6c]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(5053804) /* 0x4d1d6c */)));
L_0x004bc25e:
    // 004bc25e  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004bc261  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004bc263  db0424                 -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 004bc266  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004bc268  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 004bc26a  40                     -inc eax
    (cpu.eax)++;
    // 004bc26b  d91c95e4a45b00         -fstp dword ptr [edx*4 + 0x5ba4e4]
    app->getMemory<float>(x86::reg32(6005988) /* 0x5ba4e4 */ + cpu.edx * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bc272  83f87f                 +cmp eax, 0x7f
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
    // 004bc275  7ee7                   -jle 0x4bc25e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bc25e;
    }
    // 004bc277  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004bc279  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bc27c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_4bc280(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bc280);
    // 004bc280  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bc281  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004bc285  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bc286  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004bc28a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bc28b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004bc28d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004bc28f  e8d85c0000             -call 0x4c1f6c
    cpu.esp -= 4;
    sub_4c1f6c(app, cpu);
    if (cpu.terminate) return;
    // 004bc294  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc295  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4bc2a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bc2a0);
    // 004bc2a0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bc2a1  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004bc2a3  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004bc2a7  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004bc2ab  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 004bc2b1  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004bc2b5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bc2b6  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004bc2b8  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004bc2ba  e8815d0000             -call 0x4c2040
    cpu.esp -= 4;
    sub_4c2040(app, cpu);
    if (cpu.terminate) return;
    // 004bc2bf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc2c0  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4bc2d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bc2d0);
    // 004bc2d0  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004bc2d4  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004bc2d8  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004bc2da  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 004bc2e0  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004bc2e2  e8e55e0000             -call 0x4c21cc
    cpu.esp -= 4;
    sub_4c21cc(app, cpu);
    if (cpu.terminate) return;
    // 004bc2e7  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4bc2f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bc2f0);
    // 004bc2f0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bc2f1  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004bc2f5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bc2f6  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004bc2fa  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bc2fb  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004bc2fd  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004bc2ff  e8685c0000             -call 0x4c1f6c
    cpu.esp -= 4;
    sub_4c1f6c(app, cpu);
    if (cpu.terminate) return;
    // 004bc304  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc305  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4bc310(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bc310);
    // 004bc310  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bc311  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004bc313  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004bc317  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004bc31b  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 004bc321  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004bc325  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bc326  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004bc328  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004bc32a  e8115d0000             -call 0x4c2040
    cpu.esp -= 4;
    sub_4c2040(app, cpu);
    if (cpu.terminate) return;
    // 004bc32f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc330  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4bc340(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bc340);
    // 004bc340  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004bc344  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004bc348  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004bc34d  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 004bc353  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004bc355  e8725e0000             -call 0x4c21cc
    cpu.esp -= 4;
    sub_4c21cc(app, cpu);
    if (cpu.terminate) return;
    // 004bc35a  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_4bc360(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bc360);
    // 004bc360  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bc361  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004bc365  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bc366  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004bc36a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bc36b  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 004bc370  e8c3580000             -call 0x4c1c38
    cpu.esp -= 4;
    sub_4c1c38(app, cpu);
    if (cpu.terminate) return;
    // 004bc375  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc376  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4bc380(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bc380);
    // 004bc380  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bc381  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004bc383  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004bc387  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004bc38b  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 004bc391  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004bc395  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bc396  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004bc398  e867590000             -call 0x4c1d04
    cpu.esp -= 4;
    sub_4c1d04(app, cpu);
    if (cpu.terminate) return;
    // 004bc39d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc39e  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4bc3b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bc3b0);
    // 004bc3b0  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004bc3b4  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004bc3b8  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 004bc3be  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 004bc3c3  e8945a0000             -call 0x4c1e5c
    cpu.esp -= 4;
    sub_4c1e5c(app, cpu);
    if (cpu.terminate) return;
    // 004bc3c8  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4bc3d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bc3d0);
    // 004bc3d0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bc3d1  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004bc3d5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bc3d6  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004bc3da  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bc3db  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 004bc3e0  e853580000             -call 0x4c1c38
    cpu.esp -= 4;
    sub_4c1c38(app, cpu);
    if (cpu.terminate) return;
    // 004bc3e5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc3e6  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4bc3f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bc3f0);
    // 004bc3f0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bc3f1  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004bc3f3  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004bc3f7  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004bc3fb  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 004bc401  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004bc405  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bc406  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 004bc408  e8f7580000             -call 0x4c1d04
    cpu.esp -= 4;
    sub_4c1d04(app, cpu);
    if (cpu.terminate) return;
    // 004bc40d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc40e  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4bc420(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bc420);
    // 004bc420  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004bc424  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004bc428  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 004bc42e  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 004bc433  e8245a0000             -call 0x4c1e5c
    cpu.esp -= 4;
    sub_4c1e5c(app, cpu);
    if (cpu.terminate) return;
    // 004bc438  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4bc440(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bc440);
    // 004bc440  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bc441  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004bc445  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bc446  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004bc44a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bc44b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004bc44d  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004bc452  e8155b0000             -call 0x4c1f6c
    cpu.esp -= 4;
    sub_4c1f6c(app, cpu);
    if (cpu.terminate) return;
    // 004bc457  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc458  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4bc460(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bc460);
    // 004bc460  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bc461  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004bc463  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004bc467  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004bc46b  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 004bc471  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004bc475  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bc476  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004bc478  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004bc47a  e8c15b0000             -call 0x4c2040
    cpu.esp -= 4;
    sub_4c2040(app, cpu);
    if (cpu.terminate) return;
    // 004bc47f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc480  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4bc490(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bc490);
    // 004bc490  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004bc494  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004bc498  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004bc49a  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 004bc4a0  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004bc4a5  e8225d0000             -call 0x4c21cc
    cpu.esp -= 4;
    sub_4c21cc(app, cpu);
    if (cpu.terminate) return;
    // 004bc4aa  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_4bc4b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bc4b0);
    // 004bc4b0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bc4b1  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004bc4b5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bc4b6  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004bc4ba  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bc4bb  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004bc4bd  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004bc4c2  e8a55a0000             -call 0x4c1f6c
    cpu.esp -= 4;
    sub_4c1f6c(app, cpu);
    if (cpu.terminate) return;
    // 004bc4c7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc4c8  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4bc4d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bc4d0);
    // 004bc4d0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bc4d1  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004bc4d3  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004bc4d7  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004bc4db  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 004bc4e1  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004bc4e5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bc4e6  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004bc4e8  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004bc4ea  e8515b0000             -call 0x4c2040
    cpu.esp -= 4;
    sub_4c2040(app, cpu);
    if (cpu.terminate) return;
    // 004bc4ef  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc4f0  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4bc500(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bc500);
    // 004bc500  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004bc504  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004bc508  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004bc50d  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 004bc513  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004bc515  e8b25c0000             -call 0x4c21cc
    cpu.esp -= 4;
    sub_4c21cc(app, cpu);
    if (cpu.terminate) return;
    // 004bc51a  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_4bc520(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bc520);
    // 004bc520  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004bc523  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bc524(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bc524);
    // 004bc524  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bc525  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bc526  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bc527  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bc528  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004bc52a  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004bc52c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004bc52e  8b5718                 -mov edx, dword ptr [edi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    // 004bc531  8b4f14                 -mov ecx, dword ptr [edi + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */);
    // 004bc534  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004bc536  39ca                   +cmp edx, ecx
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
    // 004bc538  7d3e                   -jge 0x4bc578
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bc578;
    }
    // 004bc53a  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004bc53c  89470c                 -mov dword ptr [edi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004bc53f  8b471a                 -mov eax, dword ptr [edi + 0x1a]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(26) /* 0x1a */);
    // 004bc542  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004bc545  39c6                   +cmp esi, eax
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
    // 004bc547  7e39                   -jle 0x4bc582
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bc582;
    }
    // 004bc549  bd02000000             -mov ebp, 2
    cpu.ebp = 2 /*0x2*/;
    // 004bc54e  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004bc550  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004bc552:
    // 004bc552  8b7b1a                 -mov edi, dword ptr [ebx + 0x1a]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(26) /* 0x1a */);
    // 004bc555  c1ff10                 -sar edi, 0x10
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (16 /*0x10*/ % 32));
    // 004bc558  39f8                   +cmp eax, edi
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
    // 004bc55a  0f8d78000000           -jge 0x4bc5d8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bc5d8;
    }
    // 004bc560  8b7b0c                 -mov edi, dword ptr [ebx + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004bc563  668b4a1e               -mov cx, word ptr [edx + 0x1e]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(30) /* 0x1e */);
    // 004bc567  66890f                 -mov word ptr [edi], cx
    app->getMemory<x86::reg16>(cpu.edi) = cpu.cx;
    // 004bc56a  8b7b0c                 -mov edi, dword ptr [ebx + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004bc56d  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004bc570  01ef                   +add edi, ebp
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004bc572  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004bc573  897b0c                 -mov dword ptr [ebx + 0xc], edi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 004bc576  ebda                   -jmp 0x4bc552
    goto L_0x004bc552;
L_0x004bc578:
    // 004bc578  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004bc57d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc57e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc57f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc580  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc581  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bc582:
    // 004bc582  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bc584  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004bc586  7e20                   -jle 0x4bc5a8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bc5a8;
    }
    // 004bc588  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
L_0x004bc58a:
    // 004bc58a  8b7b0c                 -mov edi, dword ptr [ebx + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004bc58d  668b4a1e               -mov cx, word ptr [edx + 0x1e]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(30) /* 0x1e */);
    // 004bc591  66890f                 -mov word ptr [edi], cx
    app->getMemory<x86::reg16>(cpu.edi) = cpu.cx;
    // 004bc594  8b4b0c                 -mov ecx, dword ptr [ebx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004bc597  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004bc59a  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004bc59d  40                     -inc eax
    (cpu.eax)++;
    // 004bc59e  894b0c                 -mov dword ptr [ebx + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004bc5a1  39f0                   +cmp eax, esi
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
    // 004bc5a3  7ce5                   -jl 0x4bc58a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bc58a;
    }
    // 004bc5a5  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x004bc5a8:
    // 004bc5a8  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004bc5aa  8d1400                 -lea edx, [eax + eax]
    cpu.edx = x86::reg32(cpu.eax + cpu.eax * 1);
    // 004bc5ad  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004bc5af  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
L_0x004bc5b1:
    // 004bc5b1  8b4b1a                 -mov ecx, dword ptr [ebx + 0x1a]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(26) /* 0x1a */);
    // 004bc5b4  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004bc5b7  39c8                   +cmp eax, ecx
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
    // 004bc5b9  7d12                   -jge 0x4bc5cd
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bc5cd;
    }
    // 004bc5bb  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004bc5be  47                     -inc edi
    (cpu.edi)++;
    // 004bc5bf  668b4a1e               -mov cx, word ptr [edx + 0x1e]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(30) /* 0x1e */);
    // 004bc5c3  83c202                 +add edx, 2
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
    // 004bc5c6  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004bc5c7  66894e1c               -mov word ptr [esi + 0x1c], cx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.cx;
    // 004bc5cb  ebe4                   -jmp 0x4bc5b1
    goto L_0x004bc5b1;
L_0x004bc5cd:
    // 004bc5cd  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bc5cf  66897b1c               -mov word ptr [ebx + 0x1c], di
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(28) /* 0x1c */) = cpu.di;
    // 004bc5d3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc5d4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc5d5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc5d6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc5d7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bc5d8:
    // 004bc5d8  8b6b14                 -mov ebp, dword ptr [ebx + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 004bc5db  29fe                   -sub esi, edi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004bc5dd  2b6b18                 -sub ebp, dword ptr [ebx + 0x18]
    (cpu.ebp) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */)));
    // 004bc5e0  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004bc5e2  0f8c7b000000           -jl 0x4bc663
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bc663;
    }
L_0x004bc5e8:
    // 004bc5e8  39ee                   +cmp esi, ebp
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
    // 004bc5ea  0f8d77000000           -jge 0x4bc667
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bc667;
    }
    // 004bc5f0  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
L_0x004bc5f2:
    // 004bc5f2  8b5318                 -mov edx, dword ptr [ebx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004bc5f5  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004bc5fc  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004bc5fe  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004bc600  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004bc603  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004bc605  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004bc607  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004bc60c  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004bc60f  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004bc611  8b5310                 -mov edx, dword ptr [ebx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004bc614  893b                   -mov dword ptr [ebx], edi
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edi;
    // 004bc616  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bc618  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bc619  895308                 -mov dword ptr [ebx + 8], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004bc61c  e8df5b0000             -call 0x4c2200
    cpu.esp -= 4;
    sub_4c2200(app, cpu);
    if (cpu.terminate) return;
    // 004bc621  017b18                 -add dword ptr [ebx + 0x18], edi
    (app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */)) += x86::reg32(x86::sreg32(cpu.edi));
    // 004bc624  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004bc626  8b5318                 -mov edx, dword ptr [ebx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004bc629  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004bc62b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bc62e  895318                 -mov dword ptr [ebx + 0x18], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004bc631  39fd                   +cmp ebp, edi
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
    // 004bc633  7536                   -jne 0x4bc66b
    if (!cpu.flags.zf)
    {
        goto L_0x004bc66b;
    }
    // 004bc635  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bc637  8b4b14                 -mov ecx, dword ptr [ebx + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 004bc63a  29fe                   -sub esi, edi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004bc63c  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004bc63e  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004bc640  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004bc642  7e18                   -jle 0x4bc65c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bc65c;
    }
    // 004bc644  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004bc646:
    // 004bc646  8b430c                 -mov eax, dword ptr [ebx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004bc649  668910                 -mov word ptr [eax], dx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.dx;
    // 004bc64c  8b6b0c                 -mov ebp, dword ptr [ebx + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004bc64f  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004bc652  4e                     -dec esi
    (cpu.esi)--;
    // 004bc653  896b0c                 -mov dword ptr [ebx + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 004bc656  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004bc658  7fec                   -jg 0x4bc646
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004bc646;
    }
    // 004bc65a  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x004bc65c:
    // 004bc65c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bc65e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc65f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc660  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc661  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc662  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bc663:
    // 004bc663  31ed                   +xor ebp, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp))));
    // 004bc665  eb81                   -jmp 0x4bc5e8
    goto L_0x004bc5e8;
L_0x004bc667:
    // 004bc667  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004bc669  eb87                   -jmp 0x4bc5f2
    goto L_0x004bc5f2;
L_0x004bc66b:
    // 004bc66b  8b3b                   -mov edi, dword ptr [ebx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx);
    // 004bc66d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bc66f  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bc671  7c0b                   -jl 0x4bc67e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bc67e;
    }
    // 004bc673  6689431c               -mov word ptr [ebx + 0x1c], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(28) /* 0x1c */) = cpu.ax;
    // 004bc677  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bc679  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc67a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc67b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc67c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc67d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bc67e:
    // 004bc67e  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004bc680  8d343f                 -lea esi, [edi + edi]
    cpu.esi = x86::reg32(cpu.edi + cpu.edi * 1);
L_0x004bc683:
    // 004bc683  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004bc686  8b4b0c                 -mov ecx, dword ptr [ebx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004bc689  47                     -inc edi
    (cpu.edi)++;
    // 004bc68a  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004bc68d  668b4c31fe             -mov cx, word ptr [ecx + esi - 2]
    cpu.cx = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(-2) /* -0x2 */ + cpu.esi * 1);
    // 004bc692  40                     -inc eax
    (cpu.eax)++;
    // 004bc693  66894a1c               -mov word ptr [edx + 0x1c], cx
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(28) /* 0x1c */) = cpu.cx;
    // 004bc697  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004bc699  7ce8                   -jl 0x4bc683
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bc683;
    }
    // 004bc69b  6689431c               -mov word ptr [ebx + 0x1c], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(28) /* 0x1c */) = cpu.ax;
    // 004bc69f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bc6a1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc6a2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc6a3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc6a4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc6a5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4bc6a8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bc6a8);
    // 004bc6a8  c7401800000000         -mov dword ptr [eax + 0x18], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 004bc6af  66c7401c0000           -mov word ptr [eax + 0x1c], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 004bc6b5  66c740060000           -mov word ptr [eax + 6], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 004bc6bb  66c740040000           -mov word ptr [eax + 4], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004bc6c1  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004bc6c4  895814                 -mov dword ptr [eax + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 004bc6c7  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004bc6cb  c70024c54b00           -mov dword ptr [eax], 0x4bc524
    app->getMemory<x86::reg32>(cpu.eax) = 4965668 /*0x4bc524*/;
    // 004bc6d1  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004bc6d5  c70020c54b00           -mov dword ptr [eax], 0x4bc520
    app->getMemory<x86::reg32>(cpu.eax) = 4965664 /*0x4bc520*/;
    // 004bc6db  b854000000             -mov eax, 0x54
    cpu.eax = 84 /*0x54*/;
    // 004bc6e0  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4bc6f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bc6f0);
    // 004bc6f0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bc6f1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bc6f2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bc6f3  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004bc6f6  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004bc6f8  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004bc6fc  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004bc6ff  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004bc701  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004bc703  39d8                   +cmp eax, ebx
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
    // 004bc705  7d02                   -jge 0x4bc709
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bc709;
    }
    // 004bc707  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x004bc709:
    // 004bc709  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bc70b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bc70d  7e19                   -jle 0x4bc728
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bc728;
    }
    // 004bc70f  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
L_0x004bc713:
    // 004bc713  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004bc716  668b19                 -mov bx, word ptr [ecx]
    cpu.bx = app->getMemory<x86::reg16>(cpu.ecx);
    // 004bc719  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004bc71c  40                     -inc eax
    (cpu.eax)++;
    // 004bc71d  66895afe               -mov word ptr [edx - 2], bx
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(-2) /* -0x2 */) = cpu.bx;
    // 004bc721  39f8                   +cmp eax, edi
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
    // 004bc723  7cee                   -jl 0x4bc713
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bc713;
    }
    // 004bc725  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x004bc728:
    // 004bc728  39e8                   +cmp eax, ebp
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
    // 004bc72a  7d1c                   -jge 0x4bc748
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bc748;
    }
    // 004bc72c  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004bc730  8d1c00                 -lea ebx, [eax + eax]
    cpu.ebx = x86::reg32(cpu.eax + cpu.eax * 1);
    // 004bc733  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
L_0x004bc735:
    // 004bc735  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004bc738  668b33                 -mov si, word ptr [ebx]
    cpu.si = app->getMemory<x86::reg16>(cpu.ebx);
    // 004bc73b  83c302                 -add ebx, 2
    (cpu.ebx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004bc73e  40                     -inc eax
    (cpu.eax)++;
    // 004bc73f  668971fe               -mov word ptr [ecx - 2], si
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(-2) /* -0x2 */) = cpu.si;
    // 004bc743  39e8                   +cmp eax, ebp
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
    // 004bc745  7cee                   -jl 0x4bc735
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bc735;
    }
    // 004bc747  90                     -nop 
    ;
L_0x004bc748:
    // 004bc748  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004bc74b  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004bc74d  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004bc74f  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004bc752  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc753  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc754  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc755  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4bc758(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bc758);
    // 004bc758  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bc759  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bc75a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bc75b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bc75c  83ec44                 -sub esp, 0x44
    (cpu.esp) -= x86::reg32(x86::sreg32(68 /*0x44*/));
    // 004bc75f  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004bc761  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004bc763  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004bc765  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004bc768  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bc76a  7e55                   -jle 0x4bc7c1
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bc7c1;
    }
    // 004bc76c  8d500c                 -lea edx, [eax + 0xc]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004bc76f  8954243c               -mov dword ptr [esp + 0x3c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.edx;
    // 004bc773  8d6826                 -lea ebp, [eax + 0x26]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(38) /* 0x26 */);
L_0x004bc776:
    // 004bc776  66837e2400             +cmp word ptr [esi + 0x24], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(36) /* 0x24 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004bc77b  755c                   -jne 0x4bc7d9
    if (!cpu.flags.zf)
    {
        goto L_0x004bc7d9;
    }
    // 004bc77d  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004bc780  8b4e20                 -mov ecx, dword ptr [esi + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004bc783  83c01b                 -add eax, 0x1b
    (cpu.eax) += x86::reg32(x86::sreg32(27 /*0x1b*/));
    // 004bc786  39c8                   +cmp eax, ecx
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
    // 004bc788  7d70                   -jge 0x4bc7fa
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bc7fa;
    }
    // 004bc78a  6b56180f               -imul edx, dword ptr [esi + 0x18], 0xf
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */))) * x86::sreg64(x86::sreg32(15 /*0xf*/)));
    // 004bc78e  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004bc793  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bc795  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004bc798  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004bc79a  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004bc79d  c7061c000000           -mov dword ptr [esi], 0x1c
    app->getMemory<x86::reg32>(cpu.esi) = 28 /*0x1c*/;
    // 004bc7a3  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bc7a5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bc7a6  895608                 -mov dword ptr [esi + 8], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004bc7a9  e8525a0000             -call 0x4c2200
    cpu.esp -= 4;
    sub_4c2200(app, cpu);
    if (cpu.terminate) return;
    // 004bc7ae  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004bc7b1  83ef1c                 -sub edi, 0x1c
    (cpu.edi) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004bc7b4  83c21c                 -add edx, 0x1c
    (cpu.edx) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004bc7b7  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bc7ba  895618                 -mov dword ptr [esi + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.edx;
L_0x004bc7bd:
    // 004bc7bd  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bc7bf  7fb5                   -jg 0x4bc776
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004bc776;
    }
L_0x004bc7c1:
    // 004bc7c1  8d043f                 -lea eax, [edi + edi]
    cpu.eax = x86::reg32(cpu.edi + cpu.edi * 1);
    // 004bc7c4  01460c                 -add dword ptr [esi + 0xc], eax
    (app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */)) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bc7c7  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bc7c9  0f8c3f010000           -jl 0x4bc90e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bc90e;
    }
    // 004bc7cf  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bc7d1  83c444                 -add esp, 0x44
    (cpu.esp) += x86::reg32(x86::sreg32(68 /*0x44*/));
    // 004bc7d4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc7d5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc7d6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc7d7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc7d8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bc7d9:
    // 004bc7d9  8b4c243c               -mov ecx, dword ptr [esp + 0x3c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 004bc7dd  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004bc7df  8b4622                 -mov eax, dword ptr [esi + 0x22]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(34) /* 0x22 */);
    // 004bc7e2  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004bc7e4  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004bc7e7  e804ffffff             -call 0x4bc6f0
    cpu.esp -= 4;
    sub_4bc6f0(app, cpu);
    if (cpu.terminate) return;
    // 004bc7ec  668b5e24               -mov bx, word ptr [esi + 0x24]
    cpu.bx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004bc7f0  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004bc7f2  29c7                   +sub edi, eax
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
    // 004bc7f4  66895e24               -mov word ptr [esi + 0x24], bx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.bx;
    // 004bc7f8  ebc3                   -jmp 0x4bc7bd
    goto L_0x004bc7bd;
L_0x004bc7fa:
    // 004bc7fa  6b56180f               -imul edx, dword ptr [esi + 0x18], 0xf
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */))) * x86::sreg64(x86::sreg32(15 /*0xf*/)));
    // 004bc7fe  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004bc801  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004bc806  89442438               -mov dword ptr [esp + 0x38], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 004bc80a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bc80c  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004bc80f  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004bc811  c7061c000000           -mov dword ptr [esi], 0x1c
    app->getMemory<x86::reg32>(cpu.esi) = 28 /*0x1c*/;
    // 004bc817  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004bc81a  896e0c                 -mov dword ptr [esi + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 004bc81d  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bc81f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bc820  895608                 -mov dword ptr [esi + 8], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004bc823  e8d8590000             -call 0x4c2200
    cpu.esp -= 4;
    sub_4c2200(app, cpu);
    if (cpu.terminate) return;
    // 004bc828  8346181c               -add dword ptr [esi + 0x18], 0x1c
    (app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */)) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004bc82c  668b5e20               -mov bx, word ptr [esi + 0x20]
    cpu.bx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004bc830  668b4618               -mov ax, word ptr [esi + 0x18]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004bc834  ba1c000000             -mov edx, 0x1c
    cpu.edx = 28 /*0x1c*/;
    // 004bc839  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004bc83b  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004bc83d  668b8694000000         -mov ax, word ptr [esi + 0x94]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(148) /* 0x94 */);
    // 004bc844  66895624               -mov word ptr [esi + 0x24], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.dx;
    // 004bc848  66894606               -mov word ptr [esi + 6], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */) = cpu.ax;
    // 004bc84c  668b8696000000         -mov ax, word ptr [esi + 0x96]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(150) /* 0x96 */);
    // 004bc853  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004bc855  66894604               -mov word ptr [esi + 4], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.ax;
    // 004bc859  41                     -inc ecx
    (cpu.ecx)++;
    // 004bc85a  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004bc85d  66894e24               -mov word ptr [esi + 0x24], cx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.cx;
    // 004bc861  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004bc863  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004bc868  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004bc86b  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004bc86d  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004bc870  894618                 -mov dword ptr [esi + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004bc873  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004bc876  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004bc878  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004bc87b  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004bc87d  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bc880  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004bc882  0f847a000000           -je 0x4bc902
    if (cpu.flags.zf)
    {
        goto L_0x004bc902;
    }
    // 004bc888  890e                   -mov dword ptr [esi], ecx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ecx;
    // 004bc88a  6b56180f               -imul edx, dword ptr [esi + 0x18], 0xf
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */))) * x86::sreg64(x86::sreg32(15 /*0xf*/)));
    // 004bc88e  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004bc893  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bc895  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004bc898  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004bc89a  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004bc89d  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bc89f  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004bc8a1  895608                 -mov dword ptr [esi + 8], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004bc8a4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bc8a5  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004bc8a8  e853590000             -call 0x4c2200
    cpu.esp -= 4;
    sub_4c2200(app, cpu);
    if (cpu.terminate) return;
    // 004bc8ad  8b5e18                 -mov ebx, dword ptr [esi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004bc8b0  83c31c                 -add ebx, 0x1c
    (cpu.ebx) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004bc8b3  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004bc8b6  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004bc8b8  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bc8bb  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004bc8bd  89442440               -mov dword ptr [esp + 0x40], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.eax;
    // 004bc8c1  b81c000000             -mov eax, 0x1c
    cpu.eax = 28 /*0x1c*/;
    // 004bc8c6  8b4c2440               -mov ecx, dword ptr [esp + 0x40]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 004bc8ca  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004bc8cc  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004bc8ce  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bc8d0  895e18                 -mov dword ptr [esi + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 004bc8d3  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bc8d5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bc8d7  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004bc8d9  7e27                   -jle 0x4bc902
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bc902;
    }
L_0x004bc8db:
    // 004bc8db  8b4e22                 -mov ecx, dword ptr [esi + 0x22]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(34) /* 0x22 */);
    // 004bc8de  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004bc8e1  01c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004bc8e3  8d1c0e                 -lea ebx, [esi + ecx]
    cpu.ebx = x86::reg32(cpu.esi + cpu.ecx * 1);
    // 004bc8e6  668b0a                 -mov cx, word ptr [edx]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx);
    // 004bc8e9  66894b26               -mov word ptr [ebx + 0x26], cx
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(38) /* 0x26 */) = cpu.cx;
    // 004bc8ed  668b5e24               -mov bx, word ptr [esi + 0x24]
    cpu.bx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004bc8f1  43                     -inc ebx
    (cpu.ebx)++;
    // 004bc8f2  40                     -inc eax
    (cpu.eax)++;
    // 004bc8f3  66895e24               -mov word ptr [esi + 0x24], bx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.bx;
    // 004bc8f7  8b5c2440               -mov ebx, dword ptr [esp + 0x40]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 004bc8fb  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004bc8fe  39d8                   +cmp eax, ebx
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
    // 004bc900  7cd9                   -jl 0x4bc8db
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bc8db;
    }
L_0x004bc902:
    // 004bc902  8b442438               -mov eax, dword ptr [esp + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 004bc906  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004bc909  e9affeffff             -jmp 0x4bc7bd
    goto L_0x004bc7bd;
L_0x004bc90e:
    // 004bc90e  8b4622                 -mov eax, dword ptr [esi + 0x22]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(34) /* 0x22 */);
    // 004bc911  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004bc914  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bc916  8b4e0c                 -mov ecx, dword ptr [esi + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004bc919  8d1406                 -lea edx, [esi + eax]
    cpu.edx = x86::reg32(cpu.esi + cpu.eax * 1);
    // 004bc91c  668b01                 -mov ax, word ptr [ecx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx);
    // 004bc91f  66894226               -mov word ptr [edx + 0x26], ax
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(38) /* 0x26 */) = cpu.ax;
    // 004bc923  83460c02               -add dword ptr [esi + 0xc], 2
    (app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */)) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004bc927  668b4e24               -mov cx, word ptr [esi + 0x24]
    cpu.cx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004bc92b  41                     -inc ecx
    (cpu.ecx)++;
    // 004bc92c  47                     -inc edi
    (cpu.edi)++;
    // 004bc92d  66894e24               -mov word ptr [esi + 0x24], cx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.cx;
    // 004bc931  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bc933  7cd9                   -jl 0x4bc90e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bc90e;
    }
    // 004bc935  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bc937  83c444                 -add esp, 0x44
    (cpu.esp) += x86::reg32(x86::sreg32(68 /*0x44*/));
    // 004bc93a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc93b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc93c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc93d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc93e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4bc940(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bc940);
    // 004bc940  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bc941  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bc942  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bc943  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bc944  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004bc947  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004bc94b  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004bc94d  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004bc950  8b5022                 -mov edx, dword ptr [eax + 0x22]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(34) /* 0x22 */);
    // 004bc953  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004bc957  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004bc95a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004bc95c  39ca                   +cmp edx, ecx
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
    // 004bc95e  7d2d                   -jge 0x4bc98d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bc98d;
    }
    // 004bc960  bf02000000             -mov edi, 2
    cpu.edi = 2 /*0x2*/;
    // 004bc965  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004bc967:
    // 004bc967  8b5622                 -mov edx, dword ptr [esi + 0x22]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(34) /* 0x22 */);
    // 004bc96a  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004bc96d  39d3                   +cmp ebx, edx
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
    // 004bc96f  0f8d72000000           -jge 0x4bc9e7
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bc9e7;
    }
    // 004bc975  8b560c                 -mov edx, dword ptr [esi + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004bc978  668b4826               -mov cx, word ptr [eax + 0x26]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(38) /* 0x26 */);
    // 004bc97c  66890a                 -mov word ptr [edx], cx
    app->getMemory<x86::reg16>(cpu.edx) = cpu.cx;
    // 004bc97f  8b6e0c                 -mov ebp, dword ptr [esi + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004bc982  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004bc985  01fd                   +add ebp, edi
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
    // 004bc987  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004bc988  896e0c                 -mov dword ptr [esi + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 004bc98b  ebda                   -jmp 0x4bc967
    goto L_0x004bc967;
L_0x004bc98d:
    // 004bc98d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004bc98f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004bc991  7e21                   -jle 0x4bc9b4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bc9b4;
    }
    // 004bc993  8b6c2404               -mov ebp, dword ptr [esp + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
L_0x004bc997:
    // 004bc997  8b560c                 -mov edx, dword ptr [esi + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004bc99a  668b4826               -mov cx, word ptr [eax + 0x26]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(38) /* 0x26 */);
    // 004bc99e  66890a                 -mov word ptr [edx], cx
    app->getMemory<x86::reg16>(cpu.edx) = cpu.cx;
    // 004bc9a1  8b7e0c                 -mov edi, dword ptr [esi + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004bc9a4  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004bc9a7  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004bc9aa  43                     -inc ebx
    (cpu.ebx)++;
    // 004bc9ab  897e0c                 -mov dword ptr [esi + 0xc], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 004bc9ae  39eb                   +cmp ebx, ebp
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
    // 004bc9b0  7ce5                   -jl 0x4bc997
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bc997;
    }
    // 004bc9b2  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x004bc9b4:
    // 004bc9b4  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004bc9b6  8d141b                 -lea edx, [ebx + ebx]
    cpu.edx = x86::reg32(cpu.ebx + cpu.ebx * 1);
    // 004bc9b9  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004bc9bb  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
L_0x004bc9bd:
    // 004bc9bd  8b4e22                 -mov ecx, dword ptr [esi + 0x22]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(34) /* 0x22 */);
    // 004bc9c0  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004bc9c3  39cb                   +cmp ebx, ecx
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
    // 004bc9c5  7d12                   -jge 0x4bc9d9
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bc9d9;
    }
    // 004bc9c7  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004bc9ca  47                     -inc edi
    (cpu.edi)++;
    // 004bc9cb  668b4a26               -mov cx, word ptr [edx + 0x26]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(38) /* 0x26 */);
    // 004bc9cf  83c202                 +add edx, 2
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
    // 004bc9d2  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004bc9d3  66894824               -mov word ptr [eax + 0x24], cx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(36) /* 0x24 */) = cpu.cx;
    // 004bc9d7  ebe4                   -jmp 0x4bc9bd
    goto L_0x004bc9bd;
L_0x004bc9d9:
    // 004bc9d9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bc9db  66897e24               -mov word ptr [esi + 0x24], di
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.di;
    // 004bc9df  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004bc9e2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc9e3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc9e4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc9e5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bc9e6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bc9e7:
    // 004bc9e7  8b7e1c                 -mov edi, dword ptr [esi + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004bc9ea  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004bc9ed  8b6c2404               -mov ebp, dword ptr [esp + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004bc9f1  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004bc9f3  29d5                   -sub ebp, edx
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004bc9f5  83ef1c                 -sub edi, 0x1c
    (cpu.edi) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004bc9f8  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 004bc9fc  39ef                   +cmp edi, ebp
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
    // 004bc9fe  7e02                   -jle 0x4bca02
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bca02;
    }
    // 004bca00  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
L_0x004bca02:
    // 004bca02  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bca04  0f8cbb000000           -jl 0x4bcac5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bcac5;
    }
L_0x004bca0a:
    // 004bca0a  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004bca0d  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004bca14  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004bca16  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004bca18  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004bca1b  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004bca1d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004bca1f  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004bca24  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004bca27  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004bca29  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004bca2c  893e                   -mov dword ptr [esi], edi
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edi;
    // 004bca2e  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bca30  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bca31  895608                 -mov dword ptr [esi + 8], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004bca34  e8c7570000             -call 0x4c2200
    cpu.esp -= 4;
    sub_4c2200(app, cpu);
    if (cpu.terminate) return;
    // 004bca39  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bca3c  8b4e18                 -mov ecx, dword ptr [esi + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004bca3f  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004bca41  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004bca43  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004bca45  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004bca47  894e18                 -mov dword ptr [esi + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 004bca4a  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004bca4c  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004bca4e  895e18                 -mov dword ptr [esi + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 004bca51  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004bca55  8d0c00                 -lea ecx, [eax + eax]
    cpu.ecx = x86::reg32(cpu.eax + cpu.eax * 1);
    // 004bca58  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004bca5a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004bca5c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004bca5e  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x004bca60:
    // 004bca60  7c6a                   -jl 0x4bcacc
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bcacc;
    }
    // 004bca62  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004bca66  8b6e0c                 -mov ebp, dword ptr [esi + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004bca69  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004bca6b  29d5                   -sub ebp, edx
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004bca6d  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004bca71  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004bca74  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004bca77  66895e24               -mov word ptr [esi + 0x24], bx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.bx;
    // 004bca7b  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004bca7d  896e0c                 -mov dword ptr [esi + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 004bca80  83f81c                 +cmp eax, 0x1c
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
    // 004bca83  7d36                   -jge 0x4bcabb
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bcabb;
    }
    // 004bca85  668b4606               -mov ax, word ptr [esi + 6]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 004bca89  66898694000000         -mov word ptr [esi + 0x94], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(148) /* 0x94 */) = cpu.ax;
    // 004bca90  668b4604               -mov ax, word ptr [esi + 4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004bca94  66898696000000         -mov word ptr [esi + 0x96], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(150) /* 0x96 */) = cpu.ax;
    // 004bca9b  8b8698000000           -mov eax, dword ptr [esi + 0x98]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(152) /* 0x98 */);
    // 004bcaa1  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004bcaa5  c70058c74b00           -mov dword ptr [eax], 0x4bc758
    app->getMemory<x86::reg32>(cpu.eax) = 4966232 /*0x4bc758*/;
    // 004bcaab  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004bcaad  7e0c                   -jle 0x4bcabb
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bcabb;
    }
    // 004bcaaf  8d5e0c                 -lea ebx, [esi + 0xc]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004bcab2  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004bcab4  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004bcab6  e89dfcffff             -call 0x4bc758
    cpu.esp -= 4;
    sub_4bc758(app, cpu);
    if (cpu.terminate) return;
L_0x004bcabb:
    // 004bcabb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bcabd  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004bcac0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcac1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcac2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcac3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcac4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bcac5:
    // 004bcac5  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 004bcac7  e93effffff             -jmp 0x4bca0a
    goto L_0x004bca0a;
L_0x004bcacc:
    // 004bcacc  8d0c16                 -lea ecx, [esi + edx]
    cpu.ecx = x86::reg32(cpu.esi + cpu.edx * 1);
    // 004bcacf  8b6e0c                 -mov ebp, dword ptr [esi + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004bcad2  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004bcad5  668b0c28               -mov cx, word ptr [eax + ebp]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax + cpu.ebp * 1);
    // 004bcad9  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 004bcadc  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004bcadf  66894d26               -mov word ptr [ebp + 0x26], cx
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(38) /* 0x26 */) = cpu.cx;
    // 004bcae3  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004bcae7  43                     -inc ebx
    (cpu.ebx)++;
    // 004bcae8  41                     -inc ecx
    (cpu.ecx)++;
    // 004bcae9  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004bcaec  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 004bcaf0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bcaf2  e969ffffff             -jmp 0x4bca60
    goto L_0x004bca60;
}

/* align: skip 0x90 */
void Application::sub_4bcaf8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bcaf8);
    // 004bcaf8  c7401800000000         -mov dword ptr [eax + 0x18], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 004bcaff  66c740240000           -mov word ptr [eax + 0x24], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 004bcb05  66c740060000           -mov word ptr [eax + 6], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 004bcb0b  66c740040000           -mov word ptr [eax + 4], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004bcb11  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004bcb14  895814                 -mov dword ptr [eax + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 004bcb17  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 004bcb1a  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004bcb1e  895020                 -mov dword ptr [eax + 0x20], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 004bcb21  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004bcb25  899098000000           -mov dword ptr [eax + 0x98], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(152) /* 0x98 */) = cpu.edx;
    // 004bcb2b  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004bcb2f  c70240c94b00           -mov dword ptr [edx], 0x4bc940
    app->getMemory<x86::reg32>(cpu.edx) = 4966720 /*0x4bc940*/;
    // 004bcb35  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004bcb3b  b89c000000             -mov eax, 0x9c
    cpu.eax = 156 /*0x9c*/;
    // 004bcb40  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4bcb50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bcb50);
    // 004bcb50  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bcb51  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bcb52  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bcb53  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004bcb56  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004bcb58  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004bcb5b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004bcb5d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004bcb5f  0f84c8000000           -je 0x4bcc2d
    if (cpu.flags.zf)
    {
        goto L_0x004bcc2d;
    }
    // 004bcb65  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bcb66  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004bcb68  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004bcb6b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bcb6d  0f8ea2000000           -jle 0x4bcc15
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bcc15;
    }
    // 004bcb73  8d500c                 -lea edx, [eax + 0xc]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004bcb76  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004bcb7a  8d501e                 -lea edx, [eax + 0x1e]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(30) /* 0x1e */);
    // 004bcb7d  8d6814                 -lea ebp, [eax + 0x14]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004bcb80  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004bcb83  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004bcb87  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x004bcb8b:
    // 004bcb8b  66837e1c00             +cmp word ptr [esi + 0x1c], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(28) /* 0x1c */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004bcb90  0f85a3000000           -jne 0x4bcc39
    if (!cpu.flags.zf)
    {
        goto L_0x004bcc39;
    }
    // 004bcb96  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004bcb99  8b4e14                 -mov ecx, dword ptr [esi + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004bcb9c  83c01b                 -add eax, 0x1b
    (cpu.eax) += x86::reg32(x86::sreg32(27 /*0x1b*/));
    // 004bcb9f  39c8                   +cmp eax, ecx
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
    // 004bcba1  0f8dbb000000           -jge 0x4bcc62
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bcc62;
    }
    // 004bcba7  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004bcba9  2b5618                 -sub edx, dword ptr [esi + 0x18]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */)));
    // 004bcbac  bb1c000000             -mov ebx, 0x1c
    cpu.ebx = 28 /*0x1c*/;
    // 004bcbb1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bcbb3  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004bcbb6  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004bcbb8  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004bcbbc  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004bcbbf  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004bcbc3  39c7                   +cmp edi, eax
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
    // 004bcbc5  7d11                   -jge 0x4bcbd8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bcbd8;
    }
    // 004bcbc7  8d571b                 -lea edx, [edi + 0x1b]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(27) /* 0x1b */);
    // 004bcbca  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bcbcc  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004bcbcf  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004bcbd1  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004bcbd4  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
L_0x004bcbd8:
    // 004bcbd8  6b56180f               -imul edx, dword ptr [esi + 0x18], 0xf
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */))) * x86::sreg64(x86::sreg32(15 /*0xf*/)));
    // 004bcbdc  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004bcbe0  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 004bcbe2  bb1c000000             -mov ebx, 0x1c
    cpu.ebx = 28 /*0x1c*/;
    // 004bcbe7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bcbe9  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004bcbec  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004bcbee  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004bcbf1  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bcbf3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bcbf4  895608                 -mov dword ptr [esi + 8], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004bcbf7  e804560000             -call 0x4c2200
    cpu.esp -= 4;
    sub_4c2200(app, cpu);
    if (cpu.terminate) return;
    // 004bcbfc  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bcbff  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004bcc02  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004bcc06  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bcc08  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004bcc0a  895618                 -mov dword ptr [esi + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.edx;
L_0x004bcc0d:
    // 004bcc0d  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bcc0f  0f8f76ffffff           -jg 0x4bcb8b
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004bcb8b;
    }
L_0x004bcc15:
    // 004bcc15  8d043f                 -lea eax, [edi + edi]
    cpu.eax = x86::reg32(cpu.edi + cpu.edi * 1);
    // 004bcc18  01460c                 -add dword ptr [esi + 0xc], eax
    (app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */)) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bcc1b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bcc1d  0f8ce8000000           -jl 0x4bcd0b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bcd0b;
    }
    // 004bcc23  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bcc25  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcc26  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004bcc29  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcc2a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcc2b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcc2c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bcc2d:
    // 004bcc2d  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004bcc32  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004bcc35  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcc36  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcc37  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcc38  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bcc39:
    // 004bcc39  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004bcc3d  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004bcc41  8b461a                 -mov eax, dword ptr [esi + 0x1a]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(26) /* 0x1a */);
    // 004bcc44  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004bcc46  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004bcc49  e8a2faffff             -call 0x4bc6f0
    cpu.esp -= 4;
    sub_4bc6f0(app, cpu);
    if (cpu.terminate) return;
    // 004bcc4e  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004bcc52  668b5e1c               -mov bx, word ptr [esi + 0x1c]
    cpu.bx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004bcc56  2b5c2410               -sub ebx, dword ptr [esp + 0x10]
    (cpu.ebx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 004bcc5a  29c7                   +sub edi, eax
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
    // 004bcc5c  66895e1c               -mov word ptr [esi + 0x1c], bx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.bx;
    // 004bcc60  ebab                   -jmp 0x4bcc0d
    goto L_0x004bcc0d;
L_0x004bcc62:
    // 004bcc62  837e1001               +cmp dword ptr [esi + 0x10], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bcc66  744f                   -je 0x4bccb7
    if (cpu.flags.zf)
    {
        goto L_0x004bccb7;
    }
    // 004bcc68  3b4e18                 +cmp ecx, dword ptr [esi + 0x18]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004bcc6b  7e4a                   -jle 0x4bccb7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bccb7;
    }
    // 004bcc6d  6b56180f               -imul edx, dword ptr [esi + 0x18], 0xf
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */))) * x86::sreg64(x86::sreg32(15 /*0xf*/)));
    // 004bcc71  bb1c000000             -mov ebx, 0x1c
    cpu.ebx = 28 /*0x1c*/;
    // 004bcc76  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bcc78  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004bcc7b  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004bcc7d  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004bcc80  c7061c000000           -mov dword ptr [esi], 0x1c
    app->getMemory<x86::reg32>(cpu.esi) = 28 /*0x1c*/;
    // 004bcc86  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bcc88  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bcc89  895608                 -mov dword ptr [esi + 8], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004bcc8c  e86f550000             -call 0x4c2200
    cpu.esp -= 4;
    sub_4c2200(app, cpu);
    if (cpu.terminate) return;
    // 004bcc91  8b5e18                 -mov ebx, dword ptr [esi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004bcc94  83c31c                 -add ebx, 0x1c
    (cpu.ebx) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004bcc97  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004bcc9a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004bcc9c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bcc9f  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004bcca1  ba1c000000             -mov edx, 0x1c
    cpu.edx = 28 /*0x1c*/;
    // 004bcca6  8b4e0c                 -mov ecx, dword ptr [esi + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004bcca9  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004bccab  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bccad  895e18                 -mov dword ptr [esi + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 004bccb0  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004bccb2  29d7                   -sub edi, edx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004bccb4  894e0c                 -mov dword ptr [esi + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.ecx;
L_0x004bccb7:
    // 004bccb7  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004bccbb  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004bccbd  ff15dccf4d00           -call dword ptr [0x4dcfdc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5099484) /* 0x4dcfdc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004bccc3  8b5e10                 -mov ebx, dword ptr [esi + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004bccc6  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004bccc8  7424                   -je 0x4bccee
    if (cpu.flags.zf)
    {
        goto L_0x004bccee;
    }
    // 004bccca  668b13                 -mov dx, word ptr [ebx]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ebx);
    // 004bcccd  66895606               -mov word ptr [esi + 6], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */) = cpu.dx;
    // 004bccd1  668b4302               -mov ax, word ptr [ebx + 2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 004bccd5  66894604               -mov word ptr [esi + 4], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.ax;
    // 004bccd9  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004bccdc  c7461800000000         -mov dword ptr [esi + 0x18], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 004bcce3  83c008                 +add eax, 8
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
    // 004bcce6  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004bcce9  e91fffffff             -jmp 0x4bcc0d
    goto L_0x004bcc0d;
L_0x004bccee:
    // 004bccee  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004bccf1  01ff                   -add edi, edi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edi));
    // 004bccf3  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004bccf5  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004bccf7  e83359fdff             -call 0x49262f
    cpu.esp -= 4;
    sub_49262f(app, cpu);
    if (cpu.terminate) return;
    // 004bccfc  8b560c                 -mov edx, dword ptr [esi + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004bccff  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004bcd01  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 004bcd03  89560c                 -mov dword ptr [esi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004bcd06  e90affffff             -jmp 0x4bcc15
    goto L_0x004bcc15;
L_0x004bcd0b:
    // 004bcd0b  8b561a                 -mov edx, dword ptr [esi + 0x1a]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(26) /* 0x1a */);
    // 004bcd0e  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004bcd11  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004bcd14  668b00                 -mov ax, word ptr [eax]
    cpu.ax = app->getMemory<x86::reg16>(cpu.eax);
    // 004bcd17  668944561e             -mov word ptr [esi + edx*2 + 0x1e], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(30) /* 0x1e */ + cpu.edx * 2) = cpu.ax;
    // 004bcd1c  8b5e0c                 -mov ebx, dword ptr [esi + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004bcd1f  668b4e1c               -mov cx, word ptr [esi + 0x1c]
    cpu.cx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004bcd23  83c302                 -add ebx, 2
    (cpu.ebx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004bcd26  41                     -inc ecx
    (cpu.ecx)++;
    // 004bcd27  895e0c                 -mov dword ptr [esi + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 004bcd2a  47                     -inc edi
    (cpu.edi)++;
    // 004bcd2b  66894e1c               -mov word ptr [esi + 0x1c], cx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.cx;
    // 004bcd2f  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bcd31  7cd8                   -jl 0x4bcd0b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bcd0b;
    }
    // 004bcd33  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bcd35  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcd36  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004bcd39  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcd3a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcd3b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcd3c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4bcd40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bcd40);
    // 004bcd40  c7401001000000         -mov dword ptr [eax + 0x10], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = 1 /*0x1*/;
    // 004bcd47  c7401800000000         -mov dword ptr [eax + 0x18], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 004bcd4e  66c7401c0000           -mov word ptr [eax + 0x1c], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 004bcd54  66c740060000           -mov word ptr [eax + 6], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 004bcd5a  66c740040000           -mov word ptr [eax + 4], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004bcd60  895814                 -mov dword ptr [eax + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 004bcd63  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004bcd67  c70050cb4b00           -mov dword ptr [eax], 0x4bcb50
    app->getMemory<x86::reg32>(cpu.eax) = 4967248 /*0x4bcb50*/;
    // 004bcd6d  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004bcd71  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004bcd77  b854000000             -mov eax, 0x54
    cpu.eax = 84 /*0x54*/;
    // 004bcd7c  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 */
void Application::sub_4bcd80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bcd80);
    // 004bcd80  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004bcd83  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4bcd84(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bcd84);
    // 004bcd84  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bcd85  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bcd86  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bcd87  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bcd88  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bcd8b  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004bcd8d  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004bcd8f  8b481c                 -mov ecx, dword ptr [eax + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004bcd92  8b7818                 -mov edi, dword ptr [eax + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004bcd95  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004bcd97  39f9                   +cmp ecx, edi
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
    // 004bcd99  7d3f                   -jge 0x4bcdda
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bcdda;
    }
    // 004bcd9b  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 004bcd9d  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004bcda0  8b501e                 -mov edx, dword ptr [eax + 0x1e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(30) /* 0x1e */);
    // 004bcda3  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004bcda6  d1fa                   -sar edx, 1
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (1 /*0x1*/ % 32));
    // 004bcda8  39d6                   +cmp esi, edx
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
    // 004bcdaa  7e3b                   -jle 0x4bcde7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bcde7;
    }
    // 004bcdac  bf02000000             -mov edi, 2
    cpu.edi = 2 /*0x2*/;
    // 004bcdb1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004bcdb3:
    // 004bcdb3  8b4b1e                 -mov ecx, dword ptr [ebx + 0x1e]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(30) /* 0x1e */);
    // 004bcdb6  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004bcdb9  39ca                   +cmp edx, ecx
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
    // 004bcdbb  0f8d8a000000           -jge 0x4bce4b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bce4b;
    }
    // 004bcdc1  8b6b10                 -mov ebp, dword ptr [ebx + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004bcdc4  668b4824               -mov cx, word ptr [eax + 0x24]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 004bcdc8  66894d00               -mov word ptr [ebp], cx
    app->getMemory<x86::reg16>(cpu.ebp) = cpu.cx;
    // 004bcdcc  8b4b10                 -mov ecx, dword ptr [ebx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004bcdcf  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004bcdd2  01f9                   +add ecx, edi
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
    // 004bcdd4  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004bcdd5  894b10                 -mov dword ptr [ebx + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004bcdd8  ebd9                   -jmp 0x4bcdb3
    goto L_0x004bcdb3;
L_0x004bcdda:
    // 004bcdda  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004bcddf  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bcde2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcde3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcde4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcde5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcde6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bcde7:
    // 004bcde7  01f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 004bcde9  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004bcdeb  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004bcded  7e1d                   -jle 0x4bce0c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bce0c;
    }
L_0x004bcdef:
    // 004bcdef  8b4b10                 -mov ecx, dword ptr [ebx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004bcdf2  668b7824               -mov di, word ptr [eax + 0x24]
    cpu.di = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 004bcdf6  668939                 -mov word ptr [ecx], di
    app->getMemory<x86::reg16>(cpu.ecx) = cpu.di;
    // 004bcdf9  8b6b10                 -mov ebp, dword ptr [ebx + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004bcdfc  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004bcdff  83c502                 -add ebp, 2
    (cpu.ebp) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004bce02  42                     -inc edx
    (cpu.edx)++;
    // 004bce03  896b10                 -mov dword ptr [ebx + 0x10], ebp
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.ebp;
    // 004bce06  39f2                   +cmp edx, esi
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
    // 004bce08  7ce5                   -jl 0x4bcdef
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bcdef;
    }
    // 004bce0a  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x004bce0c:
    // 004bce0c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bce0e  8d3412                 -lea esi, [edx + edx]
    cpu.esi = x86::reg32(cpu.edx + cpu.edx * 1);
    // 004bce11  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004bce14  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004bce16  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x004bce18:
    // 004bce18  8b4b1e                 -mov ecx, dword ptr [ebx + 0x1e]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(30) /* 0x1e */);
    // 004bce1b  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004bce1e  39ca                   +cmp edx, ecx
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
    // 004bce20  7d18                   -jge 0x4bce3a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bce3a;
    }
    // 004bce22  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004bce25  668b4e24               -mov cx, word ptr [esi + 0x24]
    cpu.cx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004bce29  66894822               -mov word ptr [eax + 0x22], cx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(34) /* 0x22 */) = cpu.cx;
    // 004bce2d  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 004bce30  83c602                 +add esi, 2
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
    // 004bce33  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004bce34  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004bce35  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004bce38  ebde                   -jmp 0x4bce18
    goto L_0x004bce18;
L_0x004bce3a:
    // 004bce3a  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004bce3d  66894320               -mov word ptr [ebx + 0x20], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.ax;
    // 004bce41  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bce43  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bce46  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bce47  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bce48  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bce49  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bce4a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bce4b:
    // 004bce4b  8b6b18                 -mov ebp, dword ptr [ebx + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004bce4e  8b431c                 -mov eax, dword ptr [ebx + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */);
    // 004bce51  d1f9                   -sar ecx, 1
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (1 /*0x1*/ % 32));
    // 004bce53  29c5                   -sub ebp, eax
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004bce55  29ce                   -sub esi, ecx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004bce57  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004bce59  0f8c87000000           -jl 0x4bcee6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bcee6;
    }
L_0x004bce5f:
    // 004bce5f  39ee                   +cmp esi, ebp
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
    // 004bce61  0f8d86000000           -jge 0x4bceed
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bceed;
    }
    // 004bce67  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
L_0x004bce6a:
    // 004bce6a  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004bce6d  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004bce6f  8b431c                 -mov eax, dword ptr [ebx + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */);
    // 004bce72  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bce74  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004bce76  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004bce79  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004bce7b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004bce7d  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004bce82  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004bce85  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004bce87  8b5314                 -mov edx, dword ptr [ebx + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 004bce8a  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bce8c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004bce8d  89530c                 -mov dword ptr [ebx + 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004bce90  e85b540000             -call 0x4c22f0
    cpu.esp -= 4;
    sub_4c22f0(app, cpu);
    if (cpu.terminate) return;
    // 004bce95  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bce98  8b531c                 -mov edx, dword ptr [ebx + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */);
    // 004bce9b  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004bce9e  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bcea0  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004bcea2  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004bcea4  89531c                 -mov dword ptr [ebx + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004bcea7  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004bcea9  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 004bceac  894b1c                 -mov dword ptr [ebx + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 004bceaf  39fd                   +cmp ebp, edi
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
    // 004bceb1  7542                   -jne 0x4bcef5
    if (!cpu.flags.zf)
    {
        goto L_0x004bcef5;
    }
    // 004bceb3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004bceb5  8b5318                 -mov edx, dword ptr [ebx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    // 004bceb8  29fe                   -sub esi, edi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004bceba  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004bcebc  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004bcebe  01f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 004bcec0  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004bcec2  7e18                   -jle 0x4bcedc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bcedc;
    }
    // 004bcec4  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004bcec6:
    // 004bcec6  8b4310                 -mov eax, dword ptr [ebx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004bcec9  668910                 -mov word ptr [eax], dx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.dx;
    // 004bcecc  8b7b10                 -mov edi, dword ptr [ebx + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004bcecf  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004bced2  4e                     -dec esi
    (cpu.esi)--;
    // 004bced3  897b10                 -mov dword ptr [ebx + 0x10], edi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.edi;
    // 004bced6  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004bced8  7fec                   -jg 0x4bcec6
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004bcec6;
    }
    // 004bceda  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x004bcedc:
    // 004bcedc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bcede  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bcee1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcee2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcee3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcee4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcee5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bcee6:
    // 004bcee6  31ed                   +xor ebp, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp))));
    // 004bcee8  e972ffffff             -jmp 0x4bce5f
    goto L_0x004bce5f;
L_0x004bceed:
    // 004bceed  892c24                 -mov dword ptr [esp], ebp
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 004bcef0  e975ffffff             -jmp 0x4bce6a
    goto L_0x004bce6a;
L_0x004bcef5:
    // 004bcef5  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004bcefa  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004bcefc  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004bcefe  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004bcf01  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004bcf03  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004bcf05  29d6                   -sub esi, edx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004bcf07  6bf6ff                 -imul esi, esi, -1
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(-1 /*-0x1*/)));
    // 004bcf0a  83fee4                 +cmp esi, -0x1c
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
    // 004bcf0d  7502                   -jne 0x4bcf11
    if (!cpu.flags.zf)
    {
        goto L_0x004bcf11;
    }
    // 004bcf0f  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x004bcf11:
    // 004bcf11  01f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 004bcf13  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004bcf15  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004bcf17  7c0e                   -jl 0x4bcf27
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bcf27;
    }
    // 004bcf19  66895320               -mov word ptr [ebx + 0x20], dx
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.dx;
    // 004bcf1d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bcf1f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bcf22  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcf23  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcf24  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcf25  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcf26  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bcf27:
    // 004bcf27  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004bcf29  8d0436                 -lea eax, [esi + esi]
    cpu.eax = x86::reg32(cpu.esi + cpu.esi * 1);
L_0x004bcf2c:
    // 004bcf2c  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004bcf2f  8b6b10                 -mov ebp, dword ptr [ebx + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004bcf32  46                     -inc esi
    (cpu.esi)++;
    // 004bcf33  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004bcf36  668b7c28fe             -mov di, word ptr [eax + ebp - 2]
    cpu.di = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(-2) /* -0x2 */ + cpu.ebp * 1);
    // 004bcf3b  42                     -inc edx
    (cpu.edx)++;
    // 004bcf3c  66897922               -mov word ptr [ecx + 0x22], di
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(34) /* 0x22 */) = cpu.di;
    // 004bcf40  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004bcf42  7ce8                   -jl 0x4bcf2c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bcf2c;
    }
    // 004bcf44  66895320               -mov word ptr [ebx + 0x20], dx
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.dx;
    // 004bcf48  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bcf4a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bcf4d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcf4e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcf4f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcf50  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bcf51  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4bcf54(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bcf54);
    // 004bcf54  c7401c00000000         -mov dword ptr [eax + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 004bcf5b  66c740200000           -mov word ptr [eax + 0x20], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 004bcf61  66c740060000           -mov word ptr [eax + 6], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 004bcf67  66c740040000           -mov word ptr [eax + 4], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004bcf6d  66c7400a0000           -mov word ptr [eax + 0xa], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(10) /* 0xa */) = 0 /*0x0*/;
    // 004bcf73  66c740080000           -mov word ptr [eax + 8], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004bcf79  895014                 -mov dword ptr [eax + 0x14], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004bcf7c  895818                 -mov dword ptr [eax + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 004bcf7f  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004bcf83  c70084cd4b00           -mov dword ptr [eax], 0x4bcd84
    app->getMemory<x86::reg32>(cpu.eax) = 4967812 /*0x4bcd84*/;
    // 004bcf89  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004bcf8d  c70080cd4b00           -mov dword ptr [eax], 0x4bcd80
    app->getMemory<x86::reg32>(cpu.eax) = 4967808 /*0x4bcd80*/;
    // 004bcf93  b890000000             -mov eax, 0x90
    cpu.eax = 144 /*0x90*/;
    // 004bcf98  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4bcfa0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bcfa0);
    // 004bcfa0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bcfa1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bcfa2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bcfa3  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004bcfa6  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004bcfa8  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004bcfac  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004bcfaf  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004bcfb1  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004bcfb3  39d8                   +cmp eax, ebx
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
    // 004bcfb5  7d02                   -jge 0x4bcfb9
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bcfb9;
    }
    // 004bcfb7  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x004bcfb9:
    // 004bcfb9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bcfbb  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bcfbd  7e21                   -jle 0x4bcfe0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bcfe0;
    }
    // 004bcfbf  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
L_0x004bcfc3:
    // 004bcfc3  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004bcfc6  668b19                 -mov bx, word ptr [ecx]
    cpu.bx = app->getMemory<x86::reg16>(cpu.ecx);
    // 004bcfc9  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bcfcc  66895afe               -mov word ptr [edx - 2], bx
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(-2) /* -0x2 */) = cpu.bx;
    // 004bcfd0  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004bcfd3  668b59fe               -mov bx, word ptr [ecx - 2]
    cpu.bx = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(-2) /* -0x2 */);
    // 004bcfd7  40                     -inc eax
    (cpu.eax)++;
    // 004bcfd8  66895afe               -mov word ptr [edx - 2], bx
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(-2) /* -0x2 */) = cpu.bx;
    // 004bcfdc  39f8                   +cmp eax, edi
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
    // 004bcfde  7ce3                   -jl 0x4bcfc3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bcfc3;
    }
L_0x004bcfe0:
    // 004bcfe0  39e8                   +cmp eax, ebp
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
    // 004bcfe2  7d28                   -jge 0x4bd00c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bd00c;
    }
    // 004bcfe4  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004bcfe8  8d1c8500000000         -lea ebx, [eax*4]
    cpu.ebx = x86::reg32(cpu.eax * 4);
    // 004bcfef  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
L_0x004bcff1:
    // 004bcff1  668b33                 -mov si, word ptr [ebx]
    cpu.si = app->getMemory<x86::reg16>(cpu.ebx);
    // 004bcff4  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bcff7  668931                 -mov word ptr [ecx], si
    app->getMemory<x86::reg16>(cpu.ecx) = cpu.si;
    // 004bcffa  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bcffd  668b73fe               -mov si, word ptr [ebx - 2]
    cpu.si = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(-2) /* -0x2 */);
    // 004bd001  40                     -inc eax
    (cpu.eax)++;
    // 004bd002  668971fe               -mov word ptr [ecx - 2], si
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(-2) /* -0x2 */) = cpu.si;
    // 004bd006  39e8                   +cmp eax, ebp
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
    // 004bd008  7ce7                   -jl 0x4bcff1
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bcff1;
    }
    // 004bd00a  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x004bd00c:
    // 004bd00c  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004bd00f  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004bd011  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004bd013  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004bd016  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd017  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd018  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd019  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4bd01c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004bd01c);
    // 004bd01c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004bd01d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bd01e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004bd01f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004bd020  83ec7c                 -sub esp, 0x7c
    (cpu.esp) -= x86::reg32(x86::sreg32(124 /*0x7c*/));
    // 004bd023  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004bd025  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004bd027  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004bd029  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004bd02c  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bd02e  7e59                   -jle 0x4bd089
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bd089;
    }
    // 004bd030  8d5010                 -lea edx, [eax + 0x10]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004bd033  89542474               -mov dword ptr [esp + 0x74], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */) = cpu.edx;
    // 004bd037  8d682c                 -lea ebp, [eax + 0x2c]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(44) /* 0x2c */);
L_0x004bd03a:
    // 004bd03a  66837e2800             +cmp word ptr [esi + 0x28], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(40) /* 0x28 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004bd03f  7564                   -jne 0x4bd0a5
    if (!cpu.flags.zf)
    {
        goto L_0x004bd0a5;
    }
    // 004bd041  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004bd044  8b4e24                 -mov ecx, dword ptr [esi + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004bd047  83c01b                 -add eax, 0x1b
    (cpu.eax) += x86::reg32(x86::sreg32(27 /*0x1b*/));
    // 004bd04a  39c8                   +cmp eax, ecx
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
    // 004bd04c  0f8d74000000           -jge 0x4bd0c6
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004bd0c6;
    }
    // 004bd052  6b561c1e               -imul edx, dword ptr [esi + 0x1c], 0x1e
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */))) * x86::sreg64(x86::sreg32(30 /*0x1e*/)));
    // 004bd056  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004bd05b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bd05d  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004bd060  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004bd062  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004bd065  c7061c000000           -mov dword ptr [esi], 0x1c
    app->getMemory<x86::reg32>(cpu.esi) = 28 /*0x1c*/;
    // 004bd06b  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bd06d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bd06e  89560c                 -mov dword ptr [esi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004bd071  e87a520000             -call 0x4c22f0
    cpu.esp -= 4;
    sub_4c22f0(app, cpu);
    if (cpu.terminate) return;
    // 004bd076  8b461c                 -mov eax, dword ptr [esi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004bd079  83ef1c                 -sub edi, 0x1c
    (cpu.edi) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004bd07c  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004bd07f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bd082  89461c                 -mov dword ptr [esi + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.eax;
L_0x004bd085:
    // 004bd085  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bd087  7fb1                   -jg 0x4bd03a
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004bd03a;
    }
L_0x004bd089:
    // 004bd089  8d04bd00000000         -lea eax, [edi*4]
    cpu.eax = x86::reg32(cpu.edi * 4);
    // 004bd090  014610                 -add dword ptr [esi + 0x10], eax
    (app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */)) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bd093  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bd095  0f8c63010000           -jl 0x4bd1fe
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bd1fe;
    }
    // 004bd09b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bd09d  83c47c                 -add esp, 0x7c
    (cpu.esp) += x86::reg32(x86::sreg32(124 /*0x7c*/));
    // 004bd0a0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd0a1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd0a2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd0a3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd0a4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004bd0a5:
    // 004bd0a5  8b4c2474               -mov ecx, dword ptr [esp + 0x74]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 004bd0a9  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004bd0ab  8b4626                 -mov eax, dword ptr [esi + 0x26]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(38) /* 0x26 */);
    // 004bd0ae  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004bd0b0  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004bd0b3  e8e8feffff             -call 0x4bcfa0
    cpu.esp -= 4;
    sub_4bcfa0(app, cpu);
    if (cpu.terminate) return;
    // 004bd0b8  668b5e28               -mov bx, word ptr [esi + 0x28]
    cpu.bx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004bd0bc  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004bd0be  29c7                   +sub edi, eax
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
    // 004bd0c0  66895e28               -mov word ptr [esi + 0x28], bx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.bx;
    // 004bd0c4  ebbf                   -jmp 0x4bd085
    goto L_0x004bd085;
L_0x004bd0c6:
    // 004bd0c6  6b561c1e               -imul edx, dword ptr [esi + 0x1c], 0x1e
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */))) * x86::sreg64(x86::sreg32(30 /*0x1e*/)));
    // 004bd0ca  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004bd0cd  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004bd0d2  89442470               -mov dword ptr [esp + 0x70], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */) = cpu.eax;
    // 004bd0d6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bd0d8  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004bd0db  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004bd0dd  c7061c000000           -mov dword ptr [esi], 0x1c
    app->getMemory<x86::reg32>(cpu.esi) = 28 /*0x1c*/;
    // 004bd0e3  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004bd0e6  896e10                 -mov dword ptr [esi + 0x10], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ebp;
    // 004bd0e9  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bd0eb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bd0ec  89560c                 -mov dword ptr [esi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004bd0ef  e8fc510000             -call 0x4c22f0
    cpu.esp -= 4;
    sub_4c22f0(app, cpu);
    if (cpu.terminate) return;
    // 004bd0f4  83461c1c               -add dword ptr [esi + 0x1c], 0x1c
    (app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */)) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004bd0f8  668b5e24               -mov bx, word ptr [esi + 0x24]
    cpu.bx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 004bd0fc  668b461c               -mov ax, word ptr [esi + 0x1c]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004bd100  ba1c000000             -mov edx, 0x1c
    cpu.edx = 28 /*0x1c*/;
    // 004bd105  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004bd107  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004bd109  668b8608010000         -mov ax, word ptr [esi + 0x108]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(264) /* 0x108 */);
    // 004bd110  66895628               -mov word ptr [esi + 0x28], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.dx;
    // 004bd114  66894606               -mov word ptr [esi + 6], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */) = cpu.ax;
    // 004bd118  668b860a010000         -mov ax, word ptr [esi + 0x10a]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(266) /* 0x10a */);
    // 004bd11f  66894604               -mov word ptr [esi + 4], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.ax;
    // 004bd123  668b860c010000         -mov ax, word ptr [esi + 0x10c]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(268) /* 0x10c */);
    // 004bd12a  6689460a               -mov word ptr [esi + 0xa], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(10) /* 0xa */) = cpu.ax;
    // 004bd12e  668b860e010000         -mov ax, word ptr [esi + 0x10e]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(270) /* 0x10e */);
    // 004bd135  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004bd137  66894608               -mov word ptr [esi + 8], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.ax;
    // 004bd13b  41                     -inc ecx
    (cpu.ecx)++;
    // 004bd13c  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004bd13f  66894e28               -mov word ptr [esi + 0x28], cx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.cx;
    // 004bd143  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004bd145  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004bd14a  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004bd14d  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004bd14f  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004bd152  89461c                 -mov dword ptr [esi + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004bd155  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004bd158  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004bd15a  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004bd15d  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004bd15f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bd162  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004bd164  0f8488000000           -je 0x4bd1f2
    if (cpu.flags.zf)
    {
        goto L_0x004bd1f2;
    }
    // 004bd16a  890e                   -mov dword ptr [esi], ecx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ecx;
    // 004bd16c  6b561c1e               -imul edx, dword ptr [esi + 0x1c], 0x1e
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */))) * x86::sreg64(x86::sreg32(30 /*0x1e*/)));
    // 004bd170  b91c000000             -mov ecx, 0x1c
    cpu.ecx = 28 /*0x1c*/;
    // 004bd175  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004bd177  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004bd17a  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004bd17c  8b5614                 -mov edx, dword ptr [esi + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004bd17f  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bd181  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004bd183  89560c                 -mov dword ptr [esi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004bd186  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004bd187  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004bd18a  e861510000             -call 0x4c22f0
    cpu.esp -= 4;
    sub_4c22f0(app, cpu);
    if (cpu.terminate) return;
    // 004bd18f  8b5e1c                 -mov ebx, dword ptr [esi + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004bd192  83c31c                 -add ebx, 0x1c
    (cpu.ebx) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004bd195  8b5620                 -mov edx, dword ptr [esi + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004bd198  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004bd19a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bd19d  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004bd19f  ba38000000             -mov edx, 0x38
    cpu.edx = 56 /*0x38*/;
    // 004bd1a4  89442478               -mov dword ptr [esp + 0x78], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */) = cpu.eax;
    // 004bd1a8  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004bd1aa  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004bd1ac  8d0412                 -lea eax, [edx + edx]
    cpu.eax = x86::reg32(cpu.edx + cpu.edx * 1);
    // 004bd1af  895e1c                 -mov dword ptr [esi + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 004bd1b2  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004bd1b4  8b4c2478               -mov ecx, dword ptr [esp + 0x78]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 004bd1b8  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004bd1ba  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004bd1bc  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004bd1be  7e32                   -jle 0x4bd1f2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004bd1f2;
    }
L_0x004bd1c0:
    // 004bd1c0  8b4e26                 -mov ecx, dword ptr [esi + 0x26]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(38) /* 0x26 */);
    // 004bd1c3  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004bd1c6  668b18                 -mov bx, word ptr [eax]
    cpu.bx = app->getMemory<x86::reg16>(cpu.eax);
    // 004bd1c9  66895c8e2c             -mov word ptr [esi + ecx*4 + 0x2c], bx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(44) /* 0x2c */ + cpu.ecx * 4) = cpu.bx;
    // 004bd1ce  8b4e26                 -mov ecx, dword ptr [esi + 0x26]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(38) /* 0x26 */);
    // 004bd1d1  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004bd1d4  668b5802               -mov bx, word ptr [eax + 2]
    cpu.bx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 004bd1d8  66895c8e2e             -mov word ptr [esi + ecx*4 + 0x2e], bx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(46) /* 0x2e */ + cpu.ecx * 4) = cpu.bx;
    // 004bd1dd  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bd1e0  668b5e28               -mov bx, word ptr [esi + 0x28]
    cpu.bx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004bd1e4  42                     -inc edx
    (cpu.edx)++;
    // 004bd1e5  43                     -inc ebx
    (cpu.ebx)++;
    // 004bd1e6  8b4c2478               -mov ecx, dword ptr [esp + 0x78]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 004bd1ea  66895e28               -mov word ptr [esi + 0x28], bx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.bx;
    // 004bd1ee  39ca                   +cmp edx, ecx
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
    // 004bd1f0  7cce                   -jl 0x4bd1c0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bd1c0;
    }
L_0x004bd1f2:
    // 004bd1f2  8b442470               -mov eax, dword ptr [esp + 0x70]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */);
    // 004bd1f6  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004bd1f9  e987feffff             -jmp 0x4bd085
    goto L_0x004bd085;
L_0x004bd1fe:
    // 004bd1fe  8b4626                 -mov eax, dword ptr [esi + 0x26]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(38) /* 0x26 */);
    // 004bd201  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004bd204  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004bd207  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004bd20a  8d0c06                 -lea ecx, [esi + eax]
    cpu.ecx = x86::reg32(cpu.esi + cpu.eax * 1);
    // 004bd20d  668b02                 -mov ax, word ptr [edx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edx);
    // 004bd210  6689412c               -mov word ptr [ecx + 0x2c], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(44) /* 0x2c */) = cpu.ax;
    // 004bd214  8b4626                 -mov eax, dword ptr [esi + 0x26]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(38) /* 0x26 */);
    // 004bd217  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004bd21a  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004bd21d  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004bd220  8d0c06                 -lea ecx, [esi + eax]
    cpu.ecx = x86::reg32(cpu.esi + cpu.eax * 1);
    // 004bd223  668b4202               -mov ax, word ptr [edx + 2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 004bd227  6689412e               -mov word ptr [ecx + 0x2e], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(46) /* 0x2e */) = cpu.ax;
    // 004bd22b  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004bd22e  668b4e28               -mov cx, word ptr [esi + 0x28]
    cpu.cx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004bd232  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004bd235  41                     -inc ecx
    (cpu.ecx)++;
    // 004bd236  895610                 -mov dword ptr [esi + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004bd239  47                     -inc edi
    (cpu.edi)++;
    // 004bd23a  66894e28               -mov word ptr [esi + 0x28], cx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.cx;
    // 004bd23e  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004bd240  7cbc                   -jl 0x4bd1fe
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004bd1fe;
    }
    // 004bd242  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004bd244  83c47c                 -add esp, 0x7c
    (cpu.esp) += x86::reg32(x86::sreg32(124 /*0x7c*/));
    // 004bd247  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd248  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd249  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd24a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004bd24b  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
