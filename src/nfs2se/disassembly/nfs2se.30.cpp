#include "nfs2se.h"
#include <lib/thread.h>

namespace nfs2se
{

/* align: skip  */
void Application::sub_4a819e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a819e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a819f  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a81a1  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004a81a2  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a81a5  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a81a8  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004a81ab  d94604                 -fld dword ptr [esi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 004a81ae  d906                   -fld dword ptr [esi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi)));
    // 004a81b0  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004a81b3  83f901                 +cmp ecx, 1
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
    // 004a81b6  7e46                   -jle 0x4a81fe
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a81fe;
    }
    // 004a81b8  83e901                 -sub ecx, 1
    (cpu.ecx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004a81bb:
    // 004a81bb  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004a81bd  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004a81bf  d94704                 -fld dword ptr [edi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 004a81c2  d8cb                   -fmul st(3)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(3));
    // 004a81c4  d94708                 -fld dword ptr [edi + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(8) /* 0x8 */)));
    // 004a81c7  d8cb                   -fmul st(3)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(3));
    // 004a81c9  d9470c                 -fld dword ptr [edi + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(12) /* 0xc */)));
    // 004a81cc  d8cd                   -fmul st(5)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(5));
    // 004a81ce  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004a81d0  d84500                 -fadd dword ptr [ebp]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp));
    // 004a81d3  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004a81d5  d84504                 -fadd dword ptr [ebp + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */));
    // 004a81d8  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a81da  d84508                 -fadd dword ptr [ebp + 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */));
    // 004a81dd  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004a81df  d8450c                 -fadd dword ptr [ebp + 0xc]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */));
    // 004a81e2  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004a81e4  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a81e7  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a81ea  d95d0c                 -fstp dword ptr [ebp + 0xc]
    app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a81ed  d95d08                 -fstp dword ptr [ebp + 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a81f0  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a81f3  83c510                 -add ebp, 0x10
    (cpu.ebp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a81f6  83e902                 +sub ecx, 2
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
    // 004a81f9  7fc0                   -jg 0x4a81bb
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a81bb;
    }
    // 004a81fb  83c101                 -add ecx, 1
    (cpu.ecx) += x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004a81fe:
    // 004a81fe  83f900                 +cmp ecx, 0
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
    // 004a8201  7e26                   -jle 0x4a8229
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a8229;
    }
    // 004a8203  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004a8205  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004a8207  d94704                 -fld dword ptr [edi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 004a820a  d8cb                   -fmul st(3)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(3));
    // 004a820c  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a820e  d84500                 -fadd dword ptr [ebp]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp));
    // 004a8211  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a8213  d84504                 -fadd dword ptr [ebp + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */));
    // 004a8216  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a8218  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a821b  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a821e  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a8221  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a8224  83e901                 +sub ecx, 1
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
    // 004a8227  7fd5                   -jg 0x4a81fe
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a81fe;
    }
L_0x004a8229:
    // 004a8229  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a822b  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a822d  61                     -popal 
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
    // 004a822e  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a822f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a8230(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a8230  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a8231  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a8233  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004a8234  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a8237  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a823a  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004a823d  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004a8240  83f901                 +cmp ecx, 1
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
    // 004a8243  7e36                   -jle 0x4a827b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a827b;
    }
    // 004a8245  83e901                 -sub ecx, 1
    (cpu.ecx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004a8248:
    // 004a8248  d94500                 -fld dword ptr [ebp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp)));
    // 004a824b  d807                   -fadd dword ptr [edi]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edi));
    // 004a824d  d94504                 -fld dword ptr [ebp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */)));
    // 004a8250  d84704                 -fadd dword ptr [edi + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */));
    // 004a8253  d94508                 -fld dword ptr [ebp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */)));
    // 004a8256  d84708                 -fadd dword ptr [edi + 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(8) /* 0x8 */));
    // 004a8259  d9450c                 -fld dword ptr [ebp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */)));
    // 004a825c  d8470c                 -fadd dword ptr [edi + 0xc]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(12) /* 0xc */));
    // 004a825f  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004a8261  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a8264  d95d08                 -fstp dword ptr [ebp + 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a8267  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a826a  d95d0c                 -fstp dword ptr [ebp + 0xc]
    app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a826d  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a8270  83c510                 -add ebp, 0x10
    (cpu.ebp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a8273  83e902                 +sub ecx, 2
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
    // 004a8276  7fd0                   -jg 0x4a8248
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a8248;
    }
    // 004a8278  83c101                 -add ecx, 1
    (cpu.ecx) += x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004a827b:
    // 004a827b  83f900                 +cmp ecx, 0
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
    // 004a827e  7e1e                   -jle 0x4a829e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a829e;
    }
    // 004a8280  d94500                 -fld dword ptr [ebp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp)));
    // 004a8283  d807                   -fadd dword ptr [edi]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edi));
    // 004a8285  d94504                 -fld dword ptr [ebp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */)));
    // 004a8288  d84704                 -fadd dword ptr [edi + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */));
    // 004a828b  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a828d  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a8290  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a8293  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a8296  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a8299  83e901                 +sub ecx, 1
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
    // 004a829c  7fdd                   -jg 0x4a827b
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a827b;
    }
L_0x004a829e:
    // 004a829e  61                     -popal 
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
    // 004a829f  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a82a0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a82a1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a82a1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a82a2  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a82a4  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004a82a5  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a82a8  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a82ab  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004a82ae  d906                   -fld dword ptr [esi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi)));
    // 004a82b0  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004a82b3  83f903                 +cmp ecx, 3
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
    // 004a82b6  7e46                   -jle 0x4a82fe
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a82fe;
    }
    // 004a82b8  83e903                 -sub ecx, 3
    (cpu.ecx) -= x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x004a82bb:
    // 004a82bb  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004a82bd  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004a82bf  d94708                 -fld dword ptr [edi + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(8) /* 0x8 */)));
    // 004a82c2  d8ca                   -fmul st(2)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(2));
    // 004a82c4  d94710                 -fld dword ptr [edi + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(16) /* 0x10 */)));
    // 004a82c7  d8cb                   -fmul st(3)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(3));
    // 004a82c9  d94718                 -fld dword ptr [edi + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(24) /* 0x18 */)));
    // 004a82cc  d8cc                   -fmul st(4)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(4));
    // 004a82ce  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004a82d0  d84500                 -fadd dword ptr [ebp]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp));
    // 004a82d3  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004a82d5  d84508                 -fadd dword ptr [ebp + 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */));
    // 004a82d8  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a82da  d84510                 -fadd dword ptr [ebp + 0x10]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(16) /* 0x10 */));
    // 004a82dd  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004a82df  d84518                 -fadd dword ptr [ebp + 0x18]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(24) /* 0x18 */));
    // 004a82e2  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004a82e4  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a82e7  d95d08                 -fstp dword ptr [ebp + 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a82ea  d95d18                 -fstp dword ptr [ebp + 0x18]
    app->getMemory<float>(cpu.ebp + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a82ed  d95d10                 -fstp dword ptr [ebp + 0x10]
    app->getMemory<float>(cpu.ebp + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a82f0  83c720                 -add edi, 0x20
    (cpu.edi) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004a82f3  83c520                 -add ebp, 0x20
    (cpu.ebp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004a82f6  83e904                 +sub ecx, 4
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
    // 004a82f9  7fc0                   -jg 0x4a82bb
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a82bb;
    }
    // 004a82fb  83c103                 -add ecx, 3
    (cpu.ecx) += x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x004a82fe:
    // 004a82fe  83f900                 +cmp ecx, 0
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
    // 004a8301  7e15                   -jle 0x4a8318
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a8318;
    }
    // 004a8303  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004a8305  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004a8307  d84500                 -fadd dword ptr [ebp]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp));
    // 004a830a  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a830d  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a8310  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a8313  83e901                 +sub ecx, 1
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
    // 004a8316  7fe6                   -jg 0x4a82fe
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a82fe;
    }
L_0x004a8318:
    // 004a8318  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a831a  61                     -popal 
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
    // 004a831b  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a831c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a831d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a831d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a831e  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a8320  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004a8321  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a8324  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a8327  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004a832a  d94604                 -fld dword ptr [esi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 004a832d  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004a8330  83f903                 +cmp ecx, 3
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
    // 004a8333  7e47                   -jle 0x4a837c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a837c;
    }
    // 004a8335  83e903                 -sub ecx, 3
    (cpu.ecx) -= x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x004a8338:
    // 004a8338  d94704                 -fld dword ptr [edi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 004a833b  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004a833d  d9470c                 -fld dword ptr [edi + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(12) /* 0xc */)));
    // 004a8340  d8ca                   -fmul st(2)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(2));
    // 004a8342  d94714                 -fld dword ptr [edi + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(20) /* 0x14 */)));
    // 004a8345  d8cb                   -fmul st(3)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(3));
    // 004a8347  d9471c                 -fld dword ptr [edi + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(28) /* 0x1c */)));
    // 004a834a  d8cc                   -fmul st(4)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(4));
    // 004a834c  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004a834e  d84504                 -fadd dword ptr [ebp + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */));
    // 004a8351  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004a8353  d8450c                 -fadd dword ptr [ebp + 0xc]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */));
    // 004a8356  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a8358  d84514                 -fadd dword ptr [ebp + 0x14]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(20) /* 0x14 */));
    // 004a835b  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004a835d  d8451c                 -fadd dword ptr [ebp + 0x1c]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(28) /* 0x1c */));
    // 004a8360  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004a8362  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a8365  d95d0c                 -fstp dword ptr [ebp + 0xc]
    app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a8368  d95d1c                 -fstp dword ptr [ebp + 0x1c]
    app->getMemory<float>(cpu.ebp + x86::reg32(28) /* 0x1c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a836b  d95d14                 -fstp dword ptr [ebp + 0x14]
    app->getMemory<float>(cpu.ebp + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a836e  83c720                 -add edi, 0x20
    (cpu.edi) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004a8371  83c520                 -add ebp, 0x20
    (cpu.ebp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004a8374  83e904                 +sub ecx, 4
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
    // 004a8377  7fbf                   -jg 0x4a8338
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a8338;
    }
    // 004a8379  83c103                 -add ecx, 3
    (cpu.ecx) += x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x004a837c:
    // 004a837c  83f900                 +cmp ecx, 0
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
    // 004a837f  7e16                   -jle 0x4a8397
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a8397;
    }
    // 004a8381  d94704                 -fld dword ptr [edi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 004a8384  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004a8386  d84504                 -fadd dword ptr [ebp + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */));
    // 004a8389  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a838c  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a838f  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a8392  83e901                 +sub ecx, 1
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
    // 004a8395  7fe5                   -jg 0x4a837c
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a837c;
    }
L_0x004a8397:
    // 004a8397  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a8399  61                     -popal 
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
    // 004a839a  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a839b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a839c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a839c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a839d  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a839f  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004a83a0  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a83a3  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a83a6  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004a83a9  d906                   -fld dword ptr [esi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi)));
    // 004a83ab  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004a83ae  83f901                 +cmp ecx, 1
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
    // 004a83b1  7e42                   -jle 0x4a83f5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a83f5;
    }
    // 004a83b3  83e901                 -sub ecx, 1
    (cpu.ecx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004a83b6:
    // 004a83b6  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004a83b8  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004a83ba  d94704                 -fld dword ptr [edi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 004a83bd  d94708                 -fld dword ptr [edi + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(8) /* 0x8 */)));
    // 004a83c0  d8cb                   -fmul st(3)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(3));
    // 004a83c2  d9470c                 -fld dword ptr [edi + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(12) /* 0xc */)));
    // 004a83c5  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004a83c7  d84500                 -fadd dword ptr [ebp]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp));
    // 004a83ca  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004a83cc  d84504                 -fadd dword ptr [ebp + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */));
    // 004a83cf  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a83d1  d84508                 -fadd dword ptr [ebp + 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */));
    // 004a83d4  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004a83d6  d8450c                 -fadd dword ptr [ebp + 0xc]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */));
    // 004a83d9  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004a83db  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a83de  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a83e1  d95d0c                 -fstp dword ptr [ebp + 0xc]
    app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a83e4  d95d08                 -fstp dword ptr [ebp + 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a83e7  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a83ea  83c510                 -add ebp, 0x10
    (cpu.ebp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a83ed  83e902                 +sub ecx, 2
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
    // 004a83f0  7fc4                   -jg 0x4a83b6
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a83b6;
    }
    // 004a83f2  83c101                 -add ecx, 1
    (cpu.ecx) += x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004a83f5:
    // 004a83f5  83f900                 +cmp ecx, 0
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
    // 004a83f8  7e24                   -jle 0x4a841e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a841e;
    }
    // 004a83fa  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004a83fc  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004a83fe  d94704                 -fld dword ptr [edi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 004a8401  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a8403  d84500                 -fadd dword ptr [ebp]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp));
    // 004a8406  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a8408  d84504                 -fadd dword ptr [ebp + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */));
    // 004a840b  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a840d  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a8410  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a8413  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a8416  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a8419  83e901                 +sub ecx, 1
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
    // 004a841c  7fd7                   -jg 0x4a83f5
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a83f5;
    }
L_0x004a841e:
    // 004a841e  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a8420  61                     -popal 
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
    // 004a8421  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8422  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a8423(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a8423  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a8424  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a8426  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004a8427  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a842a  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a842d  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004a8430  d94604                 -fld dword ptr [esi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 004a8433  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004a8436  83f901                 +cmp ecx, 1
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
    // 004a8439  7e42                   -jle 0x4a847d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a847d;
    }
    // 004a843b  83e901                 -sub ecx, 1
    (cpu.ecx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004a843e:
    // 004a843e  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004a8440  d94704                 -fld dword ptr [edi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 004a8443  d8ca                   -fmul st(2)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(2));
    // 004a8445  d94708                 -fld dword ptr [edi + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(8) /* 0x8 */)));
    // 004a8448  d9470c                 -fld dword ptr [edi + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(12) /* 0xc */)));
    // 004a844b  d8cc                   -fmul st(4)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(4));
    // 004a844d  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004a844f  d84500                 -fadd dword ptr [ebp]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp));
    // 004a8452  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004a8454  d84504                 -fadd dword ptr [ebp + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */));
    // 004a8457  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a8459  d84508                 -fadd dword ptr [ebp + 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */));
    // 004a845c  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004a845e  d8450c                 -fadd dword ptr [ebp + 0xc]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */));
    // 004a8461  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004a8463  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a8466  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a8469  d95d0c                 -fstp dword ptr [ebp + 0xc]
    app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a846c  d95d08                 -fstp dword ptr [ebp + 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a846f  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a8472  83c510                 -add ebp, 0x10
    (cpu.ebp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a8475  83e902                 +sub ecx, 2
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
    // 004a8478  7fc4                   -jg 0x4a843e
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a843e;
    }
    // 004a847a  83c101                 -add ecx, 1
    (cpu.ecx) += x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004a847d:
    // 004a847d  83f900                 +cmp ecx, 0
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
    // 004a8480  7e24                   -jle 0x4a84a6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a84a6;
    }
    // 004a8482  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004a8484  d94704                 -fld dword ptr [edi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 004a8487  d8ca                   -fmul st(2)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(2));
    // 004a8489  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a848b  d84500                 -fadd dword ptr [ebp]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp));
    // 004a848e  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a8490  d84504                 -fadd dword ptr [ebp + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */));
    // 004a8493  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a8495  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a8498  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a849b  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a849e  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a84a1  83e901                 +sub ecx, 1
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
    // 004a84a4  7fd7                   -jg 0x4a847d
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a847d;
    }
L_0x004a84a6:
    // 004a84a6  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a84a8  61                     -popal 
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
    // 004a84a9  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a84aa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a84ab(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a84ab  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a84ac  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a84ae  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a84af  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a84b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a84b0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a84b1  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a84b3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a84b4  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a84b7  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 004a84bd  c7460c00000000         -mov dword ptr [esi + 0xc], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 004a84c4  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a84c7  c700f0844a00           -mov dword ptr [eax], 0x4a84f0
    app->getMemory<x86::reg32>(cpu.eax) = 4883696 /*0x4a84f0*/;
    // 004a84cd  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004a84d0  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004a84d3  c70005854a00           -mov dword ptr [eax], 0x4a8505
    app->getMemory<x86::reg32>(cpu.eax) = 4883717 /*0x4a8505*/;
    // 004a84d9  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004a84dc  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004a84df  c7004b854a00           -mov dword ptr [eax], 0x4a854b
    app->getMemory<x86::reg32>(cpu.eax) = 4883787 /*0x4a854b*/;
    // 004a84e5  894618                 -mov dword ptr [esi + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004a84e8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a84e9  b800000000             -mov eax, 0
    cpu.eax = 0 /*0x0*/;
    // 004a84ee  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a84ef  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a84f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a84f0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a84f1  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a84f3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a84f4  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a84f7  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a84fa  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004a84fd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a84fe  b800000000             -mov eax, 0
    cpu.eax = 0 /*0x0*/;
    // 004a8503  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8504  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a8505(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a8505  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a8506  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a8508  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a8509  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a850c  817e0400000100         +cmp dword ptr [esi + 4], 0x10000
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a8513  7c08                   -jl 0x4a851d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a851d;
    }
    // 004a8515  7f1e                   -jg 0x4a8535
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a8535;
    }
    // 004a8517  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8518  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a851b  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a851c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a851d:
    // 004a851d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a851e  8b550c                 -mov edx, dword ptr [ebp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a8521  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004a8524  4a                     -dec edx
    (cpu.edx)--;
    // 004a8525  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004a8528  0306                   -add eax, dword ptr [esi]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi)));
    // 004a852a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a852b  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a852e  40                     -inc eax
    (cpu.eax)++;
    // 004a852f  2b460c                 -sub eax, dword ptr [esi + 0xc]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */)));
    // 004a8532  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8533  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8534  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a8535:
    // 004a8535  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a8536  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004a8539  8b550c                 -mov edx, dword ptr [ebp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a853c  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004a853f  0306                   -add eax, dword ptr [esi]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi)));
    // 004a8541  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8542  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a8545  2b460c                 -sub eax, dword ptr [esi + 0xc]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */)));
    // 004a8548  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8549  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a854a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a854b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a854b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a854c  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a854e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a854f  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a8552  817e0400000100         +cmp dword ptr [esi + 4], 0x10000
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a8559  750f                   -jne 0x4a856a
    if (!cpu.flags.zf)
    {
        goto L_0x004a856a;
    }
    // 004a855b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a855c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a855d  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004a8560  8b5d10                 -mov ebx, dword ptr [ebp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004a8563  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 004a8565  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8566  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8567  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8568  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8569  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a856a:
    // 004a856a  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004a856b  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004a856d  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004a8570  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004a8573  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a8576  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004a8579  8b38                   -mov edi, dword ptr [eax]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax);
    // 004a857b  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 004a857e  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004a8581  03cf                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004a8583  a348f74c00             -mov dword ptr [0x4cf748], eax
    app->getMemory<x86::reg32>(x86::reg32(5044040) /* 0x4cf748 */) = cpu.eax;
    // 004a8588  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004a858b  8b7510                 -mov esi, dword ptr [ebp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004a858e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a858f  c1ee02                 -shr esi, 2
    cpu.esi >>= 2 /*0x2*/ % 32;
    // 004a8592  8beb                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004a8594  c1eb10                 -shr ebx, 0x10
    cpu.ebx >>= 16 /*0x10*/ % 32;
    // 004a8597  c1e510                 -shl ebp, 0x10
    cpu.ebp <<= 16 /*0x10*/ % 32;
    // 004a859a  83f801                 +cmp eax, 1
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
    // 004a859d  751c                   -jne 0x4a85bb
    if (!cpu.flags.zf)
    {
        goto L_0x004a85bb;
    }
    // 004a859f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a85a0  be00000000             -mov esi, 0
    cpu.esi = 0 /*0x0*/;
L_0x004a85a5:
    // 004a85a5  a148f74c00             -mov eax, dword ptr [0x4cf748]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5044040) /* 0x4cf748 */);
    // 004a85aa  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 004a85ac  03d5                   +add edx, ebp
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a85ae  13f3                   -adc esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx) + cpu.flags.cf);
    // 004a85b0  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a85b3  83fe00                 +cmp esi, 0
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a85b6  74ed                   -je 0x4a85a5
    if (cpu.flags.zf)
    {
        goto L_0x004a85a5;
    }
    // 004a85b8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a85b9  90                     -nop 
    ;
    // 004a85ba  90                     -nop 
    ;
L_0x004a85bb:
    // 004a85bb  8b04b500000000         -mov eax, dword ptr [esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi * 4);
    // 004a85c2  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 004a85c4  03d5                   +add edx, ebp
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a85c6  13f3                   -adc esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx) + cpu.flags.cf);
    // 004a85c8  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a85cb  3bf9                   +cmp edi, ecx
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
    // 004a85cd  7cec                   -jl 0x4a85bb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a85bb;
    }
    // 004a85cf  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004a85d2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a85d3  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a85d6  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 004a85d8  3b5e04                 +cmp ebx, dword ptr [esi + 4]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a85db  7c11                   -jl 0x4a85ee
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a85ee;
    }
    // 004a85dd  8b47fc                 -mov eax, dword ptr [edi - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-4) /* -0x4 */);
    // 004a85e0  c7460c01000000         -mov dword ptr [esi + 0xc], 1
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = 1 /*0x1*/;
    // 004a85e7  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004a85ea  61                     -popal 
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
    // 004a85eb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a85ec  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a85ed  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a85ee:
    // 004a85ee  c7460c00000000         -mov dword ptr [esi + 0xc], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 004a85f5  61                     -popal 
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
    // 004a85f6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a85f7  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a85f8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_4a85fc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a85fc  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a85fd  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a85ff  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a8600  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a8603  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 004a8609  c7461000000000         -mov dword ptr [esi + 0x10], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 004a8610  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a8613  c7003c864a00           -mov dword ptr [eax], 0x4a863c
    app->getMemory<x86::reg32>(cpu.eax) = 4884028 /*0x4a863c*/;
    // 004a8619  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004a861c  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004a861f  c70051864a00           -mov dword ptr [eax], 0x4a8651
    app->getMemory<x86::reg32>(cpu.eax) = 4884049 /*0x4a8651*/;
    // 004a8625  894618                 -mov dword ptr [esi + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004a8628  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004a862b  c70097864a00           -mov dword ptr [eax], 0x4a8697
    app->getMemory<x86::reg32>(cpu.eax) = 4884119 /*0x4a8697*/;
    // 004a8631  89461c                 -mov dword ptr [esi + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004a8634  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8635  b800000000             -mov eax, 0
    cpu.eax = 0 /*0x0*/;
    // 004a863a  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a863b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a863c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a863c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a863d  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a863f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a8640  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a8643  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a8646  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004a8649  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a864a  b800000000             -mov eax, 0
    cpu.eax = 0 /*0x0*/;
    // 004a864f  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8650  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a8651(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a8651  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a8652  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a8654  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a8655  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a8658  817e0400000100         +cmp dword ptr [esi + 4], 0x10000
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a865f  7c08                   -jl 0x4a8669
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a8669;
    }
    // 004a8661  7f1e                   -jg 0x4a8681
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a8681;
    }
    // 004a8663  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8664  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a8667  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8668  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a8669:
    // 004a8669  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a866a  8b550c                 -mov edx, dword ptr [ebp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a866d  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004a8670  4a                     -dec edx
    (cpu.edx)--;
    // 004a8671  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004a8674  0306                   -add eax, dword ptr [esi]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi)));
    // 004a8676  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8677  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a867a  40                     -inc eax
    (cpu.eax)++;
    // 004a867b  2b4610                 -sub eax, dword ptr [esi + 0x10]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */)));
    // 004a867e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a867f  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8680  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a8681:
    // 004a8681  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a8682  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004a8685  8b550c                 -mov edx, dword ptr [ebp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a8688  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004a868b  0306                   -add eax, dword ptr [esi]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi)));
    // 004a868d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a868e  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a8691  2b4610                 -sub eax, dword ptr [esi + 0x10]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */)));
    // 004a8694  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8695  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8696  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a8697(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a8697  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a8698  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a869a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a869b  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a869e  817e0400000100         +cmp dword ptr [esi + 4], 0x10000
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a86a5  750f                   -jne 0x4a86b6
    if (!cpu.flags.zf)
    {
        goto L_0x004a86b6;
    }
    // 004a86a7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a86a8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a86a9  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004a86ac  8b5d10                 -mov ebx, dword ptr [ebp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004a86af  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 004a86b1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a86b2  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a86b3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a86b4  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a86b5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a86b6:
    // 004a86b6  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004a86b7  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004a86b9  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004a86bc  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004a86bf  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a86c2  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004a86c5  8b38                   -mov edi, dword ptr [eax]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax);
    // 004a86c7  c1e103                 -shl ecx, 3
    cpu.ecx <<= 3 /*0x3*/ % 32;
    // 004a86ca  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004a86cd  03cf                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004a86cf  a350f74c00             -mov dword ptr [0x4cf750], eax
    app->getMemory<x86::reg32>(x86::reg32(5044048) /* 0x4cf750 */) = cpu.eax;
    // 004a86d4  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004a86d7  a354f74c00             -mov dword ptr [0x4cf754], eax
    app->getMemory<x86::reg32>(x86::reg32(5044052) /* 0x4cf754 */) = cpu.eax;
    // 004a86dc  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004a86df  8b7510                 -mov esi, dword ptr [ebp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004a86e2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a86e3  c1ee03                 -shr esi, 3
    cpu.esi >>= 3 /*0x3*/ % 32;
    // 004a86e6  8beb                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004a86e8  c1eb10                 -shr ebx, 0x10
    cpu.ebx >>= 16 /*0x10*/ % 32;
    // 004a86eb  c1e510                 -shl ebp, 0x10
    cpu.ebp <<= 16 /*0x10*/ % 32;
    // 004a86ee  83f801                 +cmp eax, 1
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
    // 004a86f1  7522                   -jne 0x4a8715
    if (!cpu.flags.zf)
    {
        goto L_0x004a8715;
    }
    // 004a86f3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a86f4  be00000000             -mov esi, 0
    cpu.esi = 0 /*0x0*/;
L_0x004a86f9:
    // 004a86f9  a150f74c00             -mov eax, dword ptr [0x4cf750]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5044048) /* 0x4cf750 */);
    // 004a86fe  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 004a8700  a154f74c00             -mov eax, dword ptr [0x4cf754]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5044052) /* 0x4cf754 */);
    // 004a8705  894704                 -mov dword ptr [edi + 4], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004a8708  03d5                   +add edx, ebp
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a870a  13f3                   -adc esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx) + cpu.flags.cf);
    // 004a870c  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a870f  83fe00                 +cmp esi, 0
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a8712  74e5                   -je 0x4a86f9
    if (cpu.flags.zf)
    {
        goto L_0x004a86f9;
    }
    // 004a8714  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004a8715:
    // 004a8715  89254cf74c00           -mov dword ptr [0x4cf74c], esp
    app->getMemory<x86::reg32>(x86::reg32(5044044) /* 0x4cf74c */) = cpu.esp;
    // 004a871b  90                     -nop 
    ;
L_0x004a871c:
    // 004a871c  8b04f500000000         -mov eax, dword ptr [esi*8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi * 8);
    // 004a8723  8b24f504000000         -mov esp, dword ptr [esi*8 + 4]
    cpu.esp = app->getMemory<x86::reg32>(x86::reg32(4) /* 0x4 */ + cpu.esi * 8);
    // 004a872a  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 004a872c  896704                 -mov dword ptr [edi + 4], esp
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.esp;
    // 004a872f  03d5                   +add edx, ebp
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a8731  13f3                   -adc esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx) + cpu.flags.cf);
    // 004a8733  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a8736  3bf9                   +cmp edi, ecx
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
    // 004a8738  7ce2                   -jl 0x4a871c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a871c;
    }
    // 004a873a  8b254cf74c00           -mov esp, dword ptr [0x4cf74c]
    cpu.esp = app->getMemory<x86::reg32>(x86::reg32(5044044) /* 0x4cf74c */);
    // 004a8740  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004a8743  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8744  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a8747  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 004a8749  3b5e04                 +cmp ebx, dword ptr [esi + 4]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a874c  7c17                   -jl 0x4a8765
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a8765;
    }
    // 004a874e  8b47f8                 -mov eax, dword ptr [edi - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-8) /* -0x8 */);
    // 004a8751  c7461001000000         -mov dword ptr [esi + 0x10], 1
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = 1 /*0x1*/;
    // 004a8758  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004a875b  8b47fc                 -mov eax, dword ptr [edi - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-4) /* -0x4 */);
    // 004a875e  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004a8761  61                     -popal 
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
    // 004a8762  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8763  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8764  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a8765:
    // 004a8765  c7461000000000         -mov dword ptr [esi + 0x10], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 004a876c  61                     -popal 
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
    // 004a876d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a876e  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a876f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a8770(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a8770  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a8771  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a8772  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a8773  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a8777  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a877b  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004a877e  48                     -dec eax
    (cpu.eax)--;
    // 004a877f  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004a8782  034204                 -add eax, dword ptr [edx + 4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 004a8785  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a8788  8b5a13                 -mov ebx, dword ptr [edx + 0x13]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 004a878b  40                     -inc eax
    (cpu.eax)++;
    // 004a878c  c1fb18                 -sar ebx, 0x18
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (24 /*0x18*/ % 32));
    // 004a878f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a8791  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004a8793  8a5a15                 -mov bl, byte ptr [edx + 0x15]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(21) /* 0x15 */);
    // 004a8796  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a8798  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 004a879a  7501                   -jne 0x4a879d
    if (!cpu.flags.zf)
    {
        goto L_0x004a879d;
    }
    // 004a879c  40                     -inc eax
    (cpu.eax)++;
L_0x004a879d:
    // 004a879d  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a87a1  8b5108                 -mov edx, dword ptr [ecx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004a87a4  0fafd7                 -imul edx, edi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 004a87a7  035104                 -add edx, dword ptr [ecx + 4]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
    // 004a87aa  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004a87ad  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004a87af  885116                 -mov byte ptr [ecx + 0x16], dl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(22) /* 0x16 */) = cpu.dl;
    // 004a87b2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a87b3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a87b4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a87b5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a87b8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a87b8  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a87bc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a87c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a87c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a87c1  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a87c5  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a87c9  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004a87cc  48                     -dec eax
    (cpu.eax)--;
    // 004a87cd  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004a87d0  034204                 -add eax, dword ptr [edx + 4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 004a87d3  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a87d5  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a87d8  8a5a15                 -mov bl, byte ptr [edx + 0x15]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(21) /* 0x15 */);
    // 004a87db  40                     -inc eax
    (cpu.eax)++;
    // 004a87dc  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 004a87de  7501                   -jne 0x4a87e1
    if (!cpu.flags.zf)
    {
        goto L_0x004a87e1;
    }
    // 004a87e0  40                     -inc eax
    (cpu.eax)++;
L_0x004a87e1:
    // 004a87e1  8b5111                 -mov edx, dword ptr [ecx + 0x11]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(17) /* 0x11 */);
    // 004a87e4  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004a87e7  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a87e9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a87ea  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a87ec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a87ec  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a87ed  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a87ee  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a87ef  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a87f0  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004a87f3  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004a87f7  8b7c242c               -mov edi, dword ptr [esp + 0x2c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004a87fb  8b542430               -mov edx, dword ptr [esp + 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004a87ff  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a8801  8a4815                 -mov cl, byte ptr [eax + 0x15]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(21) /* 0x15 */);
    // 004a8804  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004a8806  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 004a8808  7571                   -jne 0x4a887b
    if (!cpu.flags.zf)
    {
        goto L_0x004a887b;
    }
L_0x004a880a:
    // 004a880a  8b6c2434               -mov ebp, dword ptr [esp + 0x34]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004a880e  4f                     -dec edi
    (cpu.edi)--;
    // 004a880f  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp);
    // 004a8812  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a8814  7f6f                   -jg 0x4a8885
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a8885;
    }
L_0x004a8816:
    // 004a8816  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a8818  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a881b  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004a881f  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004a8822  df2c24                 -fild qword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.esp))));
    // 004a8825  dc0df8164c00           -fmul qword ptr [0x4c16f8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4986616) /* 0x4c16f8 */));
    // 004a882b  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004a882d  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 004a882f  dee1                   -fsubrp st(1)
    cpu.fpu.st(1) = cpu.fpu.st(0) - x86::Float(cpu.fpu.st(1));
    cpu.fpu.pop();
    // 004a8831  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a8833  d9448604               -fld dword ptr [esi + eax*4 + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.eax * 4)));
    // 004a8837  deca                   -fmulp st(2)
    cpu.fpu.st(2) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004a8839  d80c86                 -fmul dword ptr [esi + eax*4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + cpu.eax * 4));
    // 004a883c  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004a883e  d95cbd00               -fstp dword ptr [ebp + edi*4]
    app->getMemory<float>(cpu.ebp + cpu.edi * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a8842  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a8844  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a8847  d9448604               -fld dword ptr [esi + eax*4 + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.eax * 4)));
    // 004a884b  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a884e  d95b10                 -fstp dword ptr [ebx + 0x10]
    app->getMemory<float>(cpu.ebx + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a8851  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a8853  8b33                   -mov esi, dword ptr [ebx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a8855  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a8857  894b04                 -mov dword ptr [ebx + 4], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004a885a  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a885d  66c743060000           -mov word ptr [ebx + 6], 0
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 004a8863  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a8865  8b4313                 -mov eax, dword ptr [ebx + 0x13]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(19) /* 0x13 */);
    // 004a8868  8933                   -mov dword ptr [ebx], esi
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.esi;
    // 004a886a  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004a886d  c6431501               -mov byte ptr [ebx + 0x15], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(21) /* 0x15 */) = 1 /*0x1*/;
    // 004a8871  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004a8873  83c414                 +add esp, 0x14
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
    // 004a8876  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8877  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8878  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8879  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a887a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a887b:
    // 004a887b  8d72fc                 -lea esi, [edx - 4]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 004a887e  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004a8881  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 004a8883  eb85                   -jmp 0x4a880a
    goto L_0x004a880a;
L_0x004a8885:
    // 004a8885  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a8888  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a888b  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a888e  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004a8891  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004a8894  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a8895  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004a8898  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a8899  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004a889d  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a88a1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a88a2  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a88a3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a88a4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a88a5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a88a6  e8b1590000             -call 0x4ae25c
    cpu.esp -= 4;
    sub_4ae25c(app, cpu);
    if (cpu.terminate) return;
    // 004a88ab  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004a88ae  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a88b2  c1e810                 +shr eax, 0x10
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
    // 004a88b5  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004a88b8  e959ffffff             -jmp 0x4a8816
    goto L_0x004a8816;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a88c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a88c0  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a88c4  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a88c8  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004a88ca  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a88cc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a88cc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a88cd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a88ce  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a88cf  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a88d0  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004a88d3  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004a88d7  8b7c242c               -mov edi, dword ptr [esp + 0x2c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004a88db  8b542430               -mov edx, dword ptr [esp + 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004a88df  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a88e1  8a4815                 -mov cl, byte ptr [eax + 0x15]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(21) /* 0x15 */);
    // 004a88e4  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004a88e6  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 004a88e8  0f85c5000000           -jne 0x4a89b3
    if (!cpu.flags.zf)
    {
        goto L_0x004a89b3;
    }
L_0x004a88ee:
    // 004a88ee  807b1400               +cmp byte ptr [ebx + 0x14], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(20) /* 0x14 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a88f2  7409                   -je 0x4a88fd
    if (cpu.flags.zf)
    {
        goto L_0x004a88fd;
    }
    // 004a88f4  8b430c                 -mov eax, dword ptr [ebx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004a88f7  8946fc                 -mov dword ptr [esi - 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004a88fa  83ee04                 +sub esi, 4
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
L_0x004a88fd:
    // 004a88fd  8b6c2434               -mov ebp, dword ptr [esp + 0x34]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004a8901  c70300000000           -mov dword ptr [ebx], 0
    app->getMemory<x86::reg32>(cpu.ebx) = 0 /*0x0*/;
    // 004a8907  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp);
    // 004a890a  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a890b  7433                   -je 0x4a8940
    if (cpu.flags.zf)
    {
        goto L_0x004a8940;
    }
    // 004a890d  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a8910  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a8913  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a8916  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004a8919  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004a891c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a891d  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004a8920  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a8921  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004a8925  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a8929  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a892a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a892b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a892c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a892d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a892e  e829590000             -call 0x4ae25c
    cpu.esp -= 4;
    sub_4ae25c(app, cpu);
    if (cpu.terminate) return;
    // 004a8933  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004a8936  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a893a  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a893d  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x004a8940:
    // 004a8940  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a8942  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a8945  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004a8949  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004a894c  df2c24                 -fild qword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.esp))));
    // 004a894f  dc0d00174c00           -fmul qword ptr [0x4c1700]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4986624) /* 0x4c1700 */));
    // 004a8955  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004a8957  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 004a8959  dee1                   -fsubrp st(1)
    cpu.fpu.st(1) = cpu.fpu.st(0) - x86::Float(cpu.fpu.st(1));
    cpu.fpu.pop();
    // 004a895b  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a895d  d9448604               -fld dword ptr [esi + eax*4 + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.eax * 4)));
    // 004a8961  deca                   -fmulp st(2)
    cpu.fpu.st(2) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004a8963  d80c86                 -fmul dword ptr [esi + eax*4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + cpu.eax * 4));
    // 004a8966  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004a8968  d95cbd00               -fstp dword ptr [ebp + edi*4]
    app->getMemory<float>(cpu.ebp + cpu.edi * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a896c  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a896e  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a8971  8b3b                   -mov edi, dword ptr [ebx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a8973  d9448604               -fld dword ptr [esi + eax*4 + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.eax * 4)));
    // 004a8977  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a897a  8b6b08                 -mov ebp, dword ptr [ebx + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a897d  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a897f  d95b10                 -fstp dword ptr [ebx + 0x10]
    app->getMemory<float>(cpu.ebx + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a8982  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a8984  894b04                 -mov dword ptr [ebx + 4], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004a8987  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a898a  66c743060000           -mov word ptr [ebx + 6], 0
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 004a8990  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a8992  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a8995  893b                   -mov dword ptr [ebx], edi
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edi;
    // 004a8997  39e8                   +cmp eax, ebp
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
    // 004a8999  7225                   -jb 0x4a89c0
    if (cpu.flags.cf)
    {
        goto L_0x004a89c0;
    }
    // 004a899b  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a899d  c6431401               -mov byte ptr [ebx + 0x14], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(20) /* 0x14 */) = 1 /*0x1*/;
    // 004a89a1  8b1486                 -mov edx, dword ptr [esi + eax*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + cpu.eax * 4);
    // 004a89a4  89530c                 -mov dword ptr [ebx + 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004a89a7  c6431501               -mov byte ptr [ebx + 0x15], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(21) /* 0x15 */) = 1 /*0x1*/;
    // 004a89ab  83c414                 +add esp, 0x14
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
    // 004a89ae  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a89af  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a89b0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a89b1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a89b2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a89b3:
    // 004a89b3  8d72fc                 -lea esi, [edx - 4]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 004a89b6  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004a89b9  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 004a89bb  e92effffff             -jmp 0x4a88ee
    goto L_0x004a88ee;
L_0x004a89c0:
    // 004a89c0  c6431400               -mov byte ptr [ebx + 0x14], 0
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 004a89c4  c6431501               -mov byte ptr [ebx + 0x15], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(21) /* 0x15 */) = 1 /*0x1*/;
    // 004a89c8  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004a89cb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a89cc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a89cd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a89ce  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a89cf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a89d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a89d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a89d1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a89d2  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a89d6  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a89da  8b5908                 -mov ebx, dword ptr [ecx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004a89dd  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a89df  81fb00000100           +cmp ebx, 0x10000
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
    // 004a89e5  732c                   -jae 0x4a8a13
    if (!cpu.flags.cf)
    {
        goto L_0x004a8a13;
    }
    // 004a89e7  81fa00000100           +cmp edx, 0x10000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a89ed  7324                   -jae 0x4a8a13
    if (!cpu.flags.cf)
    {
        goto L_0x004a8a13;
    }
L_0x004a89ef:
    // 004a89ef  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004a89f2  81fa00000100           +cmp edx, 0x10000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a89f8  724b                   -jb 0x4a8a45
    if (cpu.flags.cf)
    {
        goto L_0x004a8a45;
    }
    // 004a89fa  7660                   -jbe 0x4a8a5c
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a8a5c;
    }
    // 004a89fc  8b501c                 -mov edx, dword ptr [eax + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004a89ff  c70270874a00           -mov dword ptr [edx], 0x4a8770
    app->getMemory<x86::reg32>(cpu.edx) = 4884336 /*0x4a8770*/;
    // 004a8a05  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004a8a08  c700ec874a00           -mov dword ptr [eax], 0x4a87ec
    app->getMemory<x86::reg32>(cpu.eax) = 4884460 /*0x4a87ec*/;
    // 004a8a0e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a8a10  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8a11  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8a12  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a8a13:
    // 004a8a13  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004a8a16  39f2                   +cmp edx, esi
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
    // 004a8a18  74d5                   -je 0x4a89ef
    if (cpu.flags.zf)
    {
        goto L_0x004a89ef;
    }
    // 004a8a1a  81fe00000100           +cmp esi, 0x10000
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a8a20  7608                   -jbe 0x4a8a2a
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a8a2a;
    }
    // 004a8a22  81fa00000100           +cmp edx, 0x10000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a8a28  77c5                   -ja 0x4a89ef
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004a89ef;
    }
L_0x004a8a2a:
    // 004a8a2a  c6401400               -mov byte ptr [eax + 0x14], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 004a8a2e  c6401500               -mov byte ptr [eax + 0x15], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(21) /* 0x15 */) = 0 /*0x0*/;
    // 004a8a32  c6401600               -mov byte ptr [eax + 0x16], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(22) /* 0x16 */) = 0 /*0x0*/;
    // 004a8a36  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004a8a3d  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004a8a43  ebaa                   -jmp 0x4a89ef
    goto L_0x004a89ef;
L_0x004a8a45:
    // 004a8a45  8b501c                 -mov edx, dword ptr [eax + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004a8a48  c702c0874a00           -mov dword ptr [edx], 0x4a87c0
    app->getMemory<x86::reg32>(cpu.edx) = 4884416 /*0x4a87c0*/;
    // 004a8a4e  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004a8a51  c700cc884a00           -mov dword ptr [eax], 0x4a88cc
    app->getMemory<x86::reg32>(cpu.eax) = 4884684 /*0x4a88cc*/;
    // 004a8a57  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a8a59  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8a5a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8a5b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a8a5c:
    // 004a8a5c  8b501c                 -mov edx, dword ptr [eax + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004a8a5f  c702b8874a00           -mov dword ptr [edx], 0x4a87b8
    app->getMemory<x86::reg32>(cpu.edx) = 4884408 /*0x4a87b8*/;
    // 004a8a65  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004a8a68  c700c0884a00           -mov dword ptr [eax], 0x4a88c0
    app->getMemory<x86::reg32>(cpu.eax) = 4884672 /*0x4a88c0*/;
    // 004a8a6e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a8a70  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8a71  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8a72  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a8a74(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a8a74  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a8a78  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004a8a7e  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004a8a85  c6401400               -mov byte ptr [eax + 0x14], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 004a8a89  c7401000000000         -mov dword ptr [eax + 0x10], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 004a8a90  c6401500               -mov byte ptr [eax + 0x15], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(21) /* 0x15 */) = 0 /*0x0*/;
    // 004a8a94  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a8a98  c6401601               -mov byte ptr [eax + 0x16], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(22) /* 0x16 */) = 1 /*0x1*/;
    // 004a8a9c  895018                 -mov dword ptr [eax + 0x18], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004a8a9f  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a8aa3  89501c                 -mov dword ptr [eax + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004a8aa6  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a8aaa  895020                 -mov dword ptr [eax + 0x20], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 004a8aad  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004a8ab0  c700d0894a00           -mov dword ptr [eax], 0x4a89d0
    app->getMemory<x86::reg32>(cpu.eax) = 4884944 /*0x4a89d0*/;
    // 004a8ab6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a8ab8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a8ac0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a8ac0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a8ac1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a8ac2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a8ac3  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a8ac7  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a8acb  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004a8ace  48                     -dec eax
    (cpu.eax)--;
    // 004a8acf  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004a8ad2  034204                 -add eax, dword ptr [edx + 4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 004a8ad5  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a8ad8  8b5a1b                 -mov ebx, dword ptr [edx + 0x1b]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(27) /* 0x1b */);
    // 004a8adb  40                     -inc eax
    (cpu.eax)++;
    // 004a8adc  c1fb18                 -sar ebx, 0x18
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (24 /*0x18*/ % 32));
    // 004a8adf  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a8ae1  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004a8ae3  8a5a1d                 -mov bl, byte ptr [edx + 0x1d]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(29) /* 0x1d */);
    // 004a8ae6  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a8ae8  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 004a8aea  7501                   -jne 0x4a8aed
    if (!cpu.flags.zf)
    {
        goto L_0x004a8aed;
    }
    // 004a8aec  40                     -inc eax
    (cpu.eax)++;
L_0x004a8aed:
    // 004a8aed  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a8af1  8b5108                 -mov edx, dword ptr [ecx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004a8af4  0fafd7                 -imul edx, edi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 004a8af7  035104                 -add edx, dword ptr [ecx + 4]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
    // 004a8afa  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004a8afd  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004a8aff  88511e                 -mov byte ptr [ecx + 0x1e], dl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) = cpu.dl;
    // 004a8b02  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8b03  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8b04  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8b05  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a8b08(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a8b08  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a8b0c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a8b10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a8b10  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a8b11  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a8b15  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a8b19  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004a8b1c  48                     -dec eax
    (cpu.eax)--;
    // 004a8b1d  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004a8b20  034204                 -add eax, dword ptr [edx + 4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 004a8b23  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a8b25  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a8b28  8a5a1d                 -mov bl, byte ptr [edx + 0x1d]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(29) /* 0x1d */);
    // 004a8b2b  40                     -inc eax
    (cpu.eax)++;
    // 004a8b2c  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 004a8b2e  7501                   -jne 0x4a8b31
    if (!cpu.flags.zf)
    {
        goto L_0x004a8b31;
    }
    // 004a8b30  40                     -inc eax
    (cpu.eax)++;
L_0x004a8b31:
    // 004a8b31  8b5119                 -mov edx, dword ptr [ecx + 0x19]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(25) /* 0x19 */);
    // 004a8b34  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004a8b37  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a8b39  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8b3a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a8b3c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a8b3c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a8b3d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a8b3e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a8b3f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a8b40  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004a8b43  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004a8b47  8b7c242c               -mov edi, dword ptr [esp + 0x2c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004a8b4b  8b542430               -mov edx, dword ptr [esp + 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004a8b4f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a8b51  8a481d                 -mov cl, byte ptr [eax + 0x1d]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(29) /* 0x1d */);
    // 004a8b54  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004a8b56  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 004a8b58  0f8598000000           -jne 0x4a8bf6
    if (!cpu.flags.zf)
    {
        goto L_0x004a8bf6;
    }
L_0x004a8b5e:
    // 004a8b5e  8b6c2434               -mov ebp, dword ptr [esp + 0x34]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004a8b62  4f                     -dec edi
    (cpu.edi)--;
    // 004a8b63  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp);
    // 004a8b66  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a8b68  0f8f9d000000           -jg 0x4a8c0b
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a8c0b;
    }
L_0x004a8b6e:
    // 004a8b6e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a8b70  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a8b73  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004a8b77  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004a8b7a  df2c24                 -fild qword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.esp))));
    // 004a8b7d  dc0d08174c00           -fmul qword ptr [0x4c1708]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4986632) /* 0x4c1708 */));
    // 004a8b83  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004a8b85  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 004a8b87  dee1                   -fsubrp st(1)
    cpu.fpu.st(1) = cpu.fpu.st(0) - x86::Float(cpu.fpu.st(1));
    cpu.fpu.pop();
    // 004a8b89  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a8b8b  d944c608               -fld dword ptr [esi + eax*8 + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(8) /* 0x8 */ + cpu.eax * 8)));
    // 004a8b8f  d8ca                   -fmul st(2)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(2));
    // 004a8b91  d904c6                 -fld dword ptr [esi + eax*8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + cpu.eax * 8)));
    // 004a8b94  d8ca                   -fmul st(2)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(2));
    // 004a8b96  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004a8b98  8d04fd00000000         -lea eax, [edi*8]
    cpu.eax = x86::reg32(cpu.edi * 8);
    // 004a8b9f  d91c28                 -fstp dword ptr [eax + ebp]
    app->getMemory<float>(cpu.eax + cpu.ebp * 1) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a8ba2  8b3b                   -mov edi, dword ptr [ebx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a8ba4  d84cfe04               -fmul dword ptr [esi + edi*8 + 4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.edi * 8));
    // 004a8ba8  d944fe0c               -fld dword ptr [esi + edi*8 + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(12) /* 0xc */ + cpu.edi * 8)));
    // 004a8bac  deca                   -fmulp st(2)
    cpu.fpu.st(2) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004a8bae  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004a8bb0  d95c2804               -fstp dword ptr [eax + ebp + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */ + cpu.ebp * 1) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a8bb4  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a8bb6  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a8bb9  d944c608               -fld dword ptr [esi + eax*8 + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(8) /* 0x8 */ + cpu.eax * 8)));
    // 004a8bbd  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a8bbf  d95b14                 -fstp dword ptr [ebx + 0x14]
    app->getMemory<float>(cpu.ebx + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a8bc2  d944c60c               -fld dword ptr [esi + eax*8 + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(12) /* 0xc */ + cpu.eax * 8)));
    // 004a8bc6  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a8bc9  d95b18                 -fstp dword ptr [ebx + 0x18]
    app->getMemory<float>(cpu.ebx + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a8bcc  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a8bce  8b33                   -mov esi, dword ptr [ebx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a8bd0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a8bd2  894b04                 -mov dword ptr [ebx + 4], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004a8bd5  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a8bd8  66c743060000           -mov word ptr [ebx + 6], 0
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 004a8bde  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a8be0  8b431b                 -mov eax, dword ptr [ebx + 0x1b]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(27) /* 0x1b */);
    // 004a8be3  8933                   -mov dword ptr [ebx], esi
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.esi;
    // 004a8be5  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004a8be8  c6431d01               -mov byte ptr [ebx + 0x1d], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(29) /* 0x1d */) = 1 /*0x1*/;
    // 004a8bec  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004a8bee  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004a8bf1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8bf2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8bf3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8bf4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8bf5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a8bf6:
    // 004a8bf6  8d72fc                 -lea esi, [edx - 4]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 004a8bf9  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004a8bfc  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 004a8bfe  83ee04                 +sub esi, 4
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a8c01  8b5014                 -mov edx, dword ptr [eax + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004a8c04  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 004a8c06  e953ffffff             -jmp 0x4a8b5e
    goto L_0x004a8b5e;
L_0x004a8c0b:
    // 004a8c0b  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a8c0e  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a8c11  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a8c14  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 004a8c17  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004a8c1a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a8c1b  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004a8c1e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a8c1f  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004a8c23  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a8c27  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a8c28  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a8c29  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a8c2a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a8c2b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a8c2c  e81b570000             -call 0x4ae34c
    cpu.esp -= 4;
    sub_4ae34c(app, cpu);
    if (cpu.terminate) return;
    // 004a8c31  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004a8c34  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a8c38  c1e810                 +shr eax, 0x10
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
    // 004a8c3b  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004a8c3e  e92bffffff             -jmp 0x4a8b6e
    goto L_0x004a8b6e;
}

/* align: skip 0x90 */
void Application::sub_4a8c44(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a8c44  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a8c48  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a8c4c  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004a8c4e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a8c50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a8c50  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a8c51  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a8c52  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a8c53  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a8c54  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004a8c57  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004a8c5b  8b7c242c               -mov edi, dword ptr [esp + 0x2c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004a8c5f  8b542430               -mov edx, dword ptr [esp + 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004a8c63  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a8c65  8a481d                 -mov cl, byte ptr [eax + 0x1d]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(29) /* 0x1d */);
    // 004a8c68  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004a8c6a  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 004a8c6c  0f85f2000000           -jne 0x4a8d64
    if (!cpu.flags.zf)
    {
        goto L_0x004a8d64;
    }
L_0x004a8c72:
    // 004a8c72  807b1c00               +cmp byte ptr [ebx + 0x1c], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(28) /* 0x1c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a8c76  7412                   -je 0x4a8c8a
    if (cpu.flags.zf)
    {
        goto L_0x004a8c8a;
    }
    // 004a8c78  8b4310                 -mov eax, dword ptr [ebx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004a8c7b  8946fc                 -mov dword ptr [esi - 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004a8c7e  83ee04                 -sub esi, 4
    (cpu.esi) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a8c81  8b430c                 -mov eax, dword ptr [ebx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004a8c84  8946fc                 -mov dword ptr [esi - 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004a8c87  83ee04                 -sub esi, 4
    (cpu.esi) -= x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004a8c8a:
    // 004a8c8a  8b6c2434               -mov ebp, dword ptr [esp + 0x34]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004a8c8e  c70300000000           -mov dword ptr [ebx], 0
    app->getMemory<x86::reg32>(cpu.ebx) = 0 /*0x0*/;
    // 004a8c94  4f                     -dec edi
    (cpu.edi)--;
    // 004a8c95  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp);
    // 004a8c98  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a8c9a  7e33                   -jle 0x4a8ccf
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a8ccf;
    }
    // 004a8c9c  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a8c9f  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a8ca2  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a8ca5  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004a8ca8  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004a8cab  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a8cac  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004a8caf  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a8cb0  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004a8cb4  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a8cb8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a8cb9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a8cba  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a8cbb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a8cbc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a8cbd  e88a560000             -call 0x4ae34c
    cpu.esp -= 4;
    sub_4ae34c(app, cpu);
    if (cpu.terminate) return;
    // 004a8cc2  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004a8cc5  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a8cc9  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a8ccc  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x004a8ccf:
    // 004a8ccf  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a8cd1  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a8cd4  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004a8cd8  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004a8cdb  df2c24                 -fild qword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.esp))));
    // 004a8cde  dc0d10174c00           -fmul qword ptr [0x4c1710]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4986640) /* 0x4c1710 */));
    // 004a8ce4  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a8ce6  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004a8ce8  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 004a8cea  dee1                   -fsubrp st(1)
    cpu.fpu.st(1) = cpu.fpu.st(0) - x86::Float(cpu.fpu.st(1));
    cpu.fpu.pop();
    // 004a8cec  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a8cee  d944c608               -fld dword ptr [esi + eax*8 + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(8) /* 0x8 */ + cpu.eax * 8)));
    // 004a8cf2  d8ca                   -fmul st(2)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(2));
    // 004a8cf4  d904c6                 -fld dword ptr [esi + eax*8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + cpu.eax * 8)));
    // 004a8cf7  d8ca                   -fmul st(2)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(2));
    // 004a8cf9  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004a8cfb  d95cfd00               -fstp dword ptr [ebp + edi*8]
    app->getMemory<float>(cpu.ebp + cpu.edi * 8) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a8cff  d84cd604               -fmul dword ptr [esi + edx*8 + 4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.edx * 8));
    // 004a8d03  d944d60c               -fld dword ptr [esi + edx*8 + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(12) /* 0xc */ + cpu.edx * 8)));
    // 004a8d07  deca                   -fmulp st(2)
    cpu.fpu.st(2) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004a8d09  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004a8d0b  d95cfd04               -fstp dword ptr [ebp + edi*8 + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */ + cpu.edi * 8) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a8d0f  d944d608               -fld dword ptr [esi + edx*8 + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(8) /* 0x8 */ + cpu.edx * 8)));
    // 004a8d13  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a8d16  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a8d19  8b3b                   -mov edi, dword ptr [ebx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a8d1b  8b6b08                 -mov ebp, dword ptr [ebx + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a8d1e  d95b14                 -fstp dword ptr [ebx + 0x14]
    app->getMemory<float>(cpu.ebx + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a8d21  d944d60c               -fld dword ptr [esi + edx*8 + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(12) /* 0xc */ + cpu.edx * 8)));
    // 004a8d25  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a8d27  d95b18                 -fstp dword ptr [ebx + 0x18]
    app->getMemory<float>(cpu.ebx + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a8d2a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a8d2c  894b04                 -mov dword ptr [ebx + 4], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004a8d2f  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a8d32  66c743060000           -mov word ptr [ebx + 6], 0
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 004a8d38  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a8d3a  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a8d3d  893b                   -mov dword ptr [ebx], edi
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edi;
    // 004a8d3f  39e8                   +cmp eax, ebp
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
    // 004a8d41  7236                   -jb 0x4a8d79
    if (cpu.flags.cf)
    {
        goto L_0x004a8d79;
    }
    // 004a8d43  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a8d45  c6431c01               -mov byte ptr [ebx + 0x1c], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(28) /* 0x1c */) = 1 /*0x1*/;
    // 004a8d49  d904c6                 -fld dword ptr [esi + eax*8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + cpu.eax * 8)));
    // 004a8d4c  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a8d4e  d95b0c                 -fstp dword ptr [ebx + 0xc]
    app->getMemory<float>(cpu.ebx + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a8d51  8b54c604               -mov edx, dword ptr [esi + eax*8 + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.eax * 8);
    // 004a8d55  895310                 -mov dword ptr [ebx + 0x10], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004a8d58  c6431d01               -mov byte ptr [ebx + 0x1d], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(29) /* 0x1d */) = 1 /*0x1*/;
    // 004a8d5c  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004a8d5f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8d60  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8d61  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8d62  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8d63  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a8d64:
    // 004a8d64  8d72fc                 -lea esi, [edx - 4]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 004a8d67  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004a8d6a  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 004a8d6c  83ee04                 +sub esi, 4
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a8d6f  8b5014                 -mov edx, dword ptr [eax + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004a8d72  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 004a8d74  e9f9feffff             -jmp 0x4a8c72
    goto L_0x004a8c72;
L_0x004a8d79:
    // 004a8d79  c6431c00               -mov byte ptr [ebx + 0x1c], 0
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 004a8d7d  c6431d01               -mov byte ptr [ebx + 0x1d], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(29) /* 0x1d */) = 1 /*0x1*/;
    // 004a8d81  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004a8d84  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8d85  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8d86  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8d87  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8d88  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a8d8c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a8d8c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a8d8d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a8d8e  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a8d92  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a8d96  8b5908                 -mov ebx, dword ptr [ecx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004a8d99  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a8d9b  81fb00000100           +cmp ebx, 0x10000
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
    // 004a8da1  732c                   -jae 0x4a8dcf
    if (!cpu.flags.cf)
    {
        goto L_0x004a8dcf;
    }
    // 004a8da3  81fa00000100           +cmp edx, 0x10000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a8da9  7324                   -jae 0x4a8dcf
    if (!cpu.flags.cf)
    {
        goto L_0x004a8dcf;
    }
L_0x004a8dab:
    // 004a8dab  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004a8dae  81fa00000100           +cmp edx, 0x10000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a8db4  724b                   -jb 0x4a8e01
    if (cpu.flags.cf)
    {
        goto L_0x004a8e01;
    }
    // 004a8db6  7660                   -jbe 0x4a8e18
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a8e18;
    }
    // 004a8db8  8b5024                 -mov edx, dword ptr [eax + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 004a8dbb  c702c08a4a00           -mov dword ptr [edx], 0x4a8ac0
    app->getMemory<x86::reg32>(cpu.edx) = 4885184 /*0x4a8ac0*/;
    // 004a8dc1  8b4028                 -mov eax, dword ptr [eax + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 004a8dc4  c7003c8b4a00           -mov dword ptr [eax], 0x4a8b3c
    app->getMemory<x86::reg32>(cpu.eax) = 4885308 /*0x4a8b3c*/;
    // 004a8dca  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a8dcc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8dcd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8dce  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a8dcf:
    // 004a8dcf  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004a8dd2  39f2                   +cmp edx, esi
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
    // 004a8dd4  74d5                   -je 0x4a8dab
    if (cpu.flags.zf)
    {
        goto L_0x004a8dab;
    }
    // 004a8dd6  81fe00000100           +cmp esi, 0x10000
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a8ddc  7608                   -jbe 0x4a8de6
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a8de6;
    }
    // 004a8dde  81fa00000100           +cmp edx, 0x10000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a8de4  77c5                   -ja 0x4a8dab
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004a8dab;
    }
L_0x004a8de6:
    // 004a8de6  c6401c00               -mov byte ptr [eax + 0x1c], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 004a8dea  c6401d00               -mov byte ptr [eax + 0x1d], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(29) /* 0x1d */) = 0 /*0x0*/;
    // 004a8dee  c6401e00               -mov byte ptr [eax + 0x1e], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(30) /* 0x1e */) = 0 /*0x0*/;
    // 004a8df2  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004a8df9  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004a8dff  ebaa                   -jmp 0x4a8dab
    goto L_0x004a8dab;
L_0x004a8e01:
    // 004a8e01  8b5024                 -mov edx, dword ptr [eax + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 004a8e04  c702108b4a00           -mov dword ptr [edx], 0x4a8b10
    app->getMemory<x86::reg32>(cpu.edx) = 4885264 /*0x4a8b10*/;
    // 004a8e0a  8b4028                 -mov eax, dword ptr [eax + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 004a8e0d  c700508c4a00           -mov dword ptr [eax], 0x4a8c50
    app->getMemory<x86::reg32>(cpu.eax) = 4885584 /*0x4a8c50*/;
    // 004a8e13  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a8e15  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8e16  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8e17  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a8e18:
    // 004a8e18  8b5024                 -mov edx, dword ptr [eax + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 004a8e1b  c702088b4a00           -mov dword ptr [edx], 0x4a8b08
    app->getMemory<x86::reg32>(cpu.edx) = 4885256 /*0x4a8b08*/;
    // 004a8e21  8b4028                 -mov eax, dword ptr [eax + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 004a8e24  c700448c4a00           -mov dword ptr [eax], 0x4a8c44
    app->getMemory<x86::reg32>(cpu.eax) = 4885572 /*0x4a8c44*/;
    // 004a8e2a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a8e2c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8e2d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8e2e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a8e30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a8e30  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a8e34  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004a8e3a  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004a8e41  c6401c00               -mov byte ptr [eax + 0x1c], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 004a8e45  c6401d00               -mov byte ptr [eax + 0x1d], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(29) /* 0x1d */) = 0 /*0x0*/;
    // 004a8e49  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a8e4d  c6401e00               -mov byte ptr [eax + 0x1e], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(30) /* 0x1e */) = 0 /*0x0*/;
    // 004a8e51  895020                 -mov dword ptr [eax + 0x20], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 004a8e54  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a8e58  895024                 -mov dword ptr [eax + 0x24], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 004a8e5b  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a8e5f  895028                 -mov dword ptr [eax + 0x28], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 004a8e62  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004a8e65  c7008c8d4a00           -mov dword ptr [eax], 0x4a8d8c
    app->getMemory<x86::reg32>(cpu.eax) = 4885900 /*0x4a8d8c*/;
    // 004a8e6b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a8e6d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4a8e70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a8e70  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a8e71  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a8e74  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a8e78  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a8e7c  c1e303                 -shl ebx, 3
    cpu.ebx <<= 3 /*0x3*/ % 32;
    // 004a8e7f  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a8e83  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a8e85  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a8e87  39d9                   +cmp ecx, ebx
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
    // 004a8e89  7341                   -jae 0x4a8ecc
    if (!cpu.flags.cf)
    {
        goto L_0x004a8ecc;
    }
L_0x004a8e8b:
    // 004a8e8b  d94004                 -fld dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */)));
    // 004a8e8e  d800                   -fadd dword ptr [eax]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax));
    // 004a8e90  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004a8e92  dc0d18174c00           -fmul qword ptr [0x4c1718]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4986648) /* 0x4c1718 */));
    // 004a8e98  ddd1                   -fst st(1)
    cpu.fpu.st(1) = x86::Float(cpu.fpu.st(0));
    // 004a8e9a  dc0520174c00           -fadd qword ptr [0x4c1720]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(4986656) /* 0x4c1720 */));
    // 004a8ea0  ddd9                   -fstp st(1)
    cpu.fpu.st(1) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a8ea2  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a8ea4  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004a8ea6  81e1ffff0f00           -and ecx, 0xfffff
    cpu.ecx &= x86::reg32(x86::sreg32(1048575 /*0xfffff*/));
    // 004a8eac  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a8eaf  83f97f                 +cmp ecx, 0x7f
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
    // 004a8eb2  7622                   -jbe 0x4a8ed6
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a8ed6;
    }
    // 004a8eb4  81f980ff0f00           +cmp ecx, 0xfff80
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1048448 /*0xfff80*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a8eba  731a                   -jae 0x4a8ed6
    if (!cpu.flags.cf)
    {
        goto L_0x004a8ed6;
    }
    // 004a8ebc  81f900000800           +cmp ecx, 0x80000
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
    // 004a8ec2  730d                   -jae 0x4a8ed1
    if (!cpu.flags.cf)
    {
        goto L_0x004a8ed1;
    }
    // 004a8ec4  c602ff                 -mov byte ptr [edx], 0xff
    app->getMemory<x86::reg8>(cpu.edx) = 255 /*0xff*/;
L_0x004a8ec7:
    // 004a8ec7  42                     -inc edx
    (cpu.edx)++;
    // 004a8ec8  39d8                   +cmp eax, ebx
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
    // 004a8eca  72bf                   -jb 0x4a8e8b
    if (cpu.flags.cf)
    {
        goto L_0x004a8e8b;
    }
L_0x004a8ecc:
    // 004a8ecc  83c408                 +add esp, 8
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
    // 004a8ecf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8ed0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a8ed1:
    // 004a8ed1  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
    // 004a8ed4  ebf1                   -jmp 0x4a8ec7
    goto L_0x004a8ec7;
L_0x004a8ed6:
    // 004a8ed6  80c180                 -add cl, 0x80
    (cpu.cl) += x86::reg8(x86::sreg8(128 /*0x80*/));
    // 004a8ed9  880a                   -mov byte ptr [edx], cl
    app->getMemory<x86::reg8>(cpu.edx) = cpu.cl;
    // 004a8edb  42                     -inc edx
    (cpu.edx)++;
    // 004a8edc  39d8                   +cmp eax, ebx
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
    // 004a8ede  72ab                   -jb 0x4a8e8b
    if (cpu.flags.cf)
    {
        goto L_0x004a8e8b;
    }
    // 004a8ee0  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a8ee3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8ee4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a8ef0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a8ef0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a8ef1  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a8ef4  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a8ef8  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a8efc  c1e303                 -shl ebx, 3
    cpu.ebx <<= 3 /*0x3*/ % 32;
    // 004a8eff  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a8f03  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a8f05  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a8f07  39d9                   +cmp ecx, ebx
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
    // 004a8f09  7339                   -jae 0x4a8f44
    if (!cpu.flags.cf)
    {
        goto L_0x004a8f44;
    }
L_0x004a8f0b:
    // 004a8f0b  d900                   -fld dword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax)));
    // 004a8f0d  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004a8f0f  dc0528174c00           -fadd qword ptr [0x4c1728]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(4986664) /* 0x4c1728 */));
    // 004a8f15  ddd9                   -fstp st(1)
    cpu.fpu.st(1) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a8f17  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a8f19  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004a8f1b  81e1ffff0f00           -and ecx, 0xfffff
    cpu.ecx &= x86::reg32(x86::sreg32(1048575 /*0xfffff*/));
    // 004a8f21  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a8f24  81f9ff7f0000           +cmp ecx, 0x7fff
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
    // 004a8f2a  7622                   -jbe 0x4a8f4e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a8f4e;
    }
    // 004a8f2c  81f900800f00           +cmp ecx, 0xf8000
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1015808 /*0xf8000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a8f32  731a                   -jae 0x4a8f4e
    if (!cpu.flags.cf)
    {
        goto L_0x004a8f4e;
    }
    // 004a8f34  81f900000800           +cmp ecx, 0x80000
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
    // 004a8f3a  730d                   -jae 0x4a8f49
    if (!cpu.flags.cf)
    {
        goto L_0x004a8f49;
    }
    // 004a8f3c  c602ff                 -mov byte ptr [edx], 0xff
    app->getMemory<x86::reg8>(cpu.edx) = 255 /*0xff*/;
L_0x004a8f3f:
    // 004a8f3f  42                     -inc edx
    (cpu.edx)++;
    // 004a8f40  39d8                   +cmp eax, ebx
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
    // 004a8f42  72c7                   -jb 0x4a8f0b
    if (cpu.flags.cf)
    {
        goto L_0x004a8f0b;
    }
L_0x004a8f44:
    // 004a8f44  83c408                 +add esp, 8
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
    // 004a8f47  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8f48  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a8f49:
    // 004a8f49  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
    // 004a8f4c  ebf1                   -jmp 0x4a8f3f
    goto L_0x004a8f3f;
L_0x004a8f4e:
    // 004a8f4e  c1e908                 -shr ecx, 8
    cpu.ecx >>= 8 /*0x8*/ % 32;
    // 004a8f51  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a8f57  81c180000000           -add ecx, 0x80
    (cpu.ecx) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 004a8f5d  880a                   -mov byte ptr [edx], cl
    app->getMemory<x86::reg8>(cpu.edx) = cpu.cl;
    // 004a8f5f  42                     -inc edx
    (cpu.edx)++;
    // 004a8f60  39d8                   +cmp eax, ebx
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
    // 004a8f62  72a7                   -jb 0x4a8f0b
    if (cpu.flags.cf)
    {
        goto L_0x004a8f0b;
    }
    // 004a8f64  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a8f67  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8f68  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a8f70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a8f70  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a8f71  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a8f74  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a8f78  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a8f7c  c1e303                 -shl ebx, 3
    cpu.ebx <<= 3 /*0x3*/ % 32;
    // 004a8f7f  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a8f83  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a8f85  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a8f87  39d9                   +cmp ecx, ebx
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
    // 004a8f89  7348                   -jae 0x4a8fd3
    if (!cpu.flags.cf)
    {
        goto L_0x004a8fd3;
    }
L_0x004a8f8b:
    // 004a8f8b  d94004                 -fld dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */)));
    // 004a8f8e  d800                   -fadd dword ptr [eax]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax));
    // 004a8f90  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004a8f92  dc0d30174c00           -fmul qword ptr [0x4c1730]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(4986672) /* 0x4c1730 */));
    // 004a8f98  ddd1                   -fst st(1)
    cpu.fpu.st(1) = x86::Float(cpu.fpu.st(0));
    // 004a8f9a  dc0538174c00           -fadd qword ptr [0x4c1738]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(4986680) /* 0x4c1738 */));
    // 004a8fa0  ddd9                   -fstp st(1)
    cpu.fpu.st(1) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a8fa2  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a8fa4  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004a8fa6  81e1ffff0f00           -and ecx, 0xfffff
    cpu.ecx &= x86::reg32(x86::sreg32(1048575 /*0xfffff*/));
    // 004a8fac  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a8faf  81f9ff7f0000           +cmp ecx, 0x7fff
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
    // 004a8fb5  7628                   -jbe 0x4a8fdf
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a8fdf;
    }
    // 004a8fb7  81f900800f00           +cmp ecx, 0xf8000
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1015808 /*0xf8000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a8fbd  7320                   -jae 0x4a8fdf
    if (!cpu.flags.cf)
    {
        goto L_0x004a8fdf;
    }
    // 004a8fbf  81f900000800           +cmp ecx, 0x80000
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
    // 004a8fc5  7311                   -jae 0x4a8fd8
    if (!cpu.flags.cf)
    {
        goto L_0x004a8fd8;
    }
    // 004a8fc7  66c702ff7f             -mov word ptr [edx], 0x7fff
    app->getMemory<x86::reg16>(cpu.edx) = 32767 /*0x7fff*/;
L_0x004a8fcc:
    // 004a8fcc  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004a8fcf  39d8                   +cmp eax, ebx
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
    // 004a8fd1  72b8                   -jb 0x4a8f8b
    if (cpu.flags.cf)
    {
        goto L_0x004a8f8b;
    }
L_0x004a8fd3:
    // 004a8fd3  83c408                 +add esp, 8
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
    // 004a8fd6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8fd7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a8fd8:
    // 004a8fd8  66c7020080             -mov word ptr [edx], 0x8000
    app->getMemory<x86::reg16>(cpu.edx) = 32768 /*0x8000*/;
    // 004a8fdd  ebed                   -jmp 0x4a8fcc
    goto L_0x004a8fcc;
L_0x004a8fdf:
    // 004a8fdf  66890a                 -mov word ptr [edx], cx
    app->getMemory<x86::reg16>(cpu.edx) = cpu.cx;
    // 004a8fe2  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004a8fe5  39d8                   +cmp eax, ebx
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
    // 004a8fe7  72a2                   -jb 0x4a8f8b
    if (cpu.flags.cf)
    {
        goto L_0x004a8f8b;
    }
    // 004a8fe9  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a8fec  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8fed  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4a8ff0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a8ff0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a8ff1  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a8ff4  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a8ff8  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a8ffc  c1e303                 -shl ebx, 3
    cpu.ebx <<= 3 /*0x3*/ % 32;
    // 004a8fff  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a9003  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a9005  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a9007  39d9                   +cmp ecx, ebx
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
    // 004a9009  733d                   -jae 0x4a9048
    if (!cpu.flags.cf)
    {
        goto L_0x004a9048;
    }
L_0x004a900b:
    // 004a900b  d900                   -fld dword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax)));
    // 004a900d  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004a900f  dc0540174c00           -fadd qword ptr [0x4c1740]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(4986688) /* 0x4c1740 */));
    // 004a9015  ddd9                   -fstp st(1)
    cpu.fpu.st(1) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a9017  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a9019  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004a901b  81e1ffff0f00           -and ecx, 0xfffff
    cpu.ecx &= x86::reg32(x86::sreg32(1048575 /*0xfffff*/));
    // 004a9021  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a9024  81f9ff7f0000           +cmp ecx, 0x7fff
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
    // 004a902a  7628                   -jbe 0x4a9054
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a9054;
    }
    // 004a902c  81f900800f00           +cmp ecx, 0xf8000
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1015808 /*0xf8000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a9032  7320                   -jae 0x4a9054
    if (!cpu.flags.cf)
    {
        goto L_0x004a9054;
    }
    // 004a9034  81f900000800           +cmp ecx, 0x80000
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
    // 004a903a  7311                   -jae 0x4a904d
    if (!cpu.flags.cf)
    {
        goto L_0x004a904d;
    }
    // 004a903c  66c702ff7f             -mov word ptr [edx], 0x7fff
    app->getMemory<x86::reg16>(cpu.edx) = 32767 /*0x7fff*/;
L_0x004a9041:
    // 004a9041  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004a9044  39d8                   +cmp eax, ebx
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
    // 004a9046  72c3                   -jb 0x4a900b
    if (cpu.flags.cf)
    {
        goto L_0x004a900b;
    }
L_0x004a9048:
    // 004a9048  83c408                 +add esp, 8
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
    // 004a904b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a904c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a904d:
    // 004a904d  66c7020080             -mov word ptr [edx], 0x8000
    app->getMemory<x86::reg16>(cpu.edx) = 32768 /*0x8000*/;
    // 004a9052  ebed                   -jmp 0x4a9041
    goto L_0x004a9041;
L_0x004a9054:
    // 004a9054  66890a                 -mov word ptr [edx], cx
    app->getMemory<x86::reg16>(cpu.edx) = cpu.cx;
    // 004a9057  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004a905a  39d8                   +cmp eax, ebx
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
    // 004a905c  72ad                   -jb 0x4a900b
    if (cpu.flags.cf)
    {
        goto L_0x004a900b;
    }
    // 004a905e  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a9061  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9062  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4a9064(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9064  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a9065  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a9067  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a9068  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a9069  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a906a  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a906d  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a9070  b800000000             -mov eax, 0
    cpu.eax = 0 /*0x0*/;
    // 004a9075  83f90f                 +cmp ecx, 0xf
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
    // 004a9078  7e3d                   -jle 0x4a90b7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a90b7;
    }
    // 004a907a  83e90f                 -sub ecx, 0xf
    (cpu.ecx) -= x86::reg32(x86::sreg32(15 /*0xf*/));
L_0x004a907d:
    // 004a907d  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 004a907f  894704                 -mov dword ptr [edi + 4], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004a9082  894708                 -mov dword ptr [edi + 8], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004a9085  89470c                 -mov dword ptr [edi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004a9088  894710                 -mov dword ptr [edi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004a908b  894714                 -mov dword ptr [edi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004a908e  894718                 -mov dword ptr [edi + 0x18], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004a9091  89471c                 -mov dword ptr [edi + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004a9094  894720                 -mov dword ptr [edi + 0x20], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 004a9097  894724                 -mov dword ptr [edi + 0x24], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 004a909a  894728                 -mov dword ptr [edi + 0x28], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 004a909d  89472c                 -mov dword ptr [edi + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 004a90a0  894730                 -mov dword ptr [edi + 0x30], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 004a90a3  894734                 -mov dword ptr [edi + 0x34], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 004a90a6  894738                 -mov dword ptr [edi + 0x38], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 004a90a9  89473c                 -mov dword ptr [edi + 0x3c], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(60) /* 0x3c */) = cpu.eax;
    // 004a90ac  83c740                 -add edi, 0x40
    (cpu.edi) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004a90af  83e910                 +sub ecx, 0x10
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
    // 004a90b2  7fc9                   -jg 0x4a907d
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a907d;
    }
    // 004a90b4  83c10f                 -add ecx, 0xf
    (cpu.ecx) += x86::reg32(x86::sreg32(15 /*0xf*/));
L_0x004a90b7:
    // 004a90b7  83f900                 +cmp ecx, 0
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
    // 004a90ba  7e0a                   -jle 0x4a90c6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a90c6;
    }
    // 004a90bc  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 004a90be  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a90c1  83e901                 +sub ecx, 1
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
    // 004a90c4  7ff1                   -jg 0x4a90b7
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a90b7;
    }
L_0x004a90c6:
    // 004a90c6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a90c7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a90c8  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a90c9  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a90ca  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4a90cc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a90cc  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a90cd  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a90cf  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a90d0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a90d1  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a90d4  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a90d7  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004a90da  c70029914a00           -mov dword ptr [eax], 0x4a9129
    app->getMemory<x86::reg32>(cpu.eax) = 4886825 /*0x4a9129*/;
    // 004a90e0  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004a90e3  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004a90e6  c700f0904a00           -mov dword ptr [eax], 0x4a90f0
    app->getMemory<x86::reg32>(cpu.eax) = 4886768 /*0x4a90f0*/;
    // 004a90ec  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a90ed  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a90ee  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a90ef  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a90f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a90f0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a90f1  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a90f3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a90f4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a90f5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a90f6  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a90f9  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a90fc  c1e018                 -shl eax, 0x18
    cpu.eax <<= 24 /*0x18*/ % 32;
    // 004a90ff  8b5d0c                 -mov ebx, dword ptr [ebp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a9102  668bc3                 -mov ax, bx
    cpu.ax = cpu.bx;
    // 004a9105  66c1e008               -shl ax, 8
    cpu.ax <<= 8 /*0x8*/ % 32;
    // 004a9109  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 004a910b  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004a910e  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004a9111  c1e018                 -shl eax, 0x18
    cpu.eax <<= 24 /*0x18*/ % 32;
    // 004a9114  8b5d10                 -mov ebx, dword ptr [ebp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004a9117  668bc3                 -mov ax, bx
    cpu.ax = cpu.bx;
    // 004a911a  66c1e008               -shl ax, 8
    cpu.ax <<= 8 /*0x8*/ % 32;
    // 004a911e  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004a9121  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004a9124  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9125  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9126  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9127  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9128  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a9129(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9129  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a912a  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a912c  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004a912d  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a9130  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a9133  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004a9136  0f6f06                 -movq mm0, qword ptr [esi]
    cpu.mmx.mm0 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.esi));
    // 004a9139  0f6f4e08               -movq mm1, qword ptr [esi + 8]
    cpu.mmx.mm1 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.esi + x86::reg32(8) /* 0x8 */));
    // 004a913d  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004a9140  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a9142  83e003                 -and eax, 3
    cpu.eax &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004a9145  83f800                 +cmp eax, 0
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a9148  7405                   -je 0x4a914f
    if (cpu.flags.zf)
    {
        goto L_0x004a914f;
    }
    // 004a914a  83e904                 +sub ecx, 4
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
    // 004a914d  7c3e                   -jl 0x4a918d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a918d;
    }
L_0x004a914f:
    // 004a914f  0f6fd0                 -movq mm2, mm0
    cpu.mmx.mm2 = cpu.mmx.mm0;
    // 004a9152  0f6fe1                 -movq mm4, mm1
    cpu.mmx.mm4 = cpu.mmx.mm1;
    // 004a9155  0f6e2f                 -movd mm5, dword ptr [edi]
    cpu.mmx.mm5 = { _mm_loadu_si32(&app->getMemory<x86::reg32>(cpu.edi)) };
    // 004a9158  0f60f5                 -punpcklbw mm6, mm5
    cpu.mmx.mm6 = { _mm_unpacklo_epi8(cpu.mmx.mm6, cpu.mmx.mm5) };
    // 004a915b  0fe5d6                 -pmulhw mm2, mm6
    cpu.mmx.mm2 = { _mm_mulhi_epi16(cpu.mmx.mm2, cpu.mmx.mm6) };
    // 004a915e  0fe5e6                 -pmulhw mm4, mm6
    cpu.mmx.mm4 = { _mm_mulhi_epi16(cpu.mmx.mm4, cpu.mmx.mm6) };
    // 004a9161  0f6fda                 -movq mm3, mm2
    cpu.mmx.mm3 = cpu.mmx.mm2;
    // 004a9164  0f69dc                 -punpckhwd mm3, mm4
    cpu.mmx.mm3 = { _mm_unpacklo_epi16(_mm_srli_epi64(cpu.mmx.mm3, 32), _mm_srli_epi64(cpu.mmx.mm4, 32)) };
    // 004a9167  0f61d4                 -punpcklwd mm2, mm4
    cpu.mmx.mm2 = { _mm_unpacklo_epi16(cpu.mmx.mm2, cpu.mmx.mm4) };
    // 004a916a  0fed5500               -paddsw mm2, qword ptr [ebp]
    cpu.mmx.mm2 = { _mm_adds_epi16(cpu.mmx.mm2, x86::from_reg64(app->getMemory<x86::reg64>(cpu.ebp))) };
    // 004a916e  0fed5d08               -paddsw mm3, qword ptr [ebp + 8]
    cpu.mmx.mm3 = { _mm_adds_epi16(cpu.mmx.mm3, x86::from_reg64(app->getMemory<x86::reg64>(cpu.ebp + x86::reg32(8) /* 0x8 */))) };
    // 004a9172  0f7f5500               -movq qword ptr [ebp], mm2
    app->getMemory<x86::reg64>(cpu.ebp) = cpu.mmx.mm2;
    // 004a9176  0f7f5d08               -movq qword ptr [ebp + 8], mm3
    app->getMemory<x86::reg64>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.mmx.mm3;
    // 004a917a  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a917d  83c510                 -add ebp, 0x10
    (cpu.ebp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a9180  83e904                 +sub ecx, 4
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
    // 004a9183  7fca                   -jg 0x4a914f
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a914f;
    }
    // 004a9185  83f900                 +cmp ecx, 0
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
    // 004a9188  7503                   -jne 0x4a918d
    if (!cpu.flags.zf)
    {
        goto L_0x004a918d;
    }
    // 004a918a  61                     -popal 
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
    // 004a918b  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a918c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a918d:
    // 004a918d  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a9190  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004a9192  b800000000             -mov eax, 0
    cpu.eax = 0 /*0x0*/;
L_0x004a9197:
    // 004a9197  0f6fd0                 -movq mm2, mm0
    cpu.mmx.mm2 = cpu.mmx.mm0;
    // 004a919a  0f6fe1                 -movq mm4, mm1
    cpu.mmx.mm4 = cpu.mmx.mm1;
    // 004a919d  8a27                   -mov ah, byte ptr [edi]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edi);
    // 004a919f  0f6ef0                 -movd mm6, eax
    cpu.mmx.mm6 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004a91a2  0fe5d6                 -pmulhw mm2, mm6
    cpu.mmx.mm2 = { _mm_mulhi_epi16(cpu.mmx.mm2, cpu.mmx.mm6) };
    // 004a91a5  0fe5e6                 -pmulhw mm4, mm6
    cpu.mmx.mm4 = { _mm_mulhi_epi16(cpu.mmx.mm4, cpu.mmx.mm6) };
    // 004a91a8  0f6fda                 -movq mm3, mm2
    cpu.mmx.mm3 = cpu.mmx.mm2;
    // 004a91ab  0f69dc                 -punpckhwd mm3, mm4
    cpu.mmx.mm3 = { _mm_unpacklo_epi16(_mm_srli_epi64(cpu.mmx.mm3, 32), _mm_srli_epi64(cpu.mmx.mm4, 32)) };
    // 004a91ae  0f61d4                 -punpcklwd mm2, mm4
    cpu.mmx.mm2 = { _mm_unpacklo_epi16(cpu.mmx.mm2, cpu.mmx.mm4) };
    // 004a91b1  0f6e5d00               -movd mm3, dword ptr [ebp]
    cpu.mmx.mm3 = { _mm_loadu_si32(&app->getMemory<x86::reg32>(cpu.ebp)) };
    // 004a91b5  0fedda                 -paddsw mm3, mm2
    cpu.mmx.mm3 = { _mm_adds_epi16(cpu.mmx.mm3, cpu.mmx.mm2) };
    // 004a91b8  0f7e5d00               -movd dword ptr [ebp], mm3
    _mm_storeu_si32(&app->getMemory<x86::reg32>(cpu.ebp), cpu.mmx.mm3);
    // 004a91bc  83c701                 -add edi, 1
    (cpu.edi) += x86::reg32(x86::sreg32(1 /*0x1*/));
    // 004a91bf  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a91c2  83c101                 +add ecx, 1
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
    // 004a91c5  7cd0                   -jl 0x4a9197
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a9197;
    }
    // 004a91c7  61                     -popal 
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
    // 004a91c8  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a91c9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4a91cc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a91cc  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a91cd  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a91cf  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a91d0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a91d1  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a91d4  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a91d7  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004a91da  c70013924a00           -mov dword ptr [eax], 0x4a9213
    app->getMemory<x86::reg32>(cpu.eax) = 4887059 /*0x4a9213*/;
    // 004a91e0  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004a91e3  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004a91e6  c700f0914a00           -mov dword ptr [eax], 0x4a91f0
    app->getMemory<x86::reg32>(cpu.eax) = 4887024 /*0x4a91f0*/;
    // 004a91ec  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a91ed  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a91ee  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a91ef  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a91f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a91f0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a91f1  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a91f3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a91f4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a91f5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a91f6  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a91f9  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004a91fc  c1e018                 -shl eax, 0x18
    cpu.eax <<= 24 /*0x18*/ % 32;
    // 004a91ff  8b5d0c                 -mov ebx, dword ptr [ebp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a9202  668bc3                 -mov ax, bx
    cpu.ax = cpu.bx;
    // 004a9205  66c1e008               -shl ax, 8
    cpu.ax <<= 8 /*0x8*/ % 32;
    // 004a9209  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 004a920b  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004a920e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a920f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9210  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9211  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9212  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a9213(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9213  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a9214  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a9216  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004a9217  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a921a  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a921d  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004a9220  0f6f06                 -movq mm0, qword ptr [esi]
    cpu.mmx.mm0 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.esi));
    // 004a9223  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004a9226  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a9228  83e003                 -and eax, 3
    cpu.eax &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004a922b  83f800                 +cmp eax, 0
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a922e  7405                   -je 0x4a9235
    if (cpu.flags.zf)
    {
        goto L_0x004a9235;
    }
    // 004a9230  83e904                 +sub ecx, 4
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
    // 004a9233  7c38                   -jl 0x4a926d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a926d;
    }
L_0x004a9235:
    // 004a9235  0f6f1f                 -movq mm3, qword ptr [edi]
    cpu.mmx.mm3 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edi));
    // 004a9238  0f6fc8                 -movq mm1, mm0
    cpu.mmx.mm1 = cpu.mmx.mm0;
    // 004a923b  0f6fd0                 -movq mm2, mm0
    cpu.mmx.mm2 = cpu.mmx.mm0;
    // 004a923e  0f60e3                 -punpcklbw mm4, mm3
    cpu.mmx.mm4 = { _mm_unpacklo_epi8(cpu.mmx.mm4, cpu.mmx.mm3) };
    // 004a9241  0f68eb                 -punpckhbw mm5, mm3
    cpu.mmx.mm5 = { _mm_unpacklo_epi8(_mm_srli_epi64(cpu.mmx.mm5, 32), _mm_srli_epi64(cpu.mmx.mm3, 32)) };
    // 004a9244  0fe5cc                 -pmulhw mm1, mm4
    cpu.mmx.mm1 = { _mm_mulhi_epi16(cpu.mmx.mm1, cpu.mmx.mm4) };
    // 004a9247  0fe5d5                 -pmulhw mm2, mm5
    cpu.mmx.mm2 = { _mm_mulhi_epi16(cpu.mmx.mm2, cpu.mmx.mm5) };
    // 004a924a  0fed4d00               -paddsw mm1, qword ptr [ebp]
    cpu.mmx.mm1 = { _mm_adds_epi16(cpu.mmx.mm1, x86::from_reg64(app->getMemory<x86::reg64>(cpu.ebp))) };
    // 004a924e  0fed5508               -paddsw mm2, qword ptr [ebp + 8]
    cpu.mmx.mm2 = { _mm_adds_epi16(cpu.mmx.mm2, x86::from_reg64(app->getMemory<x86::reg64>(cpu.ebp + x86::reg32(8) /* 0x8 */))) };
    // 004a9252  0f7f4d00               -movq qword ptr [ebp], mm1
    app->getMemory<x86::reg64>(cpu.ebp) = cpu.mmx.mm1;
    // 004a9256  0f7f5508               -movq qword ptr [ebp + 8], mm2
    app->getMemory<x86::reg64>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.mmx.mm2;
    // 004a925a  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a925d  83c510                 -add ebp, 0x10
    (cpu.ebp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a9260  83e904                 +sub ecx, 4
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
    // 004a9263  7fd0                   -jg 0x4a9235
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a9235;
    }
    // 004a9265  83f900                 +cmp ecx, 0
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
    // 004a9268  7503                   -jne 0x4a926d
    if (!cpu.flags.zf)
    {
        goto L_0x004a926d;
    }
    // 004a926a  61                     -popal 
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
    // 004a926b  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a926c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a926d:
    // 004a926d  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a9270  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
L_0x004a9272:
    // 004a9272  8a4701                 -mov al, byte ptr [edi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 004a9275  c1e018                 -shl eax, 0x18
    cpu.eax <<= 24 /*0x18*/ % 32;
    // 004a9278  8a27                   -mov ah, byte ptr [edi]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edi);
    // 004a927a  0f6ec8                 -movd mm1, eax
    cpu.mmx.mm1 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004a927d  0fe5c8                 -pmulhw mm1, mm0
    cpu.mmx.mm1 = { _mm_mulhi_epi16(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 004a9280  0f6e5500               -movd mm2, dword ptr [ebp]
    cpu.mmx.mm2 = { _mm_loadu_si32(&app->getMemory<x86::reg32>(cpu.ebp)) };
    // 004a9284  0fedca                 -paddsw mm1, mm2
    cpu.mmx.mm1 = { _mm_adds_epi16(cpu.mmx.mm1, cpu.mmx.mm2) };
    // 004a9287  0f7e4d00               -movd dword ptr [ebp], mm1
    _mm_storeu_si32(&app->getMemory<x86::reg32>(cpu.ebp), cpu.mmx.mm1);
    // 004a928b  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004a928e  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a9291  83c101                 +add ecx, 1
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
    // 004a9294  7cdc                   -jl 0x4a9272
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a9272;
    }
    // 004a9296  61                     -popal 
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
    // 004a9297  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9298  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_4a929c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a929c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a929d  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a929f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a92a0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a92a1  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a92a4  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a92a7  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004a92aa  c700f9924a00           -mov dword ptr [eax], 0x4a92f9
    app->getMemory<x86::reg32>(cpu.eax) = 4887289 /*0x4a92f9*/;
    // 004a92b0  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004a92b3  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004a92b6  c700c0924a00           -mov dword ptr [eax], 0x4a92c0
    app->getMemory<x86::reg32>(cpu.eax) = 4887232 /*0x4a92c0*/;
    // 004a92bc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a92bd  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a92be  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a92bf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a92c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a92c0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a92c1  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a92c3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a92c4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a92c5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a92c6  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a92c9  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a92cc  c1e018                 -shl eax, 0x18
    cpu.eax <<= 24 /*0x18*/ % 32;
    // 004a92cf  8b5d0c                 -mov ebx, dword ptr [ebp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a92d2  668bc3                 -mov ax, bx
    cpu.ax = cpu.bx;
    // 004a92d5  66c1e008               -shl ax, 8
    cpu.ax <<= 8 /*0x8*/ % 32;
    // 004a92d9  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 004a92db  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004a92de  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004a92e1  c1e018                 -shl eax, 0x18
    cpu.eax <<= 24 /*0x18*/ % 32;
    // 004a92e4  8b5d10                 -mov ebx, dword ptr [ebp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004a92e7  668bc3                 -mov ax, bx
    cpu.ax = cpu.bx;
    // 004a92ea  66c1e008               -shl ax, 8
    cpu.ax <<= 8 /*0x8*/ % 32;
    // 004a92ee  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004a92f1  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004a92f4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a92f5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a92f6  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a92f7  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a92f8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a92f9(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a92f9  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a92fa  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a92fc  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004a92fd  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a9300  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a9303  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004a9306  0f6f06                 -movq mm0, qword ptr [esi]
    cpu.mmx.mm0 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.esi));
    // 004a9309  0f6f4e08               -movq mm1, qword ptr [esi + 8]
    cpu.mmx.mm1 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.esi + x86::reg32(8) /* 0x8 */));
    // 004a930d  8b5d14                 -mov ebx, dword ptr [ebp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004a9310  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a9312  83e003                 -and eax, 3
    cpu.eax &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004a9315  83f800                 +cmp eax, 0
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a9318  7405                   -je 0x4a931f
    if (cpu.flags.zf)
    {
        goto L_0x004a931f;
    }
    // 004a931a  83e904                 +sub ecx, 4
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
    // 004a931d  7c39                   -jl 0x4a9358
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a9358;
    }
L_0x004a931f:
    // 004a931f  0f6fd0                 -movq mm2, mm0
    cpu.mmx.mm2 = cpu.mmx.mm0;
    // 004a9322  0f6fe1                 -movq mm4, mm1
    cpu.mmx.mm4 = cpu.mmx.mm1;
    // 004a9325  0f6f37                 -movq mm6, qword ptr [edi]
    cpu.mmx.mm6 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edi));
    // 004a9328  0fe5d6                 -pmulhw mm2, mm6
    cpu.mmx.mm2 = { _mm_mulhi_epi16(cpu.mmx.mm2, cpu.mmx.mm6) };
    // 004a932b  0fe5e6                 -pmulhw mm4, mm6
    cpu.mmx.mm4 = { _mm_mulhi_epi16(cpu.mmx.mm4, cpu.mmx.mm6) };
    // 004a932e  0f6fda                 -movq mm3, mm2
    cpu.mmx.mm3 = cpu.mmx.mm2;
    // 004a9331  0f69dc                 -punpckhwd mm3, mm4
    cpu.mmx.mm3 = { _mm_unpacklo_epi16(_mm_srli_epi64(cpu.mmx.mm3, 32), _mm_srli_epi64(cpu.mmx.mm4, 32)) };
    // 004a9334  0f61d4                 -punpcklwd mm2, mm4
    cpu.mmx.mm2 = { _mm_unpacklo_epi16(cpu.mmx.mm2, cpu.mmx.mm4) };
    // 004a9337  0fed13                 -paddsw mm2, qword ptr [ebx]
    cpu.mmx.mm2 = { _mm_adds_epi16(cpu.mmx.mm2, x86::from_reg64(app->getMemory<x86::reg64>(cpu.ebx))) };
    // 004a933a  0fed5b08               -paddsw mm3, qword ptr [ebx + 8]
    cpu.mmx.mm3 = { _mm_adds_epi16(cpu.mmx.mm3, x86::from_reg64(app->getMemory<x86::reg64>(cpu.ebx + x86::reg32(8) /* 0x8 */))) };
    // 004a933e  0f7f13                 -movq qword ptr [ebx], mm2
    app->getMemory<x86::reg64>(cpu.ebx) = cpu.mmx.mm2;
    // 004a9341  0f7f5b08               -movq qword ptr [ebx + 8], mm3
    app->getMemory<x86::reg64>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.mmx.mm3;
    // 004a9345  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a9348  83c310                 -add ebx, 0x10
    (cpu.ebx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a934b  83e904                 +sub ecx, 4
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
    // 004a934e  7fcf                   -jg 0x4a931f
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a931f;
    }
    // 004a9350  83f900                 +cmp ecx, 0
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
    // 004a9353  7503                   -jne 0x4a9358
    if (!cpu.flags.zf)
    {
        goto L_0x004a9358;
    }
    // 004a9355  61                     -popal 
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
    // 004a9356  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9357  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a9358:
    // 004a9358  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a935b  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
L_0x004a935d:
    // 004a935d  0f6fd0                 -movq mm2, mm0
    cpu.mmx.mm2 = cpu.mmx.mm0;
    // 004a9360  0f6fe1                 -movq mm4, mm1
    cpu.mmx.mm4 = cpu.mmx.mm1;
    // 004a9363  668b07                 -mov ax, word ptr [edi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edi);
    // 004a9366  0f6ef0                 -movd mm6, eax
    cpu.mmx.mm6 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004a9369  0fe5d6                 -pmulhw mm2, mm6
    cpu.mmx.mm2 = { _mm_mulhi_epi16(cpu.mmx.mm2, cpu.mmx.mm6) };
    // 004a936c  0fe5e6                 -pmulhw mm4, mm6
    cpu.mmx.mm4 = { _mm_mulhi_epi16(cpu.mmx.mm4, cpu.mmx.mm6) };
    // 004a936f  0f6fda                 -movq mm3, mm2
    cpu.mmx.mm3 = cpu.mmx.mm2;
    // 004a9372  0f69dc                 -punpckhwd mm3, mm4
    cpu.mmx.mm3 = { _mm_unpacklo_epi16(_mm_srli_epi64(cpu.mmx.mm3, 32), _mm_srli_epi64(cpu.mmx.mm4, 32)) };
    // 004a9375  0f61d4                 -punpcklwd mm2, mm4
    cpu.mmx.mm2 = { _mm_unpacklo_epi16(cpu.mmx.mm2, cpu.mmx.mm4) };
    // 004a9378  0f6e1b                 -movd mm3, dword ptr [ebx]
    cpu.mmx.mm3 = { _mm_loadu_si32(&app->getMemory<x86::reg32>(cpu.ebx)) };
    // 004a937b  0fedda                 -paddsw mm3, mm2
    cpu.mmx.mm3 = { _mm_adds_epi16(cpu.mmx.mm3, cpu.mmx.mm2) };
    // 004a937e  0f7e1b                 -movd dword ptr [ebx], mm3
    _mm_storeu_si32(&app->getMemory<x86::reg32>(cpu.ebx), cpu.mmx.mm3);
    // 004a9381  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004a9384  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a9387  83c101                 +add ecx, 1
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
    // 004a938a  7cd1                   -jl 0x4a935d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a935d;
    }
    // 004a938c  61                     -popal 
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
    // 004a938d  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a938e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4a9390(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9390  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a9391  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a9393  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a9394  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a9395  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a9398  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a939b  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004a939e  c700d7934a00           -mov dword ptr [eax], 0x4a93d7
    app->getMemory<x86::reg32>(cpu.eax) = 4887511 /*0x4a93d7*/;
    // 004a93a4  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004a93a7  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004a93aa  c700b4934a00           -mov dword ptr [eax], 0x4a93b4
    app->getMemory<x86::reg32>(cpu.eax) = 4887476 /*0x4a93b4*/;
    // 004a93b0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a93b1  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a93b2  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a93b3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a93b4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a93b4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a93b5  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a93b7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a93b8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a93b9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a93ba  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a93bd  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004a93c0  c1e018                 -shl eax, 0x18
    cpu.eax <<= 24 /*0x18*/ % 32;
    // 004a93c3  8b5d0c                 -mov ebx, dword ptr [ebp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a93c6  668bc3                 -mov ax, bx
    cpu.ax = cpu.bx;
    // 004a93c9  66c1e008               -shl ax, 8
    cpu.ax <<= 8 /*0x8*/ % 32;
    // 004a93cd  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 004a93cf  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004a93d2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a93d3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a93d4  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a93d5  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a93d6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a93d7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a93d7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a93d8  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a93da  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004a93db  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a93de  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a93e1  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004a93e4  0f6f06                 -movq mm0, qword ptr [esi]
    cpu.mmx.mm0 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.esi));
    // 004a93e7  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004a93ea  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a93ec  83e007                 -and eax, 7
    cpu.eax &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004a93ef  83f800                 +cmp eax, 0
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a93f2  7405                   -je 0x4a93f9
    if (cpu.flags.zf)
    {
        goto L_0x004a93f9;
    }
    // 004a93f4  83e908                 +sub ecx, 8
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a93f7  7c4e                   -jl 0x4a9447
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a9447;
    }
L_0x004a93f9:
    // 004a93f9  0f6fc8                 -movq mm1, mm0
    cpu.mmx.mm1 = cpu.mmx.mm0;
    // 004a93fc  0f6fd0                 -movq mm2, mm0
    cpu.mmx.mm2 = cpu.mmx.mm0;
    // 004a93ff  0f6fd8                 -movq mm3, mm0
    cpu.mmx.mm3 = cpu.mmx.mm0;
    // 004a9402  0f6fe0                 -movq mm4, mm0
    cpu.mmx.mm4 = cpu.mmx.mm0;
    // 004a9405  0fe50f                 -pmulhw mm1, qword ptr [edi]
    cpu.mmx.mm1 = { _mm_mulhi_epi16(cpu.mmx.mm1, x86::from_reg64(app->getMemory<x86::reg64>(cpu.edi))) };
    // 004a9408  0fe55708               -pmulhw mm2, qword ptr [edi + 8]
    cpu.mmx.mm2 = { _mm_mulhi_epi16(cpu.mmx.mm2, x86::from_reg64(app->getMemory<x86::reg64>(cpu.edi + x86::reg32(8) /* 0x8 */))) };
    // 004a940c  0fe55f10               -pmulhw mm3, qword ptr [edi + 0x10]
    cpu.mmx.mm3 = { _mm_mulhi_epi16(cpu.mmx.mm3, x86::from_reg64(app->getMemory<x86::reg64>(cpu.edi + x86::reg32(16) /* 0x10 */))) };
    // 004a9410  0fe56718               -pmulhw mm4, qword ptr [edi + 0x18]
    cpu.mmx.mm4 = { _mm_mulhi_epi16(cpu.mmx.mm4, x86::from_reg64(app->getMemory<x86::reg64>(cpu.edi + x86::reg32(24) /* 0x18 */))) };
    // 004a9414  0fed4d00               -paddsw mm1, qword ptr [ebp]
    cpu.mmx.mm1 = { _mm_adds_epi16(cpu.mmx.mm1, x86::from_reg64(app->getMemory<x86::reg64>(cpu.ebp))) };
    // 004a9418  0fed5508               -paddsw mm2, qword ptr [ebp + 8]
    cpu.mmx.mm2 = { _mm_adds_epi16(cpu.mmx.mm2, x86::from_reg64(app->getMemory<x86::reg64>(cpu.ebp + x86::reg32(8) /* 0x8 */))) };
    // 004a941c  0fed5d10               -paddsw mm3, qword ptr [ebp + 0x10]
    cpu.mmx.mm3 = { _mm_adds_epi16(cpu.mmx.mm3, x86::from_reg64(app->getMemory<x86::reg64>(cpu.ebp + x86::reg32(16) /* 0x10 */))) };
    // 004a9420  0fed6518               -paddsw mm4, qword ptr [ebp + 0x18]
    cpu.mmx.mm4 = { _mm_adds_epi16(cpu.mmx.mm4, x86::from_reg64(app->getMemory<x86::reg64>(cpu.ebp + x86::reg32(24) /* 0x18 */))) };
    // 004a9424  0f7f4d00               -movq qword ptr [ebp], mm1
    app->getMemory<x86::reg64>(cpu.ebp) = cpu.mmx.mm1;
    // 004a9428  0f7f5508               -movq qword ptr [ebp + 8], mm2
    app->getMemory<x86::reg64>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.mmx.mm2;
    // 004a942c  0f7f5d10               -movq qword ptr [ebp + 0x10], mm3
    app->getMemory<x86::reg64>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.mmx.mm3;
    // 004a9430  0f7f6518               -movq qword ptr [ebp + 0x18], mm4
    app->getMemory<x86::reg64>(cpu.ebp + x86::reg32(24) /* 0x18 */) = cpu.mmx.mm4;
    // 004a9434  83c720                 -add edi, 0x20
    (cpu.edi) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004a9437  83c520                 -add ebp, 0x20
    (cpu.ebp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004a943a  83e908                 +sub ecx, 8
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a943d  7fba                   -jg 0x4a93f9
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a93f9;
    }
    // 004a943f  83f900                 +cmp ecx, 0
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
    // 004a9442  7503                   -jne 0x4a9447
    if (!cpu.flags.zf)
    {
        goto L_0x004a9447;
    }
    // 004a9444  61                     -popal 
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
    // 004a9445  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9446  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a9447:
    // 004a9447  83c108                 -add ecx, 8
    (cpu.ecx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a944a  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004a944c  0f6fc8                 -movq mm1, mm0
    cpu.mmx.mm1 = cpu.mmx.mm0;
L_0x004a944f:
    // 004a944f  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 004a9451  0f6ec8                 -movd mm1, eax
    cpu.mmx.mm1 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004a9454  0fe5c8                 -pmulhw mm1, mm0
    cpu.mmx.mm1 = { _mm_mulhi_epi16(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 004a9457  0f6e5500               -movd mm2, dword ptr [ebp]
    cpu.mmx.mm2 = { _mm_loadu_si32(&app->getMemory<x86::reg32>(cpu.ebp)) };
    // 004a945b  0fedca                 -paddsw mm1, mm2
    cpu.mmx.mm1 = { _mm_adds_epi16(cpu.mmx.mm1, cpu.mmx.mm2) };
    // 004a945e  0f7e4d00               -movd dword ptr [ebp], mm1
    _mm_storeu_si32(&app->getMemory<x86::reg32>(cpu.ebp), cpu.mmx.mm1);
    // 004a9462  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a9465  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a9468  83c101                 +add ecx, 1
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
    // 004a946b  7ce2                   -jl 0x4a944f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a944f;
    }
    // 004a946d  61                     -popal 
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
    // 004a946e  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a946f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a9470(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9470  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a9471  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a9473  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004a9474  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a9477  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004a947a  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
L_0x004a947d:
    // 004a947d  668b448efc             -mov ax, word ptr [esi + ecx*4 - 4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(-4) /* -0x4 */ + cpu.ecx * 4);
    // 004a9482  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004a9485  668b448efe             -mov ax, word ptr [esi + ecx*4 - 2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(-2) /* -0x2 */ + cpu.ecx * 4);
    // 004a948a  0f6ec8                 -movd mm1, eax
    cpu.mmx.mm1 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004a948d  0fedc1                 -paddsw mm0, mm1
    cpu.mmx.mm0 = { _mm_adds_epi16(cpu.mmx.mm0, cpu.mmx.mm1) };
    // 004a9490  0f7ec0                 -movd eax, mm0
    cpu.eax = _mm_cvtsi128_si32(cpu.mmx.mm0);
    // 004a9493  3500800000             -xor eax, 0x8000
    cpu.eax ^= x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 004a9498  886439ff               -mov byte ptr [ecx + edi - 1], ah
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-1) /* -0x1 */ + cpu.edi * 1) = cpu.ah;
    // 004a949c  83e901                 +sub ecx, 1
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
    // 004a949f  7fdc                   -jg 0x4a947d
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a947d;
    }
    // 004a94a1  61                     -popal 
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
    // 004a94a2  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a94a3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a94a4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a94a4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a94a5  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a94a7  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004a94a8  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a94ab  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004a94ae  d1e1                   -shl ecx, 1
    cpu.ecx <<= 1 /*0x1*/ % 32;
    // 004a94b0  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a94b3  bb58f74c00             -mov ebx, 0x4cf758
    cpu.ebx = 5044056 /*0x4cf758*/;
L_0x004a94b8:
    // 004a94b8  0f6f444ef8             -movq mm0, qword ptr [esi + ecx*2 - 8]
    cpu.mmx.mm0 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.esi + x86::reg32(-8) /* -0x8 */ + cpu.ecx * 2));
    // 004a94bd  0f6f4c4ef0             -movq mm1, qword ptr [esi + ecx*2 - 0x10]
    cpu.mmx.mm1 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.esi + x86::reg32(-16) /* -0x10 */ + cpu.ecx * 2));
    // 004a94c2  0f6f544ee8             -movq mm2, qword ptr [esi + ecx*2 - 0x18]
    cpu.mmx.mm2 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.esi + x86::reg32(-24) /* -0x18 */ + cpu.ecx * 2));
    // 004a94c7  0f6f5c4ee0             -movq mm3, qword ptr [esi + ecx*2 - 0x20]
    cpu.mmx.mm3 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.esi + x86::reg32(-32) /* -0x20 */ + cpu.ecx * 2));
    // 004a94cc  0f6f644ed8             -movq mm4, qword ptr [esi + ecx*2 - 0x28]
    cpu.mmx.mm4 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.esi + x86::reg32(-40) /* -0x28 */ + cpu.ecx * 2));
    // 004a94d1  0f6f6c4ed0             -movq mm5, qword ptr [esi + ecx*2 - 0x30]
    cpu.mmx.mm5 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.esi + x86::reg32(-48) /* -0x30 */ + cpu.ecx * 2));
    // 004a94d6  0f6f744ec8             -movq mm6, qword ptr [esi + ecx*2 - 0x38]
    cpu.mmx.mm6 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.esi + x86::reg32(-56) /* -0x38 */ + cpu.ecx * 2));
    // 004a94db  0f6f7c4ec0             -movq mm7, qword ptr [esi + ecx*2 - 0x40]
    cpu.mmx.mm7 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.esi + x86::reg32(-64) /* -0x40 */ + cpu.ecx * 2));
    // 004a94e0  0fedc0                 -paddsw mm0, mm0
    cpu.mmx.mm0 = { _mm_adds_epi16(cpu.mmx.mm0, cpu.mmx.mm0) };
    // 004a94e3  0fedc9                 -paddsw mm1, mm1
    cpu.mmx.mm1 = { _mm_adds_epi16(cpu.mmx.mm1, cpu.mmx.mm1) };
    // 004a94e6  0fedd2                 -paddsw mm2, mm2
    cpu.mmx.mm2 = { _mm_adds_epi16(cpu.mmx.mm2, cpu.mmx.mm2) };
    // 004a94e9  0feddb                 -paddsw mm3, mm3
    cpu.mmx.mm3 = { _mm_adds_epi16(cpu.mmx.mm3, cpu.mmx.mm3) };
    // 004a94ec  0fede4                 -paddsw mm4, mm4
    cpu.mmx.mm4 = { _mm_adds_epi16(cpu.mmx.mm4, cpu.mmx.mm4) };
    // 004a94ef  0feded                 -paddsw mm5, mm5
    cpu.mmx.mm5 = { _mm_adds_epi16(cpu.mmx.mm5, cpu.mmx.mm5) };
    // 004a94f2  0fedf6                 -paddsw mm6, mm6
    cpu.mmx.mm6 = { _mm_adds_epi16(cpu.mmx.mm6, cpu.mmx.mm6) };
    // 004a94f5  0fedff                 -paddsw mm7, mm7
    cpu.mmx.mm7 = { _mm_adds_epi16(cpu.mmx.mm7, cpu.mmx.mm7) };
    // 004a94f8  0f71d008               -psrlw mm0, 8
    cpu.mmx.mm0 = { _mm_srli_epi16(cpu.mmx.mm0, 8 /*0x8*/) };
    // 004a94fc  0f71d108               -psrlw mm1, 8
    cpu.mmx.mm1 = { _mm_srli_epi16(cpu.mmx.mm1, 8 /*0x8*/) };
    // 004a9500  0f71d208               -psrlw mm2, 8
    cpu.mmx.mm2 = { _mm_srli_epi16(cpu.mmx.mm2, 8 /*0x8*/) };
    // 004a9504  0f71d308               -psrlw mm3, 8
    cpu.mmx.mm3 = { _mm_srli_epi16(cpu.mmx.mm3, 8 /*0x8*/) };
    // 004a9508  0f71d408               -psrlw mm4, 8
    cpu.mmx.mm4 = { _mm_srli_epi16(cpu.mmx.mm4, 8 /*0x8*/) };
    // 004a950c  0f71d508               -psrlw mm5, 8
    cpu.mmx.mm5 = { _mm_srli_epi16(cpu.mmx.mm5, 8 /*0x8*/) };
    // 004a9510  0f71d608               -psrlw mm6, 8
    cpu.mmx.mm6 = { _mm_srli_epi16(cpu.mmx.mm6, 8 /*0x8*/) };
    // 004a9514  0f71d708               -psrlw mm7, 8
    cpu.mmx.mm7 = { _mm_srli_epi16(cpu.mmx.mm7, 8 /*0x8*/) };
    // 004a9518  0f67c8                 -packuswb mm1, mm0
    { __m128i _packed = _mm_packus_epi16(cpu.mmx.mm1, cpu.mmx.mm0); cpu.mmx.mm1 = {_mm_unpacklo_epi32(_packed, _mm_srli_si128(_packed, 8))}; }
    // 004a951b  0f67da                 -packuswb mm3, mm2
    { __m128i _packed = _mm_packus_epi16(cpu.mmx.mm3, cpu.mmx.mm2); cpu.mmx.mm3 = {_mm_unpacklo_epi32(_packed, _mm_srli_si128(_packed, 8))}; }
    // 004a951e  0f67ec                 -packuswb mm5, mm4
    { __m128i _packed = _mm_packus_epi16(cpu.mmx.mm5, cpu.mmx.mm4); cpu.mmx.mm5 = {_mm_unpacklo_epi32(_packed, _mm_srli_si128(_packed, 8))}; }
    // 004a9521  0f67fe                 -packuswb mm7, mm6
    { __m128i _packed = _mm_packus_epi16(cpu.mmx.mm7, cpu.mmx.mm6); cpu.mmx.mm7 = {_mm_unpacklo_epi32(_packed, _mm_srli_si128(_packed, 8))}; }
    // 004a9524  0f6f03                 -movq mm0, qword ptr [ebx]
    cpu.mmx.mm0 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.ebx));
    // 004a9527  0fefc8                 -pxor mm1, mm0
    cpu.mmx.mm1 = { _mm_xor_si128(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 004a952a  0fefd8                 -pxor mm3, mm0
    cpu.mmx.mm3 = { _mm_xor_si128(cpu.mmx.mm3, cpu.mmx.mm0) };
    // 004a952d  0fefe8                 -pxor mm5, mm0
    cpu.mmx.mm5 = { _mm_xor_si128(cpu.mmx.mm5, cpu.mmx.mm0) };
    // 004a9530  0feff8                 -pxor mm7, mm0
    cpu.mmx.mm7 = { _mm_xor_si128(cpu.mmx.mm7, cpu.mmx.mm0) };
    // 004a9533  0f7f4c39f8             -movq qword ptr [ecx + edi - 8], mm1
    app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-8) /* -0x8 */ + cpu.edi * 1) = cpu.mmx.mm1;
    // 004a9538  0f7f5c39f0             -movq qword ptr [ecx + edi - 0x10], mm3
    app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-16) /* -0x10 */ + cpu.edi * 1) = cpu.mmx.mm3;
    // 004a953d  0f7f6c39e8             -movq qword ptr [ecx + edi - 0x18], mm5
    app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-24) /* -0x18 */ + cpu.edi * 1) = cpu.mmx.mm5;
    // 004a9542  0f7f7c39e0             -movq qword ptr [ecx + edi - 0x20], mm7
    app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-32) /* -0x20 */ + cpu.edi * 1) = cpu.mmx.mm7;
    // 004a9547  83e920                 +sub ecx, 0x20
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a954a  0f8f68ffffff           -jg 0x4a94b8
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a94b8;
    }
    // 004a9550  61                     -popal 
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
    // 004a9551  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9552  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4a9554(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9554  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a9555  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a9557  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004a9558  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a955b  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004a955e  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
L_0x004a9561:
    // 004a9561  668b448efc             -mov ax, word ptr [esi + ecx*4 - 4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(-4) /* -0x4 */ + cpu.ecx * 4);
    // 004a9566  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004a9569  668b448efe             -mov ax, word ptr [esi + ecx*4 - 2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(-2) /* -0x2 */ + cpu.ecx * 4);
    // 004a956e  0f6ec8                 -movd mm1, eax
    cpu.mmx.mm1 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004a9571  0fedc1                 -paddsw mm0, mm1
    cpu.mmx.mm0 = { _mm_adds_epi16(cpu.mmx.mm0, cpu.mmx.mm1) };
    // 004a9574  0f7ec0                 -movd eax, mm0
    cpu.eax = _mm_cvtsi128_si32(cpu.mmx.mm0);
    // 004a9577  6689444ffe             -mov word ptr [edi + ecx*2 - 2], ax
    app->getMemory<x86::reg16>(cpu.edi + x86::reg32(-2) /* -0x2 */ + cpu.ecx * 2) = cpu.ax;
    // 004a957c  83e901                 +sub ecx, 1
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
    // 004a957f  7fe0                   -jg 0x4a9561
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a9561;
    }
    // 004a9581  61                     -popal 
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
    // 004a9582  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9583  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a9584(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9584  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a9585  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a9587  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004a9588  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a958b  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004a958e  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 004a9591  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
L_0x004a9594:
    // 004a9594  0f6f4431f8             -movq mm0, qword ptr [ecx + esi - 8]
    cpu.mmx.mm0 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-8) /* -0x8 */ + cpu.esi * 1));
    // 004a9599  0f6f4c31f0             -movq mm1, qword ptr [ecx + esi - 0x10]
    cpu.mmx.mm1 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-16) /* -0x10 */ + cpu.esi * 1));
    // 004a959e  0f6f5431e8             -movq mm2, qword ptr [ecx + esi - 0x18]
    cpu.mmx.mm2 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-24) /* -0x18 */ + cpu.esi * 1));
    // 004a95a3  0f6f5c31e0             -movq mm3, qword ptr [ecx + esi - 0x20]
    cpu.mmx.mm3 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-32) /* -0x20 */ + cpu.esi * 1));
    // 004a95a8  0f6f6431d8             -movq mm4, qword ptr [ecx + esi - 0x28]
    cpu.mmx.mm4 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-40) /* -0x28 */ + cpu.esi * 1));
    // 004a95ad  0f6f6c31d0             -movq mm5, qword ptr [ecx + esi - 0x30]
    cpu.mmx.mm5 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-48) /* -0x30 */ + cpu.esi * 1));
    // 004a95b2  0f6f7431c8             -movq mm6, qword ptr [ecx + esi - 0x38]
    cpu.mmx.mm6 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-56) /* -0x38 */ + cpu.esi * 1));
    // 004a95b7  0f6f7c31c0             -movq mm7, qword ptr [ecx + esi - 0x40]
    cpu.mmx.mm7 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-64) /* -0x40 */ + cpu.esi * 1));
    // 004a95bc  0fedc0                 -paddsw mm0, mm0
    cpu.mmx.mm0 = { _mm_adds_epi16(cpu.mmx.mm0, cpu.mmx.mm0) };
    // 004a95bf  0fedc9                 -paddsw mm1, mm1
    cpu.mmx.mm1 = { _mm_adds_epi16(cpu.mmx.mm1, cpu.mmx.mm1) };
    // 004a95c2  0fedd2                 -paddsw mm2, mm2
    cpu.mmx.mm2 = { _mm_adds_epi16(cpu.mmx.mm2, cpu.mmx.mm2) };
    // 004a95c5  0feddb                 -paddsw mm3, mm3
    cpu.mmx.mm3 = { _mm_adds_epi16(cpu.mmx.mm3, cpu.mmx.mm3) };
    // 004a95c8  0fede4                 -paddsw mm4, mm4
    cpu.mmx.mm4 = { _mm_adds_epi16(cpu.mmx.mm4, cpu.mmx.mm4) };
    // 004a95cb  0feded                 -paddsw mm5, mm5
    cpu.mmx.mm5 = { _mm_adds_epi16(cpu.mmx.mm5, cpu.mmx.mm5) };
    // 004a95ce  0fedf6                 -paddsw mm6, mm6
    cpu.mmx.mm6 = { _mm_adds_epi16(cpu.mmx.mm6, cpu.mmx.mm6) };
    // 004a95d1  0fedff                 -paddsw mm7, mm7
    cpu.mmx.mm7 = { _mm_adds_epi16(cpu.mmx.mm7, cpu.mmx.mm7) };
    // 004a95d4  0f7f4439f8             -movq qword ptr [ecx + edi - 8], mm0
    app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-8) /* -0x8 */ + cpu.edi * 1) = cpu.mmx.mm0;
    // 004a95d9  0f7f4c39f0             -movq qword ptr [ecx + edi - 0x10], mm1
    app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-16) /* -0x10 */ + cpu.edi * 1) = cpu.mmx.mm1;
    // 004a95de  0f7f5439e8             -movq qword ptr [ecx + edi - 0x18], mm2
    app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-24) /* -0x18 */ + cpu.edi * 1) = cpu.mmx.mm2;
    // 004a95e3  0f7f5c39e0             -movq qword ptr [ecx + edi - 0x20], mm3
    app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-32) /* -0x20 */ + cpu.edi * 1) = cpu.mmx.mm3;
    // 004a95e8  0f7f6439d8             -movq qword ptr [ecx + edi - 0x28], mm4
    app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-40) /* -0x28 */ + cpu.edi * 1) = cpu.mmx.mm4;
    // 004a95ed  0f7f6c39d0             -movq qword ptr [ecx + edi - 0x30], mm5
    app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-48) /* -0x30 */ + cpu.edi * 1) = cpu.mmx.mm5;
    // 004a95f2  0f7f7439c8             -movq qword ptr [ecx + edi - 0x38], mm6
    app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-56) /* -0x38 */ + cpu.edi * 1) = cpu.mmx.mm6;
    // 004a95f7  0f7f7c39c0             -movq qword ptr [ecx + edi - 0x40], mm7
    app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-64) /* -0x40 */ + cpu.edi * 1) = cpu.mmx.mm7;
    // 004a95fc  83e940                 +sub ecx, 0x40
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(64 /*0x40*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a95ff  7f93                   -jg 0x4a9594
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a9594;
    }
    // 004a9601  61                     -popal 
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
    // 004a9602  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9603  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a9604(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9604  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a9605  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a9607  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a9608  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a9609  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004a960c  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004a960f  0fefc0                 -pxor mm0, mm0
    cpu.mmx.mm0 = { _mm_xor_si128(cpu.mmx.mm0, cpu.mmx.mm0) };
    // 004a9612  83f90f                 +cmp ecx, 0xf
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
    // 004a9615  7e2d                   -jle 0x4a9644
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a9644;
    }
    // 004a9617  83e90f                 -sub ecx, 0xf
    (cpu.ecx) -= x86::reg32(x86::sreg32(15 /*0xf*/));
L_0x004a961a:
    // 004a961a  0f7f07                 -movq qword ptr [edi], mm0
    app->getMemory<x86::reg64>(cpu.edi) = cpu.mmx.mm0;
    // 004a961d  0f7f4708               -movq qword ptr [edi + 8], mm0
    app->getMemory<x86::reg64>(cpu.edi + x86::reg32(8) /* 0x8 */) = cpu.mmx.mm0;
    // 004a9621  0f7f4710               -movq qword ptr [edi + 0x10], mm0
    app->getMemory<x86::reg64>(cpu.edi + x86::reg32(16) /* 0x10 */) = cpu.mmx.mm0;
    // 004a9625  0f7f4718               -movq qword ptr [edi + 0x18], mm0
    app->getMemory<x86::reg64>(cpu.edi + x86::reg32(24) /* 0x18 */) = cpu.mmx.mm0;
    // 004a9629  0f7f4720               -movq qword ptr [edi + 0x20], mm0
    app->getMemory<x86::reg64>(cpu.edi + x86::reg32(32) /* 0x20 */) = cpu.mmx.mm0;
    // 004a962d  0f7f4728               -movq qword ptr [edi + 0x28], mm0
    app->getMemory<x86::reg64>(cpu.edi + x86::reg32(40) /* 0x28 */) = cpu.mmx.mm0;
    // 004a9631  0f7f4730               -movq qword ptr [edi + 0x30], mm0
    app->getMemory<x86::reg64>(cpu.edi + x86::reg32(48) /* 0x30 */) = cpu.mmx.mm0;
    // 004a9635  0f7f4738               -movq qword ptr [edi + 0x38], mm0
    app->getMemory<x86::reg64>(cpu.edi + x86::reg32(56) /* 0x38 */) = cpu.mmx.mm0;
    // 004a9639  83c740                 -add edi, 0x40
    (cpu.edi) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004a963c  83e910                 +sub ecx, 0x10
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
    // 004a963f  7fd9                   -jg 0x4a961a
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a961a;
    }
    // 004a9641  83c10f                 -add ecx, 0xf
    (cpu.ecx) += x86::reg32(x86::sreg32(15 /*0xf*/));
L_0x004a9644:
    // 004a9644  83f900                 +cmp ecx, 0
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
    // 004a9647  7e0b                   -jle 0x4a9654
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a9654;
    }
    // 004a9649  0f7e07                 -movd dword ptr [edi], mm0
    _mm_storeu_si32(&app->getMemory<x86::reg32>(cpu.edi), cpu.mmx.mm0);
    // 004a964c  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a964f  83e901                 +sub ecx, 1
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
    // 004a9652  7ff0                   -jg 0x4a9644
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a9644;
    }
L_0x004a9654:
    // 004a9654  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9655  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9656  0f77                   -emms 
    cpu.mmx.init();
    // 004a9658  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9659  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a9660(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9660  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a9661  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a9662  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a9663  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a9667  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a966b  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004a966e  48                     -dec eax
    (cpu.eax)--;
    // 004a966f  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004a9672  034204                 -add eax, dword ptr [edx + 4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 004a9675  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a9678  8b5a0d                 -mov ebx, dword ptr [edx + 0xd]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(13) /* 0xd */);
    // 004a967b  40                     -inc eax
    (cpu.eax)++;
    // 004a967c  c1fb18                 -sar ebx, 0x18
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (24 /*0x18*/ % 32));
    // 004a967f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a9681  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004a9683  8a5a0f                 -mov bl, byte ptr [edx + 0xf]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(15) /* 0xf */);
    // 004a9686  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a9688  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 004a968a  7501                   -jne 0x4a968d
    if (!cpu.flags.zf)
    {
        goto L_0x004a968d;
    }
    // 004a968c  40                     -inc eax
    (cpu.eax)++;
L_0x004a968d:
    // 004a968d  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a9691  8b5108                 -mov edx, dword ptr [ecx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004a9694  0fafd7                 -imul edx, edi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 004a9697  035104                 -add edx, dword ptr [ecx + 4]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
    // 004a969a  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004a969d  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004a969f  885110                 -mov byte ptr [ecx + 0x10], dl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.dl;
    // 004a96a2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a96a3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a96a4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a96a5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a96a8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a96a8  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a96ac  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a96b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a96b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a96b1  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a96b5  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a96b9  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004a96bc  48                     -dec eax
    (cpu.eax)--;
    // 004a96bd  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004a96c0  034204                 -add eax, dword ptr [edx + 4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 004a96c3  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a96c5  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a96c8  8a5a0f                 -mov bl, byte ptr [edx + 0xf]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(15) /* 0xf */);
    // 004a96cb  40                     -inc eax
    (cpu.eax)++;
    // 004a96cc  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 004a96ce  7501                   -jne 0x4a96d1
    if (!cpu.flags.zf)
    {
        goto L_0x004a96d1;
    }
    // 004a96d0  40                     -inc eax
    (cpu.eax)++;
L_0x004a96d1:
    // 004a96d1  8b510b                 -mov edx, dword ptr [ecx + 0xb]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(11) /* 0xb */);
    // 004a96d4  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004a96d7  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a96d9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a96da  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a96dc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a96dc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a96dd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a96de  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a96df  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a96e0  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a96e3  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a96e7  8b7c241c               -mov edi, dword ptr [esp + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a96eb  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004a96ef  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a96f1  8a480f                 -mov cl, byte ptr [eax + 0xf]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(15) /* 0xf */);
    // 004a96f4  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004a96f6  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 004a96f8  7572                   -jne 0x4a976c
    if (!cpu.flags.zf)
    {
        goto L_0x004a976c;
    }
L_0x004a96fa:
    // 004a96fa  8b6c2424               -mov ebp, dword ptr [esp + 0x24]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a96fe  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp);
    // 004a9701  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a9702  7572                   -jne 0x4a9776
    if (!cpu.flags.zf)
    {
        goto L_0x004a9776;
    }
L_0x004a9704:
    // 004a9704  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a9706  baffff0000             -mov edx, 0xffff
    cpu.edx = 65535 /*0xffff*/;
    // 004a970b  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a970e  0fbe0406               -movsx eax, byte ptr [esi + eax]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1)));
    // 004a9712  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a9714  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004a9717  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004a971a  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a971c  0fbe543201             -movsx edx, byte ptr [edx + esi + 1]
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */ + cpu.esi * 1)));
    // 004a9721  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004a9724  0fafd1                 -imul edx, ecx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004a9727  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a972a  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004a972d  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a972f  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 004a9732  88042f                 -mov byte ptr [edi + ebp], al
    app->getMemory<x86::reg8>(cpu.edi + cpu.ebp * 1) = cpu.al;
    // 004a9735  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a9737  8a440601               -mov al, byte ptr [esi + eax + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.eax * 1);
    // 004a973b  88430d                 -mov byte ptr [ebx + 0xd], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(13) /* 0xd */) = cpu.al;
    // 004a973e  8b7304                 -mov esi, dword ptr [ebx + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a9741  037308                 -add esi, dword ptr [ebx + 8]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */)));
    // 004a9744  8b3b                   -mov edi, dword ptr [ebx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a9746  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a9748  897304                 -mov dword ptr [ebx + 4], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 004a974b  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a974e  66c743060000           -mov word ptr [ebx + 6], 0
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 004a9754  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a9756  8b430d                 -mov eax, dword ptr [ebx + 0xd]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(13) /* 0xd */);
    // 004a9759  893b                   -mov dword ptr [ebx], edi
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edi;
    // 004a975b  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004a975e  c6430f01               -mov byte ptr [ebx + 0xf], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(15) /* 0xf */) = 1 /*0x1*/;
    // 004a9762  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004a9764  83c404                 +add esp, 4
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
    // 004a9767  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9768  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9769  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a976a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a976b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a976c:
    // 004a976c  8d72ff                 -lea esi, [edx - 1]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 004a976f  8a400d                 -mov al, byte ptr [eax + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */);
    // 004a9772  8806                   -mov byte ptr [esi], al
    app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
    // 004a9774  eb84                   -jmp 0x4a96fa
    goto L_0x004a96fa;
L_0x004a9776:
    // 004a9776  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a9779  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a977c  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a977f  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004a9782  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004a9785  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a9786  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004a9789  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a978a  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004a978e  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a9792  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a9793  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a9794  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a9795  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a9796  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a9797  e8404c0000             -call 0x4ae3dc
    cpu.esp -= 4;
    sub_4ae3dc(app, cpu);
    if (cpu.terminate) return;
    // 004a979c  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004a979f  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004a97a2  c1e810                 +shr eax, 0x10
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
    // 004a97a5  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004a97a8  e957ffffff             -jmp 0x4a9704
    goto L_0x004a9704;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a97b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a97b0  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a97b4  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a97b8  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004a97ba  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a97bc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a97bc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a97bd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a97be  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a97bf  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a97c0  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a97c3  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a97c7  8b7c241c               -mov edi, dword ptr [esp + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a97cb  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004a97cf  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a97d1  8a480f                 -mov cl, byte ptr [eax + 0xf]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(15) /* 0xf */);
    // 004a97d4  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004a97d6  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 004a97d8  0f85c7000000           -jne 0x4a98a5
    if (!cpu.flags.zf)
    {
        goto L_0x004a98a5;
    }
L_0x004a97de:
    // 004a97de  807b0e00               +cmp byte ptr [ebx + 0xe], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(14) /* 0xe */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a97e2  7406                   -je 0x4a97ea
    if (cpu.flags.zf)
    {
        goto L_0x004a97ea;
    }
    // 004a97e4  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a97e5  8a430c                 -mov al, byte ptr [ebx + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004a97e8  8806                   -mov byte ptr [esi], al
    app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
L_0x004a97ea:
    // 004a97ea  8b6c2424               -mov ebp, dword ptr [esp + 0x24]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a97ee  c70300000000           -mov dword ptr [ebx], 0
    app->getMemory<x86::reg32>(cpu.ebx) = 0 /*0x0*/;
    // 004a97f4  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp);
    // 004a97f7  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a97f8  7432                   -je 0x4a982c
    if (cpu.flags.zf)
    {
        goto L_0x004a982c;
    }
    // 004a97fa  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a97fd  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a9800  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a9803  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004a9806  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004a9809  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a980a  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004a980d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a980e  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004a9812  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a9816  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a9817  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a9818  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a9819  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a981a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a981b  e8bc4b0000             -call 0x4ae3dc
    cpu.esp -= 4;
    sub_4ae3dc(app, cpu);
    if (cpu.terminate) return;
    // 004a9820  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004a9823  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004a9826  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a9829  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x004a982c:
    // 004a982c  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a982e  0fbe0406               -movsx eax, byte ptr [esi + eax]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1)));
    // 004a9832  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a9835  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a9837  b8ffff0000             -mov eax, 0xffff
    cpu.eax = 65535 /*0xffff*/;
    // 004a983c  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004a983f  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a9841  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004a9844  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a9846  0fbe543201             -movsx edx, byte ptr [edx + esi + 1]
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */ + cpu.esi * 1)));
    // 004a984b  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004a984e  0fafd1                 -imul edx, ecx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004a9851  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a9854  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004a9857  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a9859  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 004a985c  88042f                 -mov byte ptr [edi + ebp], al
    app->getMemory<x86::reg8>(cpu.edi + cpu.ebp * 1) = cpu.al;
    // 004a985f  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a9861  8a440601               -mov al, byte ptr [esi + eax + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.eax * 1);
    // 004a9865  88430d                 -mov byte ptr [ebx + 0xd], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(13) /* 0xd */) = cpu.al;
    // 004a9868  8b7b04                 -mov edi, dword ptr [ebx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a986b  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a986e  8b2b                   -mov ebp, dword ptr [ebx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a9870  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a9872  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a9875  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a9877  897b04                 -mov dword ptr [ebx + 4], edi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 004a987a  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a987d  66c743060000           -mov word ptr [ebx + 6], 0
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 004a9883  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a9885  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a9888  892b                   -mov dword ptr [ebx], ebp
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.ebp;
    // 004a988a  39d0                   +cmp eax, edx
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
    // 004a988c  7224                   -jb 0x4a98b2
    if (cpu.flags.cf)
    {
        goto L_0x004a98b2;
    }
    // 004a988e  0333                   -add esi, dword ptr [ebx]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx)));
    // 004a9890  c6430e01               -mov byte ptr [ebx + 0xe], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(14) /* 0xe */) = 1 /*0x1*/;
    // 004a9894  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004a9896  88430c                 -mov byte ptr [ebx + 0xc], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.al;
    // 004a9899  c6430f01               -mov byte ptr [ebx + 0xf], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(15) /* 0xf */) = 1 /*0x1*/;
    // 004a989d  83c404                 +add esp, 4
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
    // 004a98a0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a98a1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a98a2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a98a3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a98a4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a98a5:
    // 004a98a5  8d72ff                 -lea esi, [edx - 1]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 004a98a8  8a400d                 -mov al, byte ptr [eax + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */);
    // 004a98ab  8806                   -mov byte ptr [esi], al
    app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
    // 004a98ad  e92cffffff             -jmp 0x4a97de
    goto L_0x004a97de;
L_0x004a98b2:
    // 004a98b2  c6430e00               -mov byte ptr [ebx + 0xe], 0
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(14) /* 0xe */) = 0 /*0x0*/;
    // 004a98b6  c6430f01               -mov byte ptr [ebx + 0xf], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(15) /* 0xf */) = 1 /*0x1*/;
    // 004a98ba  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a98bd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a98be  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a98bf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a98c0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a98c1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a98c4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a98c4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a98c5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a98c6  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a98ca  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a98ce  8b5908                 -mov ebx, dword ptr [ecx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004a98d1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a98d3  81fb00000100           +cmp ebx, 0x10000
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
    // 004a98d9  732c                   -jae 0x4a9907
    if (!cpu.flags.cf)
    {
        goto L_0x004a9907;
    }
    // 004a98db  81fa00000100           +cmp edx, 0x10000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a98e1  7324                   -jae 0x4a9907
    if (!cpu.flags.cf)
    {
        goto L_0x004a9907;
    }
L_0x004a98e3:
    // 004a98e3  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004a98e6  81fa00000100           +cmp edx, 0x10000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a98ec  724b                   -jb 0x4a9939
    if (cpu.flags.cf)
    {
        goto L_0x004a9939;
    }
    // 004a98ee  7660                   -jbe 0x4a9950
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a9950;
    }
    // 004a98f0  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004a98f3  c70260964a00           -mov dword ptr [edx], 0x4a9660
    app->getMemory<x86::reg32>(cpu.edx) = 4888160 /*0x4a9660*/;
    // 004a98f9  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004a98fc  c700dc964a00           -mov dword ptr [eax], 0x4a96dc
    app->getMemory<x86::reg32>(cpu.eax) = 4888284 /*0x4a96dc*/;
    // 004a9902  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a9904  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9905  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9906  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a9907:
    // 004a9907  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004a990a  39f2                   +cmp edx, esi
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
    // 004a990c  74d5                   -je 0x4a98e3
    if (cpu.flags.zf)
    {
        goto L_0x004a98e3;
    }
    // 004a990e  81fe00000100           +cmp esi, 0x10000
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a9914  7608                   -jbe 0x4a991e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a991e;
    }
    // 004a9916  81fa00000100           +cmp edx, 0x10000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a991c  77c5                   -ja 0x4a98e3
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004a98e3;
    }
L_0x004a991e:
    // 004a991e  c6400e00               -mov byte ptr [eax + 0xe], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(14) /* 0xe */) = 0 /*0x0*/;
    // 004a9922  c6400f00               -mov byte ptr [eax + 0xf], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(15) /* 0xf */) = 0 /*0x0*/;
    // 004a9926  c6401000               -mov byte ptr [eax + 0x10], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 004a992a  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004a9931  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004a9937  ebaa                   -jmp 0x4a98e3
    goto L_0x004a98e3;
L_0x004a9939:
    // 004a9939  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004a993c  c702b0964a00           -mov dword ptr [edx], 0x4a96b0
    app->getMemory<x86::reg32>(cpu.edx) = 4888240 /*0x4a96b0*/;
    // 004a9942  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004a9945  c700bc974a00           -mov dword ptr [eax], 0x4a97bc
    app->getMemory<x86::reg32>(cpu.eax) = 4888508 /*0x4a97bc*/;
    // 004a994b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a994d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a994e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a994f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a9950:
    // 004a9950  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004a9953  c702a8964a00           -mov dword ptr [edx], 0x4a96a8
    app->getMemory<x86::reg32>(cpu.edx) = 4888232 /*0x4a96a8*/;
    // 004a9959  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004a995c  c700b0974a00           -mov dword ptr [eax], 0x4a97b0
    app->getMemory<x86::reg32>(cpu.eax) = 4888496 /*0x4a97b0*/;
    // 004a9962  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a9964  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9965  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9966  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a9968(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9968  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a996c  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004a9972  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004a9979  c6400e00               -mov byte ptr [eax + 0xe], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(14) /* 0xe */) = 0 /*0x0*/;
    // 004a997d  c6400d00               -mov byte ptr [eax + 0xd], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */) = 0 /*0x0*/;
    // 004a9981  c6400f00               -mov byte ptr [eax + 0xf], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(15) /* 0xf */) = 0 /*0x0*/;
    // 004a9985  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a9989  c6401001               -mov byte ptr [eax + 0x10], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(16) /* 0x10 */) = 1 /*0x1*/;
    // 004a998d  895014                 -mov dword ptr [eax + 0x14], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004a9990  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a9994  895018                 -mov dword ptr [eax + 0x18], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004a9997  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a999b  89501c                 -mov dword ptr [eax + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004a999e  8b4014                 -mov eax, dword ptr [eax + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004a99a1  c700c4984a00           -mov dword ptr [eax], 0x4a98c4
    app->getMemory<x86::reg32>(cpu.eax) = 4888772 /*0x4a98c4*/;
    // 004a99a7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a99a9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a99b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a99b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a99b1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a99b2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a99b3  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a99b7  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a99bb  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004a99be  48                     -dec eax
    (cpu.eax)--;
    // 004a99bf  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004a99c2  034204                 -add eax, dword ptr [edx + 4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 004a99c5  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a99c8  8b5a0f                 -mov ebx, dword ptr [edx + 0xf]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(15) /* 0xf */);
    // 004a99cb  40                     -inc eax
    (cpu.eax)++;
    // 004a99cc  c1fb18                 -sar ebx, 0x18
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (24 /*0x18*/ % 32));
    // 004a99cf  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a99d1  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004a99d3  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 004a99d6  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a99d8  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 004a99da  7501                   -jne 0x4a99dd
    if (!cpu.flags.zf)
    {
        goto L_0x004a99dd;
    }
    // 004a99dc  40                     -inc eax
    (cpu.eax)++;
L_0x004a99dd:
    // 004a99dd  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a99e1  8b5108                 -mov edx, dword ptr [ecx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004a99e4  0fafd7                 -imul edx, edi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 004a99e7  035104                 -add edx, dword ptr [ecx + 4]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
    // 004a99ea  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004a99ed  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004a99ef  885112                 -mov byte ptr [ecx + 0x12], dl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(18) /* 0x12 */) = cpu.dl;
    // 004a99f2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a99f3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a99f4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a99f5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a99f8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a99f8  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a99fc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a9a00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9a00  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a9a01  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a9a05  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a9a09  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004a9a0c  48                     -dec eax
    (cpu.eax)--;
    // 004a9a0d  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004a9a10  034204                 -add eax, dword ptr [edx + 4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 004a9a13  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a9a15  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a9a18  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 004a9a1b  40                     -inc eax
    (cpu.eax)++;
    // 004a9a1c  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 004a9a1e  7501                   -jne 0x4a9a21
    if (!cpu.flags.zf)
    {
        goto L_0x004a9a21;
    }
    // 004a9a20  40                     -inc eax
    (cpu.eax)++;
L_0x004a9a21:
    // 004a9a21  8b510d                 -mov edx, dword ptr [ecx + 0xd]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(13) /* 0xd */);
    // 004a9a24  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004a9a27  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a9a29  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9a2a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a9a2c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9a2c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a9a2d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a9a2e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a9a2f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a9a30  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a9a33  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a9a37  8b7c2420               -mov edi, dword ptr [esp + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004a9a3b  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a9a3f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a9a41  8a4811                 -mov cl, byte ptr [eax + 0x11]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(17) /* 0x11 */);
    // 004a9a44  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004a9a46  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 004a9a48  0f85b9000000           -jne 0x4a9b07
    if (!cpu.flags.zf)
    {
        goto L_0x004a9b07;
    }
L_0x004a9a4e:
    // 004a9a4e  8b6c2428               -mov ebp, dword ptr [esp + 0x28]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004a9a52  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp);
    // 004a9a55  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a9a56  0f85be000000           -jne 0x4a9b1a
    if (!cpu.flags.zf)
    {
        goto L_0x004a9b1a;
    }
L_0x004a9a5c:
    // 004a9a5c  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a9a5e  0fbe0456               -movsx eax, byte ptr [esi + edx*2]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.esi + cpu.edx * 2)));
    // 004a9a62  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004a9a65  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a9a68  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004a9a6c  b8ffff0000             -mov eax, 0xffff
    cpu.eax = 65535 /*0xffff*/;
    // 004a9a71  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a9a73  0faf442404             -imul eax, dword ptr [esp + 4]
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */))));
    // 004a9a78  0fbe545602             -movsx edx, byte ptr [esi + edx*2 + 2]
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */ + cpu.edx * 2)));
    // 004a9a7d  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004a9a80  0faf5304               -imul edx, dword ptr [ebx + 4]
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */))));
    // 004a9a84  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a9a87  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004a9a8a  01ff                   -add edi, edi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edi));
    // 004a9a8c  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a9a8e  01fd                   -add ebp, edi
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edi));
    // 004a9a90  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 004a9a93  884500                 -mov byte ptr [ebp], al
    app->getMemory<x86::reg8>(cpu.ebp) = cpu.al;
    // 004a9a96  8b3b                   -mov edi, dword ptr [ebx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a9a98  b8ffff0000             -mov eax, 0xffff
    cpu.eax = 65535 /*0xffff*/;
    // 004a9a9d  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a9aa0  0fbe547e01             -movsx edx, byte ptr [esi + edi*2 + 1]
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.edi * 2)));
    // 004a9aa5  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a9aa7  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004a9aaa  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004a9aad  8b147e                 -mov edx, dword ptr [esi + edi*2]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + cpu.edi * 2);
    // 004a9ab0  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004a9ab3  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004a9ab6  0fafd1                 -imul edx, ecx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004a9ab9  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a9abc  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004a9abf  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a9ac1  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 004a9ac4  884501                 -mov byte ptr [ebp + 1], al
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004a9ac7  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a9ac9  8a444602               -mov al, byte ptr [esi + eax*2 + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */ + cpu.eax * 2);
    // 004a9acd  88430e                 -mov byte ptr [ebx + 0xe], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(14) /* 0xe */) = cpu.al;
    // 004a9ad0  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a9ad2  8a444603               -mov al, byte ptr [esi + eax*2 + 3]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */ + cpu.eax * 2);
    // 004a9ad6  88430f                 -mov byte ptr [ebx + 0xf], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(15) /* 0xf */) = cpu.al;
    // 004a9ad9  8b6b04                 -mov ebp, dword ptr [ebx + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a9adc  036b08                 -add ebp, dword ptr [ebx + 8]
    (cpu.ebp) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */)));
    // 004a9adf  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a9ae1  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004a9ae3  896b04                 -mov dword ptr [ebx + 4], ebp
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 004a9ae6  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a9ae9  66c743060000           -mov word ptr [ebx + 6], 0
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 004a9aef  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a9af1  8b430f                 -mov eax, dword ptr [ebx + 0xf]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(15) /* 0xf */);
    // 004a9af4  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 004a9af6  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004a9af9  c6431101               -mov byte ptr [ebx + 0x11], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(17) /* 0x11 */) = 1 /*0x1*/;
    // 004a9afd  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004a9aff  83c408                 +add esp, 8
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
    // 004a9b02  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9b03  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9b04  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9b05  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9b06  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a9b07:
    // 004a9b07  8d72ff                 -lea esi, [edx - 1]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 004a9b0a  8a500f                 -mov dl, byte ptr [eax + 0xf]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(15) /* 0xf */);
    // 004a9b0d  8816                   -mov byte ptr [esi], dl
    app->getMemory<x86::reg8>(cpu.esi) = cpu.dl;
    // 004a9b0f  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a9b10  8a400e                 -mov al, byte ptr [eax + 0xe]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(14) /* 0xe */);
    // 004a9b13  8806                   -mov byte ptr [esi], al
    app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
    // 004a9b15  e934ffffff             -jmp 0x4a9a4e
    goto L_0x004a9a4e;
L_0x004a9b1a:
    // 004a9b1a  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a9b1d  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a9b20  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a9b23  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004a9b26  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004a9b29  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a9b2a  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004a9b2d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a9b2e  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004a9b32  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a9b36  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a9b37  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a9b38  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a9b39  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a9b3a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a9b3b  e81c490000             -call 0x4ae45c
    cpu.esp -= 4;
    sub_4ae45c(app, cpu);
    if (cpu.terminate) return;
    // 004a9b40  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004a9b43  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004a9b46  c1e810                 +shr eax, 0x10
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
    // 004a9b49  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004a9b4c  e90bffffff             -jmp 0x4a9a5c
    goto L_0x004a9a5c;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a9b54(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9b54  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a9b58  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a9b5c  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004a9b5e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a9b60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9b60  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a9b61  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a9b62  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a9b63  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a9b64  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a9b67  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a9b6b  8b7c241c               -mov edi, dword ptr [esp + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a9b6f  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004a9b73  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a9b75  8a4811                 -mov cl, byte ptr [eax + 0x11]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(17) /* 0x11 */);
    // 004a9b78  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004a9b7a  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 004a9b7c  0f8510010000           -jne 0x4a9c92
    if (!cpu.flags.zf)
    {
        goto L_0x004a9c92;
    }
L_0x004a9b82:
    // 004a9b82  807b1000               +cmp byte ptr [ebx + 0x10], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a9b86  740c                   -je 0x4a9b94
    if (cpu.flags.zf)
    {
        goto L_0x004a9b94;
    }
    // 004a9b88  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a9b89  8a430d                 -mov al, byte ptr [ebx + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(13) /* 0xd */);
    // 004a9b8c  8806                   -mov byte ptr [esi], al
    app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
    // 004a9b8e  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a9b8f  8a430c                 -mov al, byte ptr [ebx + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004a9b92  8806                   -mov byte ptr [esi], al
    app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
L_0x004a9b94:
    // 004a9b94  8b6c2424               -mov ebp, dword ptr [esp + 0x24]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a9b98  c70300000000           -mov dword ptr [ebx], 0
    app->getMemory<x86::reg32>(cpu.ebx) = 0 /*0x0*/;
    // 004a9b9e  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp);
    // 004a9ba1  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a9ba2  7432                   -je 0x4a9bd6
    if (cpu.flags.zf)
    {
        goto L_0x004a9bd6;
    }
    // 004a9ba4  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a9ba7  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a9baa  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a9bad  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004a9bb0  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004a9bb3  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a9bb4  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004a9bb7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a9bb8  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004a9bbc  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a9bc0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a9bc1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a9bc2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a9bc3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a9bc4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a9bc5  e892480000             -call 0x4ae45c
    cpu.esp -= 4;
    sub_4ae45c(app, cpu);
    if (cpu.terminate) return;
    // 004a9bca  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004a9bcd  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004a9bd0  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a9bd3  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x004a9bd6:
    // 004a9bd6  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a9bd8  b9ffff0000             -mov ecx, 0xffff
    cpu.ecx = 65535 /*0xffff*/;
    // 004a9bdd  0fbe0456               -movsx eax, byte ptr [esi + edx*2]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.esi + cpu.edx * 2)));
    // 004a9be1  2b4b04                 -sub ecx, dword ptr [ebx + 4]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */)));
    // 004a9be4  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004a9be7  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004a9bea  0fbe545602             -movsx edx, byte ptr [esi + edx*2 + 2]
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */ + cpu.edx * 2)));
    // 004a9bef  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004a9bf2  0faf5304               -imul edx, dword ptr [ebx + 4]
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */))));
    // 004a9bf6  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a9bf9  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004a9bfc  01ff                   -add edi, edi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edi));
    // 004a9bfe  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a9c00  01fd                   -add ebp, edi
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edi));
    // 004a9c02  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 004a9c05  884500                 -mov byte ptr [ebp], al
    app->getMemory<x86::reg8>(cpu.ebp) = cpu.al;
    // 004a9c08  8b3b                   -mov edi, dword ptr [ebx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a9c0a  b8ffff0000             -mov eax, 0xffff
    cpu.eax = 65535 /*0xffff*/;
    // 004a9c0f  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a9c12  0fbe547e01             -movsx edx, byte ptr [esi + edi*2 + 1]
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.edi * 2)));
    // 004a9c17  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a9c19  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004a9c1c  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004a9c1f  8b147e                 -mov edx, dword ptr [esi + edi*2]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + cpu.edi * 2);
    // 004a9c22  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004a9c25  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004a9c28  0fafd1                 -imul edx, ecx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004a9c2b  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a9c2e  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004a9c31  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a9c33  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 004a9c36  884501                 -mov byte ptr [ebp + 1], al
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004a9c39  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a9c3b  8a444602               -mov al, byte ptr [esi + eax*2 + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */ + cpu.eax * 2);
    // 004a9c3f  88430e                 -mov byte ptr [ebx + 0xe], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(14) /* 0xe */) = cpu.al;
    // 004a9c42  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a9c44  8a444603               -mov al, byte ptr [esi + eax*2 + 3]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */ + cpu.eax * 2);
    // 004a9c48  88430f                 -mov byte ptr [ebx + 0xf], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(15) /* 0xf */) = cpu.al;
    // 004a9c4b  8b6b04                 -mov ebp, dword ptr [ebx + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a9c4e  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a9c51  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a9c53  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a9c55  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a9c58  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004a9c5a  896b04                 -mov dword ptr [ebx + 4], ebp
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 004a9c5d  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a9c60  66c743060000           -mov word ptr [ebx + 6], 0
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 004a9c66  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a9c68  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a9c6b  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 004a9c6d  39c8                   +cmp eax, ecx
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
    // 004a9c6f  7234                   -jb 0x4a9ca5
    if (cpu.flags.cf)
    {
        goto L_0x004a9ca5;
    }
    // 004a9c71  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a9c73  c6431001               -mov byte ptr [ebx + 0x10], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */) = 1 /*0x1*/;
    // 004a9c77  8a0446                 -mov al, byte ptr [esi + eax*2]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 2);
    // 004a9c7a  88430c                 -mov byte ptr [ebx + 0xc], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.al;
    // 004a9c7d  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a9c7f  8a444601               -mov al, byte ptr [esi + eax*2 + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.eax * 2);
    // 004a9c83  88430d                 -mov byte ptr [ebx + 0xd], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(13) /* 0xd */) = cpu.al;
    // 004a9c86  c6431101               -mov byte ptr [ebx + 0x11], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(17) /* 0x11 */) = 1 /*0x1*/;
    // 004a9c8a  83c404                 +add esp, 4
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
    // 004a9c8d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9c8e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9c8f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9c90  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9c91  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a9c92:
    // 004a9c92  8d72ff                 -lea esi, [edx - 1]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 004a9c95  8a500f                 -mov dl, byte ptr [eax + 0xf]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(15) /* 0xf */);
    // 004a9c98  8816                   -mov byte ptr [esi], dl
    app->getMemory<x86::reg8>(cpu.esi) = cpu.dl;
    // 004a9c9a  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a9c9b  8a400e                 -mov al, byte ptr [eax + 0xe]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(14) /* 0xe */);
    // 004a9c9e  8806                   -mov byte ptr [esi], al
    app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
    // 004a9ca0  e9ddfeffff             -jmp 0x4a9b82
    goto L_0x004a9b82;
L_0x004a9ca5:
    // 004a9ca5  c6431000               -mov byte ptr [ebx + 0x10], 0
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 004a9ca9  c6431101               -mov byte ptr [ebx + 0x11], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(17) /* 0x11 */) = 1 /*0x1*/;
    // 004a9cad  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a9cb0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9cb1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9cb2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9cb3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9cb4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a9cb8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9cb8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a9cb9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a9cba  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a9cbe  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a9cc2  8b5908                 -mov ebx, dword ptr [ecx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004a9cc5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a9cc7  81fb00000100           +cmp ebx, 0x10000
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
    // 004a9ccd  732c                   -jae 0x4a9cfb
    if (!cpu.flags.cf)
    {
        goto L_0x004a9cfb;
    }
    // 004a9ccf  81fa00000100           +cmp edx, 0x10000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a9cd5  7324                   -jae 0x4a9cfb
    if (!cpu.flags.cf)
    {
        goto L_0x004a9cfb;
    }
L_0x004a9cd7:
    // 004a9cd7  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004a9cda  81fa00000100           +cmp edx, 0x10000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a9ce0  724b                   -jb 0x4a9d2d
    if (cpu.flags.cf)
    {
        goto L_0x004a9d2d;
    }
    // 004a9ce2  7660                   -jbe 0x4a9d44
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a9d44;
    }
    // 004a9ce4  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004a9ce7  c702b0994a00           -mov dword ptr [edx], 0x4a99b0
    app->getMemory<x86::reg32>(cpu.edx) = 4889008 /*0x4a99b0*/;
    // 004a9ced  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004a9cf0  c7002c9a4a00           -mov dword ptr [eax], 0x4a9a2c
    app->getMemory<x86::reg32>(cpu.eax) = 4889132 /*0x4a9a2c*/;
    // 004a9cf6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a9cf8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9cf9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9cfa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a9cfb:
    // 004a9cfb  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004a9cfe  39f2                   +cmp edx, esi
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
    // 004a9d00  74d5                   -je 0x4a9cd7
    if (cpu.flags.zf)
    {
        goto L_0x004a9cd7;
    }
    // 004a9d02  81fe00000100           +cmp esi, 0x10000
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a9d08  7608                   -jbe 0x4a9d12
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a9d12;
    }
    // 004a9d0a  81fa00000100           +cmp edx, 0x10000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a9d10  77c5                   -ja 0x4a9cd7
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004a9cd7;
    }
L_0x004a9d12:
    // 004a9d12  c6401000               -mov byte ptr [eax + 0x10], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 004a9d16  c6401100               -mov byte ptr [eax + 0x11], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(17) /* 0x11 */) = 0 /*0x0*/;
    // 004a9d1a  c6401200               -mov byte ptr [eax + 0x12], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(18) /* 0x12 */) = 0 /*0x0*/;
    // 004a9d1e  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004a9d25  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004a9d2b  ebaa                   -jmp 0x4a9cd7
    goto L_0x004a9cd7;
L_0x004a9d2d:
    // 004a9d2d  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004a9d30  c702009a4a00           -mov dword ptr [edx], 0x4a9a00
    app->getMemory<x86::reg32>(cpu.edx) = 4889088 /*0x4a9a00*/;
    // 004a9d36  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004a9d39  c700609b4a00           -mov dword ptr [eax], 0x4a9b60
    app->getMemory<x86::reg32>(cpu.eax) = 4889440 /*0x4a9b60*/;
    // 004a9d3f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a9d41  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9d42  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9d43  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a9d44:
    // 004a9d44  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004a9d47  c702f8994a00           -mov dword ptr [edx], 0x4a99f8
    app->getMemory<x86::reg32>(cpu.edx) = 4889080 /*0x4a99f8*/;
    // 004a9d4d  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004a9d50  c700549b4a00           -mov dword ptr [eax], 0x4a9b54
    app->getMemory<x86::reg32>(cpu.eax) = 4889428 /*0x4a9b54*/;
    // 004a9d56  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a9d58  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9d59  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9d5a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a9d5c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9d5c  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a9d60  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004a9d66  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004a9d6d  c6401000               -mov byte ptr [eax + 0x10], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 004a9d71  c6401100               -mov byte ptr [eax + 0x11], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(17) /* 0x11 */) = 0 /*0x0*/;
    // 004a9d75  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a9d79  c6401200               -mov byte ptr [eax + 0x12], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(18) /* 0x12 */) = 0 /*0x0*/;
    // 004a9d7d  895014                 -mov dword ptr [eax + 0x14], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004a9d80  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a9d84  895018                 -mov dword ptr [eax + 0x18], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004a9d87  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a9d8b  89501c                 -mov dword ptr [eax + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004a9d8e  8b4014                 -mov eax, dword ptr [eax + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004a9d91  c700b89c4a00           -mov dword ptr [eax], 0x4a9cb8
    app->getMemory<x86::reg32>(cpu.eax) = 4889784 /*0x4a9cb8*/;
    // 004a9d97  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a9d99  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a9da0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9da0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a9da1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a9da2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a9da3  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a9da7  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a9dab  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004a9dae  48                     -dec eax
    (cpu.eax)--;
    // 004a9daf  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004a9db2  034204                 -add eax, dword ptr [edx + 4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 004a9db5  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a9db8  8b5a0f                 -mov ebx, dword ptr [edx + 0xf]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(15) /* 0xf */);
    // 004a9dbb  40                     -inc eax
    (cpu.eax)++;
    // 004a9dbc  c1fb18                 -sar ebx, 0x18
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (24 /*0x18*/ % 32));
    // 004a9dbf  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a9dc1  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004a9dc3  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 004a9dc6  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a9dc8  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 004a9dca  7501                   -jne 0x4a9dcd
    if (!cpu.flags.zf)
    {
        goto L_0x004a9dcd;
    }
    // 004a9dcc  40                     -inc eax
    (cpu.eax)++;
L_0x004a9dcd:
    // 004a9dcd  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a9dd1  8b5108                 -mov edx, dword ptr [ecx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004a9dd4  0fafd7                 -imul edx, edi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 004a9dd7  035104                 -add edx, dword ptr [ecx + 4]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
    // 004a9dda  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004a9ddd  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004a9ddf  885112                 -mov byte ptr [ecx + 0x12], dl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(18) /* 0x12 */) = cpu.dl;
    // 004a9de2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9de3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9de4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9de5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a9de8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9de8  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a9dec  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a9df0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9df0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a9df1  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a9df5  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a9df9  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004a9dfc  48                     -dec eax
    (cpu.eax)--;
    // 004a9dfd  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004a9e00  034204                 -add eax, dword ptr [edx + 4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 004a9e03  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a9e05  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a9e08  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 004a9e0b  40                     -inc eax
    (cpu.eax)++;
    // 004a9e0c  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 004a9e0e  7501                   -jne 0x4a9e11
    if (!cpu.flags.zf)
    {
        goto L_0x004a9e11;
    }
    // 004a9e10  40                     -inc eax
    (cpu.eax)++;
L_0x004a9e11:
    // 004a9e11  8b510d                 -mov edx, dword ptr [ecx + 0xd]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(13) /* 0xd */);
    // 004a9e14  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004a9e17  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a9e19  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9e1a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a9e1c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9e1c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a9e1d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a9e1e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a9e1f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a9e20  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a9e23  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a9e27  8b7c241c               -mov edi, dword ptr [esp + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a9e2b  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004a9e2f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a9e31  8a4811                 -mov cl, byte ptr [eax + 0x11]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(17) /* 0x11 */);
    // 004a9e34  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004a9e36  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 004a9e38  0f8581000000           -jne 0x4a9ebf
    if (!cpu.flags.zf)
    {
        goto L_0x004a9ebf;
    }
L_0x004a9e3e:
    // 004a9e3e  8b6c2424               -mov ebp, dword ptr [esp + 0x24]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a9e42  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp);
    // 004a9e45  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a9e46  0f8582000000           -jne 0x4a9ece
    if (!cpu.flags.zf)
    {
        goto L_0x004a9ece;
    }
L_0x004a9e4c:
    // 004a9e4c  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a9e4e  baffff0000             -mov edx, 0xffff
    cpu.edx = 65535 /*0xffff*/;
    // 004a9e53  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a9e56  0fbf0446               -movsx eax, word ptr [esi + eax*2]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.esi + cpu.eax * 2)));
    // 004a9e5a  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a9e5c  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004a9e5f  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a9e62  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a9e64  8d043f                 -lea eax, [edi + edi]
    cpu.eax = x86::reg32(cpu.edi + cpu.edi * 1);
    // 004a9e67  66891428               -mov word ptr [eax + ebp], dx
    app->getMemory<x86::reg16>(cpu.eax + cpu.ebp * 1) = cpu.dx;
    // 004a9e6b  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a9e6d  8b1456                 -mov edx, dword ptr [esi + edx*2]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + cpu.edx * 2);
    // 004a9e70  8b7b04                 -mov edi, dword ptr [ebx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a9e73  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004a9e76  0faffa                 -imul edi, edx
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004a9e79  c1ef10                 -shr edi, 0x10
    cpu.edi >>= 16 /*0x10*/ % 32;
    // 004a9e7c  0fbf1428               -movsx edx, word ptr [eax + ebp]
    cpu.edx = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.eax + cpu.ebp * 1)));
    // 004a9e80  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004a9e82  66891428               -mov word ptr [eax + ebp], dx
    app->getMemory<x86::reg16>(cpu.eax + cpu.ebp * 1) = cpu.dx;
    // 004a9e86  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a9e88  668b444602             -mov ax, word ptr [esi + eax*2 + 2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(2) /* 0x2 */ + cpu.eax * 2);
    // 004a9e8d  6689430e               -mov word ptr [ebx + 0xe], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(14) /* 0xe */) = cpu.ax;
    // 004a9e91  8b6b04                 -mov ebp, dword ptr [ebx + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a9e94  036b08                 -add ebp, dword ptr [ebx + 8]
    (cpu.ebp) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */)));
    // 004a9e97  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a9e99  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004a9e9b  896b04                 -mov dword ptr [ebx + 4], ebp
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 004a9e9e  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a9ea1  66c743060000           -mov word ptr [ebx + 6], 0
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 004a9ea7  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a9ea9  8b430f                 -mov eax, dword ptr [ebx + 0xf]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(15) /* 0xf */);
    // 004a9eac  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 004a9eae  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004a9eb1  c6431101               -mov byte ptr [ebx + 0x11], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(17) /* 0x11 */) = 1 /*0x1*/;
    // 004a9eb5  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004a9eb7  83c404                 +add esp, 4
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
    // 004a9eba  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9ebb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9ebc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9ebd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9ebe  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a9ebf:
    // 004a9ebf  8d72fe                 -lea esi, [edx - 2]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(-2) /* -0x2 */);
    // 004a9ec2  668b400e               -mov ax, word ptr [eax + 0xe]
    cpu.ax = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(14) /* 0xe */);
    // 004a9ec6  668906                 -mov word ptr [esi], ax
    app->getMemory<x86::reg16>(cpu.esi) = cpu.ax;
    // 004a9ec9  e970ffffff             -jmp 0x4a9e3e
    goto L_0x004a9e3e;
L_0x004a9ece:
    // 004a9ece  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a9ed1  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a9ed4  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a9ed7  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004a9eda  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004a9edd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a9ede  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004a9ee1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a9ee2  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004a9ee6  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a9eea  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a9eeb  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a9eec  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a9eed  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a9eee  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a9eef  e808460000             -call 0x4ae4fc
    cpu.esp -= 4;
    sub_4ae4fc(app, cpu);
    if (cpu.terminate) return;
    // 004a9ef4  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004a9ef7  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004a9efa  c1e810                 +shr eax, 0x10
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
    // 004a9efd  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004a9f00  e947ffffff             -jmp 0x4a9e4c
    goto L_0x004a9e4c;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a9f08(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9f08  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a9f0c  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a9f10  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004a9f12  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a9f14(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9f14  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a9f15  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a9f16  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a9f17  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a9f18  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a9f1b  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a9f1f  8b7c241c               -mov edi, dword ptr [esp + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a9f23  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004a9f27  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a9f29  8a4811                 -mov cl, byte ptr [eax + 0x11]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(17) /* 0x11 */);
    // 004a9f2c  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004a9f2e  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 004a9f30  0f85d5000000           -jne 0x4aa00b
    if (!cpu.flags.zf)
    {
        goto L_0x004aa00b;
    }
L_0x004a9f36:
    // 004a9f36  807b1000               +cmp byte ptr [ebx + 0x10], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a9f3a  740a                   -je 0x4a9f46
    if (cpu.flags.zf)
    {
        goto L_0x004a9f46;
    }
    // 004a9f3c  83ee02                 +sub esi, 2
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a9f3f  668b430c               -mov ax, word ptr [ebx + 0xc]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004a9f43  668906                 -mov word ptr [esi], ax
    app->getMemory<x86::reg16>(cpu.esi) = cpu.ax;
L_0x004a9f46:
    // 004a9f46  8b6c2424               -mov ebp, dword ptr [esp + 0x24]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a9f4a  c70300000000           -mov dword ptr [ebx], 0
    app->getMemory<x86::reg32>(cpu.ebx) = 0 /*0x0*/;
    // 004a9f50  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp);
    // 004a9f53  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a9f54  7432                   -je 0x4a9f88
    if (cpu.flags.zf)
    {
        goto L_0x004a9f88;
    }
    // 004a9f56  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a9f59  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a9f5c  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a9f5f  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004a9f62  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004a9f65  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a9f66  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004a9f69  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a9f6a  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004a9f6e  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a9f72  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a9f73  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a9f74  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a9f75  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a9f76  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a9f77  e880450000             -call 0x4ae4fc
    cpu.esp -= 4;
    sub_4ae4fc(app, cpu);
    if (cpu.terminate) return;
    // 004a9f7c  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004a9f7f  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004a9f82  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a9f85  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x004a9f88:
    // 004a9f88  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a9f8a  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a9f8d  0fbf1446               -movsx edx, word ptr [esi + eax*2]
    cpu.edx = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.esi + cpu.eax * 2)));
    // 004a9f91  b8ffff0000             -mov eax, 0xffff
    cpu.eax = 65535 /*0xffff*/;
    // 004a9f96  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a9f98  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004a9f9b  8d143f                 -lea edx, [edi + edi]
    cpu.edx = x86::reg32(cpu.edi + cpu.edi * 1);
    // 004a9f9e  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a9fa1  6689042a               -mov word ptr [edx + ebp], ax
    app->getMemory<x86::reg16>(cpu.edx + cpu.ebp * 1) = cpu.ax;
    // 004a9fa5  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a9fa7  8b0446                 -mov eax, dword ptr [esi + eax*2]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + cpu.eax * 2);
    // 004a9faa  8b7b04                 -mov edi, dword ptr [ebx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a9fad  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004a9fb0  0faff8                 -imul edi, eax
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 004a9fb3  c1ef10                 -shr edi, 0x10
    cpu.edi >>= 16 /*0x10*/ % 32;
    // 004a9fb6  0fbf042a               -movsx eax, word ptr [edx + ebp]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.edx + cpu.ebp * 1)));
    // 004a9fba  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 004a9fbc  6689042a               -mov word ptr [edx + ebp], ax
    app->getMemory<x86::reg16>(cpu.edx + cpu.ebp * 1) = cpu.ax;
    // 004a9fc0  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a9fc2  668b444602             -mov ax, word ptr [esi + eax*2 + 2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(2) /* 0x2 */ + cpu.eax * 2);
    // 004a9fc7  6689430e               -mov word ptr [ebx + 0xe], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(14) /* 0xe */) = cpu.ax;
    // 004a9fcb  8b6b04                 -mov ebp, dword ptr [ebx + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a9fce  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a9fd1  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a9fd3  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a9fd5  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a9fd8  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004a9fda  896b04                 -mov dword ptr [ebx + 4], ebp
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 004a9fdd  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a9fe0  66c743060000           -mov word ptr [ebx + 6], 0
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 004a9fe6  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a9fe8  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a9feb  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 004a9fed  39c8                   +cmp eax, ecx
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
    // 004a9fef  7229                   -jb 0x4aa01a
    if (cpu.flags.cf)
    {
        goto L_0x004aa01a;
    }
    // 004a9ff1  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a9ff3  c6431001               -mov byte ptr [ebx + 0x10], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */) = 1 /*0x1*/;
    // 004a9ff7  668b0446               -mov ax, word ptr [esi + eax*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.eax * 2);
    // 004a9ffb  6689430c               -mov word ptr [ebx + 0xc], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.ax;
    // 004a9fff  c6431101               -mov byte ptr [ebx + 0x11], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(17) /* 0x11 */) = 1 /*0x1*/;
    // 004aa003  83c404                 +add esp, 4
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
    // 004aa006  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa007  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa008  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa009  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa00a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004aa00b:
    // 004aa00b  8d72fe                 -lea esi, [edx - 2]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(-2) /* -0x2 */);
    // 004aa00e  668b400e               -mov ax, word ptr [eax + 0xe]
    cpu.ax = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(14) /* 0xe */);
    // 004aa012  668906                 -mov word ptr [esi], ax
    app->getMemory<x86::reg16>(cpu.esi) = cpu.ax;
    // 004aa015  e91cffffff             -jmp 0x4a9f36
    goto L_0x004a9f36;
L_0x004aa01a:
    // 004aa01a  c6431000               -mov byte ptr [ebx + 0x10], 0
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 004aa01e  c6431101               -mov byte ptr [ebx + 0x11], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(17) /* 0x11 */) = 1 /*0x1*/;
    // 004aa022  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004aa025  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa026  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa027  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa028  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa029  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4aa02c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa02c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004aa02d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004aa02e  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004aa032  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004aa036  8b5908                 -mov ebx, dword ptr [ecx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004aa039  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004aa03b  81fb00000100           +cmp ebx, 0x10000
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
    // 004aa041  732c                   -jae 0x4aa06f
    if (!cpu.flags.cf)
    {
        goto L_0x004aa06f;
    }
    // 004aa043  81fa00000100           +cmp edx, 0x10000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aa049  7324                   -jae 0x4aa06f
    if (!cpu.flags.cf)
    {
        goto L_0x004aa06f;
    }
L_0x004aa04b:
    // 004aa04b  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004aa04e  81fa00000100           +cmp edx, 0x10000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aa054  724b                   -jb 0x4aa0a1
    if (cpu.flags.cf)
    {
        goto L_0x004aa0a1;
    }
    // 004aa056  7660                   -jbe 0x4aa0b8
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004aa0b8;
    }
    // 004aa058  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004aa05b  c702a09d4a00           -mov dword ptr [edx], 0x4a9da0
    app->getMemory<x86::reg32>(cpu.edx) = 4890016 /*0x4a9da0*/;
    // 004aa061  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004aa064  c7001c9e4a00           -mov dword ptr [eax], 0x4a9e1c
    app->getMemory<x86::reg32>(cpu.eax) = 4890140 /*0x4a9e1c*/;
    // 004aa06a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004aa06c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa06d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa06e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004aa06f:
    // 004aa06f  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004aa072  39f2                   +cmp edx, esi
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
    // 004aa074  74d5                   -je 0x4aa04b
    if (cpu.flags.zf)
    {
        goto L_0x004aa04b;
    }
    // 004aa076  81fe00000100           +cmp esi, 0x10000
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aa07c  7608                   -jbe 0x4aa086
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004aa086;
    }
    // 004aa07e  81fa00000100           +cmp edx, 0x10000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aa084  77c5                   -ja 0x4aa04b
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004aa04b;
    }
L_0x004aa086:
    // 004aa086  c6401000               -mov byte ptr [eax + 0x10], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 004aa08a  c6401100               -mov byte ptr [eax + 0x11], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(17) /* 0x11 */) = 0 /*0x0*/;
    // 004aa08e  c6401200               -mov byte ptr [eax + 0x12], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(18) /* 0x12 */) = 0 /*0x0*/;
    // 004aa092  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004aa099  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004aa09f  ebaa                   -jmp 0x4aa04b
    goto L_0x004aa04b;
L_0x004aa0a1:
    // 004aa0a1  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004aa0a4  c702f09d4a00           -mov dword ptr [edx], 0x4a9df0
    app->getMemory<x86::reg32>(cpu.edx) = 4890096 /*0x4a9df0*/;
    // 004aa0aa  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004aa0ad  c700149f4a00           -mov dword ptr [eax], 0x4a9f14
    app->getMemory<x86::reg32>(cpu.eax) = 4890388 /*0x4a9f14*/;
    // 004aa0b3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004aa0b5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa0b6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa0b7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004aa0b8:
    // 004aa0b8  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004aa0bb  c702e89d4a00           -mov dword ptr [edx], 0x4a9de8
    app->getMemory<x86::reg32>(cpu.edx) = 4890088 /*0x4a9de8*/;
    // 004aa0c1  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004aa0c4  c700089f4a00           -mov dword ptr [eax], 0x4a9f08
    app->getMemory<x86::reg32>(cpu.eax) = 4890376 /*0x4a9f08*/;
    // 004aa0ca  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004aa0cc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa0cd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa0ce  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4aa0d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa0d0  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004aa0d4  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004aa0da  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004aa0e1  c6401000               -mov byte ptr [eax + 0x10], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 004aa0e5  66c7400e0000           -mov word ptr [eax + 0xe], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(14) /* 0xe */) = 0 /*0x0*/;
    // 004aa0eb  c6401100               -mov byte ptr [eax + 0x11], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(17) /* 0x11 */) = 0 /*0x0*/;
    // 004aa0ef  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004aa0f3  c6401201               -mov byte ptr [eax + 0x12], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(18) /* 0x12 */) = 1 /*0x1*/;
    // 004aa0f7  895014                 -mov dword ptr [eax + 0x14], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004aa0fa  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004aa0fe  895018                 -mov dword ptr [eax + 0x18], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004aa101  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004aa105  89501c                 -mov dword ptr [eax + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004aa108  8b4014                 -mov eax, dword ptr [eax + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004aa10b  c7002ca04a00           -mov dword ptr [eax], 0x4aa02c
    app->getMemory<x86::reg32>(cpu.eax) = 4890668 /*0x4aa02c*/;
    // 004aa111  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004aa113  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4aa120(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa120  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004aa121  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004aa122  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004aa123  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004aa127  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004aa12b  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004aa12e  48                     -dec eax
    (cpu.eax)--;
    // 004aa12f  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004aa132  034204                 -add eax, dword ptr [edx + 4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 004aa135  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004aa138  8b5a13                 -mov ebx, dword ptr [edx + 0x13]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 004aa13b  40                     -inc eax
    (cpu.eax)++;
    // 004aa13c  c1fb18                 -sar ebx, 0x18
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (24 /*0x18*/ % 32));
    // 004aa13f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004aa141  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa143  8a5a15                 -mov bl, byte ptr [edx + 0x15]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(21) /* 0x15 */);
    // 004aa146  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004aa148  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 004aa14a  7501                   -jne 0x4aa14d
    if (!cpu.flags.zf)
    {
        goto L_0x004aa14d;
    }
    // 004aa14c  40                     -inc eax
    (cpu.eax)++;
L_0x004aa14d:
    // 004aa14d  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004aa151  8b5108                 -mov edx, dword ptr [ecx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004aa154  0fafd7                 -imul edx, edi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 004aa157  035104                 -add edx, dword ptr [ecx + 4]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
    // 004aa15a  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004aa15d  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004aa15f  885116                 -mov byte ptr [ecx + 0x16], dl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(22) /* 0x16 */) = cpu.dl;
    // 004aa162  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa163  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa164  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa165  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4aa168(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa168  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004aa16c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4aa170(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa170  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004aa171  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004aa175  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004aa179  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004aa17c  48                     -dec eax
    (cpu.eax)--;
    // 004aa17d  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004aa180  034204                 -add eax, dword ptr [edx + 4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 004aa183  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004aa185  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004aa188  8a5a15                 -mov bl, byte ptr [edx + 0x15]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(21) /* 0x15 */);
    // 004aa18b  40                     -inc eax
    (cpu.eax)++;
    // 004aa18c  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 004aa18e  7501                   -jne 0x4aa191
    if (!cpu.flags.zf)
    {
        goto L_0x004aa191;
    }
    // 004aa190  40                     -inc eax
    (cpu.eax)++;
L_0x004aa191:
    // 004aa191  8b5111                 -mov edx, dword ptr [ecx + 0x11]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(17) /* 0x11 */);
    // 004aa194  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004aa197  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004aa199  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa19a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4aa19c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa19c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004aa19d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004aa19e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004aa19f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004aa1a0  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004aa1a3  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004aa1a7  8b7c241c               -mov edi, dword ptr [esp + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004aa1ab  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004aa1af  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004aa1b1  8a4815                 -mov cl, byte ptr [eax + 0x15]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(21) /* 0x15 */);
    // 004aa1b4  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004aa1b6  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 004aa1b8  0f85d1000000           -jne 0x4aa28f
    if (!cpu.flags.zf)
    {
        goto L_0x004aa28f;
    }
L_0x004aa1be:
    // 004aa1be  8b6c2424               -mov ebp, dword ptr [esp + 0x24]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004aa1c2  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp);
    // 004aa1c5  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004aa1c6  0f85dc000000           -jne 0x4aa2a8
    if (!cpu.flags.zf)
    {
        goto L_0x004aa2a8;
    }
L_0x004aa1cc:
    // 004aa1cc  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004aa1ce  baffff0000             -mov edx, 0xffff
    cpu.edx = 65535 /*0xffff*/;
    // 004aa1d3  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004aa1d6  0fbf0486               -movsx eax, word ptr [esi + eax*4]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.esi + cpu.eax * 4)));
    // 004aa1da  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004aa1dc  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004aa1df  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004aa1e2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004aa1e4  8d04bd00000000         -lea eax, [edi*4]
    cpu.eax = x86::reg32(cpu.edi * 4);
    // 004aa1eb  66891428               -mov word ptr [eax + ebp], dx
    app->getMemory<x86::reg16>(cpu.eax + cpu.ebp * 1) = cpu.dx;
    // 004aa1ef  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004aa1f1  8b549602               -mov edx, dword ptr [esi + edx*4 + 2]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(2) /* 0x2 */ + cpu.edx * 4);
    // 004aa1f5  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004aa1f7  8b7b04                 -mov edi, dword ptr [ebx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004aa1fa  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004aa1fd  0fafcf                 -imul ecx, edi
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 004aa200  0fbf1428               -movsx edx, word ptr [eax + ebp]
    cpu.edx = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.eax + cpu.ebp * 1)));
    // 004aa204  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004aa207  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004aa209  66891428               -mov word ptr [eax + ebp], dx
    app->getMemory<x86::reg16>(cpu.eax + cpu.ebp * 1) = cpu.dx;
    // 004aa20d  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004aa20f  b9ffff0000             -mov ecx, 0xffff
    cpu.ecx = 65535 /*0xffff*/;
    // 004aa214  8b7b04                 -mov edi, dword ptr [ebx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004aa217  8b1496                 -mov edx, dword ptr [esi + edx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + cpu.edx * 4);
    // 004aa21a  29f9                   -sub ecx, edi
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004aa21c  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004aa21f  0fafd1                 -imul edx, ecx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004aa222  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004aa225  6689542802             -mov word ptr [eax + ebp + 2], dx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */ + cpu.ebp * 1) = cpu.dx;
    // 004aa22a  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004aa22c  8b549604               -mov edx, dword ptr [esi + edx*4 + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.edx * 4);
    // 004aa230  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004aa232  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004aa235  c1ff10                 -sar edi, 0x10
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (16 /*0x10*/ % 32));
    // 004aa238  0faff9                 -imul edi, ecx
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004aa23b  8b1428                 -mov edx, dword ptr [eax + ebp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + cpu.ebp * 1);
    // 004aa23e  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004aa241  c1ef10                 -shr edi, 0x10
    cpu.edi >>= 16 /*0x10*/ % 32;
    // 004aa244  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004aa246  6689542802             -mov word ptr [eax + ebp + 2], dx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */ + cpu.ebp * 1) = cpu.dx;
    // 004aa24b  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004aa24d  668b448604             -mov ax, word ptr [esi + eax*4 + 4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.eax * 4);
    // 004aa252  66894310               -mov word ptr [ebx + 0x10], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.ax;
    // 004aa256  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004aa258  668b448606             -mov ax, word ptr [esi + eax*4 + 6]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */ + cpu.eax * 4);
    // 004aa25d  66894312               -mov word ptr [ebx + 0x12], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(18) /* 0x12 */) = cpu.ax;
    // 004aa261  8b7304                 -mov esi, dword ptr [ebx + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004aa264  037308                 -add esi, dword ptr [ebx + 8]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */)));
    // 004aa267  8b3b                   -mov edi, dword ptr [ebx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx);
    // 004aa269  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004aa26b  897304                 -mov dword ptr [ebx + 4], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 004aa26e  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004aa271  66c743060000           -mov word ptr [ebx + 6], 0
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 004aa277  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004aa279  8b4313                 -mov eax, dword ptr [ebx + 0x13]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(19) /* 0x13 */);
    // 004aa27c  893b                   -mov dword ptr [ebx], edi
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edi;
    // 004aa27e  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004aa281  c6431501               -mov byte ptr [ebx + 0x15], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(21) /* 0x15 */) = 1 /*0x1*/;
    // 004aa285  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004aa287  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004aa28a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa28b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa28c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa28d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa28e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004aa28f:
    // 004aa28f  8d72fe                 -lea esi, [edx - 2]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(-2) /* -0x2 */);
    // 004aa292  668b5012               -mov dx, word ptr [eax + 0x12]
    cpu.dx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(18) /* 0x12 */);
    // 004aa296  668916                 -mov word ptr [esi], dx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.dx;
    // 004aa299  83ee02                 +sub esi, 2
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004aa29c  668b4010               -mov ax, word ptr [eax + 0x10]
    cpu.ax = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004aa2a0  668906                 -mov word ptr [esi], ax
    app->getMemory<x86::reg16>(cpu.esi) = cpu.ax;
    // 004aa2a3  e916ffffff             -jmp 0x4aa1be
    goto L_0x004aa1be;
L_0x004aa2a8:
    // 004aa2a8  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004aa2ab  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004aa2ae  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004aa2b1  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004aa2b4  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004aa2b7  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004aa2b8  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004aa2bb  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004aa2bc  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004aa2c0  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004aa2c4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004aa2c5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004aa2c6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004aa2c7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004aa2c8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004aa2c9  e8ae420000             -call 0x4ae57c
    cpu.esp -= 4;
    sub_4ae57c(app, cpu);
    if (cpu.terminate) return;
    // 004aa2ce  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004aa2d1  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004aa2d4  c1e810                 +shr eax, 0x10
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
    // 004aa2d7  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004aa2da  e9edfeffff             -jmp 0x4aa1cc
    goto L_0x004aa1cc;
}

/* align: skip 0x90 */
void Application::sub_4aa2e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa2e0  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004aa2e4  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004aa2e8  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004aa2ea  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4aa2ec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa2ec  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004aa2ed  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004aa2ee  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004aa2ef  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004aa2f0  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004aa2f3  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004aa2f7  8b7c241c               -mov edi, dword ptr [esp + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004aa2fb  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004aa2ff  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004aa301  8a4815                 -mov cl, byte ptr [eax + 0x15]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(21) /* 0x15 */);
    // 004aa304  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004aa306  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 004aa308  0f8538010000           -jne 0x4aa446
    if (!cpu.flags.zf)
    {
        goto L_0x004aa446;
    }
L_0x004aa30e:
    // 004aa30e  807b1400               +cmp byte ptr [ebx + 0x14], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(20) /* 0x14 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004aa312  7414                   -je 0x4aa328
    if (cpu.flags.zf)
    {
        goto L_0x004aa328;
    }
    // 004aa314  83ee02                 -sub esi, 2
    (cpu.esi) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004aa317  668b430e               -mov ax, word ptr [ebx + 0xe]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(14) /* 0xe */);
    // 004aa31b  668906                 -mov word ptr [esi], ax
    app->getMemory<x86::reg16>(cpu.esi) = cpu.ax;
    // 004aa31e  83ee02                 +sub esi, 2
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004aa321  668b430c               -mov ax, word ptr [ebx + 0xc]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004aa325  668906                 -mov word ptr [esi], ax
    app->getMemory<x86::reg16>(cpu.esi) = cpu.ax;
L_0x004aa328:
    // 004aa328  8b6c2424               -mov ebp, dword ptr [esp + 0x24]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004aa32c  c70300000000           -mov dword ptr [ebx], 0
    app->getMemory<x86::reg32>(cpu.ebx) = 0 /*0x0*/;
    // 004aa332  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp);
    // 004aa335  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004aa336  7432                   -je 0x4aa36a
    if (cpu.flags.zf)
    {
        goto L_0x004aa36a;
    }
    // 004aa338  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004aa33b  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004aa33e  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004aa341  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004aa344  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004aa347  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004aa348  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004aa34b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004aa34c  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004aa350  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004aa354  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004aa355  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004aa356  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004aa357  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004aa358  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004aa359  e81e420000             -call 0x4ae57c
    cpu.esp -= 4;
    sub_4ae57c(app, cpu);
    if (cpu.terminate) return;
    // 004aa35e  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004aa361  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004aa364  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004aa367  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x004aa36a:
    // 004aa36a  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004aa36c  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004aa36f  0fbf1486               -movsx edx, word ptr [esi + eax*4]
    cpu.edx = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.esi + cpu.eax * 4)));
    // 004aa373  b8ffff0000             -mov eax, 0xffff
    cpu.eax = 65535 /*0xffff*/;
    // 004aa378  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004aa37a  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004aa37d  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004aa380  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004aa382  8d04bd00000000         -lea eax, [edi*4]
    cpu.eax = x86::reg32(cpu.edi * 4);
    // 004aa389  66891428               -mov word ptr [eax + ebp], dx
    app->getMemory<x86::reg16>(cpu.eax + cpu.ebp * 1) = cpu.dx;
    // 004aa38d  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004aa38f  8b549602               -mov edx, dword ptr [esi + edx*4 + 2]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(2) /* 0x2 */ + cpu.edx * 4);
    // 004aa393  8b7b04                 -mov edi, dword ptr [ebx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004aa396  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004aa399  0fafd7                 -imul edx, edi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 004aa39c  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004aa39f  0fbf3c28               -movsx edi, word ptr [eax + ebp]
    cpu.edi = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.eax + cpu.ebp * 1)));
    // 004aa3a3  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 004aa3a5  66893c28               -mov word ptr [eax + ebp], di
    app->getMemory<x86::reg16>(cpu.eax + cpu.ebp * 1) = cpu.di;
    // 004aa3a9  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004aa3ab  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004aa3ae  8b3c96                 -mov edi, dword ptr [esi + edx*4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + cpu.edx * 4);
    // 004aa3b1  baffff0000             -mov edx, 0xffff
    cpu.edx = 65535 /*0xffff*/;
    // 004aa3b6  c1ff10                 -sar edi, 0x10
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (16 /*0x10*/ % 32));
    // 004aa3b9  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004aa3bb  0faffa                 -imul edi, edx
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004aa3be  c1ef10                 -shr edi, 0x10
    cpu.edi >>= 16 /*0x10*/ % 32;
    // 004aa3c1  66897c2802             -mov word ptr [eax + ebp + 2], di
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */ + cpu.ebp * 1) = cpu.di;
    // 004aa3c6  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004aa3c8  8b549604               -mov edx, dword ptr [esi + edx*4 + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.edx * 4);
    // 004aa3cc  8b7b04                 -mov edi, dword ptr [ebx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004aa3cf  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004aa3d2  0fafd7                 -imul edx, edi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 004aa3d5  8b3c28                 -mov edi, dword ptr [eax + ebp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + cpu.ebp * 1);
    // 004aa3d8  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004aa3db  c1ff10                 -sar edi, 0x10
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (16 /*0x10*/ % 32));
    // 004aa3de  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 004aa3e0  66897c2802             -mov word ptr [eax + ebp + 2], di
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */ + cpu.ebp * 1) = cpu.di;
    // 004aa3e5  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004aa3e7  668b448604             -mov ax, word ptr [esi + eax*4 + 4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.eax * 4);
    // 004aa3ec  66894310               -mov word ptr [ebx + 0x10], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.ax;
    // 004aa3f0  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004aa3f2  668b448606             -mov ax, word ptr [esi + eax*4 + 6]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */ + cpu.eax * 4);
    // 004aa3f7  66894312               -mov word ptr [ebx + 0x12], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(18) /* 0x12 */) = cpu.ax;
    // 004aa3fb  8b6b04                 -mov ebp, dword ptr [ebx + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004aa3fe  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004aa401  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004aa403  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 004aa405  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004aa408  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004aa40a  896b04                 -mov dword ptr [ebx + 4], ebp
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 004aa40d  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004aa410  66c743060000           -mov word ptr [ebx + 6], 0
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 004aa416  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004aa418  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004aa41b  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 004aa41d  39c8                   +cmp eax, ecx
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
    // 004aa41f  723e                   -jb 0x4aa45f
    if (cpu.flags.cf)
    {
        goto L_0x004aa45f;
    }
    // 004aa421  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004aa423  c6431401               -mov byte ptr [ebx + 0x14], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(20) /* 0x14 */) = 1 /*0x1*/;
    // 004aa427  668b0486               -mov ax, word ptr [esi + eax*4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.eax * 4);
    // 004aa42b  6689430c               -mov word ptr [ebx + 0xc], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.ax;
    // 004aa42f  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004aa431  668b448602             -mov ax, word ptr [esi + eax*4 + 2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(2) /* 0x2 */ + cpu.eax * 4);
    // 004aa436  6689430e               -mov word ptr [ebx + 0xe], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(14) /* 0xe */) = cpu.ax;
    // 004aa43a  c6431501               -mov byte ptr [ebx + 0x15], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(21) /* 0x15 */) = 1 /*0x1*/;
    // 004aa43e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004aa441  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa442  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa443  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa444  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa445  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004aa446:
    // 004aa446  8d72fe                 -lea esi, [edx - 2]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(-2) /* -0x2 */);
    // 004aa449  668b5012               -mov dx, word ptr [eax + 0x12]
    cpu.dx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(18) /* 0x12 */);
    // 004aa44d  668916                 -mov word ptr [esi], dx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.dx;
    // 004aa450  83ee02                 +sub esi, 2
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004aa453  668b4010               -mov ax, word ptr [eax + 0x10]
    cpu.ax = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004aa457  668906                 -mov word ptr [esi], ax
    app->getMemory<x86::reg16>(cpu.esi) = cpu.ax;
    // 004aa45a  e9affeffff             -jmp 0x4aa30e
    goto L_0x004aa30e;
L_0x004aa45f:
    // 004aa45f  c6431400               -mov byte ptr [ebx + 0x14], 0
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 004aa463  c6431501               -mov byte ptr [ebx + 0x15], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(21) /* 0x15 */) = 1 /*0x1*/;
    // 004aa467  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004aa46a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa46b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa46c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa46d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa46e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4aa470(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa470  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004aa471  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004aa472  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004aa476  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004aa47a  8b5908                 -mov ebx, dword ptr [ecx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004aa47d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004aa47f  81fb00000100           +cmp ebx, 0x10000
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
    // 004aa485  732c                   -jae 0x4aa4b3
    if (!cpu.flags.cf)
    {
        goto L_0x004aa4b3;
    }
    // 004aa487  81fa00000100           +cmp edx, 0x10000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aa48d  7324                   -jae 0x4aa4b3
    if (!cpu.flags.cf)
    {
        goto L_0x004aa4b3;
    }
L_0x004aa48f:
    // 004aa48f  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004aa492  81fa00000100           +cmp edx, 0x10000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aa498  724b                   -jb 0x4aa4e5
    if (cpu.flags.cf)
    {
        goto L_0x004aa4e5;
    }
    // 004aa49a  7660                   -jbe 0x4aa4fc
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004aa4fc;
    }
    // 004aa49c  8b501c                 -mov edx, dword ptr [eax + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004aa49f  c70220a14a00           -mov dword ptr [edx], 0x4aa120
    app->getMemory<x86::reg32>(cpu.edx) = 4890912 /*0x4aa120*/;
    // 004aa4a5  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004aa4a8  c7009ca14a00           -mov dword ptr [eax], 0x4aa19c
    app->getMemory<x86::reg32>(cpu.eax) = 4891036 /*0x4aa19c*/;
    // 004aa4ae  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004aa4b0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa4b1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa4b2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004aa4b3:
    // 004aa4b3  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004aa4b6  39f2                   +cmp edx, esi
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
    // 004aa4b8  74d5                   -je 0x4aa48f
    if (cpu.flags.zf)
    {
        goto L_0x004aa48f;
    }
    // 004aa4ba  81fe00000100           +cmp esi, 0x10000
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aa4c0  7608                   -jbe 0x4aa4ca
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004aa4ca;
    }
    // 004aa4c2  81fa00000100           +cmp edx, 0x10000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aa4c8  77c5                   -ja 0x4aa48f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004aa48f;
    }
L_0x004aa4ca:
    // 004aa4ca  c6401400               -mov byte ptr [eax + 0x14], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 004aa4ce  c6401500               -mov byte ptr [eax + 0x15], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(21) /* 0x15 */) = 0 /*0x0*/;
    // 004aa4d2  c6401600               -mov byte ptr [eax + 0x16], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(22) /* 0x16 */) = 0 /*0x0*/;
    // 004aa4d6  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004aa4dd  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004aa4e3  ebaa                   -jmp 0x4aa48f
    goto L_0x004aa48f;
L_0x004aa4e5:
    // 004aa4e5  8b501c                 -mov edx, dword ptr [eax + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004aa4e8  c70270a14a00           -mov dword ptr [edx], 0x4aa170
    app->getMemory<x86::reg32>(cpu.edx) = 4890992 /*0x4aa170*/;
    // 004aa4ee  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004aa4f1  c700eca24a00           -mov dword ptr [eax], 0x4aa2ec
    app->getMemory<x86::reg32>(cpu.eax) = 4891372 /*0x4aa2ec*/;
    // 004aa4f7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004aa4f9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa4fa  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa4fb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004aa4fc:
    // 004aa4fc  8b501c                 -mov edx, dword ptr [eax + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004aa4ff  c70268a14a00           -mov dword ptr [edx], 0x4aa168
    app->getMemory<x86::reg32>(cpu.edx) = 4890984 /*0x4aa168*/;
    // 004aa505  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004aa508  c700e0a24a00           -mov dword ptr [eax], 0x4aa2e0
    app->getMemory<x86::reg32>(cpu.eax) = 4891360 /*0x4aa2e0*/;
    // 004aa50e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004aa510  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa511  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa512  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4aa514(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa514  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004aa518  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004aa51e  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004aa525  c6401400               -mov byte ptr [eax + 0x14], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 004aa529  c6401500               -mov byte ptr [eax + 0x15], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(21) /* 0x15 */) = 0 /*0x0*/;
    // 004aa52d  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004aa531  c6401600               -mov byte ptr [eax + 0x16], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(22) /* 0x16 */) = 0 /*0x0*/;
    // 004aa535  895018                 -mov dword ptr [eax + 0x18], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004aa538  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004aa53c  89501c                 -mov dword ptr [eax + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004aa53f  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004aa543  895020                 -mov dword ptr [eax + 0x20], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 004aa546  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004aa549  c70070a44a00           -mov dword ptr [eax], 0x4aa470
    app->getMemory<x86::reg32>(cpu.eax) = 4891760 /*0x4aa470*/;
    // 004aa54f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004aa551  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4aa554(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa554  0f77                   -emms 
    cpu.mmx.init();
    // 004aa556  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4aa560(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa560  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004aa561  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004aa562  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004aa563  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004aa564  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004aa565  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004aa566  833d00a44c0000         +cmp dword ptr [0x4ca400], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5022720) /* 0x4ca400 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aa56d  744b                   -je 0x4aa5ba
    if (cpu.flags.zf)
    {
        goto L_0x004aa5ba;
    }
    // 004aa56f  ba20e64a00             -mov edx, 0x4ae620
    cpu.edx = 4908576 /*0x4ae620*/;
    // 004aa574  b940e64a00             -mov ecx, 0x4ae640
    cpu.ecx = 4908608 /*0x4ae640*/;
    // 004aa579  bb70e64a00             -mov ebx, 0x4ae670
    cpu.ebx = 4908656 /*0x4ae670*/;
    // 004aa57e  be90e64a00             -mov esi, 0x4ae690
    cpu.esi = 4908688 /*0x4ae690*/;
    // 004aa583  bfb0e64a00             -mov edi, 0x4ae6b0
    cpu.edi = 4908720 /*0x4ae6b0*/;
    // 004aa588  bde0e64a00             -mov ebp, 0x4ae6e0
    cpu.ebp = 4908768 /*0x4ae6e0*/;
    // 004aa58d  891550d44c00           -mov dword ptr [0x4cd450], edx
    app->getMemory<x86::reg32>(x86::reg32(5035088) /* 0x4cd450 */) = cpu.edx;
    // 004aa593  890d54d44c00           -mov dword ptr [0x4cd454], ecx
    app->getMemory<x86::reg32>(x86::reg32(5035092) /* 0x4cd454 */) = cpu.ecx;
    // 004aa599  891d58d44c00           -mov dword ptr [0x4cd458], ebx
    app->getMemory<x86::reg32>(x86::reg32(5035096) /* 0x4cd458 */) = cpu.ebx;
    // 004aa59f  89355cd44c00           -mov dword ptr [0x4cd45c], esi
    app->getMemory<x86::reg32>(x86::reg32(5035100) /* 0x4cd45c */) = cpu.esi;
    // 004aa5a5  893d60d44c00           -mov dword ptr [0x4cd460], edi
    app->getMemory<x86::reg32>(x86::reg32(5035104) /* 0x4cd460 */) = cpu.edi;
    // 004aa5ab  892d64d44c00           -mov dword ptr [0x4cd464], ebp
    app->getMemory<x86::reg32>(x86::reg32(5035108) /* 0x4cd464 */) = cpu.ebp;
    // 004aa5b1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004aa5b3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa5b4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa5b5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa5b6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa5b7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa5b8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa5b9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004aa5ba:
    // 004aa5ba  e841410000             -call 0x4ae700
    cpu.esp -= 4;
    sub_4ae700(app, cpu);
    if (cpu.terminate) return;
    // 004aa5bf  b930e74a00             -mov ecx, 0x4ae730
    cpu.ecx = 4908848 /*0x4ae730*/;
    // 004aa5c4  bb50e74a00             -mov ebx, 0x4ae750
    cpu.ebx = 4908880 /*0x4ae750*/;
    // 004aa5c9  be80e74a00             -mov esi, 0x4ae780
    cpu.esi = 4908928 /*0x4ae780*/;
    // 004aa5ce  bfa0e74a00             -mov edi, 0x4ae7a0
    cpu.edi = 4908960 /*0x4ae7a0*/;
    // 004aa5d3  bdc0e74a00             -mov ebp, 0x4ae7c0
    cpu.ebp = 4908992 /*0x4ae7c0*/;
    // 004aa5d8  b8f0e74a00             -mov eax, 0x4ae7f0
    cpu.eax = 4909040 /*0x4ae7f0*/;
    // 004aa5dd  890d50d44c00           -mov dword ptr [0x4cd450], ecx
    app->getMemory<x86::reg32>(x86::reg32(5035088) /* 0x4cd450 */) = cpu.ecx;
    // 004aa5e3  891d54d44c00           -mov dword ptr [0x4cd454], ebx
    app->getMemory<x86::reg32>(x86::reg32(5035092) /* 0x4cd454 */) = cpu.ebx;
    // 004aa5e9  893558d44c00           -mov dword ptr [0x4cd458], esi
    app->getMemory<x86::reg32>(x86::reg32(5035096) /* 0x4cd458 */) = cpu.esi;
    // 004aa5ef  893d5cd44c00           -mov dword ptr [0x4cd45c], edi
    app->getMemory<x86::reg32>(x86::reg32(5035100) /* 0x4cd45c */) = cpu.edi;
    // 004aa5f5  892d60d44c00           -mov dword ptr [0x4cd460], ebp
    app->getMemory<x86::reg32>(x86::reg32(5035104) /* 0x4cd460 */) = cpu.ebp;
    // 004aa5fb  a364d44c00             -mov dword ptr [0x4cd464], eax
    app->getMemory<x86::reg32>(x86::reg32(5035108) /* 0x4cd464 */) = cpu.eax;
    // 004aa600  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004aa602  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa603  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa604  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa605  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa606  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa607  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa608  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4aa610(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa610  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004aa611  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004aa612  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004aa613  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004aa614  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004aa615  833d00a44c0000         +cmp dword ptr [0x4ca400], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5022720) /* 0x4ca400 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aa61c  744c                   -je 0x4aa66a
    if (cpu.flags.zf)
    {
        goto L_0x004aa66a;
    }
    // 004aa61e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004aa61f  ba10e84a00             -mov edx, 0x4ae810
    cpu.edx = 4909072 /*0x4ae810*/;
    // 004aa624  b930e84a00             -mov ecx, 0x4ae830
    cpu.ecx = 4909104 /*0x4ae830*/;
    // 004aa629  bb60e84a00             -mov ebx, 0x4ae860
    cpu.ebx = 4909152 /*0x4ae860*/;
    // 004aa62e  be80e84a00             -mov esi, 0x4ae880
    cpu.esi = 4909184 /*0x4ae880*/;
    // 004aa633  bfa0e84a00             -mov edi, 0x4ae8a0
    cpu.edi = 4909216 /*0x4ae8a0*/;
    // 004aa638  bdd0e84a00             -mov ebp, 0x4ae8d0
    cpu.ebp = 4909264 /*0x4ae8d0*/;
    // 004aa63d  891568d44c00           -mov dword ptr [0x4cd468], edx
    app->getMemory<x86::reg32>(x86::reg32(5035112) /* 0x4cd468 */) = cpu.edx;
    // 004aa643  890d6cd44c00           -mov dword ptr [0x4cd46c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5035116) /* 0x4cd46c */) = cpu.ecx;
    // 004aa649  891d70d44c00           -mov dword ptr [0x4cd470], ebx
    app->getMemory<x86::reg32>(x86::reg32(5035120) /* 0x4cd470 */) = cpu.ebx;
    // 004aa64f  893574d44c00           -mov dword ptr [0x4cd474], esi
    app->getMemory<x86::reg32>(x86::reg32(5035124) /* 0x4cd474 */) = cpu.esi;
    // 004aa655  893d78d44c00           -mov dword ptr [0x4cd478], edi
    app->getMemory<x86::reg32>(x86::reg32(5035128) /* 0x4cd478 */) = cpu.edi;
    // 004aa65b  892d7cd44c00           -mov dword ptr [0x4cd47c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5035132) /* 0x4cd47c */) = cpu.ebp;
    // 004aa661  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa662  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004aa664  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa665  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa666  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa667  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa668  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa669  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004aa66a:
    // 004aa66a  b9f0e84a00             -mov ecx, 0x4ae8f0
    cpu.ecx = 4909296 /*0x4ae8f0*/;
    // 004aa66f  bb10e94a00             -mov ebx, 0x4ae910
    cpu.ebx = 4909328 /*0x4ae910*/;
    // 004aa674  be40e94a00             -mov esi, 0x4ae940
    cpu.esi = 4909376 /*0x4ae940*/;
    // 004aa679  bf60e94a00             -mov edi, 0x4ae960
    cpu.edi = 4909408 /*0x4ae960*/;
    // 004aa67e  bd80e94a00             -mov ebp, 0x4ae980
    cpu.ebp = 4909440 /*0x4ae980*/;
    // 004aa683  b8b0e94a00             -mov eax, 0x4ae9b0
    cpu.eax = 4909488 /*0x4ae9b0*/;
    // 004aa688  890d68d44c00           -mov dword ptr [0x4cd468], ecx
    app->getMemory<x86::reg32>(x86::reg32(5035112) /* 0x4cd468 */) = cpu.ecx;
    // 004aa68e  891d6cd44c00           -mov dword ptr [0x4cd46c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5035116) /* 0x4cd46c */) = cpu.ebx;
    // 004aa694  893570d44c00           -mov dword ptr [0x4cd470], esi
    app->getMemory<x86::reg32>(x86::reg32(5035120) /* 0x4cd470 */) = cpu.esi;
    // 004aa69a  893d74d44c00           -mov dword ptr [0x4cd474], edi
    app->getMemory<x86::reg32>(x86::reg32(5035124) /* 0x4cd474 */) = cpu.edi;
    // 004aa6a0  892d78d44c00           -mov dword ptr [0x4cd478], ebp
    app->getMemory<x86::reg32>(x86::reg32(5035128) /* 0x4cd478 */) = cpu.ebp;
    // 004aa6a6  a37cd44c00             -mov dword ptr [0x4cd47c], eax
    app->getMemory<x86::reg32>(x86::reg32(5035132) /* 0x4cd47c */) = cpu.eax;
    // 004aa6ab  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004aa6ad  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa6ae  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa6af  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa6b0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa6b1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa6b2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4aa6c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa6c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004aa6c1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004aa6c2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004aa6c3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004aa6c4  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004aa6c7  bd40000000             -mov ebp, 0x40
    cpu.ebp = 64 /*0x40*/;
    // 004aa6cc  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004aa6ce:
    // 004aa6ce  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004aa6d0  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004aa6d2  88d9                   -mov cl, bl
    cpu.cl = cpu.bl;
    // 004aa6d4  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004aa6d6  c1e006                 -shl eax, 6
    cpu.eax <<= 6 /*0x6*/ % 32;
L_0x004aa6d9:
    // 004aa6d9  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004aa6db  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 004aa6de  d3fe                   -sar esi, cl
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (cpu.cl % 32));
    // 004aa6e0  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004aa6e3  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 004aa6e6  81c200000010           -add edx, 0x10000000
    (cpu.edx) += x86::reg32(x86::sreg32(268435456 /*0x10000000*/));
    // 004aa6ec  db0424                 -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 004aa6ef  d99860845400           -fstp dword ptr [eax + 0x548460]
    app->getMemory<float>(cpu.eax + x86::reg32(5538912) /* 0x548460 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004aa6f5  39f8                   +cmp eax, edi
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
    // 004aa6f7  75e0                   -jne 0x4aa6d9
    if (!cpu.flags.zf)
    {
        goto L_0x004aa6d9;
    }
    // 004aa6f9  43                     -inc ebx
    (cpu.ebx)++;
    // 004aa6fa  83c540                 -add ebp, 0x40
    (cpu.ebp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004aa6fd  83fb0d                 +cmp ebx, 0xd
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
    // 004aa700  7ccc                   -jl 0x4aa6ce
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004aa6ce;
    }
    // 004aa702  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004aa705  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa706  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa707  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa708  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa709  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4aa70c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa70c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004aa70d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004aa70e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004aa70f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004aa710  bd40000000             -mov ebp, 0x40
    cpu.ebp = 64 /*0x40*/;
    // 004aa715  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004aa717:
    // 004aa717  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004aa719  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004aa71b  88d9                   -mov cl, bl
    cpu.cl = cpu.bl;
    // 004aa71d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004aa71f  c1e006                 -shl eax, 6
    cpu.eax <<= 6 /*0x6*/ % 32;
L_0x004aa722:
    // 004aa722  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004aa724  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 004aa727  d3fe                   -sar esi, cl
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (cpu.cl % 32));
    // 004aa729  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004aa72c  c1e608                 -shl esi, 8
    cpu.esi <<= 8 /*0x8*/ % 32;
    // 004aa72f  81c200000010           -add edx, 0x10000000
    (cpu.edx) += x86::reg32(x86::sreg32(268435456 /*0x10000000*/));
    // 004aa735  89b060885400           -mov dword ptr [eax + 0x548860], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5539936) /* 0x548860 */) = cpu.esi;
    // 004aa73b  39f8                   +cmp eax, edi
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
    // 004aa73d  75e3                   -jne 0x4aa722
    if (!cpu.flags.zf)
    {
        goto L_0x004aa722;
    }
    // 004aa73f  43                     -inc ebx
    (cpu.ebx)++;
    // 004aa740  83c540                 -add ebp, 0x40
    (cpu.ebp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004aa743  83fb0d                 +cmp ebx, 0xd
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
    // 004aa746  7ccf                   -jl 0x4aa717
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004aa717;
    }
    // 004aa748  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa749  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa74a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa74b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa74c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4aa750(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa750  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004aa751  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004aa752  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004aa753  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004aa754  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004aa755  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004aa756  833d00a44c0000         +cmp dword ptr [0x4ca400], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5022720) /* 0x4ca400 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aa75d  7450                   -je 0x4aa7af
    if (cpu.flags.zf)
    {
        goto L_0x004aa7af;
    }
    // 004aa75f  e8a8ffffff             -call 0x4aa70c
    cpu.esp -= 4;
    sub_4aa70c(app, cpu);
    if (cpu.terminate) return;
    // 004aa764  ba58eb4a00             -mov edx, 0x4aeb58
    cpu.edx = 4909912 /*0x4aeb58*/;
    // 004aa769  b9a8ef4a00             -mov ecx, 0x4aefa8
    cpu.ecx = 4911016 /*0x4aefa8*/;
    // 004aa76e  bbf0f14a00             -mov ebx, 0x4af1f0
    cpu.ebx = 4911600 /*0x4af1f0*/;
    // 004aa773  be04f44a00             -mov esi, 0x4af404
    cpu.esi = 4912132 /*0x4af404*/;
    // 004aa778  bf08f94a00             -mov edi, 0x4af908
    cpu.edi = 4913416 /*0x4af908*/;
    // 004aa77d  bd1cfb4a00             -mov ebp, 0x4afb1c
    cpu.ebp = 4913948 /*0x4afb1c*/;
    // 004aa782  891580d44c00           -mov dword ptr [0x4cd480], edx
    app->getMemory<x86::reg32>(x86::reg32(5035136) /* 0x4cd480 */) = cpu.edx;
    // 004aa788  890d84d44c00           -mov dword ptr [0x4cd484], ecx
    app->getMemory<x86::reg32>(x86::reg32(5035140) /* 0x4cd484 */) = cpu.ecx;
    // 004aa78e  891d88d44c00           -mov dword ptr [0x4cd488], ebx
    app->getMemory<x86::reg32>(x86::reg32(5035144) /* 0x4cd488 */) = cpu.ebx;
    // 004aa794  89358cd44c00           -mov dword ptr [0x4cd48c], esi
    app->getMemory<x86::reg32>(x86::reg32(5035148) /* 0x4cd48c */) = cpu.esi;
    // 004aa79a  893d90d44c00           -mov dword ptr [0x4cd490], edi
    app->getMemory<x86::reg32>(x86::reg32(5035152) /* 0x4cd490 */) = cpu.edi;
    // 004aa7a0  892d94d44c00           -mov dword ptr [0x4cd494], ebp
    app->getMemory<x86::reg32>(x86::reg32(5035156) /* 0x4cd494 */) = cpu.ebp;
    // 004aa7a6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004aa7a8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa7a9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa7aa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa7ab  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa7ac  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa7ad  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa7ae  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004aa7af:
    // 004aa7af  e80cffffff             -call 0x4aa6c0
    cpu.esp -= 4;
    sub_4aa6c0(app, cpu);
    if (cpu.terminate) return;
    // 004aa7b4  b9f8fc4a00             -mov ecx, 0x4afcf8
    cpu.ecx = 4914424 /*0x4afcf8*/;
    // 004aa7b9  bb2c014b00             -mov ebx, 0x4b012c
    cpu.ebx = 4915500 /*0x4b012c*/;
    // 004aa7be  be44034b00             -mov esi, 0x4b0344
    cpu.esi = 4916036 /*0x4b0344*/;
    // 004aa7c3  bf38054b00             -mov edi, 0x4b0538
    cpu.edi = 4916536 /*0x4b0538*/;
    // 004aa7c8  bd140a4b00             -mov ebp, 0x4b0a14
    cpu.ebp = 4917780 /*0x4b0a14*/;
    // 004aa7cd  b8200c4b00             -mov eax, 0x4b0c20
    cpu.eax = 4918304 /*0x4b0c20*/;
    // 004aa7d2  890d80d44c00           -mov dword ptr [0x4cd480], ecx
    app->getMemory<x86::reg32>(x86::reg32(5035136) /* 0x4cd480 */) = cpu.ecx;
    // 004aa7d8  891d84d44c00           -mov dword ptr [0x4cd484], ebx
    app->getMemory<x86::reg32>(x86::reg32(5035140) /* 0x4cd484 */) = cpu.ebx;
    // 004aa7de  893588d44c00           -mov dword ptr [0x4cd488], esi
    app->getMemory<x86::reg32>(x86::reg32(5035144) /* 0x4cd488 */) = cpu.esi;
    // 004aa7e4  893d8cd44c00           -mov dword ptr [0x4cd48c], edi
    app->getMemory<x86::reg32>(x86::reg32(5035148) /* 0x4cd48c */) = cpu.edi;
    // 004aa7ea  892d90d44c00           -mov dword ptr [0x4cd490], ebp
    app->getMemory<x86::reg32>(x86::reg32(5035152) /* 0x4cd490 */) = cpu.ebp;
    // 004aa7f0  a394d44c00             -mov dword ptr [0x4cd494], eax
    app->getMemory<x86::reg32>(x86::reg32(5035156) /* 0x4cd494 */) = cpu.eax;
    // 004aa7f5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004aa7f7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa7f8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa7f9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa7fa  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa7fb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa7fc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa7fd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4aa800(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa800  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004aa801  833d00a44c0000         +cmp dword ptr [0x4ca400], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5022720) /* 0x4ca400 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aa808  741f                   -je 0x4aa829
    if (cpu.flags.zf)
    {
        goto L_0x004aa829;
    }
    // 004aa80a  bff40d4b00             -mov edi, 0x4b0df4
    cpu.edi = 4918772 /*0x4b0df4*/;
    // 004aa80f  b8c80f4b00             -mov eax, 0x4b0fc8
    cpu.eax = 4919240 /*0x4b0fc8*/;
    // 004aa814  893db0d44c00           -mov dword ptr [0x4cd4b0], edi
    app->getMemory<x86::reg32>(x86::reg32(5035184) /* 0x4cd4b0 */) = cpu.edi;
    // 004aa81a  893dbcd44c00           -mov dword ptr [0x4cd4bc], edi
    app->getMemory<x86::reg32>(x86::reg32(5035196) /* 0x4cd4bc */) = cpu.edi;
    // 004aa820  a3c4d44c00             -mov dword ptr [0x4cd4c4], eax
    app->getMemory<x86::reg32>(x86::reg32(5035204) /* 0x4cd4c4 */) = cpu.eax;
    // 004aa825  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004aa827  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa828  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004aa829:
    // 004aa829  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004aa82a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004aa82b  b968114b00             -mov ecx, 0x4b1168
    cpu.ecx = 4919656 /*0x4b1168*/;
    // 004aa830  be70134b00             -mov esi, 0x4b1370
    cpu.esi = 4920176 /*0x4b1370*/;
    // 004aa835  890db0d44c00           -mov dword ptr [0x4cd4b0], ecx
    app->getMemory<x86::reg32>(x86::reg32(5035184) /* 0x4cd4b0 */) = cpu.ecx;
    // 004aa83b  890dbcd44c00           -mov dword ptr [0x4cd4bc], ecx
    app->getMemory<x86::reg32>(x86::reg32(5035196) /* 0x4cd4bc */) = cpu.ecx;
    // 004aa841  8935c4d44c00           -mov dword ptr [0x4cd4c4], esi
    app->getMemory<x86::reg32>(x86::reg32(5035204) /* 0x4cd4c4 */) = cpu.esi;
    // 004aa847  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa848  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa849  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004aa84b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa84c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_4aa850(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa850  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004aa851  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004aa853  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004aa854  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004aa857  8b7d0c                 -mov edi, dword ptr [ebp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004aa85a  8b15b04f5400           -mov edx, dword ptr [0x544fb0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5525424) /* 0x544fb0 */);
    // 004aa860  a150f65300             -mov eax, dword ptr [0x53f650]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5502544) /* 0x53f650 */);
    // 004aa865  8b1d704f5400           -mov ebx, dword ptr [0x544f70]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5525360) /* 0x544f70 */);
    // 004aa86b  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004aa86e  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004aa871:
    // 004aa871  3bc2                   +cmp eax, edx
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
    // 004aa873  7c05                   -jl 0x4aa87a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004aa87a;
    }
    // 004aa875  a1804f5400             -mov eax, dword ptr [0x544f80]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5525376) /* 0x544f80 */);
L_0x004aa87a:
    // 004aa87a  3bda                   +cmp ebx, edx
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
    // 004aa87c  7c06                   -jl 0x4aa884
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004aa884;
    }
    // 004aa87e  8b1d804f5400           -mov ebx, dword ptr [0x544f80]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5525376) /* 0x544f80 */);
L_0x004aa884:
    // 004aa884  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004aa886  d805a04f5400           -fadd dword ptr [0x544fa0]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5525408) /* 0x544fa0 */));
    // 004aa88c  d903                   -fld dword ptr [ebx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebx)));
    // 004aa88e  a350f65300             -mov dword ptr [0x53f650], eax
    app->getMemory<x86::reg32>(x86::reg32(5502544) /* 0x53f650 */) = cpu.eax;
    // 004aa893  891d704f5400           -mov dword ptr [0x544f70], ebx
    app->getMemory<x86::reg32>(x86::reg32(5525360) /* 0x544f70 */) = cpu.ebx;
    // 004aa899  d80d54e14c00           -fmul dword ptr [0x4ce154]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5038420) /* 0x4ce154 */));
    // 004aa89f  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004aa8a1  d910                   -fst dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    // 004aa8a3  d80d54e14c00           -fmul dword ptr [0x4ce154]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5038420) /* 0x4ce154 */));
    // 004aa8a9  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004aa8ab  d91da04f5400           -fstp dword ptr [0x544fa0]
    app->getMemory<float>(x86::reg32(5525408) /* 0x544fa0 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004aa8b1  d82b                   -fsubr dword ptr [ebx]
    cpu.fpu.st(0) = x86::Float(app->getMemory<float>(cpu.ebx)) - cpu.fpu.st(0);
    // 004aa8b3  8b15b44f5400           -mov edx, dword ptr [0x544fb4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5525428) /* 0x544fb4 */);
    // 004aa8b9  a154f65300             -mov eax, dword ptr [0x53f654]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5502548) /* 0x53f654 */);
    // 004aa8be  8b1d744f5400           -mov ebx, dword ptr [0x544f74]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5525364) /* 0x544f74 */);
    // 004aa8c4  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004aa8c7  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004aa8ca  3bc2                   +cmp eax, edx
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
    // 004aa8cc  7c05                   -jl 0x4aa8d3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004aa8d3;
    }
    // 004aa8ce  a1844f5400             -mov eax, dword ptr [0x544f84]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5525380) /* 0x544f84 */);
L_0x004aa8d3:
    // 004aa8d3  3bda                   +cmp ebx, edx
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
    // 004aa8d5  7c06                   -jl 0x4aa8dd
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004aa8dd;
    }
    // 004aa8d7  8b1d844f5400           -mov ebx, dword ptr [0x544f84]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5525380) /* 0x544f84 */);
L_0x004aa8dd:
    // 004aa8dd  d805a44f5400           -fadd dword ptr [0x544fa4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5525412) /* 0x544fa4 */));
    // 004aa8e3  d903                   -fld dword ptr [ebx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebx)));
    // 004aa8e5  a354f65300             -mov dword ptr [0x53f654], eax
    app->getMemory<x86::reg32>(x86::reg32(5502548) /* 0x53f654 */) = cpu.eax;
    // 004aa8ea  891d744f5400           -mov dword ptr [0x544f74], ebx
    app->getMemory<x86::reg32>(x86::reg32(5525364) /* 0x544f74 */) = cpu.ebx;
    // 004aa8f0  d80d58e14c00           -fmul dword ptr [0x4ce158]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5038424) /* 0x4ce158 */));
    // 004aa8f6  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004aa8f8  d910                   -fst dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    // 004aa8fa  d80d58e14c00           -fmul dword ptr [0x4ce158]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5038424) /* 0x4ce158 */));
    // 004aa900  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004aa902  d91da44f5400           -fstp dword ptr [0x544fa4]
    app->getMemory<float>(x86::reg32(5525412) /* 0x544fa4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004aa908  d82b                   -fsubr dword ptr [ebx]
    cpu.fpu.st(0) = x86::Float(app->getMemory<float>(cpu.ebx)) - cpu.fpu.st(0);
    // 004aa90a  d90528e14c00           -fld dword ptr [0x4ce128]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5038376) /* 0x4ce128 */)));
    // 004aa910  d80d38e14c00           -fmul dword ptr [0x4ce138]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5038392) /* 0x4ce138 */));
    // 004aa916  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004aa918  d80d48e14c00           -fmul dword ptr [0x4ce148]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5038408) /* 0x4ce148 */));
    // 004aa91e  a158f65300             -mov eax, dword ptr [0x53f658]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5502552) /* 0x53f658 */);
    // 004aa923  8b1d784f5400           -mov ebx, dword ptr [0x544f78]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5525368) /* 0x544f78 */);
    // 004aa929  8b15b84f5400           -mov edx, dword ptr [0x544fb8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5525432) /* 0x544fb8 */);
    // 004aa92f  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004aa931  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004aa934  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004aa937  3bc2                   +cmp eax, edx
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
    // 004aa939  7c05                   -jl 0x4aa940
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004aa940;
    }
    // 004aa93b  a1884f5400             -mov eax, dword ptr [0x544f88]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5525384) /* 0x544f88 */);
L_0x004aa940:
    // 004aa940  3bda                   +cmp ebx, edx
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
    // 004aa942  7c06                   -jl 0x4aa94a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004aa94a;
    }
    // 004aa944  8b1d884f5400           -mov ebx, dword ptr [0x544f88]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5525384) /* 0x544f88 */);
L_0x004aa94a:
    // 004aa94a  d91528e14c00           -fst dword ptr [0x4ce128]
    app->getMemory<float>(x86::reg32(5038376) /* 0x4ce128 */) = float(cpu.fpu.st(0));
    // 004aa950  d805a84f5400           -fadd dword ptr [0x544fa8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5525416) /* 0x544fa8 */));
    // 004aa956  d903                   -fld dword ptr [ebx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebx)));
    // 004aa958  a358f65300             -mov dword ptr [0x53f658], eax
    app->getMemory<x86::reg32>(x86::reg32(5502552) /* 0x53f658 */) = cpu.eax;
    // 004aa95d  891d784f5400           -mov dword ptr [0x544f78], ebx
    app->getMemory<x86::reg32>(x86::reg32(5525368) /* 0x544f78 */) = cpu.ebx;
    // 004aa963  d80d5ce14c00           -fmul dword ptr [0x4ce15c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5038428) /* 0x4ce15c */));
    // 004aa969  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004aa96b  d910                   -fst dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    // 004aa96d  d80d5ce14c00           -fmul dword ptr [0x4ce15c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5038428) /* 0x4ce15c */));
    // 004aa973  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004aa975  d91da84f5400           -fstp dword ptr [0x544fa8]
    app->getMemory<float>(x86::reg32(5525416) /* 0x544fa8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004aa97b  d82b                   -fsubr dword ptr [ebx]
    cpu.fpu.st(0) = x86::Float(app->getMemory<float>(cpu.ebx)) - cpu.fpu.st(0);
    // 004aa97d  8b15bc4f5400           -mov edx, dword ptr [0x544fbc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5525436) /* 0x544fbc */);
    // 004aa983  a15cf65300             -mov eax, dword ptr [0x53f65c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5502556) /* 0x53f65c */);
    // 004aa988  8b1d7c4f5400           -mov ebx, dword ptr [0x544f7c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5525372) /* 0x544f7c */);
    // 004aa98e  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004aa991  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004aa994  3bc2                   +cmp eax, edx
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
    // 004aa996  7c05                   -jl 0x4aa99d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004aa99d;
    }
    // 004aa998  a18c4f5400             -mov eax, dword ptr [0x544f8c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5525388) /* 0x544f8c */);
L_0x004aa99d:
    // 004aa99d  3bda                   +cmp ebx, edx
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
    // 004aa99f  7c06                   -jl 0x4aa9a7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004aa9a7;
    }
    // 004aa9a1  8b1d8c4f5400           -mov ebx, dword ptr [0x544f8c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5525388) /* 0x544f8c */);
L_0x004aa9a7:
    // 004aa9a7  d805ac4f5400           -fadd dword ptr [0x544fac]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5525420) /* 0x544fac */));
    // 004aa9ad  d903                   -fld dword ptr [ebx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebx)));
    // 004aa9af  a35cf65300             -mov dword ptr [0x53f65c], eax
    app->getMemory<x86::reg32>(x86::reg32(5502556) /* 0x53f65c */) = cpu.eax;
    // 004aa9b4  891d7c4f5400           -mov dword ptr [0x544f7c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5525372) /* 0x544f7c */) = cpu.ebx;
    // 004aa9ba  d80d60e14c00           -fmul dword ptr [0x4ce160]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5038432) /* 0x4ce160 */));
    // 004aa9c0  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004aa9c2  d910                   -fst dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    // 004aa9c4  d80d60e14c00           -fmul dword ptr [0x4ce160]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5038432) /* 0x4ce160 */));
    // 004aa9ca  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004aa9cc  d91dac4f5400           -fstp dword ptr [0x544fac]
    app->getMemory<float>(x86::reg32(5525420) /* 0x544fac */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004aa9d2  d82b                   -fsubr dword ptr [ebx]
    cpu.fpu.st(0) = x86::Float(app->getMemory<float>(cpu.ebx)) - cpu.fpu.st(0);
    // 004aa9d4  d90530e14c00           -fld dword ptr [0x4ce130]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5038384) /* 0x4ce130 */)));
    // 004aa9da  d80d40e14c00           -fmul dword ptr [0x4ce140]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5038400) /* 0x4ce140 */));
    // 004aa9e0  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004aa9e2  d80d50e14c00           -fmul dword ptr [0x4ce150]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5038416) /* 0x4ce150 */));
    // 004aa9e8  8b15b04f5400           -mov edx, dword ptr [0x544fb0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5525424) /* 0x544fb0 */);
    // 004aa9ee  a150f65300             -mov eax, dword ptr [0x53f650]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5502544) /* 0x53f650 */);
    // 004aa9f3  8b1d704f5400           -mov ebx, dword ptr [0x544f70]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5525360) /* 0x544f70 */);
    // 004aa9f9  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004aa9fb  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004aa9fe  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004aaa01  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004aaa04  d91530e14c00           -fst dword ptr [0x4ce130]
    app->getMemory<float>(x86::reg32(5038384) /* 0x4ce130 */) = float(cpu.fpu.st(0));
    // 004aaa0a  d95ffc                 -fstp dword ptr [edi - 4]
    app->getMemory<float>(cpu.edi + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004aaa0d  83e901                 +sub ecx, 1
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
    // 004aaa10  0f8f5bfeffff           -jg 0x4aa871
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004aa871;
    }
    // 004aaa16  61                     -popal 
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
    // 004aaa17  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aaa18  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4aaa20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aaa20  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004aaa24  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004aaa28  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004aaa2c  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 004aaa2f  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004aaa31  39c8                   +cmp eax, ecx
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
    // 004aaa33  7313                   -jae 0x4aaa48
    if (!cpu.flags.cf)
    {
        goto L_0x004aaa48;
    }
L_0x004aaa35:
    // 004aaa35  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 004aaa37  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004aaa3a  d84204                 -fadd dword ptr [edx + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */));
    // 004aaa3d  83c208                 -add edx, 8
    (cpu.edx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004aaa40  d958fc                 -fstp dword ptr [eax - 4]
    app->getMemory<float>(cpu.eax + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004aaa43  39c8                   +cmp eax, ecx
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
    // 004aaa45  72ee                   -jb 0x4aaa35
    if (cpu.flags.cf)
    {
        goto L_0x004aaa35;
    }
    // 004aaa47  90                     -nop 
    ;
L_0x004aaa48:
    // 004aaa48  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4aaa50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aaa50  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004aaa51  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004aaa52  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004aaa55  c704240000803f         -mov dword ptr [esp], 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp) = 1065353216 /*0x3f800000*/;
    // 004aaa5c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004aaa5e  7e2f                   -jle 0x4aaa8f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004aaa8f;
    }
    // 004aaa60  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004aaa65  39d0                   +cmp eax, edx
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
    // 004aaa67  7c0f                   -jl 0x4aaa78
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004aaa78;
    }
    // 004aaa69  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004aaa6b:
    // 004aaa6b  85c2                   +test edx, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.eax));
    // 004aaa6d  7512                   -jne 0x4aaa81
    if (!cpu.flags.zf)
    {
        goto L_0x004aaa81;
    }
L_0x004aaa6f:
    // 004aaa6f  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004aaa71  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004aaa74  39c2                   +cmp edx, eax
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
    // 004aaa76  7ef3                   -jle 0x4aaa6b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004aaa6b;
    }
L_0x004aaa78:
    // 004aaa78  d90424                 -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 004aaa7b  83c404                 +add esp, 4
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
    // 004aaa7e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aaa7f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aaa80  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004aaa81:
    // 004aaa81  d90424                 +fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 004aaa84  d889a0f74c00           +fmul dword ptr [ecx + 0x4cf7a0]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(5044128) /* 0x4cf7a0 */));
    // 004aaa8a  d91c24                 +fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004aaa8d  ebe0                   -jmp 0x4aaa6f
    goto L_0x004aaa6f;
L_0x004aaa8f:
    // 004aaa8f  6bc0ff                 -imul eax, eax, -1
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(-1 /*-0x1*/)));
    // 004aaa92  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004aaa97  39d0                   +cmp eax, edx
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
    // 004aaa99  7cdd                   -jl 0x4aaa78
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004aaa78;
    }
    // 004aaa9b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004aaa9d:
    // 004aaa9d  85c2                   +test edx, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.eax));
    // 004aaa9f  750b                   -jne 0x4aaaac
    if (!cpu.flags.zf)
    {
        goto L_0x004aaaac;
    }
    // 004aaaa1  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004aaaa3  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004aaaa6  39c2                   +cmp edx, eax
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
    // 004aaaa8  7fce                   -jg 0x4aaa78
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004aaa78;
    }
    // 004aaaaa  ebf1                   -jmp 0x4aaa9d
    goto L_0x004aaa9d;
L_0x004aaaac:
    // 004aaaac  d90424                 -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 004aaaaf  d8b1a0f74c00           -fdiv dword ptr [ecx + 0x4cf7a0]
    cpu.fpu.st(0) /= x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(5044128) /* 0x4cf7a0 */));
    // 004aaab5  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004aaab8  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004aaaba  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004aaabd  39c2                   +cmp edx, eax
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
    // 004aaabf  7fb7                   -jg 0x4aaa78
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004aaa78;
    }
    // 004aaac1  ebda                   -jmp 0x4aaa9d
    goto L_0x004aaa9d;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4aaad0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aaad0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004aaad1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004aaad2  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004aaad4  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004aaad6  c1f806                 -sar eax, 6
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (6 /*0x6*/ % 32));
    // 004aaad9  c0e407                 +shl ah, 7
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
    // 004aaadc  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004aaade  00e4                   +add ah, ah
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
    // 004aaae0  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 004aaae2  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004aaae4  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004aaae9  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004aaaeb  8b048500ab4c00         -mov eax, dword ptr [eax*4 + 0x4cab00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5024512) /* 0x4cab00 */ + cpu.eax * 4);
    // 004aaaf2  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004aaaf4  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004aaaf6  b900000100             -mov ecx, 0x10000
    cpu.ecx = 65536 /*0x10000*/;
    // 004aaafb  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004aaafd  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004aaaff  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004aab01  0fafc7                 -imul eax, edi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 004aab04  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004aab07  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004aab09  83f87f                 +cmp eax, 0x7f
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
    // 004aab0c  7f16                   -jg 0x4aab24
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004aab24;
    }
L_0x004aab0e:
    // 004aab0e  81c200000100           -add edx, 0x10000
    (cpu.edx) += x86::reg32(x86::sreg32(65536 /*0x10000*/));
    // 004aab14  0faffa                 -imul edi, edx
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004aab17  c1ef10                 -shr edi, 0x10
    cpu.edi >>= 16 /*0x10*/ % 32;
    // 004aab1a  893e                   -mov dword ptr [esi], edi
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edi;
    // 004aab1c  83ff7f                 +cmp edi, 0x7f
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
    // 004aab1f  7f0b                   -jg 0x4aab2c
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004aab2c;
    }
    // 004aab21  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aab22  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aab23  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004aab24:
    // 004aab24  c7037f000000           -mov dword ptr [ebx], 0x7f
    app->getMemory<x86::reg32>(cpu.ebx) = 127 /*0x7f*/;
    // 004aab2a  ebe2                   -jmp 0x4aab0e
    goto L_0x004aab0e;
L_0x004aab2c:
    // 004aab2c  c7067f000000           -mov dword ptr [esi], 0x7f
    app->getMemory<x86::reg32>(cpu.esi) = 127 /*0x7f*/;
    // 004aab32  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aab33  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aab34  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aab35(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aab35  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004aab36  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004aab37  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004aab38  8a25b5e14c00           -mov ah, byte ptr [0x4ce1b5]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5038517) /* 0x4ce1b5 */);
    // 004aab3e  80e4f8                 -and ah, 0xf8
    cpu.ah &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 004aab41  88e2                   -mov dl, ah
    cpu.dl = cpu.ah;
    // 004aab43  8825b5e14c00           -mov byte ptr [0x4ce1b5], ah
    app->getMemory<x86::reg8>(x86::reg32(5038517) /* 0x4ce1b5 */) = cpu.ah;
    // 004aab49  80ca04                 +or dl, 4
    cpu.clear_co();
    cpu.set_szp((cpu.dl |= x86::reg8(x86::sreg8(4 /*0x4*/))));
    // 004aab4c  bb74e14c00             -mov ebx, 0x4ce174
    cpu.ebx = 5038452 /*0x4ce174*/;
    // 004aab51  8815b5e14c00           -mov byte ptr [0x4ce1b5], dl
    app->getMemory<x86::reg8>(x86::reg32(5038517) /* 0x4ce1b5 */) = cpu.dl;
    // 004aab57  eb5d                   -jmp 0x4aabb6
    goto L_0x004aabb6;
L_0x004aab59:
    // 004aab59  b81d000000             -mov eax, 0x1d
    cpu.eax = 29 /*0x1d*/;
    // 004aab5e  e8b0f4feff             -call 0x49a013
    cpu.esp -= 4;
    malloc(app, cpu);
    if (cpu.terminate) return;
    // 004aab63  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004aab65  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004aab67  751f                   -jne 0x4aab88
    if (!cpu.flags.zf)
    {
        goto L_0x004aab88;
    }
    // 004aab69  b81d000000             -mov eax, 0x1d
    cpu.eax = 29 /*0x1d*/;
    // 004aab6e  e8a0f4feff             -call 0x49a013
    cpu.esp -= 4;
    malloc(app, cpu);
    if (cpu.terminate) return;
    // 004aab73  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004aab75  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004aab77  750f                   -jne 0x4aab88
    if (!cpu.flags.zf)
    {
        goto L_0x004aab88;
    }
    // 004aab79  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004aab7e  b848174c00             -mov eax, 0x4c1748
    cpu.eax = 4986696 /*0x4c1748*/;
    // 004aab83  e869140000             -call 0x4abff1
    cpu.esp -= 4;
    sub_4abff1(app, cpu);
    if (cpu.terminate) return;
L_0x004aab88:
    // 004aab88  a1c44f5400             -mov eax, dword ptr [0x544fc4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5525444) /* 0x544fc4 */);
    // 004aab8d  895904                 -mov dword ptr [ecx + 4], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004aab90  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 004aab92  894b08                 -mov dword ptr [ebx + 8], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 004aab95  c7410800000000         -mov dword ptr [ecx + 8], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004aab9c  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004aab9f  c6401400               -mov byte ptr [eax + 0x14], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 004aaba3  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004aaba6  890dc44f5400           -mov dword ptr [0x544fc4], ecx
    app->getMemory<x86::reg32>(x86::reg32(5525444) /* 0x544fc4 */) = cpu.ecx;
    // 004aabac  83c31a                 -add ebx, 0x1a
    (cpu.ebx) += x86::reg32(x86::sreg32(26 /*0x1a*/));
    // 004aabaf  c7400c00000000         -mov dword ptr [eax + 0xc], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
L_0x004aabb6:
    // 004aabb6  8b530c                 -mov edx, dword ptr [ebx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004aabb9  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004aabbb  759c                   -jne 0x4aab59
    if (!cpu.flags.zf)
    {
        goto L_0x004aab59;
    }
    // 004aabbd  8915c84f5400           -mov dword ptr [0x544fc8], edx
    app->getMemory<x86::reg32>(x86::reg32(5525448) /* 0x544fc8 */) = cpu.edx;
    // 004aabc3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aabc4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aabc5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aabc6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aabc7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aabc7  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004aabc9  e80a000000             -call 0x4aabd8
    cpu.esp -= 4;
    sub_4aabd8(app, cpu);
    if (cpu.terminate) return;
    // 004aabce  e90e2bffff             -jmp 0x49d6e1
    return sub_49d6e1(app, cpu);
}

/* align: skip  */
void Application::sub_4aabd3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aabd3  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 004aabd8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004aabd9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004aabda  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004aabdb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004aabdc  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004aabde  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004aabe1  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004aabe3  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004aabe6  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004aabe8  be74e14c00             -mov esi, 0x4ce174
    cpu.esi = 5038452 /*0x4ce174*/;
    // 004aabed  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004aabef  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004aabf1  01c6                   +add esi, eax
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
    // 004aabf3  a1c44f5400             -mov eax, dword ptr [0x544fc4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5525444) /* 0x544fc4 */);
    // 004aabf8  eb2b                   -jmp 0x4aac25
    goto L_0x004aac25;
L_0x004aabfa:
    // 004aabfa  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004aabfc  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004aabff  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004aac04  f6400d40               +test byte ptr [eax + 0xd], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */) & 64 /*0x40*/));
    // 004aac08  7513                   -jne 0x4aac1d
    if (!cpu.flags.zf)
    {
        goto L_0x004aac1d;
    }
    // 004aac0a  f6400d08               +test byte ptr [eax + 0xd], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */) & 8 /*0x8*/));
    // 004aac0e  750d                   -jne 0x4aac1d
    if (!cpu.flags.zf)
    {
        goto L_0x004aac1d;
    }
    // 004aac10  39f0                   +cmp eax, esi
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
    // 004aac12  720f                   -jb 0x4aac23
    if (cpu.flags.cf)
    {
        goto L_0x004aac23;
    }
    // 004aac14  3dc2e14c00             +cmp eax, 0x4ce1c2
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5038530 /*0x4ce1c2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aac19  7302                   -jae 0x4aac1d
    if (!cpu.flags.cf)
    {
        goto L_0x004aac1d;
    }
    // 004aac1b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004aac1d:
    // 004aac1d  e85468fdff             -call 0x481476
    cpu.esp -= 4;
    sub_481476(app, cpu);
    if (cpu.terminate) return;
    // 004aac22  43                     -inc ebx
    (cpu.ebx)++;
L_0x004aac23:
    // 004aac23  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x004aac25:
    // 004aac25  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004aac27  75d1                   -jne 0x4aabfa
    if (!cpu.flags.zf)
    {
        goto L_0x004aabfa;
    }
    // 004aac29  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004aac2b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aac2c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aac2d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aac2e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aac2f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aabd8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004aabd8;
    // 004aabd3  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
L_entry_0x004aabd8:
    // 004aabd8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004aabd9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004aabda  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004aabdb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004aabdc  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004aabde  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004aabe1  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004aabe3  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004aabe6  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004aabe8  be74e14c00             -mov esi, 0x4ce174
    cpu.esi = 5038452 /*0x4ce174*/;
    // 004aabed  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004aabef  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004aabf1  01c6                   +add esi, eax
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
    // 004aabf3  a1c44f5400             -mov eax, dword ptr [0x544fc4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5525444) /* 0x544fc4 */);
    // 004aabf8  eb2b                   -jmp 0x4aac25
    goto L_0x004aac25;
L_0x004aabfa:
    // 004aabfa  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004aabfc  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004aabff  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004aac04  f6400d40               +test byte ptr [eax + 0xd], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */) & 64 /*0x40*/));
    // 004aac08  7513                   -jne 0x4aac1d
    if (!cpu.flags.zf)
    {
        goto L_0x004aac1d;
    }
    // 004aac0a  f6400d08               +test byte ptr [eax + 0xd], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */) & 8 /*0x8*/));
    // 004aac0e  750d                   -jne 0x4aac1d
    if (!cpu.flags.zf)
    {
        goto L_0x004aac1d;
    }
    // 004aac10  39f0                   +cmp eax, esi
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
    // 004aac12  720f                   -jb 0x4aac23
    if (cpu.flags.cf)
    {
        goto L_0x004aac23;
    }
    // 004aac14  3dc2e14c00             +cmp eax, 0x4ce1c2
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5038530 /*0x4ce1c2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aac19  7302                   -jae 0x4aac1d
    if (!cpu.flags.cf)
    {
        goto L_0x004aac1d;
    }
    // 004aac1b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004aac1d:
    // 004aac1d  e85468fdff             -call 0x481476
    cpu.esp -= 4;
    sub_481476(app, cpu);
    if (cpu.terminate) return;
    // 004aac22  43                     -inc ebx
    (cpu.ebx)++;
L_0x004aac23:
    // 004aac23  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x004aac25:
    // 004aac25  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004aac27  75d1                   -jne 0x4aabfa
    if (!cpu.flags.zf)
    {
        goto L_0x004aabfa;
    }
    // 004aac29  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004aac2b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aac2c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aac2d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aac2e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aac2f  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
