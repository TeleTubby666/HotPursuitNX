#include "nfs2se.h"
#include <lib/thread.h>

namespace nfs2se
{

/* align: skip  */
void Application::sub_4b4e06(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4e06  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b4e07  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b4e08  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b4e09  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b4e0a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b4e0b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b4e0c  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b4e0f  b8641d4c00             -mov eax, 0x4c1d64
    cpu.eax = 4988260 /*0x4c1d64*/;
    // 004b4e14  e8a06effff             -call 0x4abcb9
    cpu.esp -= 4;
    sub_4abcb9(app, cpu);
    if (cpu.terminate) return;
    // 004b4e19  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004b4e1b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b4e1d  0f84f9000000           -je 0x4b4f1c
    if (cpu.flags.zf)
    {
        goto L_0x004b4f1c;
    }
L_0x004b4e23:
    // 004b4e23  803900                 +cmp byte ptr [ecx], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b4e26  0f84e6000000           -je 0x4b4f12
    if (cpu.flags.zf)
    {
        goto L_0x004b4f12;
    }
    // 004b4e2c  b23a                   -mov dl, 0x3a
    cpu.dl = 58 /*0x3a*/;
    // 004b4e2e  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
L_0x004b4e30:
    // 004b4e30  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004b4e32  3ac2                   +cmp al, dl
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
    // 004b4e34  7412                   -je 0x4b4e48
    if (cpu.flags.zf)
    {
        goto L_0x004b4e48;
    }
    // 004b4e36  3c00                   +cmp al, 0
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
    // 004b4e38  740c                   -je 0x4b4e46
    if (cpu.flags.zf)
    {
        goto L_0x004b4e46;
    }
    // 004b4e3a  46                     -inc esi
    (cpu.esi)++;
    // 004b4e3b  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004b4e3d  3ac2                   +cmp al, dl
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
    // 004b4e3f  7407                   -je 0x4b4e48
    if (cpu.flags.zf)
    {
        goto L_0x004b4e48;
    }
    // 004b4e41  46                     -inc esi
    (cpu.esi)++;
    // 004b4e42  3c00                   +cmp al, 0
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
    // 004b4e44  75ea                   -jne 0x4b4e30
    if (!cpu.flags.zf)
    {
        goto L_0x004b4e30;
    }
L_0x004b4e46:
    // 004b4e46  2bf6                   -sub esi, esi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x004b4e48:
    // 004b4e48  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b4e4a  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 004b4e4c  29ce                   -sub esi, ecx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b4e4e  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004b4e50  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004b4e52  e86571fcff             -call 0x47bfbc
    cpu.esp -= 4;
    sub_47bfbc(app, cpu);
    if (cpu.terminate) return;
    // 004b4e57  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 004b4e5c  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 004b4e5e  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b4e60  881434                 -mov byte ptr [esp + esi], dl
    app->getMemory<x86::reg8>(cpu.esp + cpu.esi * 1) = cpu.dl;
    // 004b4e63  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b4e65  e898060000             -call 0x4b5502
    cpu.esp -= 4;
    sub_4b5502(app, cpu);
    if (cpu.terminate) return;
    // 004b4e6a  8d7501                 -lea esi, [ebp + 1]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(1) /* 0x1 */);
    // 004b4e6d  b23a                   -mov dl, 0x3a
    cpu.dl = 58 /*0x3a*/;
    // 004b4e6f  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004b4e71  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
L_0x004b4e73:
    // 004b4e73  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004b4e75  3ac2                   +cmp al, dl
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
    // 004b4e77  7412                   -je 0x4b4e8b
    if (cpu.flags.zf)
    {
        goto L_0x004b4e8b;
    }
    // 004b4e79  3c00                   +cmp al, 0
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
    // 004b4e7b  740c                   -je 0x4b4e89
    if (cpu.flags.zf)
    {
        goto L_0x004b4e89;
    }
    // 004b4e7d  46                     -inc esi
    (cpu.esi)++;
    // 004b4e7e  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004b4e80  3ac2                   +cmp al, dl
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
    // 004b4e82  7407                   -je 0x4b4e8b
    if (cpu.flags.zf)
    {
        goto L_0x004b4e8b;
    }
    // 004b4e84  46                     -inc esi
    (cpu.esi)++;
    // 004b4e85  3c00                   +cmp al, 0
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
    // 004b4e87  75ea                   -jne 0x4b4e73
    if (!cpu.flags.zf)
    {
        goto L_0x004b4e73;
    }
L_0x004b4e89:
    // 004b4e89  2bf6                   -sub esi, esi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x004b4e8b:
    // 004b4e8b  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b4e8d  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 004b4e8f  29ce                   -sub esi, ecx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b4e91  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004b4e93  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004b4e95  e82271fcff             -call 0x47bfbc
    cpu.esp -= 4;
    sub_47bfbc(app, cpu);
    if (cpu.terminate) return;
    // 004b4e9a  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 004b4e9f  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 004b4ea1  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b4ea3  883434                 -mov byte ptr [esp + esi], dh
    app->getMemory<x86::reg8>(cpu.esp + cpu.esi * 1) = cpu.dh;
    // 004b4ea6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b4ea8  e855060000             -call 0x4b5502
    cpu.esp -= 4;
    sub_4b5502(app, cpu);
    if (cpu.terminate) return;
    // 004b4ead  8d7501                 -lea esi, [ebp + 1]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(1) /* 0x1 */);
    // 004b4eb0  b22a                   -mov dl, 0x2a
    cpu.dl = 42 /*0x2a*/;
    // 004b4eb2  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004b4eb6  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
L_0x004b4eb8:
    // 004b4eb8  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004b4eba  3ac2                   +cmp al, dl
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
    // 004b4ebc  7412                   -je 0x4b4ed0
    if (cpu.flags.zf)
    {
        goto L_0x004b4ed0;
    }
    // 004b4ebe  3c00                   +cmp al, 0
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
    // 004b4ec0  740c                   -je 0x4b4ece
    if (cpu.flags.zf)
    {
        goto L_0x004b4ece;
    }
    // 004b4ec2  46                     -inc esi
    (cpu.esi)++;
    // 004b4ec3  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004b4ec5  3ac2                   +cmp al, dl
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
    // 004b4ec7  7407                   -je 0x4b4ed0
    if (cpu.flags.zf)
    {
        goto L_0x004b4ed0;
    }
    // 004b4ec9  46                     -inc esi
    (cpu.esi)++;
    // 004b4eca  3c00                   +cmp al, 0
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
    // 004b4ecc  75ea                   -jne 0x4b4eb8
    if (!cpu.flags.zf)
    {
        goto L_0x004b4eb8;
    }
L_0x004b4ece:
    // 004b4ece  2bf6                   -sub esi, esi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x004b4ed0:
    // 004b4ed0  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b4ed2  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 004b4ed4  29ce                   -sub esi, ecx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b4ed6  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004b4ed8  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004b4eda  e8dd70fcff             -call 0x47bfbc
    cpu.esp -= 4;
    sub_47bfbc(app, cpu);
    if (cpu.terminate) return;
    // 004b4edf  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b4ee1  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 004b4ee3  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004b4ee5  881c34                 -mov byte ptr [esp + esi], bl
    app->getMemory<x86::reg8>(cpu.esp + cpu.esi * 1) = cpu.bl;
    // 004b4ee8  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 004b4eed  e810060000             -call 0x4b5502
    cpu.esp -= 4;
    sub_4b5502(app, cpu);
    if (cpu.terminate) return;
    // 004b4ef2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004b4ef4  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004b4ef6  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b4efa  e8ef5dffff             -call 0x4aacee
    cpu.esp -= 4;
    sub_4aacee(app, cpu);
    if (cpu.terminate) return;
    // 004b4eff  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004b4f01  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004b4f03  8d7501                 -lea esi, [ebp + 1]
    cpu.esi = x86::reg32(cpu.ebp + x86::reg32(1) /* 0x1 */);
    // 004b4f06  e84260ffff             -call 0x4aaf4d
    cpu.esp -= 4;
    sub_4aaf4d(app, cpu);
    if (cpu.terminate) return;
    // 004b4f0b  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004b4f0d  e911ffffff             -jmp 0x4b4e23
    goto L_0x004b4e23;
L_0x004b4f12:
    // 004b4f12  b8701d4c00             -mov eax, 0x4c1d70
    cpu.eax = 4988272 /*0x4c1d70*/;
    // 004b4f17  e83f060000             -call 0x4b555b
    cpu.esp -= 4;
    sub_4b555b(app, cpu);
    if (cpu.terminate) return;
L_0x004b4f1c:
    // 004b4f1c  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b4f1f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4f20  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4f21  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4f22  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4f23  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4f24  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4f25  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b4f26(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4f26  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b4f27  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b4f28  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b4f29  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b4f2a  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b4f2d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b4f2f  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b4f31  8a25b8a94c00           -mov ah, byte ptr [0x4ca9b8]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5024184) /* 0x4ca9b8 */);
    // 004b4f37  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004b4f3a  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 004b4f3c  7426                   -je 0x4b4f64
    if (cpu.flags.zf)
    {
        goto L_0x004b4f64;
    }
    // 004b4f3e  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 004b4f40  36d93f                 -fnstcw word ptr ss:[edi]
    app->getMemory<x86::reg16>(cpu.ess + cpu.edi) = cpu.fpu.control.word;
    // 004b4f43  9b                     -wait 
    /*nothing*/;
    // 004b4f44  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b4f46  741c                   -je 0x4b4f64
    if (cpu.flags.zf)
    {
        goto L_0x004b4f64;
    }
    // 004b4f48  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b4f4a  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 004b4f4d  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 004b4f4f  21da                   -and edx, ebx
    cpu.edx &= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b4f51  21f0                   -and eax, esi
    cpu.eax &= x86::reg32(x86::sreg32(cpu.esi));
    // 004b4f53  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 004b4f55  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 004b4f57  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004b4f5a  36d92f                 -fldcw word ptr ss:[edi]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.ess + cpu.edi);
    // 004b4f5d  9b                     -wait 
    /*nothing*/;
    // 004b4f5e  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 004b4f60  36d93f                 -fnstcw word ptr ss:[edi]
    app->getMemory<x86::reg16>(cpu.ess + cpu.edi) = cpu.fpu.control.word;
    // 004b4f63  9b                     -wait 
    /*nothing*/;
L_0x004b4f64:
    // 004b4f64  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b4f66  668b0424               -mov ax, word ptr [esp]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esp);
    // 004b4f6a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b4f6d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4f6e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4f6f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4f70  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4f71  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b4f72(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4f72  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b4f73  803800                 +cmp byte ptr [eax], 0
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
    // 004b4f76  7507                   -jne 0x4b4f7f
    if (!cpu.flags.zf)
    {
        goto L_0x004b4f7f;
    }
    // 004b4f78  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004b4f7d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4f7e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b4f7f:
    // 004b4f7f  833ddc93540000         +cmp dword ptr [0x5493dc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5542876) /* 0x5493dc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b4f86  7422                   -je 0x4b4faa
    if (cpu.flags.zf)
    {
        goto L_0x004b4faa;
    }
    // 004b4f88  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b4f8a  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004b4f8c  8a92e1935400           -mov dl, byte ptr [edx + 0x5493e1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5542881) /* 0x5493e1 */);
    // 004b4f92  80e201                 -and dl, 1
    cpu.dl &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004b4f95  81e2ff000000           +and edx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004b4f9b  740d                   -je 0x4b4faa
    if (cpu.flags.zf)
    {
        goto L_0x004b4faa;
    }
    // 004b4f9d  80780100               +cmp byte ptr [eax + 1], 0
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
    // 004b4fa1  7507                   -jne 0x4b4faa
    if (!cpu.flags.zf)
    {
        goto L_0x004b4faa;
    }
    // 004b4fa3  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 004b4fa8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4fa9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b4faa:
    // 004b4faa  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b4fac  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4fad  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b4fae(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b4fae  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b4faf  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b4fb0  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b4fb3  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b4fb5  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b4fb7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b4fb9  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b4fbb  e83e090000             -call 0x4b58fe
    cpu.esp -= 4;
    sub_4b58fe(app, cpu);
    if (cpu.terminate) return;
    // 004b4fc0  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b4fc2  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 004b4fc4  e8fcceffff             -call 0x4b1ec5
    cpu.esp -= 4;
    sub_4b1ec5(app, cpu);
    if (cpu.terminate) return;
    // 004b4fc9  881404                 -mov byte ptr [esp + eax], dl
    app->getMemory<x86::reg8>(cpu.esp + cpu.eax * 1) = cpu.dl;
    // 004b4fcc  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b4fd0  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004b4fd2  e827090000             -call 0x4b58fe
    cpu.esp -= 4;
    sub_4b58fe(app, cpu);
    if (cpu.terminate) return;
    // 004b4fd7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b4fd9  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 004b4fdb  e8e5ceffff             -call 0x4b1ec5
    cpu.esp -= 4;
    sub_4b1ec5(app, cpu);
    if (cpu.terminate) return;
    // 004b4fe0  88740404               -mov byte ptr [esp + eax + 4], dh
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */ + cpu.eax * 1) = cpu.dh;
    // 004b4fe4  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b4fe6  e844090000             -call 0x4b592f
    cpu.esp -= 4;
    sub_4b592f(app, cpu);
    if (cpu.terminate) return;
    // 004b4feb  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b4fef  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b4ff3  e837090000             -call 0x4b592f
    cpu.esp -= 4;
    sub_4b592f(app, cpu);
    if (cpu.terminate) return;
    // 004b4ff8  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b4ffa  e87f090000             -call 0x4b597e
    cpu.esp -= 4;
    sub_4b597e(app, cpu);
    if (cpu.terminate) return;
    // 004b4fff  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b5002  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5003  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5004  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b5005(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b5005  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b5006  833ddc93540000         +cmp dword ptr [0x5493dc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5542876) /* 0x5493dc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b500d  7420                   -je 0x4b502f
    if (cpu.flags.zf)
    {
        goto L_0x004b502f;
    }
    // 004b500f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b5011  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004b5013  8a92e1935400           -mov dl, byte ptr [edx + 0x5493e1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5542881) /* 0x5493e1 */);
    // 004b5019  80e201                 -and dl, 1
    cpu.dl &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004b501c  81e2ff000000           +and edx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004b5022  740b                   -je 0x4b502f
    if (cpu.flags.zf)
    {
        goto L_0x004b502f;
    }
    // 004b5024  80780100               +cmp byte ptr [eax + 1], 0
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
    // 004b5028  7405                   -je 0x4b502f
    if (cpu.flags.zf)
    {
        goto L_0x004b502f;
    }
    // 004b502a  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004b502d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b502e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b502f:
    // 004b502f  40                     -inc eax
    (cpu.eax)++;
    // 004b5030  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5031  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b5032(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b5032  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b5033  668b5008               -mov dx, word ptr [eax + 8]
    cpu.dx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004b5037  80e67f                 -and dh, 0x7f
    cpu.dh &= x86::reg8(x86::sreg8(127 /*0x7f*/));
    // 004b503a  6681faff7f             +cmp dx, 0x7fff
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(32767 /*0x7fff*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004b503f  751c                   -jne 0x4b505d
    if (!cpu.flags.zf)
    {
        goto L_0x004b505d;
    }
    // 004b5041  81780400000080         +cmp dword ptr [eax + 4], 0x80000000
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2147483648 /*0x80000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b5048  750c                   -jne 0x4b5056
    if (!cpu.flags.zf)
    {
        goto L_0x004b5056;
    }
    // 004b504a  833800                 +cmp dword ptr [eax], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b504d  7507                   -jne 0x4b5056
    if (!cpu.flags.zf)
    {
        goto L_0x004b5056;
    }
    // 004b504f  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 004b5054  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5055  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b5056:
    // 004b5056  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 004b505b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b505c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b505d:
    // 004b505d  66f74008ff7f           +test word ptr [eax + 8], 0x7fff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(app->getMemory<x86::reg16>(cpu.eax + x86::reg32(8) /* 0x8 */) & 32767 /*0x7fff*/));
    // 004b5063  7516                   -jne 0x4b507b
    if (!cpu.flags.zf)
    {
        goto L_0x004b507b;
    }
    // 004b5065  83780400               +cmp dword ptr [eax + 4], 0
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
    // 004b5069  7509                   -jne 0x4b5074
    if (!cpu.flags.zf)
    {
        goto L_0x004b5074;
    }
    // 004b506b  833800                 +cmp dword ptr [eax], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b506e  7504                   -jne 0x4b5074
    if (!cpu.flags.zf)
    {
        goto L_0x004b5074;
    }
    // 004b5070  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b5072  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5073  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b5074:
    // 004b5074  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 004b5079  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b507a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b507b:
    // 004b507b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004b5080  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5081  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b5082(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b5082  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b5083  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b5084  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b5085  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b5086  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b5087  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b5088  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b508a  29d2                   -sub edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b508c  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b508e  29ed                   -sub ebp, ebp
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004b5090  29c0                   -sub eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax));
L_0x004b5092:
    // 004b5092  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004b5094  3c00                   +cmp al, 0
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
    // 004b5096  742f                   -je 0x4b50c7
    if (cpu.flags.zf)
    {
        goto L_0x004b50c7;
    }
    // 004b5098  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004b509a  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004b509c  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004b509e  01ed                   +add ebp, ebp
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b50a0  11c9                   +adc ecx, ecx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b50a2  11d2                   -adc edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004b50a4  01ed                   +add ebp, ebp
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b50a6  11c9                   +adc ecx, ecx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b50a8  11d2                   -adc edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004b50aa  01c5                   +add ebp, eax
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b50ac  11d9                   +adc ecx, ebx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b50ae  11fa                   -adc edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi) + cpu.flags.cf);
    // 004b50b0  01ed                   +add ebp, ebp
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b50b2  11c9                   +adc ecx, ecx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b50b4  11d2                   -adc edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004b50b6  29c0                   -sub eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004b50b8  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004b50ba  240f                   -and al, 0xf
    cpu.al &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 004b50bc  01c5                   +add ebp, eax
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b50be  83d100                 +adc ecx, 0
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b50c1  83d200                 +adc edx, 0
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b50c4  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004b50c5  ebcb                   -jmp 0x4b5092
    goto L_0x004b5092;
L_0x004b50c7:
    // 004b50c7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b50c9  bf5e400000             -mov edi, 0x405e
    cpu.edi = 16478 /*0x405e*/;
    // 004b50ce  e811000000             -call 0x4b50e4
    cpu.esp -= 4;
    sub_4b50e4(app, cpu);
    if (cpu.terminate) return;
    // 004b50d3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b50d4  895504                 -mov dword ptr [ebp + 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004b50d7  894500                 -mov dword ptr [ebp], eax
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
    // 004b50da  66897508               -mov word ptr [ebp + 8], si
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.si;
    // 004b50de  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b50df  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b50e0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b50e1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b50e2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b50e3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b50e4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b50e4  29f6                   -sub esi, esi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004b50e6  09c6                   -or esi, eax
    cpu.esi |= x86::reg32(x86::sreg32(cpu.eax));
    // 004b50e8  09d6                   -or esi, edx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.edx));
    // 004b50ea  09ee                   +or esi, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.esi |= x86::reg32(x86::sreg32(cpu.ebp))));
    // 004b50ec  7436                   -je 0x4b5124
    if (cpu.flags.zf)
    {
        goto L_0x004b5124;
    }
    // 004b50ee  09d2                   +or edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx |= x86::reg32(x86::sreg32(cpu.edx))));
    // 004b50f0  7509                   -jne 0x4b50fb
    if (!cpu.flags.zf)
    {
        goto L_0x004b50fb;
    }
    // 004b50f2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b50f4  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004b50f6  29ed                   -sub ebp, ebp
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004b50f8  83ef20                 -sub edi, 0x20
    (cpu.edi) -= x86::reg32(x86::sreg32(32 /*0x20*/));
L_0x004b50fb:
    // 004b50fb  09d2                   +or edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx |= x86::reg32(x86::sreg32(cpu.edx))));
    // 004b50fd  7509                   -jne 0x4b5108
    if (!cpu.flags.zf)
    {
        goto L_0x004b5108;
    }
    // 004b50ff  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b5101  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004b5103  29ed                   -sub ebp, ebp
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004b5105  83ef20                 -sub edi, 0x20
    (cpu.edi) -= x86::reg32(x86::sreg32(32 /*0x20*/));
L_0x004b5108:
    // 004b5108  09d2                   +or edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx |= x86::reg32(x86::sreg32(cpu.edx))));
    // 004b510a  7809                   -js 0x4b5115
    if (cpu.flags.sf)
    {
        goto L_0x004b5115;
    }
    // 004b510c  4f                     -dec edi
    (cpu.edi)--;
    // 004b510d  01ed                   +add ebp, ebp
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b510f  11c0                   +adc eax, eax
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b5111  11d2                   +adc edx, edx
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
    // 004b5113  ebf3                   -jmp 0x4b5108
    goto L_0x004b5108;
L_0x004b5115:
    // 004b5115  01ed                   +add ebp, ebp
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebp));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b5117  83d000                 +adc eax, 0
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b511a  83d200                 +adc edx, 0
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b511d  7303                   -jae 0x4b5122
    if (!cpu.flags.cf)
    {
        goto L_0x004b5122;
    }
    // 004b511f  d1da                   -rcr edx, 1
    {
        x86::reg32& op = cpu.edx;
        x86::reg32 shift = 1 /*0x1*/ % 32;
        cpu.flags.of = (1 & (op >> 31)) ^ cpu.flags.cf;
        while (shift)
        {
            x86::reg32 cf = op & 1;
            op = op >> 1 | x86::reg32(cpu.flags.cf) << 31;
            cpu.flags.cf = cf;
            shift--;
        }
    }
    // 004b5121  47                     -inc edi
    (cpu.edi)++;
L_0x004b5122:
    // 004b5122  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
L_0x004b5124:
    // 004b5124  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_4b5128(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b5128  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b5129  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b512b  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004b512c  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b512f  8b7d0c                 -mov edi, dword ptr [ebp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b5132  8b6d10                 -mov ebp, dword ptr [ebp + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b5135  83f907                 +cmp ecx, 7
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
    // 004b5138  7e42                   -jle 0x4b517c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b517c;
    }
    // 004b513a  83e907                 -sub ecx, 7
    (cpu.ecx) -= x86::reg32(x86::sreg32(7 /*0x7*/));
L_0x004b513d:
    // 004b513d  df07                   -fild word ptr [edi]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.edi))));
    // 004b513f  df4702                 -fild word ptr [edi + 2]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.edi + x86::reg32(2) /* 0x2 */))));
    // 004b5142  df4704                 -fild word ptr [edi + 4]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.edi + x86::reg32(4) /* 0x4 */))));
    // 004b5145  df4706                 -fild word ptr [edi + 6]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.edi + x86::reg32(6) /* 0x6 */))));
    // 004b5148  df4708                 -fild word ptr [edi + 8]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.edi + x86::reg32(8) /* 0x8 */))));
    // 004b514b  df470a                 -fild word ptr [edi + 0xa]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.edi + x86::reg32(10) /* 0xa */))));
    // 004b514e  df470c                 -fild word ptr [edi + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.edi + x86::reg32(12) /* 0xc */))));
    // 004b5151  df470e                 -fild word ptr [edi + 0xe]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.edi + x86::reg32(14) /* 0xe */))));
    // 004b5154  d9cf                   -fxch st(7)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(7);
        cpu.fpu.st(7) = tmp;
    }
    // 004b5156  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b5159  d95d18                 -fstp dword ptr [ebp + 0x18]
    app->getMemory<float>(cpu.ebp + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b515c  d95d14                 -fstp dword ptr [ebp + 0x14]
    app->getMemory<float>(cpu.ebp + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b515f  d95d10                 -fstp dword ptr [ebp + 0x10]
    app->getMemory<float>(cpu.ebp + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b5162  d95d0c                 -fstp dword ptr [ebp + 0xc]
    app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b5165  d95d08                 -fstp dword ptr [ebp + 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b5168  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b516b  d95d1c                 -fstp dword ptr [ebp + 0x1c]
    app->getMemory<float>(cpu.ebp + x86::reg32(28) /* 0x1c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b516e  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b5171  83c520                 -add ebp, 0x20
    (cpu.ebp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004b5174  83e908                 +sub ecx, 8
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
    // 004b5177  7fc4                   -jg 0x4b513d
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b513d;
    }
    // 004b5179  83c107                 -add ecx, 7
    (cpu.ecx) += x86::reg32(x86::sreg32(7 /*0x7*/));
L_0x004b517c:
    // 004b517c  83f900                 +cmp ecx, 0
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
    // 004b517f  7e10                   -jle 0x4b5191
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b5191;
    }
    // 004b5181  df07                   -fild word ptr [edi]
    cpu.fpu.push(x86::Float(x86::sreg16(app->getMemory<x86::reg16>(cpu.edi))));
    // 004b5183  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b5186  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004b5189  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b518c  83e901                 +sub ecx, 1
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
    // 004b518f  7feb                   -jg 0x4b517c
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b517c;
    }
L_0x004b5191:
    // 004b5191  61                     -popal 
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
    // 004b5192  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5193  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b5194(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b5194  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b5195  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b5197  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004b5198  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b519b  8b7d0c                 -mov edi, dword ptr [ebp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b519e  8b6d10                 -mov ebp, dword ptr [ebp + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b51a1  33c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b51a3  33d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b51a5  83f903                 +cmp ecx, 3
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
    // 004b51a8  7e44                   -jle 0x4b51ee
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b51ee;
    }
    // 004b51aa  83e903                 -sub ecx, 3
    (cpu.ecx) -= x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x004b51ad:
    // 004b51ad  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 004b51af  8a5701                 -mov dl, byte ptr [edi + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 004b51b2  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b51b5  83c510                 -add ebp, 0x10
    (cpu.ebp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b51b8  8b1c85f0945400         -mov ebx, dword ptr [eax*4 + 0x5494f0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5543152) /* 0x5494f0 */ + cpu.eax * 4);
    // 004b51bf  8b3495f0945400         -mov esi, dword ptr [edx*4 + 0x5494f0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5543152) /* 0x5494f0 */ + cpu.edx * 4);
    // 004b51c6  8a47fe                 -mov al, byte ptr [edi - 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(-2) /* -0x2 */);
    // 004b51c9  8a57ff                 -mov dl, byte ptr [edi - 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(-1) /* -0x1 */);
    // 004b51cc  895df0                 -mov dword ptr [ebp - 0x10], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.ebx;
    // 004b51cf  8975f4                 -mov dword ptr [ebp - 0xc], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.esi;
    // 004b51d2  8b1c85f0945400         -mov ebx, dword ptr [eax*4 + 0x5494f0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5543152) /* 0x5494f0 */ + cpu.eax * 4);
    // 004b51d9  8b3495f0945400         -mov esi, dword ptr [edx*4 + 0x5494f0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5543152) /* 0x5494f0 */ + cpu.edx * 4);
    // 004b51e0  895df8                 -mov dword ptr [ebp - 8], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.ebx;
    // 004b51e3  8975fc                 -mov dword ptr [ebp - 4], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.esi;
    // 004b51e6  83e904                 +sub ecx, 4
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
    // 004b51e9  7fc2                   -jg 0x4b51ad
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b51ad;
    }
    // 004b51eb  83c103                 -add ecx, 3
    (cpu.ecx) += x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x004b51ee:
    // 004b51ee  83f900                 +cmp ecx, 0
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
    // 004b51f1  7e17                   -jle 0x4b520a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b520a;
    }
    // 004b51f3  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 004b51f5  83c701                 -add edi, 1
    (cpu.edi) += x86::reg32(x86::sreg32(1 /*0x1*/));
    // 004b51f8  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b51fb  8b1c85f0945400         -mov ebx, dword ptr [eax*4 + 0x5494f0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5543152) /* 0x5494f0 */ + cpu.eax * 4);
    // 004b5202  895dfc                 -mov dword ptr [ebp - 4], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 004b5205  83e901                 +sub ecx, 1
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
    // 004b5208  7fe4                   -jg 0x4b51ee
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b51ee;
    }
L_0x004b520a:
    // 004b520a  61                     -popal 
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
    // 004b520b  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b520c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b520d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b520d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b520e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b520f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b5210  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004b5211  0fa0                   -push fs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.fs;
    cpu.esp -= 4;
    // 004b5213  0fa8                   -push gs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.gs;
    cpu.esp -= 4;
    // 004b5215  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b5216  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b5218  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b521b  8b7520                 -mov esi, dword ptr [ebp + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 004b521e  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004b5220  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 004b5223  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004b5226  8b15cc4f5400           -mov edx, dword ptr [0x544fcc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5525452) /* 0x544fcc */);
    // 004b522c  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004b522e  8b7e04                 -mov edi, dword ptr [esi + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b5231  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004b5234  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b5236  753e                   -jne 0x4b5276
    if (!cpu.flags.zf)
    {
        goto L_0x004b5276;
    }
    // 004b5238  a16cf84c00             -mov eax, dword ptr [0x4cf86c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5044332) /* 0x4cf86c */);
    // 004b523d  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004b5240  24fc                   -and al, 0xfc
    cpu.al &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 004b5242  29c4                   -sub esp, eax
    (cpu.esp) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004b5244  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 004b5246  8b1d6cf84c00           -mov ebx, dword ptr [0x4cf86c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5044332) /* 0x4cf86c */);
    // 004b524c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b524e  e85c40fdff             -call 0x4892af
    cpu.esp -= 4;
    sub_4892af(app, cpu);
    if (cpu.terminate) return;
    // 004b5253  a16cf84c00             -mov eax, dword ptr [0x4cf86c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5044332) /* 0x4cf86c */);
    // 004b5258  8981f0000000           -mov dword ptr [ecx + 0xf0], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(240) /* 0xf0 */) = cpu.eax;
    // 004b525e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b5260  e82460ffff             -call 0x4ab289
    cpu.esp -= 4;
    sub_4ab289(app, cpu);
    if (cpu.terminate) return;
    // 004b5265  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b5267  750d                   -jne 0x4b5276
    if (!cpu.flags.zf)
    {
        goto L_0x004b5276;
    }
    // 004b5269  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004b526c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b526d  2eff1550744b00         -call dword ptr cs:[0x4b7450]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944976) /* 0x4b7450 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b5274  eb32                   -jmp 0x4b52a8
    goto L_0x004b52a8;
L_0x004b5276:
    // 004b5276  8b5dfc                 -mov ebx, dword ptr [ebp - 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004b5279  ff1588e34c00           -call dword ptr [0x4ce388]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5038984) /* 0x4ce388 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b527f  8998de000000           -mov dword ptr [eax + 0xde], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(222) /* 0xde */) = cpu.ebx;
    // 004b5285  8b5e0c                 -mov ebx, dword ptr [esi + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004b5288  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b5289  2eff1584754b00         -call dword ptr cs:[0x4b7584]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945284) /* 0x4b7584 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b5290  8d45f0                 -lea eax, [ebp - 0x10]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004b5293  e8cb67ffff             -call 0x4aba63
    cpu.esp -= 4;
    sub_4aba63(app, cpu);
    if (cpu.terminate) return;
    // 004b5298  ff15c8e34c00           -call dword ptr [0x4ce3c8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5039048) /* 0x4ce3c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b529e  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004b52a0  ff55f8                 -call dword ptr [ebp - 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b52a3  e811fbffff             -call 0x4b4db9
    cpu.esp -= 4;
    sub_4b4db9(app, cpu);
    if (cpu.terminate) return;
L_0x004b52a8:
    // 004b52a8  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004b52aa  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b52ab  0fa9                   -pop gs
    cpu.gs = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004b52ad  0fa1                   -pop fs
    cpu.fs = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004b52af  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004b52b0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b52b1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b52b2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b52b3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b52b4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b52b4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b52b5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b52b6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b52b7  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004b52b8  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b52b9  83ec3c                 -sub esp, 0x3c
    (cpu.esp) -= x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 004b52bc  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004b52be  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004b52c0  833d84e34c00ff         +cmp dword ptr [0x4ce384], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5038980) /* 0x4ce384 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b52c7  7512                   -jne 0x4b52db
    if (!cpu.flags.zf)
    {
        goto L_0x004b52db;
    }
    // 004b52c9  e8665fffff             -call 0x4ab234
    cpu.esp -= 4;
    sub_4ab234(app, cpu);
    if (cpu.terminate) return;
    // 004b52ce  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b52d0  0f84ae000000           -je 0x4b5384
    if (cpu.flags.zf)
    {
        goto L_0x004b5384;
    }
    // 004b52d6  e87e60ffff             -call 0x4ab359
    cpu.esp -= 4;
    sub_4ab359(app, cpu);
    if (cpu.terminate) return;
L_0x004b52db:
    // 004b52db  894c2420               -mov dword ptr [esp + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 004b52df  895c2424               -mov dword ptr [esp + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 004b52e3  2eff15cc744b00         -call dword ptr cs:[0x4b74cc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945100) /* 0x4b74cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b52ea  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 004b52ee  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004b52f0  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 004b52f2  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004b52f4  be801d4c00             -mov esi, 0x4c1d80
    cpu.esi = 4988288 /*0x4c1d80*/;
    // 004b52f9  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 004b52fe  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004b52ff  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004b5300  a4                     -movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004b5301  2eff15c8744b00         -call dword ptr cs:[0x4b74c8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945096) /* 0x4b74c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b5308  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b530c  e8608cffff             -call 0x4adf71
    cpu.esp -= 4;
    sub_4adf71(app, cpu);
    if (cpu.terminate) return;
    // 004b5311  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b5313  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b5314  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004b5316  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004b5318  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004b531a  2eff1554744b00         -call dword ptr cs:[0x4b7454]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944980) /* 0x4b7454 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b5321  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 004b5325  8d442434               -lea eax, [esp + 0x34]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004b5329  89442430               -mov dword ptr [esp + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 004b532d  8d442438               -lea eax, [esp + 0x38]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 004b5331  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b5332  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004b5334  8d442428               -lea eax, [esp + 0x28]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004b5338  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b5339  81c5ff0f0000           -add ebp, 0xfff
    (cpu.ebp) += x86::reg32(x86::sreg32(4095 /*0xfff*/));
    // 004b533f  680d524b00             -push 0x4b520d
    app->getMemory<x86::reg32>(cpu.esp-4) = 4936205 /*0x4b520d*/;
    cpu.esp -= 4;
    // 004b5344  81e500f0ffff           -and ebp, 0xfffff000
    cpu.ebp &= x86::reg32(x86::sreg32(4294963200 /*0xfffff000*/));
    // 004b534a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b534b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004b534d  2eff1564744b00         -call dword ptr cs:[0x4b7464]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944996) /* 0x4b7464 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b5354  89442434               -mov dword ptr [esp + 0x34], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 004b5358  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b535a  750a                   -jne 0x4b5366
    if (!cpu.flags.zf)
    {
        goto L_0x004b5366;
    }
    // 004b535c  c7442438ffffffff       -mov dword ptr [esp + 0x38], 0xffffffff
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = 4294967295 /*0xffffffff*/;
    // 004b5364  eb0e                   -jmp 0x4b5374
    goto L_0x004b5374;
L_0x004b5366:
    // 004b5366  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 004b5368  8b5c2430               -mov ebx, dword ptr [esp + 0x30]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004b536c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b536d  2eff15d0754b00         -call dword ptr cs:[0x4b75d0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945360) /* 0x4b75d0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004b5374:
    // 004b5374  8b74242c               -mov esi, dword ptr [esp + 0x2c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004b5378  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b5379  2eff1550744b00         -call dword ptr cs:[0x4b7450]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944976) /* 0x4b7450 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b5380  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
L_0x004b5384:
    // 004b5384  83c43c                 -add esp, 0x3c
    (cpu.esp) += x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 004b5387  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5388  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004b5389  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b538a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b538b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b538c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b538d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b538d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b538e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b538f  ff15cce34c00           -call dword ptr [0x4ce3cc]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5039052) /* 0x4ce3cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b5395  e81567ffff             -call 0x4abaaf
    cpu.esp -= 4;
    sub_4abaaf(app, cpu);
    if (cpu.terminate) return;
    // 004b539a  833dcc4f540000         +cmp dword ptr [0x544fcc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5525452) /* 0x544fcc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b53a1  750a                   -jne 0x4b53ad
    if (!cpu.flags.zf)
    {
        goto L_0x004b53ad;
    }
    // 004b53a3  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004b53a8  e82b5fffff             -call 0x4ab2d8
    cpu.esp -= 4;
    sub_4ab2d8(app, cpu);
    if (cpu.terminate) return;
L_0x004b53ad:
    // 004b53ad  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004b53af  2eff1584744b00         -call dword ptr cs:[0x4b7484]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945028) /* 0x4b7484 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b53b6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b53b7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b53b8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b53b9(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b53b9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b53ba  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b53bb  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b53bc  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004b53bf  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b53c0  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004b53c2  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004b53c4  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004b53c8  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b53ca  7402                   -je 0x4b53ce
    if (cpu.flags.zf)
    {
        goto L_0x004b53ce;
    }
    // 004b53cc  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
L_0x004b53ce:
    // 004b53ce  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
L_0x004b53d1:
    // 004b53d1  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 004b53d3  fec0                   -inc al
    (cpu.al)++;
    // 004b53d5  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b53da  f680c8ea4c0002         +test byte ptr [eax + 0x4ceac8], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5040840) /* 0x4ceac8 */) & 2 /*0x2*/));
    // 004b53e1  7403                   -je 0x4b53e6
    if (cpu.flags.zf)
    {
        goto L_0x004b53e6;
    }
    // 004b53e3  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004b53e4  ebeb                   -jmp 0x4b53d1
    goto L_0x004b53d1;
L_0x004b53e6:
    // 004b53e6  8a2a                   -mov ch, byte ptr [edx]
    cpu.ch = app->getMemory<x86::reg8>(cpu.edx);
    // 004b53e8  80fd2b                 +cmp ch, 0x2b
    {
        x86::reg8 tmp1 = cpu.ch;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(43 /*0x2b*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b53eb  7405                   -je 0x4b53f2
    if (cpu.flags.zf)
    {
        goto L_0x004b53f2;
    }
    // 004b53ed  80fd2d                 +cmp ch, 0x2d
    {
        x86::reg8 tmp1 = cpu.ch;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(45 /*0x2d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b53f0  7501                   -jne 0x4b53f3
    if (!cpu.flags.zf)
    {
        goto L_0x004b53f3;
    }
L_0x004b53f2:
    // 004b53f2  42                     -inc edx
    (cpu.edx)++;
L_0x004b53f3:
    // 004b53f3  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004b53f5  752c                   -jne 0x4b5423
    if (!cpu.flags.zf)
    {
        goto L_0x004b5423;
    }
    // 004b53f7  803a30                 +cmp byte ptr [edx], 0x30
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b53fa  7514                   -jne 0x4b5410
    if (!cpu.flags.zf)
    {
        goto L_0x004b5410;
    }
    // 004b53fc  8a4a01                 -mov cl, byte ptr [edx + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004b53ff  80f978                 +cmp cl, 0x78
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(120 /*0x78*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b5402  7405                   -je 0x4b5409
    if (cpu.flags.zf)
    {
        goto L_0x004b5409;
    }
    // 004b5404  80f958                 +cmp cl, 0x58
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(88 /*0x58*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b5407  7507                   -jne 0x4b5410
    if (!cpu.flags.zf)
    {
        goto L_0x004b5410;
    }
L_0x004b5409:
    // 004b5409  be10000000             -mov esi, 0x10
    cpu.esi = 16 /*0x10*/;
    // 004b540e  eb33                   -jmp 0x4b5443
    goto L_0x004b5443;
L_0x004b5410:
    // 004b5410  803a30                 +cmp byte ptr [edx], 0x30
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b5413  7507                   -jne 0x4b541c
    if (!cpu.flags.zf)
    {
        goto L_0x004b541c;
    }
    // 004b5415  be08000000             -mov esi, 8
    cpu.esi = 8 /*0x8*/;
    // 004b541a  eb3c                   -jmp 0x4b5458
    goto L_0x004b5458;
L_0x004b541c:
    // 004b541c  be0a000000             -mov esi, 0xa
    cpu.esi = 10 /*0xa*/;
    // 004b5421  eb35                   -jmp 0x4b5458
    goto L_0x004b5458;
L_0x004b5423:
    // 004b5423  83fe02                 +cmp esi, 2
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
    // 004b5426  7c05                   -jl 0x4b542d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b542d;
    }
    // 004b5428  83fe24                 +cmp esi, 0x24
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(36 /*0x24*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b542b  7e11                   -jle 0x4b543e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b543e;
    }
L_0x004b542d:
    // 004b542d  b80d000000             -mov eax, 0xd
    cpu.eax = 13 /*0xd*/;
    // 004b5432  e8c94cfeff             -call 0x49a100
    cpu.esp -= 4;
    sub_49a100(app, cpu);
    if (cpu.terminate) return;
    // 004b5437  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004b5439  e9b3000000             -jmp 0x4b54f1
    goto L_0x004b54f1;
L_0x004b543e:
    // 004b543e  83fe10                 +cmp esi, 0x10
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
    // 004b5441  7515                   -jne 0x4b5458
    if (!cpu.flags.zf)
    {
        goto L_0x004b5458;
    }
L_0x004b5443:
    // 004b5443  803a30                 +cmp byte ptr [edx], 0x30
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b5446  7510                   -jne 0x4b5458
    if (!cpu.flags.zf)
    {
        goto L_0x004b5458;
    }
    // 004b5448  8a7a01                 -mov bh, byte ptr [edx + 1]
    cpu.bh = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004b544b  80ff78                 +cmp bh, 0x78
    {
        x86::reg8 tmp1 = cpu.bh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(120 /*0x78*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b544e  7405                   -je 0x4b5455
    if (cpu.flags.zf)
    {
        goto L_0x004b5455;
    }
    // 004b5450  80ff58                 +cmp bh, 0x58
    {
        x86::reg8 tmp1 = cpu.bh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(88 /*0x58*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b5453  7503                   -jne 0x4b5458
    if (!cpu.flags.zf)
    {
        goto L_0x004b5458;
    }
L_0x004b5455:
    // 004b5455  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x004b5458:
    // 004b5458  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004b545c  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 004b545e  30c9                   -xor cl, cl
    cpu.cl ^= x86::reg8(x86::sreg8(cpu.cl));
    // 004b5460  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b5462  c1e702                 -shl edi, 2
    cpu.edi <<= 2 /*0x2*/ % 32;
L_0x004b5465:
    // 004b5465  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b5467  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 004b5469  e89c000000             -call 0x4b550a
    cpu.esp -= 4;
    sub_4b550a(app, cpu);
    if (cpu.terminate) return;
    // 004b546e  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b5472  39f0                   +cmp eax, esi
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
    // 004b5474  7d1c                   -jge 0x4b5492
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b5492;
    }
    // 004b5476  3b9fd4004d00           +cmp ebx, dword ptr [edi + 0x4d00d4]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5046484) /* 0x4d00d4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b547c  7602                   -jbe 0x4b5480
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b5480;
    }
    // 004b547e  b101                   -mov cl, 1
    cpu.cl = 1 /*0x1*/;
L_0x004b5480:
    // 004b5480  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b5482  0fafde                 -imul ebx, esi
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 004b5485  035c2408               -add ebx, dword ptr [esp + 8]
    (cpu.ebx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 004b5489  39c3                   +cmp ebx, eax
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
    // 004b548b  7302                   -jae 0x4b548f
    if (!cpu.flags.cf)
    {
        goto L_0x004b548f;
    }
    // 004b548d  b101                   -mov cl, 1
    cpu.cl = 1 /*0x1*/;
L_0x004b548f:
    // 004b548f  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004b5490  ebd3                   -jmp 0x4b5465
    goto L_0x004b5465;
L_0x004b5492:
    // 004b5492  3b542404               +cmp edx, dword ptr [esp + 4]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b5496  7503                   -jne 0x4b549b
    if (!cpu.flags.zf)
    {
        goto L_0x004b549b;
    }
    // 004b5498  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
L_0x004b549b:
    // 004b549b  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004b549d  7403                   -je 0x4b54a2
    if (cpu.flags.zf)
    {
        goto L_0x004b54a2;
    }
    // 004b549f  895500                 -mov dword ptr [ebp], edx
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.edx;
L_0x004b54a2:
    // 004b54a2  837c240c01             +cmp dword ptr [esp + 0xc], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b54a7  750f                   -jne 0x4b54b8
    if (!cpu.flags.zf)
    {
        goto L_0x004b54b8;
    }
    // 004b54a9  81fb00000080           +cmp ebx, 0x80000000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2147483648 /*0x80000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b54af  7207                   -jb 0x4b54b8
    if (cpu.flags.cf)
    {
        goto L_0x004b54b8;
    }
    // 004b54b1  7509                   -jne 0x4b54bc
    if (!cpu.flags.zf)
    {
        goto L_0x004b54bc;
    }
    // 004b54b3  80fd2d                 +cmp ch, 0x2d
    {
        x86::reg8 tmp1 = cpu.ch;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(45 /*0x2d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b54b6  7504                   -jne 0x4b54bc
    if (!cpu.flags.zf)
    {
        goto L_0x004b54bc;
    }
L_0x004b54b8:
    // 004b54b8  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 004b54ba  742c                   -je 0x4b54e8
    if (cpu.flags.zf)
    {
        goto L_0x004b54e8;
    }
L_0x004b54bc:
    // 004b54bc  b80e000000             -mov eax, 0xe
    cpu.eax = 14 /*0xe*/;
    // 004b54c1  8b6c240c               -mov ebp, dword ptr [esp + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b54c5  e8364cfeff             -call 0x49a100
    cpu.esp -= 4;
    sub_49a100(app, cpu);
    if (cpu.terminate) return;
    // 004b54ca  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004b54cc  7507                   -jne 0x4b54d5
    if (!cpu.flags.zf)
    {
        goto L_0x004b54d5;
    }
    // 004b54ce  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004b54d3  eb1c                   -jmp 0x4b54f1
    goto L_0x004b54f1;
L_0x004b54d5:
    // 004b54d5  80fd2d                 +cmp ch, 0x2d
    {
        x86::reg8 tmp1 = cpu.ch;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(45 /*0x2d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b54d8  7507                   -jne 0x4b54e1
    if (!cpu.flags.zf)
    {
        goto L_0x004b54e1;
    }
    // 004b54da  b800000080             -mov eax, 0x80000000
    cpu.eax = 2147483648 /*0x80000000*/;
    // 004b54df  eb10                   -jmp 0x4b54f1
    goto L_0x004b54f1;
L_0x004b54e1:
    // 004b54e1  b8ffffff7f             -mov eax, 0x7fffffff
    cpu.eax = 2147483647 /*0x7fffffff*/;
    // 004b54e6  eb09                   -jmp 0x4b54f1
    goto L_0x004b54f1;
L_0x004b54e8:
    // 004b54e8  80fd2d                 +cmp ch, 0x2d
    {
        x86::reg8 tmp1 = cpu.ch;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(45 /*0x2d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b54eb  7502                   -jne 0x4b54ef
    if (!cpu.flags.zf)
    {
        goto L_0x004b54ef;
    }
    // 004b54ed  f7db                   -neg ebx
    cpu.ebx = ~cpu.ebx + 1;
L_0x004b54ef:
    // 004b54ef  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x004b54f1:
    // 004b54f1  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b54f4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b54f5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b54f6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b54f7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b54f8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b54f8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b54f9  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b54fb  e8b9feffff             -call 0x4b53b9
    cpu.esp -= 4;
    sub_4b53b9(app, cpu);
    if (cpu.terminate) return;
    // 004b5500  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5501  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b54fb(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004b54fb;
    // 004b54f8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b54f9  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_entry_0x004b54fb:
    // 004b54fb  e8b9feffff             -call 0x4b53b9
    cpu.esp -= 4;
    sub_4b53b9(app, cpu);
    if (cpu.terminate) return;
    // 004b5500  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5501  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b5502(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b5502  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b5503  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004b5508  ebf1                   -jmp 0x4b54fb
    return sub_4b54fb(app, cpu);
}

/* align: skip  */
void Application::sub_4b550a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b550a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b550b  3c30                   +cmp al, 0x30
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b550d  720e                   -jb 0x4b551d
    if (cpu.flags.cf)
    {
        goto L_0x004b551d;
    }
    // 004b550f  3c39                   +cmp al, 0x39
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(57 /*0x39*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b5511  770a                   -ja 0x4b551d
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004b551d;
    }
    // 004b5513  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b5518  83e830                 -sub eax, 0x30
    (cpu.eax) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 004b551b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b551c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b551d:
    // 004b551d  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b5522  e8647efeff             -call 0x49d38b
    cpu.esp -= 4;
    sub_49d38b(app, cpu);
    if (cpu.terminate) return;
    // 004b5527  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b5529  3c61                   +cmp al, 0x61
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(97 /*0x61*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b552b  720d                   -jb 0x4b553a
    if (cpu.flags.cf)
    {
        goto L_0x004b553a;
    }
    // 004b552d  3c69                   +cmp al, 0x69
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(105 /*0x69*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b552f  7709                   -ja 0x4b553a
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004b553a;
    }
    // 004b5531  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b5533  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 004b5535  83e857                 -sub eax, 0x57
    (cpu.eax) -= x86::reg32(x86::sreg32(87 /*0x57*/));
    // 004b5538  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5539  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b553a:
    // 004b553a  3c6a                   +cmp al, 0x6a
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(106 /*0x6a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b553c  720e                   -jb 0x4b554c
    if (cpu.flags.cf)
    {
        goto L_0x004b554c;
    }
    // 004b553e  3c72                   +cmp al, 0x72
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(114 /*0x72*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b5540  770a                   -ja 0x4b554c
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004b554c;
    }
L_0x004b5542:
    // 004b5542  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b5547  83e857                 -sub eax, 0x57
    (cpu.eax) -= x86::reg32(x86::sreg32(87 /*0x57*/));
    // 004b554a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b554b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b554c:
    // 004b554c  3c73                   +cmp al, 0x73
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(115 /*0x73*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b554e  7204                   -jb 0x4b5554
    if (cpu.flags.cf)
    {
        goto L_0x004b5554;
    }
    // 004b5550  3c7a                   +cmp al, 0x7a
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(122 /*0x7a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b5552  76ee                   -jbe 0x4b5542
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b5542;
    }
L_0x004b5554:
    // 004b5554  b825000000             -mov eax, 0x25
    cpu.eax = 37 /*0x25*/;
    // 004b5559  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b555a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b555b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b555b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b555c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b555d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b555e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b555f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b5560  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b5561  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004b5564  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004b5566  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 004b556b  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004b5570  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004b5573  ba3d000000             -mov edx, 0x3d
    cpu.edx = 61 /*0x3d*/;
    // 004b5578  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004b557c  e855040000             -call 0x4b59d6
    cpu.esp -= 4;
    sub_4b59d6(app, cpu);
    if (cpu.terminate) return;
    // 004b5581  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b5583  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b5585  7469                   -je 0x4b55f0
    if (cpu.flags.zf)
    {
        goto L_0x004b55f0;
    }
    // 004b5587  39e8                   +cmp eax, ebp
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
    // 004b5589  7465                   -je 0x4b55f0
    if (cpu.flags.zf)
    {
        goto L_0x004b55f0;
    }
    // 004b558b  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004b558d  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004b5591  40                     -inc eax
    (cpu.eax)++;
    // 004b5592  e87c4afeff             -call 0x49a013
    cpu.esp -= 4;
    malloc(app, cpu);
    if (cpu.terminate) return;
    // 004b5597  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b5599  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b559d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b559f  744f                   -je 0x4b55f0
    if (cpu.flags.zf)
    {
        goto L_0x004b55f0;
    }
    // 004b55a1  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b55a5  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
    // 004b55a7  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004b55a9  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004b55aa  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004b55ac  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004b55ae  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b55af  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b55b1  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004b55b4  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b55b6  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004b55b8  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004b55bb  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004b55bd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b55be  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004b55bf  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b55c3  8d7301                 -lea esi, [ebx + 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004b55c6  c6040200               -mov byte ptr [edx + eax], 0
    app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1) = 0 /*0x0*/;
    // 004b55ca  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b55cc  e861040000             -call 0x4b5a32
    cpu.esp -= 4;
    sub_4b5a32(app, cpu);
    if (cpu.terminate) return;
    // 004b55d1  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004b55d5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b55d7  7446                   -je 0x4b561f
    if (cpu.flags.zf)
    {
        goto L_0x004b561f;
    }
    // 004b55d9  40                     -inc eax
    (cpu.eax)++;
    // 004b55da  e8344afeff             -call 0x49a013
    cpu.esp -= 4;
    malloc(app, cpu);
    if (cpu.terminate) return;
    // 004b55df  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b55e1  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004b55e5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b55e7  7511                   -jne 0x4b55fa
    if (!cpu.flags.zf)
    {
        goto L_0x004b55fa;
    }
    // 004b55e9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x004b55eb:
    // 004b55eb  e8b99afeff             -call 0x49f0a9
    cpu.esp -= 4;
    sub_49f0a9(app, cpu);
    if (cpu.terminate) return;
L_0x004b55f0:
    // 004b55f0  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004b55f5  e9af000000             -jmp 0x4b56a9
    goto L_0x004b56a9;
L_0x004b55fa:
    // 004b55fa  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004b55fe  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004b5600  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004b5601  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004b5603  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004b5605  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b5606  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b5608  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004b560b  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b560d  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004b560f  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004b5612  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004b5614  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5615  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004b5616  035c2414               +add ebx, dword ptr [esp + 0x14]
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b561a  c60300                 -mov byte ptr [ebx], 0
    app->getMemory<x86::reg8>(cpu.ebx) = 0 /*0x0*/;
    // 004b561d  eb04                   -jmp 0x4b5623
    goto L_0x004b5623;
L_0x004b561f:
    // 004b561f  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x004b5623:
    // 004b5623  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b5627  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b5628  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b562c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b562d  2eff157c754b00         -call dword ptr cs:[0x4b757c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945276) /* 0x4b757c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b5634  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b5636  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b563a  e86a9afeff             -call 0x49f0a9
    cpu.esp -= 4;
    sub_49f0a9(app, cpu);
    if (cpu.terminate) return;
    // 004b563f  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b5643  e8619afeff             -call 0x49f0a9
    cpu.esp -= 4;
    sub_49f0a9(app, cpu);
    if (cpu.terminate) return;
    // 004b5648  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b564a  74a4                   -je 0x4b55f0
    if (cpu.flags.zf)
    {
        goto L_0x004b55f0;
    }
    // 004b564c  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004b564e  e860000000             -call 0x4b56b3
    cpu.esp -= 4;
    sub_4b56b3(app, cpu);
    if (cpu.terminate) return;
    // 004b5653  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b5655  7599                   -jne 0x4b55f0
    if (!cpu.flags.zf)
    {
        goto L_0x004b55f0;
    }
    // 004b5657  833dd093540000         +cmp dword ptr [0x5493d0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5542864) /* 0x5493d0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b565e  7449                   -je 0x4b56a9
    if (cpu.flags.zf)
    {
        goto L_0x004b56a9;
    }
    // 004b5660  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004b5662  e8cb030000             -call 0x4b5a32
    cpu.esp -= 4;
    sub_4b5a32(app, cpu);
    if (cpu.terminate) return;
    // 004b5667  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b566a  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004b566d  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004b5670  e89e49feff             -call 0x49a013
    cpu.esp -= 4;
    malloc(app, cpu);
    if (cpu.terminate) return;
    // 004b5675  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004b5677  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b5679  750f                   -jne 0x4b568a
    if (!cpu.flags.zf)
    {
        goto L_0x004b568a;
    }
    // 004b567b  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 004b5680  e82c49feff             -call 0x499fb1
    cpu.esp -= 4;
    sub_499fb1(app, cpu);
    if (cpu.terminate) return;
    // 004b5685  e966ffffff             -jmp 0x4b55f0
    goto L_0x004b55f0;
L_0x004b568a:
    // 004b568a  0faf5c2404             -imul ebx, dword ptr [esp + 4]
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */))));
    // 004b568f  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004b5691  e8be030000             -call 0x4b5a54
    cpu.esp -= 4;
    sub_4b5a54(app, cpu);
    if (cpu.terminate) return;
    // 004b5696  83f8ff                 +cmp eax, -1
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
    // 004b5699  7507                   -jne 0x4b56a2
    if (!cpu.flags.zf)
    {
        goto L_0x004b56a2;
    }
    // 004b569b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b569d  e949ffffff             -jmp 0x4b55eb
    goto L_0x004b55eb;
L_0x004b56a2:
    // 004b56a2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b56a4  e849050000             -call 0x4b5bf2
    cpu.esp -= 4;
    sub_4b5bf2(app, cpu);
    if (cpu.terminate) return;
L_0x004b56a9:
    // 004b56a9  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004b56ac  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b56ad  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b56ae  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b56af  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b56b0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b56b1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b56b2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b56ac(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004b56ac;
    // 004b555b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b555c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b555d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b555e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b555f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b5560  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b5561  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004b5564  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004b5566  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 004b556b  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004b5570  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004b5573  ba3d000000             -mov edx, 0x3d
    cpu.edx = 61 /*0x3d*/;
    // 004b5578  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004b557c  e855040000             -call 0x4b59d6
    cpu.esp -= 4;
    sub_4b59d6(app, cpu);
    if (cpu.terminate) return;
    // 004b5581  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b5583  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b5585  7469                   -je 0x4b55f0
    if (cpu.flags.zf)
    {
        goto L_0x004b55f0;
    }
    // 004b5587  39e8                   +cmp eax, ebp
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
    // 004b5589  7465                   -je 0x4b55f0
    if (cpu.flags.zf)
    {
        goto L_0x004b55f0;
    }
    // 004b558b  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004b558d  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004b5591  40                     -inc eax
    (cpu.eax)++;
    // 004b5592  e87c4afeff             -call 0x49a013
    cpu.esp -= 4;
    malloc(app, cpu);
    if (cpu.terminate) return;
    // 004b5597  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b5599  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b559d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b559f  744f                   -je 0x4b55f0
    if (cpu.flags.zf)
    {
        goto L_0x004b55f0;
    }
    // 004b55a1  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b55a5  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
    // 004b55a7  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004b55a9  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004b55aa  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004b55ac  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004b55ae  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b55af  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b55b1  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004b55b4  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b55b6  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004b55b8  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004b55bb  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004b55bd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b55be  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004b55bf  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b55c3  8d7301                 -lea esi, [ebx + 1]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004b55c6  c6040200               -mov byte ptr [edx + eax], 0
    app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1) = 0 /*0x0*/;
    // 004b55ca  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b55cc  e861040000             -call 0x4b5a32
    cpu.esp -= 4;
    sub_4b5a32(app, cpu);
    if (cpu.terminate) return;
    // 004b55d1  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004b55d5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b55d7  7446                   -je 0x4b561f
    if (cpu.flags.zf)
    {
        goto L_0x004b561f;
    }
    // 004b55d9  40                     -inc eax
    (cpu.eax)++;
    // 004b55da  e8344afeff             -call 0x49a013
    cpu.esp -= 4;
    malloc(app, cpu);
    if (cpu.terminate) return;
    // 004b55df  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b55e1  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004b55e5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b55e7  7511                   -jne 0x4b55fa
    if (!cpu.flags.zf)
    {
        goto L_0x004b55fa;
    }
    // 004b55e9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x004b55eb:
    // 004b55eb  e8b99afeff             -call 0x49f0a9
    cpu.esp -= 4;
    sub_49f0a9(app, cpu);
    if (cpu.terminate) return;
L_0x004b55f0:
    // 004b55f0  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004b55f5  e9af000000             -jmp 0x4b56a9
    goto L_0x004b56a9;
L_0x004b55fa:
    // 004b55fa  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004b55fe  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004b5600  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004b5601  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004b5603  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004b5605  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b5606  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b5608  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004b560b  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b560d  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004b560f  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004b5612  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004b5614  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5615  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004b5616  035c2414               +add ebx, dword ptr [esp + 0x14]
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b561a  c60300                 -mov byte ptr [ebx], 0
    app->getMemory<x86::reg8>(cpu.ebx) = 0 /*0x0*/;
    // 004b561d  eb04                   -jmp 0x4b5623
    goto L_0x004b5623;
L_0x004b561f:
    // 004b561f  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x004b5623:
    // 004b5623  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b5627  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b5628  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b562c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b562d  2eff157c754b00         -call dword ptr cs:[0x4b757c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945276) /* 0x4b757c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b5634  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b5636  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b563a  e86a9afeff             -call 0x49f0a9
    cpu.esp -= 4;
    sub_49f0a9(app, cpu);
    if (cpu.terminate) return;
    // 004b563f  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b5643  e8619afeff             -call 0x49f0a9
    cpu.esp -= 4;
    sub_49f0a9(app, cpu);
    if (cpu.terminate) return;
    // 004b5648  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b564a  74a4                   -je 0x4b55f0
    if (cpu.flags.zf)
    {
        goto L_0x004b55f0;
    }
    // 004b564c  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004b564e  e860000000             -call 0x4b56b3
    cpu.esp -= 4;
    sub_4b56b3(app, cpu);
    if (cpu.terminate) return;
    // 004b5653  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b5655  7599                   -jne 0x4b55f0
    if (!cpu.flags.zf)
    {
        goto L_0x004b55f0;
    }
    // 004b5657  833dd093540000         +cmp dword ptr [0x5493d0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5542864) /* 0x5493d0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b565e  7449                   -je 0x4b56a9
    if (cpu.flags.zf)
    {
        goto L_0x004b56a9;
    }
    // 004b5660  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004b5662  e8cb030000             -call 0x4b5a32
    cpu.esp -= 4;
    sub_4b5a32(app, cpu);
    if (cpu.terminate) return;
    // 004b5667  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b566a  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004b566d  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004b5670  e89e49feff             -call 0x49a013
    cpu.esp -= 4;
    malloc(app, cpu);
    if (cpu.terminate) return;
    // 004b5675  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004b5677  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b5679  750f                   -jne 0x4b568a
    if (!cpu.flags.zf)
    {
        goto L_0x004b568a;
    }
    // 004b567b  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 004b5680  e82c49feff             -call 0x499fb1
    cpu.esp -= 4;
    sub_499fb1(app, cpu);
    if (cpu.terminate) return;
    // 004b5685  e966ffffff             -jmp 0x4b55f0
    goto L_0x004b55f0;
L_0x004b568a:
    // 004b568a  0faf5c2404             -imul ebx, dword ptr [esp + 4]
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */))));
    // 004b568f  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004b5691  e8be030000             -call 0x4b5a54
    cpu.esp -= 4;
    sub_4b5a54(app, cpu);
    if (cpu.terminate) return;
    // 004b5696  83f8ff                 +cmp eax, -1
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
    // 004b5699  7507                   -jne 0x4b56a2
    if (!cpu.flags.zf)
    {
        goto L_0x004b56a2;
    }
    // 004b569b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b569d  e949ffffff             -jmp 0x4b55eb
    goto L_0x004b55eb;
L_0x004b56a2:
    // 004b56a2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b56a4  e849050000             -call 0x4b5bf2
    cpu.esp -= 4;
    sub_4b5bf2(app, cpu);
    if (cpu.terminate) return;
L_0x004b56a9:
    // 004b56a9  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
L_entry_0x004b56ac:
    // 004b56ac  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b56ad  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b56ae  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b56af  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b56b0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b56b1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b56b2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b56b3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b56b3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b56b4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b56b5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b56b6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b56b7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b56b8  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b56b9  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b56bc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b56bd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b56bf  750a                   -jne 0x4b56cb
    if (!cpu.flags.zf)
    {
        goto L_0x004b56cb;
    }
L_0x004b56c1:
    // 004b56c1  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004b56c6  e94b010000             -jmp 0x4b5816
    goto L_0x004b5816;
L_0x004b56cb:
    // 004b56cb  803800                 +cmp byte ptr [eax], 0
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
    // 004b56ce  7411                   -je 0x4b56e1
    if (cpu.flags.zf)
    {
        goto L_0x004b56e1;
    }
    // 004b56d0  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b56d3  eb06                   -jmp 0x4b56db
    goto L_0x004b56db;
L_0x004b56d5:
    // 004b56d5  80ff3d                 +cmp bh, 0x3d
    {
        x86::reg8 tmp1 = cpu.bh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(61 /*0x3d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b56d8  7407                   -je 0x4b56e1
    if (cpu.flags.zf)
    {
        goto L_0x004b56e1;
    }
    // 004b56da  42                     -inc edx
    (cpu.edx)++;
L_0x004b56db:
    // 004b56db  8a3a                   -mov bh, byte ptr [edx]
    cpu.bh = app->getMemory<x86::reg8>(cpu.edx);
    // 004b56dd  84ff                   +test bh, bh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & cpu.bh));
    // 004b56df  75f4                   -jne 0x4b56d5
    if (!cpu.flags.zf)
    {
        goto L_0x004b56d5;
    }
L_0x004b56e1:
    // 004b56e1  803a00                 +cmp byte ptr [edx], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b56e4  74db                   -je 0x4b56c1
    if (cpu.flags.zf)
    {
        goto L_0x004b56c1;
    }
    // 004b56e6  807a0100               +cmp byte ptr [edx + 1], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b56ea  0f94c0                 -sete al
    cpu.al = cpu.flags.zf;
    // 004b56ed  0fb6e8                 -movzx ebp, al
    cpu.ebp = x86::reg32(cpu.al);
    // 004b56f0  a1cc935400             -mov eax, dword ptr [0x5493cc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5542860) /* 0x5493cc */);
    // 004b56f5  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b56f9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b56fb  7531                   -jne 0x4b572e
    if (!cpu.flags.zf)
    {
        goto L_0x004b572e;
    }
    // 004b56fd  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004b56ff  0f8511010000           -jne 0x4b5816
    if (!cpu.flags.zf)
    {
        goto L_0x004b5816;
    }
    // 004b5705  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 004b570a  e80449feff             -call 0x49a013
    cpu.esp -= 4;
    malloc(app, cpu);
    if (cpu.terminate) return;
    // 004b570f  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b5713  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b5715  74aa                   -je 0x4b56c1
    if (cpu.flags.zf)
    {
        goto L_0x004b56c1;
    }
    // 004b5717  a3cc935400             -mov dword ptr [0x5493cc], eax
    app->getMemory<x86::reg32>(x86::reg32(5542860) /* 0x5493cc */) = cpu.eax;
    // 004b571c  8928                   -mov dword ptr [eax], ebp
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebp;
    // 004b571e  83c008                 +add eax, 8
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
    // 004b5721  8968fc                 -mov dword ptr [eax - 4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ebp;
    // 004b5724  a3c8935400             -mov dword ptr [0x5493c8], eax
    app->getMemory<x86::reg32>(x86::reg32(5542856) /* 0x5493c8 */) = cpu.eax;
    // 004b5729  e9cd000000             -jmp 0x4b57fb
    goto L_0x004b57fb;
L_0x004b572e:
    // 004b572e  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004b5731  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004b5733  e8e6000000             -call 0x4b581e
    cpu.esp -= 4;
    sub_4b581e(app, cpu);
    if (cpu.terminate) return;
    // 004b5738  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004b573a  0f85d4000000           -jne 0x4b5814
    if (!cpu.flags.zf)
    {
        goto L_0x004b5814;
    }
    // 004b5740  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b5742  0f8fb0000000           -jg 0x4b57f8
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b57f8;
    }
    // 004b5748  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004b574a  f7dd                   -neg ebp
    cpu.ebp = ~cpu.ebp + 1;
    // 004b574c  8d5d01                 -lea ebx, [ebp + 1]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(1) /* 0x1 */);
    // 004b574f  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004b5751  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 004b5754  8d4108                 -lea eax, [ecx + 8]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004b5757  8b35c8935400           -mov esi, dword ptr [0x5493c8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5542856) /* 0x5493c8 */);
    // 004b575d  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004b5761  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b5763  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004b5765  7545                   -jne 0x4b57ac
    if (!cpu.flags.zf)
    {
        goto L_0x004b57ac;
    }
    // 004b5767  e8a748feff             -call 0x49a013
    cpu.esp -= 4;
    malloc(app, cpu);
    if (cpu.terminate) return;
    // 004b576c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b576e  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b5772  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b5774  0f8447ffffff           -je 0x4b56c1
    if (cpu.flags.zf)
    {
        goto L_0x004b56c1;
    }
    // 004b577a  8b35cc935400           -mov esi, dword ptr [0x5493cc]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5542860) /* 0x5493cc */);
    // 004b5780  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004b5782  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004b5783  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004b5785  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004b5787  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b5788  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b578a  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004b578d  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b578f  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004b5791  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004b5794  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004b5796  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5797  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004b5798  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b579c  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b579e  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004b57a0  a3c8935400             -mov dword ptr [0x5493c8], eax
    app->getMemory<x86::reg32>(x86::reg32(5542856) /* 0x5493c8 */) = cpu.eax;
    // 004b57a5  e8053bfdff             -call 0x4892af
    cpu.esp -= 4;
    sub_4892af(app, cpu);
    if (cpu.terminate) return;
    // 004b57aa  eb32                   -jmp 0x4b57de
    goto L_0x004b57de;
L_0x004b57ac:
    // 004b57ac  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b57ae  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b57b2  e8fdbbffff             -call 0x4b13b4
    cpu.esp -= 4;
    sub_4b13b4(app, cpu);
    if (cpu.terminate) return;
    // 004b57b7  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b57bb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b57bd  0f84fefeffff           -je 0x4b56c1
    if (cpu.flags.zf)
    {
        goto L_0x004b56c1;
    }
    // 004b57c3  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b57c7  8b15c8935400           -mov edx, dword ptr [0x5493c8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5542856) /* 0x5493c8 */);
    // 004b57cd  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b57cf  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 004b57d1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b57d3  e84f060000             -call 0x4b5e27
    cpu.esp -= 4;
    sub_4b5e27(app, cpu);
    if (cpu.terminate) return;
    // 004b57d8  890dc8935400           -mov dword ptr [0x5493c8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5542856) /* 0x5493c8 */) = cpu.ecx;
L_0x004b57de:
    // 004b57de  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004b57e0  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b57e4  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004b57e7  01f8                   +add eax, edi
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b57e9  893dcc935400           -mov dword ptr [0x5493cc], edi
    app->getMemory<x86::reg32>(x86::reg32(5542860) /* 0x5493cc */) = cpu.edi;
    // 004b57ef  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004b57f6  eb03                   -jmp 0x4b57fb
    goto L_0x004b57fb;
L_0x004b57f8:
    // 004b57f8  8d68ff                 -lea ebp, [eax - 1]
    cpu.ebp = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
L_0x004b57fb:
    // 004b57fb  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004b57fd  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b5801  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004b5804  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b5806  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004b5809  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004b580b  a1c8935400             -mov eax, dword ptr [0x5493c8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5542856) /* 0x5493c8 */);
    // 004b5810  c6042800               -mov byte ptr [eax + ebp], 0
    app->getMemory<x86::reg8>(cpu.eax + cpu.ebp * 1) = 0 /*0x0*/;
L_0x004b5814:
    // 004b5814  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004b5816:
    // 004b5816  83c40c                 +add esp, 0xc
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
    // 004b5819  e98efeffff             -jmp 0x4b56ac
    return sub_4b56ac(app, cpu);
}

/* align: skip  */
void Application::sub_4b581e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b581e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b581f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b5820  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b5821  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b5822  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b5823  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004b5825  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004b5827  8b35cc935400           -mov esi, dword ptr [0x5493cc]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5542860) /* 0x5493cc */);
    // 004b582d  e9b2000000             -jmp 0x4b58e4
    goto L_0x004b58e4;
L_0x004b5832:
    // 004b5832  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004b5834  e99f000000             -jmp 0x4b58d8
    goto L_0x004b58d8;
L_0x004b5839:
    // 004b5839  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b583b  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 004b583d  e8c067fcff             -call 0x47c002
    cpu.esp -= 4;
    sub_47c002(app, cpu);
    if (cpu.terminate) return;
    // 004b5842  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004b5844  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b5846  8a03                   -mov al, byte ptr [ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx);
    // 004b5848  e8b567fcff             -call 0x47c002
    cpu.esp -= 4;
    sub_47c002(app, cpu);
    if (cpu.terminate) return;
    // 004b584d  39c1                   +cmp ecx, eax
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
    // 004b584f  0f858c000000           -jne 0x4b58e1
    if (!cpu.flags.zf)
    {
        goto L_0x004b58e1;
    }
    // 004b5855  803a3d                 +cmp byte ptr [edx], 0x3d
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(61 /*0x3d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b5858  0f8578000000           -jne 0x4b58d6
    if (!cpu.flags.zf)
    {
        goto L_0x004b58d6;
    }
    // 004b585e  8b15cc935400           -mov edx, dword ptr [0x5493cc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5542860) /* 0x5493cc */);
    // 004b5864  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 004b5866  29d7                   -sub edi, edx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b5868  c1ff02                 -sar edi, 2
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (2 /*0x2*/ % 32));
    // 004b586b  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004b586d  7462                   -je 0x4b58d1
    if (cpu.flags.zf)
    {
        goto L_0x004b58d1;
    }
    // 004b586f  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004b5871  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004b5873  eb08                   -jmp 0x4b587d
    goto L_0x004b587d;
L_0x004b5875:
    // 004b5875  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004b5878  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 004b587a  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004b587d:
    // 004b587d  833900                 +cmp dword ptr [ecx], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b5880  75f3                   -jne 0x4b5875
    if (!cpu.flags.zf)
    {
        goto L_0x004b5875;
    }
    // 004b5882  8b35c8935400           -mov esi, dword ptr [0x5493c8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5542856) /* 0x5493c8 */);
    // 004b5888  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004b588a  7441                   -je 0x4b58cd
    if (cpu.flags.zf)
    {
        goto L_0x004b58cd;
    }
    // 004b588c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b588e  803c0700               +cmp byte ptr [edi + eax], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edi + cpu.eax * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b5892  7407                   -je 0x4b589b
    if (cpu.flags.zf)
    {
        goto L_0x004b589b;
    }
    // 004b5894  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b5896  e80e98feff             -call 0x49f0a9
    cpu.esp -= 4;
    sub_49f0a9(app, cpu);
    if (cpu.terminate) return;
L_0x004b589b:
    // 004b589b  8b2dcc935400           -mov ebp, dword ptr [0x5493cc]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5542860) /* 0x5493cc */);
    // 004b58a1  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004b58a3  29ee                   -sub esi, ebp
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004b58a5  8b15c8935400           -mov edx, dword ptr [0x5493c8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5542856) /* 0x5493c8 */);
    // 004b58ab  c1fe02                 +sar esi, 2
    {
        x86::reg8 tmp = 2 /*0x2*/ % 32;
        x86::reg32& op = cpu.esi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 004b58ae  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b58b0  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004b58b2  e870050000             -call 0x4b5e27
    cpu.esp -= 4;
    sub_4b5e27(app, cpu);
    if (cpu.terminate) return;
    // 004b58b7  890dc8935400           -mov dword ptr [0x5493c8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5542856) /* 0x5493c8 */) = cpu.ecx;
    // 004b58bd  8d040f                 -lea eax, [edi + ecx]
    cpu.eax = x86::reg32(cpu.edi + cpu.ecx * 1);
    // 004b58c0  eb07                   -jmp 0x4b58c9
    goto L_0x004b58c9;
L_0x004b58c2:
    // 004b58c2  8a5001                 -mov dl, byte ptr [eax + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b58c5  47                     -inc edi
    (cpu.edi)++;
    // 004b58c6  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 004b58c8  40                     -inc eax
    (cpu.eax)++;
L_0x004b58c9:
    // 004b58c9  39f7                   +cmp edi, esi
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
    // 004b58cb  7cf5                   -jl 0x4b58c2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b58c2;
    }
L_0x004b58cd:
    // 004b58cd  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004b58cf  eb27                   -jmp 0x4b58f8
    goto L_0x004b58f8;
L_0x004b58d1:
    // 004b58d1  8d4701                 -lea eax, [edi + 1]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 004b58d4  eb22                   -jmp 0x4b58f8
    goto L_0x004b58f8;
L_0x004b58d6:
    // 004b58d6  42                     -inc edx
    (cpu.edx)++;
    // 004b58d7  43                     -inc ebx
    (cpu.ebx)++;
L_0x004b58d8:
    // 004b58d8  803b00                 +cmp byte ptr [ebx], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b58db  0f8558ffffff           -jne 0x4b5839
    if (!cpu.flags.zf)
    {
        goto L_0x004b5839;
    }
L_0x004b58e1:
    // 004b58e1  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004b58e4:
    // 004b58e4  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004b58e6  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b58e8  0f8544ffffff           -jne 0x4b5832
    if (!cpu.flags.zf)
    {
        goto L_0x004b5832;
    }
    // 004b58ee  a1cc935400             -mov eax, dword ptr [0x5493cc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5542860) /* 0x5493cc */);
    // 004b58f3  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004b58f5  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
L_0x004b58f8:
    // 004b58f8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b58f9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b58fa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b58fb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b58fc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b58fd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b58fe(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b58fe  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b58ff  833ddc93540000         +cmp dword ptr [0x5493dc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5542876) /* 0x5493dc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b5906  7421                   -je 0x4b5929
    if (cpu.flags.zf)
    {
        goto L_0x004b5929;
    }
    // 004b5908  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b590a  8a1a                   -mov bl, byte ptr [edx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx);
    // 004b590c  8a9be1935400           -mov bl, byte ptr [ebx + 0x5493e1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5542881) /* 0x5493e1 */);
    // 004b5912  80e301                 -and bl, 1
    cpu.bl &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004b5915  81e3ff000000           +and ebx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004b591b  740c                   -je 0x4b5929
    if (cpu.flags.zf)
    {
        goto L_0x004b5929;
    }
    // 004b591d  8a1a                   -mov bl, byte ptr [edx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx);
    // 004b591f  8818                   -mov byte ptr [eax], bl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bl;
    // 004b5921  8a5201                 -mov dl, byte ptr [edx + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004b5924  885001                 -mov byte ptr [eax + 1], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = cpu.dl;
    // 004b5927  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5928  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b5929:
    // 004b5929  8a12                   -mov dl, byte ptr [edx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx);
    // 004b592b  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 004b592d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b592e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b592f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b592f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b5930  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b5931  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b5932  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b5935  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x004b5937:
    // 004b5937  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b5939  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b593b  e832f6ffff             -call 0x4b4f72
    cpu.esp -= 4;
    sub_4b4f72(app, cpu);
    if (cpu.terminate) return;
    // 004b5940  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b5942  7531                   -jne 0x4b5975
    if (!cpu.flags.zf)
    {
        goto L_0x004b5975;
    }
    // 004b5944  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b5946  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004b5948  e827050000             -call 0x4b5e74
    cpu.esp -= 4;
    sub_4b5e74(app, cpu);
    if (cpu.terminate) return;
    // 004b594d  e85d050000             -call 0x4b5eaf
    cpu.esp -= 4;
    sub_4b5eaf(app, cpu);
    if (cpu.terminate) return;
    // 004b5952  e8c1050000             -call 0x4b5f18
    cpu.esp -= 4;
    sub_4b5f18(app, cpu);
    if (cpu.terminate) return;
    // 004b5957  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b5959  30d2                   +xor dl, dl
    cpu.clear_co();
    cpu.set_szp((cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl))));
    // 004b595b  e865c5ffff             -call 0x4b1ec5
    cpu.esp -= 4;
    sub_4b1ec5(app, cpu);
    if (cpu.terminate) return;
    // 004b5960  881404                 -mov byte ptr [esp + eax], dl
    app->getMemory<x86::reg8>(cpu.esp + cpu.eax * 1) = cpu.dl;
    // 004b5963  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004b5965  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b5967  e892ffffff             -call 0x4b58fe
    cpu.esp -= 4;
    sub_4b58fe(app, cpu);
    if (cpu.terminate) return;
    // 004b596c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b596e  e892f6ffff             -call 0x4b5005
    cpu.esp -= 4;
    sub_4b5005(app, cpu);
    if (cpu.terminate) return;
    // 004b5973  ebc2                   -jmp 0x4b5937
    goto L_0x004b5937;
L_0x004b5975:
    // 004b5975  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b5977  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b597a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b597b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b597c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b597d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b597e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b597e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b597f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b5980  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 004b5982  3a1a                   +cmp bl, byte ptr [edx]
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.edx)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b5984  7541                   -jne 0x4b59c7
    if (!cpu.flags.zf)
    {
        goto L_0x004b59c7;
    }
    // 004b5986  833ddc93540000         +cmp dword ptr [0x5493dc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5542876) /* 0x5493dc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b598d  741f                   -je 0x4b59ae
    if (cpu.flags.zf)
    {
        goto L_0x004b59ae;
    }
    // 004b598f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b5991  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 004b5993  8a9be1935400           -mov bl, byte ptr [ebx + 0x5493e1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5542881) /* 0x5493e1 */);
    // 004b5999  80e301                 -and bl, 1
    cpu.bl &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004b599c  81e3ff000000           +and ebx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004b59a2  740a                   -je 0x4b59ae
    if (cpu.flags.zf)
    {
        goto L_0x004b59ae;
    }
    // 004b59a4  8a5801                 -mov bl, byte ptr [eax + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b59a7  8a4a01                 -mov cl, byte ptr [edx + 1]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004b59aa  38cb                   +cmp bl, cl
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.cl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b59ac  7505                   -jne 0x4b59b3
    if (!cpu.flags.zf)
    {
        goto L_0x004b59b3;
    }
L_0x004b59ae:
    // 004b59ae  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b59b0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b59b1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b59b2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b59b3:
    // 004b59b3  88d8                   -mov al, bl
    cpu.al = cpu.bl;
    // 004b59b5  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b59ba  88ca                   -mov dl, cl
    cpu.dl = cpu.cl;
    // 004b59bc  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b59c2  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b59c4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b59c5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b59c6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b59c7:
    // 004b59c7  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b59c9  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 004b59cb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b59cd  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 004b59cf  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004b59d1  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b59d3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b59d4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b59d5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b59d6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b59d6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b59d7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b59d8  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b59db  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b59dd  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b59df  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004b59e1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b59e3  e830050000             -call 0x4b5f18
    cpu.esp -= 4;
    sub_4b5f18(app, cpu);
    if (cpu.terminate) return;
    // 004b59e8  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b59ea  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 004b59ec  e8d4c4ffff             -call 0x4b1ec5
    cpu.esp -= 4;
    sub_4b1ec5(app, cpu);
    if (cpu.terminate) return;
    // 004b59f1  881404                 -mov byte ptr [esp + eax], dl
    app->getMemory<x86::reg8>(cpu.esp + cpu.eax * 1) = cpu.dl;
L_0x004b59f4:
    // 004b59f4  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b59f6  e877f5ffff             -call 0x4b4f72
    cpu.esp -= 4;
    sub_4b4f72(app, cpu);
    if (cpu.terminate) return;
    // 004b59fb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b59fd  7518                   -jne 0x4b5a17
    if (!cpu.flags.zf)
    {
        goto L_0x004b5a17;
    }
    // 004b59ff  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004b5a01  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b5a03  e876ffffff             -call 0x4b597e
    cpu.esp -= 4;
    sub_4b597e(app, cpu);
    if (cpu.terminate) return;
    // 004b5a08  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b5a0a  740b                   -je 0x4b5a17
    if (cpu.flags.zf)
    {
        goto L_0x004b5a17;
    }
    // 004b5a0c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b5a0e  e8f2f5ffff             -call 0x4b5005
    cpu.esp -= 4;
    sub_4b5005(app, cpu);
    if (cpu.terminate) return;
    // 004b5a13  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b5a15  ebdd                   -jmp 0x4b59f4
    goto L_0x004b59f4;
L_0x004b5a17:
    // 004b5a17  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b5a19  e854f5ffff             -call 0x4b4f72
    cpu.esp -= 4;
    sub_4b4f72(app, cpu);
    if (cpu.terminate) return;
    // 004b5a1e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b5a20  7404                   -je 0x4b5a26
    if (cpu.flags.zf)
    {
        goto L_0x004b5a26;
    }
    // 004b5a22  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004b5a24  7504                   -jne 0x4b5a2a
    if (!cpu.flags.zf)
    {
        goto L_0x004b5a2a;
    }
L_0x004b5a26:
    // 004b5a26  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b5a28  eb02                   -jmp 0x4b5a2c
    goto L_0x004b5a2c;
L_0x004b5a2a:
    // 004b5a2a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004b5a2c:
    // 004b5a2c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b5a2f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5a30  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5a31  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b5a32(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b5a32  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b5a33  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b5a34  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b5a36  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004b5a38:
    // 004b5a38  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b5a3a  e833f5ffff             -call 0x4b4f72
    cpu.esp -= 4;
    sub_4b4f72(app, cpu);
    if (cpu.terminate) return;
    // 004b5a3f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b5a41  750c                   -jne 0x4b5a4f
    if (!cpu.flags.zf)
    {
        goto L_0x004b5a4f;
    }
    // 004b5a43  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b5a45  e8bbf5ffff             -call 0x4b5005
    cpu.esp -= 4;
    sub_4b5005(app, cpu);
    if (cpu.terminate) return;
    // 004b5a4a  43                     +inc ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004b5a4b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b5a4d  ebe9                   -jmp 0x4b5a38
    goto L_0x004b5a38;
L_0x004b5a4f:
    // 004b5a4f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b5a51  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5a52  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5a53  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b5a54(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b5a54  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b5a55  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b5a56  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b5a57  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b5a58  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b5a5a  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b5a5c  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004b5a5e  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004b5a60  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b5a62  7438                   -je 0x4b5a9c
    if (cpu.flags.zf)
    {
        goto L_0x004b5a9c;
    }
L_0x004b5a64:
    // 004b5a64  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004b5a66  7658                   -jbe 0x4b5ac0
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b5ac0;
    }
    // 004b5a68  803900                 +cmp byte ptr [ecx], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b5a6b  7418                   -je 0x4b5a85
    if (cpu.flags.zf)
    {
        goto L_0x004b5a85;
    }
    // 004b5a6d  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 004b5a72  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004b5a74  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b5a76  e8cf60ffff             -call 0x4abb4a
    cpu.esp -= 4;
    sub_4abb4a(app, cpu);
    if (cpu.terminate) return;
    // 004b5a7b  83f8ff                 +cmp eax, -1
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
    // 004b5a7e  750c                   -jne 0x4b5a8c
    if (!cpu.flags.zf)
    {
        goto L_0x004b5a8c;
    }
    // 004b5a80  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5a81  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5a82  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5a83  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5a84  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b5a85:
    // 004b5a85  66c7060000             -mov word ptr [esi], 0
    app->getMemory<x86::reg16>(cpu.esi) = 0 /*0x0*/;
    // 004b5a8a  eb34                   -jmp 0x4b5ac0
    goto L_0x004b5ac0;
L_0x004b5a8c:
    // 004b5a8c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b5a8e  4d                     -dec ebp
    (cpu.ebp)--;
    // 004b5a8f  e871f5ffff             -call 0x4b5005
    cpu.esp -= 4;
    sub_4b5005(app, cpu);
    if (cpu.terminate) return;
    // 004b5a94  83c602                 +add esi, 2
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
    // 004b5a97  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004b5a98  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004b5a9a  ebc8                   -jmp 0x4b5a64
    goto L_0x004b5a64;
L_0x004b5a9c:
    // 004b5a9c  803900                 +cmp byte ptr [ecx], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b5a9f  741f                   -je 0x4b5ac0
    if (cpu.flags.zf)
    {
        goto L_0x004b5ac0;
    }
    // 004b5aa1  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 004b5aa6  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004b5aa8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b5aaa  e89b60ffff             -call 0x4abb4a
    cpu.esp -= 4;
    sub_4abb4a(app, cpu);
    if (cpu.terminate) return;
    // 004b5aaf  83f8ff                 +cmp eax, -1
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
    // 004b5ab2  740e                   -je 0x4b5ac2
    if (cpu.flags.zf)
    {
        goto L_0x004b5ac2;
    }
    // 004b5ab4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b5ab6  e84af5ffff             -call 0x4b5005
    cpu.esp -= 4;
    sub_4b5005(app, cpu);
    if (cpu.terminate) return;
    // 004b5abb  47                     +inc edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004b5abc  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004b5abe  ebdc                   -jmp 0x4b5a9c
    goto L_0x004b5a9c;
L_0x004b5ac0:
    // 004b5ac0  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x004b5ac2:
    // 004b5ac2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5ac3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5ac4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5ac5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5ac6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b5ac7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b5ac7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b5ac8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b5ac9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b5aca  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b5acb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b5acc  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b5acd  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b5ad0  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004b5ad2  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 004b5ad7  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004b5adb  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004b5ade  ba3d000000             -mov edx, 0x3d
    cpu.edx = 61 /*0x3d*/;
    // 004b5ae3  e84a040000             -call 0x4b5f32
    cpu.esp -= 4;
    sub_4b5f32(app, cpu);
    if (cpu.terminate) return;
    // 004b5ae8  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004b5aea  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b5aec  7458                   -je 0x4b5b46
    if (cpu.flags.zf)
    {
        goto L_0x004b5b46;
    }
    // 004b5aee  39c8                   +cmp eax, ecx
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
    // 004b5af0  7454                   -je 0x4b5b46
    if (cpu.flags.zf)
    {
        goto L_0x004b5b46;
    }
    // 004b5af2  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004b5af4  29cd                   -sub ebp, ecx
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b5af6  d1fd                   -sar ebp, 1
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (1 /*0x1*/ % 32));
    // 004b5af8  01ed                   -add ebp, ebp
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004b5afa  8d4502                 -lea eax, [ebp + 2]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(2) /* 0x2 */);
    // 004b5afd  e81145feff             -call 0x49a013
    cpu.esp -= 4;
    malloc(app, cpu);
    if (cpu.terminate) return;
    // 004b5b02  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b5b04  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b5b08  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b5b0a  743a                   -je 0x4b5b46
    if (cpu.flags.zf)
    {
        goto L_0x004b5b46;
    }
    // 004b5b0c  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 004b5b0e  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004b5b10  e837bcffff             -call 0x4b174c
    cpu.esp -= 4;
    sub_4b174c(app, cpu);
    if (cpu.terminate) return;
    // 004b5b15  8d5702                 -lea edx, [edi + 2]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 004b5b18  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b5b1a  66c7042e0000           -mov word ptr [esi + ebp], 0
    app->getMemory<x86::reg16>(cpu.esi + cpu.ebp * 1) = 0 /*0x0*/;
    // 004b5b20  e814bcffff             -call 0x4b1739
    cpu.esp -= 4;
    sub_4b1739(app, cpu);
    if (cpu.terminate) return;
    // 004b5b25  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b5b27  743d                   -je 0x4b5b66
    if (cpu.flags.zf)
    {
        goto L_0x004b5b66;
    }
    // 004b5b29  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b5b2b  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004b5b2f  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004b5b32  e8dc44feff             -call 0x49a013
    cpu.esp -= 4;
    malloc(app, cpu);
    if (cpu.terminate) return;
    // 004b5b37  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004b5b39  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004b5b3b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b5b3d  7511                   -jne 0x4b5b50
    if (!cpu.flags.zf)
    {
        goto L_0x004b5b50;
    }
L_0x004b5b3f:
    // 004b5b3f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b5b41  e86395feff             -call 0x49f0a9
    cpu.esp -= 4;
    sub_49f0a9(app, cpu);
    if (cpu.terminate) return;
L_0x004b5b46:
    // 004b5b46  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004b5b4b  e998000000             -jmp 0x4b5be8
    goto L_0x004b5be8;
L_0x004b5b50:
    // 004b5b50  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b5b54  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b5b58  01f7                   +add edi, esi
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b5b5a  e8edbbffff             -call 0x4b174c
    cpu.esp -= 4;
    sub_4b174c(app, cpu);
    if (cpu.terminate) return;
    // 004b5b5f  66c7070000             -mov word ptr [edi], 0
    app->getMemory<x86::reg16>(cpu.edi) = 0 /*0x0*/;
    // 004b5b64  eb02                   -jmp 0x4b5b68
    goto L_0x004b5b68;
L_0x004b5b66:
    // 004b5b66  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x004b5b68:
    // 004b5b68  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b5b6c  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004b5b6e  e8d5030000             -call 0x4b5f48
    cpu.esp -= 4;
    sub_4b5f48(app, cpu);
    if (cpu.terminate) return;
    // 004b5b73  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b5b75  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b5b79  e82b95feff             -call 0x49f0a9
    cpu.esp -= 4;
    sub_49f0a9(app, cpu);
    if (cpu.terminate) return;
    // 004b5b7e  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004b5b80  e82495feff             -call 0x49f0a9
    cpu.esp -= 4;
    sub_49f0a9(app, cpu);
    if (cpu.terminate) return;
    // 004b5b85  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b5b87  74bd                   -je 0x4b5b46
    if (cpu.flags.zf)
    {
        goto L_0x004b5b46;
    }
    // 004b5b89  833dd093540000         +cmp dword ptr [0x5493d0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5542864) /* 0x5493d0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b5b90  7505                   -jne 0x4b5b97
    if (!cpu.flags.zf)
    {
        goto L_0x004b5b97;
    }
    // 004b5b92  e877040000             -call 0x4b600e
    cpu.esp -= 4;
    sub_4b600e(app, cpu);
    if (cpu.terminate) return;
L_0x004b5b97:
    // 004b5b97  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b5b99  e854000000             -call 0x4b5bf2
    cpu.esp -= 4;
    sub_4b5bf2(app, cpu);
    if (cpu.terminate) return;
    // 004b5b9e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b5ba0  75a4                   -jne 0x4b5b46
    if (!cpu.flags.zf)
    {
        goto L_0x004b5b46;
    }
    // 004b5ba2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b5ba4  e890bbffff             -call 0x4b1739
    cpu.esp -= 4;
    sub_4b1739(app, cpu);
    if (cpu.terminate) return;
    // 004b5ba9  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b5bac  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b5bb0  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004b5bb3  e85b44feff             -call 0x49a013
    cpu.esp -= 4;
    malloc(app, cpu);
    if (cpu.terminate) return;
    // 004b5bb8  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b5bba  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b5bbc  750f                   -jne 0x4b5bcd
    if (!cpu.flags.zf)
    {
        goto L_0x004b5bcd;
    }
    // 004b5bbe  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 004b5bc3  e8e943feff             -call 0x499fb1
    cpu.esp -= 4;
    sub_499fb1(app, cpu);
    if (cpu.terminate) return;
    // 004b5bc8  e979ffffff             -jmp 0x4b5b46
    goto L_0x004b5b46;
L_0x004b5bcd:
    // 004b5bcd  0faf1c24               -imul ebx, dword ptr [esp]
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 004b5bd1  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004b5bd3  e8cc85ffff             -call 0x4ae1a4
    cpu.esp -= 4;
    sub_4ae1a4(app, cpu);
    if (cpu.terminate) return;
    // 004b5bd8  83f8ff                 +cmp eax, -1
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
    // 004b5bdb  0f845effffff           -je 0x4b5b3f
    if (cpu.flags.zf)
    {
        goto L_0x004b5b3f;
    }
    // 004b5be1  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b5be3  e8cbfaffff             -call 0x4b56b3
    cpu.esp -= 4;
    sub_4b56b3(app, cpu);
    if (cpu.terminate) return;
L_0x004b5be8:
    // 004b5be8  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b5beb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5bec  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5bed  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5bee  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5bef  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5bf0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5bf1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b5beb(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004b5beb;
    // 004b5ac7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b5ac8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b5ac9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b5aca  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b5acb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b5acc  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b5acd  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b5ad0  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004b5ad2  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 004b5ad7  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004b5adb  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004b5ade  ba3d000000             -mov edx, 0x3d
    cpu.edx = 61 /*0x3d*/;
    // 004b5ae3  e84a040000             -call 0x4b5f32
    cpu.esp -= 4;
    sub_4b5f32(app, cpu);
    if (cpu.terminate) return;
    // 004b5ae8  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004b5aea  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b5aec  7458                   -je 0x4b5b46
    if (cpu.flags.zf)
    {
        goto L_0x004b5b46;
    }
    // 004b5aee  39c8                   +cmp eax, ecx
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
    // 004b5af0  7454                   -je 0x4b5b46
    if (cpu.flags.zf)
    {
        goto L_0x004b5b46;
    }
    // 004b5af2  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004b5af4  29cd                   -sub ebp, ecx
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b5af6  d1fd                   -sar ebp, 1
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (1 /*0x1*/ % 32));
    // 004b5af8  01ed                   -add ebp, ebp
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004b5afa  8d4502                 -lea eax, [ebp + 2]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(2) /* 0x2 */);
    // 004b5afd  e81145feff             -call 0x49a013
    cpu.esp -= 4;
    malloc(app, cpu);
    if (cpu.terminate) return;
    // 004b5b02  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b5b04  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b5b08  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b5b0a  743a                   -je 0x4b5b46
    if (cpu.flags.zf)
    {
        goto L_0x004b5b46;
    }
    // 004b5b0c  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 004b5b0e  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004b5b10  e837bcffff             -call 0x4b174c
    cpu.esp -= 4;
    sub_4b174c(app, cpu);
    if (cpu.terminate) return;
    // 004b5b15  8d5702                 -lea edx, [edi + 2]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 004b5b18  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b5b1a  66c7042e0000           -mov word ptr [esi + ebp], 0
    app->getMemory<x86::reg16>(cpu.esi + cpu.ebp * 1) = 0 /*0x0*/;
    // 004b5b20  e814bcffff             -call 0x4b1739
    cpu.esp -= 4;
    sub_4b1739(app, cpu);
    if (cpu.terminate) return;
    // 004b5b25  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b5b27  743d                   -je 0x4b5b66
    if (cpu.flags.zf)
    {
        goto L_0x004b5b66;
    }
    // 004b5b29  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b5b2b  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004b5b2f  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004b5b32  e8dc44feff             -call 0x49a013
    cpu.esp -= 4;
    malloc(app, cpu);
    if (cpu.terminate) return;
    // 004b5b37  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004b5b39  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004b5b3b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b5b3d  7511                   -jne 0x4b5b50
    if (!cpu.flags.zf)
    {
        goto L_0x004b5b50;
    }
L_0x004b5b3f:
    // 004b5b3f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b5b41  e86395feff             -call 0x49f0a9
    cpu.esp -= 4;
    sub_49f0a9(app, cpu);
    if (cpu.terminate) return;
L_0x004b5b46:
    // 004b5b46  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004b5b4b  e998000000             -jmp 0x4b5be8
    goto L_0x004b5be8;
L_0x004b5b50:
    // 004b5b50  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b5b54  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b5b58  01f7                   +add edi, esi
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b5b5a  e8edbbffff             -call 0x4b174c
    cpu.esp -= 4;
    sub_4b174c(app, cpu);
    if (cpu.terminate) return;
    // 004b5b5f  66c7070000             -mov word ptr [edi], 0
    app->getMemory<x86::reg16>(cpu.edi) = 0 /*0x0*/;
    // 004b5b64  eb02                   -jmp 0x4b5b68
    goto L_0x004b5b68;
L_0x004b5b66:
    // 004b5b66  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x004b5b68:
    // 004b5b68  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b5b6c  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004b5b6e  e8d5030000             -call 0x4b5f48
    cpu.esp -= 4;
    sub_4b5f48(app, cpu);
    if (cpu.terminate) return;
    // 004b5b73  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b5b75  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b5b79  e82b95feff             -call 0x49f0a9
    cpu.esp -= 4;
    sub_49f0a9(app, cpu);
    if (cpu.terminate) return;
    // 004b5b7e  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004b5b80  e82495feff             -call 0x49f0a9
    cpu.esp -= 4;
    sub_49f0a9(app, cpu);
    if (cpu.terminate) return;
    // 004b5b85  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b5b87  74bd                   -je 0x4b5b46
    if (cpu.flags.zf)
    {
        goto L_0x004b5b46;
    }
    // 004b5b89  833dd093540000         +cmp dword ptr [0x5493d0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5542864) /* 0x5493d0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b5b90  7505                   -jne 0x4b5b97
    if (!cpu.flags.zf)
    {
        goto L_0x004b5b97;
    }
    // 004b5b92  e877040000             -call 0x4b600e
    cpu.esp -= 4;
    sub_4b600e(app, cpu);
    if (cpu.terminate) return;
L_0x004b5b97:
    // 004b5b97  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b5b99  e854000000             -call 0x4b5bf2
    cpu.esp -= 4;
    sub_4b5bf2(app, cpu);
    if (cpu.terminate) return;
    // 004b5b9e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b5ba0  75a4                   -jne 0x4b5b46
    if (!cpu.flags.zf)
    {
        goto L_0x004b5b46;
    }
    // 004b5ba2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b5ba4  e890bbffff             -call 0x4b1739
    cpu.esp -= 4;
    sub_4b1739(app, cpu);
    if (cpu.terminate) return;
    // 004b5ba9  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b5bac  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b5bb0  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004b5bb3  e85b44feff             -call 0x49a013
    cpu.esp -= 4;
    malloc(app, cpu);
    if (cpu.terminate) return;
    // 004b5bb8  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b5bba  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b5bbc  750f                   -jne 0x4b5bcd
    if (!cpu.flags.zf)
    {
        goto L_0x004b5bcd;
    }
    // 004b5bbe  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 004b5bc3  e8e943feff             -call 0x499fb1
    cpu.esp -= 4;
    sub_499fb1(app, cpu);
    if (cpu.terminate) return;
    // 004b5bc8  e979ffffff             -jmp 0x4b5b46
    goto L_0x004b5b46;
L_0x004b5bcd:
    // 004b5bcd  0faf1c24               -imul ebx, dword ptr [esp]
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 004b5bd1  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004b5bd3  e8cc85ffff             -call 0x4ae1a4
    cpu.esp -= 4;
    sub_4ae1a4(app, cpu);
    if (cpu.terminate) return;
    // 004b5bd8  83f8ff                 +cmp eax, -1
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
    // 004b5bdb  0f845effffff           -je 0x4b5b3f
    if (cpu.flags.zf)
    {
        goto L_0x004b5b3f;
    }
    // 004b5be1  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b5be3  e8cbfaffff             -call 0x4b56b3
    cpu.esp -= 4;
    sub_4b56b3(app, cpu);
    if (cpu.terminate) return;
L_0x004b5be8:
    // 004b5be8  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_entry_0x004b5beb:
    // 004b5beb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5bec  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5bed  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5bee  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5bef  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5bf0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5bf1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b5bf2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b5bf2  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b5bf3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b5bf4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b5bf5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b5bf6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b5bf7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b5bf8  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b5bfb  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004b5bfd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b5bff  750a                   -jne 0x4b5c0b
    if (!cpu.flags.zf)
    {
        goto L_0x004b5c0b;
    }
L_0x004b5c01:
    // 004b5c01  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004b5c06  e92b010000             -jmp 0x4b5d36
    goto L_0x004b5d36;
L_0x004b5c0b:
    // 004b5c0b  66833800               +cmp word ptr [eax], 0
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
    // 004b5c0f  7416                   -je 0x4b5c27
    if (cpu.flags.zf)
    {
        goto L_0x004b5c27;
    }
    // 004b5c11  8d5002                 -lea edx, [eax + 2]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 004b5c14  eb09                   -jmp 0x4b5c1f
    goto L_0x004b5c1f;
L_0x004b5c16:
    // 004b5c16  6683f93d               +cmp cx, 0x3d
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(61 /*0x3d*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004b5c1a  740b                   -je 0x4b5c27
    if (cpu.flags.zf)
    {
        goto L_0x004b5c27;
    }
    // 004b5c1c  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x004b5c1f:
    // 004b5c1f  668b0a                 -mov cx, word ptr [edx]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx);
    // 004b5c22  6685c9                 +test cx, cx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.cx & cpu.cx));
    // 004b5c25  75ef                   -jne 0x4b5c16
    if (!cpu.flags.zf)
    {
        goto L_0x004b5c16;
    }
L_0x004b5c27:
    // 004b5c27  66833a00               +cmp word ptr [edx], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.edx);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004b5c2b  74d4                   -je 0x4b5c01
    if (cpu.flags.zf)
    {
        goto L_0x004b5c01;
    }
    // 004b5c2d  66837a0200             +cmp word ptr [edx + 2], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(2) /* 0x2 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004b5c32  0f94c0                 -sete al
    cpu.al = cpu.flags.zf;
    // 004b5c35  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b5c37  8b0dd0935400           -mov ecx, dword ptr [0x5493d0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5542864) /* 0x5493d0 */);
    // 004b5c3d  88c3                   -mov bl, al
    cpu.bl = cpu.al;
    // 004b5c3f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004b5c41  7531                   -jne 0x4b5c74
    if (!cpu.flags.zf)
    {
        goto L_0x004b5c74;
    }
    // 004b5c43  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004b5c45  0f85e9000000           -jne 0x4b5d34
    if (!cpu.flags.zf)
    {
        goto L_0x004b5d34;
    }
    // 004b5c4b  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 004b5c50  e8be43feff             -call 0x49a013
    cpu.esp -= 4;
    malloc(app, cpu);
    if (cpu.terminate) return;
    // 004b5c55  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004b5c57  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b5c59  74a6                   -je 0x4b5c01
    if (cpu.flags.zf)
    {
        goto L_0x004b5c01;
    }
    // 004b5c5b  a3d0935400             -mov dword ptr [0x5493d0], eax
    app->getMemory<x86::reg32>(x86::reg32(5542864) /* 0x5493d0 */) = cpu.eax;
    // 004b5c60  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 004b5c62  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b5c65  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 004b5c67  8958fc                 -mov dword ptr [eax - 4], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.ebx;
    // 004b5c6a  a3c8935400             -mov dword ptr [0x5493c8], eax
    app->getMemory<x86::reg32>(x86::reg32(5542856) /* 0x5493c8 */) = cpu.eax;
    // 004b5c6f  e9b2000000             -jmp 0x4b5d26
    goto L_0x004b5d26;
L_0x004b5c74:
    // 004b5c74  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b5c76  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004b5c78  e8c1000000             -call 0x4b5d3e
    cpu.esp -= 4;
    sub_4b5d3e(app, cpu);
    if (cpu.terminate) return;
    // 004b5c7d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004b5c7f  0f85af000000           -jne 0x4b5d34
    if (!cpu.flags.zf)
    {
        goto L_0x004b5d34;
    }
    // 004b5c85  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b5c87  0f8f96000000           -jg 0x4b5d23
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b5d23;
    }
    // 004b5c8d  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 004b5c8f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b5c91  8b2dc8935400           -mov ebp, dword ptr [0x5493c8]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5542856) /* 0x5493c8 */);
    // 004b5c97  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004b5c99  40                     -inc eax
    (cpu.eax)++;
    // 004b5c9a  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 004b5c9d  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004b5ca1  8d4308                 -lea eax, [ebx + 8]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b5ca4  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b5ca8  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004b5cab  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b5cad  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004b5caf  7533                   -jne 0x4b5ce4
    if (!cpu.flags.zf)
    {
        goto L_0x004b5ce4;
    }
    // 004b5cb1  e85d43feff             -call 0x49a013
    cpu.esp -= 4;
    malloc(app, cpu);
    if (cpu.terminate) return;
    // 004b5cb6  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004b5cb8  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004b5cba  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b5cbc  0f843fffffff           -je 0x4b5c01
    if (cpu.flags.zf)
    {
        goto L_0x004b5c01;
    }
    // 004b5cc2  8b15d0935400           -mov edx, dword ptr [0x5493d0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5542864) /* 0x5493d0 */);
    // 004b5cc8  e87fbaffff             -call 0x4b174c
    cpu.esp -= 4;
    sub_4b174c(app, cpu);
    if (cpu.terminate) return;
    // 004b5ccd  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004b5cd0  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b5cd4  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004b5cd6  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004b5cd8  a3c8935400             -mov dword ptr [0x5493c8], eax
    app->getMemory<x86::reg32>(x86::reg32(5542856) /* 0x5493c8 */) = cpu.eax;
    // 004b5cdd  e8cd35fdff             -call 0x4892af
    cpu.esp -= 4;
    sub_4892af(app, cpu);
    if (cpu.terminate) return;
    // 004b5ce2  eb2d                   -jmp 0x4b5d11
    goto L_0x004b5d11;
L_0x004b5ce4:
    // 004b5ce4  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b5ce6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b5ce8  e8c7b6ffff             -call 0x4b13b4
    cpu.esp -= 4;
    sub_4b13b4(app, cpu);
    if (cpu.terminate) return;
    // 004b5ced  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004b5cef  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b5cf1  0f840affffff           -je 0x4b5c01
    if (cpu.flags.zf)
    {
        goto L_0x004b5c01;
    }
    // 004b5cf7  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 004b5cfa  8b15c8935400           -mov edx, dword ptr [0x5493c8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5542856) /* 0x5493c8 */);
    // 004b5d00  01c5                   +add ebp, eax
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b5d02  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004b5d04  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004b5d06  e81c010000             -call 0x4b5e27
    cpu.esp -= 4;
    sub_4b5e27(app, cpu);
    if (cpu.terminate) return;
    // 004b5d0b  892dc8935400           -mov dword ptr [0x5493c8], ebp
    app->getMemory<x86::reg32>(x86::reg32(5542856) /* 0x5493c8 */) = cpu.ebp;
L_0x004b5d11:
    // 004b5d11  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b5d13  890dd0935400           -mov dword ptr [0x5493d0], ecx
    app->getMemory<x86::reg32>(x86::reg32(5542864) /* 0x5493d0 */) = cpu.ecx;
    // 004b5d19  c744810400000000       -mov dword ptr [ecx + eax*4 + 4], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */ + cpu.eax * 4) = 0 /*0x0*/;
    // 004b5d21  eb03                   -jmp 0x4b5d26
    goto L_0x004b5d26;
L_0x004b5d23:
    // 004b5d23  8d70ff                 -lea esi, [eax - 1]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
L_0x004b5d26:
    // 004b5d26  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b5d28  893c81                 -mov dword ptr [ecx + eax*4], edi
    app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 4) = cpu.edi;
    // 004b5d2b  a1c8935400             -mov eax, dword ptr [0x5493c8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5542856) /* 0x5493c8 */);
    // 004b5d30  c6040600               -mov byte ptr [esi + eax], 0
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 0 /*0x0*/;
L_0x004b5d34:
    // 004b5d34  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004b5d36:
    // 004b5d36  83c408                 +add esp, 8
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
    // 004b5d39  e9adfeffff             -jmp 0x4b5beb
    return sub_4b5beb(app, cpu);
}

/* align: skip  */
void Application::sub_4b5d3e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b5d3e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b5d3f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b5d40  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b5d41  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b5d42  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b5d43  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004b5d45  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004b5d47  8b35d0935400           -mov esi, dword ptr [0x5493d0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5542864) /* 0x5493d0 */);
    // 004b5d4d  e9bb000000             -jmp 0x4b5e0d
    goto L_0x004b5e0d;
L_0x004b5d52:
    // 004b5d52  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004b5d54  e9a7000000             -jmp 0x4b5e00
    goto L_0x004b5e00;
L_0x004b5d59:
    // 004b5d59  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b5d5b  668b02                 -mov ax, word ptr [edx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edx);
    // 004b5d5e  e8fb020000             -call 0x4b605e
    cpu.esp -= 4;
    sub_4b605e(app, cpu);
    if (cpu.terminate) return;
    // 004b5d63  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004b5d65  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b5d67  668b03                 -mov ax, word ptr [ebx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx);
    // 004b5d6a  e8ef020000             -call 0x4b605e
    cpu.esp -= 4;
    sub_4b605e(app, cpu);
    if (cpu.terminate) return;
    // 004b5d6f  6639c1                 +cmp cx, ax
    {
        x86::reg16 tmp1 = cpu.cx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(cpu.ax));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004b5d72  0f8592000000           -jne 0x4b5e0a
    if (!cpu.flags.zf)
    {
        goto L_0x004b5e0a;
    }
    // 004b5d78  66833a3d               +cmp word ptr [edx], 0x3d
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.edx);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(61 /*0x3d*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004b5d7c  0f8578000000           -jne 0x4b5dfa
    if (!cpu.flags.zf)
    {
        goto L_0x004b5dfa;
    }
    // 004b5d82  8b15d0935400           -mov edx, dword ptr [0x5493d0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5542864) /* 0x5493d0 */);
    // 004b5d88  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 004b5d8a  29d7                   -sub edi, edx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b5d8c  c1ff02                 -sar edi, 2
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (2 /*0x2*/ % 32));
    // 004b5d8f  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004b5d91  7462                   -je 0x4b5df5
    if (cpu.flags.zf)
    {
        goto L_0x004b5df5;
    }
    // 004b5d93  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004b5d95  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004b5d97  eb08                   -jmp 0x4b5da1
    goto L_0x004b5da1;
L_0x004b5d99:
    // 004b5d99  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004b5d9c  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 004b5d9e  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004b5da1:
    // 004b5da1  833900                 +cmp dword ptr [ecx], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b5da4  75f3                   -jne 0x4b5d99
    if (!cpu.flags.zf)
    {
        goto L_0x004b5d99;
    }
    // 004b5da6  8b35c8935400           -mov esi, dword ptr [0x5493c8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5542856) /* 0x5493c8 */);
    // 004b5dac  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004b5dae  7441                   -je 0x4b5df1
    if (cpu.flags.zf)
    {
        goto L_0x004b5df1;
    }
    // 004b5db0  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b5db2  803c0700               +cmp byte ptr [edi + eax], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edi + cpu.eax * 1);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b5db6  7407                   -je 0x4b5dbf
    if (cpu.flags.zf)
    {
        goto L_0x004b5dbf;
    }
    // 004b5db8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b5dba  e8ea92feff             -call 0x49f0a9
    cpu.esp -= 4;
    sub_49f0a9(app, cpu);
    if (cpu.terminate) return;
L_0x004b5dbf:
    // 004b5dbf  8b2dd0935400           -mov ebp, dword ptr [0x5493d0]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5542864) /* 0x5493d0 */);
    // 004b5dc5  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004b5dc7  29ee                   -sub esi, ebp
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004b5dc9  8b15c8935400           -mov edx, dword ptr [0x5493c8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5542856) /* 0x5493c8 */);
    // 004b5dcf  c1fe02                 +sar esi, 2
    {
        x86::reg8 tmp = 2 /*0x2*/ % 32;
        x86::reg32& op = cpu.esi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 004b5dd2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b5dd4  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004b5dd6  e84c000000             -call 0x4b5e27
    cpu.esp -= 4;
    sub_4b5e27(app, cpu);
    if (cpu.terminate) return;
    // 004b5ddb  890dc8935400           -mov dword ptr [0x5493c8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5542856) /* 0x5493c8 */) = cpu.ecx;
    // 004b5de1  8d040f                 -lea eax, [edi + ecx]
    cpu.eax = x86::reg32(cpu.edi + cpu.ecx * 1);
    // 004b5de4  eb07                   -jmp 0x4b5ded
    goto L_0x004b5ded;
L_0x004b5de6:
    // 004b5de6  8a5001                 -mov dl, byte ptr [eax + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b5de9  47                     -inc edi
    (cpu.edi)++;
    // 004b5dea  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 004b5dec  40                     -inc eax
    (cpu.eax)++;
L_0x004b5ded:
    // 004b5ded  39f7                   +cmp edi, esi
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
    // 004b5def  7cf5                   -jl 0x4b5de6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b5de6;
    }
L_0x004b5df1:
    // 004b5df1  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004b5df3  eb2c                   -jmp 0x4b5e21
    goto L_0x004b5e21;
L_0x004b5df5:
    // 004b5df5  8d4701                 -lea eax, [edi + 1]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 004b5df8  eb27                   -jmp 0x4b5e21
    goto L_0x004b5e21;
L_0x004b5dfa:
    // 004b5dfa  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004b5dfd  83c302                 -add ebx, 2
    (cpu.ebx) += x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x004b5e00:
    // 004b5e00  66833b00               +cmp word ptr [ebx], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ebx);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004b5e04  0f854fffffff           -jne 0x4b5d59
    if (!cpu.flags.zf)
    {
        goto L_0x004b5d59;
    }
L_0x004b5e0a:
    // 004b5e0a  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004b5e0d:
    // 004b5e0d  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004b5e0f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b5e11  0f853bffffff           -jne 0x4b5d52
    if (!cpu.flags.zf)
    {
        goto L_0x004b5d52;
    }
    // 004b5e17  a1d0935400             -mov eax, dword ptr [0x5493d0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5542864) /* 0x5493d0 */);
    // 004b5e1c  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004b5e1e  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
L_0x004b5e21:
    // 004b5e21  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5e22  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5e23  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5e24  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5e25  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5e26  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b5e27(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b5e27  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b5e28  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b5e29  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b5e2a  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004b5e2c  39c2                   +cmp edx, eax
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
    // 004b5e2e  7440                   -je 0x4b5e70
    if (cpu.flags.zf)
    {
        goto L_0x004b5e70;
    }
    // 004b5e30  7328                   -jae 0x4b5e5a
    if (!cpu.flags.cf)
    {
        goto L_0x004b5e5a;
    }
    // 004b5e32  8d3c1a                 -lea edi, [edx + ebx]
    cpu.edi = x86::reg32(cpu.edx + cpu.ebx * 1);
    // 004b5e35  39c7                   +cmp edi, eax
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
    // 004b5e37  7621                   -jbe 0x4b5e5a
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b5e5a;
    }
    // 004b5e39  8d77ff                 -lea esi, [edi - 1]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(-1) /* -0x1 */);
    // 004b5e3c  8d3c18                 -lea edi, [eax + ebx]
    cpu.edi = x86::reg32(cpu.eax + cpu.ebx * 1);
    // 004b5e3f  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 004b5e41  4f                     -dec edi
    (cpu.edi)--;
    // 004b5e42  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004b5e43  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
    // 004b5e45  fd                     -std 
    cpu.flags.df = 1;
    // 004b5e46  4e                     -dec esi
    (cpu.esi)--;
    // 004b5e47  4f                     -dec edi
    (cpu.edi)--;
    // 004b5e48  d1e9                   +shr ecx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.ecx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 004b5e4a  66f3a5                 -rep movsw word ptr es:[edi], word ptr [esi]
    while (cpu.ecx)
    {
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
        --cpu.ecx;
    }
    // 004b5e4d  11c9                   -adc ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 004b5e4f  46                     -inc esi
    (cpu.esi)++;
    // 004b5e50  47                     -inc edi
    (cpu.edi)++;
    // 004b5e51  66f3a4                 -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 004b5e54  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004b5e55  fc                     -cld 
    cpu.flags.df = 0;
    // 004b5e56  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5e57  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5e58  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5e59  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b5e5a:
    // 004b5e5a  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004b5e5c  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004b5e5e  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 004b5e60  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004b5e61  8ec2                   -mov es, edx
    cpu.es = cpu.edx;
    // 004b5e63  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b5e64  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004b5e67  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b5e69  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5e6a  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004b5e6d  f3a4                   -rep movsb byte ptr es:[edi], byte ptr [esi]
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
    }
    // 004b5e6f  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
L_0x004b5e70:
    // 004b5e70  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5e71  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5e72  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5e73  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b5e74(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b5e74  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b5e75  833ddc93540000         +cmp dword ptr [0x5493dc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5542876) /* 0x5493dc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b5e7c  7428                   -je 0x4b5ea6
    if (cpu.flags.zf)
    {
        goto L_0x004b5ea6;
    }
    // 004b5e7e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b5e80  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004b5e82  8a92e1935400           -mov dl, byte ptr [edx + 0x5493e1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5542881) /* 0x5493e1 */);
    // 004b5e88  80e201                 -and dl, 1
    cpu.dl &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004b5e8b  81e2ff000000           +and edx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004b5e91  7413                   -je 0x4b5ea6
    if (cpu.flags.zf)
    {
        goto L_0x004b5ea6;
    }
    // 004b5e93  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b5e95  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004b5e97  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004b5e9a  8a4001                 -mov al, byte ptr [eax + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b5e9d  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b5ea2  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 004b5ea4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5ea5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b5ea6:
    // 004b5ea6  8a00                   -mov al, byte ptr [eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax);
    // 004b5ea8  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b5ead  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5eae  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b5eaf(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b5eaf  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b5eb0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b5eb1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b5eb2  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b5eb5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b5eb7  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004b5eb9  e85a000000             -call 0x4b5f18
    cpu.esp -= 4;
    sub_4b5f18(app, cpu);
    if (cpu.terminate) return;
    // 004b5ebe  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b5ec0  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 004b5ec2  e8febfffff             -call 0x4b1ec5
    cpu.esp -= 4;
    sub_4b1ec5(app, cpu);
    if (cpu.terminate) return;
    // 004b5ec7  881404                 -mov byte ptr [esp + eax], dl
    app->getMemory<x86::reg8>(cpu.esp + cpu.eax * 1) = cpu.dl;
    // 004b5eca  813d88fb4c00a4030000   +cmp dword ptr [0x4cfb88], 0x3a4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5045128) /* 0x4cfb88 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(932 /*0x3a4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b5ed4  7526                   -jne 0x4b5efc
    if (!cpu.flags.zf)
    {
        goto L_0x004b5efc;
    }
    // 004b5ed6  833ddc93540000         +cmp dword ptr [0x5493dc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5542876) /* 0x5493dc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b5edd  741d                   -je 0x4b5efc
    if (cpu.flags.zf)
    {
        goto L_0x004b5efc;
    }
    // 004b5edf  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b5ee1  8a0424                 -mov al, byte ptr [esp]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp);
    // 004b5ee4  8a80e1935400           -mov al, byte ptr [eax + 0x5493e1]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5542881) /* 0x5493e1 */);
    // 004b5eea  2401                   -and al, 1
    cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004b5eec  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004b5ef1  7409                   -je 0x4b5efc
    if (cpu.flags.zf)
    {
        goto L_0x004b5efc;
    }
    // 004b5ef3  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b5ef5  e874010000             -call 0x4b606e
    cpu.esp -= 4;
    sub_4b606e(app, cpu);
    if (cpu.terminate) return;
    // 004b5efa  eb15                   -jmp 0x4b5f11
    goto L_0x004b5f11;
L_0x004b5efc:
    // 004b5efc  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004b5efe  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b5f02  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b5f03  2eff15c0734b00         -call dword ptr cs:[0x4b73c0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944832) /* 0x4b73c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b5f0a  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b5f0c  e863ffffff             -call 0x4b5e74
    cpu.esp -= 4;
    sub_4b5e74(app, cpu);
    if (cpu.terminate) return;
L_0x004b5f11:
    // 004b5f11  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b5f14  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5f15  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5f16  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5f17  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b5f18(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b5f18  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b5f19  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b5f1b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b5f1d  f6c7ff                 +test bh, 0xff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 255 /*0xff*/));
    // 004b5f20  740c                   -je 0x4b5f2e
    if (cpu.flags.zf)
    {
        goto L_0x004b5f2e;
    }
    // 004b5f22  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b5f24  885801                 -mov byte ptr [eax + 1], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = cpu.bl;
    // 004b5f27  c1ea08                 -shr edx, 8
    cpu.edx >>= 8 /*0x8*/ % 32;
    // 004b5f2a  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 004b5f2c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5f2d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b5f2e:
    // 004b5f2e  881a                   -mov byte ptr [edx], bl
    app->getMemory<x86::reg8>(cpu.edx) = cpu.bl;
    // 004b5f30  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5f31  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b5f32(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b5f32  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b5f33  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
L_0x004b5f35:
    // 004b5f35  663b18                 +cmp bx, word ptr [eax]
    {
        x86::reg16 tmp1 = cpu.bx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(app->getMemory<x86::reg16>(cpu.eax)));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004b5f38  740c                   -je 0x4b5f46
    if (cpu.flags.zf)
    {
        goto L_0x004b5f46;
    }
    // 004b5f3a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b5f3c  40                     -inc eax
    (cpu.eax)++;
    // 004b5f3d  40                     -inc eax
    (cpu.eax)++;
    // 004b5f3e  66833a00               +cmp word ptr [edx], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.edx);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004b5f42  75f1                   -jne 0x4b5f35
    if (!cpu.flags.zf)
    {
        goto L_0x004b5f35;
    }
    // 004b5f44  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004b5f46:
    // 004b5f46  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5f47  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b5f48(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b5f48  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b5f49  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b5f4a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b5f4b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b5f4c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b5f4d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b5f4e  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004b5f50  66813d49ce4c000080     +cmp word ptr [0x4cce49], 0x8000
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5033545) /* 0x4cce49 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(32768 /*0x8000*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004b5f59  730e                   -jae 0x4b5f69
    if (!cpu.flags.cf)
    {
        goto L_0x004b5f69;
    }
    // 004b5f5b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b5f5c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b5f5d  2eff1580754b00         -call dword ptr cs:[0x4b7580]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945280) /* 0x4b7580 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b5f64  e99c000000             -jmp 0x4b6005
    goto L_0x004b6005;
L_0x004b5f69:
    // 004b5f69  e8cbb7ffff             -call 0x4b1739
    cpu.esp -= 4;
    sub_4b1739(app, cpu);
    if (cpu.terminate) return;
    // 004b5f6e  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b5f70  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b5f73  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b5f75  e89940feff             -call 0x49a013
    cpu.esp -= 4;
    malloc(app, cpu);
    if (cpu.terminate) return;
    // 004b5f7a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b5f7c  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004b5f7e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b5f80  0f847f000000           -je 0x4b6005
    if (cpu.flags.zf)
    {
        goto L_0x004b6005;
    }
    // 004b5f86  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004b5f88  7504                   -jne 0x4b5f8e
    if (!cpu.flags.zf)
    {
        goto L_0x004b5f8e;
    }
    // 004b5f8a  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 004b5f8c  eb1d                   -jmp 0x4b5fab
    goto L_0x004b5fab;
L_0x004b5f8e:
    // 004b5f8e  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004b5f90  e8a4b7ffff             -call 0x4b1739
    cpu.esp -= 4;
    sub_4b1739(app, cpu);
    if (cpu.terminate) return;
    // 004b5f95  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b5f97  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b5f9a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b5f9c  e87240feff             -call 0x49a013
    cpu.esp -= 4;
    malloc(app, cpu);
    if (cpu.terminate) return;
    // 004b5fa1  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b5fa3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b5fa5  7504                   -jne 0x4b5fab
    if (!cpu.flags.zf)
    {
        goto L_0x004b5fab;
    }
    // 004b5fa7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b5fa9  eb1e                   -jmp 0x4b5fc9
    goto L_0x004b5fc9;
L_0x004b5fab:
    // 004b5fab  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004b5fae  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004b5fb0  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004b5fb2  e8ed81ffff             -call 0x4ae1a4
    cpu.esp -= 4;
    sub_4ae1a4(app, cpu);
    if (cpu.terminate) return;
    // 004b5fb7  83f8ff                 +cmp eax, -1
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
    // 004b5fba  7516                   -jne 0x4b5fd2
    if (!cpu.flags.zf)
    {
        goto L_0x004b5fd2;
    }
    // 004b5fbc  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004b5fbe  e8e690feff             -call 0x49f0a9
    cpu.esp -= 4;
    sub_49f0a9(app, cpu);
    if (cpu.terminate) return;
    // 004b5fc3  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004b5fc5  7407                   -je 0x4b5fce
    if (cpu.flags.zf)
    {
        goto L_0x004b5fce;
    }
L_0x004b5fc7:
    // 004b5fc7  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x004b5fc9:
    // 004b5fc9  e8db90feff             -call 0x49f0a9
    cpu.esp -= 4;
    sub_49f0a9(app, cpu);
    if (cpu.terminate) return;
L_0x004b5fce:
    // 004b5fce  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004b5fd0  eb33                   -jmp 0x4b6005
    goto L_0x004b6005;
L_0x004b5fd2:
    // 004b5fd2  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004b5fd4  7410                   -je 0x4b5fe6
    if (cpu.flags.zf)
    {
        goto L_0x004b5fe6;
    }
    // 004b5fd6  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004b5fd8  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004b5fda  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b5fdc  e8c381ffff             -call 0x4ae1a4
    cpu.esp -= 4;
    sub_4ae1a4(app, cpu);
    if (cpu.terminate) return;
    // 004b5fe1  83f8ff                 +cmp eax, -1
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
    // 004b5fe4  74e1                   -je 0x4b5fc7
    if (cpu.flags.zf)
    {
        goto L_0x004b5fc7;
    }
L_0x004b5fe6:
    // 004b5fe6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b5fe7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b5fe8  2eff157c754b00         -call dword ptr cs:[0x4b757c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945276) /* 0x4b757c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b5fef  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b5ff1  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004b5ff3  e8b190feff             -call 0x49f0a9
    cpu.esp -= 4;
    sub_49f0a9(app, cpu);
    if (cpu.terminate) return;
    // 004b5ff8  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004b5ffa  7407                   -je 0x4b6003
    if (cpu.flags.zf)
    {
        goto L_0x004b6003;
    }
    // 004b5ffc  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b5ffe  e8a690feff             -call 0x49f0a9
    cpu.esp -= 4;
    sub_49f0a9(app, cpu);
    if (cpu.terminate) return;
L_0x004b6003:
    // 004b6003  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x004b6005:
    // 004b6005  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b6008  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6009  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b600a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b600b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b600c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b600d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b600e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b600e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b600f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b6010  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b6011  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b6012  8b35cc935400           -mov esi, dword ptr [0x5493cc]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5542860) /* 0x5493cc */);
    // 004b6018  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004b601a  743d                   -je 0x4b6059
    if (cpu.flags.zf)
    {
        goto L_0x004b6059;
    }
L_0x004b601c:
    // 004b601c  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004b601e  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b6021  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b6023  7434                   -je 0x4b6059
    if (cpu.flags.zf)
    {
        goto L_0x004b6059;
    }
    // 004b6025  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b6027  e806faffff             -call 0x4b5a32
    cpu.esp -= 4;
    sub_4b5a32(app, cpu);
    if (cpu.terminate) return;
    // 004b602c  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b602f  8d041b                 -lea eax, [ebx + ebx]
    cpu.eax = x86::reg32(cpu.ebx + cpu.ebx * 1);
    // 004b6032  e8dc3ffeff             -call 0x49a013
    cpu.esp -= 4;
    malloc(app, cpu);
    if (cpu.terminate) return;
    // 004b6037  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004b6039  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b603b  74df                   -je 0x4b601c
    if (cpu.flags.zf)
    {
        goto L_0x004b601c;
    }
    // 004b603d  e812faffff             -call 0x4b5a54
    cpu.esp -= 4;
    sub_4b5a54(app, cpu);
    if (cpu.terminate) return;
    // 004b6042  83f8ff                 +cmp eax, -1
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
    // 004b6045  7409                   -je 0x4b6050
    if (cpu.flags.zf)
    {
        goto L_0x004b6050;
    }
    // 004b6047  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b6049  e8a4fbffff             -call 0x4b5bf2
    cpu.esp -= 4;
    sub_4b5bf2(app, cpu);
    if (cpu.terminate) return;
    // 004b604e  ebcc                   -jmp 0x4b601c
    goto L_0x004b601c;
L_0x004b6050:
    // 004b6050  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b6052  e85290feff             -call 0x49f0a9
    cpu.esp -= 4;
    sub_49f0a9(app, cpu);
    if (cpu.terminate) return;
    // 004b6057  ebc3                   -jmp 0x4b601c
    goto L_0x004b601c;
L_0x004b6059:
    // 004b6059  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b605a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b605b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b605c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b605d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b605e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b605e  663d6100               +cmp ax, 0x61
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
    // 004b6062  7209                   -jb 0x4b606d
    if (cpu.flags.cf)
    {
        goto L_0x004b606d;
    }
    // 004b6064  663d7a00               +cmp ax, 0x7a
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
    // 004b6068  7703                   -ja 0x4b606d
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004b606d;
    }
    // 004b606a  83e820                 -sub eax, 0x20
    (cpu.eax) -= x86::reg32(x86::sreg32(32 /*0x20*/));
L_0x004b606d:
    // 004b606d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b606e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b606e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b606f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b6071  e80b000000             -call 0x4b6081
    cpu.esp -= 4;
    sub_4b6081(app, cpu);
    if (cpu.terminate) return;
    // 004b6076  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b6078  7403                   -je 0x4b607d
    if (cpu.flags.zf)
    {
        goto L_0x004b607d;
    }
    // 004b607a  83ea21                 -sub edx, 0x21
    (cpu.edx) -= x86::reg32(x86::sreg32(33 /*0x21*/));
L_0x004b607d:
    // 004b607d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b607f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6080  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b6081(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b6081  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b6082  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b6084  e83b000000             -call 0x4b60c4
    cpu.esp -= 4;
    sub_4b60c4(app, cpu);
    if (cpu.terminate) return;
    // 004b6089  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b608b  741f                   -je 0x4b60ac
    if (cpu.flags.zf)
    {
        goto L_0x004b60ac;
    }
    // 004b608d  81fa81820000           +cmp edx, 0x8281
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(33409 /*0x8281*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b6093  7211                   -jb 0x4b60a6
    if (cpu.flags.cf)
    {
        goto L_0x004b60a6;
    }
    // 004b6095  81fa9a820000           +cmp edx, 0x829a
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(33434 /*0x829a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b609b  7709                   -ja 0x4b60a6
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004b60a6;
    }
    // 004b609d  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004b60a2  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b60a4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b60a5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b60a6:
    // 004b60a6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b60a8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b60aa  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b60ab  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b60ac:
    // 004b60ac  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 004b60ae  fec0                   -inc al
    (cpu.al)++;
    // 004b60b0  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b60b2  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 004b60b4  8a82c8ea4c00           -mov al, byte ptr [edx + 0x4ceac8]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5040840) /* 0x4ceac8 */);
    // 004b60ba  2480                   -and al, 0x80
    cpu.al &= x86::reg8(x86::sreg8(128 /*0x80*/));
    // 004b60bc  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b60be  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 004b60c0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b60c2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b60c3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b60c4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b60c4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b60c5  833ddc93540000         +cmp dword ptr [0x5493dc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5542876) /* 0x5493dc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b60cc  7431                   -je 0x4b60ff
    if (cpu.flags.zf)
    {
        goto L_0x004b60ff;
    }
    // 004b60ce  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b60d0  c1ea08                 -shr edx, 8
    cpu.edx >>= 8 /*0x8*/ % 32;
    // 004b60d3  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b60d9  8a92e1935400           -mov dl, byte ptr [edx + 0x5493e1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5542881) /* 0x5493e1 */);
    // 004b60df  80e201                 -and dl, 1
    cpu.dl &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004b60e2  81e2ff000000           +and edx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004b60e8  7415                   -je 0x4b60ff
    if (cpu.flags.zf)
    {
        goto L_0x004b60ff;
    }
    // 004b60ea  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b60ef  e80f000000             -call 0x4b6103
    cpu.esp -= 4;
    sub_4b6103(app, cpu);
    if (cpu.terminate) return;
    // 004b60f4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b60f6  7407                   -je 0x4b60ff
    if (cpu.flags.zf)
    {
        goto L_0x004b60ff;
    }
    // 004b60f8  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004b60fd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b60fe  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b60ff:
    // 004b60ff  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b6101  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6102  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b6103(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b6103  833ddc93540000         +cmp dword ptr [0x5493dc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5542876) /* 0x5493dc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b610a  7429                   -je 0x4b6135
    if (cpu.flags.zf)
    {
        goto L_0x004b6135;
    }
    // 004b610c  813d88fb4c00a4030000   +cmp dword ptr [0x4cfb88], 0x3a4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5045128) /* 0x4cfb88 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(932 /*0x3a4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b6116  740a                   -je 0x4b6122
    if (cpu.flags.zf)
    {
        goto L_0x004b6122;
    }
    // 004b6118  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b611a  741b                   -je 0x4b6137
    if (cpu.flags.zf)
    {
        goto L_0x004b6137;
    }
    // 004b611c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004b6121  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b6122:
    // 004b6122  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b6127  8a8069014d00           -mov al, byte ptr [eax + 0x4d0169]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5046633) /* 0x4d0169 */);
    // 004b612d  2408                   -and al, 8
    cpu.al &= x86::reg8(x86::sreg8(8 /*0x8*/));
    // 004b612f  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b6134  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b6135:
    // 004b6135  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004b6137:
    // 004b6137  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4b6140(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b6140  833db8024d0000         +cmp dword ptr [0x4d02b8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5046968) /* 0x4d02b8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b6147  751e                   -jne 0x4b6167
    if (!cpu.flags.zf)
    {
        goto L_0x004b6167;
    }
    // 004b6149  6860064d00             -push 0x4d0660
    app->getMemory<x86::reg32>(cpu.esp-4) = 5047904 /*0x4d0660*/;
    cpu.esp -= 4;
    // 004b614e  ff1540754b00           -call dword ptr [0x4b7540]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4945216) /* 0x4b7540 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b6154  a3b8024d00             -mov dword ptr [0x4d02b8], eax
    app->getMemory<x86::reg32>(x86::reg32(5046968) /* 0x4d02b8 */) = cpu.eax;
    // 004b6159  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b615b  750a                   -jne 0x4b6167
    if (!cpu.flags.zf)
    {
        goto L_0x004b6167;
    }
    // 004b615d  c705b8024d00ffffffff   -mov dword ptr [0x4d02b8], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5046968) /* 0x4d02b8 */) = 4294967295 /*0xffffffff*/;
L_0x004b6167:
    // 004b6167  833db8024d00ff         +cmp dword ptr [0x4d02b8], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5046968) /* 0x4d02b8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b616e  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 004b6173  7420                   -je 0x4b6195
    if (cpu.flags.zf)
    {
        goto L_0x004b6195;
    }
    // 004b6175  ff742404               -push dword ptr [esp + 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    // 004b6179  ff35b8024d00           -push dword ptr [0x4d02b8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(x86::reg32(5046968) /* 0x4d02b8 */);
    cpu.esp -= 4;
    // 004b617f  ff1510754b00           -call dword ptr [0x4b7510]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(4945168) /* 0x4b7510 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b6185  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b6189  83f801                 +cmp eax, 1
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
    // 004b618c  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 004b618e  1bc0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 004b6190  2549000080             -and eax, 0x80000049
    cpu.eax &= x86::reg32(x86::sreg32(2147483721 /*0x80000049*/));
L_0x004b6195:
    // 004b6195  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_4b6198(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b6198  833dd8024d0000         +cmp dword ptr [0x4d02d8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5047000) /* 0x4d02d8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b619f  751f                   -jne 0x4b61c0
    if (!cpu.flags.zf)
    {
        goto L_0x004b61c0;
    }
    // 004b61a1  68d8024d00             -push 0x4d02d8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5047000 /*0x4d02d8*/;
    cpu.esp -= 4;
    // 004b61a6  68d8064d00             -push 0x4d06d8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5048024 /*0x4d06d8*/;
    cpu.esp -= 4;
    // 004b61ab  e890ffffff             -call 0x4b6140
    cpu.esp -= 4;
    sub_4b6140(app, cpu);
    if (cpu.terminate) return;
    // 004b61b0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b61b2  740c                   -je 0x4b61c0
    if (cpu.flags.zf)
    {
        goto L_0x004b61c0;
    }
    // 004b61b4  c705d8024d00ffffffff   -mov dword ptr [0x4d02d8], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5047000) /* 0x4d02d8 */) = 4294967295 /*0xffffffff*/;
    // 004b61be  eb20                   -jmp 0x4b61e0
    goto L_0x004b61e0;
L_0x004b61c0:
    // 004b61c0  833dd8024d00ff         +cmp dword ptr [0x4d02d8], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5047000) /* 0x4d02d8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b61c7  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 004b61cc  7412                   -je 0x4b61e0
    if (cpu.flags.zf)
    {
        goto L_0x004b61e0;
    }
    // 004b61ce  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004b61d2  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004b61d6  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004b61da  ff15d8024d00           -call dword ptr [0x4d02d8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5047000) /* 0x4d02d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004b61e0:
    // 004b61e0  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_4b61e3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b61e3  833de8024d0000         +cmp dword ptr [0x4d02e8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5047016) /* 0x4d02e8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b61ea  751f                   -jne 0x4b620b
    if (!cpu.flags.zf)
    {
        goto L_0x004b620b;
    }
    // 004b61ec  68e8024d00             -push 0x4d02e8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5047016 /*0x4d02e8*/;
    cpu.esp -= 4;
    // 004b61f1  6820074d00             -push 0x4d0720
    app->getMemory<x86::reg32>(cpu.esp-4) = 5048096 /*0x4d0720*/;
    cpu.esp -= 4;
    // 004b61f6  e845ffffff             -call 0x4b6140
    cpu.esp -= 4;
    sub_4b6140(app, cpu);
    if (cpu.terminate) return;
    // 004b61fb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b61fd  740c                   -je 0x4b620b
    if (cpu.flags.zf)
    {
        goto L_0x004b620b;
    }
    // 004b61ff  c705e8024d00ffffffff   -mov dword ptr [0x4d02e8], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5047016) /* 0x4d02e8 */) = 4294967295 /*0xffffffff*/;
    // 004b6209  eb18                   -jmp 0x4b6223
    goto L_0x004b6223;
L_0x004b620b:
    // 004b620b  833de8024d00ff         +cmp dword ptr [0x4d02e8], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5047016) /* 0x4d02e8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b6212  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 004b6217  740a                   -je 0x4b6223
    if (cpu.flags.zf)
    {
        goto L_0x004b6223;
    }
    // 004b6219  ff742404               -push dword ptr [esp + 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    // 004b621d  ff15e8024d00           -call dword ptr [0x4d02e8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5047016) /* 0x4d02e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004b6223:
    // 004b6223  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_4b6226(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b6226  833d10034d0000         +cmp dword ptr [0x4d0310], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5047056) /* 0x4d0310 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b622d  751f                   -jne 0x4b624e
    if (!cpu.flags.zf)
    {
        goto L_0x004b624e;
    }
    // 004b622f  6810034d00             -push 0x4d0310
    app->getMemory<x86::reg32>(cpu.esp-4) = 5047056 /*0x4d0310*/;
    cpu.esp -= 4;
    // 004b6234  68f0074d00             -push 0x4d07f0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5048304 /*0x4d07f0*/;
    cpu.esp -= 4;
    // 004b6239  e802ffffff             -call 0x4b6140
    cpu.esp -= 4;
    sub_4b6140(app, cpu);
    if (cpu.terminate) return;
    // 004b623e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b6240  740c                   -je 0x4b624e
    if (cpu.flags.zf)
    {
        goto L_0x004b624e;
    }
    // 004b6242  c70510034d00ffffffff   -mov dword ptr [0x4d0310], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5047056) /* 0x4d0310 */) = 4294967295 /*0xffffffff*/;
    // 004b624c  eb18                   -jmp 0x4b6266
    goto L_0x004b6266;
L_0x004b624e:
    // 004b624e  833d10034d00ff         +cmp dword ptr [0x4d0310], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5047056) /* 0x4d0310 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b6255  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 004b625a  740a                   -je 0x4b6266
    if (cpu.flags.zf)
    {
        goto L_0x004b6266;
    }
    // 004b625c  ff742404               -push dword ptr [esp + 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    // 004b6260  ff1510034d00           -call dword ptr [0x4d0310]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5047056) /* 0x4d0310 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004b6266:
    // 004b6266  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_4b6269(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b6269  833d28034d0000         +cmp dword ptr [0x4d0328], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5047080) /* 0x4d0328 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b6270  751f                   -jne 0x4b6291
    if (!cpu.flags.zf)
    {
        goto L_0x004b6291;
    }
    // 004b6272  6828034d00             -push 0x4d0328
    app->getMemory<x86::reg32>(cpu.esp-4) = 5047080 /*0x4d0328*/;
    cpu.esp -= 4;
    // 004b6277  6850084d00             -push 0x4d0850
    app->getMemory<x86::reg32>(cpu.esp-4) = 5048400 /*0x4d0850*/;
    cpu.esp -= 4;
    // 004b627c  e8bffeffff             -call 0x4b6140
    cpu.esp -= 4;
    sub_4b6140(app, cpu);
    if (cpu.terminate) return;
    // 004b6281  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b6283  740c                   -je 0x4b6291
    if (cpu.flags.zf)
    {
        goto L_0x004b6291;
    }
    // 004b6285  c70528034d00ffffffff   -mov dword ptr [0x4d0328], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5047080) /* 0x4d0328 */) = 4294967295 /*0xffffffff*/;
    // 004b628f  eb20                   -jmp 0x4b62b1
    goto L_0x004b62b1;
L_0x004b6291:
    // 004b6291  833d28034d00ff         +cmp dword ptr [0x4d0328], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5047080) /* 0x4d0328 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b6298  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 004b629d  7412                   -je 0x4b62b1
    if (cpu.flags.zf)
    {
        goto L_0x004b62b1;
    }
    // 004b629f  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004b62a3  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004b62a7  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004b62ab  ff1528034d00           -call dword ptr [0x4d0328]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5047080) /* 0x4d0328 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004b62b1:
    // 004b62b1  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_4b62b4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b62b4  833dc4034d0000         +cmp dword ptr [0x4d03c4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5047236) /* 0x4d03c4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b62bb  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b62bc  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b62be  751f                   -jne 0x4b62df
    if (!cpu.flags.zf)
    {
        goto L_0x004b62df;
    }
    // 004b62c0  68c4034d00             -push 0x4d03c4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5047236 /*0x4d03c4*/;
    cpu.esp -= 4;
    // 004b62c5  685c0b4d00             -push 0x4d0b5c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5049180 /*0x4d0b5c*/;
    cpu.esp -= 4;
    // 004b62ca  e871feffff             -call 0x4b6140
    cpu.esp -= 4;
    sub_4b6140(app, cpu);
    if (cpu.terminate) return;
    // 004b62cf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b62d1  740c                   -je 0x4b62df
    if (cpu.flags.zf)
    {
        goto L_0x004b62df;
    }
    // 004b62d3  c705c4034d00ffffffff   -mov dword ptr [0x4d03c4], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5047236) /* 0x4d03c4 */) = 4294967295 /*0xffffffff*/;
    // 004b62dd  eb23                   -jmp 0x4b6302
    goto L_0x004b6302;
L_0x004b62df:
    // 004b62df  833dc4034d00ff         +cmp dword ptr [0x4d03c4], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5047236) /* 0x4d03c4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b62e6  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 004b62eb  7415                   -je 0x4b6302
    if (cpu.flags.zf)
    {
        goto L_0x004b6302;
    }
    // 004b62ed  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 004b62f0  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 004b62f3  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 004b62f6  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004b62f9  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 004b62fc  ff15c4034d00           -call dword ptr [0x4d03c4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5047236) /* 0x4d03c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004b6302:
    // 004b6302  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6303  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip  */
void Application::sub_4b6306(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b6306  833dd0034d0000         +cmp dword ptr [0x4d03d0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5047248) /* 0x4d03d0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b630d  751f                   -jne 0x4b632e
    if (!cpu.flags.zf)
    {
        goto L_0x004b632e;
    }
    // 004b630f  68d0034d00             -push 0x4d03d0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5047248 /*0x4d03d0*/;
    cpu.esp -= 4;
    // 004b6314  688c0b4d00             -push 0x4d0b8c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5049228 /*0x4d0b8c*/;
    cpu.esp -= 4;
    // 004b6319  e822feffff             -call 0x4b6140
    cpu.esp -= 4;
    sub_4b6140(app, cpu);
    if (cpu.terminate) return;
    // 004b631e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b6320  740c                   -je 0x4b632e
    if (cpu.flags.zf)
    {
        goto L_0x004b632e;
    }
    // 004b6322  c705d0034d00ffffffff   -mov dword ptr [0x4d03d0], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5047248) /* 0x4d03d0 */) = 4294967295 /*0xffffffff*/;
    // 004b632c  eb20                   -jmp 0x4b634e
    goto L_0x004b634e;
L_0x004b632e:
    // 004b632e  833dd0034d00ff         +cmp dword ptr [0x4d03d0], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5047248) /* 0x4d03d0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b6335  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 004b633a  7412                   -je 0x4b634e
    if (cpu.flags.zf)
    {
        goto L_0x004b634e;
    }
    // 004b633c  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004b6340  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004b6344  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004b6348  ff15d0034d00           -call dword ptr [0x4d03d0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5047248) /* 0x4d03d0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004b634e:
    // 004b634e  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_4b6351(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b6351  833dec034d0000         +cmp dword ptr [0x4d03ec], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5047276) /* 0x4d03ec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b6358  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b6359  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b635b  751f                   -jne 0x4b637c
    if (!cpu.flags.zf)
    {
        goto L_0x004b637c;
    }
    // 004b635d  68ec034d00             -push 0x4d03ec
    app->getMemory<x86::reg32>(cpu.esp-4) = 5047276 /*0x4d03ec*/;
    cpu.esp -= 4;
    // 004b6362  68040c4d00             -push 0x4d0c04
    app->getMemory<x86::reg32>(cpu.esp-4) = 5049348 /*0x4d0c04*/;
    cpu.esp -= 4;
    // 004b6367  e8d4fdffff             -call 0x4b6140
    cpu.esp -= 4;
    sub_4b6140(app, cpu);
    if (cpu.terminate) return;
    // 004b636c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b636e  740c                   -je 0x4b637c
    if (cpu.flags.zf)
    {
        goto L_0x004b637c;
    }
    // 004b6370  c705ec034d00ffffffff   -mov dword ptr [0x4d03ec], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5047276) /* 0x4d03ec */) = 4294967295 /*0xffffffff*/;
    // 004b637a  eb26                   -jmp 0x4b63a2
    goto L_0x004b63a2;
L_0x004b637c:
    // 004b637c  833dec034d00ff         +cmp dword ptr [0x4d03ec], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5047276) /* 0x4d03ec */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b6383  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 004b6388  7418                   -je 0x4b63a2
    if (cpu.flags.zf)
    {
        goto L_0x004b63a2;
    }
    // 004b638a  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 004b638d  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 004b6390  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 004b6393  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 004b6396  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004b6399  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 004b639c  ff15ec034d00           -call dword ptr [0x4d03ec]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5047276) /* 0x4d03ec */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004b63a2:
    // 004b63a2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b63a3  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip  */
void Application::sub_4b63a6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b63a6  833df8034d0000         +cmp dword ptr [0x4d03f8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5047288) /* 0x4d03f8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b63ad  751f                   -jne 0x4b63ce
    if (!cpu.flags.zf)
    {
        goto L_0x004b63ce;
    }
    // 004b63af  68f8034d00             -push 0x4d03f8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5047288 /*0x4d03f8*/;
    cpu.esp -= 4;
    // 004b63b4  68280c4d00             -push 0x4d0c28
    app->getMemory<x86::reg32>(cpu.esp-4) = 5049384 /*0x4d0c28*/;
    cpu.esp -= 4;
    // 004b63b9  e882fdffff             -call 0x4b6140
    cpu.esp -= 4;
    sub_4b6140(app, cpu);
    if (cpu.terminate) return;
    // 004b63be  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b63c0  740c                   -je 0x4b63ce
    if (cpu.flags.zf)
    {
        goto L_0x004b63ce;
    }
    // 004b63c2  c705f8034d00ffffffff   -mov dword ptr [0x4d03f8], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5047288) /* 0x4d03f8 */) = 4294967295 /*0xffffffff*/;
    // 004b63cc  eb1c                   -jmp 0x4b63ea
    goto L_0x004b63ea;
L_0x004b63ce:
    // 004b63ce  833df8034d00ff         +cmp dword ptr [0x4d03f8], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5047288) /* 0x4d03f8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b63d5  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 004b63da  740e                   -je 0x4b63ea
    if (cpu.flags.zf)
    {
        goto L_0x004b63ea;
    }
    // 004b63dc  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 004b63e0  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 004b63e4  ff15f8034d00           -call dword ptr [0x4d03f8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5047288) /* 0x4d03f8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004b63ea:
    // 004b63ea  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_4b63ed(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b63ed  833d44044d0000         +cmp dword ptr [0x4d0444], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5047364) /* 0x4d0444 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b63f4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b63f5  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b63f7  751f                   -jne 0x4b6418
    if (!cpu.flags.zf)
    {
        goto L_0x004b6418;
    }
    // 004b63f9  6844044d00             -push 0x4d0444
    app->getMemory<x86::reg32>(cpu.esp-4) = 5047364 /*0x4d0444*/;
    cpu.esp -= 4;
    // 004b63fe  689c0d4d00             -push 0x4d0d9c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5049756 /*0x4d0d9c*/;
    cpu.esp -= 4;
    // 004b6403  e838fdffff             -call 0x4b6140
    cpu.esp -= 4;
    sub_4b6140(app, cpu);
    if (cpu.terminate) return;
    // 004b6408  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b640a  740c                   -je 0x4b6418
    if (cpu.flags.zf)
    {
        goto L_0x004b6418;
    }
    // 004b640c  c70544044d00ffffffff   -mov dword ptr [0x4d0444], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5047364) /* 0x4d0444 */) = 4294967295 /*0xffffffff*/;
    // 004b6416  eb23                   -jmp 0x4b643b
    goto L_0x004b643b;
L_0x004b6418:
    // 004b6418  833d44044d00ff         +cmp dword ptr [0x4d0444], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5047364) /* 0x4d0444 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b641f  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 004b6424  7415                   -je 0x4b643b
    if (cpu.flags.zf)
    {
        goto L_0x004b643b;
    }
    // 004b6426  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 004b6429  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 004b642c  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 004b642f  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004b6432  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 004b6435  ff1544044d00           -call dword ptr [0x4d0444]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5047364) /* 0x4d0444 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004b643b:
    // 004b643b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b643c  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip  */
void Application::sub_4b643f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b643f  833d50044d0000         +cmp dword ptr [0x4d0450], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5047376) /* 0x4d0450 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b6446  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b6447  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b6449  751f                   -jne 0x4b646a
    if (!cpu.flags.zf)
    {
        goto L_0x004b646a;
    }
    // 004b644b  6850044d00             -push 0x4d0450
    app->getMemory<x86::reg32>(cpu.esp-4) = 5047376 /*0x4d0450*/;
    cpu.esp -= 4;
    // 004b6450  68d40d4d00             -push 0x4d0dd4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5049812 /*0x4d0dd4*/;
    cpu.esp -= 4;
    // 004b6455  e8e6fcffff             -call 0x4b6140
    cpu.esp -= 4;
    sub_4b6140(app, cpu);
    if (cpu.terminate) return;
    // 004b645a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b645c  740c                   -je 0x4b646a
    if (cpu.flags.zf)
    {
        goto L_0x004b646a;
    }
    // 004b645e  c70550044d00ffffffff   -mov dword ptr [0x4d0450], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5047376) /* 0x4d0450 */) = 4294967295 /*0xffffffff*/;
    // 004b6468  eb23                   -jmp 0x4b648d
    goto L_0x004b648d;
L_0x004b646a:
    // 004b646a  833d50044d00ff         +cmp dword ptr [0x4d0450], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5047376) /* 0x4d0450 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b6471  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 004b6476  7415                   -je 0x4b648d
    if (cpu.flags.zf)
    {
        goto L_0x004b648d;
    }
    // 004b6478  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 004b647b  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 004b647e  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 004b6481  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004b6484  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 004b6487  ff1550044d00           -call dword ptr [0x4d0450]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5047376) /* 0x4d0450 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004b648d:
    // 004b648d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b648e  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip  */
void Application::sub_4b6491(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b6491  833d68044d0000         +cmp dword ptr [0x4d0468], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5047400) /* 0x4d0468 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b6498  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b6499  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b649b  751f                   -jne 0x4b64bc
    if (!cpu.flags.zf)
    {
        goto L_0x004b64bc;
    }
    // 004b649d  6868044d00             -push 0x4d0468
    app->getMemory<x86::reg32>(cpu.esp-4) = 5047400 /*0x4d0468*/;
    cpu.esp -= 4;
    // 004b64a2  68400e4d00             -push 0x4d0e40
    app->getMemory<x86::reg32>(cpu.esp-4) = 5049920 /*0x4d0e40*/;
    cpu.esp -= 4;
    // 004b64a7  e894fcffff             -call 0x4b6140
    cpu.esp -= 4;
    sub_4b6140(app, cpu);
    if (cpu.terminate) return;
    // 004b64ac  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b64ae  740c                   -je 0x4b64bc
    if (cpu.flags.zf)
    {
        goto L_0x004b64bc;
    }
    // 004b64b0  c70568044d00ffffffff   -mov dword ptr [0x4d0468], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5047400) /* 0x4d0468 */) = 4294967295 /*0xffffffff*/;
    // 004b64ba  eb26                   -jmp 0x4b64e2
    goto L_0x004b64e2;
L_0x004b64bc:
    // 004b64bc  833d68044d00ff         +cmp dword ptr [0x4d0468], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5047400) /* 0x4d0468 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b64c3  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 004b64c8  7418                   -je 0x4b64e2
    if (cpu.flags.zf)
    {
        goto L_0x004b64e2;
    }
    // 004b64ca  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 004b64cd  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 004b64d0  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 004b64d3  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 004b64d6  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004b64d9  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 004b64dc  ff1568044d00           -call dword ptr [0x4d0468]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5047400) /* 0x4d0468 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004b64e2:
    // 004b64e2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b64e3  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip  */
void Application::sub_4b64e6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b64e6  833d70044d0000         +cmp dword ptr [0x4d0470], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5047408) /* 0x4d0470 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b64ed  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b64ee  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b64f0  751f                   -jne 0x4b6511
    if (!cpu.flags.zf)
    {
        goto L_0x004b6511;
    }
    // 004b64f2  6870044d00             -push 0x4d0470
    app->getMemory<x86::reg32>(cpu.esp-4) = 5047408 /*0x4d0470*/;
    cpu.esp -= 4;
    // 004b64f7  68700e4d00             -push 0x4d0e70
    app->getMemory<x86::reg32>(cpu.esp-4) = 5049968 /*0x4d0e70*/;
    cpu.esp -= 4;
    // 004b64fc  e83ffcffff             -call 0x4b6140
    cpu.esp -= 4;
    sub_4b6140(app, cpu);
    if (cpu.terminate) return;
    // 004b6501  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b6503  740c                   -je 0x4b6511
    if (cpu.flags.zf)
    {
        goto L_0x004b6511;
    }
    // 004b6505  c70570044d00ffffffff   -mov dword ptr [0x4d0470], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5047408) /* 0x4d0470 */) = 4294967295 /*0xffffffff*/;
    // 004b650f  eb2f                   -jmp 0x4b6540
    goto L_0x004b6540;
L_0x004b6511:
    // 004b6511  833d70044d00ff         +cmp dword ptr [0x4d0470], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5047408) /* 0x4d0470 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b6518  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 004b651d  7421                   -je 0x4b6540
    if (cpu.flags.zf)
    {
        goto L_0x004b6540;
    }
    // 004b651f  ff7528                 -push dword ptr [ebp + 0x28]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */);
    cpu.esp -= 4;
    // 004b6522  ff7524                 -push dword ptr [ebp + 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */);
    cpu.esp -= 4;
    // 004b6525  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 004b6528  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 004b652b  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 004b652e  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 004b6531  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 004b6534  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004b6537  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 004b653a  ff1570044d00           -call dword ptr [0x4d0470]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5047408) /* 0x4d0470 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004b6540:
    // 004b6540  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6541  c22400                 -ret 0x24
    cpu.esp += 4+36 /*0x24*/;
    return;
}

/* align: skip  */
void Application::sub_4b6544(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b6544  833d00054d0000         +cmp dword ptr [0x4d0500], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5047552) /* 0x4d0500 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b654b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b654c  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b654e  751f                   -jne 0x4b656f
    if (!cpu.flags.zf)
    {
        goto L_0x004b656f;
    }
    // 004b6550  6800054d00             -push 0x4d0500
    app->getMemory<x86::reg32>(cpu.esp-4) = 5047552 /*0x4d0500*/;
    cpu.esp -= 4;
    // 004b6555  6830114d00             -push 0x4d1130
    app->getMemory<x86::reg32>(cpu.esp-4) = 5050672 /*0x4d1130*/;
    cpu.esp -= 4;
    // 004b655a  e8e1fbffff             -call 0x4b6140
    cpu.esp -= 4;
    sub_4b6140(app, cpu);
    if (cpu.terminate) return;
    // 004b655f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b6561  740c                   -je 0x4b656f
    if (cpu.flags.zf)
    {
        goto L_0x004b656f;
    }
    // 004b6563  c70500054d00ffffffff   -mov dword ptr [0x4d0500], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5047552) /* 0x4d0500 */) = 4294967295 /*0xffffffff*/;
    // 004b656d  eb20                   -jmp 0x4b658f
    goto L_0x004b658f;
L_0x004b656f:
    // 004b656f  833d00054d00ff         +cmp dword ptr [0x4d0500], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5047552) /* 0x4d0500 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b6576  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 004b657b  7412                   -je 0x4b658f
    if (cpu.flags.zf)
    {
        goto L_0x004b658f;
    }
    // 004b657d  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 004b6580  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 004b6583  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004b6586  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 004b6589  ff1500054d00           -call dword ptr [0x4d0500]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5047552) /* 0x4d0500 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004b658f:
    // 004b658f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6590  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::sub_4b6593(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b6593  833d1c054d0000         +cmp dword ptr [0x4d051c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5047580) /* 0x4d051c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b659a  751f                   -jne 0x4b65bb
    if (!cpu.flags.zf)
    {
        goto L_0x004b65bb;
    }
    // 004b659c  681c054d00             -push 0x4d051c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5047580 /*0x4d051c*/;
    cpu.esp -= 4;
    // 004b65a1  68bc114d00             -push 0x4d11bc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5050812 /*0x4d11bc*/;
    cpu.esp -= 4;
    // 004b65a6  e895fbffff             -call 0x4b6140
    cpu.esp -= 4;
    sub_4b6140(app, cpu);
    if (cpu.terminate) return;
    // 004b65ab  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b65ad  740c                   -je 0x4b65bb
    if (cpu.flags.zf)
    {
        goto L_0x004b65bb;
    }
    // 004b65af  c7051c054d00ffffffff   -mov dword ptr [0x4d051c], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5047580) /* 0x4d051c */) = 4294967295 /*0xffffffff*/;
    // 004b65b9  eb20                   -jmp 0x4b65db
    goto L_0x004b65db;
L_0x004b65bb:
    // 004b65bb  833d1c054d00ff         +cmp dword ptr [0x4d051c], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5047580) /* 0x4d051c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b65c2  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 004b65c7  7412                   -je 0x4b65db
    if (cpu.flags.zf)
    {
        goto L_0x004b65db;
    }
    // 004b65c9  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004b65cd  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004b65d1  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004b65d5  ff151c054d00           -call dword ptr [0x4d051c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5047580) /* 0x4d051c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004b65db:
    // 004b65db  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_4b65de(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b65de  833d48054d0000         +cmp dword ptr [0x4d0548], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5047624) /* 0x4d0548 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b65e5  751f                   -jne 0x4b6606
    if (!cpu.flags.zf)
    {
        goto L_0x004b6606;
    }
    // 004b65e7  6848054d00             -push 0x4d0548
    app->getMemory<x86::reg32>(cpu.esp-4) = 5047624 /*0x4d0548*/;
    cpu.esp -= 4;
    // 004b65ec  689c124d00             -push 0x4d129c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5051036 /*0x4d129c*/;
    cpu.esp -= 4;
    // 004b65f1  e84afbffff             -call 0x4b6140
    cpu.esp -= 4;
    sub_4b6140(app, cpu);
    if (cpu.terminate) return;
    // 004b65f6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b65f8  740c                   -je 0x4b6606
    if (cpu.flags.zf)
    {
        goto L_0x004b6606;
    }
    // 004b65fa  c70548054d00ffffffff   -mov dword ptr [0x4d0548], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5047624) /* 0x4d0548 */) = 4294967295 /*0xffffffff*/;
    // 004b6604  eb18                   -jmp 0x4b661e
    goto L_0x004b661e;
L_0x004b6606:
    // 004b6606  833d48054d00ff         +cmp dword ptr [0x4d0548], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5047624) /* 0x4d0548 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b660d  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 004b6612  740a                   -je 0x4b661e
    if (cpu.flags.zf)
    {
        goto L_0x004b661e;
    }
    // 004b6614  ff742404               -push dword ptr [esp + 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    // 004b6618  ff1548054d00           -call dword ptr [0x4d0548]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5047624) /* 0x4d0548 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004b661e:
    // 004b661e  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
/* data blob: d0184d000000000003ffff0000000000c0184d000400000003ffff0000000000b0184d000800000003ffff8000000000000000000c0000000cffff0000000000000000000d0000000cffff0000000000000000000e0000000cffff8000000000000000000f0000000cffff8000000000180000001000000002000000100000000700000030664b000000000000000000d0184d000000000003ffff8000010000c0184d000400000003ffff8000010000b0184d000800000003ffff800001000020194d000c00000003ffff800001000010194d001000000003ffff800001000000194d001400000003ffff8000010000f0184d001800000003ffff8000010000f0184d001c00000003ffff8000010000e0184d002000000010ffff8000000000e0184d002400000010ffff8000000000e0184d002800000010ffff8000000000e0184d002c00000010ffff800000000000000000300000000cffff800000000000000000310000000cffff800000000000000000320000000cffff800000000000000000330000000cffff800000000000000000340000000cffff800000000000000000350000000cffff800000000000000000360000000cffff800000000000000000370000000cffff800000000000000000380000000cffff800000000000000000390000000cffff8000000000000000003a0000000cffff8000000000000000003b0000000cffff8000000000000000003c0000000cffff8000000000000000003d0000000cffff8000000000000000003e0000000cffff8000000000000000003f0000000cffff800000000000000000400000000cffff800000000000000000410000000cffff800000000000000000420000000cffff800000000000000000430000000cffff800000000000000000440000000cffff800000000000000000450000000cffff800000000000000000460000000cffff800000000000000000470000000cffff800000000000000000480000000cffff800000000000000000490000000cffff8000000000000000004a0000000cffff8000000000000000004b0000000cffff8000000000000000004c0000000cffff8000000000000000004d0000000cffff8000000000000000004e0000000cffff8000000000000000004f0000000cffff8000000000180000001000000001000000500000002c000000c0664b00 */
void Application::sub_4b6998(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b6998  ff2594744b00           -jmp dword ptr [0x4b7494]
    return app->dynamic_call(app->getMemory<x86::reg32>(4945044), cpu);
}

/* align: skip  */
void Application::sub_4b699e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b699e  ff2548754b00           -jmp dword ptr [0x4b7548]
    return app->dynamic_call(app->getMemory<x86::reg32>(4945224), cpu);
}

/* align: skip  */
void Application::sub_4b69a4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b69a4  ff259c754b00           -jmp dword ptr [0x4b759c]
    return app->dynamic_call(app->getMemory<x86::reg32>(4945308), cpu);
}

/* align: skip  */
void Application::sub_4b69aa(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b69aa  ff25b8754b00           -jmp dword ptr [0x4b75b8]
    return app->dynamic_call(app->getMemory<x86::reg32>(4945336), cpu);
}

/* align: skip  */
void Application::sub_4b69b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b69b0  ff25c8754b00           -jmp dword ptr [0x4b75c8]
    return app->dynamic_call(app->getMemory<x86::reg32>(4945352), cpu);
}

/* align: skip  */
void Application::sub_4b69b6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b69b6  ff254c754b00           -jmp dword ptr [0x4b754c]
    return app->dynamic_call(app->getMemory<x86::reg32>(4945228), cpu);
}

/* align: skip  */
void Application::sub_4b69bc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b69bc  ff2500754b00           -jmp dword ptr [0x4b7500]
    return app->dynamic_call(app->getMemory<x86::reg32>(4945152), cpu);
}

/* align: skip  */
void Application::sub_4b69c2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b69c2  ff25ac754b00           -jmp dword ptr [0x4b75ac]
    return app->dynamic_call(app->getMemory<x86::reg32>(4945324), cpu);
}

/* align: skip  */
void Application::sub_4b69c8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b69c8  ff25b4754b00           -jmp dword ptr [0x4b75b4]
    return app->dynamic_call(app->getMemory<x86::reg32>(4945332), cpu);
}

/* align: skip  */
void Application::sub_4b69ce(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b69ce  ff25a8754b00           -jmp dword ptr [0x4b75a8]
    return app->dynamic_call(app->getMemory<x86::reg32>(4945320), cpu);
}

/* align: skip  */
void Application::sub_4b69d4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b69d4  ff2590754b00           -jmp dword ptr [0x4b7590]
    return app->dynamic_call(app->getMemory<x86::reg32>(4945296), cpu);
}

/* align: skip  */
void Application::sub_4b69da(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b69da  ff25b0754b00           -jmp dword ptr [0x4b75b0]
    return app->dynamic_call(app->getMemory<x86::reg32>(4945328), cpu);
}

/* align: skip  */
void Application::sub_4b69e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b69e0  ff25e4744b00           -jmp dword ptr [0x4b74e4]
    return app->dynamic_call(app->getMemory<x86::reg32>(4945124), cpu);
}

/* align: skip  */
void Application::sub_4b69e6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b69e6  ff2514754b00           -jmp dword ptr [0x4b7514]
    return app->dynamic_call(app->getMemory<x86::reg32>(4945172), cpu);
}

/* align: skip  */
void Application::sub_4b69ec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b69ec  ff2594754b00           -jmp dword ptr [0x4b7594]
    return app->dynamic_call(app->getMemory<x86::reg32>(4945300), cpu);
}

/* align: skip  */
void Application::sub_4b69f2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b69f2  ff2524754b00           -jmp dword ptr [0x4b7524]
    return app->dynamic_call(app->getMemory<x86::reg32>(4945188), cpu);
}

/* align: skip  */
void Application::sub_4b69f8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b69f8  ff25ec734b00           -jmp dword ptr [0x4b73ec]
    return app->dynamic_call(app->getMemory<x86::reg32>(4944876), cpu);
}

/* align: skip  */
void Application::sub_4b69fe(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b69fe  ff25c4744b00           -jmp dword ptr [0x4b74c4]
    return app->dynamic_call(app->getMemory<x86::reg32>(4945092), cpu);
}

/* align: skip  */
void Application::sub_4b6a04(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b6a04  ff25b4744b00           -jmp dword ptr [0x4b74b4]
    return app->dynamic_call(app->getMemory<x86::reg32>(4945076), cpu);
}

/* align: skip  */
void Application::sub_4b6a0a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b6a0a  ff25b0744b00           -jmp dword ptr [0x4b74b0]
    return app->dynamic_call(app->getMemory<x86::reg32>(4945072), cpu);
}

/* align: skip  */
void Application::sub_4b6a10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b6a10  ff25fc744b00           -jmp dword ptr [0x4b74fc]
    return app->dynamic_call(app->getMemory<x86::reg32>(4945148), cpu);
}

/* align: skip  */
void Application::sub_4b6a16(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b6a16  ff2528754b00           -jmp dword ptr [0x4b7528]
    return app->dynamic_call(app->getMemory<x86::reg32>(4945192), cpu);
}

/* align: skip  */
void Application::sub_4b6a1c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b6a1c  ff25d8744b00           -jmp dword ptr [0x4b74d8]
    return app->dynamic_call(app->getMemory<x86::reg32>(4945112), cpu);
}

/* align: skip  */
void Application::sub_4b6a22(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b6a22  ff25f0744b00           -jmp dword ptr [0x4b74f0]
    return app->dynamic_call(app->getMemory<x86::reg32>(4945136), cpu);
}

/* align: skip  */
void Application::sub_4b6a28(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b6a28  ff2594734b00           -jmp dword ptr [0x4b7394]
    return app->dynamic_call(app->getMemory<x86::reg32>(4944788), cpu);
}

/* align: skip  */
void Application::sub_4b6a2e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b6a2e  ff25a0734b00           -jmp dword ptr [0x4b73a0]
    return app->dynamic_call(app->getMemory<x86::reg32>(4944800), cpu);
}

/* align: skip  */
void Application::sub_4b6a34(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b6a34  ff259c734b00           -jmp dword ptr [0x4b739c]
    return app->dynamic_call(app->getMemory<x86::reg32>(4944796), cpu);
}

/* align: skip  */
void Application::sub_4b6a3a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b6a3a  ff2544744b00           -jmp dword ptr [0x4b7444]
    return app->dynamic_call(app->getMemory<x86::reg32>(4944964), cpu);
}

/* align: skip  */
void Application::sub_4b6a40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b6a40  ff25e8734b00           -jmp dword ptr [0x4b73e8]
    return app->dynamic_call(app->getMemory<x86::reg32>(4944872), cpu);
}

/* align: skip  */
void Application::sub_4b6a46(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b6a46  ff25d4744b00           -jmp dword ptr [0x4b74d4]
    return app->dynamic_call(app->getMemory<x86::reg32>(4945108), cpu);
}

/* align: skip  */
void Application::sub_4b6a4c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b6a4c  ff25c0754b00           -jmp dword ptr [0x4b75c0]
    return app->dynamic_call(app->getMemory<x86::reg32>(4945344), cpu);
}

/* align: skip  */
void Application::sub_4b6a52(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b6a52  ff2518754b00           -jmp dword ptr [0x4b7518]
    return app->dynamic_call(app->getMemory<x86::reg32>(4945176), cpu);
}

/* align: skip  */
void Application::sub_4b6a58(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b6a58  ff25c4754b00           -jmp dword ptr [0x4b75c4]
    return app->dynamic_call(app->getMemory<x86::reg32>(4945348), cpu);
}

/* align: skip  */
void Application::sub_4b6a5e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b6a5e  ff2598734b00           -jmp dword ptr [0x4b7398]
    return app->dynamic_call(app->getMemory<x86::reg32>(4944792), cpu);
}

/* align: skip  */
void Application::sub_4b6a64(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b6a64  ff2564754b00           -jmp dword ptr [0x4b7564]
    return app->dynamic_call(app->getMemory<x86::reg32>(4945252), cpu);
}

/* align: skip  */
void Application::sub_4b6a6a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b6a6a  ff25ac744b00           -jmp dword ptr [0x4b74ac]
    return app->dynamic_call(app->getMemory<x86::reg32>(4945068), cpu);
}

/* align: skip  */
void Application::sub_4b6a70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b6a70  ff2568754b00           -jmp dword ptr [0x4b7568]
    return app->dynamic_call(app->getMemory<x86::reg32>(4945256), cpu);
}

/* align: skip  */
void Application::sub_4b6a76(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b6a76  ff25a4744b00           -jmp dword ptr [0x4b74a4]
    return app->dynamic_call(app->getMemory<x86::reg32>(4945060), cpu);
}

/* align: skip  */
void Application::sub_4b6a7c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b6a7c  ff257c744b00           -jmp dword ptr [0x4b747c]
    return app->dynamic_call(app->getMemory<x86::reg32>(4945020), cpu);
}

/* align: skip  */
void Application::sub_4b6a82(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b6a82  ff2554754b00           -jmp dword ptr [0x4b7554]
    return app->dynamic_call(app->getMemory<x86::reg32>(4945236), cpu);
}

}
