#include "nfs2sea.h"
#include <lib/thread.h>

namespace nfs2sea
{

/* align: skip 0x90 */
void Application::sub_4b3f30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b3f30);
    // 004b3f30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b3f31  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b3f32  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b3f33  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b3f34  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004b3f37  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004b3f3b  8b7c242c               -mov edi, dword ptr [esp + 0x2c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004b3f3f  8b542430               -mov edx, dword ptr [esp + 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004b3f43  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b3f45  8a481d                 -mov cl, byte ptr [eax + 0x1d]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(29) /* 0x1d */);
    // 004b3f48  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004b3f4a  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 004b3f4c  0f85f2000000           -jne 0x4b4044
    if (!cpu.flags.zf)
    {
        goto L_0x004b4044;
    }
L_0x004b3f52:
    // 004b3f52  807b1c00               +cmp byte ptr [ebx + 0x1c], 0
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
    // 004b3f56  7412                   -je 0x4b3f6a
    if (cpu.flags.zf)
    {
        goto L_0x004b3f6a;
    }
    // 004b3f58  8b4310                 -mov eax, dword ptr [ebx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004b3f5b  8946fc                 -mov dword ptr [esi - 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004b3f5e  83ee04                 -sub esi, 4
    (cpu.esi) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b3f61  8b430c                 -mov eax, dword ptr [ebx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004b3f64  8946fc                 -mov dword ptr [esi - 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004b3f67  83ee04                 -sub esi, 4
    (cpu.esi) -= x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004b3f6a:
    // 004b3f6a  8b6c2434               -mov ebp, dword ptr [esp + 0x34]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004b3f6e  c70300000000           -mov dword ptr [ebx], 0
    app->getMemory<x86::reg32>(cpu.ebx) = 0 /*0x0*/;
    // 004b3f74  4f                     -dec edi
    (cpu.edi)--;
    // 004b3f75  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp);
    // 004b3f78  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004b3f7a  7e33                   -jle 0x4b3faf
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b3faf;
    }
    // 004b3f7c  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b3f7f  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b3f82  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b3f85  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004b3f88  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004b3f8b  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b3f8c  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004b3f8f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b3f90  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004b3f94  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004b3f98  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b3f99  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b3f9a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b3f9b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b3f9c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b3f9d  e8625f0000             -call 0x4b9f04
    cpu.esp -= 4;
    sub_4b9f04(app, cpu);
    if (cpu.terminate) return;
    // 004b3fa2  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004b3fa5  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b3fa9  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b3fac  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x004b3faf:
    // 004b3faf  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b3fb1  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b3fb4  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004b3fb8  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004b3fbb  df2c24                 -fild qword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.esp))));
    // 004b3fbe  dc0d3cf74c00           -fmul qword ptr [0x4cf73c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5044028) /* 0x4cf73c */));
    // 004b3fc4  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b3fc6  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004b3fc8  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 004b3fca  dee1                   -fsubrp st(1)
    cpu.fpu.st(1) = cpu.fpu.st(0) - x86::Float(cpu.fpu.st(1));
    cpu.fpu.pop();
    // 004b3fcc  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b3fce  d944c608               -fld dword ptr [esi + eax*8 + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(8) /* 0x8 */ + cpu.eax * 8)));
    // 004b3fd2  d8ca                   -fmul st(2)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(2));
    // 004b3fd4  d904c6                 -fld dword ptr [esi + eax*8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + cpu.eax * 8)));
    // 004b3fd7  d8ca                   -fmul st(2)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(2));
    // 004b3fd9  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b3fdb  d95cfd00               -fstp dword ptr [ebp + edi*8]
    app->getMemory<float>(cpu.ebp + cpu.edi * 8) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b3fdf  d84cd604               -fmul dword ptr [esi + edx*8 + 4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.edx * 8));
    // 004b3fe3  d944d60c               -fld dword ptr [esi + edx*8 + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(12) /* 0xc */ + cpu.edx * 8)));
    // 004b3fe7  deca                   -fmulp st(2)
    cpu.fpu.st(2) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b3fe9  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b3feb  d95cfd04               -fstp dword ptr [ebp + edi*8 + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */ + cpu.edi * 8) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b3fef  d944d608               -fld dword ptr [esi + edx*8 + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(8) /* 0x8 */ + cpu.edx * 8)));
    // 004b3ff3  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b3ff6  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b3ff9  8b3b                   -mov edi, dword ptr [ebx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b3ffb  8b6b08                 -mov ebp, dword ptr [ebx + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b3ffe  d95b14                 -fstp dword ptr [ebx + 0x14]
    app->getMemory<float>(cpu.ebx + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b4001  d944d60c               -fld dword ptr [esi + edx*8 + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(12) /* 0xc */ + cpu.edx * 8)));
    // 004b4005  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b4007  d95b18                 -fstp dword ptr [ebx + 0x18]
    app->getMemory<float>(cpu.ebx + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b400a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b400c  894b04                 -mov dword ptr [ebx + 4], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004b400f  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b4012  66c743060000           -mov word ptr [ebx + 6], 0
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 004b4018  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b401a  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b401d  893b                   -mov dword ptr [ebx], edi
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edi;
    // 004b401f  39e8                   +cmp eax, ebp
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
    // 004b4021  7236                   -jb 0x4b4059
    if (cpu.flags.cf)
    {
        goto L_0x004b4059;
    }
    // 004b4023  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b4025  c6431c01               -mov byte ptr [ebx + 0x1c], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(28) /* 0x1c */) = 1 /*0x1*/;
    // 004b4029  d904c6                 -fld dword ptr [esi + eax*8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + cpu.eax * 8)));
    // 004b402c  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b402e  d95b0c                 -fstp dword ptr [ebx + 0xc]
    app->getMemory<float>(cpu.ebx + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b4031  8b54c604               -mov edx, dword ptr [esi + eax*8 + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.eax * 8);
    // 004b4035  895310                 -mov dword ptr [ebx + 0x10], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004b4038  c6431d01               -mov byte ptr [ebx + 0x1d], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(29) /* 0x1d */) = 1 /*0x1*/;
    // 004b403c  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004b403f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4040  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4041  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4042  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4043  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b4044:
    // 004b4044  8d72fc                 -lea esi, [edx - 4]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 004b4047  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004b404a  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 004b404c  83ee04                 +sub esi, 4
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
    // 004b404f  8b5014                 -mov edx, dword ptr [eax + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004b4052  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 004b4054  e9f9feffff             -jmp 0x4b3f52
    goto L_0x004b3f52;
L_0x004b4059:
    // 004b4059  c6431c00               -mov byte ptr [ebx + 0x1c], 0
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 004b405d  c6431d01               -mov byte ptr [ebx + 0x1d], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(29) /* 0x1d */) = 1 /*0x1*/;
    // 004b4061  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004b4064  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4065  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4066  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4067  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4068  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4b406c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b406c);
    // 004b406c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b406d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b406e  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b4072  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b4076  8b5908                 -mov ebx, dword ptr [ecx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004b4079  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b407b  81fb00000100           +cmp ebx, 0x10000
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
    // 004b4081  732c                   -jae 0x4b40af
    if (!cpu.flags.cf)
    {
        goto L_0x004b40af;
    }
    // 004b4083  81fa00000100           +cmp edx, 0x10000
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
    // 004b4089  7324                   -jae 0x4b40af
    if (!cpu.flags.cf)
    {
        goto L_0x004b40af;
    }
L_0x004b408b:
    // 004b408b  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004b408e  81fa00000100           +cmp edx, 0x10000
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
    // 004b4094  724b                   -jb 0x4b40e1
    if (cpu.flags.cf)
    {
        goto L_0x004b40e1;
    }
    // 004b4096  7660                   -jbe 0x4b40f8
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b40f8;
    }
    // 004b4098  8b5024                 -mov edx, dword ptr [eax + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 004b409b  c702a03d4b00           -mov dword ptr [edx], 0x4b3da0
    app->getMemory<x86::reg32>(cpu.edx) = 4930976 /*0x4b3da0*/;
    // 004b40a1  8b4028                 -mov eax, dword ptr [eax + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 004b40a4  c7001c3e4b00           -mov dword ptr [eax], 0x4b3e1c
    app->getMemory<x86::reg32>(cpu.eax) = 4931100 /*0x4b3e1c*/;
    // 004b40aa  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b40ac  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b40ad  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b40ae  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b40af:
    // 004b40af  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004b40b2  39f2                   +cmp edx, esi
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
    // 004b40b4  74d5                   -je 0x4b408b
    if (cpu.flags.zf)
    {
        goto L_0x004b408b;
    }
    // 004b40b6  81fe00000100           +cmp esi, 0x10000
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
    // 004b40bc  7608                   -jbe 0x4b40c6
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b40c6;
    }
    // 004b40be  81fa00000100           +cmp edx, 0x10000
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
    // 004b40c4  77c5                   -ja 0x4b408b
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004b408b;
    }
L_0x004b40c6:
    // 004b40c6  c6401c00               -mov byte ptr [eax + 0x1c], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 004b40ca  c6401d00               -mov byte ptr [eax + 0x1d], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(29) /* 0x1d */) = 0 /*0x0*/;
    // 004b40ce  c6401e00               -mov byte ptr [eax + 0x1e], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(30) /* 0x1e */) = 0 /*0x0*/;
    // 004b40d2  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004b40d9  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004b40df  ebaa                   -jmp 0x4b408b
    goto L_0x004b408b;
L_0x004b40e1:
    // 004b40e1  8b5024                 -mov edx, dword ptr [eax + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 004b40e4  c702f03d4b00           -mov dword ptr [edx], 0x4b3df0
    app->getMemory<x86::reg32>(cpu.edx) = 4931056 /*0x4b3df0*/;
    // 004b40ea  8b4028                 -mov eax, dword ptr [eax + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 004b40ed  c700303f4b00           -mov dword ptr [eax], 0x4b3f30
    app->getMemory<x86::reg32>(cpu.eax) = 4931376 /*0x4b3f30*/;
    // 004b40f3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b40f5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b40f6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b40f7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b40f8:
    // 004b40f8  8b5024                 -mov edx, dword ptr [eax + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 004b40fb  c702e83d4b00           -mov dword ptr [edx], 0x4b3de8
    app->getMemory<x86::reg32>(cpu.edx) = 4931048 /*0x4b3de8*/;
    // 004b4101  8b4028                 -mov eax, dword ptr [eax + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 004b4104  c700243f4b00           -mov dword ptr [eax], 0x4b3f24
    app->getMemory<x86::reg32>(cpu.eax) = 4931364 /*0x4b3f24*/;
    // 004b410a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b410c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b410d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b410e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4b4110(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b4110);
    // 004b4110  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b4114  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004b411a  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004b4121  c6401c00               -mov byte ptr [eax + 0x1c], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 004b4125  c6401d00               -mov byte ptr [eax + 0x1d], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(29) /* 0x1d */) = 0 /*0x0*/;
    // 004b4129  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b412d  c6401e00               -mov byte ptr [eax + 0x1e], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(30) /* 0x1e */) = 0 /*0x0*/;
    // 004b4131  895020                 -mov dword ptr [eax + 0x20], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 004b4134  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b4138  895024                 -mov dword ptr [eax + 0x24], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 004b413b  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b413f  895028                 -mov dword ptr [eax + 0x28], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 004b4142  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004b4145  c7006c404b00           -mov dword ptr [eax], 0x4b406c
    app->getMemory<x86::reg32>(cpu.eax) = 4931692 /*0x4b406c*/;
    // 004b414b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b414d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4b4150(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b4150);
    // 004b4150  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b4151  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b4154  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004b4158  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b415c  c1e303                 -shl ebx, 3
    cpu.ebx <<= 3 /*0x3*/ % 32;
    // 004b415f  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004b4163  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004b4165  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b4167  39d9                   +cmp ecx, ebx
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
    // 004b4169  7341                   -jae 0x4b41ac
    if (!cpu.flags.cf)
    {
        goto L_0x004b41ac;
    }
L_0x004b416b:
    // 004b416b  d94004                 -fld dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */)));
    // 004b416e  d800                   -fadd dword ptr [eax]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax));
    // 004b4170  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004b4172  dc0d44f74c00           -fmul qword ptr [0x4cf744]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5044036) /* 0x4cf744 */));
    // 004b4178  ddd1                   -fst st(1)
    cpu.fpu.st(1) = x86::Float(cpu.fpu.st(0));
    // 004b417a  dc054cf74c00           -fadd qword ptr [0x4cf74c]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(5044044) /* 0x4cf74c */));
    // 004b4180  ddd9                   -fstp st(1)
    cpu.fpu.st(1) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b4182  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b4184  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004b4186  81e1ffff0f00           -and ecx, 0xfffff
    cpu.ecx &= x86::reg32(x86::sreg32(1048575 /*0xfffff*/));
    // 004b418c  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b418f  83f97f                 +cmp ecx, 0x7f
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
    // 004b4192  7622                   -jbe 0x4b41b6
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b41b6;
    }
    // 004b4194  81f980ff0f00           +cmp ecx, 0xfff80
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
    // 004b419a  731a                   -jae 0x4b41b6
    if (!cpu.flags.cf)
    {
        goto L_0x004b41b6;
    }
    // 004b419c  81f900000800           +cmp ecx, 0x80000
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
    // 004b41a2  730d                   -jae 0x4b41b1
    if (!cpu.flags.cf)
    {
        goto L_0x004b41b1;
    }
    // 004b41a4  c602ff                 -mov byte ptr [edx], 0xff
    app->getMemory<x86::reg8>(cpu.edx) = 255 /*0xff*/;
L_0x004b41a7:
    // 004b41a7  42                     -inc edx
    (cpu.edx)++;
    // 004b41a8  39d8                   +cmp eax, ebx
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
    // 004b41aa  72bf                   -jb 0x4b416b
    if (cpu.flags.cf)
    {
        goto L_0x004b416b;
    }
L_0x004b41ac:
    // 004b41ac  83c408                 +add esp, 8
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
    // 004b41af  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b41b0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b41b1:
    // 004b41b1  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
    // 004b41b4  ebf1                   -jmp 0x4b41a7
    goto L_0x004b41a7;
L_0x004b41b6:
    // 004b41b6  80c180                 -add cl, 0x80
    (cpu.cl) += x86::reg8(x86::sreg8(128 /*0x80*/));
    // 004b41b9  880a                   -mov byte ptr [edx], cl
    app->getMemory<x86::reg8>(cpu.edx) = cpu.cl;
    // 004b41bb  42                     -inc edx
    (cpu.edx)++;
    // 004b41bc  39d8                   +cmp eax, ebx
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
    // 004b41be  72ab                   -jb 0x4b416b
    if (cpu.flags.cf)
    {
        goto L_0x004b416b;
    }
    // 004b41c0  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b41c3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b41c4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4b41d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b41d0);
    // 004b41d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b41d1  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b41d4  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004b41d8  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b41dc  c1e303                 -shl ebx, 3
    cpu.ebx <<= 3 /*0x3*/ % 32;
    // 004b41df  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004b41e3  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004b41e5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b41e7  39d9                   +cmp ecx, ebx
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
    // 004b41e9  7339                   -jae 0x4b4224
    if (!cpu.flags.cf)
    {
        goto L_0x004b4224;
    }
L_0x004b41eb:
    // 004b41eb  d900                   -fld dword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax)));
    // 004b41ed  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004b41ef  dc0554f74c00           -fadd qword ptr [0x4cf754]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(5044052) /* 0x4cf754 */));
    // 004b41f5  ddd9                   -fstp st(1)
    cpu.fpu.st(1) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b41f7  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b41f9  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004b41fb  81e1ffff0f00           -and ecx, 0xfffff
    cpu.ecx &= x86::reg32(x86::sreg32(1048575 /*0xfffff*/));
    // 004b4201  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b4204  81f9ff7f0000           +cmp ecx, 0x7fff
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
    // 004b420a  7622                   -jbe 0x4b422e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b422e;
    }
    // 004b420c  81f900800f00           +cmp ecx, 0xf8000
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
    // 004b4212  731a                   -jae 0x4b422e
    if (!cpu.flags.cf)
    {
        goto L_0x004b422e;
    }
    // 004b4214  81f900000800           +cmp ecx, 0x80000
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
    // 004b421a  730d                   -jae 0x4b4229
    if (!cpu.flags.cf)
    {
        goto L_0x004b4229;
    }
    // 004b421c  c602ff                 -mov byte ptr [edx], 0xff
    app->getMemory<x86::reg8>(cpu.edx) = 255 /*0xff*/;
L_0x004b421f:
    // 004b421f  42                     -inc edx
    (cpu.edx)++;
    // 004b4220  39d8                   +cmp eax, ebx
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
    // 004b4222  72c7                   -jb 0x4b41eb
    if (cpu.flags.cf)
    {
        goto L_0x004b41eb;
    }
L_0x004b4224:
    // 004b4224  83c408                 +add esp, 8
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
    // 004b4227  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4228  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b4229:
    // 004b4229  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
    // 004b422c  ebf1                   -jmp 0x4b421f
    goto L_0x004b421f;
L_0x004b422e:
    // 004b422e  c1e908                 -shr ecx, 8
    cpu.ecx >>= 8 /*0x8*/ % 32;
    // 004b4231  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b4237  81c180000000           -add ecx, 0x80
    (cpu.ecx) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 004b423d  880a                   -mov byte ptr [edx], cl
    app->getMemory<x86::reg8>(cpu.edx) = cpu.cl;
    // 004b423f  42                     -inc edx
    (cpu.edx)++;
    // 004b4240  39d8                   +cmp eax, ebx
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
    // 004b4242  72a7                   -jb 0x4b41eb
    if (cpu.flags.cf)
    {
        goto L_0x004b41eb;
    }
    // 004b4244  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b4247  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4248  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4b4250(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b4250);
    // 004b4250  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b4251  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b4254  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004b4258  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b425c  c1e303                 -shl ebx, 3
    cpu.ebx <<= 3 /*0x3*/ % 32;
    // 004b425f  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004b4263  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004b4265  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b4267  39d9                   +cmp ecx, ebx
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
    // 004b4269  7348                   -jae 0x4b42b3
    if (!cpu.flags.cf)
    {
        goto L_0x004b42b3;
    }
L_0x004b426b:
    // 004b426b  d94004                 -fld dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */)));
    // 004b426e  d800                   -fadd dword ptr [eax]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax));
    // 004b4270  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004b4272  dc0d5cf74c00           -fmul qword ptr [0x4cf75c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5044060) /* 0x4cf75c */));
    // 004b4278  ddd1                   -fst st(1)
    cpu.fpu.st(1) = x86::Float(cpu.fpu.st(0));
    // 004b427a  dc0564f74c00           -fadd qword ptr [0x4cf764]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(5044068) /* 0x4cf764 */));
    // 004b4280  ddd9                   -fstp st(1)
    cpu.fpu.st(1) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b4282  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b4284  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004b4286  81e1ffff0f00           -and ecx, 0xfffff
    cpu.ecx &= x86::reg32(x86::sreg32(1048575 /*0xfffff*/));
    // 004b428c  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b428f  81f9ff7f0000           +cmp ecx, 0x7fff
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
    // 004b4295  7628                   -jbe 0x4b42bf
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b42bf;
    }
    // 004b4297  81f900800f00           +cmp ecx, 0xf8000
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
    // 004b429d  7320                   -jae 0x4b42bf
    if (!cpu.flags.cf)
    {
        goto L_0x004b42bf;
    }
    // 004b429f  81f900000800           +cmp ecx, 0x80000
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
    // 004b42a5  7311                   -jae 0x4b42b8
    if (!cpu.flags.cf)
    {
        goto L_0x004b42b8;
    }
    // 004b42a7  66c702ff7f             -mov word ptr [edx], 0x7fff
    app->getMemory<x86::reg16>(cpu.edx) = 32767 /*0x7fff*/;
L_0x004b42ac:
    // 004b42ac  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004b42af  39d8                   +cmp eax, ebx
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
    // 004b42b1  72b8                   -jb 0x4b426b
    if (cpu.flags.cf)
    {
        goto L_0x004b426b;
    }
L_0x004b42b3:
    // 004b42b3  83c408                 +add esp, 8
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
    // 004b42b6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b42b7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b42b8:
    // 004b42b8  66c7020080             -mov word ptr [edx], 0x8000
    app->getMemory<x86::reg16>(cpu.edx) = 32768 /*0x8000*/;
    // 004b42bd  ebed                   -jmp 0x4b42ac
    goto L_0x004b42ac;
L_0x004b42bf:
    // 004b42bf  66890a                 -mov word ptr [edx], cx
    app->getMemory<x86::reg16>(cpu.edx) = cpu.cx;
    // 004b42c2  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004b42c5  39d8                   +cmp eax, ebx
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
    // 004b42c7  72a2                   -jb 0x4b426b
    if (cpu.flags.cf)
    {
        goto L_0x004b426b;
    }
    // 004b42c9  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b42cc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b42cd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4b42d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b42d0);
    // 004b42d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b42d1  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b42d4  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004b42d8  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b42dc  c1e303                 -shl ebx, 3
    cpu.ebx <<= 3 /*0x3*/ % 32;
    // 004b42df  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004b42e3  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004b42e5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b42e7  39d9                   +cmp ecx, ebx
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
    // 004b42e9  733d                   -jae 0x4b4328
    if (!cpu.flags.cf)
    {
        goto L_0x004b4328;
    }
L_0x004b42eb:
    // 004b42eb  d900                   -fld dword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax)));
    // 004b42ed  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004b42ef  dc056cf74c00           -fadd qword ptr [0x4cf76c]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(5044076) /* 0x4cf76c */));
    // 004b42f5  ddd9                   -fstp st(1)
    cpu.fpu.st(1) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b42f7  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b42f9  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004b42fb  81e1ffff0f00           -and ecx, 0xfffff
    cpu.ecx &= x86::reg32(x86::sreg32(1048575 /*0xfffff*/));
    // 004b4301  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b4304  81f9ff7f0000           +cmp ecx, 0x7fff
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
    // 004b430a  7628                   -jbe 0x4b4334
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b4334;
    }
    // 004b430c  81f900800f00           +cmp ecx, 0xf8000
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
    // 004b4312  7320                   -jae 0x4b4334
    if (!cpu.flags.cf)
    {
        goto L_0x004b4334;
    }
    // 004b4314  81f900000800           +cmp ecx, 0x80000
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
    // 004b431a  7311                   -jae 0x4b432d
    if (!cpu.flags.cf)
    {
        goto L_0x004b432d;
    }
    // 004b431c  66c702ff7f             -mov word ptr [edx], 0x7fff
    app->getMemory<x86::reg16>(cpu.edx) = 32767 /*0x7fff*/;
L_0x004b4321:
    // 004b4321  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004b4324  39d8                   +cmp eax, ebx
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
    // 004b4326  72c3                   -jb 0x4b42eb
    if (cpu.flags.cf)
    {
        goto L_0x004b42eb;
    }
L_0x004b4328:
    // 004b4328  83c408                 +add esp, 8
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
    // 004b432b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b432c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b432d:
    // 004b432d  66c7020080             -mov word ptr [edx], 0x8000
    app->getMemory<x86::reg16>(cpu.edx) = 32768 /*0x8000*/;
    // 004b4332  ebed                   -jmp 0x4b4321
    goto L_0x004b4321;
L_0x004b4334:
    // 004b4334  66890a                 -mov word ptr [edx], cx
    app->getMemory<x86::reg16>(cpu.edx) = cpu.cx;
    // 004b4337  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004b433a  39d8                   +cmp eax, ebx
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
    // 004b433c  72ad                   -jb 0x4b42eb
    if (cpu.flags.cf)
    {
        goto L_0x004b42eb;
    }
    // 004b433e  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b4341  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4342  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4b4344(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b4344);
    // 004b4344  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b4345  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b4347  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b4348  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b4349  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b434a  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b434d  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b4350  b800000000             -mov eax, 0
    cpu.eax = 0 /*0x0*/;
    // 004b4355  83f90f                 +cmp ecx, 0xf
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
    // 004b4358  7e3d                   -jle 0x4b4397
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b4397;
    }
    // 004b435a  83e90f                 -sub ecx, 0xf
    (cpu.ecx) -= x86::reg32(x86::sreg32(15 /*0xf*/));
L_0x004b435d:
    // 004b435d  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 004b435f  894704                 -mov dword ptr [edi + 4], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004b4362  894708                 -mov dword ptr [edi + 8], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b4365  89470c                 -mov dword ptr [edi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004b4368  894710                 -mov dword ptr [edi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004b436b  894714                 -mov dword ptr [edi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004b436e  894718                 -mov dword ptr [edi + 0x18], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004b4371  89471c                 -mov dword ptr [edi + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004b4374  894720                 -mov dword ptr [edi + 0x20], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 004b4377  894724                 -mov dword ptr [edi + 0x24], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 004b437a  894728                 -mov dword ptr [edi + 0x28], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 004b437d  89472c                 -mov dword ptr [edi + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 004b4380  894730                 -mov dword ptr [edi + 0x30], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 004b4383  894734                 -mov dword ptr [edi + 0x34], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 004b4386  894738                 -mov dword ptr [edi + 0x38], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 004b4389  89473c                 -mov dword ptr [edi + 0x3c], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(60) /* 0x3c */) = cpu.eax;
    // 004b438c  83c740                 -add edi, 0x40
    (cpu.edi) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004b438f  83e910                 +sub ecx, 0x10
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
    // 004b4392  7fc9                   -jg 0x4b435d
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b435d;
    }
    // 004b4394  83c10f                 -add ecx, 0xf
    (cpu.ecx) += x86::reg32(x86::sreg32(15 /*0xf*/));
L_0x004b4397:
    // 004b4397  83f900                 +cmp ecx, 0
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
    // 004b439a  7e0a                   -jle 0x4b43a6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b43a6;
    }
    // 004b439c  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 004b439e  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b43a1  83e901                 +sub ecx, 1
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
    // 004b43a4  7ff1                   -jg 0x4b4397
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b4397;
    }
L_0x004b43a6:
    // 004b43a6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b43a7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b43a8  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b43a9  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b43aa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4b43ac(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b43ac);
    // 004b43ac  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b43ad  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b43af  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b43b0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b43b1  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b43b4  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b43b7  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004b43ba  c70009444b00           -mov dword ptr [eax], 0x4b4409
    app->getMemory<x86::reg32>(cpu.eax) = 4932617 /*0x4b4409*/;
    // 004b43c0  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b43c3  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004b43c6  c700d0434b00           -mov dword ptr [eax], 0x4b43d0
    app->getMemory<x86::reg32>(cpu.eax) = 4932560 /*0x4b43d0*/;
    // 004b43cc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b43cd  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b43ce  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b43cf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b43d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b43d0);
    // 004b43d0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b43d1  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b43d3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b43d4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b43d5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b43d6  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b43d9  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b43dc  c1e018                 -shl eax, 0x18
    cpu.eax <<= 24 /*0x18*/ % 32;
    // 004b43df  8b5d0c                 -mov ebx, dword ptr [ebp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b43e2  668bc3                 -mov ax, bx
    cpu.ax = cpu.bx;
    // 004b43e5  66c1e008               -shl ax, 8
    cpu.ax <<= 8 /*0x8*/ % 32;
    // 004b43e9  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 004b43eb  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004b43ee  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b43f1  c1e018                 -shl eax, 0x18
    cpu.eax <<= 24 /*0x18*/ % 32;
    // 004b43f4  8b5d10                 -mov ebx, dword ptr [ebp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b43f7  668bc3                 -mov ax, bx
    cpu.ax = cpu.bx;
    // 004b43fa  66c1e008               -shl ax, 8
    cpu.ax <<= 8 /*0x8*/ % 32;
    // 004b43fe  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b4401  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004b4404  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4405  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4406  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4407  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4408  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b4409(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b4409);
    // 004b4409  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b440a  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b440c  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004b440d  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b4410  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b4413  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b4416  0f6f06                 -movq mm0, qword ptr [esi]
    cpu.mmx.mm0 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.esi));
    // 004b4419  0f6f4e08               -movq mm1, qword ptr [esi + 8]
    cpu.mmx.mm1 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.esi + x86::reg32(8) /* 0x8 */));
    // 004b441d  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004b4420  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b4422  83e003                 -and eax, 3
    cpu.eax &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004b4425  83f800                 +cmp eax, 0
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
    // 004b4428  7405                   -je 0x4b442f
    if (cpu.flags.zf)
    {
        goto L_0x004b442f;
    }
    // 004b442a  83e904                 +sub ecx, 4
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
    // 004b442d  7c3e                   -jl 0x4b446d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b446d;
    }
L_0x004b442f:
    // 004b442f  0f6fd0                 -movq mm2, mm0
    cpu.mmx.mm2 = cpu.mmx.mm0;
    // 004b4432  0f6fe1                 -movq mm4, mm1
    cpu.mmx.mm4 = cpu.mmx.mm1;
    // 004b4435  0f6e2f                 -movd mm5, dword ptr [edi]
    cpu.mmx.mm5 = { _mm_loadu_si32(&app->getMemory<x86::reg32>(cpu.edi)) };
    // 004b4438  0f60f5                 -punpcklbw mm6, mm5
    cpu.mmx.mm6 = { _mm_unpacklo_epi8(cpu.mmx.mm6, cpu.mmx.mm5) };
    // 004b443b  0fe5d6                 -pmulhw mm2, mm6
    cpu.mmx.mm2 = { _mm_mulhi_epi16(cpu.mmx.mm2, cpu.mmx.mm6) };
    // 004b443e  0fe5e6                 -pmulhw mm4, mm6
    cpu.mmx.mm4 = { _mm_mulhi_epi16(cpu.mmx.mm4, cpu.mmx.mm6) };
    // 004b4441  0f6fda                 -movq mm3, mm2
    cpu.mmx.mm3 = cpu.mmx.mm2;
    // 004b4444  0f69dc                 -punpckhwd mm3, mm4
    cpu.mmx.mm3 = { _mm_unpacklo_epi16(_mm_srli_epi64(cpu.mmx.mm3, 32), _mm_srli_epi64(cpu.mmx.mm4, 32)) };
    // 004b4447  0f61d4                 -punpcklwd mm2, mm4
    cpu.mmx.mm2 = { _mm_unpacklo_epi16(cpu.mmx.mm2, cpu.mmx.mm4) };
    // 004b444a  0fed5500               -paddsw mm2, qword ptr [ebp]
    cpu.mmx.mm2 = { _mm_adds_epi16(cpu.mmx.mm2, x86::from_reg64(app->getMemory<x86::reg64>(cpu.ebp))) };
    // 004b444e  0fed5d08               -paddsw mm3, qword ptr [ebp + 8]
    cpu.mmx.mm3 = { _mm_adds_epi16(cpu.mmx.mm3, x86::from_reg64(app->getMemory<x86::reg64>(cpu.ebp + x86::reg32(8) /* 0x8 */))) };
    // 004b4452  0f7f5500               -movq qword ptr [ebp], mm2
    app->getMemory<x86::reg64>(cpu.ebp) = cpu.mmx.mm2;
    // 004b4456  0f7f5d08               -movq qword ptr [ebp + 8], mm3
    app->getMemory<x86::reg64>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.mmx.mm3;
    // 004b445a  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b445d  83c510                 -add ebp, 0x10
    (cpu.ebp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b4460  83e904                 +sub ecx, 4
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
    // 004b4463  7fca                   -jg 0x4b442f
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b442f;
    }
    // 004b4465  83f900                 +cmp ecx, 0
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
    // 004b4468  7503                   -jne 0x4b446d
    if (!cpu.flags.zf)
    {
        goto L_0x004b446d;
    }
    // 004b446a  61                     -popal 
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
    // 004b446b  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b446c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b446d:
    // 004b446d  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b4470  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004b4472  b800000000             -mov eax, 0
    cpu.eax = 0 /*0x0*/;
L_0x004b4477:
    // 004b4477  0f6fd0                 -movq mm2, mm0
    cpu.mmx.mm2 = cpu.mmx.mm0;
    // 004b447a  0f6fe1                 -movq mm4, mm1
    cpu.mmx.mm4 = cpu.mmx.mm1;
    // 004b447d  8a27                   -mov ah, byte ptr [edi]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edi);
    // 004b447f  0f6ef0                 -movd mm6, eax
    cpu.mmx.mm6 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004b4482  0fe5d6                 -pmulhw mm2, mm6
    cpu.mmx.mm2 = { _mm_mulhi_epi16(cpu.mmx.mm2, cpu.mmx.mm6) };
    // 004b4485  0fe5e6                 -pmulhw mm4, mm6
    cpu.mmx.mm4 = { _mm_mulhi_epi16(cpu.mmx.mm4, cpu.mmx.mm6) };
    // 004b4488  0f6fda                 -movq mm3, mm2
    cpu.mmx.mm3 = cpu.mmx.mm2;
    // 004b448b  0f69dc                 -punpckhwd mm3, mm4
    cpu.mmx.mm3 = { _mm_unpacklo_epi16(_mm_srli_epi64(cpu.mmx.mm3, 32), _mm_srli_epi64(cpu.mmx.mm4, 32)) };
    // 004b448e  0f61d4                 -punpcklwd mm2, mm4
    cpu.mmx.mm2 = { _mm_unpacklo_epi16(cpu.mmx.mm2, cpu.mmx.mm4) };
    // 004b4491  0f6e5d00               -movd mm3, dword ptr [ebp]
    cpu.mmx.mm3 = { _mm_loadu_si32(&app->getMemory<x86::reg32>(cpu.ebp)) };
    // 004b4495  0fedda                 -paddsw mm3, mm2
    cpu.mmx.mm3 = { _mm_adds_epi16(cpu.mmx.mm3, cpu.mmx.mm2) };
    // 004b4498  0f7e5d00               -movd dword ptr [ebp], mm3
    _mm_storeu_si32(&app->getMemory<x86::reg32>(cpu.ebp), cpu.mmx.mm3);
    // 004b449c  83c701                 -add edi, 1
    (cpu.edi) += x86::reg32(x86::sreg32(1 /*0x1*/));
    // 004b449f  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b44a2  83c101                 +add ecx, 1
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
    // 004b44a5  7cd0                   -jl 0x4b4477
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b4477;
    }
    // 004b44a7  61                     -popal 
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
    // 004b44a8  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b44a9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4b44ac(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b44ac);
    // 004b44ac  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b44ad  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b44af  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b44b0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b44b1  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b44b4  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b44b7  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b44ba  c700f3444b00           -mov dword ptr [eax], 0x4b44f3
    app->getMemory<x86::reg32>(cpu.eax) = 4932851 /*0x4b44f3*/;
    // 004b44c0  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b44c3  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004b44c6  c700d0444b00           -mov dword ptr [eax], 0x4b44d0
    app->getMemory<x86::reg32>(cpu.eax) = 4932816 /*0x4b44d0*/;
    // 004b44cc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b44cd  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b44ce  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b44cf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b44d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b44d0);
    // 004b44d0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b44d1  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b44d3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b44d4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b44d5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b44d6  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b44d9  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b44dc  c1e018                 -shl eax, 0x18
    cpu.eax <<= 24 /*0x18*/ % 32;
    // 004b44df  8b5d0c                 -mov ebx, dword ptr [ebp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b44e2  668bc3                 -mov ax, bx
    cpu.ax = cpu.bx;
    // 004b44e5  66c1e008               -shl ax, 8
    cpu.ax <<= 8 /*0x8*/ % 32;
    // 004b44e9  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 004b44eb  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004b44ee  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b44ef  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b44f0  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b44f1  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b44f2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b44f3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b44f3);
    // 004b44f3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b44f4  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b44f6  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004b44f7  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b44fa  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b44fd  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b4500  0f6f06                 -movq mm0, qword ptr [esi]
    cpu.mmx.mm0 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.esi));
    // 004b4503  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004b4506  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b4508  83e003                 -and eax, 3
    cpu.eax &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004b450b  83f800                 +cmp eax, 0
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
    // 004b450e  7405                   -je 0x4b4515
    if (cpu.flags.zf)
    {
        goto L_0x004b4515;
    }
    // 004b4510  83e904                 +sub ecx, 4
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
    // 004b4513  7c38                   -jl 0x4b454d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b454d;
    }
L_0x004b4515:
    // 004b4515  0f6f1f                 -movq mm3, qword ptr [edi]
    cpu.mmx.mm3 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edi));
    // 004b4518  0f6fc8                 -movq mm1, mm0
    cpu.mmx.mm1 = cpu.mmx.mm0;
    // 004b451b  0f6fd0                 -movq mm2, mm0
    cpu.mmx.mm2 = cpu.mmx.mm0;
    // 004b451e  0f60e3                 -punpcklbw mm4, mm3
    cpu.mmx.mm4 = { _mm_unpacklo_epi8(cpu.mmx.mm4, cpu.mmx.mm3) };
    // 004b4521  0f68eb                 -punpckhbw mm5, mm3
    cpu.mmx.mm5 = { _mm_unpacklo_epi8(_mm_srli_epi64(cpu.mmx.mm5, 32), _mm_srli_epi64(cpu.mmx.mm3, 32)) };
    // 004b4524  0fe5cc                 -pmulhw mm1, mm4
    cpu.mmx.mm1 = { _mm_mulhi_epi16(cpu.mmx.mm1, cpu.mmx.mm4) };
    // 004b4527  0fe5d5                 -pmulhw mm2, mm5
    cpu.mmx.mm2 = { _mm_mulhi_epi16(cpu.mmx.mm2, cpu.mmx.mm5) };
    // 004b452a  0fed4d00               -paddsw mm1, qword ptr [ebp]
    cpu.mmx.mm1 = { _mm_adds_epi16(cpu.mmx.mm1, x86::from_reg64(app->getMemory<x86::reg64>(cpu.ebp))) };
    // 004b452e  0fed5508               -paddsw mm2, qword ptr [ebp + 8]
    cpu.mmx.mm2 = { _mm_adds_epi16(cpu.mmx.mm2, x86::from_reg64(app->getMemory<x86::reg64>(cpu.ebp + x86::reg32(8) /* 0x8 */))) };
    // 004b4532  0f7f4d00               -movq qword ptr [ebp], mm1
    app->getMemory<x86::reg64>(cpu.ebp) = cpu.mmx.mm1;
    // 004b4536  0f7f5508               -movq qword ptr [ebp + 8], mm2
    app->getMemory<x86::reg64>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.mmx.mm2;
    // 004b453a  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b453d  83c510                 -add ebp, 0x10
    (cpu.ebp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b4540  83e904                 +sub ecx, 4
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
    // 004b4543  7fd0                   -jg 0x4b4515
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b4515;
    }
    // 004b4545  83f900                 +cmp ecx, 0
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
    // 004b4548  7503                   -jne 0x4b454d
    if (!cpu.flags.zf)
    {
        goto L_0x004b454d;
    }
    // 004b454a  61                     -popal 
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
    // 004b454b  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b454c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b454d:
    // 004b454d  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b4550  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
L_0x004b4552:
    // 004b4552  8a4701                 -mov al, byte ptr [edi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 004b4555  c1e018                 -shl eax, 0x18
    cpu.eax <<= 24 /*0x18*/ % 32;
    // 004b4558  8a27                   -mov ah, byte ptr [edi]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edi);
    // 004b455a  0f6ec8                 -movd mm1, eax
    cpu.mmx.mm1 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004b455d  0fe5c8                 -pmulhw mm1, mm0
    cpu.mmx.mm1 = { _mm_mulhi_epi16(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 004b4560  0f6e5500               -movd mm2, dword ptr [ebp]
    cpu.mmx.mm2 = { _mm_loadu_si32(&app->getMemory<x86::reg32>(cpu.ebp)) };
    // 004b4564  0fedca                 -paddsw mm1, mm2
    cpu.mmx.mm1 = { _mm_adds_epi16(cpu.mmx.mm1, cpu.mmx.mm2) };
    // 004b4567  0f7e4d00               -movd dword ptr [ebp], mm1
    _mm_storeu_si32(&app->getMemory<x86::reg32>(cpu.ebp), cpu.mmx.mm1);
    // 004b456b  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004b456e  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b4571  83c101                 +add ecx, 1
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
    // 004b4574  7cdc                   -jl 0x4b4552
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b4552;
    }
    // 004b4576  61                     -popal 
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
    // 004b4577  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4578  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_4b457c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b457c);
    // 004b457c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b457d  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b457f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b4580  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b4581  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b4584  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b4587  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004b458a  c700d9454b00           -mov dword ptr [eax], 0x4b45d9
    app->getMemory<x86::reg32>(cpu.eax) = 4933081 /*0x4b45d9*/;
    // 004b4590  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b4593  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004b4596  c700a0454b00           -mov dword ptr [eax], 0x4b45a0
    app->getMemory<x86::reg32>(cpu.eax) = 4933024 /*0x4b45a0*/;
    // 004b459c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b459d  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b459e  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b459f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b45a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b45a0);
    // 004b45a0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b45a1  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b45a3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b45a4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b45a5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b45a6  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b45a9  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b45ac  c1e018                 -shl eax, 0x18
    cpu.eax <<= 24 /*0x18*/ % 32;
    // 004b45af  8b5d0c                 -mov ebx, dword ptr [ebp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b45b2  668bc3                 -mov ax, bx
    cpu.ax = cpu.bx;
    // 004b45b5  66c1e008               -shl ax, 8
    cpu.ax <<= 8 /*0x8*/ % 32;
    // 004b45b9  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 004b45bb  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004b45be  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b45c1  c1e018                 -shl eax, 0x18
    cpu.eax <<= 24 /*0x18*/ % 32;
    // 004b45c4  8b5d10                 -mov ebx, dword ptr [ebp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b45c7  668bc3                 -mov ax, bx
    cpu.ax = cpu.bx;
    // 004b45ca  66c1e008               -shl ax, 8
    cpu.ax <<= 8 /*0x8*/ % 32;
    // 004b45ce  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b45d1  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004b45d4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b45d5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b45d6  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b45d7  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b45d8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b45d9(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b45d9);
    // 004b45d9  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b45da  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b45dc  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004b45dd  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b45e0  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b45e3  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b45e6  0f6f06                 -movq mm0, qword ptr [esi]
    cpu.mmx.mm0 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.esi));
    // 004b45e9  0f6f4e08               -movq mm1, qword ptr [esi + 8]
    cpu.mmx.mm1 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.esi + x86::reg32(8) /* 0x8 */));
    // 004b45ed  8b5d14                 -mov ebx, dword ptr [ebp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004b45f0  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b45f2  83e003                 -and eax, 3
    cpu.eax &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004b45f5  83f800                 +cmp eax, 0
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
    // 004b45f8  7405                   -je 0x4b45ff
    if (cpu.flags.zf)
    {
        goto L_0x004b45ff;
    }
    // 004b45fa  83e904                 +sub ecx, 4
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
    // 004b45fd  7c39                   -jl 0x4b4638
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b4638;
    }
L_0x004b45ff:
    // 004b45ff  0f6fd0                 -movq mm2, mm0
    cpu.mmx.mm2 = cpu.mmx.mm0;
    // 004b4602  0f6fe1                 -movq mm4, mm1
    cpu.mmx.mm4 = cpu.mmx.mm1;
    // 004b4605  0f6f37                 -movq mm6, qword ptr [edi]
    cpu.mmx.mm6 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edi));
    // 004b4608  0fe5d6                 -pmulhw mm2, mm6
    cpu.mmx.mm2 = { _mm_mulhi_epi16(cpu.mmx.mm2, cpu.mmx.mm6) };
    // 004b460b  0fe5e6                 -pmulhw mm4, mm6
    cpu.mmx.mm4 = { _mm_mulhi_epi16(cpu.mmx.mm4, cpu.mmx.mm6) };
    // 004b460e  0f6fda                 -movq mm3, mm2
    cpu.mmx.mm3 = cpu.mmx.mm2;
    // 004b4611  0f69dc                 -punpckhwd mm3, mm4
    cpu.mmx.mm3 = { _mm_unpacklo_epi16(_mm_srli_epi64(cpu.mmx.mm3, 32), _mm_srli_epi64(cpu.mmx.mm4, 32)) };
    // 004b4614  0f61d4                 -punpcklwd mm2, mm4
    cpu.mmx.mm2 = { _mm_unpacklo_epi16(cpu.mmx.mm2, cpu.mmx.mm4) };
    // 004b4617  0fed13                 -paddsw mm2, qword ptr [ebx]
    cpu.mmx.mm2 = { _mm_adds_epi16(cpu.mmx.mm2, x86::from_reg64(app->getMemory<x86::reg64>(cpu.ebx))) };
    // 004b461a  0fed5b08               -paddsw mm3, qword ptr [ebx + 8]
    cpu.mmx.mm3 = { _mm_adds_epi16(cpu.mmx.mm3, x86::from_reg64(app->getMemory<x86::reg64>(cpu.ebx + x86::reg32(8) /* 0x8 */))) };
    // 004b461e  0f7f13                 -movq qword ptr [ebx], mm2
    app->getMemory<x86::reg64>(cpu.ebx) = cpu.mmx.mm2;
    // 004b4621  0f7f5b08               -movq qword ptr [ebx + 8], mm3
    app->getMemory<x86::reg64>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.mmx.mm3;
    // 004b4625  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b4628  83c310                 -add ebx, 0x10
    (cpu.ebx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b462b  83e904                 +sub ecx, 4
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
    // 004b462e  7fcf                   -jg 0x4b45ff
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b45ff;
    }
    // 004b4630  83f900                 +cmp ecx, 0
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
    // 004b4633  7503                   -jne 0x4b4638
    if (!cpu.flags.zf)
    {
        goto L_0x004b4638;
    }
    // 004b4635  61                     -popal 
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
    // 004b4636  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4637  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b4638:
    // 004b4638  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b463b  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
L_0x004b463d:
    // 004b463d  0f6fd0                 -movq mm2, mm0
    cpu.mmx.mm2 = cpu.mmx.mm0;
    // 004b4640  0f6fe1                 -movq mm4, mm1
    cpu.mmx.mm4 = cpu.mmx.mm1;
    // 004b4643  668b07                 -mov ax, word ptr [edi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edi);
    // 004b4646  0f6ef0                 -movd mm6, eax
    cpu.mmx.mm6 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004b4649  0fe5d6                 -pmulhw mm2, mm6
    cpu.mmx.mm2 = { _mm_mulhi_epi16(cpu.mmx.mm2, cpu.mmx.mm6) };
    // 004b464c  0fe5e6                 -pmulhw mm4, mm6
    cpu.mmx.mm4 = { _mm_mulhi_epi16(cpu.mmx.mm4, cpu.mmx.mm6) };
    // 004b464f  0f6fda                 -movq mm3, mm2
    cpu.mmx.mm3 = cpu.mmx.mm2;
    // 004b4652  0f69dc                 -punpckhwd mm3, mm4
    cpu.mmx.mm3 = { _mm_unpacklo_epi16(_mm_srli_epi64(cpu.mmx.mm3, 32), _mm_srli_epi64(cpu.mmx.mm4, 32)) };
    // 004b4655  0f61d4                 -punpcklwd mm2, mm4
    cpu.mmx.mm2 = { _mm_unpacklo_epi16(cpu.mmx.mm2, cpu.mmx.mm4) };
    // 004b4658  0f6e1b                 -movd mm3, dword ptr [ebx]
    cpu.mmx.mm3 = { _mm_loadu_si32(&app->getMemory<x86::reg32>(cpu.ebx)) };
    // 004b465b  0fedda                 -paddsw mm3, mm2
    cpu.mmx.mm3 = { _mm_adds_epi16(cpu.mmx.mm3, cpu.mmx.mm2) };
    // 004b465e  0f7e1b                 -movd dword ptr [ebx], mm3
    _mm_storeu_si32(&app->getMemory<x86::reg32>(cpu.ebx), cpu.mmx.mm3);
    // 004b4661  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004b4664  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b4667  83c101                 +add ecx, 1
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
    // 004b466a  7cd1                   -jl 0x4b463d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b463d;
    }
    // 004b466c  61                     -popal 
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
    // 004b466d  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b466e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4b4670(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b4670);
    // 004b4670  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b4671  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b4673  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b4674  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b4675  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b4678  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b467b  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b467e  c700b7464b00           -mov dword ptr [eax], 0x4b46b7
    app->getMemory<x86::reg32>(cpu.eax) = 4933303 /*0x4b46b7*/;
    // 004b4684  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b4687  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004b468a  c70094464b00           -mov dword ptr [eax], 0x4b4694
    app->getMemory<x86::reg32>(cpu.eax) = 4933268 /*0x4b4694*/;
    // 004b4690  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4691  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4692  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4693  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b4694(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b4694);
    // 004b4694  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b4695  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b4697  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b4698  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b4699  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b469a  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b469d  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b46a0  c1e018                 -shl eax, 0x18
    cpu.eax <<= 24 /*0x18*/ % 32;
    // 004b46a3  8b5d0c                 -mov ebx, dword ptr [ebp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b46a6  668bc3                 -mov ax, bx
    cpu.ax = cpu.bx;
    // 004b46a9  66c1e008               -shl ax, 8
    cpu.ax <<= 8 /*0x8*/ % 32;
    // 004b46ad  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 004b46af  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004b46b2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b46b3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b46b4  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b46b5  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b46b6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b46b7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b46b7);
    // 004b46b7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b46b8  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b46ba  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004b46bb  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b46be  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b46c1  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b46c4  0f6f06                 -movq mm0, qword ptr [esi]
    cpu.mmx.mm0 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.esi));
    // 004b46c7  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004b46ca  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b46cc  83e007                 -and eax, 7
    cpu.eax &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004b46cf  83f800                 +cmp eax, 0
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
    // 004b46d2  7405                   -je 0x4b46d9
    if (cpu.flags.zf)
    {
        goto L_0x004b46d9;
    }
    // 004b46d4  83e908                 +sub ecx, 8
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
    // 004b46d7  7c4e                   -jl 0x4b4727
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b4727;
    }
L_0x004b46d9:
    // 004b46d9  0f6fc8                 -movq mm1, mm0
    cpu.mmx.mm1 = cpu.mmx.mm0;
    // 004b46dc  0f6fd0                 -movq mm2, mm0
    cpu.mmx.mm2 = cpu.mmx.mm0;
    // 004b46df  0f6fd8                 -movq mm3, mm0
    cpu.mmx.mm3 = cpu.mmx.mm0;
    // 004b46e2  0f6fe0                 -movq mm4, mm0
    cpu.mmx.mm4 = cpu.mmx.mm0;
    // 004b46e5  0fe50f                 -pmulhw mm1, qword ptr [edi]
    cpu.mmx.mm1 = { _mm_mulhi_epi16(cpu.mmx.mm1, x86::from_reg64(app->getMemory<x86::reg64>(cpu.edi))) };
    // 004b46e8  0fe55708               -pmulhw mm2, qword ptr [edi + 8]
    cpu.mmx.mm2 = { _mm_mulhi_epi16(cpu.mmx.mm2, x86::from_reg64(app->getMemory<x86::reg64>(cpu.edi + x86::reg32(8) /* 0x8 */))) };
    // 004b46ec  0fe55f10               -pmulhw mm3, qword ptr [edi + 0x10]
    cpu.mmx.mm3 = { _mm_mulhi_epi16(cpu.mmx.mm3, x86::from_reg64(app->getMemory<x86::reg64>(cpu.edi + x86::reg32(16) /* 0x10 */))) };
    // 004b46f0  0fe56718               -pmulhw mm4, qword ptr [edi + 0x18]
    cpu.mmx.mm4 = { _mm_mulhi_epi16(cpu.mmx.mm4, x86::from_reg64(app->getMemory<x86::reg64>(cpu.edi + x86::reg32(24) /* 0x18 */))) };
    // 004b46f4  0fed4d00               -paddsw mm1, qword ptr [ebp]
    cpu.mmx.mm1 = { _mm_adds_epi16(cpu.mmx.mm1, x86::from_reg64(app->getMemory<x86::reg64>(cpu.ebp))) };
    // 004b46f8  0fed5508               -paddsw mm2, qword ptr [ebp + 8]
    cpu.mmx.mm2 = { _mm_adds_epi16(cpu.mmx.mm2, x86::from_reg64(app->getMemory<x86::reg64>(cpu.ebp + x86::reg32(8) /* 0x8 */))) };
    // 004b46fc  0fed5d10               -paddsw mm3, qword ptr [ebp + 0x10]
    cpu.mmx.mm3 = { _mm_adds_epi16(cpu.mmx.mm3, x86::from_reg64(app->getMemory<x86::reg64>(cpu.ebp + x86::reg32(16) /* 0x10 */))) };
    // 004b4700  0fed6518               -paddsw mm4, qword ptr [ebp + 0x18]
    cpu.mmx.mm4 = { _mm_adds_epi16(cpu.mmx.mm4, x86::from_reg64(app->getMemory<x86::reg64>(cpu.ebp + x86::reg32(24) /* 0x18 */))) };
    // 004b4704  0f7f4d00               -movq qword ptr [ebp], mm1
    app->getMemory<x86::reg64>(cpu.ebp) = cpu.mmx.mm1;
    // 004b4708  0f7f5508               -movq qword ptr [ebp + 8], mm2
    app->getMemory<x86::reg64>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.mmx.mm2;
    // 004b470c  0f7f5d10               -movq qword ptr [ebp + 0x10], mm3
    app->getMemory<x86::reg64>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.mmx.mm3;
    // 004b4710  0f7f6518               -movq qword ptr [ebp + 0x18], mm4
    app->getMemory<x86::reg64>(cpu.ebp + x86::reg32(24) /* 0x18 */) = cpu.mmx.mm4;
    // 004b4714  83c720                 -add edi, 0x20
    (cpu.edi) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004b4717  83c520                 -add ebp, 0x20
    (cpu.ebp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004b471a  83e908                 +sub ecx, 8
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
    // 004b471d  7fba                   -jg 0x4b46d9
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b46d9;
    }
    // 004b471f  83f900                 +cmp ecx, 0
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
    // 004b4722  7503                   -jne 0x4b4727
    if (!cpu.flags.zf)
    {
        goto L_0x004b4727;
    }
    // 004b4724  61                     -popal 
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
    // 004b4725  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4726  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b4727:
    // 004b4727  83c108                 -add ecx, 8
    (cpu.ecx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b472a  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004b472c  0f6fc8                 -movq mm1, mm0
    cpu.mmx.mm1 = cpu.mmx.mm0;
L_0x004b472f:
    // 004b472f  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 004b4731  0f6ec8                 -movd mm1, eax
    cpu.mmx.mm1 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004b4734  0fe5c8                 -pmulhw mm1, mm0
    cpu.mmx.mm1 = { _mm_mulhi_epi16(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 004b4737  0f6e5500               -movd mm2, dword ptr [ebp]
    cpu.mmx.mm2 = { _mm_loadu_si32(&app->getMemory<x86::reg32>(cpu.ebp)) };
    // 004b473b  0fedca                 -paddsw mm1, mm2
    cpu.mmx.mm1 = { _mm_adds_epi16(cpu.mmx.mm1, cpu.mmx.mm2) };
    // 004b473e  0f7e4d00               -movd dword ptr [ebp], mm1
    _mm_storeu_si32(&app->getMemory<x86::reg32>(cpu.ebp), cpu.mmx.mm1);
    // 004b4742  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b4745  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b4748  83c101                 +add ecx, 1
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
    // 004b474b  7ce2                   -jl 0x4b472f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b472f;
    }
    // 004b474d  61                     -popal 
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
    // 004b474e  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b474f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b4750(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b4750);
    // 004b4750  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b4751  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b4753  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004b4754  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b4757  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b475a  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
L_0x004b475d:
    // 004b475d  668b448efc             -mov ax, word ptr [esi + ecx*4 - 4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(-4) /* -0x4 */ + cpu.ecx * 4);
    // 004b4762  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004b4765  668b448efe             -mov ax, word ptr [esi + ecx*4 - 2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(-2) /* -0x2 */ + cpu.ecx * 4);
    // 004b476a  0f6ec8                 -movd mm1, eax
    cpu.mmx.mm1 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004b476d  0fedc1                 -paddsw mm0, mm1
    cpu.mmx.mm0 = { _mm_adds_epi16(cpu.mmx.mm0, cpu.mmx.mm1) };
    // 004b4770  0f7ec0                 -movd eax, mm0
    cpu.eax = _mm_cvtsi128_si32(cpu.mmx.mm0);
    // 004b4773  3500800000             -xor eax, 0x8000
    cpu.eax ^= x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 004b4778  886439ff               -mov byte ptr [ecx + edi - 1], ah
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-1) /* -0x1 */ + cpu.edi * 1) = cpu.ah;
    // 004b477c  83e901                 +sub ecx, 1
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
    // 004b477f  7fdc                   -jg 0x4b475d
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b475d;
    }
    // 004b4781  61                     -popal 
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
    // 004b4782  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4783  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b4784(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b4784);
    // 004b4784  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b4785  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b4787  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004b4788  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b478b  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b478e  d1e1                   -shl ecx, 1
    cpu.ecx <<= 1 /*0x1*/ % 32;
    // 004b4790  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b4793  bb5ce34d00             -mov ebx, 0x4de35c
    cpu.ebx = 5104476 /*0x4de35c*/;
L_0x004b4798:
    // 004b4798  0f6f444ef8             -movq mm0, qword ptr [esi + ecx*2 - 8]
    cpu.mmx.mm0 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.esi + x86::reg32(-8) /* -0x8 */ + cpu.ecx * 2));
    // 004b479d  0f6f4c4ef0             -movq mm1, qword ptr [esi + ecx*2 - 0x10]
    cpu.mmx.mm1 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.esi + x86::reg32(-16) /* -0x10 */ + cpu.ecx * 2));
    // 004b47a2  0f6f544ee8             -movq mm2, qword ptr [esi + ecx*2 - 0x18]
    cpu.mmx.mm2 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.esi + x86::reg32(-24) /* -0x18 */ + cpu.ecx * 2));
    // 004b47a7  0f6f5c4ee0             -movq mm3, qword ptr [esi + ecx*2 - 0x20]
    cpu.mmx.mm3 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.esi + x86::reg32(-32) /* -0x20 */ + cpu.ecx * 2));
    // 004b47ac  0f6f644ed8             -movq mm4, qword ptr [esi + ecx*2 - 0x28]
    cpu.mmx.mm4 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.esi + x86::reg32(-40) /* -0x28 */ + cpu.ecx * 2));
    // 004b47b1  0f6f6c4ed0             -movq mm5, qword ptr [esi + ecx*2 - 0x30]
    cpu.mmx.mm5 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.esi + x86::reg32(-48) /* -0x30 */ + cpu.ecx * 2));
    // 004b47b6  0f6f744ec8             -movq mm6, qword ptr [esi + ecx*2 - 0x38]
    cpu.mmx.mm6 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.esi + x86::reg32(-56) /* -0x38 */ + cpu.ecx * 2));
    // 004b47bb  0f6f7c4ec0             -movq mm7, qword ptr [esi + ecx*2 - 0x40]
    cpu.mmx.mm7 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.esi + x86::reg32(-64) /* -0x40 */ + cpu.ecx * 2));
    // 004b47c0  0fedc0                 -paddsw mm0, mm0
    cpu.mmx.mm0 = { _mm_adds_epi16(cpu.mmx.mm0, cpu.mmx.mm0) };
    // 004b47c3  0fedc9                 -paddsw mm1, mm1
    cpu.mmx.mm1 = { _mm_adds_epi16(cpu.mmx.mm1, cpu.mmx.mm1) };
    // 004b47c6  0fedd2                 -paddsw mm2, mm2
    cpu.mmx.mm2 = { _mm_adds_epi16(cpu.mmx.mm2, cpu.mmx.mm2) };
    // 004b47c9  0feddb                 -paddsw mm3, mm3
    cpu.mmx.mm3 = { _mm_adds_epi16(cpu.mmx.mm3, cpu.mmx.mm3) };
    // 004b47cc  0fede4                 -paddsw mm4, mm4
    cpu.mmx.mm4 = { _mm_adds_epi16(cpu.mmx.mm4, cpu.mmx.mm4) };
    // 004b47cf  0feded                 -paddsw mm5, mm5
    cpu.mmx.mm5 = { _mm_adds_epi16(cpu.mmx.mm5, cpu.mmx.mm5) };
    // 004b47d2  0fedf6                 -paddsw mm6, mm6
    cpu.mmx.mm6 = { _mm_adds_epi16(cpu.mmx.mm6, cpu.mmx.mm6) };
    // 004b47d5  0fedff                 -paddsw mm7, mm7
    cpu.mmx.mm7 = { _mm_adds_epi16(cpu.mmx.mm7, cpu.mmx.mm7) };
    // 004b47d8  0f71d008               -psrlw mm0, 8
    cpu.mmx.mm0 = { _mm_srli_epi16(cpu.mmx.mm0, 8 /*0x8*/) };
    // 004b47dc  0f71d108               -psrlw mm1, 8
    cpu.mmx.mm1 = { _mm_srli_epi16(cpu.mmx.mm1, 8 /*0x8*/) };
    // 004b47e0  0f71d208               -psrlw mm2, 8
    cpu.mmx.mm2 = { _mm_srli_epi16(cpu.mmx.mm2, 8 /*0x8*/) };
    // 004b47e4  0f71d308               -psrlw mm3, 8
    cpu.mmx.mm3 = { _mm_srli_epi16(cpu.mmx.mm3, 8 /*0x8*/) };
    // 004b47e8  0f71d408               -psrlw mm4, 8
    cpu.mmx.mm4 = { _mm_srli_epi16(cpu.mmx.mm4, 8 /*0x8*/) };
    // 004b47ec  0f71d508               -psrlw mm5, 8
    cpu.mmx.mm5 = { _mm_srli_epi16(cpu.mmx.mm5, 8 /*0x8*/) };
    // 004b47f0  0f71d608               -psrlw mm6, 8
    cpu.mmx.mm6 = { _mm_srli_epi16(cpu.mmx.mm6, 8 /*0x8*/) };
    // 004b47f4  0f71d708               -psrlw mm7, 8
    cpu.mmx.mm7 = { _mm_srli_epi16(cpu.mmx.mm7, 8 /*0x8*/) };
    // 004b47f8  0f67c8                 -packuswb mm1, mm0
    { __m128i _packed = _mm_packus_epi16(cpu.mmx.mm1, cpu.mmx.mm0); cpu.mmx.mm1 = {_mm_unpacklo_epi32(_packed, _mm_srli_si128(_packed, 8))}; }
    // 004b47fb  0f67da                 -packuswb mm3, mm2
    { __m128i _packed = _mm_packus_epi16(cpu.mmx.mm3, cpu.mmx.mm2); cpu.mmx.mm3 = {_mm_unpacklo_epi32(_packed, _mm_srli_si128(_packed, 8))}; }
    // 004b47fe  0f67ec                 -packuswb mm5, mm4
    { __m128i _packed = _mm_packus_epi16(cpu.mmx.mm5, cpu.mmx.mm4); cpu.mmx.mm5 = {_mm_unpacklo_epi32(_packed, _mm_srli_si128(_packed, 8))}; }
    // 004b4801  0f67fe                 -packuswb mm7, mm6
    { __m128i _packed = _mm_packus_epi16(cpu.mmx.mm7, cpu.mmx.mm6); cpu.mmx.mm7 = {_mm_unpacklo_epi32(_packed, _mm_srli_si128(_packed, 8))}; }
    // 004b4804  0f6f03                 -movq mm0, qword ptr [ebx]
    cpu.mmx.mm0 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.ebx));
    // 004b4807  0fefc8                 -pxor mm1, mm0
    cpu.mmx.mm1 = { _mm_xor_si128(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 004b480a  0fefd8                 -pxor mm3, mm0
    cpu.mmx.mm3 = { _mm_xor_si128(cpu.mmx.mm3, cpu.mmx.mm0) };
    // 004b480d  0fefe8                 -pxor mm5, mm0
    cpu.mmx.mm5 = { _mm_xor_si128(cpu.mmx.mm5, cpu.mmx.mm0) };
    // 004b4810  0feff8                 -pxor mm7, mm0
    cpu.mmx.mm7 = { _mm_xor_si128(cpu.mmx.mm7, cpu.mmx.mm0) };
    // 004b4813  0f7f4c39f8             -movq qword ptr [ecx + edi - 8], mm1
    app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-8) /* -0x8 */ + cpu.edi * 1) = cpu.mmx.mm1;
    // 004b4818  0f7f5c39f0             -movq qword ptr [ecx + edi - 0x10], mm3
    app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-16) /* -0x10 */ + cpu.edi * 1) = cpu.mmx.mm3;
    // 004b481d  0f7f6c39e8             -movq qword ptr [ecx + edi - 0x18], mm5
    app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-24) /* -0x18 */ + cpu.edi * 1) = cpu.mmx.mm5;
    // 004b4822  0f7f7c39e0             -movq qword ptr [ecx + edi - 0x20], mm7
    app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-32) /* -0x20 */ + cpu.edi * 1) = cpu.mmx.mm7;
    // 004b4827  83e920                 +sub ecx, 0x20
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
    // 004b482a  0f8f68ffffff           -jg 0x4b4798
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b4798;
    }
    // 004b4830  61                     -popal 
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
    // 004b4831  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4832  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4b4834(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b4834);
    // 004b4834  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b4835  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b4837  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004b4838  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b483b  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b483e  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
L_0x004b4841:
    // 004b4841  668b448efc             -mov ax, word ptr [esi + ecx*4 - 4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(-4) /* -0x4 */ + cpu.ecx * 4);
    // 004b4846  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004b4849  668b448efe             -mov ax, word ptr [esi + ecx*4 - 2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(-2) /* -0x2 */ + cpu.ecx * 4);
    // 004b484e  0f6ec8                 -movd mm1, eax
    cpu.mmx.mm1 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004b4851  0fedc1                 -paddsw mm0, mm1
    cpu.mmx.mm0 = { _mm_adds_epi16(cpu.mmx.mm0, cpu.mmx.mm1) };
    // 004b4854  0f7ec0                 -movd eax, mm0
    cpu.eax = _mm_cvtsi128_si32(cpu.mmx.mm0);
    // 004b4857  6689444ffe             -mov word ptr [edi + ecx*2 - 2], ax
    app->getMemory<x86::reg16>(cpu.edi + x86::reg32(-2) /* -0x2 */ + cpu.ecx * 2) = cpu.ax;
    // 004b485c  83e901                 +sub ecx, 1
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
    // 004b485f  7fe0                   -jg 0x4b4841
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b4841;
    }
    // 004b4861  61                     -popal 
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
    // 004b4862  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4863  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b4864(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b4864);
    // 004b4864  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b4865  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b4867  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004b4868  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b486b  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b486e  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 004b4871  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
L_0x004b4874:
    // 004b4874  0f6f4431f8             -movq mm0, qword ptr [ecx + esi - 8]
    cpu.mmx.mm0 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-8) /* -0x8 */ + cpu.esi * 1));
    // 004b4879  0f6f4c31f0             -movq mm1, qword ptr [ecx + esi - 0x10]
    cpu.mmx.mm1 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-16) /* -0x10 */ + cpu.esi * 1));
    // 004b487e  0f6f5431e8             -movq mm2, qword ptr [ecx + esi - 0x18]
    cpu.mmx.mm2 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-24) /* -0x18 */ + cpu.esi * 1));
    // 004b4883  0f6f5c31e0             -movq mm3, qword ptr [ecx + esi - 0x20]
    cpu.mmx.mm3 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-32) /* -0x20 */ + cpu.esi * 1));
    // 004b4888  0f6f6431d8             -movq mm4, qword ptr [ecx + esi - 0x28]
    cpu.mmx.mm4 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-40) /* -0x28 */ + cpu.esi * 1));
    // 004b488d  0f6f6c31d0             -movq mm5, qword ptr [ecx + esi - 0x30]
    cpu.mmx.mm5 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-48) /* -0x30 */ + cpu.esi * 1));
    // 004b4892  0f6f7431c8             -movq mm6, qword ptr [ecx + esi - 0x38]
    cpu.mmx.mm6 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-56) /* -0x38 */ + cpu.esi * 1));
    // 004b4897  0f6f7c31c0             -movq mm7, qword ptr [ecx + esi - 0x40]
    cpu.mmx.mm7 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-64) /* -0x40 */ + cpu.esi * 1));
    // 004b489c  0fedc0                 -paddsw mm0, mm0
    cpu.mmx.mm0 = { _mm_adds_epi16(cpu.mmx.mm0, cpu.mmx.mm0) };
    // 004b489f  0fedc9                 -paddsw mm1, mm1
    cpu.mmx.mm1 = { _mm_adds_epi16(cpu.mmx.mm1, cpu.mmx.mm1) };
    // 004b48a2  0fedd2                 -paddsw mm2, mm2
    cpu.mmx.mm2 = { _mm_adds_epi16(cpu.mmx.mm2, cpu.mmx.mm2) };
    // 004b48a5  0feddb                 -paddsw mm3, mm3
    cpu.mmx.mm3 = { _mm_adds_epi16(cpu.mmx.mm3, cpu.mmx.mm3) };
    // 004b48a8  0fede4                 -paddsw mm4, mm4
    cpu.mmx.mm4 = { _mm_adds_epi16(cpu.mmx.mm4, cpu.mmx.mm4) };
    // 004b48ab  0feded                 -paddsw mm5, mm5
    cpu.mmx.mm5 = { _mm_adds_epi16(cpu.mmx.mm5, cpu.mmx.mm5) };
    // 004b48ae  0fedf6                 -paddsw mm6, mm6
    cpu.mmx.mm6 = { _mm_adds_epi16(cpu.mmx.mm6, cpu.mmx.mm6) };
    // 004b48b1  0fedff                 -paddsw mm7, mm7
    cpu.mmx.mm7 = { _mm_adds_epi16(cpu.mmx.mm7, cpu.mmx.mm7) };
    // 004b48b4  0f7f4439f8             -movq qword ptr [ecx + edi - 8], mm0
    app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-8) /* -0x8 */ + cpu.edi * 1) = cpu.mmx.mm0;
    // 004b48b9  0f7f4c39f0             -movq qword ptr [ecx + edi - 0x10], mm1
    app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-16) /* -0x10 */ + cpu.edi * 1) = cpu.mmx.mm1;
    // 004b48be  0f7f5439e8             -movq qword ptr [ecx + edi - 0x18], mm2
    app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-24) /* -0x18 */ + cpu.edi * 1) = cpu.mmx.mm2;
    // 004b48c3  0f7f5c39e0             -movq qword ptr [ecx + edi - 0x20], mm3
    app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-32) /* -0x20 */ + cpu.edi * 1) = cpu.mmx.mm3;
    // 004b48c8  0f7f6439d8             -movq qword ptr [ecx + edi - 0x28], mm4
    app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-40) /* -0x28 */ + cpu.edi * 1) = cpu.mmx.mm4;
    // 004b48cd  0f7f6c39d0             -movq qword ptr [ecx + edi - 0x30], mm5
    app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-48) /* -0x30 */ + cpu.edi * 1) = cpu.mmx.mm5;
    // 004b48d2  0f7f7439c8             -movq qword ptr [ecx + edi - 0x38], mm6
    app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-56) /* -0x38 */ + cpu.edi * 1) = cpu.mmx.mm6;
    // 004b48d7  0f7f7c39c0             -movq qword ptr [ecx + edi - 0x40], mm7
    app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-64) /* -0x40 */ + cpu.edi * 1) = cpu.mmx.mm7;
    // 004b48dc  83e940                 +sub ecx, 0x40
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
    // 004b48df  7f93                   -jg 0x4b4874
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b4874;
    }
    // 004b48e1  61                     -popal 
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
    // 004b48e2  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b48e3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b48e4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b48e4);
    // 004b48e4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b48e5  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b48e7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b48e8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b48e9  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b48ec  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b48ef  0fefc0                 -pxor mm0, mm0
    cpu.mmx.mm0 = { _mm_xor_si128(cpu.mmx.mm0, cpu.mmx.mm0) };
    // 004b48f2  83f90f                 +cmp ecx, 0xf
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
    // 004b48f5  7e2d                   -jle 0x4b4924
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b4924;
    }
    // 004b48f7  83e90f                 -sub ecx, 0xf
    (cpu.ecx) -= x86::reg32(x86::sreg32(15 /*0xf*/));
L_0x004b48fa:
    // 004b48fa  0f7f07                 -movq qword ptr [edi], mm0
    app->getMemory<x86::reg64>(cpu.edi) = cpu.mmx.mm0;
    // 004b48fd  0f7f4708               -movq qword ptr [edi + 8], mm0
    app->getMemory<x86::reg64>(cpu.edi + x86::reg32(8) /* 0x8 */) = cpu.mmx.mm0;
    // 004b4901  0f7f4710               -movq qword ptr [edi + 0x10], mm0
    app->getMemory<x86::reg64>(cpu.edi + x86::reg32(16) /* 0x10 */) = cpu.mmx.mm0;
    // 004b4905  0f7f4718               -movq qword ptr [edi + 0x18], mm0
    app->getMemory<x86::reg64>(cpu.edi + x86::reg32(24) /* 0x18 */) = cpu.mmx.mm0;
    // 004b4909  0f7f4720               -movq qword ptr [edi + 0x20], mm0
    app->getMemory<x86::reg64>(cpu.edi + x86::reg32(32) /* 0x20 */) = cpu.mmx.mm0;
    // 004b490d  0f7f4728               -movq qword ptr [edi + 0x28], mm0
    app->getMemory<x86::reg64>(cpu.edi + x86::reg32(40) /* 0x28 */) = cpu.mmx.mm0;
    // 004b4911  0f7f4730               -movq qword ptr [edi + 0x30], mm0
    app->getMemory<x86::reg64>(cpu.edi + x86::reg32(48) /* 0x30 */) = cpu.mmx.mm0;
    // 004b4915  0f7f4738               -movq qword ptr [edi + 0x38], mm0
    app->getMemory<x86::reg64>(cpu.edi + x86::reg32(56) /* 0x38 */) = cpu.mmx.mm0;
    // 004b4919  83c740                 -add edi, 0x40
    (cpu.edi) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004b491c  83e910                 +sub ecx, 0x10
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
    // 004b491f  7fd9                   -jg 0x4b48fa
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b48fa;
    }
    // 004b4921  83c10f                 -add ecx, 0xf
    (cpu.ecx) += x86::reg32(x86::sreg32(15 /*0xf*/));
L_0x004b4924:
    // 004b4924  83f900                 +cmp ecx, 0
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
    // 004b4927  7e0b                   -jle 0x4b4934
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b4934;
    }
    // 004b4929  0f7e07                 -movd dword ptr [edi], mm0
    _mm_storeu_si32(&app->getMemory<x86::reg32>(cpu.edi), cpu.mmx.mm0);
    // 004b492c  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b492f  83e901                 +sub ecx, 1
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
    // 004b4932  7ff0                   -jg 0x4b4924
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b4924;
    }
L_0x004b4934:
    // 004b4934  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4935  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4936  0f77                   -emms 
    cpu.mmx.init();
    // 004b4938  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4939  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4b4940(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b4940);
    // 004b4940  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b4941  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b4942  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b4943  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b4947  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004b494b  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004b494e  48                     -dec eax
    (cpu.eax)--;
    // 004b494f  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004b4952  034204                 -add eax, dword ptr [edx + 4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 004b4955  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b4958  8b5a0d                 -mov ebx, dword ptr [edx + 0xd]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(13) /* 0xd */);
    // 004b495b  40                     -inc eax
    (cpu.eax)++;
    // 004b495c  c1fb18                 -sar ebx, 0x18
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (24 /*0x18*/ % 32));
    // 004b495f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b4961  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b4963  8a5a0f                 -mov bl, byte ptr [edx + 0xf]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(15) /* 0xf */);
    // 004b4966  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b4968  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 004b496a  7501                   -jne 0x4b496d
    if (!cpu.flags.zf)
    {
        goto L_0x004b496d;
    }
    // 004b496c  40                     -inc eax
    (cpu.eax)++;
L_0x004b496d:
    // 004b496d  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004b4971  8b5108                 -mov edx, dword ptr [ecx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004b4974  0fafd7                 -imul edx, edi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 004b4977  035104                 -add edx, dword ptr [ecx + 4]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
    // 004b497a  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004b497d  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004b497f  885110                 -mov byte ptr [ecx + 0x10], dl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.dl;
    // 004b4982  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4983  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4984  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4985  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4b4988(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b4988);
    // 004b4988  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b498c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4b4990(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b4990);
    // 004b4990  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b4991  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b4995  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b4999  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004b499c  48                     -dec eax
    (cpu.eax)--;
    // 004b499d  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004b49a0  034204                 -add eax, dword ptr [edx + 4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 004b49a3  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b49a5  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b49a8  8a5a0f                 -mov bl, byte ptr [edx + 0xf]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(15) /* 0xf */);
    // 004b49ab  40                     -inc eax
    (cpu.eax)++;
    // 004b49ac  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 004b49ae  7501                   -jne 0x4b49b1
    if (!cpu.flags.zf)
    {
        goto L_0x004b49b1;
    }
    // 004b49b0  40                     -inc eax
    (cpu.eax)++;
L_0x004b49b1:
    // 004b49b1  8b510b                 -mov edx, dword ptr [ecx + 0xb]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(11) /* 0xb */);
    // 004b49b4  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004b49b7  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b49b9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b49ba  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4b49bc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b49bc);
    // 004b49bc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b49bd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b49be  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b49bf  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b49c0  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b49c3  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004b49c7  8b7c241c               -mov edi, dword ptr [esp + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004b49cb  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004b49cf  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b49d1  8a480f                 -mov cl, byte ptr [eax + 0xf]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(15) /* 0xf */);
    // 004b49d4  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004b49d6  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 004b49d8  7572                   -jne 0x4b4a4c
    if (!cpu.flags.zf)
    {
        goto L_0x004b4a4c;
    }
L_0x004b49da:
    // 004b49da  8b6c2424               -mov ebp, dword ptr [esp + 0x24]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004b49de  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp);
    // 004b49e1  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004b49e2  7572                   -jne 0x4b4a56
    if (!cpu.flags.zf)
    {
        goto L_0x004b4a56;
    }
L_0x004b49e4:
    // 004b49e4  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b49e6  baffff0000             -mov edx, 0xffff
    cpu.edx = 65535 /*0xffff*/;
    // 004b49eb  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b49ee  0fbe0406               -movsx eax, byte ptr [esi + eax]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1)));
    // 004b49f2  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b49f4  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004b49f7  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004b49fa  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b49fc  0fbe543201             -movsx edx, byte ptr [edx + esi + 1]
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */ + cpu.esi * 1)));
    // 004b4a01  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004b4a04  0fafd1                 -imul edx, ecx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004b4a07  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b4a0a  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004b4a0d  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b4a0f  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 004b4a12  88042f                 -mov byte ptr [edi + ebp], al
    app->getMemory<x86::reg8>(cpu.edi + cpu.ebp * 1) = cpu.al;
    // 004b4a15  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b4a17  8a440601               -mov al, byte ptr [esi + eax + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.eax * 1);
    // 004b4a1b  88430d                 -mov byte ptr [ebx + 0xd], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(13) /* 0xd */) = cpu.al;
    // 004b4a1e  8b7304                 -mov esi, dword ptr [ebx + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b4a21  037308                 -add esi, dword ptr [ebx + 8]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */)));
    // 004b4a24  8b3b                   -mov edi, dword ptr [ebx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b4a26  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b4a28  897304                 -mov dword ptr [ebx + 4], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 004b4a2b  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b4a2e  66c743060000           -mov word ptr [ebx + 6], 0
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 004b4a34  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b4a36  8b430d                 -mov eax, dword ptr [ebx + 0xd]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(13) /* 0xd */);
    // 004b4a39  893b                   -mov dword ptr [ebx], edi
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edi;
    // 004b4a3b  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004b4a3e  c6430f01               -mov byte ptr [ebx + 0xf], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(15) /* 0xf */) = 1 /*0x1*/;
    // 004b4a42  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004b4a44  83c404                 +add esp, 4
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
    // 004b4a47  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4a48  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4a49  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4a4a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4a4b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b4a4c:
    // 004b4a4c  8d72ff                 -lea esi, [edx - 1]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 004b4a4f  8a400d                 -mov al, byte ptr [eax + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */);
    // 004b4a52  8806                   -mov byte ptr [esi], al
    app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
    // 004b4a54  eb84                   -jmp 0x4b49da
    goto L_0x004b49da;
L_0x004b4a56:
    // 004b4a56  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b4a59  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b4a5c  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b4a5f  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004b4a62  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004b4a65  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b4a66  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004b4a69  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b4a6a  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b4a6e  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b4a72  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b4a73  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b4a74  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b4a75  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b4a76  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b4a77  e818550000             -call 0x4b9f94
    cpu.esp -= 4;
    sub_4b9f94(app, cpu);
    if (cpu.terminate) return;
    // 004b4a7c  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004b4a7f  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004b4a82  c1e810                 +shr eax, 0x10
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
    // 004b4a85  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004b4a88  e957ffffff             -jmp 0x4b49e4
    goto L_0x004b49e4;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4b4a90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b4a90);
    // 004b4a90  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b4a94  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b4a98  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004b4a9a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4b4a9c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b4a9c);
    // 004b4a9c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b4a9d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b4a9e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b4a9f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b4aa0  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b4aa3  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004b4aa7  8b7c241c               -mov edi, dword ptr [esp + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004b4aab  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004b4aaf  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b4ab1  8a480f                 -mov cl, byte ptr [eax + 0xf]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(15) /* 0xf */);
    // 004b4ab4  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004b4ab6  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 004b4ab8  0f85c7000000           -jne 0x4b4b85
    if (!cpu.flags.zf)
    {
        goto L_0x004b4b85;
    }
L_0x004b4abe:
    // 004b4abe  807b0e00               +cmp byte ptr [ebx + 0xe], 0
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
    // 004b4ac2  7406                   -je 0x4b4aca
    if (cpu.flags.zf)
    {
        goto L_0x004b4aca;
    }
    // 004b4ac4  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004b4ac5  8a430c                 -mov al, byte ptr [ebx + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004b4ac8  8806                   -mov byte ptr [esi], al
    app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
L_0x004b4aca:
    // 004b4aca  8b6c2424               -mov ebp, dword ptr [esp + 0x24]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004b4ace  c70300000000           -mov dword ptr [ebx], 0
    app->getMemory<x86::reg32>(cpu.ebx) = 0 /*0x0*/;
    // 004b4ad4  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp);
    // 004b4ad7  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004b4ad8  7432                   -je 0x4b4b0c
    if (cpu.flags.zf)
    {
        goto L_0x004b4b0c;
    }
    // 004b4ada  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b4add  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b4ae0  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b4ae3  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004b4ae6  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004b4ae9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b4aea  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004b4aed  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b4aee  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b4af2  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b4af6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b4af7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b4af8  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b4af9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b4afa  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b4afb  e894540000             -call 0x4b9f94
    cpu.esp -= 4;
    sub_4b9f94(app, cpu);
    if (cpu.terminate) return;
    // 004b4b00  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004b4b03  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004b4b06  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b4b09  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x004b4b0c:
    // 004b4b0c  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b4b0e  0fbe0406               -movsx eax, byte ptr [esi + eax]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1)));
    // 004b4b12  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b4b15  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b4b17  b8ffff0000             -mov eax, 0xffff
    cpu.eax = 65535 /*0xffff*/;
    // 004b4b1c  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004b4b1f  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b4b21  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004b4b24  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b4b26  0fbe543201             -movsx edx, byte ptr [edx + esi + 1]
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */ + cpu.esi * 1)));
    // 004b4b2b  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004b4b2e  0fafd1                 -imul edx, ecx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004b4b31  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b4b34  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004b4b37  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b4b39  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 004b4b3c  88042f                 -mov byte ptr [edi + ebp], al
    app->getMemory<x86::reg8>(cpu.edi + cpu.ebp * 1) = cpu.al;
    // 004b4b3f  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b4b41  8a440601               -mov al, byte ptr [esi + eax + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.eax * 1);
    // 004b4b45  88430d                 -mov byte ptr [ebx + 0xd], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(13) /* 0xd */) = cpu.al;
    // 004b4b48  8b7b04                 -mov edi, dword ptr [ebx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b4b4b  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b4b4e  8b2b                   -mov ebp, dword ptr [ebx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b4b50  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b4b52  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b4b55  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004b4b57  897b04                 -mov dword ptr [ebx + 4], edi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 004b4b5a  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b4b5d  66c743060000           -mov word ptr [ebx + 6], 0
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 004b4b63  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b4b65  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b4b68  892b                   -mov dword ptr [ebx], ebp
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.ebp;
    // 004b4b6a  39d0                   +cmp eax, edx
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
    // 004b4b6c  7224                   -jb 0x4b4b92
    if (cpu.flags.cf)
    {
        goto L_0x004b4b92;
    }
    // 004b4b6e  0333                   -add esi, dword ptr [ebx]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx)));
    // 004b4b70  c6430e01               -mov byte ptr [ebx + 0xe], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(14) /* 0xe */) = 1 /*0x1*/;
    // 004b4b74  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004b4b76  88430c                 -mov byte ptr [ebx + 0xc], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.al;
    // 004b4b79  c6430f01               -mov byte ptr [ebx + 0xf], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(15) /* 0xf */) = 1 /*0x1*/;
    // 004b4b7d  83c404                 +add esp, 4
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
    // 004b4b80  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4b81  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4b82  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4b83  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4b84  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b4b85:
    // 004b4b85  8d72ff                 -lea esi, [edx - 1]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 004b4b88  8a400d                 -mov al, byte ptr [eax + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */);
    // 004b4b8b  8806                   -mov byte ptr [esi], al
    app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
    // 004b4b8d  e92cffffff             -jmp 0x4b4abe
    goto L_0x004b4abe;
L_0x004b4b92:
    // 004b4b92  c6430e00               -mov byte ptr [ebx + 0xe], 0
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(14) /* 0xe */) = 0 /*0x0*/;
    // 004b4b96  c6430f01               -mov byte ptr [ebx + 0xf], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(15) /* 0xf */) = 1 /*0x1*/;
    // 004b4b9a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b4b9d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4b9e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4b9f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4ba0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4ba1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4b4ba4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b4ba4);
    // 004b4ba4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b4ba5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b4ba6  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b4baa  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b4bae  8b5908                 -mov ebx, dword ptr [ecx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004b4bb1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b4bb3  81fb00000100           +cmp ebx, 0x10000
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
    // 004b4bb9  732c                   -jae 0x4b4be7
    if (!cpu.flags.cf)
    {
        goto L_0x004b4be7;
    }
    // 004b4bbb  81fa00000100           +cmp edx, 0x10000
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
    // 004b4bc1  7324                   -jae 0x4b4be7
    if (!cpu.flags.cf)
    {
        goto L_0x004b4be7;
    }
L_0x004b4bc3:
    // 004b4bc3  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004b4bc6  81fa00000100           +cmp edx, 0x10000
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
    // 004b4bcc  724b                   -jb 0x4b4c19
    if (cpu.flags.cf)
    {
        goto L_0x004b4c19;
    }
    // 004b4bce  7660                   -jbe 0x4b4c30
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b4c30;
    }
    // 004b4bd0  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004b4bd3  c70240494b00           -mov dword ptr [edx], 0x4b4940
    app->getMemory<x86::reg32>(cpu.edx) = 4933952 /*0x4b4940*/;
    // 004b4bd9  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004b4bdc  c700bc494b00           -mov dword ptr [eax], 0x4b49bc
    app->getMemory<x86::reg32>(cpu.eax) = 4934076 /*0x4b49bc*/;
    // 004b4be2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b4be4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4be5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4be6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b4be7:
    // 004b4be7  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004b4bea  39f2                   +cmp edx, esi
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
    // 004b4bec  74d5                   -je 0x4b4bc3
    if (cpu.flags.zf)
    {
        goto L_0x004b4bc3;
    }
    // 004b4bee  81fe00000100           +cmp esi, 0x10000
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
    // 004b4bf4  7608                   -jbe 0x4b4bfe
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b4bfe;
    }
    // 004b4bf6  81fa00000100           +cmp edx, 0x10000
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
    // 004b4bfc  77c5                   -ja 0x4b4bc3
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004b4bc3;
    }
L_0x004b4bfe:
    // 004b4bfe  c6400e00               -mov byte ptr [eax + 0xe], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(14) /* 0xe */) = 0 /*0x0*/;
    // 004b4c02  c6400f00               -mov byte ptr [eax + 0xf], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(15) /* 0xf */) = 0 /*0x0*/;
    // 004b4c06  c6401000               -mov byte ptr [eax + 0x10], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 004b4c0a  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004b4c11  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004b4c17  ebaa                   -jmp 0x4b4bc3
    goto L_0x004b4bc3;
L_0x004b4c19:
    // 004b4c19  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004b4c1c  c70290494b00           -mov dword ptr [edx], 0x4b4990
    app->getMemory<x86::reg32>(cpu.edx) = 4934032 /*0x4b4990*/;
    // 004b4c22  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004b4c25  c7009c4a4b00           -mov dword ptr [eax], 0x4b4a9c
    app->getMemory<x86::reg32>(cpu.eax) = 4934300 /*0x4b4a9c*/;
    // 004b4c2b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b4c2d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4c2e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4c2f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b4c30:
    // 004b4c30  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004b4c33  c70288494b00           -mov dword ptr [edx], 0x4b4988
    app->getMemory<x86::reg32>(cpu.edx) = 4934024 /*0x4b4988*/;
    // 004b4c39  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004b4c3c  c700904a4b00           -mov dword ptr [eax], 0x4b4a90
    app->getMemory<x86::reg32>(cpu.eax) = 4934288 /*0x4b4a90*/;
    // 004b4c42  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b4c44  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4c45  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4c46  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4b4c48(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b4c48);
    // 004b4c48  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b4c4c  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004b4c52  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004b4c59  c6400e00               -mov byte ptr [eax + 0xe], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(14) /* 0xe */) = 0 /*0x0*/;
    // 004b4c5d  c6400d00               -mov byte ptr [eax + 0xd], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */) = 0 /*0x0*/;
    // 004b4c61  c6400f00               -mov byte ptr [eax + 0xf], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(15) /* 0xf */) = 0 /*0x0*/;
    // 004b4c65  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b4c69  c6401001               -mov byte ptr [eax + 0x10], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(16) /* 0x10 */) = 1 /*0x1*/;
    // 004b4c6d  895014                 -mov dword ptr [eax + 0x14], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004b4c70  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b4c74  895018                 -mov dword ptr [eax + 0x18], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004b4c77  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b4c7b  89501c                 -mov dword ptr [eax + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004b4c7e  8b4014                 -mov eax, dword ptr [eax + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004b4c81  c700a44b4b00           -mov dword ptr [eax], 0x4b4ba4
    app->getMemory<x86::reg32>(cpu.eax) = 4934564 /*0x4b4ba4*/;
    // 004b4c87  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b4c89  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4b4c90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b4c90);
    // 004b4c90  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b4c91  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b4c92  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b4c93  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b4c97  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004b4c9b  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004b4c9e  48                     -dec eax
    (cpu.eax)--;
    // 004b4c9f  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004b4ca2  034204                 -add eax, dword ptr [edx + 4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 004b4ca5  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b4ca8  8b5a0f                 -mov ebx, dword ptr [edx + 0xf]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(15) /* 0xf */);
    // 004b4cab  40                     -inc eax
    (cpu.eax)++;
    // 004b4cac  c1fb18                 -sar ebx, 0x18
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (24 /*0x18*/ % 32));
    // 004b4caf  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b4cb1  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b4cb3  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 004b4cb6  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b4cb8  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 004b4cba  7501                   -jne 0x4b4cbd
    if (!cpu.flags.zf)
    {
        goto L_0x004b4cbd;
    }
    // 004b4cbc  40                     -inc eax
    (cpu.eax)++;
L_0x004b4cbd:
    // 004b4cbd  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004b4cc1  8b5108                 -mov edx, dword ptr [ecx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004b4cc4  0fafd7                 -imul edx, edi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 004b4cc7  035104                 -add edx, dword ptr [ecx + 4]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
    // 004b4cca  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004b4ccd  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004b4ccf  885112                 -mov byte ptr [ecx + 0x12], dl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(18) /* 0x12 */) = cpu.dl;
    // 004b4cd2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4cd3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4cd4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4cd5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4b4cd8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b4cd8);
    // 004b4cd8  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b4cdc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4b4ce0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b4ce0);
    // 004b4ce0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b4ce1  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b4ce5  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b4ce9  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004b4cec  48                     -dec eax
    (cpu.eax)--;
    // 004b4ced  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004b4cf0  034204                 -add eax, dword ptr [edx + 4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 004b4cf3  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b4cf5  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b4cf8  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 004b4cfb  40                     -inc eax
    (cpu.eax)++;
    // 004b4cfc  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 004b4cfe  7501                   -jne 0x4b4d01
    if (!cpu.flags.zf)
    {
        goto L_0x004b4d01;
    }
    // 004b4d00  40                     -inc eax
    (cpu.eax)++;
L_0x004b4d01:
    // 004b4d01  8b510d                 -mov edx, dword ptr [ecx + 0xd]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(13) /* 0xd */);
    // 004b4d04  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004b4d07  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b4d09  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4d0a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4b4d0c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b4d0c);
    // 004b4d0c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b4d0d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b4d0e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b4d0f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b4d10  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b4d13  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004b4d17  8b7c2420               -mov edi, dword ptr [esp + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004b4d1b  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004b4d1f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b4d21  8a4811                 -mov cl, byte ptr [eax + 0x11]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(17) /* 0x11 */);
    // 004b4d24  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004b4d26  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 004b4d28  0f85b9000000           -jne 0x4b4de7
    if (!cpu.flags.zf)
    {
        goto L_0x004b4de7;
    }
L_0x004b4d2e:
    // 004b4d2e  8b6c2428               -mov ebp, dword ptr [esp + 0x28]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004b4d32  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp);
    // 004b4d35  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004b4d36  0f85be000000           -jne 0x4b4dfa
    if (!cpu.flags.zf)
    {
        goto L_0x004b4dfa;
    }
L_0x004b4d3c:
    // 004b4d3c  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b4d3e  0fbe0456               -movsx eax, byte ptr [esi + edx*2]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.esi + cpu.edx * 2)));
    // 004b4d42  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004b4d45  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b4d48  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004b4d4c  b8ffff0000             -mov eax, 0xffff
    cpu.eax = 65535 /*0xffff*/;
    // 004b4d51  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b4d53  0faf442404             -imul eax, dword ptr [esp + 4]
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */))));
    // 004b4d58  0fbe545602             -movsx edx, byte ptr [esi + edx*2 + 2]
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */ + cpu.edx * 2)));
    // 004b4d5d  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004b4d60  0faf5304               -imul edx, dword ptr [ebx + 4]
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */))));
    // 004b4d64  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b4d67  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004b4d6a  01ff                   -add edi, edi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edi));
    // 004b4d6c  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b4d6e  01fd                   -add ebp, edi
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edi));
    // 004b4d70  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 004b4d73  884500                 -mov byte ptr [ebp], al
    app->getMemory<x86::reg8>(cpu.ebp) = cpu.al;
    // 004b4d76  8b3b                   -mov edi, dword ptr [ebx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b4d78  b8ffff0000             -mov eax, 0xffff
    cpu.eax = 65535 /*0xffff*/;
    // 004b4d7d  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b4d80  0fbe547e01             -movsx edx, byte ptr [esi + edi*2 + 1]
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.edi * 2)));
    // 004b4d85  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b4d87  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004b4d8a  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004b4d8d  8b147e                 -mov edx, dword ptr [esi + edi*2]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + cpu.edi * 2);
    // 004b4d90  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004b4d93  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004b4d96  0fafd1                 -imul edx, ecx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004b4d99  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b4d9c  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004b4d9f  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b4da1  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 004b4da4  884501                 -mov byte ptr [ebp + 1], al
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004b4da7  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b4da9  8a444602               -mov al, byte ptr [esi + eax*2 + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */ + cpu.eax * 2);
    // 004b4dad  88430e                 -mov byte ptr [ebx + 0xe], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(14) /* 0xe */) = cpu.al;
    // 004b4db0  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b4db2  8a444603               -mov al, byte ptr [esi + eax*2 + 3]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */ + cpu.eax * 2);
    // 004b4db6  88430f                 -mov byte ptr [ebx + 0xf], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(15) /* 0xf */) = cpu.al;
    // 004b4db9  8b6b04                 -mov ebp, dword ptr [ebx + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b4dbc  036b08                 -add ebp, dword ptr [ebx + 8]
    (cpu.ebp) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */)));
    // 004b4dbf  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b4dc1  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004b4dc3  896b04                 -mov dword ptr [ebx + 4], ebp
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 004b4dc6  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b4dc9  66c743060000           -mov word ptr [ebx + 6], 0
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 004b4dcf  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b4dd1  8b430f                 -mov eax, dword ptr [ebx + 0xf]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(15) /* 0xf */);
    // 004b4dd4  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 004b4dd6  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004b4dd9  c6431101               -mov byte ptr [ebx + 0x11], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(17) /* 0x11 */) = 1 /*0x1*/;
    // 004b4ddd  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004b4ddf  83c408                 +add esp, 8
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
    // 004b4de2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4de3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4de4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4de5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4de6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b4de7:
    // 004b4de7  8d72ff                 -lea esi, [edx - 1]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 004b4dea  8a500f                 -mov dl, byte ptr [eax + 0xf]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(15) /* 0xf */);
    // 004b4ded  8816                   -mov byte ptr [esi], dl
    app->getMemory<x86::reg8>(cpu.esi) = cpu.dl;
    // 004b4def  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004b4df0  8a400e                 -mov al, byte ptr [eax + 0xe]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(14) /* 0xe */);
    // 004b4df3  8806                   -mov byte ptr [esi], al
    app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
    // 004b4df5  e934ffffff             -jmp 0x4b4d2e
    goto L_0x004b4d2e;
L_0x004b4dfa:
    // 004b4dfa  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b4dfd  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b4e00  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b4e03  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004b4e06  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004b4e09  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b4e0a  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004b4e0d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b4e0e  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b4e12  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b4e16  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b4e17  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b4e18  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b4e19  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b4e1a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b4e1b  e8f4510000             -call 0x4ba014
    cpu.esp -= 4;
    sub_4ba014(app, cpu);
    if (cpu.terminate) return;
    // 004b4e20  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004b4e23  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004b4e26  c1e810                 +shr eax, 0x10
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
    // 004b4e29  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004b4e2c  e90bffffff             -jmp 0x4b4d3c
    goto L_0x004b4d3c;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4b4e34(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b4e34);
    // 004b4e34  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b4e38  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b4e3c  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004b4e3e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4b4e40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b4e40);
    // 004b4e40  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b4e41  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b4e42  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b4e43  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b4e44  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b4e47  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004b4e4b  8b7c241c               -mov edi, dword ptr [esp + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004b4e4f  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004b4e53  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b4e55  8a4811                 -mov cl, byte ptr [eax + 0x11]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(17) /* 0x11 */);
    // 004b4e58  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004b4e5a  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 004b4e5c  0f8510010000           -jne 0x4b4f72
    if (!cpu.flags.zf)
    {
        goto L_0x004b4f72;
    }
L_0x004b4e62:
    // 004b4e62  807b1000               +cmp byte ptr [ebx + 0x10], 0
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
    // 004b4e66  740c                   -je 0x4b4e74
    if (cpu.flags.zf)
    {
        goto L_0x004b4e74;
    }
    // 004b4e68  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004b4e69  8a430d                 -mov al, byte ptr [ebx + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(13) /* 0xd */);
    // 004b4e6c  8806                   -mov byte ptr [esi], al
    app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
    // 004b4e6e  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004b4e6f  8a430c                 -mov al, byte ptr [ebx + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004b4e72  8806                   -mov byte ptr [esi], al
    app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
L_0x004b4e74:
    // 004b4e74  8b6c2424               -mov ebp, dword ptr [esp + 0x24]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004b4e78  c70300000000           -mov dword ptr [ebx], 0
    app->getMemory<x86::reg32>(cpu.ebx) = 0 /*0x0*/;
    // 004b4e7e  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp);
    // 004b4e81  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004b4e82  7432                   -je 0x4b4eb6
    if (cpu.flags.zf)
    {
        goto L_0x004b4eb6;
    }
    // 004b4e84  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b4e87  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b4e8a  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b4e8d  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004b4e90  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004b4e93  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b4e94  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004b4e97  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b4e98  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b4e9c  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b4ea0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b4ea1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b4ea2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b4ea3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b4ea4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b4ea5  e86a510000             -call 0x4ba014
    cpu.esp -= 4;
    sub_4ba014(app, cpu);
    if (cpu.terminate) return;
    // 004b4eaa  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004b4ead  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004b4eb0  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b4eb3  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x004b4eb6:
    // 004b4eb6  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b4eb8  b9ffff0000             -mov ecx, 0xffff
    cpu.ecx = 65535 /*0xffff*/;
    // 004b4ebd  0fbe0456               -movsx eax, byte ptr [esi + edx*2]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.esi + cpu.edx * 2)));
    // 004b4ec1  2b4b04                 -sub ecx, dword ptr [ebx + 4]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */)));
    // 004b4ec4  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004b4ec7  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004b4eca  0fbe545602             -movsx edx, byte ptr [esi + edx*2 + 2]
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */ + cpu.edx * 2)));
    // 004b4ecf  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004b4ed2  0faf5304               -imul edx, dword ptr [ebx + 4]
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */))));
    // 004b4ed6  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b4ed9  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004b4edc  01ff                   -add edi, edi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edi));
    // 004b4ede  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b4ee0  01fd                   -add ebp, edi
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edi));
    // 004b4ee2  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 004b4ee5  884500                 -mov byte ptr [ebp], al
    app->getMemory<x86::reg8>(cpu.ebp) = cpu.al;
    // 004b4ee8  8b3b                   -mov edi, dword ptr [ebx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b4eea  b8ffff0000             -mov eax, 0xffff
    cpu.eax = 65535 /*0xffff*/;
    // 004b4eef  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b4ef2  0fbe547e01             -movsx edx, byte ptr [esi + edi*2 + 1]
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.edi * 2)));
    // 004b4ef7  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b4ef9  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004b4efc  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004b4eff  8b147e                 -mov edx, dword ptr [esi + edi*2]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + cpu.edi * 2);
    // 004b4f02  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004b4f05  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004b4f08  0fafd1                 -imul edx, ecx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004b4f0b  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b4f0e  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004b4f11  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b4f13  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 004b4f16  884501                 -mov byte ptr [ebp + 1], al
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004b4f19  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b4f1b  8a444602               -mov al, byte ptr [esi + eax*2 + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */ + cpu.eax * 2);
    // 004b4f1f  88430e                 -mov byte ptr [ebx + 0xe], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(14) /* 0xe */) = cpu.al;
    // 004b4f22  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b4f24  8a444603               -mov al, byte ptr [esi + eax*2 + 3]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */ + cpu.eax * 2);
    // 004b4f28  88430f                 -mov byte ptr [ebx + 0xf], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(15) /* 0xf */) = cpu.al;
    // 004b4f2b  8b6b04                 -mov ebp, dword ptr [ebx + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b4f2e  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b4f31  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b4f33  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b4f35  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b4f38  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004b4f3a  896b04                 -mov dword ptr [ebx + 4], ebp
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 004b4f3d  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b4f40  66c743060000           -mov word ptr [ebx + 6], 0
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 004b4f46  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b4f48  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b4f4b  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 004b4f4d  39c8                   +cmp eax, ecx
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
    // 004b4f4f  7234                   -jb 0x4b4f85
    if (cpu.flags.cf)
    {
        goto L_0x004b4f85;
    }
    // 004b4f51  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b4f53  c6431001               -mov byte ptr [ebx + 0x10], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */) = 1 /*0x1*/;
    // 004b4f57  8a0446                 -mov al, byte ptr [esi + eax*2]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 2);
    // 004b4f5a  88430c                 -mov byte ptr [ebx + 0xc], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.al;
    // 004b4f5d  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b4f5f  8a444601               -mov al, byte ptr [esi + eax*2 + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.eax * 2);
    // 004b4f63  88430d                 -mov byte ptr [ebx + 0xd], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(13) /* 0xd */) = cpu.al;
    // 004b4f66  c6431101               -mov byte ptr [ebx + 0x11], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(17) /* 0x11 */) = 1 /*0x1*/;
    // 004b4f6a  83c404                 +add esp, 4
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
    // 004b4f6d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4f6e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4f6f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4f70  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4f71  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b4f72:
    // 004b4f72  8d72ff                 -lea esi, [edx - 1]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 004b4f75  8a500f                 -mov dl, byte ptr [eax + 0xf]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(15) /* 0xf */);
    // 004b4f78  8816                   -mov byte ptr [esi], dl
    app->getMemory<x86::reg8>(cpu.esi) = cpu.dl;
    // 004b4f7a  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004b4f7b  8a400e                 -mov al, byte ptr [eax + 0xe]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(14) /* 0xe */);
    // 004b4f7e  8806                   -mov byte ptr [esi], al
    app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
    // 004b4f80  e9ddfeffff             -jmp 0x4b4e62
    goto L_0x004b4e62;
L_0x004b4f85:
    // 004b4f85  c6431000               -mov byte ptr [ebx + 0x10], 0
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 004b4f89  c6431101               -mov byte ptr [ebx + 0x11], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(17) /* 0x11 */) = 1 /*0x1*/;
    // 004b4f8d  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b4f90  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4f91  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4f92  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4f93  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4f94  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4b4f98(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b4f98);
    // 004b4f98  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b4f99  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b4f9a  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b4f9e  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b4fa2  8b5908                 -mov ebx, dword ptr [ecx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004b4fa5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b4fa7  81fb00000100           +cmp ebx, 0x10000
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
    // 004b4fad  732c                   -jae 0x4b4fdb
    if (!cpu.flags.cf)
    {
        goto L_0x004b4fdb;
    }
    // 004b4faf  81fa00000100           +cmp edx, 0x10000
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
    // 004b4fb5  7324                   -jae 0x4b4fdb
    if (!cpu.flags.cf)
    {
        goto L_0x004b4fdb;
    }
L_0x004b4fb7:
    // 004b4fb7  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004b4fba  81fa00000100           +cmp edx, 0x10000
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
    // 004b4fc0  724b                   -jb 0x4b500d
    if (cpu.flags.cf)
    {
        goto L_0x004b500d;
    }
    // 004b4fc2  7660                   -jbe 0x4b5024
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b5024;
    }
    // 004b4fc4  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004b4fc7  c702904c4b00           -mov dword ptr [edx], 0x4b4c90
    app->getMemory<x86::reg32>(cpu.edx) = 4934800 /*0x4b4c90*/;
    // 004b4fcd  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004b4fd0  c7000c4d4b00           -mov dword ptr [eax], 0x4b4d0c
    app->getMemory<x86::reg32>(cpu.eax) = 4934924 /*0x4b4d0c*/;
    // 004b4fd6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b4fd8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4fd9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4fda  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b4fdb:
    // 004b4fdb  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004b4fde  39f2                   +cmp edx, esi
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
    // 004b4fe0  74d5                   -je 0x4b4fb7
    if (cpu.flags.zf)
    {
        goto L_0x004b4fb7;
    }
    // 004b4fe2  81fe00000100           +cmp esi, 0x10000
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
    // 004b4fe8  7608                   -jbe 0x4b4ff2
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b4ff2;
    }
    // 004b4fea  81fa00000100           +cmp edx, 0x10000
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
    // 004b4ff0  77c5                   -ja 0x4b4fb7
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004b4fb7;
    }
L_0x004b4ff2:
    // 004b4ff2  c6401000               -mov byte ptr [eax + 0x10], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 004b4ff6  c6401100               -mov byte ptr [eax + 0x11], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(17) /* 0x11 */) = 0 /*0x0*/;
    // 004b4ffa  c6401200               -mov byte ptr [eax + 0x12], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(18) /* 0x12 */) = 0 /*0x0*/;
    // 004b4ffe  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004b5005  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004b500b  ebaa                   -jmp 0x4b4fb7
    goto L_0x004b4fb7;
L_0x004b500d:
    // 004b500d  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004b5010  c702e04c4b00           -mov dword ptr [edx], 0x4b4ce0
    app->getMemory<x86::reg32>(cpu.edx) = 4934880 /*0x4b4ce0*/;
    // 004b5016  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004b5019  c700404e4b00           -mov dword ptr [eax], 0x4b4e40
    app->getMemory<x86::reg32>(cpu.eax) = 4935232 /*0x4b4e40*/;
    // 004b501f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b5021  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5022  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5023  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b5024:
    // 004b5024  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004b5027  c702d84c4b00           -mov dword ptr [edx], 0x4b4cd8
    app->getMemory<x86::reg32>(cpu.edx) = 4934872 /*0x4b4cd8*/;
    // 004b502d  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004b5030  c700344e4b00           -mov dword ptr [eax], 0x4b4e34
    app->getMemory<x86::reg32>(cpu.eax) = 4935220 /*0x4b4e34*/;
    // 004b5036  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b5038  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5039  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b503a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4b503c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b503c);
    // 004b503c  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b5040  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004b5046  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004b504d  c6401000               -mov byte ptr [eax + 0x10], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 004b5051  c6401100               -mov byte ptr [eax + 0x11], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(17) /* 0x11 */) = 0 /*0x0*/;
    // 004b5055  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b5059  c6401200               -mov byte ptr [eax + 0x12], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(18) /* 0x12 */) = 0 /*0x0*/;
    // 004b505d  895014                 -mov dword ptr [eax + 0x14], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004b5060  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b5064  895018                 -mov dword ptr [eax + 0x18], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004b5067  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b506b  89501c                 -mov dword ptr [eax + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004b506e  8b4014                 -mov eax, dword ptr [eax + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004b5071  c700984f4b00           -mov dword ptr [eax], 0x4b4f98
    app->getMemory<x86::reg32>(cpu.eax) = 4935576 /*0x4b4f98*/;
    // 004b5077  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b5079  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4b5080(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b5080);
    // 004b5080  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b5081  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b5082  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b5083  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b5087  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004b508b  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004b508e  48                     -dec eax
    (cpu.eax)--;
    // 004b508f  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004b5092  034204                 -add eax, dword ptr [edx + 4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 004b5095  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b5098  8b5a0f                 -mov ebx, dword ptr [edx + 0xf]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(15) /* 0xf */);
    // 004b509b  40                     -inc eax
    (cpu.eax)++;
    // 004b509c  c1fb18                 -sar ebx, 0x18
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (24 /*0x18*/ % 32));
    // 004b509f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b50a1  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b50a3  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 004b50a6  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b50a8  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 004b50aa  7501                   -jne 0x4b50ad
    if (!cpu.flags.zf)
    {
        goto L_0x004b50ad;
    }
    // 004b50ac  40                     -inc eax
    (cpu.eax)++;
L_0x004b50ad:
    // 004b50ad  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004b50b1  8b5108                 -mov edx, dword ptr [ecx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004b50b4  0fafd7                 -imul edx, edi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 004b50b7  035104                 -add edx, dword ptr [ecx + 4]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
    // 004b50ba  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004b50bd  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004b50bf  885112                 -mov byte ptr [ecx + 0x12], dl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(18) /* 0x12 */) = cpu.dl;
    // 004b50c2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b50c3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b50c4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b50c5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4b50c8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b50c8);
    // 004b50c8  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b50cc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4b50d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b50d0);
    // 004b50d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b50d1  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b50d5  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b50d9  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004b50dc  48                     -dec eax
    (cpu.eax)--;
    // 004b50dd  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004b50e0  034204                 -add eax, dword ptr [edx + 4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 004b50e3  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b50e5  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b50e8  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 004b50eb  40                     -inc eax
    (cpu.eax)++;
    // 004b50ec  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 004b50ee  7501                   -jne 0x4b50f1
    if (!cpu.flags.zf)
    {
        goto L_0x004b50f1;
    }
    // 004b50f0  40                     -inc eax
    (cpu.eax)++;
L_0x004b50f1:
    // 004b50f1  8b510d                 -mov edx, dword ptr [ecx + 0xd]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(13) /* 0xd */);
    // 004b50f4  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004b50f7  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b50f9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b50fa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4b50fc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b50fc);
    // 004b50fc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b50fd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b50fe  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b50ff  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b5100  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b5103  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004b5107  8b7c241c               -mov edi, dword ptr [esp + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004b510b  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004b510f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b5111  8a4811                 -mov cl, byte ptr [eax + 0x11]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(17) /* 0x11 */);
    // 004b5114  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004b5116  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 004b5118  0f8581000000           -jne 0x4b519f
    if (!cpu.flags.zf)
    {
        goto L_0x004b519f;
    }
L_0x004b511e:
    // 004b511e  8b6c2424               -mov ebp, dword ptr [esp + 0x24]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004b5122  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp);
    // 004b5125  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004b5126  0f8582000000           -jne 0x4b51ae
    if (!cpu.flags.zf)
    {
        goto L_0x004b51ae;
    }
L_0x004b512c:
    // 004b512c  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b512e  baffff0000             -mov edx, 0xffff
    cpu.edx = 65535 /*0xffff*/;
    // 004b5133  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b5136  0fbf0446               -movsx eax, word ptr [esi + eax*2]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.esi + cpu.eax * 2)));
    // 004b513a  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b513c  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004b513f  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b5142  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b5144  8d043f                 -lea eax, [edi + edi]
    cpu.eax = x86::reg32(cpu.edi + cpu.edi * 1);
    // 004b5147  66891428               -mov word ptr [eax + ebp], dx
    app->getMemory<x86::reg16>(cpu.eax + cpu.ebp * 1) = cpu.dx;
    // 004b514b  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b514d  8b1456                 -mov edx, dword ptr [esi + edx*2]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + cpu.edx * 2);
    // 004b5150  8b7b04                 -mov edi, dword ptr [ebx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b5153  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004b5156  0faffa                 -imul edi, edx
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004b5159  c1ef10                 -shr edi, 0x10
    cpu.edi >>= 16 /*0x10*/ % 32;
    // 004b515c  0fbf1428               -movsx edx, word ptr [eax + ebp]
    cpu.edx = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.eax + cpu.ebp * 1)));
    // 004b5160  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004b5162  66891428               -mov word ptr [eax + ebp], dx
    app->getMemory<x86::reg16>(cpu.eax + cpu.ebp * 1) = cpu.dx;
    // 004b5166  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b5168  668b444602             -mov ax, word ptr [esi + eax*2 + 2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(2) /* 0x2 */ + cpu.eax * 2);
    // 004b516d  6689430e               -mov word ptr [ebx + 0xe], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(14) /* 0xe */) = cpu.ax;
    // 004b5171  8b6b04                 -mov ebp, dword ptr [ebx + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b5174  036b08                 -add ebp, dword ptr [ebx + 8]
    (cpu.ebp) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */)));
    // 004b5177  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b5179  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004b517b  896b04                 -mov dword ptr [ebx + 4], ebp
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 004b517e  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b5181  66c743060000           -mov word ptr [ebx + 6], 0
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 004b5187  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b5189  8b430f                 -mov eax, dword ptr [ebx + 0xf]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(15) /* 0xf */);
    // 004b518c  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 004b518e  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004b5191  c6431101               -mov byte ptr [ebx + 0x11], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(17) /* 0x11 */) = 1 /*0x1*/;
    // 004b5195  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004b5197  83c404                 +add esp, 4
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
    // 004b519a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b519b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b519c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b519d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b519e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b519f:
    // 004b519f  8d72fe                 -lea esi, [edx - 2]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(-2) /* -0x2 */);
    // 004b51a2  668b400e               -mov ax, word ptr [eax + 0xe]
    cpu.ax = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(14) /* 0xe */);
    // 004b51a6  668906                 -mov word ptr [esi], ax
    app->getMemory<x86::reg16>(cpu.esi) = cpu.ax;
    // 004b51a9  e970ffffff             -jmp 0x4b511e
    goto L_0x004b511e;
L_0x004b51ae:
    // 004b51ae  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b51b1  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b51b4  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b51b7  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004b51ba  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004b51bd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b51be  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004b51c1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b51c2  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b51c6  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b51ca  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b51cb  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b51cc  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b51cd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b51ce  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b51cf  e8e04e0000             -call 0x4ba0b4
    cpu.esp -= 4;
    sub_4ba0b4(app, cpu);
    if (cpu.terminate) return;
    // 004b51d4  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004b51d7  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004b51da  c1e810                 +shr eax, 0x10
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
    // 004b51dd  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004b51e0  e947ffffff             -jmp 0x4b512c
    goto L_0x004b512c;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4b51e8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b51e8);
    // 004b51e8  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b51ec  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b51f0  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004b51f2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4b51f4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b51f4);
    // 004b51f4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b51f5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b51f6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b51f7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b51f8  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b51fb  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004b51ff  8b7c241c               -mov edi, dword ptr [esp + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004b5203  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004b5207  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b5209  8a4811                 -mov cl, byte ptr [eax + 0x11]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(17) /* 0x11 */);
    // 004b520c  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004b520e  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 004b5210  0f85d5000000           -jne 0x4b52eb
    if (!cpu.flags.zf)
    {
        goto L_0x004b52eb;
    }
L_0x004b5216:
    // 004b5216  807b1000               +cmp byte ptr [ebx + 0x10], 0
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
    // 004b521a  740a                   -je 0x4b5226
    if (cpu.flags.zf)
    {
        goto L_0x004b5226;
    }
    // 004b521c  83ee02                 +sub esi, 2
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
    // 004b521f  668b430c               -mov ax, word ptr [ebx + 0xc]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004b5223  668906                 -mov word ptr [esi], ax
    app->getMemory<x86::reg16>(cpu.esi) = cpu.ax;
L_0x004b5226:
    // 004b5226  8b6c2424               -mov ebp, dword ptr [esp + 0x24]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004b522a  c70300000000           -mov dword ptr [ebx], 0
    app->getMemory<x86::reg32>(cpu.ebx) = 0 /*0x0*/;
    // 004b5230  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp);
    // 004b5233  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004b5234  7432                   -je 0x4b5268
    if (cpu.flags.zf)
    {
        goto L_0x004b5268;
    }
    // 004b5236  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b5239  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b523c  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b523f  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004b5242  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004b5245  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b5246  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004b5249  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b524a  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b524e  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b5252  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b5253  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b5254  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b5255  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b5256  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b5257  e8584e0000             -call 0x4ba0b4
    cpu.esp -= 4;
    sub_4ba0b4(app, cpu);
    if (cpu.terminate) return;
    // 004b525c  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004b525f  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004b5262  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b5265  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x004b5268:
    // 004b5268  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b526a  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b526d  0fbf1446               -movsx edx, word ptr [esi + eax*2]
    cpu.edx = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.esi + cpu.eax * 2)));
    // 004b5271  b8ffff0000             -mov eax, 0xffff
    cpu.eax = 65535 /*0xffff*/;
    // 004b5276  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b5278  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004b527b  8d143f                 -lea edx, [edi + edi]
    cpu.edx = x86::reg32(cpu.edi + cpu.edi * 1);
    // 004b527e  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b5281  6689042a               -mov word ptr [edx + ebp], ax
    app->getMemory<x86::reg16>(cpu.edx + cpu.ebp * 1) = cpu.ax;
    // 004b5285  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b5287  8b0446                 -mov eax, dword ptr [esi + eax*2]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + cpu.eax * 2);
    // 004b528a  8b7b04                 -mov edi, dword ptr [ebx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b528d  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004b5290  0faff8                 -imul edi, eax
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 004b5293  c1ef10                 -shr edi, 0x10
    cpu.edi >>= 16 /*0x10*/ % 32;
    // 004b5296  0fbf042a               -movsx eax, word ptr [edx + ebp]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.edx + cpu.ebp * 1)));
    // 004b529a  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 004b529c  6689042a               -mov word ptr [edx + ebp], ax
    app->getMemory<x86::reg16>(cpu.edx + cpu.ebp * 1) = cpu.ax;
    // 004b52a0  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b52a2  668b444602             -mov ax, word ptr [esi + eax*2 + 2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(2) /* 0x2 */ + cpu.eax * 2);
    // 004b52a7  6689430e               -mov word ptr [ebx + 0xe], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(14) /* 0xe */) = cpu.ax;
    // 004b52ab  8b6b04                 -mov ebp, dword ptr [ebx + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b52ae  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b52b1  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b52b3  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b52b5  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b52b8  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004b52ba  896b04                 -mov dword ptr [ebx + 4], ebp
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 004b52bd  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b52c0  66c743060000           -mov word ptr [ebx + 6], 0
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 004b52c6  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b52c8  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b52cb  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 004b52cd  39c8                   +cmp eax, ecx
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
    // 004b52cf  7229                   -jb 0x4b52fa
    if (cpu.flags.cf)
    {
        goto L_0x004b52fa;
    }
    // 004b52d1  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b52d3  c6431001               -mov byte ptr [ebx + 0x10], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */) = 1 /*0x1*/;
    // 004b52d7  668b0446               -mov ax, word ptr [esi + eax*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.eax * 2);
    // 004b52db  6689430c               -mov word ptr [ebx + 0xc], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.ax;
    // 004b52df  c6431101               -mov byte ptr [ebx + 0x11], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(17) /* 0x11 */) = 1 /*0x1*/;
    // 004b52e3  83c404                 +add esp, 4
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
    // 004b52e6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b52e7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b52e8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b52e9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b52ea  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b52eb:
    // 004b52eb  8d72fe                 -lea esi, [edx - 2]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(-2) /* -0x2 */);
    // 004b52ee  668b400e               -mov ax, word ptr [eax + 0xe]
    cpu.ax = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(14) /* 0xe */);
    // 004b52f2  668906                 -mov word ptr [esi], ax
    app->getMemory<x86::reg16>(cpu.esi) = cpu.ax;
    // 004b52f5  e91cffffff             -jmp 0x4b5216
    goto L_0x004b5216;
L_0x004b52fa:
    // 004b52fa  c6431000               -mov byte ptr [ebx + 0x10], 0
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 004b52fe  c6431101               -mov byte ptr [ebx + 0x11], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(17) /* 0x11 */) = 1 /*0x1*/;
    // 004b5302  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b5305  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5306  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5307  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5308  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5309  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4b530c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b530c);
    // 004b530c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b530d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b530e  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b5312  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b5316  8b5908                 -mov ebx, dword ptr [ecx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004b5319  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b531b  81fb00000100           +cmp ebx, 0x10000
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
    // 004b5321  732c                   -jae 0x4b534f
    if (!cpu.flags.cf)
    {
        goto L_0x004b534f;
    }
    // 004b5323  81fa00000100           +cmp edx, 0x10000
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
    // 004b5329  7324                   -jae 0x4b534f
    if (!cpu.flags.cf)
    {
        goto L_0x004b534f;
    }
L_0x004b532b:
    // 004b532b  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004b532e  81fa00000100           +cmp edx, 0x10000
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
    // 004b5334  724b                   -jb 0x4b5381
    if (cpu.flags.cf)
    {
        goto L_0x004b5381;
    }
    // 004b5336  7660                   -jbe 0x4b5398
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b5398;
    }
    // 004b5338  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004b533b  c70280504b00           -mov dword ptr [edx], 0x4b5080
    app->getMemory<x86::reg32>(cpu.edx) = 4935808 /*0x4b5080*/;
    // 004b5341  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004b5344  c700fc504b00           -mov dword ptr [eax], 0x4b50fc
    app->getMemory<x86::reg32>(cpu.eax) = 4935932 /*0x4b50fc*/;
    // 004b534a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b534c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b534d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b534e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b534f:
    // 004b534f  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004b5352  39f2                   +cmp edx, esi
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
    // 004b5354  74d5                   -je 0x4b532b
    if (cpu.flags.zf)
    {
        goto L_0x004b532b;
    }
    // 004b5356  81fe00000100           +cmp esi, 0x10000
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
    // 004b535c  7608                   -jbe 0x4b5366
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b5366;
    }
    // 004b535e  81fa00000100           +cmp edx, 0x10000
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
    // 004b5364  77c5                   -ja 0x4b532b
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004b532b;
    }
L_0x004b5366:
    // 004b5366  c6401000               -mov byte ptr [eax + 0x10], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 004b536a  c6401100               -mov byte ptr [eax + 0x11], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(17) /* 0x11 */) = 0 /*0x0*/;
    // 004b536e  c6401200               -mov byte ptr [eax + 0x12], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(18) /* 0x12 */) = 0 /*0x0*/;
    // 004b5372  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004b5379  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004b537f  ebaa                   -jmp 0x4b532b
    goto L_0x004b532b;
L_0x004b5381:
    // 004b5381  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004b5384  c702d0504b00           -mov dword ptr [edx], 0x4b50d0
    app->getMemory<x86::reg32>(cpu.edx) = 4935888 /*0x4b50d0*/;
    // 004b538a  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004b538d  c700f4514b00           -mov dword ptr [eax], 0x4b51f4
    app->getMemory<x86::reg32>(cpu.eax) = 4936180 /*0x4b51f4*/;
    // 004b5393  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b5395  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5396  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5397  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b5398:
    // 004b5398  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004b539b  c702c8504b00           -mov dword ptr [edx], 0x4b50c8
    app->getMemory<x86::reg32>(cpu.edx) = 4935880 /*0x4b50c8*/;
    // 004b53a1  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004b53a4  c700e8514b00           -mov dword ptr [eax], 0x4b51e8
    app->getMemory<x86::reg32>(cpu.eax) = 4936168 /*0x4b51e8*/;
    // 004b53aa  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b53ac  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b53ad  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b53ae  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4b53b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b53b0);
    // 004b53b0  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b53b4  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004b53ba  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004b53c1  c6401000               -mov byte ptr [eax + 0x10], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 004b53c5  66c7400e0000           -mov word ptr [eax + 0xe], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(14) /* 0xe */) = 0 /*0x0*/;
    // 004b53cb  c6401100               -mov byte ptr [eax + 0x11], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(17) /* 0x11 */) = 0 /*0x0*/;
    // 004b53cf  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b53d3  c6401201               -mov byte ptr [eax + 0x12], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(18) /* 0x12 */) = 1 /*0x1*/;
    // 004b53d7  895014                 -mov dword ptr [eax + 0x14], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004b53da  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b53de  895018                 -mov dword ptr [eax + 0x18], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004b53e1  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b53e5  89501c                 -mov dword ptr [eax + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004b53e8  8b4014                 -mov eax, dword ptr [eax + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004b53eb  c7000c534b00           -mov dword ptr [eax], 0x4b530c
    app->getMemory<x86::reg32>(cpu.eax) = 4936460 /*0x4b530c*/;
    // 004b53f1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b53f3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4b5400(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b5400);
    // 004b5400  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b5401  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b5402  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b5403  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b5407  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004b540b  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004b540e  48                     -dec eax
    (cpu.eax)--;
    // 004b540f  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004b5412  034204                 -add eax, dword ptr [edx + 4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 004b5415  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b5418  8b5a13                 -mov ebx, dword ptr [edx + 0x13]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 004b541b  40                     -inc eax
    (cpu.eax)++;
    // 004b541c  c1fb18                 -sar ebx, 0x18
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (24 /*0x18*/ % 32));
    // 004b541f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b5421  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b5423  8a5a15                 -mov bl, byte ptr [edx + 0x15]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(21) /* 0x15 */);
    // 004b5426  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b5428  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 004b542a  7501                   -jne 0x4b542d
    if (!cpu.flags.zf)
    {
        goto L_0x004b542d;
    }
    // 004b542c  40                     -inc eax
    (cpu.eax)++;
L_0x004b542d:
    // 004b542d  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004b5431  8b5108                 -mov edx, dword ptr [ecx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004b5434  0fafd7                 -imul edx, edi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 004b5437  035104                 -add edx, dword ptr [ecx + 4]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
    // 004b543a  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004b543d  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004b543f  885116                 -mov byte ptr [ecx + 0x16], dl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(22) /* 0x16 */) = cpu.dl;
    // 004b5442  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5443  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5444  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5445  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4b5448(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b5448);
    // 004b5448  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b544c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4b5450(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b5450);
    // 004b5450  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b5451  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b5455  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b5459  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004b545c  48                     -dec eax
    (cpu.eax)--;
    // 004b545d  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004b5460  034204                 -add eax, dword ptr [edx + 4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 004b5463  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b5465  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b5468  8a5a15                 -mov bl, byte ptr [edx + 0x15]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(21) /* 0x15 */);
    // 004b546b  40                     -inc eax
    (cpu.eax)++;
    // 004b546c  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 004b546e  7501                   -jne 0x4b5471
    if (!cpu.flags.zf)
    {
        goto L_0x004b5471;
    }
    // 004b5470  40                     -inc eax
    (cpu.eax)++;
L_0x004b5471:
    // 004b5471  8b5111                 -mov edx, dword ptr [ecx + 0x11]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(17) /* 0x11 */);
    // 004b5474  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004b5477  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b5479  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b547a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4b547c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b547c);
    // 004b547c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b547d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b547e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b547f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b5480  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b5483  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004b5487  8b7c241c               -mov edi, dword ptr [esp + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004b548b  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004b548f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b5491  8a4815                 -mov cl, byte ptr [eax + 0x15]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(21) /* 0x15 */);
    // 004b5494  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004b5496  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 004b5498  0f85d1000000           -jne 0x4b556f
    if (!cpu.flags.zf)
    {
        goto L_0x004b556f;
    }
L_0x004b549e:
    // 004b549e  8b6c2424               -mov ebp, dword ptr [esp + 0x24]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004b54a2  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp);
    // 004b54a5  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004b54a6  0f85dc000000           -jne 0x4b5588
    if (!cpu.flags.zf)
    {
        goto L_0x004b5588;
    }
L_0x004b54ac:
    // 004b54ac  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b54ae  baffff0000             -mov edx, 0xffff
    cpu.edx = 65535 /*0xffff*/;
    // 004b54b3  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b54b6  0fbf0486               -movsx eax, word ptr [esi + eax*4]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.esi + cpu.eax * 4)));
    // 004b54ba  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b54bc  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004b54bf  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b54c2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b54c4  8d04bd00000000         -lea eax, [edi*4]
    cpu.eax = x86::reg32(cpu.edi * 4);
    // 004b54cb  66891428               -mov word ptr [eax + ebp], dx
    app->getMemory<x86::reg16>(cpu.eax + cpu.ebp * 1) = cpu.dx;
    // 004b54cf  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b54d1  8b549602               -mov edx, dword ptr [esi + edx*4 + 2]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(2) /* 0x2 */ + cpu.edx * 4);
    // 004b54d5  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b54d7  8b7b04                 -mov edi, dword ptr [ebx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b54da  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004b54dd  0fafcf                 -imul ecx, edi
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 004b54e0  0fbf1428               -movsx edx, word ptr [eax + ebp]
    cpu.edx = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.eax + cpu.ebp * 1)));
    // 004b54e4  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004b54e7  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004b54e9  66891428               -mov word ptr [eax + ebp], dx
    app->getMemory<x86::reg16>(cpu.eax + cpu.ebp * 1) = cpu.dx;
    // 004b54ed  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b54ef  b9ffff0000             -mov ecx, 0xffff
    cpu.ecx = 65535 /*0xffff*/;
    // 004b54f4  8b7b04                 -mov edi, dword ptr [ebx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b54f7  8b1496                 -mov edx, dword ptr [esi + edx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + cpu.edx * 4);
    // 004b54fa  29f9                   -sub ecx, edi
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004b54fc  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004b54ff  0fafd1                 -imul edx, ecx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004b5502  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004b5505  6689542802             -mov word ptr [eax + ebp + 2], dx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */ + cpu.ebp * 1) = cpu.dx;
    // 004b550a  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b550c  8b549604               -mov edx, dword ptr [esi + edx*4 + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.edx * 4);
    // 004b5510  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004b5512  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b5515  c1ff10                 -sar edi, 0x10
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (16 /*0x10*/ % 32));
    // 004b5518  0faff9                 -imul edi, ecx
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004b551b  8b1428                 -mov edx, dword ptr [eax + ebp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + cpu.ebp * 1);
    // 004b551e  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004b5521  c1ef10                 -shr edi, 0x10
    cpu.edi >>= 16 /*0x10*/ % 32;
    // 004b5524  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004b5526  6689542802             -mov word ptr [eax + ebp + 2], dx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */ + cpu.ebp * 1) = cpu.dx;
    // 004b552b  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b552d  668b448604             -mov ax, word ptr [esi + eax*4 + 4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.eax * 4);
    // 004b5532  66894310               -mov word ptr [ebx + 0x10], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.ax;
    // 004b5536  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b5538  668b448606             -mov ax, word ptr [esi + eax*4 + 6]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */ + cpu.eax * 4);
    // 004b553d  66894312               -mov word ptr [ebx + 0x12], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(18) /* 0x12 */) = cpu.ax;
    // 004b5541  8b7304                 -mov esi, dword ptr [ebx + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b5544  037308                 -add esi, dword ptr [ebx + 8]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */)));
    // 004b5547  8b3b                   -mov edi, dword ptr [ebx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b5549  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b554b  897304                 -mov dword ptr [ebx + 4], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 004b554e  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b5551  66c743060000           -mov word ptr [ebx + 6], 0
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 004b5557  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b5559  8b4313                 -mov eax, dword ptr [ebx + 0x13]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(19) /* 0x13 */);
    // 004b555c  893b                   -mov dword ptr [ebx], edi
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edi;
    // 004b555e  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004b5561  c6431501               -mov byte ptr [ebx + 0x15], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(21) /* 0x15 */) = 1 /*0x1*/;
    // 004b5565  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004b5567  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b556a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b556b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b556c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b556d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b556e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b556f:
    // 004b556f  8d72fe                 -lea esi, [edx - 2]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(-2) /* -0x2 */);
    // 004b5572  668b5012               -mov dx, word ptr [eax + 0x12]
    cpu.dx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(18) /* 0x12 */);
    // 004b5576  668916                 -mov word ptr [esi], dx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.dx;
    // 004b5579  83ee02                 +sub esi, 2
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
    // 004b557c  668b4010               -mov ax, word ptr [eax + 0x10]
    cpu.ax = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004b5580  668906                 -mov word ptr [esi], ax
    app->getMemory<x86::reg16>(cpu.esi) = cpu.ax;
    // 004b5583  e916ffffff             -jmp 0x4b549e
    goto L_0x004b549e;
L_0x004b5588:
    // 004b5588  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b558b  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b558e  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b5591  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004b5594  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004b5597  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b5598  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004b559b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b559c  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b55a0  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b55a4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b55a5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b55a6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b55a7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b55a8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b55a9  e8864b0000             -call 0x4ba134
    cpu.esp -= 4;
    sub_4ba134(app, cpu);
    if (cpu.terminate) return;
    // 004b55ae  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004b55b1  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004b55b4  c1e810                 +shr eax, 0x10
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
    // 004b55b7  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004b55ba  e9edfeffff             -jmp 0x4b54ac
    goto L_0x004b54ac;
}

/* align: skip 0x90 */
void Application::sub_4b55c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b55c0);
    // 004b55c0  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b55c4  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b55c8  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004b55ca  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4b55cc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b55cc);
    // 004b55cc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b55cd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b55ce  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b55cf  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b55d0  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b55d3  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004b55d7  8b7c241c               -mov edi, dword ptr [esp + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004b55db  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004b55df  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b55e1  8a4815                 -mov cl, byte ptr [eax + 0x15]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(21) /* 0x15 */);
    // 004b55e4  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004b55e6  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 004b55e8  0f8538010000           -jne 0x4b5726
    if (!cpu.flags.zf)
    {
        goto L_0x004b5726;
    }
L_0x004b55ee:
    // 004b55ee  807b1400               +cmp byte ptr [ebx + 0x14], 0
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
    // 004b55f2  7414                   -je 0x4b5608
    if (cpu.flags.zf)
    {
        goto L_0x004b5608;
    }
    // 004b55f4  83ee02                 -sub esi, 2
    (cpu.esi) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004b55f7  668b430e               -mov ax, word ptr [ebx + 0xe]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(14) /* 0xe */);
    // 004b55fb  668906                 -mov word ptr [esi], ax
    app->getMemory<x86::reg16>(cpu.esi) = cpu.ax;
    // 004b55fe  83ee02                 +sub esi, 2
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
    // 004b5601  668b430c               -mov ax, word ptr [ebx + 0xc]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004b5605  668906                 -mov word ptr [esi], ax
    app->getMemory<x86::reg16>(cpu.esi) = cpu.ax;
L_0x004b5608:
    // 004b5608  8b6c2424               -mov ebp, dword ptr [esp + 0x24]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004b560c  c70300000000           -mov dword ptr [ebx], 0
    app->getMemory<x86::reg32>(cpu.ebx) = 0 /*0x0*/;
    // 004b5612  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp);
    // 004b5615  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004b5616  7432                   -je 0x4b564a
    if (cpu.flags.zf)
    {
        goto L_0x004b564a;
    }
    // 004b5618  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b561b  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b561e  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b5621  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004b5624  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004b5627  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b5628  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004b562b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b562c  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b5630  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b5634  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b5635  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b5636  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b5637  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b5638  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b5639  e8f64a0000             -call 0x4ba134
    cpu.esp -= 4;
    sub_4ba134(app, cpu);
    if (cpu.terminate) return;
    // 004b563e  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004b5641  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004b5644  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b5647  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x004b564a:
    // 004b564a  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b564c  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b564f  0fbf1486               -movsx edx, word ptr [esi + eax*4]
    cpu.edx = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.esi + cpu.eax * 4)));
    // 004b5653  b8ffff0000             -mov eax, 0xffff
    cpu.eax = 65535 /*0xffff*/;
    // 004b5658  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b565a  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004b565d  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b5660  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b5662  8d04bd00000000         -lea eax, [edi*4]
    cpu.eax = x86::reg32(cpu.edi * 4);
    // 004b5669  66891428               -mov word ptr [eax + ebp], dx
    app->getMemory<x86::reg16>(cpu.eax + cpu.ebp * 1) = cpu.dx;
    // 004b566d  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b566f  8b549602               -mov edx, dword ptr [esi + edx*4 + 2]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(2) /* 0x2 */ + cpu.edx * 4);
    // 004b5673  8b7b04                 -mov edi, dword ptr [ebx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b5676  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004b5679  0fafd7                 -imul edx, edi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 004b567c  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004b567f  0fbf3c28               -movsx edi, word ptr [eax + ebp]
    cpu.edi = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.eax + cpu.ebp * 1)));
    // 004b5683  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b5685  66893c28               -mov word ptr [eax + ebp], di
    app->getMemory<x86::reg16>(cpu.eax + cpu.ebp * 1) = cpu.di;
    // 004b5689  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b568b  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b568e  8b3c96                 -mov edi, dword ptr [esi + edx*4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + cpu.edx * 4);
    // 004b5691  baffff0000             -mov edx, 0xffff
    cpu.edx = 65535 /*0xffff*/;
    // 004b5696  c1ff10                 -sar edi, 0x10
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (16 /*0x10*/ % 32));
    // 004b5699  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b569b  0faffa                 -imul edi, edx
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004b569e  c1ef10                 -shr edi, 0x10
    cpu.edi >>= 16 /*0x10*/ % 32;
    // 004b56a1  66897c2802             -mov word ptr [eax + ebp + 2], di
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */ + cpu.ebp * 1) = cpu.di;
    // 004b56a6  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b56a8  8b549604               -mov edx, dword ptr [esi + edx*4 + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.edx * 4);
    // 004b56ac  8b7b04                 -mov edi, dword ptr [ebx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b56af  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004b56b2  0fafd7                 -imul edx, edi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 004b56b5  8b3c28                 -mov edi, dword ptr [eax + ebp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + cpu.ebp * 1);
    // 004b56b8  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004b56bb  c1ff10                 -sar edi, 0x10
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (16 /*0x10*/ % 32));
    // 004b56be  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b56c0  66897c2802             -mov word ptr [eax + ebp + 2], di
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */ + cpu.ebp * 1) = cpu.di;
    // 004b56c5  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b56c7  668b448604             -mov ax, word ptr [esi + eax*4 + 4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.eax * 4);
    // 004b56cc  66894310               -mov word ptr [ebx + 0x10], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.ax;
    // 004b56d0  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b56d2  668b448606             -mov ax, word ptr [esi + eax*4 + 6]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */ + cpu.eax * 4);
    // 004b56d7  66894312               -mov word ptr [ebx + 0x12], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(18) /* 0x12 */) = cpu.ax;
    // 004b56db  8b6b04                 -mov ebp, dword ptr [ebx + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b56de  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b56e1  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b56e3  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b56e5  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b56e8  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004b56ea  896b04                 -mov dword ptr [ebx + 4], ebp
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 004b56ed  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b56f0  66c743060000           -mov word ptr [ebx + 6], 0
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 004b56f6  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b56f8  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b56fb  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 004b56fd  39c8                   +cmp eax, ecx
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
    // 004b56ff  723e                   -jb 0x4b573f
    if (cpu.flags.cf)
    {
        goto L_0x004b573f;
    }
    // 004b5701  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b5703  c6431401               -mov byte ptr [ebx + 0x14], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(20) /* 0x14 */) = 1 /*0x1*/;
    // 004b5707  668b0486               -mov ax, word ptr [esi + eax*4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.eax * 4);
    // 004b570b  6689430c               -mov word ptr [ebx + 0xc], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.ax;
    // 004b570f  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b5711  668b448602             -mov ax, word ptr [esi + eax*4 + 2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(2) /* 0x2 */ + cpu.eax * 4);
    // 004b5716  6689430e               -mov word ptr [ebx + 0xe], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(14) /* 0xe */) = cpu.ax;
    // 004b571a  c6431501               -mov byte ptr [ebx + 0x15], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(21) /* 0x15 */) = 1 /*0x1*/;
    // 004b571e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b5721  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5722  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5723  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5724  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5725  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b5726:
    // 004b5726  8d72fe                 -lea esi, [edx - 2]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(-2) /* -0x2 */);
    // 004b5729  668b5012               -mov dx, word ptr [eax + 0x12]
    cpu.dx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(18) /* 0x12 */);
    // 004b572d  668916                 -mov word ptr [esi], dx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.dx;
    // 004b5730  83ee02                 +sub esi, 2
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
    // 004b5733  668b4010               -mov ax, word ptr [eax + 0x10]
    cpu.ax = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004b5737  668906                 -mov word ptr [esi], ax
    app->getMemory<x86::reg16>(cpu.esi) = cpu.ax;
    // 004b573a  e9affeffff             -jmp 0x4b55ee
    goto L_0x004b55ee;
L_0x004b573f:
    // 004b573f  c6431400               -mov byte ptr [ebx + 0x14], 0
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 004b5743  c6431501               -mov byte ptr [ebx + 0x15], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(21) /* 0x15 */) = 1 /*0x1*/;
    // 004b5747  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b574a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b574b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b574c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b574d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b574e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4b5750(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b5750);
    // 004b5750  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b5751  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b5752  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b5756  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b575a  8b5908                 -mov ebx, dword ptr [ecx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004b575d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b575f  81fb00000100           +cmp ebx, 0x10000
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
    // 004b5765  732c                   -jae 0x4b5793
    if (!cpu.flags.cf)
    {
        goto L_0x004b5793;
    }
    // 004b5767  81fa00000100           +cmp edx, 0x10000
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
    // 004b576d  7324                   -jae 0x4b5793
    if (!cpu.flags.cf)
    {
        goto L_0x004b5793;
    }
L_0x004b576f:
    // 004b576f  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004b5772  81fa00000100           +cmp edx, 0x10000
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
    // 004b5778  724b                   -jb 0x4b57c5
    if (cpu.flags.cf)
    {
        goto L_0x004b57c5;
    }
    // 004b577a  7660                   -jbe 0x4b57dc
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b57dc;
    }
    // 004b577c  8b501c                 -mov edx, dword ptr [eax + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004b577f  c70200544b00           -mov dword ptr [edx], 0x4b5400
    app->getMemory<x86::reg32>(cpu.edx) = 4936704 /*0x4b5400*/;
    // 004b5785  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004b5788  c7007c544b00           -mov dword ptr [eax], 0x4b547c
    app->getMemory<x86::reg32>(cpu.eax) = 4936828 /*0x4b547c*/;
    // 004b578e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b5790  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5791  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5792  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b5793:
    // 004b5793  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004b5796  39f2                   +cmp edx, esi
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
    // 004b5798  74d5                   -je 0x4b576f
    if (cpu.flags.zf)
    {
        goto L_0x004b576f;
    }
    // 004b579a  81fe00000100           +cmp esi, 0x10000
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
    // 004b57a0  7608                   -jbe 0x4b57aa
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b57aa;
    }
    // 004b57a2  81fa00000100           +cmp edx, 0x10000
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
    // 004b57a8  77c5                   -ja 0x4b576f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004b576f;
    }
L_0x004b57aa:
    // 004b57aa  c6401400               -mov byte ptr [eax + 0x14], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 004b57ae  c6401500               -mov byte ptr [eax + 0x15], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(21) /* 0x15 */) = 0 /*0x0*/;
    // 004b57b2  c6401600               -mov byte ptr [eax + 0x16], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(22) /* 0x16 */) = 0 /*0x0*/;
    // 004b57b6  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004b57bd  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004b57c3  ebaa                   -jmp 0x4b576f
    goto L_0x004b576f;
L_0x004b57c5:
    // 004b57c5  8b501c                 -mov edx, dword ptr [eax + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004b57c8  c70250544b00           -mov dword ptr [edx], 0x4b5450
    app->getMemory<x86::reg32>(cpu.edx) = 4936784 /*0x4b5450*/;
    // 004b57ce  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004b57d1  c700cc554b00           -mov dword ptr [eax], 0x4b55cc
    app->getMemory<x86::reg32>(cpu.eax) = 4937164 /*0x4b55cc*/;
    // 004b57d7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b57d9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b57da  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b57db  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b57dc:
    // 004b57dc  8b501c                 -mov edx, dword ptr [eax + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004b57df  c70248544b00           -mov dword ptr [edx], 0x4b5448
    app->getMemory<x86::reg32>(cpu.edx) = 4936776 /*0x4b5448*/;
    // 004b57e5  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004b57e8  c700c0554b00           -mov dword ptr [eax], 0x4b55c0
    app->getMemory<x86::reg32>(cpu.eax) = 4937152 /*0x4b55c0*/;
    // 004b57ee  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b57f0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b57f1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b57f2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4b57f4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b57f4);
    // 004b57f4  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b57f8  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004b57fe  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004b5805  c6401400               -mov byte ptr [eax + 0x14], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 004b5809  c6401500               -mov byte ptr [eax + 0x15], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(21) /* 0x15 */) = 0 /*0x0*/;
    // 004b580d  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b5811  c6401600               -mov byte ptr [eax + 0x16], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(22) /* 0x16 */) = 0 /*0x0*/;
    // 004b5815  895018                 -mov dword ptr [eax + 0x18], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004b5818  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b581c  89501c                 -mov dword ptr [eax + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004b581f  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b5823  895020                 -mov dword ptr [eax + 0x20], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 004b5826  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004b5829  c70050574b00           -mov dword ptr [eax], 0x4b5750
    app->getMemory<x86::reg32>(cpu.eax) = 4937552 /*0x4b5750*/;
    // 004b582f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b5831  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4b5834(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b5834);
    // 004b5834  0f77                   -emms 
    cpu.mmx.init();
    // 004b5836  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4b5840(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b5840);
    // 004b5840  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b5841  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b5842  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b5843  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b5844  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b5845  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b5846  833dc8894d0000         +cmp dword ptr [0x4d89c8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5081544) /* 0x4d89c8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b584d  744b                   -je 0x4b589a
    if (cpu.flags.zf)
    {
        goto L_0x004b589a;
    }
    // 004b584f  bad0a14b00             -mov edx, 0x4ba1d0
    cpu.edx = 4956624 /*0x4ba1d0*/;
    // 004b5854  b9f0a14b00             -mov ecx, 0x4ba1f0
    cpu.ecx = 4956656 /*0x4ba1f0*/;
    // 004b5859  bb20a24b00             -mov ebx, 0x4ba220
    cpu.ebx = 4956704 /*0x4ba220*/;
    // 004b585e  be40a24b00             -mov esi, 0x4ba240
    cpu.esi = 4956736 /*0x4ba240*/;
    // 004b5863  bf60a24b00             -mov edi, 0x4ba260
    cpu.edi = 4956768 /*0x4ba260*/;
    // 004b5868  bd90a24b00             -mov ebp, 0x4ba290
    cpu.ebp = 4956816 /*0x4ba290*/;
    // 004b586d  8915d8bb4d00           -mov dword ptr [0x4dbbd8], edx
    app->getMemory<x86::reg32>(x86::reg32(5094360) /* 0x4dbbd8 */) = cpu.edx;
    // 004b5873  890ddcbb4d00           -mov dword ptr [0x4dbbdc], ecx
    app->getMemory<x86::reg32>(x86::reg32(5094364) /* 0x4dbbdc */) = cpu.ecx;
    // 004b5879  891de0bb4d00           -mov dword ptr [0x4dbbe0], ebx
    app->getMemory<x86::reg32>(x86::reg32(5094368) /* 0x4dbbe0 */) = cpu.ebx;
    // 004b587f  8935e4bb4d00           -mov dword ptr [0x4dbbe4], esi
    app->getMemory<x86::reg32>(x86::reg32(5094372) /* 0x4dbbe4 */) = cpu.esi;
    // 004b5885  893de8bb4d00           -mov dword ptr [0x4dbbe8], edi
    app->getMemory<x86::reg32>(x86::reg32(5094376) /* 0x4dbbe8 */) = cpu.edi;
    // 004b588b  892decbb4d00           -mov dword ptr [0x4dbbec], ebp
    app->getMemory<x86::reg32>(x86::reg32(5094380) /* 0x4dbbec */) = cpu.ebp;
    // 004b5891  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b5893  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5894  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5895  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5896  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5897  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5898  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5899  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b589a:
    // 004b589a  e8114a0000             -call 0x4ba2b0
    cpu.esp -= 4;
    sub_4ba2b0(app, cpu);
    if (cpu.terminate) return;
    // 004b589f  b9e0a24b00             -mov ecx, 0x4ba2e0
    cpu.ecx = 4956896 /*0x4ba2e0*/;
    // 004b58a4  bb00a34b00             -mov ebx, 0x4ba300
    cpu.ebx = 4956928 /*0x4ba300*/;
    // 004b58a9  be30a34b00             -mov esi, 0x4ba330
    cpu.esi = 4956976 /*0x4ba330*/;
    // 004b58ae  bf50a34b00             -mov edi, 0x4ba350
    cpu.edi = 4957008 /*0x4ba350*/;
    // 004b58b3  bd70a34b00             -mov ebp, 0x4ba370
    cpu.ebp = 4957040 /*0x4ba370*/;
    // 004b58b8  b8a0a34b00             -mov eax, 0x4ba3a0
    cpu.eax = 4957088 /*0x4ba3a0*/;
    // 004b58bd  890dd8bb4d00           -mov dword ptr [0x4dbbd8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5094360) /* 0x4dbbd8 */) = cpu.ecx;
    // 004b58c3  891ddcbb4d00           -mov dword ptr [0x4dbbdc], ebx
    app->getMemory<x86::reg32>(x86::reg32(5094364) /* 0x4dbbdc */) = cpu.ebx;
    // 004b58c9  8935e0bb4d00           -mov dword ptr [0x4dbbe0], esi
    app->getMemory<x86::reg32>(x86::reg32(5094368) /* 0x4dbbe0 */) = cpu.esi;
    // 004b58cf  893de4bb4d00           -mov dword ptr [0x4dbbe4], edi
    app->getMemory<x86::reg32>(x86::reg32(5094372) /* 0x4dbbe4 */) = cpu.edi;
    // 004b58d5  892de8bb4d00           -mov dword ptr [0x4dbbe8], ebp
    app->getMemory<x86::reg32>(x86::reg32(5094376) /* 0x4dbbe8 */) = cpu.ebp;
    // 004b58db  a3ecbb4d00             -mov dword ptr [0x4dbbec], eax
    app->getMemory<x86::reg32>(x86::reg32(5094380) /* 0x4dbbec */) = cpu.eax;
    // 004b58e0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b58e2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b58e3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b58e4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b58e5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b58e6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b58e7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b58e8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4b58f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b58f0);
    // 004b58f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b58f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b58f2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b58f3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b58f4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b58f5  833dc8894d0000         +cmp dword ptr [0x4d89c8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5081544) /* 0x4d89c8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b58fc  744c                   -je 0x4b594a
    if (cpu.flags.zf)
    {
        goto L_0x004b594a;
    }
    // 004b58fe  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b58ff  bac0a34b00             -mov edx, 0x4ba3c0
    cpu.edx = 4957120 /*0x4ba3c0*/;
    // 004b5904  b9e0a34b00             -mov ecx, 0x4ba3e0
    cpu.ecx = 4957152 /*0x4ba3e0*/;
    // 004b5909  bb10a44b00             -mov ebx, 0x4ba410
    cpu.ebx = 4957200 /*0x4ba410*/;
    // 004b590e  be30a44b00             -mov esi, 0x4ba430
    cpu.esi = 4957232 /*0x4ba430*/;
    // 004b5913  bf50a44b00             -mov edi, 0x4ba450
    cpu.edi = 4957264 /*0x4ba450*/;
    // 004b5918  bd80a44b00             -mov ebp, 0x4ba480
    cpu.ebp = 4957312 /*0x4ba480*/;
    // 004b591d  8915f0bb4d00           -mov dword ptr [0x4dbbf0], edx
    app->getMemory<x86::reg32>(x86::reg32(5094384) /* 0x4dbbf0 */) = cpu.edx;
    // 004b5923  890df4bb4d00           -mov dword ptr [0x4dbbf4], ecx
    app->getMemory<x86::reg32>(x86::reg32(5094388) /* 0x4dbbf4 */) = cpu.ecx;
    // 004b5929  891df8bb4d00           -mov dword ptr [0x4dbbf8], ebx
    app->getMemory<x86::reg32>(x86::reg32(5094392) /* 0x4dbbf8 */) = cpu.ebx;
    // 004b592f  8935fcbb4d00           -mov dword ptr [0x4dbbfc], esi
    app->getMemory<x86::reg32>(x86::reg32(5094396) /* 0x4dbbfc */) = cpu.esi;
    // 004b5935  893d00bc4d00           -mov dword ptr [0x4dbc00], edi
    app->getMemory<x86::reg32>(x86::reg32(5094400) /* 0x4dbc00 */) = cpu.edi;
    // 004b593b  892d04bc4d00           -mov dword ptr [0x4dbc04], ebp
    app->getMemory<x86::reg32>(x86::reg32(5094404) /* 0x4dbc04 */) = cpu.ebp;
    // 004b5941  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5942  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b5944  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5945  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5946  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5947  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5948  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5949  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b594a:
    // 004b594a  b9a0a44b00             -mov ecx, 0x4ba4a0
    cpu.ecx = 4957344 /*0x4ba4a0*/;
    // 004b594f  bbc0a44b00             -mov ebx, 0x4ba4c0
    cpu.ebx = 4957376 /*0x4ba4c0*/;
    // 004b5954  bef0a44b00             -mov esi, 0x4ba4f0
    cpu.esi = 4957424 /*0x4ba4f0*/;
    // 004b5959  bf10a54b00             -mov edi, 0x4ba510
    cpu.edi = 4957456 /*0x4ba510*/;
    // 004b595e  bd30a54b00             -mov ebp, 0x4ba530
    cpu.ebp = 4957488 /*0x4ba530*/;
    // 004b5963  b860a54b00             -mov eax, 0x4ba560
    cpu.eax = 4957536 /*0x4ba560*/;
    // 004b5968  890df0bb4d00           -mov dword ptr [0x4dbbf0], ecx
    app->getMemory<x86::reg32>(x86::reg32(5094384) /* 0x4dbbf0 */) = cpu.ecx;
    // 004b596e  891df4bb4d00           -mov dword ptr [0x4dbbf4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5094388) /* 0x4dbbf4 */) = cpu.ebx;
    // 004b5974  8935f8bb4d00           -mov dword ptr [0x4dbbf8], esi
    app->getMemory<x86::reg32>(x86::reg32(5094392) /* 0x4dbbf8 */) = cpu.esi;
    // 004b597a  893dfcbb4d00           -mov dword ptr [0x4dbbfc], edi
    app->getMemory<x86::reg32>(x86::reg32(5094396) /* 0x4dbbfc */) = cpu.edi;
    // 004b5980  892d00bc4d00           -mov dword ptr [0x4dbc00], ebp
    app->getMemory<x86::reg32>(x86::reg32(5094400) /* 0x4dbc00 */) = cpu.ebp;
    // 004b5986  a304bc4d00             -mov dword ptr [0x4dbc04], eax
    app->getMemory<x86::reg32>(x86::reg32(5094404) /* 0x4dbc04 */) = cpu.eax;
    // 004b598b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b598d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b598e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b598f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5990  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5991  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5992  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4b59a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b59a0);
    // 004b59a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b59a1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b59a2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b59a3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b59a4  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b59a7  bd40000000             -mov ebp, 0x40
    cpu.ebp = 64 /*0x40*/;
    // 004b59ac  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004b59ae:
    // 004b59ae  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b59b0  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004b59b2  88d9                   -mov cl, bl
    cpu.cl = cpu.bl;
    // 004b59b4  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b59b6  c1e006                 -shl eax, 6
    cpu.eax <<= 6 /*0x6*/ % 32;
L_0x004b59b9:
    // 004b59b9  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004b59bb  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 004b59be  d3fe                   -sar esi, cl
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (cpu.cl % 32));
    // 004b59c0  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b59c3  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 004b59c6  81c200000010           -add edx, 0x10000000
    (cpu.edx) += x86::reg32(x86::sreg32(268435456 /*0x10000000*/));
    // 004b59cc  db0424                 -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 004b59cf  d99820715b00           -fstp dword ptr [eax + 0x5b7120]
    app->getMemory<float>(cpu.eax + x86::reg32(5992736) /* 0x5b7120 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b59d5  39f8                   +cmp eax, edi
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
    // 004b59d7  75e0                   -jne 0x4b59b9
    if (!cpu.flags.zf)
    {
        goto L_0x004b59b9;
    }
    // 004b59d9  43                     -inc ebx
    (cpu.ebx)++;
    // 004b59da  83c540                 -add ebp, 0x40
    (cpu.ebp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004b59dd  83fb0d                 +cmp ebx, 0xd
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
    // 004b59e0  7ccc                   -jl 0x4b59ae
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b59ae;
    }
    // 004b59e2  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b59e5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b59e6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b59e7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b59e8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b59e9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4b59ec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b59ec);
    // 004b59ec  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b59ed  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b59ee  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b59ef  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b59f0  bd40000000             -mov ebp, 0x40
    cpu.ebp = 64 /*0x40*/;
    // 004b59f5  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004b59f7:
    // 004b59f7  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b59f9  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004b59fb  88d9                   -mov cl, bl
    cpu.cl = cpu.bl;
    // 004b59fd  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b59ff  c1e006                 -shl eax, 6
    cpu.eax <<= 6 /*0x6*/ % 32;
L_0x004b5a02:
    // 004b5a02  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004b5a04  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 004b5a07  d3fe                   -sar esi, cl
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (cpu.cl % 32));
    // 004b5a09  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b5a0c  c1e608                 -shl esi, 8
    cpu.esi <<= 8 /*0x8*/ % 32;
    // 004b5a0f  81c200000010           -add edx, 0x10000000
    (cpu.edx) += x86::reg32(x86::sreg32(268435456 /*0x10000000*/));
    // 004b5a15  89b020755b00           -mov dword ptr [eax + 0x5b7520], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5993760) /* 0x5b7520 */) = cpu.esi;
    // 004b5a1b  39f8                   +cmp eax, edi
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
    // 004b5a1d  75e3                   -jne 0x4b5a02
    if (!cpu.flags.zf)
    {
        goto L_0x004b5a02;
    }
    // 004b5a1f  43                     -inc ebx
    (cpu.ebx)++;
    // 004b5a20  83c540                 -add ebp, 0x40
    (cpu.ebp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004b5a23  83fb0d                 +cmp ebx, 0xd
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
    // 004b5a26  7ccf                   -jl 0x4b59f7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b59f7;
    }
    // 004b5a28  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5a29  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5a2a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5a2b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5a2c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4b5a30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b5a30);
    // 004b5a30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b5a31  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b5a32  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b5a33  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b5a34  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b5a35  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b5a36  833dc8894d0000         +cmp dword ptr [0x4d89c8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5081544) /* 0x4d89c8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b5a3d  7450                   -je 0x4b5a8f
    if (cpu.flags.zf)
    {
        goto L_0x004b5a8f;
    }
    // 004b5a3f  e8a8ffffff             -call 0x4b59ec
    cpu.esp -= 4;
    sub_4b59ec(app, cpu);
    if (cpu.terminate) return;
    // 004b5a44  ba08a74b00             -mov edx, 0x4ba708
    cpu.edx = 4957960 /*0x4ba708*/;
    // 004b5a49  b958ab4b00             -mov ecx, 0x4bab58
    cpu.ecx = 4959064 /*0x4bab58*/;
    // 004b5a4e  bba0ad4b00             -mov ebx, 0x4bada0
    cpu.ebx = 4959648 /*0x4bada0*/;
    // 004b5a53  beb4af4b00             -mov esi, 0x4bafb4
    cpu.esi = 4960180 /*0x4bafb4*/;
    // 004b5a58  bfb8b44b00             -mov edi, 0x4bb4b8
    cpu.edi = 4961464 /*0x4bb4b8*/;
    // 004b5a5d  bdccb64b00             -mov ebp, 0x4bb6cc
    cpu.ebp = 4961996 /*0x4bb6cc*/;
    // 004b5a62  891508bc4d00           -mov dword ptr [0x4dbc08], edx
    app->getMemory<x86::reg32>(x86::reg32(5094408) /* 0x4dbc08 */) = cpu.edx;
    // 004b5a68  890d0cbc4d00           -mov dword ptr [0x4dbc0c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5094412) /* 0x4dbc0c */) = cpu.ecx;
    // 004b5a6e  891d10bc4d00           -mov dword ptr [0x4dbc10], ebx
    app->getMemory<x86::reg32>(x86::reg32(5094416) /* 0x4dbc10 */) = cpu.ebx;
    // 004b5a74  893514bc4d00           -mov dword ptr [0x4dbc14], esi
    app->getMemory<x86::reg32>(x86::reg32(5094420) /* 0x4dbc14 */) = cpu.esi;
    // 004b5a7a  893d18bc4d00           -mov dword ptr [0x4dbc18], edi
    app->getMemory<x86::reg32>(x86::reg32(5094424) /* 0x4dbc18 */) = cpu.edi;
    // 004b5a80  892d1cbc4d00           -mov dword ptr [0x4dbc1c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5094428) /* 0x4dbc1c */) = cpu.ebp;
    // 004b5a86  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b5a88  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5a89  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5a8a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5a8b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5a8c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5a8d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5a8e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b5a8f:
    // 004b5a8f  e80cffffff             -call 0x4b59a0
    cpu.esp -= 4;
    sub_4b59a0(app, cpu);
    if (cpu.terminate) return;
    // 004b5a94  b9a8b84b00             -mov ecx, 0x4bb8a8
    cpu.ecx = 4962472 /*0x4bb8a8*/;
    // 004b5a99  bbdcbc4b00             -mov ebx, 0x4bbcdc
    cpu.ebx = 4963548 /*0x4bbcdc*/;
    // 004b5a9e  bef4be4b00             -mov esi, 0x4bbef4
    cpu.esi = 4964084 /*0x4bbef4*/;
    // 004b5aa3  bfe8c04b00             -mov edi, 0x4bc0e8
    cpu.edi = 4964584 /*0x4bc0e8*/;
    // 004b5aa8  bdc4c54b00             -mov ebp, 0x4bc5c4
    cpu.ebp = 4965828 /*0x4bc5c4*/;
    // 004b5aad  b8d0c74b00             -mov eax, 0x4bc7d0
    cpu.eax = 4966352 /*0x4bc7d0*/;
    // 004b5ab2  890d08bc4d00           -mov dword ptr [0x4dbc08], ecx
    app->getMemory<x86::reg32>(x86::reg32(5094408) /* 0x4dbc08 */) = cpu.ecx;
    // 004b5ab8  891d0cbc4d00           -mov dword ptr [0x4dbc0c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5094412) /* 0x4dbc0c */) = cpu.ebx;
    // 004b5abe  893510bc4d00           -mov dword ptr [0x4dbc10], esi
    app->getMemory<x86::reg32>(x86::reg32(5094416) /* 0x4dbc10 */) = cpu.esi;
    // 004b5ac4  893d14bc4d00           -mov dword ptr [0x4dbc14], edi
    app->getMemory<x86::reg32>(x86::reg32(5094420) /* 0x4dbc14 */) = cpu.edi;
    // 004b5aca  892d18bc4d00           -mov dword ptr [0x4dbc18], ebp
    app->getMemory<x86::reg32>(x86::reg32(5094424) /* 0x4dbc18 */) = cpu.ebp;
    // 004b5ad0  a31cbc4d00             -mov dword ptr [0x4dbc1c], eax
    app->getMemory<x86::reg32>(x86::reg32(5094428) /* 0x4dbc1c */) = cpu.eax;
    // 004b5ad5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b5ad7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5ad8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5ad9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5ada  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5adb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5adc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5add  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4b5ae0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b5ae0);
    // 004b5ae0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b5ae1  833dc8894d0000         +cmp dword ptr [0x4d89c8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5081544) /* 0x4d89c8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b5ae8  741f                   -je 0x4b5b09
    if (cpu.flags.zf)
    {
        goto L_0x004b5b09;
    }
    // 004b5aea  bfa4c94b00             -mov edi, 0x4bc9a4
    cpu.edi = 4966820 /*0x4bc9a4*/;
    // 004b5aef  b878cb4b00             -mov eax, 0x4bcb78
    cpu.eax = 4967288 /*0x4bcb78*/;
    // 004b5af4  893d38bc4d00           -mov dword ptr [0x4dbc38], edi
    app->getMemory<x86::reg32>(x86::reg32(5094456) /* 0x4dbc38 */) = cpu.edi;
    // 004b5afa  893d44bc4d00           -mov dword ptr [0x4dbc44], edi
    app->getMemory<x86::reg32>(x86::reg32(5094468) /* 0x4dbc44 */) = cpu.edi;
    // 004b5b00  a34cbc4d00             -mov dword ptr [0x4dbc4c], eax
    app->getMemory<x86::reg32>(x86::reg32(5094476) /* 0x4dbc4c */) = cpu.eax;
    // 004b5b05  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b5b07  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5b08  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b5b09:
    // 004b5b09  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b5b0a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b5b0b  b918cd4b00             -mov ecx, 0x4bcd18
    cpu.ecx = 4967704 /*0x4bcd18*/;
    // 004b5b10  be20cf4b00             -mov esi, 0x4bcf20
    cpu.esi = 4968224 /*0x4bcf20*/;
    // 004b5b15  890d38bc4d00           -mov dword ptr [0x4dbc38], ecx
    app->getMemory<x86::reg32>(x86::reg32(5094456) /* 0x4dbc38 */) = cpu.ecx;
    // 004b5b1b  890d44bc4d00           -mov dword ptr [0x4dbc44], ecx
    app->getMemory<x86::reg32>(x86::reg32(5094468) /* 0x4dbc44 */) = cpu.ecx;
    // 004b5b21  89354cbc4d00           -mov dword ptr [0x4dbc4c], esi
    app->getMemory<x86::reg32>(x86::reg32(5094476) /* 0x4dbc4c */) = cpu.esi;
    // 004b5b27  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5b28  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5b29  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b5b2b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5b2c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_4b5b30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b5b30);
    // 004b5b30  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b5b31  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b5b33  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004b5b34  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b5b37  8b7d0c                 -mov edi, dword ptr [ebp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b5b3a  8b15902b5b00           -mov edx, dword ptr [0x5b2b90]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5974928) /* 0x5b2b90 */);
    // 004b5b40  a130d25a00             -mov eax, dword ptr [0x5ad230]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5952048) /* 0x5ad230 */);
    // 004b5b45  8b1d502b5b00           -mov ebx, dword ptr [0x5b2b50]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5974864) /* 0x5b2b50 */);
    // 004b5b4b  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b5b4e  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004b5b51:
    // 004b5b51  3bc2                   +cmp eax, edx
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
    // 004b5b53  7c05                   -jl 0x4b5b5a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b5b5a;
    }
    // 004b5b55  a1602b5b00             -mov eax, dword ptr [0x5b2b60]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5974880) /* 0x5b2b60 */);
L_0x004b5b5a:
    // 004b5b5a  3bda                   +cmp ebx, edx
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
    // 004b5b5c  7c06                   -jl 0x4b5b64
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b5b64;
    }
    // 004b5b5e  8b1d602b5b00           -mov ebx, dword ptr [0x5b2b60]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5974880) /* 0x5b2b60 */);
L_0x004b5b64:
    // 004b5b64  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004b5b66  d805802b5b00           -fadd dword ptr [0x5b2b80]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5974912) /* 0x5b2b80 */));
    // 004b5b6c  d903                   -fld dword ptr [ebx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebx)));
    // 004b5b6e  a330d25a00             -mov dword ptr [0x5ad230], eax
    app->getMemory<x86::reg32>(x86::reg32(5952048) /* 0x5ad230 */) = cpu.eax;
    // 004b5b73  891d502b5b00           -mov dword ptr [0x5b2b50], ebx
    app->getMemory<x86::reg32>(x86::reg32(5974864) /* 0x5b2b50 */) = cpu.ebx;
    // 004b5b79  d80ddcc84d00           -fmul dword ptr [0x4dc8dc]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5097692) /* 0x4dc8dc */));
    // 004b5b7f  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b5b81  d910                   -fst dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    // 004b5b83  d80ddcc84d00           -fmul dword ptr [0x4dc8dc]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5097692) /* 0x4dc8dc */));
    // 004b5b89  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b5b8b  d91d802b5b00           -fstp dword ptr [0x5b2b80]
    app->getMemory<float>(x86::reg32(5974912) /* 0x5b2b80 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b5b91  d82b                   -fsubr dword ptr [ebx]
    cpu.fpu.st(0) = x86::Float(app->getMemory<float>(cpu.ebx)) - cpu.fpu.st(0);
    // 004b5b93  8b15942b5b00           -mov edx, dword ptr [0x5b2b94]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5974932) /* 0x5b2b94 */);
    // 004b5b99  a134d25a00             -mov eax, dword ptr [0x5ad234]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5952052) /* 0x5ad234 */);
    // 004b5b9e  8b1d542b5b00           -mov ebx, dword ptr [0x5b2b54]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5974868) /* 0x5b2b54 */);
    // 004b5ba4  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b5ba7  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b5baa  3bc2                   +cmp eax, edx
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
    // 004b5bac  7c05                   -jl 0x4b5bb3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b5bb3;
    }
    // 004b5bae  a1642b5b00             -mov eax, dword ptr [0x5b2b64]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5974884) /* 0x5b2b64 */);
L_0x004b5bb3:
    // 004b5bb3  3bda                   +cmp ebx, edx
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
    // 004b5bb5  7c06                   -jl 0x4b5bbd
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b5bbd;
    }
    // 004b5bb7  8b1d642b5b00           -mov ebx, dword ptr [0x5b2b64]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5974884) /* 0x5b2b64 */);
L_0x004b5bbd:
    // 004b5bbd  d805842b5b00           -fadd dword ptr [0x5b2b84]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5974916) /* 0x5b2b84 */));
    // 004b5bc3  d903                   -fld dword ptr [ebx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebx)));
    // 004b5bc5  a334d25a00             -mov dword ptr [0x5ad234], eax
    app->getMemory<x86::reg32>(x86::reg32(5952052) /* 0x5ad234 */) = cpu.eax;
    // 004b5bca  891d542b5b00           -mov dword ptr [0x5b2b54], ebx
    app->getMemory<x86::reg32>(x86::reg32(5974868) /* 0x5b2b54 */) = cpu.ebx;
    // 004b5bd0  d80de0c84d00           -fmul dword ptr [0x4dc8e0]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5097696) /* 0x4dc8e0 */));
    // 004b5bd6  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b5bd8  d910                   -fst dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    // 004b5bda  d80de0c84d00           -fmul dword ptr [0x4dc8e0]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5097696) /* 0x4dc8e0 */));
    // 004b5be0  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b5be2  d91d842b5b00           -fstp dword ptr [0x5b2b84]
    app->getMemory<float>(x86::reg32(5974916) /* 0x5b2b84 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b5be8  d82b                   -fsubr dword ptr [ebx]
    cpu.fpu.st(0) = x86::Float(app->getMemory<float>(cpu.ebx)) - cpu.fpu.st(0);
    // 004b5bea  d905b0c84d00           -fld dword ptr [0x4dc8b0]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5097648) /* 0x4dc8b0 */)));
    // 004b5bf0  d80dc0c84d00           -fmul dword ptr [0x4dc8c0]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5097664) /* 0x4dc8c0 */));
    // 004b5bf6  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b5bf8  d80dd0c84d00           -fmul dword ptr [0x4dc8d0]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5097680) /* 0x4dc8d0 */));
    // 004b5bfe  a138d25a00             -mov eax, dword ptr [0x5ad238]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5952056) /* 0x5ad238 */);
    // 004b5c03  8b1d582b5b00           -mov ebx, dword ptr [0x5b2b58]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5974872) /* 0x5b2b58 */);
    // 004b5c09  8b15982b5b00           -mov edx, dword ptr [0x5b2b98]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5974936) /* 0x5b2b98 */);
    // 004b5c0f  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b5c11  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b5c14  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b5c17  3bc2                   +cmp eax, edx
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
    // 004b5c19  7c05                   -jl 0x4b5c20
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b5c20;
    }
    // 004b5c1b  a1682b5b00             -mov eax, dword ptr [0x5b2b68]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5974888) /* 0x5b2b68 */);
L_0x004b5c20:
    // 004b5c20  3bda                   +cmp ebx, edx
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
    // 004b5c22  7c06                   -jl 0x4b5c2a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b5c2a;
    }
    // 004b5c24  8b1d682b5b00           -mov ebx, dword ptr [0x5b2b68]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5974888) /* 0x5b2b68 */);
L_0x004b5c2a:
    // 004b5c2a  d915b0c84d00           -fst dword ptr [0x4dc8b0]
    app->getMemory<float>(x86::reg32(5097648) /* 0x4dc8b0 */) = float(cpu.fpu.st(0));
    // 004b5c30  d805882b5b00           -fadd dword ptr [0x5b2b88]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5974920) /* 0x5b2b88 */));
    // 004b5c36  d903                   -fld dword ptr [ebx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebx)));
    // 004b5c38  a338d25a00             -mov dword ptr [0x5ad238], eax
    app->getMemory<x86::reg32>(x86::reg32(5952056) /* 0x5ad238 */) = cpu.eax;
    // 004b5c3d  891d582b5b00           -mov dword ptr [0x5b2b58], ebx
    app->getMemory<x86::reg32>(x86::reg32(5974872) /* 0x5b2b58 */) = cpu.ebx;
    // 004b5c43  d80de4c84d00           -fmul dword ptr [0x4dc8e4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5097700) /* 0x4dc8e4 */));
    // 004b5c49  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b5c4b  d910                   -fst dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    // 004b5c4d  d80de4c84d00           -fmul dword ptr [0x4dc8e4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5097700) /* 0x4dc8e4 */));
    // 004b5c53  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b5c55  d91d882b5b00           -fstp dword ptr [0x5b2b88]
    app->getMemory<float>(x86::reg32(5974920) /* 0x5b2b88 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b5c5b  d82b                   -fsubr dword ptr [ebx]
    cpu.fpu.st(0) = x86::Float(app->getMemory<float>(cpu.ebx)) - cpu.fpu.st(0);
    // 004b5c5d  8b159c2b5b00           -mov edx, dword ptr [0x5b2b9c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5974940) /* 0x5b2b9c */);
    // 004b5c63  a13cd25a00             -mov eax, dword ptr [0x5ad23c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5952060) /* 0x5ad23c */);
    // 004b5c68  8b1d5c2b5b00           -mov ebx, dword ptr [0x5b2b5c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5974876) /* 0x5b2b5c */);
    // 004b5c6e  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b5c71  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b5c74  3bc2                   +cmp eax, edx
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
    // 004b5c76  7c05                   -jl 0x4b5c7d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b5c7d;
    }
    // 004b5c78  a16c2b5b00             -mov eax, dword ptr [0x5b2b6c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5974892) /* 0x5b2b6c */);
L_0x004b5c7d:
    // 004b5c7d  3bda                   +cmp ebx, edx
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
    // 004b5c7f  7c06                   -jl 0x4b5c87
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b5c87;
    }
    // 004b5c81  8b1d6c2b5b00           -mov ebx, dword ptr [0x5b2b6c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5974892) /* 0x5b2b6c */);
L_0x004b5c87:
    // 004b5c87  d8058c2b5b00           -fadd dword ptr [0x5b2b8c]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5974924) /* 0x5b2b8c */));
    // 004b5c8d  d903                   -fld dword ptr [ebx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebx)));
    // 004b5c8f  a33cd25a00             -mov dword ptr [0x5ad23c], eax
    app->getMemory<x86::reg32>(x86::reg32(5952060) /* 0x5ad23c */) = cpu.eax;
    // 004b5c94  891d5c2b5b00           -mov dword ptr [0x5b2b5c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5974876) /* 0x5b2b5c */) = cpu.ebx;
    // 004b5c9a  d80de8c84d00           -fmul dword ptr [0x4dc8e8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5097704) /* 0x4dc8e8 */));
    // 004b5ca0  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b5ca2  d910                   -fst dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    // 004b5ca4  d80de8c84d00           -fmul dword ptr [0x4dc8e8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5097704) /* 0x4dc8e8 */));
    // 004b5caa  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b5cac  d91d8c2b5b00           -fstp dword ptr [0x5b2b8c]
    app->getMemory<float>(x86::reg32(5974924) /* 0x5b2b8c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b5cb2  d82b                   -fsubr dword ptr [ebx]
    cpu.fpu.st(0) = x86::Float(app->getMemory<float>(cpu.ebx)) - cpu.fpu.st(0);
    // 004b5cb4  d905b8c84d00           -fld dword ptr [0x4dc8b8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5097656) /* 0x4dc8b8 */)));
    // 004b5cba  d80dc8c84d00           -fmul dword ptr [0x4dc8c8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5097672) /* 0x4dc8c8 */));
    // 004b5cc0  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b5cc2  d80dd8c84d00           -fmul dword ptr [0x4dc8d8]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5097688) /* 0x4dc8d8 */));
    // 004b5cc8  8b15902b5b00           -mov edx, dword ptr [0x5b2b90]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5974928) /* 0x5b2b90 */);
    // 004b5cce  a130d25a00             -mov eax, dword ptr [0x5ad230]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5952048) /* 0x5ad230 */);
    // 004b5cd3  8b1d502b5b00           -mov ebx, dword ptr [0x5b2b50]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5974864) /* 0x5b2b50 */);
    // 004b5cd9  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b5cdb  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b5cde  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b5ce1  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b5ce4  d915b8c84d00           -fst dword ptr [0x4dc8b8]
    app->getMemory<float>(x86::reg32(5097656) /* 0x4dc8b8 */) = float(cpu.fpu.st(0));
    // 004b5cea  d95ffc                 -fstp dword ptr [edi - 4]
    app->getMemory<float>(cpu.edi + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b5ced  83e901                 +sub ecx, 1
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
    // 004b5cf0  0f8f5bfeffff           -jg 0x4b5b51
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b5b51;
    }
    // 004b5cf6  61                     -popal 
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
    // 004b5cf7  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5cf8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4b5d00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b5d00);
    // 004b5d00  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b5d04  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b5d08  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b5d0c  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 004b5d0f  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b5d11  39c8                   +cmp eax, ecx
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
    // 004b5d13  7313                   -jae 0x4b5d28
    if (!cpu.flags.cf)
    {
        goto L_0x004b5d28;
    }
L_0x004b5d15:
    // 004b5d15  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 004b5d17  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b5d1a  d84204                 -fadd dword ptr [edx + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edx + x86::reg32(4) /* 0x4 */));
    // 004b5d1d  83c208                 -add edx, 8
    (cpu.edx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b5d20  d958fc                 -fstp dword ptr [eax - 4]
    app->getMemory<float>(cpu.eax + x86::reg32(-4) /* -0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b5d23  39c8                   +cmp eax, ecx
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
    // 004b5d25  72ee                   -jb 0x4b5d15
    if (cpu.flags.cf)
    {
        goto L_0x004b5d15;
    }
    // 004b5d27  90                     -nop 
    ;
L_0x004b5d28:
    // 004b5d28  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4b5d30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b5d30);
    // 004b5d30  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b5d31  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b5d32  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b5d35  c704240000803f         -mov dword ptr [esp], 0x3f800000
    app->getMemory<x86::reg32>(cpu.esp) = 1065353216 /*0x3f800000*/;
    // 004b5d3c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b5d3e  7e2f                   -jle 0x4b5d6f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b5d6f;
    }
    // 004b5d40  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004b5d45  39d0                   +cmp eax, edx
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
    // 004b5d47  7c0f                   -jl 0x4b5d58
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b5d58;
    }
    // 004b5d49  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004b5d4b:
    // 004b5d4b  85c2                   +test edx, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.eax));
    // 004b5d4d  7512                   -jne 0x4b5d61
    if (!cpu.flags.zf)
    {
        goto L_0x004b5d61;
    }
L_0x004b5d4f:
    // 004b5d4f  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b5d51  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b5d54  39c2                   +cmp edx, eax
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
    // 004b5d56  7ef3                   -jle 0x4b5d4b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b5d4b;
    }
L_0x004b5d58:
    // 004b5d58  d90424                 -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 004b5d5b  83c404                 +add esp, 4
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
    // 004b5d5e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5d5f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5d60  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b5d61:
    // 004b5d61  d90424                 +fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 004b5d64  d889a4e34d00           +fmul dword ptr [ecx + 0x4de3a4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(5104548) /* 0x4de3a4 */));
    // 004b5d6a  d91c24                 +fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b5d6d  ebe0                   -jmp 0x4b5d4f
    goto L_0x004b5d4f;
L_0x004b5d6f:
    // 004b5d6f  6bc0ff                 -imul eax, eax, -1
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(-1 /*-0x1*/)));
    // 004b5d72  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004b5d77  39d0                   +cmp eax, edx
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
    // 004b5d79  7cdd                   -jl 0x4b5d58
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b5d58;
    }
    // 004b5d7b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004b5d7d:
    // 004b5d7d  85c2                   +test edx, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.eax));
    // 004b5d7f  750b                   -jne 0x4b5d8c
    if (!cpu.flags.zf)
    {
        goto L_0x004b5d8c;
    }
    // 004b5d81  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b5d83  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b5d86  39c2                   +cmp edx, eax
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
    // 004b5d88  7fce                   -jg 0x4b5d58
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b5d58;
    }
    // 004b5d8a  ebf1                   -jmp 0x4b5d7d
    goto L_0x004b5d7d;
L_0x004b5d8c:
    // 004b5d8c  d90424                 -fld dword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp)));
    // 004b5d8f  d8b1a4e34d00           -fdiv dword ptr [ecx + 0x4de3a4]
    cpu.fpu.st(0) /= x86::Float(app->getMemory<float>(cpu.ecx + x86::reg32(5104548) /* 0x4de3a4 */));
    // 004b5d95  d91c24                 -fstp dword ptr [esp]
    app->getMemory<float>(cpu.esp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b5d98  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b5d9a  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b5d9d  39c2                   +cmp edx, eax
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
    // 004b5d9f  7fb7                   -jg 0x4b5d58
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b5d58;
    }
    // 004b5da1  ebda                   -jmp 0x4b5d7d
    goto L_0x004b5d7d;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4b5db0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b5db0);
    // 004b5db0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b5db1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b5db2  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004b5db4  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004b5db6  c1f806                 -sar eax, 6
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (6 /*0x6*/ % 32));
    // 004b5db9  c0e407                 +shl ah, 7
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
    // 004b5dbc  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004b5dbe  00e4                   +add ah, ah
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
    // 004b5dc0  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 004b5dc2  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b5dc4  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b5dc9  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b5dcb  8b0485d0944d00         -mov eax, dword ptr [eax*4 + 0x4d94d0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5084368) /* 0x4d94d0 */ + cpu.eax * 4);
    // 004b5dd2  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b5dd4  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b5dd6  b900000100             -mov ecx, 0x10000
    cpu.ecx = 65536 /*0x10000*/;
    // 004b5ddb  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004b5ddd  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b5ddf  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b5de1  0fafc7                 -imul eax, edi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 004b5de4  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b5de7  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004b5de9  83f87f                 +cmp eax, 0x7f
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
    // 004b5dec  7f16                   -jg 0x4b5e04
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b5e04;
    }
L_0x004b5dee:
    // 004b5dee  81c200000100           -add edx, 0x10000
    (cpu.edx) += x86::reg32(x86::sreg32(65536 /*0x10000*/));
    // 004b5df4  0faffa                 -imul edi, edx
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004b5df7  c1ef10                 -shr edi, 0x10
    cpu.edi >>= 16 /*0x10*/ % 32;
    // 004b5dfa  893e                   -mov dword ptr [esi], edi
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edi;
    // 004b5dfc  83ff7f                 +cmp edi, 0x7f
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
    // 004b5dff  7f0b                   -jg 0x4b5e0c
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b5e0c;
    }
    // 004b5e01  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5e02  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5e03  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b5e04:
    // 004b5e04  c7037f000000           -mov dword ptr [ebx], 0x7f
    app->getMemory<x86::reg32>(cpu.ebx) = 127 /*0x7f*/;
    // 004b5e0a  ebe2                   -jmp 0x4b5dee
    goto L_0x004b5dee;
L_0x004b5e0c:
    // 004b5e0c  c7067f000000           -mov dword ptr [esi], 0x7f
    app->getMemory<x86::reg32>(cpu.esi) = 127 /*0x7f*/;
    // 004b5e12  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5e13  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5e14  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b5e15(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b5e15);
    // 004b5e15  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b5e16  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b5e17  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b5e18  8a2549c94d00           -mov ah, byte ptr [0x4dc949]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5097801) /* 0x4dc949 */);
    // 004b5e1e  80e4f8                 -and ah, 0xf8
    cpu.ah &= x86::reg8(x86::sreg8(248 /*0xf8*/));
    // 004b5e21  88e2                   -mov dl, ah
    cpu.dl = cpu.ah;
    // 004b5e23  882549c94d00           -mov byte ptr [0x4dc949], ah
    app->getMemory<x86::reg8>(x86::reg32(5097801) /* 0x4dc949 */) = cpu.ah;
    // 004b5e29  80ca04                 +or dl, 4
    cpu.clear_co();
    cpu.set_szp((cpu.dl |= x86::reg8(x86::sreg8(4 /*0x4*/))));
    // 004b5e2c  bb08c94d00             -mov ebx, 0x4dc908
    cpu.ebx = 5097736 /*0x4dc908*/;
    // 004b5e31  881549c94d00           -mov byte ptr [0x4dc949], dl
    app->getMemory<x86::reg8>(x86::reg32(5097801) /* 0x4dc949 */) = cpu.dl;
    // 004b5e37  eb5d                   -jmp 0x4b5e96
    goto L_0x004b5e96;
L_0x004b5e39:
    // 004b5e39  b81d000000             -mov eax, 0x1d
    cpu.eax = 29 /*0x1d*/;
    // 004b5e3e  e8f0c2feff             -call 0x4a2133
    cpu.esp -= 4;
    sub_4a2133(app, cpu);
    if (cpu.terminate) return;
    // 004b5e43  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004b5e45  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b5e47  751f                   -jne 0x4b5e68
    if (!cpu.flags.zf)
    {
        goto L_0x004b5e68;
    }
    // 004b5e49  b81d000000             -mov eax, 0x1d
    cpu.eax = 29 /*0x1d*/;
    // 004b5e4e  e8e0c2feff             -call 0x4a2133
    cpu.esp -= 4;
    sub_4a2133(app, cpu);
    if (cpu.terminate) return;
    // 004b5e53  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004b5e55  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b5e57  750f                   -jne 0x4b5e68
    if (!cpu.flags.zf)
    {
        goto L_0x004b5e68;
    }
    // 004b5e59  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004b5e5e  b874f74c00             -mov eax, 0x4cf774
    cpu.eax = 5044084 /*0x4cf774*/;
    // 004b5e63  e8f9390000             -call 0x4b9861
    cpu.esp -= 4;
    sub_4b9861(app, cpu);
    if (cpu.terminate) return;
L_0x004b5e68:
    // 004b5e68  a1e4435b00             -mov eax, dword ptr [0x5b43e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5981156) /* 0x5b43e4 */);
    // 004b5e6d  895904                 -mov dword ptr [ecx + 4], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004b5e70  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 004b5e72  894b08                 -mov dword ptr [ebx + 8], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 004b5e75  c7410800000000         -mov dword ptr [ecx + 8], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004b5e7c  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b5e7f  c6401400               -mov byte ptr [eax + 0x14], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 004b5e83  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b5e86  890de4435b00           -mov dword ptr [0x5b43e4], ecx
    app->getMemory<x86::reg32>(x86::reg32(5981156) /* 0x5b43e4 */) = cpu.ecx;
    // 004b5e8c  83c31a                 -add ebx, 0x1a
    (cpu.ebx) += x86::reg32(x86::sreg32(26 /*0x1a*/));
    // 004b5e8f  c7400c00000000         -mov dword ptr [eax + 0xc], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
L_0x004b5e96:
    // 004b5e96  8b530c                 -mov edx, dword ptr [ebx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004b5e99  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b5e9b  759c                   -jne 0x4b5e39
    if (!cpu.flags.zf)
    {
        goto L_0x004b5e39;
    }
    // 004b5e9d  8915e8435b00           -mov dword ptr [0x5b43e8], edx
    app->getMemory<x86::reg32>(x86::reg32(5981160) /* 0x5b43e8 */) = cpu.edx;
    // 004b5ea3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5ea4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5ea5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5ea6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b5ea7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b5ea7);
    // 004b5ea7  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004b5ea9  e80a000000             -call 0x4b5eb8
    cpu.esp -= 4;
    sub_4b5eb8(app, cpu);
    if (cpu.terminate) return;
    // 004b5eae  e93df8feff             -jmp 0x4a56f0
    return sub_4a56f0(app, cpu);
}

/* align: skip  */
void Application::sub_4b5eb3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b5eb3);
    // 004b5eb3  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 004b5eb8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b5eb9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b5eba  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b5ebb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b5ebc  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b5ebe  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004b5ec1  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b5ec3  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004b5ec6  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b5ec8  be08c94d00             -mov esi, 0x4dc908
    cpu.esi = 5097736 /*0x4dc908*/;
    // 004b5ecd  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b5ecf  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b5ed1  01c6                   +add esi, eax
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
    // 004b5ed3  a1e4435b00             -mov eax, dword ptr [0x5b43e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5981156) /* 0x5b43e4 */);
    // 004b5ed8  eb2b                   -jmp 0x4b5f05
    goto L_0x004b5f05;
L_0x004b5eda:
    // 004b5eda  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004b5edc  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004b5edf  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004b5ee4  f6400d40               +test byte ptr [eax + 0xd], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */) & 64 /*0x40*/));
    // 004b5ee8  7513                   -jne 0x4b5efd
    if (!cpu.flags.zf)
    {
        goto L_0x004b5efd;
    }
    // 004b5eea  f6400d08               +test byte ptr [eax + 0xd], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */) & 8 /*0x8*/));
    // 004b5eee  750d                   -jne 0x4b5efd
    if (!cpu.flags.zf)
    {
        goto L_0x004b5efd;
    }
    // 004b5ef0  39f0                   +cmp eax, esi
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
    // 004b5ef2  720f                   -jb 0x4b5f03
    if (cpu.flags.cf)
    {
        goto L_0x004b5f03;
    }
    // 004b5ef4  3d56c94d00             +cmp eax, 0x4dc956
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5097814 /*0x4dc956*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b5ef9  7302                   -jae 0x4b5efd
    if (!cpu.flags.cf)
    {
        goto L_0x004b5efd;
    }
    // 004b5efb  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004b5efd:
    // 004b5efd  e8642dfdff             -call 0x488c66
    cpu.esp -= 4;
    sub_488c66(app, cpu);
    if (cpu.terminate) return;
    // 004b5f02  43                     -inc ebx
    (cpu.ebx)++;
L_0x004b5f03:
    // 004b5f03  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x004b5f05:
    // 004b5f05  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b5f07  75d1                   -jne 0x4b5eda
    if (!cpu.flags.zf)
    {
        goto L_0x004b5eda;
    }
    // 004b5f09  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b5f0b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5f0c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5f0d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5f0e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5f0f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b5eb8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b5eb8);
    goto L_entry_0x004b5eb8;
    // 004b5eb3  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
L_entry_0x004b5eb8:
    // 004b5eb8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b5eb9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b5eba  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b5ebb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b5ebc  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b5ebe  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004b5ec1  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b5ec3  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004b5ec6  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b5ec8  be08c94d00             -mov esi, 0x4dc908
    cpu.esi = 5097736 /*0x4dc908*/;
    // 004b5ecd  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b5ecf  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b5ed1  01c6                   +add esi, eax
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
    // 004b5ed3  a1e4435b00             -mov eax, dword ptr [0x5b43e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5981156) /* 0x5b43e4 */);
    // 004b5ed8  eb2b                   -jmp 0x4b5f05
    goto L_0x004b5f05;
L_0x004b5eda:
    // 004b5eda  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004b5edc  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004b5edf  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004b5ee4  f6400d40               +test byte ptr [eax + 0xd], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */) & 64 /*0x40*/));
    // 004b5ee8  7513                   -jne 0x4b5efd
    if (!cpu.flags.zf)
    {
        goto L_0x004b5efd;
    }
    // 004b5eea  f6400d08               +test byte ptr [eax + 0xd], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */) & 8 /*0x8*/));
    // 004b5eee  750d                   -jne 0x4b5efd
    if (!cpu.flags.zf)
    {
        goto L_0x004b5efd;
    }
    // 004b5ef0  39f0                   +cmp eax, esi
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
    // 004b5ef2  720f                   -jb 0x4b5f03
    if (cpu.flags.cf)
    {
        goto L_0x004b5f03;
    }
    // 004b5ef4  3d56c94d00             +cmp eax, 0x4dc956
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5097814 /*0x4dc956*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b5ef9  7302                   -jae 0x4b5efd
    if (!cpu.flags.cf)
    {
        goto L_0x004b5efd;
    }
    // 004b5efb  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004b5efd:
    // 004b5efd  e8642dfdff             -call 0x488c66
    cpu.esp -= 4;
    sub_488c66(app, cpu);
    if (cpu.terminate) return;
    // 004b5f02  43                     -inc ebx
    (cpu.ebx)++;
L_0x004b5f03:
    // 004b5f03  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x004b5f05:
    // 004b5f05  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b5f07  75d1                   -jne 0x4b5eda
    if (!cpu.flags.zf)
    {
        goto L_0x004b5eda;
    }
    // 004b5f09  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b5f0b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5f0c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5f0d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5f0e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5f0f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b5f10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b5f10);
    // 004b5f10  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b5f11  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b5f12  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b5f13  8b0dd8e44d00           -mov ecx, dword ptr [0x4de4d8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5104856) /* 0x4de4d8 */);
    // 004b5f19  a1dce44d00             -mov eax, dword ptr [0x4de4dc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5104860) /* 0x4de4dc */);
    // 004b5f1e  3b05e8e44d00           +cmp eax, dword ptr [0x4de4e8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5104872) /* 0x4de4e8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b5f24  7304                   -jae 0x4b5f2a
    if (!cpu.flags.cf)
    {
        goto L_0x004b5f2a;
    }
L_0x004b5f26:
    // 004b5f26  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004b5f28  eb21                   -jmp 0x4b5f4b
    goto L_0x004b5f4b;
L_0x004b5f2a:
    // 004b5f2a  8b1ddce44d00           -mov ebx, dword ptr [0x4de4dc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5104860) /* 0x4de4dc */);
    // 004b5f30  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004b5f32  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b5f34  c1e302                 +shl ebx, 2
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
    // 004b5f37  eb09                   -jmp 0x4b5f42
    goto L_0x004b5f42;
L_0x004b5f39:
    // 004b5f39  833c0200               +cmp dword ptr [edx + eax], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 1);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b5f3d  74e7                   -je 0x4b5f26
    if (cpu.flags.zf)
    {
        goto L_0x004b5f26;
    }
    // 004b5f3f  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004b5f42:
    // 004b5f42  39d8                   +cmp eax, ebx
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
    // 004b5f44  7cf3                   -jl 0x4b5f39
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b5f39;
    }
    // 004b5f46  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004b5f4b:
    // 004b5f4b  890dd8e44d00           -mov dword ptr [0x4de4d8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5104856) /* 0x4de4d8 */) = cpu.ecx;
    // 004b5f51  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5f52  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5f53  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5f54  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b5f55(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b5f55);
    // 004b5f55  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b5f56  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b5f57  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b5f58  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b5f59  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b5f5b  ff1550cb4d00           -call dword ptr [0x4dcb50]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098320) /* 0x4dcb50 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b5f61  8b0ddce44d00           -mov ecx, dword ptr [0x4de4dc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5104860) /* 0x4de4dc */);
    // 004b5f67  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b5f69  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b5f6b  c1e102                 +shl ecx, 2
    {
        x86::reg8 tmp = 2 /*0x2*/ % 32;
        x86::reg32& op = cpu.ecx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004b5f6e  eb20                   -jmp 0x4b5f90
    goto L_0x004b5f90;
L_0x004b5f70:
    // 004b5f70  8b15d8e44d00           -mov edx, dword ptr [0x4de4d8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5104856) /* 0x4de4d8 */);
    // 004b5f76  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b5f78  833a00                 +cmp dword ptr [edx], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b5f7b  750f                   -jne 0x4b5f8c
    if (!cpu.flags.zf)
    {
        goto L_0x004b5f8c;
    }
    // 004b5f7d  8932                   -mov dword ptr [edx], esi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.esi;
    // 004b5f7f  ff1554cb4d00           -call dword ptr [0x4dcb54]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098324) /* 0x4dcb54 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b5f85  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b5f87  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5f88  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5f89  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5f8a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5f8b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b5f8c:
    // 004b5f8c  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b5f8f  43                     -inc ebx
    (cpu.ebx)++;
L_0x004b5f90:
    // 004b5f90  39c8                   +cmp eax, ecx
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
    // 004b5f92  7cdc                   -jl 0x4b5f70
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b5f70;
    }
    // 004b5f94  8b15dce44d00           -mov edx, dword ptr [0x4de4dc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5104860) /* 0x4de4dc */);
    // 004b5f9a  42                     -inc edx
    (cpu.edx)++;
    // 004b5f9b  a1d8e44d00             -mov eax, dword ptr [0x4de4d8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5104856) /* 0x4de4d8 */);
    // 004b5fa0  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 004b5fa3  e80365ffff             -call 0x4ac4ab
    cpu.esp -= 4;
    sub_4ac4ab(app, cpu);
    if (cpu.terminate) return;
    // 004b5fa8  8b15dce44d00           -mov edx, dword ptr [0x4de4dc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5104860) /* 0x4de4dc */);
    // 004b5fae  a3d8e44d00             -mov dword ptr [0x4de4d8], eax
    app->getMemory<x86::reg32>(x86::reg32(5104856) /* 0x4de4d8 */) = cpu.eax;
    // 004b5fb3  893490                 -mov dword ptr [eax + edx*4], esi
    app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4) = cpu.esi;
    // 004b5fb6  42                     -inc edx
    (cpu.edx)++;
    // 004b5fb7  8915dce44d00           -mov dword ptr [0x4de4dc], edx
    app->getMemory<x86::reg32>(x86::reg32(5104860) /* 0x4de4dc */) = cpu.edx;
    // 004b5fbd  ff1554cb4d00           -call dword ptr [0x4dcb54]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098324) /* 0x4dcb54 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b5fc3  a1dce44d00             -mov eax, dword ptr [0x4de4dc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5104860) /* 0x4de4dc */);
    // 004b5fc8  48                     -dec eax
    (cpu.eax)--;
    // 004b5fc9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5fca  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5fcb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5fcc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5fcd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b5fce(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b5fce);
    // 004b5fce  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b5fcf  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b5fd0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b5fd1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b5fd2  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004b5fd4  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004b5fd6  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b5fd8  0f8c90000000           -jl 0x4b606e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b606e;
    }
    // 004b5fde  ff1550cb4d00           -call dword ptr [0x4dcb50]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098320) /* 0x4dcb50 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b5fe4  83fa01                 +cmp edx, 1
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
    // 004b5fe7  7209                   -jb 0x4b5ff2
    if (cpu.flags.cf)
    {
        goto L_0x004b5ff2;
    }
    // 004b5fe9  7610                   -jbe 0x4b5ffb
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b5ffb;
    }
    // 004b5feb  83fa02                 +cmp edx, 2
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
    // 004b5fee  7410                   -je 0x4b6000
    if (cpu.flags.zf)
    {
        goto L_0x004b6000;
    }
    // 004b5ff0  eb18                   -jmp 0x4b600a
    goto L_0x004b600a;
L_0x004b5ff2:
    // 004b5ff2  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b5ff4  7514                   -jne 0x4b600a
    if (!cpu.flags.zf)
    {
        goto L_0x004b600a;
    }
    // 004b5ff6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b5ff7  6af6                   -push -0xa
    app->getMemory<x86::reg32>(cpu.esp-4) = -10 /*-0xa*/;
    cpu.esp -= 4;
    // 004b5ff9  eb08                   -jmp 0x4b6003
    goto L_0x004b6003;
L_0x004b5ffb:
    // 004b5ffb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b5ffc  6af5                   -push -0xb
    app->getMemory<x86::reg32>(cpu.esp-4) = -11 /*-0xb*/;
    cpu.esp -= 4;
    // 004b5ffe  eb03                   -jmp 0x4b6003
    goto L_0x004b6003;
L_0x004b6000:
    // 004b6000  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b6001  6af4                   -push -0xc
    app->getMemory<x86::reg32>(cpu.esp-4) = -12 /*-0xc*/;
    cpu.esp -= 4;
L_0x004b6003:
    // 004b6003  2eff156c454c00         -call dword ptr cs:[0x4c456c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998508) /* 0x4c456c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004b600a:
    // 004b600a  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004b600c  8b15dce44d00           -mov edx, dword ptr [0x4de4dc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5104860) /* 0x4de4dc */);
    // 004b6012  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 004b6015  39d6                   +cmp esi, edx
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
    // 004b6017  7d0a                   -jge 0x4b6023
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b6023;
    }
    // 004b6019  a1d8e44d00             -mov eax, dword ptr [0x4de4d8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5104856) /* 0x4de4d8 */);
    // 004b601e  893c01                 -mov dword ptr [ecx + eax], edi
    app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 1) = cpu.edi;
    // 004b6021  eb45                   -jmp 0x4b6068
    goto L_0x004b6068;
L_0x004b6023:
    // 004b6023  a1d8e44d00             -mov eax, dword ptr [0x4de4d8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5104856) /* 0x4de4d8 */);
    // 004b6028  8d5104                 -lea edx, [ecx + 4]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004b602b  e87b64ffff             -call 0x4ac4ab
    cpu.esp -= 4;
    sub_4ac4ab(app, cpu);
    if (cpu.terminate) return;
    // 004b6030  8b1ddce44d00           -mov ebx, dword ptr [0x4de4dc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5104860) /* 0x4de4dc */);
    // 004b6036  a3d8e44d00             -mov dword ptr [0x4de4d8], eax
    app->getMemory<x86::reg32>(x86::reg32(5104856) /* 0x4de4d8 */) = cpu.eax;
    // 004b603b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b603d  c1e002                 +shl eax, 2
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
    // 004b6040  eb11                   -jmp 0x4b6053
    goto L_0x004b6053;
L_0x004b6042:
    // 004b6042  8b15d8e44d00           -mov edx, dword ptr [0x4de4d8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5104856) /* 0x4de4d8 */);
    // 004b6048  43                     -inc ebx
    (cpu.ebx)++;
    // 004b6049  c7040200000000         -mov dword ptr [edx + eax], 0
    app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 1) = 0 /*0x0*/;
    // 004b6050  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004b6053:
    // 004b6053  39c8                   +cmp eax, ecx
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
    // 004b6055  7ceb                   -jl 0x4b6042
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b6042;
    }
    // 004b6057  a1d8e44d00             -mov eax, dword ptr [0x4de4d8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5104856) /* 0x4de4d8 */);
    // 004b605c  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004b605e  46                     -inc esi
    (cpu.esi)++;
    // 004b605f  893c90                 -mov dword ptr [eax + edx*4], edi
    app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4) = cpu.edi;
    // 004b6062  8935dce44d00           -mov dword ptr [0x4de4dc], esi
    app->getMemory<x86::reg32>(x86::reg32(5104860) /* 0x4de4dc */) = cpu.esi;
L_0x004b6068:
    // 004b6068  ff1554cb4d00           -call dword ptr [0x4dcb54]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098324) /* 0x4dcb54 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004b606e:
    // 004b606e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b606f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6070  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6071  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6072  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b6073(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b6073);
    // 004b6073  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b6074  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b6076  ff1550cb4d00           -call dword ptr [0x4dcb50]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098320) /* 0x4dcb50 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b607c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b607e  7e17                   -jle 0x4b6097
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b6097;
    }
    // 004b6080  3b15dce44d00           +cmp edx, dword ptr [0x4de4dc]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5104860) /* 0x4de4dc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b6086  7d0f                   -jge 0x4b6097
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b6097;
    }
    // 004b6088  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b608a  8b15d8e44d00           -mov edx, dword ptr [0x4de4d8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5104856) /* 0x4de4d8 */);
    // 004b6090  c7048200000000         -mov dword ptr [edx + eax*4], 0
    app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4) = 0 /*0x0*/;
L_0x004b6097:
    // 004b6097  ff1554cb4d00           -call dword ptr [0x4dcb54]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098324) /* 0x4dcb54 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b609d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b609e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b609f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b609f);
    // 004b609f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b60a0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b60a1  6af6                   -push -0xa
    app->getMemory<x86::reg32>(cpu.esp-4) = -10 /*-0xa*/;
    cpu.esp -= 4;
    // 004b60a3  2eff15ec444c00         -call dword ptr cs:[0x4c44ec]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998380) /* 0x4c44ec */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b60aa  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b60ac  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b60ae  7405                   -je 0x4b60b5
    if (cpu.flags.zf)
    {
        goto L_0x004b60b5;
    }
    // 004b60b0  83f8ff                 +cmp eax, -1
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
    // 004b60b3  7505                   -jne 0x4b60ba
    if (!cpu.flags.zf)
    {
        goto L_0x004b60ba;
    }
L_0x004b60b5:
    // 004b60b5  e844000000             -call 0x4b60fe
    cpu.esp -= 4;
    sub_4b60fe(app, cpu);
    if (cpu.terminate) return;
L_0x004b60ba:
    // 004b60ba  e896feffff             -call 0x4b5f55
    cpu.esp -= 4;
    sub_4b5f55(app, cpu);
    if (cpu.terminate) return;
    // 004b60bf  6af5                   -push -0xb
    app->getMemory<x86::reg32>(cpu.esp-4) = -11 /*-0xb*/;
    cpu.esp -= 4;
    // 004b60c1  2eff15ec444c00         -call dword ptr cs:[0x4c44ec]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998380) /* 0x4c44ec */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b60c8  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b60ca  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b60cc  7405                   -je 0x4b60d3
    if (cpu.flags.zf)
    {
        goto L_0x004b60d3;
    }
    // 004b60ce  83f8ff                 +cmp eax, -1
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
    // 004b60d1  7505                   -jne 0x4b60d8
    if (!cpu.flags.zf)
    {
        goto L_0x004b60d8;
    }
L_0x004b60d3:
    // 004b60d3  e826000000             -call 0x4b60fe
    cpu.esp -= 4;
    sub_4b60fe(app, cpu);
    if (cpu.terminate) return;
L_0x004b60d8:
    // 004b60d8  e878feffff             -call 0x4b5f55
    cpu.esp -= 4;
    sub_4b5f55(app, cpu);
    if (cpu.terminate) return;
    // 004b60dd  6af4                   -push -0xc
    app->getMemory<x86::reg32>(cpu.esp-4) = -12 /*-0xc*/;
    cpu.esp -= 4;
    // 004b60df  2eff15ec444c00         -call dword ptr cs:[0x4c44ec]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998380) /* 0x4c44ec */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b60e6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b60e8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b60ea  7405                   -je 0x4b60f1
    if (cpu.flags.zf)
    {
        goto L_0x004b60f1;
    }
    // 004b60ec  83f8ff                 +cmp eax, -1
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
    // 004b60ef  7505                   -jne 0x4b60f6
    if (!cpu.flags.zf)
    {
        goto L_0x004b60f6;
    }
L_0x004b60f1:
    // 004b60f1  e808000000             -call 0x4b60fe
    cpu.esp -= 4;
    sub_4b60fe(app, cpu);
    if (cpu.terminate) return;
L_0x004b60f6:
    // 004b60f6  e85afeffff             -call 0x4b5f55
    cpu.esp -= 4;
    sub_4b5f55(app, cpu);
    if (cpu.terminate) return;
    // 004b60fb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b60fc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b60fd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b60fe(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b60fe);
    // 004b60fe  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b60ff  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b6100  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004b6102  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004b6104  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004b6106  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004b6108  2eff152c444c00         -call dword ptr cs:[0x4c442c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998188) /* 0x4c442c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b610f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b6111  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b6113  750d                   -jne 0x4b6122
    if (!cpu.flags.zf)
    {
        goto L_0x004b6122;
    }
    // 004b6115  8b15e0e44d00           -mov edx, dword ptr [0x4de4e0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5104864) /* 0x4de4e0 */);
    // 004b611b  42                     -inc edx
    (cpu.edx)++;
    // 004b611c  8915e0e44d00           -mov dword ptr [0x4de4e0], edx
    app->getMemory<x86::reg32>(x86::reg32(5104864) /* 0x4de4e0 */) = cpu.edx;
L_0x004b6122:
    // 004b6122  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b6124  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6125  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6126  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b6127(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b6127);
    // 004b6127  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 004b6129  740e                   -je 0x4b6139
    if (cpu.flags.zf)
    {
        goto L_0x004b6139;
    }
    // 004b612b  c70200000080           -mov dword ptr [edx], 0x80000000
    app->getMemory<x86::reg32>(cpu.edx) = 2147483648 /*0x80000000*/;
    // 004b6131  c70301000000           -mov dword ptr [ebx], 1
    app->getMemory<x86::reg32>(cpu.ebx) = 1 /*0x1*/;
    // 004b6137  eb0c                   -jmp 0x4b6145
    goto L_0x004b6145;
L_0x004b6139:
    // 004b6139  c702000000c0           -mov dword ptr [edx], 0xc0000000
    app->getMemory<x86::reg32>(cpu.edx) = 3221225472 /*0xc0000000*/;
    // 004b613f  c70380000000           -mov dword ptr [ebx], 0x80
    app->getMemory<x86::reg32>(cpu.ebx) = 128 /*0x80*/;
L_0x004b6145:
    // 004b6145  a802                   +test al, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 2 /*0x2*/));
    // 004b6147  7403                   -je 0x4b614c
    if (cpu.flags.zf)
    {
        goto L_0x004b614c;
    }
    // 004b6149  800b02                 -or byte ptr [ebx], 2
    app->getMemory<x86::reg8>(cpu.ebx) |= x86::reg8(x86::sreg8(2 /*0x2*/));
L_0x004b614c:
    // 004b614c  a804                   +test al, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 4 /*0x4*/));
    // 004b614e  7403                   -je 0x4b6153
    if (cpu.flags.zf)
    {
        goto L_0x004b6153;
    }
    // 004b6150  800b04                 -or byte ptr [ebx], 4
    app->getMemory<x86::reg8>(cpu.ebx) |= x86::reg8(x86::sreg8(4 /*0x4*/));
L_0x004b6153:
    // 004b6153  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b6154(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b6154);
    // 004b6154  83f802                 +cmp eax, 2
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
    // 004b6157  750d                   -jne 0x4b6166
    if (!cpu.flags.zf)
    {
        goto L_0x004b6166;
    }
    // 004b6159  c702000000c0           -mov dword ptr [edx], 0xc0000000
    app->getMemory<x86::reg32>(cpu.edx) = 3221225472 /*0xc0000000*/;
L_0x004b615f:
    // 004b615f  c70380000000           -mov dword ptr [ebx], 0x80
    app->getMemory<x86::reg32>(cpu.ebx) = 128 /*0x80*/;
    // 004b6165  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b6166:
    // 004b6166  83f801                 +cmp eax, 1
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
    // 004b6169  7508                   -jne 0x4b6173
    if (!cpu.flags.zf)
    {
        goto L_0x004b6173;
    }
    // 004b616b  c70200000040           -mov dword ptr [edx], 0x40000000
    app->getMemory<x86::reg32>(cpu.edx) = 1073741824 /*0x40000000*/;
    // 004b6171  ebec                   -jmp 0x4b615f
    goto L_0x004b615f;
L_0x004b6173:
    // 004b6173  c70200000080           -mov dword ptr [edx], 0x80000000
    app->getMemory<x86::reg32>(cpu.edx) = 2147483648 /*0x80000000*/;
    // 004b6179  c70301000000           -mov dword ptr [ebx], 1
    app->getMemory<x86::reg32>(cpu.ebx) = 1 /*0x1*/;
    // 004b617f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b6180(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b6180);
    // 004b6180  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b6181  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b6183  83e070                 -and eax, 0x70
    cpu.eax &= x86::reg32(x86::sreg32(112 /*0x70*/));
    // 004b6186  83e307                 -and ebx, 7
    cpu.ebx &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004b6189  83f820                 +cmp eax, 0x20
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
    // 004b618c  7210                   -jb 0x4b619e
    if (cpu.flags.cf)
    {
        goto L_0x004b619e;
    }
    // 004b618e  7638                   -jbe 0x4b61c8
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b61c8;
    }
    // 004b6190  83f830                 +cmp eax, 0x30
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
    // 004b6193  7241                   -jb 0x4b61d6
    if (cpu.flags.cf)
    {
        goto L_0x004b61d6;
    }
    // 004b6195  7629                   -jbe 0x4b61c0
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b61c0;
    }
    // 004b6197  83f840                 +cmp eax, 0x40
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
    // 004b619a  7434                   -je 0x4b61d0
    if (cpu.flags.zf)
    {
        goto L_0x004b61d0;
    }
    // 004b619c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b619d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b619e:
    // 004b619e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b61a0  7607                   -jbe 0x4b61a9
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b61a9;
    }
    // 004b61a2  83f810                 +cmp eax, 0x10
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
    // 004b61a5  7411                   -je 0x4b61b8
    if (cpu.flags.zf)
    {
        goto L_0x004b61b8;
    }
    // 004b61a7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b61a8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b61a9:
    // 004b61a9  c70201000000           -mov dword ptr [edx], 1
    app->getMemory<x86::reg32>(cpu.edx) = 1 /*0x1*/;
    // 004b61af  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004b61b1  7523                   -jne 0x4b61d6
    if (!cpu.flags.zf)
    {
        goto L_0x004b61d6;
    }
    // 004b61b3  800a02                 -or byte ptr [edx], 2
    app->getMemory<x86::reg8>(cpu.edx) |= x86::reg8(x86::sreg8(2 /*0x2*/));
    // 004b61b6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b61b7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b61b8:
    // 004b61b8  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 004b61be  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b61bf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b61c0:
    // 004b61c0  c70202000000           -mov dword ptr [edx], 2
    app->getMemory<x86::reg32>(cpu.edx) = 2 /*0x2*/;
    // 004b61c6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b61c7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b61c8:
    // 004b61c8  c70201000000           -mov dword ptr [edx], 1
    app->getMemory<x86::reg32>(cpu.edx) = 1 /*0x1*/;
    // 004b61ce  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b61cf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b61d0:
    // 004b61d0  c70203000000           -mov dword ptr [edx], 3
    app->getMemory<x86::reg32>(cpu.edx) = 3 /*0x3*/;
L_0x004b61d6:
    // 004b61d6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b61d7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b61d8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b61d8);
    // 004b61d8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b61d9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b61da  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b61db  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b61dd  3b05e8e44d00           +cmp eax, dword ptr [0x4de4e8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5104872) /* 0x4de4e8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b61e3  7206                   -jb 0x4b61eb
    if (cpu.flags.cf)
    {
        goto L_0x004b61eb;
    }
    // 004b61e5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b61e7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b61e8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b61e9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b61ea  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b61eb:
    // 004b61eb  83f803                 +cmp eax, 3
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
    // 004b61ee  7d31                   -jge 0x4b6221
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b6221;
    }
    // 004b61f0  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b61f2  a13ce54d00             -mov eax, dword ptr [0x4de53c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5104956) /* 0x4de53c */);
    // 004b61f7  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 004b61fa  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b61fc  8a4801                 -mov cl, byte ptr [eax + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b61ff  f6c140                 +test cl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 64 /*0x40*/));
    // 004b6202  751d                   -jne 0x4b6221
    if (!cpu.flags.zf)
    {
        goto L_0x004b6221;
    }
    // 004b6204  88cd                   -mov ch, cl
    cpu.ch = cpu.cl;
    // 004b6206  80cd40                 -or ch, 0x40
    cpu.ch |= x86::reg8(x86::sreg8(64 /*0x40*/));
    // 004b6209  886801                 -mov byte ptr [eax + 1], ch
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = cpu.ch;
    // 004b620c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b620e  e83b000000             -call 0x4b624e
    cpu.esp -= 4;
    sub_4b624e(app, cpu);
    if (cpu.terminate) return;
    // 004b6213  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b6215  740a                   -je 0x4b6221
    if (cpu.flags.zf)
    {
        goto L_0x004b6221;
    }
    // 004b6217  a13ce54d00             -mov eax, dword ptr [0x4de53c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5104956) /* 0x4de53c */);
    // 004b621c  804c030120             -or byte ptr [ebx + eax + 1], 0x20
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */ + cpu.eax * 1) |= x86::reg8(x86::sreg8(32 /*0x20*/));
L_0x004b6221:
    // 004b6221  a13ce54d00             -mov eax, dword ptr [0x4de53c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5104956) /* 0x4de53c */);
    // 004b6226  8b0490                 -mov eax, dword ptr [eax + edx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 004b6229  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b622a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b622b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b622c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b622d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b622d);
    // 004b622d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b622e  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004b6231  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b6233  740e                   -je 0x4b6243
    if (cpu.flags.zf)
    {
        goto L_0x004b6243;
    }
    // 004b6235  8b1d3ce54d00           -mov ebx, dword ptr [0x4de53c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5104956) /* 0x4de53c */);
    // 004b623b  80ce40                 -or dh, 0x40
    cpu.dh |= x86::reg8(x86::sreg8(64 /*0x40*/));
    // 004b623e  891403                 -mov dword ptr [ebx + eax], edx
    app->getMemory<x86::reg32>(cpu.ebx + cpu.eax * 1) = cpu.edx;
    // 004b6241  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6242  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b6243:
    // 004b6243  8b1d3ce54d00           -mov ebx, dword ptr [0x4de53c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5104956) /* 0x4de53c */);
    // 004b6249  891403                 -mov dword ptr [ebx + eax], edx
    app->getMemory<x86::reg32>(cpu.ebx + cpu.eax * 1) = cpu.edx;
    // 004b624c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b624d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b624e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b624e);
    // 004b624e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b624f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b6250  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b6251  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b6253  ff1520cb4d00           -call dword ptr [0x4dcb20]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098272) /* 0x4dcb20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b6259  833d68cb4d0000         +cmp dword ptr [0x4dcb68], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5098344) /* 0x4dcb68 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b6260  741d                   -je 0x4b627f
    if (cpu.flags.zf)
    {
        goto L_0x004b627f;
    }
    // 004b6262  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b6264  ff1568cb4d00           -call dword ptr [0x4dcb68]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098344) /* 0x4dcb68 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b626a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b626c  7411                   -je 0x4b627f
    if (cpu.flags.zf)
    {
        goto L_0x004b627f;
    }
L_0x004b626e:
    // 004b626e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b6270  ff1524cb4d00           -call dword ptr [0x4dcb24]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098276) /* 0x4dcb24 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b6276  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004b627b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b627c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b627d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b627e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b627f:
    // 004b627f  a1d8e44d00             -mov eax, dword ptr [0x4de4d8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5104856) /* 0x4de4d8 */);
    // 004b6284  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b6286  8b0490                 -mov eax, dword ptr [eax + edx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 004b6289  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b628a  2eff15bc444c00         -call dword ptr cs:[0x4c44bc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998332) /* 0x4c44bc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b6291  83f802                 +cmp eax, 2
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
    // 004b6294  74d8                   -je 0x4b626e
    if (cpu.flags.zf)
    {
        goto L_0x004b626e;
    }
    // 004b6296  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b6298  ff1524cb4d00           -call dword ptr [0x4dcb24]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098276) /* 0x4dcb24 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b629e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b62a0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b62a1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b62a2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b62a3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b62a4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b62a4);
    // 004b62a4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b62a5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b62a6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b62a7  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b62a9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b62ab  7c08                   -jl 0x4b62b5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b62b5;
    }
    // 004b62ad  3b05e8e44d00           +cmp eax, dword ptr [0x4de4e8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5104872) /* 0x4de4e8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b62b3  7613                   -jbe 0x4b62c8
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b62c8;
    }
L_0x004b62b5:
    // 004b62b5  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 004b62ba  e861bffeff             -call 0x4a2220
    cpu.esp -= 4;
    sub_4a2220(app, cpu);
    if (cpu.terminate) return;
    // 004b62bf  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004b62c4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b62c5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b62c6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b62c7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b62c8:
    // 004b62c8  8b15d8e44d00           -mov edx, dword ptr [0x4de4d8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5104856) /* 0x4de4d8 */);
    // 004b62ce  8b1482                 -mov edx, dword ptr [edx + eax*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 004b62d1  ff1520cb4d00           -call dword ptr [0x4dcb20]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098272) /* 0x4dcb20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b62d7  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004b62d9  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004b62db  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004b62dd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b62de  2eff1564454c00         -call dword ptr cs:[0x4c4564]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998500) /* 0x4c4564 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b62e5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b62e7  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b62e9  ff1524cb4d00           -call dword ptr [0x4dcb24]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098276) /* 0x4dcb24 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b62ef  83faff                 +cmp edx, -1
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
    // 004b62f2  7505                   -jne 0x4b62f9
    if (!cpu.flags.zf)
    {
        goto L_0x004b62f9;
    }
    // 004b62f4  e829befeff             -call 0x4a2122
    cpu.esp -= 4;
    sub_4a2122(app, cpu);
    if (cpu.terminate) return;
L_0x004b62f9:
    // 004b62f9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b62fb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b62fc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b62fd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b62fe  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b62ff(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b62ff);
    // 004b62ff  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b6300(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b6300);
    // 004b6300  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b6301  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b6302  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b6303  8b15847a5b00           -mov edx, dword ptr [0x5b7a84]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5995140) /* 0x5b7a84 */);
    // 004b6309  83fa40                 +cmp edx, 0x40
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
    // 004b630c  7d1c                   -jge 0x4b632a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b632a;
    }
    // 004b630e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b6310  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004b6313  bb887a5b00             -mov ebx, 0x5b7a88
    cpu.ebx = 5995144 /*0x5b7a88*/;
    // 004b6318  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b631a  8d4a01                 -lea ecx, [edx + 1]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004b631d  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004b6320  890d847a5b00           -mov dword ptr [0x5b7a84], ecx
    app->getMemory<x86::reg32>(x86::reg32(5995140) /* 0x5b7a84 */) = cpu.ecx;
    // 004b6326  01c3                   +add ebx, eax
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
    // 004b6328  eb24                   -jmp 0x4b634e
    goto L_0x004b634e;
L_0x004b632a:
    // 004b632a  ba18000000             -mov edx, 0x18
    cpu.edx = 24 /*0x18*/;
    // 004b632f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004b6334  e82b6c0000             -call 0x4bcf64
    cpu.esp -= 4;
    sub_4bcf64(app, cpu);
    if (cpu.terminate) return;
    // 004b6339  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b633b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b633d  750f                   -jne 0x4b634e
    if (!cpu.flags.zf)
    {
        goto L_0x004b634e;
    }
    // 004b633f  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004b6344  b8a4f74c00             -mov eax, 0x4cf7a4
    cpu.eax = 5044132 /*0x4cf7a4*/;
    // 004b6349  e813350000             -call 0x4b9861
    cpu.esp -= 4;
    sub_4b9861(app, cpu);
    if (cpu.terminate) return;
L_0x004b634e:
    // 004b634e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b6350  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6351  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6352  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6353  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b6354(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b6354);
    // 004b6354  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b6355  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b6356  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b6357  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b6359  83780400               +cmp dword ptr [eax + 4], 0
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
    // 004b635d  740a                   -je 0x4b6369
    if (cpu.flags.zf)
    {
        goto L_0x004b6369;
    }
    // 004b635f  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004b6361  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b6362  2eff1544444c00         -call dword ptr cs:[0x4c4444]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998212) /* 0x4c4444 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004b6369:
    // 004b6369  c7430400000000         -mov dword ptr [ebx + 4], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004b6370  c7430800000000         -mov dword ptr [ebx + 8], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004b6377  c7430c00000000         -mov dword ptr [ebx + 0xc], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 004b637e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b637f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6380  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6381  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b6382(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b6382);
    // 004b6382  b824795b00             -mov eax, 0x5b7924
    cpu.eax = 5994788 /*0x5b7924*/;
    // 004b6387  e97d000000             -jmp 0x4b6409
    return sub_4b6409(app, cpu);
}

/* align: skip  */
void Application::sub_4b638c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b638c);
    // 004b638c  b824795b00             -mov eax, 0x5b7924
    cpu.eax = 5994788 /*0x5b7924*/;
    // 004b6391  e9d9000000             -jmp 0x4b646f
    return sub_4b646f(app, cpu);
}

/* align: skip  */
void Application::sub_4b6396(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b6396);
    // 004b6396  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004b6399  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004b639c  0544795b00             +add eax, 0x5b7944
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5994820 /*0x5b7944*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b63a1  eb66                   -jmp 0x4b6409
    return sub_4b6409(app, cpu);
}

/* align: skip  */
void Application::sub_4b63a3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b63a3);
    // 004b63a3  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004b63a6  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004b63a9  0544795b00             +add eax, 0x5b7944
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5994820 /*0x5b7944*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b63ae  e9bc000000             -jmp 0x4b646f
    return sub_4b646f(app, cpu);
}

/* align: skip  */
void Application::sub_4b63b3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b63b3);
    // 004b63b3  e99dfbffff             -jmp 0x4b5f55
    return sub_4b5f55(app, cpu);
}

/* align: skip  */
void Application::sub_4b63b8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b63b8);
    // 004b63b8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b63b9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b63bb  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004b63be  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004b63c1  0544795b00             -add eax, 0x5b7944
    (cpu.eax) += x86::reg32(x86::sreg32(5994820 /*0x5b7944*/));
    // 004b63c6  e889ffffff             -call 0x4b6354
    cpu.esp -= 4;
    sub_4b6354(app, cpu);
    if (cpu.terminate) return;
    // 004b63cb  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b63cd  e8a1fcffff             -call 0x4b6073
    cpu.esp -= 4;
    sub_4b6073(app, cpu);
    if (cpu.terminate) return;
    // 004b63d2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b63d3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b63d4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b63d4);
    // 004b63d4  b8447a5b00             -mov eax, 0x5b7a44
    cpu.eax = 5995076 /*0x5b7a44*/;
    // 004b63d9  eb2e                   -jmp 0x4b6409
    return sub_4b6409(app, cpu);
}

/* align: skip  */
void Application::sub_4b63db(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b63db);
    // 004b63db  b8447a5b00             -mov eax, 0x5b7a44
    cpu.eax = 5995076 /*0x5b7a44*/;
    // 004b63e0  e98a000000             -jmp 0x4b646f
    return sub_4b646f(app, cpu);
}

/* align: skip  */
void Application::sub_4b63e5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b63e5);
    // 004b63e5  b834795b00             -mov eax, 0x5b7934
    cpu.eax = 5994804 /*0x5b7934*/;
    // 004b63ea  eb1d                   -jmp 0x4b6409
    return sub_4b6409(app, cpu);
}

/* align: skip  */
void Application::sub_4b63ec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b63ec);
    // 004b63ec  b834795b00             -mov eax, 0x5b7934
    cpu.eax = 5994804 /*0x5b7934*/;
    // 004b63f1  e979000000             -jmp 0x4b646f
    return sub_4b646f(app, cpu);
}

/* align: skip  */
void Application::sub_4b63f6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b63f6);
    // 004b63f6  b8647a5b00             -mov eax, 0x5b7a64
    cpu.eax = 5995108 /*0x5b7a64*/;
    // 004b63fb  eb0c                   -jmp 0x4b6409
    return sub_4b6409(app, cpu);
}

/* align: skip  */
void Application::sub_4b63fd(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b63fd);
    // 004b63fd  b8647a5b00             -mov eax, 0x5b7a64
    cpu.eax = 5995108 /*0x5b7a64*/;
    // 004b6402  eb6b                   -jmp 0x4b646f
    return sub_4b646f(app, cpu);
}

}
