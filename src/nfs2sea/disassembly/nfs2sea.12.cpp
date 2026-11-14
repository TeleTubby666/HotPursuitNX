#include "nfs2sea.h"
#include <lib/thread.h>

namespace nfs2sea
{

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46db40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046db40  e9ab98fbff             -jmp 0x4273f0
    return sub_4273f0(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46db50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046db50  e8eb160000             -call 0x46f240
    cpu.esp -= 4;
    sub_46f240(app, cpu);
    if (cpu.terminate) return;
    // 0046db55  e9a698fbff             -jmp 0x427400
    return sub_427400(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46db60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046db60  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046db61  a1a4005200             -mov eax, dword ptr [0x5200a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5374116) /* 0x5200a4 */);
    // 0046db66  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046db68  e80312fcff             -call 0x42ed70
    cpu.esp -= 4;
    sub_42ed70(app, cpu);
    if (cpu.terminate) return;
    // 0046db6d  8915a4005200           -mov dword ptr [0x5200a4], edx
    app->getMemory<x86::reg32>(x86::reg32(5374116) /* 0x5200a4 */) = cpu.edx;
    // 0046db73  e848fa0000             -call 0x47d5c0
    cpu.esp -= 4;
    sub_47d5c0(app, cpu);
    if (cpu.terminate) return;
    // 0046db78  e89398fbff             -call 0x427410
    cpu.esp -= 4;
    sub_427410(app, cpu);
    if (cpu.terminate) return;
    // 0046db7d  e89e58fcff             -call 0x433420
    cpu.esp -= 4;
    sub_433420(app, cpu);
    if (cpu.terminate) return;
    // 0046db82  e8794b0000             -call 0x472700
    cpu.esp -= 4;
    sub_472700(app, cpu);
    if (cpu.terminate) return;
    // 0046db87  e884fb0000             -call 0x47d710
    cpu.esp -= 4;
    sub_47d710(app, cpu);
    if (cpu.terminate) return;
    // 0046db8c  e84f640000             -call 0x473fe0
    cpu.esp -= 4;
    sub_473fe0(app, cpu);
    if (cpu.terminate) return;
    // 0046db91  e8cac6feff             -call 0x45a260
    cpu.esp -= 4;
    sub_45a260(app, cpu);
    if (cpu.terminate) return;
    // 0046db96  e8559efeff             -call 0x4579f0
    cpu.esp -= 4;
    sub_4579f0(app, cpu);
    if (cpu.terminate) return;
    // 0046db9b  e8409efeff             -call 0x4579e0
    cpu.esp -= 4;
    sub_4579e0(app, cpu);
    if (cpu.terminate) return;
    // 0046dba0  e89bf6fbff             -call 0x42d240
    cpu.esp -= 4;
    sub_42d240(app, cpu);
    if (cpu.terminate) return;
    // 0046dba5  e8a6180000             -call 0x46f450
    cpu.esp -= 4;
    sub_46f450(app, cpu);
    if (cpu.terminate) return;
    // 0046dbaa  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046dbab  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_46dbb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046dbb0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046dbb1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046dbb3  e87858fcff             -call 0x433430
    cpu.esp -= 4;
    sub_433430(app, cpu);
    if (cpu.terminate) return;
    // 0046dbb8  8915a0005200           -mov dword ptr [0x5200a0], edx
    app->getMemory<x86::reg32>(x86::reg32(5374112) /* 0x5200a0 */) = cpu.edx;
    // 0046dbbe  e81d080000             -call 0x46e3e0
    cpu.esp -= 4;
    sub_46e3e0(app, cpu);
    if (cpu.terminate) return;
    // 0046dbc3  e86898fbff             -call 0x427430
    cpu.esp -= 4;
    sub_427430(app, cpu);
    if (cpu.terminate) return;
    // 0046dbc8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046dbc9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46dbd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046dbd0  e84b98fbff             -call 0x427420
    cpu.esp -= 4;
    sub_427420(app, cpu);
    if (cpu.terminate) return;
    // 0046dbd5  e8e6f7fdff             -call 0x44d3c0
    cpu.esp -= 4;
    sub_44d3c0(app, cpu);
    if (cpu.terminate) return;
    // 0046dbda  e841fb0000             -call 0x47d720
    cpu.esp -= 4;
    sub_47d720(app, cpu);
    if (cpu.terminate) return;
    // 0046dbdf  e82c4b0000             -call 0x472710
    cpu.esp -= 4;
    sub_472710(app, cpu);
    if (cpu.terminate) return;
    // 0046dbe4  e807640000             -call 0x473ff0
    cpu.esp -= 4;
    sub_473ff0(app, cpu);
    if (cpu.terminate) return;
    // 0046dbe9  e842e1fbff             -call 0x42bd30
    cpu.esp -= 4;
    sub_42bd30(app, cpu);
    if (cpu.terminate) return;
    // 0046dbee  e9dd8afcff             -jmp 0x4366d0
    return sub_4366d0(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46dc00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046dc00  e87b98fbff             -call 0x427480
    cpu.esp -= 4;
    sub_427480(app, cpu);
    if (cpu.terminate) return;
    // 0046dc05  e83658fcff             -call 0x433440
    cpu.esp -= 4;
    sub_433440(app, cpu);
    if (cpu.terminate) return;
    // 0046dc0a  e841f9fdff             -call 0x44d550
    cpu.esp -= 4;
    sub_44d550(app, cpu);
    if (cpu.terminate) return;
    // 0046dc0f  e81c4b0000             -call 0x472730
    cpu.esp -= 4;
    sub_472730(app, cpu);
    if (cpu.terminate) return;
    // 0046dc14  e817fb0000             -call 0x47d730
    cpu.esp -= 4;
    sub_47d730(app, cpu);
    if (cpu.terminate) return;
    // 0046dc19  e8e2630000             -call 0x474000
    cpu.esp -= 4;
    sub_474000(app, cpu);
    if (cpu.terminate) return;
    // 0046dc1e  e8dd9efeff             -call 0x457b00
    cpu.esp -= 4;
    sub_457b00(app, cpu);
    if (cpu.terminate) return;
    // 0046dc23  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 0046dc28  e843dd0000             -call 0x47b970
    cpu.esp -= 4;
    sub_47b970(app, cpu);
    if (cpu.terminate) return;
    // 0046dc2d  e8ae9efeff             -call 0x457ae0
    cpu.esp -= 4;
    sub_457ae0(app, cpu);
    if (cpu.terminate) return;
    // 0046dc32  e819f6fbff             -call 0x42d250
    cpu.esp -= 4;
    sub_42d250(app, cpu);
    if (cpu.terminate) return;
    // 0046dc37  e804e2fbff             -call 0x42be40
    cpu.esp -= 4;
    sub_42be40(app, cpu);
    if (cpu.terminate) return;
    // 0046dc3c  e8df85fcff             -call 0x436220
    cpu.esp -= 4;
    sub_436220(app, cpu);
    if (cpu.terminate) return;
    // 0046dc41  e82ac6feff             -call 0x45a270
    cpu.esp -= 4;
    sub_45a270(app, cpu);
    if (cpu.terminate) return;
    // 0046dc46  e925180000             -jmp 0x46f470
    return sub_46f470(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46dc50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046dc50  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046dc51  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0046dc56  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046dc58  e893c2feff             -call 0x459ef0
    cpu.esp -= 4;
    sub_459ef0(app, cpu);
    if (cpu.terminate) return;
    // 0046dc5d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046dc5f  741c                   -je 0x46dc7d
    if (cpu.flags.zf)
    {
        goto L_0x0046dc7d;
    }
    // 0046dc61  8b156c734d00           -mov edx, dword ptr [0x4d736c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5075820) /* 0x4d736c */);
    // 0046dc67  42                     -inc edx
    (cpu.edx)++;
    // 0046dc68  89156c734d00           -mov dword ptr [0x4d736c], edx
    app->getMemory<x86::reg32>(x86::reg32(5075820) /* 0x4d736c */) = cpu.edx;
    // 0046dc6e  83fa01                 +cmp edx, 1
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
    // 0046dc71  7e0a                   -jle 0x46dc7d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046dc7d;
    }
    // 0046dc73  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046dc74  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046dc76  891d6c734d00           -mov dword ptr [0x4d736c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5075820) /* 0x4d736c */) = cpu.ebx;
    // 0046dc7c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0046dc7d:
    // 0046dc7d  e8bef8fdff             -call 0x44d540
    cpu.esp -= 4;
    sub_44d540(app, cpu);
    if (cpu.terminate) return;
    // 0046dc82  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046dc83  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46dc90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046dc90  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046dc91  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046dc92  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046dc93  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046dc94  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046dc95  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046dc98  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046dc9a  833dd8ff500001         +cmp dword ptr [0x50ffd8], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5308376) /* 0x50ffd8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046dca1  0f84df000000           -je 0x46dd86
    if (cpu.flags.zf)
    {
        goto L_0x0046dd86;
    }
    // 0046dca7  a1a0005200             -mov eax, dword ptr [0x5200a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5374112) /* 0x5200a0 */);
    // 0046dcac  e87f010000             -call 0x46de30
    cpu.esp -= 4;
    sub_46de30(app, cpu);
    if (cpu.terminate) return;
    // 0046dcb1  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046dcb3  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046dcb5  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0046dcb7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046dcb9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046dcbb  e8c0010000             -call 0x46de80
    cpu.esp -= 4;
    sub_46de80(app, cpu);
    if (cpu.terminate) return;
    // 0046dcc0  833da000520000         +cmp dword ptr [0x5200a0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5374112) /* 0x5200a0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046dcc7  7568                   -jne 0x46dd31
    if (!cpu.flags.zf)
    {
        goto L_0x0046dd31;
    }
    // 0046dcc9  833d6c734d0000         +cmp dword ptr [0x4d736c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5075820) /* 0x4d736c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046dcd0  753b                   -jne 0x46dd0d
    if (!cpu.flags.zf)
    {
        goto L_0x0046dd0d;
    }
    // 0046dcd2  833d24fe500000         +cmp dword ptr [0x50fe24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5307940) /* 0x50fe24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046dcd9  7432                   -je 0x46dd0d
    if (cpu.flags.zf)
    {
        goto L_0x0046dd0d;
    }
    // 0046dcdb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046dcdd  e80ebffdff             -call 0x449bf0
    cpu.esp -= 4;
    sub_449bf0(app, cpu);
    if (cpu.terminate) return;
    // 0046dce2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046dce4  7427                   -je 0x46dd0d
    if (cpu.flags.zf)
    {
        goto L_0x0046dd0d;
    }
    // 0046dce6  8d5c2408               -lea ebx, [esp + 8]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046dcea  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046dcee  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0046dcf0  e8cb7e0000             -call 0x475bc0
    cpu.esp -= 4;
    sub_475bc0(app, cpu);
    if (cpu.terminate) return;
    // 0046dcf5  8b6c2408               -mov ebp, dword ptr [esp + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046dcf9  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046dcfd  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 0046dd00  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046dd01  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0046dd06  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046dd08  e873010000             -call 0x46de80
    cpu.esp -= 4;
    sub_46de80(app, cpu);
    if (cpu.terminate) return;
L_0x0046dd0d:
    // 0046dd0d  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0046dd0f  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0046dd14  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046dd16  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046dd18  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046dd1a  e861010000             -call 0x46de80
    cpu.esp -= 4;
    sub_46de80(app, cpu);
    if (cpu.terminate) return;
    // 0046dd1f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0046dd21  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 0046dd26  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046dd28  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046dd2a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0046dd2c:
    // 0046dd2c  e84f010000             -call 0x46de80
    cpu.esp -= 4;
    sub_46de80(app, cpu);
    if (cpu.terminate) return;
L_0x0046dd31:
    // 0046dd31  e8daa7fbff             -call 0x428510
    cpu.esp -= 4;
    sub_428510(app, cpu);
    if (cpu.terminate) return;
    // 0046dd36  e89597fbff             -call 0x4274d0
    cpu.esp -= 4;
    sub_4274d0(app, cpu);
    if (cpu.terminate) return;
    // 0046dd3b  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0046dd3d  0f84b3000000           -je 0x46ddf6
    if (cpu.flags.zf)
    {
        goto L_0x0046ddf6;
    }
    // 0046dd43  833da000520000         +cmp dword ptr [0x5200a0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5374112) /* 0x5200a0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046dd4a  7519                   -jne 0x46dd65
    if (!cpu.flags.zf)
    {
        goto L_0x0046dd65;
    }
    // 0046dd4c  c705a000520001000000   -mov dword ptr [0x5200a0], 1
    app->getMemory<x86::reg32>(x86::reg32(5374112) /* 0x5200a0 */) = 1 /*0x1*/;
    // 0046dd56  e8f50ffcff             -call 0x42ed50
    cpu.esp -= 4;
    sub_42ed50(app, cpu);
    if (cpu.terminate) return;
    // 0046dd5b  e83001ffff             -call 0x45de90
    cpu.esp -= 4;
    sub_45de90(app, cpu);
    if (cpu.terminate) return;
    // 0046dd60  e87b96fbff             -call 0x4273e0
    cpu.esp -= 4;
    sub_4273e0(app, cpu);
    if (cpu.terminate) return;
L_0x0046dd65:
    // 0046dd65  e83696fbff             -call 0x4273a0
    cpu.esp -= 4;
    sub_4273a0(app, cpu);
    if (cpu.terminate) return;
    // 0046dd6a  833d88744d0000         +cmp dword ptr [0x4d7488], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5076104) /* 0x4d7488 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046dd71  7505                   -jne 0x46dd78
    if (!cpu.flags.zf)
    {
        goto L_0x0046dd78;
    }
    // 0046dd73  e80802ffff             -call 0x45df80
    cpu.esp -= 4;
    sub_45df80(app, cpu);
    if (cpu.terminate) return;
L_0x0046dd78:
    // 0046dd78  e8f395fbff             -call 0x427370
    cpu.esp -= 4;
    sub_427370(app, cpu);
    if (cpu.terminate) return;
L_0x0046dd7d:
    // 0046dd7d  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046dd80  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046dd81  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046dd82  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046dd83  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046dd84  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046dd85  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046dd86:
    // 0046dd86  a1a0005200             -mov eax, dword ptr [0x5200a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5374112) /* 0x5200a0 */);
    // 0046dd8b  e8a0000000             -call 0x46de30
    cpu.esp -= 4;
    sub_46de30(app, cpu);
    if (cpu.terminate) return;
    // 0046dd90  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046dd92  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046dd94  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0046dd96  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046dd98  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046dd9a  e8e1000000             -call 0x46de80
    cpu.esp -= 4;
    sub_46de80(app, cpu);
    if (cpu.terminate) return;
    // 0046dd9f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0046dda1  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0046dda6  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046dda8  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046ddaa  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046ddac  e8cf000000             -call 0x46de80
    cpu.esp -= 4;
    sub_46de80(app, cpu);
    if (cpu.terminate) return;
    // 0046ddb1  a1a0005200             -mov eax, dword ptr [0x5200a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5374112) /* 0x5200a0 */);
    // 0046ddb6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046ddb8  0f8573ffffff           -jne 0x46dd31
    if (!cpu.flags.zf)
    {
        goto L_0x0046dd31;
    }
    // 0046ddbe  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046ddbf  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046ddc1  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046ddc3  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046ddc5  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0046ddca  e8b1000000             -call 0x46de80
    cpu.esp -= 4;
    sub_46de80(app, cpu);
    if (cpu.terminate) return;
    // 0046ddcf  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0046ddd1  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 0046ddd6  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046ddd8  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046ddda  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046dddc  e89f000000             -call 0x46de80
    cpu.esp -= 4;
    sub_46de80(app, cpu);
    if (cpu.terminate) return;
    // 0046dde1  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0046dde3  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0046dde8  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 0046dded  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046ddef  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0046ddf1  e936ffffff             -jmp 0x46dd2c
    goto L_0x0046dd2c;
L_0x0046ddf6:
    // 0046ddf6  833da000520000         +cmp dword ptr [0x5200a0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5374112) /* 0x5200a0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046ddfd  0f847affffff           -je 0x46dd7d
    if (cpu.flags.zf)
    {
        goto L_0x0046dd7d;
    }
    // 0046de03  8935a0005200           -mov dword ptr [0x5200a0], esi
    app->getMemory<x86::reg32>(x86::reg32(5374112) /* 0x5200a0 */) = cpu.esi;
    // 0046de09  e87200ffff             -call 0x45de80
    cpu.esp -= 4;
    sub_45de80(app, cpu);
    if (cpu.terminate) return;
    // 0046de0e  e8bd95fbff             -call 0x4273d0
    cpu.esp -= 4;
    sub_4273d0(app, cpu);
    if (cpu.terminate) return;
    // 0046de13  e8480ffcff             -call 0x42ed60
    cpu.esp -= 4;
    sub_42ed60(app, cpu);
    if (cpu.terminate) return;
    // 0046de18  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046de1b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046de1c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046de1d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046de1e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046de1f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046de20  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46de30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046de30  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046de31  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046de32  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046de34  e81789fdff             -call 0x446750
    cpu.esp -= 4;
    sub_446750(app, cpu);
    if (cpu.terminate) return;
    // 0046de39  e8124b0000             -call 0x472950
    cpu.esp -= 4;
    sub_472950(app, cpu);
    if (cpu.terminate) return;
    // 0046de3e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0046de40  7518                   -jne 0x46de5a
    if (!cpu.flags.zf)
    {
        goto L_0x0046de5a;
    }
    // 0046de42  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
L_0x0046de47:
    // 0046de47  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0046de49  7513                   -jne 0x46de5e
    if (!cpu.flags.zf)
    {
        goto L_0x0046de5e;
    }
    // 0046de4b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0046de50  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0046de52  e88996fbff             -call 0x4274e0
    cpu.esp -= 4;
    sub_4274e0(app, cpu);
    if (cpu.terminate) return;
    // 0046de57  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046de58  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046de59  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046de5a:
    // 0046de5a  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0046de5c  ebe9                   -jmp 0x46de47
    goto L_0x0046de47;
L_0x0046de5e:
    // 0046de5e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046de60  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0046de62  e87996fbff             -call 0x4274e0
    cpu.esp -= 4;
    sub_4274e0(app, cpu);
    if (cpu.terminate) return;
    // 0046de67  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046de68  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046de69  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46de80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0046de80  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046de81  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046de82  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0046de85  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046de87  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0046de89  a1a4005200             -mov eax, dword ptr [0x5200a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5374116) /* 0x5200a4 */);
    // 0046de8e  8935ac005200           -mov dword ptr [0x5200ac], esi
    app->getMemory<x86::reg32>(x86::reg32(5374124) /* 0x5200ac */) = cpu.esi;
    // 0046de94  8915b0005200           -mov dword ptr [0x5200b0], edx
    app->getMemory<x86::reg32>(x86::reg32(5374128) /* 0x5200b0 */) = cpu.edx;
    // 0046de9a  891d14015200           -mov dword ptr [0x520114], ebx
    app->getMemory<x86::reg32>(x86::reg32(5374228) /* 0x520114 */) = cpu.ebx;
    // 0046dea0  a3a8005200             -mov dword ptr [0x5200a8], eax
    app->getMemory<x86::reg32>(x86::reg32(5374120) /* 0x5200a8 */) = cpu.eax;
    // 0046dea5  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0046dea9  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046deab  a31c015200             -mov dword ptr [0x52011c], eax
    app->getMemory<x86::reg32>(x86::reg32(5374236) /* 0x52011c */) = cpu.eax;
    // 0046deb0  b8ac005200             -mov eax, 0x5200ac
    cpu.eax = 5374124 /*0x5200ac*/;
    // 0046deb5  890d18015200           -mov dword ptr [0x520118], ecx
    app->getMemory<x86::reg32>(x86::reg32(5374232) /* 0x520118 */) = cpu.ecx;
    // 0046debb  e810f5fdff             -call 0x44d3d0
    cpu.esp -= 4;
    sub_44d3d0(app, cpu);
    if (cpu.terminate) return;
    // 0046dec0  83fe03                 +cmp esi, 3
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
    // 0046dec3  7718                   -ja 0x46dedd
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0046dedd;
    }
    // 0046dec5  ff24b570de4600         -jmp dword ptr [esi*4 + 0x46de70]
    cpu.ip = app->getMemory<x86::reg32>(4644464 + cpu.esi * 4); goto dynamic_jump;
  case 0x0046decc:
    // 0046decc  b8ac005200             -mov eax, 0x5200ac
    cpu.eax = 5374124 /*0x5200ac*/;
    // 0046ded1  e88a86fdff             -call 0x446560
    cpu.esp -= 4;
    sub_446560(app, cpu);
    if (cpu.terminate) return;
    // 0046ded6  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0046ded8  e863000000             -call 0x46df40
    cpu.esp -= 4;
    sub_46df40(app, cpu);
    if (cpu.terminate) return;
L_0x0046dedd:
    // 0046dedd  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 0046dee2  b8ac005200             -mov eax, 0x5200ac
    cpu.eax = 5374124 /*0x5200ac*/;
    // 0046dee7  e8e4f4fdff             -call 0x44d3d0
    cpu.esp -= 4;
    sub_44d3d0(app, cpu);
    if (cpu.terminate) return;
    // 0046deec  8b1590005200           -mov edx, dword ptr [0x520090]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5374096) /* 0x520090 */);
    // 0046def2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046def3  8b0d8c005200           -mov ecx, dword ptr [0x52008c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5374092) /* 0x52008c */);
    // 0046def9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046defa  b8ac005200             -mov eax, 0x5200ac
    cpu.eax = 5374124 /*0x5200ac*/;
    // 0046deff  e82c96fbff             -call 0x427530
    cpu.esp -= 4;
    sub_427530(app, cpu);
    if (cpu.terminate) return;
    // 0046df04  83c410                 +add esp, 0x10
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
    // 0046df07  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046df08  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046df09  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
  case 0x0046df0c:
    // 0046df0c  b8ac005200             -mov eax, 0x5200ac
    cpu.eax = 5374124 /*0x5200ac*/;
    // 0046df11  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0046df13  bf8c005200             -mov edi, 0x52008c
    cpu.edi = 5374092 /*0x52008c*/;
    // 0046df18  e80390feff             -call 0x456f20
    cpu.esp -= 4;
    sub_456f20(app, cpu);
    if (cpu.terminate) return;
    // 0046df1d  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0046df1f  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0046df20  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0046df21  ebba                   -jmp 0x46dedd
    goto L_0x0046dedd;
  case 0x0046df23:
    // 0046df23  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046df27  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0046df29  e8f290feff             -call 0x457020
    cpu.esp -= 4;
    sub_457020(app, cpu);
    if (cpu.terminate) return;
    // 0046df2e  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046df32  bf8c005200             -mov edi, 0x52008c
    cpu.edi = 5374092 /*0x52008c*/;
    // 0046df37  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0046df38  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0046df39  eba2                   -jmp 0x46dedd
    goto L_0x0046dedd;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46df40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046df40  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046df41  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046df42  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046df43  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046df44  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046df45  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046df46  83ec48                 -sub esp, 0x48
    (cpu.esp) -= x86::reg32(x86::sreg32(72 /*0x48*/));
    // 0046df49  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046df4b  e880190000             -call 0x46f8d0
    cpu.esp -= 4;
    sub_46f8d0(app, cpu);
    if (cpu.terminate) return;
    // 0046df50  b8ac005200             -mov eax, 0x5200ac
    cpu.eax = 5374124 /*0x5200ac*/;
    // 0046df55  e876abfbff             -call 0x428ad0
    cpu.esp -= 4;
    sub_428ad0(app, cpu);
    if (cpu.terminate) return;
    // 0046df5a  b8ac005200             -mov eax, 0x5200ac
    cpu.eax = 5374124 /*0x5200ac*/;
    // 0046df5f  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0046df61  e8ca86fdff             -call 0x446630
    cpu.esp -= 4;
    sub_446630(app, cpu);
    if (cpu.terminate) return;
    // 0046df66  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046df68  bf8c005200             -mov edi, 0x52008c
    cpu.edi = 5374092 /*0x52008c*/;
    // 0046df6d  e8ae010000             -call 0x46e120
    cpu.esp -= 4;
    sub_46e120(app, cpu);
    if (cpu.terminate) return;
    // 0046df72  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0046df74  b8ac005200             -mov eax, 0x5200ac
    cpu.eax = 5374124 /*0x5200ac*/;
    // 0046df79  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0046df7a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0046df7b  e800c3feff             -call 0x45a280
    cpu.esp -= 4;
    sub_45a280(app, cpu);
    if (cpu.terminate) return;
    // 0046df80  b88c005200             -mov eax, 0x52008c
    cpu.eax = 5374092 /*0x52008c*/;
    // 0046df85  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046df89  bf8c005200             -mov edi, 0x52008c
    cpu.edi = 5374092 /*0x52008c*/;
    // 0046df8e  e88d010000             -call 0x46e120
    cpu.esp -= 4;
    sub_46e120(app, cpu);
    if (cpu.terminate) return;
    // 0046df93  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046df97  b8ac005200             -mov eax, 0x5200ac
    cpu.eax = 5374124 /*0x5200ac*/;
    // 0046df9c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0046df9d  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0046df9e  e8ddf70000             -call 0x47d780
    cpu.esp -= 4;
    sub_47d780(app, cpu);
    if (cpu.terminate) return;
    // 0046dfa3  b88c005200             -mov eax, 0x52008c
    cpu.eax = 5374092 /*0x52008c*/;
    // 0046dfa8  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046dfac  bf8c005200             -mov edi, 0x52008c
    cpu.edi = 5374092 /*0x52008c*/;
    // 0046dfb1  e86a010000             -call 0x46e120
    cpu.esp -= 4;
    sub_46e120(app, cpu);
    if (cpu.terminate) return;
    // 0046dfb6  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046dfba  b8ac005200             -mov eax, 0x5200ac
    cpu.eax = 5374124 /*0x5200ac*/;
    // 0046dfbf  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0046dfc0  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0046dfc1  e83accffff             -call 0x46ac00
    cpu.esp -= 4;
    sub_46ac00(app, cpu);
    if (cpu.terminate) return;
    // 0046dfc6  b88c005200             -mov eax, 0x52008c
    cpu.eax = 5374092 /*0x52008c*/;
    // 0046dfcb  8d742418               -lea esi, [esp + 0x18]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046dfcf  bf8c005200             -mov edi, 0x52008c
    cpu.edi = 5374092 /*0x52008c*/;
    // 0046dfd4  e847010000             -call 0x46e120
    cpu.esp -= 4;
    sub_46e120(app, cpu);
    if (cpu.terminate) return;
    // 0046dfd9  8d742418               -lea esi, [esp + 0x18]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046dfdd  b8ac005200             -mov eax, 0x5200ac
    cpu.eax = 5374124 /*0x5200ac*/;
    // 0046dfe2  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0046dfe3  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0046dfe4  e867470000             -call 0x472750
    cpu.esp -= 4;
    sub_472750(app, cpu);
    if (cpu.terminate) return;
    // 0046dfe9  b88c005200             -mov eax, 0x52008c
    cpu.eax = 5374092 /*0x52008c*/;
    // 0046dfee  8d742420               -lea esi, [esp + 0x20]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0046dff2  bf8c005200             -mov edi, 0x52008c
    cpu.edi = 5374092 /*0x52008c*/;
    // 0046dff7  e8c4000000             -call 0x46e0c0
    cpu.esp -= 4;
    sub_46e0c0(app, cpu);
    if (cpu.terminate) return;
    // 0046dffc  8d742420               -lea esi, [esp + 0x20]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0046e000  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0046e001  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0046e002  b8ac005200             -mov eax, 0x5200ac
    cpu.eax = 5374124 /*0x5200ac*/;
    // 0046e007  8d742428               -lea esi, [esp + 0x28]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0046e00b  e85061fcff             -call 0x434160
    cpu.esp -= 4;
    sub_434160(app, cpu);
    if (cpu.terminate) return;
    // 0046e010  8b54242c               -mov edx, dword ptr [esp + 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0046e014  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046e015  8b5c242c               -mov ebx, dword ptr [esp + 0x2c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0046e019  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046e01a  8b3590005200           -mov esi, dword ptr [0x520090]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5374096) /* 0x520090 */);
    // 0046e020  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046e021  8b3d8c005200           -mov edi, dword ptr [0x52008c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5374092) /* 0x52008c */);
    // 0046e027  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046e028  8d742440               -lea esi, [esp + 0x40]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0046e02c  e86f020000             -call 0x46e2a0
    cpu.esp -= 4;
    sub_46e2a0(app, cpu);
    if (cpu.terminate) return;
    // 0046e031  8d742430               -lea esi, [esp + 0x30]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0046e035  bf8c005200             -mov edi, 0x52008c
    cpu.edi = 5374092 /*0x52008c*/;
    // 0046e03a  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0046e03f  b8ac005200             -mov eax, 0x5200ac
    cpu.eax = 5374124 /*0x5200ac*/;
    // 0046e044  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0046e045  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0046e046  e885f3fdff             -call 0x44d3d0
    cpu.esp -= 4;
    sub_44d3d0(app, cpu);
    if (cpu.terminate) return;
    // 0046e04b  8b2d90005200           -mov ebp, dword ptr [0x520090]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5374096) /* 0x520090 */);
    // 0046e051  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046e052  a18c005200             -mov eax, dword ptr [0x52008c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5374092) /* 0x52008c */);
    // 0046e057  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046e058  8d742440               -lea esi, [esp + 0x40]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0046e05c  b8ac005200             -mov eax, 0x5200ac
    cpu.eax = 5374124 /*0x5200ac*/;
    // 0046e061  e82abafeff             -call 0x459a90
    cpu.esp -= 4;
    sub_459a90(app, cpu);
    if (cpu.terminate) return;
    // 0046e066  8b542444               -mov edx, dword ptr [esp + 0x44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0046e06a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046e06b  8b5c2444               -mov ebx, dword ptr [esp + 0x44]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0046e06f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046e070  8d742450               -lea esi, [esp + 0x50]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 0046e074  bf8c005200             -mov edi, 0x52008c
    cpu.edi = 5374092 /*0x52008c*/;
    // 0046e079  e822020000             -call 0x46e2a0
    cpu.esp -= 4;
    sub_46e2a0(app, cpu);
    if (cpu.terminate) return;
    // 0046e07e  8d742440               -lea esi, [esp + 0x40]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0046e082  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0046e083  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0046e084  83f901                 +cmp ecx, 1
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
    // 0046e087  740a                   -je 0x46e093
    if (cpu.flags.zf)
    {
        goto L_0x0046e093;
    }
    // 0046e089  83c448                 -add esp, 0x48
    (cpu.esp) += x86::reg32(x86::sreg32(72 /*0x48*/));
    // 0046e08c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e08d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e08e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e08f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e090  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e091  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e092  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046e093:
    // 0046e093  b946000000             -mov ecx, 0x46
    cpu.ecx = 70 /*0x46*/;
    // 0046e098  bb96000000             -mov ebx, 0x96
    cpu.ebx = 150 /*0x96*/;
    // 0046e09d  ba28000000             -mov edx, 0x28
    cpu.edx = 40 /*0x28*/;
    // 0046e0a2  b8e6010000             -mov eax, 0x1e6
    cpu.eax = 486 /*0x1e6*/;
    // 0046e0a7  e8c4000000             -call 0x46e170
    cpu.esp -= 4;
    sub_46e170(app, cpu);
    if (cpu.terminate) return;
    // 0046e0ac  83c448                 -add esp, 0x48
    (cpu.esp) += x86::reg32(x86::sreg32(72 /*0x48*/));
    // 0046e0af  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e0b0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e0b1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e0b2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e0b3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e0b4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e0b5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46e0c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046e0c0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046e0c1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046e0c2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046e0c3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046e0c4  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046e0c7  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0046e0c9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046e0cb  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0046e0cd  e80e140000             -call 0x46f4e0
    cpu.esp -= 4;
    sub_46f4e0(app, cpu);
    if (cpu.terminate) return;
    // 0046e0d2  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0046e0d4  7510                   -jne 0x46e0e6
    if (!cpu.flags.zf)
    {
        goto L_0x0046e0e6;
    }
    // 0046e0d6  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0046e0d8  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0046e0da  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0046e0db  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0046e0dc  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046e0de  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046e0e1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e0e2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e0e3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e0e4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e0e5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046e0e6:
    // 0046e0e6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046e0e7  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046e0eb  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046e0ec  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046e0f0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046e0f1  8b7904                 -mov edi, dword ptr [ecx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0046e0f4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046e0f5  8b29                   -mov ebp, dword ptr [ecx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx);
    // 0046e0f7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046e0f8  8d742414               -lea esi, [esp + 0x14]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046e0fc  e89f010000             -call 0x46e2a0
    cpu.esp -= 4;
    sub_46e2a0(app, cpu);
    if (cpu.terminate) return;
    // 0046e101  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e102  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0046e104  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0046e106  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0046e107  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0046e108  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046e10a  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046e10d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e10e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e10f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e110  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e111  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46e120(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046e120  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046e121  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046e122  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046e123  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046e124  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046e127  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0046e129  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046e12b  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0046e12d  e8ae130000             -call 0x46f4e0
    cpu.esp -= 4;
    sub_46f4e0(app, cpu);
    if (cpu.terminate) return;
    // 0046e132  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0046e134  7515                   -jne 0x46e14b
    if (!cpu.flags.zf)
    {
        goto L_0x0046e14b;
    }
L_0x0046e136:
    // 0046e136  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0046e138  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0046e13a  e891170000             -call 0x46f8d0
    cpu.esp -= 4;
    sub_46f8d0(app, cpu);
    if (cpu.terminate) return;
    // 0046e13f  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0046e140  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0046e141  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046e143  83c408                 +add esp, 8
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
    // 0046e146  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e147  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e148  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e149  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e14a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046e14b:
    // 0046e14b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046e14c  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046e150  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046e151  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046e155  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046e156  8b7904                 -mov edi, dword ptr [ecx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0046e159  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046e15a  8b29                   -mov ebp, dword ptr [ecx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx);
    // 0046e15c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046e15d  8d742414               -lea esi, [esp + 0x14]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046e161  e83a010000             -call 0x46e2a0
    cpu.esp -= 4;
    sub_46e2a0(app, cpu);
    if (cpu.terminate) return;
    // 0046e166  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e167  ebcd                   -jmp 0x46e136
    goto L_0x0046e136;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46e170(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046e170  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046e171  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046e172  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0046e175  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0046e177  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0046e179  ba14000000             -mov edx, 0x14
    cpu.edx = 20 /*0x14*/;
    // 0046e17e  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0046e180  e8eb010000             -call 0x46e370
    cpu.esp -= 4;
    sub_46e370(app, cpu);
    if (cpu.terminate) return;
    // 0046e185  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046e187  7506                   -jne 0x46e18f
    if (!cpu.flags.zf)
    {
        goto L_0x0046e18f;
    }
    // 0046e189  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0046e18c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e18d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e18e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046e18f:
    // 0046e18f  ba14000000             -mov edx, 0x14
    cpu.edx = 20 /*0x14*/;
    // 0046e194  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0046e196  e805020000             -call 0x46e3a0
    cpu.esp -= 4;
    sub_46e3a0(app, cpu);
    if (cpu.terminate) return;
    // 0046e19b  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0046e19e  8b158c005200           -mov edx, dword ptr [0x52008c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5374092) /* 0x52008c */);
    // 0046e1a4  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0046e1a6  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0046e1a9  c7400418000000         -mov dword ptr [eax + 4], 0x18
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 24 /*0x18*/;
    // 0046e1b0  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0046e1b3  66c740080100           -mov word ptr [eax + 8], 1
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(8) /* 0x8 */) = 1 /*0x1*/;
    // 0046e1b9  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0046e1bc  6689780a               -mov word ptr [eax + 0xa], di
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(10) /* 0xa */) = cpu.di;
    // 0046e1c0  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0046e1c3  6689700c               -mov word ptr [eax + 0xc], si
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.si;
    // 0046e1c7  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0046e1ca  01df                   -add edi, ebx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0046e1cc  6689780e               -mov word ptr [eax + 0xe], di
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(14) /* 0xe */) = cpu.di;
    // 0046e1d0  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0046e1d3  01ce                   -add esi, ecx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046e1d5  66897010               -mov word ptr [eax + 0x10], si
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.si;
    // 0046e1d9  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0046e1dc  a38c005200             -mov dword ptr [0x52008c], eax
    app->getMemory<x86::reg32>(x86::reg32(5374092) /* 0x52008c */) = cpu.eax;
    // 0046e1e1  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0046e1e4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e1e5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e1e6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46e1f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046e1f0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046e1f1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046e1f2  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046e1f5  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0046e1f7  8b159c005200           -mov edx, dword ptr [0x52009c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5374108) /* 0x52009c */);
    // 0046e1fd  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0046e200  8b1598005200           -mov edx, dword ptr [0x520098]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5374104) /* 0x520098 */);
    // 0046e206  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0046e20a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0046e20c  750c                   -jne 0x46e21a
    if (!cpu.flags.zf)
    {
        goto L_0x0046e21a;
    }
    // 0046e20e  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0046e210  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0046e212  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0046e213  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0046e214  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046e217  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e218  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e219  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046e21a:
    // 0046e21a  c70200000000           -mov dword ptr [edx], 0
    app->getMemory<x86::reg32>(cpu.edx) = 0 /*0x0*/;
    // 0046e220  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0046e222  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0046e224  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0046e225  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0046e226  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046e229  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e22a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e22b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_46e230(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046e230  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046e231  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046e233  e868010000             -call 0x46e3a0
    cpu.esp -= 4;
    sub_46e3a0(app, cpu);
    if (cpu.terminate) return;
    // 0046e238  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046e23a  741e                   -je 0x46e25a
    if (cpu.flags.zf)
    {
        goto L_0x0046e25a;
    }
    // 0046e23c  833d9c00520000         +cmp dword ptr [0x52009c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5374108) /* 0x52009c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046e243  7417                   -je 0x46e25c
    if (cpu.flags.zf)
    {
        goto L_0x0046e25c;
    }
    // 0046e245  a198005200             -mov eax, dword ptr [0x520098]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5374104) /* 0x520098 */);
    // 0046e24a  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 0046e24c  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0046e24e  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0046e250  a398005200             -mov dword ptr [0x520098], eax
    app->getMemory<x86::reg32>(x86::reg32(5374104) /* 0x520098 */) = cpu.eax;
    // 0046e255  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0046e25a:
    // 0046e25a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e25b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046e25c:
    // 0046e25c  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0046e25e  a39c005200             -mov dword ptr [0x52009c], eax
    app->getMemory<x86::reg32>(x86::reg32(5374108) /* 0x52009c */) = cpu.eax;
    // 0046e263  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0046e265  a398005200             -mov dword ptr [0x520098], eax
    app->getMemory<x86::reg32>(x86::reg32(5374104) /* 0x520098 */) = cpu.eax;
    // 0046e26a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0046e26f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e270  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46e280(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046e280  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046e281  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046e283  891598005200           -mov dword ptr [0x520098], edx
    app->getMemory<x86::reg32>(x86::reg32(5374104) /* 0x520098 */) = cpu.edx;
    // 0046e289  89159c005200           -mov dword ptr [0x52009c], edx
    app->getMemory<x86::reg32>(x86::reg32(5374108) /* 0x52009c */) = cpu.edx;
    // 0046e28f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e290  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46e2a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046e2a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046e2a1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046e2a2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046e2a3  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046e2a6  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0046e2a8  837c241800             +cmp dword ptr [esp + 0x18], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046e2ad  7421                   -je 0x46e2d0
    if (cpu.flags.zf)
    {
        goto L_0x0046e2d0;
    }
    // 0046e2af  8b5c2420               -mov ebx, dword ptr [esp + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0046e2b3  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0046e2b5  7521                   -jne 0x46e2d8
    if (!cpu.flags.zf)
    {
        goto L_0x0046e2d8;
    }
    // 0046e2b7  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0046e2b9  8d742418               -lea esi, [esp + 0x18]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
L_0x0046e2bd:
    // 0046e2bd  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0046e2be  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0046e2bf  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0046e2c1  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0046e2c3  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0046e2c4  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0046e2c5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046e2c7  83c408                 +add esp, 8
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
    // 0046e2ca  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e2cb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e2cc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e2cd  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x0046e2d0:
    // 0046e2d0  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0046e2d2  8d742420               -lea esi, [esp + 0x20]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0046e2d6  ebe5                   -jmp 0x46e2bd
    goto L_0x0046e2bd;
L_0x0046e2d8:
    // 0046e2d8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046e2d9  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0046e2dd  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0046e2e1  8d7c2404               -lea edi, [esp + 4]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046e2e5  8d74241c               -lea esi, [esp + 0x1c]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0046e2e9  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0046e2ed  8919                   -mov dword ptr [ecx], ebx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.ebx;
    // 0046e2ef  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0046e2f0  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0046e2f1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e2f2  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0046e2f4  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0046e2f6  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0046e2f7  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0046e2f8  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046e2fa  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046e2fd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e2fe  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e2ff  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e300  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46e310(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046e310  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046e311  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046e312  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046e315  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0046e317  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0046e31a  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0046e31e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046e320  750e                   -jne 0x46e330
    if (!cpu.flags.zf)
    {
        goto L_0x0046e330;
    }
    // 0046e322  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0046e324  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0046e326  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0046e327  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0046e328  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046e32a  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046e32d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e32e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e32f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046e330:
    // 0046e330  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 0046e336  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0046e338  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0046e33a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0046e33b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0046e33c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046e33e  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046e341  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e342  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e343  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46e350(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046e350  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046e351  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046e352  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046e355  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0046e357  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 0046e359  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046e35b  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0046e35d  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0046e361  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0046e364  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0046e365  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0046e366  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046e369  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e36a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e36b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_46e370(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046e370  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046e371  8b15a8005200           -mov edx, dword ptr [0x5200a8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5374120) /* 0x5200a8 */);
    // 0046e377  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0046e379  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046e37b  8b15a4005200           -mov edx, dword ptr [0x5200a4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5374116) /* 0x5200a4 */);
    // 0046e381  8b0d94005200           -mov ecx, dword ptr [0x520094]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5374100) /* 0x520094 */);
    // 0046e387  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0046e389  39c8                   +cmp eax, ecx
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
    // 0046e38b  7e04                   -jle 0x46e391
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046e391;
    }
    // 0046e38d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046e38f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e390  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046e391:
    // 0046e391  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0046e396  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e397  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46e3a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046e3a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046e3a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046e3a2  8b1da8005200           -mov ebx, dword ptr [0x5200a8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5374120) /* 0x5200a8 */);
    // 0046e3a8  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 0046e3aa  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046e3ac  8b15a4005200           -mov edx, dword ptr [0x5200a4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5374116) /* 0x5200a4 */);
    // 0046e3b2  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0046e3b4  8b0d94005200           -mov ecx, dword ptr [0x520094]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5374100) /* 0x520094 */);
    // 0046e3ba  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0046e3bc  39c8                   +cmp eax, ecx
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
    // 0046e3be  7e0b                   -jle 0x46e3cb
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046e3cb;
    }
    // 0046e3c0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046e3c2  891da8005200           -mov dword ptr [0x5200a8], ebx
    app->getMemory<x86::reg32>(x86::reg32(5374120) /* 0x5200a8 */) = cpu.ebx;
    // 0046e3c8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e3c9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e3ca  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046e3cb:
    // 0046e3cb  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0046e3d0  891da8005200           -mov dword ptr [0x5200a8], ebx
    app->getMemory<x86::reg32>(x86::reg32(5374120) /* 0x5200a8 */) = cpu.ebx;
    // 0046e3d6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e3d7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e3d8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46e3e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046e3e0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046e3e1  b894005200             -mov eax, 0x520094
    cpu.eax = 5374100 /*0x520094*/;
    // 0046e3e6  e89509fcff             -call 0x42ed80
    cpu.esp -= 4;
    sub_42ed80(app, cpu);
    if (cpu.terminate) return;
    // 0046e3eb  8b1594005200           -mov edx, dword ptr [0x520094]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5374100) /* 0x520094 */);
    // 0046e3f1  a3a4005200             -mov dword ptr [0x5200a4], eax
    app->getMemory<x86::reg32>(x86::reg32(5374116) /* 0x5200a4 */) = cpu.eax;
    // 0046e3f6  83ea64                 -sub edx, 0x64
    (cpu.edx) -= x86::reg32(x86::sreg32(100 /*0x64*/));
    // 0046e3f9  a3a8005200             -mov dword ptr [0x5200a8], eax
    app->getMemory<x86::reg32>(x86::reg32(5374120) /* 0x5200a8 */) = cpu.eax;
    // 0046e3fe  891594005200           -mov dword ptr [0x520094], edx
    app->getMemory<x86::reg32>(x86::reg32(5374100) /* 0x520094 */) = cpu.edx;
    // 0046e404  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e405  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46e410(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046e410  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046e411  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046e412  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046e413  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046e414  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046e415  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046e416  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046e418  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046e41b  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046e41d  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046e420  8b3518ed5300           -mov esi, dword ptr [0x53ed18]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5500184) /* 0x53ed18 */);
    // 0046e426  8b9090055200           -mov edx, dword ptr [eax + 0x520590]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5375376) /* 0x520590 */);
    // 0046e42c  81ee00020000           -sub esi, 0x200
    (cpu.esi) -= x86::reg32(x86::sreg32(512 /*0x200*/));
    // 0046e432  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0046e434  0f85d1000000           -jne 0x46e50b
    if (!cpu.flags.zf)
    {
        goto L_0x0046e50b;
    }
    // 0046e43a  8b808c055200           -mov eax, dword ptr [eax + 0x52058c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5375372) /* 0x52058c */);
    // 0046e440  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046e443  8b98a0734d00           -mov ebx, dword ptr [eax + 0x4d73a0]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5075872) /* 0x4d73a0 */);
    // 0046e449  83fb06                 +cmp ebx, 6
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046e44c  0f85c0000000           -jne 0x46e512
    if (!cpu.flags.zf)
    {
        goto L_0x0046e512;
    }
L_0x0046e452:
    // 0046e452  ba80020000             -mov edx, 0x280
    cpu.edx = 640 /*0x280*/;
L_0x0046e457:
    // 0046e457  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 0046e45e  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046e460  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046e463  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0046e465  2b9884055200           -sub ebx, dword ptr [eax + 0x520584]
    (cpu.ebx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5375364) /* 0x520584 */)));
    // 0046e46b  39d3                   +cmp ebx, edx
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
    // 0046e46d  0f8e98000000           -jle 0x46e50b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046e50b;
    }
    // 0046e473  8b808c055200           -mov eax, dword ptr [eax + 0x52058c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5375372) /* 0x52058c */);
    // 0046e479  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046e47c  8b90a0734d00           -mov edx, dword ptr [eax + 0x4d73a0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5075872) /* 0x4d73a0 */);
    // 0046e482  83fa06                 +cmp edx, 6
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
    // 0046e485  7405                   -je 0x46e48c
    if (cpu.flags.zf)
    {
        goto L_0x0046e48c;
    }
    // 0046e487  83fa05                 +cmp edx, 5
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
    // 0046e48a  7514                   -jne 0x46e4a0
    if (!cpu.flags.zf)
    {
        goto L_0x0046e4a0;
    }
L_0x0046e48c:
    // 0046e48c  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 0046e493  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046e495  c704859005520001000000 -mov dword ptr [eax*4 + 0x520590], 1
    app->getMemory<x86::reg32>(x86::reg32(5375376) /* 0x520590 */ + cpu.eax * 4) = 1 /*0x1*/;
L_0x0046e4a0:
    // 0046e4a0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046e4a2  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0046e4a5  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046e4a7  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0046e4aa  8b80903a4d00           -mov eax, dword ptr [eax + 0x4d3a90]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5061264) /* 0x4d3a90 */);
    // 0046e4b0  83b88802000000         +cmp dword ptr [eax + 0x288], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(648) /* 0x288 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046e4b7  746c                   -je 0x46e525
    if (cpu.flags.zf)
    {
        goto L_0x0046e525;
    }
    // 0046e4b9  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 0046e4be  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 0046e4c5  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0046e4c7  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046e4c9  8915a4734d00           -mov dword ptr [0x4d73a4], edx
    app->getMemory<x86::reg32>(x86::reg32(5075876) /* 0x4d73a4 */) = cpu.edx;
    // 0046e4cf  8915b0734d00           -mov dword ptr [0x4d73b0], edx
    app->getMemory<x86::reg32>(x86::reg32(5075888) /* 0x4d73b0 */) = cpu.edx;
    // 0046e4d5  89348590055200         -mov dword ptr [eax*4 + 0x520590], esi
    app->getMemory<x86::reg32>(x86::reg32(5375376) /* 0x520590 */ + cpu.eax * 4) = cpu.esi;
L_0x0046e4dc:
    // 0046e4dc  8d1c8d00000000         -lea ebx, [ecx*4]
    cpu.ebx = x86::reg32(cpu.ecx * 4);
    // 0046e4e3  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046e4e5  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 0046e4e8  8b938c055200           -mov edx, dword ptr [ebx + 0x52058c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5375372) /* 0x52058c */);
    // 0046e4ee  42                     -inc edx
    (cpu.edx)++;
    // 0046e4ef  be06000000             -mov esi, 6
    cpu.esi = 6 /*0x6*/;
    // 0046e4f4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046e4f6  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0046e4f9  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0046e4fb  8bbb90055200           -mov edi, dword ptr [ebx + 0x520590]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5375376) /* 0x520590 */);
    // 0046e501  89938c055200           -mov dword ptr [ebx + 0x52058c], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5375372) /* 0x52058c */) = cpu.edx;
    // 0046e507  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0046e509  742d                   -je 0x46e538
    if (cpu.flags.zf)
    {
        goto L_0x0046e538;
    }
L_0x0046e50b:
    // 0046e50b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e50c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e50d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e50e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e50f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e510  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e511  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046e512:
    // 0046e512  83fb05                 +cmp ebx, 5
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046e515  0f8437ffffff           -je 0x46e452
    if (cpu.flags.zf)
    {
        goto L_0x0046e452;
    }
    // 0046e51b  ba40010000             -mov edx, 0x140
    cpu.edx = 320 /*0x140*/;
    // 0046e520  e932ffffff             -jmp 0x46e457
    goto L_0x0046e457;
L_0x0046e525:
    // 0046e525  bd06000000             -mov ebp, 6
    cpu.ebp = 6 /*0x6*/;
    // 0046e52a  892da4734d00           -mov dword ptr [0x4d73a4], ebp
    app->getMemory<x86::reg32>(x86::reg32(5075876) /* 0x4d73a4 */) = cpu.ebp;
    // 0046e530  892db0734d00           -mov dword ptr [0x4d73b0], ebp
    app->getMemory<x86::reg32>(x86::reg32(5075888) /* 0x4d73b0 */) = cpu.ebp;
    // 0046e536  eba4                   -jmp 0x46e4dc
    goto L_0x0046e4dc;
L_0x0046e538:
    // 0046e538  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046e53a  e811000000             -call 0x46e550
    cpu.esp -= 4;
    sub_46e550(app, cpu);
    if (cpu.terminate) return;
    // 0046e53f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e540  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e541  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e542  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e543  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e544  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e545  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46e550(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046e550  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046e551  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046e552  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046e553  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046e554  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046e556  833d64eb530002         +cmp dword ptr [0x53eb64], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5499748) /* 0x53eb64 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046e55d  7528                   -jne 0x46e587
    if (!cpu.flags.zf)
    {
        goto L_0x0046e587;
    }
    // 0046e55f  e8bbb80200             -call 0x499e1f
    cpu.esp -= 4;
    sub_499e1f(app, cpu);
    if (cpu.terminate) return;
    // 0046e564  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046e566  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0046e569  c1e20b                 +shl edx, 0xb
    {
        x86::reg8 tmp = 11 /*0xb*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0046e56c  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0046e56e  c1f80b                 -sar eax, 0xb
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (11 /*0xb*/ % 32));
    // 0046e571  83f804                 +cmp eax, 4
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
    // 0046e574  7d6e                   -jge 0x46e5e4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0046e5e4;
    }
    // 0046e576  83f802                 +cmp eax, 2
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
    // 0046e579  7d62                   -jge 0x46e5dd
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0046e5dd;
    }
    // 0046e57b  ba7a540000             -mov edx, 0x547a
    cpu.edx = 21626 /*0x547a*/;
L_0x0046e580:
    // 0046e580  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x0046e582:
    // 0046e582  e809b2fdff             -call 0x449790
    cpu.esp -= 4;
    sub_449790(app, cpu);
    if (cpu.terminate) return;
L_0x0046e587:
    // 0046e587  8d1c8d00000000         -lea ebx, [ecx*4]
    cpu.ebx = x86::reg32(cpu.ecx * 4);
    // 0046e58e  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046e590  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 0046e593  8b938c055200           -mov edx, dword ptr [ebx + 0x52058c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5375372) /* 0x52058c */);
    // 0046e599  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046e59b  8b1495a0734d00         -mov edx, dword ptr [edx*4 + 0x4d73a0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5075872) /* 0x4d73a0 */ + cpu.edx * 4);
    // 0046e5a2  e819b5fdff             -call 0x449ac0
    cpu.esp -= 4;
    sub_449ac0(app, cpu);
    if (cpu.terminate) return;
    // 0046e5a7  8b838c055200           -mov eax, dword ptr [ebx + 0x52058c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5375372) /* 0x52058c */);
    // 0046e5ad  833c85a0734d0006       +cmp dword ptr [eax*4 + 0x4d73a0], 6
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5075872) /* 0x4d73a0 */ + cpu.eax * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046e5b5  7433                   -je 0x46e5ea
    if (cpu.flags.zf)
    {
        goto L_0x0046e5ea;
    }
L_0x0046e5b7:
    // 0046e5b7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046e5b9  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 0046e5bc  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046e5be  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0046e5c0  a118ed5300             -mov eax, dword ptr [0x53ed18]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5500184) /* 0x53ed18 */);
    // 0046e5c5  89348d90055200         -mov dword ptr [ecx*4 + 0x520590], esi
    app->getMemory<x86::reg32>(x86::reg32(5375376) /* 0x520590 */ + cpu.ecx * 4) = cpu.esi;
    // 0046e5cc  2d00020000             +sub eax, 0x200
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(512 /*0x200*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0046e5d1  89048d84055200         -mov dword ptr [ecx*4 + 0x520584], eax
    app->getMemory<x86::reg32>(x86::reg32(5375364) /* 0x520584 */ + cpu.ecx * 4) = cpu.eax;
    // 0046e5d8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e5d9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
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
L_0x0046e5dd:
    // 0046e5dd  ba86abffff             -mov edx, 0xffffab86
    cpu.edx = 4294945670 /*0xffffab86*/;
    // 0046e5e2  eb9c                   -jmp 0x46e580
    goto L_0x0046e580;
L_0x0046e5e4:
    // 0046e5e4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046e5e6  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0046e5e8  eb98                   -jmp 0x46e582
    goto L_0x0046e582;
L_0x0046e5ea:
    // 0046e5ea  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046e5ec  e87fd3fdff             -call 0x44b970
    cpu.esp -= 4;
    sub_44b970(app, cpu);
    if (cpu.terminate) return;
    // 0046e5f1  ebc4                   -jmp 0x46e5b7
    goto L_0x0046e5b7;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46e610(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0046e610  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046e611  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046e612  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046e613  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046e614  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046e615  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046e616  a16c055200             -mov eax, dword ptr [0x52056c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5375340) /* 0x52056c */);
    // 0046e61b  8b14857c734d00         -mov edx, dword ptr [eax*4 + 0x4d737c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5075836) /* 0x4d737c */ + cpu.eax * 4);
    // 0046e622  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0046e627  83fa05                 +cmp edx, 5
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
    // 0046e62a  7513                   -jne 0x46e63f
    if (!cpu.flags.zf)
    {
        goto L_0x0046e63f;
    }
    // 0046e62c  803d983a4d0007         +cmp byte ptr [0x4d3a98], 7
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5061272) /* 0x4d3a98 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(7 /*0x7*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0046e633  750a                   -jne 0x46e63f
    if (!cpu.flags.zf)
    {
        goto L_0x0046e63f;
    }
    // 0046e635  c7056c05520004000000   -mov dword ptr [0x52056c], 4
    app->getMemory<x86::reg32>(x86::reg32(5375340) /* 0x52056c */) = 4 /*0x4*/;
L_0x0046e63f:
    // 0046e63f  833dd8ff500001         +cmp dword ptr [0x50ffd8], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5308376) /* 0x50ffd8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046e646  7505                   -jne 0x46e64d
    if (!cpu.flags.zf)
    {
        goto L_0x0046e64d;
    }
    // 0046e648  be02000000             -mov esi, 2
    cpu.esi = 2 /*0x2*/;
L_0x0046e64d:
    // 0046e64d  8b3d7c055200           -mov edi, dword ptr [0x52057c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5375356) /* 0x52057c */);
    // 0046e653  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0046e655  7e5b                   -jle 0x46e6b2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046e6b2;
    }
    // 0046e657  833d7805520000         +cmp dword ptr [0x520578], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5375352) /* 0x520578 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046e65e  7452                   -je 0x46e6b2
    if (cpu.flags.zf)
    {
        goto L_0x0046e6b2;
    }
    // 0046e660  893d6c055200           -mov dword ptr [0x52056c], edi
    app->getMemory<x86::reg32>(x86::reg32(5375340) /* 0x52056c */) = cpu.edi;
    // 0046e666  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046e668  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0046e66a  7e46                   -jle 0x46e6b2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046e6b2;
    }
    // 0046e66c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0046e66e:
    // 0046e66e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046e670  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046e672  898380055200           -mov dword ptr [ebx + 0x520580], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5375360) /* 0x520580 */) = cpu.eax;
    // 0046e678  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046e67a  e811b1fdff             -call 0x449790
    cpu.esp -= 4;
    sub_449790(app, cpu);
    if (cpu.terminate) return;
    // 0046e67f  8b156c055200           -mov edx, dword ptr [0x52056c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5375340) /* 0x52056c */);
    // 0046e685  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046e687  8b14957c734d00         -mov edx, dword ptr [edx*4 + 0x4d737c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5075836) /* 0x4d737c */ + cpu.edx * 4);
    // 0046e68e  e82db4fdff             -call 0x449ac0
    cpu.esp -= 4;
    sub_449ac0(app, cpu);
    if (cpu.terminate) return;
    // 0046e693  8b156c055200           -mov edx, dword ptr [0x52056c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5375340) /* 0x52056c */);
    // 0046e699  833c957c734d0006       +cmp dword ptr [edx*4 + 0x4d737c], 6
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5075836) /* 0x4d737c */ + cpu.edx * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046e6a1  7507                   -jne 0x46e6aa
    if (!cpu.flags.zf)
    {
        goto L_0x0046e6aa;
    }
    // 0046e6a3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046e6a5  e8c6d2fdff             -call 0x44b970
    cpu.esp -= 4;
    sub_44b970(app, cpu);
    if (cpu.terminate) return;
L_0x0046e6aa:
    // 0046e6aa  41                     -inc ecx
    (cpu.ecx)++;
    // 0046e6ab  83c314                 -add ebx, 0x14
    (cpu.ebx) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0046e6ae  39f1                   +cmp ecx, esi
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
    // 0046e6b0  7cbc                   -jl 0x46e66e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046e66e;
    }
L_0x0046e6b2:
    // 0046e6b2  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0046e6b4  a174055200             -mov eax, dword ptr [0x520574]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5375348) /* 0x520574 */);
    // 0046e6b9  892d78055200           -mov dword ptr [0x520578], ebp
    app->getMemory<x86::reg32>(x86::reg32(5375352) /* 0x520578 */) = cpu.ebp;
    // 0046e6bf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046e6c1  7e1d                   -jle 0x46e6e0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046e6e0;
    }
    // 0046e6c3  8d70ff                 -lea esi, [eax - 1]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
L_0x0046e6c6:
    // 0046e6c6  893574055200           -mov dword ptr [0x520574], esi
    app->getMemory<x86::reg32>(x86::reg32(5375348) /* 0x520574 */) = cpu.esi;
L_0x0046e6cc:
    // 0046e6cc  833dfcec530000         +cmp dword ptr [0x53ecfc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5500156) /* 0x53ecfc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046e6d3  0f85df010000           -jne 0x46e8b8
    if (!cpu.flags.zf)
    {
        goto L_0x0046e8b8;
    }
    // 0046e6d9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e6da  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e6db  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e6dc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e6dd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e6de  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e6df  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046e6e0:
    // 0046e6e0  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0046e6e5  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 0046e6ea  e8a1b7feff             -call 0x459e90
    cpu.esp -= 4;
    sub_459e90(app, cpu);
    if (cpu.terminate) return;
    // 0046e6ef  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046e6f1  7427                   -je 0x46e71a
    if (cpu.flags.zf)
    {
        goto L_0x0046e71a;
    }
    // 0046e6f3  8b0d70055200           -mov ecx, dword ptr [0x520570]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5375344) /* 0x520570 */);
    // 0046e6f9  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0046e6fb  7ecf                   -jle 0x46e6cc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046e6cc;
    }
    // 0046e6fd  8d59ff                 -lea ebx, [ecx - 1]
    cpu.ebx = x86::reg32(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 0046e700  891d70055200           -mov dword ptr [0x520570], ebx
    app->getMemory<x86::reg32>(x86::reg32(5375344) /* 0x520570 */) = cpu.ebx;
    // 0046e706  833dfcec530000         +cmp dword ptr [0x53ecfc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5500156) /* 0x53ecfc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046e70d  0f85a5010000           -jne 0x46e8b8
    if (!cpu.flags.zf)
    {
        goto L_0x0046e8b8;
    }
    // 0046e713  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e714  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e715  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e716  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e717  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e718  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e719  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046e71a:
    // 0046e71a  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0046e71f  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 0046e724  e867b7feff             -call 0x459e90
    cpu.esp -= 4;
    sub_459e90(app, cpu);
    if (cpu.terminate) return;
    // 0046e729  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046e72b  7427                   -je 0x46e754
    if (cpu.flags.zf)
    {
        goto L_0x0046e754;
    }
    // 0046e72d  a170055200             -mov eax, dword ptr [0x520570]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5375344) /* 0x520570 */);
    // 0046e732  83f803                 +cmp eax, 3
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
    // 0046e735  7d95                   -jge 0x46e6cc
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0046e6cc;
    }
    // 0046e737  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 0046e73a  891570055200           -mov dword ptr [0x520570], edx
    app->getMemory<x86::reg32>(x86::reg32(5375344) /* 0x520570 */) = cpu.edx;
    // 0046e740  833dfcec530000         +cmp dword ptr [0x53ecfc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5500156) /* 0x53ecfc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046e747  0f856b010000           -jne 0x46e8b8
    if (!cpu.flags.zf)
    {
        goto L_0x0046e8b8;
    }
    // 0046e74d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e74e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e74f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e750  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e751  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e752  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e753  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046e754:
    // 0046e754  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0046e759  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 0046e75e  e82db7feff             -call 0x459e90
    cpu.esp -= 4;
    sub_459e90(app, cpu);
    if (cpu.terminate) return;
    // 0046e763  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046e765  0f8461ffffff           -je 0x46e6cc
    if (cpu.flags.zf)
    {
        goto L_0x0046e6cc;
    }
    // 0046e76b  c7057405520008000000   -mov dword ptr [0x520574], 8
    app->getMemory<x86::reg32>(x86::reg32(5375348) /* 0x520574 */) = 8 /*0x8*/;
    // 0046e775  8b1570055200           -mov edx, dword ptr [0x520570]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5375344) /* 0x520570 */);
    // 0046e77b  83fa03                 +cmp edx, 3
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
    // 0046e77e  0f8748ffffff           -ja 0x46e6cc
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0046e6cc;
    }
    // 0046e784  ff249500e64600         -jmp dword ptr [edx*4 + 0x46e600]
    cpu.ip = app->getMemory<x86::reg32>(4646400 + cpu.edx * 4); goto dynamic_jump;
  case 0x0046e78b:
    // 0046e78b  80356005520001         -xor byte ptr [0x520560], 1
    app->getMemory<x86::reg8>(x86::reg32(5375328) /* 0x520560 */) ^= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 0046e792  833dfcec530000         +cmp dword ptr [0x53ecfc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5500156) /* 0x53ecfc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046e799  0f8519010000           -jne 0x46e8b8
    if (!cpu.flags.zf)
    {
        goto L_0x0046e8b8;
    }
    // 0046e79f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e7a0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e7a1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e7a2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e7a3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e7a4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e7a5  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0046e7a6:
    // 0046e7a6  8b1564055200           -mov edx, dword ptr [0x520564]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5375332) /* 0x520564 */);
    // 0046e7ac  8b2dd8ff5000           -mov ebp, dword ptr [0x50ffd8]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5308376) /* 0x50ffd8 */);
    // 0046e7b2  42                     -inc edx
    (cpu.edx)++;
    // 0046e7b3  83fd01                 +cmp ebp, 1
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
    // 0046e7b6  7526                   -jne 0x46e7de
    if (!cpu.flags.zf)
    {
        goto L_0x0046e7de;
    }
    // 0046e7b8  b903000000             -mov ecx, 3
    cpu.ecx = 3 /*0x3*/;
    // 0046e7bd  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046e7bf  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0046e7c2  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0046e7c4  891564055200           -mov dword ptr [0x520564], edx
    app->getMemory<x86::reg32>(x86::reg32(5375332) /* 0x520564 */) = cpu.edx;
    // 0046e7ca  833dfcec530000         +cmp dword ptr [0x53ecfc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5500156) /* 0x53ecfc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046e7d1  0f85e1000000           -jne 0x46e8b8
    if (!cpu.flags.zf)
    {
        goto L_0x0046e8b8;
    }
    // 0046e7d7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e7d8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e7d9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e7da  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e7db  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e7dc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e7dd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046e7de:
    // 0046e7de  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0046e7e3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046e7e5  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0046e7e8  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0046e7ea  891564055200           -mov dword ptr [0x520564], edx
    app->getMemory<x86::reg32>(x86::reg32(5375332) /* 0x520564 */) = cpu.edx;
    // 0046e7f0  833dfcec530000         +cmp dword ptr [0x53ecfc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5500156) /* 0x53ecfc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046e7f7  0f85bb000000           -jne 0x46e8b8
    if (!cpu.flags.zf)
    {
        goto L_0x0046e8b8;
    }
    // 0046e7fd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e7fe  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e7ff  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e800  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e801  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e802  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e803  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x0046e804:
    // 0046e804  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 0046e809  be18000000             -mov esi, 0x18
    cpu.esi = 24 /*0x18*/;
    // 0046e80e  893d68055200           -mov dword ptr [0x520568], edi
    app->getMemory<x86::reg32>(x86::reg32(5375336) /* 0x520568 */) = cpu.edi;
    // 0046e814  e9adfeffff             -jmp 0x46e6c6
    goto L_0x0046e6c6;
  case 0x0046e819:
    // 0046e819  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0046e81e  8b156c055200           -mov edx, dword ptr [0x52056c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5375340) /* 0x52056c */);
    // 0046e824  890d78055200           -mov dword ptr [0x520578], ecx
    app->getMemory<x86::reg32>(x86::reg32(5375352) /* 0x520578 */) = cpu.ecx;
    // 0046e82a  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046e82c  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 0046e831  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046e833  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0046e836  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0046e838  89156c055200           -mov dword ptr [0x52056c], edx
    app->getMemory<x86::reg32>(x86::reg32(5375340) /* 0x52056c */) = cpu.edx;
    // 0046e83e  8b1c957c734d00         -mov ebx, dword ptr [edx*4 + 0x4d737c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5075836) /* 0x4d737c */ + cpu.edx * 4);
    // 0046e845  89157c055200           -mov dword ptr [0x52057c], edx
    app->getMemory<x86::reg32>(x86::reg32(5375356) /* 0x52057c */) = cpu.edx;
    // 0046e84b  83fb0a                 +cmp ebx, 0xa
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
    // 0046e84e  0f8578feffff           -jne 0x46e6cc
    if (!cpu.flags.zf)
    {
        goto L_0x0046e6cc;
    }
    // 0046e854  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046e856  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0046e858  0f8e6efeffff           -jle 0x46e6cc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046e6cc;
    }
    // 0046e85e  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 0046e863  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0046e865:
    // 0046e865  83c114                 -add ecx, 0x14
    (cpu.ecx) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0046e868  8b1518ed5300           -mov edx, dword ptr [0x53ed18]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5500184) /* 0x53ed18 */);
    // 0046e86e  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0046e870  89b96c055200           -mov dword ptr [ecx + 0x52056c], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5375340) /* 0x52056c */) = cpu.edi;
    // 0046e876  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0046e878  89a974055200           -mov dword ptr [ecx + 0x520574], ebp
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5375348) /* 0x520574 */) = cpu.ebp;
    // 0046e87e  81ea00020000           -sub edx, 0x200
    (cpu.edx) -= x86::reg32(x86::sreg32(512 /*0x200*/));
    // 0046e884  89a978055200           -mov dword ptr [ecx + 0x520578], ebp
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5375352) /* 0x520578 */) = cpu.ebp;
    // 0046e88a  01fb                   -add ebx, edi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0046e88c  899170055200           -mov dword ptr [ecx + 0x520570], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5375344) /* 0x520570 */) = cpu.edx;
    // 0046e892  8b14ada0734d00         -mov edx, dword ptr [ebp*4 + 0x4d73a0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5075872) /* 0x4d73a0 */ + cpu.ebp * 4);
    // 0046e899  89a97c055200           -mov dword ptr [ecx + 0x52057c], ebp
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5375356) /* 0x52057c */) = cpu.ebp;
    // 0046e89f  e81cb2fdff             -call 0x449ac0
    cpu.esp -= 4;
    sub_449ac0(app, cpu);
    if (cpu.terminate) return;
    // 0046e8a4  39f3                   +cmp ebx, esi
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
    // 0046e8a6  7cbd                   -jl 0x46e865
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046e865;
    }
    // 0046e8a8  833dfcec530000         +cmp dword ptr [0x53ecfc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5500156) /* 0x53ecfc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046e8af  7507                   -jne 0x46e8b8
    if (!cpu.flags.zf)
    {
        goto L_0x0046e8b8;
    }
    // 0046e8b1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e8b2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e8b3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e8b4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e8b5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e8b6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e8b7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046e8b8:
    // 0046e8b8  e857c7fdff             -call 0x44b014
    cpu.esp -= 4;
    sub_44b014(app, cpu);
    if (cpu.terminate) return;
    // 0046e8bd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e8be  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e8bf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e8c0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e8c1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e8c2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e8c3  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46e8d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046e8d0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046e8d1  8b1564eb5300           -mov edx, dword ptr [0x53eb64]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5499748) /* 0x53eb64 */);
    // 0046e8d7  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0046e8d9  7405                   -je 0x46e8e0
    if (cpu.flags.zf)
    {
        goto L_0x0046e8e0;
    }
    // 0046e8db  83fa01                 +cmp edx, 1
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
    // 0046e8de  750d                   -jne 0x46e8ed
    if (!cpu.flags.zf)
    {
        goto L_0x0046e8ed;
    }
L_0x0046e8e0:
    // 0046e8e0  8b80ec010000           -mov eax, dword ptr [eax + 0x1ec]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(492) /* 0x1ec */);
    // 0046e8e6  e885020000             -call 0x46eb70
    cpu.esp -= 4;
    sub_46eb70(app, cpu);
    if (cpu.terminate) return;
    // 0046e8eb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e8ec  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046e8ed:
    // 0046e8ed  8b80ec010000           -mov eax, dword ptr [eax + 0x1ec]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(492) /* 0x1ec */);
    // 0046e8f3  e8e8000000             -call 0x46e9e0
    cpu.esp -= 4;
    sub_46e9e0(app, cpu);
    if (cpu.terminate) return;
    // 0046e8f8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e8f9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46e900(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046e900  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046e901  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046e902  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046e903  83ec5c                 -sub esp, 0x5c
    (cpu.esp) -= x86::reg32(x86::sreg32(92 /*0x5c*/));
    // 0046e906  6858bd4c00             -push 0x4cbd58
    app->getMemory<x86::reg32>(cpu.esp-4) = 5029208 /*0x4cbd58*/;
    cpu.esp -= 4;
    // 0046e90b  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046e90f  8d4c2458               -lea ecx, [esp + 0x58]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 0046e913  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046e915  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046e916  8d5c2458               -lea ebx, [esp + 0x58]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 0046e91a  89542458               -mov dword ptr [esp + 0x58], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */) = cpu.edx;
    // 0046e91e  e84e600100             -call 0x484971
    cpu.esp -= 4;
    sub_484971(app, cpu);
    if (cpu.terminate) return;
    // 0046e923  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046e926  8d542458               -lea edx, [esp + 0x58]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 0046e92a  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0046e92c  e8fb720100             -call 0x485c2c
    cpu.esp -= 4;
    sub_485c2c(app, cpu);
    if (cpu.terminate) return;
    // 0046e931  8b4c2458               -mov ecx, dword ptr [esp + 0x58]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 0046e935  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0046e937  750d                   -jne 0x46e946
    if (!cpu.flags.zf)
    {
        goto L_0x0046e946;
    }
    // 0046e939  890d64eb5300           -mov dword ptr [0x53eb64], ecx
    app->getMemory<x86::reg32>(x86::reg32(5499748) /* 0x53eb64 */) = cpu.ecx;
    // 0046e93f  83c45c                 -add esp, 0x5c
    (cpu.esp) += x86::reg32(x86::sreg32(92 /*0x5c*/));
    // 0046e942  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e943  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e944  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e945  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046e946:
    // 0046e946  8b5c2454               -mov ebx, dword ptr [esp + 0x54]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 0046e94a  baa8055200             -mov edx, 0x5205a8
    cpu.edx = 5375400 /*0x5205a8*/;
    // 0046e94f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046e951  e872740100             -call 0x485dc8
    cpu.esp -= 4;
    sub_485dc8(app, cpu);
    if (cpu.terminate) return;
    // 0046e956  8b442458               -mov eax, dword ptr [esp + 0x58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 0046e95a  e861740100             -call 0x485dc0
    cpu.esp -= 4;
    sub_485dc0(app, cpu);
    if (cpu.terminate) return;
    // 0046e95f  83c45c                 -add esp, 0x5c
    (cpu.esp) += x86::reg32(x86::sreg32(92 /*0x5c*/));
    // 0046e962  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e963  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e964  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e965  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46e970(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046e970  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046e971  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046e972  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046e973  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046e974  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046e975  83ec3c                 -sub esp, 0x3c
    (cpu.esp) -= x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 0046e978  6858bd4c00             -push 0x4cbd58
    app->getMemory<x86::reg32>(cpu.esp-4) = 5029208 /*0x4cbd58*/;
    cpu.esp -= 4;
    // 0046e97d  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046e981  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046e982  e8ea5f0100             -call 0x484971
    cpu.esp -= 4;
    sub_484971(app, cpu);
    if (cpu.terminate) return;
    // 0046e987  8b1564eb5300           -mov edx, dword ptr [0x53eb64]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5499748) /* 0x53eb64 */);
    // 0046e98d  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046e990  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0046e992  750a                   -jne 0x46e99e
    if (!cpu.flags.zf)
    {
        goto L_0x0046e99e;
    }
    // 0046e994  a118ed5300             -mov eax, dword ptr [0x53ed18]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5500184) /* 0x53ed18 */);
    // 0046e999  a378734d00             -mov dword ptr [0x4d7378], eax
    app->getMemory<x86::reg32>(x86::reg32(5075832) /* 0x4d7378 */) = cpu.eax;
L_0x0046e99e:
    // 0046e99e  b96c010000             -mov ecx, 0x16c
    cpu.ecx = 364 /*0x16c*/;
    // 0046e9a3  bfa8055200             -mov edi, 0x5205a8
    cpu.edi = 5375400 /*0x5205a8*/;
    // 0046e9a8  bec8ff5000             -mov esi, 0x50ffc8
    cpu.esi = 5308360 /*0x50ffc8*/;
    // 0046e9ad  bbb4e50100             -mov ebx, 0x1e5b4
    cpu.ebx = 124340 /*0x1e5b4*/;
    // 0046e9b2  baa8055200             -mov edx, 0x5205a8
    cpu.edx = 5375400 /*0x5205a8*/;
    // 0046e9b7  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046e9b9  a178734d00             -mov eax, dword ptr [0x4d7378]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5075832) /* 0x4d7378 */);
    // 0046e9be  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 0046e9c3  a3580b5200             -mov dword ptr [0x520b58], eax
    app->getMemory<x86::reg32>(x86::reg32(5376856) /* 0x520b58 */) = cpu.eax;
    // 0046e9c8  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0046e9ca  890dc4055200           -mov dword ptr [0x5205c4], ecx
    app->getMemory<x86::reg32>(x86::reg32(5375428) /* 0x5205c4 */) = cpu.ecx;
    // 0046e9d0  e84b700100             -call 0x485a20
    cpu.esp -= 4;
    sub_485a20(app, cpu);
    if (cpu.terminate) return;
    // 0046e9d5  83c43c                 -add esp, 0x3c
    (cpu.esp) += x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 0046e9d8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e9d9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e9da  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e9db  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e9dc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046e9dd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_46e9e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046e9e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046e9e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046e9e2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046e9e3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046e9e4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046e9e5  81ec80000000           -sub esp, 0x80
    (cpu.esp) -= x86::reg32(x86::sreg32(128 /*0x80*/));
    // 0046e9eb  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046e9ed  833c854001520000       +cmp dword ptr [eax*4 + 0x520140], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5374272) /* 0x520140 */ + cpu.eax * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046e9f5  0f8597000000           -jne 0x46ea92
    if (!cpu.flags.zf)
    {
        goto L_0x0046ea92;
    }
    // 0046e9fb  a160eb5300             -mov eax, dword ptr [0x53eb60]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5499744) /* 0x53eb60 */);
    // 0046ea00  80b85c0b520000         +cmp byte ptr [eax + 0x520b5c], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5376860) /* 0x520b5c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0046ea07  7568                   -jne 0x46ea71
    if (!cpu.flags.zf)
    {
        goto L_0x0046ea71;
    }
    // 0046ea09  c70564eb530004000000   -mov dword ptr [0x53eb64], 4
    app->getMemory<x86::reg32>(x86::reg32(5499748) /* 0x53eb64 */) = 4 /*0x4*/;
L_0x0046ea13:
    // 0046ea13  8b2c9540015200         -mov ebp, dword ptr [edx*4 + 0x520140]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5374272) /* 0x520140 */ + cpu.edx * 4);
    // 0046ea1a  45                     -inc ebp
    (cpu.ebp)++;
    // 0046ea1b  a1d8ff5000             -mov eax, dword ptr [0x50ffd8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5308376) /* 0x50ffd8 */);
    // 0046ea20  892c9540015200         -mov dword ptr [edx*4 + 0x520140], ebp
    app->getMemory<x86::reg32>(x86::reg32(5374272) /* 0x520140 */ + cpu.edx * 4) = cpu.ebp;
    // 0046ea27  83f802                 +cmp eax, 2
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
    // 0046ea2a  0f8ce5000000           -jl 0x46eb15
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046eb15;
    }
    // 0046ea30  3b15dcff5000           +cmp edx, dword ptr [0x50ffdc]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5308380) /* 0x50ffdc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046ea36  0f85d9000000           -jne 0x46eb15
    if (!cpu.flags.zf)
    {
        goto L_0x0046eb15;
    }
L_0x0046ea3c:
    // 0046ea3c  833d8005520000         +cmp dword ptr [0x520580], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5375360) /* 0x520580 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046ea43  7410                   -je 0x46ea55
    if (cpu.flags.zf)
    {
        goto L_0x0046ea55;
    }
    // 0046ea45  833d14ed530000         +cmp dword ptr [0x53ed14], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5500180) /* 0x53ed14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046ea4c  7407                   -je 0x46ea55
    if (cpu.flags.zf)
    {
        goto L_0x0046ea55;
    }
    // 0046ea4e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0046ea50:
    // 0046ea50  e8bbf9ffff             -call 0x46e410
    cpu.esp -= 4;
    sub_46e410(app, cpu);
    if (cpu.terminate) return;
L_0x0046ea55:
    // 0046ea55  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0046ea58  83ba4001520020         +cmp dword ptr [edx + 0x520140], 0x20
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5374272) /* 0x520140 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046ea5f  0f84f2000000           -je 0x46eb57
    if (cpu.flags.zf)
    {
        goto L_0x0046eb57;
    }
    // 0046ea65  81c480000000           -add esp, 0x80
    (cpu.esp) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 0046ea6b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ea6c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ea6d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ea6e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ea6f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ea70  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046ea71:
    // 0046ea71  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046ea72  8d742404               -lea esi, [esp + 4]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046ea76  e8b5010000             -call 0x46ec30
    cpu.esp -= 4;
    sub_46ec30(app, cpu);
    if (cpu.terminate) return;
    // 0046ea7b  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0046ea7d  c1e607                 -shl esi, 7
    cpu.esi <<= 7 /*0x7*/ % 32;
    // 0046ea80  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 0046ea85  8dbe60015200           -lea edi, [esi + 0x520160]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(5374304) /* 0x520160 */);
    // 0046ea8b  8d742404               -lea esi, [esp + 4]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046ea8f  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046ea91  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0046ea92:
    // 0046ea92  8b1d64eb5300           -mov ebx, dword ptr [0x53eb64]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5499748) /* 0x53eb64 */);
    // 0046ea98  83fb02                 +cmp ebx, 2
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
    // 0046ea9b  7550                   -jne 0x46eaed
    if (!cpu.flags.zf)
    {
        goto L_0x0046eaed;
    }
    // 0046ea9d  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0046ea9f  8b049540015200         -mov eax, dword ptr [edx*4 + 0x520140]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5374272) /* 0x520140 */ + cpu.edx * 4);
    // 0046eaa6  c1e107                 -shl ecx, 7
    cpu.ecx <<= 7 /*0x7*/ % 32;
    // 0046eaa9  8a9c0160015200         -mov bl, byte ptr [ecx + eax + 0x520160]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5374304) /* 0x520160 */ + cpu.eax * 1);
    // 0046eab0  80eb40                 -sub bl, 0x40
    (cpu.bl) -= x86::reg8(x86::sreg8(64 /*0x40*/));
    // 0046eab3  c0e302                 -shl bl, 2
    cpu.bl <<= 2 /*0x2*/ % 32;
    // 0046eab6  881d08085100           -mov byte ptr [0x510808], bl
    app->getMemory<x86::reg8>(x86::reg32(5310472) /* 0x510808 */) = cpu.bl;
    // 0046eabc  8a9c0180015200         -mov bl, byte ptr [ecx + eax + 0x520180]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5374336) /* 0x520180 */ + cpu.eax * 1);
    // 0046eac3  c0e303                 -shl bl, 3
    cpu.bl <<= 3 /*0x3*/ % 32;
    // 0046eac6  881d09085100           -mov byte ptr [0x510809], bl
    app->getMemory<x86::reg8>(x86::reg32(5310473) /* 0x510809 */) = cpu.bl;
    // 0046eacc  8a9c01a0015200         -mov bl, byte ptr [ecx + eax + 0x5201a0]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5374368) /* 0x5201a0 */ + cpu.eax * 1);
    // 0046ead3  c0e303                 +shl bl, 3
    {
        x86::reg8 tmp = 3 /*0x3*/ % 32;
        x86::reg8& op = cpu.bl;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (8 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (8 - 1))));
        }
    }
    // 0046ead6  8a8401c0015200         -mov al, byte ptr [ecx + eax + 0x5201c0]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5374400) /* 0x5201c0 */ + cpu.eax * 1);
    // 0046eadd  881d0a085100           -mov byte ptr [0x51080a], bl
    app->getMemory<x86::reg8>(x86::reg32(5310474) /* 0x51080a */) = cpu.bl;
    // 0046eae3  a20b085100             -mov byte ptr [0x51080b], al
    app->getMemory<x86::reg8>(x86::reg32(5310475) /* 0x51080b */) = cpu.al;
    // 0046eae8  e926ffffff             -jmp 0x46ea13
    goto L_0x0046ea13;
L_0x0046eaed:
    // 0046eaed  83fb03                 +cmp ebx, 3
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046eaf0  0f851dffffff           -jne 0x46ea13
    if (!cpu.flags.zf)
    {
        goto L_0x0046ea13;
    }
    // 0046eaf6  30ff                   +xor bh, bh
    cpu.clear_co();
    cpu.set_szp((cpu.bh ^= x86::reg8(x86::sreg8(cpu.bh))));
    // 0046eaf8  883d09085100           -mov byte ptr [0x510809], bh
    app->getMemory<x86::reg8>(x86::reg32(5310473) /* 0x510809 */) = cpu.bh;
    // 0046eafe  883d0a085100           -mov byte ptr [0x51080a], bh
    app->getMemory<x86::reg8>(x86::reg32(5310474) /* 0x51080a */) = cpu.bh;
    // 0046eb04  883d0b085100           -mov byte ptr [0x51080b], bh
    app->getMemory<x86::reg8>(x86::reg32(5310475) /* 0x51080b */) = cpu.bh;
    // 0046eb0a  883d08085100           -mov byte ptr [0x510808], bh
    app->getMemory<x86::reg8>(x86::reg32(5310472) /* 0x510808 */) = cpu.bh;
    // 0046eb10  e9fefeffff             -jmp 0x46ea13
    goto L_0x0046ea13;
L_0x0046eb15:
    // 0046eb15  8b1dd8ff5000           -mov ebx, dword ptr [0x50ffd8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5308376) /* 0x50ffd8 */);
    // 0046eb1b  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0046eb1d  0f8419ffffff           -je 0x46ea3c
    if (cpu.flags.zf)
    {
        goto L_0x0046ea3c;
    }
    // 0046eb23  83fb01                 +cmp ebx, 1
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
    // 0046eb26  0f8529ffffff           -jne 0x46ea55
    if (!cpu.flags.zf)
    {
        goto L_0x0046ea55;
    }
    // 0046eb2c  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0046eb33  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046eb35  833c858005520000       +cmp dword ptr [eax*4 + 0x520580], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5375360) /* 0x520580 */ + cpu.eax * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046eb3d  0f8412ffffff           -je 0x46ea55
    if (cpu.flags.zf)
    {
        goto L_0x0046ea55;
    }
    // 0046eb43  833d14ed530000         +cmp dword ptr [0x53ed14], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5500180) /* 0x53ed14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046eb4a  0f8405ffffff           -je 0x46ea55
    if (cpu.flags.zf)
    {
        goto L_0x0046ea55;
    }
    // 0046eb50  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046eb52  e9f9feffff             -jmp 0x46ea50
    goto L_0x0046ea50;
L_0x0046eb57:
    // 0046eb57  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0046eb59  89b240015200           -mov dword ptr [edx + 0x520140], esi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5374272) /* 0x520140 */) = cpu.esi;
    // 0046eb5f  81c480000000           -add esp, 0x80
    (cpu.esp) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 0046eb65  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046eb66  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046eb67  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046eb68  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046eb69  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046eb6a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46eb70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046eb70  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046eb71  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046eb72  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046eb73  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046eb74  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0046eb76  e835b4feff             -call 0x459fb0
    cpu.esp -= 4;
    sub_459fb0(app, cpu);
    if (cpu.terminate) return;
    // 0046eb7b  8b1505085100           -mov edx, dword ptr [0x510805]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5310469) /* 0x510805 */);
    // 0046eb81  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 0046eb84  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046eb86  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0046eb89  c1e202                 +shl edx, 2
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
    // 0046eb8c  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0046eb8e  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 0046eb91  8d0c9d00000000         -lea ecx, [ebx*4]
    cpu.ecx = x86::reg32(cpu.ebx * 4);
    // 0046eb98  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0046eb9a  c1e607                 -shl esi, 7
    cpu.esi <<= 7 /*0x7*/ % 32;
    // 0046eb9d  8b9940015200           -mov ebx, dword ptr [ecx + 0x520140]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5374272) /* 0x520140 */);
    // 0046eba3  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046eba5  83c040                 -add eax, 0x40
    (cpu.eax) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0046eba8  8a1509085100           -mov dl, byte ptr [0x510809]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5310473) /* 0x510809 */);
    // 0046ebae  88841e60015200         -mov byte ptr [esi + ebx + 0x520160], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5374304) /* 0x520160 */ + cpu.ebx * 1) = cpu.al;
    // 0046ebb5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046ebb7  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0046ebba  c1e203                 +shl edx, 3
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
    // 0046ebbd  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0046ebbf  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 0046ebc2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046ebc4  8a150a085100           -mov dl, byte ptr [0x51080a]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5310474) /* 0x51080a */);
    // 0046ebca  88841e80015200         -mov byte ptr [esi + ebx + 0x520180], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5374336) /* 0x520180 */ + cpu.ebx * 1) = cpu.al;
    // 0046ebd1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046ebd3  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0046ebd6  c1e203                 +shl edx, 3
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
    // 0046ebd9  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0046ebdb  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 0046ebde  8d5301                 -lea edx, [ebx + 1]
    cpu.edx = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 0046ebe1  88841ea0015200         -mov byte ptr [esi + ebx + 0x5201a0], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5374368) /* 0x5201a0 */ + cpu.ebx * 1) = cpu.al;
    // 0046ebe8  a00b085100             -mov al, byte ptr [0x51080b]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5310475) /* 0x51080b */);
    // 0046ebed  899140015200           -mov dword ptr [ecx + 0x520140], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5374272) /* 0x520140 */) = cpu.edx;
    // 0046ebf3  88841ec0015200         -mov byte ptr [esi + ebx + 0x5201c0], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5374400) /* 0x5201c0 */ + cpu.ebx * 1) = cpu.al;
    // 0046ebfa  83fa20                 +cmp edx, 0x20
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
    // 0046ebfd  7405                   -je 0x46ec04
    if (cpu.flags.zf)
    {
        goto L_0x0046ec04;
    }
    // 0046ebff  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ec00  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ec01  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ec02  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ec03  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046ec04:
    // 0046ec04  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046ec05  81ec80000000           -sub esp, 0x80
    (cpu.esp) -= x86::reg32(x86::sreg32(128 /*0x80*/));
    // 0046ec0b  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0046ec0d  8db660015200           -lea esi, [esi + 0x520160]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(5374304) /* 0x520160 */);
    // 0046ec13  89b940015200           -mov dword ptr [ecx + 0x520140], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5374272) /* 0x520140 */) = cpu.edi;
    // 0046ec19  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0046ec1b  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0046ec1d  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046ec1f  e8cc010000             -call 0x46edf0
    cpu.esp -= 4;
    sub_46edf0(app, cpu);
    if (cpu.terminate) return;
    // 0046ec24  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ec25  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ec26  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ec27  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ec28  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ec29  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46ec30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046ec30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046ec31  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046ec32  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046ec33  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046ec34  81eca4000000           -sub esp, 0xa4
    (cpu.esp) -= x86::reg32(x86::sreg32(164 /*0xa4*/));
    // 0046ec3a  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0046ec3c  8b3560eb5300           -mov esi, dword ptr [0x53eb60]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5499744) /* 0x53eb60 */);
    // 0046ec42  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046ec44  8dbc2480000000         -lea edi, [esp + 0x80]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 0046ec4b  8a8e5c0b5200           -mov cl, byte ptr [esi + 0x520b5c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5376860) /* 0x520b5c */);
    // 0046ec51  81c65c0b5200           -add esi, 0x520b5c
    (cpu.esi) += x86::reg32(x86::sreg32(5376860 /*0x520b5c*/));
    // 0046ec57  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046ec58  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046ec5a  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0046ec5d  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046ec5f  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0046ec61  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0046ec64  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0046ec66  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ec67  8d842480000000         -lea eax, [esp + 0x80]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 0046ec6e  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 0046ec73  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0046ec75  e8d6040000             -call 0x46f150
    cpu.esp -= 4;
    sub_46f150(app, cpu);
    if (cpu.terminate) return;
    // 0046ec7a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046ec7c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046ec7d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046ec7f  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0046ec82  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046ec84  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0046ec86  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0046ec89  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0046ec8b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ec8c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046ec8e  8b0d60eb5300           -mov ecx, dword ptr [0x53eb60]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5499744) /* 0x53eb60 */);
    // 0046ec94  8a842480000000         -mov al, byte ptr [esp + 0x80]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 0046ec9b  be5c0b5200             -mov esi, 0x520b5c
    cpu.esi = 5376860 /*0x520b5c*/;
    // 0046eca0  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046eca2  8dbc2480000000         -lea edi, [esp + 0x80]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 0046eca9  890d60eb5300           -mov dword ptr [0x53eb60], ecx
    app->getMemory<x86::reg32>(x86::reg32(5499744) /* 0x53eb60 */) = cpu.ecx;
    // 0046ecaf  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046ecb1  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046ecb3  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046ecb5  8a885c0b5200           -mov cl, byte ptr [eax + 0x520b5c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5376860) /* 0x520b5c */);
    // 0046ecbb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046ecbc  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046ecbe  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0046ecc1  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046ecc3  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0046ecc5  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0046ecc8  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0046ecca  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046eccb  8d842480000000         -lea eax, [esp + 0x80]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 0046ecd2  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 0046ecd7  8d7c2420               -lea edi, [esp + 0x20]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0046ecdb  e870040000             -call 0x46f150
    cpu.esp -= 4;
    sub_46f150(app, cpu);
    if (cpu.terminate) return;
    // 0046ece0  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046ece2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046ece3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046ece5  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0046ece8  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046ecea  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0046ecec  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0046ecef  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0046ecf1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ecf2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046ecf4  8b1d60eb5300           -mov ebx, dword ptr [0x53eb60]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5499744) /* 0x53eb60 */);
    // 0046ecfa  8a842480000000         -mov al, byte ptr [esp + 0x80]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 0046ed01  be5c0b5200             -mov esi, 0x520b5c
    cpu.esi = 5376860 /*0x520b5c*/;
    // 0046ed06  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046ed08  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046ed0a  8dbc2480000000         -lea edi, [esp + 0x80]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 0046ed11  8a8b5c0b5200           -mov cl, byte ptr [ebx + 0x520b5c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5376860) /* 0x520b5c */);
    // 0046ed17  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0046ed19  891d60eb5300           -mov dword ptr [0x53eb60], ebx
    app->getMemory<x86::reg32>(x86::reg32(5499744) /* 0x53eb60 */) = cpu.ebx;
    // 0046ed1f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046ed20  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046ed22  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0046ed25  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046ed27  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0046ed29  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0046ed2c  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0046ed2e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ed2f  8d842480000000         -lea eax, [esp + 0x80]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 0046ed36  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 0046ed3b  8d7c2440               -lea edi, [esp + 0x40]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0046ed3f  e80c040000             -call 0x46f150
    cpu.esp -= 4;
    sub_46f150(app, cpu);
    if (cpu.terminate) return;
    // 0046ed44  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046ed46  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046ed47  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046ed49  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0046ed4c  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046ed4e  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0046ed50  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0046ed53  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0046ed55  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ed56  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046ed58  8b3560eb5300           -mov esi, dword ptr [0x53eb60]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5499744) /* 0x53eb60 */);
    // 0046ed5e  8a842480000000         -mov al, byte ptr [esp + 0x80]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 0046ed65  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046ed67  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046ed69  893560eb5300           -mov dword ptr [0x53eb60], esi
    app->getMemory<x86::reg32>(x86::reg32(5499744) /* 0x53eb60 */) = cpu.esi;
    // 0046ed6f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0046ed71  8a8e5c0b5200           -mov cl, byte ptr [esi + 0x520b5c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5376860) /* 0x520b5c */);
    // 0046ed77  be5c0b5200             -mov esi, 0x520b5c
    cpu.esi = 5376860 /*0x520b5c*/;
    // 0046ed7c  8dbc2480000000         -lea edi, [esp + 0x80]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 0046ed83  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046ed85  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046ed86  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046ed88  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0046ed8b  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046ed8d  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0046ed8f  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0046ed92  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0046ed94  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ed95  8d842480000000         -lea eax, [esp + 0x80]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 0046ed9c  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 0046eda1  8d7c2460               -lea edi, [esp + 0x60]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 0046eda5  e8a6030000             -call 0x46f150
    cpu.esp -= 4;
    sub_46f150(app, cpu);
    if (cpu.terminate) return;
    // 0046edaa  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046edac  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046edad  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046edaf  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0046edb2  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046edb4  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0046edb6  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0046edb9  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0046edbb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046edbc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046edbe  8b3d60eb5300           -mov edi, dword ptr [0x53eb60]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5499744) /* 0x53eb60 */);
    // 0046edc4  8a842480000000         -mov al, byte ptr [esp + 0x80]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 0046edcb  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 0046edd0  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046edd2  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0046edd4  893d60eb5300           -mov dword ptr [0x53eb60], edi
    app->getMemory<x86::reg32>(x86::reg32(5499744) /* 0x53eb60 */) = cpu.edi;
    // 0046edda  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0046eddc  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046edde  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046ede0  81c4a4000000           -add esp, 0xa4
    (cpu.esp) += x86::reg32(x86::sreg32(164 /*0xa4*/));
    // 0046ede6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ede7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ede8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ede9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046edea  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46edf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046edf0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046edf1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046edf2  83ec24                 -sub esp, 0x24
    (cpu.esp) -= x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0046edf5  a15ceb5300             -mov eax, dword ptr [0x53eb5c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5499740) /* 0x53eb5c */);
    // 0046edfa  0580000000             -add eax, 0x80
    (cpu.eax) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 0046edff  3d00e00100             +cmp eax, 0x1e000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(122880 /*0x1e000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046ee04  7c1d                   -jl 0x46ee23
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046ee23;
    }
    // 0046ee06  a118ed5300             -mov eax, dword ptr [0x53ed18]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5500184) /* 0x53ed18 */);
    // 0046ee0b  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 0046ee10  a378734d00             -mov dword ptr [0x4d7378], eax
    app->getMemory<x86::reg32>(x86::reg32(5075832) /* 0x4d7378 */) = cpu.eax;
    // 0046ee15  893d64eb5300           -mov dword ptr [0x53eb64], edi
    app->getMemory<x86::reg32>(x86::reg32(5499748) /* 0x53eb64 */) = cpu.edi;
    // 0046ee1b  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0046ee1e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ee1f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ee20  c28000                 -ret 0x80
    cpu.esp += 4+128 /*0x80*/;
    return;
L_0x0046ee23:
    // 0046ee23  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046ee24  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046ee25  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046ee26  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046ee27  8d442440               -lea eax, [esp + 0x40]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0046ee2b  b921000000             -mov ecx, 0x21
    cpu.ecx = 33 /*0x21*/;
    // 0046ee30  8d7c2410               -lea edi, [esp + 0x10]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046ee34  e887030000             -call 0x46f1c0
    cpu.esp -= 4;
    sub_46f1c0(app, cpu);
    if (cpu.terminate) return;
    // 0046ee39  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046ee3b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046ee3c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046ee3e  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0046ee41  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046ee43  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0046ee45  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0046ee48  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0046ee4a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ee4b  bf5c0b5200             -mov edi, 0x520b5c
    cpu.edi = 5376860 /*0x520b5c*/;
    // 0046ee50  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046ee54  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046ee56  8b155ceb5300           -mov edx, dword ptr [0x53eb5c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5499740) /* 0x53eb5c */);
    // 0046ee5c  8a4c2410               -mov cl, byte ptr [esp + 0x10]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046ee60  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046ee62  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046ee63  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046ee65  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0046ee68  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046ee6a  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0046ee6c  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0046ee6f  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0046ee71  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ee72  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046ee74  8b0d5ceb5300           -mov ecx, dword ptr [0x53eb5c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5499740) /* 0x53eb5c */);
    // 0046ee7a  8a442410               -mov al, byte ptr [esp + 0x10]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046ee7e  8d7c2410               -lea edi, [esp + 0x10]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046ee82  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046ee84  8d442460               -lea eax, [esp + 0x60]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 0046ee88  890d5ceb5300           -mov dword ptr [0x53eb5c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5499740) /* 0x53eb5c */) = cpu.ecx;
    // 0046ee8e  e82d030000             -call 0x46f1c0
    cpu.esp -= 4;
    sub_46f1c0(app, cpu);
    if (cpu.terminate) return;
    // 0046ee93  b921000000             -mov ecx, 0x21
    cpu.ecx = 33 /*0x21*/;
    // 0046ee98  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046ee9a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046ee9b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046ee9d  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0046eea0  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046eea2  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0046eea4  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0046eea7  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0046eea9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046eeaa  bf5c0b5200             -mov edi, 0x520b5c
    cpu.edi = 5376860 /*0x520b5c*/;
    // 0046eeaf  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046eeb3  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046eeb5  8b1d5ceb5300           -mov ebx, dword ptr [0x53eb5c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5499740) /* 0x53eb5c */);
    // 0046eebb  8a4c2410               -mov cl, byte ptr [esp + 0x10]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046eebf  01df                   -add edi, ebx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0046eec1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046eec2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046eec4  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0046eec7  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046eec9  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0046eecb  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0046eece  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0046eed0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046eed1  b921000000             -mov ecx, 0x21
    cpu.ecx = 33 /*0x21*/;
    // 0046eed6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046eed8  8b355ceb5300           -mov esi, dword ptr [0x53eb5c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5499740) /* 0x53eb5c */);
    // 0046eede  8a442410               -mov al, byte ptr [esp + 0x10]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046eee2  8d7c2410               -lea edi, [esp + 0x10]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046eee6  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046eee8  8d842480000000         -lea eax, [esp + 0x80]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 0046eeef  89355ceb5300           -mov dword ptr [0x53eb5c], esi
    app->getMemory<x86::reg32>(x86::reg32(5499740) /* 0x53eb5c */) = cpu.esi;
    // 0046eef5  e8c6020000             -call 0x46f1c0
    cpu.esp -= 4;
    sub_46f1c0(app, cpu);
    if (cpu.terminate) return;
    // 0046eefa  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046eefc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046eefd  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046eeff  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0046ef02  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046ef04  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0046ef06  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0046ef09  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0046ef0b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ef0c  bf5c0b5200             -mov edi, 0x520b5c
    cpu.edi = 5376860 /*0x520b5c*/;
    // 0046ef11  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046ef15  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046ef17  8b2d5ceb5300           -mov ebp, dword ptr [0x53eb5c]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5499740) /* 0x53eb5c */);
    // 0046ef1d  8a4c2410               -mov cl, byte ptr [esp + 0x10]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046ef21  01ef                   -add edi, ebp
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0046ef23  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046ef24  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046ef26  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0046ef29  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046ef2b  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0046ef2d  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0046ef30  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0046ef32  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ef33  b921000000             -mov ecx, 0x21
    cpu.ecx = 33 /*0x21*/;
    // 0046ef38  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046ef3a  8b155ceb5300           -mov edx, dword ptr [0x53eb5c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5499740) /* 0x53eb5c */);
    // 0046ef40  8a442410               -mov al, byte ptr [esp + 0x10]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046ef44  8d7c2410               -lea edi, [esp + 0x10]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046ef48  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046ef4a  8d8424a0000000         -lea eax, [esp + 0xa0]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(160) /* 0xa0 */);
    // 0046ef51  89155ceb5300           -mov dword ptr [0x53eb5c], edx
    app->getMemory<x86::reg32>(x86::reg32(5499740) /* 0x53eb5c */) = cpu.edx;
    // 0046ef57  e864020000             -call 0x46f1c0
    cpu.esp -= 4;
    sub_46f1c0(app, cpu);
    if (cpu.terminate) return;
    // 0046ef5c  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046ef5e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046ef5f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046ef61  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0046ef64  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046ef66  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0046ef68  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0046ef6b  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0046ef6d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ef6e  bf5c0b5200             -mov edi, 0x520b5c
    cpu.edi = 5376860 /*0x520b5c*/;
    // 0046ef73  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046ef77  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046ef79  8b1d5ceb5300           -mov ebx, dword ptr [0x53eb5c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5499740) /* 0x53eb5c */);
    // 0046ef7f  8a4c2410               -mov cl, byte ptr [esp + 0x10]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046ef83  01df                   -add edi, ebx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0046ef85  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046ef86  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046ef88  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0046ef8b  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046ef8d  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0046ef8f  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0046ef92  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0046ef94  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ef95  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046ef97  8b355ceb5300           -mov esi, dword ptr [0x53eb5c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5499740) /* 0x53eb5c */);
    // 0046ef9d  8a442410               -mov al, byte ptr [esp + 0x10]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046efa1  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046efa3  89355ceb5300           -mov dword ptr [0x53eb5c], esi
    app->getMemory<x86::reg32>(x86::reg32(5499740) /* 0x53eb5c */) = cpu.esi;
    // 0046efa9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046efaa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046efab  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046efac  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046efad  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0046efb0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046efb1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046efb2  c28000                 -ret 0x80
    cpu.esp += 4+128 /*0x80*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46efc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046efc0  833d64eb530001         +cmp dword ptr [0x53eb64], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5499748) /* 0x53eb64 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046efc7  7e13                   -jle 0x46efdc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046efdc;
    }
L_0x0046efc9:
    // 0046efc9  833d64eb530001         +cmp dword ptr [0x53eb64], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5499748) /* 0x53eb64 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046efd0  7e09                   -jle 0x46efdb
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046efdb;
    }
    // 0046efd2  833dd8ff500002         +cmp dword ptr [0x50ffd8], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5308376) /* 0x50ffd8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046efd9  7d08                   -jge 0x46efe3
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0046efe3;
    }
L_0x0046efdb:
    // 0046efdb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046efdc:
    // 0046efdc  e88ff9ffff             -call 0x46e970
    cpu.esp -= 4;
    sub_46e970(app, cpu);
    if (cpu.terminate) return;
    // 0046efe1  ebe6                   -jmp 0x46efc9
    goto L_0x0046efc9;
L_0x0046efe3:
    // 0046efe3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046efe4  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0046efe6  8935d8ff5000           -mov dword ptr [0x50ffd8], esi
    app->getMemory<x86::reg32>(x86::reg32(5308376) /* 0x50ffd8 */) = cpu.esi;
    // 0046efec  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046efed  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_46eff0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046eff0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046eff1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046eff2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046eff3  8b1564eb5300           -mov edx, dword ptr [0x53eb64]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5499748) /* 0x53eb64 */);
    // 0046eff9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046effa  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046effb  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0046effd  756d                   -jne 0x46f06c
    if (!cpu.flags.zf)
    {
        goto L_0x0046f06c;
    }
L_0x0046efff:
    // 0046efff  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0046f001:
    // 0046f001  40                     -inc eax
    (cpu.eax)++;
    // 0046f002  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 0046f004  88985b0b5200           -mov byte ptr [eax + 0x520b5b], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5376859) /* 0x520b5b */) = cpu.bl;
    // 0046f00a  3d00e00100             +cmp eax, 0x1e000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(122880 /*0x1e000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046f00f  7cf0                   -jl 0x46f001
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046f001;
    }
    // 0046f011  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0046f013  892d60eb5300           -mov dword ptr [0x53eb60], ebp
    app->getMemory<x86::reg32>(x86::reg32(5499744) /* 0x53eb60 */) = cpu.ebp;
    // 0046f019  892d5ceb5300           -mov dword ptr [0x53eb5c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5499740) /* 0x53eb5c */) = cpu.ebp;
L_0x0046f01f:
    // 0046f01f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046f021  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0046f026  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0046f028:
    // 0046f028  83c014                 -add eax, 0x14
    (cpu.eax) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0046f02b  898870055200           -mov dword ptr [eax + 0x520570], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5375344) /* 0x520570 */) = cpu.ecx;
    // 0046f031  898874055200           -mov dword ptr [eax + 0x520574], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5375348) /* 0x520574 */) = cpu.ecx;
    // 0046f037  898878055200           -mov dword ptr [eax + 0x520578], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5375352) /* 0x520578 */) = cpu.ecx;
    // 0046f03d  89887c055200           -mov dword ptr [eax + 0x52057c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5375356) /* 0x52057c */) = cpu.ecx;
    // 0046f043  89986c055200           -mov dword ptr [eax + 0x52056c], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5375340) /* 0x52056c */) = cpu.ebx;
    // 0046f049  83f828                 +cmp eax, 0x28
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
    // 0046f04c  75da                   -jne 0x46f028
    if (!cpu.flags.zf)
    {
        goto L_0x0046f028;
    }
    // 0046f04e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046f050  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f051  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0046f052:
    // 0046f052  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0046f055  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0046f057  89b03c015200           -mov dword ptr [eax + 0x52013c], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5374268) /* 0x52013c */) = cpu.esi;
    // 0046f05d  83f820                 +cmp eax, 0x20
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
    // 0046f060  75f0                   -jne 0x46f052
    if (!cpu.flags.zf)
    {
        goto L_0x0046f052;
    }
    // 0046f062  891564eb5300           -mov dword ptr [0x53eb64], edx
    app->getMemory<x86::reg32>(x86::reg32(5499748) /* 0x53eb64 */) = cpu.edx;
    // 0046f068  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f069  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f06a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f06b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046f06c:
    // 0046f06c  83fa01                 +cmp edx, 1
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
    // 0046f06f  748e                   -je 0x46efff
    if (cpu.flags.zf)
    {
        goto L_0x0046efff;
    }
    // 0046f071  83fa02                 +cmp edx, 2
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
    // 0046f074  7ca9                   -jl 0x46f01f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046f01f;
    }
    // 0046f076  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046f078  890d60055200           -mov dword ptr [0x520560], ecx
    app->getMemory<x86::reg32>(x86::reg32(5375328) /* 0x520560 */) = cpu.ecx;
    // 0046f07e  890d68055200           -mov dword ptr [0x520568], ecx
    app->getMemory<x86::reg32>(x86::reg32(5375336) /* 0x520568 */) = cpu.ecx;
    // 0046f084  890d70055200           -mov dword ptr [0x520570], ecx
    app->getMemory<x86::reg32>(x86::reg32(5375344) /* 0x520570 */) = cpu.ecx;
    // 0046f08a  890d74055200           -mov dword ptr [0x520574], ecx
    app->getMemory<x86::reg32>(x86::reg32(5375348) /* 0x520574 */) = cpu.ecx;
    // 0046f090  890d78055200           -mov dword ptr [0x520578], ecx
    app->getMemory<x86::reg32>(x86::reg32(5375352) /* 0x520578 */) = cpu.ecx;
    // 0046f096  890d60eb5300           -mov dword ptr [0x53eb60], ecx
    app->getMemory<x86::reg32>(x86::reg32(5499744) /* 0x53eb60 */) = cpu.ecx;
    // 0046f09c  83fa04                 +cmp edx, 4
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
    // 0046f09f  751c                   -jne 0x46f0bd
    if (!cpu.flags.zf)
    {
        goto L_0x0046f0bd;
    }
    // 0046f0a1  833d6c05520000         +cmp dword ptr [0x52056c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5375340) /* 0x52056c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046f0a8  740f                   -je 0x46f0b9
    if (cpu.flags.zf)
    {
        goto L_0x0046f0b9;
    }
    // 0046f0aa  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0046f0af:
    // 0046f0af  a378055200             -mov dword ptr [0x520578], eax
    app->getMemory<x86::reg32>(x86::reg32(5375352) /* 0x520578 */) = cpu.eax;
    // 0046f0b4  e966ffffff             -jmp 0x46f01f
    goto L_0x0046f01f;
L_0x0046f0b9:
    // 0046f0b9  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0046f0bb  ebf2                   -jmp 0x46f0af
    goto L_0x0046f0af;
L_0x0046f0bd:
    // 0046f0bd  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0046f0c2  890d7c055200           -mov dword ptr [0x52057c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5375356) /* 0x52057c */) = cpu.ecx;
    // 0046f0c8  890d6c055200           -mov dword ptr [0x52056c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5375340) /* 0x52056c */) = cpu.ecx;
    // 0046f0ce  891d64055200           -mov dword ptr [0x520564], ebx
    app->getMemory<x86::reg32>(x86::reg32(5375332) /* 0x520564 */) = cpu.ebx;
    // 0046f0d4  e946ffffff             -jmp 0x46f01f
    goto L_0x0046f01f;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46f0e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046f0e0  83ec2c                 -sub esp, 0x2c
    (cpu.esp) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 0046f0e3  a1e4ff5000             -mov eax, dword ptr [0x50ffe4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5308388) /* 0x50ffe4 */);
    // 0046f0e8  a364eb5300             -mov dword ptr [0x53eb64], eax
    app->getMemory<x86::reg32>(x86::reg32(5499748) /* 0x53eb64 */) = cpu.eax;
    // 0046f0ed  83f802                 +cmp eax, 2
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
    // 0046f0f0  7404                   -je 0x46f0f6
    if (cpu.flags.zf)
    {
        goto L_0x0046f0f6;
    }
    // 0046f0f2  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 0046f0f5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046f0f6:
    // 0046f0f6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046f0f7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046f0f8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046f0f9  b90b000000             -mov ecx, 0xb
    cpu.ecx = 11 /*0xb*/;
    // 0046f0fe  8d7c240c               -lea edi, [esp + 0xc]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046f102  be04005100             -mov esi, 0x510004
    cpu.esi = 5308420 /*0x510004*/;
    // 0046f107  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046f109  b96c010000             -mov ecx, 0x16c
    cpu.ecx = 364 /*0x16c*/;
    // 0046f10e  bfc8ff5000             -mov edi, 0x50ffc8
    cpu.edi = 5308360 /*0x50ffc8*/;
    // 0046f113  bea8055200             -mov esi, 0x5205a8
    cpu.esi = 5375400 /*0x5205a8*/;
    // 0046f118  e8e3f7ffff             -call 0x46e900
    cpu.esp -= 4;
    sub_46e900(app, cpu);
    if (cpu.terminate) return;
    // 0046f11d  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046f11f  b90b000000             -mov ecx, 0xb
    cpu.ecx = 11 /*0xb*/;
    // 0046f124  8d74240c               -lea esi, [esp + 0xc]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046f128  bf04005100             -mov edi, 0x510004
    cpu.edi = 5308420 /*0x510004*/;
    // 0046f12d  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046f12f  a1580b5200             -mov eax, dword ptr [0x520b58]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5376856) /* 0x520b58 */);
    // 0046f134  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046f136  a378734d00             -mov dword ptr [0x4d7378], eax
    app->getMemory<x86::reg32>(x86::reg32(5075832) /* 0x4d7378 */) = cpu.eax;
    // 0046f13b  890d60eb5300           -mov dword ptr [0x53eb60], ecx
    app->getMemory<x86::reg32>(x86::reg32(5499744) /* 0x53eb60 */) = cpu.ecx;
    // 0046f141  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f142  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f143  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f144  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 0046f147  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46f150(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046f150  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046f151  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046f152  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046f153  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046f154  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046f155  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046f156  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0046f159  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0046f15b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046f15d  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0046f162  8a4d00                 -mov cl, byte ptr [ebp]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebp);
    // 0046f165  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046f167  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 0046f16a  39d1                   +cmp ecx, edx
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
    // 0046f16c  7e2b                   -jle 0x46f199
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046f199;
    }
L_0x0046f16e:
    // 0046f16e  8d342a                 -lea esi, [edx + ebp]
    cpu.esi = x86::reg32(cpu.edx + cpu.ebp * 1);
    // 0046f171  8a0e                   -mov cl, byte ptr [esi]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi);
    // 0046f173  80f9ff                 +cmp cl, 0xff
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0046f176  7530                   -jne 0x46f1a8
    if (!cpu.flags.zf)
    {
        goto L_0x0046f1a8;
    }
    // 0046f178  0fb67e01               -movzx edi, byte ptr [esi + 1]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */));
    // 0046f17c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046f17e  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0046f180  7e0f                   -jle 0x46f191
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046f191;
    }
L_0x0046f182:
    // 0046f182  40                     -inc eax
    (cpu.eax)++;
    // 0046f183  8a5e02                 -mov bl, byte ptr [esi + 2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 0046f186  41                     -inc ecx
    (cpu.ecx)++;
    // 0046f187  88981f015200           -mov byte ptr [eax + 0x52011f], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5374239) /* 0x52011f */) = cpu.bl;
    // 0046f18d  39f9                   +cmp ecx, edi
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
    // 0046f18f  7cf1                   -jl 0x46f182
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046f182;
    }
L_0x0046f191:
    // 0046f191  83c203                 -add edx, 3
    (cpu.edx) += x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x0046f194:
    // 0046f194  3b1424                 +cmp edx, dword ptr [esp]
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
    // 0046f197  7cd5                   -jl 0x46f16e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046f16e;
    }
L_0x0046f199:
    // 0046f199  b820015200             -mov eax, 0x520120
    cpu.eax = 5374240 /*0x520120*/;
    // 0046f19e  83c404                 +add esp, 4
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
    // 0046f1a1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f1a2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f1a3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f1a4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f1a5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f1a6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f1a7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046f1a8:
    // 0046f1a8  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0046f1a9  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0046f1aa  88881f015200           -mov byte ptr [eax + 0x52011f], cl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5374239) /* 0x52011f */) = cpu.cl;
    // 0046f1b0  ebe2                   -jmp 0x46f194
    goto L_0x0046f194;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46f1c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046f1c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046f1c1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046f1c2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046f1c3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046f1c4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046f1c5  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0046f1c7  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0046f1cc  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0046f1ce:
    // 0046f1ce  8d340f                 -lea esi, [edi + ecx]
    cpu.esi = x86::reg32(cpu.edi + cpu.ecx * 1);
    // 0046f1d1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046f1d3  8a1e                   -mov bl, byte ptr [esi]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi);
L_0x0046f1d5:
    // 0046f1d5  41                     -inc ecx
    (cpu.ecx)++;
    // 0046f1d6  8a7e01                 -mov bh, byte ptr [esi + 1]
    cpu.bh = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0046f1d9  46                     -inc esi
    (cpu.esi)++;
    // 0046f1da  42                     -inc edx
    (cpu.edx)++;
    // 0046f1db  38df                   +cmp bh, bl
    {
        x86::reg8 tmp1 = cpu.bh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.bl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0046f1dd  7505                   -jne 0x46f1e4
    if (!cpu.flags.zf)
    {
        goto L_0x0046f1e4;
    }
    // 0046f1df  83f920                 +cmp ecx, 0x20
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046f1e2  7cf1                   -jl 0x46f1d5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046f1d5;
    }
L_0x0046f1e4:
    // 0046f1e4  83fa03                 +cmp edx, 3
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
    // 0046f1e7  7c34                   -jl 0x46f21d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046f21d;
    }
    // 0046f1e9  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0046f1ec  b6ff                   -mov dh, 0xff
    cpu.dh = 255 /*0xff*/;
    // 0046f1ee  889867eb5300           -mov byte ptr [eax + 0x53eb67], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5499751) /* 0x53eb67 */) = cpu.bl;
    // 0046f1f4  889066eb5300           -mov byte ptr [eax + 0x53eb66], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5499750) /* 0x53eb66 */) = cpu.dl;
    // 0046f1fa  88b065eb5300           -mov byte ptr [eax + 0x53eb65], dh
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5499749) /* 0x53eb65 */) = cpu.dh;
L_0x0046f200:
    // 0046f200  83f920                 +cmp ecx, 0x20
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046f203  7cc9                   -jl 0x46f1ce
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046f1ce;
    }
    // 0046f205  a268eb5300             -mov byte ptr [0x53eb68], al
    app->getMemory<x86::reg8>(x86::reg32(5499752) /* 0x53eb68 */) = cpu.al;
    // 0046f20a  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 0046f20c  889868eb5300           -mov byte ptr [eax + 0x53eb68], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5499752) /* 0x53eb68 */) = cpu.bl;
    // 0046f212  b868eb5300             -mov eax, 0x53eb68
    cpu.eax = 5499752 /*0x53eb68*/;
    // 0046f217  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f218  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f219  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f21a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f21b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f21c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046f21d:
    // 0046f21d  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0046f21f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0046f221  7edd                   -jle 0x46f200
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046f200;
    }
L_0x0046f223:
    // 0046f223  40                     -inc eax
    (cpu.eax)++;
    // 0046f224  46                     -inc esi
    (cpu.esi)++;
    // 0046f225  889867eb5300           -mov byte ptr [eax + 0x53eb67], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5499751) /* 0x53eb67 */) = cpu.bl;
    // 0046f22b  39d6                   +cmp esi, edx
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
    // 0046f22d  7cf4                   -jl 0x46f223
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046f223;
    }
    // 0046f22f  ebcf                   -jmp 0x46f200
    goto L_0x0046f200;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46f240(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046f240  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046f241  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046f242  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046f243  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046f244  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046f245  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046f246  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0046f249  bb00000600             -mov ebx, 0x60000
    cpu.ebx = 393216 /*0x60000*/;
    // 0046f24e  b800000100             -mov eax, 0x10000
    cpu.eax = 65536 /*0x10000*/;
    // 0046f253  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0046f254  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0046f256  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046f258  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046f25a  0facd010               -shrd eax, edx, 0x10
    {
        x86::reg32& destination = cpu.eax;
        destination >>= (16 /*0x10*/ % 32);
        destination |= cpu.edx  << (32 - (16 /*0x10*/ % 32));
    }
    // 0046f25e  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0046f261  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0046f263  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 0046f266  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046f268  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0046f26a  bb00000300             -mov ebx, 0x30000
    cpu.ebx = 196608 /*0x30000*/;
    // 0046f26f  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0046f273  b800000200             -mov eax, 0x20000
    cpu.eax = 131072 /*0x20000*/;
    // 0046f278  896c240c               -mov dword ptr [esp + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 0046f27c  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0046f27d  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0046f27f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046f281  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046f283  0facd010               -shrd eax, edx, 0x10
    {
        x86::reg32& destination = cpu.eax;
        destination >>= (16 /*0x10*/ % 32);
        destination |= cpu.edx  << (32 - (16 /*0x10*/ % 32));
    }
    // 0046f287  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0046f28a  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0046f28c  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 0046f28f  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046f291  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x0046f295:
    // 0046f295  bb00001300             -mov ebx, 0x130000
    cpu.ebx = 1245184 /*0x130000*/;
    // 0046f29a  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046f29e  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0046f29f  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0046f2a1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046f2a3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046f2a5  0facd010               -shrd eax, edx, 0x10
    {
        x86::reg32& destination = cpu.eax;
        destination >>= (16 /*0x10*/ % 32);
        destination |= cpu.edx  << (32 - (16 /*0x10*/ % 32));
    }
    // 0046f2a9  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0046f2ac  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0046f2ae  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 0046f2b1  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046f2b3  bb00000600             -mov ebx, 0x60000
    cpu.ebx = 393216 /*0x60000*/;
    // 0046f2b8  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046f2ba  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046f2bc  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0046f2be  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0046f2c1  c1e810                 +shr eax, 0x10
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
    // 0046f2c4  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0046f2c6  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0046f2c8  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0046f2cb  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0046f2cd  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0046f2d0  c1e810                 +shr eax, 0x10
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
    // 0046f2d3  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0046f2d5  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0046f2d7  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0046f2d8  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0046f2da  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046f2dc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046f2de  0facd010               -shrd eax, edx, 0x10
    {
        x86::reg32& destination = cpu.eax;
        destination >>= (16 /*0x10*/ % 32);
        destination |= cpu.edx  << (32 - (16 /*0x10*/ % 32));
    }
    // 0046f2e2  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0046f2e5  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0046f2e7  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 0046f2ea  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046f2ec  89852cec5300           -mov dword ptr [ebp + 0x53ec2c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(5499948) /* 0x53ec2c */) = cpu.eax;
    // 0046f2f2  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0046f2f5  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0046f2f7  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0046f2f9  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046f2fd  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0046f2ff  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046f301  89857cec5300           -mov dword ptr [ebp + 0x53ec7c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(5500028) /* 0x53ec7c */) = cpu.eax;
    // 0046f307  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0046f309  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 0046f30c  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0046f30e  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046f312  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046f314  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046f316  89858ceb5300           -mov dword ptr [ebp + 0x53eb8c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(5499788) /* 0x53eb8c */) = cpu.eax;
    // 0046f31c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0046f31e  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0046f321  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0046f323  bb00000600             -mov ebx, 0x60000
    cpu.ebx = 393216 /*0x60000*/;
    // 0046f328  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046f32a  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0046f32c  d1fe                   -sar esi, 1
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (1 /*0x1*/ % 32));
    // 0046f32e  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0046f32f  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0046f331  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046f333  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046f335  0facd010               -shrd eax, edx, 0x10
    {
        x86::reg32& destination = cpu.eax;
        destination >>= (16 /*0x10*/ % 32);
        destination |= cpu.edx  << (32 - (16 /*0x10*/ % 32));
    }
    // 0046f339  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0046f33c  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0046f33e  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 0046f341  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046f343  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046f347  8b54240e               -mov edx, dword ptr [esp + 0xe]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(14) /* 0xe */);
    // 0046f34b  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0046f34d  42                     -inc edx
    (cpu.edx)++;
    // 0046f34e  8d040e                 -lea eax, [esi + ecx]
    cpu.eax = x86::reg32(cpu.esi + cpu.ecx * 1);
    // 0046f351  668954240e             -mov word ptr [esp + 0xe], dx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(14) /* 0xe */) = cpu.dx;
    // 0046f356  8985d8eb5300           -mov dword ptr [ebp + 0x53ebd8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(5499864) /* 0x53ebd8 */) = cpu.eax;
    // 0046f35c  83fd50                 +cmp ebp, 0x50
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(80 /*0x50*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046f35f  0f8530ffffff           -jne 0x46f295
    if (!cpu.flags.zf)
    {
        goto L_0x0046f295;
    }
    // 0046f365  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0046f368  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f369  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f36a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f36b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f36c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f36d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f36e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_46f370(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046f370  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046f371  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046f372  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046f374  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0046f376  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 0046f378  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0046f37a  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0046f37c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046f37e  7e21                   -jle 0x46f3a1
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046f3a1;
    }
L_0x0046f380:
    // 0046f380  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046f382  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0046f385  2b4108                 -sub eax, dword ptr [ecx + 8]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */)));
    // 0046f388  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046f38a  7e19                   -jle 0x46f3a5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046f3a5;
    }
L_0x0046f38c:
    // 0046f38c  39c2                   +cmp edx, eax
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
    // 0046f38e  7e19                   -jle 0x46f3a9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046f3a9;
    }
    // 0046f390  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 0046f393  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046f395  39d8                   +cmp eax, ebx
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
    // 0046f397  7d21                   -jge 0x46f3ba
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0046f3ba;
    }
    // 0046f399  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0046f39e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f39f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f3a0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046f3a1:
    // 0046f3a1  f7d8                   +neg eax
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
    // 0046f3a3  ebdb                   -jmp 0x46f380
    goto L_0x0046f380;
L_0x0046f3a5:
    // 0046f3a5  f7d8                   +neg eax
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
    // 0046f3a7  ebe3                   -jmp 0x46f38c
    goto L_0x0046f38c;
L_0x0046f3a9:
    // 0046f3a9  c1fa02                 -sar edx, 2
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (2 /*0x2*/ % 32));
    // 0046f3ac  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046f3ae  39d8                   +cmp eax, ebx
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
    // 0046f3b0  7d08                   -jge 0x46f3ba
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0046f3ba;
    }
    // 0046f3b2  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0046f3b7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f3b8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f3b9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046f3ba:
    // 0046f3ba  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046f3bc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f3bd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f3be  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_46f3c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046f3c0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046f3c1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046f3c2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046f3c3  81ec00010000           -sub esp, 0x100
    (cpu.esp) -= x86::reg32(x86::sreg32(256 /*0x100*/));
    // 0046f3c9  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046f3cb  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046f3cc  b32f                   -mov bl, 0x2f
    cpu.bl = 47 /*0x2f*/;
    // 0046f3ce  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0046f3d0  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0046f3d2:
    // 0046f3d2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046f3d4  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 0046f3d6  e855000000             -call 0x46f430
    cpu.esp -= 4;
    sub_46f430(app, cpu);
    if (cpu.terminate) return;
    // 0046f3db  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0046f3dd  7418                   -je 0x46f3f7
    if (cpu.flags.zf)
    {
        goto L_0x0046f3f7;
    }
    // 0046f3df  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0046f3e0:
    // 0046f3e0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046f3e2  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 0046f3e4  e847000000             -call 0x46f430
    cpu.esp -= 4;
    sub_46f430(app, cpu);
    if (cpu.terminate) return;
    // 0046f3e9  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0046f3eb  741e                   -je 0x46f40b
    if (cpu.flags.zf)
    {
        goto L_0x0046f40b;
    }
    // 0046f3ed  41                     +inc ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0046f3ee  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 0046f3f0  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0046f3f1  88440cff               -mov byte ptr [esp + ecx - 1], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(-1) /* -0x1 */ + cpu.ecx * 1) = cpu.al;
    // 0046f3f5  ebe9                   -jmp 0x46f3e0
    goto L_0x0046f3e0;
L_0x0046f3f7:
    // 0046f3f7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046f3f9  8a38                   -mov bh, byte ptr [eax]
    cpu.bh = app->getMemory<x86::reg8>(cpu.eax);
    // 0046f3fb  42                     -inc edx
    (cpu.edx)++;
    // 0046f3fc  38fb                   +cmp bl, bh
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.bh));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0046f3fe  75d2                   -jne 0x46f3d2
    if (!cpu.flags.zf)
    {
        goto L_0x0046f3d2;
    }
L_0x0046f400:
    // 0046f400  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046f402  8a38                   -mov bh, byte ptr [eax]
    cpu.bh = app->getMemory<x86::reg8>(cpu.eax);
    // 0046f404  42                     -inc edx
    (cpu.edx)++;
    // 0046f405  38fb                   +cmp bl, bh
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.bh));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0046f407  75f7                   -jne 0x46f400
    if (!cpu.flags.zf)
    {
        goto L_0x0046f400;
    }
    // 0046f409  ebc7                   -jmp 0x46f3d2
    goto L_0x0046f3d2;
L_0x0046f40b:
    // 0046f40b  88040c                 -mov byte ptr [esp + ecx], al
    app->getMemory<x86::reg8>(cpu.esp + cpu.ecx * 1) = cpu.al;
    // 0046f40e  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0046f410  e86fb60200             -call 0x49aa84
    cpu.esp -= 4;
    sub_49aa84(app, cpu);
    if (cpu.terminate) return;
    // 0046f415  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 0046f417  81c400010000           -add esp, 0x100
    (cpu.esp) += x86::reg32(x86::sreg32(256 /*0x100*/));
    // 0046f41d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f41e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f41f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f420  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46f430(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046f430  3c30                   +cmp al, 0x30
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
    // 0046f432  7204                   -jb 0x46f438
    if (cpu.flags.cf)
    {
        goto L_0x0046f438;
    }
    // 0046f434  3c39                   +cmp al, 0x39
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
    // 0046f436  7608                   -jbe 0x46f440
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0046f440;
    }
L_0x0046f438:
    // 0046f438  3c2d                   +cmp al, 0x2d
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(45 /*0x2d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0046f43a  7404                   -je 0x46f440
    if (cpu.flags.zf)
    {
        goto L_0x0046f440;
    }
    // 0046f43c  3c2b                   +cmp al, 0x2b
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(43 /*0x2b*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0046f43e  7503                   -jne 0x46f443
    if (!cpu.flags.zf)
    {
        goto L_0x0046f443;
    }
L_0x0046f440:
    // 0046f440  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
    // 0046f442  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046f443:
    // 0046f443  30c0                   -xor al, al
    cpu.al ^= x86::reg8(x86::sreg8(cpu.al));
    // 0046f445  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46f450(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046f450  a1ccec5300             -mov eax, dword ptr [0x53eccc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5500108) /* 0x53eccc */);
    // 0046f455  e812390100             -call 0x482d6c
    cpu.esp -= 4;
    sub_482d6c(app, cpu);
    if (cpu.terminate) return;
    // 0046f45a  a1d0ec5300             -mov eax, dword ptr [0x53ecd0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5500112) /* 0x53ecd0 */);
    // 0046f45f  e908390100             -jmp 0x482d6c
    return sub_482d6c(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46f470(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046f470  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046f471  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046f472  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046f473  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046f474  ba64bd4c00             -mov edx, 0x4cbd64
    cpu.edx = 5029220 /*0x4cbd64*/;
    // 0046f479  b9d0000000             -mov ecx, 0xd0
    cpu.ecx = 208 /*0xd0*/;
    // 0046f47e  b884bd4c00             -mov eax, 0x4cbd84
    cpu.eax = 5029252 /*0x4cbd84*/;
    // 0046f483  bed1000000             -mov esi, 0xd1
    cpu.esi = 209 /*0xd1*/;
    // 0046f488  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046f48a  8915f48f4d00           -mov dword ptr [0x4d8ff4], edx
    app->getMemory<x86::reg32>(x86::reg32(5083124) /* 0x4d8ff4 */) = cpu.edx;
    // 0046f490  ba60130000             -mov edx, 0x1360
    cpu.edx = 4960 /*0x1360*/;
    // 0046f495  890df88f4d00           -mov dword ptr [0x4d8ff8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5083128) /* 0x4d8ff8 */) = cpu.ecx;
    // 0046f49b  e868340100             -call 0x482908
    cpu.esp -= 4;
    sub_482908(app, cpu);
    if (cpu.terminate) return;
    // 0046f4a0  bb64bd4c00             -mov ebx, 0x4cbd64
    cpu.ebx = 5029220 /*0x4cbd64*/;
    // 0046f4a5  ba60130000             -mov edx, 0x1360
    cpu.edx = 4960 /*0x1360*/;
    // 0046f4aa  a3ccec5300             -mov dword ptr [0x53eccc], eax
    app->getMemory<x86::reg32>(x86::reg32(5500108) /* 0x53eccc */) = cpu.eax;
    // 0046f4af  b89cbd4c00             -mov eax, 0x4cbd9c
    cpu.eax = 5029276 /*0x4cbd9c*/;
    // 0046f4b4  891df48f4d00           -mov dword ptr [0x4d8ff4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5083124) /* 0x4d8ff4 */) = cpu.ebx;
    // 0046f4ba  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046f4bc  8935f88f4d00           -mov dword ptr [0x4d8ff8], esi
    app->getMemory<x86::reg32>(x86::reg32(5083128) /* 0x4d8ff8 */) = cpu.esi;
    // 0046f4c2  e841340100             -call 0x482908
    cpu.esp -= 4;
    sub_482908(app, cpu);
    if (cpu.terminate) return;
    // 0046f4c7  a3d0ec5300             -mov dword ptr [0x53ecd0], eax
    app->getMemory<x86::reg32>(x86::reg32(5500112) /* 0x53ecd0 */) = cpu.eax;
    // 0046f4cc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f4cd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f4ce  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f4cf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f4d0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46f4e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046f4e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046f4e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046f4e2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046f4e3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046f4e4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046f4e5  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046f4e8  8b2dccec5300           -mov ebp, dword ptr [0x53eccc]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5500108) /* 0x53eccc */);
    // 0046f4ee  89742408               -mov dword ptr [esp + 8], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 0046f4f2  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046f4f4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046f4f6  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0046f4f8:
    // 0046f4f8  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0046f4fa  833c0200               +cmp dword ptr [edx + eax], 0
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
    // 0046f4fe  752c                   -jne 0x46f52c
    if (!cpu.flags.zf)
    {
        goto L_0x0046f52c;
    }
L_0x0046f500:
    // 0046f500  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0046f503  3d60130000             +cmp eax, 0x1360
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4960 /*0x1360*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046f508  75ee                   -jne 0x46f4f8
    if (!cpu.flags.zf)
    {
        goto L_0x0046f4f8;
    }
    // 0046f50a  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046f50e  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0046f510  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0046f514  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0046f517  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0046f518  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0046f519  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046f51d  892dccec5300           -mov dword ptr [0x53eccc], ebp
    app->getMemory<x86::reg32>(x86::reg32(5500108) /* 0x53eccc */) = cpu.ebp;
    // 0046f523  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046f526  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f527  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f528  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f529  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f52a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f52b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046f52c:
    // 0046f52c  8b15d0ec5300           -mov edx, dword ptr [0x53ecd0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5500112) /* 0x53ecd0 */);
    // 0046f532  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046f534  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 0046f536  891e                   -mov dword ptr [esi], ebx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ebx;
    // 0046f538  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0046f53a  7502                   -jne 0x46f53e
    if (!cpu.flags.zf)
    {
        goto L_0x0046f53e;
    }
    // 0046f53c  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
L_0x0046f53e:
    // 0046f53e  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0046f540  8b1c02                 -mov ebx, dword ptr [edx + eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 1);
    // 0046f543  ebbb                   -jmp 0x46f500
    goto L_0x0046f500;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46f550(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046f550  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046f551  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046f552  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046f553  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0046f556  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046f55a  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0046f55c  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0046f55e  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0046f562  81ef00000a00           -sub edi, 0xa0000
    (cpu.edi) -= x86::reg32(x86::sreg32(655360 /*0xa0000*/));
    // 0046f568  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0046f56a  7442                   -je 0x46f5ae
    if (cpu.flags.zf)
    {
        goto L_0x0046f5ae;
    }
    // 0046f56c  8b28                   -mov ebp, dword ptr [eax]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax);
    // 0046f56e  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0046f570  0f8eb2000000           -jle 0x46f628
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046f628;
    }
    // 0046f576  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
L_0x0046f578:
    // 0046f578  3b4808                 +cmp ecx, dword ptr [eax + 8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046f57b  7e31                   -jle 0x46f5ae
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046f5ae;
    }
    // 0046f57d  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0046f57f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0046f581  0f8eaa000000           -jle 0x46f631
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046f631;
    }
L_0x0046f587:
    // 0046f587  3b4e08                 +cmp ecx, dword ptr [esi + 8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046f58a  7e22                   -jle 0x46f5ae
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046f5ae;
    }
    // 0046f58c  8b0b                   -mov ecx, dword ptr [ebx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0046f58e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0046f590  0f8ea2000000           -jle 0x46f638
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046f638;
    }
L_0x0046f596:
    // 0046f596  3b4b08                 +cmp ecx, dword ptr [ebx + 8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046f599  7e13                   -jle 0x46f5ae
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046f5ae;
    }
    // 0046f59b  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 0046f59d  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0046f59f  0f8e9a000000           -jle 0x46f63f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046f63f;
    }
L_0x0046f5a5:
    // 0046f5a5  3b4a08                 +cmp ecx, dword ptr [edx + 8]
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
    // 0046f5a8  0f8fad000000           -jg 0x46f65b
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0046f65b;
    }
L_0x0046f5ae:
    // 0046f5ae  8b480a                 -mov ecx, dword ptr [eax + 0xa]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10) /* 0xa */);
    // 0046f5b1  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0046f5b4  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0046f5b7  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0046f5b9  8b4e0a                 -mov ecx, dword ptr [esi + 0xa]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(10) /* 0xa */);
    // 0046f5bc  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0046f5bf  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0046f5c2  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0046f5c5  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 0046f5c8  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0046f5ca  8b4b0a                 -mov ecx, dword ptr [ebx + 0xa]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(10) /* 0xa */);
    // 0046f5cd  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046f5cf  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0046f5d2  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0046f5d5  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0046f5d7  8b4a0a                 -mov ecx, dword ptr [edx + 0xa]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(10) /* 0xa */);
    // 0046f5da  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0046f5dd  8b5208                 -mov edx, dword ptr [edx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0046f5e0  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0046f5e2  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 0046f5e4  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046f5e6  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 0046f5e9  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0046f5eb  c1f80f                 -sar eax, 0xf
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (15 /*0xf*/ % 32));
    // 0046f5ee  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046f5f0  7c69                   -jl 0x46f65b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046f65b;
    }
    // 0046f5f2  3dd7040000             +cmp eax, 0x4d7
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1239 /*0x4d7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046f5f7  7f62                   -jg 0x46f65b
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0046f65b;
    }
    // 0046f5f9  8b15ccec5300           -mov edx, dword ptr [0x53eccc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5500108) /* 0x53eccc */);
    // 0046f5ff  8d0c8500000000         -lea ecx, [eax*4]
    cpu.ecx = x86::reg32(cpu.eax * 4);
    // 0046f606  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046f608  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0046f60a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046f60c  7438                   -je 0x46f646
    if (cpu.flags.zf)
    {
        goto L_0x0046f646;
    }
    // 0046f60e  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0046f612  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 0046f614  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046f618  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
L_0x0046f61a:
    // 0046f61a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0046f61f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0046f622  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f623  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f624  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f625  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x0046f628:
    // 0046f628  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0046f62a  f7d9                   +neg ecx
    {
        x86::reg32 tmp1 = 0;
        x86::reg32& tmp2 = cpu.ecx;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 0046f62c  e947ffffff             -jmp 0x46f578
    goto L_0x0046f578;
L_0x0046f631:
    // 0046f631  f7d9                   +neg ecx
    {
        x86::reg32 tmp1 = 0;
        x86::reg32& tmp2 = cpu.ecx;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 0046f633  e94fffffff             -jmp 0x46f587
    goto L_0x0046f587;
L_0x0046f638:
    // 0046f638  f7d9                   +neg ecx
    {
        x86::reg32 tmp1 = 0;
        x86::reg32& tmp2 = cpu.ecx;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 0046f63a  e957ffffff             -jmp 0x46f596
    goto L_0x0046f596;
L_0x0046f63f:
    // 0046f63f  f7d9                   +neg ecx
    {
        x86::reg32 tmp1 = 0;
        x86::reg32& tmp2 = cpu.ecx;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 0046f641  e95fffffff             -jmp 0x46f5a5
    goto L_0x0046f5a5;
L_0x0046f646:
    // 0046f646  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046f64a  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 0046f64c  a1d0ec5300             -mov eax, dword ptr [0x53ecd0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5500112) /* 0x53ecd0 */);
    // 0046f651  01c1                   +add ecx, eax
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
    // 0046f653  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0046f657  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 0046f659  ebbf                   -jmp 0x46f61a
    goto L_0x0046f61a;
L_0x0046f65b:
    // 0046f65b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046f65d  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0046f660  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f661  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f662  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f663  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46f670(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046f670  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046f671  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046f672  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046f673  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0046f676  8b7c2418               -mov edi, dword ptr [esp + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046f67a  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0046f67c  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046f680  81e900000a00           -sub ecx, 0xa0000
    (cpu.ecx) -= x86::reg32(x86::sreg32(655360 /*0xa0000*/));
    // 0046f686  8b28                   -mov ebp, dword ptr [eax]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax);
    // 0046f688  894c2414               -mov dword ptr [esp + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 0046f68c  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0046f68e  0f8ead000000           -jle 0x46f741
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046f741;
    }
    // 0046f694  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
L_0x0046f696:
    // 0046f696  3b4808                 +cmp ecx, dword ptr [eax + 8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046f699  7e31                   -jle 0x46f6cc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046f6cc;
    }
    // 0046f69b  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 0046f69d  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0046f69f  0f8ea5000000           -jle 0x46f74a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046f74a;
    }
L_0x0046f6a5:
    // 0046f6a5  3b4a08                 +cmp ecx, dword ptr [edx + 8]
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
    // 0046f6a8  7e22                   -jle 0x46f6cc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046f6cc;
    }
    // 0046f6aa  8b0b                   -mov ecx, dword ptr [ebx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0046f6ac  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0046f6ae  0f8e9d000000           -jle 0x46f751
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046f751;
    }
L_0x0046f6b4:
    // 0046f6b4  3b4b08                 +cmp ecx, dword ptr [ebx + 8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046f6b7  7e13                   -jle 0x46f6cc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046f6cc;
    }
    // 0046f6b9  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0046f6bb  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0046f6bd  0f8e95000000           -jle 0x46f758
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046f758;
    }
L_0x0046f6c3:
    // 0046f6c3  3b4e08                 +cmp ecx, dword ptr [esi + 8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046f6c6  0f8fa1000000           -jg 0x46f76d
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0046f76d;
    }
L_0x0046f6cc:
    // 0046f6cc  8b480a                 -mov ecx, dword ptr [eax + 0xa]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(10) /* 0xa */);
    // 0046f6cf  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0046f6d2  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0046f6d5  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0046f6d7  8b4a0a                 -mov ecx, dword ptr [edx + 0xa]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(10) /* 0xa */);
    // 0046f6da  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0046f6dd  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0046f6e0  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0046f6e3  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0046f6e6  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0046f6e8  8b4b0a                 -mov ecx, dword ptr [ebx + 0xa]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(10) /* 0xa */);
    // 0046f6eb  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046f6ed  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0046f6f0  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0046f6f3  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0046f6f5  8b4e0a                 -mov ecx, dword ptr [esi + 0xa]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(10) /* 0xa */);
    // 0046f6f8  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046f6fa  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0046f6fd  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0046f700  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0046f702  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046f704  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046f708  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 0046f70b  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0046f70d  c1f80f                 -sar eax, 0xf
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (15 /*0xf*/ % 32));
    // 0046f710  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046f712  7c59                   -jl 0x46f76d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046f76d;
    }
    // 0046f714  3dd7040000             +cmp eax, 0x4d7
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1239 /*0x4d7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046f719  7f52                   -jg 0x46f76d
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0046f76d;
    }
    // 0046f71b  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 0046f722  a1ccec5300             -mov eax, dword ptr [0x53eccc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5500108) /* 0x53eccc */);
    // 0046f727  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046f729  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0046f72b  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0046f72d  7430                   -je 0x46f75f
    if (cpu.flags.zf)
    {
        goto L_0x0046f75f;
    }
    // 0046f72f  890f                   -mov dword ptr [edi], ecx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.ecx;
    // 0046f731  8938                   -mov dword ptr [eax], edi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edi;
L_0x0046f733:
    // 0046f733  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0046f738  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0046f73b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f73c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f73d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f73e  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0046f741:
    // 0046f741  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0046f743  f7d9                   +neg ecx
    {
        x86::reg32 tmp1 = 0;
        x86::reg32& tmp2 = cpu.ecx;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 0046f745  e94cffffff             -jmp 0x46f696
    goto L_0x0046f696;
L_0x0046f74a:
    // 0046f74a  f7d9                   +neg ecx
    {
        x86::reg32 tmp1 = 0;
        x86::reg32& tmp2 = cpu.ecx;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 0046f74c  e954ffffff             -jmp 0x46f6a5
    goto L_0x0046f6a5;
L_0x0046f751:
    // 0046f751  f7d9                   +neg ecx
    {
        x86::reg32 tmp1 = 0;
        x86::reg32& tmp2 = cpu.ecx;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 0046f753  e95cffffff             -jmp 0x46f6b4
    goto L_0x0046f6b4;
L_0x0046f758:
    // 0046f758  f7d9                   +neg ecx
    {
        x86::reg32 tmp1 = 0;
        x86::reg32& tmp2 = cpu.ecx;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 0046f75a  e964ffffff             -jmp 0x46f6c3
    goto L_0x0046f6c3;
L_0x0046f75f:
    // 0046f75f  890f                   -mov dword ptr [edi], ecx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.ecx;
    // 0046f761  8938                   -mov dword ptr [eax], edi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edi;
    // 0046f763  a1d0ec5300             -mov eax, dword ptr [0x53ecd0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5500112) /* 0x53ecd0 */);
    // 0046f768  893c02                 -mov dword ptr [edx + eax], edi
    app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 1) = cpu.edi;
    // 0046f76b  ebc6                   -jmp 0x46f733
    goto L_0x0046f733;
L_0x0046f76d:
    // 0046f76d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046f76f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0046f772  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f773  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f774  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f775  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46f780(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046f780  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046f781  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046f782  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046f783  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046f784  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046f785  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046f786  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046f789  8b54242c               -mov edx, dword ptr [esp + 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0046f78d  81ea00000a00           -sub edx, 0xa0000
    (cpu.edx) -= x86::reg32(x86::sreg32(655360 /*0xa0000*/));
    // 0046f793  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0046f797  8954242c               -mov dword ptr [esp + 0x2c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.edx;
    // 0046f79b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046f79d  7452                   -je 0x46f7f1
    if (cpu.flags.zf)
    {
        goto L_0x0046f7f1;
    }
L_0x0046f79f:
    // 0046f79f  8b6c2430               -mov ebp, dword ptr [esp + 0x30]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0046f7a3  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0046f7a5  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0046f7a8  8b7010                 -mov esi, dword ptr [eax + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0046f7ab  8b7814                 -mov edi, dword ptr [eax + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 0046f7ae  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0046f7b2  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0046f7b5  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0046f7b7  0f8450000000           -je 0x46f80d
    if (cpu.flags.zf)
    {
        goto L_0x0046f80d;
    }
    // 0046f7bd  8b0b                   -mov ecx, dword ptr [ebx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0046f7bf  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0046f7c1  7e3a                   -jle 0x46f7fd
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046f7fd;
    }
L_0x0046f7c3:
    // 0046f7c3  3b4b08                 +cmp ecx, dword ptr [ebx + 8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046f7c6  7e45                   -jle 0x46f80d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046f80d;
    }
    // 0046f7c8  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0046f7ca  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0046f7cc  7e33                   -jle 0x46f801
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046f801;
    }
L_0x0046f7ce:
    // 0046f7ce  3b4e08                 +cmp ecx, dword ptr [esi + 8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046f7d1  7e3a                   -jle 0x46f80d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046f80d;
    }
    // 0046f7d3  8b0f                   -mov ecx, dword ptr [edi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi);
    // 0046f7d5  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0046f7d7  7e2c                   -jle 0x46f805
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046f805;
    }
L_0x0046f7d9:
    // 0046f7d9  3b4f08                 +cmp ecx, dword ptr [edi + 8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046f7dc  7e2f                   -jle 0x46f80d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046f80d;
    }
    // 0046f7de  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 0046f7e0  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0046f7e2  7e25                   -jle 0x46f809
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046f809;
    }
L_0x0046f7e4:
    // 0046f7e4  3b4a08                 +cmp ecx, dword ptr [edx + 8]
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
    // 0046f7e7  7e24                   -jle 0x46f80d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046f80d;
    }
L_0x0046f7e9:
    // 0046f7e9  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046f7ed  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046f7ef  75ae                   -jne 0x46f79f
    if (!cpu.flags.zf)
    {
        goto L_0x0046f79f;
    }
L_0x0046f7f1:
    // 0046f7f1  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046f7f4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f7f5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f7f6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f7f7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f7f8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f7f9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f7fa  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x0046f7fd:
    // 0046f7fd  f7d9                   +neg ecx
    {
        x86::reg32 tmp1 = 0;
        x86::reg32& tmp2 = cpu.ecx;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 0046f7ff  ebc2                   -jmp 0x46f7c3
    goto L_0x0046f7c3;
L_0x0046f801:
    // 0046f801  f7d9                   +neg ecx
    {
        x86::reg32 tmp1 = 0;
        x86::reg32& tmp2 = cpu.ecx;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 0046f803  ebc9                   -jmp 0x46f7ce
    goto L_0x0046f7ce;
L_0x0046f805:
    // 0046f805  f7d9                   +neg ecx
    {
        x86::reg32 tmp1 = 0;
        x86::reg32& tmp2 = cpu.ecx;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 0046f807  ebd0                   -jmp 0x46f7d9
    goto L_0x0046f7d9;
L_0x0046f809:
    // 0046f809  f7d9                   +neg ecx
    {
        x86::reg32 tmp1 = 0;
        x86::reg32& tmp2 = cpu.ecx;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 0046f80b  ebd7                   -jmp 0x46f7e4
    goto L_0x0046f7e4;
L_0x0046f80d:
    // 0046f80d  8b4b0a                 -mov ecx, dword ptr [ebx + 0xa]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(10) /* 0xa */);
    // 0046f810  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0046f813  8b5b08                 -mov ebx, dword ptr [ebx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0046f816  d3e3                   -shl ebx, cl
    cpu.ebx <<= cpu.cl % 32;
    // 0046f818  8b4e0a                 -mov ecx, dword ptr [esi + 0xa]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(10) /* 0xa */);
    // 0046f81b  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0046f81e  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0046f821  8b5e08                 -mov ebx, dword ptr [esi + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0046f824  d3e3                   -shl ebx, cl
    cpu.ebx <<= cpu.cl % 32;
    // 0046f826  031c24                 -add ebx, dword ptr [esp]
    (cpu.ebx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
    // 0046f829  8b4f0a                 -mov ecx, dword ptr [edi + 0xa]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(10) /* 0xa */);
    // 0046f82c  8b7708                 -mov esi, dword ptr [edi + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0046f82f  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0046f832  d3e6                   -shl esi, cl
    cpu.esi <<= cpu.cl % 32;
    // 0046f834  8b4a0a                 -mov ecx, dword ptr [edx + 0xa]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(10) /* 0xa */);
    // 0046f837  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 0046f83a  8b5208                 -mov edx, dword ptr [edx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0046f83d  01f3                   -add ebx, esi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0046f83f  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 0046f841  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0046f843  8b5c242c               -mov ebx, dword ptr [esp + 0x2c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0046f847  c1fa02                 -sar edx, 2
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (2 /*0x2*/ % 32));
    // 0046f84a  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046f84c  c1fa0f                 -sar edx, 0xf
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (15 /*0xf*/ % 32));
    // 0046f84f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0046f851  7c96                   -jl 0x46f7e9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046f7e9;
    }
    // 0046f853  81fad7040000           +cmp edx, 0x4d7
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1239 /*0x4d7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046f859  7f8e                   -jg 0x46f7e9
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0046f7e9;
    }
    // 0046f85b  8d0c9500000000         -lea ecx, [edx*4]
    cpu.ecx = x86::reg32(cpu.edx * 4);
    // 0046f862  8b15ccec5300           -mov edx, dword ptr [0x53eccc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5500108) /* 0x53eccc */);
    // 0046f868  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046f86a  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 0046f86c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0046f86e  7409                   -je 0x46f879
    if (cpu.flags.zf)
    {
        goto L_0x0046f879;
    }
    // 0046f870  8930                   -mov dword ptr [eax], esi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
    // 0046f872  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 0046f874  e970ffffff             -jmp 0x46f7e9
    goto L_0x0046f7e9;
L_0x0046f879:
    // 0046f879  8930                   -mov dword ptr [eax], esi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
    // 0046f87b  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 0046f87d  8b15d0ec5300           -mov edx, dword ptr [0x53ecd0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5500112) /* 0x53ecd0 */);
    // 0046f883  890411                 -mov dword ptr [ecx + edx], eax
    app->getMemory<x86::reg32>(cpu.ecx + cpu.edx * 1) = cpu.eax;
    // 0046f886  e95effffff             -jmp 0x46f7e9
    goto L_0x0046f7e9;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46f890(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046f890  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046f891  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046f892  8d0c8500000000         -lea ecx, [eax*4]
    cpu.ecx = x86::reg32(cpu.eax * 4);
    // 0046f899  a1ccec5300             -mov eax, dword ptr [0x53eccc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5500108) /* 0x53eccc */);
    // 0046f89e  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0046f8a0  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 0046f8a2  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0046f8a4  7407                   -je 0x46f8ad
    if (cpu.flags.zf)
    {
        goto L_0x0046f8ad;
    }
    // 0046f8a6  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 0046f8a8  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0046f8aa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f8ab  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f8ac  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046f8ad:
    // 0046f8ad  891a                   -mov dword ptr [edx], ebx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebx;
    // 0046f8af  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0046f8b1  a1d0ec5300             -mov eax, dword ptr [0x53ecd0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5500112) /* 0x53ecd0 */);
    // 0046f8b6  891401                 -mov dword ptr [ecx + eax], edx
    app->getMemory<x86::reg32>(cpu.ecx + cpu.eax * 1) = cpu.edx;
    // 0046f8b9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f8ba  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f8bb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_46f8c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046f8c0  0500000a00             -add eax, 0xa0000
    (cpu.eax) += x86::reg32(x86::sreg32(655360 /*0xa0000*/));
    // 0046f8c5  c1f80f                 -sar eax, 0xf
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (15 /*0xf*/ % 32));
    // 0046f8c8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46f8d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046f8d0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046f8d1  ba60130000             -mov edx, 0x1360
    cpu.edx = 4960 /*0x1360*/;
    // 0046f8d6  a1ccec5300             -mov eax, dword ptr [0x53eccc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5500108) /* 0x53eccc */);
    // 0046f8db  e8ac8b0100             -call 0x48848c
    cpu.esp -= 4;
    sub_48848c(app, cpu);
    if (cpu.terminate) return;
    // 0046f8e0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f8e1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46f8f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046f8f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046f8f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046f8f2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046f8f3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046f8f4  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046f8f6  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0046f8f9  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046f8fb  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0046f8fd  7e13                   -jle 0x46f912
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046f912;
    }
    // 0046f8ff  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x0046f901:
    // 0046f901  837a0c00               +cmp dword ptr [edx + 0xc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046f905  7510                   -jne 0x46f917
    if (!cpu.flags.zf)
    {
        goto L_0x0046f917;
    }
    // 0046f907  41                     -inc ecx
    (cpu.ecx)++;
    // 0046f908  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0046f90b  83c210                 -add edx, 0x10
    (cpu.edx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0046f90e  39d9                   +cmp ecx, ebx
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
    // 0046f910  7cef                   -jl 0x46f901
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046f901;
    }
L_0x0046f912:
    // 0046f912  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f913  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f914  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f915  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f916  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046f917:
    // 0046f917  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0046f919  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0046f91c  ff530c                 -call dword ptr [ebx + 0xc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0046f91f  41                     -inc ecx
    (cpu.ecx)++;
    // 0046f920  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0046f923  83c210                 -add edx, 0x10
    (cpu.edx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0046f926  39d9                   +cmp ecx, ebx
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
    // 0046f928  7cd7                   -jl 0x46f901
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046f901;
    }
    // 0046f92a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f92b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f92c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f92d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f92e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_46f930(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046f930  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046f931  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046f932  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0046f935  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0046f938  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0046f93a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046f93c  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0046f93f  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0046f942  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0046f944  0f8481000000           -je 0x46f9cb
    if (cpu.flags.zf)
    {
        goto L_0x0046f9cb;
    }
    // 0046f94a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046f94b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046f94c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046f94e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0046f950  7e5d                   -jle 0x46f9af
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046f9af;
    }
L_0x0046f952:
    // 0046f952  3b420c                 +cmp eax, dword ptr [edx + 0xc]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046f955  7549                   -jne 0x46f9a0
    if (!cpu.flags.zf)
    {
        goto L_0x0046f9a0;
    }
    // 0046f957  3b6a10                 +cmp ebp, dword ptr [edx + 0x10]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046f95a  7544                   -jne 0x46f9a0
    if (!cpu.flags.zf)
    {
        goto L_0x0046f9a0;
    }
    // 0046f95c  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046f960  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0046f962  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046f965  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 0046f968  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0046f96a  8d1c02                 -lea ebx, [edx + eax]
    cpu.ebx = x86::reg32(cpu.edx + cpu.eax * 1);
    // 0046f96d  83c210                 -add edx, 0x10
    (cpu.edx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0046f970  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x0046f972:
    // 0046f972  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046f976  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0046f979  48                     -dec eax
    (cpu.eax)--;
    // 0046f97a  39c5                   +cmp ebp, eax
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046f97c  7d31                   -jge 0x46f9af
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0046f9af;
    }
    // 0046f97e  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 0046f983  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0046f985  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0046f987  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046f988  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046f98a  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0046f98d  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046f98f  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0046f991  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0046f994  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0046f996  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f997  45                     -inc ebp
    (cpu.ebp)++;
    // 0046f998  83c310                 -add ebx, 0x10
    (cpu.ebx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0046f99b  83c210                 +add edx, 0x10
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0046f99e  ebd2                   -jmp 0x46f972
    goto L_0x0046f972;
L_0x0046f9a0:
    // 0046f9a0  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046f9a4  43                     -inc ebx
    (cpu.ebx)++;
    // 0046f9a5  8b7904                 -mov edi, dword ptr [ecx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0046f9a8  83c210                 -add edx, 0x10
    (cpu.edx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0046f9ab  39fb                   +cmp ebx, edi
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046f9ad  7ca3                   -jl 0x46f952
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046f952;
    }
L_0x0046f9af:
    // 0046f9af  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046f9b3  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0046f9b6  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046f9ba  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0046f9bd  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 0046f9bf  c74008fe7f0000         -mov dword ptr [eax + 8], 0x7ffe
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 32766 /*0x7ffe*/;
    // 0046f9c6  ff4f04                 -dec dword ptr [edi + 4]
    (app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */))--;
    // 0046f9c9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f9ca  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0046f9cb:
    // 0046f9cb  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0046f9ce  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f9cf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046f9d0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46f9e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046f9e0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046f9e1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046f9e2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046f9e3  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0046f9e6  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0046f9ea  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0046f9ee  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0046f9f1  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0046f9f5  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0046f9f8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046f9fa  41                     -inc ecx
    (cpu.ecx)++;
    // 0046f9fb  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0046f9ff  894804                 -mov dword ptr [eax + 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0046fa02  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0046fa04  7e22                   -jle 0x46fa28
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046fa28;
    }
    // 0046fa06  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x0046fa08:
    // 0046fa08  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046fa0c  8b7b08                 -mov edi, dword ptr [ebx + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 0046fa0f  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0046fa13  39f8                   +cmp eax, edi
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
    // 0046fa15  7c39                   -jl 0x46fa50
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046fa50;
    }
    // 0046fa17  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046fa1b  42                     -inc edx
    (cpu.edx)++;
    // 0046fa1c  8b7004                 -mov esi, dword ptr [eax + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0046fa1f  83c310                 -add ebx, 0x10
    (cpu.ebx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0046fa22  39f2                   +cmp edx, esi
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
    // 0046fa24  7ce2                   -jl 0x46fa08
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046fa08;
    }
    // 0046fa26  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x0046fa28:
    // 0046fa28  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046fa2c  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046fa30  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 0046fa33  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0046fa35  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046fa39  894208                 -mov dword ptr [edx + 8], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0046fa3c  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046fa40  89420c                 -mov dword ptr [edx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0046fa43  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0046fa46  894210                 -mov dword ptr [edx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0046fa49  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0046fa4c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fa4d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fa4e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fa4f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046fa50:
    // 0046fa50  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046fa54  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0046fa57  48                     -dec eax
    (cpu.eax)--;
    // 0046fa58  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0046fa5c  39c2                   +cmp edx, eax
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
    // 0046fa5e  7dc8                   -jge 0x46fa28
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0046fa28;
    }
    // 0046fa60  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046fa64  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046fa68  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 0046fa6b  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046fa6e  8d2c03                 -lea ebp, [ebx + eax]
    cpu.ebp = x86::reg32(cpu.ebx + cpu.eax * 1);
    // 0046fa71  83eb10                 -sub ebx, 0x10
    (cpu.ebx) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0046fa74  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x0046fa76:
    // 0046fa76  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 0046fa7b  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0046fa7d  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 0046fa7f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046fa80  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046fa82  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0046fa85  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046fa87  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0046fa89  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0046fa8c  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0046fa8e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fa8f  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046fa93  83ed10                 -sub ebp, 0x10
    (cpu.ebp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0046fa96  48                     -dec eax
    (cpu.eax)--;
    // 0046fa97  83eb10                 -sub ebx, 0x10
    (cpu.ebx) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0046fa9a  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0046fa9e  39c2                   +cmp edx, eax
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
    // 0046faa0  7cd4                   -jl 0x46fa76
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046fa76;
    }
    // 0046faa2  eb84                   -jmp 0x46fa28
    goto L_0x0046fa28;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46fab0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046fab0  e9b7320100             -jmp 0x482d6c
    return sub_482d6c(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46fac0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046fac0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046fac1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046fac2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046fac3  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0046fac5  c705f48f4d00b4bd4c00   -mov dword ptr [0x4d8ff4], 0x4cbdb4
    app->getMemory<x86::reg32>(x86::reg32(5083124) /* 0x4d8ff4 */) = 5029300 /*0x4cbdb4*/;
    // 0046facf  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0046fad1  b956000000             -mov ecx, 0x56
    cpu.ecx = 86 /*0x56*/;
    // 0046fad6  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 0046fad9  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046fadb  83c218                 -add edx, 0x18
    (cpu.edx) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0046fade  890df88f4d00           -mov dword ptr [0x4d8ff8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5083128) /* 0x4d8ff8 */) = cpu.ecx;
    // 0046fae4  e81f2e0100             -call 0x482908
    cpu.esp -= 4;
    sub_482908(app, cpu);
    if (cpu.terminate) return;
    // 0046fae9  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0046faf0  8930                   -mov dword ptr [eax], esi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
    // 0046faf2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046faf4  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 0046faf6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046faf8  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0046fafa  7e18                   -jle 0x46fb14
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046fb14;
    }
L_0x0046fafc:
    // 0046fafc  c74008fe7f0000         -mov dword ptr [eax + 8], 0x7ffe
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 32766 /*0x7ffe*/;
    // 0046fb03  c7400c00000000         -mov dword ptr [eax + 0xc], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 0046fb0a  42                     -inc edx
    (cpu.edx)++;
    // 0046fb0b  8b31                   -mov esi, dword ptr [ecx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx);
    // 0046fb0d  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0046fb10  39f2                   +cmp edx, esi
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
    // 0046fb12  7ce8                   -jl 0x46fafc
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046fafc;
    }
L_0x0046fb14:
    // 0046fb14  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046fb16  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fb17  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fb18  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fb19  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46fb20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046fb20  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046fb21  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046fb22  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0046fb24  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0046fb26  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0046fb28  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0046fb2a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046fb2c  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0046fb2f  c1e204                 +shl edx, 4
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
    // 0046fb32  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0046fb34  c1f804                 -sar eax, 4
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (4 /*0x4*/ % 32));
    // 0046fb37  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046fb39  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0046fb3c  c1e210                 +shl edx, 0x10
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
    // 0046fb3f  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0046fb41  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0046fb44  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046fb46  83f814                 +cmp eax, 0x14
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
    // 0046fb49  7c05                   -jl 0x46fb50
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046fb50;
    }
    // 0046fb4b  ba13000000             -mov edx, 0x13
    cpu.edx = 19 /*0x13*/;
L_0x0046fb50:
    // 0046fb50  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 0046fb57  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0046fb59  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046fb5c  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0046fb5e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046fb60  8a8228744d00           -mov al, byte ptr [edx + 0x4d7428]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5076008) /* 0x4d7428 */);
    // 0046fb66  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046fb69  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046fb6d  8b90b8734d00           -mov edx, dword ptr [eax + 0x4d73b8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5075896) /* 0x4d73b8 */);
    // 0046fb73  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 0046fb75  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046fb79  8b90f0734d00           -mov edx, dword ptr [eax + 0x4d73f0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5075952) /* 0x4d73f0 */);
    // 0046fb7f  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 0046fb81  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046fb85  8b90d4734d00           -mov edx, dword ptr [eax + 0x4d73d4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5075924) /* 0x4d73d4 */);
    // 0046fb8b  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 0046fb8d  833d18ed530000         +cmp dword ptr [0x53ed18], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5500184) /* 0x53ed18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046fb94  7525                   -jne 0x46fbbb
    if (!cpu.flags.zf)
    {
        goto L_0x0046fbbb;
    }
    // 0046fb96  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0046fb98:
    // 0046fb98  a118ed5300             -mov eax, dword ptr [0x53ed18]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5500184) /* 0x53ed18 */);
    // 0046fb9d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046fb9f  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0046fba2  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0046fba4  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0046fba6  0fafdf                 -imul ebx, edi
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 0046fba9  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0046fbab  21c8                   -and eax, ecx
    cpu.eax &= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046fbad  39c8                   +cmp eax, ecx
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
    // 0046fbaf  7512                   -jne 0x46fbc3
    if (!cpu.flags.zf)
    {
        goto L_0x0046fbc3;
    }
    // 0046fbb1  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0046fbb6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fbb7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fbb8  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x0046fbbb:
    // 0046fbbb  8b880c744d00           -mov ecx, dword ptr [eax + 0x4d740c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5075980) /* 0x4d740c */);
    // 0046fbc1  ebd5                   -jmp 0x46fb98
    goto L_0x0046fb98;
L_0x0046fbc3:
    // 0046fbc3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046fbc5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fbc6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fbc7  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46fbd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046fbd0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046fbd1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046fbd2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046fbd3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046fbd4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046fbd5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046fbd6  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0046fbd9  b406                   -mov ah, 6
    cpu.ah = 6 /*0x6*/;
    // 0046fbdb  be1c0d5100             -mov esi, 0x510d1c
    cpu.esi = 5311772 /*0x510d1c*/;
    // 0046fbe0  8d7c2408               -lea edi, [esp + 8]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046fbe4  bb14000000             -mov ebx, 0x14
    cpu.ebx = 20 /*0x14*/;
    // 0046fbe9  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0046fbeb  882424                 -mov byte ptr [esp], ah
    app->getMemory<x86::reg8>(cpu.esp) = cpu.ah;
    // 0046fbee  a1c4155600             -mov eax, dword ptr [0x5615c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5641668) /* 0x5615c4 */);
    // 0046fbf3  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0046fbf7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0046fbf8:
    // 0046fbf8  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0046fbfa  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0046fbfc  3c00                   +cmp al, 0
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
    // 0046fbfe  7410                   -je 0x46fc10
    if (cpu.flags.zf)
    {
        goto L_0x0046fc10;
    }
    // 0046fc00  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0046fc03  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0046fc06  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0046fc09  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0046fc0c  3c00                   +cmp al, 0
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
    // 0046fc0e  75e8                   -jne 0x46fbf8
    if (!cpu.flags.zf)
    {
        goto L_0x0046fbf8;
    }
L_0x0046fc10:
    // 0046fc10  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fc11  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046fc13  e85829ffff             -call 0x462570
    cpu.esp -= 4;
    sub_462570(app, cpu);
    if (cpu.terminate) return;
    // 0046fc18  66833da011510000       +cmp word ptr [0x5111a0], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5312928) /* 0x5111a0 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0046fc20  7517                   -jne 0x46fc39
    if (!cpu.flags.zf)
    {
        goto L_0x0046fc39;
    }
L_0x0046fc22:
    // 0046fc22  e84927ffff             -call 0x462370
    cpu.esp -= 4;
    sub_462370(app, cpu);
    if (cpu.terminate) return;
    // 0046fc27  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046fc29  0f85a3000000           -jne 0x46fcd2
    if (!cpu.flags.zf)
    {
        goto L_0x0046fcd2;
    }
    // 0046fc2f  66833da011510000       +cmp word ptr [0x5111a0], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5312928) /* 0x5111a0 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0046fc37  74e9                   -je 0x46fc22
    if (cpu.flags.zf)
    {
        goto L_0x0046fc22;
    }
L_0x0046fc39:
    // 0046fc39  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046fc3b  8a15ce115100           -mov dl, byte ptr [0x5111ce]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5312974) /* 0x5111ce */);
    // 0046fc41  66890da0115100         -mov word ptr [0x5111a0], cx
    app->getMemory<x86::reg16>(x86::reg32(5312928) /* 0x5111a0 */) = cpu.cx;
    // 0046fc48  80fa02                 +cmp dl, 2
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
    // 0046fc4b  0f8509010000           -jne 0x46fd5a
    if (!cpu.flags.zf)
    {
        goto L_0x0046fd5a;
    }
    // 0046fc51  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046fc55  8b15d8ec5300           -mov edx, dword ptr [0x53ecd8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5500120) /* 0x53ecd8 */);
    // 0046fc5b  39d0                   +cmp eax, edx
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
    // 0046fc5d  7e77                   -jle 0x46fcd6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046fcd6;
    }
    // 0046fc5f  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 0046fc64  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0046fc66  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046fc68  892ddcff5000           -mov dword ptr [0x50ffdc], ebp
    app->getMemory<x86::reg32>(x86::reg32(5308380) /* 0x50ffdc */) = cpu.ebp;
L_0x0046fc6e:
    // 0046fc6e  66a320125100           -mov word ptr [0x511220], ax
    app->getMemory<x86::reg16>(x86::reg32(5313056) /* 0x511220 */) = cpu.ax;
    // 0046fc74  66893dc8115100         -mov word ptr [0x5111c8], di
    app->getMemory<x86::reg16>(x86::reg32(5312968) /* 0x5111c8 */) = cpu.di;
L_0x0046fc7b:
    // 0046fc7b  bedcec5300             -mov esi, 0x53ecdc
    cpu.esi = 5500124 /*0x53ecdc*/;
    // 0046fc80  bf48115100             -mov edi, 0x511148
    cpu.edi = 5312840 /*0x511148*/;
    // 0046fc85  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0046fc86:
    // 0046fc86  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0046fc88  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0046fc8a  3c00                   +cmp al, 0
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
    // 0046fc8c  7410                   -je 0x46fc9e
    if (cpu.flags.zf)
    {
        goto L_0x0046fc9e;
    }
    // 0046fc8e  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0046fc91  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0046fc94  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0046fc97  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0046fc9a  3c00                   +cmp al, 0
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
    // 0046fc9c  75e8                   -jne 0x46fc86
    if (!cpu.flags.zf)
    {
        goto L_0x0046fc86;
    }
L_0x0046fc9e:
    // 0046fc9e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fc9f  be1c0d5100             -mov esi, 0x510d1c
    cpu.esi = 5311772 /*0x510d1c*/;
    // 0046fca4  bfd5115100             -mov edi, 0x5111d5
    cpu.edi = 5312981 /*0x5111d5*/;
    // 0046fca9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x0046fcaa:
    // 0046fcaa  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 0046fcac  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 0046fcae  3c00                   +cmp al, 0
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
    // 0046fcb0  7410                   -je 0x46fcc2
    if (cpu.flags.zf)
    {
        goto L_0x0046fcc2;
    }
    // 0046fcb2  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0046fcb5  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0046fcb8  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0046fcbb  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0046fcbe  3c00                   +cmp al, 0
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
    // 0046fcc0  75e8                   -jne 0x46fcaa
    if (!cpu.flags.zf)
    {
        goto L_0x0046fcaa;
    }
L_0x0046fcc2:
    // 0046fcc2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fcc3  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0046fcc8:
    // 0046fcc8  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0046fccb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fccc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fccd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fcce  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fccf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fcd0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fcd1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046fcd2:
    // 0046fcd2  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0046fcd4  ebf2                   -jmp 0x46fcc8
    goto L_0x0046fcc8;
L_0x0046fcd6:
    // 0046fcd6  7d2d                   -jge 0x46fd05
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0046fd05;
    }
    // 0046fcd8  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 0046fcdd  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0046fce2  66890dc8115100         -mov word ptr [0x5111c8], cx
    app->getMemory<x86::reg16>(x86::reg32(5312968) /* 0x5111c8 */) = cpu.cx;
    // 0046fce9  893ddcff5000           -mov dword ptr [0x50ffdc], edi
    app->getMemory<x86::reg32>(x86::reg32(5308380) /* 0x50ffdc */) = cpu.edi;
    // 0046fcef  66893520125100         -mov word ptr [0x511220], si
    app->getMemory<x86::reg16>(x86::reg32(5313056) /* 0x511220 */) = cpu.si;
    // 0046fcf6  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0046fcfb  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0046fcfe  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fcff  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fd00  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fd01  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fd02  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fd03  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fd04  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046fd05:
    // 0046fd05  badcec5300             -mov edx, 0x53ecdc
    cpu.edx = 5500124 /*0x53ecdc*/;
    // 0046fd0a  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046fd0e  e87d1e0100             -call 0x481b90
    cpu.esp -= 4;
    sub_481b90(app, cpu);
    if (cpu.terminate) return;
    // 0046fd13  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046fd15  7c16                   -jl 0x46fd2d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046fd2d;
    }
    // 0046fd17  7eb9                   -jle 0x46fcd2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046fcd2;
    }
    // 0046fd19  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 0046fd1e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046fd20  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0046fd22  891ddcff5000           -mov dword ptr [0x50ffdc], ebx
    app->getMemory<x86::reg32>(x86::reg32(5308380) /* 0x50ffdc */) = cpu.ebx;
    // 0046fd28  e941ffffff             -jmp 0x46fc6e
    goto L_0x0046fc6e;
L_0x0046fd2d:
    // 0046fd2d  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0046fd32  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0046fd37  66890dc8115100         -mov word ptr [0x5111c8], cx
    app->getMemory<x86::reg16>(x86::reg32(5312968) /* 0x5111c8 */) = cpu.cx;
    // 0046fd3e  8935dcff5000           -mov dword ptr [0x50ffdc], esi
    app->getMemory<x86::reg32>(x86::reg32(5308380) /* 0x50ffdc */) = cpu.esi;
    // 0046fd44  66891d20125100         -mov word ptr [0x511220], bx
    app->getMemory<x86::reg16>(x86::reg32(5313056) /* 0x511220 */) = cpu.bx;
    // 0046fd4b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0046fd50  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0046fd53  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fd54  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fd55  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fd56  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fd57  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fd58  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fd59  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046fd5a:
    // 0046fd5a  66833dc811510000       +cmp word ptr [0x5111c8], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5312968) /* 0x5111c8 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0046fd62  0f8513ffffff           -jne 0x46fc7b
    if (!cpu.flags.zf)
    {
        goto L_0x0046fc7b;
    }
    // 0046fd68  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0046fd6d  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0046fd70  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fd71  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fd72  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fd73  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fd74  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fd75  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fd76  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46fd80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046fd80  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046fd81  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046fd82  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046fd83  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046fd84  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046fd85  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046fd87  e81426ffff             -call 0x4623a0
    cpu.esp -= 4;
    sub_4623a0(app, cpu);
    if (cpu.terminate) return;
    // 0046fd8c  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0046fd91  8a25ce115100           -mov ah, byte ptr [0x5111ce]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5312974) /* 0x5111ce */);
    // 0046fd97  66891d1e125100         -mov word ptr [0x51121e], bx
    app->getMemory<x86::reg16>(x86::reg32(5313054) /* 0x51121e */) = cpu.bx;
    // 0046fd9e  80fc01                 +cmp ah, 1
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
    // 0046fda1  0f847e000000           -je 0x46fe25
    if (cpu.flags.zf)
    {
        goto L_0x0046fe25;
    }
    // 0046fda7  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0046fda9  a3a40e5100             -mov dword ptr [0x510ea4], eax
    app->getMemory<x86::reg32>(x86::reg32(5312164) /* 0x510ea4 */) = cpu.eax;
L_0x0046fdae:
    // 0046fdae  8b15e8894d00           -mov edx, dword ptr [0x4d89e8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5081576) /* 0x4d89e8 */);
    // 0046fdb4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046fdb6  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0046fdb9  c1e204                 +shl edx, 4
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
    // 0046fdbc  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0046fdbe  c1f804                 -sar eax, 4
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (4 /*0x4*/ % 32));
    // 0046fdc1  8a15ce115100           -mov dl, byte ptr [0x5111ce]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5312974) /* 0x5111ce */);
    // 0046fdc7  a3940e5100             -mov dword ptr [0x510e94], eax
    app->getMemory<x86::reg32>(x86::reg32(5312148) /* 0x510e94 */) = cpu.eax;
    // 0046fdcc  80fa01                 +cmp dl, 1
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
    // 0046fdcf  0f8595000000           -jne 0x46fe6a
    if (!cpu.flags.zf)
    {
        goto L_0x0046fe6a;
    }
    // 0046fdd5  8b15e8894d00           -mov edx, dword ptr [0x4d89e8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5081576) /* 0x4d89e8 */);
    // 0046fddb  b905000000             -mov ecx, 5
    cpu.ecx = 5 /*0x5*/;
L_0x0046fde0:
    // 0046fde0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046fde2  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0046fde5  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0046fde7  a3980e5100             -mov dword ptr [0x510e98], eax
    app->getMemory<x86::reg32>(x86::reg32(5312152) /* 0x510e98 */) = cpu.eax;
    // 0046fdec  a39c0e5100             -mov dword ptr [0x510e9c], eax
    app->getMemory<x86::reg32>(x86::reg32(5312156) /* 0x510e9c */) = cpu.eax;
    // 0046fdf1  bb09000000             -mov ebx, 9
    cpu.ebx = 9 /*0x9*/;
    // 0046fdf6  bd03000000             -mov ebp, 3
    cpu.ebp = 3 /*0x3*/;
    // 0046fdfb  b8700e5100             -mov eax, 0x510e70
    cpu.eax = 5312112 /*0x510e70*/;
    // 0046fe00  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0046fe02  891dac0e5100           -mov dword ptr [0x510eac], ebx
    app->getMemory<x86::reg32>(x86::reg32(5312172) /* 0x510eac */) = cpu.ebx;
    // 0046fe08  8935b00e5100           -mov dword ptr [0x510eb0], esi
    app->getMemory<x86::reg32>(x86::reg32(5312176) /* 0x510eb0 */) = cpu.esi;
    // 0046fe0e  8935b40e5100           -mov dword ptr [0x510eb4], esi
    app->getMemory<x86::reg32>(x86::reg32(5312180) /* 0x510eb4 */) = cpu.esi;
    // 0046fe14  892db80e5100           -mov dword ptr [0x510eb8], ebp
    app->getMemory<x86::reg32>(x86::reg32(5312184) /* 0x510eb8 */) = cpu.ebp;
    // 0046fe1a  e8f126ffff             -call 0x462510
    cpu.esp -= 4;
    sub_462510(app, cpu);
    if (cpu.terminate) return;
    // 0046fe1f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fe20  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fe21  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fe22  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fe23  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fe24  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046fe25:
    // 0046fe25  e88622fbff             -call 0x4220b0
    cpu.esp -= 4;
    sub_4220b0(app, cpu);
    if (cpu.terminate) return;
    // 0046fe2a  668b0dc8115100         -mov cx, word ptr [0x5111c8]
    cpu.cx = app->getMemory<x86::reg16>(x86::reg32(5312968) /* 0x5111c8 */);
    // 0046fe31  a3a80e5100             -mov dword ptr [0x510ea8], eax
    app->getMemory<x86::reg32>(x86::reg32(5312168) /* 0x510ea8 */) = cpu.eax;
    // 0046fe36  6685c9                 +test cx, cx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.cx & cpu.cx));
    // 0046fe39  7413                   -je 0x46fe4e
    if (cpu.flags.zf)
    {
        goto L_0x0046fe4e;
    }
    // 0046fe3b  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0046fe3d  8915d00e5100           -mov dword ptr [0x510ed0], edx
    app->getMemory<x86::reg32>(x86::reg32(5312208) /* 0x510ed0 */) = cpu.edx;
    // 0046fe43  8915d40e5100           -mov dword ptr [0x510ed4], edx
    app->getMemory<x86::reg32>(x86::reg32(5312212) /* 0x510ed4 */) = cpu.edx;
    // 0046fe49  e960ffffff             -jmp 0x46fdae
    goto L_0x0046fdae;
L_0x0046fe4e:
    // 0046fe4e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046fe50  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0046fe53  a3d40e5100             -mov dword ptr [0x510ed4], eax
    app->getMemory<x86::reg32>(x86::reg32(5312212) /* 0x510ed4 */) = cpu.eax;
    // 0046fe58  8b422c                 -mov eax, dword ptr [edx + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(44) /* 0x2c */);
    // 0046fe5b  05a0000000             +add eax, 0xa0
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(160 /*0xa0*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0046fe60  a3d00e5100             -mov dword ptr [0x510ed0], eax
    app->getMemory<x86::reg32>(x86::reg32(5312208) /* 0x510ed0 */) = cpu.eax;
    // 0046fe65  e944ffffff             -jmp 0x46fdae
    goto L_0x0046fdae;
L_0x0046fe6a:
    // 0046fe6a  8b15e8894d00           -mov edx, dword ptr [0x4d89e8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5081576) /* 0x4d89e8 */);
    // 0046fe70  b90a000000             -mov ecx, 0xa
    cpu.ecx = 10 /*0xa*/;
    // 0046fe75  e966ffffff             -jmp 0x46fde0
    goto L_0x0046fde0;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_46fe80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046fe80  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046fe81  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046fe82  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046fe83  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 0046fe88  bfd4ec5300             -mov edi, 0x53ecd4
    cpu.edi = 5500116 /*0x53ecd4*/;
    // 0046fe8d  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0046fe8f  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0046fe94  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046fe95  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046fe97  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0046fe9a  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046fe9c  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0046fe9e  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0046fea1  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0046fea3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fea4  668915a0115100         -mov word ptr [0x5111a0], dx
    app->getMemory<x86::reg16>(x86::reg32(5312928) /* 0x5111a0 */) = cpu.dx;
    // 0046feab  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046feac  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046fead  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046feae  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_46feb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0046feb0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046feb1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046feb2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046feb3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046feb4  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0046feb6  a0790b5100             -mov al, byte ptr [0x510b79]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5311353) /* 0x510b79 */);
    // 0046febb  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046febd  3c02                   +cmp al, 2
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
    // 0046febf  726c                   -jb 0x46ff2d
    if (cpu.flags.cf)
    {
        goto L_0x0046ff2d;
    }
    // 0046fec1  775d                   -ja 0x46ff20
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0046ff20;
    }
    // 0046fec3  c605ce11510001         -mov byte ptr [0x5111ce], 1
    app->getMemory<x86::reg8>(x86::reg32(5312974) /* 0x5111ce */) = 1 /*0x1*/;
L_0x0046feca:
    // 0046feca  ba03030000             -mov edx, 0x303
    cpu.edx = 771 /*0x303*/;
    // 0046fecf  b800030000             -mov eax, 0x300
    cpu.eax = 768 /*0x300*/;
    // 0046fed4  e8f724f9ff             -call 0x4023d0
    cpu.esp -= 4;
    sub_4023d0(app, cpu);
    if (cpu.terminate) return;
    // 0046fed9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046fedb  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0046fedd  e89efeffff             -call 0x46fd80
    cpu.esp -= 4;
    sub_46fd80(app, cpu);
    if (cpu.terminate) return;
    // 0046fee2  a0ce115100             -mov al, byte ptr [0x5111ce]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5312974) /* 0x5111ce */);
    // 0046fee7  3c01                   +cmp al, 1
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
    // 0046fee9  736a                   -jae 0x46ff55
    if (!cpu.flags.cf)
    {
        goto L_0x0046ff55;
    }
L_0x0046feeb:
    // 0046feeb  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0046feed  0f859e000000           -jne 0x46ff91
    if (!cpu.flags.zf)
    {
        goto L_0x0046ff91;
    }
L_0x0046fef3:
    // 0046fef3  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0046fef5  0f8560010000           -jne 0x47005b
    if (!cpu.flags.zf)
    {
        goto L_0x0047005b;
    }
L_0x0046fefb:
    // 0046fefb  baff020000             -mov edx, 0x2ff
    cpu.edx = 767 /*0x2ff*/;
    // 0046ff00  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046ff02  e83924f9ff             -call 0x402340
    cpu.esp -= 4;
    sub_402340(app, cpu);
    if (cpu.terminate) return;
    // 0046ff07  e83424ffff             -call 0x462340
    cpu.esp -= 4;
    sub_462340(app, cpu);
    if (cpu.terminate) return;
    // 0046ff0c  e860190100             -call 0x481871
    cpu.esp -= 4;
    sub_481871(app, cpu);
    if (cpu.terminate) return;
    // 0046ff11  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046ff13  0f8425010000           -je 0x47003e
    if (cpu.flags.zf)
    {
        goto L_0x0047003e;
    }
L_0x0046ff19:
    // 0046ff19  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0046ff1b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ff1c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ff1d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ff1e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ff1f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046ff20:
    // 0046ff20  3c03                   +cmp al, 3
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
    // 0046ff22  7509                   -jne 0x46ff2d
    if (!cpu.flags.zf)
    {
        goto L_0x0046ff2d;
    }
    // 0046ff24  c605ce11510002         -mov byte ptr [0x5111ce], 2
    app->getMemory<x86::reg8>(x86::reg32(5312974) /* 0x5111ce */) = 2 /*0x2*/;
    // 0046ff2b  eb9d                   -jmp 0x46feca
    goto L_0x0046feca;
L_0x0046ff2d:
    // 0046ff2d  baecbd4c00             -mov edx, 0x4cbdec
    cpu.edx = 5029356 /*0x4cbdec*/;
    // 0046ff32  b97b000000             -mov ecx, 0x7b
    cpu.ecx = 123 /*0x7b*/;
    // 0046ff37  680cbe4c00             -push 0x4cbe0c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5029388 /*0x4cbe0c*/;
    cpu.esp -= 4;
    // 0046ff3c  8915f48f4d00           -mov dword ptr [0x4d8ff4], edx
    app->getMemory<x86::reg32>(x86::reg32(5083124) /* 0x4d8ff4 */) = cpu.edx;
    // 0046ff42  890df88f4d00           -mov dword ptr [0x4d8ff8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5083128) /* 0x4d8ff8 */) = cpu.ecx;
    // 0046ff48  e813260100             -call 0x482560
    cpu.esp -= 4;
    sub_482560(app, cpu);
    if (cpu.terminate) return;
    // 0046ff4d  83c404                 +add esp, 4
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
    // 0046ff50  e975ffffff             -jmp 0x46feca
    goto L_0x0046feca;
L_0x0046ff55:
    // 0046ff55  761f                   -jbe 0x46ff76
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0046ff76;
    }
    // 0046ff57  3c02                   +cmp al, 2
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
    // 0046ff59  7590                   -jne 0x46feeb
    if (!cpu.flags.zf)
    {
        goto L_0x0046feeb;
    }
    // 0046ff5b  bb07000000             -mov ebx, 7
    cpu.ebx = 7 /*0x7*/;
    // 0046ff60  ba64000000             -mov edx, 0x64
    cpu.edx = 100 /*0x64*/;
    // 0046ff65  b8700e5100             -mov eax, 0x510e70
    cpu.eax = 5312112 /*0x510e70*/;
    // 0046ff6a  e881ac0200             -call 0x49abf0
    cpu.esp -= 4;
    sub_49abf0(app, cpu);
    if (cpu.terminate) return;
    // 0046ff6f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0046ff71  e975ffffff             -jmp 0x46feeb
    goto L_0x0046feeb;
L_0x0046ff76:
    // 0046ff76  bb07000000             -mov ebx, 7
    cpu.ebx = 7 /*0x7*/;
    // 0046ff7b  ba64000000             -mov edx, 0x64
    cpu.edx = 100 /*0x64*/;
    // 0046ff80  b8700e5100             -mov eax, 0x510e70
    cpu.eax = 5312112 /*0x510e70*/;
    // 0046ff85  e816e6faff             -call 0x41e5a0
    cpu.esp -= 4;
    sub_41e5a0(app, cpu);
    if (cpu.terminate) return;
    // 0046ff8a  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0046ff8c  e95affffff             -jmp 0x46feeb
    goto L_0x0046feeb;
L_0x0046ff91:
    // 0046ff91  a124554d00             -mov eax, dword ptr [0x4d5524]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5068068) /* 0x4d5524 */);
    // 0046ff96  e81d840100             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 0046ff9b  e830fcffff             -call 0x46fbd0
    cpu.esp -= 4;
    sub_46fbd0(app, cpu);
    if (cpu.terminate) return;
    // 0046ffa0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046ffa2  0f8480000000           -je 0x470028
    if (cpu.flags.zf)
    {
        goto L_0x00470028;
    }
    // 0046ffa8  66833dc811510000       +cmp word ptr [0x5111c8], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5312968) /* 0x5111c8 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0046ffb0  7542                   -jne 0x46fff4
    if (!cpu.flags.zf)
    {
        goto L_0x0046fff4;
    }
    // 0046ffb2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046ffb3  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x0046ffb5:
    // 0046ffb5  668b3d94115100         -mov di, word ptr [0x511194]
    cpu.di = app->getMemory<x86::reg16>(x86::reg32(5312916) /* 0x511194 */);
    // 0046ffbc  6639fe                 +cmp si, di
    {
        x86::reg16 tmp1 = cpu.si;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(cpu.di));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0046ffbf  7523                   -jne 0x46ffe4
    if (!cpu.flags.zf)
    {
        goto L_0x0046ffe4;
    }
    // 0046ffc1  e8aa23ffff             -call 0x462370
    cpu.esp -= 4;
    sub_462370(app, cpu);
    if (cpu.terminate) return;
    // 0046ffc6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046ffc8  743e                   -je 0x470008
    if (cpu.flags.zf)
    {
        goto L_0x00470008;
    }
    // 0046ffca  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0046ffcf  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0046ffd1  668915ca115100         -mov word ptr [0x5111ca], dx
    app->getMemory<x86::reg16>(x86::reg32(5312970) /* 0x5111ca */) = cpu.dx;
    // 0046ffd8  668915cc115100         -mov word ptr [0x5111cc], dx
    app->getMemory<x86::reg16>(x86::reg32(5312972) /* 0x5111cc */) = cpu.dx;
    // 0046ffdf  e840870100             -call 0x488724
    cpu.esp -= 4;
    sub_488724(app, cpu);
    if (cpu.terminate) return;
L_0x0046ffe4:
    // 0046ffe4  a124554d00             -mov eax, dword ptr [0x4d5524]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5068068) /* 0x4d5524 */);
    // 0046ffe9  e8e2830100             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0046ffee  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046ffef  e9fffeffff             -jmp 0x46fef3
    goto L_0x0046fef3;
L_0x0046fff4:
    // 0046fff4  a124554d00             -mov eax, dword ptr [0x4d5524]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5068068) /* 0x4d5524 */);
    // 0046fff9  e8d2830100             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0046fffe  e85d21ffff             -call 0x462160
    cpu.esp -= 4;
    sub_462160(app, cpu);
    if (cpu.terminate) return;
    // 00470003  e9ebfeffff             -jmp 0x46fef3
    goto L_0x0046fef3;
L_0x00470008:
    // 00470008  663b3dca115100         +cmp di, word ptr [0x5111ca]
    {
        x86::reg16 tmp1 = cpu.di;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(app->getMemory<x86::reg16>(x86::reg32(5312970) /* 0x5111ca */)));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0047000f  74a4                   -je 0x46ffb5
    if (cpu.flags.zf)
    {
        goto L_0x0046ffb5;
    }
    // 00470011  e80e870100             -call 0x488724
    cpu.esp -= 4;
    sub_488724(app, cpu);
    if (cpu.terminate) return;
    // 00470016  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00470018  a124554d00             -mov eax, dword ptr [0x4d5524]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5068068) /* 0x4d5524 */);
    // 0047001d  e8ae830100             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 00470022  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470023  e9cbfeffff             -jmp 0x46fef3
    goto L_0x0046fef3;
L_0x00470028:
    // 00470028  e8f7860100             -call 0x488724
    cpu.esp -= 4;
    sub_488724(app, cpu);
    if (cpu.terminate) return;
    // 0047002d  a124554d00             -mov eax, dword ptr [0x4d5524]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5068068) /* 0x4d5524 */);
    // 00470032  e899830100             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 00470037  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00470039  e9bdfeffff             -jmp 0x46fefb
    goto L_0x0046fefb;
L_0x0047003e:
    // 0047003e  e8bd58f9ff             -call 0x405900
    cpu.esp -= 4;
    sub_405900(app, cpu);
    if (cpu.terminate) return;
    // 00470043  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00470045  0f85cefeffff           -jne 0x46ff19
    if (!cpu.flags.zf)
    {
        goto L_0x0046ff19;
    }
    // 0047004b  e821180100             -call 0x481871
    cpu.esp -= 4;
    sub_481871(app, cpu);
    if (cpu.terminate) return;
    // 00470050  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00470052  74ea                   -je 0x47003e
    if (cpu.flags.zf)
    {
        goto L_0x0047003e;
    }
    // 00470054  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00470056  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470057  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470058  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470059  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047005a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047005b:
    // 0047005b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047005d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047005f  e8dc22f9ff             -call 0x402340
    cpu.esp -= 4;
    sub_402340(app, cpu);
    if (cpu.terminate) return;
    // 00470064  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00470066  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470067  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470068  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470069  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047006a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_470070(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00470070  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00470071  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00470072  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00470073  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00470074  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00470075  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00470076  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00470079  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047007b  8b3528fc5000           -mov esi, dword ptr [0x50fc28]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5307432) /* 0x50fc28 */);
    // 00470081  e89a220100             -call 0x482320
    cpu.esp -= 4;
    sub_482320(app, cpu);
    if (cpu.terminate) return;
    // 00470086  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00470088  8b1528fc5000           -mov edx, dword ptr [0x50fc28]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5307432) /* 0x50fc28 */);
    // 0047008e  81c610270000           -add esi, 0x2710
    (cpu.esi) += x86::reg32(x86::sreg32(10000 /*0x2710*/));
    // 00470094  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00470096  0f8e94010000           -jle 0x470230
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00470230;
    }
L_0x0047009c:
    // 0047009c  a10c085100             -mov eax, dword ptr [0x51080c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5310476) /* 0x51080c */);
    // 004700a1  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004700a3  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004700a5  a31ced5300             -mov dword ptr [0x53ed1c], eax
    app->getMemory<x86::reg32>(x86::reg32(5500188) /* 0x53ed1c */) = cpu.eax;
    // 004700aa  e80149fdff             -call 0x4449b0
    cpu.esp -= 4;
    sub_4449b0(app, cpu);
    if (cpu.terminate) return;
    // 004700af  e80c49fdff             -call 0x4449c0
    cpu.esp -= 4;
    sub_4449c0(app, cpu);
    if (cpu.terminate) return;
    // 004700b4  e873080100             -call 0x48092c
    cpu.esp -= 4;
    sub_48092c(app, cpu);
    if (cpu.terminate) return;
    // 004700b9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004700bb  e86005fbff             -call 0x420620
    cpu.esp -= 4;
    sub_420620(app, cpu);
    if (cpu.terminate) return;
    // 004700c0  833df4ec530000         +cmp dword ptr [0x53ecf4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5500148) /* 0x53ecf4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004700c7  0f854c010000           -jne 0x470219
    if (!cpu.flags.zf)
    {
        goto L_0x00470219;
    }
L_0x004700cd:
    // 004700cd  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004700cf  e84c220100             -call 0x482320
    cpu.esp -= 4;
    sub_482320(app, cpu);
    if (cpu.terminate) return;
    // 004700d4  a194744d00             -mov eax, dword ptr [0x4d7494]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5076116) /* 0x4d7494 */);
    // 004700d9  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004700db  a300ed5300             -mov dword ptr [0x53ed00], eax
    app->getMemory<x86::reg32>(x86::reg32(5500160) /* 0x53ed00 */) = cpu.eax;
    // 004700e0  a128fc5000             -mov eax, dword ptr [0x50fc28]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5307432) /* 0x50fc28 */);
    // 004700e5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004700e7  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004700e9  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004700eb  8b1500ed5300           -mov edx, dword ptr [0x53ed00]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5500160) /* 0x53ed00 */);
    // 004700f1  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004700f3  39d6                   +cmp esi, edx
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
    // 004700f5  7e06                   -jle 0x4700fd
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004700fd;
    }
    // 004700f7  ff0500ed5300           -inc dword ptr [0x53ed00]
    (app->getMemory<x86::reg32>(x86::reg32(5500160) /* 0x53ed00 */))++;
L_0x004700fd:
    // 004700fd  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004700ff  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00470101  8b151ced5300           -mov edx, dword ptr [0x53ed1c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5500188) /* 0x53ed1c */);
    // 00470107  a30ced5300             -mov dword ptr [0x53ed0c], eax
    app->getMemory<x86::reg32>(x86::reg32(5500172) /* 0x53ed0c */) = cpu.eax;
    // 0047010c  a10c085100             -mov eax, dword ptr [0x51080c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5310476) /* 0x51080c */);
    // 00470111  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00470113  8b0d00ed5300           -mov ecx, dword ptr [0x53ed00]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5500160) /* 0x53ed00 */);
    // 00470119  83f810                 +cmp eax, 0x10
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
    // 0047011c  0f8f1d010000           -jg 0x47023f
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0047023f;
    }
L_0x00470122:
    // 00470122  bd02000000             -mov ebp, 2
    cpu.ebp = 2 /*0x2*/;
    // 00470127  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 0047012c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0047012e:
    // 0047012e  8b150c085100           -mov edx, dword ptr [0x51080c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5310476) /* 0x51080c */);
    // 00470134  3b151ced5300           +cmp edx, dword ptr [0x53ed1c]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5500188) /* 0x53ed1c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047013a  7c0c                   -jl 0x470148
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00470148;
    }
    // 0047013c  3b1df4ec5300           +cmp ebx, dword ptr [0x53ecf4]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5500148) /* 0x53ecf4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00470142  0f8406010000           -je 0x47024e
    if (cpu.flags.zf)
    {
        goto L_0x0047024e;
    }
L_0x00470148:
    // 00470148  833df8ec530000         +cmp dword ptr [0x53ecf8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5500152) /* 0x53ecf8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047014f  0f85a6040000           -jne 0x4705fb
    if (!cpu.flags.zf)
    {
        goto L_0x004705fb;
    }
    // 00470155  833dfcec530000         +cmp dword ptr [0x53ecfc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5500156) /* 0x53ecfc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047015c  0f8599040000           -jne 0x4705fb
    if (!cpu.flags.zf)
    {
        goto L_0x004705fb;
    }
    // 00470162  833df4ec530000         +cmp dword ptr [0x53ecf4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5500148) /* 0x53ecf4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00470169  0f858c040000           -jne 0x4705fb
    if (!cpu.flags.zf)
    {
        goto L_0x004705fb;
    }
    // 0047016f  8b1500ed5300           -mov edx, dword ptr [0x53ed00]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5500160) /* 0x53ed00 */);
    // 00470175  3b1504ed5300           +cmp edx, dword ptr [0x53ed04]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5500164) /* 0x53ed04 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047017b  0f8c98030000           -jl 0x470519
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00470519;
    }
L_0x00470181:
    // 00470181  bf02000000             -mov edi, 2
    cpu.edi = 2 /*0x2*/;
    // 00470186  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 0047018b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0047018d:
    // 0047018d  8b1500ed5300           -mov edx, dword ptr [0x53ed00]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5500160) /* 0x53ed00 */);
    // 00470193  3b1504ed5300           +cmp edx, dword ptr [0x53ed04]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5500164) /* 0x53ed04 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00470199  7c0f                   -jl 0x4701aa
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004701aa;
    }
    // 0047019b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047019d  e8be040000             -call 0x470660
    cpu.esp -= 4;
    sub_470660(app, cpu);
    if (cpu.terminate) return;
    // 004701a2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004701a4  0f847e030000           -je 0x470528
    if (cpu.flags.zf)
    {
        goto L_0x00470528;
    }
L_0x004701aa:
    // 004701aa  833d0ced530000         +cmp dword ptr [0x53ed0c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5500172) /* 0x53ed0c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004701b1  750a                   -jne 0x4701bd
    if (!cpu.flags.zf)
    {
        goto L_0x004701bd;
    }
    // 004701b3  a1f8ec5300             -mov eax, dword ptr [0x53ecf8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5500152) /* 0x53ecf8 */);
    // 004701b8  e8d3daffff             -call 0x46dc90
    cpu.esp -= 4;
    sub_46dc90(app, cpu);
    if (cpu.terminate) return;
L_0x004701bd:
    // 004701bd  833dd8ff500004         +cmp dword ptr [0x50ffd8], 4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5308376) /* 0x50ffd8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004701c4  7517                   -jne 0x4701dd
    if (!cpu.flags.zf)
    {
        goto L_0x004701dd;
    }
    // 004701c6  833de4ff500001         +cmp dword ptr [0x50ffe4], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5308388) /* 0x50ffe4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004701cd  7f0e                   -jg 0x4701dd
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004701dd;
    }
    // 004701cf  833ddcff500000         +cmp dword ptr [0x50ffdc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5308380) /* 0x50ffdc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004701d6  7505                   -jne 0x4701dd
    if (!cpu.flags.zf)
    {
        goto L_0x004701dd;
    }
    // 004701d8  e833c80000             -call 0x47ca10
    cpu.esp -= 4;
    sub_47ca10(app, cpu);
    if (cpu.terminate) return;
L_0x004701dd:
    // 004701dd  e81e9cfeff             -call 0x459e00
    cpu.esp -= 4;
    sub_459e00(app, cpu);
    if (cpu.terminate) return;
    // 004701e2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004701e4  0f841b040000           -je 0x470605
    if (cpu.flags.zf)
    {
        goto L_0x00470605;
    }
L_0x004701ea:
    // 004701ea  833de4ff500001         +cmp dword ptr [0x50ffe4], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5308388) /* 0x50ffe4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004701f1  7f11                   -jg 0x470204
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00470204;
    }
    // 004701f3  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004701f8  891d9c744d00           -mov dword ptr [0x4d749c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5076124) /* 0x4d749c */) = cpu.ebx;
    // 004701fe  891d98744d00           -mov dword ptr [0x4d7498], ebx
    app->getMemory<x86::reg32>(x86::reg32(5076120) /* 0x4d7498 */) = cpu.ebx;
L_0x00470204:
    // 00470204  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00470209  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 0047020e  e88d2b0000             -call 0x472da0
    cpu.esp -= 4;
    sub_472da0(app, cpu);
    if (cpu.terminate) return;
    // 00470213  893df4ec5300           -mov dword ptr [0x53ecf4], edi
    app->getMemory<x86::reg32>(x86::reg32(5500148) /* 0x53ecf4 */) = cpu.edi;
L_0x00470219:
    // 00470219  833de4ff500001         +cmp dword ptr [0x50ffe4], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5308388) /* 0x50ffe4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00470220  0f8e18040000           -jle 0x47063e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047063e;
    }
    // 00470226  83c404                 +add esp, 4
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
    // 00470229  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047022a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047022b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047022c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047022d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047022e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047022f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00470230:
    // 00470230  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00470235  e867750200             -call 0x4977a1
    cpu.esp -= 4;
    sub_4977a1(app, cpu);
    if (cpu.terminate) return;
    // 0047023a  e95dfeffff             -jmp 0x47009c
    goto L_0x0047009c;
L_0x0047023f:
    // 0047023f  a10c085100             -mov eax, dword ptr [0x51080c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5310476) /* 0x51080c */);
    // 00470244  a31ced5300             -mov dword ptr [0x53ed1c], eax
    app->getMemory<x86::reg32>(x86::reg32(5500188) /* 0x53ed1c */) = cpu.eax;
    // 00470249  e9d4feffff             -jmp 0x470122
    goto L_0x00470122;
L_0x0047024e:
    // 0047024e  3b2dd8ff5000           +cmp ebp, dword ptr [0x50ffd8]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5308376) /* 0x50ffd8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00470254  7e05                   -jle 0x47025b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047025b;
    }
    // 00470256  e8f5d9ffff             -call 0x46dc50
    cpu.esp -= 4;
    sub_46dc50(app, cpu);
    if (cpu.terminate) return;
L_0x0047025b:
    // 0047025b  3b2d64eb5300           +cmp ebp, dword ptr [0x53eb64]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5499748) /* 0x53eb64 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00470261  7547                   -jne 0x4702aa
    if (!cpu.flags.zf)
    {
        goto L_0x004702aa;
    }
    // 00470263  8b15f8ec5300           -mov edx, dword ptr [0x53ecf8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5500152) /* 0x53ecf8 */);
    // 00470269  39d3                   +cmp ebx, edx
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
    // 0047026b  753d                   -jne 0x4702aa
    if (!cpu.flags.zf)
    {
        goto L_0x004702aa;
    }
    // 0047026d  e89ee3ffff             -call 0x46e610
    cpu.esp -= 4;
    sub_46e610(app, cpu);
    if (cpu.terminate) return;
    // 00470272  833d7405520004         +cmp dword ptr [0x520574], 4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5375348) /* 0x520574 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00470279  752f                   -jne 0x4702aa
    if (!cpu.flags.zf)
    {
        goto L_0x004702aa;
    }
    // 0047027b  a168055200             -mov eax, dword ptr [0x520568]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5375336) /* 0x520568 */);
    // 00470280  891574055200           -mov dword ptr [0x520574], edx
    app->getMemory<x86::reg32>(x86::reg32(5375348) /* 0x520574 */) = cpu.edx;
    // 00470286  a3f4ec5300             -mov dword ptr [0x53ecf4], eax
    app->getMemory<x86::reg32>(x86::reg32(5500148) /* 0x53ecf4 */) = cpu.eax;
    // 0047028b  39c2                   +cmp edx, eax
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
    // 0047028d  0f84b8010000           -je 0x47044b
    if (cpu.flags.zf)
    {
        goto L_0x0047044b;
    }
    // 00470293  3b15fcec5300           +cmp edx, dword ptr [0x53ecfc]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5500156) /* 0x53ecfc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00470299  0f84ac010000           -je 0x47044b
    if (cpu.flags.zf)
    {
        goto L_0x0047044b;
    }
    // 0047029f  8915fcec5300           -mov dword ptr [0x53ecfc], edx
    app->getMemory<x86::reg32>(x86::reg32(5500156) /* 0x53ecfc */) = cpu.edx;
    // 004702a5  e81604fdff             -call 0x4406c0
    cpu.esp -= 4;
    sub_4406c0(app, cpu);
    if (cpu.terminate) return;
L_0x004702aa:
    // 004702aa  8b15f4ec5300           -mov edx, dword ptr [0x53ecf4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5500148) /* 0x53ecf4 */);
    // 004702b0  39d3                   +cmp ebx, edx
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
    // 004702b2  7511                   -jne 0x4702c5
    if (!cpu.flags.zf)
    {
        goto L_0x004702c5;
    }
    // 004702b4  3b15f8ec5300           +cmp edx, dword ptr [0x53ecf8]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5500152) /* 0x53ecf8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004702ba  0f84c0010000           -je 0x470480
    if (cpu.flags.zf)
    {
        goto L_0x00470480;
    }
    // 004702c0  e84b040000             -call 0x470710
    cpu.esp -= 4;
    sub_470710(app, cpu);
    if (cpu.terminate) return;
L_0x004702c5:
    // 004702c5  3b1df8ec5300           +cmp ebx, dword ptr [0x53ecf8]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5500152) /* 0x53ecf8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004702cb  0f85d4010000           -jne 0x4704a5
    if (!cpu.flags.zf)
    {
        goto L_0x004704a5;
    }
    // 004702d1  b80b000000             -mov eax, 0xb
    cpu.eax = 11 /*0xb*/;
    // 004702d6  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004702d8  e8b39bfeff             -call 0x459e90
    cpu.esp -= 4;
    sub_459e90(app, cpu);
    if (cpu.terminate) return;
    // 004702dd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004702df  7405                   -je 0x4702e6
    if (cpu.flags.zf)
    {
        goto L_0x004702e6;
    }
    // 004702e1  e8ba85fbff             -call 0x4288a0
    cpu.esp -= 4;
    sub_4288a0(app, cpu);
    if (cpu.terminate) return;
L_0x004702e6:
    // 004702e6  b80a000000             -mov eax, 0xa
    cpu.eax = 10 /*0xa*/;
    // 004702eb  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004702ed  e89e9bfeff             -call 0x459e90
    cpu.esp -= 4;
    sub_459e90(app, cpu);
    if (cpu.terminate) return;
    // 004702f2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004702f4  7405                   -je 0x4702fb
    if (cpu.flags.zf)
    {
        goto L_0x004702fb;
    }
    // 004702f6  e8c585fbff             -call 0x4288c0
    cpu.esp -= 4;
    sub_4288c0(app, cpu);
    if (cpu.terminate) return;
L_0x004702fb:
    // 004702fb  b80d000000             -mov eax, 0xd
    cpu.eax = 13 /*0xd*/;
    // 00470300  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00470302  e8899bfeff             -call 0x459e90
    cpu.esp -= 4;
    sub_459e90(app, cpu);
    if (cpu.terminate) return;
    // 00470307  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00470309  7405                   -je 0x470310
    if (cpu.flags.zf)
    {
        goto L_0x00470310;
    }
    // 0047030b  e89047fdff             -call 0x444aa0
    cpu.esp -= 4;
    sub_444aa0(app, cpu);
    if (cpu.terminate) return;
L_0x00470310:
    // 00470310  b80e000000             -mov eax, 0xe
    cpu.eax = 14 /*0xe*/;
    // 00470315  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00470317  e8749bfeff             -call 0x459e90
    cpu.esp -= 4;
    sub_459e90(app, cpu);
    if (cpu.terminate) return;
    // 0047031c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047031e  7405                   -je 0x470325
    if (cpu.flags.zf)
    {
        goto L_0x00470325;
    }
    // 00470320  e84bc8fbff             -call 0x42cb70
    cpu.esp -= 4;
    sub_42cb70(app, cpu);
    if (cpu.terminate) return;
L_0x00470325:
    // 00470325  b812000000             -mov eax, 0x12
    cpu.eax = 18 /*0x12*/;
    // 0047032a  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0047032c  e85f9bfeff             -call 0x459e90
    cpu.esp -= 4;
    sub_459e90(app, cpu);
    if (cpu.terminate) return;
    // 00470331  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00470333  7407                   -je 0x47033c
    if (cpu.flags.zf)
    {
        goto L_0x0047033c;
    }
    // 00470335  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00470337  e85476feff             -call 0x457990
    cpu.esp -= 4;
    sub_457990(app, cpu);
    if (cpu.terminate) return;
L_0x0047033c:
    // 0047033c  b813000000             -mov eax, 0x13
    cpu.eax = 19 /*0x13*/;
    // 00470341  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00470343  e8489bfeff             -call 0x459e90
    cpu.esp -= 4;
    sub_459e90(app, cpu);
    if (cpu.terminate) return;
    // 00470348  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047034a  7407                   -je 0x470353
    if (cpu.flags.zf)
    {
        goto L_0x00470353;
    }
    // 0047034c  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0047034e  e83d76feff             -call 0x457990
    cpu.esp -= 4;
    sub_457990(app, cpu);
    if (cpu.terminate) return;
L_0x00470353:
    // 00470353  b811000000             -mov eax, 0x11
    cpu.eax = 17 /*0x11*/;
    // 00470358  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0047035a  e8319bfeff             -call 0x459e90
    cpu.esp -= 4;
    sub_459e90(app, cpu);
    if (cpu.terminate) return;
    // 0047035f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00470361  7405                   -je 0x470368
    if (cpu.flags.zf)
    {
        goto L_0x00470368;
    }
    // 00470363  e8e875feff             -call 0x457950
    cpu.esp -= 4;
    sub_457950(app, cpu);
    if (cpu.terminate) return;
L_0x00470368:
    // 00470368  b816000000             -mov eax, 0x16
    cpu.eax = 22 /*0x16*/;
    // 0047036d  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0047036f  e81c9bfeff             -call 0x459e90
    cpu.esp -= 4;
    sub_459e90(app, cpu);
    if (cpu.terminate) return;
    // 00470374  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00470376  7405                   -je 0x47037d
    if (cpu.flags.zf)
    {
        goto L_0x0047037d;
    }
    // 00470378  e8e301fdff             -call 0x440560
    cpu.esp -= 4;
    sub_440560(app, cpu);
    if (cpu.terminate) return;
L_0x0047037d:
    // 0047037d  b815000000             -mov eax, 0x15
    cpu.eax = 21 /*0x15*/;
    // 00470382  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00470384  e8079bfeff             -call 0x459e90
    cpu.esp -= 4;
    sub_459e90(app, cpu);
    if (cpu.terminate) return;
    // 00470389  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047038b  7405                   -je 0x470392
    if (cpu.flags.zf)
    {
        goto L_0x00470392;
    }
    // 0047038d  e88e01fdff             -call 0x440520
    cpu.esp -= 4;
    sub_440520(app, cpu);
    if (cpu.terminate) return;
L_0x00470392:
    // 00470392  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 00470397  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00470399  e8f29afeff             -call 0x459e90
    cpu.esp -= 4;
    sub_459e90(app, cpu);
    if (cpu.terminate) return;
    // 0047039e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004703a0  7419                   -je 0x4703bb
    if (cpu.flags.zf)
    {
        goto L_0x004703bb;
    }
    // 004703a2  b836000000             -mov eax, 0x36
    cpu.eax = 54 /*0x36*/;
    // 004703a7  e814460100             -call 0x4849c0
    cpu.esp -= 4;
    sub_4849c0(app, cpu);
    if (cpu.terminate) return;
    // 004703ac  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004703ae  0f84d8000000           -je 0x47048c
    if (cpu.flags.zf)
    {
        goto L_0x0047048c;
    }
L_0x004703b4:
    // 004703b4  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x004703b6:
    // 004703b6  e8756afbff             -call 0x426e30
    cpu.esp -= 4;
    sub_426e30(app, cpu);
    if (cpu.terminate) return;
L_0x004703bb:
    // 004703bb  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004703bd  e82e5d0000             -call 0x4760f0
    cpu.esp -= 4;
    sub_4760f0(app, cpu);
    if (cpu.terminate) return;
    // 004703c2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004703c4  740f                   -je 0x4703d5
    if (cpu.flags.zf)
    {
        goto L_0x004703d5;
    }
    // 004703c6  3b2d64eb5300           +cmp ebp, dword ptr [0x53eb64]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5499748) /* 0x53eb64 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004703cc  7e07                   -jle 0x4703d5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004703d5;
    }
    // 004703ce  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004703d0  e81b94fdff             -call 0x4497f0
    cpu.esp -= 4;
    sub_4497f0(app, cpu);
    if (cpu.terminate) return;
L_0x004703d5:
    // 004703d5  a1d8ff5000             -mov eax, dword ptr [0x50ffd8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5308376) /* 0x50ffd8 */);
    // 004703da  39c7                   +cmp edi, eax
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
    // 004703dc  7518                   -jne 0x4703f6
    if (!cpu.flags.zf)
    {
        goto L_0x004703f6;
    }
    // 004703de  e80d5d0000             -call 0x4760f0
    cpu.esp -= 4;
    sub_4760f0(app, cpu);
    if (cpu.terminate) return;
    // 004703e3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004703e5  740f                   -je 0x4703f6
    if (cpu.flags.zf)
    {
        goto L_0x004703f6;
    }
    // 004703e7  3b2d64eb5300           +cmp ebp, dword ptr [0x53eb64]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5499748) /* 0x53eb64 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004703ed  7e07                   -jle 0x4703f6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004703f6;
    }
    // 004703ef  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004703f1  e8fa93fdff             -call 0x4497f0
    cpu.esp -= 4;
    sub_4497f0(app, cpu);
    if (cpu.terminate) return;
L_0x004703f6:
    // 004703f6  b817000000             -mov eax, 0x17
    cpu.eax = 23 /*0x17*/;
    // 004703fb  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004703fd  e88e9afeff             -call 0x459e90
    cpu.esp -= 4;
    sub_459e90(app, cpu);
    if (cpu.terminate) return;
    // 00470402  a398065100             -mov dword ptr [0x510698], eax
    app->getMemory<x86::reg32>(x86::reg32(5310104) /* 0x510698 */) = cpu.eax;
    // 00470407  3b3dd8ff5000           +cmp edi, dword ptr [0x50ffd8]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5308376) /* 0x50ffd8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047040d  7511                   -jne 0x470420
    if (!cpu.flags.zf)
    {
        goto L_0x00470420;
    }
    // 0047040f  b819000000             -mov eax, 0x19
    cpu.eax = 25 /*0x19*/;
    // 00470414  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00470416  e8759afeff             -call 0x459e90
    cpu.esp -= 4;
    sub_459e90(app, cpu);
    if (cpu.terminate) return;
    // 0047041b  a39c065100             -mov dword ptr [0x51069c], eax
    app->getMemory<x86::reg32>(x86::reg32(5310108) /* 0x51069c */) = cpu.eax;
L_0x00470420:
    // 00470420  3b2dd8ff5000           +cmp ebp, dword ptr [0x50ffd8]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5308376) /* 0x50ffd8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00470426  0f8ec6000000           -jle 0x4704f2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004704f2;
    }
L_0x0047042c:
    // 0047042c  b808000000             -mov eax, 8
    cpu.eax = 8 /*0x8*/;
    // 00470431  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00470433  e8589afeff             -call 0x459e90
    cpu.esp -= 4;
    sub_459e90(app, cpu);
    if (cpu.terminate) return;
    // 00470438  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047043a  0f85c9000000           -jne 0x470509
    if (!cpu.flags.zf)
    {
        goto L_0x00470509;
    }
    // 00470440  ff051ced5300           +inc dword ptr [0x53ed1c]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5500188) /* 0x53ed1c */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00470446  e9e3fcffff             -jmp 0x47012e
    goto L_0x0047012e;
L_0x0047044b:
    // 0047044b  8b1560055200           -mov edx, dword ptr [0x520560]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5375328) /* 0x520560 */);
    // 00470451  3b15fcec5300           +cmp edx, dword ptr [0x53ecfc]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5500156) /* 0x53ecfc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00470457  0f844dfeffff           -je 0x4702aa
    if (cpu.flags.zf)
    {
        goto L_0x004702aa;
    }
    // 0047045d  8915fcec5300           -mov dword ptr [0x53ecfc], edx
    app->getMemory<x86::reg32>(x86::reg32(5500156) /* 0x53ecfc */) = cpu.edx;
    // 00470463  39d3                   +cmp ebx, edx
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
    // 00470465  740f                   -je 0x470476
    if (cpu.flags.zf)
    {
        goto L_0x00470476;
    }
    // 00470467  e8a8abfdff             -call 0x44b014
    cpu.esp -= 4;
    sub_44b014(app, cpu);
    if (cpu.terminate) return;
    // 0047046c  e8df02fdff             -call 0x440750
    cpu.esp -= 4;
    sub_440750(app, cpu);
    if (cpu.terminate) return;
    // 00470471  e934feffff             -jmp 0x4702aa
    goto L_0x004702aa;
L_0x00470476:
    // 00470476  e8b502fdff             -call 0x440730
    cpu.esp -= 4;
    sub_440730(app, cpu);
    if (cpu.terminate) return;
    // 0047047b  e92afeffff             -jmp 0x4702aa
    goto L_0x004702aa;
L_0x00470480:
    // 00470480  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00470482  e8d9010000             -call 0x470660
    cpu.esp -= 4;
    sub_470660(app, cpu);
    if (cpu.terminate) return;
    // 00470487  e939feffff             -jmp 0x4702c5
    goto L_0x004702c5;
L_0x0047048c:
    // 0047048c  b82a000000             -mov eax, 0x2a
    cpu.eax = 42 /*0x2a*/;
    // 00470491  e82a450100             -call 0x4849c0
    cpu.esp -= 4;
    sub_4849c0(app, cpu);
    if (cpu.terminate) return;
    // 00470496  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00470498  0f8516ffffff           -jne 0x4703b4
    if (!cpu.flags.zf)
    {
        goto L_0x004703b4;
    }
    // 0047049e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004704a0  e911ffffff             -jmp 0x4703b6
    goto L_0x004703b6;
L_0x004704a5:
    // 004704a5  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 004704aa  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004704ac  e8df99feff             -call 0x459e90
    cpu.esp -= 4;
    sub_459e90(app, cpu);
    if (cpu.terminate) return;
    // 004704b1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004704b3  7415                   -je 0x4704ca
    if (cpu.flags.zf)
    {
        goto L_0x004704ca;
    }
    // 004704b5  b836000000             -mov eax, 0x36
    cpu.eax = 54 /*0x36*/;
    // 004704ba  e801450100             -call 0x4849c0
    cpu.esp -= 4;
    sub_4849c0(app, cpu);
    if (cpu.terminate) return;
    // 004704bf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004704c1  741d                   -je 0x4704e0
    if (cpu.flags.zf)
    {
        goto L_0x004704e0;
    }
L_0x004704c3:
    // 004704c3  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x004704c5:
    // 004704c5  e86669fbff             -call 0x426e30
    cpu.esp -= 4;
    sub_426e30(app, cpu);
    if (cpu.terminate) return;
L_0x004704ca:
    // 004704ca  3b3dd8ff5000           +cmp edi, dword ptr [0x50ffd8]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5308376) /* 0x50ffd8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004704d0  0f8c4affffff           -jl 0x470420
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00470420;
    }
    // 004704d6  e865030000             -call 0x470840
    cpu.esp -= 4;
    sub_470840(app, cpu);
    if (cpu.terminate) return;
    // 004704db  e940ffffff             -jmp 0x470420
    goto L_0x00470420;
L_0x004704e0:
    // 004704e0  b82a000000             -mov eax, 0x2a
    cpu.eax = 42 /*0x2a*/;
    // 004704e5  e8d6440100             -call 0x4849c0
    cpu.esp -= 4;
    sub_4849c0(app, cpu);
    if (cpu.terminate) return;
    // 004704ea  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004704ec  75d5                   -jne 0x4704c3
    if (!cpu.flags.zf)
    {
        goto L_0x004704c3;
    }
    // 004704ee  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004704f0  ebd3                   -jmp 0x4704c5
    goto L_0x004704c5;
L_0x004704f2:
    // 004704f2  3b3de4ff5000           +cmp edi, dword ptr [0x50ffe4]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5308388) /* 0x50ffe4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004704f8  0f8c2effffff           -jl 0x47042c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047042c;
    }
    // 004704fe  ff051ced5300           +inc dword ptr [0x53ed1c]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5500188) /* 0x53ed1c */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00470504  e925fcffff             -jmp 0x47012e
    goto L_0x0047012e;
L_0x00470509:
    // 00470509  e822080000             -call 0x470d30
    cpu.esp -= 4;
    sub_470d30(app, cpu);
    if (cpu.terminate) return;
    // 0047050e  ff051ced5300           +inc dword ptr [0x53ed1c]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5500188) /* 0x53ed1c */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00470514  e915fcffff             -jmp 0x47012e
    goto L_0x0047012e;
L_0x00470519:
    // 00470519  c7050ced530001000000   -mov dword ptr [0x53ed0c], 1
    app->getMemory<x86::reg32>(x86::reg32(5500172) /* 0x53ed0c */) = 1 /*0x1*/;
    // 00470523  e959fcffff             -jmp 0x470181
    goto L_0x00470181;
L_0x00470528:
    // 00470528  a104ed5300             -mov eax, dword ptr [0x53ed04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5500164) /* 0x53ed04 */);
    // 0047052d  85c5                   +test ebp, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.eax));
    // 0047052f  7507                   -jne 0x470538
    if (!cpu.flags.zf)
    {
        goto L_0x00470538;
    }
    // 00470531  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00470533  e8a8170000             -call 0x471ce0
    cpu.esp -= 4;
    sub_471ce0(app, cpu);
    if (cpu.terminate) return;
L_0x00470538:
    // 00470538  8b1564eb5300           -mov edx, dword ptr [0x53eb64]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5499748) /* 0x53eb64 */);
    // 0047053e  891d78744d00           -mov dword ptr [0x4d7478], ebx
    app->getMemory<x86::reg32>(x86::reg32(5076088) /* 0x4d7478 */) = cpu.ebx;
    // 00470544  39d7                   +cmp edi, edx
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
    // 00470546  0f857d000000           -jne 0x4705c9
    if (!cpu.flags.zf)
    {
        goto L_0x004705c9;
    }
    // 0047054c  3b1d64055200           +cmp ebx, dword ptr [0x520564]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5375332) /* 0x520564 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00470552  752d                   -jne 0x470581
    if (!cpu.flags.zf)
    {
        goto L_0x00470581;
    }
    // 00470554  a104ed5300             -mov eax, dword ptr [0x53ed04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5500164) /* 0x53ed04 */);
    // 00470559  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047055b  c7042404000000         -mov dword ptr [esp], 4
    app->getMemory<x86::reg32>(cpu.esp) = 4 /*0x4*/;
    // 00470562  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00470565  f73c24                 -idiv dword ptr [esp]
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(app->getMemory<x86::reg32>(cpu.esp));
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00470568  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047056a  7515                   -jne 0x470581
    if (!cpu.flags.zf)
    {
        goto L_0x00470581;
    }
L_0x0047056c:
    // 0047056c  a104ed5300             -mov eax, dword ptr [0x53ed04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5500164) /* 0x53ed04 */);
    // 00470571  e8fa030000             -call 0x470970
    cpu.esp -= 4;
    sub_470970(app, cpu);
    if (cpu.terminate) return;
    // 00470576  ff0504ed5300           +inc dword ptr [0x53ed04]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5500164) /* 0x53ed04 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0047057c  e90cfcffff             -jmp 0x47018d
    goto L_0x0047018d;
L_0x00470581:
    // 00470581  3b2d64055200           +cmp ebp, dword ptr [0x520564]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5375332) /* 0x520564 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00470587  7510                   -jne 0x470599
    if (!cpu.flags.zf)
    {
        goto L_0x00470599;
    }
    // 00470589  a104ed5300             -mov eax, dword ptr [0x53ed04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5500164) /* 0x53ed04 */);
    // 0047058e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00470590  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00470593  f7ff                   -idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00470595  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00470597  74d3                   -je 0x47056c
    if (cpu.flags.zf)
    {
        goto L_0x0047056c;
    }
L_0x00470599:
    // 00470599  a164055200             -mov eax, dword ptr [0x520564]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5375332) /* 0x520564 */);
    // 0047059e  39c7                   +cmp edi, eax
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
    // 004705a0  74ca                   -je 0x47056c
    if (cpu.flags.zf)
    {
        goto L_0x0047056c;
    }
    // 004705a2  83f803                 +cmp eax, 3
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
    // 004705a5  750c                   -jne 0x4705b3
    if (!cpu.flags.zf)
    {
        goto L_0x004705b3;
    }
    // 004705a7  a104ed5300             -mov eax, dword ptr [0x53ed04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5500164) /* 0x53ed04 */);
    // 004705ac  e8bf030000             -call 0x470970
    cpu.esp -= 4;
    sub_470970(app, cpu);
    if (cpu.terminate) return;
    // 004705b1  ebb9                   -jmp 0x47056c
    goto L_0x0047056c;
L_0x004705b3:
    // 004705b3  892d78744d00           -mov dword ptr [0x4d7478], ebp
    app->getMemory<x86::reg32>(x86::reg32(5076088) /* 0x4d7478 */) = cpu.ebp;
    // 004705b9  e856aafdff             -call 0x44b014
    cpu.esp -= 4;
    sub_44b014(app, cpu);
    if (cpu.terminate) return;
    // 004705be  ff0504ed5300           +inc dword ptr [0x53ed04]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5500164) /* 0x53ed04 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004705c4  e9c4fbffff             -jmp 0x47018d
    goto L_0x0047018d;
L_0x004705c9:
    // 004705c9  83fa04                 +cmp edx, 4
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
    // 004705cc  759e                   -jne 0x47056c
    if (!cpu.flags.zf)
    {
        goto L_0x0047056c;
    }
    // 004705ce  e8bdfffcff             -call 0x440590
    cpu.esp -= 4;
    sub_440590(app, cpu);
    if (cpu.terminate) return;
    // 004705d3  e84817ffff             -call 0x461d20
    cpu.esp -= 4;
    sub_461d20(app, cpu);
    if (cpu.terminate) return;
    // 004705d8  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 004705dd  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004705e2  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 004705e4  891564eb5300           -mov dword ptr [0x53eb64], edx
    app->getMemory<x86::reg32>(x86::reg32(5499748) /* 0x53eb64 */) = cpu.edx;
    // 004705ea  891d0ced5300           -mov dword ptr [0x53ed0c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5500172) /* 0x53ed0c */) = cpu.ebx;
    // 004705f0  893d94744d00           -mov dword ptr [0x4d7494], edi
    app->getMemory<x86::reg32>(x86::reg32(5076116) /* 0x4d7494 */) = cpu.edi;
    // 004705f6  e9c2fbffff             -jmp 0x4701bd
    goto L_0x004701bd;
L_0x004705fb:
    // 004705fb  e814aafdff             -call 0x44b014
    cpu.esp -= 4;
    sub_44b014(app, cpu);
    if (cpu.terminate) return;
    // 00470600  e9a5fbffff             -jmp 0x4701aa
    goto L_0x004701aa;
L_0x00470605:
    // 00470605  66833dca11510000       +cmp word ptr [0x5111ca], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5312970) /* 0x5111ca */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0047060d  0f85d7fbffff           -jne 0x4701ea
    if (!cpu.flags.zf)
    {
        goto L_0x004701ea;
    }
    // 00470613  833d64eb530003         +cmp dword ptr [0x53eb64], 3
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5499748) /* 0x53eb64 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047061a  7510                   -jne 0x47062c
    if (!cpu.flags.zf)
    {
        goto L_0x0047062c;
    }
    // 0047061c  813d18ed530040020000   +cmp dword ptr [0x53ed18], 0x240
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5500184) /* 0x53ed18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(576 /*0x240*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00470626  0f8fbefbffff           -jg 0x4701ea
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004701ea;
    }
L_0x0047062c:
    // 0047062c  833df4ec530000         +cmp dword ptr [0x53ecf4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5500148) /* 0x53ecf4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00470633  0f8494faffff           -je 0x4700cd
    if (cpu.flags.zf)
    {
        goto L_0x004700cd;
    }
    // 00470639  e9dbfbffff             -jmp 0x470219
    goto L_0x00470219;
L_0x0047063e:
    // 0047063e  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00470643  a39c744d00             -mov dword ptr [0x4d749c], eax
    app->getMemory<x86::reg32>(x86::reg32(5076124) /* 0x4d749c */) = cpu.eax;
    // 00470648  a398744d00             -mov dword ptr [0x4d7498], eax
    app->getMemory<x86::reg32>(x86::reg32(5076120) /* 0x4d7498 */) = cpu.eax;
    // 0047064d  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00470650  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470651  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470652  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470653  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470654  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470655  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470656  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_470660(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00470660  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00470661  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00470662  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00470663  833df0ec530000         +cmp dword ptr [0x53ecf0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5500144) /* 0x53ecf0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047066a  754f                   -jne 0x4706bb
    if (!cpu.flags.zf)
    {
        goto L_0x004706bb;
    }
    // 0047066c  8b0d18ed5300           -mov ecx, dword ptr [0x53ed18]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5500184) /* 0x53ed18 */);
    // 00470672  83f920                 +cmp ecx, 0x20
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00470675  7c44                   -jl 0x4706bb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004706bb;
    }
    // 00470677  81f940010000           +cmp ecx, 0x140
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(320 /*0x140*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047067d  7d09                   -jge 0x470688
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00470688;
    }
    // 0047067f  833de4ff500001         +cmp dword ptr [0x50ffe4], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5308388) /* 0x50ffe4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00470686  7e33                   -jle 0x4706bb
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004706bb;
    }
L_0x00470688:
    // 00470688  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047068a  7422                   -je 0x4706ae
    if (cpu.flags.zf)
    {
        goto L_0x004706ae;
    }
    // 0047068c  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00470691  b806000000             -mov eax, 6
    cpu.eax = 6 /*0x6*/;
    // 00470696  e8f597feff             -call 0x459e90
    cpu.esp -= 4;
    sub_459e90(app, cpu);
    if (cpu.terminate) return;
    // 0047069b  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004706a0  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004706a2  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 004706a7  e8e497feff             -call 0x459e90
    cpu.esp -= 4;
    sub_459e90(app, cpu);
    if (cpu.terminate) return;
    // 004706ac  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004706ae:
    // 004706ae  e89d100000             -call 0x471750
    cpu.esp -= 4;
    sub_471750(app, cpu);
    if (cpu.terminate) return;
    // 004706b3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004706b5  750a                   -jne 0x4706c1
    if (!cpu.flags.zf)
    {
        goto L_0x004706c1;
    }
    // 004706b7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004706b8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004706b9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004706ba  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004706bb:
    // 004706bb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004706bd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004706be  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004706bf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004706c0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004706c1:
    // 004706c1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004706c3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004706c5  e88666fbff             -call 0x426d50
    cpu.esp -= 4;
    sub_426d50(app, cpu);
    if (cpu.terminate) return;
    // 004706ca  833dd8ff500002         +cmp dword ptr [0x50ffd8], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5308376) /* 0x50ffd8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004706d1  7c2e                   -jl 0x470701
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00470701;
    }
    // 004706d3  a12cfc5000             -mov eax, dword ptr [0x50fc2c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5307436) /* 0x50fc2c */);
    // 004706d8  83c020                 -add eax, 0x20
    (cpu.eax) += x86::reg32(x86::sreg32(32 /*0x20*/));
L_0x004706db:
    // 004706db  a310ed5300             -mov dword ptr [0x53ed10], eax
    app->getMemory<x86::reg32>(x86::reg32(5500176) /* 0x53ed10 */) = cpu.eax;
    // 004706e0  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 004706e5  e86600fdff             -call 0x440750
    cpu.esp -= 4;
    sub_440750(app, cpu);
    if (cpu.terminate) return;
    // 004706ea  892d98744d00           -mov dword ptr [0x4d7498], ebp
    app->getMemory<x86::reg32>(x86::reg32(5076120) /* 0x4d7498 */) = cpu.ebp;
    // 004706f0  892df8ec5300           -mov dword ptr [0x53ecf8], ebp
    app->getMemory<x86::reg32>(x86::reg32(5500152) /* 0x53ecf8 */) = cpu.ebp;
    // 004706f6  e855700000             -call 0x477750
    cpu.esp -= 4;
    sub_477750(app, cpu);
    if (cpu.terminate) return;
    // 004706fb  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004706fd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004706fe  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004706ff  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470700  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00470701:
    // 00470701  a12cfc5000             -mov eax, dword ptr [0x50fc2c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5307436) /* 0x50fc2c */);
    // 00470706  83c010                 +add eax, 0x10
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00470709  ebd0                   -jmp 0x4706db
    goto L_0x004706db;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_470710(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00470710  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00470711  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00470712  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00470713  8b152cfc5000           -mov edx, dword ptr [0x50fc2c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5307436) /* 0x50fc2c */);
    // 00470719  3b1510ed5300           +cmp edx, dword ptr [0x53ed10]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5500176) /* 0x53ed10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047071f  7c0a                   -jl 0x47072b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047072b;
    }
    // 00470721  8b0d88744d00           -mov ecx, dword ptr [0x4d7488]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5076104) /* 0x4d7488 */);
    // 00470727  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00470729  7404                   -je 0x47072f
    if (cpu.flags.zf)
    {
        goto L_0x0047072f;
    }
L_0x0047072b:
    // 0047072b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047072c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047072d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047072e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047072f:
    // 0047072f  e85cd8feff             -call 0x45df90
    cpu.esp -= 4;
    sub_45df90(app, cpu);
    if (cpu.terminate) return;
    // 00470734  e8a70c0000             -call 0x4713e0
    cpu.esp -= 4;
    sub_4713e0(app, cpu);
    if (cpu.terminate) return;
    // 00470739  83f801                 +cmp eax, 1
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
    // 0047073c  7466                   -je 0x4707a4
    if (cpu.flags.zf)
    {
        goto L_0x004707a4;
    }
    // 0047073e  83f802                 +cmp eax, 2
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
    // 00470741  0f848e000000           -je 0x4707d5
    if (cpu.flags.zf)
    {
        goto L_0x004707d5;
    }
    // 00470747  83f803                 +cmp eax, 3
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
    // 0047074a  0f84b2000000           -je 0x470802
    if (cpu.flags.zf)
    {
        goto L_0x00470802;
    }
    // 00470750  83f804                 +cmp eax, 4
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
    // 00470753  75d6                   -jne 0x47072b
    if (!cpu.flags.zf)
    {
        goto L_0x0047072b;
    }
    // 00470755  e866fffcff             -call 0x4406c0
    cpu.esp -= 4;
    sub_4406c0(app, cpu);
    if (cpu.terminate) return;
    // 0047075a  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0047075c  ff1514155600           -call dword ptr [0x561514]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5641492) /* 0x561514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00470762  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00470764  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00470766  ff1544155600           -call dword ptr [0x561544]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5641540) /* 0x561544 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047076c  ff1548155600           -call dword ptr [0x561548]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5641544) /* 0x561548 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00470772  ff151c155600           -call dword ptr [0x56151c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5641500) /* 0x56151c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00470778  e8936f0000             -call 0x477710
    cpu.esp -= 4;
    sub_477710(app, cpu);
    if (cpu.terminate) return;
    // 0047077d  e89e40fdff             -call 0x444820
    cpu.esp -= 4;
    sub_444820(app, cpu);
    if (cpu.terminate) return;
    // 00470782  e809400000             -call 0x474790
    cpu.esp -= 4;
    sub_474790(app, cpu);
    if (cpu.terminate) return;
    // 00470787  e85413ffff             -call 0x461ae0
    cpu.esp -= 4;
    sub_461ae0(app, cpu);
    if (cpu.terminate) return;
    // 0047078c  e8fb320100             -call 0x483a8c
    cpu.esp -= 4;
    sub_483a8c(app, cpu);
    if (cpu.terminate) return;
    // 00470791  e80a16ffff             -call 0x461da0
    cpu.esp -= 4;
    sub_461da0(app, cpu);
    if (cpu.terminate) return;
    // 00470796  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0047079b  e801700200             -call 0x4977a1
    cpu.esp -= 4;
    sub_4977a1(app, cpu);
    if (cpu.terminate) return;
    // 004707a0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004707a1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004707a2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004707a3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004707a4:
    // 004707a4  e86765fbff             -call 0x426d10
    cpu.esp -= 4;
    sub_426d10(app, cpu);
    if (cpu.terminate) return;
    // 004707a9  e85272feff             -call 0x457a00
    cpu.esp -= 4;
    sub_457a00(app, cpu);
    if (cpu.terminate) return;
    // 004707ae  833dfcec530000         +cmp dword ptr [0x53ecfc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5500156) /* 0x53ecfc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004707b5  7505                   -jne 0x4707bc
    if (!cpu.flags.zf)
    {
        goto L_0x004707bc;
    }
    // 004707b7  e874fffcff             -call 0x440730
    cpu.esp -= 4;
    sub_440730(app, cpu);
    if (cpu.terminate) return;
L_0x004707bc:
    // 004707bc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004707bd  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004707bf  891d98744d00           -mov dword ptr [0x4d7498], ebx
    app->getMemory<x86::reg32>(x86::reg32(5076120) /* 0x4d7498 */) = cpu.ebx;
    // 004707c5  891df8ec5300           -mov dword ptr [0x53ecf8], ebx
    app->getMemory<x86::reg32>(x86::reg32(5500152) /* 0x53ecf8 */) = cpu.ebx;
    // 004707cb  e8606f0000             -call 0x477730
    cpu.esp -= 4;
    sub_477730(app, cpu);
    if (cpu.terminate) return;
    // 004707d0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004707d1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004707d2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004707d3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004707d4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004707d5:
    // 004707d5  e83665fbff             -call 0x426d10
    cpu.esp -= 4;
    sub_426d10(app, cpu);
    if (cpu.terminate) return;
    // 004707da  e82172feff             -call 0x457a00
    cpu.esp -= 4;
    sub_457a00(app, cpu);
    if (cpu.terminate) return;
    // 004707df  e88cfefcff             -call 0x440670
    cpu.esp -= 4;
    sub_440670(app, cpu);
    if (cpu.terminate) return;
    // 004707e4  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004707e9  890df8ec5300           -mov dword ptr [0x53ecf8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5500152) /* 0x53ecf8 */) = cpu.ecx;
    // 004707ef  a3f4ec5300             -mov dword ptr [0x53ecf4], eax
    app->getMemory<x86::reg32>(x86::reg32(5500148) /* 0x53ecf4 */) = cpu.eax;
    // 004707f4  a3f0ec5300             -mov dword ptr [0x53ecf0], eax
    app->getMemory<x86::reg32>(x86::reg32(5500144) /* 0x53ecf0 */) = cpu.eax;
    // 004707f9  e8126f0000             -call 0x477710
    cpu.esp -= 4;
    sub_477710(app, cpu);
    if (cpu.terminate) return;
    // 004707fe  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004707ff  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470800  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470801  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00470802:
    // 00470802  e80965fbff             -call 0x426d10
    cpu.esp -= 4;
    sub_426d10(app, cpu);
    if (cpu.terminate) return;
    // 00470807  e8f471feff             -call 0x457a00
    cpu.esp -= 4;
    sub_457a00(app, cpu);
    if (cpu.terminate) return;
    // 0047080c  e8affefcff             -call 0x4406c0
    cpu.esp -= 4;
    sub_4406c0(app, cpu);
    if (cpu.terminate) return;
    // 00470811  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 00470816  890df8ec5300           -mov dword ptr [0x53ecf8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5500152) /* 0x53ecf8 */) = cpu.ecx;
    // 0047081c  890df0ec5300           -mov dword ptr [0x53ecf0], ecx
    app->getMemory<x86::reg32>(x86::reg32(5500144) /* 0x53ecf0 */) = cpu.ecx;
    // 00470822  8935f4ec5300           -mov dword ptr [0x53ecf4], esi
    app->getMemory<x86::reg32>(x86::reg32(5500148) /* 0x53ecf4 */) = cpu.esi;
    // 00470828  e8e36e0000             -call 0x477710
    cpu.esp -= 4;
    sub_477710(app, cpu);
    if (cpu.terminate) return;
    // 0047082d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047082f  e86c250000             -call 0x472da0
    cpu.esp -= 4;
    sub_472da0(app, cpu);
    if (cpu.terminate) return;
    // 00470834  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470835  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470836  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470837  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_470840(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00470840  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00470841  833d88744d0000         +cmp dword ptr [0x4d7488], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5076104) /* 0x4d7488 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00470848  0f8594000000           -jne 0x4708e2
    if (!cpu.flags.zf)
    {
        goto L_0x004708e2;
    }
L_0x0047084e:
    // 0047084e  833d88744d0000         +cmp dword ptr [0x4d7488], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5076104) /* 0x4d7488 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00470855  752a                   -jne 0x470881
    if (!cpu.flags.zf)
    {
        goto L_0x00470881;
    }
    // 00470857  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0047085c  b80b000000             -mov eax, 0xb
    cpu.eax = 11 /*0xb*/;
    // 00470861  e82a96feff             -call 0x459e90
    cpu.esp -= 4;
    sub_459e90(app, cpu);
    if (cpu.terminate) return;
    // 00470866  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00470868  7417                   -je 0x470881
    if (cpu.flags.zf)
    {
        goto L_0x00470881;
    }
    // 0047086a  833d88744d0000         +cmp dword ptr [0x4d7488], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5076104) /* 0x4d7488 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00470871  0f85a4000000           -jne 0x47091b
    if (!cpu.flags.zf)
    {
        goto L_0x0047091b;
    }
L_0x00470877:
    // 00470877  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0047087c:
    // 0047087c  a388744d00             -mov dword ptr [0x4d7488], eax
    app->getMemory<x86::reg32>(x86::reg32(5076104) /* 0x4d7488 */) = cpu.eax;
L_0x00470881:
    // 00470881  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00470886  b80d000000             -mov eax, 0xd
    cpu.eax = 13 /*0xd*/;
    // 0047088b  e80096feff             -call 0x459e90
    cpu.esp -= 4;
    sub_459e90(app, cpu);
    if (cpu.terminate) return;
    // 00470890  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00470892  7429                   -je 0x4708bd
    if (cpu.flags.zf)
    {
        goto L_0x004708bd;
    }
    // 00470894  833dc83c4d0000         +cmp dword ptr [0x4d3cc8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5061832) /* 0x4d3cc8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047089b  0f8581000000           -jne 0x470922
    if (!cpu.flags.zf)
    {
        goto L_0x00470922;
    }
    // 004708a1  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004708a6:
    // 004708a6  a3c83c4d00             -mov dword ptr [0x4d3cc8], eax
    app->getMemory<x86::reg32>(x86::reg32(5061832) /* 0x4d3cc8 */) = cpu.eax;
    // 004708ab  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004708ad  0f8473000000           -je 0x470926
    if (cpu.flags.zf)
    {
        goto L_0x00470926;
    }
    // 004708b3  a1cc3c4d00             -mov eax, dword ptr [0x4d3ccc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5061836) /* 0x4d3ccc */);
    // 004708b8  a308ed5300             -mov dword ptr [0x53ed08], eax
    app->getMemory<x86::reg32>(x86::reg32(5500168) /* 0x53ed08 */) = cpu.eax;
L_0x004708bd:
    // 004708bd  b80a000000             -mov eax, 0xa
    cpu.eax = 10 /*0xa*/;
    // 004708c2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004708c4  e8c795feff             -call 0x459e90
    cpu.esp -= 4;
    sub_459e90(app, cpu);
    if (cpu.terminate) return;
    // 004708c9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004708cb  7465                   -je 0x470932
    if (cpu.flags.zf)
    {
        goto L_0x00470932;
    }
    // 004708cd  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004708ce  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 004708d3  891d08ed5300           -mov dword ptr [0x53ed08], ebx
    app->getMemory<x86::reg32>(x86::reg32(5500168) /* 0x53ed08 */) = cpu.ebx;
    // 004708d9  891dcc3c4d00           -mov dword ptr [0x4d3ccc], ebx
    app->getMemory<x86::reg32>(x86::reg32(5061836) /* 0x4d3ccc */) = cpu.ebx;
    // 004708df  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004708e0:
    // 004708e0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004708e1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004708e2:
    // 004708e2  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004708e7  b806000000             -mov eax, 6
    cpu.eax = 6 /*0x6*/;
    // 004708ec  e89f95feff             -call 0x459e90
    cpu.esp -= 4;
    sub_459e90(app, cpu);
    if (cpu.terminate) return;
    // 004708f1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004708f3  740e                   -je 0x470903
    if (cpu.flags.zf)
    {
        goto L_0x00470903;
    }
L_0x004708f5:
    // 004708f5  833d88744d0000         +cmp dword ptr [0x4d7488], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5076104) /* 0x4d7488 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004708fc  751d                   -jne 0x47091b
    if (!cpu.flags.zf)
    {
        goto L_0x0047091b;
    }
    // 004708fe  e974ffffff             -jmp 0x470877
    goto L_0x00470877;
L_0x00470903:
    // 00470903  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00470908  b80b000000             -mov eax, 0xb
    cpu.eax = 11 /*0xb*/;
    // 0047090d  e87e95feff             -call 0x459e90
    cpu.esp -= 4;
    sub_459e90(app, cpu);
    if (cpu.terminate) return;
    // 00470912  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00470914  75df                   -jne 0x4708f5
    if (!cpu.flags.zf)
    {
        goto L_0x004708f5;
    }
    // 00470916  e933ffffff             -jmp 0x47084e
    goto L_0x0047084e;
L_0x0047091b:
    // 0047091b  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047091d  e95affffff             -jmp 0x47087c
    goto L_0x0047087c;
L_0x00470922:
    // 00470922  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00470924  eb80                   -jmp 0x4708a6
    goto L_0x004708a6;
L_0x00470926:
    // 00470926  a108ed5300             -mov eax, dword ptr [0x53ed08]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5500168) /* 0x53ed08 */);
    // 0047092b  a3cc3c4d00             -mov dword ptr [0x4d3ccc], eax
    app->getMemory<x86::reg32>(x86::reg32(5061836) /* 0x4d3ccc */) = cpu.eax;
    // 00470930  eb8b                   -jmp 0x4708bd
    goto L_0x004708bd;
L_0x00470932:
    // 00470932  b80e000000             -mov eax, 0xe
    cpu.eax = 14 /*0xe*/;
    // 00470937  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00470939  e85295feff             -call 0x459e90
    cpu.esp -= 4;
    sub_459e90(app, cpu);
    if (cpu.terminate) return;
    // 0047093e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00470940  7510                   -jne 0x470952
    if (!cpu.flags.zf)
    {
        goto L_0x00470952;
    }
    // 00470942  833dc83c4d0000         +cmp dword ptr [0x4d3cc8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5061832) /* 0x4d3cc8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00470949  7495                   -je 0x4708e0
    if (cpu.flags.zf)
    {
        goto L_0x004708e0;
    }
    // 0047094b  a3cc3c4d00             -mov dword ptr [0x4d3ccc], eax
    app->getMemory<x86::reg32>(x86::reg32(5061836) /* 0x4d3ccc */) = cpu.eax;
    // 00470950  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470951  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00470952:
    // 00470952  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00470957  891508ed5300           -mov dword ptr [0x53ed08], edx
    app->getMemory<x86::reg32>(x86::reg32(5500168) /* 0x53ed08 */) = cpu.edx;
    // 0047095d  8915cc3c4d00           -mov dword ptr [0x4d3ccc], edx
    app->getMemory<x86::reg32>(x86::reg32(5061836) /* 0x4d3ccc */) = cpu.edx;
    // 00470963  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470964  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_470970(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00470970  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00470971  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00470972  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00470973  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00470974  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00470975  833d14ed530000         +cmp dword ptr [0x53ed14], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5500180) /* 0x53ed14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047097c  7550                   -jne 0x4709ce
    if (!cpu.flags.zf)
    {
        goto L_0x004709ce;
    }
    // 0047097e  8b0d18ed5300           -mov ecx, dword ptr [0x53ed18]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5500184) /* 0x53ed18 */);
    // 00470984  81f900020000           +cmp ecx, 0x200
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(512 /*0x200*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047098a  0f8c96000000           -jl 0x470a26
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00470a26;
    }
    // 00470990  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 00470995  8a2d28384d00           -mov ch, byte ptr [0x4d3828]
    cpu.ch = app->getMemory<x86::reg8>(x86::reg32(5060648) /* 0x4d3828 */);
    // 0047099b  893514ed5300           -mov dword ptr [0x53ed14], esi
    app->getMemory<x86::reg32>(x86::reg32(5500180) /* 0x53ed14 */) = cpu.esi;
    // 004709a1  84ed                   +test ch, ch
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & cpu.ch));
    // 004709a3  7429                   -je 0x4709ce
    if (cpu.flags.zf)
    {
        goto L_0x004709ce;
    }
    // 004709a5  b97f000000             -mov ecx, 0x7f
    cpu.ecx = 127 /*0x7f*/;
    // 004709aa  8b3dcc744d00           -mov edi, dword ptr [0x4d74cc]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5076172) /* 0x4d74cc */);
    // 004709b0  6a40                   -push 0x40
    app->getMemory<x86::reg32>(cpu.esp-4) = 64 /*0x40*/;
    cpu.esp -= 4;
    // 004709b2  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004709b4  7469                   -je 0x470a1f
    if (cpu.flags.zf)
    {
        goto L_0x00470a1f;
    }
    // 004709b6  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004709b8:
    // 004709b8  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 004709bd  a104925000             -mov eax, dword ptr [0x509204]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5280260) /* 0x509204 */);
    // 004709c2  e8c9fdfcff             -call 0x440790
    cpu.esp -= 4;
    sub_440790(app, cpu);
    if (cpu.terminate) return;
    // 004709c7  30c0                   -xor al, al
    cpu.al ^= x86::reg8(x86::sreg8(cpu.al));
    // 004709c9  a228384d00             -mov byte ptr [0x4d3828], al
    app->getMemory<x86::reg8>(x86::reg32(5060648) /* 0x4d3828 */) = cpu.al;
L_0x004709ce:
    // 004709ce  e85d1afeff             -call 0x452430
    cpu.esp -= 4;
    sub_452430(app, cpu);
    if (cpu.terminate) return;
    // 004709d3  e878290000             -call 0x473350
    cpu.esp -= 4;
    sub_473350(app, cpu);
    if (cpu.terminate) return;
    // 004709d8  f60518ed530001         +test byte ptr [0x53ed18], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5500184) /* 0x53ed18 */) & 1 /*0x1*/));
    // 004709df  7516                   -jne 0x4709f7
    if (!cpu.flags.zf)
    {
        goto L_0x004709f7;
    }
    // 004709e1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004709e3  e838190100             -call 0x482320
    cpu.esp -= 4;
    sub_482320(app, cpu);
    if (cpu.terminate) return;
    // 004709e8  a124ed5300             -mov eax, dword ptr [0x53ed24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5500196) /* 0x53ed24 */);
    // 004709ed  e8feeeffff             -call 0x46f8f0
    cpu.esp -= 4;
    sub_46f8f0(app, cpu);
    if (cpu.terminate) return;
    // 004709f2  e8d9220000             -call 0x472cd0
    cpu.esp -= 4;
    sub_472cd0(app, cpu);
    if (cpu.terminate) return;
L_0x004709f7:
    // 004709f7  a120ed5300             -mov eax, dword ptr [0x53ed20]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5500192) /* 0x53ed20 */);
    // 004709fc  e8efeeffff             -call 0x46f8f0
    cpu.esp -= 4;
    sub_46f8f0(app, cpu);
    if (cpu.terminate) return;
    // 00470a01  ff0518ed5300           -inc dword ptr [0x53ed18]
    (app->getMemory<x86::reg32>(x86::reg32(5500184) /* 0x53ed18 */))++;
    // 00470a07  f60518ed530001         +test byte ptr [0x53ed18], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5500184) /* 0x53ed18 */) & 1 /*0x1*/));
    // 00470a0e  0f84ec000000           -je 0x470b00
    if (cpu.flags.zf)
    {
        goto L_0x00470b00;
    }
    // 00470a14  e877290000             -call 0x473390
    cpu.esp -= 4;
    sub_473390(app, cpu);
    if (cpu.terminate) return;
    // 00470a19  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470a1a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470a1b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470a1c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470a1d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470a1e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00470a1f:
    // 00470a1f  bb40000000             -mov ebx, 0x40
    cpu.ebx = 64 /*0x40*/;
    // 00470a24  eb92                   -jmp 0x4709b8
    goto L_0x004709b8;
L_0x00470a26:
    // 00470a26  81f9c0010000           +cmp ecx, 0x1c0
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(448 /*0x1c0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00470a2c  7c3e                   -jl 0x470a6c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00470a6c;
    }
    // 00470a2e  803d28384d0001         +cmp byte ptr [0x4d3828], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5060648) /* 0x4d3828 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00470a35  7497                   -je 0x4709ce
    if (cpu.flags.zf)
    {
        goto L_0x004709ce;
    }
    // 00470a37  b97f000000             -mov ecx, 0x7f
    cpu.ecx = 127 /*0x7f*/;
    // 00470a3c  8b1dcc744d00           -mov ebx, dword ptr [0x4d74cc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5076172) /* 0x4d74cc */);
    // 00470a42  6a40                   -push 0x40
    app->getMemory<x86::reg32>(cpu.esp-4) = 64 /*0x40*/;
    cpu.esp -= 4;
    // 00470a44  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00470a46  741d                   -je 0x470a65
    if (cpu.flags.zf)
    {
        goto L_0x00470a65;
    }
    // 00470a48  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
L_0x00470a4a:
    // 00470a4a  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00470a4f  a104925000             -mov eax, dword ptr [0x509204]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5280260) /* 0x509204 */);
    // 00470a54  e837fdfcff             -call 0x440790
    cpu.esp -= 4;
    sub_440790(app, cpu);
    if (cpu.terminate) return;
    // 00470a59  c60528384d0001         -mov byte ptr [0x4d3828], 1
    app->getMemory<x86::reg8>(x86::reg32(5060648) /* 0x4d3828 */) = 1 /*0x1*/;
    // 00470a60  e969ffffff             -jmp 0x4709ce
    goto L_0x004709ce;
L_0x00470a65:
    // 00470a65  bb40000000             -mov ebx, 0x40
    cpu.ebx = 64 /*0x40*/;
    // 00470a6a  ebde                   -jmp 0x470a4a
    goto L_0x00470a4a;
L_0x00470a6c:
    // 00470a6c  81f980010000           +cmp ecx, 0x180
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(384 /*0x180*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00470a72  7c42                   -jl 0x470ab6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00470ab6;
    }
    // 00470a74  803d28384d0002         +cmp byte ptr [0x4d3828], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5060648) /* 0x4d3828 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00470a7b  0f844dffffff           -je 0x4709ce
    if (cpu.flags.zf)
    {
        goto L_0x004709ce;
    }
    // 00470a81  b97f000000             -mov ecx, 0x7f
    cpu.ecx = 127 /*0x7f*/;
    // 00470a86  8b15cc744d00           -mov edx, dword ptr [0x4d74cc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5076172) /* 0x4d74cc */);
    // 00470a8c  6a40                   -push 0x40
    app->getMemory<x86::reg32>(cpu.esp-4) = 64 /*0x40*/;
    cpu.esp -= 4;
    // 00470a8e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00470a90  741d                   -je 0x470aaf
    if (cpu.flags.zf)
    {
        goto L_0x00470aaf;
    }
    // 00470a92  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
L_0x00470a94:
    // 00470a94  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00470a99  a104925000             -mov eax, dword ptr [0x509204]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5280260) /* 0x509204 */);
    // 00470a9e  e8edfcfcff             -call 0x440790
    cpu.esp -= 4;
    sub_440790(app, cpu);
    if (cpu.terminate) return;
    // 00470aa3  c60528384d0002         -mov byte ptr [0x4d3828], 2
    app->getMemory<x86::reg8>(x86::reg32(5060648) /* 0x4d3828 */) = 2 /*0x2*/;
    // 00470aaa  e91fffffff             -jmp 0x4709ce
    goto L_0x004709ce;
L_0x00470aaf:
    // 00470aaf  bb40000000             -mov ebx, 0x40
    cpu.ebx = 64 /*0x40*/;
    // 00470ab4  ebde                   -jmp 0x470a94
    goto L_0x00470a94;
L_0x00470ab6:
    // 00470ab6  81f940010000           +cmp ecx, 0x140
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(320 /*0x140*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00470abc  0f8c0cffffff           -jl 0x4709ce
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004709ce;
    }
    // 00470ac2  803d28384d0003         +cmp byte ptr [0x4d3828], 3
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5060648) /* 0x4d3828 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(3 /*0x3*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00470ac9  0f84fffeffff           -je 0x4709ce
    if (cpu.flags.zf)
    {
        goto L_0x004709ce;
    }
    // 00470acf  b97f000000             -mov ecx, 0x7f
    cpu.ecx = 127 /*0x7f*/;
    // 00470ad4  a1cc744d00             -mov eax, dword ptr [0x4d74cc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5076172) /* 0x4d74cc */);
    // 00470ad9  6a40                   -push 0x40
    app->getMemory<x86::reg32>(cpu.esp-4) = 64 /*0x40*/;
    cpu.esp -= 4;
    // 00470adb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00470add  741a                   -je 0x470af9
    if (cpu.flags.zf)
    {
        goto L_0x00470af9;
    }
    // 00470adf  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00470ae1:
    // 00470ae1  a104925000             -mov eax, dword ptr [0x509204]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5280260) /* 0x509204 */);
    // 00470ae6  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00470ae8  e8a3fcfcff             -call 0x440790
    cpu.esp -= 4;
    sub_440790(app, cpu);
    if (cpu.terminate) return;
    // 00470aed  c60528384d0003         -mov byte ptr [0x4d3828], 3
    app->getMemory<x86::reg8>(x86::reg32(5060648) /* 0x4d3828 */) = 3 /*0x3*/;
    // 00470af4  e9d5feffff             -jmp 0x4709ce
    goto L_0x004709ce;
L_0x00470af9:
    // 00470af9  bb40000000             -mov ebx, 0x40
    cpu.ebx = 64 /*0x40*/;
    // 00470afe  ebe1                   -jmp 0x470ae1
    goto L_0x00470ae1;
L_0x00470b00:
    // 00470b00  e8dbf7fcff             -call 0x4402e0
    cpu.esp -= 4;
    sub_4402e0(app, cpu);
    if (cpu.terminate) return;
    // 00470b05  e886280000             -call 0x473390
    cpu.esp -= 4;
    sub_473390(app, cpu);
    if (cpu.terminate) return;
    // 00470b0a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470b0b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470b0c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470b0d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470b0e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470b0f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_470b10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00470b10  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00470b11  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00470b12  e8b96b0000             -call 0x4776d0
    cpu.esp -= 4;
    sub_4776d0(app, cpu);
    if (cpu.terminate) return;
    // 00470b17  e8e4140000             -call 0x472000
    cpu.esp -= 4;
    sub_472000(app, cpu);
    if (cpu.terminate) return;
    // 00470b1c  ba14b04400             -mov edx, 0x44b014
    cpu.edx = 4501524 /*0x44b014*/;
    // 00470b21  a120ed5300             -mov eax, dword ptr [0x53ed20]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5500192) /* 0x53ed20 */);
    // 00470b26  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00470b28  e803eeffff             -call 0x46f930
    cpu.esp -= 4;
    sub_46f930(app, cpu);
    if (cpu.terminate) return;
    // 00470b2d  e81ea5fcff             -call 0x43b050
    cpu.esp -= 4;
    sub_43b050(app, cpu);
    if (cpu.terminate) return;
    // 00470b32  e8b9cefdff             -call 0x44d9f0
    cpu.esp -= 4;
    sub_44d9f0(app, cpu);
    if (cpu.terminate) return;
    // 00470b37  e824baffff             -call 0x46c560
    cpu.esp -= 4;
    sub_46c560(app, cpu);
    if (cpu.terminate) return;
    // 00470b3c  e83f160000             -call 0x472180
    cpu.esp -= 4;
    sub_472180(app, cpu);
    if (cpu.terminate) return;
    // 00470b41  e85a480000             -call 0x4753a0
    cpu.esp -= 4;
    sub_4753a0(app, cpu);
    if (cpu.terminate) return;
    // 00470b46  e815a5fcff             -call 0x43b060
    cpu.esp -= 4;
    sub_43b060(app, cpu);
    if (cpu.terminate) return;
    // 00470b4b  e8208dfeff             -call 0x459870
    cpu.esp -= 4;
    sub_459870(app, cpu);
    if (cpu.terminate) return;
    // 00470b50  a124ed5300             -mov eax, dword ptr [0x53ed24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5500196) /* 0x53ed24 */);
    // 00470b55  e856efffff             -call 0x46fab0
    cpu.esp -= 4;
    sub_46fab0(app, cpu);
    if (cpu.terminate) return;
    // 00470b5a  a120ed5300             -mov eax, dword ptr [0x53ed20]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5500192) /* 0x53ed20 */);
    // 00470b5f  e84cefffff             -call 0x46fab0
    cpu.esp -= 4;
    sub_46fab0(app, cpu);
    if (cpu.terminate) return;
    // 00470b64  e8a76efeff             -call 0x457a10
    cpu.esp -= 4;
    sub_457a10(app, cpu);
    if (cpu.terminate) return;
    // 00470b69  e812000000             -call 0x470b80
    cpu.esp -= 4;
    sub_470b80(app, cpu);
    if (cpu.terminate) return;
    // 00470b6e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470b6f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470b70  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_470b80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00470b80  e80b7dfbff             -call 0x428890
    cpu.esp -= 4;
    sub_428890(app, cpu);
    if (cpu.terminate) return;
    // 00470b85  a310005100             -mov dword ptr [0x510010], eax
    app->getMemory<x86::reg32>(x86::reg32(5308432) /* 0x510010 */) = cpu.eax;
    // 00470b8a  a29e0c5100             -mov byte ptr [0x510c9e], al
    app->getMemory<x86::reg8>(x86::reg32(5311646) /* 0x510c9e */) = cpu.al;
    // 00470b8f  e81c7dfbff             -call 0x4288b0
    cpu.esp -= 4;
    sub_4288b0(app, cpu);
    if (cpu.terminate) return;
    // 00470b94  a314005100             -mov dword ptr [0x510014], eax
    app->getMemory<x86::reg32>(x86::reg32(5308436) /* 0x510014 */) = cpu.eax;
    // 00470b99  a29f0c5100             -mov byte ptr [0x510c9f], al
    app->getMemory<x86::reg8>(x86::reg32(5311647) /* 0x510c9f */) = cpu.al;
    // 00470b9e  a018005100             -mov al, byte ptr [0x510018]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5308440) /* 0x510018 */);
    // 00470ba3  a2a10c5100             -mov byte ptr [0x510ca1], al
    app->getMemory<x86::reg8>(x86::reg32(5311649) /* 0x510ca1 */) = cpu.al;
    // 00470ba8  e80340fdff             -call 0x444bb0
    cpu.esp -= 4;
    sub_444bb0(app, cpu);
    if (cpu.terminate) return;
    // 00470bad  a31c005100             -mov dword ptr [0x51001c], eax
    app->getMemory<x86::reg32>(x86::reg32(5308444) /* 0x51001c */) = cpu.eax;
    // 00470bb2  a2a00c5100             -mov byte ptr [0x510ca0], al
    app->getMemory<x86::reg8>(x86::reg32(5311648) /* 0x510ca0 */) = cpu.al;
    // 00470bb7  a1b8c94e00             -mov eax, dword ptr [0x4ec9b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5163448) /* 0x4ec9b8 */);
    // 00470bbc  a320005100             -mov dword ptr [0x510020], eax
    app->getMemory<x86::reg32>(x86::reg32(5308448) /* 0x510020 */) = cpu.eax;
    // 00470bc1  a2a20c5100             -mov byte ptr [0x510ca2], al
    app->getMemory<x86::reg8>(x86::reg32(5311650) /* 0x510ca2 */) = cpu.al;
    // 00470bc6  e91580f9ff             -jmp 0x408be0
    return sub_408be0(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_470bd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00470bd0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00470bd1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00470bd3  a1f4ff5000             -mov eax, dword ptr [0x50fff4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5308404) /* 0x50fff4 */);
    // 00470bd8  8915f4ec5300           -mov dword ptr [0x53ecf4], edx
    app->getMemory<x86::reg32>(x86::reg32(5500148) /* 0x53ecf4 */) = cpu.edx;
    // 00470bde  8915f8ec5300           -mov dword ptr [0x53ecf8], edx
    app->getMemory<x86::reg32>(x86::reg32(5500152) /* 0x53ecf8 */) = cpu.edx;
    // 00470be4  8915fcec5300           -mov dword ptr [0x53ecfc], edx
    app->getMemory<x86::reg32>(x86::reg32(5500156) /* 0x53ecfc */) = cpu.edx;
    // 00470bea  891500ed5300           -mov dword ptr [0x53ed00], edx
    app->getMemory<x86::reg32>(x86::reg32(5500160) /* 0x53ed00 */) = cpu.edx;
    // 00470bf0  891504ed5300           -mov dword ptr [0x53ed04], edx
    app->getMemory<x86::reg32>(x86::reg32(5500164) /* 0x53ed04 */) = cpu.edx;
    // 00470bf6  891514ed5300           -mov dword ptr [0x53ed14], edx
    app->getMemory<x86::reg32>(x86::reg32(5500180) /* 0x53ed14 */) = cpu.edx;
    // 00470bfc  891518ed5300           -mov dword ptr [0x53ed18], edx
    app->getMemory<x86::reg32>(x86::reg32(5500184) /* 0x53ed18 */) = cpu.edx;
    // 00470c02  e8e98bfeff             -call 0x4597f0
    cpu.esp -= 4;
    sub_4597f0(app, cpu);
    if (cpu.terminate) return;
    // 00470c07  e894a3fcff             -call 0x43afa0
    cpu.esp -= 4;
    sub_43afa0(app, cpu);
    if (cpu.terminate) return;
    // 00470c0c  e8dfb9ffff             -call 0x46c5f0
    cpu.esp -= 4;
    sub_46c5f0(app, cpu);
    if (cpu.terminate) return;
    // 00470c11  e83ad5fdff             -call 0x44e150
    cpu.esp -= 4;
    sub_44e150(app, cpu);
    if (cpu.terminate) return;
    // 00470c16  e8e5160000             -call 0x472300
    cpu.esp -= 4;
    sub_472300(app, cpu);
    if (cpu.terminate) return;
    // 00470c1b  e820a2fcff             -call 0x43ae40
    cpu.esp -= 4;
    sub_43ae40(app, cpu);
    if (cpu.terminate) return;
    // 00470c20  e8abcfffff             -call 0x46dbd0
    cpu.esp -= 4;
    sub_46dbd0(app, cpu);
    if (cpu.terminate) return;
    // 00470c25  e8c66a0000             -call 0x4776f0
    cpu.esp -= 4;
    sub_4776f0(app, cpu);
    if (cpu.terminate) return;
    // 00470c2a  a10c085100             -mov eax, dword ptr [0x51080c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5310476) /* 0x51080c */);
    // 00470c2f  a31ced5300             -mov dword ptr [0x53ed1c], eax
    app->getMemory<x86::reg32>(x86::reg32(5500188) /* 0x53ed1c */) = cpu.eax;
    // 00470c34  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470c35  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_470c40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00470c40  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00470c41  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00470c42  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00470c43  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00470c48  b8e0bf4c00             -mov eax, 0x4cbfe0
    cpu.eax = 5029856 /*0x4cbfe0*/;
    // 00470c4d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00470c4f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00470c51  8915f0ec5300           -mov dword ptr [0x53ecf0], edx
    app->getMemory<x86::reg32>(x86::reg32(5500144) /* 0x53ecf0 */) = cpu.edx;
    // 00470c57  890df4ec5300           -mov dword ptr [0x53ecf4], ecx
    app->getMemory<x86::reg32>(x86::reg32(5500148) /* 0x53ecf4 */) = cpu.ecx;
    // 00470c5d  890df8ec5300           -mov dword ptr [0x53ecf8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5500152) /* 0x53ecf8 */) = cpu.ecx;
    // 00470c63  890dfcec5300           -mov dword ptr [0x53ecfc], ecx
    app->getMemory<x86::reg32>(x86::reg32(5500156) /* 0x53ecfc */) = cpu.ecx;
    // 00470c69  890d00ed5300           -mov dword ptr [0x53ed00], ecx
    app->getMemory<x86::reg32>(x86::reg32(5500160) /* 0x53ed00 */) = cpu.ecx;
    // 00470c6f  890d04ed5300           -mov dword ptr [0x53ed04], ecx
    app->getMemory<x86::reg32>(x86::reg32(5500164) /* 0x53ed04 */) = cpu.ecx;
    // 00470c75  890d14ed5300           -mov dword ptr [0x53ed14], ecx
    app->getMemory<x86::reg32>(x86::reg32(5500180) /* 0x53ed14 */) = cpu.ecx;
    // 00470c7b  ba90000000             -mov edx, 0x90
    cpu.edx = 144 /*0x90*/;
    // 00470c80  890d18ed5300           -mov dword ptr [0x53ed18], ecx
    app->getMemory<x86::reg32>(x86::reg32(5500184) /* 0x53ed18 */) = cpu.ecx;
    // 00470c86  e835eeffff             -call 0x46fac0
    cpu.esp -= 4;
    sub_46fac0(app, cpu);
    if (cpu.terminate) return;
    // 00470c8b  ba90000000             -mov edx, 0x90
    cpu.edx = 144 /*0x90*/;
    // 00470c90  a324ed5300             -mov dword ptr [0x53ed24], eax
    app->getMemory<x86::reg32>(x86::reg32(5500196) /* 0x53ed24 */) = cpu.eax;
    // 00470c95  b8e8bf4c00             -mov eax, 0x4cbfe8
    cpu.eax = 5029864 /*0x4cbfe8*/;
    // 00470c9a  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 00470c9f  e81ceeffff             -call 0x46fac0
    cpu.esp -= 4;
    sub_46fac0(app, cpu);
    if (cpu.terminate) return;
    // 00470ca4  baf0d64400             -mov edx, 0x44d6f0
    cpu.edx = 4511472 /*0x44d6f0*/;
    // 00470ca9  a320ed5300             -mov dword ptr [0x53ed20], eax
    app->getMemory<x86::reg32>(x86::reg32(5500192) /* 0x53ed20 */) = cpu.eax;
    // 00470cae  a124ed5300             -mov eax, dword ptr [0x53ed24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5500196) /* 0x53ed24 */);
    // 00470cb3  e828edffff             -call 0x46f9e0
    cpu.esp -= 4;
    sub_46f9e0(app, cpu);
    if (cpu.terminate) return;
    // 00470cb8  a1f4ff5000             -mov eax, dword ptr [0x50fff4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5308404) /* 0x50fff4 */);
    // 00470cbd  e82e8bfeff             -call 0x4597f0
    cpu.esp -= 4;
    sub_4597f0(app, cpu);
    if (cpu.terminate) return;
    // 00470cc2  e8e9a2fcff             -call 0x43afb0
    cpu.esp -= 4;
    sub_43afb0(app, cpu);
    if (cpu.terminate) return;
    // 00470cc7  e8f4b8ffff             -call 0x46c5c0
    cpu.esp -= 4;
    sub_46c5c0(app, cpu);
    if (cpu.terminate) return;
    // 00470ccc  e8ef460000             -call 0x4753c0
    cpu.esp -= 4;
    sub_4753c0(app, cpu);
    if (cpu.terminate) return;
    // 00470cd1  e80acffdff             -call 0x44dbe0
    cpu.esp -= 4;
    sub_44dbe0(app, cpu);
    if (cpu.terminate) return;
    // 00470cd6  e8b5680000             -call 0x477590
    cpu.esp -= 4;
    sub_477590(app, cpu);
    if (cpu.terminate) return;
    // 00470cdb  b808000000             -mov eax, 8
    cpu.eax = 8 /*0x8*/;
    // 00470ce0  b964000000             -mov ecx, 0x64
    cpu.ecx = 100 /*0x64*/;
    // 00470ce5  e886ac0000             -call 0x47b970
    cpu.esp -= 4;
    sub_47b970(app, cpu);
    if (cpu.terminate) return;
    // 00470cea  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 00470cef  ba14b04400             -mov edx, 0x44b014
    cpu.edx = 4501524 /*0x44b014*/;
    // 00470cf4  e877ac0000             -call 0x47b970
    cpu.esp -= 4;
    sub_47b970(app, cpu);
    if (cpu.terminate) return;
    // 00470cf9  e882a2fcff             -call 0x43af80
    cpu.esp -= 4;
    sub_43af80(app, cpu);
    if (cpu.terminate) return;
    // 00470cfe  b80a000000             -mov eax, 0xa
    cpu.eax = 10 /*0xa*/;
    // 00470d03  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00470d05  e866ac0000             -call 0x47b970
    cpu.esp -= 4;
    sub_47b970(app, cpu);
    if (cpu.terminate) return;
    // 00470d0a  e8913bfdff             -call 0x4448a0
    cpu.esp -= 4;
    sub_4448a0(app, cpu);
    if (cpu.terminate) return;
    // 00470d0f  a120ed5300             -mov eax, dword ptr [0x53ed20]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5500192) /* 0x53ed20 */);
    // 00470d14  e8c7ecffff             -call 0x46f9e0
    cpu.esp -= 4;
    sub_46f9e0(app, cpu);
    if (cpu.terminate) return;
    // 00470d19  e862cefdff             -call 0x44db80
    cpu.esp -= 4;
    sub_44db80(app, cpu);
    if (cpu.terminate) return;
    // 00470d1e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470d1f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470d20  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470d21  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_470d30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00470d30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00470d31  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00470d32  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00470d33  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00470d34  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00470d35  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00470d36  81ec00030000           -sub esp, 0x300
    (cpu.esp) -= x86::reg32(x86::sreg32(768 /*0x300*/));
    // 00470d3c  8b15d8ff5000           -mov edx, dword ptr [0x50ffd8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5308376) /* 0x50ffd8 */);
    // 00470d42  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00470d44  83fa02                 +cmp edx, 2
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
    // 00470d47  7c0d                   -jl 0x470d56
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00470d56;
    }
L_0x00470d49:
    // 00470d49  81c400030000           -add esp, 0x300
    (cpu.esp) += x86::reg32(x86::sreg32(768 /*0x300*/));
    // 00470d4f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470d50  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470d51  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470d52  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470d53  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470d54  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470d55  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00470d56:
    // 00470d56  8b0d84744d00           -mov ecx, dword ptr [0x4d7484]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5076100) /* 0x4d7484 */);
    // 00470d5c  ba00010000             -mov edx, 0x100
    cpu.edx = 256 /*0x100*/;
    // 00470d61  41                     -inc ecx
    (cpu.ecx)++;
    // 00470d62  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00470d64  890d84744d00           -mov dword ptr [0x4d7484], ecx
    app->getMemory<x86::reg32>(x86::reg32(5076100) /* 0x4d7484 */) = cpu.ecx;
    // 00470d6a  e8f1defbff             -call 0x42ec60
    cpu.esp -= 4;
    sub_42ec60(app, cpu);
    if (cpu.terminate) return;
    // 00470d6f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00470d71  74d6                   -je 0x470d49
    if (cpu.flags.zf)
    {
        goto L_0x00470d49;
    }
    // 00470d73  8b3584744d00           -mov esi, dword ptr [0x4d7484]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5076100) /* 0x4d7484 */);
    // 00470d79  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00470d7a  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00470d7e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00470d7f  68a4bf4c00             -push 0x4cbfa4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5029796 /*0x4cbfa4*/;
    cpu.esp -= 4;
    // 00470d84  8d84240c020000         -lea eax, [esp + 0x20c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(524) /* 0x20c */);
    // 00470d8b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00470d8c  e8e03b0100             -call 0x484971
    cpu.esp -= 4;
    sub_484971(app, cpu);
    if (cpu.terminate) return;
    // 00470d91  8b3d382b4d00           -mov edi, dword ptr [0x4d2b38]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5057336) /* 0x4d2b38 */);
    // 00470d97  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00470d9a  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00470d9c  0f8594000000           -jne 0x470e36
    if (!cpu.flags.zf)
    {
        goto L_0x00470e36;
    }
    // 00470da2  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 00470da7  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 00470dac  bae0010000             -mov edx, 0x1e0
    cpu.edx = 480 /*0x1e0*/;
    // 00470db1  b880020000             -mov eax, 0x280
    cpu.eax = 640 /*0x280*/;
    // 00470db6  e8a5c90100             -call 0x48d760
    cpu.esp -= 4;
    sub_48d760(app, cpu);
    if (cpu.terminate) return;
    // 00470dbb  a3382b4d00             -mov dword ptr [0x4d2b38], eax
    app->getMemory<x86::reg32>(x86::reg32(5057336) /* 0x4d2b38 */) = cpu.eax;
    // 00470dc0  e853fc0000             -call 0x480a18
    cpu.esp -= 4;
    sub_480a18(app, cpu);
    if (cpu.terminate) return;
    // 00470dc5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00470dc7  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00470dcc  e8dffd0000             -call 0x480bb0
    cpu.esp -= 4;
    sub_480bb0(app, cpu);
    if (cpu.terminate) return;
L_0x00470dd1:
    // 00470dd1  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00470dd3  ff1514155600           -call dword ptr [0x561514]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5641492) /* 0x561514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00470dd9  a1382b4d00             -mov eax, dword ptr [0x4d2b38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5057336) /* 0x4d2b38 */);
    // 00470dde  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 00470de1  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00470de4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00470de5  68e0010000             -push 0x1e0
    app->getMemory<x86::reg32>(cpu.esp-4) = 480 /*0x1e0*/;
    cpu.esp -= 4;
    // 00470dea  6880020000             -push 0x280
    app->getMemory<x86::reg32>(cpu.esp-4) = 640 /*0x280*/;
    cpu.esp -= 4;
    // 00470def  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00470df1  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00470df3  ff15c8145600           -call dword ptr [0x5614c8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5641416) /* 0x5614c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00470df9  8d842400020000         -lea eax, [esp + 0x200]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(512) /* 0x200 */);
    // 00470e00  e8a34b0100             -call 0x4859a8
    cpu.esp -= 4;
    sub_4859a8(app, cpu);
    if (cpu.terminate) return;
    // 00470e05  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00470e07  0f843cffffff           -je 0x470d49
    if (cpu.flags.zf)
    {
        goto L_0x00470d49;
    }
    // 00470e0d  8b2d382b4d00           -mov ebp, dword ptr [0x4d2b38]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5057336) /* 0x4d2b38 */);
    // 00470e13  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00470e15  0f842effffff           -je 0x470d49
    if (cpu.flags.zf)
    {
        goto L_0x00470d49;
    }
    // 00470e1b  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00470e1d  e8ee030100             -call 0x481210
    cpu.esp -= 4;
    sub_481210(app, cpu);
    if (cpu.terminate) return;
    // 00470e22  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00470e24  a3382b4d00             -mov dword ptr [0x4d2b38], eax
    app->getMemory<x86::reg32>(x86::reg32(5057336) /* 0x4d2b38 */) = cpu.eax;
    // 00470e29  81c400030000           +add esp, 0x300
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(768 /*0x300*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00470e2f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470e30  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470e31  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470e32  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470e33  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470e34  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470e35  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00470e36:
    // 00470e36  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00470e38  e8dbfb0000             -call 0x480a18
    cpu.esp -= 4;
    sub_480a18(app, cpu);
    if (cpu.terminate) return;
    // 00470e3d  eb92                   -jmp 0x470dd1
    goto L_0x00470dd1;
}

/* align: skip 0x00 */
void Application::sub_470e40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00470e40  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00470e41  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00470e42  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00470e44  833d8c744d0000         +cmp dword ptr [0x4d748c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5076108) /* 0x4d748c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00470e4b  743b                   -je 0x470e88
    if (cpu.flags.zf)
    {
        goto L_0x00470e88;
    }
    // 00470e4d  66833dc811510000       +cmp word ptr [0x5111c8], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5312968) /* 0x5111c8 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00470e55  7534                   -jne 0x470e8b
    if (!cpu.flags.zf)
    {
        goto L_0x00470e8b;
    }
    // 00470e57  833dd8ff500004         +cmp dword ptr [0x50ffd8], 4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5308376) /* 0x50ffd8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00470e5e  752b                   -jne 0x470e8b
    if (!cpu.flags.zf)
    {
        goto L_0x00470e8b;
    }
    // 00470e60  8b0d34005100           -mov ecx, dword ptr [0x510034]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5308468) /* 0x510034 */);
    // 00470e66  49                     -dec ecx
    (cpu.ecx)--;
    // 00470e67  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00470e69  7c1d                   -jl 0x470e88
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00470e88;
    }
    // 00470e6b  8d1c8d00000000         -lea ebx, [ecx*4]
    cpu.ebx = x86::reg32(cpu.ecx * 4);
    // 00470e72  42                     -inc edx
    (cpu.edx)++;
    // 00470e73  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
L_0x00470e75:
    // 00470e75  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00470e77  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00470e79  e846100000             -call 0x471ec4
    cpu.esp -= 4;
    sub_471ec4(app, cpu);
    if (cpu.terminate) return;
    // 00470e7e  49                     -dec ecx
    (cpu.ecx)--;
    // 00470e7f  83eb04                 -sub ebx, 4
    (cpu.ebx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00470e82  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00470e84  7def                   -jge 0x470e75
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00470e75;
    }
    // 00470e86  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x00470e88:
    // 00470e88  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470e89  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470e8a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00470e8b:
    // 00470e8b  0fbe4201               -movsx eax, byte ptr [edx + 1]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */)));
    // 00470e8f  e86c0c0000             -call 0x471b00
    cpu.esp -= 4;
    sub_471b00(app, cpu);
    if (cpu.terminate) return;
    // 00470e94  8b3dd8ff5000           -mov edi, dword ptr [0x50ffd8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5308376) /* 0x50ffd8 */);
    // 00470e9a  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00470e9d  83ff04                 +cmp edi, 4
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00470ea0  7416                   -je 0x470eb8
    if (cpu.flags.zf)
    {
        goto L_0x00470eb8;
    }
    // 00470ea2  833ddcff500000         +cmp dword ptr [0x50ffdc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5308380) /* 0x50ffdc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00470ea9  7531                   -jne 0x470edc
    if (!cpu.flags.zf)
    {
        goto L_0x00470edc;
    }
    // 00470eab  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00470eb0  e80f100000             -call 0x471ec4
    cpu.esp -= 4;
    sub_471ec4(app, cpu);
    if (cpu.terminate) return;
    // 00470eb5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470eb6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470eb7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00470eb8:
    // 00470eb8  a13ced5300             -mov eax, dword ptr [0x53ed3c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5500220) /* 0x53ed3c */);
    // 00470ebd  e8f6740100             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 00470ec2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00470ec4  e83714ffff             -call 0x462300
    cpu.esp -= 4;
    sub_462300(app, cpu);
    if (cpu.terminate) return;
    // 00470ec9  98                     -cwde 
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.ax));
    // 00470eca  e8c10e0000             -call 0x471d90
    cpu.esp -= 4;
    sub_471d90(app, cpu);
    if (cpu.terminate) return;
    // 00470ecf  a13ced5300             -mov eax, dword ptr [0x53ed3c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5500220) /* 0x53ed3c */);
    // 00470ed4  e8f7740100             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 00470ed9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470eda  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470edb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00470edc:
    // 00470edc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00470ede  e8e10f0000             -call 0x471ec4
    cpu.esp -= 4;
    sub_471ec4(app, cpu);
    if (cpu.terminate) return;
    // 00470ee3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470ee4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470ee5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
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
    // 00470ef4  83ec24                 -sub esp, 0x24
    (cpu.esp) -= x86::reg32(x86::sreg32(36 /*0x24*/));
    // 00470ef7  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00470ef9  833dd8ff500004         +cmp dword ptr [0x50ffd8], 4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5308376) /* 0x50ffd8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00470f00  755e                   -jne 0x470f60
    if (!cpu.flags.zf)
    {
        goto L_0x00470f60;
    }
    // 00470f02  66833dc811510000       +cmp word ptr [0x5111c8], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5312968) /* 0x5111c8 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00470f0a  7454                   -je 0x470f60
    if (cpu.flags.zf)
    {
        goto L_0x00470f60;
    }
    // 00470f0c  b205                   -mov dl, 5
    cpu.dl = 5 /*0x5*/;
    // 00470f0e  a13ced5300             -mov eax, dword ptr [0x53ed3c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5500220) /* 0x53ed3c */);
    // 00470f13  881424                 -mov byte ptr [esp], dl
    app->getMemory<x86::reg8>(cpu.esp) = cpu.dl;
    // 00470f16  e89d740100             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 00470f1b  a1dcff5000             -mov eax, dword ptr [0x50ffdc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5308380) /* 0x50ffdc */);
    // 00470f20  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00470f22  e89d0f0000             -call 0x471ec4
    cpu.esp -= 4;
    sub_471ec4(app, cpu);
    if (cpu.terminate) return;
    // 00470f27  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00470f29  7512                   -jne 0x470f3d
    if (!cpu.flags.zf)
    {
        goto L_0x00470f3d;
    }
    // 00470f2b  a13ced5300             -mov eax, dword ptr [0x53ed3c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5500220) /* 0x53ed3c */);
    // 00470f30  e89b740100             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
L_0x00470f35:
    // 00470f35  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 00470f38  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470f39  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470f3a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470f3b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470f3c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00470f3d:
    // 00470f3d  8d442401               -lea eax, [esp + 1]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(1) /* 0x1 */);
    // 00470f41  bb21000000             -mov ebx, 0x21
    cpu.ebx = 33 /*0x21*/;
    // 00470f46  e8450c0000             -call 0x471b90
    cpu.esp -= 4;
    sub_471b90(app, cpu);
    if (cpu.terminate) return;
    // 00470f4b  a13ced5300             -mov eax, dword ptr [0x53ed3c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5500220) /* 0x53ed3c */);
    // 00470f50  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00470f52  e879740100             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 00470f57  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00470f59  e81216ffff             -call 0x462570
    cpu.esp -= 4;
    sub_462570(app, cpu);
    if (cpu.terminate) return;
    // 00470f5e  ebd5                   -jmp 0x470f35
    goto L_0x00470f35;
L_0x00470f60:
    // 00470f60  e8bb0b0000             -call 0x471b20
    cpu.esp -= 4;
    sub_471b20(app, cpu);
    if (cpu.terminate) return;
    // 00470f65  8b0dd8ff5000           -mov ecx, dword ptr [0x50ffd8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5308376) /* 0x50ffd8 */);
    // 00470f6b  a249ed5300             -mov byte ptr [0x53ed49], al
    app->getMemory<x86::reg8>(x86::reg32(5500233) /* 0x53ed49 */) = cpu.al;
    // 00470f70  83f904                 +cmp ecx, 4
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00470f73  7410                   -je 0x470f85
    if (cpu.flags.zf)
    {
        goto L_0x00470f85;
    }
    // 00470f75  a1dcff5000             -mov eax, dword ptr [0x50ffdc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5308380) /* 0x50ffdc */);
    // 00470f7a  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00470f7c  e8430f0000             -call 0x471ec4
    cpu.esp -= 4;
    sub_471ec4(app, cpu);
    if (cpu.terminate) return;
    // 00470f81  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00470f83  74b0                   -je 0x470f35
    if (cpu.flags.zf)
    {
        goto L_0x00470f35;
    }
L_0x00470f85:
    // 00470f85  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00470f86  b405                   -mov ah, 5
    cpu.ah = 5 /*0x5*/;
    // 00470f88  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 00470f8d  bf4aed5300             -mov edi, 0x53ed4a
    cpu.edi = 5500234 /*0x53ed4a*/;
    // 00470f92  bb06000000             -mov ebx, 6
    cpu.ebx = 6 /*0x6*/;
    // 00470f97  ba48ed5300             -mov edx, 0x53ed48
    cpu.edx = 5500232 /*0x53ed48*/;
    // 00470f9c  882548ed5300           -mov byte ptr [0x53ed48], ah
    app->getMemory<x86::reg8>(x86::reg32(5500232) /* 0x53ed48 */) = cpu.ah;
    // 00470fa2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00470fa3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00470fa5  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00470fa8  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00470faa  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00470fac  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00470faf  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00470fb1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470fb2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00470fb4  e8b715ffff             -call 0x462570
    cpu.esp -= 4;
    sub_462570(app, cpu);
    if (cpu.terminate) return;
    // 00470fb9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470fba  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 00470fbd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470fbe  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470fbf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470fc0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470fc1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_470fd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00470fd0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00470fd1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00470fd2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00470fd3  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00470fd5  8b3d2ced5300           -mov edi, dword ptr [0x53ed2c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5500204) /* 0x53ed2c */);
    // 00470fdb  8b0d28ed5300           -mov ecx, dword ptr [0x53ed28]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5500200) /* 0x53ed28 */);
    // 00470fe1  8d53ff                 -lea edx, [ebx - 1]
    cpu.edx = x86::reg32(cpu.ebx + x86::reg32(-1) /* -0x1 */);
    // 00470fe4  46                     -inc esi
    (cpu.esi)++;
    // 00470fe5  01cf                   -add edi, ecx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00470fe7  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00470fe9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00470fea  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00470fec  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00470fef  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00470ff1  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00470ff3  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00470ff6  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00470ff8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00470ff9  011528ed5300           -add dword ptr [0x53ed28], edx
    (app->getMemory<x86::reg32>(x86::reg32(5500200) /* 0x53ed28 */)) += x86::reg32(x86::sreg32(cpu.edx));
    // 00470fff  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471000  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471001  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471002  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_471010(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00471010  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00471011  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00471012  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00471013  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00471014  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00471015  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00471016  81ec94000000           -sub esp, 0x94
    (cpu.esp) -= x86::reg32(x86::sreg32(148 /*0x94*/));
    // 0047101c  b92c000000             -mov ecx, 0x2c
    cpu.ecx = 44 /*0x2c*/;
    // 00471021  be04005100             -mov esi, 0x510004
    cpu.esi = 5308420 /*0x510004*/;
    // 00471026  8d7c2464               -lea edi, [esp + 0x64]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 0047102a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047102b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047102d  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00471030  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00471032  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00471034  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00471037  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00471039  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047103a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047103c  b9c8ff5000             -mov ecx, 0x50ffc8
    cpu.ecx = 5308360 /*0x50ffc8*/;
    // 00471041  b8002d0000             -mov eax, 0x2d00
    cpu.eax = 11520 /*0x2d00*/;
    // 00471046  891528ed5300           -mov dword ptr [0x53ed28], edx
    app->getMemory<x86::reg32>(x86::reg32(5500200) /* 0x53ed28 */) = cpu.edx;
    // 0047104c  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 00471051  890d2ced5300           -mov dword ptr [0x53ed2c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5500204) /* 0x53ed2c */) = cpu.ecx;
    // 00471057  e8e40dffff             -call 0x461e40
    cpu.esp -= 4;
    sub_461e40(app, cpu);
    if (cpu.terminate) return;
    // 0047105c  66833dc811510000       +cmp word ptr [0x5111c8], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5312968) /* 0x5111c8 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00471064  0f84e0000000           -je 0x47114a
    if (cpu.flags.zf)
    {
        goto L_0x0047114a;
    }
    // 0047106a  8b1dd8544d00           -mov ebx, dword ptr [0x4d54d8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5067992) /* 0x4d54d8 */);
    // 00471070  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00471072  741c                   -je 0x471090
    if (cpu.flags.zf)
    {
        goto L_0x00471090;
    }
    // 00471074  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 00471079  bfd4045100             -mov edi, 0x5104d4
    cpu.edi = 5309652 /*0x5104d4*/;
    // 0047107e  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00471080  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00471081  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00471083  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00471086  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00471088  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0047108a  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0047108d  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0047108f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00471090:
    // 00471090  8b35d4544d00           -mov esi, dword ptr [0x4d54d4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5067988) /* 0x4d54d4 */);
    // 00471096  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00471098  0f8587000000           -jne 0x471125
    if (!cpu.flags.zf)
    {
        goto L_0x00471125;
    }
L_0x0047109e:
    // 0047109e  b948000000             -mov ecx, 0x48
    cpu.ecx = 72 /*0x48*/;
    // 004710a3  be540c5100             -mov esi, 0x510c54
    cpu.esi = 5311572 /*0x510c54*/;
    // 004710a8  bfe6045100             -mov edi, 0x5104e6
    cpu.edi = 5309670 /*0x5104e6*/;
    // 004710ad  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004710ae  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004710b0  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004710b3  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004710b5  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004710b7  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004710ba  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004710bc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004710bd  b404                   -mov ah, 4
    cpu.ah = 4 /*0x4*/;
    // 004710bf  bfb0050000             -mov edi, 0x5b0
    cpu.edi = 1456 /*0x5b0*/;
    // 004710c4  882424                 -mov byte ptr [esp], ah
    app->getMemory<x86::reg8>(cpu.esp) = cpu.ah;
    // 004710c7  89bc2490000000         -mov dword ptr [esp + 0x90], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(144) /* 0x90 */) = cpu.edi;
L_0x004710ce:
    // 004710ce  bd62000000             -mov ebp, 0x62
    cpu.ebp = 98 /*0x62*/;
L_0x004710d3:
    // 004710d3  8d7c2401               -lea edi, [esp + 1]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(1) /* 0x1 */);
    // 004710d7  8b352ced5300           -mov esi, dword ptr [0x53ed2c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5500204) /* 0x53ed2c */);
    // 004710dd  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004710df  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004710e1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004710e2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004710e4  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004710e7  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004710e9  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004710eb  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004710ee  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004710f0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004710f1  8d5d01                 -lea ebx, [ebp + 1]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(1) /* 0x1 */);
    // 004710f4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004710f6  e87514ffff             -call 0x462570
    cpu.esp -= 4;
    sub_462570(app, cpu);
    if (cpu.terminate) return;
    // 004710fb  a12ced5300             -mov eax, dword ptr [0x53ed2c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5500204) /* 0x53ed2c */);
    // 00471100  8b942490000000         -mov edx, dword ptr [esp + 0x90]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(144) /* 0x90 */);
    // 00471107  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00471109  83ea62                 -sub edx, 0x62
    (cpu.edx) -= x86::reg32(x86::sreg32(98 /*0x62*/));
    // 0047110c  a32ced5300             -mov dword ptr [0x53ed2c], eax
    app->getMemory<x86::reg32>(x86::reg32(5500204) /* 0x53ed2c */) = cpu.eax;
    // 00471111  89942490000000         -mov dword ptr [esp + 0x90], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(144) /* 0x90 */) = cpu.edx;
    // 00471118  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047111a  7e2e                   -jle 0x47114a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047114a;
    }
    // 0047111c  83fa62                 +cmp edx, 0x62
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(98 /*0x62*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047111f  7dad                   -jge 0x4710ce
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004710ce;
    }
    // 00471121  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00471123  ebae                   -jmp 0x4710d3
    goto L_0x004710d3;
L_0x00471125:
    // 00471125  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 0047112a  bfc4045100             -mov edi, 0x5104c4
    cpu.edi = 5309636 /*0x5104c4*/;
    // 0047112f  81c6b0020000           -add esi, 0x2b0
    (cpu.esi) += x86::reg32(x86::sreg32(688 /*0x2b0*/));
    // 00471135  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00471136  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00471138  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0047113b  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047113d  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0047113f  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00471142  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00471144  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471145  e954ffffff             -jmp 0x47109e
    goto L_0x0047109e;
L_0x0047114a:
    // 0047114a  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 0047114f  b8000f0000             -mov eax, 0xf00
    cpu.eax = 3840 /*0xf00*/;
    // 00471154  b92c000000             -mov ecx, 0x2c
    cpu.ecx = 44 /*0x2c*/;
    // 00471159  e8e20cffff             -call 0x461e40
    cpu.esp -= 4;
    sub_461e40(app, cpu);
    if (cpu.terminate) return;
    // 0047115e  8b151e125100           -mov edx, dword ptr [0x51121e]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5313054) /* 0x51121e */);
    // 00471164  8d742464               -lea esi, [esp + 0x64]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 00471168  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0047116b  bf04005100             -mov edi, 0x510004
    cpu.edi = 5308420 /*0x510004*/;
    // 00471170  8915dcff5000           -mov dword ptr [0x50ffdc], edx
    app->getMemory<x86::reg32>(x86::reg32(5308380) /* 0x50ffdc */) = cpu.edx;
    // 00471176  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00471177  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00471179  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0047117c  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0047117e  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00471180  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00471183  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00471185  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471186  8b35d8544d00           -mov esi, dword ptr [0x4d54d8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5067992) /* 0x4d54d8 */);
    // 0047118c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047118e  741c                   -je 0x4711ac
    if (cpu.flags.zf)
    {
        goto L_0x004711ac;
    }
    // 00471190  b912000000             -mov ecx, 0x12
    cpu.ecx = 18 /*0x12*/;
    // 00471195  89f7                   -mov edi, esi
    cpu.edi = cpu.esi;
    // 00471197  bed4045100             -mov esi, 0x5104d4
    cpu.esi = 5309652 /*0x5104d4*/;
    // 0047119c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047119d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047119f  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004711a2  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004711a4  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004711a6  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004711a9  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004711ab  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004711ac:
    // 004711ac  8b3dd4544d00           -mov edi, dword ptr [0x4d54d4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5067988) /* 0x4d54d4 */);
    // 004711b2  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004711b4  752c                   -jne 0x4711e2
    if (!cpu.flags.zf)
    {
        goto L_0x004711e2;
    }
L_0x004711b6:
    // 004711b6  b948000000             -mov ecx, 0x48
    cpu.ecx = 72 /*0x48*/;
    // 004711bb  bee6045100             -mov esi, 0x5104e6
    cpu.esi = 5309670 /*0x5104e6*/;
    // 004711c0  bf540c5100             -mov edi, 0x510c54
    cpu.edi = 5311572 /*0x510c54*/;
    // 004711c5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004711c6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004711c8  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004711cb  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004711cd  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004711cf  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004711d2  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004711d4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004711d5  81c494000000           -add esp, 0x94
    (cpu.esp) += x86::reg32(x86::sreg32(148 /*0x94*/));
    // 004711db  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004711dc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004711dd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004711de  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004711df  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004711e0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004711e1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004711e2:
    // 004711e2  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 004711e7  bec4045100             -mov esi, 0x5104c4
    cpu.esi = 5309636 /*0x5104c4*/;
    // 004711ec  81c7b0020000           -add edi, 0x2b0
    (cpu.edi) += x86::reg32(x86::sreg32(688 /*0x2b0*/));
    // 004711f2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004711f3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004711f5  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004711f8  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004711fa  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004711fc  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004711ff  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00471201  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471202  ebb2                   -jmp 0x4711b6
    goto L_0x004711b6;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_471210(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00471210  83ec28                 -sub esp, 0x28
    (cpu.esp) -= x86::reg32(x86::sreg32(40 /*0x28*/));
    // 00471213  833de4ff500001         +cmp dword ptr [0x50ffe4], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5308388) /* 0x50ffe4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047121a  7e04                   -jle 0x471220
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00471220;
    }
    // 0047121c  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 0047121f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00471220:
    // 00471220  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00471221  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00471222  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00471223  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00471224  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00471225  e87661fbff             -call 0x4273a0
    cpu.esp -= 4;
    sub_4273a0(app, cpu);
    if (cpu.terminate) return;
    // 0047122a  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0047122c  ff1514155600           -call dword ptr [0x561514]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5641492) /* 0x561514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00471232  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00471234  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00471236  ff1544155600           -call dword ptr [0x561544]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5641540) /* 0x561544 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047123c  ff1548155600           -call dword ptr [0x561548]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5641544) /* 0x561548 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00471242  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00471247  8d7c2414               -lea edi, [esp + 0x14]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0047124b  e8306cfeff             -call 0x457e80
    cpu.esp -= 4;
    sub_457e80(app, cpu);
    if (cpu.terminate) return;
    // 00471250  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00471252  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00471253:
    // 00471253  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00471255  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00471257  3c00                   +cmp al, 0
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
    // 00471259  7410                   -je 0x47126b
    if (cpu.flags.zf)
    {
        goto L_0x0047126b;
    }
    // 0047125b  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0047125e  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00471261  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00471264  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00471267  3c00                   +cmp al, 0
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
    // 00471269  75e8                   -jne 0x471253
    if (!cpu.flags.zf)
    {
        goto L_0x00471253;
    }
L_0x0047126b:
    // 0047126b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047126c  bef0bf4c00             -mov esi, 0x4cbff0
    cpu.esi = 5029872 /*0x4cbff0*/;
    // 00471271  8d7c2414               -lea edi, [esp + 0x14]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00471275  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00471276  2bc9                   +sub ecx, ecx
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
    // 00471278  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00471279  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 0047127b  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0047127d  4f                     -dec edi
    (cpu.edi)--;
L_0x0047127e:
    // 0047127e  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00471280  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00471282  3c00                   +cmp al, 0
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
    // 00471284  7410                   -je 0x471296
    if (cpu.flags.zf)
    {
        goto L_0x00471296;
    }
    // 00471286  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00471289  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0047128c  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0047128f  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00471292  3c00                   +cmp al, 0
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
    // 00471294  75e8                   -jne 0x47127e
    if (!cpu.flags.zf)
    {
        goto L_0x0047127e;
    }
L_0x00471296:
    // 00471296  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471297  8d7c2414               -lea edi, [esp + 0x14]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0047129b  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047129d  49                     -dec ecx
    (cpu.ecx)--;
    // 0047129e  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004712a0  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004712a2  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004712a4  49                     -dec ecx
    (cpu.ecx)--;
    // 004712a5  d1e9                   -shr ecx, 1
    cpu.ecx >>= 1 /*0x1*/ % 32;
    // 004712a7  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 004712ae  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004712b0  ba40010000             -mov edx, 0x140
    cpu.edx = 320 /*0x140*/;
    // 004712b5  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004712b7  bbe6000000             -mov ebx, 0xe6
    cpu.ebx = 230 /*0xe6*/;
    // 004712bc  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004712be  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004712c2  e8a98f0000             -call 0x47a270
    cpu.esp -= 4;
    sub_47a270(app, cpu);
    if (cpu.terminate) return;
    // 004712c7  ff152c155600           -call dword ptr [0x56152c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5641516) /* 0x56152c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004712cd  ff151c155600           -call dword ptr [0x56151c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5641500) /* 0x56151c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004712d3  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004712d5  ff1514155600           -call dword ptr [0x561514]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5641492) /* 0x561514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004712db  ff1548155600           -call dword ptr [0x561548]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5641544) /* 0x561548 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004712e1  e85a61fbff             -call 0x427440
    cpu.esp -= 4;
    sub_427440(app, cpu);
    if (cpu.terminate) return;
    // 004712e6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004712e7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004712e8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004712e9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004712ea  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004712eb  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 004712ee  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_471300(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00471300  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00471301  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00471303  8a4201                 -mov al, byte ptr [edx + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00471306  3c03                   +cmp al, 3
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
    // 00471308  771d                   -ja 0x471327
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00471327;
    }
    // 0047130a  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 0047130f  ff2485f0124700         -jmp dword ptr [eax*4 + 0x4712f0]
    cpu.ip = app->getMemory<x86::reg32>(4657904 + cpu.eax * 4); goto dynamic_jump;
  case 0x00471316:
    // 00471316  833ddcff500000         +cmp dword ptr [0x50ffdc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5308380) /* 0x50ffdc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047131d  740a                   -je 0x471329
    if (cpu.flags.zf)
    {
        goto L_0x00471329;
    }
    // 0047131f  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00471322  a334ed5300             -mov dword ptr [0x53ed34], eax
    app->getMemory<x86::reg32>(x86::reg32(5500212) /* 0x53ed34 */) = cpu.eax;
L_0x00471327:
    // 00471327  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471328  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00471329:
    // 00471329  a13ced5300             -mov eax, dword ptr [0x53ed3c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5500220) /* 0x53ed3c */);
    // 0047132e  e885700100             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 00471333  833d34ed530000         +cmp dword ptr [0x53ed34], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5500212) /* 0x53ed34 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047133a  7519                   -jne 0x471355
    if (!cpu.flags.zf)
    {
        goto L_0x00471355;
    }
    // 0047133c  e83f080000             -call 0x471b80
    cpu.esp -= 4;
    sub_471b80(app, cpu);
    if (cpu.terminate) return;
    // 00471341  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 00471346  a334ed5300             -mov dword ptr [0x53ed34], eax
    app->getMemory<x86::reg32>(x86::reg32(5500212) /* 0x53ed34 */) = cpu.eax;
    // 0047134b  894204                 -mov dword ptr [edx + 4], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0047134e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00471350  e81b12ffff             -call 0x462570
    cpu.esp -= 4;
    sub_462570(app, cpu);
    if (cpu.terminate) return;
L_0x00471355:
    // 00471355  a13ced5300             -mov eax, dword ptr [0x53ed3c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5500220) /* 0x53ed3c */);
    // 0047135a  e871700100             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 0047135f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471360  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00471361:
    // 00471361  66833dc811510000       +cmp word ptr [0x5111c8], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5312968) /* 0x5111c8 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00471369  740c                   -je 0x471377
    if (cpu.flags.zf)
    {
        goto L_0x00471377;
    }
    // 0047136b  c70530ed530001000000   -mov dword ptr [0x53ed30], 1
    app->getMemory<x86::reg32>(x86::reg32(5500208) /* 0x53ed30 */) = 1 /*0x1*/;
    // 00471375  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471376  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00471377:
    // 00471377  66c7059a1151001200     -mov word ptr [0x51119a], 0x12
    app->getMemory<x86::reg16>(x86::reg32(5312922) /* 0x51119a */) = 18 /*0x12*/;
    // 00471380  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471381  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00471382:
    // 00471382  66833dc811510000       +cmp word ptr [0x5111c8], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5312968) /* 0x5111c8 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0047138a  759b                   -jne 0x471327
    if (!cpu.flags.zf)
    {
        goto L_0x00471327;
    }
    // 0047138c  66c7059a1151001500     -mov word ptr [0x51119a], 0x15
    app->getMemory<x86::reg16>(x86::reg32(5312922) /* 0x51119a */) = 21 /*0x15*/;
    // 00471395  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471396  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00471397:
    // 00471397  66833dc811510000       +cmp word ptr [0x5111c8], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5312968) /* 0x5111c8 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0047139f  750b                   -jne 0x4713ac
    if (!cpu.flags.zf)
    {
        goto L_0x004713ac;
    }
    // 004713a1  66c7059a1151001600     -mov word ptr [0x51119a], 0x16
    app->getMemory<x86::reg16>(x86::reg32(5312922) /* 0x51119a */) = 22 /*0x16*/;
    // 004713aa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004713ab  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004713ac:
    // 004713ac  a128554d00             -mov eax, dword ptr [0x4d5528]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5068072) /* 0x4d5528 */);
    // 004713b1  e802700100             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 004713b6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004713b8  e8430fffff             -call 0x462300
    cpu.esp -= 4;
    sub_462300(app, cpu);
    if (cpu.terminate) return;
    // 004713bd  98                     -cwde 
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.ax));
    // 004713be  66c70445a81151001600   -mov word ptr [eax*2 + 0x5111a8], 0x16
    app->getMemory<x86::reg16>(x86::reg32(5312936) /* 0x5111a8 */ + cpu.eax * 2) = 22 /*0x16*/;
    // 004713c8  a128554d00             -mov eax, dword ptr [0x4d5528]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5068072) /* 0x4d5528 */);
    // 004713cd  e8fe6f0100             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 004713d2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004713d3  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4713e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004713e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004713e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004713e2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004713e3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004713e4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004713e5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004713e6  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004713e9  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004713eb  8b15d8ff5000           -mov edx, dword ptr [0x50ffd8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5308376) /* 0x50ffd8 */);
    // 004713f1  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004713f3  740e                   -je 0x471403
    if (cpu.flags.zf)
    {
        goto L_0x00471403;
    }
    // 004713f5  83fa01                 +cmp edx, 1
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
    // 004713f8  7409                   -je 0x471403
    if (cpu.flags.zf)
    {
        goto L_0x00471403;
    }
    // 004713fa  833de4ff500001         +cmp dword ptr [0x50ffe4], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5308388) /* 0x50ffe4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00471401  7e0c                   -jle 0x47140f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047140f;
    }
L_0x00471403:
    // 00471403  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00471405  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00471408  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471409  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047140a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047140b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047140c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047140d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047140e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047140f:
    // 0047140f  a1c4155600             -mov eax, dword ptr [0x5615c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5641668) /* 0x5615c4 */);
    // 00471414  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00471416  e885f00000             -call 0x4804a0
    cpu.esp -= 4;
    sub_4804a0(app, cpu);
    if (cpu.terminate) return;
    // 0047141b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047141d  81e1ffff0000           -and ecx, 0xffff
    cpu.ecx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00471423  81f9ff000000           +cmp ecx, 0xff
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00471429  7d09                   -jge 0x471434
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00471434;
    }
    // 0047142b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047142d  e860350100             -call 0x484992
    cpu.esp -= 4;
    sub_484992(app, cpu);
    if (cpu.terminate) return;
    // 00471432  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x00471434:
    // 00471434  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00471436  0f84ac000000           -je 0x4714e8
    if (cpu.flags.zf)
    {
        goto L_0x004714e8;
    }
    // 0047143c  3b0d44ed5300           +cmp ecx, dword ptr [0x53ed44]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5500228) /* 0x53ed44 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00471442  0f8494000000           -je 0x4714dc
    if (cpu.flags.zf)
    {
        goto L_0x004714dc;
    }
L_0x00471448:
    // 00471448  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0047144d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047144f  e83ce1faff             -call 0x41f590
    cpu.esp -= 4;
    sub_41f590(app, cpu);
    if (cpu.terminate) return;
    // 00471454  3b0d44ed5300           +cmp ecx, dword ptr [0x53ed44]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5500228) /* 0x53ed44 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047145a  0f849a000000           -je 0x4714fa
    if (cpu.flags.zf)
    {
        goto L_0x004714fa;
    }
    // 00471460  83c60f                 -add esi, 0xf
    (cpu.esi) += x86::reg32(x86::sreg32(15 /*0xf*/));
L_0x00471463:
    // 00471463  893540ed5300           -mov dword ptr [0x53ed40], esi
    app->getMemory<x86::reg32>(x86::reg32(5500224) /* 0x53ed40 */) = cpu.esi;
    // 00471469  890d44ed5300           -mov dword ptr [0x53ed44], ecx
    app->getMemory<x86::reg32>(x86::reg32(5500228) /* 0x53ed44 */) = cpu.ecx;
L_0x0047146f:
    // 0047146f  66833dc811510000       +cmp word ptr [0x5111c8], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5312968) /* 0x5111c8 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00471477  0f8499010000           -je 0x471616
    if (cpu.flags.zf)
    {
        goto L_0x00471616;
    }
    // 0047147d  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00471482  3b0d34005100           +cmp ecx, dword ptr [0x510034]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5308468) /* 0x510034 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00471488  0f8dce000000           -jge 0x47155c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047155c;
    }
    // 0047148e  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
L_0x00471493:
    // 00471493  833d30ed530000         +cmp dword ptr [0x53ed30], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5500208) /* 0x53ed30 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047149a  7466                   -je 0x471502
    if (cpu.flags.zf)
    {
        goto L_0x00471502;
    }
L_0x0047149c:
    // 0047149c  ba12000000             -mov edx, 0x12
    cpu.edx = 18 /*0x12*/;
    // 004714a1  b8000a0000             -mov eax, 0xa00
    cpu.eax = 2560 /*0xa00*/;
    // 004714a6  e89509ffff             -call 0x461e40
    cpu.esp -= 4;
    sub_461e40(app, cpu);
    if (cpu.terminate) return;
    // 004714ab  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004714ad  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004714b2  892d9c744d00           -mov dword ptr [0x4d749c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5076124) /* 0x4d749c */) = cpu.ebp;
    // 004714b8  892d30ed5300           -mov dword ptr [0x53ed30], ebp
    app->getMemory<x86::reg32>(x86::reg32(5500208) /* 0x53ed30 */) = cpu.ebp;
    // 004714be  e8bde0faff             -call 0x41f580
    cpu.esp -= 4;
    sub_41f580(app, cpu);
    if (cpu.terminate) return;
    // 004714c3  b8000a0000             -mov eax, 0xa00
    cpu.eax = 2560 /*0xa00*/;
    // 004714c8  e87309ffff             -call 0x461e40
    cpu.esp -= 4;
    sub_461e40(app, cpu);
    if (cpu.terminate) return;
    // 004714cd  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004714d2  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004714d5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004714d6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004714d7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004714d8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004714d9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004714da  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004714db  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004714dc:
    // 004714dc  3b3540ed5300           +cmp esi, dword ptr [0x53ed40]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5500224) /* 0x53ed40 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004714e2  0f8f60ffffff           -jg 0x471448
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00471448;
    }
L_0x004714e8:
    // 004714e8  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004714ea  890d44ed5300           -mov dword ptr [0x53ed44], ecx
    app->getMemory<x86::reg32>(x86::reg32(5500228) /* 0x53ed44 */) = cpu.ecx;
    // 004714f0  a340ed5300             -mov dword ptr [0x53ed40], eax
    app->getMemory<x86::reg32>(x86::reg32(5500224) /* 0x53ed40 */) = cpu.eax;
    // 004714f5  e975ffffff             -jmp 0x47146f
    goto L_0x0047146f;
L_0x004714fa:
    // 004714fa  83c605                 +add esi, 5
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004714fd  e961ffffff             -jmp 0x471463
    goto L_0x00471463;
L_0x00471502:
    // 00471502  668b82a8115100         -mov ax, word ptr [edx + 0x5111a8]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(5312936) /* 0x5111a8 */);
    // 00471509  6685c0                 +test ax, ax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & cpu.ax));
    // 0047150c  763d                   -jbe 0x47154b
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0047154b;
    }
    // 0047150e  663d1600               +cmp ax, 0x16
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(22 /*0x16*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00471512  7569                   -jne 0x47157d
    if (!cpu.flags.zf)
    {
        goto L_0x0047157d;
    }
    // 00471514  833dd8ff500004         +cmp dword ptr [0x50ffd8], 4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5308376) /* 0x50ffd8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047151b  7559                   -jne 0x471576
    if (!cpu.flags.zf)
    {
        goto L_0x00471576;
    }
    // 0047151d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047151f  e8fcb30000             -call 0x47c920
    cpu.esp -= 4;
    sub_47c920(app, cpu);
    if (cpu.terminate) return;
L_0x00471524:
    // 00471524  a128554d00             -mov eax, dword ptr [0x4d5528]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5068072) /* 0x4d5528 */);
    // 00471529  e88a6e0100             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 0047152e  6683baa811510016       +cmp word ptr [edx + 0x5111a8], 0x16
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(5312936) /* 0x5111a8 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(22 /*0x16*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00471536  7509                   -jne 0x471541
    if (!cpu.flags.zf)
    {
        goto L_0x00471541;
    }
    // 00471538  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0047153a  6689baa8115100         -mov word ptr [edx + 0x5111a8], di
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(5312936) /* 0x5111a8 */) = cpu.di;
L_0x00471541:
    // 00471541  a128554d00             -mov eax, dword ptr [0x4d5528]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5068072) /* 0x4d5528 */);
    // 00471546  e8856e0100             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
L_0x0047154b:
    // 0047154b  a134005100             -mov eax, dword ptr [0x510034]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5308468) /* 0x510034 */);
    // 00471550  41                     -inc ecx
    (cpu.ecx)++;
    // 00471551  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00471554  39c1                   +cmp ecx, eax
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
    // 00471556  0f8c37ffffff           -jl 0x471493
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00471493;
    }
L_0x0047155c:
    // 0047155c  83fb02                 +cmp ebx, 2
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
    // 0047155f  733b                   -jae 0x47159c
    if (!cpu.flags.cf)
    {
        goto L_0x0047159c;
    }
    // 00471561  83fb01                 +cmp ebx, 1
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
    // 00471564  0f8432ffffff           -je 0x47149c
    if (cpu.flags.zf)
    {
        goto L_0x0047149c;
    }
L_0x0047156a:
    // 0047156a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047156c  83c410                 +add esp, 0x10
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
    // 0047156f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471570  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471571  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471572  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471573  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471574  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471575  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00471576:
    // 00471576  bb03000000             -mov ebx, 3
    cpu.ebx = 3 /*0x3*/;
    // 0047157b  eba7                   -jmp 0x471524
    goto L_0x00471524;
L_0x0047157d:
    // 0047157d  a128554d00             -mov eax, dword ptr [0x4d5528]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5068072) /* 0x4d5528 */);
    // 00471582  e8316e0100             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 00471587  6683baa811510016       +cmp word ptr [edx + 0x5111a8], 0x16
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(5312936) /* 0x5111a8 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(22 /*0x16*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0047158f  74b0                   -je 0x471541
    if (cpu.flags.zf)
    {
        goto L_0x00471541;
    }
    // 00471591  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 00471593  6689b2a8115100         -mov word ptr [edx + 0x5111a8], si
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(5312936) /* 0x5111a8 */) = cpu.si;
    // 0047159a  eba5                   -jmp 0x471541
    goto L_0x00471541;
L_0x0047159c:
    // 0047159c  7655                   -jbe 0x4715f3
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004715f3;
    }
    // 0047159e  83fb03                 +cmp ebx, 3
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004715a1  75c7                   -jne 0x47156a
    if (!cpu.flags.zf)
    {
        goto L_0x0047156a;
    }
    // 004715a3  8b1510fc5000           -mov edx, dword ptr [0x50fc10]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5307408) /* 0x50fc10 */);
    // 004715a9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004715ab  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004715ad  7e21                   -jle 0x4715d0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004715d0;
    }
    // 004715af  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004715b1:
    // 004715b1  8b8ad8fa5000           -mov ecx, dword ptr [edx + 0x50fad8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5307096) /* 0x50fad8 */);
    // 004715b7  40                     -inc eax
    (cpu.eax)++;
    // 004715b8  c7818002000001000000   -mov dword ptr [ecx + 0x280], 1
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(640) /* 0x280 */) = 1 /*0x1*/;
    // 004715c2  8b0d10fc5000           -mov ecx, dword ptr [0x50fc10]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5307408) /* 0x50fc10 */);
    // 004715c8  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004715cb  39c8                   +cmp eax, ecx
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
    // 004715cd  7ce2                   -jl 0x4715b1
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004715b1;
    }
    // 004715cf  90                     -nop 
    ;
L_0x004715d0:
    // 004715d0  ba16000000             -mov edx, 0x16
    cpu.edx = 22 /*0x16*/;
    // 004715d5  b8000a0000             -mov eax, 0xa00
    cpu.eax = 2560 /*0xa00*/;
    // 004715da  e86108ffff             -call 0x461e40
    cpu.esp -= 4;
    sub_461e40(app, cpu);
    if (cpu.terminate) return;
    // 004715df  e89cdffaff             -call 0x41f580
    cpu.esp -= 4;
    sub_41f580(app, cpu);
    if (cpu.terminate) return;
    // 004715e4  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 004715e9  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004715ec  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004715ed  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004715ee  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004715ef  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004715f0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004715f1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004715f2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004715f3:
    // 004715f3  ba15000000             -mov edx, 0x15
    cpu.edx = 21 /*0x15*/;
    // 004715f8  b8000a0000             -mov eax, 0xa00
    cpu.eax = 2560 /*0xa00*/;
    // 004715fd  e83e08ffff             -call 0x461e40
    cpu.esp -= 4;
    sub_461e40(app, cpu);
    if (cpu.terminate) return;
    // 00471602  e879dffaff             -call 0x41f580
    cpu.esp -= 4;
    sub_41f580(app, cpu);
    if (cpu.terminate) return;
    // 00471607  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0047160c  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0047160f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471610  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471611  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471612  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471613  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471614  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471615  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00471616:
    // 00471616  66a19a115100           -mov ax, word ptr [0x51119a]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5312922) /* 0x51119a */);
    // 0047161c  663d1500               +cmp ax, 0x15
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(21 /*0x15*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00471620  733b                   -jae 0x47165d
    if (!cpu.flags.cf)
    {
        goto L_0x0047165d;
    }
    // 00471622  663d1200               +cmp ax, 0x12
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(18 /*0x12*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00471626  0f848b000000           -je 0x4716b7
    if (cpu.flags.zf)
    {
        goto L_0x004716b7;
    }
L_0x0047162c:
    // 0047162c  83fb01                 +cmp ebx, 1
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
    // 0047162f  0f85bc000000           -jne 0x4716f1
    if (!cpu.flags.zf)
    {
        goto L_0x004716f1;
    }
    // 00471635  b607                   -mov dh, 7
    cpu.dh = 7 /*0x7*/;
    // 00471637  b301                   -mov bl, 1
    cpu.bl = 1 /*0x1*/;
    // 00471639  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047163b  88742408               -mov byte ptr [esp + 8], dh
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.dh;
    // 0047163f  885c2409               -mov byte ptr [esp + 9], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(9) /* 0x9 */) = cpu.bl;
    // 00471643  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 00471648  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047164c  e81f0fffff             -call 0x462570
    cpu.esp -= 4;
    sub_462570(app, cpu);
    if (cpu.terminate) return;
L_0x00471651:
    // 00471651  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00471653  83c410                 +add esp, 0x10
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
    // 00471656  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471657  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471658  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471659  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047165a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047165b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047165c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047165d:
    // 0047165d  7694                   -jbe 0x4715f3
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004715f3;
    }
    // 0047165f  663d1600               +cmp ax, 0x16
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(22 /*0x16*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00471663  75c7                   -jne 0x47162c
    if (!cpu.flags.zf)
    {
        goto L_0x0047162c;
    }
    // 00471665  8b0d10fc5000           -mov ecx, dword ptr [0x50fc10]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5307408) /* 0x50fc10 */);
    // 0047166b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047166d  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047166f  7e23                   -jle 0x471694
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00471694;
    }
    // 00471671  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00471673:
    // 00471673  8b2d10fc5000           -mov ebp, dword ptr [0x50fc10]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5307408) /* 0x50fc10 */);
    // 00471679  8b8ad8fa5000           -mov ecx, dword ptr [edx + 0x50fad8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5307096) /* 0x50fad8 */);
    // 0047167f  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00471682  40                     -inc eax
    (cpu.eax)++;
    // 00471683  c7818002000001000000   -mov dword ptr [ecx + 0x280], 1
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(640) /* 0x280 */) = 1 /*0x1*/;
    // 0047168d  39e8                   +cmp eax, ebp
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
    // 0047168f  7ce2                   -jl 0x471673
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00471673;
    }
    // 00471691  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x00471694:
    // 00471694  ba16000000             -mov edx, 0x16
    cpu.edx = 22 /*0x16*/;
    // 00471699  b8000a0000             -mov eax, 0xa00
    cpu.eax = 2560 /*0xa00*/;
    // 0047169e  e89d07ffff             -call 0x461e40
    cpu.esp -= 4;
    sub_461e40(app, cpu);
    if (cpu.terminate) return;
    // 004716a3  e8d8defaff             -call 0x41f580
    cpu.esp -= 4;
    sub_41f580(app, cpu);
    if (cpu.terminate) return;
    // 004716a8  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 004716ad  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004716b0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004716b1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004716b2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004716b3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004716b4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004716b5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004716b6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004716b7:
    // 004716b7  ba12000000             -mov edx, 0x12
    cpu.edx = 18 /*0x12*/;
    // 004716bc  b8000a0000             -mov eax, 0xa00
    cpu.eax = 2560 /*0xa00*/;
    // 004716c1  e87a07ffff             -call 0x461e40
    cpu.esp -= 4;
    sub_461e40(app, cpu);
    if (cpu.terminate) return;
    // 004716c6  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004716c8  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004716cd  89359c744d00           -mov dword ptr [0x4d749c], esi
    app->getMemory<x86::reg32>(x86::reg32(5076124) /* 0x4d749c */) = cpu.esi;
    // 004716d3  e8a8defaff             -call 0x41f580
    cpu.esp -= 4;
    sub_41f580(app, cpu);
    if (cpu.terminate) return;
    // 004716d8  b8000a0000             -mov eax, 0xa00
    cpu.eax = 2560 /*0xa00*/;
    // 004716dd  e85e07ffff             -call 0x461e40
    cpu.esp -= 4;
    sub_461e40(app, cpu);
    if (cpu.terminate) return;
    // 004716e2  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004716e7  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004716ea  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004716eb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004716ec  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004716ed  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004716ee  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004716ef  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004716f0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004716f1:
    // 004716f1  83fb03                 +cmp ebx, 3
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004716f4  0f8557ffffff           -jne 0x471651
    if (!cpu.flags.zf)
    {
        goto L_0x00471651;
    }
    // 004716fa  b407                   -mov ah, 7
    cpu.ah = 7 /*0x7*/;
    // 004716fc  b203                   -mov dl, 3
    cpu.dl = 3 /*0x3*/;
    // 004716fe  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 00471703  882424                 -mov byte ptr [esp], ah
    app->getMemory<x86::reg8>(cpu.esp) = cpu.ah;
    // 00471706  88542401               -mov byte ptr [esp + 1], dl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */) = cpu.dl;
    // 0047170a  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0047170c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047170e  e85d0effff             -call 0x462570
    cpu.esp -= 4;
    sub_462570(app, cpu);
    if (cpu.terminate) return;
    // 00471713  833dd8ff500004         +cmp dword ptr [0x50ffd8], 4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5308376) /* 0x50ffd8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047171a  0f8531ffffff           -jne 0x471651
    if (!cpu.flags.zf)
    {
        goto L_0x00471651;
    }
    // 00471720  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00471725  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 0047172a  66891dcc115100         -mov word ptr [0x5111cc], bx
    app->getMemory<x86::reg16>(x86::reg32(5312972) /* 0x5111cc */) = cpu.bx;
    // 00471731  66891dca115100         -mov word ptr [0x5111ca], bx
    app->getMemory<x86::reg16>(x86::reg32(5312970) /* 0x5111ca */) = cpu.bx;
    // 00471738  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0047173b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047173c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047173d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047173e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047173f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471740  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471741  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_471750(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00471750  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00471751  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00471752  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00471753  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00471754  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00471757  8b15d8ff5000           -mov edx, dword ptr [0x50ffd8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5308376) /* 0x50ffd8 */);
    // 0047175d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047175f  0f8477000000           -je 0x4717dc
    if (cpu.flags.zf)
    {
        goto L_0x004717dc;
    }
    // 00471765  83fa01                 +cmp edx, 1
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
    // 00471768  0f846e000000           -je 0x4717dc
    if (cpu.flags.zf)
    {
        goto L_0x004717dc;
    }
    // 0047176e  833de4ff500001         +cmp dword ptr [0x50ffe4], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5308388) /* 0x50ffe4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00471775  7f65                   -jg 0x4717dc
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004717dc;
    }
    // 00471777  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00471779  7456                   -je 0x4717d1
    if (cpu.flags.zf)
    {
        goto L_0x004717d1;
    }
    // 0047177b  8b3534ed5300           -mov esi, dword ptr [0x53ed34]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5500212) /* 0x53ed34 */);
    // 00471781  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00471783  754c                   -jne 0x4717d1
    if (!cpu.flags.zf)
    {
        goto L_0x004717d1;
    }
    // 00471785  833d90744d0000         +cmp dword ptr [0x4d7490], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5076112) /* 0x4d7490 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047178c  7543                   -jne 0x4717d1
    if (!cpu.flags.zf)
    {
        goto L_0x004717d1;
    }
    // 0047178e  8b1538ed5300           -mov edx, dword ptr [0x53ed38]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5500216) /* 0x53ed38 */);
    // 00471794  83c220                 -add edx, 0x20
    (cpu.edx) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00471797  e8d4030000             -call 0x471b70
    cpu.esp -= 4;
    sub_471b70(app, cpu);
    if (cpu.terminate) return;
    // 0047179c  39c2                   +cmp edx, eax
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
    // 0047179e  7d31                   -jge 0x4717d1
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004717d1;
    }
    // 004717a0  b407                   -mov ah, 7
    cpu.ah = 7 /*0x7*/;
    // 004717a2  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 004717a4  8b2ddcff5000           -mov ebp, dword ptr [0x50ffdc]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5308380) /* 0x50ffdc */);
    // 004717aa  88542401               -mov byte ptr [esp + 1], dl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */) = cpu.dl;
    // 004717ae  882424                 -mov byte ptr [esp], ah
    app->getMemory<x86::reg8>(cpu.esp) = cpu.ah;
    // 004717b1  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004717b3  742f                   -je 0x4717e4
    if (cpu.flags.zf)
    {
        goto L_0x004717e4;
    }
    // 004717b5  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 004717ba  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004717bc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004717be  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 004717c2  e8a90dffff             -call 0x462570
    cpu.esp -= 4;
    sub_462570(app, cpu);
    if (cpu.terminate) return;
    // 004717c7  c70590744d0001000000   -mov dword ptr [0x4d7490], 1
    app->getMemory<x86::reg32>(x86::reg32(5076112) /* 0x4d7490 */) = 1 /*0x1*/;
L_0x004717d1:
    // 004717d1  833d34ed530000         +cmp dword ptr [0x53ed34], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5500212) /* 0x53ed34 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004717d8  753c                   -jne 0x471816
    if (!cpu.flags.zf)
    {
        goto L_0x00471816;
    }
L_0x004717da:
    // 004717da  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004717dc:
    // 004717dc  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004717df  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004717e0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004717e1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004717e2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004717e3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004717e4:
    // 004717e4  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 004717e9  a13ced5300             -mov eax, dword ptr [0x53ed3c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5500220) /* 0x53ed3c */);
    // 004717ee  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004717f0  e8c36b0100             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 004717f5  e886030000             -call 0x471b80
    cpu.esp -= 4;
    sub_471b80(app, cpu);
    if (cpu.terminate) return;
    // 004717fa  a334ed5300             -mov dword ptr [0x53ed34], eax
    app->getMemory<x86::reg32>(x86::reg32(5500212) /* 0x53ed34 */) = cpu.eax;
    // 004717ff  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00471803  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00471805  e8660dffff             -call 0x462570
    cpu.esp -= 4;
    sub_462570(app, cpu);
    if (cpu.terminate) return;
    // 0047180a  a13ced5300             -mov eax, dword ptr [0x53ed3c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5500220) /* 0x53ed3c */);
    // 0047180f  e8bc6b0100             -call 0x4883d0
    cpu.esp -= 4;
    sub_4883d0(app, cpu);
    if (cpu.terminate) return;
    // 00471814  ebbb                   -jmp 0x4717d1
    goto L_0x004717d1;
L_0x00471816:
    // 00471816  e855030000             -call 0x471b70
    cpu.esp -= 4;
    sub_471b70(app, cpu);
    if (cpu.terminate) return;
    // 0047181b  3b0534ed5300           +cmp eax, dword ptr [0x53ed34]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5500212) /* 0x53ed34 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00471821  75b7                   -jne 0x4717da
    if (!cpu.flags.zf)
    {
        goto L_0x004717da;
    }
    // 00471823  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00471824  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 00471829  ba11000000             -mov edx, 0x11
    cpu.edx = 17 /*0x11*/;
    // 0047182e  b8000f0000             -mov eax, 0xf00
    cpu.eax = 3840 /*0xf00*/;
    // 00471833  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00471835  893598744d00           -mov dword ptr [0x4d7498], esi
    app->getMemory<x86::reg32>(x86::reg32(5076120) /* 0x4d7498 */) = cpu.esi;
    // 0047183b  e80006ffff             -call 0x461e40
    cpu.esp -= 4;
    sub_461e40(app, cpu);
    if (cpu.terminate) return;
    // 00471840  a134ed5300             -mov eax, dword ptr [0x53ed34]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5500212) /* 0x53ed34 */);
    // 00471845  893d90744d00           -mov dword ptr [0x4d7490], edi
    app->getMemory<x86::reg32>(x86::reg32(5076112) /* 0x4d7490 */) = cpu.edi;
    // 0047184b  893d30ed5300           -mov dword ptr [0x53ed30], edi
    app->getMemory<x86::reg32>(x86::reg32(5500208) /* 0x53ed30 */) = cpu.edi;
    // 00471851  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00471853  a338ed5300             -mov dword ptr [0x53ed38], eax
    app->getMemory<x86::reg32>(x86::reg32(5500216) /* 0x53ed38 */) = cpu.eax;
    // 00471858  893d34ed5300           -mov dword ptr [0x53ed34], edi
    app->getMemory<x86::reg32>(x86::reg32(5500212) /* 0x53ed34 */) = cpu.edi;
    // 0047185e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047185f:
    // 0047185f  e8683a0100             -call 0x4852cc
    cpu.esp -= 4;
    sub_4852cc(app, cpu);
    if (cpu.terminate) return;
    // 00471864  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00471866  7409                   -je 0x471871
    if (cpu.flags.zf)
    {
        goto L_0x00471871;
    }
    // 00471868  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047186a  e8b10a0100             -call 0x482320
    cpu.esp -= 4;
    sub_482320(app, cpu);
    if (cpu.terminate) return;
    // 0047186f  ebee                   -jmp 0x47185f
    goto L_0x0047185f;
L_0x00471871:
    // 00471871  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00471876  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00471879  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047187a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047187b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047187c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047187d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_471880(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00471880  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00471881  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 00471886  b8003c0000             -mov eax, 0x3c00
    cpu.eax = 15360 /*0x3c00*/;
    // 0047188b  e8b005ffff             -call 0x461e40
    cpu.esp -= 4;
    sub_461e40(app, cpu);
    if (cpu.terminate) return;
    // 00471890  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00471892  a13ced5300             -mov eax, dword ptr [0x53ed3c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5500220) /* 0x53ed3c */);
    // 00471897  89158c744d00           -mov dword ptr [0x4d748c], edx
    app->getMemory<x86::reg32>(x86::reg32(5076108) /* 0x4d748c */) = cpu.edx;
    // 0047189d  e8426b0100             -call 0x4883e4
    cpu.esp -= 4;
    sub_4883e4(app, cpu);
    if (cpu.terminate) return;
    // 004718a2  66833dca11510000       +cmp word ptr [0x5111ca], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(x86::reg32(5312970) /* 0x5111ca */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004718aa  7502                   -jne 0x4718ae
    if (!cpu.flags.zf)
    {
        goto L_0x004718ae;
    }
    // 004718ac  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004718ad  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004718ae:
    // 004718ae  e8716e0100             -call 0x488724
    cpu.esp -= 4;
    sub_488724(app, cpu);
    if (cpu.terminate) return;
    // 004718b3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004718b4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4718c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004718c0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004718c1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004718c2  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
    // 004718c7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004718c9  890d38ed5300           -mov dword ptr [0x53ed38], ecx
    app->getMemory<x86::reg32>(x86::reg32(5500216) /* 0x53ed38 */) = cpu.ecx;
    // 004718cf  891534ed5300           -mov dword ptr [0x53ed34], edx
    app->getMemory<x86::reg32>(x86::reg32(5500212) /* 0x53ed34 */) = cpu.edx;
    // 004718d5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004718d6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004718d7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4718e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004718e0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004718e1  e8826a0100             -call 0x488368
    cpu.esp -= 4;
    sub_488368(app, cpu);
    if (cpu.terminate) return;
    // 004718e6  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004718eb  a33ced5300             -mov dword ptr [0x53ed3c], eax
    app->getMemory<x86::reg32>(x86::reg32(5500220) /* 0x53ed3c */) = cpu.eax;
    // 004718f0  89158c744d00           -mov dword ptr [0x4d748c], edx
    app->getMemory<x86::reg32>(x86::reg32(5076108) /* 0x4d748c */) = cpu.edx;
    // 004718f6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004718f7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_471914(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00471914  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00471915  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00471916  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00471917  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00471918  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00471919  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047191a  8b15d8ff5000           -mov edx, dword ptr [0x50ffd8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5308376) /* 0x50ffd8 */);
    // 00471920  83fa04                 +cmp edx, 4
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
    // 00471923  0f8710010000           -ja 0x471a39
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00471a39;
    }
    // 00471929  ff249500194700         -jmp dword ptr [edx*4 + 0x471900]
    cpu.ip = app->getMemory<x86::reg32>(4659456 + cpu.edx * 4); goto dynamic_jump;
  case 0x00471930:
L_0x00471930:
    // 00471930  8b3d9c015400           -mov edi, dword ptr [0x54019c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5505436) /* 0x54019c */);
    // 00471936  a174015400             -mov eax, dword ptr [0x540174]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5505396) /* 0x540174 */);
    // 0047193b  8b2d78015400           -mov ebp, dword ptr [0x540178]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5505400) /* 0x540178 */);
    // 00471941  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 00471943  39e8                   +cmp eax, ebp
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
    // 00471945  0f8fe5000000           -jg 0x471a30
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00471a30;
    }
L_0x0047194b:
    // 0047194b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00471950  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471951  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471952  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471953  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471954  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471955  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471956  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00471957:
    // 00471957  833ddcff500000         +cmp dword ptr [0x50ffdc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5308380) /* 0x50ffdc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047195e  7532                   -jne 0x471992
    if (!cpu.flags.zf)
    {
        goto L_0x00471992;
    }
    // 00471960  833d9c744d0000         +cmp dword ptr [0x4d749c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5076124) /* 0x4d749c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00471967  7404                   -je 0x47196d
    if (cpu.flags.zf)
    {
        goto L_0x0047196d;
    }
    // 00471969  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047196b  75de                   -jne 0x47194b
    if (!cpu.flags.zf)
    {
        goto L_0x0047194b;
    }
L_0x0047196d:
    // 0047196d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047196f  750a                   -jne 0x47197b
    if (!cpu.flags.zf)
    {
        goto L_0x0047197b;
    }
    // 00471971  a0a0015400             -mov al, byte ptr [0x5401a0]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5505440) /* 0x5401a0 */);
    // 00471976  83f810                 +cmp eax, 0x10
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
    // 00471979  7f20                   -jg 0x47199b
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0047199b;
    }
L_0x0047197b:
    // 0047197b  8b3d9c015400           -mov edi, dword ptr [0x54019c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5505436) /* 0x54019c */);
    // 00471981  a174015400             -mov eax, dword ptr [0x540174]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5505396) /* 0x540174 */);
    // 00471986  8b2d78015400           -mov ebp, dword ptr [0x540178]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5505400) /* 0x540178 */);
    // 0047198c  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 0047198e  39e8                   +cmp eax, ebp
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
    // 00471990  7eb9                   -jle 0x47194b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047194b;
    }
L_0x00471992:
    // 00471992  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00471994  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471995  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471996  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471997  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471998  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471999  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047199a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047199b:
    // 0047199b  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 0047199d  8825a0015400           -mov byte ptr [0x5401a0], ah
    app->getMemory<x86::reg8>(x86::reg32(5505440) /* 0x5401a0 */) = cpu.ah;
    // 004719a3  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004719a8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004719a9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004719aa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004719ab  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004719ac  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004719ad  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004719ae  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004719af:
    // 004719af  3b05dcff5000           +cmp eax, dword ptr [0x50ffdc]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5308380) /* 0x50ffdc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004719b5  75db                   -jne 0x471992
    if (!cpu.flags.zf)
    {
        goto L_0x00471992;
    }
    // 004719b7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004719b9  8a15a0015400           -mov dl, byte ptr [0x5401a0]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5505440) /* 0x5401a0 */);
    // 004719bf  83fa01                 +cmp edx, 1
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
    // 004719c2  7f50                   -jg 0x471a14
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00471a14;
    }
    // 004719c4  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 004719cb  8b0d98015400           -mov ecx, dword ptr [0x540198]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5505432) /* 0x540198 */);
    // 004719d1  a174015400             -mov eax, dword ptr [0x540174]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5505396) /* 0x540174 */);
    // 004719d6  8b9a78015400           -mov ebx, dword ptr [edx + 0x540178]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5505400) /* 0x540178 */);
    // 004719dc  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004719de  39d8                   +cmp eax, ebx
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
    // 004719e0  0f8e65ffffff           -jle 0x47194b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047194b;
    }
    // 004719e6  a17c015400             -mov eax, dword ptr [0x54017c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5505404) /* 0x54017c */);
    // 004719eb  8b1578015400           -mov edx, dword ptr [0x540178]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5505400) /* 0x540178 */);
    // 004719f1  39c2                   +cmp edx, eax
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
    // 004719f3  7e02                   -jle 0x4719f7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004719f7;
    }
    // 004719f5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x004719f7:
    // 004719f7  8b359c015400           -mov esi, dword ptr [0x54019c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5505436) /* 0x54019c */);
    // 004719fd  a174015400             -mov eax, dword ptr [0x540174]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5505396) /* 0x540174 */);
    // 00471a02  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00471a04  39c2                   +cmp edx, eax
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
    // 00471a06  7c8a                   -jl 0x471992
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00471992;
    }
    // 00471a08  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00471a0d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471a0e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471a0f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471a10  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471a11  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471a12  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471a13  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00471a14:
    // 00471a14  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 00471a16  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00471a1b  8815a0015400           -mov byte ptr [0x5401a0], dl
    app->getMemory<x86::reg8>(x86::reg32(5505440) /* 0x5401a0 */) = cpu.dl;
    // 00471a21  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471a22  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471a23  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471a24  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471a25  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471a26  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471a27  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00471a28:
    // 00471a28  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00471a2a  0f8400ffffff           -je 0x471930
    if (cpu.flags.zf)
    {
        goto L_0x00471930;
    }
L_0x00471a30:
    // 00471a30  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00471a32  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471a33  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471a34  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471a35  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471a36  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471a37  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471a38  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00471a39:
    // 00471a39  baf4bf4c00             -mov edx, 0x4cbff4
    cpu.edx = 5029876 /*0x4cbff4*/;
    // 00471a3e  b9a1030000             -mov ecx, 0x3a1
    cpu.ecx = 929 /*0x3a1*/;
    // 00471a43  6818c04c00             -push 0x4cc018
    app->getMemory<x86::reg32>(cpu.esp-4) = 5029912 /*0x4cc018*/;
    cpu.esp -= 4;
    // 00471a48  8915f48f4d00           -mov dword ptr [0x4d8ff4], edx
    app->getMemory<x86::reg32>(x86::reg32(5083124) /* 0x4d8ff4 */) = cpu.edx;
    // 00471a4e  890df88f4d00           -mov dword ptr [0x4d8ff8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5083128) /* 0x4d8ff8 */) = cpu.ecx;
    // 00471a54  e8070b0100             -call 0x482560
    cpu.esp -= 4;
    sub_482560(app, cpu);
    if (cpu.terminate) return;
    // 00471a59  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00471a5c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00471a5e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471a5f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471a60  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471a61  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471a62  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471a63  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471a64  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_471a84(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00471a84  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00471a85  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00471a86  8b159c015400           -mov edx, dword ptr [0x54019c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5505436) /* 0x54019c */);
    // 00471a8c  a1d8ff5000             -mov eax, dword ptr [0x50ffd8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5308376) /* 0x50ffd8 */);
    // 00471a91  83f804                 +cmp eax, 4
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
    // 00471a94  770c                   -ja 0x471aa2
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00471aa2;
    }
    // 00471a96  ff2485701a4700         -jmp dword ptr [eax*4 + 0x471a70]
    cpu.ip = app->getMemory<x86::reg32>(4659824 + cpu.eax * 4); goto dynamic_jump;
  case 0x00471a9d:
    // 00471a9d  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
L_0x00471aa2:
    // 00471aa2  89159c015400           -mov dword ptr [0x54019c], edx
    app->getMemory<x86::reg32>(x86::reg32(5505436) /* 0x54019c */) = cpu.edx;
    // 00471aa8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471aa9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471aaa  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00471aab:
    // 00471aab  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00471aac  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00471aad  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 00471ab2  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 00471ab7  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 00471abc  890d70ed5300           -mov dword ptr [0x53ed70], ecx
    app->getMemory<x86::reg32>(x86::reg32(5500272) /* 0x53ed70 */) = cpu.ecx;
    // 00471ac2  891d98015400           -mov dword ptr [0x540198], ebx
    app->getMemory<x86::reg32>(x86::reg32(5505432) /* 0x540198 */) = cpu.ebx;
    // 00471ac8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471ac9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471aca  89159c015400           -mov dword ptr [0x54019c], edx
    app->getMemory<x86::reg32>(x86::reg32(5505436) /* 0x54019c */) = cpu.edx;
    // 00471ad0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471ad1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471ad2  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00471ad3:
    // 00471ad3  bf18000000             -mov edi, 0x18
    cpu.edi = 24 /*0x18*/;
    // 00471ad8  ba08000000             -mov edx, 8
    cpu.edx = 8 /*0x8*/;
    // 00471add  893d98015400           -mov dword ptr [0x540198], edi
    app->getMemory<x86::reg32>(x86::reg32(5505432) /* 0x540198 */) = cpu.edi;
    // 00471ae3  89159c015400           -mov dword ptr [0x54019c], edx
    app->getMemory<x86::reg32>(x86::reg32(5505436) /* 0x54019c */) = cpu.edx;
    // 00471ae9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471aea  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471aeb  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00471aec:
    // 00471aec  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 00471af1  891598015400           -mov dword ptr [0x540198], edx
    app->getMemory<x86::reg32>(x86::reg32(5505432) /* 0x540198 */) = cpu.edx;
    // 00471af7  89159c015400           -mov dword ptr [0x54019c], edx
    app->getMemory<x86::reg32>(x86::reg32(5505436) /* 0x54019c */) = cpu.edx;
    // 00471afd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471afe  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471aff  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::sub_471b00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00471b00  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00471b01  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00471b03  8a15a0015400           -mov dl, byte ptr [0x5401a0]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5505440) /* 0x5401a0 */);
    // 00471b09  39d0                   +cmp eax, edx
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
    // 00471b0b  7e07                   -jle 0x471b14
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00471b14;
    }
    // 00471b0d  a2a0015400             -mov byte ptr [0x5401a0], al
    app->getMemory<x86::reg8>(x86::reg32(5505440) /* 0x5401a0 */) = cpu.al;
    // 00471b12  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471b13  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00471b14:
    // 00471b14  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00471b16  a2a0015400             -mov byte ptr [0x5401a0], al
    app->getMemory<x86::reg8>(x86::reg32(5505440) /* 0x5401a0 */) = cpu.al;
    // 00471b1b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471b1c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_471b20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00471b20  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00471b21  833dd8ff500004         +cmp dword ptr [0x50ffd8], 4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5308376) /* 0x50ffd8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00471b28  7424                   -je 0x471b4e
    if (cpu.flags.zf)
    {
        goto L_0x00471b4e;
    }
    // 00471b2a  833ddcff500000         +cmp dword ptr [0x50ffdc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5308380) /* 0x50ffdc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00471b31  752a                   -jne 0x471b5d
    if (!cpu.flags.zf)
    {
        goto L_0x00471b5d;
    }
    // 00471b33  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00471b38:
    // 00471b38  8b15dcff5000           -mov edx, dword ptr [0x50ffdc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5308380) /* 0x50ffdc */);
    // 00471b3e  8a048578015400         -mov al, byte ptr [eax*4 + 0x540178]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5505400) /* 0x540178 */ + cpu.eax * 4);
    // 00471b45  2a049578015400         -sub al, byte ptr [edx*4 + 0x540178]
    (cpu.al) -= x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(x86::reg32(5505400) /* 0x540178 */ + cpu.edx * 4)));
    // 00471b4c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471b4d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00471b4e:
    // 00471b4e  8a1574015400           -mov dl, byte ptr [0x540174]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5505396) /* 0x540174 */);
    // 00471b54  a078015400             -mov al, byte ptr [0x540178]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5505400) /* 0x540178 */);
    // 00471b59  28d0                   -sub al, dl
    (cpu.al) -= x86::reg8(x86::sreg8(cpu.dl));
    // 00471b5b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471b5c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00471b5d:
    // 00471b5d  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00471b5f  ebd7                   -jmp 0x471b38
    goto L_0x00471b38;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_471b70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00471b70  a174015400             -mov eax, dword ptr [0x540174]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5505396) /* 0x540174 */);
    // 00471b75  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_471b80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00471b80  a178015400             -mov eax, dword ptr [0x540178]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5505400) /* 0x540178 */);
    // 00471b85  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00471b88  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_471b90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00471b90  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00471b91  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00471b92  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00471b93  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00471b94  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00471b95  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00471b96  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00471b99  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00471b9b  a178015400             -mov eax, dword ptr [0x540178]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5505400) /* 0x540178 */);
    // 00471ba0  48                     -dec eax
    (cpu.eax)--;
    // 00471ba1  8b1534005100           -mov edx, dword ptr [0x510034]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5308468) /* 0x510034 */);
    // 00471ba7  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 00471baa  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00471bac  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00471bb0  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00471bb2  0f8ecf000000           -jle 0x471c87
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00471c87;
    }
    // 00471bb8  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00471bbc  4a                     -dec edx
    (cpu.edx)--;
    // 00471bbd  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00471bc0  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00471bc3  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00471bc7  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00471bcb  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00471bcf  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00471bd1  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00471bd3  81c274ed5300           -add edx, 0x53ed74
    (cpu.edx) += x86::reg32(x86::sreg32(5500276 /*0x53ed74*/));
L_0x00471bd9:
    // 00471bd9  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00471bdd  80b874fd530000         +cmp byte ptr [eax + 0x53fd74], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5504372) /* 0x53fd74 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00471be4  7556                   -jne 0x471c3c
    if (!cpu.flags.zf)
    {
        goto L_0x00471c3c;
    }
    // 00471be6  ff049d78015400         -inc dword ptr [ebx*4 + 0x540178]
    (app->getMemory<x86::reg32>(x86::reg32(5505400) /* 0x540178 */ + cpu.ebx * 4))++;
    // 00471bed  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00471bf1  b501                   -mov ch, 1
    cpu.ch = 1 /*0x1*/;
    // 00471bf3  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00471bf7  88a874fd5300           -mov byte ptr [eax + 0x53fd74], ch
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5504372) /* 0x53fd74 */) = cpu.ch;
    // 00471bfd  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 00471c02  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00471c04  0f848d000000           -je 0x471c97
    if (cpu.flags.zf)
    {
        goto L_0x00471c97;
    }
    // 00471c0a  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
L_0x00471c0d:
    // 00471c0d  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 00471c10  8d348500000000         -lea esi, [eax*4]
    cpu.esi = x86::reg32(cpu.eax * 4);
    // 00471c17  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00471c19  c1e009                 -shl eax, 9
    cpu.eax <<= 9 /*0x9*/ % 32;
    // 00471c1c  0574ed5300             -add eax, 0x53ed74
    (cpu.eax) += x86::reg32(x86::sreg32(5500276 /*0x53ed74*/));
    // 00471c21  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00471c23  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00471c25  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00471c26  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00471c28  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00471c2b  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00471c2d  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00471c2f  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00471c32  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00471c34  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471c35  80a577ed5300bc         -and byte ptr [ebp + 0x53ed77], 0xbc
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(5500279) /* 0x53ed77 */) &= x86::reg8(x86::sreg8(188 /*0xbc*/));
L_0x00471c3c:
    // 00471c3c  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 00471c41  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00471c45  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00471c47  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00471c48  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00471c4a  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00471c4d  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00471c4f  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00471c51  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00471c54  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00471c56  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471c57  81c500020000           -add ebp, 0x200
    (cpu.ebp) += x86::reg32(x86::sreg32(512 /*0x200*/));
    // 00471c5d  43                     -inc ebx
    (cpu.ebx)++;
    // 00471c5e  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00471c62  8d7704                 -lea esi, [edi + 4]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00471c65  81c200020000           -add edx, 0x200
    (cpu.edx) += x86::reg32(x86::sreg32(512 /*0x200*/));
    // 00471c6b  8b3d34005100           -mov edi, dword ptr [0x510034]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5308468) /* 0x510034 */);
    // 00471c71  81c180000000           -add ecx, 0x80
    (cpu.ecx) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 00471c77  89742408               -mov dword ptr [esp + 8], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 00471c7b  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 00471c7f  39fb                   +cmp ebx, edi
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00471c81  0f8c52ffffff           -jl 0x471bd9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00471bd9;
    }
L_0x00471c87:
    // 00471c87  ff0594744d00           -inc dword ptr [0x4d7494]
    (app->getMemory<x86::reg32>(x86::reg32(5076116) /* 0x4d7494 */))++;
    // 00471c8d  83c410                 +add esp, 0x10
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
    // 00471c90  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471c91  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471c92  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471c93  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471c94  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471c95  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471c96  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00471c97:
    // 00471c97  b87f000000             -mov eax, 0x7f
    cpu.eax = 127 /*0x7f*/;
    // 00471c9c  e96cffffff             -jmp 0x471c0d
    goto L_0x00471c0d;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
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
    // 00471cb3  be50ed5300             -mov esi, 0x53ed50
    cpu.esi = 5500240 /*0x53ed50*/;
    // 00471cb8  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 00471cbd  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00471cc0  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00471cc2  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00471cc4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00471cc5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00471cc7  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00471cca  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00471ccc  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00471cce  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00471cd1  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00471cd3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471cd4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471cd5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471cd6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471cd7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_471ce0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00471ce0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00471ce1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00471ce2  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00471ce5  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 00471ce8  8b15e4ff5000           -mov edx, dword ptr [0x50ffe4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5308388) /* 0x50ffe4 */);
    // 00471cee  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00471cf1  83fa01                 +cmp edx, 1
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
    // 00471cf4  0f8f88000000           -jg 0x471d82
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00471d82;
    }
    // 00471cfa  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00471cfb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00471cfc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00471cfd  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00471cfe  8b0d34005100           -mov ecx, dword ptr [0x510034]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5308468) /* 0x510034 */);
    // 00471d04  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00471d06  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00471d08  7e42                   -jle 0x471d4c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00471d4c;
    }
    // 00471d0a  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 00471d11  bb50ed5300             -mov ebx, 0x53ed50
    cpu.ebx = 5500240 /*0x53ed50*/;
    // 00471d16  81c274ed5300           -add edx, 0x53ed74
    (cpu.edx) += x86::reg32(x86::sreg32(5500276 /*0x53ed74*/));
L_0x00471d1c:
    // 00471d1c  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 00471d21  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00471d23  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00471d25  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00471d26  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00471d28  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00471d2b  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00471d2d  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00471d2f  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00471d32  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00471d34  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471d35  45                     -inc ebp
    (cpu.ebp)++;
    // 00471d36  8b3534005100           -mov esi, dword ptr [0x510034]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5308468) /* 0x510034 */);
    // 00471d3c  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00471d3f  81c200020000           -add edx, 0x200
    (cpu.edx) += x86::reg32(x86::sreg32(512 /*0x200*/));
    // 00471d45  39f5                   +cmp ebp, esi
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00471d47  7cd3                   -jl 0x471d1c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00471d1c;
    }
    // 00471d49  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x00471d4c:
    // 00471d4c  8b3d34005100           -mov edi, dword ptr [0x510034]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5308468) /* 0x510034 */);
    // 00471d52  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00471d54  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00471d56  7e20                   -jle 0x471d78
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00471d78;
    }
    // 00471d58  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00471d5c  8b2d34005100           -mov ebp, dword ptr [0x510034]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5308468) /* 0x510034 */);
L_0x00471d62:
    // 00471d62  81c280000000           -add edx, 0x80
    (cpu.edx) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 00471d68  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 00471d6a  43                     -inc ebx
    (cpu.ebx)++;
    // 00471d6b  88a2f4fc5300           -mov byte ptr [edx + 0x53fcf4], ah
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5504244) /* 0x53fcf4 */) = cpu.ah;
    // 00471d71  39eb                   +cmp ebx, ebp
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
    // 00471d73  7ced                   -jl 0x471d62
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00471d62;
    }
    // 00471d75  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x00471d78:
    // 00471d78  ff0574015400           -inc dword ptr [0x540174]
    (app->getMemory<x86::reg32>(x86::reg32(5505396) /* 0x540174 */))++;
    // 00471d7e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471d7f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471d80  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471d81  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00471d82:
    // 00471d82  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00471d85  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471d86  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471d87  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_471d90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00471d90  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00471d91  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00471d94  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00471d97  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00471d9b  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 00471da2  8baa78015400           -mov ebp, dword ptr [edx + 0x540178]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5505400) /* 0x540178 */);
    // 00471da8  e867fbffff             -call 0x471914
    cpu.esp -= 4;
    sub_471914(app, cpu);
    if (cpu.terminate) return;
    // 00471dad  83e57f                 -and ebp, 0x7f
    cpu.ebp &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 00471db0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00471db2  0f85e5000000           -jne 0x471e9d
    if (!cpu.flags.zf)
    {
        goto L_0x00471e9d;
    }
    // 00471db8  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00471dbb  c1e007                 -shl eax, 7
    cpu.eax <<= 7 /*0x7*/ % 32;
    // 00471dbe  8a842874fd5300         -mov al, byte ptr [eax + ebp + 0x53fd74]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5504372) /* 0x53fd74 */ + cpu.ebp * 1);
    // 00471dc5  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00471dc7  0f85d0000000           -jne 0x471e9d
    if (!cpu.flags.zf)
    {
        goto L_0x00471e9d;
    }
    // 00471dcd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00471dce  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00471dcf  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00471dd0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00471dd1  8b1d70ed5300           -mov ebx, dword ptr [0x53ed70]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5500272) /* 0x53ed70 */);
    // 00471dd7  8b0d78015400           -mov ecx, dword ptr [0x540178]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5505400) /* 0x540178 */);
    // 00471ddd  8bb278015400           -mov esi, dword ptr [edx + 0x540178]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5505400) /* 0x540178 */);
    // 00471de3  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00471de5  39f1                   +cmp ecx, esi
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
    // 00471de7  7d68                   -jge 0x471e51
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00471e51;
    }
    // 00471de9  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00471ded  8d7eff                 -lea edi, [esi - 1]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(-1) /* -0x1 */);
    // 00471df0  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00471df2  89ba78015400           -mov dword ptr [edx + 0x540178], edi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5505400) /* 0x540178 */) = cpu.edi;
    // 00471df8  c1e309                 -shl ebx, 9
    cpu.ebx <<= 9 /*0x9*/ % 32;
    // 00471dfb  8b0d78015400           -mov ecx, dword ptr [0x540178]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5505400) /* 0x540178 */);
    // 00471e01  81c374ed5300           -add ebx, 0x53ed74
    (cpu.ebx) += x86::reg32(x86::sreg32(5500276 /*0x53ed74*/));
    // 00471e07  39f9                   +cmp ecx, edi
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
    // 00471e09  7d3d                   -jge 0x471e48
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00471e48;
    }
L_0x00471e0b:
    // 00471e0b  8d5101                 -lea edx, [ecx + 1]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 00471e0e  83e17f                 -and ecx, 0x7f
    cpu.ecx &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 00471e11  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00471e13  8d3c8d00000000         -lea edi, [ecx*4]
    cpu.edi = x86::reg32(cpu.ecx * 4);
    // 00471e1a  83e67f                 -and esi, 0x7f
    cpu.esi &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 00471e1d  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 00471e22  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 00471e25  01df                   -add edi, ebx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00471e27  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00471e29  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00471e2a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00471e2c  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00471e2f  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00471e31  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00471e33  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00471e36  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00471e38  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471e39  8bb578015400           -mov esi, dword ptr [ebp + 0x540178]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(5505400) /* 0x540178 */);
    // 00471e3f  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00471e41  39f2                   +cmp edx, esi
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
    // 00471e43  7cc6                   -jl 0x471e0b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00471e0b;
    }
    // 00471e45  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x00471e48:
    // 00471e48  8bad78015400           -mov ebp, dword ptr [ebp + 0x540178]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(5505400) /* 0x540178 */);
    // 00471e4e  83e57f                 -and ebp, 0x7f
    cpu.ebp &= x86::reg32(x86::sreg32(127 /*0x7f*/));
L_0x00471e51:
    // 00471e51  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00471e55  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 00471e5a  c1e009                 -shl eax, 9
    cpu.eax <<= 9 /*0x9*/ % 32;
    // 00471e5d  8d3cad00000000         -lea edi, [ebp*4]
    cpu.edi = x86::reg32(cpu.ebp * 4);
    // 00471e64  0574ed5300             -add eax, 0x53ed74
    (cpu.eax) += x86::reg32(x86::sreg32(5500276 /*0x53ed74*/));
    // 00471e69  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00471e6d  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00471e6f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00471e70  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00471e72  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00471e75  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00471e77  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00471e79  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00471e7c  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00471e7e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471e7f  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00471e83  c1e007                 -shl eax, 7
    cpu.eax <<= 7 /*0x7*/ % 32;
    // 00471e86  c6842874fd530001       -mov byte ptr [eax + ebp + 0x53fd74], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5504372) /* 0x53fd74 */ + cpu.ebp * 1) = 1 /*0x1*/;
    // 00471e8e  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00471e92  ff048578015400         -inc dword ptr [eax*4 + 0x540178]
    (app->getMemory<x86::reg32>(x86::reg32(5505400) /* 0x540178 */ + cpu.eax * 4))++;
    // 00471e99  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471e9a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471e9b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471e9c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00471e9d:
    // 00471e9d  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00471ea0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471ea1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_471ec4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00471ec4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00471ec5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00471ec6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00471ec7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00471ec8  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00471ec9  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00471ecb  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00471ecd  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 00471ed4  8bba78015400           -mov edi, dword ptr [edx + 0x540178]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5505400) /* 0x540178 */);
    // 00471eda  668b0dca115100         -mov cx, word ptr [0x5111ca]
    cpu.cx = app->getMemory<x86::reg16>(x86::reg32(5312970) /* 0x5111ca */);
    // 00471ee1  83e77f                 -and edi, 0x7f
    cpu.edi &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 00471ee4  6685c9                 +test cx, cx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.cx & cpu.cx));
    // 00471ee7  7414                   -je 0x471efd
    if (cpu.flags.zf)
    {
        goto L_0x00471efd;
    }
    // 00471ee9  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00471eee  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00471ef0  a398744d00             -mov dword ptr [0x4d7498], eax
    app->getMemory<x86::reg32>(x86::reg32(5076120) /* 0x4d7498 */) = cpu.eax;
    // 00471ef5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00471ef7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471ef8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471ef9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471efa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471efb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471efc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00471efd:
    // 00471efd  e812faffff             -call 0x471914
    cpu.esp -= 4;
    sub_471914(app, cpu);
    if (cpu.terminate) return;
    // 00471f02  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00471f04  752c                   -jne 0x471f32
    if (!cpu.flags.zf)
    {
        goto L_0x00471f32;
    }
    // 00471f06  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00471f08  c1e507                 -shl ebp, 7
    cpu.ebp <<= 7 /*0x7*/ % 32;
    // 00471f0b  01fd                   -add ebp, edi
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edi));
    // 00471f0d  80bd74fd530000         +cmp byte ptr [ebp + 0x53fd74], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(5504372) /* 0x53fd74 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00471f14  7426                   -je 0x471f3c
    if (cpu.flags.zf)
    {
        goto L_0x00471f3c;
    }
    // 00471f16  833dd8ff500001         +cmp dword ptr [0x50ffd8], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5308376) /* 0x50ffd8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00471f1d  7e13                   -jle 0x471f32
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00471f32;
    }
    // 00471f1f  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 00471f24  668935cc115100         -mov word ptr [0x5111cc], si
    app->getMemory<x86::reg16>(x86::reg32(5312972) /* 0x5111cc */) = cpu.si;
    // 00471f2b  668935ca115100         -mov word ptr [0x5111ca], si
    app->getMemory<x86::reg16>(x86::reg32(5312970) /* 0x5111ca */) = cpu.si;
L_0x00471f32:
    // 00471f32  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00471f34  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00471f36  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471f37  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471f38  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471f39  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471f3a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471f3b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00471f3c:
    // 00471f3c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00471f3e  c1e009                 -shl eax, 9
    cpu.eax <<= 9 /*0x9*/ % 32;
    // 00471f41  c1e702                 -shl edi, 2
    cpu.edi <<= 2 /*0x2*/ % 32;
    // 00471f44  0574ed5300             -add eax, 0x53ed74
    (cpu.eax) += x86::reg32(x86::sreg32(5500276 /*0x53ed74*/));
    // 00471f49  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 00471f4e  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00471f50  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00471f51  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00471f53  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 00471f56  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00471f58  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00471f5a  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00471f5d  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00471f5f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471f60  c68574fd530001         -mov byte ptr [ebp + 0x53fd74], 1
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(5504372) /* 0x53fd74 */) = 1 /*0x1*/;
    // 00471f67  8b8a78015400           -mov ecx, dword ptr [edx + 0x540178]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5505400) /* 0x540178 */);
    // 00471f6d  41                     -inc ecx
    (cpu.ecx)++;
    // 00471f6e  a1d8ff5000             -mov eax, dword ptr [0x50ffd8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5308376) /* 0x50ffd8 */);
    // 00471f73  898a78015400           -mov dword ptr [edx + 0x540178], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5505400) /* 0x540178 */) = cpu.ecx;
    // 00471f79  83f804                 +cmp eax, 4
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
    // 00471f7c  770d                   -ja 0x471f8b
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00471f8b;
    }
    // 00471f7e  ff2485b01e4700         -jmp dword ptr [eax*4 + 0x471eb0]
    cpu.ip = app->getMemory<x86::reg32>(4660912 + cpu.eax * 4); goto dynamic_jump;
  case 0x00471f85:
    // 00471f85  ff0594744d00           -inc dword ptr [0x4d7494]
    (app->getMemory<x86::reg32>(x86::reg32(5076116) /* 0x4d7494 */))++;
L_0x00471f8b:
    // 00471f8b  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00471f90  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00471f92  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471f93  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471f94  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471f95  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471f96  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471f97  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00471f98:
    // 00471f98  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00471f9a  75ef                   -jne 0x471f8b
    if (!cpu.flags.zf)
    {
        goto L_0x00471f8b;
    }
    // 00471f9c  833ddcff500000         +cmp dword ptr [0x50ffdc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5308380) /* 0x50ffdc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00471fa3  74e6                   -je 0x471f8b
    if (cpu.flags.zf)
    {
        goto L_0x00471f8b;
    }
    // 00471fa5  ff0594744d00           -inc dword ptr [0x4d7494]
    (app->getMemory<x86::reg32>(x86::reg32(5076116) /* 0x4d7494 */))++;
    // 00471fab  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00471fb0  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00471fb2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471fb3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471fb4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471fb5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471fb6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471fb7  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00471fb8:
    // 00471fb8  8b157c015400           -mov edx, dword ptr [0x54017c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5505404) /* 0x54017c */);
    // 00471fbe  a178015400             -mov eax, dword ptr [0x540178]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5505400) /* 0x540178 */);
    // 00471fc3  39d0                   +cmp eax, edx
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
    // 00471fc5  7d02                   -jge 0x471fc9
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00471fc9;
    }
    // 00471fc7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x00471fc9:
    // 00471fc9  4a                     -dec edx
    (cpu.edx)--;
    // 00471fca  891594744d00           -mov dword ptr [0x4d7494], edx
    app->getMemory<x86::reg32>(x86::reg32(5076116) /* 0x4d7494 */) = cpu.edx;
    // 00471fd0  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00471fd5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00471fd7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471fd8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471fd9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471fda  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471fdb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471fdc  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00471fdd:
    // 00471fdd  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00471fdf  74aa                   -je 0x471f8b
    if (cpu.flags.zf)
    {
        goto L_0x00471f8b;
    }
    // 00471fe1  ff0594744d00           -inc dword ptr [0x4d7494]
    (app->getMemory<x86::reg32>(x86::reg32(5076116) /* 0x4d7494 */))++;
    // 00471fe7  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00471fec  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00471fee  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471fef  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471ff0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471ff1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471ff2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00471ff3  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_472000(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00472000  833de4ff500001         +cmp dword ptr [0x50ffe4], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5308388) /* 0x50ffe4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00472007  7e01                   -jle 0x47200a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047200a;
    }
    // 00472009  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047200a:
    // 0047200a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047200b  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00472010  890d98744d00           -mov dword ptr [0x4d7498], ecx
    app->getMemory<x86::reg32>(x86::reg32(5076120) /* 0x4d7498 */) = cpu.ecx;
    // 00472016  890d9c744d00           -mov dword ptr [0x4d749c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5076124) /* 0x4d749c */) = cpu.ecx;
    // 0047201c  e85ff8ffff             -call 0x471880
    cpu.esp -= 4;
    sub_471880(app, cpu);
    if (cpu.terminate) return;
    // 00472021  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472022  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_472030(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00472030  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00472031  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00472034  833de4ff500001         +cmp dword ptr [0x50ffe4], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5308388) /* 0x50ffe4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047203b  0f8f7b000000           -jg 0x4720bc
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004720bc;
    }
    // 00472041  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00472042  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00472043  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00472044  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00472045  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00472046  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0047204b  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0047204d  890d9c744d00           -mov dword ptr [0x4d749c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5076124) /* 0x4d749c */) = cpu.ecx;
    // 00472053  8974241c               -mov dword ptr [esp + 0x1c], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.esi;
    // 00472057  89742414               -mov dword ptr [esp + 0x14], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.esi;
    // 0047205b  89742418               -mov dword ptr [esp + 0x18], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 0047205f  890d98744d00           -mov dword ptr [0x4d7498], ecx
    app->getMemory<x86::reg32>(x86::reg32(5076120) /* 0x4d7498 */) = cpu.ecx;
    // 00472065  b701                   -mov bh, 1
    cpu.bh = 1 /*0x1*/;
L_0x00472067:
    // 00472067  8b6c241c               -mov ebp, dword ptr [esp + 0x1c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0047206b  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0047206f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00472071  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 00472073  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
L_0x00472075:
    // 00472075  8d043a                 -lea eax, [edx + edi]
    cpu.eax = x86::reg32(cpu.edx + cpu.edi * 1);
    // 00472078  88b874fd5300           -mov byte ptr [eax + 0x53fd74], bh
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5504372) /* 0x53fd74 */) = cpu.bh;
    // 0047207e  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00472085  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00472087  8d0c2a                 -lea ecx, [edx + ebp]
    cpu.ecx = x86::reg32(cpu.edx + cpu.ebp * 1);
L_0x0047208a:
    // 0047208a  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047208d  889871ed5300           -mov byte ptr [eax + 0x53ed71], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5500273) /* 0x53ed71 */) = cpu.bl;
    // 00472093  889872ed5300           -mov byte ptr [eax + 0x53ed72], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5500274) /* 0x53ed72 */) = cpu.bl;
    // 00472099  41                     -inc ecx
    (cpu.ecx)++;
    // 0047209a  889873ed5300           -mov byte ptr [eax + 0x53ed73], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5500275) /* 0x53ed73 */) = cpu.bl;
    // 004720a0  42                     -inc edx
    (cpu.edx)++;
    // 004720a1  889870ed5300           -mov byte ptr [eax + 0x53ed70], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5500272) /* 0x53ed70 */) = cpu.bl;
    // 004720a7  81fa80000000           +cmp edx, 0x80
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(128 /*0x80*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004720ad  7d19                   -jge 0x4720c8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004720c8;
    }
    // 004720af  83fa04                 +cmp edx, 4
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
    // 004720b2  7cc1                   -jl 0x472075
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00472075;
    }
    // 004720b4  889974fd5300           -mov byte ptr [ecx + 0x53fd74], bl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5504372) /* 0x53fd74 */) = cpu.bl;
    // 004720ba  ebce                   -jmp 0x47208a
    goto L_0x0047208a;
L_0x004720bc:
    // 004720bc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004720be  a394744d00             -mov dword ptr [0x4d7494], eax
    app->getMemory<x86::reg32>(x86::reg32(5076116) /* 0x4d7494 */) = cpu.eax;
    // 004720c3  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004720c6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004720c7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004720c8:
    // 004720c8  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004720cc  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004720d0  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004720d4  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 004720d9  81c180000000           -add ecx, 0x80
    (cpu.ecx) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 004720df  81c600020000           -add esi, 0x200
    (cpu.esi) += x86::reg32(x86::sreg32(512 /*0x200*/));
    // 004720e5  8d3c10                 -lea edi, [eax + edx]
    cpu.edi = x86::reg32(cpu.eax + cpu.edx * 1);
    // 004720e8  899078015400           -mov dword ptr [eax + 0x540178], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5505400) /* 0x540178 */) = cpu.edx;
    // 004720ee  894c241c               -mov dword ptr [esp + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 004720f2  89742414               -mov dword ptr [esp + 0x14], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.esi;
    // 004720f6  897c2418               -mov dword ptr [esp + 0x18], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 004720fa  83ff20                 +cmp edi, 0x20
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
    // 004720fd  0f8564ffffff           -jne 0x472067
    if (!cpu.flags.zf)
    {
        goto L_0x00472067;
    }
    // 00472103  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 00472108  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047210a  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047210c  a374015400             -mov dword ptr [0x540174], eax
    app->getMemory<x86::reg32>(x86::reg32(5505396) /* 0x540174 */) = cpu.eax;
    // 00472111  891594744d00           -mov dword ptr [0x4d7494], edx
    app->getMemory<x86::reg32>(x86::reg32(5076116) /* 0x4d7494 */) = cpu.edx;
    // 00472117  e8a4f7ffff             -call 0x4718c0
    cpu.esp -= 4;
    sub_4718c0(app, cpu);
    if (cpu.terminate) return;
    // 0047211c  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 0047211e  ba0f000000             -mov edx, 0xf
    cpu.edx = 15 /*0xf*/;
    // 00472123  8825a0015400           -mov byte ptr [0x5401a0], ah
    app->getMemory<x86::reg8>(x86::reg32(5505440) /* 0x5401a0 */) = cpu.ah;
    // 00472129  b8001e0000             -mov eax, 0x1e00
    cpu.eax = 7680 /*0x1e00*/;
    // 0047212e  890d9c744d00           -mov dword ptr [0x4d749c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5076124) /* 0x4d749c */) = cpu.ecx;
    // 00472134  e807fdfeff             -call 0x461e40
    cpu.esp -= 4;
    sub_461e40(app, cpu);
    if (cpu.terminate) return;
    // 00472139  890d98744d00           -mov dword ptr [0x4d7498], ecx
    app->getMemory<x86::reg32>(x86::reg32(5076120) /* 0x4d7498 */) = cpu.ecx;
    // 0047213f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472140  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472141  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472142  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472143  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472144  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00472147  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472148  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_472150(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00472150  833de4ff500001         +cmp dword ptr [0x50ffe4], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5308388) /* 0x50ffe4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00472157  7e01                   -jle 0x47215a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047215a;
    }
    // 00472159  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047215a:
    // 0047215a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047215b  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00472160  890d98744d00           -mov dword ptr [0x4d7498], ecx
    app->getMemory<x86::reg32>(x86::reg32(5076120) /* 0x4d7498 */) = cpu.ecx;
    // 00472166  890d9c744d00           -mov dword ptr [0x4d749c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5076124) /* 0x4d749c */) = cpu.ecx;
    // 0047216c  e86ff7ffff             -call 0x4718e0
    cpu.esp -= 4;
    sub_4718e0(app, cpu);
    if (cpu.terminate) return;
    // 00472171  e80ef9ffff             -call 0x471a84
    cpu.esp -= 4;
    sub_471a84(app, cpu);
    if (cpu.terminate) return;
    // 00472176  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472177  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_472180(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00472180  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_472190(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00472190  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00472191  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00472192  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00472193  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00472194  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00472195  b8fcc04c00             -mov eax, 0x4cc0fc
    cpu.eax = 5030140 /*0x4cc0fc*/;
    // 0047219a  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0047219f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004721a1  e82a010000             -call 0x4722d0
    cpu.esp -= 4;
    sub_4722d0(app, cpu);
    if (cpu.terminate) return;
    // 004721a6  e885220000             -call 0x474430
    cpu.esp -= 4;
    sub_474430(app, cpu);
    if (cpu.terminate) return;
    // 004721ab  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004721ad  e8fe210000             -call 0x4743b0
    cpu.esp -= 4;
    sub_4743b0(app, cpu);
    if (cpu.terminate) return;
    // 004721b2  8b0dc0045100           -mov ecx, dword ptr [0x5104c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5309632) /* 0x5104c0 */);
    // 004721b8  39c8                   +cmp eax, ecx
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
    // 004721ba  7e02                   -jle 0x4721be
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004721be;
    }
    // 004721bc  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x004721be:
    // 004721be  a3c0045100             -mov dword ptr [0x5104c0], eax
    app->getMemory<x86::reg32>(x86::reg32(5309632) /* 0x5104c0 */) = cpu.eax;
    // 004721c3  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004721c5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004721c7  7e77                   -jle 0x472240
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00472240;
    }
    // 004721c9  be10000000             -mov esi, 0x10
    cpu.esi = 16 /*0x10*/;
    // 004721ce  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004721d0:
    // 004721d0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004721d2  e8d9210000             -call 0x4743b0
    cpu.esp -= 4;
    sub_4743b0(app, cpu);
    if (cpu.terminate) return;
    // 004721d7  8981c0015400           -mov dword ptr [ecx + 0x5401c0], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5505472) /* 0x5401c0 */) = cpu.eax;
    // 004721dd  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004721df  89b1c4015400           -mov dword ptr [ecx + 0x5401c4], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5505476) /* 0x5401c4 */) = cpu.esi;
    // 004721e5  89b9c8015400           -mov dword ptr [ecx + 0x5401c8], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5505480) /* 0x5401c8 */) = cpu.edi;
    // 004721eb  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004721ed  89b9cc015400           -mov dword ptr [ecx + 0x5401cc], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5505484) /* 0x5401cc */) = cpu.edi;
    // 004721f3  e8b8210000             -call 0x4743b0
    cpu.esp -= 4;
    sub_4743b0(app, cpu);
    if (cpu.terminate) return;
    // 004721f8  898100025400           -mov dword ptr [ecx + 0x540200], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5505536) /* 0x540200 */) = cpu.eax;
    // 004721fe  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00472200  e8ab210000             -call 0x4743b0
    cpu.esp -= 4;
    sub_4743b0(app, cpu);
    if (cpu.terminate) return;
    // 00472205  898104025400           -mov dword ptr [ecx + 0x540204], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5505540) /* 0x540204 */) = cpu.eax;
    // 0047220b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047220d  e89e210000             -call 0x4743b0
    cpu.esp -= 4;
    sub_4743b0(app, cpu);
    if (cpu.terminate) return;
    // 00472212  898108025400           -mov dword ptr [ecx + 0x540208], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5505544) /* 0x540208 */) = cpu.eax;
    // 00472218  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047221a  e891210000             -call 0x4743b0
    cpu.esp -= 4;
    sub_4743b0(app, cpu);
    if (cpu.terminate) return;
    // 0047221f  89810c025400           -mov dword ptr [ecx + 0x54020c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5505548) /* 0x54020c */) = cpu.eax;
    // 00472225  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00472227  43                     -inc ebx
    (cpu.ebx)++;
    // 00472228  e883210000             -call 0x4743b0
    cpu.esp -= 4;
    sub_4743b0(app, cpu);
    if (cpu.terminate) return;
    // 0047222d  898110025400           -mov dword ptr [ecx + 0x540210], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5505552) /* 0x540210 */) = cpu.eax;
    // 00472233  a1c0045100             -mov eax, dword ptr [0x5104c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5309632) /* 0x5104c0 */);
    // 00472238  83c154                 -add ecx, 0x54
    (cpu.ecx) += x86::reg32(x86::sreg32(84 /*0x54*/));
    // 0047223b  39c3                   +cmp ebx, eax
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
    // 0047223d  7c91                   -jl 0x4721d0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004721d0;
    }
    // 0047223f  90                     -nop 
    ;
L_0x00472240:
    // 00472240  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00472242  e8b9210000             -call 0x474400
    cpu.esp -= 4;
    sub_474400(app, cpu);
    if (cpu.terminate) return;
    // 00472247  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472248  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00472249  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047224a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047224b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047224c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_472250(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00472250  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00472251  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00472252  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00472254  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00472256  8b1530005100           -mov edx, dword ptr [0x510030]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5308464) /* 0x510030 */);
    // 0047225c  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 0047225f  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00472261  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00472263  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00472266  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00472268  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0047226b  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0047226d  8b148500025400         -mov edx, dword ptr [eax*4 + 0x540200]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5505536) /* 0x540200 */ + cpu.eax * 4);
    // 00472274  895114                 -mov dword ptr [ecx + 0x14], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 00472277  8b148504025400         -mov edx, dword ptr [eax*4 + 0x540204]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5505540) /* 0x540204 */ + cpu.eax * 4);
    // 0047227e  89919c000000           -mov dword ptr [ecx + 0x9c], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(156) /* 0x9c */) = cpu.edx;
    // 00472284  8b148508025400         -mov edx, dword ptr [eax*4 + 0x540208]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5505544) /* 0x540208 */ + cpu.eax * 4);
    // 0047228b  8991a0000000           -mov dword ptr [ecx + 0xa0], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(160) /* 0xa0 */) = cpu.edx;
    // 00472291  8b14850c025400         -mov edx, dword ptr [eax*4 + 0x54020c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5505548) /* 0x54020c */ + cpu.eax * 4);
    // 00472298  c6818c00000001         -mov byte ptr [ecx + 0x8c], 1
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(140) /* 0x8c */) = 1 /*0x1*/;
    // 0047229f  8991a4000000           -mov dword ptr [ecx + 0xa4], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(164) /* 0xa4 */) = cpu.edx;
    // 004722a5  8b148510025400         -mov edx, dword ptr [eax*4 + 0x540210]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5505552) /* 0x540210 */ + cpu.eax * 4);
    // 004722ac  8d81c4000000           -lea eax, [ecx + 0xc4]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(196) /* 0xc4 */);
    // 004722b2  e839740200             -call 0x4996f0
    cpu.esp -= 4;
    sub_4996f0(app, cpu);
    if (cpu.terminate) return;
    // 004722b7  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004722b9  e802ebfeff             -call 0x460dc0
    cpu.esp -= 4;
    sub_460dc0(app, cpu);
    if (cpu.terminate) return;
    // 004722be  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004722bf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004722c0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4722d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004722d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004722d1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004722d2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004722d3  8b15ecff5000           -mov edx, dword ptr [0x50ffec]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5308396) /* 0x50ffec */);
    // 004722d9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004722da  8b0d58125100           -mov ecx, dword ptr [0x511258]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5313112) /* 0x511258 */);
    // 004722e0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004722e1  68f0c04c00             -push 0x4cc0f0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5030128 /*0x4cc0f0*/;
    cpu.esp -= 4;
    // 004722e6  6864035400             -push 0x540364
    app->getMemory<x86::reg32>(cpu.esp-4) = 5505892 /*0x540364*/;
    cpu.esp -= 4;
    // 004722eb  e881260100             -call 0x484971
    cpu.esp -= 4;
    sub_484971(app, cpu);
    if (cpu.terminate) return;
    // 004722f0  b864035400             -mov eax, 0x540364
    cpu.eax = 5505892 /*0x540364*/;
    // 004722f5  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004722f8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004722f9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004722fa  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
