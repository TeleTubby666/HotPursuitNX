#include "nfs2se.h"
#include <lib/thread.h>

namespace nfs2se
{

/* align: skip 0x00 0x00 0x00 */
void Application::sub_46e4b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046e4b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046e4b1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046e4b2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046e4b3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046e4b4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046e4b5  83ec1c                 -sub esp, 0x1c
    (cpu.esp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0046e4b8  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0046e4ba  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0046e4bc  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0046e4bf  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046e4c1  e82a040000             -call 0x46e8f0
    cpu.esp -= 4;
    sub_46e8f0(app, cpu);
    if (cpu.terminate) return;
    // 0046e4c6  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0046e4ca  8b530c                 -mov edx, dword ptr [ebx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 0046e4cd  db442418               -fild dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */))));
    // 0046e4d1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046e4d3  d95c2410               -fstp dword ptr [esp + 0x10]
    app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046e4d7  e814040000             -call 0x46e8f0
    cpu.esp -= 4;
    sub_46e8f0(app, cpu);
    if (cpu.terminate) return;
    // 0046e4dc  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0046e4e0  8b5310                 -mov edx, dword ptr [ebx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 0046e4e3  db442418               -fild dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */))));
    // 0046e4e7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046e4e9  d95c2414               -fstp dword ptr [esp + 0x14]
    app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046e4ed  e8fe030000             -call 0x46e8f0
    cpu.esp -= 4;
    sub_46e8f0(app, cpu);
    if (cpu.terminate) return;
    // 0046e4f2  d9442410               -fld dword ptr [esp + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 0046e4f6  8b5104                 -mov edx, dword ptr [ecx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0046e4f9  d84c2410               -fmul dword ptr [esp + 0x10]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(16) /* 0x10 */));
    // 0046e4fd  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0046e4ff  d9442414               -fld dword ptr [esp + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 0046e503  c1e704                 -shl edi, 4
    cpu.edi <<= 4 /*0x4*/ % 32;
    // 0046e506  d84c2414               -fmul dword ptr [esp + 0x14]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(20) /* 0x14 */));
    // 0046e50a  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046e50c  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0046e510  c1e706                 -shl edi, 6
    cpu.edi <<= 6 /*0x6*/ % 32;
    // 0046e513  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0046e515  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046e517  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0046e51b  c1e702                 -shl edi, 2
    cpu.edi <<= 2 /*0x2*/ % 32;
    // 0046e51e  8b510c                 -mov edx, dword ptr [ecx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0046e521  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046e523  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046e525  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 0046e528  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046e52a  8b7114                 -mov esi, dword ptr [ecx + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 0046e52d  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046e530  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 0046e533  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0046e536  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 0046e538  8d2c30                 -lea ebp, [eax + esi]
    cpu.ebp = x86::reg32(cpu.eax + cpu.esi * 1);
    // 0046e53b  8b5110                 -mov edx, dword ptr [ecx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0046e53e  d94500                 -fld dword ptr [ebp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp)));
    // 0046e541  d82490                 -fsub dword ptr [eax + edx*4]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.eax + cpu.edx * 4));
    // 0046e544  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0046e547  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0046e549  c1e505                 -shl ebp, 5
    cpu.ebp <<= 5 /*0x5*/ % 32;
    // 0046e54c  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046e54e  c1e502                 -shl ebp, 2
    cpu.ebp <<= 2 /*0x2*/ % 32;
    // 0046e551  8d042f                 -lea eax, [edi + ebp]
    cpu.eax = x86::reg32(cpu.edi + cpu.ebp * 1);
    // 0046e554  8d3c30                 -lea edi, [eax + esi]
    cpu.edi = x86::reg32(cpu.eax + cpu.esi * 1);
    // 0046e557  d827                   -fsub dword ptr [edi]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.edi));
    // 0046e559  8b39                   -mov edi, dword ptr [ecx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx);
    // 0046e55b  d80490                 -fadd dword ptr [eax + edx*4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + cpu.edx * 4));
    // 0046e55e  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0046e560  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0046e563  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 0046e565  c1e006                 -shl eax, 6
    cpu.eax <<= 6 /*0x6*/ % 32;
    // 0046e568  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 0046e56a  8b7c2404               -mov edi, dword ptr [esp + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046e56e  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046e571  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046e573  db442418               -fild dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */))));
    // 0046e577  897c2404               -mov dword ptr [esp + 4], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 0046e57b  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0046e57d  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 0046e580  d95c240c               -fstp dword ptr [esp + 0xc]
    app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046e584  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 0046e586  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0046e588  dec2                   -faddp st(2)
    cpu.fpu.st(2) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0046e58a  8d3c30                 -lea edi, [eax + esi]
    cpu.edi = x86::reg32(cpu.eax + cpu.esi * 1);
    // 0046e58d  d944240c               -fld dword ptr [esp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 0046e591  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0046e593  d827                   -fsub dword ptr [edi]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.edi));
    // 0046e595  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0046e597  d84c240c               -fmul dword ptr [esp + 0xc]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(12) /* 0xc */));
    // 0046e59b  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0046e59d  d80490                 -fadd dword ptr [eax + edx*4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax + cpu.edx * 4));
    // 0046e5a0  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046e5a4  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0046e5a6  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0046e5a8  dec2                   -faddp st(2)
    cpu.fpu.st(2) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0046e5aa  d80406                 -fadd dword ptr [esi + eax]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esi + cpu.eax * 1));
    // 0046e5ad  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0046e5af  d95c2404               -fstp dword ptr [esp + 4]
    app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046e5b3  d82490                 -fsub dword ptr [eax + edx*4]
    cpu.fpu.st(0) -= x86::Float(app->getMemory<float>(cpu.eax + cpu.edx * 4));
    // 0046e5b6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046e5b8  8b5304                 -mov edx, dword ptr [ebx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0046e5bb  d95c2408               -fstp dword ptr [esp + 8]
    app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046e5bf  e82c030000             -call 0x46e8f0
    cpu.esp -= 4;
    sub_46e8f0(app, cpu);
    if (cpu.terminate) return;
    // 0046e5c4  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0046e5c8  db442418               -fild dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */))));
    // 0046e5cc  d87c2404               -fdivr dword ptr [esp + 4]
    cpu.fpu.st(0) = x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(4) /* 0x4 */)) / cpu.fpu.st(0);
    // 0046e5d0  d86c2408               -fsubr dword ptr [esp + 8]
    cpu.fpu.st(0) = x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(8) /* 0x8 */)) - cpu.fpu.st(0);
    // 0046e5d4  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0046e5d7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e5d8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e5d9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e5da  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e5db  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e5dc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_46e5e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046e5e0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046e5e1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046e5e2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046e5e3  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046e5e6  80fa01                 +cmp dl, 1
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
    // 0046e5e9  737d                   -jae 0x46e668
    if (!cpu.flags.cf)
    {
        goto L_0x0046e668;
    }
    // 0046e5eb  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 0046e5ed  0f8553010000           -jne 0x46e746
    if (!cpu.flags.zf)
    {
        goto L_0x0046e746;
    }
    // 0046e5f3  8b7004                 -mov esi, dword ptr [eax + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0046e5f6  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0046e5f8  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 0046e5fb  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0046e5fd  c1e206                 -shl edx, 6
    cpu.edx <<= 6 /*0x6*/ % 32;
    // 0046e600  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0046e602  8b700c                 -mov esi, dword ptr [eax + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0046e605  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 0046e607  c1e505                 -shl ebp, 5
    cpu.ebp <<= 5 /*0x5*/ % 32;
    // 0046e60a  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0046e60d  01f5                   -add ebp, esi
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.esi));
    // 0046e60f  8d3c11                 -lea edi, [ecx + edx]
    cpu.edi = x86::reg32(cpu.ecx + cpu.edx * 1);
    // 0046e612  c1e502                 -shl ebp, 2
    cpu.ebp <<= 2 /*0x2*/ % 32;
    // 0046e615  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 0046e618  8d142f                 -lea edx, [edi + ebp]
    cpu.edx = x86::reg32(cpu.edi + cpu.ebp * 1);
    // 0046e61b  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0046e61d  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0046e620  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0046e624  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0046e626  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 0046e629  01d6                   -add esi, edx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046e62b  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 0046e62e  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046e632  01f7                   -add edi, esi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.esi));
    // 0046e634  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 0046e636  2b141f                 -sub edx, dword ptr [edi + ebx]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 1)));
    // 0046e639  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0046e63b  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0046e63d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046e63f  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0046e642  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046e644  c1e006                 -shl eax, 6
    cpu.eax <<= 6 /*0x6*/ % 32;
    // 0046e647  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046e649  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046e64c  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046e64e  8d0429                 -lea eax, [ecx + ebp]
    cpu.eax = x86::reg32(cpu.ecx + cpu.ebp * 1);
    // 0046e651  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0046e653  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0046e655  8b2c03                 -mov ebp, dword ptr [ebx + eax]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + cpu.eax * 1);
    // 0046e658  8b0419                 -mov eax, dword ptr [ecx + ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + cpu.ebx * 1);
    // 0046e65b  29ea                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0046e65d  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046e65f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046e661  83c408                 +add esp, 8
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
    // 0046e664  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e665  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e666  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e667  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046e668:
    // 0046e668  7668                   -jbe 0x46e6d2
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0046e6d2;
    }
    // 0046e66a  80fa02                 +cmp dl, 2
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
    // 0046e66d  0f85d3000000           -jne 0x46e746
    if (!cpu.flags.zf)
    {
        goto L_0x0046e746;
    }
    // 0046e673  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0046e675  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 0046e678  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0046e67a  c1e206                 -shl edx, 6
    cpu.edx <<= 6 /*0x6*/ % 32;
    // 0046e67d  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0046e67f  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0046e682  8d1c11                 -lea ebx, [ecx + edx]
    cpu.ebx = x86::reg32(cpu.ecx + cpu.edx * 1);
    // 0046e685  8b480c                 -mov ecx, dword ptr [eax + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0046e688  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0046e68a  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 0046e68d  8b7010                 -mov esi, dword ptr [eax + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0046e690  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046e692  8b4814                 -mov ecx, dword ptr [eax + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 0046e695  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0046e698  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 0046e69b  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0046e69d  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 0046e6a0  8d2c0a                 -lea ebp, [edx + ecx]
    cpu.ebp = x86::reg32(cpu.edx + cpu.ecx * 1);
    // 0046e6a3  8d3c32                 -lea edi, [edx + esi]
    cpu.edi = x86::reg32(cpu.edx + cpu.esi * 1);
    // 0046e6a6  8b5500                 -mov edx, dword ptr [ebp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp);
    // 0046e6a9  8b2f                   -mov ebp, dword ptr [edi]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edi);
    // 0046e6ab  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0046e6ad  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0046e6b0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046e6b2  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 0046e6b5  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046e6b7  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046e6ba  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0046e6bc  29ef                   -sub edi, ebp
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0046e6be  8b1401                 -mov edx, dword ptr [ecx + eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 1);
    // 0046e6c1  8b0c06                 -mov ecx, dword ptr [esi + eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + cpu.eax * 1);
    // 0046e6c4  29d7                   -sub edi, edx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0046e6c6  8d140f                 -lea edx, [edi + ecx]
    cpu.edx = x86::reg32(cpu.edi + cpu.ecx * 1);
    // 0046e6c9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046e6cb  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046e6ce  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e6cf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e6d0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e6d1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046e6d2:
    // 0046e6d2  8b7004                 -mov esi, dword ptr [eax + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0046e6d5  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0046e6d7  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 0046e6da  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0046e6dc  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0046e6de  c1e705                 -shl edi, 5
    cpu.edi <<= 5 /*0x5*/ % 32;
    // 0046e6e1  c1e206                 -shl edx, 6
    cpu.edx <<= 6 /*0x6*/ % 32;
    // 0046e6e4  01df                   -add edi, ebx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0046e6e6  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0046e6e8  c1e702                 -shl edi, 2
    cpu.edi <<= 2 /*0x2*/ % 32;
    // 0046e6eb  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0046e6ee  8b5814                 -mov ebx, dword ptr [eax + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 0046e6f1  8d3411                 -lea esi, [ecx + edx]
    cpu.esi = x86::reg32(cpu.ecx + cpu.edx * 1);
    // 0046e6f4  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 0046e6f7  8d143e                 -lea edx, [esi + edi]
    cpu.edx = x86::reg32(cpu.esi + cpu.edi * 1);
    // 0046e6fa  8d341a                 -lea esi, [edx + ebx]
    cpu.esi = x86::reg32(cpu.edx + cpu.ebx * 1);
    // 0046e6fd  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 0046e700  8b7010                 -mov esi, dword ptr [eax + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0046e703  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 0046e706  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0046e708  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0046e70c  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0046e70f  8b6c2404               -mov ebp, dword ptr [esp + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046e713  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 0046e715  2b5500                 -sub edx, dword ptr [ebp]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp)));
    // 0046e718  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0046e71a  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0046e71c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046e71e  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0046e721  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046e723  c1e006                 -shl eax, 6
    cpu.eax <<= 6 /*0x6*/ % 32;
    // 0046e726  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046e728  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046e72b  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046e72d  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 0046e72f  8d1418                 -lea edx, [eax + ebx]
    cpu.edx = x86::reg32(cpu.eax + cpu.ebx * 1);
    // 0046e732  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 0046e734  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0046e736  8b3c06                 -mov edi, dword ptr [esi + eax]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + cpu.eax * 1);
    // 0046e739  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046e73b  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0046e73d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046e73f  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046e742  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e743  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e744  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e745  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046e746:
    // 0046e746  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046e748  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046e74a  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046e74d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e74e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e74f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e750  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46e760(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046e760  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046e761  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046e762  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046e763  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046e764  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046e767  80fa01                 +cmp dl, 1
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
    // 0046e76a  0f8383000000           -jae 0x46e7f3
    if (!cpu.flags.cf)
    {
        goto L_0x0046e7f3;
    }
    // 0046e770  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 0046e772  0f855e010000           -jne 0x46e8d6
    if (!cpu.flags.zf)
    {
        goto L_0x0046e8d6;
    }
    // 0046e778  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0046e77b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0046e77d  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 0046e780  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046e782  c1e206                 -shl edx, 6
    cpu.edx <<= 6 /*0x6*/ % 32;
    // 0046e785  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046e787  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0046e78a  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 0046e78c  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0046e78f  c1e505                 -shl ebp, 5
    cpu.ebp <<= 5 /*0x5*/ % 32;
    // 0046e792  8d3413                 -lea esi, [ebx + edx]
    cpu.esi = x86::reg32(cpu.ebx + cpu.edx * 1);
    // 0046e795  01cd                   -add ebp, ecx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046e797  8b4810                 -mov ecx, dword ptr [eax + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0046e79a  c1e502                 -shl ebp, 2
    cpu.ebp <<= 2 /*0x2*/ % 32;
    // 0046e79d  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 0046e7a0  8d142e                 -lea edx, [esi + ebp]
    cpu.edx = x86::reg32(cpu.esi + cpu.ebp * 1);
    // 0046e7a3  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046e7a5  8b780c                 -mov edi, dword ptr [eax + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0046e7a8  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0046e7ac  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0046e7ae  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 0046e7b1  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046e7b3  c1e702                 -shl edi, 2
    cpu.edi <<= 2 /*0x2*/ % 32;
    // 0046e7b6  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046e7ba  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 0046e7bc  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 0046e7be  2b1431                 -sub edx, dword ptr [ecx + esi]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + cpu.esi * 1)));
    // 0046e7c1  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0046e7c3  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0046e7c5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046e7c7  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0046e7ca  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046e7cc  c1e006                 -shl eax, 6
    cpu.eax <<= 6 /*0x6*/ % 32;
    // 0046e7cf  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046e7d1  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046e7d4  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046e7d6  8d043b                 -lea eax, [ebx + edi]
    cpu.eax = x86::reg32(cpu.ebx + cpu.edi * 1);
    // 0046e7d9  01eb                   -add ebx, ebp
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0046e7db  8b3c01                 -mov edi, dword ptr [ecx + eax]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 1);
    // 0046e7de  8d140b                 -lea edx, [ebx + ecx]
    cpu.edx = x86::reg32(cpu.ebx + cpu.ecx * 1);
    // 0046e7e1  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 0046e7e3  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx);
    // 0046e7e5  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0046e7e7  29ea                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0046e7e9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046e7eb  83c408                 +add esp, 8
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
    // 0046e7ee  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e7ef  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e7f0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e7f1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e7f2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046e7f3:
    // 0046e7f3  7669                   -jbe 0x46e85e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0046e85e;
    }
    // 0046e7f5  80fa02                 +cmp dl, 2
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
    // 0046e7f8  0f85d8000000           -jne 0x46e8d6
    if (!cpu.flags.zf)
    {
        goto L_0x0046e8d6;
    }
    // 0046e7fe  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0046e800  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0046e802  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 0046e805  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046e807  c1e206                 -shl edx, 6
    cpu.edx <<= 6 /*0x6*/ % 32;
    // 0046e80a  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046e80c  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0046e80f  8b480c                 -mov ecx, dword ptr [eax + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0046e812  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046e814  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0046e816  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 0046e819  8b7010                 -mov esi, dword ptr [eax + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0046e81c  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046e81e  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 0046e821  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0046e824  8b4814                 -mov ecx, dword ptr [eax + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 0046e827  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0046e829  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 0046e82c  8d2c32                 -lea ebp, [edx + esi]
    cpu.ebp = x86::reg32(cpu.edx + cpu.esi * 1);
    // 0046e82f  8d3c0a                 -lea edi, [edx + ecx]
    cpu.edi = x86::reg32(cpu.edx + cpu.ecx * 1);
    // 0046e832  8b5500                 -mov edx, dword ptr [ebp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp);
    // 0046e835  8b2f                   -mov ebp, dword ptr [edi]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edi);
    // 0046e837  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0046e839  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0046e83c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046e83e  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 0046e841  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046e843  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046e846  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0046e848  29ef                   -sub edi, ebp
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0046e84a  8b1401                 -mov edx, dword ptr [ecx + eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 1);
    // 0046e84d  8b0c06                 -mov ecx, dword ptr [esi + eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + cpu.eax * 1);
    // 0046e850  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0046e852  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046e854  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046e856  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046e859  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e85a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e85b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e85c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e85d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046e85e:
    // 0046e85e  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0046e861  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0046e863  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 0046e866  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046e868  c1e206                 -shl edx, 6
    cpu.edx <<= 6 /*0x6*/ % 32;
    // 0046e86b  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046e86d  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0046e870  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0046e873  8d3413                 -lea esi, [ebx + edx]
    cpu.esi = x86::reg32(cpu.ebx + cpu.edx * 1);
    // 0046e876  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0046e878  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 0046e87b  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046e87d  8b7810                 -mov edi, dword ptr [eax + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0046e880  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 0046e883  c1e702                 -shl edi, 2
    cpu.edi <<= 2 /*0x2*/ % 32;
    // 0046e886  8d140e                 -lea edx, [esi + ecx]
    cpu.edx = x86::reg32(cpu.esi + cpu.ecx * 1);
    // 0046e889  8d343a                 -lea esi, [edx + edi]
    cpu.esi = x86::reg32(cpu.edx + cpu.edi * 1);
    // 0046e88c  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 0046e88f  8b7014                 -mov esi, dword ptr [eax + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 0046e892  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 0046e895  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0046e897  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0046e89b  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0046e89e  8b6c2404               -mov ebp, dword ptr [esp + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046e8a2  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 0046e8a4  2b5500                 -sub edx, dword ptr [ebp]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp)));
    // 0046e8a7  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0046e8a9  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0046e8ab  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046e8ad  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0046e8b0  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046e8b2  c1e006                 -shl eax, 6
    cpu.eax <<= 6 /*0x6*/ % 32;
    // 0046e8b5  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046e8b7  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046e8ba  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046e8bc  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0046e8be  8b1c31                 -mov ebx, dword ptr [ecx + esi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + cpu.esi * 1);
    // 0046e8c1  8d1439                 -lea edx, [ecx + edi]
    cpu.edx = x86::reg32(cpu.ecx + cpu.edi * 1);
    // 0046e8c4  01dd                   -add ebp, ebx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0046e8c6  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 0046e8c8  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0046e8ca  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0046e8cc  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046e8ce  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046e8d1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e8d2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e8d3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e8d4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e8d5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046e8d6:
    // 0046e8d6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046e8d8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046e8da  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046e8dd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e8de  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e8df  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e8e0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e8e1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46e8f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046e8f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046e8f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046e8f2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046e8f3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046e8f4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046e8f5  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046e8f8  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0046e8fa  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0046e8fd  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0046e8ff  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 0046e902  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046e904  c1e206                 -shl edx, 6
    cpu.edx <<= 6 /*0x6*/ % 32;
    // 0046e907  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046e909  8b480c                 -mov ecx, dword ptr [eax + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0046e90c  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0046e90f  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0046e911  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0046e913  c1e705                 -shl edi, 5
    cpu.edi <<= 5 /*0x5*/ % 32;
    // 0046e916  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0046e919  01cf                   -add edi, ecx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046e91b  8b4814                 -mov ecx, dword ptr [eax + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 0046e91e  c1e702                 -shl edi, 2
    cpu.edi <<= 2 /*0x2*/ % 32;
    // 0046e921  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 0046e924  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0046e926  8d1c0a                 -lea ebx, [edx + ecx]
    cpu.ebx = x86::reg32(cpu.edx + cpu.ecx * 1);
    // 0046e929  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0046e92d  8b5810                 -mov ebx, dword ptr [eax + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0046e930  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 0046e933  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0046e935  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0046e939  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046e93d  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 0046e93f  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0046e943  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046e947  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046e94b  2b2a                   -sub ebp, dword ptr [edx]
    (cpu.ebp) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
    // 0046e94d  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0046e950  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0046e954  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 0046e958  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046e95c  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 0046e95f  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0046e961  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0046e964  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0046e968  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0046e96b  03542408               -add edx, dword ptr [esp + 8]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 0046e96f  8b6c2404               -mov ebp, dword ptr [esp + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046e973  2b2c11                 -sub ebp, dword ptr [ecx + edx]
    (cpu.ebp) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 1)));
    // 0046e976  032c1a                 -add ebp, dword ptr [edx + ebx]
    (cpu.ebp) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + cpu.ebx * 1)));
    // 0046e979  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0046e97b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046e97d  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0046e980  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046e982  c1e006                 -shl eax, 6
    cpu.eax <<= 6 /*0x6*/ % 32;
    // 0046e985  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046e987  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046e98a  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0046e98c  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046e98e  8d140f                 -lea edx, [edi + ecx]
    cpu.edx = x86::reg32(cpu.edi + cpu.ecx * 1);
    // 0046e991  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
    // 0046e993  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx);
    // 0046e995  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0046e997  8b341f                 -mov esi, dword ptr [edi + ebx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 1);
    // 0046e99a  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046e99e  29ea                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0046e9a0  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 0046e9a2  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0046e9a4  031401                 -add edx, dword ptr [ecx + eax]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 1)));
    // 0046e9a7  8b0c03                 -mov ecx, dword ptr [ebx + eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + cpu.eax * 1);
    // 0046e9aa  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046e9ac  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046e9ae  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046e9b1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e9b2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e9b3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e9b4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e9b5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e9b6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46e9c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046e9c0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046e9c1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046e9c2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046e9c3  81ecc4020000           -sub esp, 0x2c4
    (cpu.esp) -= x86::reg32(x86::sreg32(708 /*0x2c4*/));
    // 0046e9c9  898424ac020000         -mov dword ptr [esp + 0x2ac], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(684) /* 0x2ac */) = cpu.eax;
    // 0046e9d0  8994249c020000         -mov dword ptr [esp + 0x29c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(668) /* 0x29c */) = cpu.edx;
    // 0046e9d7  899c2494020000         -mov dword ptr [esp + 0x294], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(660) /* 0x294 */) = cpu.ebx;
    // 0046e9de  898c2498020000         -mov dword ptr [esp + 0x298], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(664) /* 0x298 */) = cpu.ecx;
    // 0046e9e5  c68424c002000001       -mov byte ptr [esp + 0x2c0], 1
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(704) /* 0x2c0 */) = 1 /*0x1*/;
L_0x0046e9ed:
    // 0046e9ed  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
L_0x0046e9ef:
    // 0046e9ef  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046e9f1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046e9f3  898c24bc020000         -mov dword ptr [esp + 0x2bc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(700) /* 0x2bc */) = cpu.ecx;
    // 0046e9fa  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 0046e9fc  db8424bc020000         -fild dword ptr [esp + 0x2bc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(700) /* 0x2bc */))));
    // 0046ea03  fec2                   -inc dl
    (cpu.dl)++;
    // 0046ea05  898c8410020000         -mov dword ptr [esp + eax*4 + 0x210], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(528) /* 0x210 */ + cpu.eax * 4) = cpu.ecx;
    // 0046ea0c  898c8408010000         -mov dword ptr [esp + eax*4 + 0x108], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(264) /* 0x108 */ + cpu.eax * 4) = cpu.ecx;
    // 0046ea13  898c8484000000         -mov dword ptr [esp + eax*4 + 0x84], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */ + cpu.eax * 4) = cpu.ecx;
    // 0046ea1a  898c848c010000         -mov dword ptr [esp + eax*4 + 0x18c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(396) /* 0x18c */ + cpu.eax * 4) = cpu.ecx;
    // 0046ea21  d91c84                 -fstp dword ptr [esp + eax*4]
    app->getMemory<float>(cpu.esp + cpu.eax * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046ea24  80fa20                 +cmp dl, 0x20
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
    // 0046ea27  76c6                   -jbe 0x46e9ef
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0046e9ef;
    }
    // 0046ea29  b701                   -mov bh, 1
    cpu.bh = 1 /*0x1*/;
L_0x0046ea2b:
    // 0046ea2b  b301                   -mov bl, 1
    cpu.bl = 1 /*0x1*/;
    // 0046ea2d  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0046ea2f  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0046ea31  89bc24b4020000         -mov dword ptr [esp + 0x2b4], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(692) /* 0x2b4 */) = cpu.edi;
    // 0046ea38  89bc24b8020000         -mov dword ptr [esp + 0x2b8], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(696) /* 0x2b8 */) = cpu.edi;
    // 0046ea3f  89bc24b0020000         -mov dword ptr [esp + 0x2b0], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(688) /* 0x2b0 */) = cpu.edi;
    // 0046ea46  d98424b0020000         -fld dword ptr [esp + 0x2b0]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + x86::reg32(688) /* 0x2b0 */)));
L_0x0046ea4d:
    // 0046ea4d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046ea4f  8a8424c0020000         -mov al, byte ptr [esp + 0x2c0]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(704) /* 0x2c0 */);
    // 0046ea56  69d041040000           -imul edx, eax, 0x441
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(1089 /*0x441*/)));
    // 0046ea5c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046ea5e  88f8                   -mov al, bh
    cpu.al = cpu.bh;
    // 0046ea60  6bc021                 -imul eax, eax, 0x21
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(33 /*0x21*/)));
    // 0046ea63  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046ea65  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046ea67  88d8                   -mov al, bl
    cpu.al = cpu.bl;
    // 0046ea69  8bac24ac020000         -mov ebp, dword ptr [esp + 0x2ac]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(684) /* 0x2ac */);
    // 0046ea70  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046ea72  898424bc020000         -mov dword ptr [esp + 0x2bc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(700) /* 0x2bc */) = cpu.eax;
    // 0046ea79  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0046ea80  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046ea82  8b4d00                 -mov ecx, dword ptr [ebp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp);
    // 0046ea85  018c24b8020000         -add dword ptr [esp + 0x2b8], ecx
    (app->getMemory<x86::reg32>(cpu.esp + x86::reg32(696) /* 0x2b8 */)) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046ea8c  8b8c249c020000         -mov ecx, dword ptr [esp + 0x29c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(668) /* 0x29c */);
    // 0046ea93  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046ea95  898c24a0020000         -mov dword ptr [esp + 0x2a0], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(672) /* 0x2a0 */) = cpu.ecx;
    // 0046ea9c  0331                   -add esi, dword ptr [ecx]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx)));
    // 0046ea9e  8b8c2494020000         -mov ecx, dword ptr [esp + 0x294]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(660) /* 0x294 */);
    // 0046eaa5  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046eaa7  898c24a4020000         -mov dword ptr [esp + 0x2a4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(676) /* 0x2a4 */) = cpu.ecx;
    // 0046eaae  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0046eab0  018c24b4020000         -add dword ptr [esp + 0x2b4], ecx
    (app->getMemory<x86::reg32>(cpu.esp + x86::reg32(692) /* 0x2b4 */)) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046eab7  8b8c2498020000         -mov ecx, dword ptr [esp + 0x298]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(664) /* 0x298 */);
    // 0046eabe  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046eac0  898c24a8020000         -mov dword ptr [esp + 0x2a8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(680) /* 0x2a8 */) = cpu.ecx;
    // 0046eac7  0339                   -add edi, dword ptr [ecx]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx)));
    // 0046eac9  8b8c24d4020000         -mov ecx, dword ptr [esp + 0x2d4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(724) /* 0x2d4 */);
    // 0046ead0  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 0046ead2  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046ead4  8b8424bc020000         -mov eax, dword ptr [esp + 0x2bc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(700) /* 0x2bc */);
    // 0046eadb  898c24bc020000         -mov dword ptr [esp + 0x2bc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(700) /* 0x2bc */) = cpu.ecx;
    // 0046eae2  d801                   -fadd dword ptr [ecx]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ecx));
    // 0046eae4  8b8c24b8020000         -mov ecx, dword ptr [esp + 0x2b8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(696) /* 0x2b8 */);
    // 0046eaeb  018c848c010000         -add dword ptr [esp + eax*4 + 0x18c], ecx
    (app->getMemory<x86::reg32>(cpu.esp + x86::reg32(396) /* 0x18c */ + cpu.eax * 4)) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046eaf2  8b8c8484000000         -mov ecx, dword ptr [esp + eax*4 + 0x84]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */ + cpu.eax * 4);
    // 0046eaf9  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0046eafb  81ea41040000           -sub edx, 0x441
    (cpu.edx) -= x86::reg32(x86::sreg32(1089 /*0x441*/));
    // 0046eb01  898c8484000000         -mov dword ptr [esp + eax*4 + 0x84], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */ + cpu.eax * 4) = cpu.ecx;
    // 0046eb08  8b8c24b4020000         -mov ecx, dword ptr [esp + 0x2b4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(692) /* 0x2b4 */);
    // 0046eb0f  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0046eb12  018c8408010000         -add dword ptr [esp + eax*4 + 0x108], ecx
    (app->getMemory<x86::reg32>(cpu.esp + x86::reg32(264) /* 0x108 */ + cpu.eax * 4)) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046eb19  8b8c8410020000         -mov ecx, dword ptr [esp + eax*4 + 0x210]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(528) /* 0x210 */ + cpu.eax * 4);
    // 0046eb20  d90484                 -fld dword ptr [esp + eax*4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esp + cpu.eax * 4)));
    // 0046eb23  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0046eb25  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 0046eb27  ddda                   -fstp st(2)
    cpu.fpu.st(2) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046eb29  d8c1                   -fadd st(1)
    cpu.fpu.st(0) += x86::Float(cpu.fpu.st(1));
    // 0046eb2b  898c8410020000         -mov dword ptr [esp + eax*4 + 0x210], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(528) /* 0x210 */ + cpu.eax * 4) = cpu.ecx;
    // 0046eb32  8b8c24ac020000         -mov ecx, dword ptr [esp + 0x2ac]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(684) /* 0x2ac */);
    // 0046eb39  d91c84                 -fstp dword ptr [esp + eax*4]
    app->getMemory<float>(cpu.esp + cpu.eax * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046eb3c  8b0c11                 -mov ecx, dword ptr [ecx + edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 1);
    // 0046eb3f  038c848c010000         -add ecx, dword ptr [esp + eax*4 + 0x18c]
    (cpu.ecx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(396) /* 0x18c */ + cpu.eax * 4)));
    // 0046eb46  894d00                 -mov dword ptr [ebp], ecx
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.ecx;
    // 0046eb49  8b8c249c020000         -mov ecx, dword ptr [esp + 0x29c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(668) /* 0x29c */);
    // 0046eb50  8bac8484000000         -mov ebp, dword ptr [esp + eax*4 + 0x84]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */ + cpu.eax * 4);
    // 0046eb57  8b0c11                 -mov ecx, dword ptr [ecx + edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 1);
    // 0046eb5a  01e9                   -add ecx, ebp
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0046eb5c  8bac24a0020000         -mov ebp, dword ptr [esp + 0x2a0]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(672) /* 0x2a0 */);
    // 0046eb63  894d00                 -mov dword ptr [ebp], ecx
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.ecx;
    // 0046eb66  8b8c2494020000         -mov ecx, dword ptr [esp + 0x294]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(660) /* 0x294 */);
    // 0046eb6d  8bac8408010000         -mov ebp, dword ptr [esp + eax*4 + 0x108]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(264) /* 0x108 */ + cpu.eax * 4);
    // 0046eb74  8b0c11                 -mov ecx, dword ptr [ecx + edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 1);
    // 0046eb77  01e9                   -add ecx, ebp
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0046eb79  8bac24a4020000         -mov ebp, dword ptr [esp + 0x2a4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(676) /* 0x2a4 */);
    // 0046eb80  894d00                 -mov dword ptr [ebp], ecx
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.ecx;
    // 0046eb83  8b8c2498020000         -mov ecx, dword ptr [esp + 0x298]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(664) /* 0x298 */);
    // 0046eb8a  8bac8410020000         -mov ebp, dword ptr [esp + eax*4 + 0x210]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(528) /* 0x210 */ + cpu.eax * 4);
    // 0046eb91  8b0c11                 -mov ecx, dword ptr [ecx + edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 1);
    // 0046eb94  01e9                   -add ecx, ebp
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0046eb96  8bac24a8020000         -mov ebp, dword ptr [esp + 0x2a8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(680) /* 0x2a8 */);
    // 0046eb9d  894d00                 -mov dword ptr [ebp], ecx
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.ecx;
    // 0046eba0  039424d4020000         -add edx, dword ptr [esp + 0x2d4]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(724) /* 0x2d4 */)));
    // 0046eba7  d902                   -fld dword ptr [edx]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edx)));
    // 0046eba9  d80484                 -fadd dword ptr [esp + eax*4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.esp + cpu.eax * 4));
    // 0046ebac  8b8424bc020000         -mov eax, dword ptr [esp + 0x2bc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(700) /* 0x2bc */);
    // 0046ebb3  fec3                   -inc bl
    (cpu.bl)++;
    // 0046ebb5  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046ebb7  80fb20                 +cmp bl, 0x20
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(32 /*0x20*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0046ebba  0f868dfeffff           -jbe 0x46ea4d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0046ea4d;
    }
    // 0046ebc0  fec7                   -inc bh
    (cpu.bh)++;
    // 0046ebc2  d99c24b0020000         -fstp dword ptr [esp + 0x2b0]
    app->getMemory<float>(cpu.esp + x86::reg32(688) /* 0x2b0 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046ebc9  80ff20                 +cmp bh, 0x20
    {
        x86::reg8 tmp1 = cpu.bh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(32 /*0x20*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0046ebcc  0f8659feffff           -jbe 0x46ea2b
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0046ea2b;
    }
    // 0046ebd2  8a9424c0020000         -mov dl, byte ptr [esp + 0x2c0]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(704) /* 0x2c0 */);
    // 0046ebd9  fec2                   -inc dl
    (cpu.dl)++;
    // 0046ebdb  889424c0020000         -mov byte ptr [esp + 0x2c0], dl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(704) /* 0x2c0 */) = cpu.dl;
    // 0046ebe2  80fa20                 +cmp dl, 0x20
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
    // 0046ebe5  0f8602feffff           -jbe 0x46e9ed
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0046e9ed;
    }
    // 0046ebeb  81c4c4020000           -add esp, 0x2c4
    (cpu.esp) += x86::reg32(x86::sreg32(708 /*0x2c4*/));
    // 0046ebf1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ebf2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ebf3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ebf4  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46ec00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046ec00  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046ec01  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046ec02  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046ec03  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0046ec06  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0046ec0a  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0046ec0e  895c2410               -mov dword ptr [esp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 0046ec12  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0046ec16  8b4814                 -mov ecx, dword ptr [eax + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 0046ec19  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0046ec1b:
    // 0046ec1b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046ec1d  8a4101                 -mov al, byte ptr [ecx + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 0046ec20  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0046ec23  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046ec25  8a4102                 -mov al, byte ptr [ecx + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 0046ec28  0fb631                 -movzx esi, byte ptr [ecx]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.ecx));
    // 0046ec2b  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0046ec2f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0046ec31  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 0046ec34  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0046ec37  69d241040000           -imul edx, edx, 0x441
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(1089 /*0x441*/)));
    // 0046ec3d  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0046ec40  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 0046ec43  40                     -inc eax
    (cpu.eax)++;
    // 0046ec44  6bc021                 -imul eax, eax, 0x21
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(33 /*0x21*/)));
    // 0046ec47  8b7c2404               -mov edi, dword ptr [esp + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046ec4b  c1ff03                 -sar edi, 3
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (3 /*0x3*/ % 32));
    // 0046ec4e  47                     -inc edi
    (cpu.edi)++;
    // 0046ec4f  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046ec51  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046ec55  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 0046ec57  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046ec5b  8b5218                 -mov edx, dword ptr [edx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0046ec5e  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046ec61  8b141a                 -mov edx, dword ptr [edx + ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + cpu.ebx * 1);
    // 0046ec64  011407                 -add dword ptr [edi + eax], edx
    (app->getMemory<x86::reg32>(cpu.edi + cpu.eax * 1)) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046ec67  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 0046ec69  0fafea                 -imul ebp, edx
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0046ec6c  8b7c2410               -mov edi, dword ptr [esp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046ec70  012c07                 -add dword ptr [edi + eax], ebp
    (app->getMemory<x86::reg32>(cpu.edi + cpu.eax * 1)) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0046ec73  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 0046ec76  0fafea                 -imul ebp, edx
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0046ec79  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046ec7d  012c07                 -add dword ptr [edi + eax], ebp
    (app->getMemory<x86::reg32>(cpu.edi + cpu.eax * 1)) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0046ec80  8b6c2404               -mov ebp, dword ptr [esp + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046ec84  0fafea                 -imul ebp, edx
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0046ec87  8b7c2430               -mov edi, dword ptr [esp + 0x30]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0046ec8b  012c07                 -add dword ptr [edi + eax], ebp
    (app->getMemory<x86::reg32>(cpu.edi + cpu.eax * 1)) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0046ec8e  8b7c2434               -mov edi, dword ptr [esp + 0x34]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0046ec92  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 0046ec95  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046ec97  a1e4ab5100             -mov eax, dword ptr [0x51abe4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5352420) /* 0x51abe4 */);
    // 0046ec9c  8d2c30                 -lea ebp, [eax + esi]
    cpu.ebp = x86::reg32(cpu.eax + cpu.esi * 1);
    // 0046ec9f  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 0046eca2  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 0046eca5  896c2418               -mov dword ptr [esp + 0x18], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ebp;
    // 0046eca9  8d2c30                 -lea ebp, [eax + esi]
    cpu.ebp = x86::reg32(cpu.eax + cpu.esi * 1);
    // 0046ecac  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046ecb0  8b36                   -mov esi, dword ptr [esi]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi);
    // 0046ecb2  89742418               -mov dword ptr [esp + 0x18], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 0046ecb6  8b7500                 -mov esi, dword ptr [ebp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp);
    // 0046ecb9  8b6c2418               -mov ebp, dword ptr [esp + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046ecbd  01f5                   -add ebp, esi
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.esi));
    // 0046ecbf  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046ecc3  032cb0                 -add ebp, dword ptr [eax + esi*4]
    (cpu.ebp) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4)));
    // 0046ecc6  896c2418               -mov dword ptr [esp + 0x18], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ebp;
    // 0046ecca  8954241c               -mov dword ptr [esp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 0046ecce  db442418               -fild dword ptr [esp + 0x18]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */))));
    // 0046ecd2  db44241c               -fild dword ptr [esp + 0x1c]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */))));
    // 0046ecd6  dec9                   -fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 0046ecd8  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0046ecdb  d807                   -fadd dword ptr [edi]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edi));
    // 0046ecdd  83c103                 -add ecx, 3
    (cpu.ecx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0046ece0  d91f                   -fstp dword ptr [edi]
    app->getMemory<float>(cpu.edi) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 0046ece2  81fbfc030000           +cmp ebx, 0x3fc
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1020 /*0x3fc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046ece8  0f852dffffff           -jne 0x46ec1b
    if (!cpu.flags.zf)
    {
        goto L_0x0046ec1b;
    }
    // 0046ecee  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0046ecf1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ecf2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ecf3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ecf4  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46ed00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046ed00  a1e4ab5100             -mov eax, dword ptr [0x51abe4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5352420) /* 0x51abe4 */);
    // 0046ed05  e982b90000             -jmp 0x47a68c
    return sub_47a68c(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46ed10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046ed10  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046ed11  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046ed12  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046ed13  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046ed14  8b35e4ab5100           -mov esi, dword ptr [0x51abe4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5352420) /* 0x51abe4 */);
    // 0046ed1a  ba04e64b00             -mov edx, 0x4be604
    cpu.edx = 4974084 /*0x4be604*/;
    // 0046ed1f  b942000000             -mov ecx, 0x42
    cpu.ecx = 66 /*0x42*/;
    // 0046ed24  bb20000000             -mov ebx, 0x20
    cpu.ebx = 32 /*0x20*/;
    // 0046ed29  b820e64b00             -mov eax, 0x4be620
    cpu.eax = 4974112 /*0x4be620*/;
    // 0046ed2e  891578a64c00           -mov dword ptr [0x4ca678], edx
    app->getMemory<x86::reg32>(x86::reg32(5023352) /* 0x4ca678 */) = cpu.edx;
    // 0046ed34  ba00040000             -mov edx, 0x400
    cpu.edx = 1024 /*0x400*/;
    // 0046ed39  890d7ca64c00           -mov dword ptr [0x4ca67c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5023356) /* 0x4ca67c */) = cpu.ecx;
    // 0046ed3f  e8e4b40000             -call 0x47a228
    cpu.esp -= 4;
    sub_47a228(app, cpu);
    if (cpu.terminate) return;
    // 0046ed44  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046ed46  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046ed48  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0046ed4a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0046ed4c:
    // 0046ed4c  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0046ed4e  0fafd8                 -imul ebx, eax
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0046ed51  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0046ed54  40                     -inc eax
    (cpu.eax)++;
    // 0046ed55  895c11fc               -mov dword ptr [ecx + edx - 4], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */ + cpu.edx * 1) = cpu.ebx;
    // 0046ed59  3d00010000             +cmp eax, 0x100
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
    // 0046ed5e  7cec                   -jl 0x46ed4c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046ed4c;
    }
    // 0046ed60  8935e4ab5100           -mov dword ptr [0x51abe4], esi
    app->getMemory<x86::reg32>(x86::reg32(5352420) /* 0x51abe4 */) = cpu.esi;
    // 0046ed66  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ed67  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ed68  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ed69  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ed6a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46ed70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046ed70  a1ecab5100             -mov eax, dword ptr [0x51abec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5352428) /* 0x51abec */);
    // 0046ed75  e912b90000             -jmp 0x47a68c
    return sub_47a68c(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46ed80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046ed80  a1ecab5100             -mov eax, dword ptr [0x51abec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5352428) /* 0x51abec */);
    // 0046ed85  e802b90000             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
    // 0046ed8a  e901000000             -jmp 0x46ed90
    return sub_46ed90(app, cpu);
}

/* align: skip 0x00 */
void Application::sub_46ed90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046ed90  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046ed91  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046ed92  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046ed93  ba44e64b00             -mov edx, 0x4be644
    cpu.edx = 4974148 /*0x4be644*/;
    // 0046ed98  b91b010000             -mov ecx, 0x11b
    cpu.ecx = 283 /*0x11b*/;
    // 0046ed9d  b864e64b00             -mov eax, 0x4be664
    cpu.eax = 4974180 /*0x4be664*/;
    // 0046eda2  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046eda4  891578a64c00           -mov dword ptr [0x4ca678], edx
    app->getMemory<x86::reg32>(x86::reg32(5023352) /* 0x4ca678 */) = cpu.edx;
    // 0046edaa  ba00340000             -mov edx, 0x3400
    cpu.edx = 13312 /*0x3400*/;
    // 0046edaf  890d7ca64c00           -mov dword ptr [0x4ca67c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5023356) /* 0x4ca67c */) = cpu.ecx;
    // 0046edb5  e86eb40000             -call 0x47a228
    cpu.esp -= 4;
    sub_47a228(app, cpu);
    if (cpu.terminate) return;
    // 0046edba  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046edbc  a3ecab5100             -mov dword ptr [0x51abec], eax
    app->getMemory<x86::reg32>(x86::reg32(5352428) /* 0x51abec */) = cpu.eax;
    // 0046edc1  891df0ab5100           -mov dword ptr [0x51abf0], ebx
    app->getMemory<x86::reg32>(x86::reg32(5352432) /* 0x51abf0 */) = cpu.ebx;
    // 0046edc7  891de8ab5100           -mov dword ptr [0x51abe8], ebx
    app->getMemory<x86::reg32>(x86::reg32(5352424) /* 0x51abe8 */) = cpu.ebx;
    // 0046edcd  89580c                 -mov dword ptr [eax + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 0046edd0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046edd1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046edd2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046edd3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46ede0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046ede0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046ede1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046ede2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046ede3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046ede4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046ede5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046ede6  83ec40                 -sub esp, 0x40
    (cpu.esp) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0046ede9  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0046edeb  a1f0ab5100             -mov eax, dword ptr [0x51abf0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5352432) /* 0x51abf0 */);
    // 0046edf0  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046edf2  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0046edf6  89542434               -mov dword ptr [esp + 0x34], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.edx;
    // 0046edfa  89542438               -mov dword ptr [esp + 0x38], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.edx;
    // 0046edfe  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0046ee00  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0046ee04  83c044                 -add eax, 0x44
    (cpu.eax) += x86::reg32(x86::sreg32(68 /*0x44*/));
    // 0046ee07  8d3c9500000000         -lea edi, [edx*4]
    cpu.edi = x86::reg32(cpu.edx * 4);
    // 0046ee0e  89442430               -mov dword ptr [esp + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 0046ee12  29d7                   -sub edi, edx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0046ee14  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0046ee16  c1e702                 -shl edi, 2
    cpu.edi <<= 2 /*0x2*/ % 32;
    // 0046ee19  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046ee1c  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046ee1e  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0046ee22  c1e705                 -shl edi, 5
    cpu.edi <<= 5 /*0x5*/ % 32;
L_0x0046ee25:
    // 0046ee25  8b5c2420               -mov ebx, dword ptr [esp + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0046ee29  4b                     -dec ebx
    (cpu.ebx)--;
    // 0046ee2a  81efa0010000           -sub edi, 0x1a0
    (cpu.edi) -= x86::reg32(x86::sreg32(416 /*0x1a0*/));
    // 0046ee30  895c2420               -mov dword ptr [esp + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 0046ee34  81ff60feffff           +cmp edi, 0xfffffe60
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294966880 /*0xfffffe60*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046ee3a  753a                   -jne 0x46ee76
    if (!cpu.flags.zf)
    {
        goto L_0x0046ee76;
    }
    // 0046ee3c  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0046ee40  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0046ee44  8b442438               -mov eax, dword ptr [esp + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0046ee48  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0046ee4c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046ee4e  7406                   -je 0x46ee56
    if (cpu.flags.zf)
    {
        goto L_0x0046ee56;
    }
    // 0046ee50  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
L_0x0046ee56:
    // 0046ee56  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0046ee58  6800000600             -push 0x60000
    app->getMemory<x86::reg32>(cpu.esp-4) = 393216 /*0x60000*/;
    cpu.esp -= 4;
    // 0046ee5d  8b742424               -mov esi, dword ptr [esp + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0046ee61  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046ee62  8b7c2424               -mov edi, dword ptr [esp + 0x24]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0046ee66  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046ee67  e8b4f2feff             -call 0x45e120
    cpu.esp -= 4;
    sub_45e120(app, cpu);
    if (cpu.terminate) return;
    // 0046ee6c  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0046ee6f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ee70  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ee71  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ee72  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ee73  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ee74  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ee75  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046ee76:
    // 0046ee76  8b35ecab5100           -mov esi, dword ptr [0x51abec]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5352428) /* 0x51abec */);
    // 0046ee7c  bb00003200             -mov ebx, 0x320000
    cpu.ebx = 3276800 /*0x320000*/;
    // 0046ee81  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 0046ee83  8b54242c               -mov edx, dword ptr [esp + 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0046ee87  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0046ee89  e882eefeff             -call 0x45dd10
    cpu.esp -= 4;
    sub_45dd10(app, cpu);
    if (cpu.terminate) return;
    // 0046ee8e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046ee90  7493                   -je 0x46ee25
    if (cpu.flags.zf)
    {
        goto L_0x0046ee25;
    }
    // 0046ee92  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0046ee95  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046ee98  8b5508                 -mov edx, dword ptr [ebp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0046ee9b  8944243c               -mov dword ptr [esp + 0x3c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.eax;
    // 0046ee9f  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0046eea1  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0046eea3  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0046eea6  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0046eea9  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0046eeac  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046eeae  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0046eeb2  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0046eeb5  8b5d10                 -mov ebx, dword ptr [ebp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0046eeb8  8b542430               -mov edx, dword ptr [esp + 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0046eebc  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046eebe  8d5c240c               -lea ebx, [esp + 0xc]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046eec2  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0046eec6  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0046eec8  e8730c0000             -call 0x46fb40
    cpu.esp -= 4;
    sub_46fb40(app, cpu);
    if (cpu.terminate) return;
    // 0046eecd  8b54243c               -mov edx, dword ptr [esp + 0x3c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0046eed1  8d442424               -lea eax, [esp + 0x24]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0046eed5  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 0046eed8  e893dafeff             -call 0x45c970
    cpu.esp -= 4;
    sub_45c970(app, cpu);
    if (cpu.terminate) return;
    // 0046eedd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046eedf  0f8440ffffff           -je 0x46ee25
    if (cpu.flags.zf)
    {
        goto L_0x0046ee25;
    }
    // 0046eee5  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0046eee9  8b5c243c               -mov ebx, dword ptr [esp + 0x3c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0046eeed  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046eef1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046eef2  8d4e10                 -lea ecx, [esi + 0x10]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0046eef5  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0046eef9  e8e2090000             -call 0x46f8e0
    cpu.esp -= 4;
    sub_46f8e0(app, cpu);
    if (cpu.terminate) return;
    // 0046eefe  8b4e0c                 -mov ecx, dword ptr [esi + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0046ef01  ba05000000             -mov edx, 5
    cpu.edx = 5 /*0x5*/;
    // 0046ef06  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046ef08  81c690010000           -add esi, 0x190
    (cpu.esi) += x86::reg32(x86::sreg32(400 /*0x190*/));
    // 0046ef0e  e82d3b0000             -call 0x472a40
    cpu.esp -= 4;
    sub_472a40(app, cpu);
    if (cpu.terminate) return;
L_0x0046ef13:
    // 0046ef13  49                     -dec ecx
    (cpu.ecx)--;
    // 0046ef14  83f9ff                 +cmp ecx, -1
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
    // 0046ef17  0f8408ffffff           -je 0x46ee25
    if (cpu.flags.zf)
    {
        goto L_0x0046ee25;
    }
    // 0046ef1d  ba24000000             -mov edx, 0x24
    cpu.edx = 36 /*0x24*/;
    // 0046ef22  8d442428               -lea eax, [esp + 0x28]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0046ef26  e845dafeff             -call 0x45c970
    cpu.esp -= 4;
    sub_45c970(app, cpu);
    if (cpu.terminate) return;
    // 0046ef2b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046ef2d  7511                   -jne 0x46ef40
    if (!cpu.flags.zf)
    {
        goto L_0x0046ef40;
    }
    // 0046ef2f  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0046ef33  81c380000000           +add ebx, 0x80
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(128 /*0x80*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0046ef39  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0046ef3a  895c2424               -mov dword ptr [esp + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 0046ef3e  ebd3                   -jmp 0x46ef13
    goto L_0x0046ef13;
L_0x0046ef40:
    // 0046ef40  837c243400             +cmp dword ptr [esp + 0x34], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046ef45  0f8586000000           -jne 0x46efd1
    if (!cpu.flags.zf)
    {
        goto L_0x0046efd1;
    }
    // 0046ef4b  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0046ef4f  89442434               -mov dword ptr [esp + 0x34], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.eax;
L_0x0046ef53:
    // 0046ef53  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0046ef57  89442438               -mov dword ptr [esp + 0x38], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 0046ef5b  c740040a000000         -mov dword ptr [eax + 4], 0xa
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 10 /*0xa*/;
    // 0046ef62  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046ef64  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0046ef66  8b542428               -mov edx, dword ptr [esp + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0046ef6a  8b04852cbb5100         -mov eax, dword ptr [eax*4 + 0x51bb2c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5356332) /* 0x51bb2c */ + cpu.eax * 4);
    // 0046ef71  89421c                 -mov dword ptr [edx + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0046ef74  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0046ef78  66c7400a0100           -mov word ptr [eax + 0xa], 1
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(10) /* 0xa */) = 1 /*0x1*/;
    // 0046ef7e  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0046ef82  66c740080300           -mov word ptr [eax + 8], 3
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(8) /* 0x8 */) = 3 /*0x3*/;
    // 0046ef88  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0046ef8c  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0046ef90  83c220                 -add edx, 0x20
    (cpu.edx) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0046ef93  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0046ef96  8b542428               -mov edx, dword ptr [esp + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0046ef9a  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0046ef9e  894210                 -mov dword ptr [edx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0046efa1  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0046efa5  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0046efa9  83c260                 -add edx, 0x60
    (cpu.edx) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 0046efac  895014                 -mov dword ptr [eax + 0x14], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 0046efaf  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0046efb3  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0046efb7  83c240                 -add edx, 0x40
    (cpu.edx) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0046efba  895018                 -mov dword ptr [eax + 0x18], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0046efbd  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0046efc1  81c380000000           +add ebx, 0x80
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(128 /*0x80*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0046efc7  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0046efc8  895c2424               -mov dword ptr [esp + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 0046efcc  e942ffffff             -jmp 0x46ef13
    goto L_0x0046ef13;
L_0x0046efd1:
    // 0046efd1  8b542438               -mov edx, dword ptr [esp + 0x38]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0046efd5  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0046efd9  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 0046efdb  e973ffffff             -jmp 0x46ef53
    goto L_0x0046ef53;
}

/* align: skip  */
void Application::sub_46efe0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046efe0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046efe1  837c240800             +cmp dword ptr [esp + 8], 0
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
    // 0046efe6  0f84b7000000           -je 0x46f0a3
    if (cpu.flags.zf)
    {
        goto L_0x0046f0a3;
    }
    // 0046efec  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046efed  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046efee  a1e8ab5100             -mov eax, dword ptr [0x51abe8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5352424) /* 0x51abe8 */);
    // 0046eff3  8d2c8500000000         -lea ebp, [eax*4]
    cpu.ebp = x86::reg32(cpu.eax * 4);
    // 0046effa  29c5                   -sub ebp, eax
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0046effc  c1e502                 -shl ebp, 2
    cpu.ebp <<= 2 /*0x2*/ % 32;
    // 0046efff  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046f001  a1ecab5100             -mov eax, dword ptr [0x51abec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5352428) /* 0x51abec */);
    // 0046f006  c1e505                 -shl ebp, 5
    cpu.ebp <<= 5 /*0x5*/ % 32;
    // 0046f009  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046f00b  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0046f00e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046f010  83fe10                 +cmp esi, 0x10
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
    // 0046f013  0f858e000000           -jne 0x46f0a7
    if (!cpu.flags.zf)
    {
        goto L_0x0046f0a7;
    }
L_0x0046f019:
    // 0046f019  8b15f0ab5100           -mov edx, dword ptr [0x51abf0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5352432) /* 0x51abf0 */);
    // 0046f01f  83fa20                 +cmp edx, 0x20
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
    // 0046f022  0f8d07010000           -jge 0x46f12f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0046f12f;
    }
    // 0046f028  8915e8ab5100           -mov dword ptr [0x51abe8], edx
    app->getMemory<x86::reg32>(x86::reg32(5352424) /* 0x51abe8 */) = cpu.edx;
    // 0046f02e  8d4201                 -lea eax, [edx + 1]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0046f031  a3f0ab5100             -mov dword ptr [0x51abf0], eax
    app->getMemory<x86::reg32>(x86::reg32(5352432) /* 0x51abf0 */) = cpu.eax;
L_0x0046f036:
    // 0046f036  a1e8ab5100             -mov eax, dword ptr [0x51abe8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5352424) /* 0x51abe8 */);
    // 0046f03b  8d2c8500000000         -lea ebp, [eax*4]
    cpu.ebp = x86::reg32(cpu.eax * 4);
    // 0046f042  29c5                   -sub ebp, eax
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0046f044  c1e502                 -shl ebp, 2
    cpu.ebp <<= 2 /*0x2*/ % 32;
    // 0046f047  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046f049  a1ecab5100             -mov eax, dword ptr [0x51abec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5352428) /* 0x51abec */);
    // 0046f04e  c1e505                 -shl ebp, 5
    cpu.ebp <<= 5 /*0x5*/ % 32;
    // 0046f051  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046f053  c7450c00000000         -mov dword ptr [ebp + 0xc], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
L_0x0046f05a:
    // 0046f05a  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 0046f05c  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0046f05e  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0046f05f  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0046f060  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
L_0x0046f061:
    // 0046f061  8b550c                 -mov edx, dword ptr [ebp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0046f064  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0046f06b  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0046f06d  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0046f070  8d5510                 -lea edx, [ebp + 0x10]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0046f073  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046f075  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0046f077  e8f4000000             -call 0x46f170
    cpu.esp -= 4;
    sub_46f170(app, cpu);
    if (cpu.terminate) return;
    // 0046f07c  837c241002             +cmp dword ptr [esp + 0x10], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046f081  0f85ce000000           -jne 0x46f155
    if (!cpu.flags.zf)
    {
        goto L_0x0046f155;
    }
    // 0046f087  e8a4f70000             -call 0x47e830
    cpu.esp -= 4;
    sub_47e830(app, cpu);
    if (cpu.terminate) return;
    // 0046f08c  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 0046f08e  80e201                 -and dl, 1
    cpu.dl &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 0046f091  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0046f094  80c202                 -add dl, 2
    (cpu.dl) += x86::reg8(x86::sreg8(2 /*0x2*/));
    // 0046f097  88942890010000         -mov byte ptr [eax + ebp + 0x190], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(400) /* 0x190 */ + cpu.ebp * 1) = cpu.dl;
    // 0046f09e  ff450c                 -inc dword ptr [ebp + 0xc]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */))++;
    // 0046f0a1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f0a2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0046f0a3:
    // 0046f0a3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f0a4  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0046f0a7:
    // 0046f0a7  8b39                   -mov edi, dword ptr [ecx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx);
    // 0046f0a9  8b4500                 -mov eax, dword ptr [ebp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp);
    // 0046f0ac  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0046f0ae  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046f0b0  7e0c                   -jle 0x46f0be
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046f0be;
    }
    // 0046f0b2  3d00004000             +cmp eax, 0x400000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4194304 /*0x400000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046f0b7  7c13                   -jl 0x46f0cc
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046f0cc;
    }
    // 0046f0b9  e95bffffff             -jmp 0x46f019
    goto L_0x0046f019;
L_0x0046f0be:
    // 0046f0be  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 0046f0c0  3d00004000             +cmp eax, 0x400000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4194304 /*0x400000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046f0c5  7c05                   -jl 0x46f0cc
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046f0cc;
    }
    // 0046f0c7  e94dffffff             -jmp 0x46f019
    goto L_0x0046f019;
L_0x0046f0cc:
    // 0046f0cc  8b7104                 -mov esi, dword ptr [ecx + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0046f0cf  8b4504                 -mov eax, dword ptr [ebp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0046f0d2  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0046f0d4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046f0d6  7e0c                   -jle 0x46f0e4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046f0e4;
    }
    // 0046f0d8  3d00004000             +cmp eax, 0x400000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4194304 /*0x400000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046f0dd  7c13                   -jl 0x46f0f2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046f0f2;
    }
    // 0046f0df  e935ffffff             -jmp 0x46f019
    goto L_0x0046f019;
L_0x0046f0e4:
    // 0046f0e4  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 0046f0e6  3d00004000             +cmp eax, 0x400000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4194304 /*0x400000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046f0eb  7c05                   -jl 0x46f0f2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046f0f2;
    }
    // 0046f0ed  e927ffffff             -jmp 0x46f019
    goto L_0x0046f019;
L_0x0046f0f2:
    // 0046f0f2  8b7908                 -mov edi, dword ptr [ecx + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0046f0f5  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0046f0f8  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0046f0fa  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046f0fc  7e0c                   -jle 0x46f10a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046f10a;
    }
    // 0046f0fe  3d00004000             +cmp eax, 0x400000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4194304 /*0x400000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046f103  7c13                   -jl 0x46f118
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046f118;
    }
    // 0046f105  e90fffffff             -jmp 0x46f019
    goto L_0x0046f019;
L_0x0046f10a:
    // 0046f10a  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 0046f10c  3d00004000             +cmp eax, 0x400000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4194304 /*0x400000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046f111  7c05                   -jl 0x46f118
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046f118;
    }
    // 0046f113  e901ffffff             -jmp 0x46f019
    goto L_0x0046f019;
L_0x0046f118:
    // 0046f118  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0046f11a  0f85f9feffff           -jne 0x46f019
    if (!cpu.flags.zf)
    {
        goto L_0x0046f019;
    }
    // 0046f120  837d0c00               +cmp dword ptr [ebp + 0xc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046f124  0f8430ffffff           -je 0x46f05a
    if (cpu.flags.zf)
    {
        goto L_0x0046f05a;
    }
    // 0046f12a  e932ffffff             -jmp 0x46f061
    goto L_0x0046f061;
L_0x0046f12f:
    // 0046f12f  8b35e8ab5100           -mov esi, dword ptr [0x51abe8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5352424) /* 0x51abe8 */);
    // 0046f135  83fe1f                 +cmp esi, 0x1f
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(31 /*0x1f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046f138  7d0e                   -jge 0x46f148
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0046f148;
    }
    // 0046f13a  8d6e01                 -lea ebp, [esi + 1]
    cpu.ebp = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0046f13d  892de8ab5100           -mov dword ptr [0x51abe8], ebp
    app->getMemory<x86::reg32>(x86::reg32(5352424) /* 0x51abe8 */) = cpu.ebp;
    // 0046f143  e9eefeffff             -jmp 0x46f036
    goto L_0x0046f036;
L_0x0046f148:
    // 0046f148  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 0046f14a  893de8ab5100           -mov dword ptr [0x51abe8], edi
    app->getMemory<x86::reg32>(x86::reg32(5352424) /* 0x51abe8 */) = cpu.edi;
    // 0046f150  e9e1feffff             -jmp 0x46f036
    goto L_0x0046f036;
L_0x0046f155:
    // 0046f155  e8d6f60000             -call 0x47e830
    cpu.esp -= 4;
    sub_47e830(app, cpu);
    if (cpu.terminate) return;
    // 0046f15a  8b550c                 -mov edx, dword ptr [ebp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0046f15d  2401                   -and al, 1
    cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 0046f15f  88842a90010000         -mov byte ptr [edx + ebp + 0x190], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(400) /* 0x190 */ + cpu.ebp * 1) = cpu.al;
    // 0046f166  ff450c                 -inc dword ptr [ebp + 0xc]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */))++;
    // 0046f169  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f16a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f16b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f16c  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x00 */
void Application::sub_46f170(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046f170  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046f171  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046f172  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046f173  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046f176  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046f178  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0046f17a  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 0046f17c  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0046f17e  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0046f180  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0046f183  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0046f185  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0046f188  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0046f18a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046f18c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046f18e  e82def0100             -call 0x48e0c0
    cpu.esp -= 4;
    sub_48e0c0(app, cpu);
    if (cpu.terminate) return;
    // 0046f193  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0046f197  8d8800010000           -lea ecx, [eax + 0x100]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(256) /* 0x100 */);
    // 0046f19d  c0e507                 +shl ch, 7
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
    // 0046f1a0  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0046f1a2  00ed                   +add ch, ch
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
    // 0046f1a4  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 0046f1a6  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046f1a8  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0046f1ad  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046f1af  8b048500ab4c00         -mov eax, dword ptr [eax*4 + 0x4cab00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5024512) /* 0x4cab00 */ + cpu.eax * 4);
    // 0046f1b6  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046f1b8  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0046f1ba  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046f1bc  b8cc4c0000             -mov eax, 0x4ccc
    cpu.eax = 19660 /*0x4ccc*/;
    // 0046f1c1  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 0046f1c3  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0046f1c5  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0046f1c8  c1e810                 +shr eax, 0x10
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
    // 0046f1cb  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0046f1cd  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0046f1cf  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0046f1d2  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046f1d6  c0e407                 +shl ah, 7
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
    // 0046f1d9  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0046f1db  00e4                   +add ah, ah
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
    // 0046f1dd  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 0046f1df  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046f1e1  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0046f1e6  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046f1e8  8b048500ab4c00         -mov eax, dword ptr [eax*4 + 0x4cab00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5024512) /* 0x4cab00 */ + cpu.eax * 4);
    // 0046f1ef  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046f1f1  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0046f1f3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046f1f5  b8cc4c0000             -mov eax, 0x4ccc
    cpu.eax = 19660 /*0x4ccc*/;
    // 0046f1fa  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 0046f1fd  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0046f1ff  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0046f202  c1e810                 +shr eax, 0x10
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
    // 0046f205  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0046f207  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0046f209  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046f20b  2b17                   -sub edx, dword ptr [edi]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi)));
    // 0046f20d  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 0046f210  668916                 -mov word ptr [esi], dx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.dx;
    // 0046f213  8b5304                 -mov edx, dword ptr [ebx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0046f216  2b5704                 -sub edx, dword ptr [edi + 4]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 0046f219  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 0046f21c  66895602               -mov word ptr [esi + 2], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(2) /* 0x2 */) = cpu.dx;
    // 0046f220  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0046f222  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0046f225  8b4f08                 -mov ecx, dword ptr [edi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0046f228  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046f22a  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046f22c  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 0046f22f  66895604               -mov word ptr [esi + 4], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.dx;
    // 0046f233  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 0046f236  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0046f238  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046f23a  2b17                   -sub edx, dword ptr [edi]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi)));
    // 0046f23c  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 0046f23f  66895606               -mov word ptr [esi + 6], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */) = cpu.dx;
    // 0046f243  8b5304                 -mov edx, dword ptr [ebx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0046f246  2b5704                 -sub edx, dword ptr [edi + 4]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 0046f249  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 0046f24c  66895608               -mov word ptr [esi + 8], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.dx;
    // 0046f250  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0046f253  8b5f08                 -mov ebx, dword ptr [edi + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0046f256  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0046f258  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046f25a  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 0046f25d  6689560a               -mov word ptr [esi + 0xa], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(10) /* 0xa */) = cpu.dx;
    // 0046f261  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 0046f264  8b5500                 -mov edx, dword ptr [ebp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp);
    // 0046f267  8b1f                   -mov ebx, dword ptr [edi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi);
    // 0046f269  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046f26b  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046f26d  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 0046f270  6689560c               -mov word ptr [esi + 0xc], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.dx;
    // 0046f274  8b5504                 -mov edx, dword ptr [ebp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0046f277  2b5704                 -sub edx, dword ptr [edi + 4]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 0046f27a  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 0046f27d  6689560e               -mov word ptr [esi + 0xe], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(14) /* 0xe */) = cpu.dx;
    // 0046f281  8b5508                 -mov edx, dword ptr [ebp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0046f284  8b5f08                 -mov ebx, dword ptr [edi + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0046f287  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0046f289  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046f28b  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 0046f28e  66895610               -mov word ptr [esi + 0x10], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.dx;
    // 0046f292  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 0046f295  8b5500                 -mov edx, dword ptr [ebp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp);
    // 0046f298  8b1f                   -mov ebx, dword ptr [edi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi);
    // 0046f29a  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046f29c  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046f29e  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 0046f2a1  66895612               -mov word ptr [esi + 0x12], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(18) /* 0x12 */) = cpu.dx;
    // 0046f2a5  8b5504                 -mov edx, dword ptr [ebp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0046f2a8  2b5704                 -sub edx, dword ptr [edi + 4]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 0046f2ab  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 0046f2ae  66895614               -mov word ptr [esi + 0x14], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.dx;
    // 0046f2b2  8b5d08                 -mov ebx, dword ptr [ebp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0046f2b5  8b6f08                 -mov ebp, dword ptr [edi + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0046f2b8  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0046f2ba  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0046f2bc  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 0046f2bf  66894616               -mov word ptr [esi + 0x16], ax
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(22) /* 0x16 */) = cpu.ax;
    // 0046f2c3  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046f2c6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f2c7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f2c8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f2c9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46f2d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046f2d0  a1008d4c00             -mov eax, dword ptr [0x4c8d00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5016832) /* 0x4c8d00 */);
    // 0046f2d5  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0046f2d8  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046f2da  8b15f8ab5100           -mov edx, dword ptr [0x51abf8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5352440) /* 0x51abf8 */);
    // 0046f2e0  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0046f2e2  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046f2e4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46f2f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046f2f0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046f2f1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046f2f2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046f2f3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046f2f4  3b050c215000           +cmp eax, dword ptr [0x50210c]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5251340) /* 0x50210c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046f2fa  7416                   -je 0x46f312
    if (cpu.flags.zf)
    {
        goto L_0x0046f312;
    }
    // 0046f2fc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046f2fd  bba3000000             -mov ebx, 0xa3
    cpu.ebx = 163 /*0xa3*/;
    // 0046f302  ba70e64b00             -mov edx, 0x4be670
    cpu.edx = 4974192 /*0x4be670*/;
    // 0046f307  b8e4e64b00             -mov eax, 0x4be6e4
    cpu.eax = 4974308 /*0x4be6e4*/;
    // 0046f30c  e882040200             -call 0x48f793
    cpu.esp -= 4;
    sub_48f793(app, cpu);
    if (cpu.terminate) return;
    // 0046f311  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0046f312:
    // 0046f312  a10c215000             -mov eax, dword ptr [0x50210c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5251340) /* 0x50210c */);
    // 0046f317  e82490fdff             -call 0x448340
    cpu.esp -= 4;
    sub_448340(app, cpu);
    if (cpu.terminate) return;
    // 0046f31c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046f31e  8b35008d4c00           -mov esi, dword ptr [0x4c8d00]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5016832) /* 0x4c8d00 */);
    // 0046f324  890d2c9e4c00           -mov dword ptr [0x4c9e2c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5021228) /* 0x4c9e2c */) = cpu.ecx;
    // 0046f32a  890d0c215000           -mov dword ptr [0x50210c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5251340) /* 0x50210c */) = cpu.ecx;
    // 0046f330  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0046f332  740d                   -je 0x46f341
    if (cpu.flags.zf)
    {
        goto L_0x0046f341;
    }
    // 0046f334  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0046f336  e851b30000             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
    // 0046f33b  890d008d4c00           -mov dword ptr [0x4c8d00], ecx
    app->getMemory<x86::reg32>(x86::reg32(5016832) /* 0x4c8d00 */) = cpu.ecx;
L_0x0046f341:
    // 0046f341  8b2d048d4c00           -mov ebp, dword ptr [0x4c8d04]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5016836) /* 0x4c8d04 */);
    // 0046f347  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0046f349  740e                   -je 0x46f359
    if (cpu.flags.zf)
    {
        goto L_0x0046f359;
    }
    // 0046f34b  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0046f34d  e83ab30000             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
    // 0046f352  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046f354  a3048d4c00             -mov dword ptr [0x4c8d04], eax
    app->getMemory<x86::reg32>(x86::reg32(5016836) /* 0x4c8d04 */) = cpu.eax;
L_0x0046f359:
    // 0046f359  8b15088d4c00           -mov edx, dword ptr [0x4c8d08]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5016840) /* 0x4c8d08 */);
    // 0046f35f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0046f361  7505                   -jne 0x46f368
    if (!cpu.flags.zf)
    {
        goto L_0x0046f368;
    }
    // 0046f363  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f364  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f365  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f366  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f367  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046f368:
    // 0046f368  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046f36a  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046f36c  e81bb30000             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
    // 0046f371  890d088d4c00           -mov dword ptr [0x4c8d08], ecx
    app->getMemory<x86::reg32>(x86::reg32(5016840) /* 0x4c8d08 */) = cpu.ecx;
    // 0046f377  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f378  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f379  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f37a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f37b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_46f380(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046f380  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046f381  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046f382  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046f383  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046f384  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046f385  b90c215000             -mov ecx, 0x50210c
    cpu.ecx = 5251340 /*0x50210c*/;
    // 0046f38a  bb00080000             -mov ebx, 0x800
    cpu.ebx = 2048 /*0x800*/;
    // 0046f38f  ba01080000             -mov edx, 0x801
    cpu.edx = 2049 /*0x801*/;
    // 0046f394  e88799fdff             -call 0x448d20
    cpu.esp -= 4;
    sub_448d20(app, cpu);
    if (cpu.terminate) return;
    // 0046f399  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046f39b  7523                   -jne 0x46f3c0
    if (!cpu.flags.zf)
    {
        goto L_0x0046f3c0;
    }
    // 0046f39d  ba70e64b00             -mov edx, 0x4be670
    cpu.edx = 4974192 /*0x4be670*/;
    // 0046f3a2  b971000000             -mov ecx, 0x71
    cpu.ecx = 113 /*0x71*/;
    // 0046f3a7  688ce64b00             -push 0x4be68c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4974220 /*0x4be68c*/;
    cpu.esp -= 4;
    // 0046f3ac  891578a64c00           -mov dword ptr [0x4ca678], edx
    app->getMemory<x86::reg32>(x86::reg32(5023352) /* 0x4ca678 */) = cpu.edx;
    // 0046f3b2  890d7ca64c00           -mov dword ptr [0x4ca67c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5023356) /* 0x4ca67c */) = cpu.ecx;
    // 0046f3b8  e8c3aa0000             -call 0x479e80
    cpu.esp -= 4;
    crt_exit(app, cpu);
    if (cpu.terminate) return;
    // 0046f3bd  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0046f3c0:
    // 0046f3c0  a10c215000             -mov eax, dword ptr [0x50210c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5251340) /* 0x50210c */);
    // 0046f3c5  baec205000             -mov edx, 0x5020ec
    cpu.edx = 5251308 /*0x5020ec*/;
    // 0046f3ca  e8b18efdff             -call 0x448280
    cpu.esp -= 4;
    sub_448280(app, cpu);
    if (cpu.terminate) return;
    // 0046f3cf  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046f3d1  a3f8ab5100             -mov dword ptr [0x51abf8], eax
    app->getMemory<x86::reg32>(x86::reg32(5352440) /* 0x51abf8 */) = cpu.eax;
    // 0046f3d6  891df4ab5100           -mov dword ptr [0x51abf4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5352436) /* 0x51abf4 */) = cpu.ebx;
    // 0046f3dc  bb20000000             -mov ebx, 0x20
    cpu.ebx = 32 /*0x20*/;
    // 0046f3e1  a10c215000             -mov eax, dword ptr [0x50210c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5251340) /* 0x50210c */);
    // 0046f3e6  e855010000             -call 0x46f540
    cpu.esp -= 4;
    sub_46f540(app, cpu);
    if (cpu.terminate) return;
    // 0046f3eb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046f3ed  0f8426010000           -je 0x46f519
    if (cpu.flags.zf)
    {
        goto L_0x0046f519;
    }
    // 0046f3f3  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 0046f3f8  bab8e64b00             -mov edx, 0x4be6b8
    cpu.edx = 4974264 /*0x4be6b8*/;
    // 0046f3fd  b8ec205000             -mov eax, 0x5020ec
    cpu.eax = 5251308 /*0x5020ec*/;
    // 0046f402  e8b9310100             -call 0x4825c0
    cpu.esp -= 4;
    sub_4825c0(app, cpu);
    if (cpu.terminate) return;
    // 0046f407  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046f409  0f850a010000           -jne 0x46f519
    if (!cpu.flags.zf)
    {
        goto L_0x0046f519;
    }
    // 0046f40f  833df020500016         +cmp dword ptr [0x5020f0], 0x16
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5251312) /* 0x5020f0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(22 /*0x16*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046f416  0f85fd000000           -jne 0x46f519
    if (!cpu.flags.zf)
    {
        goto L_0x0046f519;
    }
    // 0046f41c  bf70e64b00             -mov edi, 0x4be670
    cpu.edi = 4974192 /*0x4be670*/;
    // 0046f421  bd82000000             -mov ebp, 0x82
    cpu.ebp = 130 /*0x82*/;
    // 0046f426  b8c0e64b00             -mov eax, 0x4be6c0
    cpu.eax = 4974272 /*0x4be6c0*/;
    // 0046f42b  8b1504215000           -mov edx, dword ptr [0x502104]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5251332) /* 0x502104 */);
    // 0046f431  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046f433  893d78a64c00           -mov dword ptr [0x4ca678], edi
    app->getMemory<x86::reg32>(x86::reg32(5023352) /* 0x4ca678 */) = cpu.edi;
    // 0046f439  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0046f43c  892d7ca64c00           -mov dword ptr [0x4ca67c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5023356) /* 0x4ca67c */) = cpu.ebp;
    // 0046f442  e8e1ad0000             -call 0x47a228
    cpu.esp -= 4;
    sub_47a228(app, cpu);
    if (cpu.terminate) return;
    // 0046f447  8b1d04215000           -mov ebx, dword ptr [0x502104]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5251332) /* 0x502104 */);
    // 0046f44d  8b0d0c215000           -mov ecx, dword ptr [0x50210c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5251340) /* 0x50210c */);
    // 0046f453  a3008d4c00             -mov dword ptr [0x4c8d00], eax
    app->getMemory<x86::reg32>(x86::reg32(5016832) /* 0x4c8d00 */) = cpu.eax;
    // 0046f458  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046f45a  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 0046f45d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046f45f  e8dc000000             -call 0x46f540
    cpu.esp -= 4;
    sub_46f540(app, cpu);
    if (cpu.terminate) return;
    // 0046f464  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046f466  0f84ad000000           -je 0x46f519
    if (cpu.flags.zf)
    {
        goto L_0x0046f519;
    }
    // 0046f46c  c7057ca64c0087000000   -mov dword ptr [0x4ca67c], 0x87
    app->getMemory<x86::reg32>(x86::reg32(5023356) /* 0x4ca67c */) = 135 /*0x87*/;
    // 0046f476  8b1508215000           -mov edx, dword ptr [0x502108]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5251336) /* 0x502108 */);
    // 0046f47c  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0046f483  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0046f485  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 0046f48c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046f48e  b8cce64b00             -mov eax, 0x4be6cc
    cpu.eax = 4974284 /*0x4be6cc*/;
    // 0046f493  893d78a64c00           -mov dword ptr [0x4ca678], edi
    app->getMemory<x86::reg32>(x86::reg32(5023352) /* 0x4ca678 */) = cpu.edi;
    // 0046f499  e88aad0000             -call 0x47a228
    cpu.esp -= 4;
    sub_47a228(app, cpu);
    if (cpu.terminate) return;
    // 0046f49e  8b1d08215000           -mov ebx, dword ptr [0x502108]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5251336) /* 0x502108 */);
    // 0046f4a4  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046f4a6  a3048d4c00             -mov dword ptr [0x4c8d04], eax
    app->getMemory<x86::reg32>(x86::reg32(5016836) /* 0x4c8d04 */) = cpu.eax;
    // 0046f4ab  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 0046f4b2  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046f4b4  8d1c8500000000         -lea ebx, [eax*4]
    cpu.ebx = x86::reg32(cpu.eax * 4);
    // 0046f4bb  a10c215000             -mov eax, dword ptr [0x50210c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5251340) /* 0x50210c */);
    // 0046f4c0  e87b000000             -call 0x46f540
    cpu.esp -= 4;
    sub_46f540(app, cpu);
    if (cpu.terminate) return;
    // 0046f4c5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046f4c7  7450                   -je 0x46f519
    if (cpu.flags.zf)
    {
        goto L_0x0046f519;
    }
    // 0046f4c9  bb8c000000             -mov ebx, 0x8c
    cpu.ebx = 140 /*0x8c*/;
    // 0046f4ce  b8d8e64b00             -mov eax, 0x4be6d8
    cpu.eax = 4974296 /*0x4be6d8*/;
    // 0046f4d3  8b1508215000           -mov edx, dword ptr [0x502108]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5251336) /* 0x502108 */);
    // 0046f4d9  891d7ca64c00           -mov dword ptr [0x4ca67c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5023356) /* 0x4ca67c */) = cpu.ebx;
    // 0046f4df  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046f4e1  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046f4e3  893d78a64c00           -mov dword ptr [0x4ca678], edi
    app->getMemory<x86::reg32>(x86::reg32(5023352) /* 0x4ca678 */) = cpu.edi;
    // 0046f4e9  e83aad0000             -call 0x47a228
    cpu.esp -= 4;
    sub_47a228(app, cpu);
    if (cpu.terminate) return;
    // 0046f4ee  8b1d08215000           -mov ebx, dword ptr [0x502108]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5251336) /* 0x502108 */);
    // 0046f4f4  8b0d0c215000           -mov ecx, dword ptr [0x50210c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5251340) /* 0x50210c */);
    // 0046f4fa  a3088d4c00             -mov dword ptr [0x4c8d08], eax
    app->getMemory<x86::reg32>(x86::reg32(5016840) /* 0x4c8d08 */) = cpu.eax;
    // 0046f4ff  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046f501  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046f503  01db                   -add ebx, ebx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0046f505  e836000000             -call 0x46f540
    cpu.esp -= 4;
    sub_46f540(app, cpu);
    if (cpu.terminate) return;
    // 0046f50a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046f50c  740b                   -je 0x46f519
    if (cpu.flags.zf)
    {
        goto L_0x0046f519;
    }
    // 0046f50e  a10c215000             -mov eax, dword ptr [0x50210c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5251340) /* 0x50210c */);
    // 0046f513  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f514  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f515  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f516  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f517  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f518  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046f519:
    // 0046f519  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046f51a  a10c215000             -mov eax, dword ptr [0x50210c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5251340) /* 0x50210c */);
    // 0046f51f  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0046f521  e81a8efdff             -call 0x448340
    cpu.esp -= 4;
    sub_448340(app, cpu);
    if (cpu.terminate) return;
    // 0046f526  89350c215000           -mov dword ptr [0x50210c], esi
    app->getMemory<x86::reg32>(x86::reg32(5251340) /* 0x50210c */) = cpu.esi;
    // 0046f52c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046f52e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f52f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f530  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f531  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f532  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f533  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f534  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46f540(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046f540  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046f541  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046f542  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0046f544  a1f8ab5100             -mov eax, dword ptr [0x51abf8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5352440) /* 0x51abf8 */);
    // 0046f549  0305f4ab5100           -add eax, dword ptr [0x51abf4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5352436) /* 0x51abf4 */)));
    // 0046f54f  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0046f551  e8aa200100             -call 0x481600
    cpu.esp -= 4;
    sub_481600(app, cpu);
    if (cpu.terminate) return;
    // 0046f556  8b35f4ab5100           -mov esi, dword ptr [0x51abf4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5352436) /* 0x51abf4 */);
    // 0046f55c  01ce                   -add esi, ecx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046f55e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046f560  8935f4ab5100           -mov dword ptr [0x51abf4], esi
    app->getMemory<x86::reg32>(x86::reg32(5352436) /* 0x51abf4 */) = cpu.esi;
    // 0046f566  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f567  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f568  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46f570(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046f570  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046f571  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046f572  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046f573  83ec1c                 -sub esp, 0x1c
    (cpu.esp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0046f576  8b6c242c               -mov ebp, dword ptr [esp + 0x2c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0046f57a  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0046f57e  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0046f580  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0046f582  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046f586  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 0046f589  e8e2d3feff             -call 0x45c970
    cpu.esp -= 4;
    sub_45c970(app, cpu);
    if (cpu.terminate) return;
    // 0046f58e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046f590  0f84af020000           -je 0x46f845
    if (cpu.flags.zf)
    {
        goto L_0x0046f845;
    }
    // 0046f596  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046f59a  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046f59e  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046f5a2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0046f5a4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046f5a5  8b4914                 -mov ecx, dword ptr [ecx + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 0046f5a8  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0046f5aa  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0046f5ac  e82f030000             -call 0x46f8e0
    cpu.esp -= 4;
    sub_46f8e0(app, cpu);
    if (cpu.terminate) return;
    // 0046f5b1  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046f5b5  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0046f5b8  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 0046f5bf  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046f5c1  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046f5c5  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0046f5c8  e8a3d3feff             -call 0x45c970
    cpu.esp -= 4;
    sub_45c970(app, cpu);
    if (cpu.terminate) return;
    // 0046f5cd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046f5cf  0f8470020000           -je 0x46f845
    if (cpu.flags.zf)
    {
        goto L_0x0046f845;
    }
    // 0046f5d5  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046f5d9  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046f5db  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0046f5de  e85d340000             -call 0x472a40
    cpu.esp -= 4;
    sub_472a40(app, cpu);
    if (cpu.terminate) return;
    // 0046f5e3  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046f5e7  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0046f5ea  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0046f5ec  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0046f5ee  0f8e20010000           -jle 0x46f714
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046f714;
    }
    // 0046f5f4  bf24000000             -mov edi, 0x24
    cpu.edi = 36 /*0x24*/;
    // 0046f5f9  89742418               -mov dword ptr [esp + 0x18], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 0046f5fd  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046f5ff  897c2414               -mov dword ptr [esp + 0x14], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edi;
L_0x0046f603:
    // 0046f603  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046f607  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046f60b  8b6c2414               -mov ebp, dword ptr [esp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046f60f  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0046f611  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0046f613  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0046f615  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046f619  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046f61d  8b5218                 -mov edx, dword ptr [edx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0046f620  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046f622  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046f624  8b6c2434               -mov ebp, dword ptr [esp + 0x34]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0046f628  668b4a02               -mov cx, word ptr [edx + 2]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0046f62c  01cd                   -add ebp, ecx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046f62e  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046f630  8a4a01                 -mov cl, byte ptr [edx + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0046f633  01cd                   -add ebp, ecx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046f635  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046f637  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 0046f639  f6c108                 +test cl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 8 /*0x8*/));
    // 0046f63c  0f841d010000           -je 0x46f75f
    if (cpu.flags.zf)
    {
        goto L_0x0046f75f;
    }
    // 0046f642  f6c101                 +test cl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 1 /*0x1*/));
    // 0046f645  0f8408010000           -je 0x46f753
    if (cpu.flags.zf)
    {
        goto L_0x0046f753;
    }
    // 0046f64b  c740040d000000         -mov dword ptr [eax + 4], 0xd
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 13 /*0xd*/;
L_0x0046f652:
    // 0046f652  f6c110                 +test cl, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 16 /*0x10*/));
    // 0046f655  0f8421010000           -je 0x46f77c
    if (cpu.flags.zf)
    {
        goto L_0x0046f77c;
    }
    // 0046f65b  66c7400a0200           -mov word ptr [eax + 0xa], 2
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(10) /* 0xa */) = 2 /*0x2*/;
L_0x0046f661:
    // 0046f661  6bed0c                 -imul ebp, ebp, 0xc
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(12 /*0xc*/)));
    // 0046f664  668b3d148d4c00         -mov di, word ptr [0x4c8d14]
    cpu.di = app->getMemory<x86::reg16>(x86::reg32(5016852) /* 0x4c8d14 */);
    // 0046f66b  66897808               -mov word ptr [eax + 8], di
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.di;
    // 0046f66f  8b3d288e4c00           -mov edi, dword ptr [0x4c8e28]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5017128) /* 0x4c8e28 */);
    // 0046f675  01fd                   -add ebp, edi
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edi));
    // 0046f677  8b7d00                 -mov edi, dword ptr [ebp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp);
    // 0046f67a  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0046f67d  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0046f67f  0f8402010000           -je 0x46f787
    if (cpu.flags.zf)
    {
        goto L_0x0046f787;
    }
L_0x0046f685:
    // 0046f685  668b3d08ac5100         -mov di, word ptr [0x51ac08]
    cpu.di = app->getMemory<x86::reg16>(x86::reg32(5352456) /* 0x51ac08 */);
    // 0046f68c  89681c                 -mov dword ptr [eax + 0x1c], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ebp;
    // 0046f68f  66897820               -mov word ptr [eax + 0x20], di
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.di;
    // 0046f693  f6c104                 +test cl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 4 /*0x4*/));
    // 0046f696  0f8430010000           -je 0x46f7cc
    if (cpu.flags.zf)
    {
        goto L_0x0046f7cc;
    }
    // 0046f69c  f6c101                 +test cl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 1 /*0x1*/));
    // 0046f69f  0f84ed000000           -je 0x46f792
    if (cpu.flags.zf)
    {
        goto L_0x0046f792;
    }
    // 0046f6a5  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046f6a7  8a4a02                 -mov cl, byte ptr [edx + 2]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0046f6aa  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046f6ae  c1e105                 -shl ecx, 5
    cpu.ecx <<= 5 /*0x5*/ % 32;
    // 0046f6b1  01cd                   -add ebp, ecx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046f6b3  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046f6b5  89680c                 -mov dword ptr [eax + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 0046f6b8  8a4a01                 -mov cl, byte ptr [edx + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0046f6bb  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046f6bf  c1e105                 -shl ecx, 5
    cpu.ecx <<= 5 /*0x5*/ % 32;
    // 0046f6c2  01cd                   -add ebp, ecx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046f6c4  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046f6c6  896810                 -mov dword ptr [eax + 0x10], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ebp;
    // 0046f6c9  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 0046f6cb  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046f6cf  c1e105                 -shl ecx, 5
    cpu.ecx <<= 5 /*0x5*/ % 32;
    // 0046f6d2  01cd                   -add ebp, ecx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046f6d4  896814                 -mov dword ptr [eax + 0x14], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ebp;
    // 0046f6d7  8a12                   -mov dl, byte ptr [edx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx);
L_0x0046f6d9:
    // 0046f6d9  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0046f6df  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046f6e3  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 0046f6e6  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046f6e8  894818                 -mov dword ptr [eax + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 0046f6eb  8b7c2418               -mov edi, dword ptr [esp + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046f6ef  8b6c2414               -mov ebp, dword ptr [esp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046f6f3  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046f6f7  83c324                 -add ebx, 0x24
    (cpu.ebx) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0046f6fa  46                     -inc esi
    (cpu.esi)++;
    // 0046f6fb  83c70c                 -add edi, 0xc
    (cpu.edi) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046f6fe  83c524                 -add ebp, 0x24
    (cpu.ebp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0046f701  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0046f704  897c2418               -mov dword ptr [esp + 0x18], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 0046f708  896c2414               -mov dword ptr [esp + 0x14], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ebp;
    // 0046f70c  39d6                   +cmp esi, edx
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
    // 0046f70e  0f8ceffeffff           -jl 0x46f603
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046f603;
    }
L_0x0046f714:
    // 0046f714  8b542430               -mov edx, dword ptr [esp + 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0046f718  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046f71c  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046f720  8904d558215000         -mov dword ptr [edx*8 + 0x502158], eax
    app->getMemory<x86::reg32>(x86::reg32(5251416) /* 0x502158 */ + cpu.edx * 8) = cpu.eax;
    // 0046f727  8b4904                 -mov ecx, dword ptr [ecx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0046f72a  49                     -dec ecx
    (cpu.ecx)--;
    // 0046f72b  8d04cd00000000         -lea eax, [ecx*8]
    cpu.eax = x86::reg32(cpu.ecx * 8);
    // 0046f732  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046f734  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046f738  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046f73b  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046f73d  8904d55c215000         -mov dword ptr [edx*8 + 0x50215c], eax
    app->getMemory<x86::reg32>(x86::reg32(5251420) /* 0x50215c */ + cpu.edx * 8) = cpu.eax;
    // 0046f744  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 0046f74a  83c41c                 +add esp, 0x1c
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
    // 0046f74d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f74e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f74f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f750  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x0046f753:
    // 0046f753  c7400409000000         -mov dword ptr [eax + 4], 9
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 9 /*0x9*/;
    // 0046f75a  e9f3feffff             -jmp 0x46f652
    goto L_0x0046f652;
L_0x0046f75f:
    // 0046f75f  f6c101                 +test cl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 1 /*0x1*/));
    // 0046f762  740c                   -je 0x46f770
    if (cpu.flags.zf)
    {
        goto L_0x0046f770;
    }
    // 0046f764  c740040c000000         -mov dword ptr [eax + 4], 0xc
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 12 /*0xc*/;
    // 0046f76b  e9e2feffff             -jmp 0x46f652
    goto L_0x0046f652;
L_0x0046f770:
    // 0046f770  c7400408000000         -mov dword ptr [eax + 4], 8
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 8 /*0x8*/;
    // 0046f777  e9d6feffff             -jmp 0x46f652
    goto L_0x0046f652;
L_0x0046f77c:
    // 0046f77c  66c7400a0000           -mov word ptr [eax + 0xa], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(10) /* 0xa */) = 0 /*0x0*/;
    // 0046f782  e9dafeffff             -jmp 0x46f661
    goto L_0x0046f661;
L_0x0046f787:
    // 0046f787  8b2d80bb5100           -mov ebp, dword ptr [0x51bb80]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5356416) /* 0x51bb80 */);
    // 0046f78d  e9f3feffff             -jmp 0x46f685
    goto L_0x0046f685;
L_0x0046f792:
    // 0046f792  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046f794  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 0046f796  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046f79a  c1e105                 -shl ecx, 5
    cpu.ecx <<= 5 /*0x5*/ % 32;
    // 0046f79d  01cd                   -add ebp, ecx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046f79f  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046f7a1  89680c                 -mov dword ptr [eax + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 0046f7a4  8a4a03                 -mov cl, byte ptr [edx + 3]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(3) /* 0x3 */);
    // 0046f7a7  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046f7ab  c1e105                 -shl ecx, 5
    cpu.ecx <<= 5 /*0x5*/ % 32;
    // 0046f7ae  01cd                   -add ebp, ecx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046f7b0  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046f7b2  896810                 -mov dword ptr [eax + 0x10], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ebp;
    // 0046f7b5  8a4a02                 -mov cl, byte ptr [edx + 2]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0046f7b8  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046f7bc  c1e105                 -shl ecx, 5
    cpu.ecx <<= 5 /*0x5*/ % 32;
    // 0046f7bf  01cd                   +add ebp, ecx
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0046f7c1  896814                 -mov dword ptr [eax + 0x14], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ebp;
    // 0046f7c4  8a5201                 -mov dl, byte ptr [edx + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0046f7c7  e90dffffff             -jmp 0x46f6d9
    goto L_0x0046f6d9;
L_0x0046f7cc:
    // 0046f7cc  f6c101                 +test cl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 1 /*0x1*/));
    // 0046f7cf  743a                   -je 0x46f80b
    if (cpu.flags.zf)
    {
        goto L_0x0046f80b;
    }
    // 0046f7d1  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046f7d3  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 0046f7d5  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046f7d9  c1e105                 -shl ecx, 5
    cpu.ecx <<= 5 /*0x5*/ % 32;
    // 0046f7dc  01cd                   -add ebp, ecx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046f7de  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046f7e0  89680c                 -mov dword ptr [eax + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 0046f7e3  8a4a01                 -mov cl, byte ptr [edx + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0046f7e6  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046f7ea  c1e105                 -shl ecx, 5
    cpu.ecx <<= 5 /*0x5*/ % 32;
    // 0046f7ed  01cd                   -add ebp, ecx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046f7ef  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046f7f1  896810                 -mov dword ptr [eax + 0x10], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ebp;
    // 0046f7f4  8a4a02                 -mov cl, byte ptr [edx + 2]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0046f7f7  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046f7fb  c1e105                 -shl ecx, 5
    cpu.ecx <<= 5 /*0x5*/ % 32;
    // 0046f7fe  01cd                   +add ebp, ecx
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0046f800  896814                 -mov dword ptr [eax + 0x14], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ebp;
    // 0046f803  8a5202                 -mov dl, byte ptr [edx + 2]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0046f806  e9cefeffff             -jmp 0x46f6d9
    goto L_0x0046f6d9;
L_0x0046f80b:
    // 0046f80b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046f80d  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 0046f80f  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046f813  c1e105                 -shl ecx, 5
    cpu.ecx <<= 5 /*0x5*/ % 32;
    // 0046f816  01cd                   -add ebp, ecx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046f818  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046f81a  89680c                 -mov dword ptr [eax + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 0046f81d  8a4a01                 -mov cl, byte ptr [edx + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0046f820  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046f824  c1e105                 -shl ecx, 5
    cpu.ecx <<= 5 /*0x5*/ % 32;
    // 0046f827  01cd                   -add ebp, ecx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046f829  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046f82b  896810                 -mov dword ptr [eax + 0x10], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ebp;
    // 0046f82e  8a4a02                 -mov cl, byte ptr [edx + 2]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 0046f831  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046f835  c1e105                 -shl ecx, 5
    cpu.ecx <<= 5 /*0x5*/ % 32;
    // 0046f838  01cd                   +add ebp, ecx
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0046f83a  896814                 -mov dword ptr [eax + 0x14], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ebp;
    // 0046f83d  8a5203                 -mov dl, byte ptr [edx + 3]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(3) /* 0x3 */);
    // 0046f840  e994feffff             -jmp 0x46f6d9
    goto L_0x0046f6d9;
L_0x0046f845:
    // 0046f845  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0046f847  e8d4d0feff             -call 0x45c920
    cpu.esp -= 4;
    sub_45c920(app, cpu);
    if (cpu.terminate) return;
    // 0046f84c  8b742430               -mov esi, dword ptr [esp + 0x30]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0046f850  8d3cf558215000         -lea edi, [esi*8 + 0x502158]
    cpu.edi = x86::reg32(x86::reg32(5251416) /* 0x502158 */ + cpu.esi * 8);
    // 0046f857  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0046f859  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0046f85a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0046f85b  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0046f85e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f85f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f860  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f861  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46f870(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046f870  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046f871  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046f872  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046f873  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046f875  30e5                   -xor ch, ah
    cpu.ch ^= x86::reg8(x86::sreg8(cpu.ah));
    // 0046f877  66c1f804               -sar ax, 4
    cpu.ax = x86::reg16(x86::sreg16(cpu.ax) >> (4 /*0x4*/ % 32));
    // 0046f87b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046f87d  30e6                   -xor dh, ah
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.ah));
    // 0046f87f  66c1f803               -sar ax, 3
    cpu.ax = x86::reg16(x86::sreg16(cpu.ax) >> (3 /*0x3*/ % 32));
    // 0046f883  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0046f885  30e7                   -xor bh, ah
    cpu.bh ^= x86::reg8(x86::sreg8(cpu.ah));
    // 0046f887  80e207                 -and dl, 7
    cpu.dl &= x86::reg8(x86::sreg8(7 /*0x7*/));
    // 0046f88a  80e307                 -and bl, 7
    cpu.bl &= x86::reg8(x86::sreg8(7 /*0x7*/));
    // 0046f88d  66c1f803               -sar ax, 3
    cpu.ax = x86::reg16(x86::sreg16(cpu.ax) >> (3 /*0x3*/ % 32));
    // 0046f891  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0046f893  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0046f895  30e7                   -xor bh, ah
    cpu.bh ^= x86::reg8(x86::sreg8(cpu.ah));
    // 0046f897  66c1f803               -sar ax, 3
    cpu.ax = x86::reg16(x86::sreg16(cpu.ax) >> (3 /*0x3*/ % 32));
    // 0046f89b  80e307                 -and bl, 7
    cpu.bl &= x86::reg8(x86::sreg8(7 /*0x7*/));
    // 0046f89e  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 0046f8a0  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0046f8a2  2407                   -and al, 7
    cpu.al &= x86::reg8(x86::sreg8(7 /*0x7*/));
    // 0046f8a4  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046f8a6  66c1ea02               -shr dx, 2
    cpu.dx >>= 2 /*0x2*/ % 32;
    // 0046f8aa  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0046f8ac  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046f8ae  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 0046f8b1  c1e007                 -shl eax, 7
    cpu.eax <<= 7 /*0x7*/ % 32;
    // 0046f8b4  09c3                   -or ebx, eax
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0046f8b6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046f8b8  c1e00a                 -shl eax, 0xa
    cpu.eax <<= 10 /*0xa*/ % 32;
    // 0046f8bb  c1e20d                 -shl edx, 0xd
    cpu.edx <<= 13 /*0xd*/ % 32;
    // 0046f8be  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046f8c0  80e10f                 -and cl, 0xf
    cpu.cl &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 0046f8c3  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 0046f8c5  09c1                   -or ecx, eax
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0046f8c7  66890d08ac5100         -mov word ptr [0x51ac08], cx
    app->getMemory<x86::reg16>(x86::reg32(5352456) /* 0x51ac08 */) = cpu.cx;
    // 0046f8ce  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f8cf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f8d0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f8d1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46f8e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046f8e0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046f8e1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046f8e2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046f8e3  83ec38                 -sub esp, 0x38
    (cpu.esp) -= x86::reg32(x86::sreg32(56 /*0x38*/));
    // 0046f8e6  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 0046f8ea  89542430               -mov dword ptr [esp + 0x30], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.edx;
    // 0046f8ee  895c2424               -mov dword ptr [esp + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 0046f8f2  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 0046f8f4  8b4c2448               -mov ecx, dword ptr [esp + 0x48]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0046f8f8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046f8fa  89542434               -mov dword ptr [esp + 0x34], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.edx;
    // 0046f8fe  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0046f900  0f8e0e010000           -jle 0x46fa14
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046fa14;
    }
    // 0046f906  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0046f909  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
L_0x0046f90d:
    // 0046f90d  0fbf4500               -movsx eax, word ptr [ebp]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.ebp)));
    // 0046f911  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0046f914  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0046f918  8b4500                 -mov eax, dword ptr [ebp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp);
    // 0046f91b  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0046f91e  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0046f921  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0046f925  8b4502                 -mov eax, dword ptr [ebp + 2]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(2) /* 0x2 */);
    // 0046f928  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0046f92b  8d5c2418               -lea ebx, [esp + 0x18]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046f92f  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0046f932  8b542428               -mov edx, dword ptr [esp + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0046f936  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0046f93a  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046f93e  e835fa0100             -call 0x48f378
    cpu.esp -= 4;
    sub_48f378(app, cpu);
    if (cpu.terminate) return;
    // 0046f943  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0046f947  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046f94b  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0046f94d  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046f94f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0046f951  8919                   -mov dword ptr [ecx], ebx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.ebx;
    // 0046f953  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 0046f956  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0046f959  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0046f95d  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0046f961  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0046f964  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046f966  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0046f968  895904                 -mov dword ptr [ecx + 4], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0046f96b  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 0046f96e  8b7c242c               -mov edi, dword ptr [esp + 0x2c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0046f972  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0046f976  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0046f97a  83c120                 -add ecx, 0x20
    (cpu.ecx) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0046f97d  8b5c2420               -mov ebx, dword ptr [esp + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0046f981  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0046f984  83c506                 -add ebp, 6
    (cpu.ebp) += x86::reg32(x86::sreg32(6 /*0x6*/));
    // 0046f987  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046f989  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0046f98b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0046f98d  8959e8                 -mov dword ptr [ecx - 0x18], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-24) /* -0x18 */) = cpu.ebx;
    // 0046f990  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 0046f993  893580a44c00           -mov dword ptr [0x4ca480], esi
    app->getMemory<x86::reg32>(x86::reg32(5022848) /* 0x4ca480 */) = cpu.esi;
    // 0046f999  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0046f99d  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0046f99f  66c741ec0000           -mov word ptr [ecx - 0x14], 0
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(-20) /* -0x14 */) = 0 /*0x0*/;
    // 0046f9a5  837e0800               +cmp dword ptr [esi + 8], 0
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
    // 0046f9a9  7e2a                   -jle 0x46f9d5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046f9d5;
    }
    // 0046f9ab  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0046f9ad  f72d78a44c00           -imul dword ptr [0x4ca478]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5022840) /* 0x4ca478 */))));
    // 0046f9b3  f77e08                 -idiv dword ptr [esi + 8]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0046f9b6  030570a44c00           -add eax, dword ptr [0x4ca470]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5022832) /* 0x4ca470 */)));
    // 0046f9bc  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 0046f9be  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0046f9c1  f72d7ca44c00           -imul dword ptr [0x4ca47c]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5022844) /* 0x4ca47c */))));
    // 0046f9c7  f77e08                 -idiv dword ptr [esi + 8]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0046f9ca  030574a44c00           +add eax, dword ptr [0x4ca474]
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
    // 0046f9d0  894704                 -mov dword ptr [edi + 4], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0046f9d3  eb14                   -jmp 0x46f9e9
    goto L_0x0046f9e9;
L_0x0046f9d5:
    // 0046f9d5  c70700000080           -mov dword ptr [edi], 0x80000000
    app->getMemory<x86::reg32>(cpu.edi) = 2147483648 /*0x80000000*/;
    // 0046f9db  c7470400000080         -mov dword ptr [edi + 4], 0x80000000
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = 2147483648 /*0x80000000*/;
    // 0046f9e2  830d80a44c0001         -or dword ptr [0x4ca480], 1
    app->getMemory<x86::reg32>(x86::reg32(5022848) /* 0x4ca480 */) |= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x0046f9e9:
    // 0046f9e9  8b7c242c               -mov edi, dword ptr [esp + 0x2c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0046f9ed  66a180a44c00           -mov ax, word ptr [0x4ca480]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5022848) /* 0x4ca480 */);
    // 0046f9f3  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0046f9f7  668941ee               -mov word ptr [ecx - 0x12], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(-18) /* -0x12 */) = cpu.ax;
    // 0046f9fb  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0046f9ff  83c720                 -add edi, 0x20
    (cpu.edi) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0046fa02  40                     -inc eax
    (cpu.eax)++;
    // 0046fa03  897c242c               -mov dword ptr [esp + 0x2c], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.edi;
    // 0046fa07  89442434               -mov dword ptr [esp + 0x34], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 0046fa0b  39d0                   +cmp eax, edx
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
    // 0046fa0d  0f8cfafeffff           -jl 0x46f90d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046f90d;
    }
    // 0046fa13  90                     -nop 
    ;
L_0x0046fa14:
    // 0046fa14  83c438                 -add esp, 0x38
    (cpu.esp) += x86::reg32(x86::sreg32(56 /*0x38*/));
    // 0046fa17  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fa18  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fa19  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fa1a  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_46fa20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046fa20  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046fa21  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046fa22  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046fa23  83ec2c                 -sub esp, 0x2c
    (cpu.esp) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 0046fa26  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0046fa2a  89542424               -mov dword ptr [esp + 0x24], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 0046fa2e  895c2420               -mov dword ptr [esp + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 0046fa32  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 0046fa34  8b4c243c               -mov ecx, dword ptr [esp + 0x3c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0046fa38  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046fa3a  89542428               -mov dword ptr [esp + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 0046fa3e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0046fa40  0f8ee6000000           -jle 0x46fb2c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046fb2c;
    }
    // 0046fa46  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0046fa49  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
L_0x0046fa4d:
    // 0046fa4d  8d5c240c               -lea ebx, [esp + 0xc]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046fa51  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0046fa55  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0046fa57  e81cf90100             -call 0x48f378
    cpu.esp -= 4;
    sub_48f378(app, cpu);
    if (cpu.terminate) return;
    // 0046fa5c  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0046fa60  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046fa64  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0046fa66  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046fa68  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0046fa6a  8919                   -mov dword ptr [ecx], ebx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.ebx;
    // 0046fa6c  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 0046fa6f  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0046fa72  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0046fa76  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046fa7a  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0046fa7d  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046fa7f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0046fa81  895904                 -mov dword ptr [ecx + 4], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0046fa84  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 0046fa87  8b7c2418               -mov edi, dword ptr [esp + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046fa8b  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0046fa8f  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0046fa93  83c120                 -add ecx, 0x20
    (cpu.ecx) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0046fa96  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046fa9a  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0046fa9d  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0046fa9f  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046faa1  893580a44c00           -mov dword ptr [0x4ca480], esi
    app->getMemory<x86::reg32>(x86::reg32(5022848) /* 0x4ca480 */) = cpu.esi;
    // 0046faa7  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0046faa9  8959e8                 -mov dword ptr [ecx - 0x18], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-24) /* -0x18 */) = cpu.ebx;
    // 0046faac  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 0046faaf  83c50c                 -add ebp, 0xc
    (cpu.ebp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046fab2  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0046fab6  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0046fab8  66c741ec0000           -mov word ptr [ecx - 0x14], 0
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(-20) /* -0x14 */) = 0 /*0x0*/;
    // 0046fabe  837e0800               +cmp dword ptr [esi + 8], 0
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
    // 0046fac2  7e2a                   -jle 0x46faee
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046faee;
    }
    // 0046fac4  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0046fac6  f72d78a44c00           -imul dword ptr [0x4ca478]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5022840) /* 0x4ca478 */))));
    // 0046facc  f77e08                 -idiv dword ptr [esi + 8]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0046facf  030570a44c00           -add eax, dword ptr [0x4ca470]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5022832) /* 0x4ca470 */)));
    // 0046fad5  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 0046fad7  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0046fada  f72d7ca44c00           -imul dword ptr [0x4ca47c]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5022844) /* 0x4ca47c */))));
    // 0046fae0  f77e08                 -idiv dword ptr [esi + 8]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0046fae3  030574a44c00           +add eax, dword ptr [0x4ca474]
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
    // 0046fae9  894704                 -mov dword ptr [edi + 4], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0046faec  eb14                   -jmp 0x46fb02
    goto L_0x0046fb02;
L_0x0046faee:
    // 0046faee  c70700000080           -mov dword ptr [edi], 0x80000000
    app->getMemory<x86::reg32>(cpu.edi) = 2147483648 /*0x80000000*/;
    // 0046faf4  c7470400000080         -mov dword ptr [edi + 4], 0x80000000
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = 2147483648 /*0x80000000*/;
    // 0046fafb  830d80a44c0001         -or dword ptr [0x4ca480], 1
    app->getMemory<x86::reg32>(x86::reg32(5022848) /* 0x4ca480 */) |= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x0046fb02:
    // 0046fb02  8b7c2418               -mov edi, dword ptr [esp + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046fb06  66a180a44c00           -mov ax, word ptr [0x4ca480]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5022848) /* 0x4ca480 */);
    // 0046fb0c  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0046fb10  668941ee               -mov word ptr [ecx - 0x12], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(-18) /* -0x12 */) = cpu.ax;
    // 0046fb14  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0046fb18  83c720                 -add edi, 0x20
    (cpu.edi) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0046fb1b  40                     -inc eax
    (cpu.eax)++;
    // 0046fb1c  897c2418               -mov dword ptr [esp + 0x18], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 0046fb20  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 0046fb24  39d0                   +cmp eax, edx
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
    // 0046fb26  0f8c21ffffff           -jl 0x46fa4d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046fa4d;
    }
L_0x0046fb2c:
    // 0046fb2c  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 0046fb2f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fb30  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fb31  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fb32  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46fb40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046fb40  e933f80100             -jmp 0x48f378
    return sub_48f378(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46fb50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046fb50  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046fb51  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046fb52  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046fb53  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046fb54  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046fb55  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0046fb58  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046fb5a  833801                 +cmp dword ptr [eax], 1
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
    // 0046fb5d  7556                   -jne 0x46fbb5
    if (!cpu.flags.zf)
    {
        goto L_0x0046fbb5;
    }
    // 0046fb5f  8b566c                 -mov edx, dword ptr [esi + 0x6c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(108) /* 0x6c */);
    // 0046fb62  8b4068                 -mov eax, dword ptr [eax + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(104) /* 0x68 */);
    // 0046fb65  09d0                   +or eax, edx
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(cpu.edx))));
    // 0046fb67  742e                   -je 0x46fb97
    if (cpu.flags.zf)
    {
        goto L_0x0046fb97;
    }
    // 0046fb69  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0046fb6b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0046fb6d  b9d2000000             -mov ecx, 0xd2
    cpu.ecx = 210 /*0xd2*/;
    // 0046fb72  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0046fb74  bbc2010000             -mov ebx, 0x1c2
    cpu.ebx = 450 /*0x1c2*/;
    // 0046fb79  8b4668                 -mov eax, dword ptr [esi + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(104) /* 0x68 */);
    // 0046fb7c  6888000000             -push 0x88
    app->getMemory<x86::reg32>(cpu.esp-4) = 136 /*0x88*/;
    cpu.esp -= 4;
    // 0046fb81  83ea46                 -sub edx, 0x46
    (cpu.edx) -= x86::reg32(x86::sreg32(70 /*0x46*/));
    // 0046fb84  2d96000000             -sub eax, 0x96
    (cpu.eax) -= x86::reg32(x86::sreg32(150 /*0x96*/));
L_0x0046fb89:
    // 0046fb89  e8f2000000             -call 0x46fc80
    cpu.esp -= 4;
    sub_46fc80(app, cpu);
    if (cpu.terminate) return;
L_0x0046fb8e:
    // 0046fb8e  83c420                 +add esp, 0x20
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
    // 0046fb91  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fb92  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fb93  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fb94  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fb95  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fb96  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046fb97:
    // 0046fb97  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046fb98  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046fb99  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046fb9a  b9d2000000             -mov ecx, 0xd2
    cpu.ecx = 210 /*0xd2*/;
    // 0046fb9f  bbc2010000             -mov ebx, 0x1c2
    cpu.ebx = 450 /*0x1c2*/;
    // 0046fba4  6888000000             -push 0x88
    app->getMemory<x86::reg32>(cpu.esp-4) = 136 /*0x88*/;
    cpu.esp -= 4;
    // 0046fba9  babaffffff             -mov edx, 0xffffffba
    cpu.edx = 4294967226 /*0xffffffba*/;
    // 0046fbae  b86affffff             -mov eax, 0xffffff6a
    cpu.eax = 4294967146 /*0xffffff6a*/;
    // 0046fbb3  ebd4                   -jmp 0x46fb89
    goto L_0x0046fb89;
L_0x0046fbb5:
    // 0046fbb5  833d28f54d0001         +cmp dword ptr [0x4df528], 1
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
    // 0046fbbc  746f                   -je 0x46fc2d
    if (cpu.flags.zf)
    {
        goto L_0x0046fc2d;
    }
    // 0046fbbe  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0046fbc1  e8caa0fcff             -call 0x439c90
    cpu.esp -= 4;
    sub_439c90(app, cpu);
    if (cpu.terminate) return;
    // 0046fbc6  83f805                 +cmp eax, 5
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
    // 0046fbc9  74c3                   -je 0x46fb8e
    if (cpu.flags.zf)
    {
        goto L_0x0046fb8e;
    }
    // 0046fbcb  8d44241c               -lea eax, [esp + 0x1c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0046fbcf  8d4c2418               -lea ecx, [esp + 0x18]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046fbd3  8d5c2414               -lea ebx, [esp + 0x14]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046fbd7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046fbd8  8d542414               -lea edx, [esp + 0x14]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046fbdc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046fbde  e86d0f0000             -call 0x470b50
    cpu.esp -= 4;
    sub_470b50(app, cpu);
    if (cpu.terminate) return;
    // 0046fbe3  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0046fbe6  e8a5a0fcff             -call 0x439c90
    cpu.esp -= 4;
    sub_439c90(app, cpu);
    if (cpu.terminate) return;
    // 0046fbeb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046fbed  7514                   -jne 0x46fc03
    if (!cpu.flags.zf)
    {
        goto L_0x0046fc03;
    }
    // 0046fbef  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0046fbf3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046fbf5  b90c000000             -mov ecx, 0xc
    cpu.ecx = 12 /*0xc*/;
    // 0046fbfa  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0046fbfd  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0046fbff  29442414               -sub dword ptr [esp + 0x14], eax
    (app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */)) -= x86::reg32(x86::sreg32(cpu.eax));
L_0x0046fc03:
    // 0046fc03  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046fc04  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0046fc06  8b74241c               -mov esi, dword ptr [esp + 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0046fc0a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046fc0b  8b7c241c               -mov edi, dword ptr [esp + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0046fc0f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046fc10  8b4c242c               -mov ecx, dword ptr [esp + 0x2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0046fc14  8b5c2428               -mov ebx, dword ptr [esp + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0046fc18  6a5a                   -push 0x5a
    app->getMemory<x86::reg32>(cpu.esp-4) = 90 /*0x5a*/;
    cpu.esp -= 4;
    // 0046fc1a  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0046fc1c  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0046fc1e  e85d000000             -call 0x46fc80
    cpu.esp -= 4;
    sub_46fc80(app, cpu);
    if (cpu.terminate) return;
    // 0046fc23  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fc24  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0046fc27  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fc28  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fc29  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fc2a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fc2b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fc2c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046fc2d:
    // 0046fc2d  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046fc31  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046fc35  8d5c2404               -lea ebx, [esp + 4]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046fc39  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046fc3a  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046fc3e  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0046fc41  e80a0f0000             -call 0x470b50
    cpu.esp -= 4;
    sub_470b50(app, cpu);
    if (cpu.terminate) return;
    // 0046fc46  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0046fc48  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046fc4c  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046fc50  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046fc54  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046fc58  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046fc5c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046fc5d  d1fa                   -sar edx, 1
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (1 /*0x1*/ % 32));
    // 0046fc5f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046fc60  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0046fc62  01c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046fc64  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0046fc66  6a5a                   -push 0x5a
    app->getMemory<x86::reg32>(cpu.esp-4) = 90 /*0x5a*/;
    cpu.esp -= 4;
    // 0046fc68  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046fc6a  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046fc6e  e80d000000             -call 0x46fc80
    cpu.esp -= 4;
    sub_46fc80(app, cpu);
    if (cpu.terminate) return;
    // 0046fc73  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0046fc76  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fc77  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fc78  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fc79  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fc7a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fc7b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_46fc80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046fc80  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046fc81  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046fc85  e8a6220200             -call 0x491f30
    cpu.esp -= 4;
    sub_491f30(app, cpu);
    if (cpu.terminate) return;
    // 0046fc8a  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0046fc8c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0046fc8e  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0046fc91  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0046fc93  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0046fc95  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046fc97  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046fc9a  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0046fc9c  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046fc9f  8d1406                 -lea edx, [esi + eax]
    cpu.edx = x86::reg32(cpu.esi + cpu.eax * 1);
    // 0046fca2  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046fca4  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0046fca7  c1e204                 +shl edx, 4
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
    // 0046fcaa  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0046fcac  c1f804                 -sar eax, 4
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (4 /*0x4*/ % 32));
    // 0046fcaf  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046fcb1  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0046fcb3  e8dc230200             -call 0x492094
    cpu.esp -= 4;
    sub_492094(app, cpu);
    if (cpu.terminate) return;
    // 0046fcb8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fcb9  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_46fcc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046fcc0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046fcc1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046fcc3  8915309e4c00           -mov dword ptr [0x4c9e30], edx
    app->getMemory<x86::reg32>(x86::reg32(5021232) /* 0x4c9e30 */) = cpu.edx;
    // 0046fcc9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fcca  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46fcd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046fcd0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046fcd1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046fcd3  8915309e4c00           -mov dword ptr [0x4c9e30], edx
    app->getMemory<x86::reg32>(x86::reg32(5021232) /* 0x4c9e30 */) = cpu.edx;
    // 0046fcd9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fcda  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
/* data blob: 44332200000000000000000000000000 */
void Application::sub_46fcf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046fcf0  e8ff810000             -call 0x477ef4
    cpu.esp -= 4;
    sub_477ef4(app, cpu);
    if (cpu.terminate) return;
    // 0046fcf5  a170b75100             -mov eax, dword ptr [0x51b770]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355376) /* 0x51b770 */);
    // 0046fcfa  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0046fcfd  e8ae530200             -call 0x4950b0
    cpu.esp -= 4;
    sub_4950b0(app, cpu);
    if (cpu.terminate) return;
    // 0046fd02  e915820000             -jmp 0x477f1c
    return sub_477f1c(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46fd10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046fd10  a170b75100             -mov eax, dword ptr [0x51b770]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355376) /* 0x51b770 */);
    // 0046fd15  e9ee820000             -jmp 0x478008
    return sub_478008(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46fd20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046fd20  c70554b7510001000000   -mov dword ptr [0x51b754], 1
    app->getMemory<x86::reg32>(x86::reg32(5355348) /* 0x51b754 */) = 1 /*0x1*/;
    // 0046fd2a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46fd30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046fd30  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46fd40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046fd40  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046fd41  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046fd42  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046fd43  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046fd44  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046fd45  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046fd46  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0046fd49  bfa0000000             -mov edi, 0xa0
    cpu.edi = 160 /*0xa0*/;
    // 0046fd4e  bda0000000             -mov ebp, 0xa0
    cpu.ebp = 160 /*0xa0*/;
    // 0046fd53  8b0dc4fd4d00           -mov ecx, dword ptr [0x4dfdc4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5111236) /* 0x4dfdc4 */);
    // 0046fd59  8b15c0fd4d00           -mov edx, dword ptr [0x4dfdc0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5111232) /* 0x4dfdc0 */);
    // 0046fd5f  8b1de0fd4d00           -mov ebx, dword ptr [0x4dfde0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5111264) /* 0x4dfde0 */);
    // 0046fd65  29cf                   -sub edi, ecx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046fd67  29d5                   -sub ebp, edx
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0046fd69  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0046fd6b  740e                   -je 0x46fd7b
    if (cpu.flags.zf)
    {
        goto L_0x0046fd7b;
    }
    // 0046fd6d  833dd4fd4d0000         +cmp dword ptr [0x4dfdd4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5111252) /* 0x4dfdd4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046fd74  746a                   -je 0x46fde0
    if (cpu.flags.zf)
    {
        goto L_0x0046fde0;
    }
    // 0046fd76  e855030000             -call 0x4700d0
    cpu.esp -= 4;
    sub_4700d0(app, cpu);
    if (cpu.terminate) return;
L_0x0046fd7b:
    // 0046fd7b  833dd4fd4d0000         +cmp dword ptr [0x4dfdd4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5111252) /* 0x4dfdd4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046fd82  0f8481000000           -je 0x46fe09
    if (cpu.flags.zf)
    {
        goto L_0x0046fe09;
    }
    // 0046fd88  833d18f54d0002         +cmp dword ptr [0x4df518], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5109016) /* 0x4df518 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046fd8f  7556                   -jne 0x46fde7
    if (!cpu.flags.zf)
    {
        goto L_0x0046fde7;
    }
    // 0046fd91  ba24e74b00             -mov edx, 0x4be724
    cpu.edx = 4974372 /*0x4be724*/;
L_0x0046fd96:
    // 0046fd96  a1ccfd4d00             -mov eax, dword ptr [0x4dfdcc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5111244) /* 0x4dfdcc */);
    // 0046fd9b  e8b88b0000             -call 0x478958
    cpu.esp -= 4;
    sub_478958(app, cpu);
    if (cpu.terminate) return;
    // 0046fda0  e86b960000             -call 0x479410
    cpu.esp -= 4;
    sub_479410(app, cpu);
    if (cpu.terminate) return;
    // 0046fda5  833dc8fd4d0000         +cmp dword ptr [0x4dfdc8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5111240) /* 0x4dfdc8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046fdac  7440                   -je 0x46fdee
    if (cpu.flags.zf)
    {
        goto L_0x0046fdee;
    }
    // 0046fdae  ba34e74b00             -mov edx, 0x4be734
    cpu.edx = 4974388 /*0x4be734*/;
    // 0046fdb3  a1ccfd4d00             -mov eax, dword ptr [0x4dfdcc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5111244) /* 0x4dfdcc */);
    // 0046fdb8  e89b8b0000             -call 0x478958
    cpu.esp -= 4;
    sub_478958(app, cpu);
    if (cpu.terminate) return;
    // 0046fdbd  e82eca0000             -call 0x47c7f0
    cpu.esp -= 4;
    sub_47c7f0(app, cpu);
    if (cpu.terminate) return;
    // 0046fdc2  ba3ce74b00             -mov edx, 0x4be73c
    cpu.edx = 4974396 /*0x4be73c*/;
L_0x0046fdc7:
    // 0046fdc7  a1ccfd4d00             -mov eax, dword ptr [0x4dfdcc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5111244) /* 0x4dfdcc */);
    // 0046fdcc  e8878b0000             -call 0x478958
    cpu.esp -= 4;
    sub_478958(app, cpu);
    if (cpu.terminate) return;
    // 0046fdd1  e81aca0000             -call 0x47c7f0
    cpu.esp -= 4;
    sub_47c7f0(app, cpu);
    if (cpu.terminate) return;
L_0x0046fdd6:
    // 0046fdd6  83c414                 +add esp, 0x14
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
    // 0046fdd9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fdda  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fddb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fddc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fddd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fdde  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fddf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046fde0:
    // 0046fde0  e82b020000             -call 0x470010
    cpu.esp -= 4;
    sub_470010(app, cpu);
    if (cpu.terminate) return;
    // 0046fde5  eb94                   -jmp 0x46fd7b
    goto L_0x0046fd7b;
L_0x0046fde7:
    // 0046fde7  ba2ce74b00             -mov edx, 0x4be72c
    cpu.edx = 4974380 /*0x4be72c*/;
    // 0046fdec  eba8                   -jmp 0x46fd96
    goto L_0x0046fd96;
L_0x0046fdee:
    // 0046fdee  ba44e74b00             -mov edx, 0x4be744
    cpu.edx = 4974404 /*0x4be744*/;
    // 0046fdf3  a1ccfd4d00             -mov eax, dword ptr [0x4dfdcc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5111244) /* 0x4dfdcc */);
    // 0046fdf8  e85b8b0000             -call 0x478958
    cpu.esp -= 4;
    sub_478958(app, cpu);
    if (cpu.terminate) return;
    // 0046fdfd  e8eec90000             -call 0x47c7f0
    cpu.esp -= 4;
    sub_47c7f0(app, cpu);
    if (cpu.terminate) return;
    // 0046fe02  ba4ce74b00             -mov edx, 0x4be74c
    cpu.edx = 4974412 /*0x4be74c*/;
    // 0046fe07  ebbe                   -jmp 0x46fdc7
    goto L_0x0046fdc7;
L_0x0046fe09:
    // 0046fe09  ba06000000             -mov edx, 6
    cpu.edx = 6 /*0x6*/;
    // 0046fe0e  8b0d28f54d00           -mov ecx, dword ptr [0x4df528]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5109032) /* 0x4df528 */);
    // 0046fe14  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0046fe18  83f901                 +cmp ecx, 1
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
    // 0046fe1b  7e08                   -jle 0x46fe25
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046fe25;
    }
    // 0046fe1d  c744241005000000       -mov dword ptr [esp + 0x10], 5
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = 5 /*0x5*/;
L_0x0046fe25:
    // 0046fe25  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046fe29  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0046fe2b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046fe2d  0f8eb5000000           -jle 0x46fee8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046fee8;
    }
    // 0046fe33  b80c020000             -mov eax, 0x20c
    cpu.eax = 524 /*0x20c*/;
    // 0046fe38  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0046fe3a  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0046fe3e  b80c020000             -mov eax, 0x20c
    cpu.eax = 524 /*0x20c*/;
    // 0046fe43  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0046fe45  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x0046fe49:
    // 0046fe49  83fe01                 +cmp esi, 1
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
    // 0046fe4c  0f8515010000           -jne 0x46ff67
    if (!cpu.flags.zf)
    {
        goto L_0x0046ff67;
    }
    // 0046fe52  833ddcfd4d0000         +cmp dword ptr [0x4dfddc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5111260) /* 0x4dfddc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046fe59  0f8408010000           -je 0x46ff67
    if (cpu.flags.zf)
    {
        goto L_0x0046ff67;
    }
    // 0046fe5f  ba54e74b00             -mov edx, 0x4be754
    cpu.edx = 4974420 /*0x4be754*/;
L_0x0046fe64:
    // 0046fe64  a1ccfd4d00             -mov eax, dword ptr [0x4dfdcc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5111244) /* 0x4dfdcc */);
    // 0046fe69  e8ea8a0000             -call 0x478958
    cpu.esp -= 4;
    sub_478958(app, cpu);
    if (cpu.terminate) return;
    // 0046fe6e  e87dc90000             -call 0x47c7f0
    cpu.esp -= 4;
    sub_47c7f0(app, cpu);
    if (cpu.terminate) return;
    // 0046fe73  ba6ce74b00             -mov edx, 0x4be76c
    cpu.edx = 4974444 /*0x4be76c*/;
    // 0046fe78  a1ccfd4d00             -mov eax, dword ptr [0x4dfdcc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5111244) /* 0x4dfdcc */);
    // 0046fe7d  bb94000000             -mov ebx, 0x94
    cpu.ebx = 148 /*0x94*/;
    // 0046fe82  e8d18a0000             -call 0x478958
    cpu.esp -= 4;
    sub_478958(app, cpu);
    if (cpu.terminate) return;
    // 0046fe87  ba6c010000             -mov edx, 0x16c
    cpu.edx = 364 /*0x16c*/;
    // 0046fe8c  e86f950000             -call 0x479400
    cpu.esp -= 4;
    sub_479400(app, cpu);
    if (cpu.terminate) return;
    // 0046fe91  ba6ce74b00             -mov edx, 0x4be76c
    cpu.edx = 4974444 /*0x4be76c*/;
    // 0046fe96  a1ccfd4d00             -mov eax, dword ptr [0x4dfdcc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5111244) /* 0x4dfdcc */);
    // 0046fe9b  bbc0000000             -mov ebx, 0xc0
    cpu.ebx = 192 /*0xc0*/;
    // 0046fea0  e8b38a0000             -call 0x478958
    cpu.esp -= 4;
    sub_478958(app, cpu);
    if (cpu.terminate) return;
    // 0046fea5  ba6c010000             -mov edx, 0x16c
    cpu.edx = 364 /*0x16c*/;
    // 0046feaa  b90e000000             -mov ecx, 0xe
    cpu.ecx = 14 /*0xe*/;
    // 0046feaf  e84c950000             -call 0x479400
    cpu.esp -= 4;
    sub_479400(app, cpu);
    if (cpu.terminate) return;
    // 0046feb4  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 0046feb6  ba94000000             -mov edx, 0x94
    cpu.edx = 148 /*0x94*/;
    // 0046febb  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046febf  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0046fec1  e81aef0000             -call 0x47ede0
    cpu.esp -= 4;
    sub_47ede0(app, cpu);
    if (cpu.terminate) return;
    // 0046fec6  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 0046fec8  b90e000000             -mov ecx, 0xe
    cpu.ecx = 14 /*0xe*/;
    // 0046fecd  bac0000000             -mov edx, 0xc0
    cpu.edx = 192 /*0xc0*/;
    // 0046fed2  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046fed6  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0046fed8  46                     -inc esi
    (cpu.esi)++;
    // 0046fed9  e802ef0000             -call 0x47ede0
    cpu.esp -= 4;
    sub_47ede0(app, cpu);
    if (cpu.terminate) return;
    // 0046fede  3b742410               +cmp esi, dword ptr [esp + 0x10]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046fee2  0f8c61ffffff           -jl 0x46fe49
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046fe49;
    }
L_0x0046fee8:
    // 0046fee8  8b3528f54d00           -mov esi, dword ptr [0x4df528]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5109032) /* 0x4df528 */);
    // 0046feee  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0046fef0  0f84e0feffff           -je 0x46fdd6
    if (cpu.flags.zf)
    {
        goto L_0x0046fdd6;
    }
    // 0046fef6  83fe01                 +cmp esi, 1
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
    // 0046fef9  0f84d7feffff           -je 0x46fdd6
    if (cpu.flags.zf)
    {
        goto L_0x0046fdd6;
    }
    // 0046feff  833d34f54d0001         +cmp dword ptr [0x4df534], 1
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
    // 0046ff06  0f8fcafeffff           -jg 0x46fdd6
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0046fdd6;
    }
    // 0046ff0c  803d7f074e0001         +cmp byte ptr [0x4e077f], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5113727) /* 0x4e077f */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0046ff13  0f84a8000000           -je 0x46ffc1
    if (cpu.flags.zf)
    {
        goto L_0x0046ffc1;
    }
    // 0046ff19  ba7ce74b00             -mov edx, 0x4be77c
    cpu.edx = 4974460 /*0x4be77c*/;
    // 0046ff1e  a1ccfd4d00             -mov eax, dword ptr [0x4dfdcc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5111244) /* 0x4dfdcc */);
    // 0046ff23  e8308a0000             -call 0x478958
    cpu.esp -= 4;
    sub_478958(app, cpu);
    if (cpu.terminate) return;
    // 0046ff28  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046ff2a  e8c1c80000             -call 0x47c7f0
    cpu.esp -= 4;
    sub_47c7f0(app, cpu);
    if (cpu.terminate) return;
    // 0046ff2f  8b510c                 -mov edx, dword ptr [ecx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0046ff32  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0046ff35  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 0046ff38  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0046ff3b  c1fa14                 -sar edx, 0x14
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (20 /*0x14*/ % 32));
    // 0046ff3e  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046ff40  8b510c                 -mov edx, dword ptr [ecx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0046ff43  8d58fe                 -lea ebx, [eax - 2]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(-2) /* -0x2 */);
    // 0046ff46  c1e214                 -shl edx, 0x14
    cpu.edx <<= 20 /*0x14*/ % 32;
    // 0046ff49  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046ff4b  c1fa14                 -sar edx, 0x14
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (20 /*0x14*/ % 32));
    // 0046ff4e  e8edc70000             -call 0x47c740
    cpu.esp -= 4;
    sub_47c740(app, cpu);
    if (cpu.terminate) return;
    // 0046ff53  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0046ff58  e86317fbff             -call 0x4216c0
    cpu.esp -= 4;
    sub_4216c0(app, cpu);
    if (cpu.terminate) return;
    // 0046ff5d  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0046ff60  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ff61  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ff62  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ff63  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ff64  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ff65  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ff66  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046ff67:
    // 0046ff67  83fe02                 +cmp esi, 2
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
    // 0046ff6a  7509                   -jne 0x46ff75
    if (!cpu.flags.zf)
    {
        goto L_0x0046ff75;
    }
    // 0046ff6c  833dd8fd4d0000         +cmp dword ptr [0x4dfdd8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5111256) /* 0x4dfdd8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046ff73  7526                   -jne 0x46ff9b
    if (!cpu.flags.zf)
    {
        goto L_0x0046ff9b;
    }
L_0x0046ff75:
    // 0046ff75  8b0dc8fd4d00           -mov ecx, dword ptr [0x4dfdc8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5111240) /* 0x4dfdc8 */);
    // 0046ff7b  39ce                   +cmp esi, ecx
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
    // 0046ff7d  7526                   -jne 0x46ffa5
    if (!cpu.flags.zf)
    {
        goto L_0x0046ffa5;
    }
    // 0046ff7f  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0046ff81  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046ff82  6864e74b00             -push 0x4be764
    app->getMemory<x86::reg32>(cpu.esp-4) = 4974436 /*0x4be764*/;
    cpu.esp -= 4;
    // 0046ff87  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046ff8b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046ff8c  e850c00000             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 0046ff91  83c410                 +add esp, 0x10
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
    // 0046ff94  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0046ff96  e9c9feffff             -jmp 0x46fe64
    goto L_0x0046fe64;
L_0x0046ff9b:
    // 0046ff9b  ba5ce74b00             -mov edx, 0x4be75c
    cpu.edx = 4974428 /*0x4be75c*/;
    // 0046ffa0  e9bffeffff             -jmp 0x46fe64
    goto L_0x0046fe64;
L_0x0046ffa5:
    // 0046ffa5  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0046ffa7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046ffa8  6864e74b00             -push 0x4be764
    app->getMemory<x86::reg32>(cpu.esp-4) = 4974436 /*0x4be764*/;
    cpu.esp -= 4;
    // 0046ffad  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046ffb1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046ffb2  e82ac00000             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 0046ffb7  83c410                 +add esp, 0x10
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
    // 0046ffba  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0046ffbc  e9a3feffff             -jmp 0x46fe64
    goto L_0x0046fe64;
L_0x0046ffc1:
    // 0046ffc1  ba74e74b00             -mov edx, 0x4be774
    cpu.edx = 4974452 /*0x4be774*/;
    // 0046ffc6  a1ccfd4d00             -mov eax, dword ptr [0x4dfdcc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5111244) /* 0x4dfdcc */);
    // 0046ffcb  e888890000             -call 0x478958
    cpu.esp -= 4;
    sub_478958(app, cpu);
    if (cpu.terminate) return;
    // 0046ffd0  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0046ffd2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x0046ffd4:
    // 0046ffd4  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0046ffd7  8b510c                 -mov edx, dword ptr [ecx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0046ffda  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0046ffdd  c1e214                 -shl edx, 0x14
    cpu.edx <<= 20 /*0x14*/ % 32;
    // 0046ffe0  c1f814                 -sar eax, 0x14
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (20 /*0x14*/ % 32));
    // 0046ffe3  c1fa14                 -sar edx, 0x14
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (20 /*0x14*/ % 32));
    // 0046ffe6  8d1c06                 -lea ebx, [esi + eax]
    cpu.ebx = x86::reg32(cpu.esi + cpu.eax * 1);
    // 0046ffe9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046ffeb  83c61a                 -add esi, 0x1a
    (cpu.esi) += x86::reg32(x86::sreg32(26 /*0x1a*/));
    // 0046ffee  e84dc70000             -call 0x47c740
    cpu.esp -= 4;
    sub_47c740(app, cpu);
    if (cpu.terminate) return;
    // 0046fff3  81fed0000000           +cmp esi, 0xd0
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(208 /*0xd0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046fff9  75d9                   -jne 0x46ffd4
    if (!cpu.flags.zf)
    {
        goto L_0x0046ffd4;
    }
    // 0046fffb  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00470000  e8bb16fbff             -call 0x4216c0
    cpu.esp -= 4;
    sub_4216c0(app, cpu);
    if (cpu.terminate) return;
    // 00470005  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00470008  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470009  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047000a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047000b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047000c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047000d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047000e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_470010(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00470010  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00470011  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00470012  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00470013  ba0ce74b00             -mov edx, 0x4be70c
    cpu.edx = 4974348 /*0x4be70c*/;
    // 00470018  a1ccfd4d00             -mov eax, dword ptr [0x4dfdcc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5111244) /* 0x4dfdcc */);
    // 0047001d  e842890000             -call 0x478964
    cpu.esp -= 4;
    sub_478964(app, cpu);
    if (cpu.terminate) return;
    // 00470022  ba14e74b00             -mov edx, 0x4be714
    cpu.edx = 4974356 /*0x4be714*/;
    // 00470027  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00470029  e8a2000000             -call 0x4700d0
    cpu.esp -= 4;
    sub_4700d0(app, cpu);
    if (cpu.terminate) return;
    // 0047002e  a1ccfd4d00             -mov eax, dword ptr [0x4dfdcc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5111244) /* 0x4dfdcc */);
    // 00470033  bb8a000000             -mov ebx, 0x8a
    cpu.ebx = 138 /*0x8a*/;
    // 00470038  e81b890000             -call 0x478958
    cpu.esp -= 4;
    sub_478958(app, cpu);
    if (cpu.terminate) return;
    // 0047003d  e8ce930000             -call 0x479410
    cpu.esp -= 4;
    sub_479410(app, cpu);
    if (cpu.terminate) return;
    // 00470042  ba52010000             -mov edx, 0x152
    cpu.edx = 338 /*0x152*/;
    // 00470047  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00470049  e8f2c60000             -call 0x47c740
    cpu.esp -= 4;
    sub_47c740(app, cpu);
    if (cpu.terminate) return;
    // 0047004e  bbb6000000             -mov ebx, 0xb6
    cpu.ebx = 182 /*0xb6*/;
    // 00470053  ba52010000             -mov edx, 0x152
    cpu.edx = 338 /*0x152*/;
    // 00470058  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047005a  e8e1c60000             -call 0x47c740
    cpu.esp -= 4;
    sub_47c740(app, cpu);
    if (cpu.terminate) return;
    // 0047005f  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 00470061  b80c020000             -mov eax, 0x20c
    cpu.eax = 524 /*0x20c*/;
    // 00470066  b90e000000             -mov ecx, 0xe
    cpu.ecx = 14 /*0xe*/;
    // 0047006b  8b1dc0fd4d00           -mov ebx, dword ptr [0x4dfdc0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5111232) /* 0x4dfdc0 */);
    // 00470071  ba94000000             -mov edx, 0x94
    cpu.edx = 148 /*0x94*/;
    // 00470076  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00470078  e863ed0000             -call 0x47ede0
    cpu.esp -= 4;
    sub_47ede0(app, cpu);
    if (cpu.terminate) return;
    // 0047007d  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 0047007f  b80c020000             -mov eax, 0x20c
    cpu.eax = 524 /*0x20c*/;
    // 00470084  b90e000000             -mov ecx, 0xe
    cpu.ecx = 14 /*0xe*/;
    // 00470089  8b1dc4fd4d00           -mov ebx, dword ptr [0x4dfdc4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5111236) /* 0x4dfdc4 */);
    // 0047008f  bac0000000             -mov edx, 0xc0
    cpu.edx = 192 /*0xc0*/;
    // 00470094  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00470096  e845ed0000             -call 0x47ede0
    cpu.esp -= 4;
    sub_47ede0(app, cpu);
    if (cpu.terminate) return;
    // 0047009b  8b1528f54d00           -mov edx, dword ptr [0x4df528]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5109032) /* 0x4df528 */);
    // 004700a1  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004700a3  7412                   -je 0x4700b7
    if (cpu.flags.zf)
    {
        goto L_0x004700b7;
    }
    // 004700a5  83fa01                 +cmp edx, 1
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
    // 004700a8  740d                   -je 0x4700b7
    if (cpu.flags.zf)
    {
        goto L_0x004700b7;
    }
    // 004700aa  833d34f54d0001         +cmp dword ptr [0x4df534], 1
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
    // 004700b1  7f04                   -jg 0x4700b7
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004700b7;
    }
    // 004700b3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004700b4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004700b5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004700b6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004700b7:
    // 004700b7  ba1ce74b00             -mov edx, 0x4be71c
    cpu.edx = 4974364 /*0x4be71c*/;
    // 004700bc  a1ccfd4d00             -mov eax, dword ptr [0x4dfdcc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5111244) /* 0x4dfdcc */);
    // 004700c1  e892880000             -call 0x478958
    cpu.esp -= 4;
    sub_478958(app, cpu);
    if (cpu.terminate) return;
    // 004700c6  e825c70000             -call 0x47c7f0
    cpu.esp -= 4;
    sub_47c7f0(app, cpu);
    if (cpu.terminate) return;
    // 004700cb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004700cc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004700cd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004700ce  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4700d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004700d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004700d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004700d2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004700d3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004700d4  ba04e74b00             -mov edx, 0x4be704
    cpu.edx = 4974340 /*0x4be704*/;
    // 004700d9  a1ccfd4d00             -mov eax, dword ptr [0x4dfdcc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5111244) /* 0x4dfdcc */);
    // 004700de  bbf0000000             -mov ebx, 0xf0
    cpu.ebx = 240 /*0xf0*/;
    // 004700e3  e87c880000             -call 0x478964
    cpu.esp -= 4;
    sub_478964(app, cpu);
    if (cpu.terminate) return;
    // 004700e8  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004700ea  a170b75100             -mov eax, dword ptr [0x51b770]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355376) /* 0x51b770 */);
    // 004700ef  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004700f1  e8127f0000             -call 0x478008
    cpu.esp -= 4;
    sub_478008(app, cpu);
    if (cpu.terminate) return;
    // 004700f6  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004700f8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004700fa  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004700fc  e86f060000             -call 0x470770
    cpu.esp -= 4;
    sub_470770(app, cpu);
    if (cpu.terminate) return;
    // 00470101  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00470103  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00470105  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00470107  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00470109  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047010b  e860060000             -call 0x470770
    cpu.esp -= 4;
    sub_470770(app, cpu);
    if (cpu.terminate) return;
    // 00470110  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00470112  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00470117  ba40010000             -mov edx, 0x140
    cpu.edx = 320 /*0x140*/;
    // 0047011c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047011e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00470120  e84b060000             -call 0x470770
    cpu.esp -= 4;
    sub_470770(app, cpu);
    if (cpu.terminate) return;
    // 00470125  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00470127  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0047012c  bbf0000000             -mov ebx, 0xf0
    cpu.ebx = 240 /*0xf0*/;
    // 00470131  ba40010000             -mov edx, 0x140
    cpu.edx = 320 /*0x140*/;
    // 00470136  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00470138  e833060000             -call 0x470770
    cpu.esp -= 4;
    sub_470770(app, cpu);
    if (cpu.terminate) return;
    // 0047013d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047013e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047013f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470140  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470141  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_470150(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00470150  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_470160(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00470160  e8cb4e0200             -call 0x495030
    cpu.esp -= 4;
    sub_495030(app, cpu);
    if (cpu.terminate) return;
    // 00470165  e9660c0000             -jmp 0x470dd0
    return sub_470dd0(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_470170(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00470170  a170b75100             -mov eax, dword ptr [0x51b770]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355376) /* 0x51b770 */);
    // 00470175  e8d6860000             -call 0x478850
    cpu.esp -= 4;
    sub_478850(app, cpu);
    if (cpu.terminate) return;
    // 0047017a  a174b75100             -mov eax, dword ptr [0x51b774]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355380) /* 0x51b774 */);
    // 0047017f  e8cc860000             -call 0x478850
    cpu.esp -= 4;
    sub_478850(app, cpu);
    if (cpu.terminate) return;
    // 00470184  a144b75100             -mov eax, dword ptr [0x51b744]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355332) /* 0x51b744 */);
    // 00470189  e8c2860000             -call 0x478850
    cpu.esp -= 4;
    sub_478850(app, cpu);
    if (cpu.terminate) return;
    // 0047018e  833d28f54d0001         +cmp dword ptr [0x4df528], 1
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
    // 00470195  7401                   -je 0x470198
    if (cpu.flags.zf)
    {
        goto L_0x00470198;
    }
    // 00470197  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00470198:
    // 00470198  a148b75100             -mov eax, dword ptr [0x51b748]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355336) /* 0x51b748 */);
    // 0047019d  e9ae860000             -jmp 0x478850
    return sub_478850(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4701b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004701b0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4701c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004701c0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4701d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004701d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004701d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004701d2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004701d3  81ec00030000           -sub esp, 0x300
    (cpu.esp) -= x86::reg32(x86::sreg32(768 /*0x300*/));
    // 004701d9  ba05000000             -mov edx, 5
    cpu.edx = 5 /*0x5*/;
    // 004701de  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 004701e3  8915dca34c00           -mov dword ptr [0x4ca3dc], edx
    app->getMemory<x86::reg32>(x86::reg32(5022684) /* 0x4ca3dc */) = cpu.edx;
    // 004701e9  890dd8a34c00           -mov dword ptr [0x4ca3d8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5022680) /* 0x4ca3d8 */) = cpu.ecx;
    // 004701ef  e8007d0000             -call 0x477ef4
    cpu.esp -= 4;
    sub_477ef4(app, cpu);
    if (cpu.terminate) return;
    // 004701f4  b8000000ff             -mov eax, 0xff000000
    cpu.eax = 4278190080 /*0xff000000*/;
    // 004701f9  e81e7f0000             -call 0x47811c
    cpu.esp -= 4;
    sub_47811c(app, cpu);
    if (cpu.terminate) return;
    // 004701fe  e8ed7f0000             -call 0x4781f0
    cpu.esp -= 4;
    sub_4781f0(app, cpu);
    if (cpu.terminate) return;
    // 00470203  e8147d0000             -call 0x477f1c
    cpu.esp -= 4;
    sub_477f1c(app, cpu);
    if (cpu.terminate) return;
    // 00470208  e8fb7c0000             -call 0x477f08
    cpu.esp -= 4;
    sub_477f08(app, cpu);
    if (cpu.terminate) return;
    // 0047020d  b8000000ff             -mov eax, 0xff000000
    cpu.eax = 4278190080 /*0xff000000*/;
    // 00470212  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00470214  e8037f0000             -call 0x47811c
    cpu.esp -= 4;
    sub_47811c(app, cpu);
    if (cpu.terminate) return;
    // 00470219  e8d27f0000             -call 0x4781f0
    cpu.esp -= 4;
    sub_4781f0(app, cpu);
    if (cpu.terminate) return;
    // 0047021e  e8f97c0000             -call 0x477f1c
    cpu.esp -= 4;
    sub_477f1c(app, cpu);
    if (cpu.terminate) return;
    // 00470223  b811000000             -mov eax, 0x11
    cpu.eax = 17 /*0x11*/;
    // 00470228  bae0010000             -mov edx, 0x1e0
    cpu.edx = 480 /*0x1e0*/;
    // 0047022d  e84e22fbff             -call 0x422480
    cpu.esp -= 4;
    sub_422480(app, cpu);
    if (cpu.terminate) return;
    // 00470232  b880020000             -mov eax, 0x280
    cpu.eax = 640 /*0x280*/;
    // 00470237  e898e40000             -call 0x47e6d4
    cpu.esp -= 4;
    sub_47e6d4(app, cpu);
    if (cpu.terminate) return;
    // 0047023c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047023e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00470240  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00470242  e8f922fbff             -call 0x422540
    cpu.esp -= 4;
    sub_422540(app, cpu);
    if (cpu.terminate) return;
    // 00470247  bae0010000             -mov edx, 0x1e0
    cpu.edx = 480 /*0x1e0*/;
    // 0047024c  b880020000             -mov eax, 0x280
    cpu.eax = 640 /*0x280*/;
    // 00470251  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00470253  e87ce40000             -call 0x47e6d4
    cpu.esp -= 4;
    sub_47e6d4(app, cpu);
    if (cpu.terminate) return;
    // 00470258  ba00030000             -mov edx, 0x300
    cpu.edx = 768 /*0x300*/;
    // 0047025d  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0047025f  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00470261  e8360a0100             -call 0x480c9c
    cpu.esp -= 4;
    sub_480c9c(app, cpu);
    if (cpu.terminate) return;
    // 00470266  ba00010000             -mov edx, 0x100
    cpu.edx = 256 /*0x100*/;
    // 0047026b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047026d  e8e61a0200             -call 0x491d58
    cpu.esp -= 4;
    sub_491d58(app, cpu);
    if (cpu.terminate) return;
    // 00470272  e87d7c0000             -call 0x477ef4
    cpu.esp -= 4;
    sub_477ef4(app, cpu);
    if (cpu.terminate) return;
    // 00470277  b8000000ff             -mov eax, 0xff000000
    cpu.eax = 4278190080 /*0xff000000*/;
    // 0047027c  e89b7e0000             -call 0x47811c
    cpu.esp -= 4;
    sub_47811c(app, cpu);
    if (cpu.terminate) return;
    // 00470281  e86a7f0000             -call 0x4781f0
    cpu.esp -= 4;
    sub_4781f0(app, cpu);
    if (cpu.terminate) return;
    // 00470286  e8917c0000             -call 0x477f1c
    cpu.esp -= 4;
    sub_477f1c(app, cpu);
    if (cpu.terminate) return;
    // 0047028b  e8787c0000             -call 0x477f08
    cpu.esp -= 4;
    sub_477f08(app, cpu);
    if (cpu.terminate) return;
    // 00470290  b8000000ff             -mov eax, 0xff000000
    cpu.eax = 4278190080 /*0xff000000*/;
    // 00470295  e8827e0000             -call 0x47811c
    cpu.esp -= 4;
    sub_47811c(app, cpu);
    if (cpu.terminate) return;
    // 0047029a  e8517f0000             -call 0x4781f0
    cpu.esp -= 4;
    sub_4781f0(app, cpu);
    if (cpu.terminate) return;
    // 0047029f  e8787c0000             -call 0x477f1c
    cpu.esp -= 4;
    sub_477f1c(app, cpu);
    if (cpu.terminate) return;
    // 004702a4  81c400030000           -add esp, 0x300
    (cpu.esp) += x86::reg32(x86::sreg32(768 /*0x300*/));
    // 004702aa  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004702ab  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004702ac  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004702ad  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4702b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004702b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004702b1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004702b2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004702b3  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 004702b8  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 004702bd  bae0010000             -mov edx, 0x1e0
    cpu.edx = 480 /*0x1e0*/;
    // 004702c2  b880020000             -mov eax, 0x280
    cpu.eax = 640 /*0x280*/;
    // 004702c7  e8444d0200             -call 0x495010
    cpu.esp -= 4;
    sub_495010(app, cpu);
    if (cpu.terminate) return;
    // 004702cc  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 004702d1  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 004702d6  ba46000000             -mov edx, 0x46
    cpu.edx = 70 /*0x46*/;
    // 004702db  a370b75100             -mov dword ptr [0x51b770], eax
    app->getMemory<x86::reg32>(x86::reg32(5355376) /* 0x51b770 */) = cpu.eax;
    // 004702e0  b880020000             -mov eax, 0x280
    cpu.eax = 640 /*0x280*/;
    // 004702e5  e8264d0200             -call 0x495010
    cpu.esp -= 4;
    sub_495010(app, cpu);
    if (cpu.terminate) return;
    // 004702ea  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 004702ef  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 004702f4  ba87000000             -mov edx, 0x87
    cpu.edx = 135 /*0x87*/;
    // 004702f9  a374b75100             -mov dword ptr [0x51b774], eax
    app->getMemory<x86::reg32>(x86::reg32(5355380) /* 0x51b774 */) = cpu.eax;
    // 004702fe  b86c000000             -mov eax, 0x6c
    cpu.eax = 108 /*0x6c*/;
    // 00470303  e8084d0200             -call 0x495010
    cpu.esp -= 4;
    sub_495010(app, cpu);
    if (cpu.terminate) return;
    // 00470308  8b1528f54d00           -mov edx, dword ptr [0x4df528]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5109032) /* 0x4df528 */);
    // 0047030e  a344b75100             -mov dword ptr [0x51b744], eax
    app->getMemory<x86::reg32>(x86::reg32(5355332) /* 0x51b744 */) = cpu.eax;
    // 00470313  83fa01                 +cmp edx, 1
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
    // 00470316  7432                   -je 0x47034a
    if (cpu.flags.zf)
    {
        goto L_0x0047034a;
    }
    // 00470318  a160f54d00             -mov eax, dword ptr [0x4df560]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5109088) /* 0x4df560 */);
    // 0047031d  a34cb75100             -mov dword ptr [0x51b74c], eax
    app->getMemory<x86::reg32>(x86::reg32(5355340) /* 0x51b74c */) = cpu.eax;
L_0x00470322:
    // 00470322  a16cf54d00             -mov eax, dword ptr [0x4df56c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5109100) /* 0x4df56c */);
    // 00470327  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0047032c  e80f4dfcff             -call 0x435040
    cpu.esp -= 4;
    sub_435040(app, cpu);
    if (cpu.terminate) return;
    // 00470331  a164f54d00             -mov eax, dword ptr [0x4df564]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5109092) /* 0x4df564 */);
    // 00470336  891d54b75100           -mov dword ptr [0x51b754], ebx
    app->getMemory<x86::reg32>(x86::reg32(5355348) /* 0x51b754 */) = cpu.ebx;
    // 0047033c  a350b75100             -mov dword ptr [0x51b750], eax
    app->getMemory<x86::reg32>(x86::reg32(5355344) /* 0x51b750 */) = cpu.eax;
    // 00470341  e80a070000             -call 0x470a50
    cpu.esp -= 4;
    sub_470a50(app, cpu);
    if (cpu.terminate) return;
    // 00470346  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470347  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470348  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470349  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047034a:
    // 0047034a  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 0047034f  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 00470354  ba87000000             -mov edx, 0x87
    cpu.edx = 135 /*0x87*/;
    // 00470359  b86c000000             -mov eax, 0x6c
    cpu.eax = 108 /*0x6c*/;
    // 0047035e  e8ad4c0200             -call 0x495010
    cpu.esp -= 4;
    sub_495010(app, cpu);
    if (cpu.terminate) return;
    // 00470363  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00470365  a348b75100             -mov dword ptr [0x51b748], eax
    app->getMemory<x86::reg32>(x86::reg32(5355336) /* 0x51b748 */) = cpu.eax;
    // 0047036a  890d4cb75100           -mov dword ptr [0x51b74c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5355340) /* 0x51b74c */) = cpu.ecx;
    // 00470370  ebb0                   -jmp 0x470322
    goto L_0x00470322;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_470380(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00470380  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00470381  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00470382  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00470383  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00470384  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00470385  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00470388  8b1560b75100           -mov edx, dword ptr [0x51b760]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5355360) /* 0x51b760 */);
    // 0047038e  42                     -inc edx
    (cpu.edx)++;
    // 0047038f  a170b75100             -mov eax, dword ptr [0x51b770]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355376) /* 0x51b770 */);
    // 00470394  891560b75100           -mov dword ptr [0x51b760], edx
    app->getMemory<x86::reg32>(x86::reg32(5355360) /* 0x51b760 */) = cpu.edx;
    // 0047039a  e8697c0000             -call 0x478008
    cpu.esp -= 4;
    sub_478008(app, cpu);
    if (cpu.terminate) return;
    // 0047039f  8b0dc4f74f00           -mov ecx, dword ptr [0x4ff7c4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5240772) /* 0x4ff7c4 */);
    // 004703a5  81f920020000           +cmp ecx, 0x220
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(544 /*0x220*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004703ab  0f8dcc000000           -jge 0x47047d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047047d;
    }
    // 004703b1  81f920010000           +cmp ecx, 0x120
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(288 /*0x120*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004703b7  0f8ec0000000           -jle 0x47047d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047047d;
    }
    // 004703bd  a1e0fc4600             -mov eax, dword ptr [0x46fce0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4652256) /* 0x46fce0 */);
    // 004703c2  8b35b0f34d00           -mov esi, dword ptr [0x4df3b0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5108656) /* 0x4df3b0 */);
    // 004703c8  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004703cb  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004703cd  7433                   -je 0x470402
    if (cpu.flags.zf)
    {
        goto L_0x00470402;
    }
    // 004703cf  833dbcf34d0005         +cmp dword ptr [0x4df3bc], 5
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5108668) /* 0x4df3bc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004703d6  752a                   -jne 0x470402
    if (!cpu.flags.zf)
    {
        goto L_0x00470402;
    }
    // 004703d8  8a542401               -mov dl, byte ptr [esp + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */);
    // 004703dc  8a5c2403               -mov bl, byte ptr [esp + 3]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(3) /* 0x3 */);
    // 004703e0  8a2424                 -mov ah, byte ptr [esp]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esp);
    // 004703e3  80c228                 -add dl, 0x28
    (cpu.dl) += x86::reg8(x86::sreg8(40 /*0x28*/));
    // 004703e6  80c328                 -add bl, 0x28
    (cpu.bl) += x86::reg8(x86::sreg8(40 /*0x28*/));
    // 004703e9  80c428                 -add ah, 0x28
    (cpu.ah) += x86::reg8(x86::sreg8(40 /*0x28*/));
    // 004703ec  88542401               -mov byte ptr [esp + 1], dl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */) = cpu.dl;
    // 004703f0  8a742402               -mov dh, byte ptr [esp + 2]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(2) /* 0x2 */);
    // 004703f4  885c2403               -mov byte ptr [esp + 3], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(3) /* 0x3 */) = cpu.bl;
    // 004703f8  80c628                 -add dh, 0x28
    (cpu.dh) += x86::reg8(x86::sreg8(40 /*0x28*/));
    // 004703fb  882424                 -mov byte ptr [esp], ah
    app->getMemory<x86::reg8>(cpu.esp) = cpu.ah;
    // 004703fe  88742402               -mov byte ptr [esp + 2], dh
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(2) /* 0x2 */) = cpu.dh;
L_0x00470402:
    // 00470402  803d6c4f4c0000         +cmp byte ptr [0x4c4f6c], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5001068) /* 0x4c4f6c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00470409  0f84b0010000           -je 0x4705bf
    if (cpu.flags.zf)
    {
        goto L_0x004705bf;
    }
L_0x0047040f:
    // 0047040f  8b0d28f54d00           -mov ecx, dword ptr [0x4df528]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5109032) /* 0x4df528 */);
    // 00470415  83f901                 +cmp ecx, 1
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
    // 00470418  0f85c7010000           -jne 0x4705e5
    if (!cpu.flags.zf)
    {
        goto L_0x004705e5;
    }
    // 0047041e  a14cb75100             -mov eax, dword ptr [0x51b74c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355340) /* 0x51b74c */);
    // 00470423  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00470425  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00470427  8a158db75100           -mov dl, byte ptr [0x51b78d]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5355405) /* 0x51b78d */);
    // 0047042d  8a1c04                 -mov bl, byte ptr [esp + eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + cpu.eax * 1);
    // 00470430  8b34c528a34c00         -mov esi, dword ptr [eax*8 + 0x4ca328]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5022504) /* 0x4ca328 */ + cpu.eax * 8);
    // 00470437  a08cb75100             -mov al, byte ptr [0x51b78c]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5355404) /* 0x51b78c */);
    // 0047043c  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047043e  d1fe                   -sar esi, 1
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (1 /*0x1*/ % 32));
    // 00470440  88d1                   -mov cl, dl
    cpu.cl = cpu.dl;
    // 00470442  83ee5f                 -sub esi, 0x5f
    (cpu.esi) -= x86::reg32(x86::sreg32(95 /*0x5f*/));
    // 00470445  d3fb                   -sar ebx, cl
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (cpu.cl % 32));
    // 00470447  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 00470449  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047044a  d3fe                   -sar esi, cl
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (cpu.cl % 32));
    // 0047044c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047044e  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 00470453  8a0d6c4f4c00           -mov cl, byte ptr [0x4c4f6c]
    cpu.cl = app->getMemory<x86::reg8>(x86::reg32(5001068) /* 0x4c4f6c */);
    // 00470459  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047045b  88d1                   -mov cl, dl
    cpu.cl = cpu.dl;
    // 0047045d  ba59000000             -mov edx, 0x59
    cpu.edx = 89 /*0x59*/;
    // 00470462  8b1c9d6cbb5100         -mov ebx, dword ptr [ebx*4 + 0x51bb6c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5356396) /* 0x51bb6c */ + cpu.ebx * 4);
    // 00470469  d3fa                   -sar edx, cl
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (cpu.cl % 32));
    // 0047046b  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 0047046d  b8bf000000             -mov eax, 0xbf
    cpu.eax = 191 /*0xbf*/;
    // 00470472  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 00470474  d3f8                   -sar eax, cl
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (cpu.cl % 32));
    // 00470476  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00470478  e883ee0000             -call 0x47f300
    cpu.esp -= 4;
    sub_47f300(app, cpu);
    if (cpu.terminate) return;
L_0x0047047d:
    // 0047047d  833d54b7510000         +cmp dword ptr [0x51b754], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5355348) /* 0x51b754 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00470484  0f84c3010000           -je 0x47064d
    if (cpu.flags.zf)
    {
        goto L_0x0047064d;
    }
    // 0047048a  e8797a0000             -call 0x477f08
    cpu.esp -= 4;
    sub_477f08(app, cpu);
    if (cpu.terminate) return;
L_0x0047048f:
    // 0047048f  8b154cb75100           -mov edx, dword ptr [0x51b74c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5355340) /* 0x51b74c */);
    // 00470495  a150b75100             -mov eax, dword ptr [0x51b750]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355344) /* 0x51b750 */);
    // 0047049a  e89198ffff             -call 0x469d30
    cpu.esp -= 4;
    sub_469d30(app, cpu);
    if (cpu.terminate) return;
    // 0047049f  8b0d70b75100           -mov ecx, dword ptr [0x51b770]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5355376) /* 0x51b770 */);
    // 004704a5  8b4920                 -mov ecx, dword ptr [ecx + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004704a8  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004704aa  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004704ac  e877090200             -call 0x490e28
    cpu.esp -= 4;
    sub_490e28(app, cpu);
    if (cpu.terminate) return;
    // 004704b1  833d54b7510000         +cmp dword ptr [0x51b754], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5355348) /* 0x51b754 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004704b8  750a                   -jne 0x4704c4
    if (!cpu.flags.zf)
    {
        goto L_0x004704c4;
    }
    // 004704ba  e85d7a0000             -call 0x477f1c
    cpu.esp -= 4;
    sub_477f1c(app, cpu);
    if (cpu.terminate) return;
    // 004704bf  e8307a0000             -call 0x477ef4
    cpu.esp -= 4;
    sub_477ef4(app, cpu);
    if (cpu.terminate) return;
L_0x004704c4:
    // 004704c4  b8fdffffff             -mov eax, 0xfffffffd
    cpu.eax = 4294967293 /*0xfffffffd*/;
    // 004704c9  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004704cb  e86098ffff             -call 0x469d30
    cpu.esp -= 4;
    sub_469d30(app, cpu);
    if (cpu.terminate) return;
    // 004704d0  8b0d70b75100           -mov ecx, dword ptr [0x51b770]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5355376) /* 0x51b770 */);
    // 004704d6  8b4920                 -mov ecx, dword ptr [ecx + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004704d9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004704db  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004704dd  e85e50ffff             -call 0x465540
    cpu.esp -= 4;
    sub_465540(app, cpu);
    if (cpu.terminate) return;
    // 004704e2  b8feffffff             -mov eax, 0xfffffffe
    cpu.eax = 4294967294 /*0xfffffffe*/;
    // 004704e7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004704e9  e84298ffff             -call 0x469d30
    cpu.esp -= 4;
    sub_469d30(app, cpu);
    if (cpu.terminate) return;
    // 004704ee  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004704f0  7412                   -je 0x470504
    if (cpu.flags.zf)
    {
        goto L_0x00470504;
    }
    // 004704f2  8b0d74b75100           -mov ecx, dword ptr [0x51b774]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5355380) /* 0x51b774 */);
    // 004704f8  8b4920                 -mov ecx, dword ptr [ecx + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004704fb  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004704fd  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004704ff  e824090200             -call 0x490e28
    cpu.esp -= 4;
    sub_490e28(app, cpu);
    if (cpu.terminate) return;
L_0x00470504:
    // 00470504  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00470509  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047050b  e82098ffff             -call 0x469d30
    cpu.esp -= 4;
    sub_469d30(app, cpu);
    if (cpu.terminate) return;
    // 00470510  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00470512  7412                   -je 0x470526
    if (cpu.flags.zf)
    {
        goto L_0x00470526;
    }
    // 00470514  8b0d74b75100           -mov ecx, dword ptr [0x51b774]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5355380) /* 0x51b774 */);
    // 0047051a  8b4920                 -mov ecx, dword ptr [ecx + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 0047051d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047051f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00470521  e802090200             -call 0x490e28
    cpu.esp -= 4;
    sub_490e28(app, cpu);
    if (cpu.terminate) return;
L_0x00470526:
    // 00470526  833d28f54d0001         +cmp dword ptr [0x4df528], 1
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
    // 0047052d  0f8524010000           -jne 0x470657
    if (!cpu.flags.zf)
    {
        goto L_0x00470657;
    }
    // 00470533  833d40f34d0000         +cmp dword ptr [0x4df340], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5108544) /* 0x4df340 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047053a  7414                   -je 0x470550
    if (cpu.flags.zf)
    {
        goto L_0x00470550;
    }
    // 0047053c  a144b75100             -mov eax, dword ptr [0x51b744]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355332) /* 0x51b744 */);
    // 00470541  bb45000000             -mov ebx, 0x45
    cpu.ebx = 69 /*0x45*/;
    // 00470546  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00470548  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0047054b  e8b08e0000             -call 0x479400
    cpu.esp -= 4;
    sub_479400(app, cpu);
    if (cpu.terminate) return;
L_0x00470550:
    // 00470550  833d44f34d0000         +cmp dword ptr [0x4df344], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5108548) /* 0x4df344 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00470557  7414                   -je 0x47056d
    if (cpu.flags.zf)
    {
        goto L_0x0047056d;
    }
    // 00470559  a148b75100             -mov eax, dword ptr [0x51b748]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355336) /* 0x51b748 */);
    // 0047055e  bb35010000             -mov ebx, 0x135
    cpu.ebx = 309 /*0x135*/;
    // 00470563  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00470565:
    // 00470565  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 00470568  e8938e0000             -call 0x479400
    cpu.esp -= 4;
    sub_479400(app, cpu);
    if (cpu.terminate) return;
L_0x0047056d:
    // 0047056d  833d14f64f0002         +cmp dword ptr [0x4ff614], 2
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
    // 00470574  7526                   -jne 0x47059c
    if (!cpu.flags.zf)
    {
        goto L_0x0047059c;
    }
    // 00470576  b9dd010000             -mov ecx, 0x1dd
    cpu.ecx = 477 /*0x1dd*/;
    // 0047057b  bb8b010000             -mov ebx, 0x18b
    cpu.ebx = 395 /*0x18b*/;
    // 00470580  bab5010000             -mov edx, 0x1b5
    cpu.edx = 437 /*0x1b5*/;
    // 00470585  b8f5000000             -mov eax, 0xf5
    cpu.eax = 245 /*0xf5*/;
    // 0047058a  e821830000             -call 0x4788b0
    cpu.esp -= 4;
    sub_4788b0(app, cpu);
    if (cpu.terminate) return;
    // 0047058f  a170b75100             -mov eax, dword ptr [0x51b770]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355376) /* 0x51b770 */);
    // 00470594  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 00470597  e8748e0000             -call 0x479410
    cpu.esp -= 4;
    sub_479410(app, cpu);
    if (cpu.terminate) return;
L_0x0047059c:
    // 0047059c  833d54b7510000         +cmp dword ptr [0x51b754], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5355348) /* 0x51b754 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004705a3  0f84cf000000           -je 0x470678
    if (cpu.flags.zf)
    {
        goto L_0x00470678;
    }
    // 004705a9  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004705ab  e8a0c90100             -call 0x48cf50
    cpu.esp -= 4;
    sub_48cf50(app, cpu);
    if (cpu.terminate) return;
    // 004705b0  893554b75100           -mov dword ptr [0x51b754], esi
    app->getMemory<x86::reg32>(x86::reg32(5355348) /* 0x51b754 */) = cpu.esi;
    // 004705b6  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004705b9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004705ba  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004705bb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004705bc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004705bd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004705be  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004705bf:
    // 004705bf  8b2d54f54d00           -mov ebp, dword ptr [0x4df554]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5109076) /* 0x4df554 */);
    // 004705c5  83fd01                 +cmp ebp, 1
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
    // 004705c8  0f84affeffff           -je 0x47047d
    if (cpu.flags.zf)
    {
        goto L_0x0047047d;
    }
    // 004705ce  83fd03                 +cmp ebp, 3
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
    // 004705d1  0f84a6feffff           -je 0x47047d
    if (cpu.flags.zf)
    {
        goto L_0x0047047d;
    }
    // 004705d7  83fd04                 +cmp ebp, 4
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004705da  0f849dfeffff           -je 0x47047d
    if (cpu.flags.zf)
    {
        goto L_0x0047047d;
    }
    // 004705e0  e92afeffff             -jmp 0x47040f
    goto L_0x0047040f;
L_0x004705e5:
    // 004705e5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004705e6  8b154cb75100           -mov edx, dword ptr [0x51b74c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5355340) /* 0x51b74c */);
    // 004705ec  a08db75100             -mov al, byte ptr [0x51b78d]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5355405) /* 0x51b78d */);
    // 004705f1  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004705f3  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 004705f5  8a5c1404               -mov bl, byte ptr [esp + edx + 4]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */ + cpu.edx * 1);
    // 004705f9  8b3cd528a34c00         -mov edi, dword ptr [edx*8 + 0x4ca328]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5022504) /* 0x4ca328 */ + cpu.edx * 8);
    // 00470600  8a158cb75100           -mov dl, byte ptr [0x51b78c]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5355404) /* 0x51b78c */);
    // 00470606  d1ff                   -sar edi, 1
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (1 /*0x1*/ % 32));
    // 00470608  d3fb                   -sar ebx, cl
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (cpu.cl % 32));
    // 0047060a  83ef5f                 -sub edi, 0x5f
    (cpu.edi) -= x86::reg32(x86::sreg32(95 /*0x5f*/));
    // 0047060d  88d1                   -mov cl, dl
    cpu.cl = cpu.dl;
    // 0047060f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00470610  d3ff                   -sar edi, cl
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (cpu.cl % 32));
    // 00470612  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00470614  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 00470619  8a0d6c4f4c00           -mov cl, byte ptr [0x4c4f6c]
    cpu.cl = app->getMemory<x86::reg8>(x86::reg32(5001068) /* 0x4c4f6c */);
    // 0047061f  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00470621  bebf000000             -mov esi, 0xbf
    cpu.esi = 191 /*0xbf*/;
    // 00470626  8b1c9d6cbb5100         -mov ebx, dword ptr [ebx*4 + 0x51bb6c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5356396) /* 0x51bb6c */ + cpu.ebx * 4);
    // 0047062d  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 0047062f  b859000000             -mov eax, 0x59
    cpu.eax = 89 /*0x59*/;
    // 00470634  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 00470636  d3f8                   -sar eax, cl
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (cpu.cl % 32));
    // 00470638  88d1                   -mov cl, dl
    cpu.cl = cpu.dl;
    // 0047063a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047063c  d3fe                   +sar esi, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.esi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 0047063e  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00470640  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00470642  e8b9ec0000             -call 0x47f300
    cpu.esp -= 4;
    sub_47f300(app, cpu);
    if (cpu.terminate) return;
    // 00470647  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470648  e930feffff             -jmp 0x47047d
    goto L_0x0047047d;
L_0x0047064d:
    // 0047064d  e8a2780000             -call 0x477ef4
    cpu.esp -= 4;
    sub_477ef4(app, cpu);
    if (cpu.terminate) return;
    // 00470652  e938feffff             -jmp 0x47048f
    goto L_0x0047048f;
L_0x00470657:
    // 00470657  833d40f34d0000         +cmp dword ptr [0x4df340], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5108544) /* 0x4df340 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047065e  0f8409ffffff           -je 0x47056d
    if (cpu.flags.zf)
    {
        goto L_0x0047056d;
    }
    // 00470664  a144b75100             -mov eax, dword ptr [0x51b744]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355332) /* 0x51b744 */);
    // 00470669  bb3e010000             -mov ebx, 0x13e
    cpu.ebx = 318 /*0x13e*/;
    // 0047066e  ba14020000             -mov edx, 0x214
    cpu.edx = 532 /*0x214*/;
    // 00470673  e9edfeffff             -jmp 0x470565
    goto L_0x00470565;
L_0x00470678:
    // 00470678  e89f780000             -call 0x477f1c
    cpu.esp -= 4;
    sub_477f1c(app, cpu);
    if (cpu.terminate) return;
    // 0047067d  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00470680  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470681  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470682  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470683  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470684  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470685  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_470690(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00470690  e87b50ffff             -call 0x465710
    cpu.esp -= 4;
    sub_465710(app, cpu);
    if (cpu.terminate) return;
    // 00470695  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00470697  750a                   -jne 0x4706a3
    if (!cpu.flags.zf)
    {
        goto L_0x004706a3;
    }
    // 00470699  833d54b7510000         +cmp dword ptr [0x51b754], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5355348) /* 0x51b754 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004706a0  750b                   -jne 0x4706ad
    if (!cpu.flags.zf)
    {
        goto L_0x004706ad;
    }
    // 004706a2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004706a3:
    // 004706a3  c70554b7510001000000   -mov dword ptr [0x51b754], 1
    app->getMemory<x86::reg32>(x86::reg32(5355348) /* 0x51b754 */) = 1 /*0x1*/;
L_0x004706ad:
    // 004706ad  e8ce75fdff             -call 0x447c80
    cpu.esp -= 4;
    sub_447c80(app, cpu);
    if (cpu.terminate) return;
    // 004706b2  e8c9040000             -call 0x470b80
    cpu.esp -= 4;
    sub_470b80(app, cpu);
    if (cpu.terminate) return;
    // 004706b7  e904000000             -jmp 0x4706c0
    return sub_4706c0(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_4706c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004706c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004706c1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004706c2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004706c3  e840780000             -call 0x477f08
    cpu.esp -= 4;
    sub_477f08(app, cpu);
    if (cpu.terminate) return;
    // 004706c8  833d4cb7510000         +cmp dword ptr [0x51b74c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5355340) /* 0x51b74c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004706cf  7536                   -jne 0x470707
    if (!cpu.flags.zf)
    {
        goto L_0x00470707;
    }
L_0x004706d1:
    // 004706d1  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004706d3  8b1d4cb75100           -mov ebx, dword ptr [0x51b74c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5355340) /* 0x51b74c */);
    // 004706d9  bae0010000             -mov edx, 0x1e0
    cpu.edx = 480 /*0x1e0*/;
    // 004706de  b880020000             -mov eax, 0x280
    cpu.eax = 640 /*0x280*/;
    // 004706e3  8b0cdd2ca34c00         -mov ecx, dword ptr [ebx*8 + 0x4ca32c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5022508) /* 0x4ca32c */ + cpu.ebx * 8);
    // 004706ea  8b1cdd28a34c00         -mov ebx, dword ptr [ebx*8 + 0x4ca328]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5022504) /* 0x4ca328 */ + cpu.ebx * 8);
    // 004706f1  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004706f3  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004706f5  d1fa                   -sar edx, 1
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (1 /*0x1*/ % 32));
    // 004706f7  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004706f9  e8e2e60000             -call 0x47ede0
    cpu.esp -= 4;
    sub_47ede0(app, cpu);
    if (cpu.terminate) return;
    // 004706fe  e819780000             -call 0x477f1c
    cpu.esp -= 4;
    sub_477f1c(app, cpu);
    if (cpu.terminate) return;
    // 00470703  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470704  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470705  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470706  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00470707:
    // 00470707  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00470709  a164bb5100             -mov eax, dword ptr [0x51bb64]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5356388) /* 0x51bb64 */);
    // 0047070e  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00470710  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00470712  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00470714  e857000000             -call 0x470770
    cpu.esp -= 4;
    sub_470770(app, cpu);
    if (cpu.terminate) return;
    // 00470719  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0047071b  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00470720  ba40010000             -mov edx, 0x140
    cpu.edx = 320 /*0x140*/;
    // 00470725  a164bb5100             -mov eax, dword ptr [0x51bb64]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5356388) /* 0x51bb64 */);
    // 0047072a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047072c  e83f000000             -call 0x470770
    cpu.esp -= 4;
    sub_470770(app, cpu);
    if (cpu.terminate) return;
    // 00470731  e8e6770000             -call 0x477f1c
    cpu.esp -= 4;
    sub_477f1c(app, cpu);
    if (cpu.terminate) return;
    // 00470736  e8cd770000             -call 0x477f08
    cpu.esp -= 4;
    sub_477f08(app, cpu);
    if (cpu.terminate) return;
    // 0047073b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047073d  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00470742  bbf0000000             -mov ebx, 0xf0
    cpu.ebx = 240 /*0xf0*/;
    // 00470747  ba40010000             -mov edx, 0x140
    cpu.edx = 320 /*0x140*/;
    // 0047074c  a164bb5100             -mov eax, dword ptr [0x51bb64]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5356388) /* 0x51bb64 */);
    // 00470751  e81a000000             -call 0x470770
    cpu.esp -= 4;
    sub_470770(app, cpu);
    if (cpu.terminate) return;
    // 00470756  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00470758  bbf0000000             -mov ebx, 0xf0
    cpu.ebx = 240 /*0xf0*/;
    // 0047075d  a164bb5100             -mov eax, dword ptr [0x51bb64]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5356388) /* 0x51bb64 */);
    // 00470762  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00470764  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00470766  e805000000             -call 0x470770
    cpu.esp -= 4;
    sub_470770(app, cpu);
    if (cpu.terminate) return;
    // 0047076b  e961ffffff             -jmp 0x4706d1
    goto L_0x004706d1;
}

/* align: skip  */
void Application::sub_470770(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00470770  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00470771  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00470772  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00470773  83ec60                 -sub esp, 0x60
    (cpu.esp) -= x86::reg32(x86::sreg32(96 /*0x60*/));
    // 00470776  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00470778  8b4002                 -mov eax, dword ptr [eax + 2]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0047077b  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0047077e  48                     -dec eax
    (cpu.eax)--;
    // 0047077f  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 00470782  8d7c2448               -lea edi, [esp + 0x48]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 00470786  89442458               -mov dword ptr [esp + 0x58], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */) = cpu.eax;
    // 0047078a  8b4504                 -mov eax, dword ptr [ebp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0047078d  8d742428               -lea esi, [esp + 0x28]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00470791  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00470794  89542428               -mov dword ptr [esp + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 00470798  895c242c               -mov dword ptr [esp + 0x2c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.ebx;
    // 0047079c  895c2434               -mov dword ptr [esp + 0x34], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.ebx;
    // 004707a0  48                     -dec eax
    (cpu.eax)--;
    // 004707a1  81c3f0000000           -add ebx, 0xf0
    (cpu.ebx) += x86::reg32(x86::sreg32(240 /*0xf0*/));
    // 004707a7  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004707aa  895c243c               -mov dword ptr [esp + 0x3c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.ebx;
    // 004707ae  8944245c               -mov dword ptr [esp + 0x5c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */) = cpu.eax;
    // 004707b2  8d8240010000           -lea eax, [edx + 0x140]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(320) /* 0x140 */);
    // 004707b8  895c2444               -mov dword ptr [esp + 0x44], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */) = cpu.ebx;
    // 004707bc  89442430               -mov dword ptr [esp + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 004707c0  89442438               -mov dword ptr [esp + 0x38], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 004707c4  89542440               -mov dword ptr [esp + 0x40], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.edx;
    // 004707c8  8b442458               -mov eax, dword ptr [esp + 0x58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 004707cc  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004707ce  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004707cf  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004707d0  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004707d3  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004707d7  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004707db  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004707df  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004707e3  8b44245c               -mov eax, dword ptr [esp + 0x5c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 004707e7  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004707eb  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004707ef  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004707f3  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004707f5  7568                   -jne 0x47085f
    if (!cpu.flags.zf)
    {
        goto L_0x0047085f;
    }
L_0x004707f7:
    // 004707f7  837c247000             +cmp dword ptr [esp + 0x70], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004707fc  7438                   -je 0x470836
    if (cpu.flags.zf)
    {
        goto L_0x00470836;
    }
    // 004707fe  8d7c2450               -lea edi, [esp + 0x50]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 00470802  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00470804  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00470805  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00470806  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00470808  8d742418               -lea esi, [esp + 0x18]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0047080c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0047080d  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0047080e  8d7c2418               -lea edi, [esp + 0x18]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00470812  8d742450               -lea esi, [esp + 0x50]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 00470816  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00470817  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00470818  8d7c2450               -lea edi, [esp + 0x50]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 0047081c  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00470820  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00470821  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00470822  8d7c2408               -lea edi, [esp + 8]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00470826  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0047082a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0047082b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0047082c  8d7c2410               -lea edi, [esp + 0x10]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00470830  8d742450               -lea esi, [esp + 0x50]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 00470834  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00470835  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
L_0x00470836:
    // 00470836  8d7c2420               -lea edi, [esp + 0x20]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0047083a  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0047083c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047083e  8d4c242c               -lea ecx, [esp + 0x2c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00470842  8d5c2404               -lea ebx, [esp + 4]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00470846  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 0047084b  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0047084d  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0047084f  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00470850  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00470851  e8c6200200             -call 0x49291c
    cpu.esp -= 4;
    sub_49291c(app, cpu);
    if (cpu.terminate) return;
    // 00470856  83c460                 +add esp, 0x60
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
    // 00470859  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047085a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047085b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047085c  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0047085f:
    // 0047085f  8d7c2450               -lea edi, [esp + 0x50]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 00470863  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00470865  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00470866  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00470867  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00470869  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047086d  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0047086e  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0047086f  8d7c2408               -lea edi, [esp + 8]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00470873  8d742450               -lea esi, [esp + 0x50]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 00470877  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00470878  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00470879  8d7c2450               -lea edi, [esp + 0x50]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 0047087d  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00470881  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00470882  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00470883  8d7c2410               -lea edi, [esp + 0x10]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00470887  8d742418               -lea esi, [esp + 0x18]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0047088b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0047088c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0047088d  8d7c2418               -lea edi, [esp + 0x18]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00470891  8d742450               -lea esi, [esp + 0x50]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 00470895  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00470896  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00470897  e95bffffff             -jmp 0x4707f7
    goto L_0x004707f7;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_4708a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004708a0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004708a1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004708a2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004708a4  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004708a6  83f901                 +cmp ecx, 1
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
    // 004708a9  7429                   -je 0x4708d4
    if (cpu.flags.zf)
    {
        goto L_0x004708d4;
    }
    // 004708ab  83f903                 +cmp ecx, 3
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
    // 004708ae  752b                   -jne 0x4708db
    if (!cpu.flags.zf)
    {
        goto L_0x004708db;
    }
    // 004708b0  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004708b3  8b048544b75100         -mov eax, dword ptr [eax*4 + 0x51b744]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355332) /* 0x51b744 */ + cpu.eax * 4);
L_0x004708ba:
    // 004708ba  e849770000             -call 0x478008
    cpu.esp -= 4;
    sub_478008(app, cpu);
    if (cpu.terminate) return;
    // 004708bf  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004708c1  e84a000000             -call 0x470910
    cpu.esp -= 4;
    sub_470910(app, cpu);
    if (cpu.terminate) return;
    // 004708c6  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004708ca  e851040000             -call 0x470d20
    cpu.esp -= 4;
    sub_470d20(app, cpu);
    if (cpu.terminate) return;
    // 004708cf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004708d0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004708d1  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004708d4:
    // 004708d4  a174b75100             -mov eax, dword ptr [0x51b774]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355380) /* 0x51b774 */);
    // 004708d9  ebdf                   -jmp 0x4708ba
    goto L_0x004708ba;
L_0x004708db:
    // 004708db  a170b75100             -mov eax, dword ptr [0x51b770]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355376) /* 0x51b770 */);
    // 004708e0  ebd8                   -jmp 0x4708ba
    goto L_0x004708ba;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4708f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004708f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004708f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004708f2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004708f3  b9e0010000             -mov ecx, 0x1e0
    cpu.ecx = 480 /*0x1e0*/;
    // 004708f8  bb80020000             -mov ebx, 0x280
    cpu.ebx = 640 /*0x280*/;
    // 004708fd  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004708ff  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00470901  e8aa7f0000             -call 0x4788b0
    cpu.esp -= 4;
    sub_4788b0(app, cpu);
    if (cpu.terminate) return;
    // 00470906  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470907  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470908  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470909  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_470910(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00470910  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00470911  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00470912  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00470913  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00470914  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00470915  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00470917  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00470919  e87293fcff             -call 0x439c90
    cpu.esp -= 4;
    sub_439c90(app, cpu);
    if (cpu.terminate) return;
    // 0047091e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00470920  7509                   -jne 0x47092b
    if (!cpu.flags.zf)
    {
        goto L_0x0047092b;
    }
    // 00470922  833a00                 +cmp dword ptr [edx], 0
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
    // 00470925  0f848a000000           -je 0x4709b5
    if (cpu.flags.zf)
    {
        goto L_0x004709b5;
    }
L_0x0047092b:
    // 0047092b  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0047092e  b974ac5100             -mov ecx, 0x51ac74
    cpu.ecx = 5352564 /*0x51ac74*/;
    // 00470933  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00470936  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00470938  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0047093a  8b5a68                 -mov ebx, dword ptr [edx + 0x68]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(104) /* 0x68 */);
    // 0047093d  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00470940  8b726c                 -mov esi, dword ptr [edx + 0x6c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(108) /* 0x6c */);
    // 00470943  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00470945  09f3                   +or ebx, esi
    cpu.clear_co();
    cpu.set_szp((cpu.ebx |= x86::reg32(x86::sreg32(cpu.esi))));
    // 00470947  0f84d6000000           -je 0x470a23
    if (cpu.flags.zf)
    {
        goto L_0x00470a23;
    }
    // 0047094d  8b4a68                 -mov ecx, dword ptr [edx + 0x68]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(104) /* 0x68 */);
    // 00470950  0fbf18                 -movsx ebx, word ptr [eax]
    cpu.ebx = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.eax)));
    // 00470953  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00470955  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00470957  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0047095a  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0047095c  890d88b75100           -mov dword ptr [0x51b788], ecx
    app->getMemory<x86::reg32>(x86::reg32(5355400) /* 0x51b788 */) = cpu.ecx;
    // 00470962  8b4802                 -mov ecx, dword ptr [eax + 2]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00470965  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00470968  891d84b75100           -mov dword ptr [0x51b784], ebx
    app->getMemory<x86::reg32>(x86::reg32(5355396) /* 0x51b784 */) = cpu.ebx;
    // 0047096e  8d140b                 -lea edx, [ebx + ecx]
    cpu.edx = x86::reg32(cpu.ebx + cpu.ecx * 1);
L_0x00470971:
    // 00470971  891564b75100           -mov dword ptr [0x51b764], edx
    app->getMemory<x86::reg32>(x86::reg32(5355364) /* 0x51b764 */) = cpu.edx;
    // 00470977  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0047097a  a188b75100             -mov eax, dword ptr [0x51b788]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355400) /* 0x51b788 */);
    // 0047097f  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00470982  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00470984  a36cb75100             -mov dword ptr [0x51b76c], eax
    app->getMemory<x86::reg32>(x86::reg32(5355372) /* 0x51b76c */) = cpu.eax;
    // 00470989  a16cb75100             -mov eax, dword ptr [0x51b76c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355372) /* 0x51b76c */);
    // 0047098e  a378b75100             -mov dword ptr [0x51b778], eax
    app->getMemory<x86::reg32>(x86::reg32(5355384) /* 0x51b778 */) = cpu.eax;
L_0x00470993:
    // 00470993  8b0d6cb75100           -mov ecx, dword ptr [0x51b76c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5355372) /* 0x51b76c */);
    // 00470999  8b1d64b75100           -mov ebx, dword ptr [0x51b764]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5355364) /* 0x51b764 */);
    // 0047099f  8b1588b75100           -mov edx, dword ptr [0x51b788]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5355400) /* 0x51b788 */);
    // 004709a5  a184b75100             -mov eax, dword ptr [0x51b784]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355396) /* 0x51b784 */);
    // 004709aa  e8017f0000             -call 0x4788b0
    cpu.esp -= 4;
    sub_4788b0(app, cpu);
    if (cpu.terminate) return;
    // 004709af  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004709b0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004709b1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004709b2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004709b3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004709b4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004709b5:
    // 004709b5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004709b6  e8254dffff             -call 0x4656e0
    cpu.esp -= 4;
    sub_4656e0(app, cpu);
    if (cpu.terminate) return;
    // 004709bb  8a1d8cb75100           -mov bl, byte ptr [0x51b78c]
    cpu.bl = app->getMemory<x86::reg8>(x86::reg32(5355404) /* 0x51b78c */);
    // 004709c1  0fbf30                 -movsx esi, word ptr [eax]
    cpu.esi = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.eax)));
    // 004709c4  88d9                   -mov cl, bl
    cpu.cl = cpu.bl;
    // 004709c6  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004709c8  8b38                   -mov edi, dword ptr [eax]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax);
    // 004709ca  d3fa                   -sar edx, cl
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (cpu.cl % 32));
    // 004709cc  c1ff10                 -sar edi, 0x10
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (16 /*0x10*/ % 32));
    // 004709cf  891584b75100           -mov dword ptr [0x51b784], edx
    app->getMemory<x86::reg32>(x86::reg32(5355396) /* 0x51b784 */) = cpu.edx;
    // 004709d5  8a158db75100           -mov dl, byte ptr [0x51b78d]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5355405) /* 0x51b78d */);
    // 004709db  89fd                   -mov ebp, edi
    cpu.ebp = cpu.edi;
    // 004709dd  88d1                   -mov cl, dl
    cpu.cl = cpu.dl;
    // 004709df  d3fd                   -sar ebp, cl
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (cpu.cl % 32));
    // 004709e1  8b4802                 -mov ecx, dword ptr [eax + 2]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 004709e4  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004709e7  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004709ea  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004709ed  01ce                   -add esi, ecx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004709ef  88d9                   -mov cl, bl
    cpu.cl = cpu.bl;
    // 004709f1  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004709f3  d3fe                   -sar esi, cl
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (cpu.cl % 32));
    // 004709f5  88d1                   -mov cl, dl
    cpu.cl = cpu.dl;
    // 004709f7  892d88b75100           -mov dword ptr [0x51b788], ebp
    app->getMemory<x86::reg32>(x86::reg32(5355400) /* 0x51b788 */) = cpu.ebp;
    // 004709fd  d3ff                   -sar edi, cl
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (cpu.cl % 32));
    // 004709ff  893564b75100           -mov dword ptr [0x51b764], esi
    app->getMemory<x86::reg32>(x86::reg32(5355364) /* 0x51b764 */) = cpu.esi;
    // 00470a05  893d6cb75100           -mov dword ptr [0x51b76c], edi
    app->getMemory<x86::reg32>(x86::reg32(5355372) /* 0x51b76c */) = cpu.edi;
    // 00470a0b  e8904cffff             -call 0x4656a0
    cpu.esp -= 4;
    sub_4656a0(app, cpu);
    if (cpu.terminate) return;
    // 00470a10  8a0d8db75100           -mov cl, byte ptr [0x51b78d]
    cpu.cl = app->getMemory<x86::reg8>(x86::reg32(5355405) /* 0x51b78d */);
    // 00470a16  d3f8                   +sar eax, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 00470a18  a378b75100             -mov dword ptr [0x51b778], eax
    app->getMemory<x86::reg32>(x86::reg32(5355384) /* 0x51b778 */) = cpu.eax;
    // 00470a1d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470a1e  e970ffffff             -jmp 0x470993
    goto L_0x00470993;
L_0x00470a23:
    // 00470a23  0fbf10                 -movsx edx, word ptr [eax]
    cpu.edx = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.eax)));
    // 00470a26  891584b75100           -mov dword ptr [0x51b784], edx
    app->getMemory<x86::reg32>(x86::reg32(5355396) /* 0x51b784 */) = cpu.edx;
    // 00470a2c  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00470a2e  8b4802                 -mov ecx, dword ptr [eax + 2]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00470a31  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00470a34  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00470a37  891588b75100           -mov dword ptr [0x51b788], edx
    app->getMemory<x86::reg32>(x86::reg32(5355400) /* 0x51b788 */) = cpu.edx;
    // 00470a3d  8b1584b75100           -mov edx, dword ptr [0x51b784]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5355396) /* 0x51b784 */);
    // 00470a43  01ca                   +add edx, ecx
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00470a45  e927ffffff             -jmp 0x470971
    goto L_0x00470971;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_470a50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00470a50  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00470a51  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00470a52  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00470a53  833d28f54d0001         +cmp dword ptr [0x4df528], 1
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
    // 00470a5a  756b                   -jne 0x470ac7
    if (!cpu.flags.zf)
    {
        goto L_0x00470ac7;
    }
    // 00470a5c  68f0000000             -push 0xf0
    app->getMemory<x86::reg32>(cpu.esp-4) = 240 /*0xf0*/;
    cpu.esp -= 4;
    // 00470a61  6880020000             -push 0x280
    app->getMemory<x86::reg32>(cpu.esp-4) = 640 /*0x280*/;
    cpu.esp -= 4;
    // 00470a66  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00470a68  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00470a6a  68f0000000             -push 0xf0
    app->getMemory<x86::reg32>(cpu.esp-4) = 240 /*0xf0*/;
    cpu.esp -= 4;
    // 00470a6f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00470a71  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00470a73  e878000000             -call 0x470af0
    cpu.esp -= 4;
    sub_470af0(app, cpu);
    if (cpu.terminate) return;
    // 00470a78  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00470a7a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
L_0x00470a7c:
    // 00470a7c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00470a81  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00470a83  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00470a85  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00470a87  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00470a89  e862000000             -call 0x470af0
    cpu.esp -= 4;
    sub_470af0(app, cpu);
    if (cpu.terminate) return;
    // 00470a8e  68e0010000             -push 0x1e0
    app->getMemory<x86::reg32>(cpu.esp-4) = 480 /*0x1e0*/;
    cpu.esp -= 4;
    // 00470a93  6880020000             -push 0x280
    app->getMemory<x86::reg32>(cpu.esp-4) = 640 /*0x280*/;
    cpu.esp -= 4;
    // 00470a98  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00470a9d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00470a9f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00470aa1  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00470aa3  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00470aa5  e846000000             -call 0x470af0
    cpu.esp -= 4;
    sub_470af0(app, cpu);
    if (cpu.terminate) return;
    // 00470aaa  6887000000             -push 0x87
    app->getMemory<x86::reg32>(cpu.esp-4) = 135 /*0x87*/;
    cpu.esp -= 4;
    // 00470aaf  6a6c                   -push 0x6c
    app->getMemory<x86::reg32>(cpu.esp-4) = 108 /*0x6c*/;
    cpu.esp -= 4;
    // 00470ab1  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 00470ab6  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00470ab8  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00470aba  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00470abc  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00470abe  e82d000000             -call 0x470af0
    cpu.esp -= 4;
    sub_470af0(app, cpu);
    if (cpu.terminate) return;
    // 00470ac3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470ac4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470ac5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470ac6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00470ac7:
    // 00470ac7  68e0010000             -push 0x1e0
    app->getMemory<x86::reg32>(cpu.esp-4) = 480 /*0x1e0*/;
    cpu.esp -= 4;
    // 00470acc  6880020000             -push 0x280
    app->getMemory<x86::reg32>(cpu.esp-4) = 640 /*0x280*/;
    cpu.esp -= 4;
    // 00470ad1  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00470ad3  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00470ad5  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00470ad7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00470ad9  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00470adb  e810000000             -call 0x470af0
    cpu.esp -= 4;
    sub_470af0(app, cpu);
    if (cpu.terminate) return;
    // 00470ae0  6a46                   -push 0x46
    app->getMemory<x86::reg32>(cpu.esp-4) = 70 /*0x46*/;
    cpu.esp -= 4;
    // 00470ae2  6896000000             -push 0x96
    app->getMemory<x86::reg32>(cpu.esp-4) = 150 /*0x96*/;
    cpu.esp -= 4;
    // 00470ae7  eb93                   -jmp 0x470a7c
    goto L_0x00470a7c;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_470af0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00470af0  668914c574ac5100       -mov word ptr [eax*8 + 0x51ac74], dx
    app->getMemory<x86::reg16>(x86::reg32(5352564) /* 0x51ac74 */ + cpu.eax * 8) = cpu.dx;
    // 00470af8  66891cc576ac5100       -mov word ptr [eax*8 + 0x51ac76], bx
    app->getMemory<x86::reg16>(x86::reg32(5352566) /* 0x51ac76 */ + cpu.eax * 8) = cpu.bx;
    // 00470b00  66890cc594ac5100       -mov word ptr [eax*8 + 0x51ac94], cx
    app->getMemory<x86::reg16>(x86::reg32(5352596) /* 0x51ac94 */ + cpu.eax * 8) = cpu.cx;
    // 00470b08  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00470b0c  668914c578ac5100       -mov word ptr [eax*8 + 0x51ac78], dx
    app->getMemory<x86::reg16>(x86::reg32(5352568) /* 0x51ac78 */ + cpu.eax * 8) = cpu.dx;
    // 00470b14  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00470b18  668914c57aac5100       -mov word ptr [eax*8 + 0x51ac7a], dx
    app->getMemory<x86::reg16>(x86::reg32(5352570) /* 0x51ac7a */ + cpu.eax * 8) = cpu.dx;
    // 00470b20  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00470b24  668914c596ac5100       -mov word ptr [eax*8 + 0x51ac96], dx
    app->getMemory<x86::reg16>(x86::reg32(5352598) /* 0x51ac96 */ + cpu.eax * 8) = cpu.dx;
    // 00470b2c  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00470b30  668914c598ac5100       -mov word ptr [eax*8 + 0x51ac98], dx
    app->getMemory<x86::reg16>(x86::reg32(5352600) /* 0x51ac98 */ + cpu.eax * 8) = cpu.dx;
    // 00470b38  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00470b3c  668914c59aac5100       -mov word ptr [eax*8 + 0x51ac9a], dx
    app->getMemory<x86::reg16>(x86::reg32(5352602) /* 0x51ac9a */ + cpu.eax * 8) = cpu.dx;
    // 00470b44  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_470b50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00470b50  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00470b51  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00470b54  0574ac5100             -add eax, 0x51ac74
    (cpu.eax) += x86::reg32(x86::sreg32(5352564 /*0x51ac74*/));
    // 00470b59  0fbf30                 -movsx esi, word ptr [eax]
    cpu.esi = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.eax)));
    // 00470b5c  8932                   -mov dword ptr [edx], esi
    app->getMemory<x86::reg32>(cpu.edx) = cpu.esi;
    // 00470b5e  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00470b60  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00470b63  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 00470b65  8b5002                 -mov edx, dword ptr [eax + 2]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00470b68  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00470b6b  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 00470b6d  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00470b70  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00470b74  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00470b77  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 00470b79  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470b7a  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_470b80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00470b80  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00470b81  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00470b82  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00470b83  a150b75100             -mov eax, dword ptr [0x51b750]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355344) /* 0x51b750 */);
    // 00470b88  8a144540a34c00         -mov dl, byte ptr [eax*2 + 0x4ca340]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5022528) /* 0x4ca340 */ + cpu.eax * 2);
    // 00470b8f  88158cb75100           -mov byte ptr [0x51b78c], dl
    app->getMemory<x86::reg8>(x86::reg32(5355404) /* 0x51b78c */) = cpu.dl;
    // 00470b95  8a044541a34c00         -mov al, byte ptr [eax*2 + 0x4ca341]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5022529) /* 0x4ca341 */ + cpu.eax * 2);
    // 00470b9c  8b1528f54d00           -mov edx, dword ptr [0x4df528]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5109032) /* 0x4df528 */);
    // 00470ba2  a28db75100             -mov byte ptr [0x51b78d], al
    app->getMemory<x86::reg8>(x86::reg32(5355405) /* 0x51b78d */) = cpu.al;
    // 00470ba7  83fa01                 +cmp edx, 1
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
    // 00470baa  7549                   -jne 0x470bf5
    if (!cpu.flags.zf)
    {
        goto L_0x00470bf5;
    }
    // 00470bac  a14cb75100             -mov eax, dword ptr [0x51b74c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355340) /* 0x51b74c */);
    // 00470bb1  8a0d8cb75100           -mov cl, byte ptr [0x51b78c]
    cpu.cl = app->getMemory<x86::reg8>(x86::reg32(5355404) /* 0x51b78c */);
    // 00470bb7  8b14c528a34c00         -mov edx, dword ptr [eax*8 + 0x4ca328]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5022504) /* 0x4ca328 */ + cpu.eax * 8);
    // 00470bbe  d3fa                   -sar edx, cl
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (cpu.cl % 32));
    // 00470bc0  66891598ac5100         -mov word ptr [0x51ac98], dx
    app->getMemory<x86::reg16>(x86::reg32(5352600) /* 0x51ac98 */) = cpu.dx;
    // 00470bc7  8a158db75100           -mov dl, byte ptr [0x51b78d]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5355405) /* 0x51b78d */);
    // 00470bcd  fec2                   -inc dl
    (cpu.dl)++;
    // 00470bcf  8b04c52ca34c00         -mov eax, dword ptr [eax*8 + 0x4ca32c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5022508) /* 0x4ca32c */ + cpu.eax * 8);
    // 00470bd6  88d1                   -mov cl, dl
    cpu.cl = cpu.dl;
    // 00470bd8  88158db75100           -mov byte ptr [0x51b78d], dl
    app->getMemory<x86::reg8>(x86::reg32(5355405) /* 0x51b78d */) = cpu.dl;
    // 00470bde  d3f8                   -sar eax, cl
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (cpu.cl % 32));
    // 00470be0  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00470be2  66a39aac5100           -mov word ptr [0x51ac9a], ax
    app->getMemory<x86::reg16>(x86::reg32(5352602) /* 0x51ac9a */) = cpu.ax;
    // 00470be8  66891594ac5100         -mov word ptr [0x51ac94], dx
    app->getMemory<x86::reg16>(x86::reg32(5352596) /* 0x51ac94 */) = cpu.dx;
    // 00470bef  66a396ac5100           -mov word ptr [0x51ac96], ax
    app->getMemory<x86::reg16>(x86::reg32(5352598) /* 0x51ac96 */) = cpu.ax;
L_0x00470bf5:
    // 00470bf5  a14cb75100             -mov eax, dword ptr [0x51b74c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355340) /* 0x51b74c */);
    // 00470bfa  8a0d8cb75100           -mov cl, byte ptr [0x51b78c]
    cpu.cl = app->getMemory<x86::reg8>(x86::reg32(5355404) /* 0x51b78c */);
    // 00470c00  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00470c02  8b14c528a34c00         -mov edx, dword ptr [eax*8 + 0x4ca328]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5022504) /* 0x4ca328 */ + cpu.eax * 8);
    // 00470c09  8b04c52ca34c00         -mov eax, dword ptr [eax*8 + 0x4ca32c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5022508) /* 0x4ca32c */ + cpu.eax * 8);
    // 00470c10  d3fa                   -sar edx, cl
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (cpu.cl % 32));
    // 00470c12  8a0d8db75100           -mov cl, byte ptr [0x51b78d]
    cpu.cl = app->getMemory<x86::reg8>(x86::reg32(5355405) /* 0x51b78d */);
    // 00470c18  66891578ac5100         -mov word ptr [0x51ac78], dx
    app->getMemory<x86::reg16>(x86::reg32(5352568) /* 0x51ac78 */) = cpu.dx;
    // 00470c1f  88cb                   -mov bl, cl
    cpu.bl = cpu.cl;
    // 00470c21  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00470c23  d3f8                   -sar eax, cl
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (cpu.cl % 32));
    // 00470c25  8a158cb75100           -mov dl, byte ptr [0x51b78c]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5355404) /* 0x51b78c */);
    // 00470c2b  66a37aac5100           -mov word ptr [0x51ac7a], ax
    app->getMemory<x86::reg16>(x86::reg32(5352570) /* 0x51ac7a */) = cpu.ax;
    // 00470c31  a14cb75100             -mov eax, dword ptr [0x51b74c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355340) /* 0x51b74c */);
    // 00470c36  e805400000             -call 0x474c40
    cpu.esp -= 4;
    sub_474c40(app, cpu);
    if (cpu.terminate) return;
    // 00470c3b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470c3c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470c3d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470c3e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_470c40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00470c40  833d4cb7510000         +cmp dword ptr [0x51b74c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5355340) /* 0x51b74c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00470c47  7506                   -jne 0x470c4f
    if (!cpu.flags.zf)
    {
        goto L_0x00470c4f;
    }
    // 00470c49  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00470c4e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00470c4f:
    // 00470c4f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00470c51  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_470c60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00470c60  a14cb75100             -mov eax, dword ptr [0x51b74c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355340) /* 0x51b74c */);
    // 00470c65  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_470c70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00470c70  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00470c71  833d28f54d0001         +cmp dword ptr [0x4df528], 1
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
    // 00470c78  7425                   -je 0x470c9f
    if (cpu.flags.zf)
    {
        goto L_0x00470c9f;
    }
    // 00470c7a  833db0f34d0000         +cmp dword ptr [0x4df3b0], 0
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
    // 00470c81  751e                   -jne 0x470ca1
    if (!cpu.flags.zf)
    {
        goto L_0x00470ca1;
    }
L_0x00470c83:
    // 00470c83  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 00470c88  a14cb75100             -mov eax, dword ptr [0x51b74c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355340) /* 0x51b74c */);
    // 00470c8d  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00470c8f  892d54b75100           -mov dword ptr [0x51b754], ebp
    app->getMemory<x86::reg32>(x86::reg32(5355348) /* 0x51b754 */) = cpu.ebp;
    // 00470c95  a34cb75100             -mov dword ptr [0x51b74c], eax
    app->getMemory<x86::reg32>(x86::reg32(5355340) /* 0x51b74c */) = cpu.eax;
    // 00470c9a  83f803                 +cmp eax, 3
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
    // 00470c9d  7d27                   -jge 0x470cc6
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00470cc6;
    }
L_0x00470c9f:
    // 00470c9f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470ca0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00470ca1:
    // 00470ca1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00470ca3  e8988cfcff             -call 0x439940
    cpu.esp -= 4;
    sub_439940(app, cpu);
    if (cpu.terminate) return;
    // 00470ca8  833d14f64f0002         +cmp dword ptr [0x4ff614], 2
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
    // 00470caf  75d2                   -jne 0x470c83
    if (!cpu.flags.zf)
    {
        goto L_0x00470c83;
    }
    // 00470cb1  833d1c104e0008         +cmp dword ptr [0x4e101c], 8
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5115932) /* 0x4e101c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00470cb8  75c9                   -jne 0x470c83
    if (!cpu.flags.zf)
    {
        goto L_0x00470c83;
    }
    // 00470cba  c7051c104e0007000000   -mov dword ptr [0x4e101c], 7
    app->getMemory<x86::reg32>(x86::reg32(5115932) /* 0x4e101c */) = 7 /*0x7*/;
    // 00470cc4  ebbd                   -jmp 0x470c83
    goto L_0x00470c83;
L_0x00470cc6:
    // 00470cc6  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00470cc7  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00470cc9  890d4cb75100           -mov dword ptr [0x51b74c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5355340) /* 0x51b74c */) = cpu.ecx;
    // 00470ccf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470cd0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470cd1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_470ce0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00470ce0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00470ce1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00470ce2  8b1550b75100           -mov edx, dword ptr [0x51b750]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5355344) /* 0x51b750 */);
    // 00470ce8  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00470ced  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00470cef  890d54b75100           -mov dword ptr [0x51b754], ecx
    app->getMemory<x86::reg32>(x86::reg32(5355348) /* 0x51b754 */) = cpu.ecx;
    // 00470cf5  83fa05                 +cmp edx, 5
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00470cf8  7c02                   -jl 0x470cfc
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00470cfc;
    }
    // 00470cfa  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00470cfc:
    // 00470cfc  891550b75100           -mov dword ptr [0x51b750], edx
    app->getMemory<x86::reg32>(x86::reg32(5355344) /* 0x51b750 */) = cpu.edx;
    // 00470d02  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470d03  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470d04  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_470d10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00470d10  a150b75100             -mov eax, dword ptr [0x51b750]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355344) /* 0x51b750 */);
    // 00470d15  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_470d20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00470d20  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00470d21  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00470d22  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00470d24  e827000000             -call 0x470d50
    cpu.esp -= 4;
    sub_470d50(app, cpu);
    if (cpu.terminate) return;
    // 00470d29  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00470d2b  7413                   -je 0x470d40
    if (cpu.flags.zf)
    {
        goto L_0x00470d40;
    }
L_0x00470d2d:
    // 00470d2d  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00470d30  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00470d32  ff148d0cac5100         -call dword ptr [ecx*4 + 0x51ac0c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5352460) /* 0x51ac0c */ + cpu.ecx * 4);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00470d39  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 00470d3b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00470d3d  75ee                   -jne 0x470d2d
    if (!cpu.flags.zf)
    {
        goto L_0x00470d2d;
    }
    // 00470d3f  90                     -nop 
    ;
L_0x00470d40:
    // 00470d40  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470d41  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470d42  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_470d50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00470d50  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00470d51  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00470d52  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00470d53  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00470d54  b970124700             -mov ecx, 0x471270
    cpu.ecx = 4657776 /*0x471270*/;
    // 00470d59  bb50124700             -mov ebx, 0x471250
    cpu.ebx = 4657744 /*0x471250*/;
    // 00470d5e  be60124700             -mov esi, 0x471260
    cpu.esi = 4657760 /*0x471260*/;
    // 00470d63  bab0124700             -mov edx, 0x4712b0
    cpu.edx = 4657840 /*0x4712b0*/;
    // 00470d68  890d30ac5100           -mov dword ptr [0x51ac30], ecx
    app->getMemory<x86::reg32>(x86::reg32(5352496) /* 0x51ac30 */) = cpu.ecx;
    // 00470d6e  891d34ac5100           -mov dword ptr [0x51ac34], ebx
    app->getMemory<x86::reg32>(x86::reg32(5352500) /* 0x51ac34 */) = cpu.ebx;
    // 00470d74  893538ac5100           -mov dword ptr [0x51ac38], esi
    app->getMemory<x86::reg32>(x86::reg32(5352504) /* 0x51ac38 */) = cpu.esi;
    // 00470d7a  89152cac5100           -mov dword ptr [0x51ac2c], edx
    app->getMemory<x86::reg32>(x86::reg32(5352492) /* 0x51ac2c */) = cpu.edx;
    // 00470d80  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470d81  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470d82  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470d83  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470d84  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_470d90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00470d90  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00470d91  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00470d92  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00470d93  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00470d94  b910134700             -mov ecx, 0x471310
    cpu.ecx = 4657936 /*0x471310*/;
    // 00470d99  bbf0124700             -mov ebx, 0x4712f0
    cpu.ebx = 4657904 /*0x4712f0*/;
    // 00470d9e  be00134700             -mov esi, 0x471300
    cpu.esi = 4657920 /*0x471300*/;
    // 00470da3  ba50134700             -mov edx, 0x471350
    cpu.edx = 4658000 /*0x471350*/;
    // 00470da8  890d30ac5100           -mov dword ptr [0x51ac30], ecx
    app->getMemory<x86::reg32>(x86::reg32(5352496) /* 0x51ac30 */) = cpu.ecx;
    // 00470dae  891d34ac5100           -mov dword ptr [0x51ac34], ebx
    app->getMemory<x86::reg32>(x86::reg32(5352500) /* 0x51ac34 */) = cpu.ebx;
    // 00470db4  893538ac5100           -mov dword ptr [0x51ac38], esi
    app->getMemory<x86::reg32>(x86::reg32(5352504) /* 0x51ac38 */) = cpu.esi;
    // 00470dba  89152cac5100           -mov dword ptr [0x51ac2c], edx
    app->getMemory<x86::reg32>(x86::reg32(5352492) /* 0x51ac2c */) = cpu.edx;
    // 00470dc0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470dc1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470dc2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470dc3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470dc4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_470dd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00470dd0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00470dd1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00470dd2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00470dd3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00470dd4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00470dd5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00470dd6  b940104700             -mov ecx, 0x471040
    cpu.ecx = 4657216 /*0x471040*/;
    // 00470ddb  bbe00e4700             -mov ebx, 0x470ee0
    cpu.ebx = 4656864 /*0x470ee0*/;
    // 00470de0  bf20124700             -mov edi, 0x471220
    cpu.edi = 4657696 /*0x471220*/;
    // 00470de5  bd10124700             -mov ebp, 0x471210
    cpu.ebp = 4657680 /*0x471210*/;
    // 00470dea  b800124700             -mov eax, 0x471200
    cpu.eax = 4657664 /*0x471200*/;
    // 00470def  ba70104700             -mov edx, 0x471070
    cpu.edx = 4657264 /*0x471070*/;
    // 00470df4  be70114700             -mov esi, 0x471170
    cpu.esi = 4657520 /*0x471170*/;
    // 00470df9  890d50ac5100           -mov dword ptr [0x51ac50], ecx
    app->getMemory<x86::reg32>(x86::reg32(5352528) /* 0x51ac50 */) = cpu.ecx;
    // 00470dff  891d10ac5100           -mov dword ptr [0x51ac10], ebx
    app->getMemory<x86::reg32>(x86::reg32(5352464) /* 0x51ac10 */) = cpu.ebx;
    // 00470e05  891d14ac5100           -mov dword ptr [0x51ac14], ebx
    app->getMemory<x86::reg32>(x86::reg32(5352468) /* 0x51ac14 */) = cpu.ebx;
    // 00470e0b  893d18ac5100           -mov dword ptr [0x51ac18], edi
    app->getMemory<x86::reg32>(x86::reg32(5352472) /* 0x51ac18 */) = cpu.edi;
    // 00470e11  892d1cac5100           -mov dword ptr [0x51ac1c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5352476) /* 0x51ac1c */) = cpu.ebp;
    // 00470e17  a320ac5100             -mov dword ptr [0x51ac20], eax
    app->getMemory<x86::reg32>(x86::reg32(5352480) /* 0x51ac20 */) = cpu.eax;
    // 00470e1c  893d24ac5100           -mov dword ptr [0x51ac24], edi
    app->getMemory<x86::reg32>(x86::reg32(5352484) /* 0x51ac24 */) = cpu.edi;
    // 00470e22  89150cac5100           -mov dword ptr [0x51ac0c], edx
    app->getMemory<x86::reg32>(x86::reg32(5352460) /* 0x51ac0c */) = cpu.edx;
    // 00470e28  89355cac5100           -mov dword ptr [0x51ac5c], esi
    app->getMemory<x86::reg32>(x86::reg32(5352540) /* 0x51ac5c */) = cpu.esi;
    // 00470e2e  b9b0114700             -mov ecx, 0x4711b0
    cpu.ecx = 4657584 /*0x4711b0*/;
    // 00470e33  bb90114700             -mov ebx, 0x471190
    cpu.ebx = 4657552 /*0x471190*/;
    // 00470e38  bf20114700             -mov edi, 0x471120
    cpu.edi = 4657440 /*0x471120*/;
    // 00470e3d  bde00e4700             -mov ebp, 0x470ee0
    cpu.ebp = 4656864 /*0x470ee0*/;
    // 00470e42  b850134700             -mov eax, 0x471350
    cpu.eax = 4658000 /*0x471350*/;
    // 00470e47  ba10134700             -mov edx, 0x471310
    cpu.edx = 4657936 /*0x471310*/;
    // 00470e4c  be40124700             -mov esi, 0x471240
    cpu.esi = 4657728 /*0x471240*/;
    // 00470e51  890d60ac5100           -mov dword ptr [0x51ac60], ecx
    app->getMemory<x86::reg32>(x86::reg32(5352544) /* 0x51ac60 */) = cpu.ecx;
    // 00470e57  891d58ac5100           -mov dword ptr [0x51ac58], ebx
    app->getMemory<x86::reg32>(x86::reg32(5352536) /* 0x51ac58 */) = cpu.ebx;
    // 00470e5d  893d54ac5100           -mov dword ptr [0x51ac54], edi
    app->getMemory<x86::reg32>(x86::reg32(5352532) /* 0x51ac54 */) = cpu.edi;
    // 00470e63  892d28ac5100           -mov dword ptr [0x51ac28], ebp
    app->getMemory<x86::reg32>(x86::reg32(5352488) /* 0x51ac28 */) = cpu.ebp;
    // 00470e69  a32cac5100             -mov dword ptr [0x51ac2c], eax
    app->getMemory<x86::reg32>(x86::reg32(5352492) /* 0x51ac2c */) = cpu.eax;
    // 00470e6e  891530ac5100           -mov dword ptr [0x51ac30], edx
    app->getMemory<x86::reg32>(x86::reg32(5352496) /* 0x51ac30 */) = cpu.edx;
    // 00470e74  89353cac5100           -mov dword ptr [0x51ac3c], esi
    app->getMemory<x86::reg32>(x86::reg32(5352508) /* 0x51ac3c */) = cpu.esi;
    // 00470e7a  893544ac5100           -mov dword ptr [0x51ac44], esi
    app->getMemory<x86::reg32>(x86::reg32(5352516) /* 0x51ac44 */) = cpu.esi;
    // 00470e80  893548ac5100           -mov dword ptr [0x51ac48], esi
    app->getMemory<x86::reg32>(x86::reg32(5352520) /* 0x51ac48 */) = cpu.esi;
    // 00470e86  b9f0124700             -mov ecx, 0x4712f0
    cpu.ecx = 4657904 /*0x4712f0*/;
    // 00470e8b  bb00134700             -mov ebx, 0x471300
    cpu.ebx = 4657920 /*0x471300*/;
    // 00470e90  bf30124700             -mov edi, 0x471230
    cpu.edi = 4657712 /*0x471230*/;
    // 00470e95  baf00f4700             -mov edx, 0x470ff0
    cpu.edx = 4657136 /*0x470ff0*/;
    // 00470e9a  beb00f4700             -mov esi, 0x470fb0
    cpu.esi = 4657072 /*0x470fb0*/;
    // 00470e9f  890d34ac5100           -mov dword ptr [0x51ac34], ecx
    app->getMemory<x86::reg32>(x86::reg32(5352500) /* 0x51ac34 */) = cpu.ecx;
    // 00470ea5  891d38ac5100           -mov dword ptr [0x51ac38], ebx
    app->getMemory<x86::reg32>(x86::reg32(5352504) /* 0x51ac38 */) = cpu.ebx;
    // 00470eab  893d40ac5100           -mov dword ptr [0x51ac40], edi
    app->getMemory<x86::reg32>(x86::reg32(5352512) /* 0x51ac40 */) = cpu.edi;
    // 00470eb1  891568ac5100           -mov dword ptr [0x51ac68], edx
    app->getMemory<x86::reg32>(x86::reg32(5352552) /* 0x51ac68 */) = cpu.edx;
    // 00470eb7  893570ac5100           -mov dword ptr [0x51ac70], esi
    app->getMemory<x86::reg32>(x86::reg32(5352560) /* 0x51ac70 */) = cpu.esi;
    // 00470ebd  b9e00f4700             -mov ecx, 0x470fe0
    cpu.ecx = 4657120 /*0x470fe0*/;
    // 00470ec2  bbd00f4700             -mov ebx, 0x470fd0
    cpu.ebx = 4657104 /*0x470fd0*/;
    // 00470ec7  890d64ac5100           -mov dword ptr [0x51ac64], ecx
    app->getMemory<x86::reg32>(x86::reg32(5352548) /* 0x51ac64 */) = cpu.ecx;
    // 00470ecd  891d6cac5100           -mov dword ptr [0x51ac6c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5352556) /* 0x51ac6c */) = cpu.ebx;
    // 00470ed3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470ed4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470ed5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470ed6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470ed7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470ed8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470ed9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_470ee0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00470ee0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_470ef0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00470ef0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00470ef1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00470ef2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00470ef3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00470ef4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00470ef5  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00470ef8  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00470efa  8b1568b75100           -mov edx, dword ptr [0x51b768]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5355368) /* 0x51b768 */);
    // 00470f00  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00470f02  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00470f04  7e20                   -jle 0x470f26
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00470f26;
    }
    // 00470f06  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00470f08:
    // 00470f08  ba0c000000             -mov edx, 0xc
    cpu.edx = 12 /*0xc*/;
    // 00470f0d  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00470f0f  e85cbafeff             -call 0x45c970
    cpu.esp -= 4;
    sub_45c970(app, cpu);
    if (cpu.terminate) return;
    // 00470f14  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00470f16  7533                   -jne 0x470f4b
    if (!cpu.flags.zf)
    {
        goto L_0x00470f4b;
    }
L_0x00470f18:
    // 00470f18  8b3d68b75100           -mov edi, dword ptr [0x51b768]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5355368) /* 0x51b768 */);
    // 00470f1e  41                     -inc ecx
    (cpu.ecx)++;
    // 00470f1f  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00470f22  39f9                   +cmp ecx, edi
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
    // 00470f24  7ce2                   -jl 0x470f08
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00470f08;
    }
L_0x00470f26:
    // 00470f26  833e00                 +cmp dword ptr [esi], 0
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
    // 00470f29  7546                   -jne 0x470f71
    if (!cpu.flags.zf)
    {
        goto L_0x00470f71;
    }
    // 00470f2b  b900000a00             -mov ecx, 0xa0000
    cpu.ecx = 655360 /*0xa0000*/;
L_0x00470f30:
    // 00470f30  ba0c000000             -mov edx, 0xc
    cpu.edx = 12 /*0xc*/;
    // 00470f35  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00470f39  e832bafeff             -call 0x45c970
    cpu.esp -= 4;
    sub_45c970(app, cpu);
    if (cpu.terminate) return;
    // 00470f3e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00470f40  7536                   -jne 0x470f78
    if (!cpu.flags.zf)
    {
        goto L_0x00470f78;
    }
    // 00470f42  83c408                 +add esp, 8
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
    // 00470f45  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470f46  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470f47  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470f48  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470f49  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470f4a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00470f4b:
    // 00470f4b  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00470f4e  c7400416000000         -mov dword ptr [eax + 4], 0x16
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 22 /*0x16*/;
    // 00470f55  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00470f58  8a81f4b65100           -mov al, byte ptr [ecx + 0x51b6f4]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5355252) /* 0x51b6f4 */);
    // 00470f5e  884208                 -mov byte ptr [edx + 8], al
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.al;
    // 00470f61  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00470f64  8b8304b75100           -mov eax, dword ptr [ebx + 0x51b704]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5355268) /* 0x51b704 */);
    // 00470f6a  e8c1d2feff             -call 0x45e230
    cpu.esp -= 4;
    sub_45e230(app, cpu);
    if (cpu.terminate) return;
    // 00470f6f  eba7                   -jmp 0x470f18
    goto L_0x00470f18;
L_0x00470f71:
    // 00470f71  b900000400             -mov ecx, 0x40000
    cpu.ecx = 262144 /*0x40000*/;
    // 00470f76  ebb8                   -jmp 0x470f30
    goto L_0x00470f30;
L_0x00470f78:
    // 00470f78  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00470f7c  c7400418000000         -mov dword ptr [eax + 4], 0x18
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 24 /*0x18*/;
    // 00470f83  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00470f87  c6400801               -mov byte ptr [eax + 8], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */) = 1 /*0x1*/;
    // 00470f8b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00470f8d  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00470f91  e8cad2feff             -call 0x45e260
    cpu.esp -= 4;
    sub_45e260(app, cpu);
    if (cpu.terminate) return;
    // 00470f96  e895d2feff             -call 0x45e230
    cpu.esp -= 4;
    sub_45e230(app, cpu);
    if (cpu.terminate) return;
    // 00470f9b  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00470f9e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470f9f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470fa0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470fa1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470fa2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470fa3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_470fb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00470fb0  833d54b7510000         +cmp dword ptr [0x51b754], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5355348) /* 0x51b754 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00470fb7  0f84376f0000           -je 0x477ef4
    if (cpu.flags.zf)
    {
        return sub_477ef4(app, cpu);
    }
    // 00470fbd  e9466f0000             -jmp 0x477f08
    return sub_477f08(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_470fd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00470fd0  e9bbfdffff             -jmp 0x470d90
    return sub_470d90(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_470fe0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00470fe0  8a4008                 -mov al, byte ptr [eax + 8]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00470fe3  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00470fe8  a380b75100             -mov dword ptr [0x51b780], eax
    app->getMemory<x86::reg32>(x86::reg32(5355392) /* 0x51b780 */) = cpu.eax;
    // 00470fed  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_470ff0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00470ff0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00470ff1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00470ff2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00470ff3  6683780800             +cmp word ptr [eax + 8], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(8) /* 0x8 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00470ff8  7c21                   -jl 0x47101b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047101b;
    }
    // 00470ffa  8b480c                 -mov ecx, dword ptr [eax + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00470ffd  8b580a                 -mov ebx, dword ptr [eax + 0xa]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10) /* 0xa */);
    // 00471000  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00471003  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00471006  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 00471009  8b4006                 -mov eax, dword ptr [eax + 6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 0047100c  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0047100f  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00471012  e899780000             -call 0x4788b0
    cpu.esp -= 4;
    sub_4788b0(app, cpu);
    if (cpu.terminate) return;
    // 00471017  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471018  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471019  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047101a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047101b:
    // 0047101b  8b0d6cb75100           -mov ecx, dword ptr [0x51b76c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5355372) /* 0x51b76c */);
    // 00471021  8b1d64b75100           -mov ebx, dword ptr [0x51b764]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5355364) /* 0x51b764 */);
    // 00471027  8b1588b75100           -mov edx, dword ptr [0x51b788]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5355400) /* 0x51b788 */);
    // 0047102d  a184b75100             -mov eax, dword ptr [0x51b784]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355396) /* 0x51b784 */);
    // 00471032  e879780000             -call 0x4788b0
    cpu.esp -= 4;
    sub_4788b0(app, cpu);
    if (cpu.terminate) return;
    // 00471037  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471038  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471039  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047103a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_471040(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00471040  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00471041  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00471042  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00471043  8b480e                 -mov ecx, dword ptr [eax + 0xe]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(14) /* 0xe */);
    // 00471046  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00471049  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047104b  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0047104e  8a5008                 -mov dl, byte ptr [eax + 8]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00471051  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 00471054  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00471055  8b500a                 -mov edx, dword ptr [eax + 0xa]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10) /* 0xa */);
    // 00471058  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0047105b  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0047105e  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00471061  e85aba0100             -call 0x48cac0
    cpu.esp -= 4;
    sub_48cac0(app, cpu);
    if (cpu.terminate) return;
    // 00471066  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471067  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471068  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471069  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_471070(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00471070  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00471071  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00471072  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00471073  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00471074  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00471075  83ec40                 -sub esp, 0x40
    (cpu.esp) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00471078  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047107a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047107c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047107e  8a4239                 -mov al, byte ptr [edx + 0x39]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(57) /* 0x39 */);
    // 00471081  8a5a3a                 -mov bl, byte ptr [edx + 0x3a]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(58) /* 0x3a */);
    // 00471084  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 00471087  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 0047108a  09c3                   -or ebx, eax
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0047108c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047108e  8a423b                 -mov al, byte ptr [edx + 0x3b]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(59) /* 0x3b */);
    // 00471091  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 00471093  e884700000             -call 0x47811c
    cpu.esp -= 4;
    sub_47811c(app, cpu);
    if (cpu.terminate) return;
    // 00471098  8b4a08                 -mov ecx, dword ptr [edx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0047109b  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047109d  744d                   -je 0x4710ec
    if (cpu.flags.zf)
    {
        goto L_0x004710ec;
    }
    // 0047109f  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004710a1  8d7c2420               -lea edi, [esp + 0x20]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004710a5  8d7610                 -lea esi, [esi + 0x10]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004710a8  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004710a9  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004710aa  8b720c                 -mov esi, dword ptr [edx + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004710ad  8d7c2428               -lea edi, [esp + 0x28]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004710b1  8d7610                 -lea esi, [esi + 0x10]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004710b4  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004710b5  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004710b6  8b7210                 -mov esi, dword ptr [edx + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004710b9  8d7c2430               -lea edi, [esp + 0x30]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004710bd  8d7610                 -lea esi, [esi + 0x10]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004710c0  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004710c1  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004710c2  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004710c4  8b7214                 -mov esi, dword ptr [edx + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 004710c7  8d5c2424               -lea ebx, [esp + 0x24]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004710cb  8d7c243c               -lea edi, [esp + 0x3c]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 004710cf  8d7610                 -lea esi, [esi + 0x10]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(16) /* 0x10 */);
L_0x004710d2:
    // 004710d2  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 004710d7  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 004710dc  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004710dd  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004710de  e81d3a0200             -call 0x494b00
    cpu.esp -= 4;
    sub_494b00(app, cpu);
    if (cpu.terminate) return;
    // 004710e3  83c440                 +add esp, 0x40
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(64 /*0x40*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004710e6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004710e7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004710e8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004710e9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004710ea  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004710eb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004710ec:
    // 004710ec  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 004710ee  8d7218                 -lea esi, [edx + 0x18]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 004710f1  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004710f2  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004710f3  8d7c2408               -lea edi, [esp + 8]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004710f7  8d7220                 -lea esi, [edx + 0x20]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 004710fa  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004710fb  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004710fc  8d7c2410               -lea edi, [esp + 0x10]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00471100  8d7228                 -lea esi, [edx + 0x28]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(40) /* 0x28 */);
    // 00471103  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00471105  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00471106  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00471107  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00471108  8d7c241c               -lea edi, [esp + 0x1c]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0047110c  8d7230                 -lea esi, [edx + 0x30]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(48) /* 0x30 */);
    // 0047110f  ebc1                   -jmp 0x4710d2
    goto L_0x004710d2;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_471120(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00471120  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00471121  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00471122  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00471123  80782900               +cmp byte ptr [eax + 0x29], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(41) /* 0x29 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00471127  741b                   -je 0x471144
    if (cpu.flags.zf)
    {
        goto L_0x00471144;
    }
    // 00471129  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047112b  8b481c                 -mov ecx, dword ptr [eax + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0047112e  8a5028                 -mov dl, byte ptr [eax + 0x28]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 00471131  8b5818                 -mov ebx, dword ptr [eax + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00471134  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00471135  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00471138  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0047113b  e8a0dc0000             -call 0x47ede0
    cpu.esp -= 4;
    sub_47ede0(app, cpu);
    if (cpu.terminate) return;
    // 00471140  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471141  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471142  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471143  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00471144:
    // 00471144  8d5808                 -lea ebx, [eax + 8]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00471147  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00471149  8a4028                 -mov al, byte ptr [eax + 0x28]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 0047114c  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 00471151  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 00471156  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0047115b  e8a0390200             -call 0x494b00
    cpu.esp -= 4;
    sub_494b00(app, cpu);
    if (cpu.terminate) return;
    // 00471160  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471161  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471162  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471163  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_471170(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00471170  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00471171  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00471172  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00471175  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00471178  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0047117b  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0047117d  e8beb50000             -call 0x47c740
    cpu.esp -= 4;
    sub_47c740(app, cpu);
    if (cpu.terminate) return;
    // 00471182  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471183  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471184  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_471190(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00471190  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00471191  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00471192  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00471195  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00471198  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0047119b  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0047119d  e85e820000             -call 0x479400
    cpu.esp -= 4;
    sub_479400(app, cpu);
    if (cpu.terminate) return;
    // 004711a2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004711a3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004711a4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4711b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004711b0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004711b1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004711b2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004711b3  83ec28                 -sub esp, 0x28
    (cpu.esp) -= x86::reg32(x86::sreg32(40 /*0x28*/));
    // 004711b6  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 004711b8  8d7008                 -lea esi, [eax + 8]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004711bb  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004711bc  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004711bd  8d7c2420               -lea edi, [esp + 0x20]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004711c1  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 004711c3  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004711c4  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004711c5  8d7c2408               -lea edi, [esp + 8]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004711c9  8d7010                 -lea esi, [eax + 0x10]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004711cc  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004711cd  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004711ce  8d7c2410               -lea edi, [esp + 0x10]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004711d2  8d7018                 -lea esi, [eax + 0x18]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004711d5  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004711d6  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004711d7  8d7c2418               -lea edi, [esp + 0x18]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004711db  8d7020                 -lea esi, [eax + 0x20]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004711de  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004711df  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004711e0  8b4028                 -mov eax, dword ptr [eax + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 004711e3  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004711e5  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004711e7  e884320200             -call 0x494470
    cpu.esp -= 4;
    sub_494470(app, cpu);
    if (cpu.terminate) return;
    // 004711ec  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 004711ef  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004711f0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004711f1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004711f2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_471200(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00471200  c7057cb7510007000000   -mov dword ptr [0x51b77c], 7
    app->getMemory<x86::reg32>(x86::reg32(5355388) /* 0x51b77c */) = 7 /*0x7*/;
    // 0047120a  e931030000             -jmp 0x471540
    return sub_471540(app, cpu);
}

/* align: skip 0x00 */
void Application::sub_471210(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00471210  c7057cb7510001000000   -mov dword ptr [0x51b77c], 1
    app->getMemory<x86::reg32>(x86::reg32(5355388) /* 0x51b77c */) = 1 /*0x1*/;
    // 0047121a  e921030000             -jmp 0x471540
    return sub_471540(app, cpu);
}

/* align: skip 0x00 */
void Application::sub_471220(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00471220  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00471221  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00471223  89157cb75100           -mov dword ptr [0x51b77c], edx
    app->getMemory<x86::reg32>(x86::reg32(5355388) /* 0x51b77c */) = cpu.edx;
    // 00471229  e812030000             -call 0x471540
    cpu.esp -= 4;
    sub_471540(app, cpu);
    if (cpu.terminate) return;
    // 0047122e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047122f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_471230(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00471230  c7057cb7510005000000   -mov dword ptr [0x51b77c], 5
    app->getMemory<x86::reg32>(x86::reg32(5355388) /* 0x51b77c */) = 5 /*0x5*/;
    // 0047123a  e951010000             -jmp 0x471390
    return sub_471390(app, cpu);
}

/* align: skip 0x00 */
void Application::sub_471240(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00471240  c7057cb7510004000000   -mov dword ptr [0x51b77c], 4
    app->getMemory<x86::reg32>(x86::reg32(5355388) /* 0x51b77c */) = 4 /*0x4*/;
    // 0047124a  e941010000             -jmp 0x471390
    return sub_471390(app, cpu);
}

/* align: skip 0x00 */
void Application::sub_471250(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00471250  c7057cb7510002000000   -mov dword ptr [0x51b77c], 2
    app->getMemory<x86::reg32>(x86::reg32(5355388) /* 0x51b77c */) = 2 /*0x2*/;
    // 0047125a  e9b1040000             -jmp 0x471710
    return sub_471710(app, cpu);
}

/* align: skip 0x00 */
void Application::sub_471260(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00471260  c7057cb7510007000000   -mov dword ptr [0x51b77c], 7
    app->getMemory<x86::reg32>(x86::reg32(5355388) /* 0x51b77c */) = 7 /*0x7*/;
    // 0047126a  e9a1040000             -jmp 0x471710
    return sub_471710(app, cpu);
}

/* align: skip 0x00 */
void Application::sub_471270(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00471270  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00471271  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00471272  c7057cb7510005000000   -mov dword ptr [0x51b77c], 5
    app->getMemory<x86::reg32>(x86::reg32(5355388) /* 0x51b77c */) = 5 /*0x5*/;
    // 0047127c  8b501c                 -mov edx, dword ptr [eax + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0047127f  8b0dd0ab5100           -mov ecx, dword ptr [0x51abd0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5352400) /* 0x51abd0 */);
    // 00471285  3b4a08                 +cmp ecx, dword ptr [edx + 8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00471288  7513                   -jne 0x47129d
    if (!cpu.flags.zf)
    {
        goto L_0x0047129d;
    }
    // 0047128a  833d80b7510000         +cmp dword ptr [0x51b780], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5355392) /* 0x51b780 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00471291  750a                   -jne 0x47129d
    if (!cpu.flags.zf)
    {
        goto L_0x0047129d;
    }
    // 00471293  c7057cb7510001000000   -mov dword ptr [0x51b77c], 1
    app->getMemory<x86::reg32>(x86::reg32(5355388) /* 0x51b77c */) = 1 /*0x1*/;
L_0x0047129d:
    // 0047129d  e86e040000             -call 0x471710
    cpu.esp -= 4;
    sub_471710(app, cpu);
    if (cpu.terminate) return;
    // 004712a2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004712a3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004712a4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4712b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004712b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004712b1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004712b2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004712b3  c7057cb7510004000000   -mov dword ptr [0x51b77c], 4
    app->getMemory<x86::reg32>(x86::reg32(5355388) /* 0x51b77c */) = 4 /*0x4*/;
    // 004712bd  8b501c                 -mov edx, dword ptr [eax + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004712c0  8b0dd0ab5100           -mov ecx, dword ptr [0x51abd0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5352400) /* 0x51abd0 */);
    // 004712c6  3b4a08                 +cmp ecx, dword ptr [edx + 8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004712c9  7510                   -jne 0x4712db
    if (!cpu.flags.zf)
    {
        goto L_0x004712db;
    }
    // 004712cb  8b1d80b75100           -mov ebx, dword ptr [0x51b780]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5355392) /* 0x51b780 */);
    // 004712d1  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004712d3  7506                   -jne 0x4712db
    if (!cpu.flags.zf)
    {
        goto L_0x004712db;
    }
    // 004712d5  891d7cb75100           -mov dword ptr [0x51b77c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5355388) /* 0x51b77c */) = cpu.ebx;
L_0x004712db:
    // 004712db  e830040000             -call 0x471710
    cpu.esp -= 4;
    sub_471710(app, cpu);
    if (cpu.terminate) return;
    // 004712e0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004712e1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004712e2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004712e3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4712f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004712f0  c7057cb7510002000000   -mov dword ptr [0x51b77c], 2
    app->getMemory<x86::reg32>(x86::reg32(5355388) /* 0x51b77c */) = 2 /*0x2*/;
    // 004712fa  e991060000             -jmp 0x471990
    return sub_471990(app, cpu);
}

/* align: skip 0x00 */
void Application::sub_471300(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00471300  c7057cb7510007000000   -mov dword ptr [0x51b77c], 7
    app->getMemory<x86::reg32>(x86::reg32(5355388) /* 0x51b77c */) = 7 /*0x7*/;
    // 0047130a  e981060000             -jmp 0x471990
    return sub_471990(app, cpu);
}

/* align: skip 0x00 */
void Application::sub_471310(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00471310  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00471311  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00471312  c7057cb7510005000000   -mov dword ptr [0x51b77c], 5
    app->getMemory<x86::reg32>(x86::reg32(5355388) /* 0x51b77c */) = 5 /*0x5*/;
    // 0047131c  8b501c                 -mov edx, dword ptr [eax + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0047131f  8b0dd0ab5100           -mov ecx, dword ptr [0x51abd0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5352400) /* 0x51abd0 */);
    // 00471325  3b4a08                 +cmp ecx, dword ptr [edx + 8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00471328  7513                   -jne 0x47133d
    if (!cpu.flags.zf)
    {
        goto L_0x0047133d;
    }
    // 0047132a  833d80b7510000         +cmp dword ptr [0x51b780], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5355392) /* 0x51b780 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00471331  750a                   -jne 0x47133d
    if (!cpu.flags.zf)
    {
        goto L_0x0047133d;
    }
    // 00471333  c7057cb7510001000000   -mov dword ptr [0x51b77c], 1
    app->getMemory<x86::reg32>(x86::reg32(5355388) /* 0x51b77c */) = 1 /*0x1*/;
L_0x0047133d:
    // 0047133d  e84e060000             -call 0x471990
    cpu.esp -= 4;
    sub_471990(app, cpu);
    if (cpu.terminate) return;
    // 00471342  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471343  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471344  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_471350(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00471350  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00471351  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00471352  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00471353  c7057cb7510004000000   -mov dword ptr [0x51b77c], 4
    app->getMemory<x86::reg32>(x86::reg32(5355388) /* 0x51b77c */) = 4 /*0x4*/;
    // 0047135d  8b501c                 -mov edx, dword ptr [eax + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 00471360  8b0dd0ab5100           -mov ecx, dword ptr [0x51abd0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5352400) /* 0x51abd0 */);
    // 00471366  3b4a08                 +cmp ecx, dword ptr [edx + 8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00471369  7510                   -jne 0x47137b
    if (!cpu.flags.zf)
    {
        goto L_0x0047137b;
    }
    // 0047136b  8b1d80b75100           -mov ebx, dword ptr [0x51b780]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5355392) /* 0x51b780 */);
    // 00471371  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00471373  7506                   -jne 0x47137b
    if (!cpu.flags.zf)
    {
        goto L_0x0047137b;
    }
    // 00471375  891d7cb75100           -mov dword ptr [0x51b77c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5355388) /* 0x51b77c */) = cpu.ebx;
L_0x0047137b:
    // 0047137b  e810060000             -call 0x471990
    cpu.esp -= 4;
    sub_471990(app, cpu);
    if (cpu.terminate) return;
    // 00471380  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471381  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471382  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471383  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_471390(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00471390  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00471391  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00471392  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00471393  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00471394  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00471395  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00471396  83ec38                 -sub esp, 0x38
    (cpu.esp) -= x86::reg32(x86::sreg32(56 /*0x38*/));
    // 00471399  8b700c                 -mov esi, dword ptr [eax + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0047139c  668b560e               -mov dx, word ptr [esi + 0xe]
    cpu.dx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(14) /* 0xe */);
    // 004713a0  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004713a2  6685d2                 +test dx, dx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.dx & cpu.dx));
    // 004713a5  0f8500010000           -jne 0x4714ab
    if (!cpu.flags.zf)
    {
        goto L_0x004714ab;
    }
    // 004713ab  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004713ae  66837a0e00             +cmp word ptr [edx + 0xe], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(14) /* 0xe */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004713b3  0f85f2000000           -jne 0x4714ab
    if (!cpu.flags.zf)
    {
        goto L_0x004714ab;
    }
    // 004713b9  8b5014                 -mov edx, dword ptr [eax + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004713bc  66837a0e00             +cmp word ptr [edx + 0xe], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(14) /* 0xe */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004713c1  0f85e4000000           -jne 0x4714ab
    if (!cpu.flags.zf)
    {
        goto L_0x004714ab;
    }
    // 004713c7  8d7c2420               -lea edi, [esp + 0x20]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004713cb  8d7610                 -lea esi, [esi + 0x10]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004713ce  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004713cf  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004713d0  8b7010                 -mov esi, dword ptr [eax + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004713d3  8d7c2428               -lea edi, [esp + 0x28]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004713d7  8d7610                 -lea esi, [esi + 0x10]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004713da  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004713db  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004713dc  8b7014                 -mov esi, dword ptr [eax + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004713df  8d7c2430               -lea edi, [esp + 0x30]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004713e3  8d7610                 -lea esi, [esi + 0x10]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004713e6  8b154cf54d00           -mov edx, dword ptr [0x4df54c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5109068) /* 0x4df54c */);
    // 004713ec  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004713ed  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004713ee  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004713f0  0f84f0000000           -je 0x4714e6
    if (cpu.flags.zf)
    {
        goto L_0x004714e6;
    }
    // 004713f6  6683780a02             +cmp word ptr [eax + 0xa], 2
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(10) /* 0xa */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(2 /*0x2*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004713fb  0f85b4000000           -jne 0x4714b5
    if (!cpu.flags.zf)
    {
        goto L_0x004714b5;
    }
L_0x00471401:
    // 00471401  8b4d1c                 -mov ecx, dword ptr [ebp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 00471404  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00471406  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00471408  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0047140a  8a5904                 -mov bl, byte ptr [ecx + 4]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0047140d  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00471410  8b5202                 -mov edx, dword ptr [edx + 2]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 00471413  8934dc                 -mov dword ptr [esp + ebx*8], esi
    app->getMemory<x86::reg32>(cpu.esp + cpu.ebx * 8) = cpu.esi;
    // 00471416  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00471418  8a5904                 -mov bl, byte ptr [ecx + 4]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0047141b  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0047141e  8974dc04               -mov dword ptr [esp + ebx*8 + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */ + cpu.ebx * 8) = cpu.esi;
    // 00471422  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00471424  4a                     -dec edx
    (cpu.edx)--;
    // 00471425  8a5905                 -mov bl, byte ptr [ecx + 5]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5) /* 0x5 */);
    // 00471428  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0047142b  8914dc                 -mov dword ptr [esp + ebx*8], edx
    app->getMemory<x86::reg32>(cpu.esp + cpu.ebx * 8) = cpu.edx;
    // 0047142e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00471430  8a5905                 -mov bl, byte ptr [ecx + 5]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5) /* 0x5 */);
    // 00471433  8974dc04               -mov dword ptr [esp + ebx*8 + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */ + cpu.ebx * 8) = cpu.esi;
    // 00471437  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00471439  8a5906                 -mov bl, byte ptr [ecx + 6]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(6) /* 0x6 */);
    // 0047143c  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0047143f  8914dc                 -mov dword ptr [esp + ebx*8], edx
    app->getMemory<x86::reg32>(cpu.esp + cpu.ebx * 8) = cpu.edx;
    // 00471442  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00471444  48                     -dec eax
    (cpu.eax)--;
    // 00471445  8a5106                 -mov dl, byte ptr [ecx + 6]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(6) /* 0x6 */);
    // 00471448  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0047144b  8944d404               -mov dword ptr [esp + edx*8 + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */ + cpu.edx * 8) = cpu.eax;
    // 0047144f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00471451  8a5107                 -mov dl, byte ptr [ecx + 7]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(7) /* 0x7 */);
    // 00471454  8934d4                 -mov dword ptr [esp + edx*8], esi
    app->getMemory<x86::reg32>(cpu.esp + cpu.edx * 8) = cpu.esi;
    // 00471457  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00471459  8a5107                 -mov dl, byte ptr [ecx + 7]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(7) /* 0x7 */);
    // 0047145c  8944d404               -mov dword ptr [esp + edx*8 + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */ + cpu.edx * 8) = cpu.eax;
    // 00471460  a1349e4c00             -mov eax, dword ptr [0x4c9e34]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021236) /* 0x4c9e34 */);
    // 00471465  3b4108                 +cmp eax, dword ptr [ecx + 8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00471468  0f84b4000000           -je 0x471522
    if (cpu.flags.zf)
    {
        goto L_0x00471522;
    }
L_0x0047146e:
    // 0047146e  8b1580b75100           -mov edx, dword ptr [0x51b780]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5355392) /* 0x51b780 */);
    // 00471474  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00471477  e8b4baffff             -call 0x46cf30
    cpu.esp -= 4;
    sub_46cf30(app, cpu);
    if (cpu.terminate) return;
    // 0047147c  a180b75100             -mov eax, dword ptr [0x51b780]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355392) /* 0x51b780 */);
    // 00471481  a3389e4c00             -mov dword ptr [0x4c9e38], eax
    app->getMemory<x86::reg32>(x86::reg32(5021240) /* 0x4c9e38 */) = cpu.eax;
    // 00471486  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00471489  a3349e4c00             -mov dword ptr [0x4c9e34], eax
    app->getMemory<x86::reg32>(x86::reg32(5021236) /* 0x4c9e34 */) = cpu.eax;
L_0x0047148e:
    // 0047148e  8b2d7cb75100           -mov ebp, dword ptr [0x51b77c]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5355388) /* 0x51b77c */);
    // 00471494  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00471495  8d5c2404               -lea ebx, [esp + 4]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00471499  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 0047149e  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 004714a0  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 004714a2  8d4c2428               -lea ecx, [esp + 0x28]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004714a6  e871140200             -call 0x49291c
    cpu.esp -= 4;
    sub_49291c(app, cpu);
    if (cpu.terminate) return;
L_0x004714ab:
    // 004714ab  83c438                 -add esp, 0x38
    (cpu.esp) += x86::reg32(x86::sreg32(56 /*0x38*/));
    // 004714ae  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004714af  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004714b0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004714b1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004714b2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004714b3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004714b4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004714b5:
    // 004714b5  8d5c2430               -lea ebx, [esp + 0x30]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004714b9  8d742428               -lea esi, [esp + 0x28]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004714bd  8d542420               -lea edx, [esp + 0x20]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004714c1  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004714c3  8b5b04                 -mov ebx, dword ptr [ebx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004714c6  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004714c8  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004714cb  2b06                   -sub eax, dword ptr [esi]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi)));
    // 004714cd  2b5e04                 -sub ebx, dword ptr [esi + 4]
    (cpu.ebx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 004714d0  2b0e                   -sub ecx, dword ptr [esi]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi)));
    // 004714d2  2b5604                 -sub edx, dword ptr [esi + 4]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 004714d5  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004714d8  0fafd9                 -imul ebx, ecx
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004714db  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004714dd  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004714df  7cca                   -jl 0x4714ab
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004714ab;
    }
    // 004714e1  e91bffffff             -jmp 0x471401
    goto L_0x00471401;
L_0x004714e6:
    // 004714e6  6683780a02             +cmp word ptr [eax + 0xa], 2
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(10) /* 0xa */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(2 /*0x2*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004714eb  0f8410ffffff           -je 0x471401
    if (cpu.flags.zf)
    {
        goto L_0x00471401;
    }
    // 004714f1  8d5c2430               -lea ebx, [esp + 0x30]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004714f5  8d742428               -lea esi, [esp + 0x28]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004714f9  8d542420               -lea edx, [esp + 0x20]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004714fd  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004714ff  8b5b04                 -mov ebx, dword ptr [ebx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00471502  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00471504  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00471507  2b06                   -sub eax, dword ptr [esi]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi)));
    // 00471509  2b5e04                 -sub ebx, dword ptr [esi + 4]
    (cpu.ebx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 0047150c  2b0e                   -sub ecx, dword ptr [esi]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi)));
    // 0047150e  2b5604                 -sub edx, dword ptr [esi + 4]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 00471511  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00471514  0fafd9                 -imul ebx, ecx
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 00471517  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00471519  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047151b  7f8e                   -jg 0x4714ab
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004714ab;
    }
    // 0047151d  e9dffeffff             -jmp 0x471401
    goto L_0x00471401;
L_0x00471522:
    // 00471522  8b3d80b75100           -mov edi, dword ptr [0x51b780]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5355392) /* 0x51b780 */);
    // 00471528  3b3d389e4c00           +cmp edi, dword ptr [0x4c9e38]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5021240) /* 0x4c9e38 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047152e  0f853affffff           -jne 0x47146e
    if (!cpu.flags.zf)
    {
        goto L_0x0047146e;
    }
    // 00471534  e955ffffff             -jmp 0x47148e
    goto L_0x0047148e;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_471540(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00471540  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00471541  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00471542  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00471543  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00471544  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00471545  83ec50                 -sub esp, 0x50
    (cpu.esp) -= x86::reg32(x86::sreg32(80 /*0x50*/));
    // 00471548  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0047154b  81fa00f0ffff           +cmp edx, 0xfffff000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294963200 /*0xfffff000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00471551  0f8c7e010000           -jl 0x4716d5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004716d5;
    }
    // 00471557  81fa00100000           +cmp edx, 0x1000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4096 /*0x1000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047155d  0f8f72010000           -jg 0x4716d5
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004716d5;
    }
    // 00471563  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00471566  81fb00f0ffff           +cmp ebx, 0xfffff000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294963200 /*0xfffff000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047156c  0f8c63010000           -jl 0x4716d5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004716d5;
    }
    // 00471572  81fb00100000           +cmp ebx, 0x1000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4096 /*0x1000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00471578  0f8f57010000           -jg 0x4716d5
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004716d5;
    }
    // 0047157e  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00471580  8d7008                 -lea esi, [eax + 8]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00471583  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00471584  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00471585  8b7810                 -mov edi, dword ptr [eax + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00471588  81ff00f0ffff           +cmp edi, 0xfffff000
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294963200 /*0xfffff000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047158e  0f8c41010000           -jl 0x4716d5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004716d5;
    }
    // 00471594  81ff00100000           +cmp edi, 0x1000
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4096 /*0x1000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047159a  0f8f35010000           -jg 0x4716d5
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004716d5;
    }
    // 004715a0  8b5014                 -mov edx, dword ptr [eax + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004715a3  81fa00f0ffff           +cmp edx, 0xfffff000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294963200 /*0xfffff000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004715a9  0f8c26010000           -jl 0x4716d5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004716d5;
    }
    // 004715af  81fa00100000           +cmp edx, 0x1000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4096 /*0x1000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004715b5  0f8f1a010000           -jg 0x4716d5
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004716d5;
    }
    // 004715bb  8d7c2408               -lea edi, [esp + 8]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004715bf  8d7010                 -lea esi, [eax + 0x10]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004715c2  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004715c3  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004715c4  8b5818                 -mov ebx, dword ptr [eax + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004715c7  81fb00f0ffff           +cmp ebx, 0xfffff000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294963200 /*0xfffff000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004715cd  0f8c02010000           -jl 0x4716d5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004716d5;
    }
    // 004715d3  81fb00100000           +cmp ebx, 0x1000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4096 /*0x1000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004715d9  0f8ff6000000           -jg 0x4716d5
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004716d5;
    }
    // 004715df  8b781c                 -mov edi, dword ptr [eax + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004715e2  81ff00f0ffff           +cmp edi, 0xfffff000
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294963200 /*0xfffff000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004715e8  0f8ce7000000           -jl 0x4716d5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004716d5;
    }
    // 004715ee  81ff00100000           +cmp edi, 0x1000
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4096 /*0x1000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004715f4  0f8fdb000000           -jg 0x4716d5
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004716d5;
    }
    // 004715fa  8d7c2410               -lea edi, [esp + 0x10]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004715fe  8d7018                 -lea esi, [eax + 0x18]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00471601  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00471602  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00471603  8b5020                 -mov edx, dword ptr [eax + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 00471606  81fa00f0ffff           +cmp edx, 0xfffff000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294963200 /*0xfffff000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047160c  0f8cc3000000           -jl 0x4716d5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004716d5;
    }
    // 00471612  81fa00100000           +cmp edx, 0x1000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4096 /*0x1000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00471618  0f8fb7000000           -jg 0x4716d5
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004716d5;
    }
    // 0047161e  8b5824                 -mov ebx, dword ptr [eax + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 00471621  81fb00f0ffff           +cmp ebx, 0xfffff000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294963200 /*0xfffff000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00471627  0f8ca8000000           -jl 0x4716d5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004716d5;
    }
    // 0047162d  81fb00100000           +cmp ebx, 0x1000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4096 /*0x1000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00471633  0f8f9c000000           -jg 0x4716d5
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004716d5;
    }
    // 00471639  8d7c2418               -lea edi, [esp + 0x18]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0047163d  8d7020                 -lea esi, [eax + 0x20]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 00471640  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00471641  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00471642  8d7c2420               -lea edi, [esp + 0x20]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00471646  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00471648  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00471649  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0047164a  8b4028                 -mov eax, dword ptr [eax + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 0047164d  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0047164f  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00471651  0fb67004               -movzx esi, byte ptr [eax + 4]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */));
    // 00471655  8b5104                 -mov edx, dword ptr [ecx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00471658  8b5902                 -mov ebx, dword ptr [ecx + 2]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 0047165b  897cf428               -mov dword ptr [esp + esi*8 + 0x28], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */ + cpu.esi * 8) = cpu.edi;
    // 0047165f  0fb67004               -movzx esi, byte ptr [eax + 4]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */));
    // 00471663  897cf42c               -mov dword ptr [esp + esi*8 + 0x2c], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */ + cpu.esi * 8) = cpu.edi;
    // 00471667  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 0047166a  0fb67005               -movzx esi, byte ptr [eax + 5]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */));
    // 0047166e  4b                     -dec ebx
    (cpu.ebx)--;
    // 0047166f  895cf428               -mov dword ptr [esp + esi*8 + 0x28], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */ + cpu.esi * 8) = cpu.ebx;
    // 00471673  0fb67005               -movzx esi, byte ptr [eax + 5]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */));
    // 00471677  897cf42c               -mov dword ptr [esp + esi*8 + 0x2c], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */ + cpu.esi * 8) = cpu.edi;
    // 0047167b  0fb67006               -movzx esi, byte ptr [eax + 6]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(6) /* 0x6 */));
    // 0047167f  895cf428               -mov dword ptr [esp + esi*8 + 0x28], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */ + cpu.esi * 8) = cpu.ebx;
    // 00471683  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00471685  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00471688  8a5806                 -mov bl, byte ptr [eax + 6]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 0047168b  4a                     -dec edx
    (cpu.edx)--;
    // 0047168c  8954dc2c               -mov dword ptr [esp + ebx*8 + 0x2c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */ + cpu.ebx * 8) = cpu.edx;
    // 00471690  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00471692  8a5807                 -mov bl, byte ptr [eax + 7]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(7) /* 0x7 */);
    // 00471695  897cdc28               -mov dword ptr [esp + ebx*8 + 0x28], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */ + cpu.ebx * 8) = cpu.edi;
    // 00471699  8a4007                 -mov al, byte ptr [eax + 7]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(7) /* 0x7 */);
    // 0047169c  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004716a1  8d7c2448               -lea edi, [esp + 0x48]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 004716a5  8d742428               -lea esi, [esp + 0x28]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004716a9  8954c42c               -mov dword ptr [esp + eax*8 + 0x2c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */ + cpu.eax * 8) = cpu.edx;
    // 004716ad  a17cb75100             -mov eax, dword ptr [0x51b77c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355388) /* 0x51b77c */);
    // 004716b2  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004716b3  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004716b4  83f807                 +cmp eax, 7
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
    // 004716b7  7525                   -jne 0x4716de
    if (!cpu.flags.zf)
    {
        goto L_0x004716de;
    }
    // 004716b9  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004716bb  8d542428               -lea edx, [esp + 0x28]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004716bf  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004716c1  e8ee210200             -call 0x4938b4
    cpu.esp -= 4;
    sub_4938b4(app, cpu);
    if (cpu.terminate) return;
    // 004716c6  8d5c2410               -lea ebx, [esp + 0x10]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004716ca  8d542438               -lea edx, [esp + 0x38]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 004716ce  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004716d0  e8df210200             -call 0x4938b4
    cpu.esp -= 4;
    sub_4938b4(app, cpu);
    if (cpu.terminate) return;
L_0x004716d5:
    // 004716d5  83c450                 -add esp, 0x50
    (cpu.esp) += x86::reg32(x86::sreg32(80 /*0x50*/));
    // 004716d8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004716d9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004716da  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004716db  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004716dc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004716dd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004716de:
    // 004716de  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004716e0  8d542428               -lea edx, [esp + 0x28]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004716e4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004716e6  e8a92c0200             -call 0x494394
    cpu.esp -= 4;
    sub_494394(app, cpu);
    if (cpu.terminate) return;
    // 004716eb  8d5c2410               -lea ebx, [esp + 0x10]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004716ef  8d542438               -lea edx, [esp + 0x38]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 004716f3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004716f5  e89a2c0200             -call 0x494394
    cpu.esp -= 4;
    sub_494394(app, cpu);
    if (cpu.terminate) return;
    // 004716fa  83c450                 -add esp, 0x50
    (cpu.esp) += x86::reg32(x86::sreg32(80 /*0x50*/));
    // 004716fd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004716fe  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004716ff  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471700  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471701  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471702  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_471710(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00471710  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00471711  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00471712  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00471713  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00471714  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00471715  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00471716  83ec50                 -sub esp, 0x50
    (cpu.esp) -= x86::reg32(x86::sreg32(80 /*0x50*/));
    // 00471719  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0047171b  8b700c                 -mov esi, dword ptr [eax + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0047171e  8d7c2428               -lea edi, [esp + 0x28]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00471722  8d7610                 -lea esi, [esi + 0x10]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00471725  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00471726  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00471727  8b542428               -mov edx, dword ptr [esp + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0047172b  81fa00f0ffff           +cmp edx, 0xfffff000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294963200 /*0xfffff000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00471731  0f8cbb010000           -jl 0x4718f2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004718f2;
    }
    // 00471737  81fa00100000           +cmp edx, 0x1000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4096 /*0x1000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047173d  0f8faf010000           -jg 0x4718f2
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004718f2;
    }
    // 00471743  8b5c242c               -mov ebx, dword ptr [esp + 0x2c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00471747  81fb00f0ffff           +cmp ebx, 0xfffff000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294963200 /*0xfffff000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047174d  0f8c9f010000           -jl 0x4718f2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004718f2;
    }
    // 00471753  81fb00100000           +cmp ebx, 0x1000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4096 /*0x1000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00471759  0f8f93010000           -jg 0x4718f2
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004718f2;
    }
    // 0047175f  8b7010                 -mov esi, dword ptr [eax + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00471762  8d7c2430               -lea edi, [esp + 0x30]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00471766  8d7610                 -lea esi, [esi + 0x10]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00471769  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0047176a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0047176b  8b7c2430               -mov edi, dword ptr [esp + 0x30]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0047176f  81ff00f0ffff           +cmp edi, 0xfffff000
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294963200 /*0xfffff000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00471775  0f8c77010000           -jl 0x4718f2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004718f2;
    }
    // 0047177b  81ff00100000           +cmp edi, 0x1000
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4096 /*0x1000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00471781  0f8f6b010000           -jg 0x4718f2
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004718f2;
    }
    // 00471787  8b542434               -mov edx, dword ptr [esp + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0047178b  81fa00f0ffff           +cmp edx, 0xfffff000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294963200 /*0xfffff000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00471791  0f8c5b010000           -jl 0x4718f2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004718f2;
    }
    // 00471797  81fa00100000           +cmp edx, 0x1000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4096 /*0x1000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047179d  0f8f4f010000           -jg 0x4718f2
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004718f2;
    }
    // 004717a3  8b7014                 -mov esi, dword ptr [eax + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004717a6  8d7c2438               -lea edi, [esp + 0x38]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 004717aa  8d7610                 -lea esi, [esi + 0x10]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004717ad  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004717ae  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004717af  8b5c2438               -mov ebx, dword ptr [esp + 0x38]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 004717b3  81fb00f0ffff           +cmp ebx, 0xfffff000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294963200 /*0xfffff000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004717b9  0f8c33010000           -jl 0x4718f2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004718f2;
    }
    // 004717bf  81fb00100000           +cmp ebx, 0x1000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4096 /*0x1000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004717c5  0f8f27010000           -jg 0x4718f2
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004718f2;
    }
    // 004717cb  8b7c243c               -mov edi, dword ptr [esp + 0x3c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 004717cf  81ff00f0ffff           +cmp edi, 0xfffff000
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294963200 /*0xfffff000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004717d5  0f8c17010000           -jl 0x4718f2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004718f2;
    }
    // 004717db  81ff00100000           +cmp edi, 0x1000
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4096 /*0x1000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004717e1  0f8f0b010000           -jg 0x4718f2
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004718f2;
    }
    // 004717e7  8b7018                 -mov esi, dword ptr [eax + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004717ea  8d7c2440               -lea edi, [esp + 0x40]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 004717ee  8d7610                 -lea esi, [esi + 0x10]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004717f1  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004717f2  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004717f3  8b542440               -mov edx, dword ptr [esp + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 004717f7  81fa00f0ffff           +cmp edx, 0xfffff000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294963200 /*0xfffff000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004717fd  0f8cef000000           -jl 0x4718f2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004718f2;
    }
    // 00471803  81fa00100000           +cmp edx, 0x1000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4096 /*0x1000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00471809  0f8fe3000000           -jg 0x4718f2
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004718f2;
    }
    // 0047180f  8b5c2444               -mov ebx, dword ptr [esp + 0x44]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 00471813  81fb00f0ffff           +cmp ebx, 0xfffff000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294963200 /*0xfffff000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00471819  0f8cd3000000           -jl 0x4718f2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004718f2;
    }
    // 0047181f  81fb00100000           +cmp ebx, 0x1000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4096 /*0x1000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00471825  0f8fc7000000           -jg 0x4718f2
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004718f2;
    }
    // 0047182b  6683780a02             +cmp word ptr [eax + 0xa], 2
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(10) /* 0xa */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(2 /*0x2*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00471830  0f84c6000000           -je 0x4718fc
    if (cpu.flags.zf)
    {
        goto L_0x004718fc;
    }
    // 00471836  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
L_0x0047183b:
    // 0047183b  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 0047183d  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047183f  0f85be000000           -jne 0x471903
    if (!cpu.flags.zf)
    {
        goto L_0x00471903;
    }
L_0x00471845:
    // 00471845  8b6d1c                 -mov ebp, dword ptr [ebp + 0x1c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 00471848  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047184a  8b7500                 -mov esi, dword ptr [ebp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp);
    // 0047184d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047184f  8a5504                 -mov dl, byte ptr [ebp + 4]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 00471852  8b4e04                 -mov ecx, dword ptr [esi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00471855  8b4602                 -mov eax, dword ptr [esi + 2]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 00471858  891cd4                 -mov dword ptr [esp + edx*8], ebx
    app->getMemory<x86::reg32>(cpu.esp + cpu.edx * 8) = cpu.ebx;
    // 0047185b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047185d  8a5504                 -mov dl, byte ptr [ebp + 4]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 00471860  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00471863  895cd404               -mov dword ptr [esp + edx*8 + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */ + cpu.edx * 8) = cpu.ebx;
    // 00471867  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00471869  48                     -dec eax
    (cpu.eax)--;
    // 0047186a  8a5505                 -mov dl, byte ptr [ebp + 5]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(5) /* 0x5 */);
    // 0047186d  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 00471870  8904d4                 -mov dword ptr [esp + edx*8], eax
    app->getMemory<x86::reg32>(cpu.esp + cpu.edx * 8) = cpu.eax;
    // 00471873  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00471875  8a5505                 -mov dl, byte ptr [ebp + 5]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(5) /* 0x5 */);
    // 00471878  895cd404               -mov dword ptr [esp + edx*8 + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */ + cpu.edx * 8) = cpu.ebx;
    // 0047187c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047187e  8a5506                 -mov dl, byte ptr [ebp + 6]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(6) /* 0x6 */);
    // 00471881  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 00471884  8904d4                 -mov dword ptr [esp + edx*8], eax
    app->getMemory<x86::reg32>(cpu.esp + cpu.edx * 8) = cpu.eax;
    // 00471887  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00471889  49                     -dec ecx
    (cpu.ecx)--;
    // 0047188a  8a4506                 -mov al, byte ptr [ebp + 6]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(6) /* 0x6 */);
    // 0047188d  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 00471890  894cc404               -mov dword ptr [esp + eax*8 + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */ + cpu.eax * 8) = cpu.ecx;
    // 00471894  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00471896  8a4507                 -mov al, byte ptr [ebp + 7]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(7) /* 0x7 */);
    // 00471899  891cc4                 -mov dword ptr [esp + eax*8], ebx
    app->getMemory<x86::reg32>(cpu.esp + cpu.eax * 8) = cpu.ebx;
    // 0047189c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047189e  8a4507                 -mov al, byte ptr [ebp + 7]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(7) /* 0x7 */);
    // 004718a1  894cc404               -mov dword ptr [esp + eax*8 + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */ + cpu.eax * 8) = cpu.ecx;
    // 004718a5  a1349e4c00             -mov eax, dword ptr [0x4c9e34]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5021236) /* 0x4c9e34 */);
    // 004718aa  3b4508                 +cmp eax, dword ptr [ebp + 8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004718ad  7472                   -je 0x471921
    if (cpu.flags.zf)
    {
        goto L_0x00471921;
    }
L_0x004718af:
    // 004718af  8b1580b75100           -mov edx, dword ptr [0x51b780]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5355392) /* 0x51b780 */);
    // 004718b5  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004718b8  e873b6ffff             -call 0x46cf30
    cpu.esp -= 4;
    sub_46cf30(app, cpu);
    if (cpu.terminate) return;
    // 004718bd  a180b75100             -mov eax, dword ptr [0x51b780]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355392) /* 0x51b780 */);
    // 004718c2  a3389e4c00             -mov dword ptr [0x4c9e38], eax
    app->getMemory<x86::reg32>(x86::reg32(5021240) /* 0x4c9e38 */) = cpu.eax;
    // 004718c7  8b4508                 -mov eax, dword ptr [ebp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004718ca  a3349e4c00             -mov dword ptr [0x4c9e34], eax
    app->getMemory<x86::reg32>(x86::reg32(5021236) /* 0x4c9e34 */) = cpu.eax;
L_0x004718cf:
    // 004718cf  a17cb75100             -mov eax, dword ptr [0x51b77c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355388) /* 0x51b77c */);
    // 004718d4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004718d5  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004718d7  8d4c242c               -lea ecx, [esp + 0x2c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004718db  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 004718dd  8d5c2404               -lea ebx, [esp + 4]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004718e1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004718e2  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 004718e7  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004718e9  e82e100200             -call 0x49291c
    cpu.esp -= 4;
    sub_49291c(app, cpu);
    if (cpu.terminate) return;
    // 004718ee  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004718f0  7c3f                   -jl 0x471931
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00471931;
    }
L_0x004718f2:
    // 004718f2  83c450                 -add esp, 0x50
    (cpu.esp) += x86::reg32(x86::sreg32(80 /*0x50*/));
    // 004718f5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004718f6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004718f7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004718f8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004718f9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004718fa  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004718fb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004718fc:
    // 004718fc  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 004718fe  e938ffffff             -jmp 0x47183b
    goto L_0x0047183b;
L_0x00471903:
    // 00471903  8d4c2440               -lea ecx, [esp + 0x40]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00471907  8d5c2438               -lea ebx, [esp + 0x38]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0047190b  8d542430               -lea edx, [esp + 0x30]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0047190f  8d442428               -lea eax, [esp + 0x28]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00471913  e8c8020000             -call 0x471be0
    cpu.esp -= 4;
    sub_471be0(app, cpu);
    if (cpu.terminate) return;
    // 00471918  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047191a  75d6                   -jne 0x4718f2
    if (!cpu.flags.zf)
    {
        goto L_0x004718f2;
    }
    // 0047191c  e924ffffff             -jmp 0x471845
    goto L_0x00471845;
L_0x00471921:
    // 00471921  8b1d80b75100           -mov ebx, dword ptr [0x51b780]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5355392) /* 0x51b780 */);
    // 00471927  3b1d389e4c00           +cmp ebx, dword ptr [0x4c9e38]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5021240) /* 0x4c9e38 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047192d  7580                   -jne 0x4718af
    if (!cpu.flags.zf)
    {
        goto L_0x004718af;
    }
    // 0047192f  eb9e                   -jmp 0x4718cf
    goto L_0x004718cf;
L_0x00471931:
    // 00471931  8d7c2448               -lea edi, [esp + 0x48]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 00471935  8d742428               -lea esi, [esp + 0x28]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00471939  8d4c2428               -lea ecx, [esp + 0x28]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0047193d  8b157cb75100           -mov edx, dword ptr [0x51b77c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5355388) /* 0x51b77c */);
    // 00471943  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00471944  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00471945  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00471946  8d7c2424               -lea edi, [esp + 0x24]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0047194a  8d742404               -lea esi, [esp + 4]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047194e  8d5c2404               -lea ebx, [esp + 4]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00471952  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00471954  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00471955  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00471956  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 0047195b  8b4500                 -mov eax, dword ptr [ebp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp);
    // 0047195e  e8b90f0200             -call 0x49291c
    cpu.esp -= 4;
    sub_49291c(app, cpu);
    if (cpu.terminate) return;
    // 00471963  8b0d7cb75100           -mov ecx, dword ptr [0x51b77c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5355388) /* 0x51b77c */);
    // 00471969  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047196a  8d5c2414               -lea ebx, [esp + 0x14]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0047196e  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 00471973  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00471975  8b4500                 -mov eax, dword ptr [ebp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp);
    // 00471978  8d4c2440               -lea ecx, [esp + 0x40]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0047197c  e89b0f0200             -call 0x49291c
    cpu.esp -= 4;
    sub_49291c(app, cpu);
    if (cpu.terminate) return;
    // 00471981  83c450                 -add esp, 0x50
    (cpu.esp) += x86::reg32(x86::sreg32(80 /*0x50*/));
    // 00471984  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471985  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471986  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471987  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471988  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471989  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047198a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_471990(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00471990  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00471991  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00471992  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00471993  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00471994  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00471996  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00471998  89155cb75100           -mov dword ptr [0x51b75c], edx
    app->getMemory<x86::reg32>(x86::reg32(5355356) /* 0x51b75c */) = cpu.edx;
    // 0047199e  6683780a02             +cmp word ptr [eax + 0xa], 2
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(10) /* 0xa */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(2 /*0x2*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004719a3  0f85bb000000           -jne 0x471a64
    if (!cpu.flags.zf)
    {
        goto L_0x00471a64;
    }
    // 004719a9  c7055cb7510001000000   -mov dword ptr [0x51b75c], 1
    app->getMemory<x86::reg32>(x86::reg32(5355356) /* 0x51b75c */) = 1 /*0x1*/;
L_0x004719b3:
    // 004719b3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004719b4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004719b5  8b5d0c                 -mov ebx, dword ptr [ebp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004719b8  bfc4ac5100             -mov edi, 0x51acc4
    cpu.edi = 5352644 /*0x51acc4*/;
    // 004719bd  8d7310                 -lea esi, [ebx + 0x10]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004719c0  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004719c1  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004719c2  8b5510                 -mov edx, dword ptr [ebp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004719c5  bfc4ad5100             -mov edi, 0x51adc4
    cpu.edi = 5352900 /*0x51adc4*/;
    // 004719ca  8d7210                 -lea esi, [edx + 0x10]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004719cd  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004719ce  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004719cf  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004719d2  bfc4b65100             -mov edi, 0x51b6c4
    cpu.edi = 5355204 /*0x51b6c4*/;
    // 004719d7  8d7010                 -lea esi, [eax + 0x10]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004719da  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004719db  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004719dc  8b4d18                 -mov ecx, dword ptr [ebp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 004719df  bfc4b55100             -mov edi, 0x51b5c4
    cpu.edi = 5354948 /*0x51b5c4*/;
    // 004719e4  8d7110                 -lea esi, [ecx + 0x10]
    cpu.esi = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004719e7  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004719e8  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004719e9  bfb4ac5100             -mov edi, 0x51acb4
    cpu.edi = 5352628 /*0x51acb4*/;
    // 004719ee  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004719f0  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004719f1  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004719f2  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004719f3  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004719f4  bfb4ad5100             -mov edi, 0x51adb4
    cpu.edi = 5352884 /*0x51adb4*/;
    // 004719f9  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004719fb  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004719fc  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004719fd  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004719fe  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004719ff  bfb4b65100             -mov edi, 0x51b6b4
    cpu.edi = 5355188 /*0x51b6b4*/;
    // 00471a04  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00471a06  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00471a07  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00471a08  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00471a09  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00471a0a  bfb4b55100             -mov edi, 0x51b5b4
    cpu.edi = 5354932 /*0x51b5b4*/;
    // 00471a0f  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00471a11  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00471a12  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00471a13  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00471a14  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00471a15  8b451c                 -mov eax, dword ptr [ebp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 00471a18  8b15349e4c00           -mov edx, dword ptr [0x4c9e34]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5021236) /* 0x4c9e34 */);
    // 00471a1e  3b5008                 +cmp edx, dword ptr [eax + 8]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00471a21  745b                   -je 0x471a7e
    if (cpu.flags.zf)
    {
        goto L_0x00471a7e;
    }
L_0x00471a23:
    // 00471a23  8b451c                 -mov eax, dword ptr [ebp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 00471a26  8b1580b75100           -mov edx, dword ptr [0x51b780]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5355392) /* 0x51b780 */);
    // 00471a2c  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00471a2f  e8fcb4ffff             -call 0x46cf30
    cpu.esp -= 4;
    sub_46cf30(app, cpu);
    if (cpu.terminate) return;
    // 00471a34  a180b75100             -mov eax, dword ptr [0x51b780]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355392) /* 0x51b780 */);
    // 00471a39  a3389e4c00             -mov dword ptr [0x4c9e38], eax
    app->getMemory<x86::reg32>(x86::reg32(5021240) /* 0x4c9e38 */) = cpu.eax;
    // 00471a3e  8b451c                 -mov eax, dword ptr [ebp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 00471a41  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00471a44  a3349e4c00             -mov dword ptr [0x4c9e34], eax
    app->getMemory<x86::reg32>(x86::reg32(5021236) /* 0x4c9e34 */) = cpu.eax;
L_0x00471a49:
    // 00471a49  b8b4ac5100             -mov eax, 0x51acb4
    cpu.eax = 5352628 /*0x51acb4*/;
    // 00471a4e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00471a50  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00471a52  892d58b75100           -mov dword ptr [0x51b758], ebp
    app->getMemory<x86::reg32>(x86::reg32(5355352) /* 0x51b758 */) = cpu.ebp;
    // 00471a58  e853020000             -call 0x471cb0
    cpu.esp -= 4;
    sub_471cb0(app, cpu);
    if (cpu.terminate) return;
    // 00471a5d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471a5e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00471a5f:
    // 00471a5f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471a60  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471a61  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471a62  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471a63  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00471a64:
    // 00471a64  8b4818                 -mov ecx, dword ptr [eax + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00471a67  8b5814                 -mov ebx, dword ptr [eax + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 00471a6a  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00471a6d  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00471a70  e81b000000             -call 0x471a90
    cpu.esp -= 4;
    sub_471a90(app, cpu);
    if (cpu.terminate) return;
    // 00471a75  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00471a77  75e6                   -jne 0x471a5f
    if (!cpu.flags.zf)
    {
        goto L_0x00471a5f;
    }
    // 00471a79  e935ffffff             -jmp 0x4719b3
    goto L_0x004719b3;
L_0x00471a7e:
    // 00471a7e  8b3580b75100           -mov esi, dword ptr [0x51b780]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5355392) /* 0x51b780 */);
    // 00471a84  3b35389e4c00           +cmp esi, dword ptr [0x4c9e38]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5021240) /* 0x4c9e38 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00471a8a  7597                   -jne 0x471a23
    if (!cpu.flags.zf)
    {
        goto L_0x00471a23;
    }
    // 00471a8c  ebbb                   -jmp 0x471a49
    goto L_0x00471a49;
}

/* align: skip 0x00 0x00 */
void Application::sub_471a90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00471a90  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00471a91  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00471a92  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00471a93  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00471a96  8b355cb75100           -mov esi, dword ptr [0x51b75c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5355356) /* 0x51b75c */);
    // 00471a9c  83fe01                 +cmp esi, 1
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
    // 00471a9f  0f847b000000           -je 0x471b20
    if (cpu.flags.zf)
    {
        goto L_0x00471b20;
    }
    // 00471aa5  83fe02                 +cmp esi, 2
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
    // 00471aa8  0f8476000000           -je 0x471b24
    if (cpu.flags.zf)
    {
        goto L_0x00471b24;
    }
    // 00471aae  6683780e00             +cmp word ptr [eax + 0xe], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(14) /* 0xe */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00471ab3  756b                   -jne 0x471b20
    if (!cpu.flags.zf)
    {
        goto L_0x00471b20;
    }
    // 00471ab5  66837a0e00             +cmp word ptr [edx + 0xe], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(14) /* 0xe */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00471aba  7564                   -jne 0x471b20
    if (!cpu.flags.zf)
    {
        goto L_0x00471b20;
    }
    // 00471abc  66837b0e00             +cmp word ptr [ebx + 0xe], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(14) /* 0xe */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00471ac1  755d                   -jne 0x471b20
    if (!cpu.flags.zf)
    {
        goto L_0x00471b20;
    }
    // 00471ac3  6683790e00             +cmp word ptr [ecx + 0xe], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(14) /* 0xe */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00471ac8  7556                   -jne 0x471b20
    if (!cpu.flags.zf)
    {
        goto L_0x00471b20;
    }
    // 00471aca  8d7810                 -lea edi, [eax + 0x10]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 00471acd  83c110                 -add ecx, 0x10
    (cpu.ecx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00471ad0  8d7210                 -lea esi, [edx + 0x10]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00471ad3  8d6b10                 -lea ebp, [ebx + 0x10]
    cpu.ebp = x86::reg32(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 00471ad6  a14cf54d00             -mov eax, dword ptr [0x4df54c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5109068) /* 0x4df54c */);
    // 00471adb  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 00471ade  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00471ae0  0f8484000000           -je 0x471b6a
    if (cpu.flags.zf)
    {
        goto L_0x00471b6a;
    }
    // 00471ae6  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 00471ae8  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00471aea  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 00471aec  8b5b04                 -mov ebx, dword ptr [ebx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00471aef  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00471af1  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00471af4  2b06                   -sub eax, dword ptr [esi]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi)));
    // 00471af6  2b5e04                 -sub ebx, dword ptr [esi + 4]
    (cpu.ebx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 00471af9  2b0e                   -sub ecx, dword ptr [esi]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi)));
    // 00471afb  2b5604                 -sub edx, dword ptr [esi + 4]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 00471afe  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00471b01  0fafd9                 -imul ebx, ecx
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 00471b04  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00471b06  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00471b08  7c21                   -jl 0x471b2b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00471b2b;
    }
L_0x00471b0a:
    // 00471b0a  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00471b0f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00471b11  890d5cb75100           -mov dword ptr [0x51b75c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5355356) /* 0x51b75c */) = cpu.ecx;
L_0x00471b17:
    // 00471b17  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00471b19  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00471b1c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471b1d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471b1e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471b1f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00471b20:
    // 00471b20  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00471b22  ebf3                   -jmp 0x471b17
    goto L_0x00471b17;
L_0x00471b24:
    // 00471b24  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00471b29  ebec                   -jmp 0x471b17
    goto L_0x00471b17;
L_0x00471b2b:
    // 00471b2b  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 00471b2e  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00471b30  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00471b32  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 00471b34  8b5b04                 -mov ebx, dword ptr [ebx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00471b37  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00471b39  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00471b3c  2b06                   -sub eax, dword ptr [esi]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi)));
    // 00471b3e  2b5e04                 -sub ebx, dword ptr [esi + 4]
    (cpu.ebx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 00471b41  2b0e                   -sub ecx, dword ptr [esi]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi)));
    // 00471b43  2b5604                 -sub edx, dword ptr [esi + 4]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 00471b46  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00471b49  0fafd9                 -imul ebx, ecx
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 00471b4c  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00471b4e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00471b50  7db8                   -jge 0x471b0a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00471b0a;
    }
    // 00471b52  c7055cb7510002000000   -mov dword ptr [0x51b75c], 2
    app->getMemory<x86::reg32>(x86::reg32(5355356) /* 0x51b75c */) = 2 /*0x2*/;
    // 00471b5c  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00471b61  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00471b63  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00471b66  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471b67  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471b68  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471b69  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00471b6a:
    // 00471b6a  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 00471b6c  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00471b6e  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 00471b70  8b5b04                 -mov ebx, dword ptr [ebx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00471b73  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00471b75  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00471b78  2b06                   -sub eax, dword ptr [esi]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi)));
    // 00471b7a  2b5e04                 -sub ebx, dword ptr [esi + 4]
    (cpu.ebx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 00471b7d  2b0e                   -sub ecx, dword ptr [esi]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi)));
    // 00471b7f  2b5604                 -sub edx, dword ptr [esi + 4]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 00471b82  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00471b85  0fafd9                 -imul ebx, ecx
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 00471b88  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00471b8a  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00471b8c  0f8e78ffffff           -jle 0x471b0a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00471b0a;
    }
    // 00471b92  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 00471b95  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00471b97  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00471b99  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 00471b9b  8b5b04                 -mov ebx, dword ptr [ebx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00471b9e  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00471ba0  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00471ba3  2b06                   -sub eax, dword ptr [esi]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi)));
    // 00471ba5  2b5e04                 -sub ebx, dword ptr [esi + 4]
    (cpu.ebx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 00471ba8  2b0e                   -sub ecx, dword ptr [esi]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi)));
    // 00471baa  2b5604                 -sub edx, dword ptr [esi + 4]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 00471bad  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00471bb0  0fafd9                 -imul ebx, ecx
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 00471bb3  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00471bb5  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00471bb7  0f8e4dffffff           -jle 0x471b0a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00471b0a;
    }
    // 00471bbd  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00471bc2  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00471bc7  89155cb75100           -mov dword ptr [0x51b75c], edx
    app->getMemory<x86::reg32>(x86::reg32(5355356) /* 0x51b75c */) = cpu.edx;
    // 00471bcd  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00471bcf  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00471bd2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471bd3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471bd4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471bd5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_471be0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00471be0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00471be1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00471be2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00471be3  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00471be6  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00471be8  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00471bea  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00471bec  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 00471bef  833d4cf54d0000         +cmp dword ptr [0x4df54c], 0
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
    // 00471bf6  745b                   -je 0x471c53
    if (cpu.flags.zf)
    {
        goto L_0x00471c53;
    }
    // 00471bf8  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00471bfa  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 00471bfc  8b5b04                 -mov ebx, dword ptr [ebx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00471bff  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00471c01  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00471c04  2b06                   -sub eax, dword ptr [esi]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi)));
    // 00471c06  2b5e04                 -sub ebx, dword ptr [esi + 4]
    (cpu.ebx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 00471c09  2b0e                   -sub ecx, dword ptr [esi]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi)));
    // 00471c0b  2b5604                 -sub edx, dword ptr [esi + 4]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 00471c0e  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00471c11  0fafd9                 -imul ebx, ecx
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 00471c14  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00471c16  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00471c18  7c0b                   -jl 0x471c25
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00471c25;
    }
L_0x00471c1a:
    // 00471c1a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00471c1c:
    // 00471c1c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00471c1e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00471c21  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471c22  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471c23  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471c24  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00471c25:
    // 00471c25  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 00471c28  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00471c2a  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00471c2c  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 00471c2e  8b5b04                 -mov ebx, dword ptr [ebx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00471c31  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00471c33  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00471c36  2b06                   -sub eax, dword ptr [esi]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi)));
    // 00471c38  2b5e04                 -sub ebx, dword ptr [esi + 4]
    (cpu.ebx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 00471c3b  2b0e                   -sub ecx, dword ptr [esi]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi)));
    // 00471c3d  2b5604                 -sub edx, dword ptr [esi + 4]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 00471c40  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00471c43  0fafd9                 -imul ebx, ecx
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 00471c46  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00471c48  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00471c4a  7dce                   -jge 0x471c1a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00471c1a;
    }
    // 00471c4c  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00471c51  ebc9                   -jmp 0x471c1c
    goto L_0x00471c1c;
L_0x00471c53:
    // 00471c53  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00471c55  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 00471c57  8b5b04                 -mov ebx, dword ptr [ebx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00471c5a  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00471c5c  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00471c5f  2b06                   -sub eax, dword ptr [esi]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi)));
    // 00471c61  2b5e04                 -sub ebx, dword ptr [esi + 4]
    (cpu.ebx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 00471c64  2b0e                   -sub ecx, dword ptr [esi]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi)));
    // 00471c66  2b5604                 -sub edx, dword ptr [esi + 4]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 00471c69  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00471c6c  0fafd9                 -imul ebx, ecx
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 00471c6f  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00471c71  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00471c73  7ea5                   -jle 0x471c1a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00471c1a;
    }
    // 00471c75  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 00471c78  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00471c7a  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00471c7c  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 00471c7e  8b5b04                 -mov ebx, dword ptr [ebx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 00471c81  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00471c83  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00471c86  2b06                   -sub eax, dword ptr [esi]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi)));
    // 00471c88  2b5e04                 -sub ebx, dword ptr [esi + 4]
    (cpu.ebx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 00471c8b  2b0e                   -sub ecx, dword ptr [esi]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi)));
    // 00471c8d  2b5604                 -sub edx, dword ptr [esi + 4]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 00471c90  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00471c93  0fafd9                 -imul ebx, ecx
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 00471c96  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00471c98  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00471c9a  0f8e7affffff           -jle 0x471c1a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00471c1a;
    }
    // 00471ca0  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00471ca5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00471ca7  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00471caa  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471cab  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471cac  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471cad  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_471cb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00471cb0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00471cb1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00471cb2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00471cb3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00471cb4  83ec58                 -sub esp, 0x58
    (cpu.esp) -= x86::reg32(x86::sreg32(88 /*0x58*/));
    // 00471cb7  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00471cb9  89542454               -mov dword ptr [esp + 0x54], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */) = cpu.edx;
    // 00471cbd  895c2450               -mov dword ptr [esp + 0x50], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */) = cpu.ebx;
    // 00471cc1  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00471cc3  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
    // 00471cc6  8b81a8a24c00           -mov eax, dword ptr [ecx + 0x4ca2a8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5022376) /* 0x4ca2a8 */);
    // 00471ccc  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00471cce  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00471cd1  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00471cd3  8b81aca24c00           -mov eax, dword ptr [ecx + 0x4ca2ac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5022380) /* 0x4ca2ac */);
    // 00471cd9  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00471cdc  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00471cdf  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00471ce1  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00471ce3  8b81b0a24c00           -mov eax, dword ptr [ecx + 0x4ca2b0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5022384) /* 0x4ca2b0 */);
    // 00471ce9  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00471ced  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00471cf0  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00471cf2  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00471cf4  8b81b4a24c00           -mov eax, dword ptr [ecx + 0x4ca2b4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5022388) /* 0x4ca2b4 */);
    // 00471cfa  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00471cfe  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00471d01  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00471d03  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00471d05  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00471d08  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00471d0c  81780800800000         +cmp dword ptr [eax + 8], 0x8000
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32768 /*0x8000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00471d13  7f27                   -jg 0x471d3c
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00471d3c;
    }
    // 00471d15  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00471d19  81780800800000         +cmp dword ptr [eax + 8], 0x8000
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32768 /*0x8000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00471d20  7f1a                   -jg 0x471d3c
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00471d3c;
    }
    // 00471d22  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00471d26  81780800800000         +cmp dword ptr [eax + 8], 0x8000
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32768 /*0x8000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00471d2d  7f0d                   -jg 0x471d3c
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00471d3c;
    }
    // 00471d2f  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00471d33  81780800800000         +cmp dword ptr [eax + 8], 0x8000
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32768 /*0x8000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00471d3a  7e29                   -jle 0x471d65
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00471d65;
    }
L_0x00471d3c:
    // 00471d3c  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00471d3f  8b3d78b75100           -mov edi, dword ptr [0x51b778]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5355384) /* 0x51b778 */);
    // 00471d45  3b7814                 +cmp edi, dword ptr [eax + 0x14]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00471d48  7d23                   -jge 0x471d6d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00471d6d;
    }
    // 00471d4a  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00471d4e  3b7814                 +cmp edi, dword ptr [eax + 0x14]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00471d51  7d1a                   -jge 0x471d6d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00471d6d;
    }
    // 00471d53  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00471d57  3b7814                 +cmp edi, dword ptr [eax + 0x14]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00471d5a  7d11                   -jge 0x471d6d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00471d6d;
    }
    // 00471d5c  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00471d60  3b7814                 +cmp edi, dword ptr [eax + 0x14]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00471d63  7d08                   -jge 0x471d6d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00471d6d;
    }
L_0x00471d65:
    // 00471d65  83c458                 -add esp, 0x58
    (cpu.esp) += x86::reg32(x86::sreg32(88 /*0x58*/));
    // 00471d68  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471d69  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471d6a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471d6b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471d6c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00471d6d:
    // 00471d6d  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00471d71  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00471d75  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00471d79  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00471d7c  e80ffdffff             -call 0x471a90
    cpu.esp -= 4;
    sub_471a90(app, cpu);
    if (cpu.terminate) return;
    // 00471d81  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00471d83  75e0                   -jne 0x471d65
    if (!cpu.flags.zf)
    {
        goto L_0x00471d65;
    }
    // 00471d85  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00471d89  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 00471d8c  8b7208                 -mov esi, dword ptr [edx + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00471d8f  8b4908                 -mov ecx, dword ptr [ecx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00471d92  8b7c2454               -mov edi, dword ptr [esp + 0x54]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 00471d96  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 00471d98  83ff02                 +cmp edi, 2
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
    // 00471d9b  7e33                   -jle 0x471dd0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00471dd0;
    }
L_0x00471d9d:
    // 00471d9d  837c245400             +cmp dword ptr [esp + 0x54], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00471da2  0f8ed0040000           -jle 0x472278
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00472278;
    }
    // 00471da8  a158b75100             -mov eax, dword ptr [0x51b758]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355352) /* 0x51b758 */);
    // 00471dad  6683780800             +cmp word ptr [eax + 8], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(8) /* 0x8 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00471db2  0f85c0040000           -jne 0x472278
    if (!cpu.flags.zf)
    {
        goto L_0x00472278;
    }
    // 00471db8  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00471dbd  8b542450               -mov edx, dword ptr [esp + 0x50]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 00471dc1  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00471dc3  e8c8040000             -call 0x472290
    cpu.esp -= 4;
    sub_472290(app, cpu);
    if (cpu.terminate) return;
    // 00471dc8  83c458                 -add esp, 0x58
    (cpu.esp) += x86::reg32(x86::sreg32(88 /*0x58*/));
    // 00471dcb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471dcc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471dcd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471dce  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471dcf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00471dd0:
    // 00471dd0  8b1558b75100           -mov edx, dword ptr [0x51b758]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5355352) /* 0x51b758 */);
    // 00471dd6  8b5206                 -mov edx, dword ptr [edx + 6]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(6) /* 0x6 */);
    // 00471dd9  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00471ddc  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00471dde  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 00471de1  3b8c82e8a24c00         +cmp ecx, dword ptr [edx + eax*4 + 0x4ca2e8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5022440) /* 0x4ca2e8 */ + cpu.eax * 4)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00471de8  7fb3                   -jg 0x471d9d
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00471d9d;
    }
    // 00471dea  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00471ded  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00471def  8944244c               -mov dword ptr [esp + 0x4c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */) = cpu.eax;
    // 00471df3  8b8048a24c00           -mov eax, dword ptr [eax + 0x4ca248]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5022280) /* 0x4ca248 */);
    // 00471df9  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
    // 00471dfc  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00471dff  8b91a8a24c00           -mov edx, dword ptr [ecx + 0x4ca2a8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5022376) /* 0x4ca2a8 */);
    // 00471e05  8d1c28                 -lea ebx, [eax + ebp]
    cpu.ebx = x86::reg32(cpu.eax + cpu.ebp * 1);
    // 00471e08  8b81aca24c00           -mov eax, dword ptr [ecx + 0x4ca2ac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5022380) /* 0x4ca2ac */);
    // 00471e0e  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 00471e11  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00471e14  8b342a                 -mov esi, dword ptr [edx + ebp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + cpu.ebp * 1);
    // 00471e17  8b3c28                 -mov edi, dword ptr [eax + ebp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + cpu.ebp * 1);
    // 00471e1a  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 00471e1c  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 00471e1e  d1ff                   -sar edi, 1
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (1 /*0x1*/ % 32));
    // 00471e20  c1fe09                 -sar esi, 9
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (9 /*0x9*/ % 32));
    // 00471e23  893b                   -mov dword ptr [ebx], edi
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edi;
    // 00471e25  89742428               -mov dword ptr [esp + 0x28], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.esi;
    // 00471e29  8b742a04               -mov esi, dword ptr [edx + ebp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */ + cpu.ebp * 1);
    // 00471e2d  8b7c2804               -mov edi, dword ptr [eax + ebp + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */ + cpu.ebp * 1);
    // 00471e31  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 00471e33  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 00471e35  d1ff                   -sar edi, 1
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (1 /*0x1*/ % 32));
    // 00471e37  c1fe09                 -sar esi, 9
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (9 /*0x9*/ % 32));
    // 00471e3a  897b04                 -mov dword ptr [ebx + 4], edi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 00471e3d  8974242c               -mov dword ptr [esp + 0x2c], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.esi;
    // 00471e41  8b542a08               -mov edx, dword ptr [edx + ebp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */ + cpu.ebp * 1);
    // 00471e45  8b742808               -mov esi, dword ptr [eax + ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */ + cpu.ebp * 1);
    // 00471e49  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00471e4b  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 00471e4d  893d80a44c00           -mov dword ptr [0x4ca480], edi
    app->getMemory<x86::reg32>(x86::reg32(5022848) /* 0x4ca480 */) = cpu.edi;
    // 00471e53  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00471e55  8d7b10                 -lea edi, [ebx + 0x10]
    cpu.edi = x86::reg32(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 00471e58  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00471e5a  c1fa09                 -sar edx, 9
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (9 /*0x9*/ % 32));
    // 00471e5d  894308                 -mov dword ptr [ebx + 8], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00471e60  8d742428               -lea esi, [esp + 0x28]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00471e64  89542430               -mov dword ptr [esp + 0x30], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.edx;
    // 00471e68  837e0800               +cmp dword ptr [esi + 8], 0
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
    // 00471e6c  7e2a                   -jle 0x471e98
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00471e98;
    }
    // 00471e6e  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00471e70  f72d78a44c00           -imul dword ptr [0x4ca478]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5022840) /* 0x4ca478 */))));
    // 00471e76  f77e08                 -idiv dword ptr [esi + 8]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00471e79  030570a44c00           -add eax, dword ptr [0x4ca470]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5022832) /* 0x4ca470 */)));
    // 00471e7f  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 00471e81  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00471e84  f72d7ca44c00           -imul dword ptr [0x4ca47c]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5022844) /* 0x4ca47c */))));
    // 00471e8a  f77e08                 -idiv dword ptr [esi + 8]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00471e8d  030574a44c00           +add eax, dword ptr [0x4ca474]
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
    // 00471e93  894704                 -mov dword ptr [edi + 4], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00471e96  eb14                   -jmp 0x471eac
    goto L_0x00471eac;
L_0x00471e98:
    // 00471e98  c70700000080           -mov dword ptr [edi], 0x80000000
    app->getMemory<x86::reg32>(cpu.edi) = 2147483648 /*0x80000000*/;
    // 00471e9e  c7470400000080         -mov dword ptr [edi + 4], 0x80000000
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = 2147483648 /*0x80000000*/;
    // 00471ea5  830d80a44c0001         -or dword ptr [0x4ca480], 1
    app->getMemory<x86::reg32>(x86::reg32(5022848) /* 0x4ca480 */) |= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x00471eac:
    // 00471eac  66a180a44c00           -mov ax, word ptr [0x4ca480]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5022848) /* 0x4ca480 */);
    // 00471eb2  6689430e               -mov word ptr [ebx + 0xe], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(14) /* 0xe */) = cpu.ax;
    // 00471eb6  8b44244c               -mov eax, dword ptr [esp + 0x4c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 00471eba  8b804ca24c00           -mov eax, dword ptr [eax + 0x4ca24c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5022284) /* 0x4ca24c */);
    // 00471ec0  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00471ec3  8b91a8a24c00           -mov edx, dword ptr [ecx + 0x4ca2a8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5022376) /* 0x4ca2a8 */);
    // 00471ec9  8d1c28                 -lea ebx, [eax + ebp]
    cpu.ebx = x86::reg32(cpu.eax + cpu.ebp * 1);
    // 00471ecc  8b81b4a24c00           -mov eax, dword ptr [ecx + 0x4ca2b4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5022388) /* 0x4ca2b4 */);
    // 00471ed2  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 00471ed5  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00471ed8  8b342a                 -mov esi, dword ptr [edx + ebp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + cpu.ebp * 1);
    // 00471edb  8b3c28                 -mov edi, dword ptr [eax + ebp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + cpu.ebp * 1);
    // 00471ede  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 00471ee0  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 00471ee2  d1ff                   -sar edi, 1
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (1 /*0x1*/ % 32));
    // 00471ee4  c1fe09                 -sar esi, 9
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (9 /*0x9*/ % 32));
    // 00471ee7  893b                   -mov dword ptr [ebx], edi
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edi;
    // 00471ee9  89742434               -mov dword ptr [esp + 0x34], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.esi;
    // 00471eed  8b742a04               -mov esi, dword ptr [edx + ebp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */ + cpu.ebp * 1);
    // 00471ef1  8b7c2804               -mov edi, dword ptr [eax + ebp + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */ + cpu.ebp * 1);
    // 00471ef5  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 00471ef7  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 00471ef9  d1ff                   -sar edi, 1
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (1 /*0x1*/ % 32));
    // 00471efb  c1fe09                 -sar esi, 9
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (9 /*0x9*/ % 32));
    // 00471efe  897b04                 -mov dword ptr [ebx + 4], edi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 00471f01  89742438               -mov dword ptr [esp + 0x38], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.esi;
    // 00471f05  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00471f07  8b542a08               -mov edx, dword ptr [edx + ebp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */ + cpu.ebp * 1);
    // 00471f0b  8b742808               -mov esi, dword ptr [eax + ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */ + cpu.ebp * 1);
    // 00471f0f  893d80a44c00           -mov dword ptr [0x4ca480], edi
    app->getMemory<x86::reg32>(x86::reg32(5022848) /* 0x4ca480 */) = cpu.edi;
    // 00471f15  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 00471f17  8d7b10                 -lea edi, [ebx + 0x10]
    cpu.edi = x86::reg32(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 00471f1a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00471f1c  d1fa                   -sar edx, 1
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (1 /*0x1*/ % 32));
    // 00471f1e  c1f809                 -sar eax, 9
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (9 /*0x9*/ % 32));
    // 00471f21  895308                 -mov dword ptr [ebx + 8], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00471f24  8d742434               -lea esi, [esp + 0x34]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00471f28  8944243c               -mov dword ptr [esp + 0x3c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.eax;
    // 00471f2c  837e0800               +cmp dword ptr [esi + 8], 0
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
    // 00471f30  7e2a                   -jle 0x471f5c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00471f5c;
    }
    // 00471f32  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00471f34  f72d78a44c00           -imul dword ptr [0x4ca478]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5022840) /* 0x4ca478 */))));
    // 00471f3a  f77e08                 -idiv dword ptr [esi + 8]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00471f3d  030570a44c00           -add eax, dword ptr [0x4ca470]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5022832) /* 0x4ca470 */)));
    // 00471f43  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 00471f45  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00471f48  f72d7ca44c00           -imul dword ptr [0x4ca47c]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5022844) /* 0x4ca47c */))));
    // 00471f4e  f77e08                 -idiv dword ptr [esi + 8]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00471f51  030574a44c00           +add eax, dword ptr [0x4ca474]
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
    // 00471f57  894704                 -mov dword ptr [edi + 4], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00471f5a  eb14                   -jmp 0x471f70
    goto L_0x00471f70;
L_0x00471f5c:
    // 00471f5c  c70700000080           -mov dword ptr [edi], 0x80000000
    app->getMemory<x86::reg32>(cpu.edi) = 2147483648 /*0x80000000*/;
    // 00471f62  c7470400000080         -mov dword ptr [edi + 4], 0x80000000
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = 2147483648 /*0x80000000*/;
    // 00471f69  830d80a44c0001         -or dword ptr [0x4ca480], 1
    app->getMemory<x86::reg32>(x86::reg32(5022848) /* 0x4ca480 */) |= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x00471f70:
    // 00471f70  66a180a44c00           -mov ax, word ptr [0x4ca480]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5022848) /* 0x4ca480 */);
    // 00471f76  6689430e               -mov word ptr [ebx + 0xe], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(14) /* 0xe */) = cpu.ax;
    // 00471f7a  8b44244c               -mov eax, dword ptr [esp + 0x4c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 00471f7e  8b8050a24c00           -mov eax, dword ptr [eax + 0x4ca250]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5022288) /* 0x4ca250 */);
    // 00471f84  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00471f87  8b91b0a24c00           -mov edx, dword ptr [ecx + 0x4ca2b0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5022384) /* 0x4ca2b0 */);
    // 00471f8d  8d1c28                 -lea ebx, [eax + ebp]
    cpu.ebx = x86::reg32(cpu.eax + cpu.ebp * 1);
    // 00471f90  8b81a8a24c00           -mov eax, dword ptr [ecx + 0x4ca2a8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5022376) /* 0x4ca2a8 */);
    // 00471f96  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 00471f99  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00471f9c  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00471f9e  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00471fa0  8b3a                   -mov edi, dword ptr [edx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx);
    // 00471fa2  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 00471fa4  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 00471fa6  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 00471fa8  d1ff                   -sar edi, 1
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (1 /*0x1*/ % 32));
    // 00471faa  c1fe09                 -sar esi, 9
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (9 /*0x9*/ % 32));
    // 00471fad  893b                   -mov dword ptr [ebx], edi
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edi;
    // 00471faf  89742440               -mov dword ptr [esp + 0x40], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.esi;
    // 00471fb3  8b7004                 -mov esi, dword ptr [eax + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00471fb6  8b7a04                 -mov edi, dword ptr [edx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00471fb9  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 00471fbb  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 00471fbd  d1ff                   -sar edi, 1
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (1 /*0x1*/ % 32));
    // 00471fbf  c1fe09                 -sar esi, 9
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (9 /*0x9*/ % 32));
    // 00471fc2  897b04                 -mov dword ptr [ebx + 4], edi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 00471fc5  89742444               -mov dword ptr [esp + 0x44], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */) = cpu.esi;
    // 00471fc9  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00471fcc  8b7208                 -mov esi, dword ptr [edx + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00471fcf  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00471fd1  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00471fd3  893d80a44c00           -mov dword ptr [0x4ca480], edi
    app->getMemory<x86::reg32>(x86::reg32(5022848) /* 0x4ca480 */) = cpu.edi;
    // 00471fd9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00471fdb  8d742440               -lea esi, [esp + 0x40]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00471fdf  d1fa                   -sar edx, 1
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (1 /*0x1*/ % 32));
    // 00471fe1  c1f809                 -sar eax, 9
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (9 /*0x9*/ % 32));
    // 00471fe4  895308                 -mov dword ptr [ebx + 8], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00471fe7  8d7b10                 -lea edi, [ebx + 0x10]
    cpu.edi = x86::reg32(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 00471fea  89442448               -mov dword ptr [esp + 0x48], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */) = cpu.eax;
    // 00471fee  837e0800               +cmp dword ptr [esi + 8], 0
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
    // 00471ff2  7e2a                   -jle 0x47201e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047201e;
    }
    // 00471ff4  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 00471ff6  f72d78a44c00           -imul dword ptr [0x4ca478]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5022840) /* 0x4ca478 */))));
    // 00471ffc  f77e08                 -idiv dword ptr [esi + 8]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00471fff  030570a44c00           -add eax, dword ptr [0x4ca470]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5022832) /* 0x4ca470 */)));
    // 00472005  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 00472007  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0047200a  f72d7ca44c00           -imul dword ptr [0x4ca47c]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5022844) /* 0x4ca47c */))));
    // 00472010  f77e08                 -idiv dword ptr [esi + 8]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00472013  030574a44c00           +add eax, dword ptr [0x4ca474]
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
    // 00472019  894704                 -mov dword ptr [edi + 4], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0047201c  eb14                   -jmp 0x472032
    goto L_0x00472032;
L_0x0047201e:
    // 0047201e  c70700000080           -mov dword ptr [edi], 0x80000000
    app->getMemory<x86::reg32>(cpu.edi) = 2147483648 /*0x80000000*/;
    // 00472024  c7470400000080         -mov dword ptr [edi + 4], 0x80000000
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = 2147483648 /*0x80000000*/;
    // 0047202b  830d80a44c0001         -or dword ptr [0x4ca480], 1
    app->getMemory<x86::reg32>(x86::reg32(5022848) /* 0x4ca480 */) |= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x00472032:
    // 00472032  66a180a44c00           -mov ax, word ptr [0x4ca480]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5022848) /* 0x4ca480 */);
    // 00472038  6689430e               -mov word ptr [ebx + 0xe], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(14) /* 0xe */) = cpu.ax;
    // 0047203c  8b44244c               -mov eax, dword ptr [esp + 0x4c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 00472040  8b8054a24c00           -mov eax, dword ptr [eax + 0x4ca254]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5022292) /* 0x4ca254 */);
    // 00472046  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00472049  8bb9aca24c00           -mov edi, dword ptr [ecx + 0x4ca2ac]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5022380) /* 0x4ca2ac */);
    // 0047204f  8d1c28                 -lea ebx, [eax + ebp]
    cpu.ebx = x86::reg32(cpu.eax + cpu.ebp * 1);
    // 00472052  8b81b0a24c00           -mov eax, dword ptr [ecx + 0x4ca2b0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5022384) /* 0x4ca2b0 */);
    // 00472058  c1e705                 -shl edi, 5
    cpu.edi <<= 5 /*0x5*/ % 32;
    // 0047205b  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 0047205e  8b342f                 -mov esi, dword ptr [edi + ebp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + cpu.ebp * 1);
    // 00472061  8b1428                 -mov edx, dword ptr [eax + ebp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + cpu.ebp * 1);
    // 00472064  01d6                   -add esi, edx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edx));
    // 00472066  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00472068  d1fa                   -sar edx, 1
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (1 /*0x1*/ % 32));
    // 0047206a  c1fe09                 -sar esi, 9
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (9 /*0x9*/ % 32));
    // 0047206d  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 0047206f  8974241c               -mov dword ptr [esp + 0x1c], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.esi;
    // 00472073  8b542f04               -mov edx, dword ptr [edi + ebp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */ + cpu.ebp * 1);
    // 00472077  8b742804               -mov esi, dword ptr [eax + ebp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */ + cpu.ebp * 1);
    // 0047207b  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0047207d  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0047207f  d1fe                   -sar esi, 1
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (1 /*0x1*/ % 32));
    // 00472081  c1fa09                 -sar edx, 9
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (9 /*0x9*/ % 32));
    // 00472084  897304                 -mov dword ptr [ebx + 4], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 00472087  89542420               -mov dword ptr [esp + 0x20], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 0047208b  8b542f08               -mov edx, dword ptr [edi + ebp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */ + cpu.ebp * 1);
    // 0047208f  03542808               -add edx, dword ptr [eax + ebp + 8]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */ + cpu.ebp * 1)));
    // 00472093  8d74241c               -lea esi, [esp + 0x1c]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00472097  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00472099  8d7b10                 -lea edi, [ebx + 0x10]
    cpu.edi = x86::reg32(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 0047209c  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0047209e  c1fa09                 -sar edx, 9
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (9 /*0x9*/ % 32));
    // 004720a1  894308                 -mov dword ptr [ebx + 8], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004720a4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004720a6  89542424               -mov dword ptr [esp + 0x24], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 004720aa  a380a44c00             -mov dword ptr [0x4ca480], eax
    app->getMemory<x86::reg32>(x86::reg32(5022848) /* 0x4ca480 */) = cpu.eax;
    // 004720af  837e0800               +cmp dword ptr [esi + 8], 0
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
    // 004720b3  7e2a                   -jle 0x4720df
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004720df;
    }
    // 004720b5  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004720b7  f72d78a44c00           -imul dword ptr [0x4ca478]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5022840) /* 0x4ca478 */))));
    // 004720bd  f77e08                 -idiv dword ptr [esi + 8]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004720c0  030570a44c00           -add eax, dword ptr [0x4ca470]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5022832) /* 0x4ca470 */)));
    // 004720c6  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 004720c8  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004720cb  f72d7ca44c00           -imul dword ptr [0x4ca47c]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5022844) /* 0x4ca47c */))));
    // 004720d1  f77e08                 -idiv dword ptr [esi + 8]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004720d4  030574a44c00           +add eax, dword ptr [0x4ca474]
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
    // 004720da  894704                 -mov dword ptr [edi + 4], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004720dd  eb14                   -jmp 0x4720f3
    goto L_0x004720f3;
L_0x004720df:
    // 004720df  c70700000080           -mov dword ptr [edi], 0x80000000
    app->getMemory<x86::reg32>(cpu.edi) = 2147483648 /*0x80000000*/;
    // 004720e5  c7470400000080         -mov dword ptr [edi + 4], 0x80000000
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = 2147483648 /*0x80000000*/;
    // 004720ec  830d80a44c0001         -or dword ptr [0x4ca480], 1
    app->getMemory<x86::reg32>(x86::reg32(5022848) /* 0x4ca480 */) |= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004720f3:
    // 004720f3  66a180a44c00           -mov ax, word ptr [0x4ca480]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5022848) /* 0x4ca480 */);
    // 004720f9  6689430e               -mov word ptr [ebx + 0xe], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(14) /* 0xe */) = cpu.ax;
    // 004720fd  8b44244c               -mov eax, dword ptr [esp + 0x4c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 00472101  8b8058a24c00           -mov eax, dword ptr [eax + 0x4ca258]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5022296) /* 0x4ca258 */);
    // 00472107  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 0047210a  8b91b4a24c00           -mov edx, dword ptr [ecx + 0x4ca2b4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5022388) /* 0x4ca2b4 */);
    // 00472110  8d1c28                 -lea ebx, [eax + ebp]
    cpu.ebx = x86::reg32(cpu.eax + cpu.ebp * 1);
    // 00472113  8b81b0a24c00           -mov eax, dword ptr [ecx + 0x4ca2b0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5022384) /* 0x4ca2b0 */);
    // 00472119  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 0047211c  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 0047211f  8b0c2a                 -mov ecx, dword ptr [edx + ebp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.ebp * 1);
    // 00472122  8b3428                 -mov esi, dword ptr [eax + ebp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + cpu.ebp * 1);
    // 00472125  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 00472127  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00472129  d1fe                   -sar esi, 1
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (1 /*0x1*/ % 32));
    // 0047212b  c1f909                 -sar ecx, 9
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (9 /*0x9*/ % 32));
    // 0047212e  8933                   -mov dword ptr [ebx], esi
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.esi;
    // 00472130  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00472134  8b4c2a04               -mov ecx, dword ptr [edx + ebp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */ + cpu.ebp * 1);
    // 00472138  8b7c2804               -mov edi, dword ptr [eax + ebp + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */ + cpu.ebp * 1);
    // 0047213c  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0047213e  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00472140  d1fe                   -sar esi, 1
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (1 /*0x1*/ % 32));
    // 00472142  c1f909                 -sar ecx, 9
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (9 /*0x9*/ % 32));
    // 00472145  897304                 -mov dword ptr [ebx + 4], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 00472148  894c2414               -mov dword ptr [esp + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 0047214c  8d7b10                 -lea edi, [ebx + 0x10]
    cpu.edi = x86::reg32(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 0047214f  8b542a08               -mov edx, dword ptr [edx + ebp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */ + cpu.ebp * 1);
    // 00472153  8b4c2808               -mov ecx, dword ptr [eax + ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */ + cpu.ebp * 1);
    // 00472157  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00472159  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0047215b  893580a44c00           -mov dword ptr [0x4ca480], esi
    app->getMemory<x86::reg32>(x86::reg32(5022848) /* 0x4ca480 */) = cpu.esi;
    // 00472161  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00472163  d1fa                   -sar edx, 1
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (1 /*0x1*/ % 32));
    // 00472165  c1f809                 -sar eax, 9
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (9 /*0x9*/ % 32));
    // 00472168  895308                 -mov dword ptr [ebx + 8], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0047216b  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0047216f  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00472173  837e0800               +cmp dword ptr [esi + 8], 0
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
    // 00472177  7e2a                   -jle 0x4721a3
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004721a3;
    }
    // 00472179  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0047217b  f72d78a44c00           -imul dword ptr [0x4ca478]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5022840) /* 0x4ca478 */))));
    // 00472181  f77e08                 -idiv dword ptr [esi + 8]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00472184  030570a44c00           -add eax, dword ptr [0x4ca470]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5022832) /* 0x4ca470 */)));
    // 0047218a  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 0047218c  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0047218f  f72d7ca44c00           -imul dword ptr [0x4ca47c]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5022844) /* 0x4ca47c */))));
    // 00472195  f77e08                 -idiv dword ptr [esi + 8]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00472198  030574a44c00           +add eax, dword ptr [0x4ca474]
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
    // 0047219e  894704                 -mov dword ptr [edi + 4], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004721a1  eb14                   -jmp 0x4721b7
    goto L_0x004721b7;
L_0x004721a3:
    // 004721a3  c70700000080           -mov dword ptr [edi], 0x80000000
    app->getMemory<x86::reg32>(cpu.edi) = 2147483648 /*0x80000000*/;
    // 004721a9  c7470400000080         -mov dword ptr [edi + 4], 0x80000000
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = 2147483648 /*0x80000000*/;
    // 004721b0  830d80a44c0001         -or dword ptr [0x4ca480], 1
    app->getMemory<x86::reg32>(x86::reg32(5022848) /* 0x4ca480 */) |= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004721b7:
    // 004721b7  66a180a44c00           -mov ax, word ptr [0x4ca480]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5022848) /* 0x4ca480 */);
    // 004721bd  6689430e               -mov word ptr [ebx + 0xe], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(14) /* 0xe */) = cpu.ax;
    // 004721c1  8b7c2454               -mov edi, dword ptr [esp + 0x54]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 004721c5  8b442450               -mov eax, dword ptr [esp + 0x50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 004721c9  8b0d58b75100           -mov ecx, dword ptr [0x51b758]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5355352) /* 0x51b758 */);
    // 004721cf  47                     -inc edi
    (cpu.edi)++;
    // 004721d0  40                     -inc eax
    (cpu.eax)++;
    // 004721d1  8b491c                 -mov ecx, dword ptr [ecx + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 004721d4  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 004721d6  89442450               -mov dword ptr [esp + 0x50], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */) = cpu.eax;
    // 004721da  c1e604                 -shl esi, 4
    cpu.esi <<= 4 /*0x4*/ % 32;
    // 004721dd  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004721df  81c6a8a24c00           -add esi, 0x4ca2a8
    (cpu.esi) += x86::reg32(x86::sreg32(5022376 /*0x4ca2a8*/));
    // 004721e5  8a4104                 -mov al, byte ptr [ecx + 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004721e8  8b0486                 -mov eax, dword ptr [esi + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + cpu.eax * 4);
    // 004721eb  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004721ed  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004721f0  8b5c2450               -mov ebx, dword ptr [esp + 0x50]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 004721f4  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004721f6  e8b5faffff             -call 0x471cb0
    cpu.esp -= 4;
    sub_471cb0(app, cpu);
    if (cpu.terminate) return;
    // 004721fb  8b542450               -mov edx, dword ptr [esp + 0x50]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 004721ff  0314bd38a24c00         -add edx, dword ptr [edi*4 + 0x4ca238]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5022264) /* 0x4ca238 */ + cpu.edi * 4)));
    // 00472206  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00472208  8a4105                 -mov al, byte ptr [ecx + 5]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5) /* 0x5 */);
    // 0047220b  89542450               -mov dword ptr [esp + 0x50], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */) = cpu.edx;
    // 0047220f  8b0486                 -mov eax, dword ptr [esi + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + cpu.eax * 4);
    // 00472212  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00472214  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00472217  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00472219  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0047221b  e890faffff             -call 0x471cb0
    cpu.esp -= 4;
    sub_471cb0(app, cpu);
    if (cpu.terminate) return;
    // 00472220  8b5c2450               -mov ebx, dword ptr [esp + 0x50]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 00472224  031cbd38a24c00         -add ebx, dword ptr [edi*4 + 0x4ca238]
    (cpu.ebx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5022264) /* 0x4ca238 */ + cpu.edi * 4)));
    // 0047222b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047222d  8a4106                 -mov al, byte ptr [ecx + 6]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(6) /* 0x6 */);
    // 00472230  8b0486                 -mov eax, dword ptr [esi + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + cpu.eax * 4);
    // 00472233  897c2454               -mov dword ptr [esp + 0x54], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */) = cpu.edi;
    // 00472237  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 0047223a  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0047223c  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0047223e  895c2450               -mov dword ptr [esp + 0x50], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */) = cpu.ebx;
    // 00472242  e869faffff             -call 0x471cb0
    cpu.esp -= 4;
    sub_471cb0(app, cpu);
    if (cpu.terminate) return;
    // 00472247  8b04bd38a24c00         -mov eax, dword ptr [edi*4 + 0x4ca238]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5022264) /* 0x4ca238 */ + cpu.edi * 4);
    // 0047224e  8b7c2450               -mov edi, dword ptr [esp + 0x50]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 00472252  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00472254  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00472256  8a4107                 -mov al, byte ptr [ecx + 7]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(7) /* 0x7 */);
    // 00472259  8b0486                 -mov eax, dword ptr [esi + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + cpu.eax * 4);
    // 0047225c  8b542454               -mov edx, dword ptr [esp + 0x54]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 00472260  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00472263  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00472265  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00472267  897c2450               -mov dword ptr [esp + 0x50], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */) = cpu.edi;
    // 0047226b  e840faffff             -call 0x471cb0
    cpu.esp -= 4;
    sub_471cb0(app, cpu);
    if (cpu.terminate) return;
    // 00472270  83c458                 -add esp, 0x58
    (cpu.esp) += x86::reg32(x86::sreg32(88 /*0x58*/));
    // 00472273  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472274  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472275  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472276  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472277  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00472278:
    // 00472278  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047227a  8b542450               -mov edx, dword ptr [esp + 0x50]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 0047227e  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00472280  e80b000000             -call 0x472290
    cpu.esp -= 4;
    sub_472290(app, cpu);
    if (cpu.terminate) return;
    // 00472285  83c458                 -add esp, 0x58
    (cpu.esp) += x86::reg32(x86::sreg32(88 /*0x58*/));
    // 00472288  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472289  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047228a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047228b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047228c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_472290(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00472290  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00472291  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00472292  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00472293  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00472294  81ecc0000000           -sub esp, 0xc0
    (cpu.esp) -= x86::reg32(x86::sreg32(192 /*0xc0*/));
    // 0047229a  898424b0000000         -mov dword ptr [esp + 0xb0], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(176) /* 0xb0 */) = cpu.eax;
    // 004722a1  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004722a3  899c2498000000         -mov dword ptr [esp + 0x98], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(152) /* 0x98 */) = cpu.ebx;
    // 004722aa  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004722ac  8d5810                 -lea ebx, [eax + 0x10]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
L_0x004722af:
    // 004722af  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 004722b1  6683780e00             +cmp word ptr [eax + 0xe], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(14) /* 0xe */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004722b6  0f855c030000           -jne 0x472618
    if (!cpu.flags.zf)
    {
        goto L_0x00472618;
    }
L_0x004722bc:
    // 004722bc  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004722bf  39d9                   +cmp ecx, ebx
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
    // 004722c1  75ec                   -jne 0x4722af
    if (!cpu.flags.zf)
    {
        goto L_0x004722af;
    }
    // 004722c3  8b0d58b75100           -mov ecx, dword ptr [0x51b758]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5355352) /* 0x51b758 */);
    // 004722c9  8d04ad00000000         -lea eax, [ebp*4]
    cpu.eax = x86::reg32(cpu.ebp * 4);
    // 004722d0  8b491c                 -mov ecx, dword ptr [ecx + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 004722d3  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004722d5  8b19                   -mov ebx, dword ptr [ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004722d7  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 004722de  898c248c000000         -mov dword ptr [esp + 0x8c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */) = cpu.ecx;
    // 004722e5  8b7302                 -mov esi, dword ptr [ebx + 2]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 004722e8  8b823c9e4c00           -mov eax, dword ptr [edx + 0x4c9e3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5021244) /* 0x4c9e3c */);
    // 004722ee  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 004722f1  88c1                   -mov cl, al
    cpu.cl = cpu.al;
    // 004722f3  8b5b04                 -mov ebx, dword ptr [ebx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004722f6  4e                     -dec esi
    (cpu.esi)--;
    // 004722f7  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 004722fa  c1e610                 -shl esi, 0x10
    cpu.esi <<= 16 /*0x10*/ % 32;
    // 004722fd  4b                     -dec ebx
    (cpu.ebx)--;
    // 004722fe  d3fe                   -sar esi, cl
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (cpu.cl % 32));
    // 00472300  c1e310                 -shl ebx, 0x10
    cpu.ebx <<= 16 /*0x10*/ % 32;
    // 00472303  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00472305  d3fb                   -sar ebx, cl
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (cpu.cl % 32));
    // 00472307  0faf82409e4c00         -imul eax, dword ptr [edx + 0x4c9e40]
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5021248) /* 0x4c9e40 */))));
    // 0047230e  899c24a0000000         -mov dword ptr [esp + 0xa0], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(160) /* 0xa0 */) = cpu.ebx;
    // 00472315  898424a8000000         -mov dword ptr [esp + 0xa8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(168) /* 0xa8 */) = cpu.eax;
    // 0047231c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047231e  0faf82449e4c00         -imul eax, dword ptr [edx + 0x4c9e44]
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5021252) /* 0x4c9e44 */))));
    // 00472325  89b4249c000000         -mov dword ptr [esp + 0x9c], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */) = cpu.esi;
    // 0047232c  8bb424b0000000         -mov esi, dword ptr [esp + 0xb0]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(176) /* 0xb0 */);
    // 00472333  8b7604                 -mov esi, dword ptr [esi + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00472336  8b9424b0000000         -mov edx, dword ptr [esp + 0xb0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(176) /* 0xb0 */);
    // 0047233d  8b9c24b0000000         -mov ebx, dword ptr [esp + 0xb0]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(176) /* 0xb0 */);
    // 00472344  83c610                 -add esi, 0x10
    (cpu.esi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00472347  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 00472349  8b5b08                 -mov ebx, dword ptr [ebx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0047234c  83c210                 -add edx, 0x10
    (cpu.edx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0047234f  83c310                 -add ebx, 0x10
    (cpu.ebx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00472352  898424a4000000         -mov dword ptr [esp + 0xa4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(164) /* 0xa4 */) = cpu.eax;
    // 00472359  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 0047235b  8b5b04                 -mov ebx, dword ptr [ebx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 0047235e  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00472360  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00472363  2b06                   -sub eax, dword ptr [esi]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi)));
    // 00472365  2b5e04                 -sub ebx, dword ptr [esi + 4]
    (cpu.ebx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 00472368  2b0e                   -sub ecx, dword ptr [esi]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi)));
    // 0047236a  2b5604                 -sub edx, dword ptr [esi + 4]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 0047236d  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00472370  0fafd9                 -imul ebx, ecx
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 00472373  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00472375  899c24ac000000         -mov dword ptr [esp + 0xac], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(172) /* 0xac */) = cpu.ebx;
    // 0047237c  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047237e  754a                   -jne 0x4723ca
    if (!cpu.flags.zf)
    {
        goto L_0x004723ca;
    }
    // 00472380  8b9c24b0000000         -mov ebx, dword ptr [esp + 0xb0]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(176) /* 0xb0 */);
    // 00472387  8bb424b0000000         -mov esi, dword ptr [esp + 0xb0]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(176) /* 0xb0 */);
    // 0047238e  8b9424b0000000         -mov edx, dword ptr [esp + 0xb0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(176) /* 0xb0 */);
    // 00472395  8b5b0c                 -mov ebx, dword ptr [ebx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 00472398  8b7608                 -mov esi, dword ptr [esi + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0047239b  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0047239e  83c310                 -add ebx, 0x10
    (cpu.ebx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004723a1  83c610                 -add esi, 0x10
    (cpu.esi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004723a4  83c210                 -add edx, 0x10
    (cpu.edx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004723a7  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004723a9  8b5b04                 -mov ebx, dword ptr [ebx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004723ac  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004723ae  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004723b1  2b06                   -sub eax, dword ptr [esi]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi)));
    // 004723b3  2b5e04                 -sub ebx, dword ptr [esi + 4]
    (cpu.ebx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 004723b6  2b0e                   -sub ecx, dword ptr [esi]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi)));
    // 004723b8  2b5604                 -sub edx, dword ptr [esi + 4]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 004723bb  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004723be  0fafd9                 -imul ebx, ecx
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004723c1  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004723c3  899c24ac000000         -mov dword ptr [esp + 0xac], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(172) /* 0xac */) = cpu.ebx;
L_0x004723ca:
    // 004723ca  83bc249800000000       +cmp dword ptr [esp + 0x98], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(152) /* 0x98 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004723d2  0f84f6020000           -je 0x4726ce
    if (cpu.flags.zf)
    {
        goto L_0x004726ce;
    }
    // 004723d8  8b84248c000000         -mov eax, dword ptr [esp + 0x8c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 004723df  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004723e1  8bb424a8000000         -mov esi, dword ptr [esp + 0xa8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(168) /* 0xa8 */);
    // 004723e8  8a5804                 -mov bl, byte ptr [eax + 4]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004723eb  8b9424a4000000         -mov edx, dword ptr [esp + 0xa4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(164) /* 0xa4 */);
    // 004723f2  01db                   -add ebx, ebx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004723f4  81c600800000           -add esi, 0x8000
    (cpu.esi) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 004723fa  8d43ff                 -lea eax, [ebx - 1]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(-1) /* -0x1 */);
    // 004723fd  8974dc40               -mov dword ptr [esp + ebx*8 + 0x40], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */ + cpu.ebx * 8) = cpu.esi;
    // 00472401  83e007                 -and eax, 7
    cpu.eax &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 00472404  8954dc44               -mov dword ptr [esp + ebx*8 + 0x44], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */ + cpu.ebx * 8) = cpu.edx;
    // 00472408  8b9424a8000000         -mov edx, dword ptr [esp + 0xa8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(168) /* 0xa8 */);
    // 0047240f  8954c440               -mov dword ptr [esp + eax*8 + 0x40], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */ + cpu.eax * 8) = cpu.edx;
    // 00472413  8b9424a4000000         -mov edx, dword ptr [esp + 0xa4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(164) /* 0xa4 */);
    // 0047241a  8b8c24a8000000         -mov ecx, dword ptr [esp + 0xa8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(168) /* 0xa8 */);
    // 00472421  81c200800000           -add edx, 0x8000
    (cpu.edx) += x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 00472427  8bbc249c000000         -mov edi, dword ptr [esp + 0x9c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */);
    // 0047242e  8954c444               -mov dword ptr [esp + eax*8 + 0x44], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */ + cpu.eax * 8) = cpu.edx;
    // 00472432  8b84248c000000         -mov eax, dword ptr [esp + 0x8c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 00472439  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047243b  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0047243d  8a5805                 -mov bl, byte ptr [eax + 5]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */);
    // 00472440  8db90080ffff           -lea edi, [ecx - 0x8000]
    cpu.edi = x86::reg32(cpu.ecx + x86::reg32(-32768) /* -0x8000 */);
    // 00472446  01db                   -add ebx, ebx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00472448  89bc2494000000         -mov dword ptr [esp + 0x94], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */) = cpu.edi;
    // 0047244f  8d43ff                 -lea eax, [ebx - 1]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(-1) /* -0x1 */);
    // 00472452  897cdc40               -mov dword ptr [esp + ebx*8 + 0x40], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */ + cpu.ebx * 8) = cpu.edi;
    // 00472456  8bbc24a4000000         -mov edi, dword ptr [esp + 0xa4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(164) /* 0xa4 */);
    // 0047245d  83e007                 -and eax, 7
    cpu.eax &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 00472460  897cdc44               -mov dword ptr [esp + ebx*8 + 0x44], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */ + cpu.ebx * 8) = cpu.edi;
    // 00472464  894cc440               -mov dword ptr [esp + eax*8 + 0x40], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */ + cpu.eax * 8) = cpu.ecx;
    // 00472468  8954c444               -mov dword ptr [esp + eax*8 + 0x44], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */ + cpu.eax * 8) = cpu.edx;
    // 0047246c  8b84248c000000         -mov eax, dword ptr [esp + 0x8c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 00472473  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00472475  8a5806                 -mov bl, byte ptr [eax + 6]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 00472478  01db                   -add ebx, ebx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0047247a  8b942494000000         -mov edx, dword ptr [esp + 0x94]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */);
    // 00472481  8954dc40               -mov dword ptr [esp + ebx*8 + 0x40], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */ + cpu.ebx * 8) = cpu.edx;
    // 00472485  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00472487  8bbc24a0000000         -mov edi, dword ptr [esp + 0xa0]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(160) /* 0xa0 */);
    // 0047248e  8d43ff                 -lea eax, [ebx - 1]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(-1) /* -0x1 */);
    // 00472491  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00472493  83e007                 -and eax, 7
    cpu.eax &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 00472496  8954dc44               -mov dword ptr [esp + ebx*8 + 0x44], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */ + cpu.ebx * 8) = cpu.edx;
    // 0047249a  894cc440               -mov dword ptr [esp + eax*8 + 0x40], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */ + cpu.eax * 8) = cpu.ecx;
    // 0047249e  8d8a0080ffff           -lea ecx, [edx - 0x8000]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(-32768) /* -0x8000 */);
    // 004724a4  894cc444               -mov dword ptr [esp + eax*8 + 0x44], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */ + cpu.eax * 8) = cpu.ecx;
    // 004724a8  8b84248c000000         -mov eax, dword ptr [esp + 0x8c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 004724af  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004724b1  8a5807                 -mov bl, byte ptr [eax + 7]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(7) /* 0x7 */);
    // 004724b4  01db                   -add ebx, ebx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004724b6  bd08000000             -mov ebp, 8
    cpu.ebp = 8 /*0x8*/;
    // 004724bb  8974dc40               -mov dword ptr [esp + ebx*8 + 0x40], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */ + cpu.ebx * 8) = cpu.esi;
    // 004724bf  8d43ff                 -lea eax, [ebx - 1]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(-1) /* -0x1 */);
    // 004724c2  8954dc44               -mov dword ptr [esp + ebx*8 + 0x44], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */ + cpu.ebx * 8) = cpu.edx;
    // 004724c6  83e007                 -and eax, 7
    cpu.eax &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004724c9  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004724cb  8b9424a8000000         -mov edx, dword ptr [esp + 0xa8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(168) /* 0xa8 */);
    // 004724d2  899c24bc000000         -mov dword ptr [esp + 0xbc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(188) /* 0xbc */) = cpu.ebx;
    // 004724d9  8954c440               -mov dword ptr [esp + eax*8 + 0x40], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */ + cpu.eax * 8) = cpu.edx;
    // 004724dd  899c24b8000000         -mov dword ptr [esp + 0xb8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */) = cpu.ebx;
    // 004724e4  894cc444               -mov dword ptr [esp + eax*8 + 0x44], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */ + cpu.eax * 8) = cpu.ecx;
    // 004724e8  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004724ed  8b8c24b0000000         -mov ecx, dword ptr [esp + 0xb0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(176) /* 0xb0 */);
    // 004724f4  89942490000000         -mov dword ptr [esp + 0x90], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(144) /* 0x90 */) = cpu.edx;
L_0x004724fb:
    // 004724fb  8d4301                 -lea eax, [ebx + 1]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004724fe  83e003                 -and eax, 3
    cpu.eax &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 00472501  8bbc24b0000000         -mov edi, dword ptr [esp + 0xb0]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(176) /* 0xb0 */);
    // 00472508  898424b4000000         -mov dword ptr [esp + 0xb4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(180) /* 0xb4 */) = cpu.eax;
    // 0047250f  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00472512  8b9424ac000000         -mov edx, dword ptr [esp + 0xac]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(172) /* 0xac */);
    // 00472519  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 0047251b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047251d  0f8c6b010000           -jl 0x47268e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047268e;
    }
    // 00472523  8b38                   -mov edi, dword ptr [eax]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax);
    // 00472525  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
L_0x00472527:
    // 00472527  8b5710                 -mov edx, dword ptr [edi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 0047252a  8b7010                 -mov esi, dword ptr [eax + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0047252d  8b4014                 -mov eax, dword ptr [eax + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 00472530  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00472532  2b4714                 +sub eax, dword ptr [edi + 0x14]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00472535  7405                   -je 0x47253c
    if (cpu.flags.zf)
    {
        goto L_0x0047253c;
    }
    // 00472537  c1f81e                 -sar eax, 0x1e
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (30 /*0x1e*/ % 32));
    // 0047253a  0c01                   -or al, 1
    cpu.al |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x0047253c:
    // 0047253c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047253e  7406                   -je 0x472546
    if (cpu.flags.zf)
    {
        goto L_0x00472546;
    }
    // 00472540  c1fa1e                 -sar edx, 0x1e
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (30 /*0x1e*/ % 32));
    // 00472543  80ca01                 -or dl, 1
    cpu.dl |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x00472546:
    // 00472546  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00472548  09d6                   +or esi, edx
    cpu.clear_co();
    cpu.set_szp((cpu.esi |= x86::reg32(x86::sreg32(cpu.edx))));
    // 0047254a  0f8447010000           -je 0x472697
    if (cpu.flags.zf)
    {
        goto L_0x00472697;
    }
    // 00472550  8b31                   -mov esi, dword ptr [ecx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx);
    // 00472552  8b7610                 -mov esi, dword ptr [esi + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00472555  8bbc24b8000000         -mov edi, dword ptr [esp + 0xb8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 0047255c  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047255e  89343c                 -mov dword ptr [esp + edi], esi
    app->getMemory<x86::reg32>(cpu.esp + cpu.edi * 1) = cpu.esi;
    // 00472561  8b31                   -mov esi, dword ptr [ecx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx);
    // 00472563  8b7614                 -mov esi, dword ptr [esi + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00472566  01d6                   -add esi, edx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edx));
    // 00472568  89743c04               -mov dword ptr [esp + edi + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */ + cpu.edi * 1) = cpu.esi;
    // 0047256c  8bb424b4000000         -mov esi, dword ptr [esp + 0xb4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(180) /* 0xb4 */);
    // 00472573  8bbc24b0000000         -mov edi, dword ptr [esp + 0xb0]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(176) /* 0xb0 */);
    // 0047257a  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 0047257d  01f7                   -add edi, esi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.esi));
    // 0047257f  8b37                   -mov esi, dword ptr [edi]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi);
    // 00472581  8b7610                 -mov esi, dword ptr [esi + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00472584  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00472586  8b842490000000         -mov eax, dword ptr [esp + 0x90]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(144) /* 0x90 */);
    // 0047258d  83e007                 -and eax, 7
    cpu.eax &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 00472590  8934c4                 -mov dword ptr [esp + eax*8], esi
    app->getMemory<x86::reg32>(cpu.esp + cpu.eax * 8) = cpu.esi;
    // 00472593  8b37                   -mov esi, dword ptr [edi]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi);
    // 00472595  8b7e14                 -mov edi, dword ptr [esi + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00472598  8bb424bc000000         -mov esi, dword ptr [esp + 0xbc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(188) /* 0xbc */);
    // 0047259f  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004725a1  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004725a4  8954c404               -mov dword ptr [esp + eax*8 + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */ + cpu.eax * 8) = cpu.edx;
    // 004725a8  8b842490000000         -mov eax, dword ptr [esp + 0x90]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(144) /* 0x90 */);
    // 004725af  8b9424b8000000         -mov edx, dword ptr [esp + 0xb8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */);
    // 004725b6  89b424bc000000         -mov dword ptr [esp + 0xbc], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(188) /* 0xbc */) = cpu.esi;
    // 004725bd  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004725c0  83c210                 -add edx, 0x10
    (cpu.edx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004725c3  89842490000000         -mov dword ptr [esp + 0x90], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(144) /* 0x90 */) = cpu.eax;
    // 004725ca  899424b8000000         -mov dword ptr [esp + 0xb8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(184) /* 0xb8 */) = cpu.edx;
L_0x004725d1:
    // 004725d1  43                     -inc ebx
    (cpu.ebx)++;
    // 004725d2  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004725d5  83fb04                 +cmp ebx, 4
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
    // 004725d8  0f8c1dffffff           -jl 0x4724fb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004724fb;
    }
L_0x004725de:
    // 004725de  8b3d7cb75100           -mov edi, dword ptr [0x51b77c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5355388) /* 0x51b77c */);
    // 004725e4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004725e5  8b8424b0000000         -mov eax, dword ptr [esp + 0xb0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(176) /* 0xb0 */);
    // 004725ec  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004725f0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004725f1  8b842494000000         -mov eax, dword ptr [esp + 0x94]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */);
    // 004725f8  8d5c2448               -lea ebx, [esp + 0x48]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 004725fc  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004725fe  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00472600  e817030200             -call 0x49291c
    cpu.esp -= 4;
    sub_49291c(app, cpu);
    if (cpu.terminate) return;
    // 00472605  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00472607  0f8c90010000           -jl 0x47279d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047279d;
    }
    // 0047260d  81c4c0000000           -add esp, 0xc0
    (cpu.esp) += x86::reg32(x86::sreg32(192 /*0xc0*/));
    // 00472613  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472614  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472615  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472616  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472617  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00472618:
    // 00472618  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0047261a  89842480000000         -mov dword ptr [esp + 0x80], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */) = cpu.eax;
    // 00472621  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00472623  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00472626  ba00800000             -mov edx, 0x8000
    cpu.edx = 32768 /*0x8000*/;
    // 0047262b  89842484000000         -mov dword ptr [esp + 0x84], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */) = cpu.eax;
    // 00472632  89942488000000         -mov dword ptr [esp + 0x88], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */) = cpu.edx;
    // 00472639  8b39                   -mov edi, dword ptr [ecx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx);
    // 0047263b  8db42480000000         -lea esi, [esp + 0x80]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 00472642  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00472645  837e0800               +cmp dword ptr [esi + 8], 0
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
    // 00472649  7e2a                   -jle 0x472675
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00472675;
    }
    // 0047264b  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0047264d  f72d78a44c00           -imul dword ptr [0x4ca478]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5022840) /* 0x4ca478 */))));
    // 00472653  f77e08                 -idiv dword ptr [esi + 8]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00472656  030570a44c00           -add eax, dword ptr [0x4ca470]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5022832) /* 0x4ca470 */)));
    // 0047265c  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 0047265e  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00472661  f72d7ca44c00           -imul dword ptr [0x4ca47c]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5022844) /* 0x4ca47c */))));
    // 00472667  f77e08                 -idiv dword ptr [esi + 8]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0047266a  030574a44c00           +add eax, dword ptr [0x4ca474]
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
    // 00472670  894704                 -mov dword ptr [edi + 4], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00472673  eb14                   -jmp 0x472689
    goto L_0x00472689;
L_0x00472675:
    // 00472675  c70700000080           -mov dword ptr [edi], 0x80000000
    app->getMemory<x86::reg32>(cpu.edi) = 2147483648 /*0x80000000*/;
    // 0047267b  c7470400000080         -mov dword ptr [edi + 4], 0x80000000
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = 2147483648 /*0x80000000*/;
    // 00472682  830d80a44c0001         +or dword ptr [0x4ca480], 1
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg32>(x86::reg32(5022848) /* 0x4ca480 */) |= x86::reg32(x86::sreg32(1 /*0x1*/))));
L_0x00472689:
    // 00472689  e92efcffff             -jmp 0x4722bc
    goto L_0x004722bc;
L_0x0047268e:
    // 0047268e  8b39                   -mov edi, dword ptr [ecx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx);
    // 00472690  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00472692  e990feffff             -jmp 0x472527
    goto L_0x00472527;
L_0x00472697:
    // 00472697  8bbc24bc000000         -mov edi, dword ptr [esp + 0xbc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(188) /* 0xbc */);
    // 0047269e  83ed02                 -sub ebp, 2
    (cpu.ebp) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004726a1  39fd                   +cmp ebp, edi
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
    // 004726a3  0f8e28ffffff           -jle 0x4725d1
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004725d1;
    }
    // 004726a9  8d14ed00000000         -lea edx, [ebp*8]
    cpu.edx = x86::reg32(cpu.ebp * 8);
    // 004726b0  8d04fd00000000         -lea eax, [edi*8]
    cpu.eax = x86::reg32(cpu.edi * 8);
L_0x004726b7:
    // 004726b7  8d7c0440               -lea edi, [esp + eax + 0x40]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */ + cpu.eax * 1);
    // 004726bb  8d740450               -lea esi, [esp + eax + 0x50]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(80) /* 0x50 */ + cpu.eax * 1);
    // 004726bf  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004726c2  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004726c3  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004726c4  39d0                   +cmp eax, edx
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
    // 004726c6  0f8d05ffffff           -jge 0x4725d1
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004725d1;
    }
    // 004726cc  ebe9                   -jmp 0x4726b7
    goto L_0x004726b7;
L_0x004726ce:
    // 004726ce  8b8c24b0000000         -mov ecx, dword ptr [esp + 0xb0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(176) /* 0xb0 */);
    // 004726d5  bd04000000             -mov ebp, 4
    cpu.ebp = 4 /*0x4*/;
    // 004726da  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004726dc:
    // 004726dc  8b31                   -mov esi, dword ptr [ecx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx);
    // 004726de  8d3c1c                 -lea edi, [esp + ebx]
    cpu.edi = x86::reg32(cpu.esp + cpu.ebx * 1);
    // 004726e1  8d7610                 -lea esi, [esi + 0x10]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004726e4  83c308                 -add ebx, 8
    (cpu.ebx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004726e7  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004726ea  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004726eb  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004726ec  83fb20                 +cmp ebx, 0x20
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004726ef  75eb                   -jne 0x4726dc
    if (!cpu.flags.zf)
    {
        goto L_0x004726dc;
    }
    // 004726f1  8b94248c000000         -mov edx, dword ptr [esp + 0x8c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 004726f8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004726fa  8a4204                 -mov al, byte ptr [edx + 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004726fd  8b9424a8000000         -mov edx, dword ptr [esp + 0xa8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(168) /* 0xa8 */);
    // 00472704  8954c440               -mov dword ptr [esp + eax*8 + 0x40], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */ + cpu.eax * 8) = cpu.edx;
    // 00472708  8b94248c000000         -mov edx, dword ptr [esp + 0x8c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 0047270f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00472711  8b9c249c000000         -mov ebx, dword ptr [esp + 0x9c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */);
    // 00472718  8a4204                 -mov al, byte ptr [edx + 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0047271b  8b9424a4000000         -mov edx, dword ptr [esp + 0xa4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(164) /* 0xa4 */);
    // 00472722  8b8c248c000000         -mov ecx, dword ptr [esp + 0x8c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 00472729  8954c444               -mov dword ptr [esp + eax*8 + 0x44], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */ + cpu.eax * 8) = cpu.edx;
    // 0047272d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047272f  8b8424a8000000         -mov eax, dword ptr [esp + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(168) /* 0xa8 */);
    // 00472736  8a5105                 -mov dl, byte ptr [ecx + 5]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5) /* 0x5 */);
    // 00472739  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0047273b  8944d440               -mov dword ptr [esp + edx*8 + 0x40], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */ + cpu.edx * 8) = cpu.eax;
    // 0047273f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00472741  8a5105                 -mov dl, byte ptr [ecx + 5]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5) /* 0x5 */);
    // 00472744  8b8c24a4000000         -mov ecx, dword ptr [esp + 0xa4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(164) /* 0xa4 */);
    // 0047274b  894cd444               -mov dword ptr [esp + edx*8 + 0x44], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */ + cpu.edx * 8) = cpu.ecx;
    // 0047274f  8b8c248c000000         -mov ecx, dword ptr [esp + 0x8c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 00472756  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00472758  8a5106                 -mov dl, byte ptr [ecx + 6]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(6) /* 0x6 */);
    // 0047275b  8bb424a0000000         -mov esi, dword ptr [esp + 0xa0]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(160) /* 0xa0 */);
    // 00472762  8944d440               -mov dword ptr [esp + edx*8 + 0x40], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */ + cpu.edx * 8) = cpu.eax;
    // 00472766  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00472768  8b8424a4000000         -mov eax, dword ptr [esp + 0xa4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(164) /* 0xa4 */);
    // 0047276f  8a5106                 -mov dl, byte ptr [ecx + 6]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(6) /* 0x6 */);
    // 00472772  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00472774  8944d444               -mov dword ptr [esp + edx*8 + 0x44], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */ + cpu.edx * 8) = cpu.eax;
    // 00472778  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047277a  8a5107                 -mov dl, byte ptr [ecx + 7]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(7) /* 0x7 */);
    // 0047277d  8b8c24a8000000         -mov ecx, dword ptr [esp + 0xa8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(168) /* 0xa8 */);
    // 00472784  894cd440               -mov dword ptr [esp + edx*8 + 0x40], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */ + cpu.edx * 8) = cpu.ecx;
    // 00472788  8b8c248c000000         -mov ecx, dword ptr [esp + 0x8c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 0047278f  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00472791  8a5107                 -mov dl, byte ptr [ecx + 7]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(7) /* 0x7 */);
    // 00472794  8944d444               -mov dword ptr [esp + edx*8 + 0x44], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */ + cpu.edx * 8) = cpu.eax;
    // 00472798  e941feffff             -jmp 0x4725de
    goto L_0x004725de;
L_0x0047279d:
    // 0047279d  8b9424b0000000         -mov edx, dword ptr [esp + 0xb0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(176) /* 0xb0 */);
    // 004727a4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004727a6:
    // 004727a6  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 004727a8  8d3c04                 -lea edi, [esp + eax]
    cpu.edi = x86::reg32(cpu.esp + cpu.eax * 1);
    // 004727ab  8d7610                 -lea esi, [esi + 0x10]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004727ae  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004727b1  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004727b4  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004727b5  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004727b6  83f820                 +cmp eax, 0x20
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
    // 004727b9  75eb                   -jne 0x4727a6
    if (!cpu.flags.zf)
    {
        goto L_0x004727a6;
    }
    // 004727bb  8b94248c000000         -mov edx, dword ptr [esp + 0x8c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 004727c2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004727c4  8a4204                 -mov al, byte ptr [edx + 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004727c7  8b9424a8000000         -mov edx, dword ptr [esp + 0xa8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(168) /* 0xa8 */);
    // 004727ce  8954c440               -mov dword ptr [esp + eax*8 + 0x40], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */ + cpu.eax * 8) = cpu.edx;
    // 004727d2  8b94248c000000         -mov edx, dword ptr [esp + 0x8c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 004727d9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004727db  8a4204                 -mov al, byte ptr [edx + 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004727de  8b9424a4000000         -mov edx, dword ptr [esp + 0xa4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(164) /* 0xa4 */);
    // 004727e5  8954c444               -mov dword ptr [esp + eax*8 + 0x44], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */ + cpu.eax * 8) = cpu.edx;
    // 004727e9  8b8424a8000000         -mov eax, dword ptr [esp + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(168) /* 0xa8 */);
    // 004727f0  8b94249c000000         -mov edx, dword ptr [esp + 0x9c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */);
    // 004727f7  8b8c248c000000         -mov ecx, dword ptr [esp + 0x8c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 004727fe  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00472800  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00472802  8a5105                 -mov dl, byte ptr [ecx + 5]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5) /* 0x5 */);
    // 00472805  8944d440               -mov dword ptr [esp + edx*8 + 0x40], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */ + cpu.edx * 8) = cpu.eax;
    // 00472809  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047280b  8a5105                 -mov dl, byte ptr [ecx + 5]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5) /* 0x5 */);
    // 0047280e  8b8c24a4000000         -mov ecx, dword ptr [esp + 0xa4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(164) /* 0xa4 */);
    // 00472815  894cd444               -mov dword ptr [esp + edx*8 + 0x44], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */ + cpu.edx * 8) = cpu.ecx;
    // 00472819  8b8c248c000000         -mov ecx, dword ptr [esp + 0x8c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 00472820  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00472822  8a5106                 -mov dl, byte ptr [ecx + 6]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(6) /* 0x6 */);
    // 00472825  8b8c24a0000000         -mov ecx, dword ptr [esp + 0xa0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(160) /* 0xa0 */);
    // 0047282c  8944d440               -mov dword ptr [esp + edx*8 + 0x40], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */ + cpu.edx * 8) = cpu.eax;
    // 00472830  8b8424a4000000         -mov eax, dword ptr [esp + 0xa4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(164) /* 0xa4 */);
    // 00472837  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00472839  8b8c248c000000         -mov ecx, dword ptr [esp + 0x8c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 00472840  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00472842  8a5106                 -mov dl, byte ptr [ecx + 6]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(6) /* 0x6 */);
    // 00472845  8d7c2420               -lea edi, [esp + 0x20]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00472849  8944d444               -mov dword ptr [esp + edx*8 + 0x44], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */ + cpu.edx * 8) = cpu.eax;
    // 0047284d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047284f  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00472851  8a5107                 -mov dl, byte ptr [ecx + 7]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(7) /* 0x7 */);
    // 00472854  8b8c24a8000000         -mov ecx, dword ptr [esp + 0xa8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(168) /* 0xa8 */);
    // 0047285b  8b1d7cb75100           -mov ebx, dword ptr [0x51b77c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5355388) /* 0x51b77c */);
    // 00472861  894cd440               -mov dword ptr [esp + edx*8 + 0x40], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */ + cpu.edx * 8) = cpu.ecx;
    // 00472865  8b8c248c000000         -mov ecx, dword ptr [esp + 0x8c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 0047286c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047286e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047286f  8a5107                 -mov dl, byte ptr [ecx + 7]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(7) /* 0x7 */);
    // 00472872  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00472873  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00472874  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00472876  8d7c2468               -lea edi, [esp + 0x68]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 0047287a  8d742448               -lea esi, [esp + 0x48]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0047287e  8944d44c               -mov dword ptr [esp + edx*8 + 0x4c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */ + cpu.edx * 8) = cpu.eax;
    // 00472882  8d5c2448               -lea ebx, [esp + 0x48]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 00472886  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00472887  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00472888  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 0047288d  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0047288f  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00472893  e884000200             -call 0x49291c
    cpu.esp -= 4;
    sub_49291c(app, cpu);
    if (cpu.terminate) return;
    // 00472898  8b357cb75100           -mov esi, dword ptr [0x51b77c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5355388) /* 0x51b77c */);
    // 0047289e  8b84248c000000         -mov eax, dword ptr [esp + 0x8c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 004728a5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004728a6  8d4c2414               -lea ecx, [esp + 0x14]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004728aa  8d5c2454               -lea ebx, [esp + 0x54]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 004728ae  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004728b0  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 004728b5  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004728b7  e860000200             -call 0x49291c
    cpu.esp -= 4;
    sub_49291c(app, cpu);
    if (cpu.terminate) return;
    // 004728bc  81c4c0000000           -add esp, 0xc0
    (cpu.esp) += x86::reg32(x86::sreg32(192 /*0xc0*/));
    // 004728c2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004728c3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004728c4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004728c5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004728c6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4728d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004728d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004728d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004728d2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004728d3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004728d4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004728d5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004728d6  81ec60130000           -sub esp, 0x1360
    (cpu.esp) -= x86::reg32(x86::sreg32(4960 /*0x1360*/));
    // 004728dc  8b3568b75100           -mov esi, dword ptr [0x51b768]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5355368) /* 0x51b768 */);
    // 004728e2  8a25a1a74c00           -mov ah, byte ptr [0x4ca7a1]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5023649) /* 0x4ca7a1 */);
    // 004728e8  bfffffffff             -mov edi, 0xffffffff
    cpu.edi = 4294967295 /*0xffffffff*/;
    // 004728ed  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 004728ef  0f8484000000           -je 0x472979
    if (cpu.flags.zf)
    {
        goto L_0x00472979;
    }
    // 004728f5  bd50000000             -mov ebp, 0x50
    cpu.ebp = 80 /*0x50*/;
    // 004728fa  bb2c010000             -mov ebx, 0x12c
    cpu.ebx = 300 /*0x12c*/;
    // 004728ff  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 00472901  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00472903  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00472905  8815c0b75100           -mov byte ptr [0x51b7c0], dl
    app->getMemory<x86::reg8>(x86::reg32(5355456) /* 0x51b7c0 */) = cpu.dl;
    // 0047290b  8815c1b75100           -mov byte ptr [0x51b7c1], dl
    app->getMemory<x86::reg8>(x86::reg32(5355457) /* 0x51b7c1 */) = cpu.dl;
    // 00472911  8815c2b75100           -mov byte ptr [0x51b7c2], dl
    app->getMemory<x86::reg8>(x86::reg32(5355458) /* 0x51b7c2 */) = cpu.dl;
    // 00472917  890de4b65100           -mov dword ptr [0x51b6e4], ecx
    app->getMemory<x86::reg32>(x86::reg32(5355236) /* 0x51b6e4 */) = cpu.ecx;
    // 0047291d  890dd4b65100           -mov dword ptr [0x51b6d4], ecx
    app->getMemory<x86::reg32>(x86::reg32(5355220) /* 0x51b6d4 */) = cpu.ecx;
    // 00472923  892de8b65100           -mov dword ptr [0x51b6e8], ebp
    app->getMemory<x86::reg32>(x86::reg32(5355240) /* 0x51b6e8 */) = cpu.ebp;
    // 00472929  890dd8b65100           -mov dword ptr [0x51b6d8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5355224) /* 0x51b6d8 */) = cpu.ecx;
    // 0047292f  891df0b65100           -mov dword ptr [0x51b6f0], ebx
    app->getMemory<x86::reg32>(x86::reg32(5355248) /* 0x51b6f0 */) = cpu.ebx;
    // 00472935  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0047293a  b90c000000             -mov ecx, 0xc
    cpu.ecx = 12 /*0xc*/;
    // 0047293f  bd0f000000             -mov ebp, 0xf
    cpu.ebp = 15 /*0xf*/;
    // 00472944  8915bcb75100           -mov dword ptr [0x51b7bc], edx
    app->getMemory<x86::reg32>(x86::reg32(5355452) /* 0x51b7bc */) = cpu.edx;
    // 0047294a  890ddcb65100           -mov dword ptr [0x51b6dc], ecx
    app->getMemory<x86::reg32>(x86::reg32(5355228) /* 0x51b6dc */) = cpu.ecx;
    // 00472950  ba55000000             -mov edx, 0x55
    cpu.edx = 85 /*0x55*/;
    // 00472955  b90a000000             -mov ecx, 0xa
    cpu.ecx = 10 /*0xa*/;
    // 0047295a  8915ecb65100           -mov dword ptr [0x51b6ec], edx
    app->getMemory<x86::reg32>(x86::reg32(5355244) /* 0x51b6ec */) = cpu.edx;
    // 00472960  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00472962  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00472964  892de0b65100           -mov dword ptr [0x51b6e0], ebp
    app->getMemory<x86::reg32>(x86::reg32(5355232) /* 0x51b6e0 */) = cpu.ebp;
    // 0047296a  e8a186ffff             -call 0x46b010
    cpu.esp -= 4;
    sub_46b010(app, cpu);
    if (cpu.terminate) return;
    // 0047296f  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00472974  e8c726fcff             -call 0x435040
    cpu.esp -= 4;
    sub_435040(app, cpu);
    if (cpu.terminate) return;
L_0x00472979:
    // 00472979  a1e0b65100             -mov eax, dword ptr [0x51b6e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5355232) /* 0x51b6e0 */);
    // 0047297e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047297f  8b15f0b65100           -mov edx, dword ptr [0x51b6f0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5355248) /* 0x51b6f0 */);
    // 00472985  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00472986  8b0ddcb65100           -mov ecx, dword ptr [0x51b6dc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5355228) /* 0x51b6dc */);
    // 0047298c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047298d  8b1decb65100           -mov ebx, dword ptr [0x51b6ec]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5355244) /* 0x51b6ec */);
    // 00472993  8b35d8b65100           -mov esi, dword ptr [0x51b6d8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5355224) /* 0x51b6d8 */);
    // 00472999  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047299a  8d442410               -lea eax, [esp + 0x10]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0047299e  8b15e4b65100           -mov edx, dword ptr [0x51b6e4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5355236) /* 0x51b6e4 */);
    // 004729a4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004729a5  8b0de8b65100           -mov ecx, dword ptr [0x51b6e8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5355240) /* 0x51b6e8 */);
    // 004729ab  8b1dd4b65100           -mov ebx, dword ptr [0x51b6d4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5355220) /* 0x51b6d4 */);
    // 004729b1  e88aaefeff             -call 0x45d840
    cpu.esp -= 4;
    sub_45d840(app, cpu);
    if (cpu.terminate) return;
    // 004729b6  8b15f0b65100           -mov edx, dword ptr [0x51b6f0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5355248) /* 0x51b6f0 */);
    // 004729bc  8b2de4b65100           -mov ebp, dword ptr [0x51b6e4]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5355236) /* 0x51b6e4 */);
    // 004729c2  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004729c4  39ea                   +cmp edx, ebp
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
    // 004729c6  7c34                   -jl 0x4729fc
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004729fc;
    }
    // 004729c8  8b0de4b65100           -mov ecx, dword ptr [0x51b6e4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5355236) /* 0x51b6e4 */);
    // 004729ce  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
L_0x004729d5:
    // 004729d5  8b1c04                 -mov ebx, dword ptr [esp + eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + cpu.eax * 1);
    // 004729d8  39df                   +cmp edi, ebx
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004729da  7418                   -je 0x4729f4
    if (cpu.flags.zf)
    {
        goto L_0x004729f4;
    }
    // 004729dc  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004729de  83fe10                 +cmp esi, 0x10
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
    // 004729e1  7d11                   -jge 0x4729f4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004729f4;
    }
    // 004729e3  46                     -inc esi
    (cpu.esi)++;
    // 004729e4  8a1c04                 -mov bl, byte ptr [esp + eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + cpu.eax * 1);
    // 004729e7  8914b500b75100         -mov dword ptr [esi*4 + 0x51b700], edx
    app->getMemory<x86::reg32>(x86::reg32(5355264) /* 0x51b700 */ + cpu.esi * 4) = cpu.edx;
    // 004729ee  889ef3b65100           -mov byte ptr [esi + 0x51b6f3], bl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5355251) /* 0x51b6f3 */) = cpu.bl;
L_0x004729f4:
    // 004729f4  4a                     -dec edx
    (cpu.edx)--;
    // 004729f5  83e804                 -sub eax, 4
    (cpu.eax) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004729f8  39ca                   +cmp edx, ecx
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
    // 004729fa  7dd9                   -jge 0x4729d5
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004729d5;
    }
L_0x004729fc:
    // 004729fc  c70504b75100d7040000   -mov dword ptr [0x51b704], 0x4d7
    app->getMemory<x86::reg32>(x86::reg32(5355268) /* 0x51b704 */) = 1239 /*0x4d7*/;
    // 00472a06  893568b75100           -mov dword ptr [0x51b768], esi
    app->getMemory<x86::reg32>(x86::reg32(5355368) /* 0x51b768 */) = cpu.esi;
    // 00472a0c  81c460130000           -add esp, 0x1360
    (cpu.esp) += x86::reg32(x86::sreg32(4960 /*0x1360*/));
    // 00472a12  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472a13  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472a14  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472a15  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472a16  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472a17  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472a18  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_472a20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00472a20  891485d4b65100         -mov dword ptr [eax*4 + 0x51b6d4], edx
    app->getMemory<x86::reg32>(x86::reg32(5355220) /* 0x51b6d4 */ + cpu.eax * 4) = cpu.edx;
    // 00472a27  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_472a30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00472a30  891485e4b65100         -mov dword ptr [eax*4 + 0x51b6e4], edx
    app->getMemory<x86::reg32>(x86::reg32(5355236) /* 0x51b6e4 */ + cpu.eax * 4) = cpu.edx;
    // 00472a37  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_472a40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00472a40  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_472a50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00472a50  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
/* data blob: 00000000000000000000000000000000 */
void Application::sub_472a70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00472a70  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00472a71  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00472a72  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00472a73  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00472a74  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00472a75  81ec88020000           -sub esp, 0x288
    (cpu.esp) -= x86::reg32(x86::sreg32(648 /*0x288*/));
    // 00472a7b  89b42474020000         -mov dword ptr [esp + 0x274], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(628) /* 0x274 */) = cpu.esi;
    // 00472a82  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00472a84  e8a7070000             -call 0x473230
    cpu.esp -= 4;
    sub_473230(app, cpu);
    if (cpu.terminate) return;
    // 00472a89  e8c29dfeff             -call 0x45c850
    cpu.esp -= 4;
    sub_45c850(app, cpu);
    if (cpu.terminate) return;
    // 00472a8e  833f01                 +cmp dword ptr [edi], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00472a91  0f8401010000           -je 0x472b98
    if (cpu.flags.zf)
    {
        goto L_0x00472b98;
    }
L_0x00472a97:
    // 00472a97  833d6cb8510000         +cmp dword ptr [0x51b86c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5355628) /* 0x51b86c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00472a9e  750d                   -jne 0x472aad
    if (!cpu.flags.zf)
    {
        goto L_0x00472aad;
    }
    // 00472aa0  833dbcb7510000         +cmp dword ptr [0x51b7bc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5355452) /* 0x51b7bc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00472aa7  0f84c9010000           -je 0x472c76
    if (cpu.flags.zf)
    {
        goto L_0x00472c76;
    }
L_0x00472aad:
    // 00472aad  ba2c000000             -mov edx, 0x2c
    cpu.edx = 44 /*0x2c*/;
    // 00472ab2  8d84245c020000         -lea eax, [esp + 0x25c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(604) /* 0x25c */);
    // 00472ab9  e8429dfeff             -call 0x45c800
    cpu.esp -= 4;
    sub_45c800(app, cpu);
    if (cpu.terminate) return;
    // 00472abe  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00472ac0  0f84a3000000           -je 0x472b69
    if (cpu.flags.zf)
    {
        goto L_0x00472b69;
    }
    // 00472ac6  833dbcb7510000         +cmp dword ptr [0x51b7bc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5355452) /* 0x51b7bc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00472acd  0f848d010000           -je 0x472c60
    if (cpu.flags.zf)
    {
        goto L_0x00472c60;
    }
    // 00472ad3  b90b000000             -mov ecx, 0xb
    cpu.ecx = 11 /*0xb*/;
    // 00472ad8  8bbc245c020000         -mov edi, dword ptr [esp + 0x25c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(604) /* 0x25c */);
    // 00472adf  be20b85100             -mov esi, 0x51b820
    cpu.esi = 5355552 /*0x51b820*/;
L_0x00472ae4:
    // 00472ae4  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00472ae6  8b84245c020000         -mov eax, dword ptr [esp + 0x25c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(604) /* 0x25c */);
    // 00472aed  c6402901               -mov byte ptr [eax + 0x29], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(41) /* 0x29 */) = 1 /*0x1*/;
    // 00472af1  8b94245c020000         -mov edx, dword ptr [esp + 0x25c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(604) /* 0x25c */);
    // 00472af8  a1ccfa4d00             -mov eax, dword ptr [0x4dfacc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5110476) /* 0x4dfacc */);
    // 00472afd  894208                 -mov dword ptr [edx + 8], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00472b00  8b94245c020000         -mov edx, dword ptr [esp + 0x25c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(604) /* 0x25c */);
    // 00472b07  a1d8fa4d00             -mov eax, dword ptr [0x4dfad8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5110488) /* 0x4dfad8 */);
    // 00472b0c  89420c                 -mov dword ptr [edx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00472b0f  8b94245c020000         -mov edx, dword ptr [esp + 0x25c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(604) /* 0x25c */);
    // 00472b16  a1c8fa4d00             -mov eax, dword ptr [0x4dfac8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5110472) /* 0x4dfac8 */);
    // 00472b1b  894210                 -mov dword ptr [edx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00472b1e  8b94245c020000         -mov edx, dword ptr [esp + 0x25c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(604) /* 0x25c */);
    // 00472b25  a1d8fa4d00             -mov eax, dword ptr [0x4dfad8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5110488) /* 0x4dfad8 */);
    // 00472b2a  894214                 -mov dword ptr [edx + 0x14], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00472b2d  8b94245c020000         -mov edx, dword ptr [esp + 0x25c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(604) /* 0x25c */);
    // 00472b34  a1c8fa4d00             -mov eax, dword ptr [0x4dfac8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5110472) /* 0x4dfac8 */);
    // 00472b39  894218                 -mov dword ptr [edx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00472b3c  8b94245c020000         -mov edx, dword ptr [esp + 0x25c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(604) /* 0x25c */);
    // 00472b43  a1d0fa4d00             -mov eax, dword ptr [0x4dfad0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5110480) /* 0x4dfad0 */);
    // 00472b48  89421c                 -mov dword ptr [edx + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00472b4b  8b94245c020000         -mov edx, dword ptr [esp + 0x25c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(604) /* 0x25c */);
    // 00472b52  a1ccfa4d00             -mov eax, dword ptr [0x4dfacc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5110476) /* 0x4dfacc */);
    // 00472b57  894220                 -mov dword ptr [edx + 0x20], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 00472b5a  8b94245c020000         -mov edx, dword ptr [esp + 0x25c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(604) /* 0x25c */);
    // 00472b61  a1d0fa4d00             -mov eax, dword ptr [0x4dfad0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5110480) /* 0x4dfad0 */);
    // 00472b66  894224                 -mov dword ptr [edx + 0x24], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */) = cpu.eax;
L_0x00472b69:
    // 00472b69  8db42450020000         -lea esi, [esp + 0x250]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(592) /* 0x250 */);
    // 00472b70  e84b9cfeff             -call 0x45c7c0
    cpu.esp -= 4;
    sub_45c7c0(app, cpu);
    if (cpu.terminate) return;
    // 00472b75  8bbc2474020000         -mov edi, dword ptr [esp + 0x274]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(628) /* 0x274 */);
    // 00472b7c  8db42450020000         -lea esi, [esp + 0x250]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(592) /* 0x250 */);
    // 00472b83  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00472b84  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00472b85  8b842474020000         -mov eax, dword ptr [esp + 0x274]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(628) /* 0x274 */);
    // 00472b8c  81c488020000           -add esp, 0x288
    (cpu.esp) += x86::reg32(x86::sreg32(648 /*0x288*/));
    // 00472b92  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472b93  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472b94  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472b95  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472b96  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472b97  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00472b98:
    // 00472b98  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00472b9b  e8e054fcff             -call 0x438080
    cpu.esp -= 4;
    sub_438080(app, cpu);
    if (cpu.terminate) return;
    // 00472ba0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00472ba2  0f84effeffff           -je 0x472a97
    if (cpu.flags.zf)
    {
        goto L_0x00472a97;
    }
    // 00472ba8  ba2c000000             -mov edx, 0x2c
    cpu.edx = 44 /*0x2c*/;
    // 00472bad  8d84245c020000         -lea eax, [esp + 0x25c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(604) /* 0x25c */);
    // 00472bb4  e8479cfeff             -call 0x45c800
    cpu.esp -= 4;
    sub_45c800(app, cpu);
    if (cpu.terminate) return;
    // 00472bb9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00472bbb  74ac                   -je 0x472b69
    if (cpu.flags.zf)
    {
        goto L_0x00472b69;
    }
    // 00472bbd  b90b000000             -mov ecx, 0xb
    cpu.ecx = 11 /*0xb*/;
    // 00472bc2  8bbc245c020000         -mov edi, dword ptr [esp + 0x25c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(604) /* 0x25c */);
    // 00472bc9  be20b85100             -mov esi, 0x51b820
    cpu.esi = 5355552 /*0x51b820*/;
    // 00472bce  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00472bd0  8b84245c020000         -mov eax, dword ptr [esp + 0x25c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(604) /* 0x25c */);
    // 00472bd7  c6402901               -mov byte ptr [eax + 0x29], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(41) /* 0x29 */) = 1 /*0x1*/;
    // 00472bdb  8b84245c020000         -mov eax, dword ptr [esp + 0x25c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(604) /* 0x25c */);
    // 00472be2  8b15ccfa4d00           -mov edx, dword ptr [0x4dfacc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5110476) /* 0x4dfacc */);
    // 00472be8  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00472beb  8b84245c020000         -mov eax, dword ptr [esp + 0x25c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(604) /* 0x25c */);
    // 00472bf2  8b15d8fa4d00           -mov edx, dword ptr [0x4dfad8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5110488) /* 0x4dfad8 */);
    // 00472bf8  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00472bfb  8b84245c020000         -mov eax, dword ptr [esp + 0x25c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(604) /* 0x25c */);
    // 00472c02  8b15c8fa4d00           -mov edx, dword ptr [0x4dfac8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5110472) /* 0x4dfac8 */);
    // 00472c08  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 00472c0b  8b84245c020000         -mov eax, dword ptr [esp + 0x25c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(604) /* 0x25c */);
    // 00472c12  8b15d8fa4d00           -mov edx, dword ptr [0x4dfad8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5110488) /* 0x4dfad8 */);
    // 00472c18  895014                 -mov dword ptr [eax + 0x14], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 00472c1b  8b84245c020000         -mov eax, dword ptr [esp + 0x25c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(604) /* 0x25c */);
    // 00472c22  8b15c8fa4d00           -mov edx, dword ptr [0x4dfac8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5110472) /* 0x4dfac8 */);
    // 00472c28  895018                 -mov dword ptr [eax + 0x18], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 00472c2b  8b84245c020000         -mov eax, dword ptr [esp + 0x25c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(604) /* 0x25c */);
    // 00472c32  8b15d0fa4d00           -mov edx, dword ptr [0x4dfad0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5110480) /* 0x4dfad0 */);
    // 00472c38  89501c                 -mov dword ptr [eax + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 00472c3b  8b84245c020000         -mov eax, dword ptr [esp + 0x25c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(604) /* 0x25c */);
    // 00472c42  8b15ccfa4d00           -mov edx, dword ptr [0x4dfacc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5110476) /* 0x4dfacc */);
    // 00472c48  895020                 -mov dword ptr [eax + 0x20], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 00472c4b  8b84245c020000         -mov eax, dword ptr [esp + 0x25c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(604) /* 0x25c */);
    // 00472c52  8b15d0fa4d00           -mov edx, dword ptr [0x4dfad0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5110480) /* 0x4dfad0 */);
    // 00472c58  895024                 -mov dword ptr [eax + 0x24], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 00472c5b  e909ffffff             -jmp 0x472b69
    goto L_0x00472b69;
L_0x00472c60:
    // 00472c60  b90b000000             -mov ecx, 0xb
    cpu.ecx = 11 /*0xb*/;
    // 00472c65  8bbc245c020000         -mov edi, dword ptr [esp + 0x25c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(604) /* 0x25c */);
    // 00472c6c  bec8b75100             -mov esi, 0x51b7c8
    cpu.esi = 5355464 /*0x51b7c8*/;
    // 00472c71  e96efeffff             -jmp 0x472ae4
    goto L_0x00472ae4;
L_0x00472c76:
    // 00472c76  bacc000000             -mov edx, 0xcc
    cpu.edx = 204 /*0xcc*/;
    // 00472c7b  8d842458020000         -lea eax, [esp + 0x258]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(600) /* 0x258 */);
    // 00472c82  e8e99cfeff             -call 0x45c970
    cpu.esp -= 4;
    sub_45c970(app, cpu);
    if (cpu.terminate) return;
    // 00472c87  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00472c89  0f84dafeffff           -je 0x472b69
    if (cpu.flags.zf)
    {
        goto L_0x00472b69;
    }
    // 00472c8f  8b8c2458020000         -mov ecx, dword ptr [esp + 0x258]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(600) /* 0x258 */);
    // 00472c96  ba11000000             -mov edx, 0x11
    cpu.edx = 17 /*0x11*/;
    // 00472c9b  8b1dd4fa4d00           -mov ebx, dword ptr [0x4dfad4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5110484) /* 0x4dfad4 */);
    // 00472ca1  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00472ca3  e8f872fdff             -call 0x449fa0
    cpu.esp -= 4;
    sub_449fa0(app, cpu);
    if (cpu.terminate) return;
    // 00472ca8  bacc000000             -mov edx, 0xcc
    cpu.edx = 204 /*0xcc*/;
    // 00472cad  8d842468020000         -lea eax, [esp + 0x268]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(616) /* 0x268 */);
    // 00472cb4  e8b79cfeff             -call 0x45c970
    cpu.esp -= 4;
    sub_45c970(app, cpu);
    if (cpu.terminate) return;
    // 00472cb9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00472cbb  0f84a8feffff           -je 0x472b69
    if (cpu.flags.zf)
    {
        goto L_0x00472b69;
    }
    // 00472cc1  8b8c2468020000         -mov ecx, dword ptr [esp + 0x268]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(616) /* 0x268 */);
    // 00472cc8  ba11000000             -mov edx, 0x11
    cpu.edx = 17 /*0x11*/;
    // 00472ccd  8b1ddcfa4d00           -mov ebx, dword ptr [0x4dfadc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5110492) /* 0x4dfadc */);
    // 00472cd3  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00472cd5  e8c672fdff             -call 0x449fa0
    cpu.esp -= 4;
    sub_449fa0(app, cpu);
    if (cpu.terminate) return;
    // 00472cda  ba0c000000             -mov edx, 0xc
    cpu.edx = 12 /*0xc*/;
    // 00472cdf  8d84246c020000         -lea eax, [esp + 0x26c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(620) /* 0x26c */);
    // 00472ce6  e8859cfeff             -call 0x45c970
    cpu.esp -= 4;
    sub_45c970(app, cpu);
    if (cpu.terminate) return;
    // 00472ceb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00472ced  0f8476feffff           -je 0x472b69
    if (cpu.flags.zf)
    {
        goto L_0x00472b69;
    }
    // 00472cf3  8b8c246c020000         -mov ecx, dword ptr [esp + 0x26c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(620) /* 0x26c */);
    // 00472cfa  bb4cb85100             -mov ebx, 0x51b84c
    cpu.ebx = 5355596 /*0x51b84c*/;
    // 00472cff  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00472d04  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00472d06  e89572fdff             -call 0x449fa0
    cpu.esp -= 4;
    sub_449fa0(app, cpu);
    if (cpu.terminate) return;
    // 00472d0b  ba0c000000             -mov edx, 0xc
    cpu.edx = 12 /*0xc*/;
    // 00472d10  8d842470020000         -lea eax, [esp + 0x270]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(624) /* 0x270 */);
    // 00472d17  e8549cfeff             -call 0x45c970
    cpu.esp -= 4;
    sub_45c970(app, cpu);
    if (cpu.terminate) return;
    // 00472d1c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00472d1e  0f8445feffff           -je 0x472b69
    if (cpu.flags.zf)
    {
        goto L_0x00472b69;
    }
    // 00472d24  8b8c2470020000         -mov ecx, dword ptr [esp + 0x270]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(624) /* 0x270 */);
    // 00472d2b  bbb0b75100             -mov ebx, 0x51b7b0
    cpu.ebx = 5355440 /*0x51b7b0*/;
    // 00472d30  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00472d35  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00472d37  e86472fdff             -call 0x449fa0
    cpu.esp -= 4;
    sub_449fa0(app, cpu);
    if (cpu.terminate) return;
    // 00472d3c  bb11000000             -mov ebx, 0x11
    cpu.ebx = 17 /*0x11*/;
    // 00472d41  8d942488000000         -lea edx, [esp + 0x88]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(136) /* 0x88 */);
    // 00472d48  8b842458020000         -mov eax, dword ptr [esp + 0x258]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(600) /* 0x258 */);
    // 00472d4f  bee1fa0000             -mov esi, 0xfae1
    cpu.esi = 64225 /*0xfae1*/;
    // 00472d54  e847050000             -call 0x4732a0
    cpu.esp -= 4;
    sub_4732a0(app, cpu);
    if (cpu.terminate) return;
    // 00472d59  bb11000000             -mov ebx, 0x11
    cpu.ebx = 17 /*0x11*/;
    // 00472d5e  8d942410010000         -lea edx, [esp + 0x110]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(272) /* 0x110 */);
    // 00472d65  8b842468020000         -mov eax, dword ptr [esp + 0x268]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(616) /* 0x268 */);
    // 00472d6c  b95cb85100             -mov ecx, 0x51b85c
    cpu.ecx = 5355612 /*0x51b85c*/;
    // 00472d71  e82a050000             -call 0x4732a0
    cpu.esp -= 4;
    sub_4732a0(app, cpu);
    if (cpu.terminate) return;
    // 00472d76  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00472d7b  8d942440020000         -lea edx, [esp + 0x240]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(576) /* 0x240 */);
    // 00472d82  8b84246c020000         -mov eax, dword ptr [esp + 0x26c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(620) /* 0x26c */);
    // 00472d89  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00472d8b  e810050000             -call 0x4732a0
    cpu.esp -= 4;
    sub_4732a0(app, cpu);
    if (cpu.terminate) return;
    // 00472d90  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00472d95  8d942448020000         -lea edx, [esp + 0x248]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(584) /* 0x248 */);
    // 00472d9c  8b842470020000         -mov eax, dword ptr [esp + 0x270]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(624) /* 0x270 */);
    // 00472da3  89bc247c020000         -mov dword ptr [esp + 0x27c], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(636) /* 0x27c */) = cpu.edi;
    // 00472daa  e8f1040000             -call 0x4732a0
    cpu.esp -= 4;
    sub_4732a0(app, cpu);
    if (cpu.terminate) return;
    // 00472daf  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00472db1  8d9c248c000000         -lea ebx, [esp + 0x8c]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 00472db8  8d942414010000         -lea edx, [esp + 0x114]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 00472dbf  6a11                   -push 0x11
    app->getMemory<x86::reg32>(cpu.esp-4) = 17 /*0x11*/;
    cpu.esp -= 4;
    // 00472dc1  8d8424a0010000         -lea eax, [esp + 0x1a0]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(416) /* 0x1a0 */);
    // 00472dc8  89bc2488020000         -mov dword ptr [esp + 0x288], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(648) /* 0x288 */) = cpu.edi;
    // 00472dcf  e88c6ffdff             -call 0x449d60
    cpu.esp -= 4;
    sub_449d60(app, cpu);
    if (cpu.terminate) return;
    // 00472dd4  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00472dd6  8d8c2468020000         -lea ecx, [esp + 0x268]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(616) /* 0x268 */);
    // 00472ddd  8d9c248c000000         -lea ebx, [esp + 0x8c]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 00472de4  8d942414010000         -lea edx, [esp + 0x114]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 00472deb  6a11                   -push 0x11
    app->getMemory<x86::reg32>(cpu.esp-4) = 17 /*0x11*/;
    cpu.esp -= 4;
    // 00472ded  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00472df1  89b4246c020000         -mov dword ptr [esp + 0x26c], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(620) /* 0x26c */) = cpu.esi;
    // 00472df8  e8636ffdff             -call 0x449d60
    cpu.esp -= 4;
    sub_449d60(app, cpu);
    if (cpu.terminate) return;
    // 00472dfd  b80c000000             -mov eax, 0xc
    cpu.eax = 12 /*0xc*/;
    // 00472e02  ba0f000000             -mov edx, 0xf
    cpu.edx = 15 /*0xf*/;
    // 00472e07  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00472e09  89842484020000         -mov dword ptr [esp + 0x284], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(644) /* 0x284 */) = cpu.eax;
    // 00472e10  89942478020000         -mov dword ptr [esp + 0x278], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(632) /* 0x278 */) = cpu.edx;
L_0x00472e17:
    // 00472e17  8b842458020000         -mov eax, dword ptr [esp + 0x258]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(600) /* 0x258 */);
    // 00472e1e  8bb42480020000         -mov esi, dword ptr [esp + 0x280]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(640) /* 0x280 */);
    // 00472e25  8b2d70b85100           -mov ebp, dword ptr [0x51b870]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5355632) /* 0x51b870 */);
    // 00472e2b  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00472e2d  c1fd02                 -sar ebp, 2
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (2 /*0x2*/ % 32));
    // 00472e30  3b6808                 +cmp ebp, dword ptr [eax + 8]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00472e33  0f8f1e030000           -jg 0x473157
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00473157;
    }
L_0x00472e39:
    // 00472e39  8dbc2420020000         -lea edi, [esp + 0x220]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(544) /* 0x220 */);
    // 00472e40  8d741c08               -lea esi, [esp + ebx + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */ + cpu.ebx * 1);
    // 00472e44  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00472e45  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00472e46  8dbc2428020000         -lea edi, [esp + 0x228]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(552) /* 0x228 */);
    // 00472e4d  8d341c                 -lea esi, [esp + ebx]
    cpu.esi = x86::reg32(cpu.esp + cpu.ebx * 1);
    // 00472e50  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00472e51  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00472e52  8dbc2430020000         -lea edi, [esp + 0x230]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(560) /* 0x230 */);
    // 00472e59  8db42440020000         -lea esi, [esp + 0x240]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(576) /* 0x240 */);
    // 00472e60  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00472e61  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00472e62  8dbc2438020000         -lea edi, [esp + 0x238]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(568) /* 0x238 */);
    // 00472e69  8db42440020000         -lea esi, [esp + 0x240]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(576) /* 0x240 */);
    // 00472e70  8d842420020000         -lea eax, [esp + 0x220]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(544) /* 0x220 */);
    // 00472e77  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00472e78  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00472e79  e8d26ffdff             -call 0x449e50
    cpu.esp -= 4;
    sub_449e50(app, cpu);
    if (cpu.terminate) return;
    // 00472e7e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00472e80  0f847f000000           -je 0x472f05
    if (cpu.flags.zf)
    {
        goto L_0x00472f05;
    }
    // 00472e86  ba2c000000             -mov edx, 0x2c
    cpu.edx = 44 /*0x2c*/;
    // 00472e8b  8d84245c020000         -lea eax, [esp + 0x25c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(604) /* 0x25c */);
    // 00472e92  e86999feff             -call 0x45c800
    cpu.esp -= 4;
    sub_45c800(app, cpu);
    if (cpu.terminate) return;
    // 00472e97  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00472e99  746a                   -je 0x472f05
    if (cpu.flags.zf)
    {
        goto L_0x00472f05;
    }
    // 00472e9b  b90b000000             -mov ecx, 0xb
    cpu.ecx = 11 /*0xb*/;
    // 00472ea0  8bbc245c020000         -mov edi, dword ptr [esp + 0x25c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(604) /* 0x25c */);
    // 00472ea7  bec8b75100             -mov esi, 0x51b7c8
    cpu.esi = 5355464 /*0x51b7c8*/;
    // 00472eac  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00472eae  8b84245c020000         -mov eax, dword ptr [esp + 0x25c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(604) /* 0x25c */);
    // 00472eb5  c6402900               -mov byte ptr [eax + 0x29], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(41) /* 0x29 */) = 0 /*0x0*/;
    // 00472eb9  8bbc245c020000         -mov edi, dword ptr [esp + 0x25c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(604) /* 0x25c */);
    // 00472ec0  8db42420020000         -lea esi, [esp + 0x220]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(544) /* 0x220 */);
    // 00472ec7  8d7f08                 -lea edi, [edi + 8]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 00472eca  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00472ecb  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00472ecc  8bbc245c020000         -mov edi, dword ptr [esp + 0x25c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(604) /* 0x25c */);
    // 00472ed3  8db42428020000         -lea esi, [esp + 0x228]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(552) /* 0x228 */);
    // 00472eda  8d7f10                 -lea edi, [edi + 0x10]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 00472edd  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00472ede  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00472edf  8bbc245c020000         -mov edi, dword ptr [esp + 0x25c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(604) /* 0x25c */);
    // 00472ee6  8db42430020000         -lea esi, [esp + 0x230]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(560) /* 0x230 */);
    // 00472eed  8d7f18                 -lea edi, [edi + 0x18]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(24) /* 0x18 */);
    // 00472ef0  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00472ef1  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00472ef2  8bbc245c020000         -mov edi, dword ptr [esp + 0x25c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(604) /* 0x25c */);
    // 00472ef9  8db42438020000         -lea esi, [esp + 0x238]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(568) /* 0x238 */);
    // 00472f00  8d7f20                 -lea edi, [edi + 0x20]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(32) /* 0x20 */);
    // 00472f03  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00472f04  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
L_0x00472f05:
    // 00472f05  8b842468020000         -mov eax, dword ptr [esp + 0x268]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(616) /* 0x268 */);
    // 00472f0c  03842480020000         -add eax, dword ptr [esp + 0x280]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(640) /* 0x280 */)));
    // 00472f13  3b6808                 +cmp ebp, dword ptr [eax + 8]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00472f16  0f8f57020000           -jg 0x473173
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00473173;
    }
L_0x00472f1c:
    // 00472f1c  8dbc2420020000         -lea edi, [esp + 0x220]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(544) /* 0x220 */);
    // 00472f23  8db41c98010000         -lea esi, [esp + ebx + 0x198]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(408) /* 0x198 */ + cpu.ebx * 1);
    // 00472f2a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00472f2b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00472f2c  8dbc2428020000         -lea edi, [esp + 0x228]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(552) /* 0x228 */);
    // 00472f33  8db41ca0010000         -lea esi, [esp + ebx + 0x1a0]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(416) /* 0x1a0 */ + cpu.ebx * 1);
    // 00472f3a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00472f3b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00472f3c  8dbc2430020000         -lea edi, [esp + 0x230]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(560) /* 0x230 */);
    // 00472f43  8db42448020000         -lea esi, [esp + 0x248]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(584) /* 0x248 */);
    // 00472f4a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00472f4b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00472f4c  8dbc2438020000         -lea edi, [esp + 0x238]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(568) /* 0x238 */);
    // 00472f53  8db42448020000         -lea esi, [esp + 0x248]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(584) /* 0x248 */);
    // 00472f5a  8d842420020000         -lea eax, [esp + 0x220]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(544) /* 0x220 */);
    // 00472f61  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00472f62  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00472f63  e8e86efdff             -call 0x449e50
    cpu.esp -= 4;
    sub_449e50(app, cpu);
    if (cpu.terminate) return;
    // 00472f68  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00472f6a  0f847f000000           -je 0x472fef
    if (cpu.flags.zf)
    {
        goto L_0x00472fef;
    }
    // 00472f70  ba2c000000             -mov edx, 0x2c
    cpu.edx = 44 /*0x2c*/;
    // 00472f75  8d84245c020000         -lea eax, [esp + 0x25c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(604) /* 0x25c */);
    // 00472f7c  e87f98feff             -call 0x45c800
    cpu.esp -= 4;
    sub_45c800(app, cpu);
    if (cpu.terminate) return;
    // 00472f81  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00472f83  746a                   -je 0x472fef
    if (cpu.flags.zf)
    {
        goto L_0x00472fef;
    }
    // 00472f85  b90b000000             -mov ecx, 0xb
    cpu.ecx = 11 /*0xb*/;
    // 00472f8a  8bbc245c020000         -mov edi, dword ptr [esp + 0x25c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(604) /* 0x25c */);
    // 00472f91  bef4b75100             -mov esi, 0x51b7f4
    cpu.esi = 5355508 /*0x51b7f4*/;
    // 00472f96  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00472f98  8b84245c020000         -mov eax, dword ptr [esp + 0x25c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(604) /* 0x25c */);
    // 00472f9f  c6402900               -mov byte ptr [eax + 0x29], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(41) /* 0x29 */) = 0 /*0x0*/;
    // 00472fa3  8bbc245c020000         -mov edi, dword ptr [esp + 0x25c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(604) /* 0x25c */);
    // 00472faa  8db42420020000         -lea esi, [esp + 0x220]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(544) /* 0x220 */);
    // 00472fb1  8d7f08                 -lea edi, [edi + 8]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 00472fb4  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00472fb5  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00472fb6  8bbc245c020000         -mov edi, dword ptr [esp + 0x25c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(604) /* 0x25c */);
    // 00472fbd  8db42428020000         -lea esi, [esp + 0x228]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(552) /* 0x228 */);
    // 00472fc4  8d7f10                 -lea edi, [edi + 0x10]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 00472fc7  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00472fc8  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00472fc9  8bbc245c020000         -mov edi, dword ptr [esp + 0x25c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(604) /* 0x25c */);
    // 00472fd0  8db42430020000         -lea esi, [esp + 0x230]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(560) /* 0x230 */);
    // 00472fd7  8d7f18                 -lea edi, [edi + 0x18]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(24) /* 0x18 */);
    // 00472fda  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00472fdb  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00472fdc  8bbc245c020000         -mov edi, dword ptr [esp + 0x25c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(604) /* 0x25c */);
    // 00472fe3  8db42438020000         -lea esi, [esp + 0x238]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(568) /* 0x238 */);
    // 00472fea  8d7f20                 -lea edi, [edi + 0x20]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(32) /* 0x20 */);
    // 00472fed  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00472fee  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
L_0x00472fef:
    // 00472fef  8b842458020000         -mov eax, dword ptr [esp + 0x258]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(600) /* 0x258 */);
    // 00472ff6  8bb42480020000         -mov esi, dword ptr [esp + 0x280]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(640) /* 0x280 */);
    // 00472ffd  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00472fff  3b6808                 +cmp ebp, dword ptr [eax + 8]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00473002  0f8f87010000           -jg 0x47318f
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0047318f;
    }
L_0x00473008:
    // 00473008  833d64b8510000         +cmp dword ptr [0x51b864], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5355620) /* 0x51b864 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047300f  0f84bc010000           -je 0x4731d1
    if (cpu.flags.zf)
    {
        goto L_0x004731d1;
    }
    // 00473015  83bc247c02000007       +cmp dword ptr [esp + 0x27c], 7
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(636) /* 0x27c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047301d  0f8eae010000           -jle 0x4731d1
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004731d1;
    }
    // 00473023  8b842478020000         -mov eax, dword ptr [esp + 0x278]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(632) /* 0x278 */);
    // 0047302a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047302c  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 00473031  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00473034  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00473036  8dbc2420020000         -lea edi, [esp + 0x220]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(544) /* 0x220 */);
    // 0047303d  8db41c90000000         -lea esi, [esp + ebx + 0x90]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(144) /* 0x90 */ + cpu.ebx * 1);
    // 00473044  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00473045  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00473046  8dbc2428020000         -lea edi, [esp + 0x228]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(552) /* 0x228 */);
    // 0047304d  8db41c88000000         -lea esi, [esp + ebx + 0x88]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(136) /* 0x88 */ + cpu.ebx * 1);
    // 00473054  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00473055  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00473056  8dbc2430020000         -lea edi, [esp + 0x230]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(560) /* 0x230 */);
    // 0047305d  8db41c98010000         -lea esi, [esp + ebx + 0x198]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(408) /* 0x198 */ + cpu.ebx * 1);
    // 00473064  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00473065  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00473066  8dbc2438020000         -lea edi, [esp + 0x238]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(568) /* 0x238 */);
    // 0047306d  8db41ca0010000         -lea esi, [esp + ebx + 0x1a0]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(416) /* 0x1a0 */ + cpu.ebx * 1);
L_0x00473074:
    // 00473074  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00473075  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00473076  8b2c9590b75100         -mov ebp, dword ptr [edx*4 + 0x51b790]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5355408) /* 0x51b790 */ + cpu.edx * 4);
    // 0047307d  8d842420020000         -lea eax, [esp + 0x220]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(544) /* 0x220 */);
    // 00473084  e8c76dfdff             -call 0x449e50
    cpu.esp -= 4;
    sub_449e50(app, cpu);
    if (cpu.terminate) return;
    // 00473089  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047308b  7479                   -je 0x473106
    if (cpu.flags.zf)
    {
        goto L_0x00473106;
    }
    // 0047308d  ba30000000             -mov edx, 0x30
    cpu.edx = 48 /*0x30*/;
    // 00473092  8d842460020000         -lea eax, [esp + 0x260]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(608) /* 0x260 */);
    // 00473099  e86297feff             -call 0x45c800
    cpu.esp -= 4;
    sub_45c800(app, cpu);
    if (cpu.terminate) return;
    // 0047309e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004730a0  7464                   -je 0x473106
    if (cpu.flags.zf)
    {
        goto L_0x00473106;
    }
    // 004730a2  8b842460020000         -mov eax, dword ptr [esp + 0x260]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(608) /* 0x260 */);
    // 004730a9  c7400415000000         -mov dword ptr [eax + 4], 0x15
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 21 /*0x15*/;
    // 004730b0  8b842460020000         -mov eax, dword ptr [esp + 0x260]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(608) /* 0x260 */);
    // 004730b7  896828                 -mov dword ptr [eax + 0x28], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */) = cpu.ebp;
    // 004730ba  8bbc2460020000         -mov edi, dword ptr [esp + 0x260]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(608) /* 0x260 */);
    // 004730c1  8db42420020000         -lea esi, [esp + 0x220]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(544) /* 0x220 */);
    // 004730c8  8d7f08                 -lea edi, [edi + 8]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 004730cb  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004730cc  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004730cd  8bbc2460020000         -mov edi, dword ptr [esp + 0x260]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(608) /* 0x260 */);
    // 004730d4  8db42428020000         -lea esi, [esp + 0x228]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(552) /* 0x228 */);
    // 004730db  8d7f10                 -lea edi, [edi + 0x10]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 004730de  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004730df  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004730e0  8bbc2460020000         -mov edi, dword ptr [esp + 0x260]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(608) /* 0x260 */);
    // 004730e7  8db42430020000         -lea esi, [esp + 0x230]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(560) /* 0x230 */);
    // 004730ee  8d7f18                 -lea edi, [edi + 0x18]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(24) /* 0x18 */);
    // 004730f1  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004730f2  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004730f3  8bbc2460020000         -mov edi, dword ptr [esp + 0x260]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(608) /* 0x260 */);
    // 004730fa  8db42438020000         -lea esi, [esp + 0x238]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(568) /* 0x238 */);
    // 00473101  8d7f20                 -lea edi, [edi + 0x20]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(32) /* 0x20 */);
    // 00473104  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00473105  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
L_0x00473106:
    // 00473106  8b842484020000         -mov eax, dword ptr [esp + 0x284]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(644) /* 0x284 */);
    // 0047310d  8b942478020000         -mov edx, dword ptr [esp + 0x278]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(632) /* 0x278 */);
    // 00473114  8b8c247c020000         -mov ecx, dword ptr [esp + 0x27c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(636) /* 0x27c */);
    // 0047311b  8bac2480020000         -mov ebp, dword ptr [esp + 0x280]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(640) /* 0x280 */);
    // 00473122  83c308                 -add ebx, 8
    (cpu.ebx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00473125  83c00c                 -add eax, 0xc
    (cpu.eax) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00473128  4a                     -dec edx
    (cpu.edx)--;
    // 00473129  41                     -inc ecx
    (cpu.ecx)++;
    // 0047312a  83c50c                 -add ebp, 0xc
    (cpu.ebp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047312d  89842484020000         -mov dword ptr [esp + 0x284], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(644) /* 0x284 */) = cpu.eax;
    // 00473134  89942478020000         -mov dword ptr [esp + 0x278], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(632) /* 0x278 */) = cpu.edx;
    // 0047313b  898c247c020000         -mov dword ptr [esp + 0x27c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(636) /* 0x27c */) = cpu.ecx;
    // 00473142  89ac2480020000         -mov dword ptr [esp + 0x280], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(640) /* 0x280 */) = cpu.ebp;
    // 00473149  83f910                 +cmp ecx, 0x10
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
    // 0047314c  0f8cc5fcffff           -jl 0x472e17
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00472e17;
    }
    // 00473152  e912faffff             -jmp 0x472b69
    goto L_0x00472b69;
L_0x00473157:
    // 00473157  8b842458020000         -mov eax, dword ptr [esp + 0x258]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(600) /* 0x258 */);
    // 0047315e  03842484020000         -add eax, dword ptr [esp + 0x284]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(644) /* 0x284 */)));
    // 00473165  3b6808                 +cmp ebp, dword ptr [eax + 8]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00473168  0f8ecbfcffff           -jle 0x472e39
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00472e39;
    }
    // 0047316e  e992fdffff             -jmp 0x472f05
    goto L_0x00472f05;
L_0x00473173:
    // 00473173  8b842468020000         -mov eax, dword ptr [esp + 0x268]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(616) /* 0x268 */);
    // 0047317a  03842484020000         -add eax, dword ptr [esp + 0x284]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(644) /* 0x284 */)));
    // 00473181  3b6808                 +cmp ebp, dword ptr [eax + 8]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00473184  0f8e92fdffff           -jle 0x472f1c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00472f1c;
    }
    // 0047318a  e960feffff             -jmp 0x472fef
    goto L_0x00472fef;
L_0x0047318f:
    // 0047318f  8b842458020000         -mov eax, dword ptr [esp + 0x258]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(600) /* 0x258 */);
    // 00473196  8b942484020000         -mov edx, dword ptr [esp + 0x284]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(644) /* 0x284 */);
    // 0047319d  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0047319f  3b6808                 +cmp ebp, dword ptr [eax + 8]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004731a2  0f8e60feffff           -jle 0x473008
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00473008;
    }
    // 004731a8  8b842468020000         -mov eax, dword ptr [esp + 0x268]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(616) /* 0x268 */);
    // 004731af  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004731b1  3b6808                 +cmp ebp, dword ptr [eax + 8]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004731b4  0f8e4efeffff           -jle 0x473008
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00473008;
    }
    // 004731ba  8b842468020000         -mov eax, dword ptr [esp + 0x268]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(616) /* 0x268 */);
    // 004731c1  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004731c3  3b6808                 +cmp ebp, dword ptr [eax + 8]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004731c6  0f8e3cfeffff           -jle 0x473008
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00473008;
    }
    // 004731cc  e935ffffff             -jmp 0x473106
    goto L_0x00473106;
L_0x004731d1:
    // 004731d1  8b84247c020000         -mov eax, dword ptr [esp + 0x27c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(636) /* 0x27c */);
    // 004731d8  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004731da  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 004731df  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004731e2  f7f9                   +idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004731e4  8dbc2420020000         -lea edi, [esp + 0x220]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(544) /* 0x220 */);
    // 004731eb  8db41c88000000         -lea esi, [esp + ebx + 0x88]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(136) /* 0x88 */ + cpu.ebx * 1);
    // 004731f2  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004731f3  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004731f4  8dbc2428020000         -lea edi, [esp + 0x228]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(552) /* 0x228 */);
    // 004731fb  8db41c90000000         -lea esi, [esp + ebx + 0x90]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(144) /* 0x90 */ + cpu.ebx * 1);
    // 00473202  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00473203  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00473204  8dbc2430020000         -lea edi, [esp + 0x230]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(560) /* 0x230 */);
    // 0047320b  8db41ca0010000         -lea esi, [esp + ebx + 0x1a0]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(416) /* 0x1a0 */ + cpu.ebx * 1);
    // 00473212  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00473213  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00473214  8dbc2438020000         -lea edi, [esp + 0x238]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(568) /* 0x238 */);
    // 0047321b  8db41c98010000         -lea esi, [esp + ebx + 0x198]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(408) /* 0x198 */ + cpu.ebx * 1);
    // 00473222  e94dfeffff             -jmp 0x473074
    goto L_0x00473074;
}

}
