#include "nfs2se.h"
#include <lib/thread.h>

namespace nfs2se
{

/* align: skip 0x90 */
void Application::sub_479d24(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00479d24  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00479d26  a0cfd75100             -mov al, byte ptr [0x51d7cf]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5363663) /* 0x51d7cf */);
    // 00479d2b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_479d2c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00479d2c  803dd0d7510000         +cmp byte ptr [0x51d7d0], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5363664) /* 0x51d7d0 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00479d33  74eb                   -je 0x479d20
    if (cpu.flags.zf)
    {
        return sub_479d20(app, cpu);
    }
    // 00479d35  803da5d7510000         +cmp byte ptr [0x51d7a5], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5363621) /* 0x51d7a5 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00479d3c  75e2                   -jne 0x479d20
    if (!cpu.flags.zf)
    {
        return sub_479d20(app, cpu);
    }
    // 00479d3e  803da4d7510000         +cmp byte ptr [0x51d7a4], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5363620) /* 0x51d7a4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00479d45  75d9                   -jne 0x479d20
    if (!cpu.flags.zf)
    {
        return sub_479d20(app, cpu);
    }
    // 00479d47  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00479d4c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_479d50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00479d50  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00479d52  a0d2d75100             -mov al, byte ptr [0x51d7d2]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5363666) /* 0x51d7d2 */);
    // 00479d57  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_479d58(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00479d58  83ec70                 -sub esp, 0x70
    (cpu.esp) -= x86::reg32(x86::sreg32(112 /*0x70*/));
    // 00479d5b  833df0a64c0000         +cmp dword ptr [0x4ca6f0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5023472) /* 0x4ca6f0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00479d62  741c                   -je 0x479d80
    if (cpu.flags.zf)
    {
        goto L_0x00479d80;
    }
    // 00479d64  833dc8ca4c0000         +cmp dword ptr [0x4ccac8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5032648) /* 0x4ccac8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00479d6b  741c                   -je 0x479d89
    if (cpu.flags.zf)
    {
        goto L_0x00479d89;
    }
    // 00479d6d  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00479d6f  e8ecdc0100             -call 0x497a60
    cpu.esp -= 4;
    sub_497a60(app, cpu);
    if (cpu.terminate) return;
    // 00479d74  e8a3e1ffff             -call 0x477f1c
    cpu.esp -= 4;
    sub_477f1c(app, cpu);
    if (cpu.terminate) return;
    // 00479d79  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00479d7b  e804dd0100             -call 0x497a84
    cpu.esp -= 4;
    sub_497a84(app, cpu);
    if (cpu.terminate) return;
L_0x00479d80:
    // 00479d80  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00479d85  83c470                 -add esp, 0x70
    (cpu.esp) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 00479d88  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00479d89:
    // 00479d89  b870d35100             -mov eax, 0x51d370
    cpu.eax = 5362544 /*0x51d370*/;
    // 00479d8e  e8d1ec0000             -call 0x488a64
    cpu.esp -= 4;
    sub_488a64(app, cpu);
    if (cpu.terminate) return;
    // 00479d93  83c470                 -add esp, 0x70
    (cpu.esp) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 00479d96  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_479d98(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00479d98  833de4d7510000         +cmp dword ptr [0x51d7e4], 0
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
    // 00479d9f  0f847bffffff           -je 0x479d20
    if (cpu.flags.zf)
    {
        return sub_479d20(app, cpu);
    }
    // 00479da5  833dc4d7510000         +cmp dword ptr [0x51d7c4], 0
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
    // 00479dac  0f846effffff           -je 0x479d20
    if (cpu.flags.zf)
    {
        return sub_479d20(app, cpu);
    }
    // 00479db2  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 00479db4  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00479db9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_479dbc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00479dbc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00479dbd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00479dbe  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00479dbf  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00479dc1  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00479dc3  2eff15f4734b00         -call dword ptr cs:[0x4b73f4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944884) /* 0x4b73f4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00479dca  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00479dcc  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 00479dce  2eff15f4734b00         -call dword ptr cs:[0x4b73f4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944884) /* 0x4b73f4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00479dd5  c7430800000000         -mov dword ptr [ebx + 8], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 00479ddc  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00479ddf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479de0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479de1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479de2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_479de4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00479de4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00479de5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00479de6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00479de7  833d98a34c0000         +cmp dword ptr [0x4ca398], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5022616) /* 0x4ca398 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00479dee  750c                   -jne 0x479dfc
    if (!cpu.flags.zf)
    {
        goto L_0x00479dfc;
    }
    // 00479df0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00479df2  746c                   -je 0x479e60
    if (cpu.flags.zf)
    {
        goto L_0x00479e60;
    }
    // 00479df4  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x00479df6:
    // 00479df6  891d98a34c00           -mov dword ptr [0x4ca398], ebx
    app->getMemory<x86::reg32>(x86::reg32(5022616) /* 0x4ca398 */) = cpu.ebx;
L_0x00479dfc:
    // 00479dfc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00479dfe  7505                   -jne 0x479e05
    if (!cpu.flags.zf)
    {
        goto L_0x00479e05;
    }
    // 00479e00  a198a34c00             -mov eax, dword ptr [0x4ca398]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5022616) /* 0x4ca398 */);
L_0x00479e05:
    // 00479e05  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00479e06  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00479e08  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00479e0a  2eff1560744b00         -call dword ptr cs:[0x4b7460]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944992) /* 0x4b7460 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00479e11  a3e8d75100             -mov dword ptr [0x51d7e8], eax
    app->getMemory<x86::reg32>(x86::reg32(5363688) /* 0x51d7e8 */) = cpu.eax;
    // 00479e16  2eff15ec744b00         -call dword ptr cs:[0x4b74ec]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945132) /* 0x4b74ec */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00479e1d  3db7000000             +cmp eax, 0xb7
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(183 /*0xb7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00479e22  7536                   -jne 0x479e5a
    if (!cpu.flags.zf)
    {
        goto L_0x00479e5a;
    }
    // 00479e24  8b0d98a34c00           -mov ecx, dword ptr [0x4ca398]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5022616) /* 0x4ca398 */);
    // 00479e2a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00479e2b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00479e2d  2eff15dc734b00         -call dword ptr cs:[0x4b73dc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944860) /* 0x4b73dc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00479e34  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00479e36  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00479e38  7412                   -je 0x479e4c
    if (cpu.flags.zf)
    {
        goto L_0x00479e4c;
    }
    // 00479e3a  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 00479e3c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00479e3d  2eff1534744b00         -call dword ptr cs:[0x4b7434]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944948) /* 0x4b7434 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00479e44  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00479e45  2eff1524744b00         -call dword ptr cs:[0x4b7424]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944932) /* 0x4b7424 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00479e4c:
    // 00479e4c  833d74a64c0000         +cmp dword ptr [0x4ca674], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5023348) /* 0x4ca674 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00479e53  7415                   -je 0x479e6a
    if (cpu.flags.zf)
    {
        goto L_0x00479e6a;
    }
    // 00479e55  e887680100             -call 0x4906e1
    cpu.esp -= 4;
    sub_4906e1(app, cpu);
    if (cpu.terminate) return;
L_0x00479e5a:
    // 00479e5a  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00479e5c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479e5d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479e5e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479e5f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00479e60:
    // 00479e60  8b1dec845200           -mov ebx, dword ptr [0x5284ec]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5407980) /* 0x5284ec */);
    // 00479e66  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 00479e68  eb8c                   -jmp 0x479df6
    goto L_0x00479df6;
L_0x00479e6a:
    // 00479e6a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00479e6f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479e70  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479e71  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00479e72  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::crt_exit(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00479e80  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00479e81  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00479e82  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00479e83  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00479e84  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00479e85  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00479e86  81ec04030000           -sub esp, 0x304
    (cpu.esp) -= x86::reg32(x86::sreg32(772 /*0x304*/));
    // 00479e8c  8b1588a64c00           -mov edx, dword ptr [0x4ca688]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023368) /* 0x4ca688 */);
    // 00479e92  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00479e94  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00479e96  0f8582010000           -jne 0x47a01e
    if (!cpu.flags.zf)
    {
        goto L_0x0047a01e;
    }
    // 00479e9c  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00479ea1  8b9c2420030000         -mov ebx, dword ptr [esp + 0x320]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(800) /* 0x320 */);
    // 00479ea8  890d88a64c00           -mov dword ptr [0x4ca688], ecx
    app->getMemory<x86::reg32>(x86::reg32(5023368) /* 0x4ca688 */) = cpu.ecx;
    // 00479eae  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00479eb0  0f8575010000           -jne 0x47a02b
    if (!cpu.flags.zf)
    {
        goto L_0x0047a02b;
    }
    // 00479eb6  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 00479eb8  882424                 -mov byte ptr [esp], ah
    app->getMemory<x86::reg8>(cpu.esp) = cpu.ah;
L_0x00479ebb:
    // 00479ebb  833d54a44c0000         +cmp dword ptr [0x4ca454], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5022804) /* 0x4ca454 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00479ec2  0f8592010000           -jne 0x47a05a
    if (!cpu.flags.zf)
    {
        goto L_0x0047a05a;
    }
L_0x00479ec8:
    // 00479ec8  833d50a44c0000         +cmp dword ptr [0x4ca450], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5022800) /* 0x4ca450 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00479ecf  0f84a4000000           -je 0x479f79
    if (cpu.flags.zf)
    {
        goto L_0x00479f79;
    }
    // 00479ed5  8b1578a64c00           -mov edx, dword ptr [0x4ca678]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023352) /* 0x4ca678 */);
    // 00479edb  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00479edd  7448                   -je 0x479f27
    if (cpu.flags.zf)
    {
        goto L_0x00479f27;
    }
    // 00479edf  8b0d7ca64c00           -mov ecx, dword ptr [0x4ca67c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5023356) /* 0x4ca67c */);
    // 00479ee5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00479ee6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00479ee7  6800ff4b00             -push 0x4bff00
    app->getMemory<x86::reg32>(cpu.esp-4) = 4980480 /*0x4bff00*/;
    cpu.esp -= 4;
    // 00479eec  8d84240c020000         -lea eax, [esp + 0x20c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(524) /* 0x20c */);
    // 00479ef3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00479ef4  e8e8200000             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 00479ef9  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00479efc  8db42400020000         -lea esi, [esp + 0x200]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(512) /* 0x200 */);
    // 00479f03  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00479f05  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00479f06  2bc9                   +sub ecx, ecx
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
    // 00479f08  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00479f09  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 00479f0b  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00479f0d  4f                     -dec edi
    (cpu.edi)--;
L_0x00479f0e:
    // 00479f0e  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00479f10  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00479f12  3c00                   +cmp al, 0
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
    // 00479f14  7410                   -je 0x479f26
    if (cpu.flags.zf)
    {
        goto L_0x00479f26;
    }
    // 00479f16  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00479f19  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00479f1c  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00479f1f  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00479f22  3c00                   +cmp al, 0
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
    // 00479f24  75e8                   -jne 0x479f0e
    if (!cpu.flags.zf)
    {
        goto L_0x00479f0e;
    }
L_0x00479f26:
    // 00479f26  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00479f27:
    // 00479f27  8b3580a64c00           -mov esi, dword ptr [0x4ca680]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5023360) /* 0x4ca680 */);
    // 00479f2d  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00479f2f  7448                   -je 0x479f79
    if (cpu.flags.zf)
    {
        goto L_0x00479f79;
    }
    // 00479f31  8b3d84a64c00           -mov edi, dword ptr [0x4ca684]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5023364) /* 0x4ca684 */);
    // 00479f37  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00479f38  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00479f39  6814ff4b00             -push 0x4bff14
    app->getMemory<x86::reg32>(cpu.esp-4) = 4980500 /*0x4bff14*/;
    cpu.esp -= 4;
    // 00479f3e  8d84248c020000         -lea eax, [esp + 0x28c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(652) /* 0x28c */);
    // 00479f45  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00479f46  e896200000             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 00479f4b  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00479f4e  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00479f50  8db42480020000         -lea esi, [esp + 0x280]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(640) /* 0x280 */);
    // 00479f57  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00479f58  2bc9                   +sub ecx, ecx
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
    // 00479f5a  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00479f5b  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 00479f5d  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00479f5f  4f                     -dec edi
    (cpu.edi)--;
L_0x00479f60:
    // 00479f60  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00479f62  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00479f64  3c00                   +cmp al, 0
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
    // 00479f66  7410                   -je 0x479f78
    if (cpu.flags.zf)
    {
        goto L_0x00479f78;
    }
    // 00479f68  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00479f6b  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00479f6e  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00479f71  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00479f74  3c00                   +cmp al, 0
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
    // 00479f76  75e8                   -jne 0x479f60
    if (!cpu.flags.zf)
    {
        goto L_0x00479f60;
    }
L_0x00479f78:
    // 00479f78  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00479f79:
    // 00479f79  833d44a44c0000         +cmp dword ptr [0x4ca444], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5022788) /* 0x4ca444 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00479f80  7411                   -je 0x479f93
    if (cpu.flags.zf)
    {
        goto L_0x00479f93;
    }
    // 00479f82  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00479f84  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00479f85  2eff1550754b00         -call dword ptr cs:[0x4b7550]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945232) /* 0x4b7550 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00479f8c  2eff1568744b00         -call dword ptr cs:[0x4b7468]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945000) /* 0x4b7468 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00479f93:
    // 00479f93  833d58a44c0000         +cmp dword ptr [0x4ca458], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5022808) /* 0x4ca458 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00479f9a  7408                   -je 0x479fa4
    if (cpu.flags.zf)
    {
        goto L_0x00479fa4;
    }
    // 00479f9c  ff1558a44c00           -call dword ptr [0x4ca458]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5022808) /* 0x4ca458 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00479fa2  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
L_0x00479fa4:
    // 00479fa4  833d5ca44c0000         +cmp dword ptr [0x4ca45c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5022812) /* 0x4ca45c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00479fab  7406                   -je 0x479fb3
    if (cpu.flags.zf)
    {
        goto L_0x00479fb3;
    }
    // 00479fad  ff155ca44c00           -call dword ptr [0x4ca45c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5022812) /* 0x4ca45c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00479fb3:
    // 00479fb3  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00479fb5  2eff1530744b00         -call dword ptr cs:[0x4b7430]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944944) /* 0x4b7430 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00479fbc  6831100100             -push 0x11031
    app->getMemory<x86::reg32>(cpu.esp-4) = 69681 /*0x11031*/;
    cpu.esp -= 4;
    // 00479fc1  6834ff4b00             -push 0x4bff34
    app->getMemory<x86::reg32>(cpu.esp-4) = 4980532 /*0x4bff34*/;
    cpu.esp -= 4;
    // 00479fc6  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00479fca  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00479fcb  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00479fcd  2eff1500744b00         -call dword ptr cs:[0x4b7400]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944896) /* 0x4b7400 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00479fd4  83f801                 +cmp eax, 1
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
    // 00479fd7  7528                   -jne 0x47a001
    if (!cpu.flags.zf)
    {
        goto L_0x0047a001;
    }
    // 00479fd9  833d48a44c0000         +cmp dword ptr [0x4ca448], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5022792) /* 0x4ca448 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00479fe0  741f                   -je 0x47a001
    if (cpu.flags.zf)
    {
        goto L_0x0047a001;
    }
    // 00479fe2  833d4ca44c0000         +cmp dword ptr [0x4ca44c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5022796) /* 0x4ca44c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00479fe9  7416                   -je 0x47a001
    if (cpu.flags.zf)
    {
        goto L_0x0047a001;
    }
    // 00479feb  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00479fed  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00479fee  6844ff4b00             -push 0x4bff44
    app->getMemory<x86::reg32>(cpu.esp-4) = 4980548 /*0x4bff44*/;
    cpu.esp -= 4;
    // 00479ff3  e8a9da0100             -call 0x497aa1
    cpu.esp -= 4;
    sub_497aa1(app, cpu);
    if (cpu.terminate) return;
    // 00479ff8  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00479ffb  ff154ca44c00           -call dword ptr [0x4ca44c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5022796) /* 0x4ca44c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0047a001:
    // 0047a001  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0047a003  7407                   -je 0x47a00c
    if (cpu.flags.zf)
    {
        goto L_0x0047a00c;
    }
    // 0047a005  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0047a007  e8d46b0000             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
L_0x0047a00c:
    // 0047a00c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047a00e  e855680000             -call 0x480868
    cpu.esp -= 4;
    sub_480868(app, cpu);
    if (cpu.terminate) return;
    // 0047a013  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047a015  745a                   -je 0x47a071
    if (cpu.flags.zf)
    {
        goto L_0x0047a071;
    }
    // 0047a017  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047a019  e887640100             -call 0x4904a5
    cpu.esp -= 4;
    sub_4904a5(app, cpu);
    if (cpu.terminate) return;
L_0x0047a01e:
    // 0047a01e  81c404030000           +add esp, 0x304
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(772 /*0x304*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047a024  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a025  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a026  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a027  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a028  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a029  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a02a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047a02b:
    // 0047a02b  8d842424030000         -lea eax, [esp + 0x324]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(804) /* 0x324 */);
    // 0047a032  8d9c2400030000         -lea ebx, [esp + 0x300]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(768) /* 0x300 */);
    // 0047a039  8b942420030000         -mov edx, dword ptr [esp + 0x320]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(800) /* 0x320 */);
    // 0047a040  89842400030000         -mov dword ptr [esp + 0x300], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(768) /* 0x300 */) = cpu.eax;
    // 0047a047  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0047a049  e888da0100             -call 0x497ad6
    cpu.esp -= 4;
    sub_497ad6(app, cpu);
    if (cpu.terminate) return;
    // 0047a04e  89ac2400030000         -mov dword ptr [esp + 0x300], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(768) /* 0x300 */) = cpu.ebp;
    // 0047a055  e961feffff             -jmp 0x479ebb
    goto L_0x00479ebb;
L_0x0047a05a:
    // 0047a05a  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0047a05c  ff1554a44c00           -call dword ptr [0x4ca454]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5022804) /* 0x4ca454 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047a062  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047a064  0f855efeffff           -jne 0x479ec8
    if (!cpu.flags.zf)
    {
        goto L_0x00479ec8;
    }
    // 0047a06a  a388a64c00             -mov dword ptr [0x4ca688], eax
    app->getMemory<x86::reg32>(x86::reg32(5023368) /* 0x4ca688 */) = cpu.eax;
    // 0047a06f  ebad                   -jmp 0x47a01e
    goto L_0x0047a01e;
L_0x0047a071:
    // 0047a071  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047a072  2eff1580744b00         -call dword ptr cs:[0x4b7480]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945024) /* 0x4b7480 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047a079  81c404030000           -add esp, 0x304
    (cpu.esp) += x86::reg32(x86::sreg32(772 /*0x304*/));
    // 0047a07f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a080  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a081  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a082  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a083  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a084  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a085  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47a090(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047a090  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047a091  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047a092  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047a093  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047a095  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0047a097  e854da0100             -call 0x497af0
    cpu.esp -= 4;
    sub_497af0(app, cpu);
    if (cpu.terminate) return;
    // 0047a09c  a370d95100             -mov dword ptr [0x51d970], eax
    app->getMemory<x86::reg32>(x86::reg32(5364080) /* 0x51d970 */) = cpu.eax;
    // 0047a0a1  e86ada0100             -call 0x497b10
    cpu.esp -= 4;
    sub_497b10(app, cpu);
    if (cpu.terminate) return;
    // 0047a0a6  b8f0d75100             -mov eax, 0x51d7f0
    cpu.eax = 5363696 /*0x51d7f0*/;
    // 0047a0ab  891598a64c00           -mov dword ptr [0x4ca698], edx
    app->getMemory<x86::reg32>(x86::reg32(5023384) /* 0x4ca698 */) = cpu.edx;
    // 0047a0b1  ba80010000             -mov edx, 0x180
    cpu.edx = 384 /*0x180*/;
    // 0047a0b6  e8e16b0000             -call 0x480c9c
    cpu.esp -= 4;
    sub_480c9c(app, cpu);
    if (cpu.terminate) return;
    // 0047a0bb  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047a0bd  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0047a0bf  8d3c9500000000         -lea edi, [edx*4]
    cpu.edi = x86::reg32(cpu.edx * 4);
    // 0047a0c6  a198a64c00             -mov eax, dword ptr [0x4ca698]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023384) /* 0x4ca698 */);
    // 0047a0cb  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 0047a0cd  e8fe090000             -call 0x47aad0
    cpu.esp -= 4;
    sub_47aad0(app, cpu);
    if (cpu.terminate) return;
    // 0047a0d2  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047a0d4  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0047a0d6  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047a0d8  b848ff4b00             -mov eax, 0x4bff48
    cpu.eax = 4980552 /*0x4bff48*/;
    // 0047a0dd  8b1d98a64c00           -mov ebx, dword ptr [0x4ca698]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5023384) /* 0x4ca698 */);
    // 0047a0e3  6a20                   -push 0x20
    app->getMemory<x86::reg32>(cpu.esp-4) = 32 /*0x20*/;
    cpu.esp -= 4;
    // 0047a0e5  c1e703                 -shl edi, 3
    cpu.edi <<= 3 /*0x3*/ % 32;
    // 0047a0e8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047a0ea  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 0047a0ec  01fb                   -add ebx, edi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0047a0ee  893594a64c00           -mov dword ptr [0x4ca694], esi
    app->getMemory<x86::reg32>(x86::reg32(5023380) /* 0x4ca694 */) = cpu.esi;
    // 0047a0f4  e823000000             -call 0x47a11c
    cpu.esp -= 4;
    sub_47a11c(app, cpu);
    if (cpu.terminate) return;
    // 0047a0f9  a194a64c00             -mov eax, dword ptr [0x4ca694]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023380) /* 0x4ca694 */);
    // 0047a0fe  8b1598a64c00           -mov edx, dword ptr [0x4ca698]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023384) /* 0x4ca698 */);
    // 0047a104  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0047a106  a37cd95100             -mov dword ptr [0x51d97c], eax
    app->getMemory<x86::reg32>(x86::reg32(5364092) /* 0x51d97c */) = cpu.eax;
    // 0047a10b  a170d95100             -mov eax, dword ptr [0x51d970]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364080) /* 0x51d970 */);
    // 0047a110  e803da0100             -call 0x497b18
    cpu.esp -= 4;
    sub_497b18(app, cpu);
    if (cpu.terminate) return;
    // 0047a115  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a116  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a117  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a118  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47a11c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047a11c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047a11d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047a11e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047a11f  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0047a121  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0047a123  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 0047a125  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0047a127  81e1000f0000           -and ecx, 0xf00
    cpu.ecx &= x86::reg32(x86::sreg32(3840 /*0xf00*/));
    // 0047a12d  c1f908                 -sar ecx, 8
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (8 /*0x8*/ % 32));
    // 0047a130  8d148d00000000         -lea edx, [ecx*4]
    cpu.edx = x86::reg32(cpu.ecx * 4);
    // 0047a137  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047a139  b9f0d75100             -mov ecx, 0x51d7f0
    cpu.ecx = 5363696 /*0x51d7f0*/;
    // 0047a13e  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 0047a141  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0047a145  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0047a147  48                     -dec eax
    (cpu.eax)--;
    // 0047a148  894108                 -mov dword ptr [ecx + 8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0047a14b  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0047a14f  48                     -dec eax
    (cpu.eax)--;
    // 0047a150  89410c                 -mov dword ptr [ecx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0047a153  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0047a157  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0047a15b  894110                 -mov dword ptr [ecx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0047a15e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047a160  7405                   -je 0x47a167
    if (cpu.flags.zf)
    {
        goto L_0x0047a167;
    }
    // 0047a162  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
L_0x0047a167:
    // 0047a167  895114                 -mov dword ptr [ecx + 0x14], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 0047a16a  8b1574d95100           -mov edx, dword ptr [0x51d974]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5364084) /* 0x51d974 */);
    // 0047a170  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047a171  8b4220                 -mov eax, dword ptr [edx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 0047a174  6850ff4b00             -push 0x4bff50
    app->getMemory<x86::reg32>(cpu.esp-4) = 4980560 /*0x4bff50*/;
    cpu.esp -= 4;
    // 0047a179  a374d95100             -mov dword ptr [0x51d974], eax
    app->getMemory<x86::reg32>(x86::reg32(5364084) /* 0x51d974 */) = cpu.eax;
    // 0047a17e  8d4204                 -lea eax, [edx + 4]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0047a181  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047a182  e85a1e0000             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 0047a187  c7421400000000         -mov dword ptr [edx + 0x14], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 0047a18e  c7422400000000         -mov dword ptr [edx + 0x24], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 0047a195  8b4214                 -mov eax, dword ptr [edx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 0047a198  894210                 -mov dword ptr [edx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0047a19b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047a19d  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 0047a19f  80cc80                 -or ah, 0x80
    cpu.ah |= x86::reg8(x86::sreg8(128 /*0x80*/));
    // 0047a1a2  894218                 -mov dword ptr [edx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0047a1a5  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047a1a8  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 0047a1aa  8b1574d95100           -mov edx, dword ptr [0x51d974]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5364084) /* 0x51d974 */);
    // 0047a1b0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047a1b1  8b5a20                 -mov ebx, dword ptr [edx + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 0047a1b4  685cff4b00             -push 0x4bff5c
    app->getMemory<x86::reg32>(cpu.esp-4) = 4980572 /*0x4bff5c*/;
    cpu.esp -= 4;
    // 0047a1b9  891d74d95100           -mov dword ptr [0x51d974], ebx
    app->getMemory<x86::reg32>(x86::reg32(5364084) /* 0x51d974 */) = cpu.ebx;
    // 0047a1bf  8d5a04                 -lea ebx, [edx + 4]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0047a1c2  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047a1c3  e8191e0000             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 0047a1c8  c7421400000000         -mov dword ptr [edx + 0x14], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 0047a1cf  c7422000000000         -mov dword ptr [edx + 0x20], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 0047a1d6  6681ce2080             -or si, 0x8020
    cpu.si |= x86::reg16(x86::sreg16(32800 /*0x8020*/));
    // 0047a1db  892a                   -mov dword ptr [edx], ebp
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebp;
    // 0047a1dd  897218                 -mov dword ptr [edx + 0x18], esi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 0047a1e0  8b4214                 -mov eax, dword ptr [edx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 0047a1e3  894210                 -mov dword ptr [edx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0047a1e6  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0047a1e8  895104                 -mov dword ptr [ecx + 4], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0047a1eb  895020                 -mov dword ptr [eax + 0x20], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 0047a1ee  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047a1f1  8b19                   -mov ebx, dword ptr [ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0047a1f3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047a1f5  895a24                 -mov dword ptr [edx + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 0047a1f8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a1f9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a1fa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a1fb  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47a200(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047a200  c705aca64c0090604900   -mov dword ptr [0x4ca6ac], 0x496090
    app->getMemory<x86::reg32>(x86::reg32(5023404) /* 0x4ca6ac */) = 4808848 /*0x496090*/;
    // 0047a20a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_47a20c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047a20c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047a20d  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0047a212  e84d000000             -call 0x47a264
    cpu.esp -= 4;
    sub_47a264(app, cpu);
    if (cpu.terminate) return;
    // 0047a217  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a218  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47a21c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047a21c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047a21d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047a21f  e840000000             -call 0x47a264
    cpu.esp -= 4;
    sub_47a264(app, cpu);
    if (cpu.terminate) return;
    // 0047a224  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a225  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47a228(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047a228  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047a229  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0047a22e  e831000000             -call 0x47a264
    cpu.esp -= 4;
    sub_47a264(app, cpu);
    if (cpu.terminate) return;
    // 0047a233  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047a235  7502                   -jne 0x47a239
    if (!cpu.flags.zf)
    {
        goto L_0x0047a239;
    }
    // 0047a237  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a238  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047a239:
    // 0047a239  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0047a23b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a23c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47a240(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047a240  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047a241  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047a243  e81c000000             -call 0x47a264
    cpu.esp -= 4;
    sub_47a264(app, cpu);
    if (cpu.terminate) return;
    // 0047a248  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047a24a  7502                   -jne 0x47a24e
    if (!cpu.flags.zf)
    {
        goto L_0x0047a24e;
    }
    // 0047a24c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a24d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047a24e:
    // 0047a24e  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0047a250  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a251  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47a254(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047a254  e80b000000             -call 0x47a264
    cpu.esp -= 4;
    sub_47a264(app, cpu);
    if (cpu.terminate) return;
    // 0047a259  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047a25b  7503                   -jne 0x47a260
    if (!cpu.flags.zf)
    {
        goto L_0x0047a260;
    }
    // 0047a25d  c3                     -ret 
    cpu.esp += 4;
    return;
    // 0047a25e  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x0047a260:
    // 0047a260  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0047a262  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47a260(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0047a260;
    // 0047a254  e80b000000             -call 0x47a264
    cpu.esp -= 4;
    sub_47a264(app, cpu);
    if (cpu.terminate) return;
    // 0047a259  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047a25b  7503                   -jne 0x47a260
    if (!cpu.flags.zf)
    {
        goto L_0x0047a260;
    }
    // 0047a25d  c3                     -ret 
    cpu.esp += 4;
    return;
    // 0047a25e  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x0047a260:
L_entry_0x0047a260:
    // 0047a260  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0047a262  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_47a264(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047a264  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047a265  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047a266  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047a267  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047a269  8b3d70d95100           -mov edi, dword ptr [0x51d970]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5364080) /* 0x51d970 */);
    // 0047a26f  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0047a271  7407                   -je 0x47a27a
    if (cpu.flags.zf)
    {
        goto L_0x0047a27a;
    }
    // 0047a273  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0047a275  e896d80100             -call 0x497b10
    cpu.esp -= 4;
    sub_497b10(app, cpu);
    if (cpu.terminate) return;
L_0x0047a27a:
    // 0047a27a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047a27c  e81f000000             -call 0x47a2a0
    cpu.esp -= 4;
    sub_47a2a0(app, cpu);
    if (cpu.terminate) return;
    // 0047a281  8b2d70d95100           -mov ebp, dword ptr [0x51d970]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5364080) /* 0x51d970 */);
    // 0047a287  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047a289  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0047a28b  7506                   -jne 0x47a293
    if (!cpu.flags.zf)
    {
        goto L_0x0047a293;
    }
    // 0047a28d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047a28f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a290  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a291  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a292  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047a293:
    // 0047a293  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0047a295  e87ed80100             -call 0x497b18
    cpu.esp -= 4;
    sub_497b18(app, cpu);
    if (cpu.terminate) return;
    // 0047a29a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047a29c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a29d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a29e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a29f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47a2a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047a2a0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047a2a1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047a2a2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047a2a3  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0047a2a6  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0047a2aa  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0047a2ae  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0047a2b0  81e2000f0000           -and edx, 0xf00
    cpu.edx &= x86::reg32(x86::sreg32(3840 /*0xf00*/));
    // 0047a2b6  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 0047a2b9  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0047a2c0  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0047a2c2  b9f0d75100             -mov ecx, 0x51d7f0
    cpu.ecx = 5363696 /*0x51d7f0*/;
    // 0047a2c7  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0047a2ca  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047a2cc  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047a2d0  e84bd80100             -call 0x497b20
    cpu.esp -= 4;
    sub_497b20(app, cpu);
    if (cpu.terminate) return;
    // 0047a2d5  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0047a2d9  f6c340                 +test bl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 64 /*0x40*/));
    // 0047a2dc  0f850a010000           -jne 0x47a3ec
    if (!cpu.flags.zf)
    {
        goto L_0x0047a3ec;
    }
    // 0047a2e2  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0047a2e6  034114                 -add eax, dword ptr [ecx + 0x14]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */)));
    // 0047a2e9  8b5108                 -mov edx, dword ptr [ecx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0047a2ec  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047a2ee  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
L_0x0047a2f1:
    // 0047a2f1  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 0047a2f3  21c2                   -and edx, eax
    cpu.edx &= x86::reg32(x86::sreg32(cpu.eax));
    // 0047a2f5  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0047a2f8  8b39                   -mov edi, dword ptr [ecx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx);
    // 0047a2fa  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0047a2fc  0f84b6010000           -je 0x47a4b8
    if (cpu.flags.zf)
    {
        goto L_0x0047a4b8;
    }
    // 0047a302  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047a304  25000f0000             -and eax, 0xf00
    cpu.eax &= x86::reg32(x86::sreg32(3840 /*0xf00*/));
    // 0047a309  3d00030000             +cmp eax, 0x300
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(768 /*0x300*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047a30e  0f84ee000000           -je 0x47a402
    if (cpu.flags.zf)
    {
        goto L_0x0047a402;
    }
    // 0047a314  f6c320                 +test bl, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 32 /*0x20*/));
    // 0047a317  0f85d2010000           -jne 0x47a4ef
    if (!cpu.flags.zf)
    {
        goto L_0x0047a4ef;
    }
    // 0047a31d  833da4a64c0000         +cmp dword ptr [0x4ca6a4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5023396) /* 0x4ca6a4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047a324  0f8542010000           -jne 0x47a46c
    if (!cpu.flags.zf)
    {
        goto L_0x0047a46c;
    }
L_0x0047a32a:
    // 0047a32a  8b39                   -mov edi, dword ptr [ecx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx);
    // 0047a32c  8b7720                 -mov esi, dword ptr [edi + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */);
    // 0047a32f  8b3f                   -mov edi, dword ptr [edi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi);
    // 0047a331  f6c340                 +test bl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 64 /*0x40*/));
    // 0047a334  0f854a010000           -jne 0x47a484
    if (!cpu.flags.zf)
    {
        goto L_0x0047a484;
    }
L_0x0047a33a:
    // 0047a33a  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0047a33c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047a33e  39c7                   +cmp edi, eax
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
L_0x0047a340:
    // 0047a340  0f824f010000           -jb 0x47a495
    if (cpu.flags.cf)
    {
        goto L_0x0047a495;
    }
    // 0047a346  8b3e                   -mov edi, dword ptr [esi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi);
    // 0047a348  037e10                 -add edi, dword ptr [esi + 0x10]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */)));
    // 0047a34b  f6c340                 +test bl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 64 /*0x40*/));
    // 0047a34e  740c                   -je 0x47a35c
    if (cpu.flags.zf)
    {
        goto L_0x0047a35c;
    }
    // 0047a350  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0047a353  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 0047a355  8b790c                 -mov edi, dword ptr [ecx + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0047a358  f7d7                   -not edi
    cpu.edi = ~cpu.edi;
    // 0047a35a  21c7                   -and edi, eax
    cpu.edi &= x86::reg32(x86::sreg32(cpu.eax));
L_0x0047a35c:
    // 0047a35c  3b7104                 +cmp esi, dword ptr [ecx + 4]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047a35f  0f8539010000           -jne 0x47a49e
    if (!cpu.flags.zf)
    {
        goto L_0x0047a49e;
    }
L_0x0047a365:
    // 0047a365  3b1424                 +cmp edx, dword ptr [esp]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047a368  0f8c3a010000           -jl 0x47a4a8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047a4a8;
    }
    // 0047a36e  8b2d74d95100           -mov ebp, dword ptr [0x51d974]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5364084) /* 0x51d974 */);
    // 0047a374  8b15a0a64c00           -mov edx, dword ptr [0x4ca6a0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023392) /* 0x4ca6a0 */);
    // 0047a37a  895d18                 -mov dword ptr [ebp + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 0047a37d  896c2408               -mov dword ptr [esp + 8], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebp;
    // 0047a381  8b4520                 -mov eax, dword ptr [ebp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 0047a384  89551c                 -mov dword ptr [ebp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 0047a387  bb0c000000             -mov ebx, 0xc
    cpu.ebx = 12 /*0xc*/;
    // 0047a38c  a374d95100             -mov dword ptr [0x51d974], eax
    app->getMemory<x86::reg32>(x86::reg32(5364084) /* 0x51d974 */) = cpu.eax;
    // 0047a391  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0047a395  42                     -inc edx
    (cpu.edx)++;
    // 0047a396  894514                 -mov dword ptr [ebp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0047a399  8915a0a64c00           -mov dword ptr [0x4ca6a0], edx
    app->getMemory<x86::reg32>(x86::reg32(5023392) /* 0x4ca6a0 */) = cpu.edx;
    // 0047a39f  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0047a3a2  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047a3a6  894510                 -mov dword ptr [ebp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0047a3a9  8d4504                 -lea eax, [ebp + 4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0047a3ac  e80b1c0000             -call 0x47bfbc
    cpu.esp -= 4;
    sub_47bfbc(app, cpu);
    if (cpu.terminate) return;
    // 0047a3b1  897d00                 -mov dword ptr [ebp], edi
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.edi;
    // 0047a3b4  8b4624                 -mov eax, dword ptr [esi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 0047a3b7  894524                 -mov dword ptr [ebp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0047a3ba  897520                 -mov dword ptr [ebp + 0x20], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 0047a3bd  8b4624                 -mov eax, dword ptr [esi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 0047a3c0  896820                 -mov dword ptr [eax + 0x20], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ebp;
    // 0047a3c3  896e24                 -mov dword ptr [esi + 0x24], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.ebp;
    // 0047a3c6  83791400               +cmp dword ptr [ecx + 0x14], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047a3ca  7407                   -je 0x47a3d3
    if (cpu.flags.zf)
    {
        goto L_0x0047a3d3;
    }
    // 0047a3cc  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0047a3ce  e88dd70100             -call 0x497b60
    cpu.esp -= 4;
    sub_497b60(app, cpu);
    if (cpu.terminate) return;
L_0x0047a3d3:
    // 0047a3d3  833da4a64c0000         +cmp dword ptr [0x4ca6a4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5023396) /* 0x4ca6a4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047a3da  7405                   -je 0x47a3e1
    if (cpu.flags.zf)
    {
        goto L_0x0047a3e1;
    }
    // 0047a3dc  e8c3040000             -call 0x47a8a4
    cpu.esp -= 4;
    sub_47a8a4(app, cpu);
    if (cpu.terminate) return;
L_0x0047a3e1:
    // 0047a3e1  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
L_0x0047a3e5:
    // 0047a3e5  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0047a3e8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a3e9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a3ea  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a3eb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047a3ec:
    // 0047a3ec  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0047a3f0  8b7114                 -mov esi, dword ptr [ecx + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 0047a3f3  8b510c                 -mov edx, dword ptr [ecx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0047a3f6  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0047a3f8  01c2                   +add edx, eax
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
    // 0047a3fa  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0047a3fd  e9effeffff             -jmp 0x47a2f1
    goto L_0x0047a2f1;
L_0x0047a402:
    // 0047a402  8b0d74d95100           -mov ecx, dword ptr [0x51d974]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5364084) /* 0x51d974 */);
    // 0047a408  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 0047a40b  a374d95100             -mov dword ptr [0x51d974], eax
    app->getMemory<x86::reg32>(x86::reg32(5364084) /* 0x51d974 */) = cpu.eax;
    // 0047a410  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0047a412  8b7720                 -mov esi, dword ptr [edi + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */);
    // 0047a415  e82ab10100             -call 0x495544
    cpu.esp -= 4;
    sub_495544(app, cpu);
    if (cpu.terminate) return;
    // 0047a41a  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 0047a41c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047a41e  74c5                   -je 0x47a3e5
    if (cpu.flags.zf)
    {
        goto L_0x0047a3e5;
    }
    // 0047a420  8b15a0a64c00           -mov edx, dword ptr [0x4ca6a0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023392) /* 0x4ca6a0 */);
    // 0047a426  895918                 -mov dword ptr [ecx + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 0047a429  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0047a42d  89511c                 -mov dword ptr [ecx + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 0047a430  bb0c000000             -mov ebx, 0xc
    cpu.ebx = 12 /*0xc*/;
    // 0047a435  894114                 -mov dword ptr [ecx + 0x14], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0047a438  42                     -inc edx
    (cpu.edx)++;
    // 0047a439  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0047a43c  8915a0a64c00           -mov dword ptr [0x4ca6a0], edx
    app->getMemory<x86::reg32>(x86::reg32(5023392) /* 0x4ca6a0 */) = cpu.edx;
    // 0047a442  894110                 -mov dword ptr [ecx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0047a445  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047a449  8d4104                 -lea eax, [ecx + 4]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0047a44c  e86b1b0000             -call 0x47bfbc
    cpu.esp -= 4;
    sub_47bfbc(app, cpu);
    if (cpu.terminate) return;
    // 0047a451  8b4624                 -mov eax, dword ptr [esi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 0047a454  894124                 -mov dword ptr [ecx + 0x24], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0047a457  897120                 -mov dword ptr [ecx + 0x20], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 0047a45a  8b4624                 -mov eax, dword ptr [esi + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 0047a45d  894820                 -mov dword ptr [eax + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 0047a460  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047a462  894e24                 -mov dword ptr [esi + 0x24], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = cpu.ecx;
    // 0047a465  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0047a468  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a469  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a46a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a46b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047a46c:
    // 0047a46c  f6c310                 +test bl, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 16 /*0x10*/));
    // 0047a46f  0f85b5feffff           -jne 0x47a32a
    if (!cpu.flags.zf)
    {
        goto L_0x0047a32a;
    }
    // 0047a475  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0047a477  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0047a47a  e819d80100             -call 0x497c98
    cpu.esp -= 4;
    sub_497c98(app, cpu);
    if (cpu.terminate) return;
    // 0047a47f  e9a6feffff             -jmp 0x47a32a
    goto L_0x0047a32a;
L_0x0047a484:
    // 0047a484  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0047a487  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 0047a489  8b790c                 -mov edi, dword ptr [ecx + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0047a48c  f7d7                   -not edi
    cpu.edi = ~cpu.edi;
    // 0047a48e  21c7                   +and edi, eax
    cpu.clear_co();
    cpu.set_szp((cpu.edi &= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047a490  e9a5feffff             -jmp 0x47a33a
    goto L_0x0047a33a;
L_0x0047a495:
    // 0047a495  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 0047a497  29fa                   +sub edx, edi
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047a499  e9c7feffff             -jmp 0x47a365
    goto L_0x0047a365;
L_0x0047a49e:
    // 0047a49e  8b7620                 -mov esi, dword ptr [esi + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 0047a4a1  3b3e                   +cmp edi, dword ptr [esi]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047a4a3  e998feffff             -jmp 0x47a340
    goto L_0x0047a340;
L_0x0047a4a8:
    // 0047a4a8  3b7104                 +cmp esi, dword ptr [ecx + 4]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047a4ab  7514                   -jne 0x47a4c1
    if (!cpu.flags.zf)
    {
        goto L_0x0047a4c1;
    }
    // 0047a4ad  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047a4af  e8a4da0100             -call 0x497f58
    cpu.esp -= 4;
    sub_497f58(app, cpu);
    if (cpu.terminate) return;
    // 0047a4b4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047a4b6  7528                   -jne 0x47a4e0
    if (!cpu.flags.zf)
    {
        goto L_0x0047a4e0;
    }
L_0x0047a4b8:
    // 0047a4b8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047a4ba  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0047a4bd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a4be  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a4bf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a4c0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047a4c1:
    // 0047a4c1  8b3e                   -mov edi, dword ptr [esi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi);
    // 0047a4c3  037e10                 -add edi, dword ptr [esi + 0x10]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */)));
    // 0047a4c6  f6c340                 +test bl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 64 /*0x40*/));
    // 0047a4c9  7508                   -jne 0x47a4d3
    if (!cpu.flags.zf)
    {
        goto L_0x0047a4d3;
    }
L_0x0047a4cb:
    // 0047a4cb  8b7620                 -mov esi, dword ptr [esi + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 0047a4ce  e967feffff             -jmp 0x47a33a
    goto L_0x0047a33a;
L_0x0047a4d3:
    // 0047a4d3  8b510c                 -mov edx, dword ptr [ecx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0047a4d6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047a4d8  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 0047a4da  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 0047a4dc  21c7                   +and edi, eax
    cpu.clear_co();
    cpu.set_szp((cpu.edi &= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047a4de  ebeb                   -jmp 0x47a4cb
    goto L_0x0047a4cb;
L_0x0047a4e0:
    // 0047a4e0  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0047a4e2  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0047a4e5  e8aed70100             -call 0x497c98
    cpu.esp -= 4;
    sub_497c98(app, cpu);
    if (cpu.terminate) return;
    // 0047a4ea  e93bfeffff             -jmp 0x47a32a
    goto L_0x0047a32a;
L_0x0047a4ef:
    // 0047a4ef  833da4a64c0000         +cmp dword ptr [0x4ca6a4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5023396) /* 0x4ca6a4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047a4f6  0f85c8000000           -jne 0x47a5c4
    if (!cpu.flags.zf)
    {
        goto L_0x0047a5c4;
    }
L_0x0047a4fc:
    // 0047a4fc  8b7904                 -mov edi, dword ptr [ecx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0047a4ff  8b7724                 -mov esi, dword ptr [edi + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */);
    // 0047a502  8b3f                   -mov edi, dword ptr [edi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi);
    // 0047a504  f6c340                 +test bl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 64 /*0x40*/));
    // 0047a507  0f85cf000000           -jne 0x47a5dc
    if (!cpu.flags.zf)
    {
        goto L_0x0047a5dc;
    }
L_0x0047a50d:
    // 0047a50d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047a50f  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
L_0x0047a513:
    // 0047a513  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0047a515  034610                 -add eax, dword ptr [esi + 0x10]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */)));
    // 0047a518  f6c340                 +test bl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 64 /*0x40*/));
    // 0047a51b  740c                   -je 0x47a529
    if (cpu.flags.zf)
    {
        goto L_0x0047a529;
    }
    // 0047a51d  8b510c                 -mov edx, dword ptr [ecx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0047a520  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047a522  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0047a525  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 0047a527  21d0                   -and eax, edx
    cpu.eax &= x86::reg32(x86::sreg32(cpu.edx));
L_0x0047a529:
    // 0047a529  39f8                   +cmp eax, edi
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
    // 0047a52b  0f83b7000000           -jae 0x47a5e8
    if (!cpu.flags.cf)
    {
        goto L_0x0047a5e8;
    }
    // 0047a531  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0047a533  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0047a535  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
L_0x0047a539:
    // 0047a539  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0047a53d  3b0424                 +cmp eax, dword ptr [esp]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047a540  0f8cc0000000           -jl 0x47a606
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047a606;
    }
    // 0047a546  8b2d74d95100           -mov ebp, dword ptr [0x51d974]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5364084) /* 0x51d974 */);
    // 0047a54c  8b15a0a64c00           -mov edx, dword ptr [0x4ca6a0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023392) /* 0x4ca6a0 */);
    // 0047a552  895d18                 -mov dword ptr [ebp + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 0047a555  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 0047a559  8b4520                 -mov eax, dword ptr [ebp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 0047a55c  89551c                 -mov dword ptr [ebp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 0047a55f  bb0c000000             -mov ebx, 0xc
    cpu.ebx = 12 /*0xc*/;
    // 0047a564  a374d95100             -mov dword ptr [0x51d974], eax
    app->getMemory<x86::reg32>(x86::reg32(5364084) /* 0x51d974 */) = cpu.eax;
    // 0047a569  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0047a56d  42                     -inc edx
    (cpu.edx)++;
    // 0047a56e  894514                 -mov dword ptr [ebp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0047a571  8915a0a64c00           -mov dword ptr [0x4ca6a0], edx
    app->getMemory<x86::reg32>(x86::reg32(5023392) /* 0x4ca6a0 */) = cpu.edx;
    // 0047a577  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0047a57a  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047a57e  894510                 -mov dword ptr [ebp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0047a581  8d4504                 -lea eax, [ebp + 4]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0047a584  e8331a0000             -call 0x47bfbc
    cpu.esp -= 4;
    sub_47bfbc(app, cpu);
    if (cpu.terminate) return;
    // 0047a589  2b3c24                 -sub edi, dword ptr [esp]
    (cpu.edi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
    // 0047a58c  897524                 -mov dword ptr [ebp + 0x24], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */) = cpu.esi;
    // 0047a58f  897d00                 -mov dword ptr [ebp], edi
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.edi;
    // 0047a592  8b4620                 -mov eax, dword ptr [esi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 0047a595  894520                 -mov dword ptr [ebp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0047a598  896824                 -mov dword ptr [eax + 0x24], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = cpu.ebp;
    // 0047a59b  896e20                 -mov dword ptr [esi + 0x20], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = cpu.ebp;
    // 0047a59e  83791400               +cmp dword ptr [ecx + 0x14], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047a5a2  7407                   -je 0x47a5ab
    if (cpu.flags.zf)
    {
        goto L_0x0047a5ab;
    }
    // 0047a5a4  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0047a5a6  e8b5d50100             -call 0x497b60
    cpu.esp -= 4;
    sub_497b60(app, cpu);
    if (cpu.terminate) return;
L_0x0047a5ab:
    // 0047a5ab  833da4a64c0000         +cmp dword ptr [0x4ca6a4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5023396) /* 0x4ca6a4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047a5b2  7405                   -je 0x47a5b9
    if (cpu.flags.zf)
    {
        goto L_0x0047a5b9;
    }
    // 0047a5b4  e8eb020000             -call 0x47a8a4
    cpu.esp -= 4;
    sub_47a8a4(app, cpu);
    if (cpu.terminate) return;
L_0x0047a5b9:
    // 0047a5b9  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047a5bd  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0047a5c0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a5c1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a5c2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a5c3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047a5c4:
    // 0047a5c4  f6c310                 +test bl, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 16 /*0x10*/));
    // 0047a5c7  0f852fffffff           -jne 0x47a4fc
    if (!cpu.flags.zf)
    {
        goto L_0x0047a4fc;
    }
    // 0047a5cd  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0047a5cf  8b5104                 -mov edx, dword ptr [ecx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0047a5d2  e8d1d70100             -call 0x497da8
    cpu.esp -= 4;
    sub_497da8(app, cpu);
    if (cpu.terminate) return;
    // 0047a5d7  e920ffffff             -jmp 0x47a4fc
    goto L_0x0047a4fc;
L_0x0047a5dc:
    // 0047a5dc  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0047a5df  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 0047a5e1  21c7                   +and edi, eax
    cpu.clear_co();
    cpu.set_szp((cpu.edi &= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047a5e3  e925ffffff             -jmp 0x47a50d
    goto L_0x0047a50d;
L_0x0047a5e8:
    // 0047a5e8  8b3e                   -mov edi, dword ptr [esi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi);
    // 0047a5ea  f6c340                 +test bl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 64 /*0x40*/));
    // 0047a5ed  7407                   -je 0x47a5f6
    if (cpu.flags.zf)
    {
        goto L_0x0047a5f6;
    }
    // 0047a5ef  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0047a5f2  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 0047a5f4  21c7                   -and edi, eax
    cpu.edi &= x86::reg32(x86::sreg32(cpu.eax));
L_0x0047a5f6:
    // 0047a5f6  3b31                   +cmp esi, dword ptr [ecx]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047a5f8  0f843bffffff           -je 0x47a539
    if (cpu.flags.zf)
    {
        goto L_0x0047a539;
    }
    // 0047a5fe  8b7624                 -mov esi, dword ptr [esi + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 0047a601  e90dffffff             -jmp 0x47a513
    goto L_0x0047a513;
L_0x0047a606:
    // 0047a606  3b31                   +cmp esi, dword ptr [ecx]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047a608  7418                   -je 0x47a622
    if (cpu.flags.zf)
    {
        goto L_0x0047a622;
    }
    // 0047a60a  8b3e                   -mov edi, dword ptr [esi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi);
    // 0047a60c  f6c340                 +test bl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 64 /*0x40*/));
    // 0047a60f  7508                   -jne 0x47a619
    if (!cpu.flags.zf)
    {
        goto L_0x0047a619;
    }
L_0x0047a611:
    // 0047a611  8b7624                 -mov esi, dword ptr [esi + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */);
    // 0047a614  e9f4feffff             -jmp 0x47a50d
    goto L_0x0047a50d;
L_0x0047a619:
    // 0047a619  8b410c                 -mov eax, dword ptr [ecx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0047a61c  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 0047a61e  21c7                   +and edi, eax
    cpu.clear_co();
    cpu.set_szp((cpu.edi &= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047a620  ebef                   -jmp 0x47a611
    goto L_0x0047a611;
L_0x0047a622:
    // 0047a622  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047a624  e82fd90100             -call 0x497f58
    cpu.esp -= 4;
    sub_497f58(app, cpu);
    if (cpu.terminate) return;
    // 0047a629  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047a62b  0f8487feffff           -je 0x47a4b8
    if (cpu.flags.zf)
    {
        goto L_0x0047a4b8;
    }
    // 0047a631  8b5104                 -mov edx, dword ptr [ecx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0047a634  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0047a636  e86dd70100             -call 0x497da8
    cpu.esp -= 4;
    sub_497da8(app, cpu);
    if (cpu.terminate) return;
    // 0047a63b  e9bcfeffff             -jmp 0x47a4fc
    goto L_0x0047a4fc;
}

/* align: skip  */
void Application::sub_47a640(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047a640  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047a641  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047a642  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047a644  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047a646  742e                   -je 0x47a676
    if (cpu.flags.zf)
    {
        goto L_0x0047a676;
    }
    // 0047a648  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0047a64a:
    // 0047a64a  8b93f4d75100           -mov edx, dword ptr [ebx + 0x51d7f4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5363700) /* 0x51d7f4 */);
    // 0047a650  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047a652  7417                   -je 0x47a66b
    if (cpu.flags.zf)
    {
        goto L_0x0047a66b;
    }
    // 0047a654  8b83f0d75100           -mov eax, dword ptr [ebx + 0x51d7f0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5363696) /* 0x51d7f0 */);
L_0x0047a65a:
    // 0047a65a  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0047a65d  3b08                   +cmp ecx, dword ptr [eax]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047a65f  7404                   -je 0x47a665
    if (cpu.flags.zf)
    {
        goto L_0x0047a665;
    }
    // 0047a661  39d0                   +cmp eax, edx
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
    // 0047a663  75f5                   -jne 0x47a65a
    if (!cpu.flags.zf)
    {
        goto L_0x0047a65a;
    }
L_0x0047a665:
    // 0047a665  f6401980               +test byte ptr [eax + 0x19], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(25) /* 0x19 */) & 128 /*0x80*/));
    // 0047a669  740d                   -je 0x47a678
    if (cpu.flags.zf)
    {
        goto L_0x0047a678;
    }
L_0x0047a66b:
    // 0047a66b  83c318                 -add ebx, 0x18
    (cpu.ebx) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0047a66e  81fb80010000           +cmp ebx, 0x180
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(384 /*0x180*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047a674  7cd4                   -jl 0x47a64a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047a64a;
    }
L_0x0047a676:
    // 0047a676  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0047a678:
    // 0047a678  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a679  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a67a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_47a67c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047a67c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047a67d  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0047a682  e8b9ffffff             -call 0x47a640
    cpu.esp -= 4;
    sub_47a640(app, cpu);
    if (cpu.terminate) return;
    // 0047a687  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a688  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47a68c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047a68c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047a68d  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0047a692  e8a9ffffff             -call 0x47a640
    cpu.esp -= 4;
    sub_47a640(app, cpu);
    if (cpu.terminate) return;
    // 0047a697  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047a699  a170d95100             -mov eax, dword ptr [0x51d970]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364080) /* 0x51d970 */);
    // 0047a69e  e86dd40100             -call 0x497b10
    cpu.esp -= 4;
    sub_497b10(app, cpu);
    if (cpu.terminate) return;
    // 0047a6a3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047a6a5  e82e000000             -call 0x47a6d8
    cpu.esp -= 4;
    sub_47a6d8(app, cpu);
    if (cpu.terminate) return;
    // 0047a6aa  a170d95100             -mov eax, dword ptr [0x51d970]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364080) /* 0x51d970 */);
    // 0047a6af  e864d40100             -call 0x497b18
    cpu.esp -= 4;
    sub_497b18(app, cpu);
    if (cpu.terminate) return;
    // 0047a6b4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a6b5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47a6b8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047a6b8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047a6b9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047a6bb  a170d95100             -mov eax, dword ptr [0x51d970]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364080) /* 0x51d970 */);
    // 0047a6c0  e84bd40100             -call 0x497b10
    cpu.esp -= 4;
    sub_497b10(app, cpu);
    if (cpu.terminate) return;
    // 0047a6c5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047a6c7  e80c000000             -call 0x47a6d8
    cpu.esp -= 4;
    sub_47a6d8(app, cpu);
    if (cpu.terminate) return;
    // 0047a6cc  a170d95100             -mov eax, dword ptr [0x51d970]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364080) /* 0x51d970 */);
    // 0047a6d1  e842d40100             -call 0x497b18
    cpu.esp -= 4;
    sub_497b18(app, cpu);
    if (cpu.terminate) return;
    // 0047a6d6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a6d7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47a6d8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047a6d8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047a6d9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047a6db  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047a6dd  743a                   -je 0x47a719
    if (cpu.flags.zf)
    {
        goto L_0x0047a719;
    }
    // 0047a6df  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047a6e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047a6e1  8b5824                 -mov ebx, dword ptr [eax + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 0047a6e4  8b4820                 -mov ecx, dword ptr [eax + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0047a6e7  894b20                 -mov dword ptr [ebx + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 0047a6ea  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0047a6ec  8b4824                 -mov ecx, dword ptr [eax + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 0047a6ef  894b24                 -mov dword ptr [ebx + 0x24], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */) = cpu.ecx;
    // 0047a6f2  8b4818                 -mov ecx, dword ptr [eax + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0047a6f5  81e1000f0000           -and ecx, 0xf00
    cpu.ecx &= x86::reg32(x86::sreg32(3840 /*0xf00*/));
    // 0047a6fb  81f900030000           +cmp ecx, 0x300
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(768 /*0x300*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047a701  7418                   -je 0x47a71b
    if (cpu.flags.zf)
    {
        goto L_0x0047a71b;
    }
L_0x0047a703:
    // 0047a703  a174d95100             -mov eax, dword ptr [0x51d974]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364084) /* 0x51d974 */);
    // 0047a708  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 0047a70e  891574d95100           -mov dword ptr [0x51d974], edx
    app->getMemory<x86::reg32>(x86::reg32(5364084) /* 0x51d974 */) = cpu.edx;
    // 0047a714  894220                 -mov dword ptr [edx + 0x20], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0047a717  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a718  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047a719:
    // 0047a719  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a71a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047a71b:
    // 0047a71b  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0047a71d  e886ae0100             -call 0x4955a8
    cpu.esp -= 4;
    sub_4955a8(app, cpu);
    if (cpu.terminate) return;
    // 0047a722  ebdf                   -jmp 0x47a703
    goto L_0x0047a703;
}

/* align: skip  */
void Application::sub_47a724(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047a724  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047a725  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0047a72a  e811ffffff             -call 0x47a640
    cpu.esp -= 4;
    sub_47a640(app, cpu);
    if (cpu.terminate) return;
    // 0047a72f  e804000000             -call 0x47a738
    cpu.esp -= 4;
    sub_47a738(app, cpu);
    if (cpu.terminate) return;
    // 0047a734  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a735  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47a738(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047a738  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047a739  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047a73b  a170d95100             -mov eax, dword ptr [0x51d970]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364080) /* 0x51d970 */);
    // 0047a740  e8cbd30100             -call 0x497b10
    cpu.esp -= 4;
    sub_497b10(app, cpu);
    if (cpu.terminate) return;
    // 0047a745  8b5220                 -mov edx, dword ptr [edx + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 0047a748  f6421820               +test byte ptr [edx + 0x18], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(24) /* 0x18 */) & 32 /*0x20*/));
    // 0047a74c  7512                   -jne 0x47a760
    if (!cpu.flags.zf)
    {
        goto L_0x0047a760;
    }
L_0x0047a74e:
    // 0047a74e  8b5220                 -mov edx, dword ptr [edx + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 0047a751  8b4224                 -mov eax, dword ptr [edx + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */);
    // 0047a754  e87fffffff             -call 0x47a6d8
    cpu.esp -= 4;
    sub_47a6d8(app, cpu);
    if (cpu.terminate) return;
    // 0047a759  f6421820               +test byte ptr [edx + 0x18], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(24) /* 0x18 */) & 32 /*0x20*/));
    // 0047a75d  74ef                   -je 0x47a74e
    if (cpu.flags.zf)
    {
        goto L_0x0047a74e;
    }
    // 0047a75f  90                     -nop 
    ;
L_0x0047a760:
    // 0047a760  a170d95100             -mov eax, dword ptr [0x51d970]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364080) /* 0x51d970 */);
    // 0047a765  e8aed30100             -call 0x497b18
    cpu.esp -= 4;
    sub_497b18(app, cpu);
    if (cpu.terminate) return;
    // 0047a76a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a76b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47a76c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047a76c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047a76d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047a76f  a170d95100             -mov eax, dword ptr [0x51d970]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364080) /* 0x51d970 */);
    // 0047a774  e897d30100             -call 0x497b10
    cpu.esp -= 4;
    sub_497b10(app, cpu);
    if (cpu.terminate) return;
    // 0047a779  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047a77b  e810000000             -call 0x47a790
    cpu.esp -= 4;
    sub_47a790(app, cpu);
    if (cpu.terminate) return;
    // 0047a780  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047a782  a170d95100             -mov eax, dword ptr [0x51d970]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364080) /* 0x51d970 */);
    // 0047a787  e88cd30100             -call 0x497b18
    cpu.esp -= 4;
    sub_497b18(app, cpu);
    if (cpu.terminate) return;
    // 0047a78c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047a78e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a78f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47a790(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047a790  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047a791  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047a792  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047a793  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047a794  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047a795  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047a796  8b35a0a64c00           -mov esi, dword ptr [0x4ca6a0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5023392) /* 0x4ca6a0 */);
    // 0047a79c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047a79e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047a7a0  81e2000f0000           -and edx, 0xf00
    cpu.edx &= x86::reg32(x86::sreg32(3840 /*0xf00*/));
    // 0047a7a6  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 0047a7a9  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0047a7b0  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0047a7b2  bdf0d75100             -mov ebp, 0x51d7f0
    cpu.ebp = 5363696 /*0x51d7f0*/;
    // 0047a7b7  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0047a7ba  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047a7bc  83e107                 -and ecx, 7
    cpu.ecx &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 0047a7bf  8b4500                 -mov eax, dword ptr [ebp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp);
    // 0047a7c2  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0047a7c4  8b5504                 -mov edx, dword ptr [ebp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0047a7c7  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0047a7ca  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047a7cc  39d0                   +cmp eax, edx
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
    // 0047a7ce  7429                   -je 0x47a7f9
    if (cpu.flags.zf)
    {
        goto L_0x0047a7f9;
    }
L_0x0047a7d0:
    // 0047a7d0  f6401808               +test byte ptr [eax + 0x18], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(24) /* 0x18 */) & 8 /*0x8*/));
    // 0047a7d4  741b                   -je 0x47a7f1
    if (cpu.flags.zf)
    {
        goto L_0x0047a7f1;
    }
    // 0047a7d6  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0047a7d9  83e207                 -and edx, 7
    cpu.edx &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 0047a7dc  39ca                   +cmp edx, ecx
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
    // 0047a7de  7632                   -jbe 0x47a812
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0047a812;
    }
L_0x0047a7e0:
    // 0047a7e0  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0047a7e2  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0047a7e4  8b581c                 -mov ebx, dword ptr [eax + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0047a7e7  8b4818                 -mov ecx, dword ptr [eax + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0047a7ea  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047a7ec  83e107                 -and ecx, 7
    cpu.ecx &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 0047a7ef  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
L_0x0047a7f1:
    // 0047a7f1  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0047a7f4  3b4504                 +cmp eax, dword ptr [ebp + 4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047a7f7  75d7                   -jne 0x47a7d0
    if (!cpu.flags.zf)
    {
        goto L_0x0047a7d0;
    }
L_0x0047a7f9:
    // 0047a7f9  8935a0a64c00           -mov dword ptr [0x4ca6a0], esi
    app->getMemory<x86::reg32>(x86::reg32(5023392) /* 0x4ca6a0 */) = cpu.esi;
    // 0047a7ff  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0047a801  751c                   -jne 0x47a81f
    if (!cpu.flags.zf)
    {
        goto L_0x0047a81f;
    }
    // 0047a803  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047a805  8b35a0a64c00           -mov esi, dword ptr [0x4ca6a0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5023392) /* 0x4ca6a0 */);
    // 0047a80b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a80c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a80d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a80e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a80f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a810  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a811  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047a812:
    // 0047a812  75dd                   -jne 0x47a7f1
    if (!cpu.flags.zf)
    {
        goto L_0x0047a7f1;
    }
    // 0047a814  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0047a816  2b501c                 -sub edx, dword ptr [eax + 0x1c]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */)));
    // 0047a819  39da                   +cmp edx, ebx
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
    // 0047a81b  73c3                   -jae 0x47a7e0
    if (!cpu.flags.cf)
    {
        goto L_0x0047a7e0;
    }
    // 0047a81d  ebd2                   -jmp 0x47a7f1
    goto L_0x0047a7f1;
L_0x0047a81f:
    // 0047a81f  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0047a821  e8b2feffff             -call 0x47a6d8
    cpu.esp -= 4;
    sub_47a6d8(app, cpu);
    if (cpu.terminate) return;
    // 0047a826  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047a82b  8b35a0a64c00           -mov esi, dword ptr [0x4ca6a0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5023392) /* 0x4ca6a0 */);
    // 0047a831  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a832  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a833  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a834  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a835  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a836  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a837  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47a838(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047a838  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047a839  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047a83a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047a83b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047a83c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047a83e  81e2000f0000           -and edx, 0xf00
    cpu.edx &= x86::reg32(x86::sreg32(3840 /*0xf00*/));
    // 0047a844  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 0047a847  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0047a84e  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0047a850  bff0d75100             -mov edi, 0x51d7f0
    cpu.edi = 5363696 /*0x51d7f0*/;
    // 0047a855  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0047a858  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047a85a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047a85c  e8bfd20100             -call 0x497b20
    cpu.esp -= 4;
    sub_497b20(app, cpu);
    if (cpu.terminate) return;
    // 0047a861  8b0f                   -mov ecx, dword ptr [edi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi);
    // 0047a863  8b5704                 -mov edx, dword ptr [edi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0047a866  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047a868  39d1                   +cmp ecx, edx
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
    // 0047a86a  741b                   -je 0x47a887
    if (cpu.flags.zf)
    {
        goto L_0x0047a887;
    }
L_0x0047a86c:
    // 0047a86c  bb0c000000             -mov ebx, 0xc
    cpu.ebx = 12 /*0xc*/;
    // 0047a871  8d5104                 -lea edx, [ecx + 4]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0047a874  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047a876  e8457d0000             -call 0x4825c0
    cpu.esp -= 4;
    sub_4825c0(app, cpu);
    if (cpu.terminate) return;
    // 0047a87b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047a87d  740f                   -je 0x47a88e
    if (cpu.flags.zf)
    {
        goto L_0x0047a88e;
    }
    // 0047a87f  8b4920                 -mov ecx, dword ptr [ecx + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 0047a882  3b4f04                 +cmp ecx, dword ptr [edi + 4]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047a885  75e5                   -jne 0x47a86c
    if (!cpu.flags.zf)
    {
        goto L_0x0047a86c;
    }
L_0x0047a887:
    // 0047a887  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047a889  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a88a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a88b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a88c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a88d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047a88e:
    // 0047a88e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047a890  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a891  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a892  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a893  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a894  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47a898(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047a898  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047a899  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047a89b  e898ffffff             -call 0x47a838
    cpu.esp -= 4;
    sub_47a838(app, cpu);
    if (cpu.terminate) return;
    // 0047a8a0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a8a1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47a8a4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047a8a4  833da8a64c0000         +cmp dword ptr [0x4ca6a8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5023400) /* 0x4ca6a8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047a8ab  7503                   -jne 0x47a8b0
    if (!cpu.flags.zf)
    {
        goto L_0x0047a8b0;
    }
    // 0047a8ad  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047a8af  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047a8b0:
    // 0047a8b0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047a8b2  e83d000000             -call 0x47a8f4
    cpu.esp -= 4;
    sub_47a8f4(app, cpu);
    if (cpu.terminate) return;
    // 0047a8b7  3b057cd95100           +cmp eax, dword ptr [0x51d97c]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5364092) /* 0x51d97c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047a8bd  7d05                   -jge 0x47a8c4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047a8c4;
    }
    // 0047a8bf  a37cd95100             -mov dword ptr [0x51d97c], eax
    app->getMemory<x86::reg32>(x86::reg32(5364092) /* 0x51d97c */) = cpu.eax;
L_0x0047a8c4:
    // 0047a8c4  a17cd95100             -mov eax, dword ptr [0x51d97c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364092) /* 0x51d97c */);
    // 0047a8c9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47a8cc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047a8cc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047a8ce  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 0047a8d0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047a8d1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047a8d3  a170d95100             -mov eax, dword ptr [0x51d970]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364080) /* 0x51d970 */);
    // 0047a8d8  e833d20100             -call 0x497b10
    cpu.esp -= 4;
    sub_497b10(app, cpu);
    if (cpu.terminate) return;
    // 0047a8dd  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047a8df  e810000000             -call 0x47a8f4
    cpu.esp -= 4;
    sub_47a8f4(app, cpu);
    if (cpu.terminate) return;
    // 0047a8e4  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047a8e6  a170d95100             -mov eax, dword ptr [0x51d970]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364080) /* 0x51d970 */);
    // 0047a8eb  e828d20100             -call 0x497b18
    cpu.esp -= 4;
    sub_497b18(app, cpu);
    if (cpu.terminate) return;
    // 0047a8f0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047a8f2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a8f3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47a8f4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047a8f4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047a8f5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047a8f6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047a8f7  25000f0000             -and eax, 0xf00
    cpu.eax &= x86::reg32(x86::sreg32(3840 /*0xf00*/));
    // 0047a8fc  3d00030000             +cmp eax, 0x300
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(768 /*0x300*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047a901  7456                   -je 0x47a959
    if (cpu.flags.zf)
    {
        goto L_0x0047a959;
    }
    // 0047a903  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 0047a906  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047a908  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0047a90b  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0047a90d  bef0d75100             -mov esi, 0x51d7f0
    cpu.esi = 5363696 /*0x51d7f0*/;
    // 0047a912  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0047a915  8b15a4a64c00           -mov edx, dword ptr [0x4ca6a4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023396) /* 0x4ca6a4 */);
    // 0047a91b  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047a91d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047a91f  7541                   -jne 0x47a962
    if (!cpu.flags.zf)
    {
        goto L_0x0047a962;
    }
L_0x0047a921:
    // 0047a921  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047a922  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047a923  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047a924  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0047a926  8b7e04                 -mov edi, dword ptr [esi + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0047a929  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047a92b  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 0047a92e  8b7f20                 -mov edi, dword ptr [edi + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */);
L_0x0047a931:
    // 0047a931  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0047a933  2b11                   -sub edx, dword ptr [ecx]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx)));
    // 0047a935  8b6910                 -mov ebp, dword ptr [ecx + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0047a938  8b4e14                 -mov ecx, dword ptr [esi + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0047a93b  29ea                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0047a93d  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047a93f  39da                   +cmp edx, ebx
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
    // 0047a941  7e02                   -jle 0x47a945
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047a945;
    }
    // 0047a943  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
L_0x0047a945:
    // 0047a945  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047a947  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0047a94a  39f8                   +cmp eax, edi
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
    // 0047a94c  75e3                   -jne 0x47a931
    if (!cpu.flags.zf)
    {
        goto L_0x0047a931;
    }
    // 0047a94e  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0047a950  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a951  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a952  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047a953:
    // 0047a953  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047a955  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a956  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a957  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a958  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047a959:
    // 0047a959  e8a2d80100             -call 0x498200
    cpu.esp -= 4;
    sub_498200(app, cpu);
    if (cpu.terminate) return;
    // 0047a95e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047a960  ebf1                   -jmp 0x47a953
    goto L_0x0047a953;
L_0x0047a962:
    // 0047a962  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 0047a964  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0047a967  e82cd30100             -call 0x497c98
    cpu.esp -= 4;
    sub_497c98(app, cpu);
    if (cpu.terminate) return;
    // 0047a96c  ebb3                   -jmp 0x47a921
    goto L_0x0047a921;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47a970(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047a970  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047a971  8b158ca64c00           -mov edx, dword ptr [0x4ca68c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023372) /* 0x4ca68c */);
    // 0047a977  81fa38d85100           +cmp edx, 0x51d838
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5363768 /*0x51d838*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047a97d  741c                   -je 0x47a99b
    if (cpu.flags.zf)
    {
        goto L_0x0047a99b;
    }
    // 0047a97f  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0047a981  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047a983  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047a985  7410                   -je 0x47a997
    if (cpu.flags.zf)
    {
        goto L_0x0047a997;
    }
L_0x0047a987:
    // 0047a987  f6401818               +test byte ptr [eax + 0x18], 0x18
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(24) /* 0x18 */) & 24 /*0x18*/));
    // 0047a98b  7503                   -jne 0x47a990
    if (!cpu.flags.zf)
    {
        goto L_0x0047a990;
    }
    // 0047a98d  035010                 -add edx, dword ptr [eax + 0x10]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */)));
L_0x0047a990:
    // 0047a990  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0047a993  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047a995  75f0                   -jne 0x47a987
    if (!cpu.flags.zf)
    {
        goto L_0x0047a987;
    }
L_0x0047a997:
    // 0047a997  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047a999  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a99a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047a99b:
    // 0047a99b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047a99d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a99e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_47a9a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047a9a0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047a9a1  8b158ca64c00           -mov edx, dword ptr [0x4ca68c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023372) /* 0x4ca68c */);
    // 0047a9a7  81fa38d85100           +cmp edx, 0x51d838
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5363768 /*0x51d838*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047a9ad  741c                   -je 0x47a9cb
    if (cpu.flags.zf)
    {
        goto L_0x0047a9cb;
    }
    // 0047a9af  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0047a9b1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047a9b3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047a9b5  7410                   -je 0x47a9c7
    if (cpu.flags.zf)
    {
        goto L_0x0047a9c7;
    }
L_0x0047a9b7:
    // 0047a9b7  f6401810               +test byte ptr [eax + 0x18], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(24) /* 0x18 */) & 16 /*0x10*/));
    // 0047a9bb  7403                   -je 0x47a9c0
    if (cpu.flags.zf)
    {
        goto L_0x0047a9c0;
    }
    // 0047a9bd  035010                 -add edx, dword ptr [eax + 0x10]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */)));
L_0x0047a9c0:
    // 0047a9c0  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0047a9c3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047a9c5  75f0                   -jne 0x47a9b7
    if (!cpu.flags.zf)
    {
        goto L_0x0047a9b7;
    }
L_0x0047a9c7:
    // 0047a9c7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047a9c9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a9ca  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047a9cb:
    // 0047a9cb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047a9cd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a9ce  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_47a9d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047a9d0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047a9d1  8b158ca64c00           -mov edx, dword ptr [0x4ca68c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5023372) /* 0x4ca68c */);
    // 0047a9d7  81fa38d85100           +cmp edx, 0x51d838
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5363768 /*0x51d838*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047a9dd  741c                   -je 0x47a9fb
    if (cpu.flags.zf)
    {
        goto L_0x0047a9fb;
    }
    // 0047a9df  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0047a9e1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047a9e3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047a9e5  7410                   -je 0x47a9f7
    if (cpu.flags.zf)
    {
        goto L_0x0047a9f7;
    }
L_0x0047a9e7:
    // 0047a9e7  f6401808               +test byte ptr [eax + 0x18], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(24) /* 0x18 */) & 8 /*0x8*/));
    // 0047a9eb  7403                   -je 0x47a9f0
    if (cpu.flags.zf)
    {
        goto L_0x0047a9f0;
    }
    // 0047a9ed  035010                 -add edx, dword ptr [eax + 0x10]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */)));
L_0x0047a9f0:
    // 0047a9f0  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0047a9f3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047a9f5  75f0                   -jne 0x47a9e7
    if (!cpu.flags.zf)
    {
        goto L_0x0047a9e7;
    }
L_0x0047a9f7:
    // 0047a9f7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047a9f9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a9fa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047a9fb:
    // 0047a9fb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047a9fd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047a9fe  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_47aa00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047aa00  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047aa01  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047aa02  8b358ca64c00           -mov esi, dword ptr [0x4ca68c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5023372) /* 0x4ca68c */);
    // 0047aa08  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047aa0a  81fe38d85100           +cmp esi, 0x51d838
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5363768 /*0x51d838*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047aa10  7420                   -je 0x47aa32
    if (cpu.flags.zf)
    {
        goto L_0x0047aa32;
    }
    // 0047aa12  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047aa13  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047aa14  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0047aa16  8b5020                 -mov edx, dword ptr [eax + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
L_0x0047aa19:
    // 0047aa19  3b4604                 +cmp eax, dword ptr [esi + 4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047aa1c  7422                   -je 0x47aa40
    if (cpu.flags.zf)
    {
        goto L_0x0047aa40;
    }
    // 0047aa1e  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 0047aa20  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0047aa23  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0047aa25  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 0047aa27  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0047aa29  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047aa2b  01d9                   +add ecx, ebx
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
    // 0047aa2d  8b5220                 -mov edx, dword ptr [edx + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 0047aa30  ebe7                   -jmp 0x47aa19
    goto L_0x0047aa19;
L_0x0047aa32:
    // 0047aa32  e8c9d70100             -call 0x498200
    cpu.esp -= 4;
    sub_498200(app, cpu);
    if (cpu.terminate) return;
    // 0047aa37  8b358ca64c00           -mov esi, dword ptr [0x4ca68c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5023372) /* 0x4ca68c */);
    // 0047aa3d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047aa3e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047aa3f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047aa40:
    // 0047aa40  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047aa42  89358ca64c00           -mov dword ptr [0x4ca68c], esi
    app->getMemory<x86::reg32>(x86::reg32(5023372) /* 0x4ca68c */) = cpu.esi;
    // 0047aa48  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047aa49  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047aa4a  8b358ca64c00           -mov esi, dword ptr [0x4ca68c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5023372) /* 0x4ca68c */);
    // 0047aa50  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047aa51  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047aa52  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_47aa54(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047aa54  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047aa55  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047aa56  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047aa57  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047aa59  81e2000f0000           -and edx, 0xf00
    cpu.edx &= x86::reg32(x86::sreg32(3840 /*0xf00*/));
    // 0047aa5f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047aa61  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047aa63  81fa00030000           +cmp edx, 0x300
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(768 /*0x300*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047aa69  7450                   -je 0x47aabb
    if (cpu.flags.zf)
    {
        goto L_0x0047aabb;
    }
    // 0047aa6b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047aa6c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047aa6d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047aa6e  c1fa08                 -sar edx, 8
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (8 /*0x8*/ % 32));
    // 0047aa71  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0047aa73  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0047aa76  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047aa78  bff0d75100             -mov edi, 0x51d7f0
    cpu.edi = 5363696 /*0x51d7f0*/;
    // 0047aa7d  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 0047aa80  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 0047aa82  8b0f                   -mov ecx, dword ptr [edi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi);
    // 0047aa84  8b7704                 -mov esi, dword ptr [edi + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0047aa87  8b5120                 -mov edx, dword ptr [ecx + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 0047aa8a  39f1                   +cmp ecx, esi
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
    // 0047aa8c  7424                   -je 0x47aab2
    if (cpu.flags.zf)
    {
        goto L_0x0047aab2;
    }
L_0x0047aa8e:
    // 0047aa8e  8b31                   -mov esi, dword ptr [ecx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx);
    // 0047aa90  8b4910                 -mov ecx, dword ptr [ecx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0047aa93  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0047aa95  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 0047aa97  29ce                   -sub esi, ecx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047aa99  8a4a18                 -mov cl, byte ptr [edx + 0x18]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0047aa9c  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0047aa9e  f6c108                 +test cl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 8 /*0x8*/));
    // 0047aaa1  7421                   -je 0x47aac4
    if (cpu.flags.zf)
    {
        goto L_0x0047aac4;
    }
    // 0047aaa3  034210                 -add eax, dword ptr [edx + 0x10]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */)));
L_0x0047aaa6:
    // 0047aaa6  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0047aaa8  8b6f04                 -mov ebp, dword ptr [edi + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0047aaab  8b5220                 -mov edx, dword ptr [edx + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 0047aaae  39e9                   +cmp ecx, ebp
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
    // 0047aab0  75dc                   -jne 0x47aa8e
    if (!cpu.flags.zf)
    {
        goto L_0x0047aa8e;
    }
L_0x0047aab2:
    // 0047aab2  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047aab4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047aab5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047aab6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047aab7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047aab8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047aab9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047aaba  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047aabb:
    // 0047aabb  e840d70100             -call 0x498200
    cpu.esp -= 4;
    sub_498200(app, cpu);
    if (cpu.terminate) return;
    // 0047aac0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047aac1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047aac2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047aac3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047aac4:
    // 0047aac4  39d8                   +cmp eax, ebx
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
    // 0047aac6  7e02                   -jle 0x47aaca
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047aaca;
    }
    // 0047aac8  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x0047aaca:
    // 0047aaca  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047aacc  ebd8                   -jmp 0x47aaa6
    goto L_0x0047aaa6;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47aad0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047aad0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047aad1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047aad2  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0047aad4  a374d95100             -mov dword ptr [0x51d974], eax
    app->getMemory<x86::reg32>(x86::reg32(5364084) /* 0x51d974 */) = cpu.eax;
    // 0047aad9  49                     -dec ecx
    (cpu.ecx)--;
    // 0047aada  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047aadc  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047aade  7e10                   -jle 0x47aaf0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047aaf0;
    }
L_0x0047aae0:
    // 0047aae0  8d5828                 -lea ebx, [eax + 0x28]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 0047aae3  42                     -inc edx
    (cpu.edx)++;
    // 0047aae4  895820                 -mov dword ptr [eax + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 0047aae7  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047aae9  39ca                   +cmp edx, ecx
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
    // 0047aaeb  7cf3                   -jl 0x47aae0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047aae0;
    }
    // 0047aaed  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x0047aaf0:
    // 0047aaf0  c7402000000000         -mov dword ptr [eax + 0x20], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 0047aaf7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047aaf8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047aaf9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47aafc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047aafc  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047aafd  8b1574d95100           -mov edx, dword ptr [0x51d974]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5364084) /* 0x51d974 */);
    // 0047ab03  a374d95100             -mov dword ptr [0x51d974], eax
    app->getMemory<x86::reg32>(x86::reg32(5364084) /* 0x51d974 */) = cpu.eax;
    // 0047ab08  895020                 -mov dword ptr [eax + 0x20], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 0047ab0b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ab0c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47ab10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047ab10  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047ab11  a174d95100             -mov eax, dword ptr [0x51d974]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364084) /* 0x51d974 */);
    // 0047ab16  8b5020                 -mov edx, dword ptr [eax + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0047ab19  891574d95100           -mov dword ptr [0x51d974], edx
    app->getMemory<x86::reg32>(x86::reg32(5364084) /* 0x51d974 */) = cpu.edx;
    // 0047ab1f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ab20  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47ab24(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047ab24  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047ab25  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0047ab2a  e811fbffff             -call 0x47a640
    cpu.esp -= 4;
    sub_47a640(app, cpu);
    if (cpu.terminate) return;
    // 0047ab2f  8b4014                 -mov eax, dword ptr [eax + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 0047ab32  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ab33  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47ab34(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047ab34  8b4014                 -mov eax, dword ptr [eax + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 0047ab37  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47ab38(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047ab38  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047ab3b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47ab3c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047ab3c  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0047ab3f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47ab40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047ab40  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047ab41  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047ab43  a170d95100             -mov eax, dword ptr [0x51d970]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364080) /* 0x51d970 */);
    // 0047ab48  e8c3cf0100             -call 0x497b10
    cpu.esp -= 4;
    sub_497b10(app, cpu);
    if (cpu.terminate) return;
    // 0047ab4d  806218ef               -and byte ptr [edx + 0x18], 0xef
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(24) /* 0x18 */) &= x86::reg8(x86::sreg8(239 /*0xef*/));
    // 0047ab51  a170d95100             -mov eax, dword ptr [0x51d970]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364080) /* 0x51d970 */);
    // 0047ab56  e8bdcf0100             -call 0x497b18
    cpu.esp -= 4;
    sub_497b18(app, cpu);
    if (cpu.terminate) return;
    // 0047ab5b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ab5c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47ab60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047ab60  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047ab61  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047ab63  a170d95100             -mov eax, dword ptr [0x51d970]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364080) /* 0x51d970 */);
    // 0047ab68  e8a3cf0100             -call 0x497b10
    cpu.esp -= 4;
    sub_497b10(app, cpu);
    if (cpu.terminate) return;
    // 0047ab6d  804a1810               -or byte ptr [edx + 0x18], 0x10
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(24) /* 0x18 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
    // 0047ab71  a170d95100             -mov eax, dword ptr [0x51d970]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364080) /* 0x51d970 */);
    // 0047ab76  e89dcf0100             -call 0x497b18
    cpu.esp -= 4;
    sub_497b18(app, cpu);
    if (cpu.terminate) return;
    // 0047ab7b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ab7c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47ab80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047ab80  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047ab81  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0047ab83  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0047ab88  e8b3faffff             -call 0x47a640
    cpu.esp -= 4;
    sub_47a640(app, cpu);
    if (cpu.terminate) return;
    // 0047ab8d  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047ab8f  e804000000             -call 0x47ab98
    cpu.esp -= 4;
    sub_47ab98(app, cpu);
    if (cpu.terminate) return;
    // 0047ab94  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ab95  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47ab98(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047ab98  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047ab99  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047ab9b  a170d95100             -mov eax, dword ptr [0x51d970]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364080) /* 0x51d970 */);
    // 0047aba0  e86bcf0100             -call 0x497b10
    cpu.esp -= 4;
    sub_497b10(app, cpu);
    if (cpu.terminate) return;
    // 0047aba5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047aba7  e80c000000             -call 0x47abb8
    cpu.esp -= 4;
    sub_47abb8(app, cpu);
    if (cpu.terminate) return;
    // 0047abac  a170d95100             -mov eax, dword ptr [0x51d970]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364080) /* 0x51d970 */);
    // 0047abb1  e862cf0100             -call 0x497b18
    cpu.esp -= 4;
    sub_497b18(app, cpu);
    if (cpu.terminate) return;
    // 0047abb6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047abb7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47abb8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047abb8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047abb9  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047abbb  7405                   -je 0x47abc2
    if (cpu.flags.zf)
    {
        goto L_0x0047abc2;
    }
    // 0047abbd  ba00200000             -mov edx, 0x2000
    cpu.edx = 8192 /*0x2000*/;
L_0x0047abc2:
    // 0047abc2  8b4818                 -mov ecx, dword ptr [eax + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0047abc5  80e5df                 -and ch, 0xdf
    cpu.ch &= x86::reg8(x86::sreg8(223 /*0xdf*/));
    // 0047abc8  09d1                   -or ecx, edx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.edx));
    // 0047abca  894818                 -mov dword ptr [eax + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 0047abcd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047abce  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_47abd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047abd0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047abd1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047abd2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047abd3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047abd4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047abd5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047abd7  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x0047abd9:
    // 0047abd9  8b96f4d75100           -mov edx, dword ptr [esi + 0x51d7f4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5363700) /* 0x51d7f4 */);
    // 0047abdf  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047abe1  7421                   -je 0x47ac04
    if (cpu.flags.zf)
    {
        goto L_0x0047ac04;
    }
    // 0047abe3  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0047abe5  8b86f0d75100           -mov eax, dword ptr [esi + 0x51d7f0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5363696) /* 0x51d7f0 */);
L_0x0047abeb:
    // 0047abeb  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0047abee  8b38                   -mov edi, dword ptr [eax]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax);
    // 0047abf0  39f9                   +cmp ecx, edi
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
    // 0047abf2  7223                   -jb 0x47ac17
    if (cpu.flags.cf)
    {
        goto L_0x0047ac17;
    }
    // 0047abf4  8b6814                 -mov ebp, dword ptr [eax + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 0047abf7  8d142f                 -lea edx, [edi + ebp]
    cpu.edx = x86::reg32(cpu.edi + cpu.ebp * 1);
    // 0047abfa  39d1                   +cmp ecx, edx
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
    // 0047abfc  7319                   -jae 0x47ac17
    if (!cpu.flags.cf)
    {
        goto L_0x0047ac17;
    }
L_0x0047abfe:
    // 0047abfe  f6401980               +test byte ptr [eax + 0x19], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(25) /* 0x19 */) & 128 /*0x80*/));
    // 0047ac02  740d                   -je 0x47ac11
    if (cpu.flags.zf)
    {
        goto L_0x0047ac11;
    }
L_0x0047ac04:
    // 0047ac04  83c618                 -add esi, 0x18
    (cpu.esi) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0047ac07  81fe80010000           +cmp esi, 0x180
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(384 /*0x180*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047ac0d  7cca                   -jl 0x47abd9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047abd9;
    }
    // 0047ac0f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0047ac11:
    // 0047ac11  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ac12  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ac13  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ac14  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ac15  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ac16  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047ac17:
    // 0047ac17  39d8                   +cmp eax, ebx
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
    // 0047ac19  75d0                   -jne 0x47abeb
    if (!cpu.flags.zf)
    {
        goto L_0x0047abeb;
    }
    // 0047ac1b  ebe1                   -jmp 0x47abfe
    goto L_0x0047abfe;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47ac20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047ac20  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047ac21  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0047ac26  e8a5ffffff             -call 0x47abd0
    cpu.esp -= 4;
    sub_47abd0(app, cpu);
    if (cpu.terminate) return;
    // 0047ac2b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ac2c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47ac30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047ac30  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047ac31  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047ac33  e898ffffff             -call 0x47abd0
    cpu.esp -= 4;
    sub_47abd0(app, cpu);
    if (cpu.terminate) return;
    // 0047ac38  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ac39  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47ac40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047ac40  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047ac41  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047ac43  803db0cd4c0000         +cmp byte ptr [0x4ccdb0], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5033392) /* 0x4ccdb0 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047ac4a  7507                   -jne 0x47ac53
    if (!cpu.flags.zf)
    {
        goto L_0x0047ac53;
    }
    // 0047ac4c  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 0047ac51  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ac52  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047ac53:
    // 0047ac53  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047ac55  e89a110000             -call 0x47bdf4
    cpu.esp -= 4;
    sub_47bdf4(app, cpu);
    if (cpu.terminate) return;
    // 0047ac5a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047ac5c  751c                   -jne 0x47ac7a
    if (!cpu.flags.zf)
    {
        goto L_0x0047ac7a;
    }
    // 0047ac5e  8b04d5d0ad5200         -mov eax, dword ptr [edx*8 + 0x52add0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5418448) /* 0x52add0 */ + cpu.edx * 8);
    // 0047ac65  8138424e4b6c           +cmp dword ptr [eax], 0x6c4b4e42
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1816874562 /*0x6c4b4e42*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047ac6b  7519                   -jne 0x47ac86
    if (!cpu.flags.zf)
    {
        goto L_0x0047ac86;
    }
    // 0047ac6d  80780401               +cmp byte ptr [eax + 4], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047ac71  770e                   -ja 0x47ac81
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0047ac81;
    }
    // 0047ac73  b8f5ffffff             -mov eax, 0xfffffff5
    cpu.eax = 4294967285 /*0xfffffff5*/;
    // 0047ac78  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ac79  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047ac7a:
    // 0047ac7a  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 0047ac7f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ac80  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047ac81:
    // 0047ac81  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0047ac84  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ac85  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047ac86:
    // 0047ac86  b8f9ffffff             -mov eax, 0xfffffff9
    cpu.eax = 4294967289 /*0xfffffff9*/;
    // 0047ac8b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ac8c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47ac90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047ac90  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047ac91  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047ac93  803db0cd4c0000         +cmp byte ptr [0x4ccdb0], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5033392) /* 0x4ccdb0 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047ac9a  7507                   -jne 0x47aca3
    if (!cpu.flags.zf)
    {
        goto L_0x0047aca3;
    }
    // 0047ac9c  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 0047aca1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047aca2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047aca3:
    // 0047aca3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047aca5  e84a110000             -call 0x47bdf4
    cpu.esp -= 4;
    sub_47bdf4(app, cpu);
    if (cpu.terminate) return;
    // 0047acaa  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047acac  752d                   -jne 0x47acdb
    if (!cpu.flags.zf)
    {
        goto L_0x0047acdb;
    }
    // 0047acae  8b04cdd0ad5200         -mov eax, dword ptr [ecx*8 + 0x52add0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5418448) /* 0x52add0 */ + cpu.ecx * 8);
    // 0047acb5  80780401               +cmp byte ptr [eax + 4], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047acb9  7627                   -jbe 0x47ace2
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0047ace2;
    }
    // 0047acbb  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047acbd  668b4806               -mov cx, word ptr [eax + 6]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(6) /* 0x6 */);
    // 0047acc1  39ca                   +cmp edx, ecx
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
    // 0047acc3  7d16                   -jge 0x47acdb
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047acdb;
    }
    // 0047acc5  8b44900c               -mov eax, dword ptr [eax + edx*4 + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */ + cpu.edx * 4);
    // 0047acc9  6681385054             +cmp word ptr [eax], 0x5450
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
    // 0047acce  7520                   -jne 0x47acf0
    if (!cpu.flags.zf)
    {
        goto L_0x0047acf0;
    }
    // 0047acd0  f6400302               +test byte ptr [eax + 3], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */) & 2 /*0x2*/));
    // 0047acd4  7413                   -je 0x47ace9
    if (cpu.flags.zf)
    {
        goto L_0x0047ace9;
    }
    // 0047acd6  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0047acd9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047acda  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047acdb:
    // 0047acdb  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 0047ace0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ace1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047ace2:
    // 0047ace2  b8f5ffffff             -mov eax, 0xfffffff5
    cpu.eax = 4294967285 /*0xfffffff5*/;
    // 0047ace7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ace8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047ace9:
    // 0047ace9  b8f1ffffff             -mov eax, 0xfffffff1
    cpu.eax = 4294967281 /*0xfffffff1*/;
    // 0047acee  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047acef  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047acf0:
    // 0047acf0  b8f9ffffff             -mov eax, 0xfffffff9
    cpu.eax = 4294967289 /*0xfffffff9*/;
    // 0047acf5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047acf6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_47acf8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047acf8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047acf9  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047acfa  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0047acfd  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047acff  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0047ad03  8a25b0cd4c00           -mov ah, byte ptr [0x4ccdb0]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5033392) /* 0x4ccdb0 */);
    // 0047ad09  bd80000000             -mov ebp, 0x80
    cpu.ebp = 128 /*0x80*/;
    // 0047ad0e  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 0047ad10  740f                   -je 0x47ad21
    if (cpu.flags.zf)
    {
        goto L_0x0047ad21;
    }
    // 0047ad12  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047ad14  7512                   -jne 0x47ad28
    if (!cpu.flags.zf)
    {
        goto L_0x0047ad28;
    }
    // 0047ad16  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
L_0x0047ad1b:
    // 0047ad1b  83c410                 +add esp, 0x10
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
    // 0047ad1e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ad1f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ad20  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047ad21:
    // 0047ad21  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 0047ad26  ebf3                   -jmp 0x47ad1b
    goto L_0x0047ad1b;
L_0x0047ad28:
    // 0047ad28  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047ad2a  e811ffffff             -call 0x47ac40
    cpu.esp -= 4;
    sub_47ac40(app, cpu);
    if (cpu.terminate) return;
    // 0047ad2f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047ad31  7ce8                   -jl 0x47ad1b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047ad1b;
    }
    // 0047ad33  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047ad34  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047ad35  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047ad36  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0047ad38  8b14d5d0ad5200         -mov edx, dword ptr [edx*8 + 0x52add0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5418448) /* 0x52add0 */ + cpu.edx * 8);
    // 0047ad3f  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0047ad43  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047ad45  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047ad49  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0047ad4b  e8b0680000             -call 0x481600
    cpu.esp -= 4;
    sub_481600(app, cpu);
    if (cpu.terminate) return;
    // 0047ad50  8b14cdd0ad5200         -mov edx, dword ptr [ecx*8 + 0x52add0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5418448) /* 0x52add0 */ + cpu.ecx * 8);
    // 0047ad57  807a0401               +cmp byte ptr [edx + 4], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047ad5b  7204                   -jb 0x47ad61
    if (cpu.flags.cf)
    {
        goto L_0x0047ad61;
    }
    // 0047ad5d  0fb76a06               -movzx ebp, word ptr [edx + 6]
    cpu.ebp = x86::reg32(app->getMemory<x86::reg16>(cpu.edx + x86::reg32(6) /* 0x6 */));
L_0x0047ad61:
    // 0047ad61  807a0402               +cmp byte ptr [edx + 4], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047ad65  7248                   -jb 0x47adaf
    if (cpu.flags.cf)
    {
        goto L_0x0047adaf;
    }
    // 0047ad67  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0047ad69  89742414               -mov dword ptr [esp + 0x14], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.esi;
L_0x0047ad6d:
    // 0047ad6d  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0047ad6f  7e28                   -jle 0x47ad99
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047ad99;
    }
    // 0047ad71  c1e502                 -shl ebp, 2
    cpu.ebp <<= 2 /*0x2*/ % 32;
    // 0047ad74  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0047ad76:
    // 0047ad76  807a0402               +cmp byte ptr [edx + 4], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(4) /* 0x4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047ad7a  7239                   -jb 0x47adb5
    if (cpu.flags.cf)
    {
        goto L_0x0047adb5;
    }
    // 0047ad7c  8d0c07                 -lea ecx, [edi + eax]
    cpu.ecx = x86::reg32(cpu.edi + cpu.eax * 1);
    // 0047ad7f  8b490c                 -mov ecx, dword ptr [ecx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0047ad82  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047ad84  740c                   -je 0x47ad92
    if (cpu.flags.zf)
    {
        goto L_0x0047ad92;
    }
    // 0047ad86  29f9                   -sub ecx, edi
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0047ad88  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0047ad8c  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0047ad8e  894c030c               -mov dword ptr [ebx + eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */ + cpu.eax * 1) = cpu.ecx;
L_0x0047ad92:
    // 0047ad92  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047ad95  39e8                   +cmp eax, ebp
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
    // 0047ad97  7cdd                   -jl 0x47ad76
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047ad76;
    }
L_0x0047ad99:
    // 0047ad99  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0047ad9d  8934c5d0ad5200         -mov dword ptr [eax*8 + 0x52add0], esi
    app->getMemory<x86::reg32>(x86::reg32(5418448) /* 0x52add0 */ + cpu.eax * 8) = cpu.esi;
    // 0047ada4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047ada6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ada7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ada8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ada9  83c410                 +add esp, 0x10
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
    // 0047adac  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047adad  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047adae  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047adaf:
    // 0047adaf  89742418               -mov dword ptr [esp + 0x18], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 0047adb3  ebb8                   -jmp 0x47ad6d
    goto L_0x0047ad6d;
L_0x0047adb5:
    // 0047adb5  8d0c02                 -lea ecx, [edx + eax]
    cpu.ecx = x86::reg32(cpu.edx + cpu.eax * 1);
    // 0047adb8  8b4908                 -mov ecx, dword ptr [ecx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0047adbb  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047adbd  74d3                   -je 0x47ad92
    if (cpu.flags.zf)
    {
        goto L_0x0047ad92;
    }
    // 0047adbf  29d1                   +sub ecx, edx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047adc1  8d1c0e                 -lea ebx, [esi + ecx]
    cpu.ebx = x86::reg32(cpu.esi + cpu.ecx * 1);
    // 0047adc4  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0047adc8  895c0108               -mov dword ptr [ecx + eax + 8], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */ + cpu.eax * 1) = cpu.ebx;
    // 0047adcc  ebc4                   -jmp 0x47ad92
    goto L_0x0047ad92;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47add0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047add0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047add1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047add2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047add4  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0047add6  803db0cd4c0000         +cmp byte ptr [0x4ccdb0], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5033392) /* 0x4ccdb0 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047addd  740c                   -je 0x47adeb
    if (cpu.flags.zf)
    {
        goto L_0x0047adeb;
    }
    // 0047addf  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047ade1  7510                   -jne 0x47adf3
    if (!cpu.flags.zf)
    {
        goto L_0x0047adf3;
    }
    // 0047ade3  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
L_0x0047ade8:
    // 0047ade8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ade9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047adea  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047adeb:
    // 0047adeb  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 0047adf0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047adf1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047adf2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047adf3:
    // 0047adf3  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0047adf5  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047adf7  e894feffff             -call 0x47ac90
    cpu.esp -= 4;
    sub_47ac90(app, cpu);
    if (cpu.terminate) return;
    // 0047adfc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047adfe  7ce8                   -jl 0x47ade8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047ade8;
    }
    // 0047ae00  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047ae01  8b3cf5d0ad5200         -mov edi, dword ptr [esi*8 + 0x52add0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5418448) /* 0x52add0 */ + cpu.esi * 8);
    // 0047ae08  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 0047ae0b  8a5704                 -mov dl, byte ptr [edi + 4]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0047ae0e  8d341f                 -lea esi, [edi + ebx]
    cpu.esi = x86::reg32(cpu.edi + cpu.ebx * 1);
    // 0047ae11  80fa01                 +cmp dl, 1
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
    // 0047ae14  7517                   -jne 0x47ae2d
    if (!cpu.flags.zf)
    {
        goto L_0x0047ae2d;
    }
    // 0047ae16  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047ae18  8b7e08                 -mov edi, dword ptr [esi + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0047ae1b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047ae1d  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0047ae1f  e8dc670000             -call 0x481600
    cpu.esp -= 4;
    sub_481600(app, cpu);
    if (cpu.terminate) return;
    // 0047ae24  894e08                 -mov dword ptr [esi + 8], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0047ae27  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047ae29  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ae2a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ae2b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ae2c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047ae2d:
    // 0047ae2d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047ae2f  8b7e0c                 -mov edi, dword ptr [esi + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0047ae32  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047ae34  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0047ae36  e8c5670000             -call 0x481600
    cpu.esp -= 4;
    sub_481600(app, cpu);
    if (cpu.terminate) return;
    // 0047ae3b  894e0c                 -mov dword ptr [esi + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0047ae3e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047ae40  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ae41  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ae42  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ae43  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47ae44(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047ae44  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047ae45  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0047ae47  e810100000             -call 0x47be5c
    cpu.esp -= 4;
    sub_47be5c(app, cpu);
    if (cpu.terminate) return;
    // 0047ae4c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ae4d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47ae50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047ae50  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047ae51  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0047ae53  e898d50100             -call 0x4983f0
    cpu.esp -= 4;
    sub_4983f0(app, cpu);
    if (cpu.terminate) return;
    // 0047ae58  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ae59  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47ae60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047ae60  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047ae62  7506                   -jne 0x47ae6a
    if (!cpu.flags.zf)
    {
        goto L_0x0047ae6a;
    }
    // 0047ae64  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 0047ae69  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047ae6a:
    // 0047ae6a  c700ffffffff           -mov dword ptr [eax], 0xffffffff
    app->getMemory<x86::reg32>(cpu.eax) = 4294967295 /*0xffffffff*/;
    // 0047ae70  c64004ff               -mov byte ptr [eax + 4], 0xff
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */) = 255 /*0xff*/;
    // 0047ae74  c640053c               -mov byte ptr [eax + 5], 0x3c
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */) = 60 /*0x3c*/;
    // 0047ae78  c640067f               -mov byte ptr [eax + 6], 0x7f
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(6) /* 0x6 */) = 127 /*0x7f*/;
    // 0047ae7c  c6400740               -mov byte ptr [eax + 7], 0x40
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(7) /* 0x7 */) = 64 /*0x40*/;
    // 0047ae80  c640087f               -mov byte ptr [eax + 8], 0x7f
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */) = 127 /*0x7f*/;
    // 0047ae84  c6400940               -mov byte ptr [eax + 9], 0x40
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(9) /* 0x9 */) = 64 /*0x40*/;
    // 0047ae88  c6400a7f               -mov byte ptr [eax + 0xa], 0x7f
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10) /* 0xa */) = 127 /*0x7f*/;
    // 0047ae8c  c6400b00               -mov byte ptr [eax + 0xb], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(11) /* 0xb */) = 0 /*0x0*/;
    // 0047ae90  66c7400c0000           -mov word ptr [eax + 0xc], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 0047ae96  66c7400e0000           -mov word ptr [eax + 0xe], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(14) /* 0xe */) = 0 /*0x0*/;
    // 0047ae9c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047ae9e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_47aea0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047aea0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047aea1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047aea2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047aea3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047aea5  8a25b0cd4c00           -mov ah, byte ptr [0x4ccdb0]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5033392) /* 0x4ccdb0 */);
    // 0047aeab  b980000000             -mov ecx, 0x80
    cpu.ecx = 128 /*0x80*/;
    // 0047aeb0  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 0047aeb2  740d                   -je 0x47aec1
    if (cpu.flags.zf)
    {
        goto L_0x0047aec1;
    }
    // 0047aeb4  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047aeb6  7512                   -jne 0x47aeca
    if (!cpu.flags.zf)
    {
        goto L_0x0047aeca;
    }
L_0x0047aeb8:
    // 0047aeb8  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 0047aebd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047aebe  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047aebf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047aec0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047aec1:
    // 0047aec1  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 0047aec6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047aec7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047aec8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047aec9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047aeca:
    // 0047aeca  8b4201                 -mov eax, dword ptr [edx + 1]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0047aecd  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 0047aed0  e81f0f0000             -call 0x47bdf4
    cpu.esp -= 4;
    sub_47bdf4(app, cpu);
    if (cpu.terminate) return;
    // 0047aed5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047aed7  7cdf                   -jl 0x47aeb8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047aeb8;
    }
    // 0047aed9  8b4201                 -mov eax, dword ptr [edx + 1]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0047aedc  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 0047aedf  8b04c5d0ad5200         -mov eax, dword ptr [eax*8 + 0x52add0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5418448) /* 0x52add0 */ + cpu.eax * 8);
    // 0047aee6  80780401               +cmp byte ptr [eax + 4], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047aeea  7206                   -jb 0x47aef2
    if (cpu.flags.cf)
    {
        goto L_0x0047aef2;
    }
    // 0047aeec  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047aeee  668b4806               -mov cx, word ptr [eax + 6]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(6) /* 0x6 */);
L_0x0047aef2:
    // 0047aef2  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 0047aef4  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047aef6  7cc0                   -jl 0x47aeb8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047aeb8;
    }
    // 0047aef8  39d9                   +cmp ecx, ebx
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
    // 0047aefa  7ebc                   -jle 0x47aeb8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047aeb8;
    }
    // 0047aefc  80780402               +cmp byte ptr [eax + 4], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047af00  720f                   -jb 0x47af11
    if (cpu.flags.cf)
    {
        goto L_0x0047af11;
    }
    // 0047af02  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 0047af04  8b44880c               -mov eax, dword ptr [eax + ecx*4 + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */ + cpu.ecx * 4);
    // 0047af08  e843db0100             -call 0x498a50
    cpu.esp -= 4;
    sub_498a50(app, cpu);
    if (cpu.terminate) return;
    // 0047af0d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047af0e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047af0f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047af10  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047af11:
    // 0047af11  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 0047af13  8b448808               -mov eax, dword ptr [eax + ecx*4 + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */ + cpu.ecx * 4);
    // 0047af17  e834db0100             -call 0x498a50
    cpu.esp -= 4;
    sub_498a50(app, cpu);
    if (cpu.terminate) return;
    // 0047af1c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047af1d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047af1e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047af1f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47af20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047af20  3b5004                 +cmp edx, dword ptr [eax + 4]
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
    // 0047af23  7507                   -jne 0x47af2c
    if (!cpu.flags.zf)
    {
        goto L_0x0047af2c;
    }
    // 0047af25  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047af2a  c3                     -ret 
    cpu.esp += 4;
    return;
    // 0047af2b  90                     -nop 
    ;
L_0x0047af2c:
    // 0047af2c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047af2e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47af2c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0047af2c;
    // 0047af20  3b5004                 +cmp edx, dword ptr [eax + 4]
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
    // 0047af23  7507                   -jne 0x47af2c
    if (!cpu.flags.zf)
    {
        goto L_0x0047af2c;
    }
    // 0047af25  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047af2a  c3                     -ret 
    cpu.esp += 4;
    return;
    // 0047af2b  90                     -nop 
    ;
L_0x0047af2c:
L_entry_0x0047af2c:
    // 0047af2c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047af2e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_47af30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047af30  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047af31  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047af32  8b1580d95100           -mov edx, dword ptr [0x51d980]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */);
    // 0047af38  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047af3a  7434                   -je 0x47af70
    if (cpu.flags.zf)
    {
        goto L_0x0047af70;
    }
    // 0047af3c  8b4a18                 -mov ecx, dword ptr [edx + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0047af3f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047af41  7407                   -je 0x47af4a
    if (cpu.flags.zf)
    {
        goto L_0x0047af4a;
    }
    // 0047af43  c7412000000000         -mov dword ptr [ecx + 0x20], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
L_0x0047af4a:
    // 0047af4a  8b1580d95100           -mov edx, dword ptr [0x51d980]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */);
    // 0047af50  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 0047af52  b884d95100             -mov eax, 0x51d984
    cpu.eax = 5364100 /*0x51d984*/;
    // 0047af57  e8445b0000             -call 0x480aa0
    cpu.esp -= 4;
    sub_480aa0(app, cpu);
    if (cpu.terminate) return;
    // 0047af5c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0047af5e:
    // 0047af5e  a180d95100             -mov eax, dword ptr [0x51d980]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */);
    // 0047af63  3b10                   +cmp edx, dword ptr [eax]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047af65  7409                   -je 0x47af70
    if (cpu.flags.zf)
    {
        goto L_0x0047af70;
    }
    // 0047af67  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047af69  7405                   -je 0x47af70
    if (cpu.flags.zf)
    {
        goto L_0x0047af70;
    }
    // 0047af6b  3b4818                 +cmp ecx, dword ptr [eax + 0x18]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047af6e  7403                   -je 0x47af73
    if (cpu.flags.zf)
    {
        goto L_0x0047af73;
    }
L_0x0047af70:
    // 0047af70  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047af71  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047af72  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047af73:
    // 0047af73  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047af75  e8a2580000             -call 0x48081c
    cpu.esp -= 4;
    sub_48081c(app, cpu);
    if (cpu.terminate) return;
    // 0047af7a  ebe2                   -jmp 0x47af5e
    goto L_0x0047af5e;
}

/* align: skip  */
void Application::sub_47af7c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047af7c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047af7d  a180d95100             -mov eax, dword ptr [0x51d980]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */);
    // 0047af82  83c054                 -add eax, 0x54
    (cpu.eax) += x86::reg32(x86::sreg32(84 /*0x54*/));
    // 0047af85  e842790000             -call 0x4828cc
    cpu.esp -= 4;
    sub_4828cc(app, cpu);
    if (cpu.terminate) return;
    // 0047af8a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047af8c  7707                   -ja 0x47af95
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0047af95;
    }
L_0x0047af8e:
    // 0047af8e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047af90  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047af91  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 0047af94  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047af95:
    // 0047af95  a180d95100             -mov eax, dword ptr [0x51d980]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */);
    // 0047af9a  83c054                 -add eax, 0x54
    (cpu.eax) += x86::reg32(x86::sreg32(84 /*0x54*/));
    // 0047af9d  e81e780000             -call 0x4827c0
    cpu.esp -= 4;
    sub_4827c0(app, cpu);
    if (cpu.terminate) return;
    // 0047afa2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047afa4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047afa6  74e6                   -je 0x47af8e
    if (cpu.flags.zf)
    {
        goto L_0x0047af8e;
    }
L_0x0047afa8:
    // 0047afa8  8b5118                 -mov edx, dword ptr [ecx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 0047afab  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047afad  740a                   -je 0x47afb9
    if (cpu.flags.zf)
    {
        goto L_0x0047afb9;
    }
    // 0047afaf  a180d95100             -mov eax, dword ptr [0x51d980]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */);
    // 0047afb4  3b5014                 +cmp edx, dword ptr [eax + 0x14]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047afb7  752c                   -jne 0x47afe5
    if (!cpu.flags.zf)
    {
        goto L_0x0047afe5;
    }
L_0x0047afb9:
    // 0047afb9  a180d95100             -mov eax, dword ptr [0x51d980]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */);
    // 0047afbe  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047afc0  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
L_0x0047afc3:
    // 0047afc3  e838770000             -call 0x482700
    cpu.esp -= 4;
    sub_482700(app, cpu);
    if (cpu.terminate) return;
    // 0047afc8  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0047afcb  ff5124                 -call dword ptr [ecx + 0x24]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047afce  a180d95100             -mov eax, dword ptr [0x51d980]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */);
    // 0047afd3  83c054                 -add eax, 0x54
    (cpu.eax) += x86::reg32(x86::sreg32(84 /*0x54*/));
    // 0047afd6  e8e5770000             -call 0x4827c0
    cpu.esp -= 4;
    sub_4827c0(app, cpu);
    if (cpu.terminate) return;
    // 0047afdb  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047afdd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047afdf  75c7                   -jne 0x47afa8
    if (!cpu.flags.zf)
    {
        goto L_0x0047afa8;
    }
    // 0047afe1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047afe3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047afe4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047afe5:
    // 0047afe5  83c038                 +add eax, 0x38
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(56 /*0x38*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047afe8  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047afea  ebd7                   -jmp 0x47afc3
    goto L_0x0047afc3;
}

/* align: skip  */
void Application::sub_47afec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047afec  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047afed  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047afee  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047aff0  8b1580d95100           -mov edx, dword ptr [0x51d980]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */);
    // 0047aff6  8d3400                 -lea esi, [eax + eax]
    cpu.esi = x86::reg32(cpu.eax + cpu.eax * 1);
    // 0047aff9  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047affb  0f85dc000000           -jne 0x47b0dd
    if (!cpu.flags.zf)
    {
        goto L_0x0047b0dd;
    }
L_0x0047b001:
    // 0047b001  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 0047b008  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0047b00a  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0047b00d  8d888c000000           -lea ecx, [eax + 0x8c]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(140) /* 0x8c */);
    // 0047b013  b868ff4b00             -mov eax, 0x4bff68
    cpu.eax = 4980584 /*0x4bff68*/;
    // 0047b018  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047b01a  e809f2ffff             -call 0x47a228
    cpu.esp -= 4;
    sub_47a228(app, cpu);
    if (cpu.terminate) return;
    // 0047b01f  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047b021  a380d95100             -mov dword ptr [0x51d980], eax
    app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */) = cpu.eax;
    // 0047b026  e8715c0000             -call 0x480c9c
    cpu.esp -= 4;
    sub_480c9c(app, cpu);
    if (cpu.terminate) return;
    // 0047b02b  a180d95100             -mov eax, dword ptr [0x51d980]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */);
    // 0047b030  e847f6ffff             -call 0x47a67c
    cpu.esp -= 4;
    sub_47a67c(app, cpu);
    if (cpu.terminate) return;
    // 0047b035  8b0d80d95100           -mov ecx, dword ptr [0x51d980]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */);
    // 0047b03b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047b03d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047b03f  894114                 -mov dword ptr [ecx + 0x14], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0047b042  8d411c                 -lea eax, [ecx + 0x1c]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 0047b045  e862760000             -call 0x4826ac
    cpu.esp -= 4;
    sub_4826ac(app, cpu);
    if (cpu.terminate) return;
    // 0047b04a  a180d95100             -mov eax, dword ptr [0x51d980]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */);
    // 0047b04f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047b051  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047b053  83c038                 -add eax, 0x38
    (cpu.eax) += x86::reg32(x86::sreg32(56 /*0x38*/));
    // 0047b056  e851760000             -call 0x4826ac
    cpu.esp -= 4;
    sub_4826ac(app, cpu);
    if (cpu.terminate) return;
    // 0047b05b  a180d95100             -mov eax, dword ptr [0x51d980]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */);
    // 0047b060  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047b062  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047b064  83c054                 -add eax, 0x54
    (cpu.eax) += x86::reg32(x86::sreg32(84 /*0x54*/));
    // 0047b067  e840760000             -call 0x4826ac
    cpu.esp -= 4;
    sub_4826ac(app, cpu);
    if (cpu.terminate) return;
    // 0047b06c  a180d95100             -mov eax, dword ptr [0x51d980]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */);
    // 0047b071  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047b073  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047b075  83c070                 -add eax, 0x70
    (cpu.eax) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 0047b078  e82f760000             -call 0x4826ac
    cpu.esp -= 4;
    sub_4826ac(app, cpu);
    if (cpu.terminate) return;
    // 0047b07d  8b0d80d95100           -mov ecx, dword ptr [0x51d980]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */);
    // 0047b083  81c18c000000           -add ecx, 0x8c
    (cpu.ecx) += x86::reg32(x86::sreg32(140 /*0x8c*/));
L_0x0047b089:
    // 0047b089  a180d95100             -mov eax, dword ptr [0x51d980]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */);
    // 0047b08e  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047b090  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0047b093  e868760000             -call 0x482700
    cpu.esp -= 4;
    sub_482700(app, cpu);
    if (cpu.terminate) return;
    // 0047b098  83c128                 +add ecx, 0x28
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(40 /*0x28*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047b09b  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0047b09c  75eb                   -jne 0x47b089
    if (!cpu.flags.zf)
    {
        goto L_0x0047b089;
    }
    // 0047b09e  bb03000000             -mov ebx, 3
    cpu.ebx = 3 /*0x3*/;
    // 0047b0a3  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 0047b0a8  b87caf4700             -mov eax, 0x47af7c
    cpu.eax = 4697980 /*0x47af7c*/;
    // 0047b0ad  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 0047b0b2  e8a9eaffff             -call 0x479b60
    cpu.esp -= 4;
    sub_479b60(app, cpu);
    if (cpu.terminate) return;
    // 0047b0b7  6884d95100             -push 0x51d984
    app->getMemory<x86::reg32>(cpu.esp-4) = 5364100 /*0x51d984*/;
    cpu.esp -= 4;
    // 0047b0bc  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0047b0c1  b818b74700             -mov eax, 0x47b718
    cpu.eax = 4699928 /*0x47b718*/;
    // 0047b0c6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047b0c8  e893560000             -call 0x480760
    cpu.esp -= 4;
    sub_480760(app, cpu);
    if (cpu.terminate) return;
    // 0047b0cd  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047b0cf  a180d95100             -mov eax, dword ptr [0x51d980]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */);
    // 0047b0d4  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 0047b0d6  39d9                   +cmp ecx, ebx
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
    // 0047b0d8  740d                   -je 0x47b0e7
    if (cpu.flags.zf)
    {
        goto L_0x0047b0e7;
    }
    // 0047b0da  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b0db  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b0dc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047b0dd:
    // 0047b0dd  e81a000000             -call 0x47b0fc
    cpu.esp -= 4;
    sub_47b0fc(app, cpu);
    if (cpu.terminate) return;
    // 0047b0e2  e91affffff             -jmp 0x47b001
    goto L_0x0047b001;
L_0x0047b0e7:
    // 0047b0e7  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047b0e9  e82e570000             -call 0x48081c
    cpu.esp -= 4;
    sub_48081c(app, cpu);
    if (cpu.terminate) return;
    // 0047b0ee  a180d95100             -mov eax, dword ptr [0x51d980]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */);
    // 0047b0f3  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 0047b0f5  39d9                   +cmp ecx, ebx
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
    // 0047b0f7  74ee                   -je 0x47b0e7
    if (cpu.flags.zf)
    {
        goto L_0x0047b0e7;
    }
    // 0047b0f9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b0fa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b0fb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47b0fc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047b0fc  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047b0fd  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047b0fe  8b1580d95100           -mov edx, dword ptr [0x51d980]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */);
    // 0047b104  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047b106  7503                   -jne 0x47b10b
    if (!cpu.flags.zf)
    {
        goto L_0x0047b10b;
    }
    // 0047b108  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b109  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b10a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047b10b:
    // 0047b10b  c7420401000000         -mov dword ptr [edx + 4], 1
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = 1 /*0x1*/;
    // 0047b112  e819feffff             -call 0x47af30
    cpu.esp -= 4;
    sub_47af30(app, cpu);
    if (cpu.terminate) return;
    // 0047b117  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0047b119:
    // 0047b119  a180d95100             -mov eax, dword ptr [0x51d980]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */);
    // 0047b11e  3b10                   +cmp edx, dword ptr [eax]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047b120  7409                   -je 0x47b12b
    if (cpu.flags.zf)
    {
        goto L_0x0047b12b;
    }
    // 0047b122  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047b124  e8f3560000             -call 0x48081c
    cpu.esp -= 4;
    sub_48081c(app, cpu);
    if (cpu.terminate) return;
    // 0047b129  ebee                   -jmp 0x47b119
    goto L_0x0047b119;
L_0x0047b12b:
    // 0047b12b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047b12c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047b12d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047b12e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047b12f  83c070                 -add eax, 0x70
    (cpu.eax) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 0047b132  e845760000             -call 0x48277c
    cpu.esp -= 4;
    sub_48277c(app, cpu);
    if (cpu.terminate) return;
    // 0047b137  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047b139  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047b13b  743c                   -je 0x47b179
    if (cpu.flags.zf)
    {
        goto L_0x0047b179;
    }
L_0x0047b13d:
    // 0047b13d  8b5a1c                 -mov ebx, dword ptr [edx + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 0047b140  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047b142  7407                   -je 0x47b14b
    if (cpu.flags.zf)
    {
        goto L_0x0047b14b;
    }
    // 0047b144  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047b146  e841f5ffff             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
L_0x0047b14b:
    // 0047b14b  8b7218                 -mov esi, dword ptr [edx + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0047b14e  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047b150  7407                   -je 0x47b159
    if (cpu.flags.zf)
    {
        goto L_0x0047b159;
    }
    // 0047b152  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047b154  e85ff5ffff             -call 0x47a6b8
    cpu.esp -= 4;
    sub_47a6b8(app, cpu);
    if (cpu.terminate) return;
L_0x0047b159:
    // 0047b159  a180d95100             -mov eax, dword ptr [0x51d980]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */);
    // 0047b15e  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0047b161  e89a750000             -call 0x482700
    cpu.esp -= 4;
    sub_482700(app, cpu);
    if (cpu.terminate) return;
    // 0047b166  a180d95100             -mov eax, dword ptr [0x51d980]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */);
    // 0047b16b  83c070                 -add eax, 0x70
    (cpu.eax) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 0047b16e  e809760000             -call 0x48277c
    cpu.esp -= 4;
    sub_48277c(app, cpu);
    if (cpu.terminate) return;
    // 0047b173  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047b175  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047b177  75c4                   -jne 0x47b13d
    if (!cpu.flags.zf)
    {
        goto L_0x0047b13d;
    }
L_0x0047b179:
    // 0047b179  a180d95100             -mov eax, dword ptr [0x51d980]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */);
    // 0047b17e  83c038                 -add eax, 0x38
    (cpu.eax) += x86::reg32(x86::sreg32(56 /*0x38*/));
    // 0047b181  e8f6750000             -call 0x48277c
    cpu.esp -= 4;
    sub_48277c(app, cpu);
    if (cpu.terminate) return;
    // 0047b186  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047b188  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047b18a  743c                   -je 0x47b1c8
    if (cpu.flags.zf)
    {
        goto L_0x0047b1c8;
    }
L_0x0047b18c:
    // 0047b18c  8b7a1c                 -mov edi, dword ptr [edx + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 0047b18f  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0047b191  7407                   -je 0x47b19a
    if (cpu.flags.zf)
    {
        goto L_0x0047b19a;
    }
    // 0047b193  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0047b195  e8f2f4ffff             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
L_0x0047b19a:
    // 0047b19a  8b6a18                 -mov ebp, dword ptr [edx + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0047b19d  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0047b19f  7407                   -je 0x47b1a8
    if (cpu.flags.zf)
    {
        goto L_0x0047b1a8;
    }
    // 0047b1a1  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0047b1a3  e810f5ffff             -call 0x47a6b8
    cpu.esp -= 4;
    sub_47a6b8(app, cpu);
    if (cpu.terminate) return;
L_0x0047b1a8:
    // 0047b1a8  a180d95100             -mov eax, dword ptr [0x51d980]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */);
    // 0047b1ad  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0047b1b0  e84b750000             -call 0x482700
    cpu.esp -= 4;
    sub_482700(app, cpu);
    if (cpu.terminate) return;
    // 0047b1b5  a180d95100             -mov eax, dword ptr [0x51d980]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */);
    // 0047b1ba  83c038                 -add eax, 0x38
    (cpu.eax) += x86::reg32(x86::sreg32(56 /*0x38*/));
    // 0047b1bd  e8ba750000             -call 0x48277c
    cpu.esp -= 4;
    sub_48277c(app, cpu);
    if (cpu.terminate) return;
    // 0047b1c2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047b1c4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047b1c6  75c4                   -jne 0x47b18c
    if (!cpu.flags.zf)
    {
        goto L_0x0047b18c;
    }
L_0x0047b1c8:
    // 0047b1c8  a180d95100             -mov eax, dword ptr [0x51d980]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */);
    // 0047b1cd  83c054                 -add eax, 0x54
    (cpu.eax) += x86::reg32(x86::sreg32(84 /*0x54*/));
    // 0047b1d0  e8a7750000             -call 0x48277c
    cpu.esp -= 4;
    sub_48277c(app, cpu);
    if (cpu.terminate) return;
    // 0047b1d5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047b1d7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047b1d9  743c                   -je 0x47b217
    if (cpu.flags.zf)
    {
        goto L_0x0047b217;
    }
L_0x0047b1db:
    // 0047b1db  8b5a1c                 -mov ebx, dword ptr [edx + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 0047b1de  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047b1e0  7407                   -je 0x47b1e9
    if (cpu.flags.zf)
    {
        goto L_0x0047b1e9;
    }
    // 0047b1e2  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047b1e4  e8a3f4ffff             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
L_0x0047b1e9:
    // 0047b1e9  8b7218                 -mov esi, dword ptr [edx + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0047b1ec  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047b1ee  7407                   -je 0x47b1f7
    if (cpu.flags.zf)
    {
        goto L_0x0047b1f7;
    }
    // 0047b1f0  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047b1f2  e8c1f4ffff             -call 0x47a6b8
    cpu.esp -= 4;
    sub_47a6b8(app, cpu);
    if (cpu.terminate) return;
L_0x0047b1f7:
    // 0047b1f7  a180d95100             -mov eax, dword ptr [0x51d980]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */);
    // 0047b1fc  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0047b1ff  e8fc740000             -call 0x482700
    cpu.esp -= 4;
    sub_482700(app, cpu);
    if (cpu.terminate) return;
    // 0047b204  a180d95100             -mov eax, dword ptr [0x51d980]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */);
    // 0047b209  83c054                 -add eax, 0x54
    (cpu.eax) += x86::reg32(x86::sreg32(84 /*0x54*/));
    // 0047b20c  e86b750000             -call 0x48277c
    cpu.esp -= 4;
    sub_48277c(app, cpu);
    if (cpu.terminate) return;
    // 0047b211  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047b213  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047b215  75c4                   -jne 0x47b1db
    if (!cpu.flags.zf)
    {
        goto L_0x0047b1db;
    }
L_0x0047b217:
    // 0047b217  b87caf4700             -mov eax, 0x47af7c
    cpu.eax = 4697980 /*0x47af7c*/;
    // 0047b21c  e8d3e9ffff             -call 0x479bf4
    cpu.esp -= 4;
    sub_479bf4(app, cpu);
    if (cpu.terminate) return;
    // 0047b221  a180d95100             -mov eax, dword ptr [0x51d980]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */);
    // 0047b226  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0047b229  e8be740000             -call 0x4826ec
    cpu.esp -= 4;
    sub_4826ec(app, cpu);
    if (cpu.terminate) return;
    // 0047b22e  a180d95100             -mov eax, dword ptr [0x51d980]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */);
    // 0047b233  83c038                 -add eax, 0x38
    (cpu.eax) += x86::reg32(x86::sreg32(56 /*0x38*/));
    // 0047b236  e8b1740000             -call 0x4826ec
    cpu.esp -= 4;
    sub_4826ec(app, cpu);
    if (cpu.terminate) return;
    // 0047b23b  a180d95100             -mov eax, dword ptr [0x51d980]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */);
    // 0047b240  83c070                 -add eax, 0x70
    (cpu.eax) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 0047b243  e8a4740000             -call 0x4826ec
    cpu.esp -= 4;
    sub_4826ec(app, cpu);
    if (cpu.terminate) return;
    // 0047b248  a180d95100             -mov eax, dword ptr [0x51d980]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */);
    // 0047b24d  83c054                 -add eax, 0x54
    (cpu.eax) += x86::reg32(x86::sreg32(84 /*0x54*/));
    // 0047b250  e897740000             -call 0x4826ec
    cpu.esp -= 4;
    sub_4826ec(app, cpu);
    if (cpu.terminate) return;
    // 0047b255  a180d95100             -mov eax, dword ptr [0x51d980]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */);
    // 0047b25a  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0047b25d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047b25f  7407                   -je 0x47b268
    if (cpu.flags.zf)
    {
        goto L_0x0047b268;
    }
    // 0047b261  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047b263  e808200000             -call 0x47d270
    cpu.esp -= 4;
    sub_47d270(app, cpu);
    if (cpu.terminate) return;
L_0x0047b268:
    // 0047b268  a180d95100             -mov eax, dword ptr [0x51d980]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */);
    // 0047b26d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047b26f  e818f4ffff             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
    // 0047b274  890d80d95100           -mov dword ptr [0x51d980], ecx
    app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */) = cpu.ecx;
    // 0047b27a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b27b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b27c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b27d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b27e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b27f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b280  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47b284(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047b284  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047b285  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047b286  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047b288  a180d95100             -mov eax, dword ptr [0x51d980]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */);
    // 0047b28d  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0047b290  e8e7740000             -call 0x48277c
    cpu.esp -= 4;
    sub_48277c(app, cpu);
    if (cpu.terminate) return;
    // 0047b295  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0047b297  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047b299  7503                   -jne 0x47b29e
    if (!cpu.flags.zf)
    {
        goto L_0x0047b29e;
    }
    // 0047b29b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b29c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b29d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047b29e:
    // 0047b29e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047b29f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047b2a0  c7450800000000         -mov dword ptr [ebp + 8], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0047b2a7  c7450c00000000         -mov dword ptr [ebp + 0xc], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 0047b2ae  c7451000000000         -mov dword ptr [ebp + 0x10], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 0047b2b5  c7452001000000         -mov dword ptr [ebp + 0x20], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */) = 1 /*0x1*/;
    // 0047b2bc  c7451800000000         -mov dword ptr [ebp + 0x18], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 0047b2c3  895514                 -mov dword ptr [ebp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 0047b2c6  a164a74c00             -mov eax, dword ptr [0x4ca764]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023588) /* 0x4ca764 */);
    // 0047b2cb  895d24                 -mov dword ptr [ebp + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 0047b2ce  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 0047b2d0  894504                 -mov dword ptr [ebp + 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0047b2d3  40                     -inc eax
    (cpu.eax)++;
    // 0047b2d4  8b1d3ca44c00           -mov ebx, dword ptr [0x4ca43c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5022780) /* 0x4ca43c */);
    // 0047b2da  a364a74c00             -mov dword ptr [0x4ca764], eax
    app->getMemory<x86::reg32>(x86::reg32(5023588) /* 0x4ca764 */) = cpu.eax;
    // 0047b2df  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047b2e1  49                     -dec ecx
    (cpu.ecx)--;
    // 0047b2e2  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047b2e4  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0047b2e6  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0047b2e8  49                     -dec ecx
    (cpu.ecx)--;
    // 0047b2e9  b8a4ff4b00             -mov eax, 0x4bffa4
    cpu.eax = 4980644 /*0x4bffa4*/;
    // 0047b2ee  8d5101                 -lea edx, [ecx + 1]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 0047b2f1  e832efffff             -call 0x47a228
    cpu.esp -= 4;
    sub_47a228(app, cpu);
    if (cpu.terminate) return;
    // 0047b2f6  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0047b2f8  89451c                 -mov dword ptr [ebp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0047b2fb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0047b2fc:
    // 0047b2fc  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0047b2fe  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0047b300  3c00                   +cmp al, 0
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
    // 0047b302  7410                   -je 0x47b314
    if (cpu.flags.zf)
    {
        goto L_0x0047b314;
    }
    // 0047b304  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0047b307  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0047b30a  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0047b30d  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0047b310  3c00                   +cmp al, 0
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
    // 0047b312  75e8                   -jne 0x47b2fc
    if (!cpu.flags.zf)
    {
        goto L_0x0047b2fc;
    }
L_0x0047b314:
    // 0047b314  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b315  a180d95100             -mov eax, dword ptr [0x51d980]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */);
    // 0047b31a  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0047b31c  83c070                 -add eax, 0x70
    (cpu.eax) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 0047b31f  e8dc730000             -call 0x482700
    cpu.esp -= 4;
    sub_482700(app, cpu);
    if (cpu.terminate) return;
    // 0047b324  8b1580d95100           -mov edx, dword ptr [0x51d980]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */);
    // 0047b32a  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 0047b32c  b884d95100             -mov eax, 0x51d984
    cpu.eax = 5364100 /*0x51d984*/;
    // 0047b331  e86a570000             -call 0x480aa0
    cpu.esp -= 4;
    sub_480aa0(app, cpu);
    if (cpu.terminate) return;
    // 0047b336  8b4504                 -mov eax, dword ptr [ebp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0047b339  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b33a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b33b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b33c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b33d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47b340(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047b340  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047b341  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047b343  e83cffffff             -call 0x47b284
    cpu.esp -= 4;
    sub_47b284(app, cpu);
    if (cpu.terminate) return;
    // 0047b348  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b349  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47b34c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047b34c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047b34d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047b34e  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047b350  a180d95100             -mov eax, dword ptr [0x51d980]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */);
    // 0047b355  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0047b358  e81f740000             -call 0x48277c
    cpu.esp -= 4;
    sub_48277c(app, cpu);
    if (cpu.terminate) return;
    // 0047b35d  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0047b35f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047b361  7503                   -jne 0x47b366
    if (!cpu.flags.zf)
    {
        goto L_0x0047b366;
    }
    // 0047b363  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b364  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b365  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047b366:
    // 0047b366  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047b367  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047b368  c7450c00000000         -mov dword ptr [ebp + 0xc], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 0047b36f  c7451000000000         -mov dword ptr [ebp + 0x10], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 0047b376  c7452001000000         -mov dword ptr [ebp + 0x20], 1
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */) = 1 /*0x1*/;
    // 0047b37d  c7451800000000         -mov dword ptr [ebp + 0x18], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 0047b384  a164a74c00             -mov eax, dword ptr [0x4ca764]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023588) /* 0x4ca764 */);
    // 0047b389  895508                 -mov dword ptr [ebp + 8], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0047b38c  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 0047b38e  895d24                 -mov dword ptr [ebp + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 0047b391  8b153ca44c00           -mov edx, dword ptr [0x4ca43c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5022780) /* 0x4ca43c */);
    // 0047b397  894504                 -mov dword ptr [ebp + 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0047b39a  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0047b39c  40                     -inc eax
    (cpu.eax)++;
    // 0047b39d  895514                 -mov dword ptr [ebp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 0047b3a0  a364a74c00             -mov dword ptr [0x4ca764], eax
    app->getMemory<x86::reg32>(x86::reg32(5023588) /* 0x4ca764 */) = cpu.eax;
    // 0047b3a5  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047b3a7  49                     -dec ecx
    (cpu.ecx)--;
    // 0047b3a8  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047b3aa  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0047b3ac  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0047b3ae  49                     -dec ecx
    (cpu.ecx)--;
    // 0047b3af  b8a4ff4b00             -mov eax, 0x4bffa4
    cpu.eax = 4980644 /*0x4bffa4*/;
    // 0047b3b4  8d5101                 -lea edx, [ecx + 1]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 0047b3b7  e86ceeffff             -call 0x47a228
    cpu.esp -= 4;
    sub_47a228(app, cpu);
    if (cpu.terminate) return;
    // 0047b3bc  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0047b3be  89451c                 -mov dword ptr [ebp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0047b3c1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0047b3c2:
    // 0047b3c2  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0047b3c4  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0047b3c6  3c00                   +cmp al, 0
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
    // 0047b3c8  7410                   -je 0x47b3da
    if (cpu.flags.zf)
    {
        goto L_0x0047b3da;
    }
    // 0047b3ca  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0047b3cd  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0047b3d0  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0047b3d3  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0047b3d6  3c00                   +cmp al, 0
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
    // 0047b3d8  75e8                   -jne 0x47b3c2
    if (!cpu.flags.zf)
    {
        goto L_0x0047b3c2;
    }
L_0x0047b3da:
    // 0047b3da  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b3db  a180d95100             -mov eax, dword ptr [0x51d980]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */);
    // 0047b3e0  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0047b3e2  83c070                 -add eax, 0x70
    (cpu.eax) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 0047b3e5  e816730000             -call 0x482700
    cpu.esp -= 4;
    sub_482700(app, cpu);
    if (cpu.terminate) return;
    // 0047b3ea  8b1580d95100           -mov edx, dword ptr [0x51d980]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */);
    // 0047b3f0  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 0047b3f2  b884d95100             -mov eax, 0x51d984
    cpu.eax = 5364100 /*0x51d984*/;
    // 0047b3f7  e8a4560000             -call 0x480aa0
    cpu.esp -= 4;
    sub_480aa0(app, cpu);
    if (cpu.terminate) return;
    // 0047b3fc  8b4504                 -mov eax, dword ptr [ebp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0047b3ff  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b400  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b401  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b402  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b403  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47b404(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047b404  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047b405  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047b407  e840ffffff             -call 0x47b34c
    cpu.esp -= 4;
    sub_47b34c(app, cpu);
    if (cpu.terminate) return;
    // 0047b40c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b40d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47b410(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047b410  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047b411  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047b412  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047b415  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0047b417  a180d95100             -mov eax, dword ptr [0x51d980]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */);
    // 0047b41c  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0047b41f  e858730000             -call 0x48277c
    cpu.esp -= 4;
    sub_48277c(app, cpu);
    if (cpu.terminate) return;
    // 0047b424  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047b426  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0047b429  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047b42b  746d                   -je 0x47b49a
    if (cpu.flags.zf)
    {
        goto L_0x0047b49a;
    }
    // 0047b42d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047b42e  c7460800000000         -mov dword ptr [esi + 8], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0047b435  c7460c00000000         -mov dword ptr [esi + 0xc], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 0047b43c  c7461000000000         -mov dword ptr [esi + 0x10], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 0047b443  c7462002000000         -mov dword ptr [esi + 0x20], 2
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = 2 /*0x2*/;
    // 0047b44a  c7462400000000         -mov dword ptr [esi + 0x24], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 0047b451  a164a74c00             -mov eax, dword ptr [0x4ca764]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023588) /* 0x4ca764 */);
    // 0047b456  c7461800000000         -mov dword ptr [esi + 0x18], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 0047b45d  8b153ca44c00           -mov edx, dword ptr [0x4ca43c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5022780) /* 0x4ca43c */);
    // 0047b463  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0047b466  40                     -inc eax
    (cpu.eax)++;
    // 0047b467  895614                 -mov dword ptr [esi + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 0047b46a  a364a74c00             -mov dword ptr [0x4ca764], eax
    app->getMemory<x86::reg32>(x86::reg32(5023588) /* 0x4ca764 */) = cpu.eax;
    // 0047b46f  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0047b471  752d                   -jne 0x47b4a0
    if (!cpu.flags.zf)
    {
        goto L_0x0047b4a0;
    }
    // 0047b473  896e1c                 -mov dword ptr [esi + 0x1c], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.ebp;
L_0x0047b476:
    // 0047b476  a180d95100             -mov eax, dword ptr [0x51d980]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */);
    // 0047b47b  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047b47f  83c070                 -add eax, 0x70
    (cpu.eax) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 0047b482  e879720000             -call 0x482700
    cpu.esp -= 4;
    sub_482700(app, cpu);
    if (cpu.terminate) return;
    // 0047b487  8b1580d95100           -mov edx, dword ptr [0x51d980]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */);
    // 0047b48d  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 0047b48f  b884d95100             -mov eax, 0x51d984
    cpu.eax = 5364100 /*0x51d984*/;
    // 0047b494  e807560000             -call 0x480aa0
    cpu.esp -= 4;
    sub_480aa0(app, cpu);
    if (cpu.terminate) return;
    // 0047b499  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047b49a:
    // 0047b49a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047b49d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b49e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b49f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047b4a0:
    // 0047b4a0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047b4a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047b4a2  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047b4a3  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 0047b4a5  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0047b4a7  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047b4a9  49                     -dec ecx
    (cpu.ecx)--;
    // 0047b4aa  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047b4ac  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0047b4ae  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0047b4b0  49                     -dec ecx
    (cpu.ecx)--;
    // 0047b4b1  b8a4ff4b00             -mov eax, 0x4bffa4
    cpu.eax = 4980644 /*0x4bffa4*/;
    // 0047b4b6  8d5101                 -lea edx, [ecx + 1]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 0047b4b9  e86aedffff             -call 0x47a228
    cpu.esp -= 4;
    sub_47a228(app, cpu);
    if (cpu.terminate) return;
    // 0047b4be  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0047b4c0  89461c                 -mov dword ptr [esi + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0047b4c3  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
    // 0047b4c5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0047b4c6:
    // 0047b4c6  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0047b4c8  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0047b4ca  3c00                   +cmp al, 0
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
    // 0047b4cc  7410                   -je 0x47b4de
    if (cpu.flags.zf)
    {
        goto L_0x0047b4de;
    }
    // 0047b4ce  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0047b4d1  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0047b4d4  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0047b4d7  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0047b4da  3c00                   +cmp al, 0
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
    // 0047b4dc  75e8                   -jne 0x47b4c6
    if (!cpu.flags.zf)
    {
        goto L_0x0047b4c6;
    }
L_0x0047b4de:
    // 0047b4de  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b4df  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b4e0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b4e1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b4e2  eb92                   -jmp 0x47b476
    goto L_0x0047b476;
}

/* align: skip  */
void Application::sub_47b4e4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047b4e4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047b4e5  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047b4e7  e840faffff             -call 0x47af2c
    cpu.esp -= 4;
    sub_47af2c(app, cpu);
    if (cpu.terminate) return;
    // 0047b4ec  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b4ed  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47b4f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047b4f0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047b4f1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047b4f2  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047b4f5  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047b4f7  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0047b4fa  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0047b4fc  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047b4fe  a180d95100             -mov eax, dword ptr [0x51d980]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */);
    // 0047b503  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0047b506  e871720000             -call 0x48277c
    cpu.esp -= 4;
    sub_48277c(app, cpu);
    if (cpu.terminate) return;
    // 0047b50b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047b50d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047b50f  7506                   -jne 0x47b517
    if (!cpu.flags.zf)
    {
        goto L_0x0047b517;
    }
    // 0047b511  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047b514  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b515  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b516  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047b517:
    // 0047b517  a164a74c00             -mov eax, dword ptr [0x4ca764]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023588) /* 0x4ca764 */);
    // 0047b51c  894104                 -mov dword ptr [ecx + 4], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0047b51f  40                     -inc eax
    (cpu.eax)++;
    // 0047b520  8b1d80d95100           -mov ebx, dword ptr [0x51d980]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */);
    // 0047b526  a364a74c00             -mov dword ptr [0x4ca764], eax
    app->getMemory<x86::reg32>(x86::reg32(5023588) /* 0x4ca764 */) = cpu.eax;
    // 0047b52b  8b430c                 -mov eax, dword ptr [ebx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 0047b52e  c7412003000000         -mov dword ptr [ecx + 0x20], 3
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = 3 /*0x3*/;
    // 0047b535  c7411800000000         -mov dword ptr [ecx + 0x18], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 0047b53c  c7411c00000000         -mov dword ptr [ecx + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 0047b543  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0047b545  895124                 -mov dword ptr [ecx + 0x24], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 0047b548  89410c                 -mov dword ptr [ecx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0047b54b  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0047b54e  894108                 -mov dword ptr [ecx + 8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0047b551  a13ca44c00             -mov eax, dword ptr [0x4ca43c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5022780) /* 0x4ca43c */);
    // 0047b556  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047b558  894114                 -mov dword ptr [ecx + 0x14], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0047b55b  8d4370                 -lea eax, [ebx + 0x70]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(112) /* 0x70 */);
    // 0047b55e  897910                 -mov dword ptr [ecx + 0x10], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.edi;
    // 0047b561  e89a710000             -call 0x482700
    cpu.esp -= 4;
    sub_482700(app, cpu);
    if (cpu.terminate) return;
    // 0047b566  8b1580d95100           -mov edx, dword ptr [0x51d980]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */);
    // 0047b56c  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 0047b56e  b884d95100             -mov eax, 0x51d984
    cpu.eax = 5364100 /*0x51d984*/;
    // 0047b573  e828550000             -call 0x480aa0
    cpu.esp -= 4;
    sub_480aa0(app, cpu);
    if (cpu.terminate) return;
    // 0047b578  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0047b57b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047b57e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b57f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b580  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47b584(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047b584  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047b585  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047b587  e864ffffff             -call 0x47b4f0
    cpu.esp -= 4;
    sub_47b4f0(app, cpu);
    if (cpu.terminate) return;
    // 0047b58c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b58d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47b590(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047b590  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047b591  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0047b593  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0047b595  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047b597  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047b599  e852ffffff             -call 0x47b4f0
    cpu.esp -= 4;
    sub_47b4f0(app, cpu);
    if (cpu.terminate) return;
    // 0047b59e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b59f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47b5a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047b5a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047b5a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047b5a2  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0047b5a4  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047b5a6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047b5a8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047b5aa  e841ffffff             -call 0x47b4f0
    cpu.esp -= 4;
    sub_47b4f0(app, cpu);
    if (cpu.terminate) return;
    // 0047b5af  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b5b0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b5b1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47b5b4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047b5b4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047b5b5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047b5b6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047b5b7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047b5b8  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047b5ba  ba20af4700             -mov edx, 0x47af20
    cpu.edx = 4697888 /*0x47af20*/;
    // 0047b5bf  a180d95100             -mov eax, dword ptr [0x51d980]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */);
    // 0047b5c4  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0047b5c6  83c070                 -add eax, 0x70
    (cpu.eax) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 0047b5c9  e8c2740000             -call 0x482a90
    cpu.esp -= 4;
    sub_482a90(app, cpu);
    if (cpu.terminate) return;
    // 0047b5ce  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047b5d0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047b5d2  7438                   -je 0x47b60c
    if (cpu.flags.zf)
    {
        goto L_0x0047b60c;
    }
    // 0047b5d4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047b5d5  8b7020                 -mov esi, dword ptr [eax + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0047b5d8  83fe01                 +cmp esi, 1
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
    // 0047b5db  7528                   -jne 0x47b605
    if (!cpu.flags.zf)
    {
        goto L_0x0047b605;
    }
L_0x0047b5dd:
    // 0047b5dd  8b6a1c                 -mov ebp, dword ptr [edx + 0x1c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 0047b5e0  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0047b5e2  740e                   -je 0x47b5f2
    if (cpu.flags.zf)
    {
        goto L_0x0047b5f2;
    }
    // 0047b5e4  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0047b5e6  e8a1f0ffff             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
    // 0047b5eb  c7421c00000000         -mov dword ptr [edx + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
L_0x0047b5f2:
    // 0047b5f2  a180d95100             -mov eax, dword ptr [0x51d980]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */);
    // 0047b5f7  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0047b5fa  e801710000             -call 0x482700
    cpu.esp -= 4;
    sub_482700(app, cpu);
    if (cpu.terminate) return;
    // 0047b5ff  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047b600:
    // 0047b600  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b601  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b602  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b603  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b604  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047b605:
    // 0047b605  83fe02                 +cmp esi, 2
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
    // 0047b608  74d3                   -je 0x47b5dd
    if (cpu.flags.zf)
    {
        goto L_0x0047b5dd;
    }
    // 0047b60a  ebe6                   -jmp 0x47b5f2
    goto L_0x0047b5f2;
L_0x0047b60c:
    // 0047b60c  e81ff9ffff             -call 0x47af30
    cpu.esp -= 4;
    sub_47af30(app, cpu);
    if (cpu.terminate) return;
    // 0047b611  ba20af4700             -mov edx, 0x47af20
    cpu.edx = 4697888 /*0x47af20*/;
    // 0047b616  a180d95100             -mov eax, dword ptr [0x51d980]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */);
    // 0047b61b  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0047b61d  83c038                 -add eax, 0x38
    (cpu.eax) += x86::reg32(x86::sreg32(56 /*0x38*/));
    // 0047b620  e86b740000             -call 0x482a90
    cpu.esp -= 4;
    sub_482a90(app, cpu);
    if (cpu.terminate) return;
    // 0047b625  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047b627  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047b629  7516                   -jne 0x47b641
    if (!cpu.flags.zf)
    {
        goto L_0x0047b641;
    }
    // 0047b62b  ba20af4700             -mov edx, 0x47af20
    cpu.edx = 4697888 /*0x47af20*/;
    // 0047b630  a180d95100             -mov eax, dword ptr [0x51d980]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */);
    // 0047b635  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0047b637  83c054                 -add eax, 0x54
    (cpu.eax) += x86::reg32(x86::sreg32(84 /*0x54*/));
    // 0047b63a  e851740000             -call 0x482a90
    cpu.esp -= 4;
    sub_482a90(app, cpu);
    if (cpu.terminate) return;
    // 0047b63f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x0047b641:
    // 0047b641  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047b643  74bb                   -je 0x47b600
    if (cpu.flags.zf)
    {
        goto L_0x0047b600;
    }
    // 0047b645  8b4a18                 -mov ecx, dword ptr [edx + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0047b648  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047b64a  7411                   -je 0x47b65d
    if (cpu.flags.zf)
    {
        goto L_0x0047b65d;
    }
    // 0047b64c  a180d95100             -mov eax, dword ptr [0x51d980]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */);
    // 0047b651  3b4814                 +cmp ecx, dword ptr [eax + 0x14]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047b654  7407                   -je 0x47b65d
    if (cpu.flags.zf)
    {
        goto L_0x0047b65d;
    }
    // 0047b656  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047b658  e85bf0ffff             -call 0x47a6b8
    cpu.esp -= 4;
    sub_47a6b8(app, cpu);
    if (cpu.terminate) return;
L_0x0047b65d:
    // 0047b65d  a180d95100             -mov eax, dword ptr [0x51d980]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */);
    // 0047b662  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0047b665  c7421800000000         -mov dword ptr [edx + 0x18], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 0047b66c  e88f700000             -call 0x482700
    cpu.esp -= 4;
    sub_482700(app, cpu);
    if (cpu.terminate) return;
    // 0047b671  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b672  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b673  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b674  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b675  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47b678(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047b678  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047b679  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047b67a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047b67b  8b0d80d95100           -mov ecx, dword ptr [0x51d980]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */);
    // 0047b681  ba20af4700             -mov edx, 0x47af20
    cpu.edx = 4697888 /*0x47af20*/;
    // 0047b686  83c138                 -add ecx, 0x38
    (cpu.ecx) += x86::reg32(x86::sreg32(56 /*0x38*/));
    // 0047b689  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047b68b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047b68d  e8fe730000             -call 0x482a90
    cpu.esp -= 4;
    sub_482a90(app, cpu);
    if (cpu.terminate) return;
    // 0047b692  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047b694  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047b696  7506                   -jne 0x47b69e
    if (!cpu.flags.zf)
    {
        goto L_0x0047b69e;
    }
L_0x0047b698:
    // 0047b698  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047b69a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b69b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b69c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b69d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047b69e:
    // 0047b69e  a180d95100             -mov eax, dword ptr [0x51d980]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */);
    // 0047b6a3  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047b6a5  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0047b6a8  e853700000             -call 0x482700
    cpu.esp -= 4;
    sub_482700(app, cpu);
    if (cpu.terminate) return;
    // 0047b6ad  83792000               +cmp dword ptr [ecx + 0x20], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047b6b1  74e5                   -je 0x47b698
    if (cpu.flags.zf)
    {
        goto L_0x0047b698;
    }
    // 0047b6b3  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 0047b6b6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b6b7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b6b8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b6b9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47b6bc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047b6bc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047b6bd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047b6be  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047b6bf  8b0d80d95100           -mov ecx, dword ptr [0x51d980]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */);
    // 0047b6c5  ba20af4700             -mov edx, 0x47af20
    cpu.edx = 4697888 /*0x47af20*/;
    // 0047b6ca  83c138                 -add ecx, 0x38
    (cpu.ecx) += x86::reg32(x86::sreg32(56 /*0x38*/));
    // 0047b6cd  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047b6cf  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047b6d1  e8ba730000             -call 0x482a90
    cpu.esp -= 4;
    sub_482a90(app, cpu);
    if (cpu.terminate) return;
    // 0047b6d6  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047b6d8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047b6da  7504                   -jne 0x47b6e0
    if (!cpu.flags.zf)
    {
        goto L_0x0047b6e0;
    }
    // 0047b6dc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b6dd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b6de  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b6df  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047b6e0:
    // 0047b6e0  a180d95100             -mov eax, dword ptr [0x51d980]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */);
    // 0047b6e5  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047b6e7  83c01c                 -add eax, 0x1c
    (cpu.eax) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 0047b6ea  e811700000             -call 0x482700
    cpu.esp -= 4;
    sub_482700(app, cpu);
    if (cpu.terminate) return;
    // 0047b6ef  83792000               +cmp dword ptr [ecx + 0x20], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047b6f3  7409                   -je 0x47b6fe
    if (cpu.flags.zf)
    {
        goto L_0x0047b6fe;
    }
    // 0047b6f5  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047b6fa  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b6fb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b6fc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b6fd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047b6fe:
    // 0047b6fe  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0047b703  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b704  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b705  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b706  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_47b718(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0047b718  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047b719  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047b71a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047b71b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047b71c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047b71d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047b71e  81ec08010000           -sub esp, 0x108
    (cpu.esp) -= x86::reg32(x86::sreg32(264 /*0x108*/));
    // 0047b724  e863530000             -call 0x480a8c
    cpu.esp -= 4;
    sub_480a8c(app, cpu);
    if (cpu.terminate) return;
    // 0047b729  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047b72b  a180d95100             -mov eax, dword ptr [0x51d980]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */);
    // 0047b730  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0047b732  c7401800000000         -mov dword ptr [eax + 0x18], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 0047b739  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
L_0x0047b740:
    // 0047b740  a180d95100             -mov eax, dword ptr [0x51d980]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */);
    // 0047b745  83780400               +cmp dword ptr [eax + 4], 0
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
    // 0047b749  743d                   -je 0x47b788
    if (cpu.flags.zf)
    {
        goto L_0x0047b788;
    }
    // 0047b74b  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0047b74e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047b750  0f85b0030000           -jne 0x47bb06
    if (!cpu.flags.zf)
    {
        goto L_0x0047bb06;
    }
L_0x0047b756:
    // 0047b756  a180d95100             -mov eax, dword ptr [0x51d980]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */);
    // 0047b75b  c7400800000000         -mov dword ptr [eax + 8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0047b762  c7401800000000         -mov dword ptr [eax + 0x18], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 0047b769  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0047b76b  e8f8530000             -call 0x480b68
    cpu.esp -= 4;
    sub_480b68(app, cpu);
    if (cpu.terminate) return;
    // 0047b770  a180d95100             -mov eax, dword ptr [0x51d980]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */);
    // 0047b775  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 0047b77b  81c408010000           -add esp, 0x108
    (cpu.esp) += x86::reg32(x86::sreg32(264 /*0x108*/));
    // 0047b781  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b782  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b783  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b784  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b785  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b786  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b787  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047b788:
    // 0047b788  83c070                 -add eax, 0x70
    (cpu.eax) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 0047b78b  e830700000             -call 0x4827c0
    cpu.esp -= 4;
    sub_4827c0(app, cpu);
    if (cpu.terminate) return;
    // 0047b790  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0047b792  89842404010000         -mov dword ptr [esp + 0x104], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */) = cpu.eax;
    // 0047b799  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047b79b  0f8454030000           -je 0x47baf5
    if (cpu.flags.zf)
    {
        goto L_0x0047baf5;
    }
    // 0047b7a1  a180d95100             -mov eax, dword ptr [0x51d980]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */);
    // 0047b7a6  896818                 -mov dword ptr [eax + 0x18], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ebp;
    // 0047b7a9  8b5520                 -mov edx, dword ptr [ebp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 0047b7ac  4a                     -dec edx
    (cpu.edx)--;
    // 0047b7ad  83fa03                 +cmp edx, 3
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
    // 0047b7b0  760e                   -jbe 0x47b7c0
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0047b7c0;
    }
    // 0047b7b2  a180d95100             -mov eax, dword ptr [0x51d980]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */);
    // 0047b7b7  c7401800000000         -mov dword ptr [eax + 0x18], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 0047b7be  eb80                   -jmp 0x47b740
    goto L_0x0047b740;
L_0x0047b7c0:
    // 0047b7c0  ff249508b74700         -jmp dword ptr [edx*4 + 0x47b708]
    cpu.ip = app->getMemory<x86::reg32>(4699912 + cpu.edx * 4); goto dynamic_jump;
  case 0x0047b7c7:
    // 0047b7c7  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0047b7c9  8b751c                 -mov esi, dword ptr [ebp + 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 0047b7cc  8d942400010000         -lea edx, [esp + 0x100]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 0047b7d3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0047b7d4:
    // 0047b7d4  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0047b7d6  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0047b7d8  3c00                   +cmp al, 0
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
    // 0047b7da  7410                   -je 0x47b7ec
    if (cpu.flags.zf)
    {
        goto L_0x0047b7ec;
    }
    // 0047b7dc  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0047b7df  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0047b7e2  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0047b7e5  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0047b7e8  3c00                   +cmp al, 0
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
    // 0047b7ea  75e8                   -jne 0x47b7d4
    if (!cpu.flags.zf)
    {
        goto L_0x0047b7d4;
    }
L_0x0047b7ec:
    // 0047b7ec  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047b7ed  8b451c                 -mov eax, dword ptr [ebp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    // 0047b7f0  8d4d10                 -lea ecx, [ebp + 0x10]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0047b7f3  e894eeffff             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
    // 0047b7f8  8d5d0c                 -lea ebx, [ebp + 0xc]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0047b7fb  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0047b7fd  c7451c00000000         -mov dword ptr [ebp + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 0047b804  e8cb180000             -call 0x47d0d4
    cpu.esp -= 4;
    sub_47d0d4(app, cpu);
    if (cpu.terminate) return;
    // 0047b809  c7451800000000         -mov dword ptr [ebp + 0x18], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 0047b810  8b8c2400010000         -mov ecx, dword ptr [esp + 0x100]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 0047b817  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047b819  0f8435010000           -je 0x47b954
    if (cpu.flags.zf)
    {
        goto L_0x0047b954;
    }
    // 0047b81f  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0047b822  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047b824  b9c2010000             -mov ecx, 0x1c2
    cpu.ecx = 450 /*0x1c2*/;
    // 0047b829  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0047b82c  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0047b82e  8b5d08                 -mov ebx, dword ptr [ebp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047b831  8d8890010000           -lea ecx, [eax + 0x190]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(400) /* 0x190 */);
    // 0047b837  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047b839  0f8505010000           -jne 0x47b944
    if (!cpu.flags.zf)
    {
        goto L_0x0047b944;
    }
    // 0047b83f  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0047b841  8b5d14                 -mov ebx, dword ptr [ebp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0047b844  8b5510                 -mov edx, dword ptr [ebp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0047b847  e8c0e9ffff             -call 0x47a20c
    cpu.esp -= 4;
    sub_47a20c(app, cpu);
    if (cpu.terminate) return;
    // 0047b84c  894518                 -mov dword ptr [ebp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0047b84f  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0047b851  894508                 -mov dword ptr [ebp + 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.eax;
L_0x0047b854:
    // 0047b854  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047b856  e85dd20100             -call 0x498ab8
    cpu.esp -= 4;
    sub_498ab8(app, cpu);
    if (cpu.terminate) return;
    // 0047b85b  e82cd30100             -call 0x498b8c
    cpu.esp -= 4;
    sub_498b8c(app, cpu);
    if (cpu.terminate) return;
    // 0047b860  8b842400010000         -mov eax, dword ptr [esp + 0x100]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 0047b867  8b942404010000         -mov edx, dword ptr [esp + 0x104]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 0047b86e  e88dcafcff             -call 0x448300
    cpu.esp -= 4;
    sub_448300(app, cpu);
    if (cpu.terminate) return;
    // 0047b873  8b842400010000         -mov eax, dword ptr [esp + 0x100]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 0047b87a  8b520c                 -mov edx, dword ptr [edx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0047b87d  8b9c2404010000         -mov ebx, dword ptr [esp + 0x104]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 0047b884  e8ff190000             -call 0x47d288
    cpu.esp -= 4;
    sub_47d288(app, cpu);
    if (cpu.terminate) return;
    // 0047b889  8b942404010000         -mov edx, dword ptr [esp + 0x104]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 0047b890  8b842400010000         -mov eax, dword ptr [esp + 0x100]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 0047b897  8b5b10                 -mov ebx, dword ptr [ebx + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 0047b89a  8b5208                 -mov edx, dword ptr [edx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0047b89d  e8d6190000             -call 0x47d278
    cpu.esp -= 4;
    sub_47d278(app, cpu);
    if (cpu.terminate) return;
    // 0047b8a2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047b8a4  750e                   -jne 0x47b8b4
    if (!cpu.flags.zf)
    {
        goto L_0x0047b8b4;
    }
    // 0047b8a6  8b842404010000         -mov eax, dword ptr [esp + 0x104]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 0047b8ad  c7402000000000         -mov dword ptr [eax + 0x20], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
L_0x0047b8b4:
    // 0047b8b4  8b842400010000         -mov eax, dword ptr [esp + 0x100]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 0047b8bb  e800cafcff             -call 0x4482c0
    cpu.esp -= 4;
    sub_4482c0(app, cpu);
    if (cpu.terminate) return;
    // 0047b8c0  8b842400010000         -mov eax, dword ptr [esp + 0x100]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 0047b8c7  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0047b8c9  e8a2190000             -call 0x47d270
    cpu.esp -= 4;
    sub_47d270(app, cpu);
    if (cpu.terminate) return;
    // 0047b8ce  8b842404010000         -mov eax, dword ptr [esp + 0x104]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 0047b8d5  89b42400010000         -mov dword ptr [esp + 0x100], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */) = cpu.esi;
    // 0047b8dc  83782000               +cmp dword ptr [eax + 0x20], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047b8e0  7530                   -jne 0x47b912
    if (!cpu.flags.zf)
    {
        goto L_0x0047b912;
    }
    // 0047b8e2  8b942404010000         -mov edx, dword ptr [esp + 0x104]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 0047b8e9  a180d95100             -mov eax, dword ptr [0x51d980]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */);
    // 0047b8ee  8b5218                 -mov edx, dword ptr [edx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0047b8f1  3b5014                 +cmp edx, dword ptr [eax + 0x14]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047b8f4  741c                   -je 0x47b912
    if (cpu.flags.zf)
    {
        goto L_0x0047b912;
    }
    // 0047b8f6  8b842404010000         -mov eax, dword ptr [esp + 0x104]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 0047b8fd  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0047b900  e8b3edffff             -call 0x47a6b8
    cpu.esp -= 4;
    sub_47a6b8(app, cpu);
    if (cpu.terminate) return;
    // 0047b905  8b842404010000         -mov eax, dword ptr [esp + 0x104]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 0047b90c  897018                 -mov dword ptr [eax + 0x18], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 0047b90f  897008                 -mov dword ptr [eax + 8], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.esi;
L_0x0047b912:
    // 0047b912  8b842404010000         -mov eax, dword ptr [esp + 0x104]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 0047b919  83782400               +cmp dword ptr [eax + 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047b91d  743a                   -je 0x47b959
    if (cpu.flags.zf)
    {
        goto L_0x0047b959;
    }
    // 0047b91f  a180d95100             -mov eax, dword ptr [0x51d980]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */);
    // 0047b924  8b942404010000         -mov edx, dword ptr [esp + 0x104]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 0047b92b  83c054                 +add eax, 0x54
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(84 /*0x54*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047b92e  e8cd6d0000             -call 0x482700
    cpu.esp -= 4;
    sub_482700(app, cpu);
    if (cpu.terminate) return;
    // 0047b933  a180d95100             -mov eax, dword ptr [0x51d980]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */);
    // 0047b938  c7401800000000         -mov dword ptr [eax + 0x18], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 0047b93f  e9fcfdffff             -jmp 0x47b740
    goto L_0x0047b740;
L_0x0047b944:
    // 0047b944  a180d95100             -mov eax, dword ptr [0x51d980]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */);
    // 0047b949  8b4014                 -mov eax, dword ptr [eax + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 0047b94c  894518                 -mov dword ptr [ebp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0047b94f  e900ffffff             -jmp 0x47b854
    goto L_0x0047b854;
L_0x0047b954:
    // 0047b954  894d08                 -mov dword ptr [ebp + 8], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0047b957  ebb9                   -jmp 0x47b912
    goto L_0x0047b912;
L_0x0047b959:
    // 0047b959  a180d95100             -mov eax, dword ptr [0x51d980]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */);
    // 0047b95e  8b942404010000         -mov edx, dword ptr [esp + 0x104]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 0047b965  83c038                 +add eax, 0x38
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(56 /*0x38*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047b968  e8936d0000             -call 0x482700
    cpu.esp -= 4;
    sub_482700(app, cpu);
    if (cpu.terminate) return;
    // 0047b96d  a180d95100             -mov eax, dword ptr [0x51d980]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */);
    // 0047b972  c7401800000000         -mov dword ptr [eax + 0x18], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 0047b979  e9c2fdffff             -jmp 0x47b740
    goto L_0x0047b740;
  case 0x0047b97e:
    // 0047b97e  8b6808                 -mov ebp, dword ptr [eax + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0047b981  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0047b983  7407                   -je 0x47b98c
    if (cpu.flags.zf)
    {
        goto L_0x0047b98c;
    }
    // 0047b985  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0047b987  e8e4180000             -call 0x47d270
    cpu.esp -= 4;
    sub_47d270(app, cpu);
    if (cpu.terminate) return;
L_0x0047b98c:
    // 0047b98c  a180d95100             -mov eax, dword ptr [0x51d980]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */);
    // 0047b991  c7400800000000         -mov dword ptr [eax + 8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 0047b998  8b842404010000         -mov eax, dword ptr [esp + 0x104]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 0047b99f  83781c00               +cmp dword ptr [eax + 0x1c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047b9a3  7449                   -je 0x47b9ee
    if (cpu.flags.zf)
    {
        goto L_0x0047b9ee;
    }
    // 0047b9a5  b890010000             -mov eax, 0x190
    cpu.eax = 400 /*0x190*/;
    // 0047b9aa  e809d10100             -call 0x498ab8
    cpu.esp -= 4;
    sub_498ab8(app, cpu);
    if (cpu.terminate) return;
    // 0047b9af  e8d8d10100             -call 0x498b8c
    cpu.esp -= 4;
    sub_498b8c(app, cpu);
    if (cpu.terminate) return;
    // 0047b9b4  a180d95100             -mov eax, dword ptr [0x51d980]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */);
    // 0047b9b9  8d4810                 -lea ecx, [eax + 0x10]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0047b9bc  8d580c                 -lea ebx, [eax + 0xc]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0047b9bf  8d5008                 -lea edx, [eax + 8]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0047b9c2  8b842404010000         -mov eax, dword ptr [esp + 0x104]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 0047b9c9  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0047b9cc  e80b170000             -call 0x47d0dc
    cpu.esp -= 4;
    sub_47d0dc(app, cpu);
    if (cpu.terminate) return;
    // 0047b9d1  8b842404010000         -mov eax, dword ptr [esp + 0x104]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 0047b9d8  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0047b9db  e8acecffff             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
    // 0047b9e0  8b842404010000         -mov eax, dword ptr [esp + 0x104]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 0047b9e7  c7401c00000000         -mov dword ptr [eax + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
L_0x0047b9ee:
    // 0047b9ee  a180d95100             -mov eax, dword ptr [0x51d980]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */);
    // 0047b9f3  8b942404010000         -mov edx, dword ptr [esp + 0x104]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 0047b9fa  83c01c                 +add eax, 0x1c
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(28 /*0x1c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047b9fd  e8fe6c0000             -call 0x482700
    cpu.esp -= 4;
    sub_482700(app, cpu);
    if (cpu.terminate) return;
    // 0047ba02  a180d95100             -mov eax, dword ptr [0x51d980]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */);
    // 0047ba07  c7401800000000         -mov dword ptr [eax + 0x18], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 0047ba0e  e92dfdffff             -jmp 0x47b740
    goto L_0x0047b740;
  case 0x0047ba13:
    // 0047ba13  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0047ba16  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047ba18  0f8498000000           -je 0x47bab6
    if (cpu.flags.zf)
    {
        goto L_0x0047bab6;
    }
    // 0047ba1e  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0047ba21  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047ba23  b9c2010000             -mov ecx, 0x1c2
    cpu.ecx = 450 /*0x1c2*/;
    // 0047ba28  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0047ba2b  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0047ba2d  0590010000             -add eax, 0x190
    (cpu.eax) += x86::reg32(x86::sreg32(400 /*0x190*/));
    // 0047ba32  e881d00100             -call 0x498ab8
    cpu.esp -= 4;
    sub_498ab8(app, cpu);
    if (cpu.terminate) return;
    // 0047ba37  e850d10100             -call 0x498b8c
    cpu.esp -= 4;
    sub_498b8c(app, cpu);
    if (cpu.terminate) return;
    // 0047ba3c  a180d95100             -mov eax, dword ptr [0x51d980]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */);
    // 0047ba41  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0047ba44  e8b7c8fcff             -call 0x448300
    cpu.esp -= 4;
    sub_448300(app, cpu);
    if (cpu.terminate) return;
    // 0047ba49  a180d95100             -mov eax, dword ptr [0x51d980]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */);
    // 0047ba4e  8b550c                 -mov edx, dword ptr [ebp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0047ba51  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0047ba54  e82f180000             -call 0x47d288
    cpu.esp -= 4;
    sub_47d288(app, cpu);
    if (cpu.terminate) return;
    // 0047ba59  a180d95100             -mov eax, dword ptr [0x51d980]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */);
    // 0047ba5e  8b5d10                 -mov ebx, dword ptr [ebp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 0047ba61  8b5508                 -mov edx, dword ptr [ebp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 0047ba64  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0047ba67  e80c180000             -call 0x47d278
    cpu.esp -= 4;
    sub_47d278(app, cpu);
    if (cpu.terminate) return;
    // 0047ba6c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047ba6e  7503                   -jne 0x47ba73
    if (!cpu.flags.zf)
    {
        goto L_0x0047ba73;
    }
    // 0047ba70  894520                 -mov dword ptr [ebp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */) = cpu.eax;
L_0x0047ba73:
    // 0047ba73  a180d95100             -mov eax, dword ptr [0x51d980]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */);
    // 0047ba78  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0047ba7b  e840c8fcff             -call 0x4482c0
    cpu.esp -= 4;
    sub_4482c0(app, cpu);
    if (cpu.terminate) return;
L_0x0047ba80:
    // 0047ba80  8b842404010000         -mov eax, dword ptr [esp + 0x104]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 0047ba87  83782400               +cmp dword ptr [eax + 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047ba8b  0f84c8feffff           -je 0x47b959
    if (cpu.flags.zf)
    {
        goto L_0x0047b959;
    }
    // 0047ba91  a180d95100             -mov eax, dword ptr [0x51d980]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */);
    // 0047ba96  8b942404010000         -mov edx, dword ptr [esp + 0x104]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 0047ba9d  83c054                 +add eax, 0x54
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(84 /*0x54*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047baa0  e85b6c0000             -call 0x482700
    cpu.esp -= 4;
    sub_482700(app, cpu);
    if (cpu.terminate) return;
    // 0047baa5  a180d95100             -mov eax, dword ptr [0x51d980]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */);
    // 0047baaa  c7401800000000         -mov dword ptr [eax + 0x18], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 0047bab1  e98afcffff             -jmp 0x47b740
    goto L_0x0047b740;
L_0x0047bab6:
    // 0047bab6  897520                 -mov dword ptr [ebp + 0x20], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 0047bab9  ebc5                   -jmp 0x47ba80
    goto L_0x0047ba80;
  case 0x0047babb:
    // 0047babb  8b5808                 -mov ebx, dword ptr [eax + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0047babe  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047bac0  7407                   -je 0x47bac9
    if (cpu.flags.zf)
    {
        goto L_0x0047bac9;
    }
    // 0047bac2  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047bac4  e8a7170000             -call 0x47d270
    cpu.esp -= 4;
    sub_47d270(app, cpu);
    if (cpu.terminate) return;
L_0x0047bac9:
    // 0047bac9  a180d95100             -mov eax, dword ptr [0x51d980]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */);
    // 0047bace  83c01c                 +add eax, 0x1c
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(28 /*0x1c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047bad1  8b942404010000         -mov edx, dword ptr [esp + 0x104]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 0047bad8  c740ec00000000         -mov dword ptr [eax - 0x14], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-20) /* -0x14 */) = 0 /*0x0*/;
    // 0047badf  e81c6c0000             -call 0x482700
    cpu.esp -= 4;
    sub_482700(app, cpu);
    if (cpu.terminate) return;
    // 0047bae4  a180d95100             -mov eax, dword ptr [0x51d980]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */);
    // 0047bae9  c7401800000000         -mov dword ptr [eax + 0x18], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 0047baf0  e94bfcffff             -jmp 0x47b740
    goto L_0x0047b740;
L_0x0047baf5:
    // 0047baf5  a180d95100             -mov eax, dword ptr [0x51d980]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364096) /* 0x51d980 */);
    // 0047bafa  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0047bafc  e8db4f0000             -call 0x480adc
    cpu.esp -= 4;
    sub_480adc(app, cpu);
    if (cpu.terminate) return;
    // 0047bb01  e93afcffff             -jmp 0x47b740
    goto L_0x0047b740;
L_0x0047bb06:
    // 0047bb06  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047bb08  e863170000             -call 0x47d270
    cpu.esp -= 4;
    sub_47d270(app, cpu);
    if (cpu.terminate) return;
    // 0047bb0d  e944fcffff             -jmp 0x47b756
    goto L_0x0047b756;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47bb20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047bb20  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047bb21  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047bb23  803db0cd4c0000         +cmp byte ptr [0x4ccdb0], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5033392) /* 0x4ccdb0 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047bb2a  7507                   -jne 0x47bb33
    if (!cpu.flags.zf)
    {
        goto L_0x0047bb33;
    }
    // 0047bb2c  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 0047bb31  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bb32  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047bb33:
    // 0047bb33  e878d20100             -call 0x498db0
    cpu.esp -= 4;
    sub_498db0(app, cpu);
    if (cpu.terminate) return;
    // 0047bb38  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047bb3a  e87dd60100             -call 0x4991bc
    cpu.esp -= 4;
    sub_4991bc(app, cpu);
    if (cpu.terminate) return;
    // 0047bb3f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047bb41  7c0b                   -jl 0x47bb4e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047bb4e;
    }
    // 0047bb43  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047bb45  e87ad20100             -call 0x498dc4
    cpu.esp -= 4;
    sub_498dc4(app, cpu);
    if (cpu.terminate) return;
    // 0047bb4a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047bb4c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bb4d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047bb4e:
    // 0047bb4e  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0047bb53  e86cd20100             -call 0x498dc4
    cpu.esp -= 4;
    sub_498dc4(app, cpu);
    if (cpu.terminate) return;
    // 0047bb58  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047bb5a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bb5b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_47bb60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047bb60  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047bb61  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047bb62  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047bb63  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047bb65  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0047bb67  803db0cd4c0000         +cmp byte ptr [0x4ccdb0], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5033392) /* 0x4ccdb0 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047bb6e  7415                   -je 0x47bb85
    if (cpu.flags.zf)
    {
        goto L_0x0047bb85;
    }
    // 0047bb70  83fb7f                 +cmp ebx, 0x7f
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(127 /*0x7f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047bb73  7f05                   -jg 0x47bb7a
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0047bb7a;
    }
    // 0047bb75  83fbff                 +cmp ebx, -1
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
    // 0047bb78  7d12                   -jge 0x47bb8c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047bb8c;
    }
L_0x0047bb7a:
    // 0047bb7a  baf8ffffff             -mov edx, 0xfffffff8
    cpu.edx = 4294967288 /*0xfffffff8*/;
L_0x0047bb7f:
    // 0047bb7f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047bb81  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bb82  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bb83  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bb84  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047bb85:
    // 0047bb85  baf6ffffff             -mov edx, 0xfffffff6
    cpu.edx = 4294967286 /*0xfffffff6*/;
    // 0047bb8a  ebf3                   -jmp 0x47bb7f
    goto L_0x0047bb7f;
L_0x0047bb8c:
    // 0047bb8c  e81fd20100             -call 0x498db0
    cpu.esp -= 4;
    sub_498db0(app, cpu);
    if (cpu.terminate) return;
    // 0047bb91  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047bb93  e824d60100             -call 0x4991bc
    cpu.esp -= 4;
    sub_4991bc(app, cpu);
    if (cpu.terminate) return;
    // 0047bb98  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047bb9a  0f8c6d000000           -jl 0x47bc0d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047bc0d;
    }
    // 0047bba0  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 0047bba7  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0047bba9  b9d0a75200             -mov ecx, 0x52a7d0
    cpu.ecx = 5416912 /*0x52a7d0*/;
    // 0047bbae  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 0047bbb1  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0047bbb3  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047bbb5  7e66                   -jle 0x47bc1d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047bc1d;
    }
L_0x0047bbb7:
    // 0047bbb7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047bbb8  0fb6793b               -movzx edi, byte ptr [ecx + 0x3b]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(59) /* 0x3b */));
    // 0047bbbc  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0047bbbe  7464                   -je 0x47bc24
    if (cpu.flags.zf)
    {
        goto L_0x0047bc24;
    }
    // 0047bbc0  b9d0a75200             -mov ecx, 0x52a7d0
    cpu.ecx = 5416912 /*0x52a7d0*/;
    // 0047bbc5  8da900060000           -lea ebp, [ecx + 0x600]
    cpu.ebp = x86::reg32(cpu.ecx + x86::reg32(1536) /* 0x600 */);
L_0x0047bbcb:
    // 0047bbcb  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047bbcd  8a513b                 -mov dl, byte ptr [ecx + 0x3b]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(59) /* 0x3b */);
    // 0047bbd0  39fa                   +cmp edx, edi
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
    // 0047bbd2  7524                   -jne 0x47bbf8
    if (!cpu.flags.zf)
    {
        goto L_0x0047bbf8;
    }
    // 0047bbd4  80790c01               +cmp byte ptr [ecx + 0xc], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047bbd8  751e                   -jne 0x47bbf8
    if (!cpu.flags.zf)
    {
        goto L_0x0047bbf8;
    }
    // 0047bbda  833900                 +cmp dword ptr [ecx], 0
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
    // 0047bbdd  7c19                   -jl 0x47bbf8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047bbf8;
    }
    // 0047bbdf  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047bbe1  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0047bbe4  89411c                 -mov dword ptr [ecx + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0047bbe7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047bbe9  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 0047bbec  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0047bbee  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047bbf0  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0047bbf3  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0047bbf5  894118                 -mov dword ptr [ecx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = cpu.eax;
L_0x0047bbf8:
    // 0047bbf8  83c160                 -add ecx, 0x60
    (cpu.ecx) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 0047bbfb  39e9                   +cmp ecx, ebp
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
    // 0047bbfd  75cc                   -jne 0x47bbcb
    if (!cpu.flags.zf)
    {
        goto L_0x0047bbcb;
    }
    // 0047bbff  e8c0d10100             -call 0x498dc4
    cpu.esp -= 4;
    sub_498dc4(app, cpu);
    if (cpu.terminate) return;
    // 0047bc04  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0047bc06  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bc07  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047bc09  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bc0a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bc0b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bc0c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047bc0d:
    // 0047bc0d  e8b2d10100             -call 0x498dc4
    cpu.esp -= 4;
    sub_498dc4(app, cpu);
    if (cpu.terminate) return;
    // 0047bc12  baf8ffffff             -mov edx, 0xfffffff8
    cpu.edx = 4294967288 /*0xfffffff8*/;
    // 0047bc17  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047bc19  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bc1a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bc1b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bc1c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047bc1d:
    // 0047bc1d  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0047bc22  eb93                   -jmp 0x47bbb7
    goto L_0x0047bbb7;
L_0x0047bc24:
    // 0047bc24  c1e310                 -shl ebx, 0x10
    cpu.ebx <<= 16 /*0x10*/ % 32;
    // 0047bc27  89591c                 -mov dword ptr [ecx + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 0047bc2a  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0047bc2c  8b5920                 -mov ebx, dword ptr [ecx + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 0047bc2f  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047bc31  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047bc33  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0047bc36  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0047bc38  894118                 -mov dword ptr [ecx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0047bc3b  e884d10100             -call 0x498dc4
    cpu.esp -= 4;
    sub_498dc4(app, cpu);
    if (cpu.terminate) return;
    // 0047bc40  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047bc42  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bc43  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047bc45  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bc46  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bc47  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bc48  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47bc50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047bc50  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047bc51  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047bc52  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047bc53  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047bc54  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047bc55  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047bc56  81ec1c0c0000           -sub esp, 0xc1c
    (cpu.esp) -= x86::reg32(x86::sreg32(3100 /*0xc1c*/));
    // 0047bc5c  898424100c0000         -mov dword ptr [esp + 0xc10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3088) /* 0xc10 */) = cpu.eax;
    // 0047bc63  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 0047bc68  b907000000             -mov ecx, 7
    cpu.ecx = 7 /*0x7*/;
    // 0047bc6d  b880000000             -mov eax, 0x80
    cpu.eax = 128 /*0x80*/;
    // 0047bc72  beffffffff             -mov esi, 0xffffffff
    cpu.esi = 4294967295 /*0xffffffff*/;
    // 0047bc77  899424140c0000         -mov dword ptr [esp + 0xc14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3092) /* 0xc14 */) = cpu.edx;
    // 0047bc7e  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0047bc80  898c24080c0000         -mov dword ptr [esp + 0xc08], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3080) /* 0xc08 */) = cpu.ecx;
    // 0047bc87  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0047bc89:
    // 0047bc89  83c10c                 -add ecx, 0xc
    (cpu.ecx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047bc8c  89740cf4               -mov dword ptr [esp + ecx - 0xc], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(-12) /* -0xc */ + cpu.ecx * 1) = cpu.esi;
    // 0047bc90  81f9000c0000           +cmp ecx, 0xc00
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3072 /*0xc00*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047bc96  75f1                   -jne 0x47bc89
    if (!cpu.flags.zf)
    {
        goto L_0x0047bc89;
    }
    // 0047bc98  8bb424100c0000         -mov esi, dword ptr [esp + 0xc10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3088) /* 0xc10 */);
    // 0047bc9f  8b34f5d0ad5200         -mov esi, dword ptr [esi*8 + 0x52add0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5418448) /* 0x52add0 */ + cpu.esi * 8);
    // 0047bca6  807e0401               +cmp byte ptr [esi + 4], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047bcaa  7206                   -jb 0x47bcb2
    if (cpu.flags.cf)
    {
        goto L_0x0047bcb2;
    }
    // 0047bcac  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047bcae  668b4606               -mov ax, word ptr [esi + 6]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */);
L_0x0047bcb2:
    // 0047bcb2  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0047bcb4  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 0047bcb6  89bc24180c0000         -mov dword ptr [esp + 0xc18], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3096) /* 0xc18 */) = cpu.edi;
    // 0047bcbd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047bcbf  0f8ea6000000           -jle 0x47bd6b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047bd6b;
    }
    // 0047bcc5  8b9424100c0000         -mov edx, dword ptr [esp + 0xc10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3088) /* 0xc10 */);
    // 0047bccc  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0047bccf  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 0047bcd2  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047bcd4  899424000c0000         -mov dword ptr [esp + 0xc00], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3072) /* 0xc00 */) = cpu.edx;
    // 0047bcdb  8d5608                 -lea edx, [esi + 8]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0047bcde  8984240c0c0000         -mov dword ptr [esp + 0xc0c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3084) /* 0xc0c */) = cpu.eax;
    // 0047bce5  899424040c0000         -mov dword ptr [esp + 0xc04], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3076) /* 0xc04 */) = cpu.edx;
    // 0047bcec  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
L_0x0047bcee:
    // 0047bcee  807e0402               +cmp byte ptr [esi + 4], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047bcf2  0f82b8000000           -jb 0x47bdb0
    if (cpu.flags.cf)
    {
        goto L_0x0047bdb0;
    }
    // 0047bcf8  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 0047bcfa  8b470c                 -mov eax, dword ptr [edi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
L_0x0047bcfd:
    // 0047bcfd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047bcff  744a                   -je 0x47bd4b
    if (cpu.flags.zf)
    {
        goto L_0x0047bd4b;
    }
    // 0047bd01  807e0402               +cmp byte ptr [esi + 4], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047bd05  0f82ad000000           -jb 0x47bdb8
    if (cpu.flags.cf)
    {
        goto L_0x0047bdb8;
    }
    // 0047bd0b  8d0429                 -lea eax, [ecx + ebp]
    cpu.eax = x86::reg32(cpu.ecx + cpu.ebp * 1);
    // 0047bd0e  8d550c                 -lea edx, [ebp + 0xc]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 0047bd11  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0047bd14  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0047bd16  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0047bd18  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
L_0x0047bd1b:
    // 0047bd1b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047bd1d  8b9424000c0000         -mov edx, dword ptr [esp + 0xc00]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3072) /* 0xc00 */);
    // 0047bd24  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0047bd26  8b92d4ad5200           -mov edx, dword ptr [edx + 0x52add4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5418452) /* 0x52add4 */);
    // 0047bd2c  e83fc90100             -call 0x498670
    cpu.esp -= 4;
    sub_498670(app, cpu);
    if (cpu.terminate) return;
    // 0047bd31  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047bd33  83f807                 +cmp eax, 7
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
    // 0047bd36  740b                   -je 0x47bd43
    if (cpu.flags.zf)
    {
        goto L_0x0047bd43;
    }
    // 0047bd38  c78424080c000008000000 -mov dword ptr [esp + 0xc08], 8
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3080) /* 0xc08 */) = 8 /*0x8*/;
L_0x0047bd43:
    // 0047bd43  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047bd45  0f8c86000000           -jl 0x47bdd1
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047bdd1;
    }
L_0x0047bd4b:
    // 0047bd4b  8b8424180c0000         -mov eax, dword ptr [esp + 0xc18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3096) /* 0xc18 */);
    // 0047bd52  8b94240c0c0000         -mov edx, dword ptr [esp + 0xc0c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3084) /* 0xc0c */);
    // 0047bd59  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047bd5c  40                     -inc eax
    (cpu.eax)++;
    // 0047bd5d  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047bd60  898424180c0000         -mov dword ptr [esp + 0xc18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3096) /* 0xc18 */) = cpu.eax;
    // 0047bd67  39d1                   +cmp ecx, edx
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
    // 0047bd69  7c83                   -jl 0x47bcee
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047bcee;
    }
L_0x0047bd6b:
    // 0047bd6b  8b9424140c0000         -mov edx, dword ptr [esp + 0xc14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3092) /* 0xc14 */);
    // 0047bd72  83faff                 +cmp edx, -1
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
    // 0047bd75  7e21                   -jle 0x47bd98
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047bd98;
    }
    // 0047bd77  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047bd79  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047bd7b  7c1b                   -jl 0x47bd98
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047bd98;
    }
    // 0047bd7d  8bbc24140c0000         -mov edi, dword ptr [esp + 0xc14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3092) /* 0xc14 */);
L_0x0047bd84:
    // 0047bd84  8b8424100c0000         -mov eax, dword ptr [esp + 0xc10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3088) /* 0xc10 */);
    // 0047bd8b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047bd8d  41                     -inc ecx
    (cpu.ecx)++;
    // 0047bd8e  e88dc70100             -call 0x498520
    cpu.esp -= 4;
    sub_498520(app, cpu);
    if (cpu.terminate) return;
    // 0047bd93  39f9                   +cmp ecx, edi
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
    // 0047bd95  7eed                   -jle 0x47bd84
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047bd84;
    }
    // 0047bd97  90                     -nop 
    ;
L_0x0047bd98:
    // 0047bd98  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047bd9a  7c46                   -jl 0x47bde2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047bde2;
    }
    // 0047bd9c  8b8424080c0000         -mov eax, dword ptr [esp + 0xc08]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3080) /* 0xc08 */);
    // 0047bda3  81c41c0c0000           +add esp, 0xc1c
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3100 /*0xc1c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047bda9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bdaa  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bdab  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bdac  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bdad  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bdae  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bdaf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047bdb0:
    // 0047bdb0  8b4708                 -mov eax, dword ptr [edi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0047bdb3  e945ffffff             -jmp 0x47bcfd
    goto L_0x0047bcfd;
L_0x0047bdb8:
    // 0047bdb8  8d040e                 -lea eax, [esi + ecx]
    cpu.eax = x86::reg32(cpu.esi + cpu.ecx * 1);
    // 0047bdbb  8b9424040c0000         -mov edx, dword ptr [esp + 0xc04]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3076) /* 0xc04 */);
    // 0047bdc2  8b5808                 -mov ebx, dword ptr [eax + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0047bdc5  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0047bdc7  01da                   +add edx, ebx
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047bdc9  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0047bdcc  e94affffff             -jmp 0x47bd1b
    goto L_0x0047bd1b;
L_0x0047bdd1:
    // 0047bdd1  8b8424180c0000         -mov eax, dword ptr [esp + 0xc18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3096) /* 0xc18 */);
    // 0047bdd8  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0047bdd9  898424140c0000         -mov dword ptr [esp + 0xc14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(3092) /* 0xc14 */) = cpu.eax;
    // 0047bde0  eb89                   -jmp 0x47bd6b
    goto L_0x0047bd6b;
L_0x0047bde2:
    // 0047bde2  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047bde4  81c41c0c0000           -add esp, 0xc1c
    (cpu.esp) += x86::reg32(x86::sreg32(3100 /*0xc1c*/));
    // 0047bdea  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bdeb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bdec  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bded  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bdee  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bdef  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bdf0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47bdf4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047bdf4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047bdf6  7c0f                   -jl 0x47be07
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047be07;
    }
    // 0047bdf8  83f80a                 +cmp eax, 0xa
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
    // 0047bdfb  7d0a                   -jge 0x47be07
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047be07;
    }
    // 0047bdfd  833cc5d0ad520000       +cmp dword ptr [eax*8 + 0x52add0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5418448) /* 0x52add0 */ + cpu.eax * 8);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047be05  7506                   -jne 0x47be0d
    if (!cpu.flags.zf)
    {
        goto L_0x0047be0d;
    }
L_0x0047be07:
    // 0047be07  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 0047be0c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047be0d:
    // 0047be0d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047be0f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47be10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047be10  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047be11  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047be12  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047be13  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047be14  81ec000c0000           -sub esp, 0xc00
    (cpu.esp) -= x86::reg32(x86::sreg32(3072 /*0xc00*/));
    // 0047be1a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047be1c  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0047be1e  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 0047be23  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0047be25:
    // 0047be25  83c10c                 -add ecx, 0xc
    (cpu.ecx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047be28  89540cf4               -mov dword ptr [esp + ecx - 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(-12) /* -0xc */ + cpu.ecx * 1) = cpu.edx;
    // 0047be2c  81f9000c0000           +cmp ecx, 0xc00
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3072 /*0xc00*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047be32  75f1                   -jne 0x47be25
    if (!cpu.flags.zf)
    {
        goto L_0x0047be25;
    }
    // 0047be34  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047be36  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0047be38  7e12                   -jle 0x47be4c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047be4c;
    }
L_0x0047be3a:
    // 0047be3a  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0047be3c  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047be3e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047be40  41                     -inc ecx
    (cpu.ecx)++;
    // 0047be41  e8cac40100             -call 0x498310
    cpu.esp -= 4;
    sub_498310(app, cpu);
    if (cpu.terminate) return;
    // 0047be46  39f9                   +cmp ecx, edi
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
    // 0047be48  7cf0                   -jl 0x47be3a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047be3a;
    }
    // 0047be4a  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x0047be4c:
    // 0047be4c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047be4e  81c4000c0000           -add esp, 0xc00
    (cpu.esp) += x86::reg32(x86::sreg32(3072 /*0xc00*/));
    // 0047be54  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047be55  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047be56  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047be57  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047be58  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47be5c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047be5c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047be5d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047be5e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047be5f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047be60  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047be62  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047be64  8a15b0cd4c00           -mov dl, byte ptr [0x4ccdb0]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5033392) /* 0x4ccdb0 */);
    // 0047be6a  bff7ffffff             -mov edi, 0xfffffff7
    cpu.edi = 4294967287 /*0xfffffff7*/;
    // 0047be6f  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 0047be71  7449                   -je 0x47bebc
    if (cpu.flags.zf)
    {
        goto L_0x0047bebc;
    }
    // 0047be73  8138424e4b6c           +cmp dword ptr [eax], 0x6c4b4e42
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1816874562 /*0x6c4b4e42*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047be79  754b                   -jne 0x47bec6
    if (!cpu.flags.zf)
    {
        goto L_0x0047bec6;
    }
    // 0047be7b  bad0ad5200             -mov edx, 0x52add0
    cpu.edx = 5418448 /*0x52add0*/;
    // 0047be80  8b2dd0ad5200           -mov ebp, dword ptr [0x52add0]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5418448) /* 0x52add0 */);
    // 0047be86  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047be88  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0047be8a  740e                   -je 0x47be9a
    if (cpu.flags.zf)
    {
        goto L_0x0047be9a;
    }
L_0x0047be8c:
    // 0047be8c  41                     -inc ecx
    (cpu.ecx)++;
    // 0047be8d  83c208                 -add edx, 8
    (cpu.edx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0047be90  83f90a                 +cmp ecx, 0xa
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
    // 0047be93  7d46                   -jge 0x47bedb
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047bedb;
    }
    // 0047be95  833a00                 +cmp dword ptr [edx], 0
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
    // 0047be98  75f2                   -jne 0x47be8c
    if (!cpu.flags.zf)
    {
        goto L_0x0047be8c;
    }
L_0x0047be9a:
    // 0047be9a  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 0047be9c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047be9e  895a04                 -mov dword ptr [edx + 4], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0047bea1  e8aafdffff             -call 0x47bc50
    cpu.esp -= 4;
    sub_47bc50(app, cpu);
    if (cpu.terminate) return;
    // 0047bea6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047bea8  7c26                   -jl 0x47bed0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047bed0;
    }
    // 0047beaa  bae4be4700             -mov edx, 0x47bee4
    cpu.edx = 4701924 /*0x47bee4*/;
    // 0047beaf  890e                   -mov dword ptr [esi], ecx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ecx;
    // 0047beb1  8915c8cd4c00           -mov dword ptr [0x4ccdc8], edx
    app->getMemory<x86::reg32>(x86::reg32(5033416) /* 0x4ccdc8 */) = cpu.edx;
    // 0047beb7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047beb8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047beb9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047beba  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bebb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047bebc:
    // 0047bebc  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 0047bec1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bec2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bec3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bec4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bec5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047bec6:
    // 0047bec6  b8f9ffffff             -mov eax, 0xfffffff9
    cpu.eax = 4294967289 /*0xfffffff9*/;
    // 0047becb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047becc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047becd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bece  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047becf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047bed0:
    // 0047bed0  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 0047bed6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bed7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bed8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bed9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047beda  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047bedb:
    // 0047bedb  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0047bedd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bede  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bedf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bee0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bee1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47bee4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047bee4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047bee5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047bee6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047bee7  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047bee9  8a25b0cd4c00           -mov ah, byte ptr [0x4ccdb0]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5033392) /* 0x4ccdb0 */);
    // 0047beef  be80000000             -mov esi, 0x80
    cpu.esi = 128 /*0x80*/;
    // 0047bef4  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 0047bef6  741a                   -je 0x47bf12
    if (cpu.flags.zf)
    {
        goto L_0x0047bf12;
    }
    // 0047bef8  83f9ff                 +cmp ecx, -1
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
    // 0047befb  751e                   -jne 0x47bf1b
    if (!cpu.flags.zf)
    {
        goto L_0x0047bf1b;
    }
    // 0047befd  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0047beff:
    // 0047beff  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047bf01  42                     -inc edx
    (cpu.edx)++;
    // 0047bf02  e8ddffffff             -call 0x47bee4
    cpu.esp -= 4;
    sub_47bee4(app, cpu);
    if (cpu.terminate) return;
    // 0047bf07  83fa0a                 +cmp edx, 0xa
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
    // 0047bf0a  7cf3                   -jl 0x47beff
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047beff;
    }
    // 0047bf0c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047bf0e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bf0f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bf10  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bf11  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047bf12:
    // 0047bf12  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 0047bf17  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bf18  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bf19  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bf1a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047bf1b:
    // 0047bf1b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047bf1d  e8d2feffff             -call 0x47bdf4
    cpu.esp -= 4;
    sub_47bdf4(app, cpu);
    if (cpu.terminate) return;
    // 0047bf22  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047bf24  7550                   -jne 0x47bf76
    if (!cpu.flags.zf)
    {
        goto L_0x0047bf76;
    }
    // 0047bf26  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047bf27  bad0a75200             -mov edx, 0x52a7d0
    cpu.edx = 5416912 /*0x52a7d0*/;
    // 0047bf2c  8d9a00060000           -lea ebx, [edx + 0x600]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(1536) /* 0x600 */);
L_0x0047bf32:
    // 0047bf32  8b4207                 -mov eax, dword ptr [edx + 7]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(7) /* 0x7 */);
    // 0047bf35  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 0047bf38  39c8                   +cmp eax, ecx
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
    // 0047bf3a  7507                   -jne 0x47bf43
    if (!cpu.flags.zf)
    {
        goto L_0x0047bf43;
    }
    // 0047bf3c  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0047bf3e  e87d450000             -call 0x4804c0
    cpu.esp -= 4;
    sub_4804c0(app, cpu);
    if (cpu.terminate) return;
L_0x0047bf43:
    // 0047bf43  83c260                 -add edx, 0x60
    (cpu.edx) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 0047bf46  39da                   +cmp edx, ebx
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
    // 0047bf48  75e8                   -jne 0x47bf32
    if (!cpu.flags.zf)
    {
        goto L_0x0047bf32;
    }
    // 0047bf4a  8b04cdd0ad5200         -mov eax, dword ptr [ecx*8 + 0x52add0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5418448) /* 0x52add0 */ + cpu.ecx * 8);
    // 0047bf51  80780401               +cmp byte ptr [eax + 4], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047bf55  7206                   -jb 0x47bf5d
    if (cpu.flags.cf)
    {
        goto L_0x0047bf5d;
    }
    // 0047bf57  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0047bf59  668b7006               -mov si, word ptr [eax + 6]
    cpu.si = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(6) /* 0x6 */);
L_0x0047bf5d:
    // 0047bf5d  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0047bf5f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047bf61  e8aafeffff             -call 0x47be10
    cpu.esp -= 4;
    sub_47be10(app, cpu);
    if (cpu.terminate) return;
    // 0047bf66  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047bf68  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047bf6a  8914cdd0ad5200         -mov dword ptr [ecx*8 + 0x52add0], edx
    app->getMemory<x86::reg32>(x86::reg32(5418448) /* 0x52add0 */ + cpu.ecx * 8) = cpu.edx;
    // 0047bf71  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bf72  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bf73  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bf74  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bf75  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047bf76:
    // 0047bf76  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 0047bf7b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bf7c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bf7d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bf7e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_47bf80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047bf80  803db0cd4c0000         +cmp byte ptr [0x4ccdb0], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5033392) /* 0x4ccdb0 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047bf87  740f                   -je 0x47bf98
    if (cpu.flags.zf)
    {
        goto L_0x0047bf98;
    }
    // 0047bf89  83fa7f                 +cmp edx, 0x7f
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
    // 0047bf8c  7f04                   -jg 0x47bf92
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0047bf92;
    }
    // 0047bf8e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047bf90  7d0c                   -jge 0x47bf9e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047bf9e;
    }
L_0x0047bf92:
    // 0047bf92  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 0047bf97  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047bf98:
    // 0047bf98  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 0047bf9d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047bf9e:
    // 0047bf9e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047bf9f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047bfa0  881572c34c00           -mov byte ptr [0x4cc372], dl
    app->getMemory<x86::reg8>(x86::reg32(5030770) /* 0x4cc372 */) = cpu.dl;
    // 0047bfa6  8b0d00c34c00           -mov ecx, dword ptr [0x4cc300]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5030656) /* 0x4cc300 */);
    // 0047bfac  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0047bfae  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047bfb0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047bfb2  e8a9fbffff             -call 0x47bb60
    cpu.esp -= 4;
    sub_47bb60(app, cpu);
    if (cpu.terminate) return;
    // 0047bfb7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047bfb9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bfba  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bfbb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47bfbc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047bfbc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047bfbd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047bfbe  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047bfc0  eb0b                   -jmp 0x47bfcd
    goto L_0x0047bfcd;
L_0x0047bfc2:
    // 0047bfc2  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 0047bfc4  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 0047bfc6  7409                   -je 0x47bfd1
    if (cpu.flags.zf)
    {
        goto L_0x0047bfd1;
    }
    // 0047bfc8  42                     -inc edx
    (cpu.edx)++;
    // 0047bfc9  4b                     -dec ebx
    (cpu.ebx)--;
    // 0047bfca  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 0047bfcc  40                     -inc eax
    (cpu.eax)++;
L_0x0047bfcd:
    // 0047bfcd  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047bfcf  75f1                   -jne 0x47bfc2
    if (!cpu.flags.zf)
    {
        goto L_0x0047bfc2;
    }
L_0x0047bfd1:
    // 0047bfd1  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047bfd3  7407                   -je 0x47bfdc
    if (cpu.flags.zf)
    {
        goto L_0x0047bfdc;
    }
    // 0047bfd5  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0047bfd6  c60000                 -mov byte ptr [eax], 0
    app->getMemory<x86::reg8>(cpu.eax) = 0 /*0x0*/;
    // 0047bfd9  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0047bfda  ebf5                   -jmp 0x47bfd1
    goto L_0x0047bfd1;
L_0x0047bfdc:
    // 0047bfdc  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047bfde  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bfdf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047bfe0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47bfe1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047bfe1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047bfe2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047bfe3  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047bfe6  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0047bfea  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0047bfec  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0047bff0  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0047bff3  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0047bff7  e8daba0100             -call 0x497ad6
    cpu.esp -= 4;
    sub_497ad6(app, cpu);
    if (cpu.terminate) return;
    // 0047bffc  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047bfff  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c000  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c001  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47c002(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047c002  83f861                 +cmp eax, 0x61
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
    // 0047c005  7c08                   -jl 0x47c00f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047c00f;
    }
    // 0047c007  83f87a                 +cmp eax, 0x7a
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(122 /*0x7a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047c00a  7f03                   -jg 0x47c00f
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0047c00f;
    }
    // 0047c00c  83e820                 -sub eax, 0x20
    (cpu.eax) -= x86::reg32(x86::sreg32(32 /*0x20*/));
L_0x0047c00f:
    // 0047c00f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47c010(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047c010  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047c011  9b                     -wait 
    /*nothing*/;
    // 0047c012  d93c24                 -fnstcw word ptr [esp]
    app->getMemory<x86::reg16>(cpu.esp) = cpu.fpu.control.word;
    // 0047c015  9b                     -wait 
    /*nothing*/;
    // 0047c016  ff3424                 -push dword ptr [esp]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp -= 4;
    // 0047c019  c64424011f             -mov byte ptr [esp + 1], 0x1f
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */) = 31 /*0x1f*/;
    // 0047c01e  d92c24                 -fldcw word ptr [esp]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp);
    // 0047c021  d9fc                   -frndint 
    cpu.fpu.st(0) = cpu.fpu.rndint();
    // 0047c023  d96c2404               -fldcw word ptr [esp + 4]
    cpu.fpu.control.word = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047c027  9b                     -wait 
    /*nothing*/;
    // 0047c028  8d642408               -lea esp, [esp + 8]
    cpu.esp = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047c02c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_47c030(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047c030  0fb68070a74c00         -movzx eax, byte ptr [eax + 0x4ca770]
    cpu.eax = x86::reg32(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5023600) /* 0x4ca770 */));
    // 0047c037  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47c040(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047c040  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047c041  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047c042  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047c043  83ec34                 -sub esp, 0x34
    (cpu.esp) -= x86::reg32(x86::sreg32(52 /*0x34*/));
    // 0047c046  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047c048  8b1d38ca4c00           -mov ebx, dword ptr [0x4cca38]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5032504) /* 0x4cca38 */);
    // 0047c04e  890dbcca4c00           -mov dword ptr [0x4ccabc], ecx
    app->getMemory<x86::reg32>(x86::reg32(5032636) /* 0x4ccabc */) = cpu.ecx;
    // 0047c054  39d8                   +cmp eax, ebx
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
    // 0047c056  750c                   -jne 0x47c064
    if (!cpu.flags.zf)
    {
        goto L_0x0047c064;
    }
    // 0047c058  3b153cca4c00           +cmp edx, dword ptr [0x4cca3c]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5032508) /* 0x4cca3c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047c05e  0f8439010000           -je 0x47c19d
    if (cpu.flags.zf)
    {
        goto L_0x0047c19d;
    }
L_0x0047c064:
    // 0047c064  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047c065  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047c066  a338ca4c00             -mov dword ptr [0x4cca38], eax
    app->getMemory<x86::reg32>(x86::reg32(5032504) /* 0x4cca38 */) = cpu.eax;
    // 0047c06b  89153cca4c00           -mov dword ptr [0x4cca3c], edx
    app->getMemory<x86::reg32>(x86::reg32(5032508) /* 0x4cca3c */) = cpu.edx;
    // 0047c071  e82aa00100             -call 0x4960a0
    cpu.esp -= 4;
    sub_4960a0(app, cpu);
    if (cpu.terminate) return;
    // 0047c076  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047c078  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 0047c07b  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0047c081  894c2424               -mov dword ptr [esp + 0x24], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ecx;
    // 0047c085  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047c087  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0047c08c  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0047c090  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047c092  e809a00100             -call 0x4960a0
    cpu.esp -= 4;
    sub_4960a0(app, cpu);
    if (cpu.terminate) return;
    // 0047c097  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047c099  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0047c09b  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 0047c09e  897c2438               -mov dword ptr [esp + 0x38], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.edi;
    // 0047c0a2  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0047c0a8  897c2434               -mov dword ptr [esp + 0x34], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.edi;
    // 0047c0ac  8954242c               -mov dword ptr [esp + 0x2c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.edx;
    // 0047c0b0  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047c0b2  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0047c0b7  c1ea08                 -shr edx, 8
    cpu.edx >>= 8 /*0x8*/ % 32;
    // 0047c0ba  89442430               -mov dword ptr [esp + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 0047c0be  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0047c0c2  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0047c0c8  8d348500000000         -lea esi, [eax*4]
    cpu.esi = x86::reg32(cpu.eax * 4);
    // 0047c0cf  89542428               -mov dword ptr [esp + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 0047c0d3  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047c0d5  8d2c9500000000         -lea ebp, [edx*4]
    cpu.ebp = x86::reg32(cpu.edx * 4);
    // 0047c0dc  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047c0de  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 0047c0e1  01d5                   -add ebp, edx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edx));
    // 0047c0e3  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0047c0e5  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0047c0e7  c1e502                 -shl ebp, 2
    cpu.ebp <<= 2 /*0x2*/ % 32;
    // 0047c0ea  c1e908                 -shr ecx, 8
    cpu.ecx >>= 8 /*0x8*/ % 32;
    // 0047c0ed  29c5                   -sub ebp, eax
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0047c0ef  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0047c0f3  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0047c0f9  8d1c8500000000         -lea ebx, [eax*4]
    cpu.ebx = x86::reg32(cpu.eax * 4);
    // 0047c100  894c2420               -mov dword ptr [esp + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 0047c104  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047c106  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047c108  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047c10a  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 0047c10d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047c10f  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
L_0x0047c111:
    // 0047c111  8d043e                 -lea eax, [esi + edi]
    cpu.eax = x86::reg32(cpu.esi + cpu.edi * 1);
    // 0047c114  c1e804                 -shr eax, 4
    cpu.eax >>= 4 /*0x4*/ % 32;
    // 0047c117  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0047c11b  8b442438               -mov eax, dword ptr [esp + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0047c11f  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0047c121  c1e804                 -shr eax, 4
    cpu.eax >>= 4 /*0x4*/ % 32;
    // 0047c124  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0047c128  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0047c12c  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0047c12e  c1e804                 -shr eax, 4
    cpu.eax >>= 4 /*0x4*/ % 32;
    // 0047c131  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0047c135  037c2424               -add edi, dword ptr [esp + 0x24]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */)));
    // 0047c139  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0047c13d  01442438               -add dword ptr [esp + 0x38], eax
    (app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */)) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047c141  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0047c145  01442434               -add dword ptr [esp + 0x34], eax
    (app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */)) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047c149  2b74242c               -sub esi, dword ptr [esp + 0x2c]
    (cpu.esi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */)));
    // 0047c14d  2b6c2428               -sub ebp, dword ptr [esp + 0x28]
    (cpu.ebp) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */)));
    // 0047c151  2b5c2430               -sub ebx, dword ptr [esp + 0x30]
    (cpu.ebx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */)));
    // 0047c155  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047c159  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0047c15c  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047c15e  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0047c162  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047c166  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0047c169  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0047c16d  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0047c171  0b442418               -or eax, dword ptr [esp + 0x18]
    cpu.eax |= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 0047c175  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047c178  0b442410               -or eax, dword ptr [esp + 0x10]
    cpu.eax |= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 0047c17c  81c100000010           -add ecx, 0x10000000
    (cpu.ecx) += x86::reg32(x86::sreg32(268435456 /*0x10000000*/));
    // 0047c182  e895bfffff             -call 0x47811c
    cpu.esp -= 4;
    sub_47811c(app, cpu);
    if (cpu.terminate) return;
    // 0047c187  89823cca4c00           -mov dword ptr [edx + 0x4cca3c], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5032508) /* 0x4cca3c */) = cpu.eax;
    // 0047c18d  83fa40                 +cmp edx, 0x40
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
    // 0047c190  0f857bffffff           -jne 0x47c111
    if (!cpu.flags.zf)
    {
        goto L_0x0047c111;
    }
    // 0047c196  e809dc0100             -call 0x499da4
    cpu.esp -= 4;
    sub_499da4(app, cpu);
    if (cpu.terminate) return;
    // 0047c19b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c19c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047c19d:
    // 0047c19d  83c434                 -add esp, 0x34
    (cpu.esp) += x86::reg32(x86::sreg32(52 /*0x34*/));
    // 0047c1a0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c1a1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c1a2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c1a3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47c1b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047c1b0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047c1b1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047c1b2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047c1b3  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0047c1b5  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0047c1b7  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0047c1b9  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0047c1bb  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047c1bd  7436                   -je 0x47c1f5
    if (cpu.flags.zf)
    {
        goto L_0x0047c1f5;
    }
L_0x0047c1bf:
    // 0047c1bf  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047c1c1  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0047c1c3  0fafc6                 -imul eax, esi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 0047c1c6  8d1c07                 -lea ebx, [edi + eax]
    cpu.ebx = x86::reg32(cpu.edi + cpu.eax * 1);
    // 0047c1c9  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0047c1ce  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047c1d0  8b4401fc               -mov eax, dword ptr [ecx + eax - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */ + cpu.eax * 1);
    // 0047c1d4  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0047c1d6  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0047c1dd  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0047c1df  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0047c1e1  29c1                   +sub ecx, eax
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047c1e3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047c1e5  7414                   -je 0x47c1fb
    if (cpu.flags.zf)
    {
        goto L_0x0047c1fb;
    }
    // 0047c1e7  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047c1e9  7e04                   -jle 0x47c1ef
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047c1ef;
    }
    // 0047c1eb  4a                     -dec edx
    (cpu.edx)--;
    // 0047c1ec  8d3c33                 -lea edi, [ebx + esi]
    cpu.edi = x86::reg32(cpu.ebx + cpu.esi * 1);
L_0x0047c1ef:
    // 0047c1ef  d1fa                   -sar edx, 1
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (1 /*0x1*/ % 32));
    // 0047c1f1  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047c1f3  75ca                   -jne 0x47c1bf
    if (!cpu.flags.zf)
    {
        goto L_0x0047c1bf;
    }
L_0x0047c1f5:
    // 0047c1f5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047c1f7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c1f8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c1f9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c1fa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047c1fb:
    // 0047c1fb  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047c1fd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c1fe  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c1ff  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c200  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47c204(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047c204  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047c205  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047c206  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047c207  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047c208  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047c20a  8d48e0                 -lea ecx, [eax - 0x20]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(-32) /* -0x20 */);
    // 0047c20d  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 0047c214  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047c216  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0047c219  8b1590ca4c00           -mov edx, dword ptr [0x4cca90]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5032592) /* 0x4cca90 */);
    // 0047c21f  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047c221  8d1c02                 -lea ebx, [edx + eax]
    cpu.ebx = x86::reg32(cpu.edx + cpu.eax * 1);
    // 0047c224  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0047c229  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047c22b  8b4401fc               -mov eax, dword ptr [ecx + eax - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */ + cpu.eax * 1);
    // 0047c22f  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0047c231  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0047c238  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0047c23a  39f0                   +cmp eax, esi
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
    // 0047c23c  7507                   -jne 0x47c245
    if (!cpu.flags.zf)
    {
        goto L_0x0047c245;
    }
    // 0047c23e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047c240  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c241  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c242  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c243  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c244  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047c245:
    // 0047c245  b90b000000             -mov ecx, 0xb
    cpu.ecx = 11 /*0xb*/;
    // 0047c24a  8b1d80ca4c00           -mov ebx, dword ptr [0x4cca80]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5032576) /* 0x4cca80 */);
    // 0047c250  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047c252  e859ffffff             -call 0x47c1b0
    cpu.esp -= 4;
    sub_47c1b0(app, cpu);
    if (cpu.terminate) return;
    // 0047c257  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c258  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c259  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c25a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c25b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47c25c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047c25c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047c25d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047c25e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047c25f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047c260  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047c263  8b35b4ca4c00           -mov esi, dword ptr [0x4ccab4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5032628) /* 0x4ccab4 */);
    // 0047c269  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0047c26b  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0047c26e  a1b8ca4c00             -mov eax, dword ptr [0x4ccab8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5032632) /* 0x4ccab8 */);
    // 0047c273  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047c275  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047c277  7e26                   -jle 0x47c29f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047c29f;
    }
L_0x0047c279:
    // 0047c279  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047c27b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047c27d  6689fb                 -mov bx, di
    cpu.bx = cpu.di;
    // 0047c280  668b4802               -mov cx, word ptr [eax + 2]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0047c284  39d9                   +cmp ecx, ebx
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
    // 0047c286  750f                   -jne 0x47c297
    if (!cpu.flags.zf)
    {
        goto L_0x0047c297;
    }
    // 0047c288  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047c28a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047c28c  668b0c24               -mov cx, word ptr [esp]
    cpu.cx = app->getMemory<x86::reg16>(cpu.esp);
    // 0047c290  668b18                 -mov bx, word ptr [eax]
    cpu.bx = app->getMemory<x86::reg16>(cpu.eax);
    // 0047c293  39cb                   +cmp ebx, ecx
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
    // 0047c295  7412                   -je 0x47c2a9
    if (cpu.flags.zf)
    {
        goto L_0x0047c2a9;
    }
L_0x0047c297:
    // 0047c297  42                     -inc edx
    (cpu.edx)++;
    // 0047c298  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0047c29b  39f2                   +cmp edx, esi
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
    // 0047c29d  7cda                   -jl 0x47c279
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047c279;
    }
L_0x0047c29f:
    // 0047c29f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047c2a1  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047c2a4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c2a5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c2a6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c2a7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c2a8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047c2a9:
    // 0047c2a9  8b4001                 -mov eax, dword ptr [eax + 1]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0047c2ac  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 0047c2af  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047c2b2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c2b3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c2b4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c2b5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c2b6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_47c2b8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047c2b8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047c2b9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047c2ba  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047c2bb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047c2bc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047c2bd  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047c2be  83ec44                 -sub esp, 0x44
    (cpu.esp) -= x86::reg32(x86::sreg32(68 /*0x44*/));
    // 0047c2c1  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0047c2c5  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0047c2c8  a1a0ca4c00             -mov eax, dword ptr [0x4ccaa0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5032608) /* 0x4ccaa0 */);
    // 0047c2cd  bdffffffff             -mov ebp, 0xffffffff
    cpu.ebp = 4294967295 /*0xffffffff*/;
    // 0047c2d2  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0047c2d6  a1acca4c00             -mov eax, dword ptr [0x4ccaac]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5032620) /* 0x4ccaac */);
    // 0047c2db  8b3510ca4c00           -mov esi, dword ptr [0x4cca10]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5032464) /* 0x4cca10 */);
    // 0047c2e1  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0047c2e5  a1b0ca4c00             -mov eax, dword ptr [0x4ccab0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5032624) /* 0x4ccab0 */);
    // 0047c2ea  8b1518ca4c00           -mov edx, dword ptr [0x4cca18]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5032472) /* 0x4cca18 */);
    // 0047c2f0  8944243c               -mov dword ptr [esp + 0x3c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.eax;
    // 0047c2f4  a1b8ca4c00             -mov eax, dword ptr [0x4ccab8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5032632) /* 0x4ccab8 */);
    // 0047c2f9  8b0d1cca4c00           -mov ecx, dword ptr [0x4cca1c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5032476) /* 0x4cca1c */);
    // 0047c2ff  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0047c303  a114ca4c00             -mov eax, dword ptr [0x4cca14]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5032468) /* 0x4cca14 */);
    // 0047c308  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047c30a  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0047c30c  895c241c               -mov dword ptr [esp + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 0047c310  89442440               -mov dword ptr [esp + 0x40], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.eax;
    // 0047c314  a110ca4c00             -mov eax, dword ptr [0x4cca10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5032464) /* 0x4cca10 */);
    // 0047c319  895c2438               -mov dword ptr [esp + 0x38], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.ebx;
    // 0047c31d  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0047c321  a1a4ca4c00             -mov eax, dword ptr [0x4ccaa4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5032612) /* 0x4ccaa4 */);
    // 0047c326  01d6                   -add esi, edx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edx));
    // 0047c328  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047c32a  0f85fe000000           -jne 0x47c42e
    if (!cpu.flags.zf)
    {
        goto L_0x0047c42e;
    }
L_0x0047c330:
    // 0047c330  b820000000             -mov eax, 0x20
    cpu.eax = 32 /*0x20*/;
    // 0047c335  e8cafeffff             -call 0x47c204
    cpu.esp -= 4;
    sub_47c204(app, cpu);
    if (cpu.terminate) return;
    // 0047c33a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047c33c  0f85f7000000           -jne 0x47c439
    if (!cpu.flags.zf)
    {
        goto L_0x0047c439;
    }
L_0x0047c342:
    // 0047c342  8b442438               -mov eax, dword ptr [esp + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0047c346  89442434               -mov dword ptr [esp + 0x34], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 0047c34a  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0047c34c  45                     -inc ebp
    (cpu.ebp)++;
    // 0047c34d  ff54240c               -call dword ptr [esp + 0xc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047c351  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047c353  89442438               -mov dword ptr [esp + 0x38], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 0047c357  83f820                 +cmp eax, 0x20
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
    // 0047c35a  0f8efc000000           -jle 0x47c45c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047c45c;
    }
    // 0047c360  e89ffeffff             -call 0x47c204
    cpu.esp -= 4;
    sub_47c204(app, cpu);
    if (cpu.terminate) return;
    // 0047c365  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047c367  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0047c369  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047c36b  74d5                   -je 0x47c342
    if (cpu.flags.zf)
    {
        goto L_0x0047c342;
    }
    // 0047c36d  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0047c372  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047c375  8b4401fc               -mov eax, dword ptr [ecx + eax - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */ + cpu.eax * 1);
    // 0047c379  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0047c37b  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0047c382  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0047c384  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0047c389  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 0047c38d  8d4206                 -lea eax, [edx + 6]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(6) /* 0x6 */);
    // 0047c390  8b4401fc               -mov eax, dword ptr [ecx + eax - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */ + cpu.eax * 1);
    // 0047c394  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0047c396  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0047c39d  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0047c39f  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0047c3a3  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047c3a5  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0047c3a9  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0047c3ad  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0047c3b1  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047c3b3  740d                   -je 0x47c3c2
    if (cpu.flags.zf)
    {
        goto L_0x0047c3c2;
    }
    // 0047c3b5  8b542434               -mov edx, dword ptr [esp + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0047c3b9  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047c3bb  e89cfeffff             -call 0x47c25c
    cpu.esp -= 4;
    sub_47c25c(app, cpu);
    if (cpu.terminate) return;
    // 0047c3c0  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
L_0x0047c3c2:
    // 0047c3c2  8b4706                 -mov eax, dword ptr [edi + 6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(6) /* 0x6 */);
    // 0047c3c5  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 0047c3c8  8d1406                 -lea edx, [esi + eax]
    cpu.edx = x86::reg32(cpu.esi + cpu.eax * 1);
    // 0047c3cb  89542430               -mov dword ptr [esp + 0x30], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.edx;
    // 0047c3cf  8b4707                 -mov eax, dword ptr [edi + 7]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(7) /* 0x7 */);
    // 0047c3d2  8b542440               -mov edx, dword ptr [esp + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0047c3d6  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 0047c3d9  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0047c3db  8b4c243c               -mov ecx, dword ptr [esp + 0x3c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0047c3df  8954242c               -mov dword ptr [esp + 0x2c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.edx;
    // 0047c3e3  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047c3e5  7561                   -jne 0x47c448
    if (!cpu.flags.zf)
    {
        goto L_0x0047c448;
    }
L_0x0047c3e7:
    // 0047c3e7  8b1d84ca4c00           -mov ebx, dword ptr [0x4cca84]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5032580) /* 0x4cca84 */);
    // 0047c3ed  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047c3ef  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047c3f0  8a4703                 -mov al, byte ptr [edi + 3]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */);
    // 0047c3f3  8b542430               -mov edx, dword ptr [esp + 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0047c3f7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047c3f8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047c3fa  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0047c3fe  8a4702                 -mov al, byte ptr [edi + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 0047c401  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0047c403  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047c404  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0047c408  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0047c40c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047c40d  8b442440               -mov eax, dword ptr [esp + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0047c411  8b1d94ca4c00           -mov ebx, dword ptr [0x4cca94]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5032596) /* 0x4cca94 */);
    // 0047c417  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0047c419  8b4c2438               -mov ecx, dword ptr [esp + 0x38]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0047c41d  ff542420               -call dword ptr [esp + 0x20]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047c421  8b4705                 -mov eax, dword ptr [edi + 5]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5) /* 0x5 */);
    // 0047c424  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 0047c427  01c6                   +add esi, eax
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
    // 0047c429  e914ffffff             -jmp 0x47c342
    goto L_0x0047c342;
L_0x0047c42e:
    // 0047c42e  ff15a4ca4c00           -call dword ptr [0x4ccaa4]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5032612) /* 0x4ccaa4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047c434  e9f7feffff             -jmp 0x47c330
    goto L_0x0047c330;
L_0x0047c439:
    // 0047c439  8b4005                 -mov eax, dword ptr [eax + 5]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5) /* 0x5 */);
    // 0047c43c  c1f818                 +sar eax, 0x18
    {
        x86::reg8 tmp = 24 /*0x18*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 0047c43f  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0047c443  e9fafeffff             -jmp 0x47c342
    goto L_0x0047c342;
L_0x0047c448:
    // 0047c448  8b5c2420               -mov ebx, dword ptr [esp + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0047c44c  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047c450  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047c454  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0047c456  ff54243c               -call dword ptr [esp + 0x3c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047c45a  eb8b                   -jmp 0x47c3e7
    goto L_0x0047c3e7;
L_0x0047c45c:
    // 0047c45c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047c45e  7535                   -jne 0x47c495
    if (!cpu.flags.zf)
    {
        goto L_0x0047c495;
    }
    // 0047c460  833da8ca4c0000         +cmp dword ptr [0x4ccaa8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5032616) /* 0x4ccaa8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047c467  0f8598000000           -jne 0x47c505
    if (!cpu.flags.zf)
    {
        goto L_0x0047c505;
    }
L_0x0047c46d:
    // 0047c46d  a118ca4c00             -mov eax, dword ptr [0x4cca18]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5032472) /* 0x4cca18 */);
    // 0047c472  8b542440               -mov edx, dword ptr [esp + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0047c476  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0047c478  a11cca4c00             -mov eax, dword ptr [0x4cca1c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5032476) /* 0x4cca1c */);
    // 0047c47d  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0047c47f  893510ca4c00           -mov dword ptr [0x4cca10], esi
    app->getMemory<x86::reg32>(x86::reg32(5032464) /* 0x4cca10 */) = cpu.esi;
    // 0047c485  891514ca4c00           -mov dword ptr [0x4cca14], edx
    app->getMemory<x86::reg32>(x86::reg32(5032468) /* 0x4cca14 */) = cpu.edx;
    // 0047c48b  83c444                 -add esp, 0x44
    (cpu.esp) += x86::reg32(x86::sreg32(68 /*0x44*/));
    // 0047c48e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c48f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c490  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c491  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c492  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c493  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c494  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047c495:
    // 0047c495  83f80a                 +cmp eax, 0xa
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
    // 0047c498  7521                   -jne 0x47c4bb
    if (!cpu.flags.zf)
    {
        goto L_0x0047c4bb;
    }
    // 0047c49a  8b1528ca4c00           -mov edx, dword ptr [0x4cca28]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5032488) /* 0x4cca28 */);
    // 0047c4a0  8b3d2cca4c00           -mov edi, dword ptr [0x4cca2c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5032492) /* 0x4cca2c */);
    // 0047c4a6  8b442440               -mov eax, dword ptr [esp + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0047c4aa  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0047c4ac  01d0                   +add eax, edx
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
    // 0047c4ae  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0047c4b2  89442440               -mov dword ptr [esp + 0x40], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.eax;
    // 0047c4b6  e987feffff             -jmp 0x47c342
    goto L_0x0047c342;
L_0x0047c4bb:
    // 0047c4bb  833dc0a94c0000         +cmp dword ptr [0x4ca9c0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5024192) /* 0x4ca9c0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047c4c2  7509                   -jne 0x47c4cd
    if (!cpu.flags.zf)
    {
        goto L_0x0047c4cd;
    }
L_0x0047c4c4:
    // 0047c4c4  0374241c               +add esi, dword ptr [esp + 0x1c]
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047c4c8  e975feffff             -jmp 0x47c342
    goto L_0x0047c342;
L_0x0047c4cd:
    // 0047c4cd  83f809                 +cmp eax, 9
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
    // 0047c4d0  75f2                   -jne 0x47c4c4
    if (!cpu.flags.zf)
    {
        goto L_0x0047c4c4;
    }
    // 0047c4d2  8b1dbca94c00           -mov ebx, dword ptr [0x4ca9bc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5024188) /* 0x4ca9bc */);
    // 0047c4d8  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047c4da  0f8e62feffff           -jle 0x47c342
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047c342;
    }
    // 0047c4e0  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 0047c4e3  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0047c4e5:
    // 0047c4e5  a1c0a94c00             -mov eax, dword ptr [0x4ca9c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5024192) /* 0x4ca9c0 */);
    // 0047c4ea  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0047c4ec  8b38                   -mov edi, dword ptr [eax]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax);
    // 0047c4ee  39fe                   +cmp esi, edi
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
    // 0047c4f0  7d07                   -jge 0x47c4f9
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047c4f9;
    }
    // 0047c4f2  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 0047c4f4  e949feffff             -jmp 0x47c342
    goto L_0x0047c342;
L_0x0047c4f9:
    // 0047c4f9  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047c4fc  39da                   +cmp edx, ebx
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
    // 0047c4fe  7ce5                   -jl 0x47c4e5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047c4e5;
    }
    // 0047c500  e93dfeffff             -jmp 0x47c342
    goto L_0x0047c342;
L_0x0047c505:
    // 0047c505  ff15a8ca4c00           -call dword ptr [0x4ccaa8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5032616) /* 0x4ccaa8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047c50b  e95dffffff             -jmp 0x47c46d
    goto L_0x0047c46d;
}

/* align: skip  */
void Application::sub_47c510(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047c510  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047c511  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047c513  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047c515  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0047c517  e8fc050000             -call 0x47cb18
    cpu.esp -= 4;
    sub_47cb18(app, cpu);
    if (cpu.terminate) return;
    // 0047c51c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047c51e  e895fdffff             -call 0x47c2b8
    cpu.esp -= 4;
    sub_47c2b8(app, cpu);
    if (cpu.terminate) return;
    // 0047c523  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047c524  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
