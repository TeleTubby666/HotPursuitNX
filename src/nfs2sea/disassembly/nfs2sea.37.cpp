#include "nfs2sea.h"
#include <lib/thread.h>

namespace nfs2sea
{

/* align: skip  */
void Application::sub_4c4789(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c4789  833d90124e0000         +cmp dword ptr [0x4e1290], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5116560) /* 0x4e1290 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c4790  751f                   -jne 0x4c47b1
    if (!cpu.flags.zf)
    {
        goto L_0x004c47b1;
    }
    // 004c4792  6890124e00             -push 0x4e1290
    app->getMemory<x86::reg32>(cpu.esp-4) = 5116560 /*0x4e1290*/;
    cpu.esp -= 4;
    // 004c4797  68b8174e00             -push 0x4e17b8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5117880 /*0x4e17b8*/;
    cpu.esp -= 4;
    // 004c479c  e8bffeffff             -call 0x4c4660
    cpu.esp -= 4;
    sub_4c4660(app, cpu);
    if (cpu.terminate) return;
    // 004c47a1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c47a3  740c                   -je 0x4c47b1
    if (cpu.flags.zf)
    {
        goto L_0x004c47b1;
    }
    // 004c47a5  c70590124e00ffffffff   -mov dword ptr [0x4e1290], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5116560) /* 0x4e1290 */) = 4294967295 /*0xffffffff*/;
    // 004c47af  eb20                   -jmp 0x4c47d1
    goto L_0x004c47d1;
L_0x004c47b1:
    // 004c47b1  833d90124e00ff         +cmp dword ptr [0x4e1290], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5116560) /* 0x4e1290 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c47b8  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 004c47bd  7412                   -je 0x4c47d1
    if (cpu.flags.zf)
    {
        goto L_0x004c47d1;
    }
    // 004c47bf  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004c47c3  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004c47c7  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004c47cb  ff1590124e00           -call dword ptr [0x4e1290]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5116560) /* 0x4e1290 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004c47d1:
    // 004c47d1  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_4c47d4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c47d4  833d2c134e0000         +cmp dword ptr [0x4e132c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5116716) /* 0x4e132c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c47db  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004c47dc  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004c47de  751f                   -jne 0x4c47ff
    if (!cpu.flags.zf)
    {
        goto L_0x004c47ff;
    }
    // 004c47e0  682c134e00             -push 0x4e132c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5116716 /*0x4e132c*/;
    cpu.esp -= 4;
    // 004c47e5  68c41a4e00             -push 0x4e1ac4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5118660 /*0x4e1ac4*/;
    cpu.esp -= 4;
    // 004c47ea  e871feffff             -call 0x4c4660
    cpu.esp -= 4;
    sub_4c4660(app, cpu);
    if (cpu.terminate) return;
    // 004c47ef  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c47f1  740c                   -je 0x4c47ff
    if (cpu.flags.zf)
    {
        goto L_0x004c47ff;
    }
    // 004c47f3  c7052c134e00ffffffff   -mov dword ptr [0x4e132c], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5116716) /* 0x4e132c */) = 4294967295 /*0xffffffff*/;
    // 004c47fd  eb23                   -jmp 0x4c4822
    goto L_0x004c4822;
L_0x004c47ff:
    // 004c47ff  833d2c134e00ff         +cmp dword ptr [0x4e132c], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5116716) /* 0x4e132c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c4806  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 004c480b  7415                   -je 0x4c4822
    if (cpu.flags.zf)
    {
        goto L_0x004c4822;
    }
    // 004c480d  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 004c4810  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 004c4813  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 004c4816  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004c4819  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 004c481c  ff152c134e00           -call dword ptr [0x4e132c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5116716) /* 0x4e132c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004c4822:
    // 004c4822  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c4823  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip  */
void Application::sub_4c4826(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c4826  833d38134e0000         +cmp dword ptr [0x4e1338], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5116728) /* 0x4e1338 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c482d  751f                   -jne 0x4c484e
    if (!cpu.flags.zf)
    {
        goto L_0x004c484e;
    }
    // 004c482f  6838134e00             -push 0x4e1338
    app->getMemory<x86::reg32>(cpu.esp-4) = 5116728 /*0x4e1338*/;
    cpu.esp -= 4;
    // 004c4834  68f41a4e00             -push 0x4e1af4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5118708 /*0x4e1af4*/;
    cpu.esp -= 4;
    // 004c4839  e822feffff             -call 0x4c4660
    cpu.esp -= 4;
    sub_4c4660(app, cpu);
    if (cpu.terminate) return;
    // 004c483e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c4840  740c                   -je 0x4c484e
    if (cpu.flags.zf)
    {
        goto L_0x004c484e;
    }
    // 004c4842  c70538134e00ffffffff   -mov dword ptr [0x4e1338], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5116728) /* 0x4e1338 */) = 4294967295 /*0xffffffff*/;
    // 004c484c  eb20                   -jmp 0x4c486e
    goto L_0x004c486e;
L_0x004c484e:
    // 004c484e  833d38134e00ff         +cmp dword ptr [0x4e1338], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5116728) /* 0x4e1338 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c4855  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 004c485a  7412                   -je 0x4c486e
    if (cpu.flags.zf)
    {
        goto L_0x004c486e;
    }
    // 004c485c  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004c4860  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004c4864  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004c4868  ff1538134e00           -call dword ptr [0x4e1338]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5116728) /* 0x4e1338 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004c486e:
    // 004c486e  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_4c4871(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c4871  833d54134e0000         +cmp dword ptr [0x4e1354], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5116756) /* 0x4e1354 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c4878  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004c4879  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004c487b  751f                   -jne 0x4c489c
    if (!cpu.flags.zf)
    {
        goto L_0x004c489c;
    }
    // 004c487d  6854134e00             -push 0x4e1354
    app->getMemory<x86::reg32>(cpu.esp-4) = 5116756 /*0x4e1354*/;
    cpu.esp -= 4;
    // 004c4882  686c1b4e00             -push 0x4e1b6c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5118828 /*0x4e1b6c*/;
    cpu.esp -= 4;
    // 004c4887  e8d4fdffff             -call 0x4c4660
    cpu.esp -= 4;
    sub_4c4660(app, cpu);
    if (cpu.terminate) return;
    // 004c488c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c488e  740c                   -je 0x4c489c
    if (cpu.flags.zf)
    {
        goto L_0x004c489c;
    }
    // 004c4890  c70554134e00ffffffff   -mov dword ptr [0x4e1354], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5116756) /* 0x4e1354 */) = 4294967295 /*0xffffffff*/;
    // 004c489a  eb26                   -jmp 0x4c48c2
    goto L_0x004c48c2;
L_0x004c489c:
    // 004c489c  833d54134e00ff         +cmp dword ptr [0x4e1354], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5116756) /* 0x4e1354 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c48a3  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 004c48a8  7418                   -je 0x4c48c2
    if (cpu.flags.zf)
    {
        goto L_0x004c48c2;
    }
    // 004c48aa  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 004c48ad  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 004c48b0  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 004c48b3  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 004c48b6  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004c48b9  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 004c48bc  ff1554134e00           -call dword ptr [0x4e1354]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5116756) /* 0x4e1354 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004c48c2:
    // 004c48c2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c48c3  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip  */
void Application::sub_4c48c6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c48c6  833d60134e0000         +cmp dword ptr [0x4e1360], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5116768) /* 0x4e1360 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c48cd  751f                   -jne 0x4c48ee
    if (!cpu.flags.zf)
    {
        goto L_0x004c48ee;
    }
    // 004c48cf  6860134e00             -push 0x4e1360
    app->getMemory<x86::reg32>(cpu.esp-4) = 5116768 /*0x4e1360*/;
    cpu.esp -= 4;
    // 004c48d4  68901b4e00             -push 0x4e1b90
    app->getMemory<x86::reg32>(cpu.esp-4) = 5118864 /*0x4e1b90*/;
    cpu.esp -= 4;
    // 004c48d9  e882fdffff             -call 0x4c4660
    cpu.esp -= 4;
    sub_4c4660(app, cpu);
    if (cpu.terminate) return;
    // 004c48de  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c48e0  740c                   -je 0x4c48ee
    if (cpu.flags.zf)
    {
        goto L_0x004c48ee;
    }
    // 004c48e2  c70560134e00ffffffff   -mov dword ptr [0x4e1360], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5116768) /* 0x4e1360 */) = 4294967295 /*0xffffffff*/;
    // 004c48ec  eb1c                   -jmp 0x4c490a
    goto L_0x004c490a;
L_0x004c48ee:
    // 004c48ee  833d60134e00ff         +cmp dword ptr [0x4e1360], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5116768) /* 0x4e1360 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c48f5  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 004c48fa  740e                   -je 0x4c490a
    if (cpu.flags.zf)
    {
        goto L_0x004c490a;
    }
    // 004c48fc  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 004c4900  ff742408               -push dword ptr [esp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 004c4904  ff1560134e00           -call dword ptr [0x4e1360]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5116768) /* 0x4e1360 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004c490a:
    // 004c490a  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_4c490d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c490d  833dac134e0000         +cmp dword ptr [0x4e13ac], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5116844) /* 0x4e13ac */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c4914  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004c4915  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004c4917  751f                   -jne 0x4c4938
    if (!cpu.flags.zf)
    {
        goto L_0x004c4938;
    }
    // 004c4919  68ac134e00             -push 0x4e13ac
    app->getMemory<x86::reg32>(cpu.esp-4) = 5116844 /*0x4e13ac*/;
    cpu.esp -= 4;
    // 004c491e  68041d4e00             -push 0x4e1d04
    app->getMemory<x86::reg32>(cpu.esp-4) = 5119236 /*0x4e1d04*/;
    cpu.esp -= 4;
    // 004c4923  e838fdffff             -call 0x4c4660
    cpu.esp -= 4;
    sub_4c4660(app, cpu);
    if (cpu.terminate) return;
    // 004c4928  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c492a  740c                   -je 0x4c4938
    if (cpu.flags.zf)
    {
        goto L_0x004c4938;
    }
    // 004c492c  c705ac134e00ffffffff   -mov dword ptr [0x4e13ac], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5116844) /* 0x4e13ac */) = 4294967295 /*0xffffffff*/;
    // 004c4936  eb23                   -jmp 0x4c495b
    goto L_0x004c495b;
L_0x004c4938:
    // 004c4938  833dac134e00ff         +cmp dword ptr [0x4e13ac], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5116844) /* 0x4e13ac */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c493f  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 004c4944  7415                   -je 0x4c495b
    if (cpu.flags.zf)
    {
        goto L_0x004c495b;
    }
    // 004c4946  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 004c4949  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 004c494c  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 004c494f  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004c4952  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 004c4955  ff15ac134e00           -call dword ptr [0x4e13ac]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5116844) /* 0x4e13ac */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004c495b:
    // 004c495b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c495c  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip  */
void Application::sub_4c495f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c495f  833db8134e0000         +cmp dword ptr [0x4e13b8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5116856) /* 0x4e13b8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c4966  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004c4967  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004c4969  751f                   -jne 0x4c498a
    if (!cpu.flags.zf)
    {
        goto L_0x004c498a;
    }
    // 004c496b  68b8134e00             -push 0x4e13b8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5116856 /*0x4e13b8*/;
    cpu.esp -= 4;
    // 004c4970  683c1d4e00             -push 0x4e1d3c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5119292 /*0x4e1d3c*/;
    cpu.esp -= 4;
    // 004c4975  e8e6fcffff             -call 0x4c4660
    cpu.esp -= 4;
    sub_4c4660(app, cpu);
    if (cpu.terminate) return;
    // 004c497a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c497c  740c                   -je 0x4c498a
    if (cpu.flags.zf)
    {
        goto L_0x004c498a;
    }
    // 004c497e  c705b8134e00ffffffff   -mov dword ptr [0x4e13b8], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5116856) /* 0x4e13b8 */) = 4294967295 /*0xffffffff*/;
    // 004c4988  eb23                   -jmp 0x4c49ad
    goto L_0x004c49ad;
L_0x004c498a:
    // 004c498a  833db8134e00ff         +cmp dword ptr [0x4e13b8], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5116856) /* 0x4e13b8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c4991  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 004c4996  7415                   -je 0x4c49ad
    if (cpu.flags.zf)
    {
        goto L_0x004c49ad;
    }
    // 004c4998  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 004c499b  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 004c499e  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 004c49a1  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004c49a4  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 004c49a7  ff15b8134e00           -call dword ptr [0x4e13b8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5116856) /* 0x4e13b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004c49ad:
    // 004c49ad  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c49ae  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip  */
void Application::sub_4c49b1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c49b1  833dd0134e0000         +cmp dword ptr [0x4e13d0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5116880) /* 0x4e13d0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c49b8  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004c49b9  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004c49bb  751f                   -jne 0x4c49dc
    if (!cpu.flags.zf)
    {
        goto L_0x004c49dc;
    }
    // 004c49bd  68d0134e00             -push 0x4e13d0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5116880 /*0x4e13d0*/;
    cpu.esp -= 4;
    // 004c49c2  68a81d4e00             -push 0x4e1da8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5119400 /*0x4e1da8*/;
    cpu.esp -= 4;
    // 004c49c7  e894fcffff             -call 0x4c4660
    cpu.esp -= 4;
    sub_4c4660(app, cpu);
    if (cpu.terminate) return;
    // 004c49cc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c49ce  740c                   -je 0x4c49dc
    if (cpu.flags.zf)
    {
        goto L_0x004c49dc;
    }
    // 004c49d0  c705d0134e00ffffffff   -mov dword ptr [0x4e13d0], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5116880) /* 0x4e13d0 */) = 4294967295 /*0xffffffff*/;
    // 004c49da  eb26                   -jmp 0x4c4a02
    goto L_0x004c4a02;
L_0x004c49dc:
    // 004c49dc  833dd0134e00ff         +cmp dword ptr [0x4e13d0], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5116880) /* 0x4e13d0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c49e3  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 004c49e8  7418                   -je 0x4c4a02
    if (cpu.flags.zf)
    {
        goto L_0x004c4a02;
    }
    // 004c49ea  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 004c49ed  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 004c49f0  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 004c49f3  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 004c49f6  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004c49f9  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 004c49fc  ff15d0134e00           -call dword ptr [0x4e13d0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5116880) /* 0x4e13d0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004c4a02:
    // 004c4a02  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c4a03  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip  */
void Application::sub_4c4a06(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c4a06  833dd8134e0000         +cmp dword ptr [0x4e13d8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5116888) /* 0x4e13d8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c4a0d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004c4a0e  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004c4a10  751f                   -jne 0x4c4a31
    if (!cpu.flags.zf)
    {
        goto L_0x004c4a31;
    }
    // 004c4a12  68d8134e00             -push 0x4e13d8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5116888 /*0x4e13d8*/;
    cpu.esp -= 4;
    // 004c4a17  68d81d4e00             -push 0x4e1dd8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5119448 /*0x4e1dd8*/;
    cpu.esp -= 4;
    // 004c4a1c  e83ffcffff             -call 0x4c4660
    cpu.esp -= 4;
    sub_4c4660(app, cpu);
    if (cpu.terminate) return;
    // 004c4a21  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c4a23  740c                   -je 0x4c4a31
    if (cpu.flags.zf)
    {
        goto L_0x004c4a31;
    }
    // 004c4a25  c705d8134e00ffffffff   -mov dword ptr [0x4e13d8], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5116888) /* 0x4e13d8 */) = 4294967295 /*0xffffffff*/;
    // 004c4a2f  eb2f                   -jmp 0x4c4a60
    goto L_0x004c4a60;
L_0x004c4a31:
    // 004c4a31  833dd8134e00ff         +cmp dword ptr [0x4e13d8], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5116888) /* 0x4e13d8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c4a38  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 004c4a3d  7421                   -je 0x4c4a60
    if (cpu.flags.zf)
    {
        goto L_0x004c4a60;
    }
    // 004c4a3f  ff7528                 -push dword ptr [ebp + 0x28]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(40) /* 0x28 */);
    cpu.esp -= 4;
    // 004c4a42  ff7524                 -push dword ptr [ebp + 0x24]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(36) /* 0x24 */);
    cpu.esp -= 4;
    // 004c4a45  ff7520                 -push dword ptr [ebp + 0x20]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    // 004c4a48  ff751c                 -push dword ptr [ebp + 0x1c]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */);
    cpu.esp -= 4;
    // 004c4a4b  ff7518                 -push dword ptr [ebp + 0x18]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    // 004c4a4e  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 004c4a51  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 004c4a54  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004c4a57  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 004c4a5a  ff15d8134e00           -call dword ptr [0x4e13d8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5116888) /* 0x4e13d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004c4a60:
    // 004c4a60  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c4a61  c22400                 -ret 0x24
    cpu.esp += 4+36 /*0x24*/;
    return;
}

/* align: skip  */
void Application::sub_4c4a64(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c4a64  833d68144e0000         +cmp dword ptr [0x4e1468], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5117032) /* 0x4e1468 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c4a6b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004c4a6c  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004c4a6e  751f                   -jne 0x4c4a8f
    if (!cpu.flags.zf)
    {
        goto L_0x004c4a8f;
    }
    // 004c4a70  6868144e00             -push 0x4e1468
    app->getMemory<x86::reg32>(cpu.esp-4) = 5117032 /*0x4e1468*/;
    cpu.esp -= 4;
    // 004c4a75  6898204e00             -push 0x4e2098
    app->getMemory<x86::reg32>(cpu.esp-4) = 5120152 /*0x4e2098*/;
    cpu.esp -= 4;
    // 004c4a7a  e8e1fbffff             -call 0x4c4660
    cpu.esp -= 4;
    sub_4c4660(app, cpu);
    if (cpu.terminate) return;
    // 004c4a7f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c4a81  740c                   -je 0x4c4a8f
    if (cpu.flags.zf)
    {
        goto L_0x004c4a8f;
    }
    // 004c4a83  c70568144e00ffffffff   -mov dword ptr [0x4e1468], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5117032) /* 0x4e1468 */) = 4294967295 /*0xffffffff*/;
    // 004c4a8d  eb20                   -jmp 0x4c4aaf
    goto L_0x004c4aaf;
L_0x004c4a8f:
    // 004c4a8f  833d68144e00ff         +cmp dword ptr [0x4e1468], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5117032) /* 0x4e1468 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c4a96  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 004c4a9b  7412                   -je 0x4c4aaf
    if (cpu.flags.zf)
    {
        goto L_0x004c4aaf;
    }
    // 004c4a9d  ff7514                 -push dword ptr [ebp + 0x14]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    // 004c4aa0  ff7510                 -push dword ptr [ebp + 0x10]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    // 004c4aa3  ff750c                 -push dword ptr [ebp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004c4aa6  ff7508                 -push dword ptr [ebp + 8]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    // 004c4aa9  ff1568144e00           -call dword ptr [0x4e1468]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5117032) /* 0x4e1468 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004c4aaf:
    // 004c4aaf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004c4ab0  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::sub_4c4ab3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c4ab3  833d84144e0000         +cmp dword ptr [0x4e1484], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5117060) /* 0x4e1484 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c4aba  751f                   -jne 0x4c4adb
    if (!cpu.flags.zf)
    {
        goto L_0x004c4adb;
    }
    // 004c4abc  6884144e00             -push 0x4e1484
    app->getMemory<x86::reg32>(cpu.esp-4) = 5117060 /*0x4e1484*/;
    cpu.esp -= 4;
    // 004c4ac1  6824214e00             -push 0x4e2124
    app->getMemory<x86::reg32>(cpu.esp-4) = 5120292 /*0x4e2124*/;
    cpu.esp -= 4;
    // 004c4ac6  e895fbffff             -call 0x4c4660
    cpu.esp -= 4;
    sub_4c4660(app, cpu);
    if (cpu.terminate) return;
    // 004c4acb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c4acd  740c                   -je 0x4c4adb
    if (cpu.flags.zf)
    {
        goto L_0x004c4adb;
    }
    // 004c4acf  c70584144e00ffffffff   -mov dword ptr [0x4e1484], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5117060) /* 0x4e1484 */) = 4294967295 /*0xffffffff*/;
    // 004c4ad9  eb20                   -jmp 0x4c4afb
    goto L_0x004c4afb;
L_0x004c4adb:
    // 004c4adb  833d84144e00ff         +cmp dword ptr [0x4e1484], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5117060) /* 0x4e1484 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c4ae2  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 004c4ae7  7412                   -je 0x4c4afb
    if (cpu.flags.zf)
    {
        goto L_0x004c4afb;
    }
    // 004c4ae9  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004c4aed  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004c4af1  ff74240c               -push dword ptr [esp + 0xc]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    // 004c4af5  ff1584144e00           -call dword ptr [0x4e1484]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5117060) /* 0x4e1484 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004c4afb:
    // 004c4afb  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_4c4afe(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c4afe  833db0144e0000         +cmp dword ptr [0x4e14b0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5117104) /* 0x4e14b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c4b05  751f                   -jne 0x4c4b26
    if (!cpu.flags.zf)
    {
        goto L_0x004c4b26;
    }
    // 004c4b07  68b0144e00             -push 0x4e14b0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5117104 /*0x4e14b0*/;
    cpu.esp -= 4;
    // 004c4b0c  6804224e00             -push 0x4e2204
    app->getMemory<x86::reg32>(cpu.esp-4) = 5120516 /*0x4e2204*/;
    cpu.esp -= 4;
    // 004c4b11  e84afbffff             -call 0x4c4660
    cpu.esp -= 4;
    sub_4c4660(app, cpu);
    if (cpu.terminate) return;
    // 004c4b16  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004c4b18  740c                   -je 0x4c4b26
    if (cpu.flags.zf)
    {
        goto L_0x004c4b26;
    }
    // 004c4b1a  c705b0144e00ffffffff   -mov dword ptr [0x4e14b0], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5117104) /* 0x4e14b0 */) = 4294967295 /*0xffffffff*/;
    // 004c4b24  eb18                   -jmp 0x4c4b3e
    goto L_0x004c4b3e;
L_0x004c4b26:
    // 004c4b26  833db0144e00ff         +cmp dword ptr [0x4e14b0], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5117104) /* 0x4e14b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004c4b2d  b849000080             -mov eax, 0x80000049
    cpu.eax = 2147483721 /*0x80000049*/;
    // 004c4b32  740a                   -je 0x4c4b3e
    if (cpu.flags.zf)
    {
        goto L_0x004c4b3e;
    }
    // 004c4b34  ff742404               -push dword ptr [esp + 4]
    app->getMemory<x86::reg32>(cpu.esp-4) = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    // 004c4b38  ff15b0144e00           -call dword ptr [0x4e14b0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5117104) /* 0x4e14b0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004c4b3e:
    // 004c4b3e  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
/* data blob: 38284e000000000003ffff000000000028284e000400000003ffff000000000018284e000800000003ffff8000000000000000000c0000000cffff0000000000000000000d0000000cffff0000000000000000000e0000000cffff8000000000000000000f0000000cffff80000000001800000010000000020000001000000007000000504b4c00000000000000000038284e000000000003ffff800001000028284e000400000003ffff800001000018284e000800000003ffff800001000088284e000c00000003ffff800001000078284e001000000003ffff800001000068284e001400000003ffff800001000058284e001800000003ffff800001000058284e001c00000003ffff800001000048284e002000000010ffff800000000048284e002400000010ffff800000000048284e002800000010ffff800000000048284e002c00000010ffff800000000000000000300000000cffff800000000000000000310000000cffff800000000000000000320000000cffff800000000000000000330000000cffff800000000000000000340000000cffff800000000000000000350000000cffff800000000000000000360000000cffff800000000000000000370000000cffff800000000000000000380000000cffff800000000000000000390000000cffff8000000000000000003a0000000cffff8000000000000000003b0000000cffff8000000000000000003c0000000cffff8000000000000000003d0000000cffff8000000000000000003e0000000cffff8000000000000000003f0000000cffff800000000000000000400000000cffff800000000000000000410000000cffff800000000000000000420000000cffff800000000000000000430000000cffff800000000000000000440000000cffff800000000000000000450000000cffff800000000000000000460000000cffff800000000000000000470000000cffff800000000000000000480000000cffff800000000000000000490000000cffff8000000000000000004a0000000cffff8000000000000000004b0000000cffff8000000000000000004c0000000cffff8000000000000000004d0000000cffff8000000000000000004e0000000cffff8000000000000000004f0000000cffff8000000000180000001000000001000000500000002c000000e04b4c00 */
void Application::sub_4c4eb8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c4eb8  ff2584654c00           -jmp dword ptr [0x4c6584]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006724), cpu);
}

/* align: skip  */
void Application::sub_4c4ebe(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c4ebe  ff2598644c00           -jmp dword ptr [0x4c6498]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006488), cpu);
}

/* align: skip  */
void Application::sub_4c4ec4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c4ec4  ff254c654c00           -jmp dword ptr [0x4c654c]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006668), cpu);
}

/* align: skip  */
void Application::sub_4c4eca(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c4eca  ff25a0654c00           -jmp dword ptr [0x4c65a0]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006752), cpu);
}

/* align: skip  */
void Application::sub_4c4ed0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c4ed0  ff25bc654c00           -jmp dword ptr [0x4c65bc]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006780), cpu);
}

/* align: skip  */
void Application::sub_4c4ed6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c4ed6  ff25d0654c00           -jmp dword ptr [0x4c65d0]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006800), cpu);
}

/* align: skip  */
void Application::sub_4c4edc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c4edc  ff2550654c00           -jmp dword ptr [0x4c6550]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006672), cpu);
}

/* align: skip  */
void Application::sub_4c4ee2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c4ee2  ff2504654c00           -jmp dword ptr [0x4c6504]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006596), cpu);
}

/* align: skip  */
void Application::sub_4c4ee8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c4ee8  ff25b0654c00           -jmp dword ptr [0x4c65b0]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006768), cpu);
}

/* align: skip  */
void Application::sub_4c4eee(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c4eee  ff25b8654c00           -jmp dword ptr [0x4c65b8]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006776), cpu);
}

/* align: skip  */
void Application::sub_4c4ef4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c4ef4  ff25ac654c00           -jmp dword ptr [0x4c65ac]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006764), cpu);
}

/* align: skip  */
void Application::sub_4c4efa(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c4efa  ff2594654c00           -jmp dword ptr [0x4c6594]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006740), cpu);
}

/* align: skip  */
void Application::sub_4c4f00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c4f00  ff25b4654c00           -jmp dword ptr [0x4c65b4]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006772), cpu);
}

/* align: skip  */
void Application::sub_4c4f06(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c4f06  ff25e8644c00           -jmp dword ptr [0x4c64e8]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006568), cpu);
}

/* align: skip  */
void Application::sub_4c4f0c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c4f0c  ff2518654c00           -jmp dword ptr [0x4c6518]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006616), cpu);
}

/* align: skip  */
void Application::sub_4c4f12(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c4f12  ff2598654c00           -jmp dword ptr [0x4c6598]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006744), cpu);
}

/* align: skip  */
void Application::sub_4c4f18(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c4f18  ff2528654c00           -jmp dword ptr [0x4c6528]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006632), cpu);
}

/* align: skip  */
void Application::sub_4c4f1e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c4f1e  ff25f0634c00           -jmp dword ptr [0x4c63f0]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006320), cpu);
}

/* align: skip  */
void Application::sub_4c4f24(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c4f24  ff25c8644c00           -jmp dword ptr [0x4c64c8]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006536), cpu);
}

/* align: skip  */
void Application::sub_4c4f2a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c4f2a  ff25b8644c00           -jmp dword ptr [0x4c64b8]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006520), cpu);
}

/* align: skip  */
void Application::sub_4c4f30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c4f30  ff25b4644c00           -jmp dword ptr [0x4c64b4]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006516), cpu);
}

/* align: skip  */
void Application::sub_4c4f36(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c4f36  ff2500654c00           -jmp dword ptr [0x4c6500]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006592), cpu);
}

/* align: skip  */
void Application::sub_4c4f3c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c4f3c  ff252c654c00           -jmp dword ptr [0x4c652c]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006636), cpu);
}

/* align: skip  */
void Application::sub_4c4f42(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c4f42  ff25dc644c00           -jmp dword ptr [0x4c64dc]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006556), cpu);
}

/* align: skip  */
void Application::sub_4c4f48(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c4f48  ff25f4644c00           -jmp dword ptr [0x4c64f4]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006580), cpu);
}

/* align: skip  */
void Application::sub_4c4f4e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c4f4e  ff2598634c00           -jmp dword ptr [0x4c6398]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006232), cpu);
}

/* align: skip  */
void Application::sub_4c4f54(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c4f54  ff25a4634c00           -jmp dword ptr [0x4c63a4]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006244), cpu);
}

/* align: skip  */
void Application::sub_4c4f5a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c4f5a  ff25a0634c00           -jmp dword ptr [0x4c63a0]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006240), cpu);
}

/* align: skip  */
void Application::sub_4c4f60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c4f60  ff25cc654c00           -jmp dword ptr [0x4c65cc]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006796), cpu);
}

/* align: skip  */
void Application::sub_4c4f66(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c4f66  ff2548644c00           -jmp dword ptr [0x4c6448]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006408), cpu);
}

/* align: skip  */
void Application::sub_4c4f6c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c4f6c  ff25ec634c00           -jmp dword ptr [0x4c63ec]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006316), cpu);
}

/* align: skip  */
void Application::sub_4c4f72(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c4f72  ff25d8644c00           -jmp dword ptr [0x4c64d8]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006552), cpu);
}

/* align: skip  */
void Application::sub_4c4f78(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c4f78  ff2580654c00           -jmp dword ptr [0x4c6580]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006720), cpu);
}

/* align: skip  */
void Application::sub_4c4f7e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c4f7e  ff25c4654c00           -jmp dword ptr [0x4c65c4]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006788), cpu);
}

/* align: skip  */
void Application::sub_4c4f84(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c4f84  ff251c654c00           -jmp dword ptr [0x4c651c]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006620), cpu);
}

/* align: skip  */
void Application::sub_4c4f8a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c4f8a  ff25c8654c00           -jmp dword ptr [0x4c65c8]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006792), cpu);
}

/* align: skip  */
void Application::sub_4c4f90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c4f90  ff259c634c00           -jmp dword ptr [0x4c639c]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006236), cpu);
}

/* align: skip  */
void Application::sub_4c4f96(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c4f96  ff2568654c00           -jmp dword ptr [0x4c6568]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006696), cpu);
}

/* align: skip  */
void Application::sub_4c4f9c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c4f9c  ff25b0644c00           -jmp dword ptr [0x4c64b0]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006512), cpu);
}

/* align: skip  */
void Application::sub_4c4fa2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c4fa2  ff256c654c00           -jmp dword ptr [0x4c656c]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006700), cpu);
}

/* align: skip  */
void Application::sub_4c4fa8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c4fa8  ff25a8644c00           -jmp dword ptr [0x4c64a8]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006504), cpu);
}

/* align: skip  */
void Application::sub_4c4fae(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c4fae  ff2580644c00           -jmp dword ptr [0x4c6480]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006464), cpu);
}

/* align: skip  */
void Application::sub_4c4fb4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c4fb4  ff2558654c00           -jmp dword ptr [0x4c6558]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006680), cpu);
}

/* align: skip  */
void Application::sub_4c4fba(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c4fba  ff2510654c00           -jmp dword ptr [0x4c6510]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006608), cpu);
}

/* align: skip  */
void Application::sub_4c4fc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c4fc0  ff2570644c00           -jmp dword ptr [0x4c6470]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006448), cpu);
}

/* align: skip  */
void Application::sub_4c4fc6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c4fc6  ff2540654c00           -jmp dword ptr [0x4c6540]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006656), cpu);
}

/* align: skip  */
void Application::sub_4c4fcc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c4fcc  ff257c644c00           -jmp dword ptr [0x4c647c]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006460), cpu);
}

/* align: skip  */
void Application::sub_4c4fd2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c4fd2  ff253c654c00           -jmp dword ptr [0x4c653c]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006652), cpu);
}

/* align: skip  */
void Application::sub_4c4fd8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c4fd8  ff2588644c00           -jmp dword ptr [0x4c6488]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006472), cpu);
}

/* align: skip  */
void Application::sub_4c4fde(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c4fde  ff259c654c00           -jmp dword ptr [0x4c659c]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006748), cpu);
}

/* align: skip  */
void Application::sub_4c4fe4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c4fe4  ff2520654c00           -jmp dword ptr [0x4c6520]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006624), cpu);
}

/* align: skip  */
void Application::sub_4c4fea(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c4fea  ff25a8654c00           -jmp dword ptr [0x4c65a8]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006760), cpu);
}

/* align: skip  */
void Application::sub_4c4ff0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c4ff0  ff25a4654c00           -jmp dword ptr [0x4c65a4]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006756), cpu);
}

/* align: skip  */
void Application::sub_4c4ff6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c4ff6  ff2564654c00           -jmp dword ptr [0x4c6564]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006692), cpu);
}

/* align: skip  */
void Application::sub_4c4ffc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c4ffc  ff2568644c00           -jmp dword ptr [0x4c6468]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006440), cpu);
}

/* align: skip  */
void Application::sub_4c5002(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c5002  ff2578644c00           -jmp dword ptr [0x4c6478]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006456), cpu);
}

/* align: skip  */
void Application::sub_4c5008(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c5008  ff25d0644c00           -jmp dword ptr [0x4c64d0]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006544), cpu);
}

/* align: skip  */
void Application::sub_4c500e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c500e  ff25c4644c00           -jmp dword ptr [0x4c64c4]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006532), cpu);
}

/* align: skip  */
void Application::sub_4c5014(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c5014  ff25cc644c00           -jmp dword ptr [0x4c64cc]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006540), cpu);
}

/* align: skip  */
void Application::sub_4c501a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c501a  ff25d4654c00           -jmp dword ptr [0x4c65d4]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006804), cpu);
}

/* align: skip  */
void Application::sub_4c5020(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c5020  ff25e0644c00           -jmp dword ptr [0x4c64e0]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006560), cpu);
}

/* align: skip  */
void Application::sub_4c5026(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c5026  ff2594644c00           -jmp dword ptr [0x4c6494]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006484), cpu);
}

/* align: skip  */
void Application::sub_4c502c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c502c  ff2574644c00           -jmp dword ptr [0x4c6474]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006452), cpu);
}

/* align: skip  */
void Application::sub_4c5032(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c5032  ff2584644c00           -jmp dword ptr [0x4c6484]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006468), cpu);
}

/* align: skip  */
void Application::sub_4c5038(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c5038  ff2538644c00           -jmp dword ptr [0x4c6438]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006392), cpu);
}

/* align: skip  */
void Application::sub_4c503e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c503e  ff25e0634c00           -jmp dword ptr [0x4c63e0]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006304), cpu);
}

/* align: skip  */
void Application::sub_4c5044(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c5044  ff2564644c00           -jmp dword ptr [0x4c6464]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006436), cpu);
}

/* align: skip  */
void Application::sub_4c504a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c504a  ff2530644c00           -jmp dword ptr [0x4c6430]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006384), cpu);
}

/* align: skip  */
void Application::sub_4c5050(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c5050  ff2544644c00           -jmp dword ptr [0x4c6444]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006404), cpu);
}

/* align: skip  */
void Application::sub_4c5056(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c5056  ff252c644c00           -jmp dword ptr [0x4c642c]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006380), cpu);
}

/* align: skip  */
void Application::sub_4c505c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c505c  ff2514644c00           -jmp dword ptr [0x4c6414]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006356), cpu);
}

/* align: skip  */
void Application::sub_4c5062(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c5062  ff25ac634c00           -jmp dword ptr [0x4c63ac]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006252), cpu);
}

/* align: skip  */
void Application::sub_4c5068(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c5068  ff2500644c00           -jmp dword ptr [0x4c6400]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006336), cpu);
}

/* align: skip  */
void Application::sub_4c506e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c506e  ff25d4634c00           -jmp dword ptr [0x4c63d4]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006292), cpu);
}

/* align: skip  */
void Application::sub_4c5074(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c5074  ff251c644c00           -jmp dword ptr [0x4c641c]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006364), cpu);
}

/* align: skip  */
void Application::sub_4c507a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c507a  ff25cc634c00           -jmp dword ptr [0x4c63cc]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006284), cpu);
}

/* align: skip  */
void Application::sub_4c5080(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c5080  ff25b4634c00           -jmp dword ptr [0x4c63b4]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006260), cpu);
}

/* align: skip  */
void Application::sub_4c5086(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c5086  ff25bc634c00           -jmp dword ptr [0x4c63bc]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006268), cpu);
}

/* align: skip  */
void Application::sub_4c508c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c508c  ff25e4634c00           -jmp dword ptr [0x4c63e4]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006308), cpu);
}

/* align: skip  */
void Application::sub_4c5092(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c5092  ff25d0634c00           -jmp dword ptr [0x4c63d0]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006288), cpu);
}

/* align: skip  */
void Application::sub_4c5098(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c5098  ff25dc634c00           -jmp dword ptr [0x4c63dc]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006300), cpu);
}

/* align: skip  */
void Application::sub_4c509e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c509e  ff25b8634c00           -jmp dword ptr [0x4c63b8]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006264), cpu);
}

/* align: skip  */
void Application::sub_4c50a4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c50a4  ff256c644c00           -jmp dword ptr [0x4c646c]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006444), cpu);
}

/* align: skip  */
void Application::sub_4c50aa(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c50aa  ff25e8634c00           -jmp dword ptr [0x4c63e8]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006312), cpu);
}

/* align: skip  */
void Application::sub_4c50b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c50b0  ff253c644c00           -jmp dword ptr [0x4c643c]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006396), cpu);
}

/* align: skip  */
void Application::sub_4c50b6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c50b6  ff250c644c00           -jmp dword ptr [0x4c640c]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006348), cpu);
}

/* align: skip  */
void Application::sub_4c50bc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c50bc  ff2524644c00           -jmp dword ptr [0x4c6424]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006372), cpu);
}

/* align: skip  */
void Application::sub_4c50c2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004c50c2  ff2518644c00           -jmp dword ptr [0x4c6418]
    return app->dynamic_call(app->getMemory<x86::reg32>(5006360), cpu);
}

}
