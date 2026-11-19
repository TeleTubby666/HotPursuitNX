#include "nfs2se.h"
#include <lib/thread.h>

namespace nfs2se
{

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47eb80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047eb80  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047eb81  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047eb82  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047eb83  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047eb84  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047eb85  81ec40010000           -sub esp, 0x140
    (cpu.esp) -= x86::reg32(x86::sreg32(320 /*0x140*/));
    // 0047eb8b  8b15d8aa4c00           -mov edx, dword ptr [0x4caad8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5024472) /* 0x4caad8 */);
    // 0047eb91  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0047eb93  83faff                 +cmp edx, -1
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
    // 0047eb96  7409                   -je 0x47eba1
    if (cpu.flags.zf)
    {
        goto L_0x0047eba1;
    }
    // 0047eb98  bfa9da5100             -mov edi, 0x51daa9
    cpu.edi = 5364393 /*0x51daa9*/;
L_0x0047eb9d:
    // 0047eb9d  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047eb9f  740e                   -je 0x47ebaf
    if (cpu.flags.zf)
    {
        goto L_0x0047ebaf;
    }
L_0x0047eba1:
    // 0047eba1  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047eba3  81c440010000           -add esp, 0x140
    (cpu.esp) += x86::reg32(x86::sreg32(320 /*0x140*/));
    // 0047eba9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ebaa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ebab  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ebac  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ebad  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ebae  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047ebaf:
    // 0047ebaf  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0047ebb1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047ebb2  8b0dd8aa4c00           -mov ecx, dword ptr [0x4caad8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5024472) /* 0x4caad8 */);
    // 0047ebb8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047ebb9  2eff1590744b00         -call dword ptr cs:[0x4b7490]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945040) /* 0x4b7490 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047ebc0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047ebc2  743f                   -je 0x47ec03
    if (cpu.flags.zf)
    {
        goto L_0x0047ec03;
    }
    // 0047ebc4  8b1da0d95100           -mov ebx, dword ptr [0x51d9a0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5364128) /* 0x51d9a0 */);
    // 0047ebca  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 0047ebcc  baa4d95100             -mov edx, 0x51d9a4
    cpu.edx = 5364132 /*0x51d9a4*/;
    // 0047ebd1  88a3a9da5100           -mov byte ptr [ebx + 0x51daa9], ah
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5364393) /* 0x51daa9 */) = cpu.ah;
    // 0047ebd7  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0047ebd9  e8ded3ffff             -call 0x47bfbc
    cpu.esp -= 4;
    sub_47bfbc(app, cpu);
    if (cpu.terminate) return;
    // 0047ebde  bb04010000             -mov ebx, 0x104
    cpu.ebx = 260 /*0x104*/;
    // 0047ebe3  8d54242c               -lea edx, [esp + 0x2c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0047ebe7  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0047ebe9  e8ddbd0100             -call 0x49a9cb
    cpu.esp -= 4;
    sub_49a9cb(app, cpu);
    if (cpu.terminate) return;
    // 0047ebee  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047ebef  2eff15dc744b00         -call dword ptr cs:[0x4b74dc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945116) /* 0x4b74dc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047ebf6  83f8ff                 +cmp eax, -1
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
    // 0047ebf9  74a2                   -je 0x47eb9d
    if (cpu.flags.zf)
    {
        goto L_0x0047eb9d;
    }
    // 0047ebfb  a810                   +test al, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 16 /*0x10*/));
    // 0047ebfd  759e                   -jne 0x47eb9d
    if (!cpu.flags.zf)
    {
        goto L_0x0047eb9d;
    }
    // 0047ebff  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 0047ec01  eb9a                   -jmp 0x47eb9d
    goto L_0x0047eb9d;
L_0x0047ec03:
    // 0047ec03  8b1dd8aa4c00           -mov ebx, dword ptr [0x4caad8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5024472) /* 0x4caad8 */);
    // 0047ec09  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047ec0a  beffffffff             -mov esi, 0xffffffff
    cpu.esi = 4294967295 /*0xffffffff*/;
    // 0047ec0f  2eff1588744b00         -call dword ptr cs:[0x4b7488]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945032) /* 0x4b7488 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047ec16  8935d8aa4c00           -mov dword ptr [0x4caad8], esi
    app->getMemory<x86::reg32>(x86::reg32(5024472) /* 0x4caad8 */) = cpu.esi;
    // 0047ec1c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047ec1e  81c440010000           -add esp, 0x140
    (cpu.esp) += x86::reg32(x86::sreg32(320 /*0x140*/));
    // 0047ec24  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ec25  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ec26  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ec27  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ec28  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ec29  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47ec2c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047ec2c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047ec2d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047ec2e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047ec2f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047ec30  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047ec31  81ec40010000           -sub esp, 0x140
    (cpu.esp) -= x86::reg32(x86::sreg32(320 /*0x140*/));
    // 0047ec37  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047ec39  8b15d8aa4c00           -mov edx, dword ptr [0x4caad8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5024472) /* 0x4caad8 */);
    // 0047ec3f  83faff                 +cmp edx, -1
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
    // 0047ec42  0f856b000000           -jne 0x47ecb3
    if (!cpu.flags.zf)
    {
        goto L_0x0047ecb3;
    }
L_0x0047ec48:
    // 0047ec48  bb04010000             -mov ebx, 0x104
    cpu.ebx = 260 /*0x104*/;
    // 0047ec4d  b8a4d95100             -mov eax, 0x51d9a4
    cpu.eax = 5364132 /*0x51d9a4*/;
    // 0047ec52  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0047ec54  bfa4d95100             -mov edi, 0x51d9a4
    cpu.edi = 5364132 /*0x51d9a4*/;
    // 0047ec59  e85ed3ffff             -call 0x47bfbc
    cpu.esp -= 4;
    sub_47bfbc(app, cpu);
    if (cpu.terminate) return;
    // 0047ec5e  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047ec60  49                     -dec ecx
    (cpu.ecx)--;
    // 0047ec61  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047ec63  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0047ec65  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 0047ec67  49                     -dec ecx
    (cpu.ecx)--;
    // 0047ec68  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047ec6a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047ec6c  7e15                   -jle 0x47ec83
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047ec83;
    }
L_0x0047ec6e:
    // 0047ec6e  8a90a4d95100           -mov dl, byte ptr [eax + 0x51d9a4]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5364132) /* 0x51d9a4 */);
    // 0047ec74  80fa5c                 +cmp dl, 0x5c
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(92 /*0x5c*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047ec77  740a                   -je 0x47ec83
    if (cpu.flags.zf)
    {
        goto L_0x0047ec83;
    }
    // 0047ec79  80fa3a                 +cmp dl, 0x3a
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(58 /*0x3a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047ec7c  7405                   -je 0x47ec83
    if (cpu.flags.zf)
    {
        goto L_0x0047ec83;
    }
    // 0047ec7e  48                     -dec eax
    (cpu.eax)--;
    // 0047ec7f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047ec81  7feb                   -jg 0x47ec6e
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0047ec6e;
    }
L_0x0047ec83:
    // 0047ec83  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047ec85  7536                   -jne 0x47ecbd
    if (!cpu.flags.zf)
    {
        goto L_0x0047ecbd;
    }
L_0x0047ec87:
    // 0047ec87  a3a0d95100             -mov dword ptr [0x51d9a0], eax
    app->getMemory<x86::reg32>(x86::reg32(5364128) /* 0x51d9a0 */) = cpu.eax;
    // 0047ec8c  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0047ec8e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047ec8f  68a4d95100             -push 0x51d9a4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5364132 /*0x51d9a4*/;
    cpu.esp -= 4;
    // 0047ec94  2eff158c744b00         -call dword ptr cs:[0x4b748c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945036) /* 0x4b748c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047ec9b  a3d8aa4c00             -mov dword ptr [0x4caad8], eax
    app->getMemory<x86::reg32>(x86::reg32(5024472) /* 0x4caad8 */) = cpu.eax;
    // 0047eca0  83f8ff                 +cmp eax, -1
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
    // 0047eca3  751b                   -jne 0x47ecc0
    if (!cpu.flags.zf)
    {
        goto L_0x0047ecc0;
    }
    // 0047eca5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047eca7  81c440010000           +add esp, 0x140
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(320 /*0x140*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047ecad  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ecae  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ecaf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ecb0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ecb1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ecb2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047ecb3:
    // 0047ecb3  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047ecb4  2eff1588744b00         -call dword ptr cs:[0x4b7488]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945032) /* 0x4b7488 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047ecbb  eb8b                   -jmp 0x47ec48
    goto L_0x0047ec48;
L_0x0047ecbd:
    // 0047ecbd  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0047ecbe  ebc7                   -jmp 0x47ec87
    goto L_0x0047ec87;
L_0x0047ecc0:
    // 0047ecc0  baa4d95100             -mov edx, 0x51d9a4
    cpu.edx = 5364132 /*0x51d9a4*/;
    // 0047ecc5  8b1da0d95100           -mov ebx, dword ptr [0x51d9a0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5364128) /* 0x51d9a0 */);
    // 0047eccb  30c9                   -xor cl, cl
    cpu.cl ^= x86::reg8(x86::sreg8(cpu.cl));
    // 0047eccd  b8a9da5100             -mov eax, 0x51daa9
    cpu.eax = 5364393 /*0x51daa9*/;
    // 0047ecd2  888ba9da5100           -mov byte ptr [ebx + 0x51daa9], cl
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5364393) /* 0x51daa9 */) = cpu.cl;
    // 0047ecd8  e8dfd2ffff             -call 0x47bfbc
    cpu.esp -= 4;
    sub_47bfbc(app, cpu);
    if (cpu.terminate) return;
    // 0047ecdd  bb04010000             -mov ebx, 0x104
    cpu.ebx = 260 /*0x104*/;
    // 0047ece2  8d54242c               -lea edx, [esp + 0x2c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0047ece6  b8a9da5100             -mov eax, 0x51daa9
    cpu.eax = 5364393 /*0x51daa9*/;
    // 0047eceb  e8dbbc0100             -call 0x49a9cb
    cpu.esp -= 4;
    sub_49a9cb(app, cpu);
    if (cpu.terminate) return;
    // 0047ecf0  68a9da5100             -push 0x51daa9
    app->getMemory<x86::reg32>(cpu.esp-4) = 5364393 /*0x51daa9*/;
    cpu.esp -= 4;
    // 0047ecf5  2eff15dc744b00         -call dword ptr cs:[0x4b74dc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945116) /* 0x4b74dc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047ecfc  83f8ff                 +cmp eax, -1
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
    // 0047ecff  7415                   -je 0x47ed16
    if (cpu.flags.zf)
    {
        goto L_0x0047ed16;
    }
    // 0047ed01  a810                   +test al, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 16 /*0x10*/));
    // 0047ed03  7511                   -jne 0x47ed16
    if (!cpu.flags.zf)
    {
        goto L_0x0047ed16;
    }
    // 0047ed05  b8a9da5100             -mov eax, 0x51daa9
    cpu.eax = 5364393 /*0x51daa9*/;
    // 0047ed0a  81c440010000           -add esp, 0x140
    (cpu.esp) += x86::reg32(x86::sreg32(320 /*0x140*/));
    // 0047ed10  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ed11  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ed12  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ed13  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ed14  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ed15  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047ed16:
    // 0047ed16  e865feffff             -call 0x47eb80
    cpu.esp -= 4;
    sub_47eb80(app, cpu);
    if (cpu.terminate) return;
    // 0047ed1b  81c440010000           -add esp, 0x140
    (cpu.esp) += x86::reg32(x86::sreg32(320 /*0x140*/));
    // 0047ed21  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ed22  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ed23  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ed24  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ed25  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ed26  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47ed30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047ed30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047ed31  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047ed32  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047ed33  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047ed36  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047ed3a  8d5c2404               -lea ebx, [esp + 4]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047ed3e  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0047ed40  e897e3ffff             -call 0x47d0dc
    cpu.esp -= 4;
    sub_47d0dc(app, cpu);
    if (cpu.terminate) return;
    // 0047ed45  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0047ed48  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047ed4a  750a                   -jne 0x47ed56
    if (!cpu.flags.zf)
    {
        goto L_0x0047ed56;
    }
    // 0047ed4c  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0047ed4f  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047ed52  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ed53  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ed54  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ed55  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047ed56:
    // 0047ed56  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047ed58  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0047ed5d  e80ee5ffff             -call 0x47d270
    cpu.esp -= 4;
    sub_47d270(app, cpu);
    if (cpu.terminate) return;
    // 0047ed62  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 0047ed65  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0047ed68  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047ed6b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ed6c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ed6d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ed6e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_47ed70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047ed70  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047ed72  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0047ed74  8b1db0db5100           -mov ebx, dword ptr [0x51dbb0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5364656) /* 0x51dbb0 */);
    // 0047ed7a  d1fa                   +sar edx, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 0047ed7c  e9301f0000             -jmp 0x480cb1
    return sub_480cb1(app, cpu);
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47ed84(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047ed84  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047ed86  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0047ed88  8b1db0db5100           -mov ebx, dword ptr [0x51dbb0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5364656) /* 0x51dbb0 */);
    // 0047ed8e  e91e1f0000             -jmp 0x480cb1
    return sub_480cb1(app, cpu);
}

/* align: skip 0x90 */
void Application::sub_47ed94(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047ed94  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047ed96  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0047ed98  8b1db0db5100           -mov ebx, dword ptr [0x51dbb0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5364656) /* 0x51dbb0 */);
    // 0047ed9e  01d2                   +add edx, edx
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047eda0  e90c1f0000             -jmp 0x480cb1
    return sub_480cb1(app, cpu);
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47eda8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047eda8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047eda9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047edaa  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0047edac  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
L_0x0047edae:
    // 0047edae  bb03000000             -mov ebx, 3
    cpu.ebx = 3 /*0x3*/;
    // 0047edb3  8b15b0db5100           -mov edx, dword ptr [0x51dbb0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5364656) /* 0x51dbb0 */);
    // 0047edb9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047edbb  e82f3f0000             -call 0x482cef
    cpu.esp -= 4;
    sub_482cef(app, cpu);
    if (cpu.terminate) return;
    // 0047edc0  83c103                 +add ecx, 3
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3 /*0x3*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047edc3  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0047edc4  75e8                   -jne 0x47edae
    if (!cpu.flags.zf)
    {
        goto L_0x0047edae;
    }
    // 0047edc6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047edc7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047edc8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47edcc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047edcc  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047edce  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0047edd0  8b1db0db5100           -mov ebx, dword ptr [0x51dbb0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5364656) /* 0x51dbb0 */);
    // 0047edd6  c1e202                 +shl edx, 2
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
    // 0047edd9  e9d31e0000             -jmp 0x480cb1
    return sub_480cb1(app, cpu);
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47ede0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047ede0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047ede1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047ede2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047ede3  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0047ede6  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047ede8  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0047edea  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0047edee  8a15d8a64c00           -mov dl, byte ptr [0x4ca6d8]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5023448) /* 0x4ca6d8 */);
    // 0047edf4  80fa08                 +cmp dl, 8
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047edf7  735b                   -jae 0x47ee54
    if (!cpu.flags.cf)
    {
        goto L_0x0047ee54;
    }
    // 0047edf9  80fa04                 +cmp dl, 4
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
    // 0047edfc  750a                   -jne 0x47ee08
    if (!cpu.flags.zf)
    {
        goto L_0x0047ee08;
    }
    // 0047edfe  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0047ee01  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047ee03  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
L_0x0047ee06:
    // 0047ee06  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
L_0x0047ee08:
    // 0047ee08  a3b0db5100             -mov dword ptr [0x51dbb0], eax
    app->getMemory<x86::reg32>(x86::reg32(5364656) /* 0x51dbb0 */) = cpu.eax;
    // 0047ee0d  66895c2404             -mov word ptr [esp + 4], bx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.bx;
    // 0047ee12  66894c2406             -mov word ptr [esp + 6], cx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(6) /* 0x6 */) = cpu.cx;
    // 0047ee17  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 0047ee19  b9dcaa4c00             -mov ecx, 0x4caadc
    cpu.ecx = 5024476 /*0x4caadc*/;
    // 0047ee1e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047ee20  881424                 -mov byte ptr [esp], dl
    app->getMemory<x86::reg8>(cpu.esp) = cpu.dl;
    // 0047ee23  a0d9a64c00             -mov al, byte ptr [0x4ca6d9]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5023449) /* 0x4ca6d9 */);
    // 0047ee28  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0047ee2b  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0047ee30  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 0047ee32  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 0047ee34  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0047ee36  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0047ee38  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0047ee3b  81e5ff000000           -and ebp, 0xff
    cpu.ebp &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0047ee41  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0047ee43  892c24                 -mov dword ptr [esp], ebp
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 0047ee46  e891820100             -call 0x4970dc
    cpu.esp -= 4;
    sub_4970dc(app, cpu);
    if (cpu.terminate) return;
    // 0047ee4b  83c414                 +add esp, 0x14
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
    // 0047ee4e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ee4f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ee50  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ee51  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0047ee54:
    // 0047ee54  7618                   -jbe 0x47ee6e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0047ee6e;
    }
    // 0047ee56  80fa0f                 +cmp dl, 0xf
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(15 /*0xf*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047ee59  72ad                   -jb 0x47ee08
    if (cpu.flags.cf)
    {
        goto L_0x0047ee08;
    }
    // 0047ee5b  7605                   -jbe 0x47ee62
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0047ee62;
    }
    // 0047ee5d  80fa10                 +cmp dl, 0x10
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047ee60  75a6                   -jne 0x47ee08
    if (!cpu.flags.zf)
    {
        goto L_0x0047ee08;
    }
L_0x0047ee62:
    // 0047ee62  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0047ee67  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047ee69  c1e210                 +shl edx, 0x10
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
    // 0047ee6c  eb98                   -jmp 0x47ee06
    goto L_0x0047ee06;
L_0x0047ee6e:
    // 0047ee6e  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0047ee73  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047ee75  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 0047ee78  09d0                   -or eax, edx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.edx));
    // 0047ee7a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047ee7c  c1e210                 +shl edx, 0x10
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
    // 0047ee7f  eb85                   -jmp 0x47ee06
    goto L_0x0047ee06;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47ee90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047ee90  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047ee91  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047ee92  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047ee93  81ec24020000           -sub esp, 0x224
    (cpu.esp) -= x86::reg32(x86::sreg32(548 /*0x224*/));
    // 0047ee99  8bb42434020000         -mov esi, dword ptr [esp + 0x234]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(564) /* 0x234 */);
    // 0047eea0  89842410020000         -mov dword ptr [esp + 0x210], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(528) /* 0x210 */) = cpu.eax;
    // 0047eea7  8994240c020000         -mov dword ptr [esp + 0x20c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(524) /* 0x20c */) = cpu.edx;
    // 0047eeae  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0047eeb0  898c2420020000         -mov dword ptr [esp + 0x220], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(544) /* 0x220 */) = cpu.ecx;
    // 0047eeb7  8bbc2410020000         -mov edi, dword ptr [esp + 0x210]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(528) /* 0x210 */);
    // 0047eebe  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047eec0  8b4002                 -mov eax, dword ptr [eax + 2]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0047eec3  8994241c020000         -mov dword ptr [esp + 0x21c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(540) /* 0x21c */) = cpu.edx;
    // 0047eeca  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0047eecd  8b7f04                 -mov edi, dword ptr [edi + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 0047eed0  89842408020000         -mov dword ptr [esp + 0x208], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(520) /* 0x208 */) = cpu.eax;
    // 0047eed7  c1ff10                 -sar edi, 0x10
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (16 /*0x10*/ % 32));
    // 0047eeda  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047eedc  7457                   -je 0x47ef35
    if (cpu.flags.zf)
    {
        goto L_0x0047ef35;
    }
    // 0047eede  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047eee0  7453                   -je 0x47ef35
    if (cpu.flags.zf)
    {
        goto L_0x0047ef35;
    }
    // 0047eee2  89942404020000         -mov dword ptr [esp + 0x204], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(516) /* 0x204 */) = cpu.edx;
    // 0047eee9  8b942410020000         -mov edx, dword ptr [esp + 0x210]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(528) /* 0x210 */);
    // 0047eef0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047eef2  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 0047eef4  a0d9a64c00             -mov al, byte ptr [0x4ca6d9]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5023449) /* 0x4ca6d9 */);
    // 0047eef9  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0047eeff  39c2                   +cmp edx, eax
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
    // 0047ef01  753e                   -jne 0x47ef41
    if (!cpu.flags.zf)
    {
        goto L_0x0047ef41;
    }
L_0x0047ef03:
    // 0047ef03  8b84240c020000         -mov eax, dword ptr [esp + 0x20c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(524) /* 0x20c */);
    // 0047ef0a  3b05d0a64c00           +cmp eax, dword ptr [0x4ca6d0]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023440) /* 0x4ca6d0 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047ef10  0f8ca6000000           -jl 0x47efbc
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047efbc;
    }
L_0x0047ef16:
    // 0047ef16  8b942404020000         -mov edx, dword ptr [esp + 0x204]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(516) /* 0x204 */);
    // 0047ef1d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047ef1f  7407                   -je 0x47ef28
    if (cpu.flags.zf)
    {
        goto L_0x0047ef28;
    }
    // 0047ef21  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047ef23  e864b7ffff             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
L_0x0047ef28:
    // 0047ef28  833d00a44c0000         +cmp dword ptr [0x4ca400], 0
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
    // 0047ef2f  0f85cb020000           -jne 0x47f200
    if (!cpu.flags.zf)
    {
        goto L_0x0047f200;
    }
L_0x0047ef35:
    // 0047ef35  81c424020000           -add esp, 0x224
    (cpu.esp) += x86::reg32(x86::sreg32(548 /*0x224*/));
    // 0047ef3b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ef3c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ef3d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ef3e  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0047ef41:
    // 0047ef41  8b842410020000         -mov eax, dword ptr [esp + 0x210]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(528) /* 0x210 */);
    // 0047ef48  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0047ef4a  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 0047ef4d  8a80d4ca4c00           -mov al, byte ptr [eax + 0x4ccad4]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5032660) /* 0x4ccad4 */);
    // 0047ef53  83f808                 +cmp eax, 8
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
    // 0047ef56  7536                   -jne 0x47ef8e
    if (!cpu.flags.zf)
    {
        goto L_0x0047ef8e;
    }
    // 0047ef58  803dd8a64c0010         +cmp byte ptr [0x4ca6d8], 0x10
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5023448) /* 0x4ca6d8 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047ef5f  752d                   -jne 0x47ef8e
    if (!cpu.flags.zf)
    {
        goto L_0x0047ef8e;
    }
    // 0047ef61  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0047ef63  8b842410020000         -mov eax, dword ptr [esp + 0x210]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(528) /* 0x210 */);
    // 0047ef6a  bb00020000             -mov ebx, 0x200
    cpu.ebx = 512 /*0x200*/;
    // 0047ef6f  e86c7a0100             -call 0x4969e0
    cpu.esp -= 4;
    sub_4969e0(app, cpu);
    if (cpu.terminate) return;
    // 0047ef74  ba70a35200             -mov edx, 0x52a370
    cpu.edx = 5415792 /*0x52a370*/;
    // 0047ef79  e882260000             -call 0x481600
    cpu.esp -= 4;
    sub_481600(app, cpu);
    if (cpu.terminate) return;
    // 0047ef7e  c784241c02000090164900 -mov dword ptr [esp + 0x21c], 0x491690
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(540) /* 0x21c */) = 4789904 /*0x491690*/;
    // 0047ef89  e975ffffff             -jmp 0x47ef03
    goto L_0x0047ef03;
L_0x0047ef8e:
    // 0047ef8e  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0047ef93  8b842410020000         -mov eax, dword ptr [esp + 0x210]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(528) /* 0x210 */);
    // 0047ef9a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047ef9c  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0047ef9e  8a15d9a64c00           -mov dl, byte ptr [0x4ca6d9]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5023449) /* 0x4ca6d9 */);
    // 0047efa4  e87f7d0100             -call 0x496d28
    cpu.esp -= 4;
    sub_496d28(app, cpu);
    if (cpu.terminate) return;
    // 0047efa9  89842404020000         -mov dword ptr [esp + 0x204], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(516) /* 0x204 */) = cpu.eax;
    // 0047efb0  89842410020000         -mov dword ptr [esp + 0x210], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(528) /* 0x210 */) = cpu.eax;
    // 0047efb7  e947ffffff             -jmp 0x47ef03
    goto L_0x0047ef03;
L_0x0047efbc:
    // 0047efbc  3b2dd4a64c00           +cmp ebp, dword ptr [0x4ca6d4]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5023444) /* 0x4ca6d4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047efc2  0f8d4effffff           -jge 0x47ef16
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047ef16;
    }
    // 0047efc8  8b9c2420020000         -mov ebx, dword ptr [esp + 0x220]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(544) /* 0x220 */);
    // 0047efcf  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047efd1  0f8ef2010000           -jle 0x47f1c9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047f1c9;
    }
    // 0047efd7  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x0047efd9:
    // 0047efd9  8b94240c020000         -mov edx, dword ptr [esp + 0x20c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(524) /* 0x20c */);
    // 0047efe0  8b0dc8a64c00           -mov ecx, dword ptr [0x4ca6c8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5023432) /* 0x4ca6c8 */);
    // 0047efe6  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0047efe8  39c8                   +cmp eax, ecx
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
    // 0047efea  0f8e26ffffff           -jle 0x47ef16
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047ef16;
    }
    // 0047eff0  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047eff2  0f8eda010000           -jle 0x47f1d2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047f1d2;
    }
    // 0047eff8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x0047effa:
    // 0047effa  8b1dcca64c00           -mov ebx, dword ptr [0x4ca6cc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5023436) /* 0x4ca6cc */);
    // 0047f000  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0047f002  39d8                   +cmp eax, ebx
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
    // 0047f004  0f8e0cffffff           -jle 0x47ef16
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047ef16;
    }
    // 0047f00a  8b842410020000         -mov eax, dword ptr [esp + 0x210]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(528) /* 0x210 */);
    // 0047f011  8b942408020000         -mov edx, dword ptr [esp + 0x208]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(520) /* 0x208 */);
    // 0047f018  8b8c2420020000         -mov ecx, dword ptr [esp + 0x220]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(544) /* 0x220 */);
    // 0047f01f  e8ecb90100             -call 0x49aa10
    cpu.esp -= 4;
    sub_49aa10(app, cpu);
    if (cpu.terminate) return;
    // 0047f024  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0047f027  89842414020000         -mov dword ptr [esp + 0x214], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(532) /* 0x214 */) = cpu.eax;
    // 0047f02e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047f030  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0047f033  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0047f035  c1e710                 -shl edi, 0x10
    cpu.edi <<= 16 /*0x10*/ % 32;
    // 0047f038  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047f03a  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0047f03c  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0047f03e  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0047f041  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0047f043  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047f045  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0047f048  89842418020000         -mov dword ptr [esp + 0x218], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(536) /* 0x218 */) = cpu.eax;
    // 0047f04f  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0047f051  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0047f053  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0047f055  0f8c80010000           -jl 0x47f1db
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047f1db;
    }
    // 0047f05b  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x0047f05d:
    // 0047f05d  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047f05f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047f061  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0047f064  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0047f066  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0047f068  8b9c2420020000         -mov ebx, dword ptr [esp + 0x220]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(544) /* 0x220 */);
    // 0047f06f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047f071  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047f073  0f8c6b010000           -jl 0x47f1e4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047f1e4;
    }
L_0x0047f079:
    // 0047f079  8b1dcca64c00           -mov ebx, dword ptr [0x4ca6cc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5023436) /* 0x4ca6cc */);
    // 0047f07f  39dd                   +cmp ebp, ebx
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f081  7d14                   -jge 0x47f097
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047f097;
    }
    // 0047f083  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047f085  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0047f087  8bac2418020000         -mov ebp, dword ptr [esp + 0x218]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(536) /* 0x218 */);
    // 0047f08e  0fafe8                 -imul ebp, eax
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0047f091  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0047f093  01ef                   -add edi, ebp
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0047f095  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
L_0x0047f097:
    // 0047f097  8b1dd4a64c00           -mov ebx, dword ptr [0x4ca6d4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5023444) /* 0x4ca6d4 */);
    // 0047f09d  8d042e                 -lea eax, [esi + ebp]
    cpu.eax = x86::reg32(cpu.esi + cpu.ebp * 1);
    // 0047f0a0  39d8                   +cmp eax, ebx
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
    // 0047f0a2  7e04                   -jle 0x47f0a8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047f0a8;
    }
    // 0047f0a4  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0047f0a6  29ee                   -sub esi, ebp
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebp));
L_0x0047f0a8:
    // 0047f0a8  8b84240c020000         -mov eax, dword ptr [esp + 0x20c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(524) /* 0x20c */);
    // 0047f0af  8b1dc8a64c00           -mov ebx, dword ptr [0x4ca6c8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5023432) /* 0x4ca6c8 */);
    // 0047f0b5  39d8                   +cmp eax, ebx
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
    // 0047f0b7  7d2c                   -jge 0x47f0e5
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047f0e5;
    }
    // 0047f0b9  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047f0bb  2b84240c020000         -sub eax, dword ptr [esp + 0x20c]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(524) /* 0x20c */)));
    // 0047f0c2  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0047f0c4  0fafd8                 -imul ebx, eax
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0047f0c7  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0047f0c9  8b9c2420020000         -mov ebx, dword ptr [esp + 0x220]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(544) /* 0x220 */);
    // 0047f0d0  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0047f0d2  a1c8a64c00             -mov eax, dword ptr [0x4ca6c8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023432) /* 0x4ca6c8 */);
    // 0047f0d7  899c2420020000         -mov dword ptr [esp + 0x220], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(544) /* 0x220 */) = cpu.ebx;
    // 0047f0de  8984240c020000         -mov dword ptr [esp + 0x20c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(524) /* 0x20c */) = cpu.eax;
L_0x0047f0e5:
    // 0047f0e5  8b84240c020000         -mov eax, dword ptr [esp + 0x20c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(524) /* 0x20c */);
    // 0047f0ec  03842420020000         -add eax, dword ptr [esp + 0x220]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(544) /* 0x220 */)));
    // 0047f0f3  8b1dd0a64c00           -mov ebx, dword ptr [0x4ca6d0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5023440) /* 0x4ca6d0 */);
    // 0047f0f9  39d8                   +cmp eax, ebx
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
    // 0047f0fb  7e12                   -jle 0x47f10f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047f10f;
    }
    // 0047f0fd  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047f0ff  8b9c240c020000         -mov ebx, dword ptr [esp + 0x20c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(524) /* 0x20c */);
    // 0047f106  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047f108  89842420020000         -mov dword ptr [esp + 0x220], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(544) /* 0x220 */) = cpu.eax;
L_0x0047f10f:
    // 0047f10f  a1e8a64c00             -mov eax, dword ptr [0x4ca6e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023464) /* 0x4ca6e8 */);
    // 0047f114  c1e502                 -shl ebp, 2
    cpu.ebp <<= 2 /*0x2*/ % 32;
    // 0047f117  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0047f119  8bac240c020000         -mov ebp, dword ptr [esp + 0x20c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(524) /* 0x20c */);
    // 0047f120  89842400020000         -mov dword ptr [esp + 0x200], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(512) /* 0x200 */) = cpu.eax;
    // 0047f127  a1eca64c00             -mov eax, dword ptr [0x4ca6ec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5023468) /* 0x4ca6ec */);
    // 0047f12c  c1e502                 -shl ebp, 2
    cpu.ebp <<= 2 /*0x2*/ % 32;
    // 0047f12f  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0047f131  8bac2400020000         -mov ebp, dword ptr [esp + 0x200]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(512) /* 0x200 */);
    // 0047f138  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 0047f13a  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp);
    // 0047f13d  8b84241c020000         -mov eax, dword ptr [esp + 0x21c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(540) /* 0x21c */);
    // 0047f144  01dd                   -add ebp, ebx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0047f146  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047f148  750b                   -jne 0x47f155
    if (!cpu.flags.zf)
    {
        goto L_0x0047f155;
    }
    // 0047f14a  c784241c020000e2114900 -mov dword ptr [esp + 0x21c], 0x4911e2
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(540) /* 0x21c */) = 4788706 /*0x4911e2*/;
L_0x0047f155:
    // 0047f155  85c9                   -test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047f157  8b842420020000         -mov eax, dword ptr [esp + 0x220]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(544) /* 0x220 */);
    // 0047f15e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047f15f  8b9c240c020000         -mov ebx, dword ptr [esp + 0x20c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(524) /* 0x20c */);
    // 0047f166  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047f167  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0047f169  b83cae5200             -mov eax, 0x52ae3c
    cpu.eax = 5418556 /*0x52ae3c*/;
    // 0047f16e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047f170  e8fbc30100             -call 0x49b570
    cpu.esp -= 4;
    sub_49b570(app, cpu);
    if (cpu.terminate) return;
    // 0047f175  8b842410020000         -mov eax, dword ptr [esp + 0x210]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(528) /* 0x210 */);
    // 0047f17c  ba3cae5200             -mov edx, 0x52ae3c
    cpu.edx = 5418556 /*0x52ae3c*/;
    // 0047f181  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0047f184  e847200100             -call 0x4911d0
    cpu.esp -= 4;
    sub_4911d0(app, cpu);
    if (cpu.terminate) return;
L_0x0047f189:
    // 0047f189  4e                     -dec esi
    (cpu.esi)--;
    // 0047f18a  83feff                 +cmp esi, -1
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
    // 0047f18d  0f8483fdffff           -je 0x47ef16
    if (cpu.flags.zf)
    {
        goto L_0x0047ef16;
    }
    // 0047f193  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0047f195  8b942414020000         -mov edx, dword ptr [esp + 0x214]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(532) /* 0x214 */);
    // 0047f19c  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0047f19f  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0047f1a2  8b8c2420020000         -mov ecx, dword ptr [esp + 0x220]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(544) /* 0x220 */);
    // 0047f1a9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047f1aa  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047f1ab  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047f1ac  ff942428020000         -call dword ptr [esp + 0x228]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(552) /* 0x228 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047f1b3  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0047f1b6  8b1de4a64c00           -mov ebx, dword ptr [0x4ca6e4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5023460) /* 0x4ca6e4 */);
    // 0047f1bc  8b842418020000         -mov eax, dword ptr [esp + 0x218]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(536) /* 0x218 */);
    // 0047f1c3  01dd                   -add ebp, ebx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0047f1c5  01c7                   +add edi, eax
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047f1c7  ebc0                   -jmp 0x47f189
    goto L_0x0047f189;
L_0x0047f1c9:
    // 0047f1c9  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047f1cb  f7d8                   +neg eax
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
    // 0047f1cd  e907feffff             -jmp 0x47efd9
    goto L_0x0047efd9;
L_0x0047f1d2:
    // 0047f1d2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047f1d4  f7d8                   +neg eax
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
    // 0047f1d6  e91ffeffff             -jmp 0x47effa
    goto L_0x0047effa;
L_0x0047f1db:
    // 0047f1db  f7de                   -neg esi
    cpu.esi = ~cpu.esi + 1;
    // 0047f1dd  01c7                   +add edi, eax
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047f1df  e979feffff             -jmp 0x47f05d
    goto L_0x0047f05d;
L_0x0047f1e4:
    // 0047f1e4  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047f1e6  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 0047f1e8  89842420020000         -mov dword ptr [esp + 0x220], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(544) /* 0x220 */) = cpu.eax;
    // 0047f1ef  8b842408020000         -mov eax, dword ptr [esp + 0x208]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(520) /* 0x208 */);
    // 0047f1f6  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0047f1f9  01c2                   +add edx, eax
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
    // 0047f1fb  e979feffff             -jmp 0x47f079
    goto L_0x0047f079;
L_0x0047f200:
    // 0047f200  0f77                   -emms 
    cpu.mmx.init();
    // 0047f202  81c424020000           -add esp, 0x224
    (cpu.esp) += x86::reg32(x86::sreg32(548 /*0x224*/));
    // 0047f208  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f209  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f20a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f20b  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47f210(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047f210  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047f211  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047f212  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047f213  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0047f216  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047f218  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0047f21a  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0047f21d  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 0047f21f  8b4002                 -mov eax, dword ptr [eax + 2]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 0047f222  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0047f225  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047f227  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0047f22b  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0047f22e  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047f232  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047f234  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0047f237  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0047f239  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0047f23c  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0047f240  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 0047f243  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0047f246  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047f248  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047f24a  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0047f24d  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0047f24f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047f251  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047f253  7d50                   -jge 0x47f2a5
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047f2a5;
    }
    // 0047f255  8b5606                 -mov edx, dword ptr [esi + 6]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 0047f258  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047f25c  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0047f25f  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0047f261  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047f263  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047f265  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0047f267  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0047f26a  c1e810                 +shr eax, 0x10
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
    // 0047f26d  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0047f26f  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
L_0x0047f271:
    // 0047f271  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0047f273  7c46                   -jl 0x47f2bb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047f2bb;
    }
    // 0047f275  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0047f278  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047f27a  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0047f27d  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 0047f280  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0047f282  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0047f285  c1e810                 +shr eax, 0x10
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
    // 0047f288  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0047f28a  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
L_0x0047f28c:
    // 0047f28c  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0047f290  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0047f292  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047f293  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0047f295  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047f297  e8f4fbffff             -call 0x47ee90
    cpu.esp -= 4;
    sub_47ee90(app, cpu);
    if (cpu.terminate) return;
    // 0047f29c  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0047f29f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f2a0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f2a1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f2a2  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0047f2a5:
    // 0047f2a5  8b5606                 -mov edx, dword ptr [esi + 6]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 0047f2a8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047f2aa  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0047f2ad  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0047f2af  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0047f2b2  c1e810                 +shr eax, 0x10
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
    // 0047f2b5  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0047f2b7  29c5                   +sub ebp, eax
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047f2b9  ebb6                   -jmp 0x47f271
    goto L_0x0047f271;
L_0x0047f2bb:
    // 0047f2bb  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 0047f2be  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0047f2c1  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0047f2c4  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0047f2c7  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0047f2c9  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047f2cb  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 0047f2ce  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0047f2d0  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0047f2d3  c1e810                 +shr eax, 0x10
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
    // 0047f2d6  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0047f2d8  01c3                   +add ebx, eax
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
    // 0047f2da  ebb0                   -jmp 0x47f28c
    goto L_0x0047f28c;
}

/* align: skip  */
void Application::sub_47f2dc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047f2dc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047f2dd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047f2de  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047f2df  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0047f2e1  8b700c                 -mov esi, dword ptr [eax + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0047f2e4  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0047f2e7  c1e614                 -shl esi, 0x14
    cpu.esi <<= 20 /*0x14*/ % 32;
    // 0047f2ea  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 0047f2ed  c1fe14                 -sar esi, 0x14
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (20 /*0x14*/ % 32));
    // 0047f2f0  c1fb14                 -sar ebx, 0x14
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (20 /*0x14*/ % 32));
    // 0047f2f3  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0047f2f5  e896fbffff             -call 0x47ee90
    cpu.esp -= 4;
    sub_47ee90(app, cpu);
    if (cpu.terminate) return;
    // 0047f2fa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f2fb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f2fc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47f300(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047f300  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047f301  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047f302  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0047f304  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0047f306  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047f30a  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047f30c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047f30d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047f30f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047f311  e87afbffff             -call 0x47ee90
    cpu.esp -= 4;
    sub_47ee90(app, cpu);
    if (cpu.terminate) return;
    // 0047f316  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f317  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f318  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x90 */
void Application::sub_47f31c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047f31c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047f31d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047f31e  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0047f320  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0047f322  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047f326  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047f328  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047f329  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047f32b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047f32d  e8defeffff             -call 0x47f210
    cpu.esp -= 4;
    sub_47f210(app, cpu);
    if (cpu.terminate) return;
    // 0047f332  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f333  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f334  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x90 */
void Application::sub_47f338(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047f338  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047f339  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0047f33b  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0047f33d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047f33f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047f341  e896ffffff             -call 0x47f2dc
    cpu.esp -= 4;
    sub_47f2dc(app, cpu);
    if (cpu.terminate) return;
    // 0047f346  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f347  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_47f350(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047f350  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047f351  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047f353  a120ae5200             -mov eax, dword ptr [0x52ae20]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5418528) /* 0x52ae20 */);
    // 0047f358  e86b180000             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 0047f35d  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0047f35f  7423                   -je 0x47f384
    if (cpu.flags.zf)
    {
        goto L_0x0047f384;
    }
    // 0047f361  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047f362  e8e9830000             -call 0x487750
    cpu.esp -= 4;
    sub_487750(app, cpu);
    if (cpu.terminate) return;
    // 0047f367  8b0dc4dc5100           -mov ecx, dword ptr [0x51dcc4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5364932) /* 0x51dcc4 */);
    // 0047f36d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047f36f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047f371  ff152caf4c00           -call dword ptr [0x4caf2c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5025580) /* 0x4caf2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047f377  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f378  a120ae5200             -mov eax, dword ptr [0x52ae20]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5418528) /* 0x52ae20 */);
    // 0047f37d  e85e180000             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 0047f382  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f383  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047f384:
    // 0047f384  ff1530af4c00           -call dword ptr [0x4caf30]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5025584) /* 0x4caf30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047f38a  a120ae5200             -mov eax, dword ptr [0x52ae20]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5418528) /* 0x52ae20 */);
    // 0047f38f  e84c180000             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 0047f394  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f395  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47f398(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047f398  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047f399  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047f39a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047f39b  833d14af4c0000         +cmp dword ptr [0x4caf14], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5025556) /* 0x4caf14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f3a2  7406                   -je 0x47f3aa
    if (cpu.flags.zf)
    {
        goto L_0x0047f3aa;
    }
    // 0047f3a4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047f3a6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f3a7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f3a8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f3a9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047f3aa:
    // 0047f3aa  68bc024c00             -push 0x4c02bc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4981436 /*0x4c02bc*/;
    cpu.esp -= 4;
    // 0047f3af  2eff1540754b00         -call dword ptr cs:[0x4b7540]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945216) /* 0x4b7540 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047f3b6  a314af4c00             -mov dword ptr [0x4caf14], eax
    app->getMemory<x86::reg32>(x86::reg32(5025556) /* 0x4caf14 */) = cpu.eax;
    // 0047f3bb  83f820                 +cmp eax, 0x20
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
    // 0047f3be  7d10                   -jge 0x47f3d0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047f3d0;
    }
    // 0047f3c0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047f3c2  a314af4c00             -mov dword ptr [0x4caf14], eax
    app->getMemory<x86::reg32>(x86::reg32(5025556) /* 0x4caf14 */) = cpu.eax;
    // 0047f3c7  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0047f3cc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f3cd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f3ce  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f3cf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047f3d0:
    // 0047f3d0  68c8024c00             -push 0x4c02c8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4981448 /*0x4c02c8*/;
    cpu.esp -= 4;
    // 0047f3d5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047f3d6  2eff1510754b00         -call dword ptr cs:[0x4b7510]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945168) /* 0x4b7510 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047f3dd  ffd0                   -call eax
    cpu.ip = cpu.eax;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047f3df  3d02000600             +cmp eax, 0x60002
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(393218 /*0x60002*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f3e4  7409                   -je 0x47f3ef
    if (cpu.flags.zf)
    {
        goto L_0x0047f3ef;
    }
    // 0047f3e6  b8f5ffffff             -mov eax, 0xfffffff5
    cpu.eax = 4294967285 /*0xfffffff5*/;
    // 0047f3eb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f3ec  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f3ed  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f3ee  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047f3ef:
    // 0047f3ef  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047f3f0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047f3f1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047f3f2  68d8024c00             -push 0x4c02d8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4981464 /*0x4c02d8*/;
    cpu.esp -= 4;
    // 0047f3f7  8b0d14af4c00           -mov ecx, dword ptr [0x4caf14]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5025556) /* 0x4caf14 */);
    // 0047f3fd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047f3fe  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047f400  2eff1510754b00         -call dword ptr cs:[0x4b7510]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945168) /* 0x4b7510 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047f407  68a17a4900             -push 0x497aa1
    app->getMemory<x86::reg32>(cpu.esp-4) = 4815521 /*0x497aa1*/;
    cpu.esp -= 4;
    // 0047f40c  8b0dc4cd4c00           -mov ecx, dword ptr [0x4ccdc4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5033412) /* 0x4ccdc4 */);
    // 0047f412  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047f414  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047f416  b8bcc34900             -mov eax, 0x49c3bc
    cpu.eax = 4834236 /*0x49c3bc*/;
    // 0047f41b  ffd6                   -call esi
    cpu.ip = cpu.esi;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047f41d  68f0024c00             -push 0x4c02f0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4981488 /*0x4c02f0*/;
    cpu.esp -= 4;
    // 0047f422  8b1d14af4c00           -mov ebx, dword ptr [0x4caf14]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5025556) /* 0x4caf14 */);
    // 0047f428  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047f429  2eff1510754b00         -call dword ptr cs:[0x4b7510]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945168) /* 0x4b7510 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047f430  6800034c00             -push 0x4c0300
    app->getMemory<x86::reg32>(cpu.esp-4) = 4981504 /*0x4c0300*/;
    cpu.esp -= 4;
    // 0047f435  8b3514af4c00           -mov esi, dword ptr [0x4caf14]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5025556) /* 0x4caf14 */);
    // 0047f43b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047f43c  a328af4c00             -mov dword ptr [0x4caf28], eax
    app->getMemory<x86::reg32>(x86::reg32(5025576) /* 0x4caf28 */) = cpu.eax;
    // 0047f441  2eff1510754b00         -call dword ptr cs:[0x4b7510]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945168) /* 0x4b7510 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047f448  6814034c00             -push 0x4c0314
    app->getMemory<x86::reg32>(cpu.esp-4) = 4981524 /*0x4c0314*/;
    cpu.esp -= 4;
    // 0047f44d  8b3d14af4c00           -mov edi, dword ptr [0x4caf14]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5025556) /* 0x4caf14 */);
    // 0047f453  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047f454  a32caf4c00             -mov dword ptr [0x4caf2c], eax
    app->getMemory<x86::reg32>(x86::reg32(5025580) /* 0x4caf2c */) = cpu.eax;
    // 0047f459  2eff1510754b00         -call dword ptr cs:[0x4b7510]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945168) /* 0x4b7510 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047f460  6824034c00             -push 0x4c0324
    app->getMemory<x86::reg32>(cpu.esp-4) = 4981540 /*0x4c0324*/;
    cpu.esp -= 4;
    // 0047f465  8b2d14af4c00           -mov ebp, dword ptr [0x4caf14]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5025556) /* 0x4caf14 */);
    // 0047f46b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047f46c  a330af4c00             -mov dword ptr [0x4caf30], eax
    app->getMemory<x86::reg32>(x86::reg32(5025584) /* 0x4caf30 */) = cpu.eax;
    // 0047f471  2eff1510754b00         -call dword ptr cs:[0x4b7510]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945168) /* 0x4b7510 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047f478  a334af4c00             -mov dword ptr [0x4caf34], eax
    app->getMemory<x86::reg32>(x86::reg32(5025588) /* 0x4caf34 */) = cpu.eax;
    // 0047f47d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f47e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f47f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f480  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047f482  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f483  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f484  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f485  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47f488(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047f488  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047f489  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047f48a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047f48b  8b1514af4c00           -mov edx, dword ptr [0x4caf14]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5025556) /* 0x4caf14 */);
    // 0047f491  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047f493  750e                   -jne 0x47f4a3
    if (!cpu.flags.zf)
    {
        goto L_0x0047f4a3;
    }
    // 0047f495  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047f497  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047f499  891d14af4c00           -mov dword ptr [0x4caf14], ebx
    app->getMemory<x86::reg32>(x86::reg32(5025556) /* 0x4caf14 */) = cpu.ebx;
    // 0047f49f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f4a0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f4a1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f4a2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047f4a3:
    // 0047f4a3  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047f4a4  2eff1598744b00         -call dword ptr cs:[0x4b7498]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945048) /* 0x4b7498 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047f4ab  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047f4ad  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047f4af  891d14af4c00           -mov dword ptr [0x4caf14], ebx
    app->getMemory<x86::reg32>(x86::reg32(5025556) /* 0x4caf14 */) = cpu.ebx;
    // 0047f4b5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f4b6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f4b7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f4b8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47f4bc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047f4bc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047f4bd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047f4be  e8d5feffff             -call 0x47f398
    cpu.esp -= 4;
    sub_47f398(app, cpu);
    if (cpu.terminate) return;
    // 0047f4c3  e888820000             -call 0x487750
    cpu.esp -= 4;
    sub_487750(app, cpu);
    if (cpu.terminate) return;
    // 0047f4c8  ff1528af4c00           -call dword ptr [0x4caf28]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5025576) /* 0x4caf28 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047f4ce  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047f4d0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047f4d2  7e06                   -jle 0x47f4da
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047f4da;
    }
    // 0047f4d4  81ca00000100           -or edx, 0x10000
    cpu.edx |= x86::reg32(x86::sreg32(65536 /*0x10000*/));
L_0x0047f4da:
    // 0047f4da  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047f4dc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f4dd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f4de  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_47f4e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047f4e0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047f4e1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047f4e2  be18af4c00             -mov esi, 0x4caf18
    cpu.esi = 5025560 /*0x4caf18*/;
    // 0047f4e7  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0047f4e9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047f4eb  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0047f4ec  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0047f4ed  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0047f4ee  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0047f4ef  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f4f0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f4f1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47f4f4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047f4f4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047f4f5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047f4f6  bf18af4c00             -mov edi, 0x4caf18
    cpu.edi = 5025560 /*0x4caf18*/;
    // 0047f4fb  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047f4fd  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0047f4fe  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0047f4ff  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0047f500  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 0047f501  803d1eaf4c0010         +cmp byte ptr [0x4caf1e], 0x10
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5025566) /* 0x4caf1e */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047f508  7608                   -jbe 0x47f512
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0047f512;
    }
    // 0047f50a  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 0047f50f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f510  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f511  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047f512:
    // 0047f512  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047f514  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f515  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f516  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_47f518(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047f518  a310af4c00             -mov dword ptr [0x4caf10], eax
    app->getMemory<x86::reg32>(x86::reg32(5025552) /* 0x4caf10 */) = cpu.eax;
    // 0047f51d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047f51f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47f520(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047f520  803db0cd4c0000         +cmp byte ptr [0x4ccdb0], 0
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
    // 0047f527  7506                   -jne 0x47f52f
    if (!cpu.flags.zf)
    {
        goto L_0x0047f52f;
    }
    // 0047f529  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 0047f52e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047f52f:
    // 0047f52f  a120ae5200             -mov eax, dword ptr [0x52ae20]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5418528) /* 0x52ae20 */);
    // 0047f534  e88f160000             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 0047f539  ff1530af4c00           -call dword ptr [0x4caf30]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5025584) /* 0x4caf30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047f53f  a120ae5200             -mov eax, dword ptr [0x52ae20]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5418528) /* 0x52ae20 */);
    // 0047f544  e897160000             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 0047f549  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047f54b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47f54c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047f54c  803db0cd4c0000         +cmp byte ptr [0x4ccdb0], 0
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
    // 0047f553  7506                   -jne 0x47f55b
    if (!cpu.flags.zf)
    {
        goto L_0x0047f55b;
    }
    // 0047f555  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 0047f55a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047f55b:
    // 0047f55b  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047f55c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047f55d  a120ae5200             -mov eax, dword ptr [0x52ae20]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5418528) /* 0x52ae20 */);
    // 0047f562  e861160000             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 0047f567  e8e4810000             -call 0x487750
    cpu.esp -= 4;
    sub_487750(app, cpu);
    if (cpu.terminate) return;
    // 0047f56c  8b0dc4dc5100           -mov ecx, dword ptr [0x51dcc4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5364932) /* 0x51dcc4 */);
    // 0047f572  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047f574  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047f576  ff152caf4c00           -call dword ptr [0x4caf2c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5025580) /* 0x4caf2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047f57c  a120ae5200             -mov eax, dword ptr [0x52ae20]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5418528) /* 0x52ae20 */);
    // 0047f581  e85a160000             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 0047f586  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047f588  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f589  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f58a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_47f58c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047f58c  a120ae5200             -mov eax, dword ptr [0x52ae20]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5418528) /* 0x52ae20 */);
    // 0047f591  e832160000             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 0047f596  ff1534af4c00           -call dword ptr [0x4caf34]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5025588) /* 0x4caf34 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047f59c  a120ae5200             -mov eax, dword ptr [0x52ae20]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5418528) /* 0x52ae20 */);
    // 0047f5a1  e93a160000             -jmp 0x480be0
    return sub_480be0(app, cpu);
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47f5a8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047f5a8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047f5a9  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047f5ac  837c241c00             +cmp dword ptr [esp + 0x1c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f5b1  7443                   -je 0x47f5f6
    if (cpu.flags.zf)
    {
        goto L_0x0047f5f6;
    }
    // 0047f5b3  803d04af4c0000         +cmp byte ptr [0x4caf04], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5025540) /* 0x4caf04 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047f5ba  0f8588010000           -jne 0x47f748
    if (!cpu.flags.zf)
    {
        goto L_0x0047f748;
    }
L_0x0047f5c0:
    // 0047f5c0  803d05af4c0000         +cmp byte ptr [0x4caf05], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5025541) /* 0x4caf05 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047f5c7  740f                   -je 0x47f5d8
    if (cpu.flags.zf)
    {
        goto L_0x0047f5d8;
    }
    // 0047f5c9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047f5cb  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 0047f5cd  e8ae86ffff             -call 0x477c80
    cpu.esp -= 4;
    sub_477c80(app, cpu);
    if (cpu.terminate) return;
    // 0047f5d2  881d05af4c00           -mov byte ptr [0x4caf05], bl
    app->getMemory<x86::reg8>(x86::reg32(5025541) /* 0x4caf05 */) = cpu.bl;
L_0x0047f5d8:
    // 0047f5d8  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047f5da  ff1530af4c00           -call dword ptr [0x4caf30]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5025584) /* 0x4caf30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x0047f5e0:
    // 0047f5e0  890d08af4c00           -mov dword ptr [0x4caf08], ecx
    app->getMemory<x86::reg32>(x86::reg32(5025544) /* 0x4caf08 */) = cpu.ecx;
L_0x0047f5e6:
    // 0047f5e6  c60507af4c0001         -mov byte ptr [0x4caf07], 1
    app->getMemory<x86::reg8>(x86::reg32(5025543) /* 0x4caf07 */) = 1 /*0x1*/;
    // 0047f5ed  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047f5ef  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047f5f2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f5f3  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x0047f5f6:
    // 0047f5f6  a1c0dc5100             -mov eax, dword ptr [0x51dcc0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364928) /* 0x51dcc0 */);
    // 0047f5fb  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0047f5fe  e84d810000             -call 0x487750
    cpu.esp -= 4;
    sub_487750(app, cpu);
    if (cpu.terminate) return;
    // 0047f603  ff1528af4c00           -call dword ptr [0x4caf28]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5025576) /* 0x4caf28 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047f609  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047f60b  0f8eb8000000           -jle 0x47f6c9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047f6c9;
    }
    // 0047f611  8a7c2401               -mov bh, byte ptr [esp + 1]
    cpu.bh = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */);
    // 0047f615  f6c708                 +test bh, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 8 /*0x8*/));
    // 0047f618  0f84c0000000           -je 0x47f6de
    if (cpu.flags.zf)
    {
        goto L_0x0047f6de;
    }
    // 0047f61e  c7050caf4c0022560000   -mov dword ptr [0x4caf0c], 0x5622
    app->getMemory<x86::reg32>(x86::reg32(5025548) /* 0x4caf0c */) = 22050 /*0x5622*/;
L_0x0047f628:
    // 0047f628  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0047f62b  8a1506af4c00           -mov dl, byte ptr [0x4caf06]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5025542) /* 0x4caf06 */);
    // 0047f631  a3c4dc5100             -mov dword ptr [0x51dcc4], eax
    app->getMemory<x86::reg32>(x86::reg32(5364932) /* 0x51dcc4 */) = cpu.eax;
    // 0047f636  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 0047f638  7512                   -jne 0x47f64c
    if (!cpu.flags.zf)
    {
        goto L_0x0047f64c;
    }
    // 0047f63a  b840074900             -mov eax, 0x490740
    cpu.eax = 4785984 /*0x490740*/;
    // 0047f63f  b601                   -mov dh, 1
    cpu.dh = 1 /*0x1*/;
    // 0047f641  e896100100             -call 0x4906dc
    cpu.esp -= 4;
    sub_4906dc(app, cpu);
    if (cpu.terminate) return;
    // 0047f646  883506af4c00           -mov byte ptr [0x4caf06], dh
    app->getMemory<x86::reg8>(x86::reg32(5025542) /* 0x4caf06 */) = cpu.dh;
L_0x0047f64c:
    // 0047f64c  bac8904900             -mov edx, 0x4990c8
    cpu.edx = 4821192 /*0x4990c8*/;
    // 0047f651  a1c4dc5100             -mov eax, dword ptr [0x51dcc4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364932) /* 0x51dcc4 */);
    // 0047f656  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 0047f65b  e8c8c00100             -call 0x49b728
    cpu.esp -= 4;
    sub_49b728(app, cpu);
    if (cpu.terminate) return;
    // 0047f660  8b15c0a75200           -mov edx, dword ptr [0x52a7c0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5416896) /* 0x52a7c0 */);
    // 0047f666  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0047f668  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047f66a  e8ed000000             -call 0x47f75c
    cpu.esp -= 4;
    sub_47f75c(app, cpu);
    if (cpu.terminate) return;
    // 0047f66f  e8dc800000             -call 0x487750
    cpu.esp -= 4;
    sub_487750(app, cpu);
    if (cpu.terminate) return;
    // 0047f674  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0047f676  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0047f679  ff152caf4c00           -call dword ptr [0x4caf2c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5025580) /* 0x4caf2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0047f67f  a308af4c00             -mov dword ptr [0x4caf08], eax
    app->getMemory<x86::reg32>(x86::reg32(5025544) /* 0x4caf08 */) = cpu.eax;
    // 0047f684  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047f686  0f8c5affffff           -jl 0x47f5e6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047f5e6;
    }
    // 0047f68c  803d04af4c0000         +cmp byte ptr [0x4caf04], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5025540) /* 0x4caf04 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047f693  7512                   -jne 0x47f6a7
    if (!cpu.flags.zf)
    {
        goto L_0x0047f6a7;
    }
    // 0047f695  b88cf54700             -mov eax, 0x47f58c
    cpu.eax = 4715916 /*0x47f58c*/;
    // 0047f69a  b701                   -mov bh, 1
    cpu.bh = 1 /*0x1*/;
    // 0047f69c  e8bb9fffff             -call 0x47965c
    cpu.esp -= 4;
    sub_47965c(app, cpu);
    if (cpu.terminate) return;
    // 0047f6a1  883d04af4c00           -mov byte ptr [0x4caf04], bh
    app->getMemory<x86::reg8>(x86::reg32(5025540) /* 0x4caf04 */) = cpu.bh;
L_0x0047f6a7:
    // 0047f6a7  803d05af4c0000         +cmp byte ptr [0x4caf05], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5025541) /* 0x4caf05 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047f6ae  7512                   -jne 0x47f6c2
    if (!cpu.flags.zf)
    {
        goto L_0x0047f6c2;
    }
    // 0047f6b0  b850f34700             -mov eax, 0x47f350
    cpu.eax = 4715344 /*0x47f350*/;
    // 0047f6b5  b501                   -mov ch, 1
    cpu.ch = 1 /*0x1*/;
    // 0047f6b7  e8c485ffff             -call 0x477c80
    cpu.esp -= 4;
    sub_477c80(app, cpu);
    if (cpu.terminate) return;
    // 0047f6bc  882d05af4c00           -mov byte ptr [0x4caf05], ch
    app->getMemory<x86::reg8>(x86::reg32(5025541) /* 0x4caf05 */) = cpu.ch;
L_0x0047f6c2:
    // 0047f6c2  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0047f6c4  e917ffffff             -jmp 0x47f5e0
    goto L_0x0047f5e0;
L_0x0047f6c9:
    // 0047f6c9  a308af4c00             -mov dword ptr [0x4caf08], eax
    app->getMemory<x86::reg32>(x86::reg32(5025544) /* 0x4caf08 */) = cpu.eax;
    // 0047f6ce  c60507af4c0001         -mov byte ptr [0x4caf07], 1
    app->getMemory<x86::reg8>(x86::reg32(5025543) /* 0x4caf07 */) = 1 /*0x1*/;
    // 0047f6d5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047f6d7  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047f6da  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f6db  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x0047f6de:
    // 0047f6de  f6c704                 +test bh, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 4 /*0x4*/));
    // 0047f6e1  740f                   -je 0x47f6f2
    if (cpu.flags.zf)
    {
        goto L_0x0047f6f2;
    }
    // 0047f6e3  c7050caf4c00803e0000   -mov dword ptr [0x4caf0c], 0x3e80
    app->getMemory<x86::reg32>(x86::reg32(5025548) /* 0x4caf0c */) = 16000 /*0x3e80*/;
    // 0047f6ed  e936ffffff             -jmp 0x47f628
    goto L_0x0047f628;
L_0x0047f6f2:
    // 0047f6f2  f6c710                 +test bh, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 16 /*0x10*/));
    // 0047f6f5  740f                   -je 0x47f706
    if (cpu.flags.zf)
    {
        goto L_0x0047f706;
    }
    // 0047f6f7  c7050caf4c00007d0000   -mov dword ptr [0x4caf0c], 0x7d00
    app->getMemory<x86::reg32>(x86::reg32(5025548) /* 0x4caf0c */) = 32000 /*0x7d00*/;
    // 0047f701  e922ffffff             -jmp 0x47f628
    goto L_0x0047f628;
L_0x0047f706:
    // 0047f706  f6c720                 +test bh, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 32 /*0x20*/));
    // 0047f709  740f                   -je 0x47f71a
    if (cpu.flags.zf)
    {
        goto L_0x0047f71a;
    }
    // 0047f70b  c7050caf4c0044ac0000   -mov dword ptr [0x4caf0c], 0xac44
    app->getMemory<x86::reg32>(x86::reg32(5025548) /* 0x4caf0c */) = 44100 /*0xac44*/;
    // 0047f715  e90effffff             -jmp 0x47f628
    goto L_0x0047f628;
L_0x0047f71a:
    // 0047f71a  f6c702                 +test bh, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 2 /*0x2*/));
    // 0047f71d  740f                   -je 0x47f72e
    if (cpu.flags.zf)
    {
        goto L_0x0047f72e;
    }
    // 0047f71f  c7050caf4c00112b0000   -mov dword ptr [0x4caf0c], 0x2b11
    app->getMemory<x86::reg32>(x86::reg32(5025548) /* 0x4caf0c */) = 11025 /*0x2b11*/;
    // 0047f729  e9fafeffff             -jmp 0x47f628
    goto L_0x0047f628;
L_0x0047f72e:
    // 0047f72e  c70508af4c00f8ffffff   -mov dword ptr [0x4caf08], 0xfffffff8
    app->getMemory<x86::reg32>(x86::reg32(5025544) /* 0x4caf08 */) = 4294967288 /*0xfffffff8*/;
    // 0047f738  c60507af4c0001         -mov byte ptr [0x4caf07], 1
    app->getMemory<x86::reg8>(x86::reg32(5025543) /* 0x4caf07 */) = 1 /*0x1*/;
    // 0047f73f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047f741  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0047f744  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f745  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x0047f748:
    // 0047f748  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 0047f74a  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047f74c  881504af4c00           -mov byte ptr [0x4caf04], dl
    app->getMemory<x86::reg8>(x86::reg32(5025540) /* 0x4caf04 */) = cpu.dl;
    // 0047f752  e8059fffff             -call 0x47965c
    cpu.esp -= 4;
    sub_47965c(app, cpu);
    if (cpu.terminate) return;
    // 0047f757  e964feffff             -jmp 0x47f5c0
    goto L_0x0047f5c0;
}

/* align: skip  */
void Application::sub_47f75c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047f75c  83fa28                 +cmp edx, 0x28
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(40 /*0x28*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f75f  7316                   -jae 0x47f777
    if (!cpu.flags.cf)
    {
        goto L_0x0047f777;
    }
    // 0047f761  83fa0a                 +cmp edx, 0xa
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
    // 0047f764  720e                   -jb 0x47f774
    if (cpu.flags.cf)
    {
        goto L_0x0047f774;
    }
    // 0047f766  761b                   -jbe 0x47f783
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0047f783;
    }
    // 0047f768  83fa14                 +cmp edx, 0x14
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(20 /*0x14*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f76b  7207                   -jb 0x47f774
    if (cpu.flags.cf)
    {
        goto L_0x0047f774;
    }
    // 0047f76d  7614                   -jbe 0x47f783
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0047f783;
    }
    // 0047f76f  83fa1e                 +cmp edx, 0x1e
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(30 /*0x1e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f772  740f                   -je 0x47f783
    if (cpu.flags.zf)
    {
        goto L_0x0047f783;
    }
L_0x0047f774:
    // 0047f774  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047f776  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047f777:
    // 0047f777  760a                   -jbe 0x47f783
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0047f783;
    }
    // 0047f779  83fa64                 +cmp edx, 0x64
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(100 /*0x64*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f77c  7312                   -jae 0x47f790
    if (!cpu.flags.cf)
    {
        goto L_0x0047f790;
    }
    // 0047f77e  83fa32                 +cmp edx, 0x32
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(50 /*0x32*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f781  75f1                   -jne 0x47f774
    if (!cpu.flags.zf)
    {
        goto L_0x0047f774;
    }
L_0x0047f783:
    // 0047f783  a10caf4c00             -mov eax, dword ptr [0x4caf0c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5025548) /* 0x4caf0c */);
    // 0047f788  e8cfcc0100             -call 0x49c45c
    cpu.esp -= 4;
    sub_49c45c(app, cpu);
    if (cpu.terminate) return;
    // 0047f78d  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047f78f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047f790:
    // 0047f790  76f1                   -jbe 0x47f783
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0047f783;
    }
    // 0047f792  83fa6e                 +cmp edx, 0x6e
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(110 /*0x6e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f795  72dd                   -jb 0x47f774
    if (cpu.flags.cf)
    {
        goto L_0x0047f774;
    }
    // 0047f797  76ea                   -jbe 0x47f783
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0047f783;
    }
    // 0047f799  83fa78                 +cmp edx, 0x78
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(120 /*0x78*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f79c  74e5                   -je 0x47f783
    if (cpu.flags.zf)
    {
        goto L_0x0047f783;
    }
    // 0047f79e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047f7a0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47f7a4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047f7a4  803db0cd4c0000         +cmp byte ptr [0x4ccdb0], 0
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
    // 0047f7ab  75af                   -jne 0x47f75c
    if (!cpu.flags.zf)
    {
        return sub_47f75c(app, cpu);
    }
    // 0047f7ad  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
    // 0047f7b0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047f7b2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47f7b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0047f7b0;
    // 0047f7a4  803db0cd4c0000         +cmp byte ptr [0x4ccdb0], 0
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
    // 0047f7ab  75af                   -jne 0x47f75c
    if (!cpu.flags.zf)
    {
        return sub_47f75c(app, cpu);
    }
    // 0047f7ad  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_entry_0x0047f7b0:
    // 0047f7b0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047f7b2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_47f7b4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047f7b4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047f7b5  a3c0dc5100             -mov dword ptr [0x51dcc0], eax
    app->getMemory<x86::reg32>(x86::reg32(5364928) /* 0x51dcc0 */) = cpu.eax;
    // 0047f7ba  e8d9fbffff             -call 0x47f398
    cpu.esp -= 4;
    sub_47f398(app, cpu);
    if (cpu.terminate) return;
    // 0047f7bf  833d20a44c0000         +cmp dword ptr [0x4ca420], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5022752) /* 0x4ca420 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f7c6  7507                   -jne 0x47f7cf
    if (!cpu.flags.zf)
    {
        goto L_0x0047f7cf;
    }
L_0x0047f7c8:
    // 0047f7c8  b8f0ffffff             -mov eax, 0xfffffff0
    cpu.eax = 4294967280 /*0xfffffff0*/;
    // 0047f7cd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f7ce  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047f7cf:
    // 0047f7cf  e87c7f0000             -call 0x487750
    cpu.esp -= 4;
    sub_487750(app, cpu);
    if (cpu.terminate) return;
    // 0047f7d4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047f7d6  74f0                   -je 0x47f7c8
    if (cpu.flags.zf)
    {
        goto L_0x0047f7c8;
    }
    // 0047f7d8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047f7d9  68a8f54700             -push 0x47f5a8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4715944 /*0x47f5a8*/;
    cpu.esp -= 4;
    // 0047f7de  6800820000             -push 0x8200
    app->getMemory<x86::reg32>(cpu.esp-4) = 33280 /*0x8200*/;
    cpu.esp -= 4;
    // 0047f7e3  e83885ffff             -call 0x477d20
    cpu.esp -= 4;
    sub_477d20(app, cpu);
    if (cpu.terminate) return;
    // 0047f7e8  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 0047f7ea  882507af4c00           -mov byte ptr [0x4caf07], ah
    app->getMemory<x86::reg8>(x86::reg32(5025543) /* 0x4caf07 */) = cpu.ah;
    // 0047f7f0  b800820000             -mov eax, 0x8200
    cpu.eax = 33280 /*0x8200*/;
    // 0047f7f5  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047f7f7  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047f7f9  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047f7fb  e89084ffff             -call 0x477c90
    cpu.esp -= 4;
    sub_477c90(app, cpu);
    if (cpu.terminate) return;
    // 0047f800  803d07af4c0000         +cmp byte ptr [0x4caf07], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5025543) /* 0x4caf07 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047f807  7513                   -jne 0x47f81c
    if (!cpu.flags.zf)
    {
        goto L_0x0047f81c;
    }
    // 0047f809  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0047f80b:
    // 0047f80b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047f80d  e80a100000             -call 0x48081c
    cpu.esp -= 4;
    sub_48081c(app, cpu);
    if (cpu.terminate) return;
    // 0047f812  3a1507af4c00           +cmp dl, byte ptr [0x4caf07]
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(x86::reg32(5025543) /* 0x4caf07 */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047f818  74f1                   -je 0x47f80b
    if (cpu.flags.zf)
    {
        goto L_0x0047f80b;
    }
    // 0047f81a  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x0047f81c:
    // 0047f81c  a108af4c00             -mov eax, dword ptr [0x4caf08]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5025544) /* 0x4caf08 */);
    // 0047f821  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f822  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f823  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_47f824(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047f824  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047f825  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047f826  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047f827  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 0047f829  882507af4c00           -mov byte ptr [0x4caf07], ah
    app->getMemory<x86::reg8>(x86::reg32(5025543) /* 0x4caf07 */) = cpu.ah;
    // 0047f82f  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0047f834  b800820000             -mov eax, 0x8200
    cpu.eax = 33280 /*0x8200*/;
    // 0047f839  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047f83b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047f83d  e84e84ffff             -call 0x477c90
    cpu.esp -= 4;
    sub_477c90(app, cpu);
    if (cpu.terminate) return;
    // 0047f842  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047f844  7420                   -je 0x47f866
    if (cpu.flags.zf)
    {
        goto L_0x0047f866;
    }
L_0x0047f846:
    // 0047f846  803d07af4c0000         +cmp byte ptr [0x4caf07], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5025543) /* 0x4caf07 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047f84d  740e                   -je 0x47f85d
    if (cpu.flags.zf)
    {
        goto L_0x0047f85d;
    }
    // 0047f84f  e834fcffff             -call 0x47f488
    cpu.esp -= 4;
    sub_47f488(app, cpu);
    if (cpu.terminate) return;
    // 0047f854  a108af4c00             -mov eax, dword ptr [0x4caf08]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5025544) /* 0x4caf08 */);
    // 0047f859  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f85a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f85b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f85c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047f85d:
    // 0047f85d  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0047f85f  e8b80f0000             -call 0x48081c
    cpu.esp -= 4;
    sub_48081c(app, cpu);
    if (cpu.terminate) return;
    // 0047f864  ebe0                   -jmp 0x47f846
    goto L_0x0047f846;
L_0x0047f866:
    // 0047f866  803d04af4c0000         +cmp byte ptr [0x4caf04], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5025540) /* 0x4caf04 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047f86d  740d                   -je 0x47f87c
    if (cpu.flags.zf)
    {
        goto L_0x0047f87c;
    }
    // 0047f86f  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 0047f871  883504af4c00           -mov byte ptr [0x4caf04], dh
    app->getMemory<x86::reg8>(x86::reg32(5025540) /* 0x4caf04 */) = cpu.dh;
    // 0047f877  e8e09dffff             -call 0x47965c
    cpu.esp -= 4;
    sub_47965c(app, cpu);
    if (cpu.terminate) return;
L_0x0047f87c:
    // 0047f87c  803d05af4c0000         +cmp byte ptr [0x4caf05], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5025541) /* 0x4caf05 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047f883  740f                   -je 0x47f894
    if (cpu.flags.zf)
    {
        goto L_0x0047f894;
    }
    // 0047f885  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047f887  30ff                   -xor bh, bh
    cpu.bh ^= x86::reg8(x86::sreg8(cpu.bh));
    // 0047f889  e8f283ffff             -call 0x477c80
    cpu.esp -= 4;
    sub_477c80(app, cpu);
    if (cpu.terminate) return;
    // 0047f88e  883d05af4c00           -mov byte ptr [0x4caf05], bh
    app->getMemory<x86::reg8>(x86::reg32(5025541) /* 0x4caf05 */) = cpu.bh;
L_0x0047f894:
    // 0047f894  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047f896  891508af4c00           -mov dword ptr [0x4caf08], edx
    app->getMemory<x86::reg32>(x86::reg32(5025544) /* 0x4caf08 */) = cpu.edx;
    // 0047f89c  e8e7fbffff             -call 0x47f488
    cpu.esp -= 4;
    sub_47f488(app, cpu);
    if (cpu.terminate) return;
    // 0047f8a1  a108af4c00             -mov eax, dword ptr [0x4caf08]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5025544) /* 0x4caf08 */);
    // 0047f8a6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f8a7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f8a8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f8a9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47f8ac(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047f8ac  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047f8ad  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047f8af  e86cfcffff             -call 0x47f520
    cpu.esp -= 4;
    sub_47f520(app, cpu);
    if (cpu.terminate) return;
    // 0047f8b4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047f8b6  7c5b                   -jl 0x47f913
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047f913;
    }
    // 0047f8b8  890dc4dc5100           -mov dword ptr [0x51dcc4], ecx
    app->getMemory<x86::reg32>(x86::reg32(5364932) /* 0x51dcc4 */) = cpu.ecx;
    // 0047f8be  f6c508                 +test ch, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 8 /*0x8*/));
    // 0047f8c1  7552                   -jne 0x47f915
    if (!cpu.flags.zf)
    {
        goto L_0x0047f915;
    }
    // 0047f8c3  f6c504                 +test ch, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 4 /*0x4*/));
    // 0047f8c6  7459                   -je 0x47f921
    if (cpu.flags.zf)
    {
        goto L_0x0047f921;
    }
    // 0047f8c8  c7050caf4c00803e0000   -mov dword ptr [0x4caf0c], 0x3e80
    app->getMemory<x86::reg32>(x86::reg32(5025548) /* 0x4caf0c */) = 16000 /*0x3e80*/;
L_0x0047f8d2:
    // 0047f8d2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047f8d4  e8a7c00100             -call 0x49b980
    cpu.esp -= 4;
    sub_49b980(app, cpu);
    if (cpu.terminate) return;
    // 0047f8d9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047f8db  7c36                   -jl 0x47f913
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047f913;
    }
    // 0047f8dd  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047f8de  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047f8e0  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0047f8e2:
    // 0047f8e2  80b9dca7520001         +cmp byte ptr [ecx + 0x52a7dc], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5416924) /* 0x52a7dc */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047f8e9  7519                   -jne 0x47f904
    if (!cpu.flags.zf)
    {
        goto L_0x0047f904;
    }
    // 0047f8eb  83b9d0a7520000         +cmp dword ptr [ecx + 0x52a7d0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5416912) /* 0x52a7d0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f8f2  7c10                   -jl 0x47f904
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047f904;
    }
    // 0047f8f4  8b91e0a75200           -mov edx, dword ptr [ecx + 0x52a7e0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5416928) /* 0x52a7e0 */);
    // 0047f8fa  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0047f8fc  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0047f8ff  e80c0a0000             -call 0x480310
    cpu.esp -= 4;
    sub_480310(app, cpu);
    if (cpu.terminate) return;
L_0x0047f904:
    // 0047f904  43                     -inc ebx
    (cpu.ebx)++;
    // 0047f905  83c160                 -add ecx, 0x60
    (cpu.ecx) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 0047f908  83fb10                 +cmp ebx, 0x10
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
    // 0047f90b  7cd5                   -jl 0x47f8e2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047f8e2;
    }
    // 0047f90d  e83afcffff             -call 0x47f54c
    cpu.esp -= 4;
    sub_47f54c(app, cpu);
    if (cpu.terminate) return;
    // 0047f912  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0047f913:
    // 0047f913  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f914  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047f915:
    // 0047f915  c7050caf4c0022560000   -mov dword ptr [0x4caf0c], 0x5622
    app->getMemory<x86::reg32>(x86::reg32(5025548) /* 0x4caf0c */) = 22050 /*0x5622*/;
    // 0047f91f  ebb1                   -jmp 0x47f8d2
    goto L_0x0047f8d2;
L_0x0047f921:
    // 0047f921  f6c510                 +test ch, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 16 /*0x10*/));
    // 0047f924  740c                   -je 0x47f932
    if (cpu.flags.zf)
    {
        goto L_0x0047f932;
    }
    // 0047f926  c7050caf4c00007d0000   -mov dword ptr [0x4caf0c], 0x7d00
    app->getMemory<x86::reg32>(x86::reg32(5025548) /* 0x4caf0c */) = 32000 /*0x7d00*/;
    // 0047f930  eba0                   -jmp 0x47f8d2
    goto L_0x0047f8d2;
L_0x0047f932:
    // 0047f932  f6c520                 +test ch, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 32 /*0x20*/));
    // 0047f935  740c                   -je 0x47f943
    if (cpu.flags.zf)
    {
        goto L_0x0047f943;
    }
    // 0047f937  c7050caf4c0044ac0000   -mov dword ptr [0x4caf0c], 0xac44
    app->getMemory<x86::reg32>(x86::reg32(5025548) /* 0x4caf0c */) = 44100 /*0xac44*/;
    // 0047f941  eb8f                   -jmp 0x47f8d2
    goto L_0x0047f8d2;
L_0x0047f943:
    // 0047f943  f6c502                 +test ch, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 2 /*0x2*/));
    // 0047f946  740f                   -je 0x47f957
    if (cpu.flags.zf)
    {
        goto L_0x0047f957;
    }
    // 0047f948  c7050caf4c00112b0000   -mov dword ptr [0x4caf0c], 0x2b11
    app->getMemory<x86::reg32>(x86::reg32(5025548) /* 0x4caf0c */) = 11025 /*0x2b11*/;
    // 0047f952  e97bffffff             -jmp 0x47f8d2
    goto L_0x0047f8d2;
L_0x0047f957:
    // 0047f957  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 0047f95c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047f95d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_47f960(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047f960  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0047f962  7409                   -je 0x47f96d
    if (cpu.flags.zf)
    {
        goto L_0x0047f96d;
    }
    // 0047f964  015018                 -add dword ptr [eax + 0x18], edx
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */)) += x86::reg32(x86::sreg32(cpu.edx));
    // 0047f967  b808000000             -mov eax, 8
    cpu.eax = 8 /*0x8*/;
    // 0047f96c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047f96d:
    // 0047f96d  8d5018                 -lea edx, [eax + 0x18]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0047f970  015018                 -add dword ptr [eax + 0x18], edx
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */)) += x86::reg32(x86::sreg32(cpu.edx));
    // 0047f973  b808000000             -mov eax, 8
    cpu.eax = 8 /*0x8*/;
    // 0047f978  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47f97c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047f97c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047f97d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047f97e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047f97f  83ec24                 -sub esp, 0x24
    (cpu.esp) -= x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0047f982  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0047f986  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0047f988  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0047f98c  8b5c2438               -mov ebx, dword ptr [esp + 0x38]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0047f990  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0047f992  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 0047f995  30c9                   -xor cl, cl
    cpu.cl ^= x86::reg8(x86::sreg8(cpu.cl));
    // 0047f997  888ac5db5100           -mov byte ptr [edx + 0x51dbc5], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5364677) /* 0x51dbc5 */) = cpu.cl;
    // 0047f99d  c682c6db510001         -mov byte ptr [edx + 0x51dbc6], 1
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5364678) /* 0x51dbc6 */) = 1 /*0x1*/;
    // 0047f9a4  30ed                   -xor ch, ch
    cpu.ch ^= x86::reg8(x86::sreg8(cpu.ch));
    // 0047f9a6  66898acadb5100         -mov word ptr [edx + 0x51dbca], cx
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(5364682) /* 0x51dbca */) = cpu.cx;
    // 0047f9ad  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047f9af  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 0047f9b1  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0047f9b3  81fa544d706c           +cmp edx, 0x6c704d54
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1819299156 /*0x6c704d54*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047f9b9  0f85fa000000           -jne 0x47fab9
    if (!cpu.flags.zf)
    {
        goto L_0x0047fab9;
    }
    // 0047f9bf  80780400               +cmp byte ptr [eax + 4], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(4) /* 0x4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047f9c3  0f85fe000000           -jne 0x47fac7
    if (!cpu.flags.zf)
    {
        goto L_0x0047fac7;
    }
    // 0047f9c9  80780510               +cmp byte ptr [eax + 5], 0x10
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5) /* 0x5 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047f9cd  0f8502010000           -jne 0x47fad5
    if (!cpu.flags.zf)
    {
        goto L_0x0047fad5;
    }
    // 0047f9d3  80780601               +cmp byte ptr [eax + 6], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(6) /* 0x6 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047f9d7  0f85f8000000           -jne 0x47fad5
    if (!cpu.flags.zf)
    {
        goto L_0x0047fad5;
    }
    // 0047f9dd  c744241c04000000       -mov dword ptr [esp + 0x1c], 4
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = 4 /*0x4*/;
L_0x0047f9e5:
    // 0047f9e5  837c241002             +cmp dword ptr [esp + 0x10], 2
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
    // 0047f9ea  0f8530010000           -jne 0x47fb20
    if (!cpu.flags.zf)
    {
        goto L_0x0047fb20;
    }
    // 0047f9f0  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047f9f2  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0047f9f7  894c2414               -mov dword ptr [esp + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 0047f9fb  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0047f9ff  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
L_0x0047fa03:
    // 0047fa03  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0047fa05  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0047fa08  668b560a               -mov dx, word ptr [esi + 0xa]
    cpu.dx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(10) /* 0xa */);
    // 0047fa0c  668990c0db5100         -mov word ptr [eax + 0x51dbc0], dx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(5364672) /* 0x51dbc0 */) = cpu.dx;
    // 0047fa13  8a5605                 -mov dl, byte ptr [esi + 5]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5) /* 0x5 */);
    // 0047fa16  8890c2db5100           -mov byte ptr [eax + 0x51dbc2], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5364674) /* 0x51dbc2 */) = cpu.dl;
    // 0047fa1c  8a5606                 -mov dl, byte ptr [esi + 6]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 0047fa1f  8890c3db5100           -mov byte ptr [eax + 0x51dbc3], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5364675) /* 0x51dbc3 */) = cpu.dl;
    // 0047fa25  8a5607                 -mov dl, byte ptr [esi + 7]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(7) /* 0x7 */);
    // 0047fa28  8890c4db5100           -mov byte ptr [eax + 0x51dbc4], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5364676) /* 0x51dbc4 */) = cpu.dl;
    // 0047fa2e  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0047fa32  8990ccdb5100           -mov dword ptr [eax + 0x51dbcc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5364684) /* 0x51dbcc */) = cpu.edx;
    // 0047fa38  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0047fa3a  8b150caf4c00           -mov edx, dword ptr [0x4caf0c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5025548) /* 0x4caf0c */);
    // 0047fa40  668b460a               -mov ax, word ptr [esi + 0xa]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(10) /* 0xa */);
    // 0047fa44  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047fa48  e8d3ca0100             -call 0x49c520
    cpu.esp -= 4;
    sub_49c520(app, cpu);
    if (cpu.terminate) return;
    // 0047fa4d  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0047fa4f  8b542434               -mov edx, dword ptr [esp + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0047fa53  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0047fa57  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047fa5b  e800cb0100             -call 0x49c560
    cpu.esp -= 4;
    sub_49c560(app, cpu);
    if (cpu.terminate) return;
    // 0047fa60  033d10af4c00           -add edi, dword ptr [0x4caf10]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5025552) /* 0x4caf10 */)));
    // 0047fa66  83ff64                 +cmp edi, 0x64
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(100 /*0x64*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047fa69  0f8eef000000           -jle 0x47fb5e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047fb5e;
    }
    // 0047fa6f  bf64000000             -mov edi, 0x64
    cpu.edi = 100 /*0x64*/;
L_0x0047fa74:
    // 0047fa74  8b5c243c               -mov ebx, dword ptr [esp + 0x3c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0047fa78  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047fa79  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047fa7a  8b7c2410               -mov edi, dword ptr [esp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0047fa7e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047fa7f  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0047fa83  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047fa84  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0047fa88  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047fa89  8b4c2434               -mov ecx, dword ptr [esp + 0x34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0047fa8d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047fa8e  8b5c2430               -mov ebx, dword ptr [esp + 0x30]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0047fa92  8b7c242c               -mov edi, dword ptr [esp + 0x2c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0047fa96  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047fa97  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0047fa9a  8b542438               -mov edx, dword ptr [esp + 0x38]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0047fa9e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047fa9f  8b4c2430               -mov ecx, dword ptr [esp + 0x30]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0047faa3  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047faa5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047faa6  8a5e07                 -mov bl, byte ptr [esi + 7]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(7) /* 0x7 */);
    // 0047faa9  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0047faab  e89cbf0100             -call 0x49ba4c
    cpu.esp -= 4;
    sub_49ba4c(app, cpu);
    if (cpu.terminate) return;
    // 0047fab0  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0047fab3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fab4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fab5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fab6  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x0047fab9:
    // 0047fab9  b8f9ffffff             -mov eax, 0xfffffff9
    cpu.eax = 4294967289 /*0xfffffff9*/;
    // 0047fabe  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0047fac1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fac2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fac3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fac4  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x0047fac7:
    // 0047fac7  b8f5ffffff             -mov eax, 0xfffffff5
    cpu.eax = 4294967285 /*0xfffffff5*/;
    // 0047facc  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0047facf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fad0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fad1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fad2  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x0047fad5:
    // 0047fad5  807e0510               +cmp byte ptr [esi + 5], 0x10
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5) /* 0x5 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047fad9  7513                   -jne 0x47faee
    if (!cpu.flags.zf)
    {
        goto L_0x0047faee;
    }
    // 0047fadb  807e0602               +cmp byte ptr [esi + 6], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(6) /* 0x6 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047fadf  750d                   -jne 0x47faee
    if (!cpu.flags.zf)
    {
        goto L_0x0047faee;
    }
    // 0047fae1  c744241c08000000       -mov dword ptr [esp + 0x1c], 8
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = 8 /*0x8*/;
    // 0047fae9  e9f7feffff             -jmp 0x47f9e5
    goto L_0x0047f9e5;
L_0x0047faee:
    // 0047faee  807e0508               +cmp byte ptr [esi + 5], 8
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5) /* 0x5 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047faf2  7513                   -jne 0x47fb07
    if (!cpu.flags.zf)
    {
        goto L_0x0047fb07;
    }
    // 0047faf4  807e0601               +cmp byte ptr [esi + 6], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(6) /* 0x6 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047faf8  750d                   -jne 0x47fb07
    if (!cpu.flags.zf)
    {
        goto L_0x0047fb07;
    }
    // 0047fafa  c744241c01000000       -mov dword ptr [esp + 0x1c], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = 1 /*0x1*/;
    // 0047fb02  e9defeffff             -jmp 0x47f9e5
    goto L_0x0047f9e5;
L_0x0047fb07:
    // 0047fb07  807e0508               +cmp byte ptr [esi + 5], 8
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5) /* 0x5 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047fb0b  75ac                   -jne 0x47fab9
    if (!cpu.flags.zf)
    {
        goto L_0x0047fab9;
    }
    // 0047fb0d  807e0602               +cmp byte ptr [esi + 6], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(6) /* 0x6 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047fb11  75a6                   -jne 0x47fab9
    if (!cpu.flags.zf)
    {
        goto L_0x0047fab9;
    }
    // 0047fb13  c744241c02000000       -mov dword ptr [esp + 0x1c], 2
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = 2 /*0x2*/;
    // 0047fb1b  e9c5feffff             -jmp 0x47f9e5
    goto L_0x0047f9e5;
L_0x0047fb20:
    // 0047fb20  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 0047fb23  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0047fb27  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 0047fb2a  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0047fb2e  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 0047fb31  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0047fb35  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0047fb39  83faff                 +cmp edx, -1
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
    // 0047fb3c  7d08                   -jge 0x47fb46
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047fb46;
    }
    // 0047fb3e  c7442418ffffffff       -mov dword ptr [esp + 0x18], 0xffffffff
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = 4294967295 /*0xffffffff*/;
L_0x0047fb46:
    // 0047fb46  837c2420ff             +cmp dword ptr [esp + 0x20], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047fb4b  0f8db2feffff           -jge 0x47fa03
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047fa03;
    }
    // 0047fb51  c7442420ffffffff       -mov dword ptr [esp + 0x20], 0xffffffff
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = 4294967295 /*0xffffffff*/;
    // 0047fb59  e9a5feffff             -jmp 0x47fa03
    goto L_0x0047fa03;
L_0x0047fb5e:
    // 0047fb5e  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0047fb60  0f8d0effffff           -jge 0x47fa74
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047fa74;
    }
    // 0047fb66  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 0047fb68  e907ffffff             -jmp 0x47fa74
    goto L_0x0047fa74;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47fbb8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0047fbb8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047fbb9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047fbba  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047fbbb  83ec30                 -sub esp, 0x30
    (cpu.esp) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0047fbbe  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0047fbc0  895c2414               -mov dword ptr [esp + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 0047fbc4  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0047fbc8  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 0047fbcd  bd22560000             -mov ebp, 0x5622
    cpu.ebp = 22050 /*0x5622*/;
    // 0047fbd2  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 0047fbd7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0047fbd9  8b7c2410               -mov edi, dword ptr [esp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0047fbdd  8954241c               -mov dword ptr [esp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 0047fbe1  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0047fbe5  895c2424               -mov dword ptr [esp + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 0047fbe9  895c2428               -mov dword ptr [esp + 0x28], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 0047fbed  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 0047fbf1  894c242c               -mov dword ptr [esp + 0x2c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.ecx;
    // 0047fbf5  c1e704                 -shl edi, 4
    cpu.edi <<= 4 /*0x4*/ % 32;
    // 0047fbf8  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0047fbfd  81c7c0db5100           -add edi, 0x51dbc0
    (cpu.edi) += x86::reg32(x86::sreg32(5364672 /*0x51dbc0*/));
    // 0047fc03  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047fc05  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0047fc09  c6470500               -mov byte ptr [edi + 5], 0
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(5) /* 0x5 */) = 0 /*0x0*/;
    // 0047fc0d  8a542458               -mov dl, byte ptr [esp + 0x58]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 0047fc11  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0047fc13  885706                 -mov byte ptr [edi + 6], dl
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(6) /* 0x6 */) = cpu.dl;
    // 0047fc16  8b542450               -mov edx, dword ptr [esp + 0x50]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 0047fc1a  895c2420               -mov dword ptr [esp + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 0047fc1e  6689570a               -mov word ptr [edi + 0xa], dx
    app->getMemory<x86::reg16>(cpu.edi + x86::reg32(10) /* 0xa */) = cpu.dx;
    // 0047fc22  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0047fc24  754f                   -jne 0x47fc75
    if (!cpu.flags.zf)
    {
        goto L_0x0047fc75;
    }
L_0x0047fc26:
    // 0047fc26  8a26                   -mov ah, byte ptr [esi]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esi);
    // 0047fc28  80fcff                 +cmp ah, 0xff
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047fc2b  0f840f010000           -je 0x47fd40
    if (cpu.flags.zf)
    {
        goto L_0x0047fd40;
    }
    // 0047fc31  80fcfe                 +cmp ah, 0xfe
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(254 /*0xfe*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047fc34  0f8406010000           -je 0x47fd40
    if (cpu.flags.zf)
    {
        goto L_0x0047fd40;
    }
    // 0047fc3a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047fc3c  88e3                   -mov bl, ah
    cpu.bl = cpu.ah;
    // 0047fc3e  46                     -inc esi
    (cpu.esi)++;
    // 0047fc3f  81fbfc000000           +cmp ebx, 0xfc
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(252 /*0xfc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047fc45  74df                   -je 0x47fc26
    if (cpu.flags.zf)
    {
        goto L_0x0047fc26;
    }
    // 0047fc47  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047fc49  8a0e                   -mov cl, byte ptr [esi]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi);
    // 0047fc4b  81f9ff000000           +cmp ecx, 0xff
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
    // 0047fc51  7512                   -jne 0x47fc65
    if (!cpu.flags.zf)
    {
        goto L_0x0047fc65;
    }
    // 0047fc53  46                     -inc esi
    (cpu.esi)++;
    // 0047fc54  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 0047fc59  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047fc5b  e830c90100             -call 0x49c590
    cpu.esp -= 4;
    sub_49c590(app, cpu);
    if (cpu.terminate) return;
    // 0047fc60  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047fc62  83c603                 -add esi, 3
    (cpu.esi) += x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x0047fc65:
    // 0047fc65  8d837fffffff           -lea eax, [ebx - 0x81]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(-129) /* -0x81 */);
    // 0047fc6b  46                     -inc esi
    (cpu.esi)++;
    // 0047fc6c  83f811                 +cmp eax, 0x11
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(17 /*0x11*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047fc6f  7612                   -jbe 0x47fc83
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0047fc83;
    }
  [[fallthrough]];
  case 0x0047fc71:
    // 0047fc71  01ce                   +add esi, ecx
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047fc73  ebb1                   -jmp 0x47fc26
    goto L_0x0047fc26;
L_0x0047fc75:
    // 0047fc75  b8f9ffffff             -mov eax, 0xfffffff9
    cpu.eax = 4294967289 /*0xfffffff9*/;
    // 0047fc7a  83c430                 +add esp, 0x30
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(48 /*0x30*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047fc7d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fc7e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fc7f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fc80  c21c00                 -ret 0x1c
    cpu.esp += 4+28 /*0x1c*/;
    return;
L_0x0047fc83:
    // 0047fc83  ff248570fb4700         -jmp dword ptr [eax*4 + 0x47fb70]
    cpu.ip = app->getMemory<x86::reg32>(4717424 + cpu.eax * 4); goto dynamic_jump;
  case 0x0047fc8a:
    // 0047fc8a  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047fc8c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047fc8e  e8fdc80100             -call 0x49c590
    cpu.esp -= 4;
    sub_49c590(app, cpu);
    if (cpu.terminate) return;
    // 0047fc93  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 0047fc97  01ce                   +add esi, ecx
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047fc99  eb8b                   -jmp 0x47fc26
    goto L_0x0047fc26;
  case 0x0047fc9b:
    // 0047fc9b  8974241c               -mov dword ptr [esp + 0x1c], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.esi;
    // 0047fc9f  01ce                   +add esi, ecx
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047fca1  eb83                   -jmp 0x47fc26
    goto L_0x0047fc26;
  case 0x0047fca3:
    // 0047fca3  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047fca5  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047fca7  e8e4c80100             -call 0x49c590
    cpu.esp -= 4;
    sub_49c590(app, cpu);
    if (cpu.terminate) return;
    // 0047fcac  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0047fcb0  01ce                   +add esi, ecx
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047fcb2  e96fffffff             -jmp 0x47fc26
    goto L_0x0047fc26;
  case 0x0047fcb7:
    // 0047fcb7  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047fcb9  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047fcbb  e8d0c80100             -call 0x49c590
    cpu.esp -= 4;
    sub_49c590(app, cpu);
    if (cpu.terminate) return;
    // 0047fcc0  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0047fcc4  01ce                   +add esi, ecx
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047fcc6  e95bffffff             -jmp 0x47fc26
    goto L_0x0047fc26;
  case 0x0047fccb:
    // 0047fccb  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047fccd  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047fccf  e8bcc80100             -call 0x49c590
    cpu.esp -= 4;
    sub_49c590(app, cpu);
    if (cpu.terminate) return;
    // 0047fcd4  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0047fcd8  01ce                   +add esi, ecx
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047fcda  e947ffffff             -jmp 0x47fc26
    goto L_0x0047fc26;
  case 0x0047fcdf:
    // 0047fcdf  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047fce1  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047fce3  e8a8c80100             -call 0x49c590
    cpu.esp -= 4;
    sub_49c590(app, cpu);
    if (cpu.terminate) return;
    // 0047fce8  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0047fcec  01ce                   +add esi, ecx
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047fcee  e933ffffff             -jmp 0x47fc26
    goto L_0x0047fc26;
  case 0x0047fcf3:
    // 0047fcf3  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047fcf5  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047fcf7  e894c80100             -call 0x49c590
    cpu.esp -= 4;
    sub_49c590(app, cpu);
    if (cpu.terminate) return;
    // 0047fcfc  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0047fd00  01ce                   +add esi, ecx
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047fd02  e91fffffff             -jmp 0x47fc26
    goto L_0x0047fc26;
  case 0x0047fd07:
    // 0047fd07  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047fd09  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047fd0b  e880c80100             -call 0x49c590
    cpu.esp -= 4;
    sub_49c590(app, cpu);
    if (cpu.terminate) return;
    // 0047fd10  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 0047fd14  01ce                   +add esi, ecx
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047fd16  e90bffffff             -jmp 0x47fc26
    goto L_0x0047fc26;
  case 0x0047fd1b:
    // 0047fd1b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047fd1d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047fd1f  e86cc80100             -call 0x49c590
    cpu.esp -= 4;
    sub_49c590(app, cpu);
    if (cpu.terminate) return;
    // 0047fd24  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0047fd26  01ce                   +add esi, ecx
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047fd28  e9f9feffff             -jmp 0x47fc26
    goto L_0x0047fc26;
  case 0x0047fd2d:
    // 0047fd2d  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0047fd2f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0047fd31  e85ac80100             -call 0x49c590
    cpu.esp -= 4;
    sub_49c590(app, cpu);
    if (cpu.terminate) return;
    // 0047fd36  884705                 -mov byte ptr [edi + 5], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(5) /* 0x5 */) = cpu.al;
    // 0047fd39  01ce                   +add esi, ecx
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0047fd3b  e9e6feffff             -jmp 0x47fc26
    goto L_0x0047fc26;
L_0x0047fd40:
    // 0047fd40  837c241402             +cmp dword ptr [esp + 0x14], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047fd45  0f85e4000000           -jne 0x47fe2f
    if (!cpu.flags.zf)
    {
        goto L_0x0047fe2f;
    }
    // 0047fd4b  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0047fd4d  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0047fd52  89742418               -mov dword ptr [esp + 0x18], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 0047fd56  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0047fd5a  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
L_0x0047fd5e:
    // 0047fd5e  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047fd62  668907                 -mov word ptr [edi], ax
    app->getMemory<x86::reg16>(cpu.edi) = cpu.ax;
    // 0047fd65  8a44242c               -mov al, byte ptr [esp + 0x2c]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0047fd69  884702                 -mov byte ptr [edi + 2], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 0047fd6c  8a44240c               -mov al, byte ptr [esp + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047fd70  884703                 -mov byte ptr [edi + 3], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */) = cpu.al;
    // 0047fd73  8a442420               -mov al, byte ptr [esp + 0x20]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0047fd77  884704                 -mov byte ptr [edi + 4], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.al;
    // 0047fd7a  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0047fd7e  8a7705                 -mov dh, byte ptr [edi + 5]
    cpu.dh = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(5) /* 0x5 */);
    // 0047fd81  89470c                 -mov dword ptr [edi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0047fd84  84f6                   +test dh, dh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & cpu.dh));
    // 0047fd86  0f85e2000000           -jne 0x47fe6e
    if (!cpu.flags.zf)
    {
        goto L_0x0047fe6e;
    }
    // 0047fd8c  837c245800             +cmp dword ptr [esp + 0x58], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047fd91  0f84bf000000           -je 0x47fe56
    if (cpu.flags.zf)
    {
        goto L_0x0047fe56;
    }
    // 0047fd97  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047fd9b  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0047fd9d  8b542444               -mov edx, dword ptr [esp + 0x44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0047fda1  8b442440               -mov eax, dword ptr [esp + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0047fda5  e8b6c70100             -call 0x49c560
    cpu.esp -= 4;
    sub_49c560(app, cpu);
    if (cpu.terminate) return;
L_0x0047fdaa:
    // 0047fdaa  837c242c10             +cmp dword ptr [esp + 0x2c], 0x10
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047fdaf  0f851d010000           -jne 0x47fed2
    if (!cpu.flags.zf)
    {
        goto L_0x0047fed2;
    }
    // 0047fdb5  837c240c01             +cmp dword ptr [esp + 0xc], 1
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
    // 0047fdba  0f8512010000           -jne 0x47fed2
    if (!cpu.flags.zf)
    {
        goto L_0x0047fed2;
    }
    // 0047fdc0  be04000000             -mov esi, 4
    cpu.esi = 4 /*0x4*/;
L_0x0047fdc5:
    // 0047fdc5  8b5c2448               -mov ebx, dword ptr [esp + 0x48]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0047fdc9  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047fdcd  8b150caf4c00           -mov edx, dword ptr [0x4caf0c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5025548) /* 0x4caf0c */);
    // 0047fdd3  e848c70100             -call 0x49c520
    cpu.esp -= 4;
    sub_49c520(app, cpu);
    if (cpu.terminate) return;
    // 0047fdd8  032d10af4c00           -add ebp, dword ptr [0x4caf10]
    (cpu.ebp) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5025552) /* 0x4caf10 */)));
    // 0047fdde  83fd64                 +cmp ebp, 0x64
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(100 /*0x64*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047fde1  0f8e39010000           -jle 0x47ff20
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0047ff20;
    }
    // 0047fde7  bd64000000             -mov ebp, 0x64
    cpu.ebp = 100 /*0x64*/;
L_0x0047fdec:
    // 0047fdec  8b5c244c               -mov ebx, dword ptr [esp + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 0047fdf0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047fdf1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047fdf2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047fdf3  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0047fdf7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047fdf8  8b6c2410               -mov ebp, dword ptr [esp + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0047fdfc  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047fdfd  8b44243c               -mov eax, dword ptr [esp + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0047fe01  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047fe02  8b54243c               -mov edx, dword ptr [esp + 0x3c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0047fe06  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0047fe07  8b4c2434               -mov ecx, dword ptr [esp + 0x34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0047fe0b  8b442438               -mov eax, dword ptr [esp + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0047fe0f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047fe10  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0047fe12  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 0047fe14  8b4c2434               -mov ecx, dword ptr [esp + 0x34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0047fe18  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047fe19  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0047fe1d  8b5c2444               -mov ebx, dword ptr [esp + 0x44]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0047fe21  e826bc0100             -call 0x49ba4c
    cpu.esp -= 4;
    sub_49ba4c(app, cpu);
    if (cpu.terminate) return;
    // 0047fe26  83c430                 -add esp, 0x30
    (cpu.esp) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0047fe29  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fe2a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fe2b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047fe2c  c21c00                 -ret 0x1c
    cpu.esp += 4+28 /*0x1c*/;
    return;
L_0x0047fe2f:
    // 0047fe2f  837c2424ff             +cmp dword ptr [esp + 0x24], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047fe34  7d08                   -jge 0x47fe3e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047fe3e;
    }
    // 0047fe36  c7442424ffffffff       -mov dword ptr [esp + 0x24], 0xffffffff
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = 4294967295 /*0xffffffff*/;
L_0x0047fe3e:
    // 0047fe3e  837c2428ff             +cmp dword ptr [esp + 0x28], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047fe43  0f8d15ffffff           -jge 0x47fd5e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047fd5e;
    }
    // 0047fe49  c7442428ffffffff       -mov dword ptr [esp + 0x28], 0xffffffff
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = 4294967295 /*0xffffffff*/;
    // 0047fe51  e908ffffff             -jmp 0x47fd5e
    goto L_0x0047fd5e;
L_0x0047fe56:
    // 0047fe56  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047fe5a  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0047fe5c  8b542444               -mov edx, dword ptr [esp + 0x44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0047fe60  8b442450               -mov eax, dword ptr [esp + 0x50]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 0047fe64  e8c7d20100             -call 0x49d130
    cpu.esp -= 4;
    sub_49d130(app, cpu);
    if (cpu.terminate) return;
    // 0047fe69  e93cffffff             -jmp 0x47fdaa
    goto L_0x0047fdaa;
L_0x0047fe6e:
    // 0047fe6e  80fe01                 +cmp dh, 1
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047fe71  0f85fefdffff           -jne 0x47fc75
    if (!cpu.flags.zf)
    {
        goto L_0x0047fc75;
    }
    // 0047fe77  837c240c01             +cmp dword ptr [esp + 0xc], 1
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
    // 0047fe7c  0f85f3fdffff           -jne 0x47fc75
    if (!cpu.flags.zf)
    {
        goto L_0x0047fc75;
    }
    // 0047fe82  837c245800             +cmp dword ptr [esp + 0x58], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047fe87  7414                   -je 0x47fe9d
    if (cpu.flags.zf)
    {
        goto L_0x0047fe9d;
    }
    // 0047fe89  8b442440               -mov eax, dword ptr [esp + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0047fe8d  83e840                 -sub eax, 0x40
    (cpu.eax) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0047fe90  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0047fe92  89442450               -mov dword ptr [esp + 0x50], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */) = cpu.eax;
    // 0047fe96  c1e608                 -shl esi, 8
    cpu.esi <<= 8 /*0x8*/ % 32;
    // 0047fe99  89742450               -mov dword ptr [esp + 0x50], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */) = cpu.esi;
L_0x0047fe9d:
    // 0047fe9d  8b4706                 -mov eax, dword ptr [edi + 6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(6) /* 0x6 */);
    // 0047fea0  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 0047fea3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047fea4  8b4705                 -mov eax, dword ptr [edi + 5]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5) /* 0x5 */);
    // 0047fea7  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047feab  c1f818                 +sar eax, 0x18
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
    // 0047feae  8d5c2404               -lea ebx, [esp + 4]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047feb2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0047feb3  8b54244c               -mov edx, dword ptr [esp + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 0047feb7  8b442458               -mov eax, dword ptr [esp + 0x58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 0047febb  e8a0d20100             -call 0x49d160
    cpu.esp -= 4;
    sub_49d160(app, cpu);
    if (cpu.terminate) return;
    // 0047fec0  8a0424                 -mov al, byte ptr [esp]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp);
    // 0047fec3  884708                 -mov byte ptr [edi + 8], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(8) /* 0x8 */) = cpu.al;
    // 0047fec6  8a442408               -mov al, byte ptr [esp + 8]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0047feca  884709                 -mov byte ptr [edi + 9], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(9) /* 0x9 */) = cpu.al;
    // 0047fecd  e9d8feffff             -jmp 0x47fdaa
    goto L_0x0047fdaa;
L_0x0047fed2:
    // 0047fed2  837c242c10             +cmp dword ptr [esp + 0x2c], 0x10
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047fed7  7511                   -jne 0x47feea
    if (!cpu.flags.zf)
    {
        goto L_0x0047feea;
    }
    // 0047fed9  837c240c02             +cmp dword ptr [esp + 0xc], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047fede  750a                   -jne 0x47feea
    if (!cpu.flags.zf)
    {
        goto L_0x0047feea;
    }
    // 0047fee0  be08000000             -mov esi, 8
    cpu.esi = 8 /*0x8*/;
    // 0047fee5  e9dbfeffff             -jmp 0x47fdc5
    goto L_0x0047fdc5;
L_0x0047feea:
    // 0047feea  837c242c08             +cmp dword ptr [esp + 0x2c], 8
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047feef  7510                   -jne 0x47ff01
    if (!cpu.flags.zf)
    {
        goto L_0x0047ff01;
    }
    // 0047fef1  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047fef5  83ff01                 +cmp edi, 1
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047fef8  7507                   -jne 0x47ff01
    if (!cpu.flags.zf)
    {
        goto L_0x0047ff01;
    }
    // 0047fefa  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 0047fefc  e9c4feffff             -jmp 0x47fdc5
    goto L_0x0047fdc5;
L_0x0047ff01:
    // 0047ff01  837c242c08             +cmp dword ptr [esp + 0x2c], 8
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047ff06  0f8569fdffff           -jne 0x47fc75
    if (!cpu.flags.zf)
    {
        goto L_0x0047fc75;
    }
    // 0047ff0c  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0047ff10  83fa02                 +cmp edx, 2
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
    // 0047ff13  0f855cfdffff           -jne 0x47fc75
    if (!cpu.flags.zf)
    {
        goto L_0x0047fc75;
    }
    // 0047ff19  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0047ff1b  e9a5feffff             -jmp 0x47fdc5
    goto L_0x0047fdc5;
L_0x0047ff20:
    // 0047ff20  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0047ff22  0f8dc4feffff           -jge 0x47fdec
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0047fdec;
    }
    // 0047ff28  31ed                   +xor ebp, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp))));
    // 0047ff2a  e9bdfeffff             -jmp 0x47fdec
    goto L_0x0047fdec;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x90 */
void Application::sub_47ff30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047ff30  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047ff31  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047ff32  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047ff33  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047ff34  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0047ff37  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047ff39  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0047ff3d  ba08000000             -mov edx, 8
    cpu.edx = 8 /*0x8*/;
    // 0047ff42  8a20                   -mov ah, byte ptr [eax]
    cpu.ah = app->getMemory<x86::reg8>(cpu.eax);
    // 0047ff44  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0047ff46  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0047ff48  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0047ff4b  80fcff                 +cmp ah, 0xff
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047ff4e  7418                   -je 0x47ff68
    if (cpu.flags.zf)
    {
        goto L_0x0047ff68;
    }
L_0x0047ff50:
    // 0047ff50  8a31                   -mov dh, byte ptr [ecx]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ecx);
    // 0047ff52  80fefe                 +cmp dh, 0xfe
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(254 /*0xfe*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047ff55  7411                   -je 0x47ff68
    if (cpu.flags.zf)
    {
        goto L_0x0047ff68;
    }
    // 0047ff57  0fb6f6                 -movzx esi, dh
    cpu.esi = x86::reg32(cpu.dh);
    // 0047ff5a  41                     -inc ecx
    (cpu.ecx)++;
    // 0047ff5b  81fefc000000           +cmp esi, 0xfc
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(252 /*0xfc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047ff61  751a                   -jne 0x47ff7d
    if (!cpu.flags.zf)
    {
        goto L_0x0047ff7d;
    }
L_0x0047ff63:
    // 0047ff63  8039ff                 +cmp byte ptr [ecx], 0xff
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047ff66  75e8                   -jne 0x47ff50
    if (!cpu.flags.zf)
    {
        goto L_0x0047ff50;
    }
L_0x0047ff68:
    // 0047ff68  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047ff6c  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 0047ff6e  894500                 -mov dword ptr [ebp], eax
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
    // 0047ff71  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0047ff74  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0047ff77  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ff78  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ff79  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ff7a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ff7b  90                     -nop 
    ;
    // 0047ff7c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047ff7d:
    // 0047ff7d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047ff7f  8a19                   -mov bl, byte ptr [ecx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx);
    // 0047ff81  81fbff000000           +cmp ebx, 0xff
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
    // 0047ff87  7512                   -jne 0x47ff9b
    if (!cpu.flags.zf)
    {
        goto L_0x0047ff9b;
    }
    // 0047ff89  41                     -inc ecx
    (cpu.ecx)++;
    // 0047ff8a  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 0047ff8f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047ff91  e8fac50100             -call 0x49c590
    cpu.esp -= 4;
    sub_49c590(app, cpu);
    if (cpu.terminate) return;
    // 0047ff96  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047ff98  83c103                 -add ecx, 3
    (cpu.ecx) += x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x0047ff9b:
    // 0047ff9b  41                     -inc ecx
    (cpu.ecx)++;
    // 0047ff9c  81fe80000000           +cmp esi, 0x80
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(128 /*0x80*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047ffa2  7c13                   -jl 0x47ffb7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047ffb7;
    }
    // 0047ffa4  81fe88000000           +cmp esi, 0x88
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(136 /*0x88*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047ffaa  750f                   -jne 0x47ffbb
    if (!cpu.flags.zf)
    {
        goto L_0x0047ffbb;
    }
    // 0047ffac  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0047ffae  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047ffb0  e8dbc50100             -call 0x49c590
    cpu.esp -= 4;
    sub_49c590(app, cpu);
    if (cpu.terminate) return;
    // 0047ffb5  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x0047ffb7:
    // 0047ffb7  01d9                   +add ecx, ebx
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
    // 0047ffb9  eba8                   -jmp 0x47ff63
    goto L_0x0047ff63;
L_0x0047ffbb:
    // 0047ffbb  81fe8a000000           +cmp esi, 0x8a
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(138 /*0x8a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047ffc1  75f4                   -jne 0x47ffb7
    if (!cpu.flags.zf)
    {
        goto L_0x0047ffb7;
    }
    // 0047ffc3  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 0047ffc5  01d9                   +add ecx, ebx
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
    // 0047ffc7  eb9a                   -jmp 0x47ff63
    goto L_0x0047ff63;
}

/* align: skip  */
void Application::sub_47ff7c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x0047ff7c;
    // 0047ff30  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047ff31  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047ff32  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047ff33  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0047ff34  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0047ff37  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0047ff39  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0047ff3d  ba08000000             -mov edx, 8
    cpu.edx = 8 /*0x8*/;
    // 0047ff42  8a20                   -mov ah, byte ptr [eax]
    cpu.ah = app->getMemory<x86::reg8>(cpu.eax);
    // 0047ff44  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0047ff46  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 0047ff48  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0047ff4b  80fcff                 +cmp ah, 0xff
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047ff4e  7418                   -je 0x47ff68
    if (cpu.flags.zf)
    {
        goto L_0x0047ff68;
    }
L_0x0047ff50:
    // 0047ff50  8a31                   -mov dh, byte ptr [ecx]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ecx);
    // 0047ff52  80fefe                 +cmp dh, 0xfe
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(254 /*0xfe*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047ff55  7411                   -je 0x47ff68
    if (cpu.flags.zf)
    {
        goto L_0x0047ff68;
    }
    // 0047ff57  0fb6f6                 -movzx esi, dh
    cpu.esi = x86::reg32(cpu.dh);
    // 0047ff5a  41                     -inc ecx
    (cpu.ecx)++;
    // 0047ff5b  81fefc000000           +cmp esi, 0xfc
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(252 /*0xfc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047ff61  751a                   -jne 0x47ff7d
    if (!cpu.flags.zf)
    {
        goto L_0x0047ff7d;
    }
L_0x0047ff63:
    // 0047ff63  8039ff                 +cmp byte ptr [ecx], 0xff
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0047ff66  75e8                   -jne 0x47ff50
    if (!cpu.flags.zf)
    {
        goto L_0x0047ff50;
    }
L_0x0047ff68:
    // 0047ff68  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0047ff6c  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 0047ff6e  894500                 -mov dword ptr [ebp], eax
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
    // 0047ff71  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0047ff74  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0047ff77  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ff78  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ff79  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ff7a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0047ff7b  90                     -nop 
    ;
L_entry_0x0047ff7c:
    // 0047ff7c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0047ff7d:
    // 0047ff7d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0047ff7f  8a19                   -mov bl, byte ptr [ecx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx);
    // 0047ff81  81fbff000000           +cmp ebx, 0xff
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
    // 0047ff87  7512                   -jne 0x47ff9b
    if (!cpu.flags.zf)
    {
        goto L_0x0047ff9b;
    }
    // 0047ff89  41                     -inc ecx
    (cpu.ecx)++;
    // 0047ff8a  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 0047ff8f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047ff91  e8fac50100             -call 0x49c590
    cpu.esp -= 4;
    sub_49c590(app, cpu);
    if (cpu.terminate) return;
    // 0047ff96  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0047ff98  83c103                 -add ecx, 3
    (cpu.ecx) += x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x0047ff9b:
    // 0047ff9b  41                     -inc ecx
    (cpu.ecx)++;
    // 0047ff9c  81fe80000000           +cmp esi, 0x80
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(128 /*0x80*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047ffa2  7c13                   -jl 0x47ffb7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0047ffb7;
    }
    // 0047ffa4  81fe88000000           +cmp esi, 0x88
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(136 /*0x88*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047ffaa  750f                   -jne 0x47ffbb
    if (!cpu.flags.zf)
    {
        goto L_0x0047ffbb;
    }
    // 0047ffac  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0047ffae  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0047ffb0  e8dbc50100             -call 0x49c590
    cpu.esp -= 4;
    sub_49c590(app, cpu);
    if (cpu.terminate) return;
    // 0047ffb5  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x0047ffb7:
    // 0047ffb7  01d9                   +add ecx, ebx
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
    // 0047ffb9  eba8                   -jmp 0x47ff63
    goto L_0x0047ff63;
L_0x0047ffbb:
    // 0047ffbb  81fe8a000000           +cmp esi, 0x8a
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(138 /*0x8a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0047ffc1  75f4                   -jne 0x47ffb7
    if (!cpu.flags.zf)
    {
        goto L_0x0047ffb7;
    }
    // 0047ffc3  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 0047ffc5  01d9                   +add ecx, ebx
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
    // 0047ffc7  eb9a                   -jmp 0x47ff63
    goto L_0x0047ff63;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47ffcc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047ffcc  e9dfbf0100             -jmp 0x49bfb0
    return sub_49bfb0(app, cpu);
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_47ffd4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0047ffd4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0047ffd5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0047ffd6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0047ffd7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0047ffd8  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0047ffdb  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0047ffdd  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0047ffdf  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 0047ffe1  b201                   -mov dl, 1
    cpu.dl = 1 /*0x1*/;
    // 0047ffe3  c1e604                 -shl esi, 4
    cpu.esi <<= 4 /*0x4*/ % 32;
    // 0047ffe6  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 0047ffe8  8896c6db5100           -mov byte ptr [esi + 0x51dbc6], dl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5364678) /* 0x51dbc6 */) = cpu.dl;
    // 0047ffee  8d148d00000000         -lea edx, [ecx*4]
    cpu.edx = x86::reg32(cpu.ecx * 4);
    // 0047fff5  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0047fff7  8a9ec5db5100           -mov bl, byte ptr [esi + 0x51dbc5]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5364677) /* 0x51dbc5 */);
    // 0047fffd  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 00480000  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 00480002  745c                   -je 0x480060
    if (cpu.flags.zf)
    {
        goto L_0x00480060;
    }
    // 00480004  80fb01                 +cmp bl, 1
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00480007  756d                   -jne 0x480076
    if (!cpu.flags.zf)
    {
        goto L_0x00480076;
    }
    // 00480009  8b8ec6db5100           -mov ecx, dword ptr [esi + 0x51dbc6]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5364678) /* 0x51dbc6 */);
    // 0048000f  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00480011  c1f918                 -sar ecx, 0x18
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (24 /*0x18*/ % 32));
    // 00480014  83e840                 -sub eax, 0x40
    (cpu.eax) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00480017  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00480018  8b8ec5db5100           -mov ecx, dword ptr [esi + 0x51dbc5]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5364677) /* 0x51dbc5 */);
    // 0048001e  8b92fea75200           -mov edx, dword ptr [edx + 0x52a7fe]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5416958) /* 0x52a7fe */);
    // 00480024  c1f918                 -sar ecx, 0x18
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (24 /*0x18*/ % 32));
    // 00480027  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 0048002a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048002b  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 0048002e  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00480032  e829d10100             -call 0x49d160
    cpu.esp -= 4;
    sub_49d160(app, cpu);
    if (cpu.terminate) return;
    // 00480037  8a0424                 -mov al, byte ptr [esp]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp);
    // 0048003a  8886c8db5100           -mov byte ptr [esi + 0x51dbc8], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5364680) /* 0x51dbc8 */) = cpu.al;
    // 00480040  8a442404               -mov al, byte ptr [esp + 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00480044  8886c9db5100           -mov byte ptr [esi + 0x51dbc9], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5364681) /* 0x51dbc9 */) = cpu.al;
L_0x0048004a:
    // 0048004a  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0048004e  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00480051  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00480053  e8f8be0100             -call 0x49bf50
    cpu.esp -= 4;
    sub_49bf50(app, cpu);
    if (cpu.terminate) return;
    // 00480058  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048005b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048005c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048005d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048005e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048005f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00480060:
    // 00480060  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00480064  8b92fea75200           -mov edx, dword ptr [edx + 0x52a7fe]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5416958) /* 0x52a7fe */);
    // 0048006a  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0048006c  c1fa18                 +sar edx, 0x18
    {
        x86::reg8 tmp = 24 /*0x18*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 0048006f  e8ecc40100             -call 0x49c560
    cpu.esp -= 4;
    sub_49c560(app, cpu);
    if (cpu.terminate) return;
    // 00480074  ebd4                   -jmp 0x48004a
    goto L_0x0048004a;
L_0x00480076:
    // 00480076  b8f9ffffff             -mov eax, 0xfffffff9
    cpu.eax = 4294967289 /*0xfffffff9*/;
    // 0048007b  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048007e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048007f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480080  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480081  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480082  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_480084(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480084  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00480085  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00480086  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00480087  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00480088  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048008b  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0048008d  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0048008f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00480091  c1e604                 -shl esi, 4
    cpu.esi <<= 4 /*0x4*/ % 32;
    // 00480094  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00480097  81c6c0db5100           -add esi, 0x51dbc0
    (cpu.esi) += x86::reg32(x86::sreg32(5364672 /*0x51dbc0*/));
    // 0048009d  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0048009f  6689560a               -mov word ptr [esi + 0xa], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(10) /* 0xa */) = cpu.dx;
    // 004800a3  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004800a6  8a5605                 -mov dl, byte ptr [esi + 5]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5) /* 0x5 */);
    // 004800a9  c6460600               -mov byte ptr [esi + 6], 0
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 004800ad  80fa01                 +cmp dl, 1
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
    // 004800b0  7430                   -je 0x4800e2
    if (cpu.flags.zf)
    {
        goto L_0x004800e2;
    }
    // 004800b2  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 004800b4  7561                   -jne 0x480117
    if (!cpu.flags.zf)
    {
        goto L_0x00480117;
    }
    // 004800b6  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004800ba  8b90fea75200           -mov edx, dword ptr [eax + 0x52a7fe]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5416958) /* 0x52a7fe */);
    // 004800c0  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004800c2  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004800c5  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004800c7  e864d00100             -call 0x49d130
    cpu.esp -= 4;
    sub_49d130(app, cpu);
    if (cpu.terminate) return;
L_0x004800cc:
    // 004800cc  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004800d0  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004800d3  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004800d5  e876be0100             -call 0x49bf50
    cpu.esp -= 4;
    sub_49bf50(app, cpu);
    if (cpu.terminate) return;
    // 004800da  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004800dd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004800de  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004800df  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004800e0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004800e1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004800e2:
    // 004800e2  8b5606                 -mov edx, dword ptr [esi + 6]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 004800e5  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004800e8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004800e9  8b5605                 -mov edx, dword ptr [esi + 5]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5) /* 0x5 */);
    // 004800ec  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004800ef  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004800f3  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004800f4  8b90fea75200           -mov edx, dword ptr [eax + 0x52a7fe]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5416958) /* 0x52a7fe */);
    // 004800fa  8d5c2408               -lea ebx, [esp + 8]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004800fe  c1fa18                 +sar edx, 0x18
    {
        x86::reg8 tmp = 24 /*0x18*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 00480101  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00480103  e858d00100             -call 0x49d160
    cpu.esp -= 4;
    sub_49d160(app, cpu);
    if (cpu.terminate) return;
    // 00480108  8a0424                 -mov al, byte ptr [esp]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp);
    // 0048010b  884608                 -mov byte ptr [esi + 8], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.al;
    // 0048010e  8a442404               -mov al, byte ptr [esp + 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00480112  884609                 -mov byte ptr [esi + 9], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(9) /* 0x9 */) = cpu.al;
    // 00480115  ebb5                   -jmp 0x4800cc
    goto L_0x004800cc;
L_0x00480117:
    // 00480117  b8f9ffffff             -mov eax, 0xfffffff9
    cpu.eax = 4294967289 /*0xfffffff9*/;
    // 0048011c  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048011f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480120  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480121  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480122  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480123  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_480124(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480124  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00480125  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00480126  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00480127  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00480128  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048012b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048012d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048012f  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00480132  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
    // 00480135  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00480137  8a99c5db5100           -mov bl, byte ptr [ecx + 0x51dbc5]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5364677) /* 0x51dbc5 */);
    // 0048013d  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00480140  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 00480142  7549                   -jne 0x48018d
    if (!cpu.flags.zf)
    {
        goto L_0x0048018d;
    }
    // 00480144  80b9c6db510000         +cmp byte ptr [ecx + 0x51dbc6], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5364678) /* 0x51dbc6 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048014b  742a                   -je 0x480177
    if (cpu.flags.zf)
    {
        goto L_0x00480177;
    }
    // 0048014d  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00480151  8b80dca75200           -mov eax, dword ptr [eax + 0x52a7dc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5416924) /* 0x52a7dc */);
    // 00480157  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00480159  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 0048015c  e8ffc30100             -call 0x49c560
    cpu.esp -= 4;
    sub_49c560(app, cpu);
    if (cpu.terminate) return;
L_0x00480161:
    // 00480161  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00480165  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00480168  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048016a  e8e1bd0100             -call 0x49bf50
    cpu.esp -= 4;
    sub_49bf50(app, cpu);
    if (cpu.terminate) return;
    // 0048016f  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00480172  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480173  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480174  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480175  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480176  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00480177:
    // 00480177  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00480179  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0048017b  668b81cadb5100         -mov ax, word ptr [ecx + 0x51dbca]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(5364682) /* 0x51dbca */);
    // 00480182  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00480186  e8a5cf0100             -call 0x49d130
    cpu.esp -= 4;
    sub_49d130(app, cpu);
    if (cpu.terminate) return;
    // 0048018b  ebd4                   -jmp 0x480161
    goto L_0x00480161;
L_0x0048018d:
    // 0048018d  80fb01                 +cmp bl, 1
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00480190  755b                   -jne 0x4801ed
    if (!cpu.flags.zf)
    {
        goto L_0x004801ed;
    }
    // 00480192  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00480193  80b9c6db510000         +cmp byte ptr [ecx + 0x51dbc6], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5364678) /* 0x51dbc6 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048019a  740f                   -je 0x4801ab
    if (cpu.flags.zf)
    {
        goto L_0x004801ab;
    }
    // 0048019c  8bb8dca75200           -mov edi, dword ptr [eax + 0x52a7dc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5416924) /* 0x52a7dc */);
    // 004801a2  c1ff18                 -sar edi, 0x18
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (24 /*0x18*/ % 32));
    // 004801a5  83ef40                 -sub edi, 0x40
    (cpu.edi) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004801a8  c1e708                 -shl edi, 8
    cpu.edi <<= 8 /*0x8*/ % 32;
L_0x004801ab:
    // 004801ab  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 004801ad  c1e504                 -shl ebp, 4
    cpu.ebp <<= 4 /*0x4*/ % 32;
    // 004801b0  8b85c6db5100           -mov eax, dword ptr [ebp + 0x51dbc6]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(5364678) /* 0x51dbc6 */);
    // 004801b6  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004801b9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004801ba  8b85c5db5100           -mov eax, dword ptr [ebp + 0x51dbc5]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(5364677) /* 0x51dbc5 */);
    // 004801c0  c1f818                 +sar eax, 0x18
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
    // 004801c3  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004801c7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004801c8  8d5c240c               -lea ebx, [esp + 0xc]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004801cc  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004801ce  e88dcf0100             -call 0x49d160
    cpu.esp -= 4;
    sub_49d160(app, cpu);
    if (cpu.terminate) return;
    // 004801d3  8a442404               -mov al, byte ptr [esp + 4]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004801d7  8885c8db5100           -mov byte ptr [ebp + 0x51dbc8], al
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(5364680) /* 0x51dbc8 */) = cpu.al;
    // 004801dd  8a442408               -mov al, byte ptr [esp + 8]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004801e1  8885c9db5100           -mov byte ptr [ebp + 0x51dbc9], al
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(5364681) /* 0x51dbc9 */) = cpu.al;
    // 004801e7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004801e8  e974ffffff             -jmp 0x480161
    goto L_0x00480161;
L_0x004801ed:
    // 004801ed  b8f9ffffff             -mov eax, 0xfffffff9
    cpu.eax = 4294967289 /*0xfffffff9*/;
    // 004801f2  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004801f5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004801f6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004801f7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004801f8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004801f9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4801fc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004801fc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004801fd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004801fe  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00480200  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 00480203  8a9ac5db5100           -mov bl, byte ptr [edx + 0x51dbc5]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5364677) /* 0x51dbc5 */);
    // 00480209  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 0048020b  740d                   -je 0x48021a
    if (cpu.flags.zf)
    {
        goto L_0x0048021a;
    }
    // 0048020d  80fb01                 +cmp bl, 1
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00480210  7408                   -je 0x48021a
    if (cpu.flags.zf)
    {
        goto L_0x0048021a;
    }
    // 00480212  b8f9ffffff             -mov eax, 0xfffffff9
    cpu.eax = 4294967289 /*0xfffffff9*/;
    // 00480217  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480218  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480219  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048021a:
    // 0048021a  e839bc0100             -call 0x49be58
    cpu.esp -= 4;
    sub_49be58(app, cpu);
    if (cpu.terminate) return;
    // 0048021f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480220  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480221  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_480224(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480224  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00480225  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00480226  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00480227  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00480229  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0048022c  8a90c5db5100           -mov dl, byte ptr [eax + 0x51dbc5]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5364677) /* 0x51dbc5 */);
    // 00480232  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 00480234  740e                   -je 0x480244
    if (cpu.flags.zf)
    {
        goto L_0x00480244;
    }
    // 00480236  80fa01                 +cmp dl, 1
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
    // 00480239  7409                   -je 0x480244
    if (cpu.flags.zf)
    {
        goto L_0x00480244;
    }
    // 0048023b  b8f9ffffff             -mov eax, 0xfffffff9
    cpu.eax = 4294967289 /*0xfffffff9*/;
L_0x00480240:
    // 00480240  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480241  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480242  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480243  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00480244:
    // 00480244  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00480246  e891bd0100             -call 0x49bfdc
    cpu.esp -= 4;
    sub_49bfdc(app, cpu);
    if (cpu.terminate) return;
    // 0048024b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048024d  7cf1                   -jl 0x480240
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00480240;
    }
    // 0048024f  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00480251  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 00480254  8b9accdb5100           -mov ebx, dword ptr [edx + 0x51dbcc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5364684) /* 0x51dbcc */);
    // 0048025a  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0048025c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048025e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00480260  7cde                   -jl 0x480240
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00480240;
    }
    // 00480262  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00480264  668b9ac0db5100         -mov bx, word ptr [edx + 0x51dbc0]
    cpu.bx = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(5364672) /* 0x51dbc0 */);
    // 0048026b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048026d  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00480270  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00480272  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00480275  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00480277  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0048027a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048027c  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048027f  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00480281  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00480283  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 0048028a  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048028c  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 0048028f  6683b8e2a7520000       +cmp word ptr [eax + 0x52a7e2], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(5416930) /* 0x52a7e2 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00480297  7c2b                   -jl 0x4802c4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004802c4;
    }
    // 00480299  8b88e0a75200           -mov ecx, dword ptr [eax + 0x52a7e0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5416928) /* 0x52a7e0 */);
    // 0048029f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004802a1  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004802a4  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004802a6  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004802a9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004802ab  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004802ae  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004802b0  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004802b3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004802b5  81c1b0040000           -add ecx, 0x4b0
    (cpu.ecx) += x86::reg32(x86::sreg32(1200 /*0x4b0*/));
    // 004802bb  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004802be  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004802c0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004802c1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004802c2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004802c3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004802c4:
    // 004802c4  8b80e0a75200           -mov eax, dword ptr [eax + 0x52a7e0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5416928) /* 0x52a7e0 */);
    // 004802ca  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004802cd  2db0040000             -sub eax, 0x4b0
    (cpu.eax) -= x86::reg32(x86::sreg32(1200 /*0x4b0*/));
    // 004802d2  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 004802d5  b950fbffff             -mov ecx, 0xfffffb50
    cpu.ecx = 4294966096 /*0xfffffb50*/;
    // 004802da  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004802dc  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004802df  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004802e1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004802e2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004802e3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004802e4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4802e8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004802e8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004802e9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004802ea  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004802ec  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 004802ef  8a9ac5db5100           -mov bl, byte ptr [edx + 0x51dbc5]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5364677) /* 0x51dbc5 */);
    // 004802f5  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 004802f7  740d                   -je 0x480306
    if (cpu.flags.zf)
    {
        goto L_0x00480306;
    }
    // 004802f9  80fb01                 +cmp bl, 1
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004802fc  7408                   -je 0x480306
    if (cpu.flags.zf)
    {
        goto L_0x00480306;
    }
    // 004802fe  b8f9ffffff             -mov eax, 0xfffffff9
    cpu.eax = 4294967289 /*0xfffffff9*/;
    // 00480303  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480304  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480305  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00480306:
    // 00480306  e8d1bc0100             -call 0x49bfdc
    cpu.esp -= 4;
    sub_49bfdc(app, cpu);
    if (cpu.terminate) return;
    // 0048030b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048030c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048030d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_480310(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480310  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00480311  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00480312  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00480314  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00480317  8a98c5db5100           -mov bl, byte ptr [eax + 0x51dbc5]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5364677) /* 0x51dbc5 */);
    // 0048031d  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 0048031f  740d                   -je 0x48032e
    if (cpu.flags.zf)
    {
        goto L_0x0048032e;
    }
    // 00480321  80fb01                 +cmp bl, 1
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00480324  7408                   -je 0x48032e
    if (cpu.flags.zf)
    {
        goto L_0x0048032e;
    }
    // 00480326  b8f9ffffff             -mov eax, 0xfffffff9
    cpu.eax = 4294967289 /*0xfffffff9*/;
    // 0048032b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048032c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048032d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048032e:
    // 0048032e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048032f  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00480331  c1e604                 -shl esi, 4
    cpu.esi <<= 4 /*0x4*/ % 32;
    // 00480334  a10caf4c00             -mov eax, dword ptr [0x4caf0c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5025548) /* 0x4caf0c */);
    // 00480339  668bb6c0db5100         -mov si, word ptr [esi + 0x51dbc0]
    cpu.si = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(5364672) /* 0x51dbc0 */);
    // 00480340  81e6ffff0000           -and esi, 0xffff
    cpu.esi &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00480346  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00480348  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048034a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048034c  e8cfc10100             -call 0x49c520
    cpu.esp -= 4;
    sub_49c520(app, cpu);
    if (cpu.terminate) return;
    // 00480351  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00480353  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00480355  e85ebb0100             -call 0x49beb8
    cpu.esp -= 4;
    sub_49beb8(app, cpu);
    if (cpu.terminate) return;
    // 0048035a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048035b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048035c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048035d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_480360(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480360  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00480361  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00480362  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00480363  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00480365  c1e304                 -shl ebx, 4
    cpu.ebx <<= 4 /*0x4*/ % 32;
    // 00480368  81c3c0db5100           -add ebx, 0x51dbc0
    (cpu.ebx) += x86::reg32(x86::sreg32(5364672 /*0x51dbc0*/));
    // 0048036e  8d5008                 -lea edx, [eax + 8]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00480371  807b0407               +cmp byte ptr [ebx + 4], 7
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(7 /*0x7*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00480375  7461                   -je 0x4803d8
    if (cpu.flags.zf)
    {
        goto L_0x004803d8;
    }
    // 00480377  807b0409               +cmp byte ptr [ebx + 4], 9
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(9 /*0x9*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048037b  7457                   -je 0x4803d4
    if (cpu.flags.zf)
    {
        goto L_0x004803d4;
    }
    // 0048037d  807b0408               +cmp byte ptr [ebx + 4], 8
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00480381  7451                   -je 0x4803d4
    if (cpu.flags.zf)
    {
        goto L_0x004803d4;
    }
    // 00480383  807b0402               +cmp byte ptr [ebx + 4], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00480387  0f85a2000000           -jne 0x48042f
    if (!cpu.flags.zf)
    {
        goto L_0x0048042f;
    }
    // 0048038d  66c7000000             -mov word ptr [eax], 0
    app->getMemory<x86::reg16>(cpu.eax) = 0 /*0x0*/;
    // 00480392  66c740020000           -mov word ptr [eax + 2], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */) = 0 /*0x0*/;
    // 00480398  66c740040000           -mov word ptr [eax + 4], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0048039e  66c740060000           -mov word ptr [eax + 6], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 004803a4  8a4303                 -mov al, byte ptr [ebx + 3]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(3) /* 0x3 */);
    // 004803a7  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004803a9  3c01                   +cmp al, 1
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
    // 004803ab  7515                   -jne 0x4803c2
    if (!cpu.flags.zf)
    {
        goto L_0x004803c2;
    }
    // 004803ad  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 004803b2  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004803b4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004803b6  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004803b9  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004803bb  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004803bd  7401                   -je 0x4803c0
    if (cpu.flags.zf)
    {
        goto L_0x004803c0;
    }
    // 004803bf  41                     -inc ecx
    (cpu.ecx)++;
L_0x004803c0:
    // 004803c0  d1f9                   -sar ecx, 1
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (1 /*0x1*/ % 32));
L_0x004803c2:
    // 004803c2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004803c4  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004803c6  7e0c                   -jle 0x4803d4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004803d4;
    }
    // 004803c8  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
L_0x004803ca:
    // 004803ca  40                     -inc eax
    (cpu.eax)++;
    // 004803cb  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
    // 004803ce  42                     -inc edx
    (cpu.edx)++;
    // 004803cf  39c8                   +cmp eax, ecx
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
    // 004803d1  7cf7                   -jl 0x4803ca
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004803ca;
    }
    // 004803d3  90                     -nop 
    ;
L_0x004803d4:
    // 004803d4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004803d5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004803d6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004803d7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004803d8:
    // 004803d8  66c7000000             -mov word ptr [eax], 0
    app->getMemory<x86::reg16>(cpu.eax) = 0 /*0x0*/;
    // 004803dd  be1c000000             -mov esi, 0x1c
    cpu.esi = 28 /*0x1c*/;
    // 004803e2  66c740020000           -mov word ptr [eax + 2], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */) = 0 /*0x0*/;
    // 004803e8  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004803ea  66c740040000           -mov word ptr [eax + 4], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004803f0  83c11b                 -add ecx, 0x1b
    (cpu.ecx) += x86::reg32(x86::sreg32(27 /*0x1b*/));
    // 004803f3  66c740060000           -mov word ptr [eax + 6], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 004803f9  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004803fb  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004803fd  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00480400  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00480402  8d0c8500000000         -lea ecx, [eax*4]
    cpu.ecx = x86::reg32(cpu.eax * 4);
    // 00480409  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048040b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048040d  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 00480410  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00480412  807b0302               +cmp byte ptr [ebx + 3], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(3) /* 0x3 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00480416  7502                   -jne 0x48041a
    if (!cpu.flags.zf)
    {
        goto L_0x0048041a;
    }
    // 00480418  01c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
L_0x0048041a:
    // 0048041a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048041c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048041e  7eb4                   -jle 0x4803d4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004803d4;
    }
    // 00480420  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
L_0x00480422:
    // 00480422  40                     -inc eax
    (cpu.eax)++;
    // 00480423  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
    // 00480426  42                     -inc edx
    (cpu.edx)++;
    // 00480427  39c8                   +cmp eax, ecx
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
    // 00480429  7cf7                   -jl 0x480422
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00480422;
    }
    // 0048042b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048042c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048042d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048042e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048042f:
    // 0048042f  807b0400               +cmp byte ptr [ebx + 4], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(4) /* 0x4 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00480433  759f                   -jne 0x4803d4
    if (!cpu.flags.zf)
    {
        goto L_0x004803d4;
    }
    // 00480435  807b0302               +cmp byte ptr [ebx + 3], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(3) /* 0x3 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00480439  7502                   -jne 0x48043d
    if (!cpu.flags.zf)
    {
        goto L_0x0048043d;
    }
    // 0048043b  01c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
L_0x0048043d:
    // 0048043d  8a5302                 -mov dl, byte ptr [ebx + 2]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 00480440  80fa10                 +cmp dl, 0x10
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00480443  7517                   -jne 0x48045c
    if (!cpu.flags.zf)
    {
        goto L_0x0048045c;
    }
    // 00480445  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00480447  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00480449  7e89                   -jle 0x4803d4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004803d4;
    }
L_0x0048044b:
    // 0048044b  42                     -inc edx
    (cpu.edx)++;
    // 0048044c  66c7000000             -mov word ptr [eax], 0
    app->getMemory<x86::reg16>(cpu.eax) = 0 /*0x0*/;
    // 00480451  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00480454  39ca                   +cmp edx, ecx
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
    // 00480456  7cf3                   -jl 0x48044b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048044b;
    }
    // 00480458  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480459  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048045a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048045b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048045c:
    // 0048045c  80fa08                 +cmp dl, 8
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048045f  0f856fffffff           -jne 0x4803d4
    if (!cpu.flags.zf)
    {
        goto L_0x004803d4;
    }
    // 00480465  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00480467  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00480469  0f8e65ffffff           -jle 0x4803d4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004803d4;
    }
L_0x0048046f:
    // 0048046f  42                     -inc edx
    (cpu.edx)++;
    // 00480470  c60000                 -mov byte ptr [eax], 0
    app->getMemory<x86::reg8>(cpu.eax) = 0 /*0x0*/;
    // 00480473  40                     -inc eax
    (cpu.eax)++;
    // 00480474  39ca                   +cmp edx, ecx
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
    // 00480476  7cf7                   -jl 0x48046f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048046f;
    }
    // 00480478  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480479  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048047a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048047b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_480480(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480480  803db0cd4c0000         +cmp byte ptr [0x4ccdb0], 0
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
    // 00480487  740f                   -je 0x480498
    if (cpu.flags.zf)
    {
        goto L_0x00480498;
    }
    // 00480489  83f87f                 +cmp eax, 0x7f
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
    // 0048048c  7f04                   -jg 0x480492
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00480492;
    }
    // 0048048e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00480490  7d0c                   -jge 0x48049e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048049e;
    }
L_0x00480492:
    // 00480492  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 00480497  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00480498:
    // 00480498  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 0048049d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048049e:
    // 0048049e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048049f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004804a0  a272c34c00             -mov byte ptr [0x4cc372], al
    app->getMemory<x86::reg8>(x86::reg32(5030770) /* 0x4cc372 */) = cpu.al;
    // 004804a5  8b0d00c34c00           -mov ecx, dword ptr [0x4cc300]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5030656) /* 0x4cc300 */);
    // 004804ab  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004804ad  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004804af  e868010000             -call 0x48061c
    cpu.esp -= 4;
    sub_48061c(app, cpu);
    if (cpu.terminate) return;
    // 004804b4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004804b6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004804b7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004804b8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4804c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004804c0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004804c1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004804c2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004804c4  8a25b0cd4c00           -mov ah, byte ptr [0x4ccdb0]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5033392) /* 0x4ccdb0 */);
    // 004804ca  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004804cc  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 004804ce  750a                   -jne 0x4804da
    if (!cpu.flags.zf)
    {
        goto L_0x004804da;
    }
    // 004804d0  baf6ffffff             -mov edx, 0xfffffff6
    cpu.edx = 4294967286 /*0xfffffff6*/;
    // 004804d5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004804d7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004804d8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004804d9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004804da:
    // 004804da  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004804db  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004804dc  e8cf880100             -call 0x498db0
    cpu.esp -= 4;
    sub_498db0(app, cpu);
    if (cpu.terminate) return;
    // 004804e1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004804e3  e8d48c0100             -call 0x4991bc
    cpu.esp -= 4;
    sub_4991bc(app, cpu);
    if (cpu.terminate) return;
    // 004804e8  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004804ea  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004804ec  7c56                   -jl 0x480544
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00480544;
    }
    // 004804ee  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004804f1  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004804f3  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004804f6  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004804f8  8a980ba85200           -mov bl, byte ptr [eax + 0x52a80b]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5416971) /* 0x52a80b */);
    // 004804fe  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00480500  7439                   -je 0x48053b
    if (cpu.flags.zf)
    {
        goto L_0x0048053b;
    }
    // 00480502  b9d0a75200             -mov ecx, 0x52a7d0
    cpu.ecx = 5416912 /*0x52a7d0*/;
    // 00480507  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00480509:
    // 00480509  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048050b  8a413b                 -mov al, byte ptr [ecx + 0x3b]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(59) /* 0x3b */);
    // 0048050e  39d8                   +cmp eax, ebx
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
    // 00480510  7512                   -jne 0x480524
    if (!cpu.flags.zf)
    {
        goto L_0x00480524;
    }
    // 00480512  80790c01               +cmp byte ptr [ecx + 0xc], 1
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
    // 00480516  750c                   -jne 0x480524
    if (!cpu.flags.zf)
    {
        goto L_0x00480524;
    }
    // 00480518  833900                 +cmp dword ptr [ecx], 0
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
    // 0048051b  7c07                   -jl 0x480524
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00480524;
    }
    // 0048051d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048051f  e8d8fcffff             -call 0x4801fc
    cpu.esp -= 4;
    sub_4801fc(app, cpu);
    if (cpu.terminate) return;
L_0x00480524:
    // 00480524  42                     -inc edx
    (cpu.edx)++;
    // 00480525  83c160                 -add ecx, 0x60
    (cpu.ecx) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 00480528  83fa10                 +cmp edx, 0x10
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
    // 0048052b  7cdc                   -jl 0x480509
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00480509;
    }
L_0x0048052d:
    // 0048052d  e892880100             -call 0x498dc4
    cpu.esp -= 4;
    sub_498dc4(app, cpu);
    if (cpu.terminate) return;
    // 00480532  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00480534  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480535  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480536  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00480538  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480539  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048053a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048053b:
    // 0048053b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048053d  e8bafcffff             -call 0x4801fc
    cpu.esp -= 4;
    sub_4801fc(app, cpu);
    if (cpu.terminate) return;
    // 00480542  ebe9                   -jmp 0x48052d
    goto L_0x0048052d;
L_0x00480544:
    // 00480544  bef8ffffff             -mov esi, 0xfffffff8
    cpu.esi = 4294967288 /*0xfffffff8*/;
    // 00480549  e876880100             -call 0x498dc4
    cpu.esp -= 4;
    sub_498dc4(app, cpu);
    if (cpu.terminate) return;
    // 0048054e  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00480550  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480551  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480552  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00480554  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480555  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480556  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_480560(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480560  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00480561  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00480562  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00480563  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00480565  e8528c0100             -call 0x4991bc
    cpu.esp -= 4;
    sub_4991bc(app, cpu);
    if (cpu.terminate) return;
    // 0048056a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048056c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048056e  0f8c75000000           -jl 0x4805e9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004805e9;
    }
    // 00480574  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 0048057b  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0048057d  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 00480580  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00480582  81c2d0a75200           -add edx, 0x52a7d0
    (cpu.edx) += x86::reg32(x86::sreg32(5416912 /*0x52a7d0*/));
    // 00480588  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 0048058b  8b5a20                 -mov ebx, dword ptr [edx + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 0048058e  39d8                   +cmp eax, ebx
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
    // 00480590  7460                   -je 0x4805f2
    if (cpu.flags.zf)
    {
        goto L_0x004805f2;
    }
    // 00480592  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00480593  0fb67a3b               -movzx edi, byte ptr [edx + 0x3b]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(59) /* 0x3b */));
    // 00480597  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00480599  745d                   -je 0x4805f8
    if (cpu.flags.zf)
    {
        goto L_0x004805f8;
    }
    // 0048059b  b9d0a75200             -mov ecx, 0x52a7d0
    cpu.ecx = 5416912 /*0x52a7d0*/;
    // 004805a0  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004805a2:
    // 004805a2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004805a4  8a513b                 -mov dl, byte ptr [ecx + 0x3b]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(59) /* 0x3b */);
    // 004805a7  39fa                   +cmp edx, edi
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
    // 004805a9  752e                   -jne 0x4805d9
    if (!cpu.flags.zf)
    {
        goto L_0x004805d9;
    }
    // 004805ab  80790c01               +cmp byte ptr [ecx + 0xc], 1
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
    // 004805af  7528                   -jne 0x4805d9
    if (!cpu.flags.zf)
    {
        goto L_0x004805d9;
    }
    // 004805b1  833900                 +cmp dword ptr [ecx], 0
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
    // 004805b4  7c23                   -jl 0x4805d9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004805d9;
    }
    // 004805b6  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004805b8  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004805bb  894120                 -mov dword ptr [ecx + 0x20], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 004805be  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004805c0  c7411800000000         -mov dword ptr [ecx + 0x18], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 004805c7  e824cd0100             -call 0x49d2f0
    cpu.esp -= 4;
    sub_49d2f0(app, cpu);
    if (cpu.terminate) return;
    // 004805cc  8b512e                 -mov edx, dword ptr [ecx + 0x2e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(46) /* 0x2e */);
    // 004805cf  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004805d1  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004805d4  e84bfbffff             -call 0x480124
    cpu.esp -= 4;
    sub_480124(app, cpu);
    if (cpu.terminate) return;
L_0x004805d9:
    // 004805d9  43                     -inc ebx
    (cpu.ebx)++;
    // 004805da  83c160                 -add ecx, 0x60
    (cpu.ecx) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 004805dd  83fb10                 +cmp ebx, 0x10
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
    // 004805e0  7cc0                   -jl 0x4805a2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004805a2;
    }
    // 004805e2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004805e4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004805e5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004805e6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004805e7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004805e8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004805e9:
    // 004805e9  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 004805ee  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004805ef  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004805f0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004805f1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004805f2:
    // 004805f2  31d8                   -xor eax, ebx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004805f4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004805f5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004805f6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004805f7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004805f8:
    // 004805f8  894220                 -mov dword ptr [edx + 0x20], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 004805fb  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004805fd  897a18                 -mov dword ptr [edx + 0x18], edi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 00480600  e8ebcc0100             -call 0x49d2f0
    cpu.esp -= 4;
    sub_49d2f0(app, cpu);
    if (cpu.terminate) return;
    // 00480605  8b522e                 -mov edx, dword ptr [edx + 0x2e]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(46) /* 0x2e */);
    // 00480608  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048060a  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 0048060d  e812fbffff             -call 0x480124
    cpu.esp -= 4;
    sub_480124(app, cpu);
    if (cpu.terminate) return;
    // 00480612  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00480614  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480615  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480616  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480617  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480618  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48061c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048061c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048061d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048061f  803db0cd4c0000         +cmp byte ptr [0x4ccdb0], 0
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
    // 00480626  7410                   -je 0x480638
    if (cpu.flags.zf)
    {
        goto L_0x00480638;
    }
    // 00480628  83fa7f                 +cmp edx, 0x7f
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
    // 0048062b  7f04                   -jg 0x480631
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00480631;
    }
    // 0048062d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048062f  7d0e                   -jge 0x48063f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048063f;
    }
L_0x00480631:
    // 00480631  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 00480636  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480637  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00480638:
    // 00480638  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 0048063d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048063e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048063f:
    // 0048063f  e86c870100             -call 0x498db0
    cpu.esp -= 4;
    sub_498db0(app, cpu);
    if (cpu.terminate) return;
    // 00480644  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00480646  e815ffffff             -call 0x480560
    cpu.esp -= 4;
    sub_480560(app, cpu);
    if (cpu.terminate) return;
    // 0048064b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048064d  e872870100             -call 0x498dc4
    cpu.esp -= 4;
    sub_498dc4(app, cpu);
    if (cpu.terminate) return;
    // 00480652  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00480654  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480655  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_480660(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480660  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00480661  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00480662  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00480663  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00480666  8b1d40af4c00           -mov ebx, dword ptr [0x4caf40]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5025600) /* 0x4caf40 */);
    // 0048066c  8b353caf4c00           -mov esi, dword ptr [0x4caf3c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5025596) /* 0x4caf3c */);
    // 00480672  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 00480679  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0048067b  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0048067e  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00480681  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00480683  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00480685  e8ba4e0100             -call 0x495544
    cpu.esp -= 4;
    sub_495544(app, cpu);
    if (cpu.terminate) return;
    // 0048068a  8b353caf4c00           -mov esi, dword ptr [0x4caf3c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5025596) /* 0x4caf3c */);
    // 00480690  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00480692  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00480694  741d                   -je 0x4806b3
    if (cpu.flags.zf)
    {
        goto L_0x004806b3;
    }
    // 00480696  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00480697  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00480699  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048069b  7e13                   -jle 0x4806b0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004806b0;
    }
L_0x0048069d:
    // 0048069d  c7430445455246         -mov dword ptr [ebx + 4], 0x46524545
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = 1179796805 /*0x46524545*/;
    // 004806a4  42                     -inc edx
    (cpu.edx)++;
    // 004806a5  890b                   -mov dword ptr [ebx], ecx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.ecx;
    // 004806a7  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004806a9  83c318                 -add ebx, 0x18
    (cpu.ebx) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004806ac  39f2                   +cmp edx, esi
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
    // 004806ae  7ced                   -jl 0x48069d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048069d;
    }
L_0x004806b0:
    // 004806b0  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004806b2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004806b3:
    // 004806b3  89353caf4c00           -mov dword ptr [0x4caf3c], esi
    app->getMemory<x86::reg32>(x86::reg32(5025596) /* 0x4caf3c */) = cpu.esi;
    // 004806b9  891d40af4c00           -mov dword ptr [0x4caf40], ebx
    app->getMemory<x86::reg32>(x86::reg32(5025600) /* 0x4caf40 */) = cpu.ebx;
    // 004806bf  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004806c2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004806c3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004806c4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004806c5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4806c8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004806c8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004806c9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004806ca  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004806cb  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004806cd  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004806cf  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004806d1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004806d2  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004806d4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004806d5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004806d6  2eff15cc754b00         -call dword ptr cs:[0x4b75cc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945356) /* 0x4b75cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004806dd  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004806df  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004806e1  7c04                   -jl 0x4806e7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004806e7;
    }
    // 004806e3  39f8                   +cmp eax, edi
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
    // 004806e5  7c0c                   -jl 0x4806f3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004806f3;
    }
L_0x004806e7:
    // 004806e7  81fb02010000           -cmp ebx, 0x102
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(258 /*0x102*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004806ed  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004806ef  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004806f0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004806f1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004806f2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004806f3:
    // 004806f3  8b0486                 -mov eax, dword ptr [esi + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + cpu.eax * 4);
    // 004806f6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004806f7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004806f8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004806f9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4806fc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004806fc  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00480700  ffd0                   -call eax
    cpu.ip = cpu.eax;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00480702  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00480704  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x90 */
void Application::sub_480708(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480708  833dd8dc510000         +cmp dword ptr [0x51dcd8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5364952) /* 0x51dcd8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048070f  7401                   -je 0x480712
    if (cpu.flags.zf)
    {
        goto L_0x00480712;
    }
    // 00480711  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00480712:
    // 00480712  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00480713  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00480714  2eff15c8744b00         -call dword ptr cs:[0x4b74c8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945096) /* 0x4b74c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048071b  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0048071d  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048071f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00480721  68d0dc5100             -push 0x51dcd0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5364944 /*0x51dcd0*/;
    cpu.esp -= 4;
    // 00480726  a3d4dc5100             -mov dword ptr [0x51dcd4], eax
    app->getMemory<x86::reg32>(x86::reg32(5364948) /* 0x51dcd4 */) = cpu.eax;
    // 0048072b  2eff15c0744b00         -call dword ptr cs:[0x4b74c0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945088) /* 0x4b74c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00480732  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00480733  2eff15cc744b00         -call dword ptr cs:[0x4b74cc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945100) /* 0x4b74cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048073a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048073b  2eff15c0744b00         -call dword ptr cs:[0x4b74c0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945088) /* 0x4b74c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00480742  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00480743  2eff1574744b00         -call dword ptr cs:[0x4b7474]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945012) /* 0x4b7474 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048074a  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0048074f  e80cffffff             -call 0x480660
    cpu.esp -= 4;
    sub_480660(app, cpu);
    if (cpu.terminate) return;
    // 00480754  890dd8dc5100           -mov dword ptr [0x51dcd8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5364952) /* 0x51dcd8 */) = cpu.ecx;
    // 0048075a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048075b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048075c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_480760(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480760  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00480761  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00480762  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00480763  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00480766  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00480768  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0048076a  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0048076e  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00480770  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00480771  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 00480773  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00480774  68fc064800             -push 0x4806fc
    app->getMemory<x86::reg32>(cpu.esp-4) = 4720380 /*0x4806fc*/;
    cpu.esp -= 4;
    // 00480779  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048077a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048077c  2eff1564744b00         -call dword ptr cs:[0x4b7464]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944996) /* 0x4b7464 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00480783  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00480785  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00480787  7441                   -je 0x4807ca
    if (cpu.flags.zf)
    {
        goto L_0x004807ca;
    }
    // 00480789  833dd8dc510000         +cmp dword ptr [0x51dcd8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5364952) /* 0x51dcd8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480790  7507                   -jne 0x480799
    if (!cpu.flags.zf)
    {
        goto L_0x00480799;
    }
    // 00480792  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00480794  e86fffffff             -call 0x480708
    cpu.esp -= 4;
    sub_480708(app, cpu);
    if (cpu.terminate) return;
L_0x00480799:
    // 00480799  c7430c00000000         -mov dword ptr [ebx + 0xc], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 004807a0  893b                   -mov dword ptr [ebx], edi
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edi;
    // 004807a2  896b04                 -mov dword ptr [ebx + 4], ebp
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 004807a5  897308                 -mov dword ptr [ebx + 8], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 004807a8  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004807ab  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004807ad  894310                 -mov dword ptr [ebx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004807b0  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004807b2  e8a9010000             -call 0x480960
    cpu.esp -= 4;
    sub_480960(app, cpu);
    if (cpu.terminate) return;
    // 004807b7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004807b8  2eff1560754b00         -call dword ptr cs:[0x4b7560]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945248) /* 0x4b7560 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004807bf  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004807c1  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004807c3  2eff15a0754b00         -call dword ptr cs:[0x4b75a0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945312) /* 0x4b75a0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004807ca:
    // 004807ca  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004807cc  740e                   -je 0x4807dc
    if (cpu.flags.zf)
    {
        goto L_0x004807dc;
    }
    // 004807ce  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004807d3  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004807d6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004807d7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004807d8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004807d9  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004807dc:
    // 004807dc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004807de  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004807e1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004807e2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004807e3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004807e4  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x90 */
void Application::sub_4807e8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004807e8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004807ea  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4807f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004807f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004807f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004807f2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004807f3  83f8ff                 +cmp eax, -1
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
    // 004807f6  7418                   -je 0x480810
    if (cpu.flags.zf)
    {
        goto L_0x00480810;
    }
    // 004807f8  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
L_0x004807fa:
    // 004807fa  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004807fc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004807fd  2eff15a4754b00         -call dword ptr cs:[0x4b75a4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945316) /* 0x4b75a4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00480804  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00480805  2eff1550744b00         -call dword ptr cs:[0x4b7450]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944976) /* 0x4b7450 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048080c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048080d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048080e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048080f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00480810:
    // 00480810  2eff15cc744b00         -call dword ptr cs:[0x4b74cc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945100) /* 0x4b74cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00480817  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00480819  ebdf                   -jmp 0x4807fa
    goto L_0x004807fa;
}

/* align: skip 0x90 */
void Application::sub_48081c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048081c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048081d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048081e  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00480820  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00480821  2eff15a0754b00         -call dword ptr cs:[0x4b75a0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945312) /* 0x4b75a0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00480828  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480829  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048082a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48082c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048082c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048082d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048082e  8b0d20a44c00           -mov ecx, dword ptr [0x4ca420]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5022752) /* 0x4ca420 */);
    // 00480834  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00480836  7505                   -jne 0x48083d
    if (!cpu.flags.zf)
    {
        goto L_0x0048083d;
    }
    // 00480838  b964000000             -mov ecx, 0x64
    cpu.ecx = 100 /*0x64*/;
L_0x0048083d:
    // 0048083d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048083f  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00480842  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00480844  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00480847  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00480849  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0048084c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048084e  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00480851  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00480853  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00480855  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00480858  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0048085a  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0048085c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048085d  2eff15a0754b00         -call dword ptr cs:[0x4b75a0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945312) /* 0x4b75a0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00480864  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480865  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480866  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_480868(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480868  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00480869  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048086a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048086b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048086d  2eff15c8744b00         -call dword ptr cs:[0x4b74c8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945096) /* 0x4b74c8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00480874  8b0dd8dc5100           -mov ecx, dword ptr [0x51dcd8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5364952) /* 0x51dcd8 */);
    // 0048087a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048087c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048087e  7415                   -je 0x480895
    if (cpu.flags.zf)
    {
        goto L_0x00480895;
    }
L_0x00480880:
    // 00480880  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00480882  7520                   -jne 0x4808a4
    if (!cpu.flags.zf)
    {
        goto L_0x004808a4;
    }
    // 00480884  3b15d4dc5100           +cmp edx, dword ptr [0x51dcd4]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5364948) /* 0x51dcd4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048088a  7512                   -jne 0x48089e
    if (!cpu.flags.zf)
    {
        goto L_0x0048089e;
    }
L_0x0048088c:
    // 0048088c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00480891  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480892  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480893  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480894  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00480895:
    // 00480895  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00480897  e86cfeffff             -call 0x480708
    cpu.esp -= 4;
    sub_480708(app, cpu);
    if (cpu.terminate) return;
    // 0048089c  ebe2                   -jmp 0x480880
    goto L_0x00480880;
L_0x0048089e:
    // 0048089e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004808a0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004808a1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004808a2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004808a3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004808a4:
    // 004808a4  83fbff                 +cmp ebx, -1
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
    // 004808a7  74e3                   -je 0x48088c
    if (cpu.flags.zf)
    {
        goto L_0x0048088c;
    }
    // 004808a9  3b5310                 +cmp edx, dword ptr [ebx + 0x10]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004808ac  74de                   -je 0x48088c
    if (cpu.flags.zf)
    {
        goto L_0x0048088c;
    }
    // 004808ae  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004808b0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004808b1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004808b2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004808b3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4808b4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004808b4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004808b5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004808b6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004808b8  833dd8dc510000         +cmp dword ptr [0x51dcd8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5364952) /* 0x51dcd8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004808bf  742f                   -je 0x4808f0
    if (cpu.flags.zf)
    {
        goto L_0x004808f0;
    }
L_0x004808c1:
    // 004808c1  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004808c3  7534                   -jne 0x4808f9
    if (!cpu.flags.zf)
    {
        goto L_0x004808f9;
    }
    // 004808c5  a1d0dc5100             -mov eax, dword ptr [0x51dcd0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364944) /* 0x51dcd0 */);
L_0x004808ca:
    // 004808ca  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004808cb  2eff151c754b00         -call dword ptr cs:[0x4b751c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945180) /* 0x4b751c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004808d2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004808d4  7c35                   -jl 0x48090b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048090b;
    }
    // 004808d6  0f8e5b000000           -jle 0x480937
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00480937;
    }
    // 004808dc  83f802                 +cmp eax, 2
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
    // 004808df  7c4e                   -jl 0x48092f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048092f;
    }
    // 004808e1  7e44                   -jle 0x480927
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00480927;
    }
    // 004808e3  83f80f                 +cmp eax, 0xf
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
    // 004808e6  754f                   -jne 0x480937
    if (!cpu.flags.zf)
    {
        goto L_0x00480937;
    }
    // 004808e8  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 004808ed  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004808ee  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004808ef  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004808f0:
    // 004808f0  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004808f2  e811feffff             -call 0x480708
    cpu.esp -= 4;
    sub_480708(app, cpu);
    if (cpu.terminate) return;
    // 004808f7  ebc8                   -jmp 0x4808c1
    goto L_0x004808c1;
L_0x004808f9:
    // 004808f9  83faff                 +cmp edx, -1
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
    // 004808fc  7404                   -je 0x480902
    if (cpu.flags.zf)
    {
        goto L_0x00480902;
    }
    // 004808fe  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00480900  ebc8                   -jmp 0x4808ca
    goto L_0x004808ca;
L_0x00480902:
    // 00480902  2eff15cc744b00         -call dword ptr cs:[0x4b74cc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945100) /* 0x4b74cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00480909  ebbf                   -jmp 0x4808ca
    goto L_0x004808ca;
L_0x0048090b:
    // 0048090b  83f8fe                 +cmp eax, -2
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-2 /*-0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048090e  7d0d                   -jge 0x48091d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048091d;
    }
    // 00480910  83f8f1                 +cmp eax, -0xf
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-15 /*-0xf*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480913  7522                   -jne 0x480937
    if (!cpu.flags.zf)
    {
        goto L_0x00480937;
    }
    // 00480915  b8fdffffff             -mov eax, 0xfffffffd
    cpu.eax = 4294967293 /*0xfffffffd*/;
    // 0048091a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048091b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048091c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048091d:
    // 0048091d  7f1d                   -jg 0x48093c
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048093c;
    }
    // 0048091f  b8feffffff             -mov eax, 0xfffffffe
    cpu.eax = 4294967294 /*0xfffffffe*/;
    // 00480924  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480925  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480926  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00480927:
    // 00480927  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0048092c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048092d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048092e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048092f:
    // 0048092f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00480934  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480935  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480936  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00480937:
    // 00480937  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00480939  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048093a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048093b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048093c:
    // 0048093c  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00480941  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480942  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480943  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_480960(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00480960  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00480961  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00480962  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00480964  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00480966  833dd8dc510000         +cmp dword ptr [0x51dcd8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5364952) /* 0x51dcd8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048096d  742a                   -je 0x480999
    if (cpu.flags.zf)
    {
        goto L_0x00480999;
    }
L_0x0048096f:
    // 0048096f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00480971  752f                   -jne 0x4809a2
    if (!cpu.flags.zf)
    {
        goto L_0x004809a2;
    }
    // 00480973  8b0dd0dc5100           -mov ecx, dword ptr [0x51dcd0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5364944) /* 0x51dcd0 */);
    // 00480979  8d4303                 -lea eax, [ebx + 3]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(3) /* 0x3 */);
    // 0048097c  83f806                 +cmp eax, 6
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048097f  7764                   -ja 0x4809e5
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004809e5;
    }
    // 00480981  ff248544094800         -jmp dword ptr [eax*4 + 0x480944]
    cpu.ip = app->getMemory<x86::reg32>(4720964 + cpu.eax * 4); goto dynamic_jump;
  case 0x00480988:
    // 00480988  b8f1ffffff             -mov eax, 0xfffffff1
    cpu.eax = 4294967281 /*0xfffffff1*/;
L_0x0048098d:
    // 0048098d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048098e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048098f  2eff1598754b00         -call dword ptr cs:[0x4b7598]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945304) /* 0x4b7598 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00480996  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480997  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480998  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00480999:
    // 00480999  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0048099b  e868fdffff             -call 0x480708
    cpu.esp -= 4;
    sub_480708(app, cpu);
    if (cpu.terminate) return;
    // 004809a0  ebcd                   -jmp 0x48096f
    goto L_0x0048096f;
L_0x004809a2:
    // 004809a2  83f9ff                 +cmp ecx, -1
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
    // 004809a5  7411                   -je 0x4809b8
    if (cpu.flags.zf)
    {
        goto L_0x004809b8;
    }
    // 004809a7  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004809a9  8d4303                 -lea eax, [ebx + 3]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(3) /* 0x3 */);
    // 004809ac  83f806                 +cmp eax, 6
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004809af  7734                   -ja 0x4809e5
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004809e5;
    }
    // 004809b1  ff248544094800         -jmp dword ptr [eax*4 + 0x480944]
    cpu.ip = app->getMemory<x86::reg32>(4720964 + cpu.eax * 4); goto dynamic_jump;
L_0x004809b8:
    // 004809b8  2eff15cc744b00         -call dword ptr cs:[0x4b74cc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945100) /* 0x4b74cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004809bf  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004809c1  8d4303                 -lea eax, [ebx + 3]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(3) /* 0x3 */);
    // 004809c4  83f806                 +cmp eax, 6
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004809c7  771c                   -ja 0x4809e5
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004809e5;
    }
    // 004809c9  ff248544094800         -jmp dword ptr [eax*4 + 0x480944]
    cpu.ip = app->getMemory<x86::reg32>(4720964 + cpu.eax * 4); goto dynamic_jump;
  case 0x004809d0:
    // 004809d0  b80f000000             -mov eax, 0xf
    cpu.eax = 15 /*0xf*/;
    // 004809d5  ebb6                   -jmp 0x48098d
    goto L_0x0048098d;
  case 0x004809d7:
    // 004809d7  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 004809dc  ebaf                   -jmp 0x48098d
    goto L_0x0048098d;
  case 0x004809de:
    // 004809de  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004809e3  eba8                   -jmp 0x48098d
    goto L_0x0048098d;
  case 0x004809e5:
L_0x004809e5:
    // 004809e5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004809e7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004809e8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004809e9  2eff1598754b00         -call dword ptr cs:[0x4b7598]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945304) /* 0x4b7598 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004809f0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004809f1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004809f2  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x004809f3:
    // 004809f3  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004809f8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004809f9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004809fa  2eff1598754b00         -call dword ptr cs:[0x4b7598]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945304) /* 0x4b7598 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00480a01  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480a02  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480a03  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00480a04:
    // 00480a04  b8feffffff             -mov eax, 0xfffffffe
    cpu.eax = 4294967294 /*0xfffffffe*/;
    // 00480a09  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00480a0a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00480a0b  2eff1598754b00         -call dword ptr cs:[0x4b7598]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945304) /* 0x4b7598 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00480a12  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480a13  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480a14  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_480a18(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480a18  833d44af4c0000         +cmp dword ptr [0x4caf44], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5025604) /* 0x4caf44 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480a1f  750a                   -jne 0x480a2b
    if (!cpu.flags.zf)
    {
        goto L_0x00480a2b;
    }
    // 00480a21  e852010000             -call 0x480b78
    cpu.esp -= 4;
    sub_480b78(app, cpu);
    if (cpu.terminate) return;
    // 00480a26  a344af4c00             -mov dword ptr [0x4caf44], eax
    app->getMemory<x86::reg32>(x86::reg32(5025604) /* 0x4caf44 */) = cpu.eax;
L_0x00480a2b:
    // 00480a2b  a144af4c00             -mov eax, dword ptr [0x4caf44]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5025604) /* 0x4caf44 */);
    // 00480a30  e893010000             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 00480a35  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00480a3a  e875feffff             -call 0x4808b4
    cpu.esp -= 4;
    sub_4808b4(app, cpu);
    if (cpu.terminate) return;
    // 00480a3f  83f803                 +cmp eax, 3
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
    // 00480a42  7501                   -jne 0x480a45
    if (!cpu.flags.zf)
    {
        goto L_0x00480a45;
    }
    // 00480a44  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00480a45:
    // 00480a45  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00480a46  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 00480a4b  a348af4c00             -mov dword ptr [0x4caf48], eax
    app->getMemory<x86::reg32>(x86::reg32(5025608) /* 0x4caf48 */) = cpu.eax;
    // 00480a50  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00480a55  e806ffffff             -call 0x480960
    cpu.esp -= 4;
    sub_480960(app, cpu);
    if (cpu.terminate) return;
    // 00480a5a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480a5b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_480a5c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480a5c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00480a5d  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00480a62  8b1548af4c00           -mov edx, dword ptr [0x4caf48]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5025608) /* 0x4caf48 */);
    // 00480a68  e8f3feffff             -call 0x480960
    cpu.esp -= 4;
    sub_480960(app, cpu);
    if (cpu.terminate) return;
    // 00480a6d  a144af4c00             -mov eax, dword ptr [0x4caf44]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5025604) /* 0x4caf44 */);
    // 00480a72  e869010000             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 00480a77  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480a78  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_480a7c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480a7c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00480a7d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00480a7e  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00480a80  2eff1584744b00         -call dword ptr cs:[0x4b7484]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945028) /* 0x4b7484 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00480a87  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480a88  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480a89  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_480a8c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480a8c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00480a8d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00480a8e  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00480a90  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00480a92  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00480a94  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00480a96  2eff1554744b00         -call dword ptr cs:[0x4b7454]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944980) /* 0x4b7454 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00480a9d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480a9e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480a9f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_480aa0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480aa0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00480aa1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00480aa2  2eff1584754b00         -call dword ptr cs:[0x4b7584]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945284) /* 0x4b7584 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00480aa9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480aaa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_480aac(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480aac  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00480aad  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00480aae  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00480ab1  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00480ab4  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00480ab6  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00480abb  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00480abd  e806fcffff             -call 0x4806c8
    cpu.esp -= 4;
    sub_4806c8(app, cpu);
    if (cpu.terminate) return;
    // 00480ac2  3b0424                 +cmp eax, dword ptr [esp]
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
    // 00480ac5  750b                   -jne 0x480ad2
    if (!cpu.flags.zf)
    {
        goto L_0x00480ad2;
    }
    // 00480ac7  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00480acc  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00480acf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480ad0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480ad1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00480ad2:
    // 00480ad2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00480ad4  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00480ad7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480ad8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480ad9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_480adc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480adc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00480add  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00480ade  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00480ae1  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00480ae4  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 00480ae9  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00480aeb  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00480af0  e8d3fbffff             -call 0x4806c8
    cpu.esp -= 4;
    sub_4806c8(app, cpu);
    if (cpu.terminate) return;
    // 00480af5  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00480af8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480af9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480afa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_480afc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480afc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00480afd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00480afe  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00480b01  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00480b04  8b0d20a44c00           -mov ecx, dword ptr [0x4ca420]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5022752) /* 0x4ca420 */);
    // 00480b0a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00480b0c  7505                   -jne 0x480b13
    if (!cpu.flags.zf)
    {
        goto L_0x00480b13;
    }
    // 00480b0e  b964000000             -mov ecx, 0x64
    cpu.ecx = 100 /*0x64*/;
L_0x00480b13:
    // 00480b13  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00480b1a  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00480b1c  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00480b1f  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00480b21  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00480b24  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00480b26  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00480b29  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00480b2b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00480b2d  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00480b30  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00480b32  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00480b34  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00480b36  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00480b3b  e888fbffff             -call 0x4806c8
    cpu.esp -= 4;
    sub_4806c8(app, cpu);
    if (cpu.terminate) return;
    // 00480b40  3b0424                 +cmp eax, dword ptr [esp]
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
    // 00480b43  750b                   -jne 0x480b50
    if (!cpu.flags.zf)
    {
        goto L_0x00480b50;
    }
    // 00480b45  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00480b4a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00480b4d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480b4e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480b4f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00480b50:
    // 00480b50  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00480b52  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00480b55  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480b56  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480b57  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_480b58(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480b58  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00480b59  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 00480b5e  e865fbffff             -call 0x4806c8
    cpu.esp -= 4;
    sub_4806c8(app, cpu);
    if (cpu.terminate) return;
    // 00480b63  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480b64  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_480b68(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480b68  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00480b69  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00480b6a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00480b6b  2eff1550744b00         -call dword ptr cs:[0x4b7450]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4944976) /* 0x4b7450 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00480b72  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480b73  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480b74  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_480b78(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480b78  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00480b79  833d40af4c0000         +cmp dword ptr [0x4caf40], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5025600) /* 0x4caf40 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480b80  740e                   -je 0x480b90
    if (cpu.flags.zf)
    {
        goto L_0x00480b90;
    }
    // 00480b82  8b0d40af4c00           -mov ecx, dword ptr [0x4caf40]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5025600) /* 0x4caf40 */);
    // 00480b88  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00480b8a  7517                   -jne 0x480ba3
    if (!cpu.flags.zf)
    {
        goto L_0x00480ba3;
    }
    // 00480b8c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00480b8e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480b8f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00480b90:
    // 00480b90  e8cbfaffff             -call 0x480660
    cpu.esp -= 4;
    sub_480660(app, cpu);
    if (cpu.terminate) return;
    // 00480b95  8b0d40af4c00           -mov ecx, dword ptr [0x4caf40]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5025600) /* 0x4caf40 */);
    // 00480b9b  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00480b9d  7504                   -jne 0x480ba3
    if (!cpu.flags.zf)
    {
        goto L_0x00480ba3;
    }
    // 00480b9f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00480ba1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480ba2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00480ba3:
    // 00480ba3  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00480ba4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00480ba5  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00480ba7  ba18000000             -mov edx, 0x18
    cpu.edx = 24 /*0x18*/;
    // 00480bac  a340af4c00             -mov dword ptr [0x4caf40], eax
    app->getMemory<x86::reg32>(x86::reg32(5025600) /* 0x4caf40 */) = cpu.eax;
    // 00480bb1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00480bb3  e8e4000000             -call 0x480c9c
    cpu.esp -= 4;
    sub_480c9c(app, cpu);
    if (cpu.terminate) return;
    // 00480bb8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00480bb9  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00480bbb  2eff1538754b00         -call dword ptr cs:[0x4b7538]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945208) /* 0x4b7538 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00480bc2  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00480bc4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480bc5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480bc6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480bc7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_480bc8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480bc8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00480bca  7501                   -jne 0x480bcd
    if (!cpu.flags.zf)
    {
        goto L_0x00480bcd;
    }
    // 00480bcc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00480bcd:
    // 00480bcd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00480bce  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00480bcf  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00480bd0  2eff1578744b00         -call dword ptr cs:[0x4b7478]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945016) /* 0x4b7478 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00480bd7  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00480bdc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480bdd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480bde  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_480be0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480be0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00480be2  7501                   -jne 0x480be5
    if (!cpu.flags.zf)
    {
        goto L_0x00480be5;
    }
    // 00480be4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00480be5:
    // 00480be5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00480be6  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00480be7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00480be8  2eff153c754b00         -call dword ptr cs:[0x4b753c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945212) /* 0x4b753c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00480bef  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480bf0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480bf1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_480bf4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480bf4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00480bf5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00480bf7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00480bf9  7502                   -jne 0x480bfd
    if (!cpu.flags.zf)
    {
        goto L_0x00480bfd;
    }
    // 00480bfb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480bfc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00480bfd:
    // 00480bfd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00480bfe  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00480bff  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00480c00  2eff156c744b00         -call dword ptr cs:[0x4b746c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945004) /* 0x4b746c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00480c07  a140af4c00             -mov eax, dword ptr [0x4caf40]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5025600) /* 0x4caf40 */);
    // 00480c0c  c7430445455246         -mov dword ptr [ebx + 4], 0x46524545
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = 1179796805 /*0x46524545*/;
    // 00480c13  891d40af4c00           -mov dword ptr [0x4caf40], ebx
    app->getMemory<x86::reg32>(x86::reg32(5025600) /* 0x4caf40 */) = cpu.ebx;
    // 00480c19  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 00480c1b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480c1c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480c1d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480c1e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_480c20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480c20  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00480c22  750b                   -jne 0x480c2f
    if (!cpu.flags.zf)
    {
        goto L_0x00480c2f;
    }
    // 00480c24  a1dcdc5100             -mov eax, dword ptr [0x51dcdc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364956) /* 0x51dcdc */);
    // 00480c29  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00480c2e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00480c2f:
    // 00480c2f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00480c30  8b15dcdc5100           -mov edx, dword ptr [0x51dcdc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5364956) /* 0x51dcdc */);
    // 00480c36  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00480c3c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00480c3d  68f0034c00             -push 0x4c03f0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4981744 /*0x4c03f0*/;
    cpu.esp -= 4;
    // 00480c42  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00480c43  e899b3ffff             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 00480c48  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00480c4b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480c4c  a1dcdc5100             -mov eax, dword ptr [0x51dcdc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5364956) /* 0x51dcdc */);
    // 00480c51  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00480c56  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_480c58(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480c58  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00480c59  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00480c5a  2eff15ec744b00         -call dword ptr cs:[0x4b74ec]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945132) /* 0x4b74ec */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00480c61  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00480c63  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00480c65  7503                   -jne 0x480c6a
    if (!cpu.flags.zf)
    {
        goto L_0x00480c6a;
    }
L_0x00480c67:
    // 00480c67  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480c68  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480c69  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00480c6a:
    // 00480c6a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00480c6c  e8f7fbffff             -call 0x480868
    cpu.esp -= 4;
    sub_480868(app, cpu);
    if (cpu.terminate) return;
    // 00480c71  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00480c73  74f2                   -je 0x480c67
    if (cpu.flags.zf)
    {
        goto L_0x00480c67;
    }
    // 00480c75  8915dcdc5100           -mov dword ptr [0x51dcdc], edx
    app->getMemory<x86::reg32>(x86::reg32(5364956) /* 0x51dcdc */) = cpu.edx;
    // 00480c7b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480c7c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480c7d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_480c80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480c80  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00480c81  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00480c83  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00480c85  7502                   -jne 0x480c89
    if (!cpu.flags.zf)
    {
        goto L_0x00480c89;
    }
L_0x00480c87:
    // 00480c87  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480c88  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00480c89:
    // 00480c89  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00480c8b  e8d8fbffff             -call 0x480868
    cpu.esp -= 4;
    sub_480868(app, cpu);
    if (cpu.terminate) return;
    // 00480c90  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00480c92  74f3                   -je 0x480c87
    if (cpu.flags.zf)
    {
        goto L_0x00480c87;
    }
    // 00480c94  8915dcdc5100           -mov dword ptr [0x51dcdc], edx
    app->getMemory<x86::reg32>(x86::reg32(5364956) /* 0x51dcdc */) = cpu.edx;
    // 00480c9a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480c9b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_480c9c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480c9c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00480c9d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00480c9f  e80d000000             -call 0x480cb1
    cpu.esp -= 4;
    sub_480cb1(app, cpu);
    if (cpu.terminate) return;
    // 00480ca4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480ca5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_480ca6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480ca6  88df                   -mov bh, bl
    cpu.bh = cpu.bl;
    // 00480ca8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00480ca9  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00480cab  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 00480cae  09c3                   -or ebx, eax
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.eax));
    // 00480cb0  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480cb1  a907000000             +test eax, 7
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 7 /*0x7*/));
    // 00480cb6  0f85a7000000           -jne 0x480d63
    if (!cpu.flags.zf)
    {
        goto L_0x00480d63;
    }
L_0x00480cbc:
    // 00480cbc  83fa00                 +cmp edx, 0
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480cbf  7c3f                   -jl 0x480d00
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00480d00;
    }
    // 00480cc1  80fbff                 +cmp bl, 0xff
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00480cc4  743b                   -je 0x480d01
    if (cpu.flags.zf)
    {
        goto L_0x00480d01;
    }
    // 00480cc6  38fb                   +cmp bl, bh
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
    // 00480cc8  7537                   -jne 0x480d01
    if (!cpu.flags.zf)
    {
        goto L_0x00480d01;
    }
    // 00480cca  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00480ccb  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00480ccc  dd0424                 -fld qword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp)));
    // 00480ccf  83ea20                 +sub edx, 0x20
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00480cd2  7813                   -js 0x480ce7
    if (cpu.flags.sf)
    {
        goto L_0x00480ce7;
    }
L_0x00480cd4:
    // 00480cd4  dd10                   -fst qword ptr [eax]
    app->getMemory<double>(cpu.eax) = double(cpu.fpu.st(0));
    // 00480cd6  dd5008                 -fst qword ptr [eax + 8]
    app->getMemory<double>(cpu.eax + x86::reg32(8) /* 0x8 */) = double(cpu.fpu.st(0));
    // 00480cd9  dd5010                 -fst qword ptr [eax + 0x10]
    app->getMemory<double>(cpu.eax + x86::reg32(16) /* 0x10 */) = double(cpu.fpu.st(0));
    // 00480cdc  dd5018                 -fst qword ptr [eax + 0x18]
    app->getMemory<double>(cpu.eax + x86::reg32(24) /* 0x18 */) = double(cpu.fpu.st(0));
    // 00480cdf  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 00480ce2  83ea20                 +sub edx, 0x20
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00480ce5  79ed                   -jns 0x480cd4
    if (!cpu.flags.sf)
    {
        goto L_0x00480cd4;
    }
L_0x00480ce7:
    // 00480ce7  83c218                 +add edx, 0x18
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00480cea  780a                   -js 0x480cf6
    if (cpu.flags.sf)
    {
        goto L_0x00480cf6;
    }
L_0x00480cec:
    // 00480cec  dd10                   -fst qword ptr [eax]
    app->getMemory<double>(cpu.eax) = double(cpu.fpu.st(0));
    // 00480cee  8d4008                 -lea eax, [eax + 8]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00480cf1  83ea08                 +sub edx, 8
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00480cf4  79f6                   -jns 0x480cec
    if (!cpu.flags.sf)
    {
        goto L_0x00480cec;
    }
L_0x00480cf6:
    // 00480cf6  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00480cf8  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00480cfb  83c208                 +add edx, 8
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00480cfe  753d                   -jne 0x480d3d
    if (!cpu.flags.zf)
    {
        goto L_0x00480d3d;
    }
L_0x00480d00:
    // 00480d00  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00480d01:
    // 00480d01  83ea20                 +sub edx, 0x20
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00480d04  781f                   -js 0x480d25
    if (cpu.flags.sf)
    {
        goto L_0x00480d25;
    }
L_0x00480d06:
    // 00480d06  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 00480d08  895804                 -mov dword ptr [eax + 4], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00480d0b  895808                 -mov dword ptr [eax + 8], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00480d0e  89580c                 -mov dword ptr [eax + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 00480d11  895810                 -mov dword ptr [eax + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 00480d14  895814                 -mov dword ptr [eax + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 00480d17  895818                 -mov dword ptr [eax + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 00480d1a  89581c                 -mov dword ptr [eax + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 00480d1d  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 00480d20  83ea20                 +sub edx, 0x20
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00480d23  79e1                   -jns 0x480d06
    if (!cpu.flags.sf)
    {
        goto L_0x00480d06;
    }
L_0x00480d25:
    // 00480d25  83c218                 +add edx, 0x18
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00480d28  780d                   -js 0x480d37
    if (cpu.flags.sf)
    {
        goto L_0x00480d37;
    }
L_0x00480d2a:
    // 00480d2a  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 00480d2c  895804                 -mov dword ptr [eax + 4], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00480d2f  8d4008                 -lea eax, [eax + 8]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00480d32  83ea08                 +sub edx, 8
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00480d35  79f3                   -jns 0x480d2a
    if (!cpu.flags.sf)
    {
        goto L_0x00480d2a;
    }
L_0x00480d37:
    // 00480d37  83c208                 +add edx, 8
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00480d3a  7501                   -jne 0x480d3d
    if (!cpu.flags.zf)
    {
        goto L_0x00480d3d;
    }
    // 00480d3c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00480d3d:
    // 00480d3d  f7c204000000           +test edx, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 4 /*0x4*/));
    // 00480d43  7405                   -je 0x480d4a
    if (cpu.flags.zf)
    {
        goto L_0x00480d4a;
    }
    // 00480d45  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 00480d47  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
L_0x00480d4a:
    // 00480d4a  f7c202000000           +test edx, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 2 /*0x2*/));
    // 00480d50  7406                   -je 0x480d58
    if (cpu.flags.zf)
    {
        goto L_0x00480d58;
    }
    // 00480d52  668918                 -mov word ptr [eax], bx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.bx;
    // 00480d55  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
L_0x00480d58:
    // 00480d58  f7c201000000           +test edx, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 1 /*0x1*/));
    // 00480d5e  7402                   -je 0x480d62
    if (cpu.flags.zf)
    {
        goto L_0x00480d62;
    }
    // 00480d60  8818                   -mov byte ptr [eax], bl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bl;
L_0x00480d62:
    // 00480d62  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00480d63:
    // 00480d63  a901000000             +test eax, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 1 /*0x1*/));
    // 00480d68  740d                   -je 0x480d77
    if (cpu.flags.zf)
    {
        goto L_0x00480d77;
    }
    // 00480d6a  83fa01                 +cmp edx, 1
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
    // 00480d6d  7c08                   -jl 0x480d77
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00480d77;
    }
    // 00480d6f  8818                   -mov byte ptr [eax], bl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bl;
    // 00480d71  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00480d74  83ea01                 -sub edx, 1
    (cpu.edx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x00480d77:
    // 00480d77  a902000000             +test eax, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2 /*0x2*/));
    // 00480d7c  740e                   -je 0x480d8c
    if (cpu.flags.zf)
    {
        goto L_0x00480d8c;
    }
    // 00480d7e  83fa02                 +cmp edx, 2
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
    // 00480d81  7c09                   -jl 0x480d8c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00480d8c;
    }
    // 00480d83  668918                 -mov word ptr [eax], bx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.bx;
    // 00480d86  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00480d89  83ea02                 -sub edx, 2
    (cpu.edx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x00480d8c:
    // 00480d8c  a904000000             +test eax, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 4 /*0x4*/));
    // 00480d91  740d                   -je 0x480da0
    if (cpu.flags.zf)
    {
        goto L_0x00480da0;
    }
    // 00480d93  83fa04                 +cmp edx, 4
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
    // 00480d96  7c08                   -jl 0x480da0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00480da0;
    }
    // 00480d98  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 00480d9a  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00480d9d  83ea04                 +sub edx, 4
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
L_0x00480da0:
    // 00480da0  e917ffffff             -jmp 0x480cbc
    goto L_0x00480cbc;
}

/* align: skip  */
void Application::sub_480cb1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00480cb1;
    // 00480ca6  88df                   -mov bh, bl
    cpu.bh = cpu.bl;
    // 00480ca8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00480ca9  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00480cab  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 00480cae  09c3                   -or ebx, eax
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.eax));
    // 00480cb0  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_entry_0x00480cb1:
    // 00480cb1  a907000000             +test eax, 7
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 7 /*0x7*/));
    // 00480cb6  0f85a7000000           -jne 0x480d63
    if (!cpu.flags.zf)
    {
        goto L_0x00480d63;
    }
L_0x00480cbc:
    // 00480cbc  83fa00                 +cmp edx, 0
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480cbf  7c3f                   -jl 0x480d00
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00480d00;
    }
    // 00480cc1  80fbff                 +cmp bl, 0xff
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00480cc4  743b                   -je 0x480d01
    if (cpu.flags.zf)
    {
        goto L_0x00480d01;
    }
    // 00480cc6  38fb                   +cmp bl, bh
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
    // 00480cc8  7537                   -jne 0x480d01
    if (!cpu.flags.zf)
    {
        goto L_0x00480d01;
    }
    // 00480cca  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00480ccb  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00480ccc  dd0424                 -fld qword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp)));
    // 00480ccf  83ea20                 +sub edx, 0x20
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00480cd2  7813                   -js 0x480ce7
    if (cpu.flags.sf)
    {
        goto L_0x00480ce7;
    }
L_0x00480cd4:
    // 00480cd4  dd10                   -fst qword ptr [eax]
    app->getMemory<double>(cpu.eax) = double(cpu.fpu.st(0));
    // 00480cd6  dd5008                 -fst qword ptr [eax + 8]
    app->getMemory<double>(cpu.eax + x86::reg32(8) /* 0x8 */) = double(cpu.fpu.st(0));
    // 00480cd9  dd5010                 -fst qword ptr [eax + 0x10]
    app->getMemory<double>(cpu.eax + x86::reg32(16) /* 0x10 */) = double(cpu.fpu.st(0));
    // 00480cdc  dd5018                 -fst qword ptr [eax + 0x18]
    app->getMemory<double>(cpu.eax + x86::reg32(24) /* 0x18 */) = double(cpu.fpu.st(0));
    // 00480cdf  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 00480ce2  83ea20                 +sub edx, 0x20
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00480ce5  79ed                   -jns 0x480cd4
    if (!cpu.flags.sf)
    {
        goto L_0x00480cd4;
    }
L_0x00480ce7:
    // 00480ce7  83c218                 +add edx, 0x18
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00480cea  780a                   -js 0x480cf6
    if (cpu.flags.sf)
    {
        goto L_0x00480cf6;
    }
L_0x00480cec:
    // 00480cec  dd10                   -fst qword ptr [eax]
    app->getMemory<double>(cpu.eax) = double(cpu.fpu.st(0));
    // 00480cee  8d4008                 -lea eax, [eax + 8]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00480cf1  83ea08                 +sub edx, 8
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00480cf4  79f6                   -jns 0x480cec
    if (!cpu.flags.sf)
    {
        goto L_0x00480cec;
    }
L_0x00480cf6:
    // 00480cf6  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00480cf8  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00480cfb  83c208                 +add edx, 8
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00480cfe  753d                   -jne 0x480d3d
    if (!cpu.flags.zf)
    {
        goto L_0x00480d3d;
    }
L_0x00480d00:
    // 00480d00  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00480d01:
    // 00480d01  83ea20                 +sub edx, 0x20
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00480d04  781f                   -js 0x480d25
    if (cpu.flags.sf)
    {
        goto L_0x00480d25;
    }
L_0x00480d06:
    // 00480d06  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 00480d08  895804                 -mov dword ptr [eax + 4], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00480d0b  895808                 -mov dword ptr [eax + 8], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00480d0e  89580c                 -mov dword ptr [eax + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 00480d11  895810                 -mov dword ptr [eax + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 00480d14  895814                 -mov dword ptr [eax + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 00480d17  895818                 -mov dword ptr [eax + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 00480d1a  89581c                 -mov dword ptr [eax + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 00480d1d  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 00480d20  83ea20                 +sub edx, 0x20
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00480d23  79e1                   -jns 0x480d06
    if (!cpu.flags.sf)
    {
        goto L_0x00480d06;
    }
L_0x00480d25:
    // 00480d25  83c218                 +add edx, 0x18
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00480d28  780d                   -js 0x480d37
    if (cpu.flags.sf)
    {
        goto L_0x00480d37;
    }
L_0x00480d2a:
    // 00480d2a  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 00480d2c  895804                 -mov dword ptr [eax + 4], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00480d2f  8d4008                 -lea eax, [eax + 8]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00480d32  83ea08                 +sub edx, 8
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00480d35  79f3                   -jns 0x480d2a
    if (!cpu.flags.sf)
    {
        goto L_0x00480d2a;
    }
L_0x00480d37:
    // 00480d37  83c208                 +add edx, 8
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00480d3a  7501                   -jne 0x480d3d
    if (!cpu.flags.zf)
    {
        goto L_0x00480d3d;
    }
    // 00480d3c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00480d3d:
    // 00480d3d  f7c204000000           +test edx, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 4 /*0x4*/));
    // 00480d43  7405                   -je 0x480d4a
    if (cpu.flags.zf)
    {
        goto L_0x00480d4a;
    }
    // 00480d45  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 00480d47  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
L_0x00480d4a:
    // 00480d4a  f7c202000000           +test edx, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 2 /*0x2*/));
    // 00480d50  7406                   -je 0x480d58
    if (cpu.flags.zf)
    {
        goto L_0x00480d58;
    }
    // 00480d52  668918                 -mov word ptr [eax], bx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.bx;
    // 00480d55  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
L_0x00480d58:
    // 00480d58  f7c201000000           +test edx, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 1 /*0x1*/));
    // 00480d5e  7402                   -je 0x480d62
    if (cpu.flags.zf)
    {
        goto L_0x00480d62;
    }
    // 00480d60  8818                   -mov byte ptr [eax], bl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bl;
L_0x00480d62:
    // 00480d62  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00480d63:
    // 00480d63  a901000000             +test eax, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 1 /*0x1*/));
    // 00480d68  740d                   -je 0x480d77
    if (cpu.flags.zf)
    {
        goto L_0x00480d77;
    }
    // 00480d6a  83fa01                 +cmp edx, 1
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
    // 00480d6d  7c08                   -jl 0x480d77
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00480d77;
    }
    // 00480d6f  8818                   -mov byte ptr [eax], bl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bl;
    // 00480d71  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00480d74  83ea01                 -sub edx, 1
    (cpu.edx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x00480d77:
    // 00480d77  a902000000             +test eax, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2 /*0x2*/));
    // 00480d7c  740e                   -je 0x480d8c
    if (cpu.flags.zf)
    {
        goto L_0x00480d8c;
    }
    // 00480d7e  83fa02                 +cmp edx, 2
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
    // 00480d81  7c09                   -jl 0x480d8c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00480d8c;
    }
    // 00480d83  668918                 -mov word ptr [eax], bx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.bx;
    // 00480d86  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00480d89  83ea02                 -sub edx, 2
    (cpu.edx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x00480d8c:
    // 00480d8c  a904000000             +test eax, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 4 /*0x4*/));
    // 00480d91  740d                   -je 0x480da0
    if (cpu.flags.zf)
    {
        goto L_0x00480da0;
    }
    // 00480d93  83fa04                 +cmp edx, 4
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
    // 00480d96  7c08                   -jl 0x480da0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00480da0;
    }
    // 00480d98  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 00480d9a  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00480d9d  83ea04                 +sub edx, 4
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
L_0x00480da0:
    // 00480da0  e917ffffff             -jmp 0x480cbc
    goto L_0x00480cbc;
}

/* align: skip  */
void Application::sub_480ca8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x00480ca8;
    // 00480ca6  88df                   -mov bh, bl
    cpu.bh = cpu.bl;
L_entry_0x00480ca8:
    // 00480ca8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00480ca9  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00480cab  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 00480cae  09c3                   -or ebx, eax
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.eax));
    // 00480cb0  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480cb1  a907000000             +test eax, 7
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 7 /*0x7*/));
    // 00480cb6  0f85a7000000           -jne 0x480d63
    if (!cpu.flags.zf)
    {
        goto L_0x00480d63;
    }
L_0x00480cbc:
    // 00480cbc  83fa00                 +cmp edx, 0
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480cbf  7c3f                   -jl 0x480d00
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00480d00;
    }
    // 00480cc1  80fbff                 +cmp bl, 0xff
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00480cc4  743b                   -je 0x480d01
    if (cpu.flags.zf)
    {
        goto L_0x00480d01;
    }
    // 00480cc6  38fb                   +cmp bl, bh
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
    // 00480cc8  7537                   -jne 0x480d01
    if (!cpu.flags.zf)
    {
        goto L_0x00480d01;
    }
    // 00480cca  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00480ccb  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00480ccc  dd0424                 -fld qword ptr [esp]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp)));
    // 00480ccf  83ea20                 +sub edx, 0x20
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00480cd2  7813                   -js 0x480ce7
    if (cpu.flags.sf)
    {
        goto L_0x00480ce7;
    }
L_0x00480cd4:
    // 00480cd4  dd10                   -fst qword ptr [eax]
    app->getMemory<double>(cpu.eax) = double(cpu.fpu.st(0));
    // 00480cd6  dd5008                 -fst qword ptr [eax + 8]
    app->getMemory<double>(cpu.eax + x86::reg32(8) /* 0x8 */) = double(cpu.fpu.st(0));
    // 00480cd9  dd5010                 -fst qword ptr [eax + 0x10]
    app->getMemory<double>(cpu.eax + x86::reg32(16) /* 0x10 */) = double(cpu.fpu.st(0));
    // 00480cdc  dd5018                 -fst qword ptr [eax + 0x18]
    app->getMemory<double>(cpu.eax + x86::reg32(24) /* 0x18 */) = double(cpu.fpu.st(0));
    // 00480cdf  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 00480ce2  83ea20                 +sub edx, 0x20
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00480ce5  79ed                   -jns 0x480cd4
    if (!cpu.flags.sf)
    {
        goto L_0x00480cd4;
    }
L_0x00480ce7:
    // 00480ce7  83c218                 +add edx, 0x18
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00480cea  780a                   -js 0x480cf6
    if (cpu.flags.sf)
    {
        goto L_0x00480cf6;
    }
L_0x00480cec:
    // 00480cec  dd10                   -fst qword ptr [eax]
    app->getMemory<double>(cpu.eax) = double(cpu.fpu.st(0));
    // 00480cee  8d4008                 -lea eax, [eax + 8]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00480cf1  83ea08                 +sub edx, 8
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00480cf4  79f6                   -jns 0x480cec
    if (!cpu.flags.sf)
    {
        goto L_0x00480cec;
    }
L_0x00480cf6:
    // 00480cf6  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 00480cf8  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00480cfb  83c208                 +add edx, 8
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00480cfe  753d                   -jne 0x480d3d
    if (!cpu.flags.zf)
    {
        goto L_0x00480d3d;
    }
L_0x00480d00:
    // 00480d00  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00480d01:
    // 00480d01  83ea20                 +sub edx, 0x20
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00480d04  781f                   -js 0x480d25
    if (cpu.flags.sf)
    {
        goto L_0x00480d25;
    }
L_0x00480d06:
    // 00480d06  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 00480d08  895804                 -mov dword ptr [eax + 4], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00480d0b  895808                 -mov dword ptr [eax + 8], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00480d0e  89580c                 -mov dword ptr [eax + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 00480d11  895810                 -mov dword ptr [eax + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 00480d14  895814                 -mov dword ptr [eax + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 00480d17  895818                 -mov dword ptr [eax + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 00480d1a  89581c                 -mov dword ptr [eax + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 00480d1d  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 00480d20  83ea20                 +sub edx, 0x20
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00480d23  79e1                   -jns 0x480d06
    if (!cpu.flags.sf)
    {
        goto L_0x00480d06;
    }
L_0x00480d25:
    // 00480d25  83c218                 +add edx, 0x18
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00480d28  780d                   -js 0x480d37
    if (cpu.flags.sf)
    {
        goto L_0x00480d37;
    }
L_0x00480d2a:
    // 00480d2a  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 00480d2c  895804                 -mov dword ptr [eax + 4], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00480d2f  8d4008                 -lea eax, [eax + 8]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00480d32  83ea08                 +sub edx, 8
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00480d35  79f3                   -jns 0x480d2a
    if (!cpu.flags.sf)
    {
        goto L_0x00480d2a;
    }
L_0x00480d37:
    // 00480d37  83c208                 +add edx, 8
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00480d3a  7501                   -jne 0x480d3d
    if (!cpu.flags.zf)
    {
        goto L_0x00480d3d;
    }
    // 00480d3c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00480d3d:
    // 00480d3d  f7c204000000           +test edx, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 4 /*0x4*/));
    // 00480d43  7405                   -je 0x480d4a
    if (cpu.flags.zf)
    {
        goto L_0x00480d4a;
    }
    // 00480d45  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 00480d47  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
L_0x00480d4a:
    // 00480d4a  f7c202000000           +test edx, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 2 /*0x2*/));
    // 00480d50  7406                   -je 0x480d58
    if (cpu.flags.zf)
    {
        goto L_0x00480d58;
    }
    // 00480d52  668918                 -mov word ptr [eax], bx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.bx;
    // 00480d55  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
L_0x00480d58:
    // 00480d58  f7c201000000           +test edx, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 1 /*0x1*/));
    // 00480d5e  7402                   -je 0x480d62
    if (cpu.flags.zf)
    {
        goto L_0x00480d62;
    }
    // 00480d60  8818                   -mov byte ptr [eax], bl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bl;
L_0x00480d62:
    // 00480d62  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00480d63:
    // 00480d63  a901000000             +test eax, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 1 /*0x1*/));
    // 00480d68  740d                   -je 0x480d77
    if (cpu.flags.zf)
    {
        goto L_0x00480d77;
    }
    // 00480d6a  83fa01                 +cmp edx, 1
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
    // 00480d6d  7c08                   -jl 0x480d77
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00480d77;
    }
    // 00480d6f  8818                   -mov byte ptr [eax], bl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bl;
    // 00480d71  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00480d74  83ea01                 -sub edx, 1
    (cpu.edx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x00480d77:
    // 00480d77  a902000000             +test eax, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2 /*0x2*/));
    // 00480d7c  740e                   -je 0x480d8c
    if (cpu.flags.zf)
    {
        goto L_0x00480d8c;
    }
    // 00480d7e  83fa02                 +cmp edx, 2
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
    // 00480d81  7c09                   -jl 0x480d8c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00480d8c;
    }
    // 00480d83  668918                 -mov word ptr [eax], bx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.bx;
    // 00480d86  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00480d89  83ea02                 -sub edx, 2
    (cpu.edx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x00480d8c:
    // 00480d8c  a904000000             +test eax, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 4 /*0x4*/));
    // 00480d91  740d                   -je 0x480da0
    if (cpu.flags.zf)
    {
        goto L_0x00480da0;
    }
    // 00480d93  83fa04                 +cmp edx, 4
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
    // 00480d96  7c08                   -jl 0x480da0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00480da0;
    }
    // 00480d98  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 00480d9a  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00480d9d  83ea04                 +sub edx, 4
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
L_0x00480da0:
    // 00480da0  e917ffffff             -jmp 0x480cbc
    goto L_0x00480cbc;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_480db0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480db0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00480db2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_480db4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480db4  833d54af4c0000         +cmp dword ptr [0x4caf54], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5025620) /* 0x4caf54 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480dbb  7501                   -jne 0x480dbe
    if (!cpu.flags.zf)
    {
        goto L_0x00480dbe;
    }
    // 00480dbd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00480dbe:
    // 00480dbe  e871010000             -call 0x480f34
    cpu.esp -= 4;
    sub_480f34(app, cpu);
    if (cpu.terminate) return;
    // 00480dc3  b8fcdc5100             -mov eax, 0x51dcfc
    cpu.eax = 5364988 /*0x51dcfc*/;
    // 00480dc8  e81f190000             -call 0x4826ec
    cpu.esp -= 4;
    sub_4826ec(app, cpu);
    if (cpu.terminate) return;
    // 00480dcd  b8e0dc5100             -mov eax, 0x51dce0
    cpu.eax = 5364960 /*0x51dce0*/;
    // 00480dd2  e915190000             -jmp 0x4826ec
    return sub_4826ec(app, cpu);
}

/* align: skip 0x90 */
void Application::sub_480dd8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480dd8  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00480ddb  837a0c00               +cmp dword ptr [edx + 0xc], 0
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
    // 00480ddf  7506                   -jne 0x480de7
    if (!cpu.flags.zf)
    {
        goto L_0x00480de7;
    }
    // 00480de1  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00480de6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00480de7:
    // 00480de7  ff520c                 -call dword ptr [edx + 0xc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00480dea  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00480def  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_480df0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480df0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00480df1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00480df2  bad80d4800             -mov edx, 0x480dd8
    cpu.edx = 4722136 /*0x480dd8*/;
    // 00480df7  b8fcdc5100             -mov eax, 0x51dcfc
    cpu.eax = 5364988 /*0x51dcfc*/;
    // 00480dfc  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00480dfe  e8f11d0000             -call 0x482bf4
    cpu.esp -= 4;
    sub_482bf4(app, cpu);
    if (cpu.terminate) return;
    // 00480e03  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480e04  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480e05  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_480e08(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480e08  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00480e09  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00480e0a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00480e0c  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00480e0e  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00480e10  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00480e12  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00480e16  833d54af4c0000         +cmp dword ptr [0x4caf54], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5025620) /* 0x4caf54 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480e1d  0f84b0000000           -je 0x480ed3
    if (cpu.flags.zf)
    {
        goto L_0x00480ed3;
    }
L_0x00480e23:
    // 00480e23  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00480e25  745e                   -je 0x480e85
    if (cpu.flags.zf)
    {
        goto L_0x00480e85;
    }
    // 00480e27  837e2400               +cmp dword ptr [esi + 0x24], 0
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
    // 00480e2b  7507                   -jne 0x480e34
    if (!cpu.flags.zf)
    {
        goto L_0x00480e34;
    }
    // 00480e2d  c7462402000000         -mov dword ptr [esi + 0x24], 2
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = 2 /*0x2*/;
L_0x00480e34:
    // 00480e34  837e2800               +cmp dword ptr [esi + 0x28], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480e38  7507                   -jne 0x480e41
    if (!cpu.flags.zf)
    {
        goto L_0x00480e41;
    }
    // 00480e3a  c7462804000000         -mov dword ptr [esi + 0x28], 4
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = 4 /*0x4*/;
L_0x00480e41:
    // 00480e41  837e2c00               +cmp dword ptr [esi + 0x2c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480e45  7507                   -jne 0x480e4e
    if (!cpu.flags.zf)
    {
        goto L_0x00480e4e;
    }
    // 00480e47  c7462c06000000         -mov dword ptr [esi + 0x2c], 6
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */) = 6 /*0x6*/;
L_0x00480e4e:
    // 00480e4e  837e1400               +cmp dword ptr [esi + 0x14], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480e52  7507                   -jne 0x480e5b
    if (!cpu.flags.zf)
    {
        goto L_0x00480e5b;
    }
    // 00480e54  c74614b00d4800         -mov dword ptr [esi + 0x14], 0x480db0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = 4722096 /*0x480db0*/;
L_0x00480e5b:
    // 00480e5b  837e1c00               +cmp dword ptr [esi + 0x1c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480e5f  7507                   -jne 0x480e68
    if (!cpu.flags.zf)
    {
        goto L_0x00480e68;
    }
    // 00480e61  c7461cb00d4800         -mov dword ptr [esi + 0x1c], 0x480db0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = 4722096 /*0x480db0*/;
L_0x00480e68:
    // 00480e68  837e1800               +cmp dword ptr [esi + 0x18], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480e6c  7507                   -jne 0x480e75
    if (!cpu.flags.zf)
    {
        goto L_0x00480e75;
    }
    // 00480e6e  c74618b00d4800         -mov dword ptr [esi + 0x18], 0x480db0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = 4722096 /*0x480db0*/;
L_0x00480e75:
    // 00480e75  837e2000               +cmp dword ptr [esi + 0x20], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480e79  7507                   -jne 0x480e82
    if (!cpu.flags.zf)
    {
        goto L_0x00480e82;
    }
    // 00480e7b  c74620b00d4800         -mov dword ptr [esi + 0x20], 0x480db0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = 4722096 /*0x480db0*/;
L_0x00480e82:
    // 00480e82  897e0c                 -mov dword ptr [esi + 0xc], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edi;
L_0x00480e85:
    // 00480e85  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00480e87  741f                   -je 0x480ea8
    if (cpu.flags.zf)
    {
        goto L_0x00480ea8;
    }
    // 00480e89  837f0c00               +cmp dword ptr [edi + 0xc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480e8d  7419                   -je 0x480ea8
    if (cpu.flags.zf)
    {
        goto L_0x00480ea8;
    }
    // 00480e8f  833d58af4c0000         +cmp dword ptr [0x4caf58], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5025624) /* 0x4caf58 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480e96  750a                   -jne 0x480ea2
    if (!cpu.flags.zf)
    {
        goto L_0x00480ea2;
    }
    // 00480e98  b8f00d4800             -mov eax, 0x480df0
    cpu.eax = 4722160 /*0x480df0*/;
    // 00480e9d  e8926a0100             -call 0x497934
    cpu.esp -= 4;
    sub_497934(app, cpu);
    if (cpu.terminate) return;
L_0x00480ea2:
    // 00480ea2  ff0558af4c00           -inc dword ptr [0x4caf58]
    (app->getMemory<x86::reg32>(x86::reg32(5025624) /* 0x4caf58 */))++;
L_0x00480ea8:
    // 00480ea8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00480eaa  ff5704                 -call dword ptr [edi + 4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00480ead  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00480eaf  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00480eb1  7419                   -je 0x480ecc
    if (cpu.flags.zf)
    {
        goto L_0x00480ecc;
    }
    // 00480eb3  837f0c00               +cmp dword ptr [edi + 0xc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480eb7  7413                   -je 0x480ecc
    if (cpu.flags.zf)
    {
        goto L_0x00480ecc;
    }
    // 00480eb9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00480ebb  750f                   -jne 0x480ecc
    if (!cpu.flags.zf)
    {
        goto L_0x00480ecc;
    }
    // 00480ebd  8b1d58af4c00           -mov ebx, dword ptr [0x4caf58]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5025624) /* 0x4caf58 */);
    // 00480ec3  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00480ec4  891d58af4c00           -mov dword ptr [0x4caf58], ebx
    app->getMemory<x86::reg32>(x86::reg32(5025624) /* 0x4caf58 */) = cpu.ebx;
    // 00480eca  7411                   -je 0x480edd
    if (cpu.flags.zf)
    {
        goto L_0x00480edd;
    }
L_0x00480ecc:
    // 00480ecc  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00480ece  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480ecf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480ed0  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00480ed3:
    // 00480ed3  e818000000             -call 0x480ef0
    cpu.esp -= 4;
    sub_480ef0(app, cpu);
    if (cpu.terminate) return;
    // 00480ed8  e946ffffff             -jmp 0x480e23
    goto L_0x00480e23;
L_0x00480edd:
    // 00480edd  b8f00d4800             -mov eax, 0x480df0
    cpu.eax = 4722160 /*0x480df0*/;
    // 00480ee2  e8b56a0100             -call 0x49799c
    cpu.esp -= 4;
    sub_49799c(app, cpu);
    if (cpu.terminate) return;
    // 00480ee7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00480ee9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480eea  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480eeb  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_480ef0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480ef0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00480ef1  8b1554af4c00           -mov edx, dword ptr [0x4caf54]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5025620) /* 0x4caf54 */);
    // 00480ef7  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00480ef9  7402                   -je 0x480efd
    if (cpu.flags.zf)
    {
        goto L_0x00480efd;
    }
    // 00480efb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480efc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00480efd:
    // 00480efd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00480efe  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00480eff  b8fcdc5100             -mov eax, 0x51dcfc
    cpu.eax = 5364988 /*0x51dcfc*/;
    // 00480f04  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00480f06  e8a1170000             -call 0x4826ac
    cpu.esp -= 4;
    sub_4826ac(app, cpu);
    if (cpu.terminate) return;
    // 00480f0b  b8e0dc5100             -mov eax, 0x51dce0
    cpu.eax = 5364960 /*0x51dce0*/;
    // 00480f10  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00480f12  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00480f14  e893170000             -call 0x4826ac
    cpu.esp -= 4;
    sub_4826ac(app, cpu);
    if (cpu.terminate) return;
    // 00480f19  b8b40d4800             -mov eax, 0x480db4
    cpu.eax = 4722100 /*0x480db4*/;
    // 00480f1e  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00480f23  e8b4f70000             -call 0x4906dc
    cpu.esp -= 4;
    sub_4906dc(app, cpu);
    if (cpu.terminate) return;
    // 00480f28  890d54af4c00           -mov dword ptr [0x4caf54], ecx
    app->getMemory<x86::reg32>(x86::reg32(5025620) /* 0x4caf54 */) = cpu.ecx;
    // 00480f2e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480f2f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480f30  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480f31  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_480f34(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480f34  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00480f35  833d54af4c0000         +cmp dword ptr [0x4caf54], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5025620) /* 0x4caf54 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480f3c  7420                   -je 0x480f5e
    if (cpu.flags.zf)
    {
        goto L_0x00480f5e;
    }
L_0x00480f3e:
    // 00480f3e  b8fcdc5100             -mov eax, 0x51dcfc
    cpu.eax = 5364988 /*0x51dcfc*/;
    // 00480f43  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00480f45  e8aa1a0000             -call 0x4829f4
    cpu.esp -= 4;
    sub_4829f4(app, cpu);
    if (cpu.terminate) return;
    // 00480f4a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00480f4c  7512                   -jne 0x480f60
    if (!cpu.flags.zf)
    {
        goto L_0x00480f60;
    }
L_0x00480f4e:
    // 00480f4e  b8e0dc5100             -mov eax, 0x51dce0
    cpu.eax = 5364960 /*0x51dce0*/;
    // 00480f53  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00480f55  e89a1a0000             -call 0x4829f4
    cpu.esp -= 4;
    sub_4829f4(app, cpu);
    if (cpu.terminate) return;
    // 00480f5a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00480f5c  7509                   -jne 0x480f67
    if (!cpu.flags.zf)
    {
        goto L_0x00480f67;
    }
L_0x00480f5e:
    // 00480f5e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480f5f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00480f60:
    // 00480f60  e823000000             -call 0x480f88
    cpu.esp -= 4;
    sub_480f88(app, cpu);
    if (cpu.terminate) return;
    // 00480f65  ebd7                   -jmp 0x480f3e
    goto L_0x00480f3e;
L_0x00480f67:
    // 00480f67  e81c000000             -call 0x480f88
    cpu.esp -= 4;
    sub_480f88(app, cpu);
    if (cpu.terminate) return;
    // 00480f6c  ebe0                   -jmp 0x480f4e
    goto L_0x00480f4e;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_480f70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480f70  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00480f72  7406                   -je 0x480f7a
    if (cpu.flags.zf)
    {
        goto L_0x00480f7a;
    }
    // 00480f74  83780400               +cmp dword ptr [eax + 4], 0
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
    // 00480f78  7503                   -jne 0x480f7d
    if (!cpu.flags.zf)
    {
        goto L_0x00480f7d;
    }
L_0x00480f7a:
    // 00480f7a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00480f7c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00480f7d:
    // 00480f7d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00480f7e  8b480c                 -mov ecx, dword ptr [eax + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00480f81  ff5108                 -call dword ptr [ecx + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00480f84  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480f85  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_480f88(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480f88  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00480f89  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00480f8b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00480f8d  7406                   -je 0x480f95
    if (cpu.flags.zf)
    {
        goto L_0x00480f95;
    }
    // 00480f8f  83781000               +cmp dword ptr [eax + 0x10], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480f93  7504                   -jne 0x480f99
    if (!cpu.flags.zf)
    {
        goto L_0x00480f99;
    }
L_0x00480f95:
    // 00480f95  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00480f97  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480f98  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00480f99:
    // 00480f99  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00480f9a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00480f9b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00480f9c  8b480c                 -mov ecx, dword ptr [eax + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00480f9f  ff5110                 -call dword ptr [ecx + 0x10]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00480fa2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00480fa4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00480fa6  742a                   -je 0x480fd2
    if (cpu.flags.zf)
    {
        goto L_0x00480fd2;
    }
    // 00480fa8  8b420c                 -mov eax, dword ptr [edx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00480fab  83780c00               +cmp dword ptr [eax + 0xc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480faf  7421                   -je 0x480fd2
    if (cpu.flags.zf)
    {
        goto L_0x00480fd2;
    }
    // 00480fb1  8b3558af4c00           -mov esi, dword ptr [0x4caf58]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5025624) /* 0x4caf58 */);
    // 00480fb7  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00480fb9  7417                   -je 0x480fd2
    if (cpu.flags.zf)
    {
        goto L_0x00480fd2;
    }
    // 00480fbb  8d7eff                 -lea edi, [esi - 1]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(-1) /* -0x1 */);
    // 00480fbe  893d58af4c00           -mov dword ptr [0x4caf58], edi
    app->getMemory<x86::reg32>(x86::reg32(5025624) /* 0x4caf58 */) = cpu.edi;
    // 00480fc4  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00480fc6  750a                   -jne 0x480fd2
    if (!cpu.flags.zf)
    {
        goto L_0x00480fd2;
    }
    // 00480fc8  b8f00d4800             -mov eax, 0x480df0
    cpu.eax = 4722160 /*0x480df0*/;
    // 00480fcd  e8ca690100             -call 0x49799c
    cpu.esp -= 4;
    sub_49799c(app, cpu);
    if (cpu.terminate) return;
L_0x00480fd2:
    // 00480fd2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00480fd4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480fd5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480fd6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480fd7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00480fd8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_480fd9(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00480fd9  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00480fda  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00480fdb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00480fdc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00480fdd  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00480fde  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00480fe1  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00480fe3  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00480fe8  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00480fea  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00480fec  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00480fee  892c24                 -mov dword ptr [esp], ebp
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 00480ff1  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00480ff3  740e                   -je 0x481003
    if (cpu.flags.zf)
    {
        goto L_0x00481003;
    }
    // 00480ff5  3b0d70e14c00           +cmp ecx, dword ptr [0x4ce170]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5038448) /* 0x4ce170 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00480ffb  7504                   -jne 0x481001
    if (!cpu.flags.zf)
    {
        goto L_0x00481001;
    }
    // 00480ffd  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 00480fff  eb02                   -jmp 0x481003
    goto L_0x00481003;
L_0x00481001:
    // 00481001  892a                   -mov dword ptr [edx], ebp
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ebp;
L_0x00481003:
    // 00481003  8a03                   -mov al, byte ptr [ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx);
    // 00481005  3c72                   +cmp al, 0x72
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
    // 00481007  7208                   -jb 0x481011
    if (cpu.flags.cf)
    {
        goto L_0x00481011;
    }
    // 00481009  760c                   -jbe 0x481017
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00481017;
    }
    // 0048100b  3c77                   +cmp al, 0x77
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(119 /*0x77*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048100d  740e                   -je 0x48101d
    if (cpu.flags.zf)
    {
        goto L_0x0048101d;
    }
    // 0048100f  eb18                   -jmp 0x481029
    goto L_0x00481029;
L_0x00481011:
    // 00481011  3c61                   +cmp al, 0x61
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
    // 00481013  740e                   -je 0x481023
    if (cpu.flags.zf)
    {
        goto L_0x00481023;
    }
    // 00481015  eb12                   -jmp 0x481029
    goto L_0x00481029;
L_0x00481017:
    // 00481017  800c2401               +or byte ptr [esp], 1
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.esp) |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 0048101b  eb1d                   -jmp 0x48103a
    goto L_0x0048103a;
L_0x0048101d:
    // 0048101d  800c2402               +or byte ptr [esp], 2
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.esp) |= x86::reg8(x86::sreg8(2 /*0x2*/))));
    // 00481021  eb17                   -jmp 0x48103a
    goto L_0x0048103a;
L_0x00481023:
    // 00481023  800c2482               +or byte ptr [esp], 0x82
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.esp) |= x86::reg8(x86::sreg8(130 /*0x82*/))));
    // 00481027  eb11                   -jmp 0x48103a
    goto L_0x0048103a;
L_0x00481029:
    // 00481029  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 0048102e  e8cd900100             -call 0x49a100
    cpu.esp -= 4;
    sub_49a100(app, cpu);
    if (cpu.terminate) return;
    // 00481033  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00481035  e9af000000             -jmp 0x4810e9
    goto L_0x004810e9;
L_0x0048103a:
    // 0048103a  43                     -inc ebx
    (cpu.ebx)++;
    // 0048103b  8a03                   -mov al, byte ptr [ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx);
    // 0048103d  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 0048103f  0f848d000000           -je 0x4810d2
    if (cpu.flags.zf)
    {
        goto L_0x004810d2;
    }
    // 00481045  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00481047  0f8485000000           -je 0x4810d2
    if (cpu.flags.zf)
    {
        goto L_0x004810d2;
    }
    // 0048104d  3c63                   +cmp al, 0x63
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(99 /*0x63*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048104f  7216                   -jb 0x481067
    if (cpu.flags.cf)
    {
        goto L_0x00481067;
    }
    // 00481051  0f8652000000           -jbe 0x4810a9
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004810a9;
    }
    // 00481057  3c6e                   +cmp al, 0x6e
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(110 /*0x6e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00481059  72df                   -jb 0x48103a
    if (cpu.flags.cf)
    {
        goto L_0x0048103a;
    }
    // 0048105b  0f865d000000           -jbe 0x4810be
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004810be;
    }
    // 00481061  3c74                   +cmp al, 0x74
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(116 /*0x74*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00481063  7426                   -je 0x48108b
    if (cpu.flags.zf)
    {
        goto L_0x0048108b;
    }
    // 00481065  ebd3                   -jmp 0x48103a
    goto L_0x0048103a;
L_0x00481067:
    // 00481067  3c2b                   +cmp al, 0x2b
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
    // 00481069  72cf                   -jb 0x48103a
    if (cpu.flags.cf)
    {
        goto L_0x0048103a;
    }
    // 0048106b  7606                   -jbe 0x481073
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00481073;
    }
    // 0048106d  3c62                   +cmp al, 0x62
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(98 /*0x62*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048106f  7425                   -je 0x481096
    if (cpu.flags.zf)
    {
        goto L_0x00481096;
    }
    // 00481071  ebc7                   -jmp 0x48103a
    goto L_0x0048103a;
L_0x00481073:
    // 00481073  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00481075  7404                   -je 0x48107b
    if (cpu.flags.zf)
    {
        goto L_0x0048107b;
    }
L_0x00481077:
    // 00481077  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 00481079  ebbf                   -jmp 0x48103a
    goto L_0x0048103a;
L_0x0048107b:
    // 0048107b  8a2424                 -mov ah, byte ptr [esp]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esp);
    // 0048107e  80cc03                 +or ah, 3
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00481081  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 00481086  882424                 -mov byte ptr [esp], ah
    app->getMemory<x86::reg8>(cpu.esp) = cpu.ah;
    // 00481089  ebaf                   -jmp 0x48103a
    goto L_0x0048103a;
L_0x0048108b:
    // 0048108b  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048108d  75e8                   -jne 0x481077
    if (!cpu.flags.zf)
    {
        goto L_0x00481077;
    }
    // 0048108f  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 00481094  eba4                   -jmp 0x48103a
    goto L_0x0048103a;
L_0x00481096:
    // 00481096  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00481098  75dd                   -jne 0x481077
    if (!cpu.flags.zf)
    {
        goto L_0x00481077;
    }
    // 0048109a  8a0424                 -mov al, byte ptr [esp]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp);
    // 0048109d  0c40                   +or al, 0x40
    cpu.clear_co();
    cpu.set_szp((cpu.al |= x86::reg8(x86::sreg8(64 /*0x40*/))));
    // 0048109f  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 004810a4  880424                 -mov byte ptr [esp], al
    app->getMemory<x86::reg8>(cpu.esp) = cpu.al;
    // 004810a7  eb91                   -jmp 0x48103a
    goto L_0x0048103a;
L_0x004810a9:
    // 004810a9  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004810ab  75ca                   -jne 0x481077
    if (!cpu.flags.zf)
    {
        goto L_0x00481077;
    }
    // 004810ad  8a22                   -mov ah, byte ptr [edx]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edx);
    // 004810af  80cc01                 +or ah, 1
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 004810b2  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 004810b7  8822                   -mov byte ptr [edx], ah
    app->getMemory<x86::reg8>(cpu.edx) = cpu.ah;
    // 004810b9  e97cffffff             -jmp 0x48103a
    goto L_0x0048103a;
L_0x004810be:
    // 004810be  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004810c0  75b5                   -jne 0x481077
    if (!cpu.flags.zf)
    {
        goto L_0x00481077;
    }
    // 004810c2  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 004810c4  24fe                   +and al, 0xfe
    cpu.clear_co();
    cpu.set_szp((cpu.al &= x86::reg8(x86::sreg8(254 /*0xfe*/))));
    // 004810c6  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 004810cb  8802                   -mov byte ptr [edx], al
    app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
    // 004810cd  e968ffffff             -jmp 0x48103a
    goto L_0x0048103a;
L_0x004810d2:
    // 004810d2  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004810d4  7510                   -jne 0x4810e6
    if (!cpu.flags.zf)
    {
        goto L_0x004810e6;
    }
    // 004810d6  813d7de34c0000020000   +cmp dword ptr [0x4ce37d], 0x200
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5038973) /* 0x4ce37d */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(512 /*0x200*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004810e0  7504                   -jne 0x4810e6
    if (!cpu.flags.zf)
    {
        goto L_0x004810e6;
    }
    // 004810e2  800c2440               -or byte ptr [esp], 0x40
    app->getMemory<x86::reg8>(cpu.esp) |= x86::reg8(x86::sreg8(64 /*0x40*/));
L_0x004810e6:
    // 004810e6  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
L_0x004810e9:
    // 004810e9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004810eb  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004810ee  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004810ef  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004810f0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004810f1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004810f2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004810f3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4810f4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004810f4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004810f5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004810f6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004810f7  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004810f9  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 004810fb  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004810fd  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00481101  80610cfc               -and byte ptr [ecx + 0xc], 0xfc
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) &= x86::reg8(x86::sreg8(252 /*0xfc*/));
    // 00481105  09590c                 -or dword ptr [ecx + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) |= x86::reg32(x86::sreg32(cpu.ebx));
    // 00481108  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0048110d  e879c20100             -call 0x49d38b
    cpu.esp -= 4;
    sub_49d38b(app, cpu);
    if (cpu.terminate) return;
    // 00481112  3c72                   +cmp al, 0x72
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
    // 00481114  7522                   -jne 0x481138
    if (!cpu.flags.zf)
    {
        goto L_0x00481138;
    }
    // 00481116  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00481118  f6c302                 +test bl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 2 /*0x2*/));
    // 0048111b  7405                   -je 0x481122
    if (cpu.flags.zf)
    {
        goto L_0x00481122;
    }
    // 0048111d  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
L_0x00481122:
    // 00481122  f6c340                 +test bl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 64 /*0x40*/));
    // 00481125  7405                   -je 0x48112c
    if (cpu.flags.zf)
    {
        goto L_0x0048112c;
    }
    // 00481127  80cc02                 +or ah, 2
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(2 /*0x2*/))));
    // 0048112a  eb03                   -jmp 0x48112f
    goto L_0x0048112f;
L_0x0048112c:
    // 0048112c  80cc01                 +or ah, 1
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(1 /*0x1*/))));
L_0x0048112f:
    // 0048112f  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00481131  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00481135  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00481136  eb30                   -jmp 0x481168
    goto L_0x00481168;
L_0x00481138:
    // 00481138  f6c301                 +test bl, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 1 /*0x1*/));
    // 0048113b  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 0048113e  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00481143  83c021                 -add eax, 0x21
    (cpu.eax) += x86::reg32(x86::sreg32(33 /*0x21*/));
    // 00481146  f6c380                 +test bl, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 128 /*0x80*/));
    // 00481149  7404                   -je 0x48114f
    if (cpu.flags.zf)
    {
        goto L_0x0048114f;
    }
    // 0048114b  0c10                   +or al, 0x10
    cpu.clear_co();
    cpu.set_szp((cpu.al |= x86::reg8(x86::sreg8(16 /*0x10*/))));
    // 0048114d  eb02                   -jmp 0x481151
    goto L_0x00481151;
L_0x0048114f:
    // 0048114f  0c40                   -or al, 0x40
    cpu.al |= x86::reg8(x86::sreg8(64 /*0x40*/));
L_0x00481151:
    // 00481151  f6c340                 +test bl, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 64 /*0x40*/));
    // 00481154  7405                   -je 0x48115b
    if (cpu.flags.zf)
    {
        goto L_0x0048115b;
    }
    // 00481156  80cc02                 +or ah, 2
    cpu.clear_co();
    cpu.set_szp((cpu.ah |= x86::reg8(x86::sreg8(2 /*0x2*/))));
    // 00481159  eb03                   -jmp 0x48115e
    goto L_0x0048115e;
L_0x0048115b:
    // 0048115b  80cc01                 -or ah, 1
    cpu.ah |= x86::reg8(x86::sreg8(1 /*0x1*/));
L_0x0048115e:
    // 0048115e  6880010000             -push 0x180
    app->getMemory<x86::reg32>(cpu.esp-4) = 384 /*0x180*/;
    cpu.esp -= 4;
    // 00481163  8b6c2414               -mov ebp, dword ptr [esp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00481167  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
L_0x00481168:
    // 00481168  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00481169  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048116a  e84ec20100             -call 0x49d3bd
    cpu.esp -= 4;
    sub_49d3bd(app, cpu);
    if (cpu.terminate) return;
    // 0048116f  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00481172  894110                 -mov dword ptr [ecx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00481175  837910ff               +cmp dword ptr [ecx + 0x10], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481179  750b                   -jne 0x481186
    if (!cpu.flags.zf)
    {
        goto L_0x00481186;
    }
    // 0048117b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048117d  e826c50100             -call 0x49d6a8
    cpu.esp -= 4;
    sub_49d6a8(app, cpu);
    if (cpu.terminate) return;
    // 00481182  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00481184  eb4e                   -jmp 0x4811d4
    goto L_0x004811d4;
L_0x00481186:
    // 00481186  c7410400000000         -mov dword ptr [ecx + 4], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 0048118d  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00481190  c7411400000000         -mov dword ptr [ecx + 0x14], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 00481197  c7400c00000000         -mov dword ptr [eax + 0xc], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 0048119e  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004811a1  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004811a4  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004811a7  c7401500000000         -mov dword ptr [eax + 0x15], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(21) /* 0x15 */) = 0 /*0x0*/;
    // 004811ae  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004811b1  c7400800000000         -mov dword ptr [eax + 8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004811b8  f6c380                 +test bl, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 128 /*0x80*/));
    // 004811bb  740e                   -je 0x4811cb
    if (cpu.flags.zf)
    {
        goto L_0x004811cb;
    }
    // 004811bd  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 004811c2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004811c4  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004811c6  e889c50100             -call 0x49d754
    cpu.esp -= 4;
    sub_49d754(app, cpu);
    if (cpu.terminate) return;
L_0x004811cb:
    // 004811cb  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004811cd  e892c60100             -call 0x49d864
    cpu.esp -= 4;
    sub_49d864(app, cpu);
    if (cpu.terminate) return;
    // 004811d2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x004811d4:
    // 004811d4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004811d5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004811d6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004811d7  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_4811da(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004811da  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004811db  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004811dc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004811dd  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004811e0  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004811e2  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004811e4  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004811e6  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004811e8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004811ea  e8eafdffff             -call 0x480fd9
    cpu.esp -= 4;
    sub_480fd9(app, cpu);
    if (cpu.terminate) return;
    // 004811ef  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004811f1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004811f3  7422                   -je 0x481217
    if (cpu.flags.zf)
    {
        goto L_0x00481217;
    }
    // 004811f5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004811f7  e8f1c30100             -call 0x49d5ed
    cpu.esp -= 4;
    sub_49d5ed(app, cpu);
    if (cpu.terminate) return;
    // 004811fc  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004811fe  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00481200  7413                   -je 0x481215
    if (cpu.flags.zf)
    {
        goto L_0x00481215;
    }
    // 00481202  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00481203  31c2                   -xor edx, eax
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00481205  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00481206  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00481208  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 0048120a  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0048120e  e8e1feffff             -call 0x4810f4
    cpu.esp -= 4;
    sub_4810f4(app, cpu);
    if (cpu.terminate) return;
    // 00481213  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x00481215:
    // 00481215  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x00481217:
    // 00481217  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048121a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048121b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048121c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048121d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48121e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048121e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048121f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00481221  e8b4ffffff             -call 0x4811da
    cpu.esp -= 4;
    sub_4811da(app, cpu);
    if (cpu.terminate) return;
    // 00481226  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481227  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_481228(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481228  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00481229  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048122a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048122b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048122d  ff159ce34c00           -call dword ptr [0x4ce39c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5039004) /* 0x4ce39c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00481233  a1c44f5400             -mov eax, dword ptr [0x544fc4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5525444) /* 0x544fc4 */);
L_0x00481238:
    // 00481238  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048123a  7429                   -je 0x481265
    if (cpu.flags.zf)
    {
        goto L_0x00481265;
    }
    // 0048123c  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048123f  39d3                   +cmp ebx, edx
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
    // 00481241  751e                   -jne 0x481261
    if (!cpu.flags.zf)
    {
        goto L_0x00481261;
    }
    // 00481243  f6420c03               +test byte ptr [edx + 0xc], 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) & 3 /*0x3*/));
    // 00481247  740c                   -je 0x481255
    if (cpu.flags.zf)
    {
        goto L_0x00481255;
    }
    // 00481249  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0048124e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00481250  e8ec020000             -call 0x481541
    cpu.esp -= 4;
    sub_481541(app, cpu);
    if (cpu.terminate) return;
L_0x00481255:
    // 00481255  ff15a0e34c00           -call dword ptr [0x4ce3a0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5039008) /* 0x4ce3a0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048125b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048125d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048125e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048125f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481260  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00481261:
    // 00481261  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00481263  ebd3                   -jmp 0x481238
    goto L_0x00481238;
L_0x00481265:
    // 00481265  bac84f5400             -mov edx, 0x544fc8
    cpu.edx = 5525448 /*0x544fc8*/;
L_0x0048126a:
    // 0048126a  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0048126c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048126e  741c                   -je 0x48128c
    if (cpu.flags.zf)
    {
        goto L_0x0048128c;
    }
    // 00481270  3b5804                 +cmp ebx, dword ptr [eax + 4]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481273  7513                   -jne 0x481288
    if (!cpu.flags.zf)
    {
        goto L_0x00481288;
    }
    // 00481275  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00481277  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 00481279  8b15c44f5400           -mov edx, dword ptr [0x544fc4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5525444) /* 0x544fc4 */);
    // 0048127f  a3c44f5400             -mov dword ptr [0x544fc4], eax
    app->getMemory<x86::reg32>(x86::reg32(5525444) /* 0x544fc4 */) = cpu.eax;
    // 00481284  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00481286  ebcd                   -jmp 0x481255
    goto L_0x00481255;
L_0x00481288:
    // 00481288  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048128a  ebde                   -jmp 0x48126a
    goto L_0x0048126a;
L_0x0048128c:
    // 0048128c  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00481291  e86a8e0100             -call 0x49a100
    cpu.esp -= 4;
    sub_49a100(app, cpu);
    if (cpu.terminate) return;
    // 00481296  ff15a0e34c00           -call dword ptr [0x4ce3a0]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5039008) /* 0x4ce3a0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048129c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048129e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048129f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004812a0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004812a1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4812a2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004812a2  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004812a3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004812a4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004812a5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004812a6  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004812a9  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004812ab  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004812ad  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004812af  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004812b1  e823fdffff             -call 0x480fd9
    cpu.esp -= 4;
    sub_480fd9(app, cpu);
    if (cpu.terminate) return;
    // 004812b6  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004812b8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004812ba  7455                   -je 0x481311
    if (cpu.flags.zf)
    {
        goto L_0x00481311;
    }
    // 004812bc  8b7310                 -mov esi, dword ptr [ebx + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004812bf  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004812c1  ff158ce34c00           -call dword ptr [0x4ce38c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5038988) /* 0x4ce38c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004812c7  833dd8e34c0000         +cmp dword ptr [0x4ce3d8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5039064) /* 0x4ce3d8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004812ce  7408                   -je 0x4812d8
    if (cpu.flags.zf)
    {
        goto L_0x004812d8;
    }
    // 004812d0  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004812d2  ff15d8e34c00           -call dword ptr [0x4ce3d8]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5039064) /* 0x4ce3d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004812d8:
    // 004812d8  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004812da  e849ffffff             -call 0x481228
    cpu.esp -= 4;
    sub_481228(app, cpu);
    if (cpu.terminate) return;
    // 004812df  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004812e1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004812e3  7422                   -je 0x481307
    if (cpu.flags.zf)
    {
        goto L_0x00481307;
    }
    // 004812e5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004812e6  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004812e9  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004812eb  81e300400000           -and ebx, 0x4000
    cpu.ebx &= x86::reg32(x86::sreg32(16384 /*0x4000*/));
    // 004812f1  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004812f3  89580c                 -mov dword ptr [eax + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 004812f6  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 004812f8  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004812fa  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 004812fc  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00481300  e8effdffff             -call 0x4810f4
    cpu.esp -= 4;
    sub_4810f4(app, cpu);
    if (cpu.terminate) return;
    // 00481305  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x00481307:
    // 00481307  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00481309  ff1590e34c00           -call dword ptr [0x4ce390]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5038992) /* 0x4ce390 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048130f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x00481311:
    // 00481311  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00481314  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481315  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481316  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481317  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00481318  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_481319(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00481319  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048131a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048131b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048131c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048131d  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00481320  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00481322  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00481324  8b4310                 -mov eax, dword ptr [ebx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 00481327  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00481329  ff158ce34c00           -call dword ptr [0x4ce38c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5038988) /* 0x4ce38c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048132f  8a630c                 -mov ah, byte ptr [ebx + 0xc]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 00481332  8b7b0c                 -mov edi, dword ptr [ebx + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 00481335  80e4cf                 -and ah, 0xcf
    cpu.ah &= x86::reg8(x86::sreg8(207 /*0xcf*/));
    // 00481338  83e730                 -and edi, 0x30
    cpu.edi &= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 0048133b  88630c                 -mov byte ptr [ebx + 0xc], ah
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.ah;
L_0x0048133e:
    // 0048133e  49                     -dec ecx
    (cpu.ecx)--;
    // 0048133f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00481341  7e19                   -jle 0x48135c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048135c;
    }
    // 00481343  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00481345  e826c80100             -call 0x49db70
    cpu.esp -= 4;
    sub_49db70(app, cpu);
    if (cpu.terminate) return;
    // 0048134a  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0048134d  83f8ff                 +cmp eax, -1
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
    // 00481350  740a                   -je 0x48135c
    if (cpu.flags.zf)
    {
        goto L_0x0048135c;
    }
    // 00481352  8a0424                 -mov al, byte ptr [esp]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp);
    // 00481355  8802                   -mov byte ptr [edx], al
    app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
    // 00481357  42                     -inc edx
    (cpu.edx)++;
    // 00481358  3c0a                   +cmp al, 0xa
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(10 /*0xa*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048135a  75e2                   -jne 0x48133e
    if (!cpu.flags.zf)
    {
        goto L_0x0048133e;
    }
L_0x0048135c:
    // 0048135c  833c24ff               +cmp dword ptr [esp], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00481360  750e                   -jne 0x481370
    if (!cpu.flags.zf)
    {
        goto L_0x00481370;
    }
    // 00481362  39f2                   +cmp edx, esi
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
    // 00481364  7406                   -je 0x48136c
    if (cpu.flags.zf)
    {
        goto L_0x0048136c;
    }
    // 00481366  f6430c20               +test byte ptr [ebx + 0xc], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(12) /* 0xc */) & 32 /*0x20*/));
    // 0048136a  7404                   -je 0x481370
    if (cpu.flags.zf)
    {
        goto L_0x00481370;
    }
L_0x0048136c:
    // 0048136c  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 0048136e  eb03                   -jmp 0x481373
    goto L_0x00481373;
L_0x00481370:
    // 00481370  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
L_0x00481373:
    // 00481373  8b6b0c                 -mov ebp, dword ptr [ebx + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 00481376  09fd                   -or ebp, edi
    cpu.ebp |= x86::reg32(x86::sreg32(cpu.edi));
    // 00481378  8b4310                 -mov eax, dword ptr [ebx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 0048137b  896b0c                 -mov dword ptr [ebx + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 0048137e  ff1590e34c00           -call dword ptr [0x4ce390]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5038992) /* 0x4ce390 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00481384  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00481386  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00481389  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048138a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048138b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048138c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048138d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48138e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048138e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048138f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00481390  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00481392  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00481395  e8d6c70100             -call 0x49db70
    cpu.esp -= 4;
    sub_49db70(app, cpu);
    if (cpu.terminate) return;
    // 0048139a  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048139c  83f8ff                 +cmp eax, -1
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
    // 0048139f  7504                   -jne 0x4813a5
    if (!cpu.flags.zf)
    {
        goto L_0x004813a5;
    }
    // 004813a1  804a1002               -or byte ptr [edx + 0x10], 2
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(16) /* 0x10 */) |= x86::reg8(x86::sreg8(2 /*0x2*/));
L_0x004813a5:
    // 004813a5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004813a7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004813a8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004813a9  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
