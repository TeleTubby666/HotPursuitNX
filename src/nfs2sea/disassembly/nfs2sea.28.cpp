#include "nfs2sea.h"
#include <lib/thread.h>

namespace nfs2sea
{

/* align: skip  */
void Application::sub_4a6d87(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a6d87  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a6d88  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a6d89  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a6d8a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a6d8b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a6d8c  803dc8cb4d0000         +cmp byte ptr [0x4dcbc8], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5098440) /* 0x4dcbc8 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a6d93  0f85ab000000           -jne 0x4a6e44
    if (!cpu.flags.zf)
    {
        goto L_0x004a6e44;
    }
    // 004a6d99  bbb4cb4d00             -mov ebx, 0x4dcbb4
    cpu.ebx = 5098420 /*0x4dcbb4*/;
    // 004a6d9e  eb39                   -jmp 0x4a6dd9
    goto L_0x004a6dd9;
L_0x004a6da0:
    // 004a6da0  e8e8510000             -call 0x4abf8d
    cpu.esp -= 4;
    sub_4abf8d(app, cpu);
    if (cpu.terminate) return;
    // 004a6da5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a6da7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a6da9  742b                   -je 0x4a6dd6
    if (cpu.flags.zf)
    {
        goto L_0x004a6dd6;
    }
    // 004a6dab  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004a6dad  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004a6dae  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004a6db0  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004a6db2  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a6db4  49                     -dec ecx
    (cpu.ecx)--;
    // 004a6db5  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004a6db7  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004a6db9  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004a6dbb  49                     -dec ecx
    (cpu.ecx)--;
    // 004a6dbc  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004a6dbd  81f903010000           +cmp ecx, 0x103
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(259 /*0x103*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a6dc3  7711                   -ja 0x4a6dd6
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004a6dd6;
    }
    // 004a6dc5  bb03010000             -mov ebx, 0x103
    cpu.ebx = 259 /*0x103*/;
    // 004a6dca  b8c8cb4d00             -mov eax, 0x4dcbc8
    cpu.eax = 5098440 /*0x4dcbc8*/;
    // 004a6dcf  e8c5010100             -call 0x4b6f99
    cpu.esp -= 4;
    sub_4b6f99(app, cpu);
    if (cpu.terminate) return;
    // 004a6dd4  eb0a                   -jmp 0x4a6de0
    goto L_0x004a6de0;
L_0x004a6dd6:
    // 004a6dd6  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004a6dd9:
    // 004a6dd9  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a6ddb  803800                 +cmp byte ptr [eax], 0
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
    // 004a6dde  75c0                   -jne 0x4a6da0
    if (!cpu.flags.zf)
    {
        goto L_0x004a6da0;
    }
L_0x004a6de0:
    // 004a6de0  803dc8cb4d0000         +cmp byte ptr [0x4dcbc8], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5098440) /* 0x4dcbc8 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a6de7  752a                   -jne 0x4a6e13
    if (!cpu.flags.zf)
    {
        goto L_0x004a6e13;
    }
    // 004a6de9  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a6deb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a6ded  bfc8cb4d00             -mov edi, 0x4dcbc8
    cpu.edi = 5098440 /*0x4dcbc8*/;
    // 004a6df2  e8bee0fdff             -call 0x484eb5
    cpu.esp -= 4;
    sub_484eb5(app, cpu);
    if (cpu.terminate) return;
    // 004a6df7  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a6df9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x004a6dfa:
    // 004a6dfa  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004a6dfc  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004a6dfe  3c00                   +cmp al, 0
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
    // 004a6e00  7410                   -je 0x4a6e12
    if (cpu.flags.zf)
    {
        goto L_0x004a6e12;
    }
    // 004a6e02  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004a6e05  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004a6e08  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004a6e0b  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004a6e0e  3c00                   +cmp al, 0
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
    // 004a6e10  75e8                   -jne 0x4a6dfa
    if (!cpu.flags.zf)
    {
        goto L_0x004a6dfa;
    }
L_0x004a6e12:
    // 004a6e12  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004a6e13:
    // 004a6e13  bfc8cb4d00             -mov edi, 0x4dcbc8
    cpu.edi = 5098440 /*0x4dcbc8*/;
    // 004a6e18  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004a6e19  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004a6e1b  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004a6e1d  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a6e1f  49                     -dec ecx
    (cpu.ecx)--;
    // 004a6e20  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004a6e22  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004a6e24  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004a6e26  49                     -dec ecx
    (cpu.ecx)--;
    // 004a6e27  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004a6e28  8d41ff                 -lea eax, [ecx - 1]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(-1) /* -0x1 */);
    // 004a6e2b  05c8cb4d00             -add eax, 0x4dcbc8
    (cpu.eax) += x86::reg32(x86::sreg32(5098440 /*0x4dcbc8*/));
    // 004a6e30  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 004a6e32  80fb5c                 +cmp bl, 0x5c
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(92 /*0x5c*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a6e35  740d                   -je 0x4a6e44
    if (cpu.flags.zf)
    {
        goto L_0x004a6e44;
    }
    // 004a6e37  80fb2f                 +cmp bl, 0x2f
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(47 /*0x2f*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a6e3a  7408                   -je 0x4a6e44
    if (cpu.flags.zf)
    {
        goto L_0x004a6e44;
    }
    // 004a6e3c  40                     -inc eax
    (cpu.eax)++;
    // 004a6e3d  c6005c                 -mov byte ptr [eax], 0x5c
    app->getMemory<x86::reg8>(cpu.eax) = 92 /*0x5c*/;
    // 004a6e40  40                     -inc eax
    (cpu.eax)++;
    // 004a6e41  c60000                 -mov byte ptr [eax], 0
    app->getMemory<x86::reg8>(cpu.eax) = 0 /*0x0*/;
L_0x004a6e44:
    // 004a6e44  b8c8cb4d00             -mov eax, 0x4dcbc8
    cpu.eax = 5098440 /*0x4dcbc8*/;
    // 004a6e49  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6e4a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6e4b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6e4c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6e4d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6e4e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a6e4f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a6e4f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a6e50  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a6e51  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a6e52  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a6e53  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a6e54  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a6e55  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a6e57  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004a6e5a  ff1520cb4d00           -call dword ptr [0x4dcb20]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098272) /* 0x4dcb20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a6e60  8a610d                 -mov ah, byte ptr [ecx + 0xd]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */);
    // 004a6e63  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004a6e65  f6c410                 +test ah, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 16 /*0x10*/));
    // 004a6e68  0f8478000000           -je 0x4a6ee6
    if (cpu.flags.zf)
    {
        goto L_0x004a6ee6;
    }
    // 004a6e6e  88e7                   -mov bh, ah
    cpu.bh = cpu.ah;
    // 004a6e70  80e7ef                 -and bh, 0xef
    cpu.bh &= x86::reg8(x86::sreg8(239 /*0xef*/));
    // 004a6e73  8a410c                 -mov al, byte ptr [ecx + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004a6e76  88790d                 -mov byte ptr [ecx + 0xd], bh
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */) = cpu.bh;
    // 004a6e79  a802                   +test al, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 2 /*0x2*/));
    // 004a6e7b  0f84a0000000           -je 0x4a6f21
    if (cpu.flags.zf)
    {
        goto L_0x004a6f21;
    }
    // 004a6e81  8b7908                 -mov edi, dword ptr [ecx + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004a6e84  8b5f08                 -mov ebx, dword ptr [edi + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 004a6e87  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a6e89  0f8492000000           -je 0x4a6f21
    if (cpu.flags.zf)
    {
        goto L_0x004a6f21;
    }
    // 004a6e8f  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004a6e91  8b7104                 -mov esi, dword ptr [ecx + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
L_0x004a6e94:
    // 004a6e94  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a6e96  0f8485000000           -je 0x4a6f21
    if (cpu.flags.zf)
    {
        goto L_0x004a6f21;
    }
    // 004a6e9c  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004a6e9e  0f857d000000           -jne 0x4a6f21
    if (!cpu.flags.zf)
    {
        goto L_0x004a6f21;
    }
    // 004a6ea4  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004a6ea6  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004a6ea8  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004a6eab  e82b7d0000             -call 0x4aebdb
    cpu.esp -= 4;
    sub_4aebdb(app, cpu);
    if (cpu.terminate) return;
    // 004a6eb0  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a6eb2  83f8ff                 +cmp eax, -1
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
    // 004a6eb5  750d                   -jne 0x4a6ec4
    if (!cpu.flags.zf)
    {
        goto L_0x004a6ec4;
    }
    // 004a6eb7  8a590c                 -mov bl, byte ptr [ecx + 0xc]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004a6eba  80cb20                 +or bl, 0x20
    cpu.clear_co();
    cpu.set_szp((cpu.bl |= x86::reg8(x86::sreg8(32 /*0x20*/))));
    // 004a6ebd  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004a6ebf  88590c                 -mov byte ptr [ecx + 0xc], bl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.bl;
    // 004a6ec2  eb1c                   -jmp 0x4a6ee0
    goto L_0x004a6ee0;
L_0x004a6ec4:
    // 004a6ec4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a6ec6  7518                   -jne 0x4a6ee0
    if (!cpu.flags.zf)
    {
        goto L_0x004a6ee0;
    }
    // 004a6ec8  b80c000000             -mov eax, 0xc
    cpu.eax = 12 /*0xc*/;
    // 004a6ecd  e84eb3ffff             -call 0x4a2220
    cpu.esp -= 4;
    sub_4a2220(app, cpu);
    if (cpu.terminate) return;
    // 004a6ed2  8a610c                 -mov ah, byte ptr [ecx + 0xc]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004a6ed5  80cc20                 -or ah, 0x20
    cpu.ah |= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 004a6ed8  bdffffffff             -mov ebp, 0xffffffff
    cpu.ebp = 4294967295 /*0xffffffff*/;
    // 004a6edd  88610c                 -mov byte ptr [ecx + 0xc], ah
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.ah;
L_0x004a6ee0:
    // 004a6ee0  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a6ee2  29d6                   +sub esi, edx
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a6ee4  ebae                   -jmp 0x4a6e94
    goto L_0x004a6e94;
L_0x004a6ee6:
    // 004a6ee6  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004a6ee9  83780800               +cmp dword ptr [eax + 8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a6eed  7432                   -je 0x4a6f21
    if (cpu.flags.zf)
    {
        goto L_0x004a6f21;
    }
    // 004a6eef  80610cef               -and byte ptr [ecx + 0xc], 0xef
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) &= x86::reg8(x86::sreg8(239 /*0xef*/));
    // 004a6ef3  f6410d20               +test byte ptr [ecx + 0xd], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(13) /* 0xd */) & 32 /*0x20*/));
    // 004a6ef7  7528                   -jne 0x4a6f21
    if (!cpu.flags.zf)
    {
        goto L_0x004a6f21;
    }
    // 004a6ef9  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004a6efc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a6efe  7411                   -je 0x4a6f11
    if (cpu.flags.zf)
    {
        goto L_0x004a6f11;
    }
    // 004a6f00  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a6f02  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004a6f07  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 004a6f09  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004a6f0c  e8a6000000             -call 0x4a6fb7
    cpu.esp -= 4;
    sub_4a6fb7(app, cpu);
    if (cpu.terminate) return;
L_0x004a6f11:
    // 004a6f11  83f8ff                 +cmp eax, -1
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
    // 004a6f14  750b                   -jne 0x4a6f21
    if (!cpu.flags.zf)
    {
        goto L_0x004a6f21;
    }
    // 004a6f16  8a590c                 -mov bl, byte ptr [ecx + 0xc]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004a6f19  80cb20                 -or bl, 0x20
    cpu.bl |= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 004a6f1c  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004a6f1e  88590c                 -mov byte ptr [ecx + 0xc], bl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.bl;
L_0x004a6f21:
    // 004a6f21  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004a6f24  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004a6f27  c7410400000000         -mov dword ptr [ecx + 4], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004a6f2e  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 004a6f30  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004a6f32  7518                   -jne 0x4a6f4c
    if (!cpu.flags.zf)
    {
        goto L_0x004a6f4c;
    }
    // 004a6f34  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004a6f37  f6401001               +test byte ptr [eax + 0x10], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(16) /* 0x10 */) & 1 /*0x1*/));
    // 004a6f3b  740f                   -je 0x4a6f4c
    if (cpu.flags.zf)
    {
        goto L_0x004a6f4c;
    }
    // 004a6f3d  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004a6f40  e8e5000100             -call 0x4b702a
    cpu.esp -= 4;
    sub_4b702a(app, cpu);
    if (cpu.terminate) return;
    // 004a6f45  83f8ff                 +cmp eax, -1
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
    // 004a6f48  7502                   -jne 0x4a6f4c
    if (!cpu.flags.zf)
    {
        goto L_0x004a6f4c;
    }
    // 004a6f4a  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
L_0x004a6f4c:
    // 004a6f4c  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004a6f4f  ff1524cb4d00           -call dword ptr [0x4dcb24]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098276) /* 0x4dcb24 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a6f55  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004a6f57  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6f58  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6f59  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6f5a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6f5b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6f5c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6f5d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a6f5e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a6f5e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a6f5f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a6f60  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a6f61  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a6f62  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a6f64  f6400c80               +test byte ptr [eax + 0xc], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(12) /* 0xc */) & 128 /*0x80*/));
    // 004a6f68  740d                   -je 0x4a6f77
    if (cpu.flags.zf)
    {
        goto L_0x004a6f77;
    }
    // 004a6f6a  f6420d10               +test byte ptr [edx + 0xd], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) & 16 /*0x10*/));
    // 004a6f6e  7407                   -je 0x4a6f77
    if (cpu.flags.zf)
    {
        goto L_0x004a6f77;
    }
    // 004a6f70  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a6f72  e8d1790000             -call 0x4ae948
    cpu.esp -= 4;
    sub_4ae948(app, cpu);
    if (cpu.terminate) return;
L_0x004a6f77:
    // 004a6f77  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004a6f7a  e825f30000             -call 0x4b62a4
    cpu.esp -= 4;
    sub_4b62a4(app, cpu);
    if (cpu.terminate) return;
    // 004a6f7f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a6f81  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a6f83  83f8ff                 +cmp eax, -1
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
    // 004a6f86  742a                   -je 0x4a6fb2
    if (cpu.flags.zf)
    {
        goto L_0x004a6fb2;
    }
    // 004a6f88  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004a6f8b  ff1520cb4d00           -call dword ptr [0x4dcb20]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098272) /* 0x4dcb20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a6f91  8b7204                 -mov esi, dword ptr [edx + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a6f94  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a6f96  740f                   -je 0x4a6fa7
    if (cpu.flags.zf)
    {
        goto L_0x004a6fa7;
    }
    // 004a6f98  f6420d10               +test byte ptr [edx + 0xd], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) & 16 /*0x10*/));
    // 004a6f9c  7405                   -je 0x4a6fa3
    if (cpu.flags.zf)
    {
        goto L_0x004a6fa3;
    }
    // 004a6f9e  8d0c1e                 -lea ecx, [esi + ebx]
    cpu.ecx = x86::reg32(cpu.esi + cpu.ebx * 1);
    // 004a6fa1  eb04                   -jmp 0x4a6fa7
    goto L_0x004a6fa7;
L_0x004a6fa3:
    // 004a6fa3  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004a6fa5  29f1                   -sub ecx, esi
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.esi));
L_0x004a6fa7:
    // 004a6fa7  8b4210                 -mov eax, dword ptr [edx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004a6faa  ff1524cb4d00           -call dword ptr [0x4dcb24]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098276) /* 0x4dcb24 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a6fb0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x004a6fb2:
    // 004a6fb2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6fb3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6fb4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6fb5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6fb6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a6fb7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a6fb7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a6fb8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a6fb9  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a6fbb  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a6fbd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a6fbf  7c08                   -jl 0x4a6fc9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a6fc9;
    }
    // 004a6fc1  3b05e8e44d00           +cmp eax, dword ptr [0x4de4e8]
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
    // 004a6fc7  7612                   -jbe 0x4a6fdb
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a6fdb;
    }
L_0x004a6fc9:
    // 004a6fc9  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 004a6fce  e84db2ffff             -call 0x4a2220
    cpu.esp -= 4;
    sub_4a2220(app, cpu);
    if (cpu.terminate) return;
    // 004a6fd3  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004a6fd8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6fd9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a6fda  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a6fdb:
    // 004a6fdb  ff1520cb4d00           -call dword ptr [0x4dcb20]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098272) /* 0x4dcb20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a6fe1  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a6fe3  e8f0f10000             -call 0x4b61d8
    cpu.esp -= 4;
    sub_4b61d8(app, cpu);
    if (cpu.terminate) return;
    // 004a6fe8  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004a6fea  7e10                   -jle 0x4a6ffc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a6ffc;
    }
    // 004a6fec  a880                   +test al, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 128 /*0x80*/));
    // 004a6fee  750c                   -jne 0x4a6ffc
    if (!cpu.flags.zf)
    {
        goto L_0x004a6ffc;
    }
    // 004a6ff0  80cc80                 -or ah, 0x80
    cpu.ah |= x86::reg8(x86::sreg8(128 /*0x80*/));
    // 004a6ff3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a6ff5  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a6ff7  e831f20000             -call 0x4b622d
    cpu.esp -= 4;
    sub_4b622d(app, cpu);
    if (cpu.terminate) return;
L_0x004a6ffc:
    // 004a6ffc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a6ffd  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a6fff  a1d8e44d00             -mov eax, dword ptr [0x4de4d8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5104856) /* 0x4de4d8 */);
    // 004a7004  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004a7006  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a7007  8b0490                 -mov eax, dword ptr [eax + edx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 004a700a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a700b  2eff1564454c00         -call dword ptr cs:[0x4c4564]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998500) /* 0x4c4564 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a7012  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a7014  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a7016  ff1524cb4d00           -call dword ptr [0x4dcb24]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098276) /* 0x4dcb24 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a701c  83f9ff                 +cmp ecx, -1
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
    // 004a701f  7505                   -jne 0x4a7026
    if (!cpu.flags.zf)
    {
        goto L_0x004a7026;
    }
    // 004a7021  e8fcb0ffff             -call 0x4a2122
    cpu.esp -= 4;
    sub_4a2122(app, cpu);
    if (cpu.terminate) return;
L_0x004a7026:
    // 004a7026  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a7028  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7029  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a702a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a702b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a702b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a702c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a702d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a702e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a702f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a7030  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a7031  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a7033  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a7035  7c08                   -jl 0x4a703f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a703f;
    }
    // 004a7037  3b05e8e44d00           +cmp eax, dword ptr [0x4de4e8]
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
    // 004a703d  7611                   -jbe 0x4a7050
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a7050;
    }
L_0x004a703f:
    // 004a703f  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 004a7044  e8d7b1ffff             -call 0x4a2220
    cpu.esp -= 4;
    sub_4a2220(app, cpu);
    if (cpu.terminate) return;
    // 004a7049  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004a704e  eb61                   -jmp 0x4a70b1
    goto L_0x004a70b1;
L_0x004a7050:
    // 004a7050  8b15d8e44d00           -mov edx, dword ptr [0x4de4d8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5104856) /* 0x4de4d8 */);
    // 004a7056  8b2d74cb4d00           -mov ebp, dword ptr [0x4dcb74]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5098356) /* 0x4dcb74 */);
    // 004a705c  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004a705e  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004a7060  8b0c82                 -mov ecx, dword ptr [edx + eax*4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 004a7063  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004a7065  741e                   -je 0x4a7085
    if (cpu.flags.zf)
    {
        goto L_0x004a7085;
    }
    // 004a7067  ff1568cb4d00           -call dword ptr [0x4dcb68]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098344) /* 0x4dcb68 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a706d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a706f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a7071  7412                   -je 0x4a7085
    if (cpu.flags.zf)
    {
        goto L_0x004a7085;
    }
    // 004a7073  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a7075  ff156ccb4d00           -call dword ptr [0x4dcb6c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098348) /* 0x4dcb6c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a707b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a707d  ff1574cb4d00           -call dword ptr [0x4dcb74]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098356) /* 0x4dcb74 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a7083  eb21                   -jmp 0x4a70a6
    goto L_0x004a70a6;
L_0x004a7085:
    // 004a7085  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a7087  751d                   -jne 0x4a70a6
    if (!cpu.flags.zf)
    {
        goto L_0x004a70a6;
    }
    // 004a7089  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a708a  2eff1528444c00         -call dword ptr cs:[0x4c4428]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998184) /* 0x4c4428 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a7091  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a7093  7511                   -jne 0x4a70a6
    if (!cpu.flags.zf)
    {
        goto L_0x004a70a6;
    }
    // 004a7095  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 004a709a  beffffffff             -mov esi, 0xffffffff
    cpu.esi = 4294967295 /*0xffffffff*/;
    // 004a709f  e87cb1ffff             -call 0x4a2220
    cpu.esp -= 4;
    sub_4a2220(app, cpu);
    if (cpu.terminate) return;
    // 004a70a4  eb09                   -jmp 0x4a70af
    goto L_0x004a70af;
L_0x004a70a6:
    // 004a70a6  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a70a8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a70aa  e87ef10000             -call 0x4b622d
    cpu.esp -= 4;
    sub_4b622d(app, cpu);
    if (cpu.terminate) return;
L_0x004a70af:
    // 004a70af  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x004a70b1:
    // 004a70b1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a70b2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a70b3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a70b4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a70b5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a70b6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a70b7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a70b8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a70b8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a70b9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a70ba  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a70bb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a70bc  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a70be  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a70c0  0f84f1000000           -je 0x4a71b7
    if (cpu.flags.zf)
    {
        goto L_0x004a71b7;
    }
    // 004a70c6  ff1538cb4d00           -call dword ptr [0x4dcb38]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098296) /* 0x4dcb38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a70cc  8b0df4435b00           -mov ecx, dword ptr [0x5b43f4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5981172) /* 0x5b43f4 */);
    // 004a70d2  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004a70d4  7440                   -je 0x4a7116
    if (cpu.flags.zf)
    {
        goto L_0x004a7116;
    }
    // 004a70d6  39f1                   +cmp ecx, esi
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
    // 004a70d8  770c                   -ja 0x4a70e6
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004a70e6;
    }
    // 004a70da  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 004a70dc  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a70de  39f0                   +cmp eax, esi
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
    // 004a70e0  0f878b000000           -ja 0x4a7171
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004a7171;
    }
L_0x004a70e6:
    // 004a70e6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a70e8  8b4904                 -mov ecx, dword ptr [ecx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004a70eb  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004a70ed  7410                   -je 0x4a70ff
    if (cpu.flags.zf)
    {
        goto L_0x004a70ff;
    }
    // 004a70ef  39f1                   +cmp ecx, esi
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
    // 004a70f1  770c                   -ja 0x4a70ff
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004a70ff;
    }
    // 004a70f3  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004a70f5  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a70f7  39f2                   +cmp edx, esi
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
    // 004a70f9  0f8772000000           -ja 0x4a7171
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004a7171;
    }
L_0x004a70ff:
    // 004a70ff  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004a7102  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004a7104  7410                   -je 0x4a7116
    if (cpu.flags.zf)
    {
        goto L_0x004a7116;
    }
    // 004a7106  39f1                   +cmp ecx, esi
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
    // 004a7108  770c                   -ja 0x4a7116
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004a7116;
    }
    // 004a710a  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 004a710c  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a710e  39f0                   +cmp eax, esi
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
    // 004a7110  0f875b000000           -ja 0x4a7171
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004a7171;
    }
L_0x004a7116:
    // 004a7116  8b0d00b94d00           -mov ecx, dword ptr [0x4db900]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5093632) /* 0x4db900 */);
    // 004a711c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004a711e  7434                   -je 0x4a7154
    if (cpu.flags.zf)
    {
        goto L_0x004a7154;
    }
    // 004a7120  39f1                   +cmp ecx, esi
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
    // 004a7122  7708                   -ja 0x4a712c
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004a712c;
    }
    // 004a7124  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 004a7126  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a7128  39f0                   +cmp eax, esi
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
    // 004a712a  7745                   -ja 0x4a7171
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004a7171;
    }
L_0x004a712c:
    // 004a712c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a712e  8b4904                 -mov ecx, dword ptr [ecx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004a7131  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004a7133  740c                   -je 0x4a7141
    if (cpu.flags.zf)
    {
        goto L_0x004a7141;
    }
    // 004a7135  39f1                   +cmp ecx, esi
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
    // 004a7137  7708                   -ja 0x4a7141
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004a7141;
    }
    // 004a7139  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004a713b  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a713d  39f2                   +cmp edx, esi
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
    // 004a713f  7730                   -ja 0x4a7171
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004a7171;
    }
L_0x004a7141:
    // 004a7141  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004a7144  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004a7146  740c                   -je 0x4a7154
    if (cpu.flags.zf)
    {
        goto L_0x004a7154;
    }
    // 004a7148  39f1                   +cmp ecx, esi
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
    // 004a714a  7708                   -ja 0x4a7154
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004a7154;
    }
    // 004a714c  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 004a714e  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a7150  39f0                   +cmp eax, esi
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
    // 004a7152  771d                   -ja 0x4a7171
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004a7171;
    }
L_0x004a7154:
    // 004a7154  8b0dfcb84d00           -mov ecx, dword ptr [0x4db8fc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5093628) /* 0x4db8fc */);
    // 004a715a  eb0f                   -jmp 0x4a716b
    goto L_0x004a716b;
L_0x004a715c:
    // 004a715c  39f1                   +cmp ecx, esi
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
    // 004a715e  7708                   -ja 0x4a7168
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004a7168;
    }
    // 004a7160  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 004a7162  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a7164  39f0                   +cmp eax, esi
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
    // 004a7166  7709                   -ja 0x4a7171
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004a7171;
    }
L_0x004a7168:
    // 004a7168  8b4908                 -mov ecx, dword ptr [ecx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
L_0x004a716b:
    // 004a716b  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004a716d  75ed                   -jne 0x4a715c
    if (!cpu.flags.zf)
    {
        goto L_0x004a715c;
    }
    // 004a716f  eb40                   -jmp 0x4a71b1
    goto L_0x004a71b1;
L_0x004a7171:
    // 004a7171  b8fcb84d00             -mov eax, 0x4db8fc
    cpu.eax = 5093628 /*0x4db8fc*/;
    // 004a7176  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 004a7178  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004a717e  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004a7180  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a7182  e809b20000             -call 0x4b2390
    cpu.esp -= 4;
    sub_4b2390(app, cpu);
    if (cpu.terminate) return;
    // 004a7187  8b1500b94d00           -mov edx, dword ptr [0x4db900]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5093632) /* 0x4db900 */);
    // 004a718d  890df4435b00           -mov dword ptr [0x5b43f4], ecx
    app->getMemory<x86::reg32>(x86::reg32(5981172) /* 0x5b43f4 */) = cpu.ecx;
    // 004a7193  39d1                   +cmp ecx, edx
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
    // 004a7195  7312                   -jae 0x4a71a9
    if (!cpu.flags.cf)
    {
        goto L_0x004a71a9;
    }
    // 004a7197  8b1d04b94d00           -mov ebx, dword ptr [0x4db904]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5093636) /* 0x4db904 */);
    // 004a719d  8b4114                 -mov eax, dword ptr [ecx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 004a71a0  39d8                   +cmp eax, ebx
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
    // 004a71a2  7605                   -jbe 0x4a71a9
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a71a9;
    }
    // 004a71a4  a304b94d00             -mov dword ptr [0x4db904], eax
    app->getMemory<x86::reg32>(x86::reg32(5093636) /* 0x4db904 */) = cpu.eax;
L_0x004a71a9:
    // 004a71a9  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 004a71ab  882520715b00           -mov byte ptr [0x5b7120], ah
    app->getMemory<x86::reg8>(x86::reg32(5992736) /* 0x5b7120 */) = cpu.ah;
L_0x004a71b1:
    // 004a71b1  ff1540cb4d00           -call dword ptr [0x4dcb40]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098304) /* 0x4dcb40 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004a71b7:
    // 004a71b7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a71b8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a71b9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a71ba  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a71bb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a71bc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a71bc  e95decfdff             -jmp 0x485e1e
    return sub_485e1e(app, cpu);
}

/* align: skip  */
void Application::sub_4a71c1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a71c1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a71c2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a71c3  ba87704b00             -mov edx, 0x4b7087
    cpu.edx = 4944007 /*0x4b7087*/;
    // 004a71c8  bb9b714b00             -mov ebx, 0x4b719b
    cpu.ebx = 4944283 /*0x4b719b*/;
    // 004a71cd  891568e54d00           -mov dword ptr [0x4de568], edx
    app->getMemory<x86::reg32>(x86::reg32(5105000) /* 0x4de568 */) = cpu.edx;
    // 004a71d3  891d6ce54d00           -mov dword ptr [0x4de56c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5105004) /* 0x4de56c */) = cpu.ebx;
    // 004a71d9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a71da  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a71db  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_4a71e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a71e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a71e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a71e2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a71e3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a71e4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a71e5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a71e6  ba88f34c00             -mov edx, 0x4cf388
    cpu.edx = 5043080 /*0x4cf388*/;
    // 004a71eb  e81e18feff             -call 0x488a0e
    cpu.esp -= 4;
    sub_488a0e(app, cpu);
    if (cpu.terminate) return;
    // 004a71f0  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004a71f2  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004a71f4  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a71f6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a71f8  7509                   -jne 0x4a7203
    if (!cpu.flags.zf)
    {
        goto L_0x004a7203;
    }
L_0x004a71fa:
    // 004a71fa  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a71fc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a71fd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a71fe  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a71ff  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7200  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7201  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7202  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a7203:
    // 004a7203  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 004a7208  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a720a  e854e5ffff             -call 0x4a5763
    cpu.esp -= 4;
    sub_4a5763(app, cpu);
    if (cpu.terminate) return;
    // 004a720f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a7211  75e7                   -jne 0x4a71fa
    if (!cpu.flags.zf)
    {
        goto L_0x004a71fa;
    }
    // 004a7213  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a7215  e844fdffff             -call 0x4a6f5e
    cpu.esp -= 4;
    sub_4a6f5e(app, cpu);
    if (cpu.terminate) return;
    // 004a721a  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004a721c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a721e  7eda                   -jle 0x4a71fa
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a71fa;
    }
    // 004a7220  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a7222  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a7224  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a7226  e838e5ffff             -call 0x4a5763
    cpu.esp -= 4;
    sub_4a5763(app, cpu);
    if (cpu.terminate) return;
    // 004a722b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a722d  75cb                   -jne 0x4a71fa
    if (!cpu.flags.zf)
    {
        goto L_0x004a71fa;
    }
    // 004a722f  b81c100000             -mov eax, 0x101c
    cpu.eax = 4124 /*0x101c*/;
    // 004a7234  e81721ffff             -call 0x499350
    cpu.esp -= 4;
    sub_499350(app, cpu);
    if (cpu.terminate) return;
    // 004a7239  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a723b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a723d  74bb                   -je 0x4a71fa
    if (cpu.flags.zf)
    {
        goto L_0x004a71fa;
    }
    // 004a723f  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 004a7241  897804                 -mov dword ptr [eax + 4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 004a7244  897808                 -mov dword ptr [eax + 8], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 004a7247  89680c                 -mov dword ptr [eax + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 004a724a  89b814100000           -mov dword ptr [eax + 0x1014], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4116) /* 0x1014 */) = cpu.edi;
    // 004a7250  89b818100000           -mov dword ptr [eax + 0x1018], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4120) /* 0x1018 */) = cpu.edi;
    // 004a7256  8d4810                 -lea ecx, [eax + 0x10]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004a7259  898810100000           -mov dword ptr [eax + 0x1010], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4112) /* 0x1010 */) = cpu.ecx;
    // 004a725f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a7261  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7262  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7263  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7264  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7265  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7266  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7267  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a7268(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a7268  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a7269  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a726a  ba8cf34c00             -mov edx, 0x4cf38c
    cpu.edx = 5043084 /*0x4cf38c*/;
    // 004a726f  e89a17feff             -call 0x488a0e
    cpu.esp -= 4;
    sub_488a0e(app, cpu);
    if (cpu.terminate) return;
    // 004a7274  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a7276  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a7278  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a727a  7505                   -jne 0x4a7281
    if (!cpu.flags.zf)
    {
        goto L_0x004a7281;
    }
L_0x004a727c:
    // 004a727c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a727e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a727f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7280  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a7281:
    // 004a7281  b81c100000             -mov eax, 0x101c
    cpu.eax = 4124 /*0x101c*/;
    // 004a7286  e8c520ffff             -call 0x499350
    cpu.esp -= 4;
    sub_499350(app, cpu);
    if (cpu.terminate) return;
    // 004a728b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a728d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a728f  74eb                   -je 0x4a727c
    if (cpu.flags.zf)
    {
        goto L_0x004a727c;
    }
    // 004a7291  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004a7298  c7400800000000         -mov dword ptr [eax + 8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 004a729f  c7400c00000000         -mov dword ptr [eax + 0xc], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 004a72a6  c7801410000000000000   -mov dword ptr [eax + 0x1014], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4116) /* 0x1014 */) = 0 /*0x0*/;
    // 004a72b0  c7801810000001000000   -mov dword ptr [eax + 0x1018], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4120) /* 0x1018 */) = 1 /*0x1*/;
    // 004a72ba  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004a72bc  8d5010                 -lea edx, [eax + 0x10]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004a72bf  899010100000           -mov dword ptr [eax + 0x1010], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4112) /* 0x1010 */) = cpu.edx;
    // 004a72c5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a72c7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a72c8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a72c9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a72cc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a72cc  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a72cd  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a72cf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a72d1  7507                   -jne 0x4a72da
    if (!cpu.flags.zf)
    {
        goto L_0x004a72da;
    }
    // 004a72d3  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a72d8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a72d9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a72da:
    // 004a72da  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004a72dc  e84619feff             -call 0x488c27
    cpu.esp -= 4;
    sub_488c27(app, cpu);
    if (cpu.terminate) return;
    // 004a72e1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a72e3  e8d020ffff             -call 0x4993b8
    cpu.esp -= 4;
    sub_4993b8(app, cpu);
    if (cpu.terminate) return;
    // 004a72e8  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a72ed  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a72ee  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a72f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a72f0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a72f1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a72f2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a72f3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a72f4  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a72f7  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004a72f9  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004a72fb  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a72fd  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a72ff  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004a7303  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a7305  0f8eae000000           -jle 0x4a73b9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a73b9;
    }
    // 004a730b  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a730e  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
L_0x004a7311:
    // 004a7311  8b8e14100000           -mov ecx, dword ptr [esi + 0x1014]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4116) /* 0x1014 */);
    // 004a7317  39cf                   +cmp edi, ecx
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
    // 004a7319  7d02                   -jge 0x4a731d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a731d;
    }
    // 004a731b  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
L_0x004a731d:
    // 004a731d  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004a731f  7e41                   -jle 0x4a7362
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a7362;
    }
    // 004a7321  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004a7323  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004a7325  8b8610100000           -mov eax, dword ptr [esi + 0x1010]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4112) /* 0x1010 */);
    // 004a732b  e8d027feff             -call 0x489b00
    cpu.esp -= 4;
    sub_489b00(app, cpu);
    if (cpu.terminate) return;
    // 004a7330  29cf                   -sub edi, ecx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a7332  8b9e10100000           -mov ebx, dword ptr [esi + 0x1010]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4112) /* 0x1010 */);
    // 004a7338  8b8614100000           -mov eax, dword ptr [esi + 0x1014]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4116) /* 0x1014 */);
    // 004a733e  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004a7341  01cd                   -add ebp, ecx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a7343  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a7345  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a7347  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a7349  899e10100000           -mov dword ptr [esi + 0x1010], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4112) /* 0x1010 */) = cpu.ebx;
    // 004a734f  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a7353  898614100000           -mov dword ptr [esi + 0x1014], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4116) /* 0x1014 */) = cpu.eax;
    // 004a7359  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a735b  895608                 -mov dword ptr [esi + 8], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004a735e  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
L_0x004a7362:
    // 004a7362  83be1410000000         +cmp dword ptr [esi + 0x1014], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4116) /* 0x1014 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a7369  7546                   -jne 0x4a73b1
    if (!cpu.flags.zf)
    {
        goto L_0x004a73b1;
    }
    // 004a736b  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a736d  7442                   -je 0x4a73b1
    if (cpu.flags.zf)
    {
        goto L_0x004a73b1;
    }
    // 004a736f  8d4610                 -lea eax, [esi + 0x10]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004a7372  898610100000           -mov dword ptr [esi + 0x1010], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4112) /* 0x1010 */) = cpu.eax;
    // 004a7378  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004a737b  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004a737e  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a7380  3d00100000             +cmp eax, 0x1000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4096 /*0x1000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a7385  7e3e                   -jle 0x4a73c5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a73c5;
    }
    // 004a7387  bb00100000             -mov ebx, 0x1000
    cpu.ebx = 4096 /*0x1000*/;
L_0x004a738c:
    // 004a738c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a738e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a7390  7e1b                   -jle 0x4a73ad
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a73ad;
    }
    // 004a7392  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004a7397  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004a739a  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 004a739c  e8d101ffff             -call 0x497572
    cpu.esp -= 4;
    sub_497572(app, cpu);
    if (cpu.terminate) return;
    // 004a73a1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a73a3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a73a5  7e06                   -jle 0x4a73ad
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a73ad;
    }
    // 004a73a7  898614100000           -mov dword ptr [esi + 0x1014], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4116) /* 0x1014 */) = cpu.eax;
L_0x004a73ad:
    // 004a73ad  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004a73af  7408                   -je 0x4a73b9
    if (cpu.flags.zf)
    {
        goto L_0x004a73b9;
    }
L_0x004a73b1:
    // 004a73b1  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a73b3  0f8f58ffffff           -jg 0x4a7311
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a7311;
    }
L_0x004a73b9:
    // 004a73b9  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a73bd  83c408                 +add esp, 8
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
    // 004a73c0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a73c1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a73c2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a73c3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a73c4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a73c5:
    // 004a73c5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a73c7  ebc3                   -jmp 0x4a738c
    goto L_0x004a738c;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a73cc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a73cc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a73cd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a73ce  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a73cf  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004a73d1  8b5008                 -mov edx, dword ptr [eax + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004a73d4  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a73d6  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004a73d8  8b780c                 -mov edi, dword ptr [eax + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004a73db  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004a73de  39fa                   +cmp edx, edi
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
    // 004a73e0  7e03                   -jle 0x4a73e5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a73e5;
    }
    // 004a73e2  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
L_0x004a73e5:
    // 004a73e5  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004a73ea  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a73ec  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004a73ee  e89c3affff             -call 0x49ae8f
    cpu.esp -= 4;
    sub_49ae8f(app, cpu);
    if (cpu.terminate) return;
    // 004a73f3  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a73f8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a73f9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a73fa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a73fb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a73fc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a73fc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a73fd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a73fe  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a73ff  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a7400  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 004a7405  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a7407  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a7409  0f8c8d000000           -jl 0x4a749c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a749c;
    }
    // 004a740f  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004a7412  39da                   +cmp edx, ebx
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
    // 004a7414  0f8e8b000000           -jle 0x4a74a5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a74a5;
    }
    // 004a741a  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004a741c  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x004a741e:
    // 004a741e  c7811410000000000000   -mov dword ptr [ecx + 0x1014], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4116) /* 0x1014 */) = 0 /*0x0*/;
    // 004a7428  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004a742b  895108                 -mov dword ptr [ecx + 8], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004a742e  898110100000           -mov dword ptr [ecx + 0x1010], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4112) /* 0x1010 */) = cpu.eax;
L_0x004a7434:
    // 004a7434  83b91810000000         +cmp dword ptr [ecx + 0x1018], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4120) /* 0x1018 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a743b  0f8596000000           -jne 0x4a74d7
    if (!cpu.flags.zf)
    {
        goto L_0x004a74d7;
    }
    // 004a7441  8b9914100000           -mov ebx, dword ptr [ecx + 0x1014]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4116) /* 0x1014 */);
    // 004a7447  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a7449  7e0c                   -jle 0x4a7457
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a7457;
    }
    // 004a744b  81fb00100000           +cmp ebx, 0x1000
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
    // 004a7451  0f8eab000000           -jle 0x4a7502
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a7502;
    }
L_0x004a7457:
    // 004a7457  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a7459  0f8cbd000000           -jl 0x4a751c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a751c;
    }
    // 004a745f  3b510c                 +cmp edx, dword ptr [ecx + 0xc]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a7462  0f8fb4000000           -jg 0x4a751c
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a751c;
    }
    // 004a7468  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004a746b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a746d  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a746f  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 004a7471  e8ede2ffff             -call 0x4a5763
    cpu.esp -= 4;
    sub_4a5763(app, cpu);
    if (cpu.terminate) return;
    // 004a7476  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a7478  0f859e000000           -jne 0x4a751c
    if (!cpu.flags.zf)
    {
        goto L_0x004a751c;
    }
    // 004a747e  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a7480  0f8496000000           -je 0x4a751c
    if (cpu.flags.zf)
    {
        goto L_0x004a751c;
    }
    // 004a7486  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 004a748b  c7811410000000000000   -mov dword ptr [ecx + 0x1014], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4116) /* 0x1014 */) = 0 /*0x0*/;
    // 004a7495  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a7497  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7498  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7499  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a749a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a749b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a749c:
    // 004a749c  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004a749e  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004a74a0  e979ffffff             -jmp 0x4a741e
    goto L_0x004a741e;
L_0x004a74a5:
    // 004a74a5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a74a6  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004a74a8  8b7808                 -mov edi, dword ptr [eax + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004a74ab  8ba810100000           -mov ebp, dword ptr [eax + 0x1010]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4112) /* 0x1010 */);
    // 004a74b1  29fb                   -sub ebx, edi
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004a74b3  01dd                   -add ebp, ebx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004a74b5  8bb814100000           -mov edi, dword ptr [eax + 0x1014]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4116) /* 0x1014 */);
    // 004a74bb  89a810100000           -mov dword ptr [eax + 0x1010], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4112) /* 0x1010 */) = cpu.ebp;
    // 004a74c1  29df                   -sub edi, ebx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a74c3  8b6808                 -mov ebp, dword ptr [eax + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004a74c6  89b814100000           -mov dword ptr [eax + 0x1014], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4116) /* 0x1014 */) = cpu.edi;
    // 004a74cc  01dd                   +add ebp, ebx
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a74ce  896808                 -mov dword ptr [eax + 8], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebp;
    // 004a74d1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a74d2  e95dffffff             -jmp 0x4a7434
    goto L_0x004a7434;
L_0x004a74d7:
    // 004a74d7  8b5904                 -mov ebx, dword ptr [ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004a74da  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 004a74dc  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004a74de  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a74e0  e87ee2ffff             -call 0x4a5763
    cpu.esp -= 4;
    sub_4a5763(app, cpu);
    if (cpu.terminate) return;
    // 004a74e5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a74e7  7510                   -jne 0x4a74f9
    if (!cpu.flags.zf)
    {
        goto L_0x004a74f9;
    }
    // 004a74e9  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a74eb  740c                   -je 0x4a74f9
    if (cpu.flags.zf)
    {
        goto L_0x004a74f9;
    }
    // 004a74ed  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 004a74f2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a74f4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a74f5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a74f6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a74f7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a74f8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a74f9:
    // 004a74f9  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004a74fb  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a74fd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a74fe  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a74ff  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7500  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7501  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a7502:
    // 004a7502  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004a7505  8b9910100000           -mov ebx, dword ptr [ecx + 0x1010]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4112) /* 0x1010 */);
    // 004a750b  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004a750d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a750f  0f8c42ffffff           -jl 0x4a7457
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a7457;
    }
    // 004a7515  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a7517  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7518  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7519  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a751a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a751b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a751c:
    // 004a751c  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004a751e  c7811410000000000000   -mov dword ptr [ecx + 0x1014], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4116) /* 0x1014 */) = 0 /*0x0*/;
    // 004a7528  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a752a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a752b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a752c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a752d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a752e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a7530(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a7530  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004a7533  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a7534(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a7534  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004a7537  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a7538(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a7538  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 004a7539  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a753a  a907000000             +test eax, 7
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 7 /*0x7*/));
    // 004a753f  757f                   -jne 0x4a75c0
    if (!cpu.flags.zf)
    {
        goto L_0x004a75c0;
    }
L_0x004a7541:
    // 004a7541  83eb20                 +sub ebx, 0x20
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a7544  7825                   -js 0x4a756b
    if (cpu.flags.sf)
    {
        goto L_0x004a756b;
    }
L_0x004a7546:
    // 004a7546  df2a                   -fild qword ptr [edx]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.edx))));
    // 004a7548  df6a08                 -fild qword ptr [edx + 8]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(8) /* 0x8 */))));
    // 004a754b  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a754d  df38                   -fistp qword ptr [eax]
    app->getMemory<x86::reg64>(cpu.eax) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 004a754f  df7808                 -fistp qword ptr [eax + 8]
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(8) /* 0x8 */) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 004a7552  df6a10                 -fild qword ptr [edx + 0x10]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(16) /* 0x10 */))));
    // 004a7555  df6a18                 -fild qword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(24) /* 0x18 */))));
    // 004a7558  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a755a  df7810                 -fistp qword ptr [eax + 0x10]
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(16) /* 0x10 */) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 004a755d  df7818                 -fistp qword ptr [eax + 0x18]
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(24) /* 0x18 */) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 004a7560  8d5220                 -lea edx, [edx + 0x20]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 004a7563  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004a7566  83eb20                 +sub ebx, 0x20
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a7569  79db                   -jns 0x4a7546
    if (!cpu.flags.sf)
    {
        goto L_0x004a7546;
    }
L_0x004a756b:
    // 004a756b  83c318                 +add ebx, 0x18
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a756e  780f                   -js 0x4a757f
    if (cpu.flags.sf)
    {
        goto L_0x004a757f;
    }
L_0x004a7570:
    // 004a7570  df2a                   -fild qword ptr [edx]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.edx))));
    // 004a7572  df38                   -fistp qword ptr [eax]
    app->getMemory<x86::reg64>(cpu.eax) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 004a7574  8d5208                 -lea edx, [edx + 8]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004a7577  8d4008                 -lea eax, [eax + 8]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004a757a  83eb08                 +sub ebx, 8
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a757d  79f1                   -jns 0x4a7570
    if (!cpu.flags.sf)
    {
        goto L_0x004a7570;
    }
L_0x004a757f:
    // 004a757f  83c308                 +add ebx, 8
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a7582  7502                   -jne 0x4a7586
    if (!cpu.flags.zf)
    {
        goto L_0x004a7586;
    }
    // 004a7584  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7585  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a7586:
    // 004a7586  83fb04                 +cmp ebx, 4
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
    // 004a7589  720d                   -jb 0x4a7598
    if (cpu.flags.cf)
    {
        goto L_0x004a7598;
    }
    // 004a758b  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004a758d  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a7590  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 004a7592  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004a7595  83eb04                 -sub ebx, 4
    (cpu.ebx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004a7598:
    // 004a7598  83fb02                 +cmp ebx, 2
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
    // 004a759b  720f                   -jb 0x4a75ac
    if (cpu.flags.cf)
    {
        goto L_0x004a75ac;
    }
    // 004a759d  668b0a                 -mov cx, word ptr [edx]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx);
    // 004a75a0  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 004a75a3  668908                 -mov word ptr [eax], cx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.cx;
    // 004a75a6  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 004a75a9  83eb02                 -sub ebx, 2
    (cpu.ebx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x004a75ac:
    // 004a75ac  83fb01                 +cmp ebx, 1
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
    // 004a75af  720d                   -jb 0x4a75be
    if (cpu.flags.cf)
    {
        goto L_0x004a75be;
    }
    // 004a75b1  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 004a75b3  8d5201                 -lea edx, [edx + 1]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004a75b6  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 004a75b8  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004a75bb  83eb01                 -sub ebx, 1
    (cpu.ebx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004a75be:
    // 004a75be  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a75bf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a75c0:
    // 004a75c0  a901000000             +test eax, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 1 /*0x1*/));
    // 004a75c5  7412                   -je 0x4a75d9
    if (cpu.flags.zf)
    {
        goto L_0x004a75d9;
    }
    // 004a75c7  83fb01                 +cmp ebx, 1
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
    // 004a75ca  7c0d                   -jl 0x4a75d9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a75d9;
    }
    // 004a75cc  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 004a75ce  8d5201                 -lea edx, [edx + 1]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004a75d1  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 004a75d3  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004a75d6  83eb01                 -sub ebx, 1
    (cpu.ebx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004a75d9:
    // 004a75d9  a902000000             +test eax, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2 /*0x2*/));
    // 004a75de  7414                   -je 0x4a75f4
    if (cpu.flags.zf)
    {
        goto L_0x004a75f4;
    }
    // 004a75e0  83fb02                 +cmp ebx, 2
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
    // 004a75e3  7c0f                   -jl 0x4a75f4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a75f4;
    }
    // 004a75e5  668b0a                 -mov cx, word ptr [edx]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx);
    // 004a75e8  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 004a75eb  668908                 -mov word ptr [eax], cx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.cx;
    // 004a75ee  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 004a75f1  83eb02                 -sub ebx, 2
    (cpu.ebx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x004a75f4:
    // 004a75f4  a904000000             +test eax, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 4 /*0x4*/));
    // 004a75f9  7412                   -je 0x4a760d
    if (cpu.flags.zf)
    {
        goto L_0x004a760d;
    }
    // 004a75fb  83fb04                 +cmp ebx, 4
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
    // 004a75fe  7c0d                   -jl 0x4a760d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a760d;
    }
    // 004a7600  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004a7602  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a7605  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 004a7607  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004a760a  83eb04                 +sub ebx, 4
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
L_0x004a760d:
    // 004a760d  e92fffffff             -jmp 0x4a7541
    goto L_0x004a7541;
}

/* align: skip  */
void Application::sub_4a7539(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004a7539;
    // 004a7538  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
L_entry_0x004a7539:
    // 004a7539  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a753a  a907000000             +test eax, 7
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 7 /*0x7*/));
    // 004a753f  757f                   -jne 0x4a75c0
    if (!cpu.flags.zf)
    {
        goto L_0x004a75c0;
    }
L_0x004a7541:
    // 004a7541  83eb20                 +sub ebx, 0x20
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a7544  7825                   -js 0x4a756b
    if (cpu.flags.sf)
    {
        goto L_0x004a756b;
    }
L_0x004a7546:
    // 004a7546  df2a                   -fild qword ptr [edx]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.edx))));
    // 004a7548  df6a08                 -fild qword ptr [edx + 8]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(8) /* 0x8 */))));
    // 004a754b  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a754d  df38                   -fistp qword ptr [eax]
    app->getMemory<x86::reg64>(cpu.eax) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 004a754f  df7808                 -fistp qword ptr [eax + 8]
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(8) /* 0x8 */) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 004a7552  df6a10                 -fild qword ptr [edx + 0x10]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(16) /* 0x10 */))));
    // 004a7555  df6a18                 -fild qword ptr [edx + 0x18]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(24) /* 0x18 */))));
    // 004a7558  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a755a  df7810                 -fistp qword ptr [eax + 0x10]
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(16) /* 0x10 */) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 004a755d  df7818                 -fistp qword ptr [eax + 0x18]
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(24) /* 0x18 */) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 004a7560  8d5220                 -lea edx, [edx + 0x20]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 004a7563  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004a7566  83eb20                 +sub ebx, 0x20
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a7569  79db                   -jns 0x4a7546
    if (!cpu.flags.sf)
    {
        goto L_0x004a7546;
    }
L_0x004a756b:
    // 004a756b  83c318                 +add ebx, 0x18
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a756e  780f                   -js 0x4a757f
    if (cpu.flags.sf)
    {
        goto L_0x004a757f;
    }
L_0x004a7570:
    // 004a7570  df2a                   -fild qword ptr [edx]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.edx))));
    // 004a7572  df38                   -fistp qword ptr [eax]
    app->getMemory<x86::reg64>(cpu.eax) = x86::reg64(x86::sreg64(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 004a7574  8d5208                 -lea edx, [edx + 8]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004a7577  8d4008                 -lea eax, [eax + 8]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004a757a  83eb08                 +sub ebx, 8
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a757d  79f1                   -jns 0x4a7570
    if (!cpu.flags.sf)
    {
        goto L_0x004a7570;
    }
L_0x004a757f:
    // 004a757f  83c308                 +add ebx, 8
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a7582  7502                   -jne 0x4a7586
    if (!cpu.flags.zf)
    {
        goto L_0x004a7586;
    }
    // 004a7584  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7585  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a7586:
    // 004a7586  83fb04                 +cmp ebx, 4
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
    // 004a7589  720d                   -jb 0x4a7598
    if (cpu.flags.cf)
    {
        goto L_0x004a7598;
    }
    // 004a758b  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004a758d  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a7590  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 004a7592  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004a7595  83eb04                 -sub ebx, 4
    (cpu.ebx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004a7598:
    // 004a7598  83fb02                 +cmp ebx, 2
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
    // 004a759b  720f                   -jb 0x4a75ac
    if (cpu.flags.cf)
    {
        goto L_0x004a75ac;
    }
    // 004a759d  668b0a                 -mov cx, word ptr [edx]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx);
    // 004a75a0  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 004a75a3  668908                 -mov word ptr [eax], cx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.cx;
    // 004a75a6  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 004a75a9  83eb02                 -sub ebx, 2
    (cpu.ebx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x004a75ac:
    // 004a75ac  83fb01                 +cmp ebx, 1
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
    // 004a75af  720d                   -jb 0x4a75be
    if (cpu.flags.cf)
    {
        goto L_0x004a75be;
    }
    // 004a75b1  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 004a75b3  8d5201                 -lea edx, [edx + 1]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004a75b6  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 004a75b8  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004a75bb  83eb01                 -sub ebx, 1
    (cpu.ebx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004a75be:
    // 004a75be  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a75bf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a75c0:
    // 004a75c0  a901000000             +test eax, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 1 /*0x1*/));
    // 004a75c5  7412                   -je 0x4a75d9
    if (cpu.flags.zf)
    {
        goto L_0x004a75d9;
    }
    // 004a75c7  83fb01                 +cmp ebx, 1
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
    // 004a75ca  7c0d                   -jl 0x4a75d9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a75d9;
    }
    // 004a75cc  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 004a75ce  8d5201                 -lea edx, [edx + 1]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004a75d1  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 004a75d3  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004a75d6  83eb01                 -sub ebx, 1
    (cpu.ebx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004a75d9:
    // 004a75d9  a902000000             +test eax, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2 /*0x2*/));
    // 004a75de  7414                   -je 0x4a75f4
    if (cpu.flags.zf)
    {
        goto L_0x004a75f4;
    }
    // 004a75e0  83fb02                 +cmp ebx, 2
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
    // 004a75e3  7c0f                   -jl 0x4a75f4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a75f4;
    }
    // 004a75e5  668b0a                 -mov cx, word ptr [edx]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx);
    // 004a75e8  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 004a75eb  668908                 -mov word ptr [eax], cx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.cx;
    // 004a75ee  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 004a75f1  83eb02                 -sub ebx, 2
    (cpu.ebx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x004a75f4:
    // 004a75f4  a904000000             +test eax, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 4 /*0x4*/));
    // 004a75f9  7412                   -je 0x4a760d
    if (cpu.flags.zf)
    {
        goto L_0x004a760d;
    }
    // 004a75fb  83fb04                 +cmp ebx, 4
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
    // 004a75fe  7c0d                   -jl 0x4a760d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a760d;
    }
    // 004a7600  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004a7602  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a7605  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 004a7607  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004a760a  83eb04                 +sub ebx, 4
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
L_0x004a760d:
    // 004a760d  e92fffffff             -jmp 0x4a7541
    goto L_0x004a7541;
}

/* align: skip 0x00 0x00 */
void Application::sub_4a7614(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a7614  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 004a7615  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a7616  a907000000             +test eax, 7
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 7 /*0x7*/));
    // 004a761b  0f8585000000           -jne 0x4a76a6
    if (!cpu.flags.zf)
    {
        goto L_0x004a76a6;
    }
L_0x004a7621:
    // 004a7621  83eb20                 +sub ebx, 0x20
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a7624  7829                   -js 0x4a764f
    if (cpu.flags.sf)
    {
        goto L_0x004a764f;
    }
L_0x004a7626:
    // 004a7626  0f6f02                 -movq mm0, qword ptr [edx]
    cpu.mmx.mm0 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edx));
    // 004a7629  0f6f4a08               -movq mm1, qword ptr [edx + 8]
    cpu.mmx.mm1 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(8) /* 0x8 */));
    // 004a762d  0f6f5210               -movq mm2, qword ptr [edx + 0x10]
    cpu.mmx.mm2 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(16) /* 0x10 */));
    // 004a7631  0f6f5a18               -movq mm3, qword ptr [edx + 0x18]
    cpu.mmx.mm3 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(24) /* 0x18 */));
    // 004a7635  0f7f00                 -movq qword ptr [eax], mm0
    app->getMemory<x86::reg64>(cpu.eax) = cpu.mmx.mm0;
    // 004a7638  0f7f4808               -movq qword ptr [eax + 8], mm1
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.mmx.mm1;
    // 004a763c  0f7f5010               -movq qword ptr [eax + 0x10], mm2
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.mmx.mm2;
    // 004a7640  0f7f5818               -movq qword ptr [eax + 0x18], mm3
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.mmx.mm3;
    // 004a7644  8d5220                 -lea edx, [edx + 0x20]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 004a7647  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004a764a  83eb20                 +sub ebx, 0x20
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a764d  79d7                   -jns 0x4a7626
    if (!cpu.flags.sf)
    {
        goto L_0x004a7626;
    }
L_0x004a764f:
    // 004a764f  83c318                 +add ebx, 0x18
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a7652  7811                   -js 0x4a7665
    if (cpu.flags.sf)
    {
        goto L_0x004a7665;
    }
L_0x004a7654:
    // 004a7654  0f6f02                 -movq mm0, qword ptr [edx]
    cpu.mmx.mm0 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edx));
    // 004a7657  0f7f00                 -movq qword ptr [eax], mm0
    app->getMemory<x86::reg64>(cpu.eax) = cpu.mmx.mm0;
    // 004a765a  8d5208                 -lea edx, [edx + 8]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004a765d  8d4008                 -lea eax, [eax + 8]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004a7660  83eb08                 +sub ebx, 8
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a7663  79ef                   -jns 0x4a7654
    if (!cpu.flags.sf)
    {
        goto L_0x004a7654;
    }
L_0x004a7665:
    // 004a7665  83c308                 +add ebx, 8
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a7668  7502                   -jne 0x4a766c
    if (!cpu.flags.zf)
    {
        goto L_0x004a766c;
    }
    // 004a766a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a766b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a766c:
    // 004a766c  83fb04                 +cmp ebx, 4
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
    // 004a766f  720d                   -jb 0x4a767e
    if (cpu.flags.cf)
    {
        goto L_0x004a767e;
    }
    // 004a7671  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004a7673  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a7676  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 004a7678  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004a767b  83eb04                 -sub ebx, 4
    (cpu.ebx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004a767e:
    // 004a767e  83fb02                 +cmp ebx, 2
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
    // 004a7681  720f                   -jb 0x4a7692
    if (cpu.flags.cf)
    {
        goto L_0x004a7692;
    }
    // 004a7683  668b0a                 -mov cx, word ptr [edx]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx);
    // 004a7686  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 004a7689  668908                 -mov word ptr [eax], cx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.cx;
    // 004a768c  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 004a768f  83eb02                 -sub ebx, 2
    (cpu.ebx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x004a7692:
    // 004a7692  83fb01                 +cmp ebx, 1
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
    // 004a7695  720d                   -jb 0x4a76a4
    if (cpu.flags.cf)
    {
        goto L_0x004a76a4;
    }
    // 004a7697  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 004a7699  8d5201                 -lea edx, [edx + 1]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004a769c  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 004a769e  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004a76a1  83eb01                 -sub ebx, 1
    (cpu.ebx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004a76a4:
    // 004a76a4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a76a5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a76a6:
    // 004a76a6  a901000000             +test eax, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 1 /*0x1*/));
    // 004a76ab  7412                   -je 0x4a76bf
    if (cpu.flags.zf)
    {
        goto L_0x004a76bf;
    }
    // 004a76ad  83fb01                 +cmp ebx, 1
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
    // 004a76b0  7c0d                   -jl 0x4a76bf
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a76bf;
    }
    // 004a76b2  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 004a76b4  8d5201                 -lea edx, [edx + 1]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004a76b7  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 004a76b9  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004a76bc  83eb01                 -sub ebx, 1
    (cpu.ebx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004a76bf:
    // 004a76bf  a902000000             +test eax, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2 /*0x2*/));
    // 004a76c4  7414                   -je 0x4a76da
    if (cpu.flags.zf)
    {
        goto L_0x004a76da;
    }
    // 004a76c6  83fb02                 +cmp ebx, 2
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
    // 004a76c9  7c0f                   -jl 0x4a76da
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a76da;
    }
    // 004a76cb  668b0a                 -mov cx, word ptr [edx]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx);
    // 004a76ce  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 004a76d1  668908                 -mov word ptr [eax], cx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.cx;
    // 004a76d4  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 004a76d7  83eb02                 -sub ebx, 2
    (cpu.ebx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x004a76da:
    // 004a76da  a904000000             +test eax, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 4 /*0x4*/));
    // 004a76df  7412                   -je 0x4a76f3
    if (cpu.flags.zf)
    {
        goto L_0x004a76f3;
    }
    // 004a76e1  83fb04                 +cmp ebx, 4
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
    // 004a76e4  7c0d                   -jl 0x4a76f3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a76f3;
    }
    // 004a76e6  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004a76e8  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a76eb  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 004a76ed  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004a76f0  83eb04                 +sub ebx, 4
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
L_0x004a76f3:
    // 004a76f3  e929ffffff             -jmp 0x4a7621
    goto L_0x004a7621;
}

/* align: skip  */
void Application::sub_4a7615(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004a7615;
    // 004a7614  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
L_entry_0x004a7615:
    // 004a7615  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a7616  a907000000             +test eax, 7
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 7 /*0x7*/));
    // 004a761b  0f8585000000           -jne 0x4a76a6
    if (!cpu.flags.zf)
    {
        goto L_0x004a76a6;
    }
L_0x004a7621:
    // 004a7621  83eb20                 +sub ebx, 0x20
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a7624  7829                   -js 0x4a764f
    if (cpu.flags.sf)
    {
        goto L_0x004a764f;
    }
L_0x004a7626:
    // 004a7626  0f6f02                 -movq mm0, qword ptr [edx]
    cpu.mmx.mm0 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edx));
    // 004a7629  0f6f4a08               -movq mm1, qword ptr [edx + 8]
    cpu.mmx.mm1 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(8) /* 0x8 */));
    // 004a762d  0f6f5210               -movq mm2, qword ptr [edx + 0x10]
    cpu.mmx.mm2 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(16) /* 0x10 */));
    // 004a7631  0f6f5a18               -movq mm3, qword ptr [edx + 0x18]
    cpu.mmx.mm3 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edx + x86::reg32(24) /* 0x18 */));
    // 004a7635  0f7f00                 -movq qword ptr [eax], mm0
    app->getMemory<x86::reg64>(cpu.eax) = cpu.mmx.mm0;
    // 004a7638  0f7f4808               -movq qword ptr [eax + 8], mm1
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.mmx.mm1;
    // 004a763c  0f7f5010               -movq qword ptr [eax + 0x10], mm2
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.mmx.mm2;
    // 004a7640  0f7f5818               -movq qword ptr [eax + 0x18], mm3
    app->getMemory<x86::reg64>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.mmx.mm3;
    // 004a7644  8d5220                 -lea edx, [edx + 0x20]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 004a7647  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004a764a  83eb20                 +sub ebx, 0x20
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a764d  79d7                   -jns 0x4a7626
    if (!cpu.flags.sf)
    {
        goto L_0x004a7626;
    }
L_0x004a764f:
    // 004a764f  83c318                 +add ebx, 0x18
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a7652  7811                   -js 0x4a7665
    if (cpu.flags.sf)
    {
        goto L_0x004a7665;
    }
L_0x004a7654:
    // 004a7654  0f6f02                 -movq mm0, qword ptr [edx]
    cpu.mmx.mm0 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edx));
    // 004a7657  0f7f00                 -movq qword ptr [eax], mm0
    app->getMemory<x86::reg64>(cpu.eax) = cpu.mmx.mm0;
    // 004a765a  8d5208                 -lea edx, [edx + 8]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004a765d  8d4008                 -lea eax, [eax + 8]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004a7660  83eb08                 +sub ebx, 8
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a7663  79ef                   -jns 0x4a7654
    if (!cpu.flags.sf)
    {
        goto L_0x004a7654;
    }
L_0x004a7665:
    // 004a7665  83c308                 +add ebx, 8
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a7668  7502                   -jne 0x4a766c
    if (!cpu.flags.zf)
    {
        goto L_0x004a766c;
    }
    // 004a766a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a766b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a766c:
    // 004a766c  83fb04                 +cmp ebx, 4
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
    // 004a766f  720d                   -jb 0x4a767e
    if (cpu.flags.cf)
    {
        goto L_0x004a767e;
    }
    // 004a7671  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004a7673  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a7676  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 004a7678  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004a767b  83eb04                 -sub ebx, 4
    (cpu.ebx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004a767e:
    // 004a767e  83fb02                 +cmp ebx, 2
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
    // 004a7681  720f                   -jb 0x4a7692
    if (cpu.flags.cf)
    {
        goto L_0x004a7692;
    }
    // 004a7683  668b0a                 -mov cx, word ptr [edx]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx);
    // 004a7686  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 004a7689  668908                 -mov word ptr [eax], cx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.cx;
    // 004a768c  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 004a768f  83eb02                 -sub ebx, 2
    (cpu.ebx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x004a7692:
    // 004a7692  83fb01                 +cmp ebx, 1
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
    // 004a7695  720d                   -jb 0x4a76a4
    if (cpu.flags.cf)
    {
        goto L_0x004a76a4;
    }
    // 004a7697  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 004a7699  8d5201                 -lea edx, [edx + 1]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004a769c  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 004a769e  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004a76a1  83eb01                 -sub ebx, 1
    (cpu.ebx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004a76a4:
    // 004a76a4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a76a5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a76a6:
    // 004a76a6  a901000000             +test eax, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 1 /*0x1*/));
    // 004a76ab  7412                   -je 0x4a76bf
    if (cpu.flags.zf)
    {
        goto L_0x004a76bf;
    }
    // 004a76ad  83fb01                 +cmp ebx, 1
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
    // 004a76b0  7c0d                   -jl 0x4a76bf
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a76bf;
    }
    // 004a76b2  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 004a76b4  8d5201                 -lea edx, [edx + 1]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004a76b7  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 004a76b9  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004a76bc  83eb01                 -sub ebx, 1
    (cpu.ebx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004a76bf:
    // 004a76bf  a902000000             +test eax, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2 /*0x2*/));
    // 004a76c4  7414                   -je 0x4a76da
    if (cpu.flags.zf)
    {
        goto L_0x004a76da;
    }
    // 004a76c6  83fb02                 +cmp ebx, 2
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
    // 004a76c9  7c0f                   -jl 0x4a76da
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a76da;
    }
    // 004a76cb  668b0a                 -mov cx, word ptr [edx]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx);
    // 004a76ce  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 004a76d1  668908                 -mov word ptr [eax], cx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.cx;
    // 004a76d4  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 004a76d7  83eb02                 -sub ebx, 2
    (cpu.ebx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x004a76da:
    // 004a76da  a904000000             +test eax, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 4 /*0x4*/));
    // 004a76df  7412                   -je 0x4a76f3
    if (cpu.flags.zf)
    {
        goto L_0x004a76f3;
    }
    // 004a76e1  83fb04                 +cmp ebx, 4
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
    // 004a76e4  7c0d                   -jl 0x4a76f3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a76f3;
    }
    // 004a76e6  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004a76e8  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a76eb  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 004a76ed  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004a76f0  83eb04                 +sub ebx, 4
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
L_0x004a76f3:
    // 004a76f3  e929ffffff             -jmp 0x4a7621
    goto L_0x004a7621;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a7700(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a7700  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a7701  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a7705  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a7709  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004a770f  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a7711  7505                   -jne 0x4a7718
    if (!cpu.flags.zf)
    {
        goto L_0x004a7718;
    }
    // 004a7713  bbd0165600             -mov ebx, 0x5616d0
    cpu.ebx = 5641936 /*0x5616d0*/;
L_0x004a7718:
    // 004a7718  e85badfdff             -call 0x482478
    cpu.esp -= 4;
    sub_482478(app, cpu);
    if (cpu.terminate) return;
    // 004a771d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a771f  743a                   -je 0x4a775b
    if (cpu.flags.zf)
    {
        goto L_0x004a775b;
    }
    // 004a7721  833b00                 +cmp dword ptr [ebx], 0
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
    // 004a7724  7407                   -je 0x4a772d
    if (cpu.flags.zf)
    {
        goto L_0x004a772d;
    }
    // 004a7726  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a7728  e87751feff             -call 0x48c8a4
    cpu.esp -= 4;
    sub_48c8a4(app, cpu);
    if (cpu.terminate) return;
L_0x004a772d:
    // 004a772d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a772f  e83843feff             -call 0x48ba6c
    cpu.esp -= 4;
    sub_48ba6c(app, cpu);
    if (cpu.terminate) return;
    // 004a7734  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a7736  7412                   -je 0x4a774a
    if (cpu.flags.zf)
    {
        goto L_0x004a774a;
    }
    // 004a7738  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a773a  e80946feff             -call 0x48bd48
    cpu.esp -= 4;
    sub_48bd48(app, cpu);
    if (cpu.terminate) return;
    // 004a773f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a7741  7407                   -je 0x4a774a
    if (cpu.flags.zf)
    {
        goto L_0x004a774a;
    }
    // 004a7743  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a7745  a3e0cc4d00             -mov dword ptr [0x4dcce0], eax
    app->getMemory<x86::reg32>(x86::reg32(5098720) /* 0x4dcce0 */) = cpu.eax;
L_0x004a774a:
    // 004a774a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a774c  8915dccc4d00           -mov dword ptr [0x4dccdc], edx
    app->getMemory<x86::reg32>(x86::reg32(5098716) /* 0x4dccdc */) = cpu.edx;
    // 004a7752  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a7757  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7758  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x004a775b:
    // 004a775b  8b9354040000           -mov edx, dword ptr [ebx + 0x454]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1108) /* 0x454 */);
    // 004a7761  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a7763  741a                   -je 0x4a777f
    if (cpu.flags.zf)
    {
        goto L_0x004a777f;
    }
    // 004a7765  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a7766  6a09                   -push 9
    app->getMemory<x86::reg32>(cpu.esp-4) = 9 /*0x9*/;
    cpu.esp -= 4;
    // 004a7768  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a7769  2eff150c444c00         -call dword ptr cs:[0x4c440c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998156) /* 0x4c440c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a7770  8bb354040000           -mov esi, dword ptr [ebx + 0x454]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1108) /* 0x454 */);
    // 004a7776  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a7777  2eff15fc434c00         -call dword ptr cs:[0x4c43fc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998140) /* 0x4c43fc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a777e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004a777f:
    // 004a777f  c705dccc4d00ffffffff   -mov dword ptr [0x4dccdc], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5098716) /* 0x4dccdc */) = 4294967295 /*0xffffffff*/;
    // 004a7789  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a778e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a778f  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a7794(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a7794  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a7795  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a7799  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a779d  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a77a1  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004a77a7  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004a77a9  7505                   -jne 0x4a77b0
    if (!cpu.flags.zf)
    {
        goto L_0x004a77b0;
    }
    // 004a77ab  b9d0165600             -mov ecx, 0x5616d0
    cpu.ecx = 5641936 /*0x5616d0*/;
L_0x004a77b0:
    // 004a77b0  e8c3acfdff             -call 0x482478
    cpu.esp -= 4;
    sub_482478(app, cpu);
    if (cpu.terminate) return;
    // 004a77b5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a77b7  7513                   -jne 0x4a77cc
    if (!cpu.flags.zf)
    {
        goto L_0x004a77cc;
    }
    // 004a77b9  c705dccc4d00ffffffff   -mov dword ptr [0x4dccdc], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5098716) /* 0x4dccdc */) = 4294967295 /*0xffffffff*/;
    // 004a77c3  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a77c8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a77c9  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x004a77cc:
    // 004a77cc  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a77ce  e88547feff             -call 0x48bf58
    cpu.esp -= 4;
    sub_48bf58(app, cpu);
    if (cpu.terminate) return;
    // 004a77d3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a77d5  e8d64cfeff             -call 0x48c4b0
    cpu.esp -= 4;
    sub_48c4b0(app, cpu);
    if (cpu.terminate) return;
    // 004a77da  83f8ff                 +cmp eax, -1
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
    // 004a77dd  7c54                   -jl 0x4a7833
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a7833;
    }
    // 004a77df  7f24                   -jg 0x4a7805
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a7805;
    }
    // 004a77e1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a77e2  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 004a77e7  b890f34c00             -mov eax, 0x4cf390
    cpu.eax = 5043088 /*0x4cf390*/;
    // 004a77ec  891ddccc4d00           -mov dword ptr [0x4dccdc], ebx
    app->getMemory<x86::reg32>(x86::reg32(5098716) /* 0x4dccdc */) = cpu.ebx;
    // 004a77f2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a77f4  752f                   -jne 0x4a7825
    if (!cpu.flags.zf)
    {
        goto L_0x004a7825;
    }
L_0x004a77f6:
    // 004a77f6  a3e0cc4d00             -mov dword ptr [0x4dcce0], eax
    app->getMemory<x86::reg32>(x86::reg32(5098720) /* 0x4dcce0 */) = cpu.eax;
    // 004a77fb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a77fc  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a7801  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7802  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x004a7805:
    // 004a7805  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a7807  752a                   -jne 0x4a7833
    if (!cpu.flags.zf)
    {
        goto L_0x004a7833;
    }
    // 004a7809  a3dccc4d00             -mov dword ptr [0x4dccdc], eax
    app->getMemory<x86::reg32>(x86::reg32(5098716) /* 0x4dccdc */) = cpu.eax;
    // 004a780e  b89cf34c00             -mov eax, 0x4cf39c
    cpu.eax = 5043100 /*0x4cf39c*/;
    // 004a7813  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a7815  7515                   -jne 0x4a782c
    if (!cpu.flags.zf)
    {
        goto L_0x004a782c;
    }
L_0x004a7817:
    // 004a7817  a3e0cc4d00             -mov dword ptr [0x4dcce0], eax
    app->getMemory<x86::reg32>(x86::reg32(5098720) /* 0x4dcce0 */) = cpu.eax;
    // 004a781c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a7821  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7822  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x004a7825:
    // 004a7825  b898f34c00             -mov eax, 0x4cf398
    cpu.eax = 5043096 /*0x4cf398*/;
    // 004a782a  ebca                   -jmp 0x4a77f6
    goto L_0x004a77f6;
L_0x004a782c:
    // 004a782c  b898f34c00             -mov eax, 0x4cf398
    cpu.eax = 5043096 /*0x4cf398*/;
    // 004a7831  ebe4                   -jmp 0x4a7817
    goto L_0x004a7817;
L_0x004a7833:
    // 004a7833  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a7835  e8ba47feff             -call 0x48bff4
    cpu.esp -= 4;
    sub_48bff4(app, cpu);
    if (cpu.terminate) return;
    // 004a783a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a783c  752b                   -jne 0x4a7869
    if (!cpu.flags.zf)
    {
        goto L_0x004a7869;
    }
    // 004a783e  833de0cc4d0000         +cmp dword ptr [0x4dcce0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5098720) /* 0x4dcce0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a7845  7529                   -jne 0x4a7870
    if (!cpu.flags.zf)
    {
        goto L_0x004a7870;
    }
    // 004a7847  b890f34c00             -mov eax, 0x4cf390
    cpu.eax = 5043088 /*0x4cf390*/;
    // 004a784c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a784e  752e                   -jne 0x4a787e
    if (!cpu.flags.zf)
    {
        goto L_0x004a787e;
    }
L_0x004a7850:
    // 004a7850  bdffffffff             -mov ebp, 0xffffffff
    cpu.ebp = 4294967295 /*0xffffffff*/;
    // 004a7855  a3e0cc4d00             -mov dword ptr [0x4dcce0], eax
    app->getMemory<x86::reg32>(x86::reg32(5098720) /* 0x4dcce0 */) = cpu.eax;
    // 004a785a  892ddccc4d00           -mov dword ptr [0x4dccdc], ebp
    app->getMemory<x86::reg32>(x86::reg32(5098716) /* 0x4dccdc */) = cpu.ebp;
    // 004a7860  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a7865  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7866  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x004a7869:
    // 004a7869  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004a786b  a3e0cc4d00             -mov dword ptr [0x4dcce0], eax
    app->getMemory<x86::reg32>(x86::reg32(5098720) /* 0x4dcce0 */) = cpu.eax;
L_0x004a7870:
    // 004a7870  a3dccc4d00             -mov dword ptr [0x4dccdc], eax
    app->getMemory<x86::reg32>(x86::reg32(5098716) /* 0x4dccdc */) = cpu.eax;
    // 004a7875  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a787a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a787b  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x004a787e:
    // 004a787e  b898f34c00             -mov eax, 0x4cf398
    cpu.eax = 5043096 /*0x4cf398*/;
    // 004a7883  ebcb                   -jmp 0x4a7850
    goto L_0x004a7850;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a7888(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a7888  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a7889  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a788a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a788b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a788c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a788d  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004a788f  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004a7891  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004a7896  b8a4f34c00             -mov eax, 0x4cf3a4
    cpu.eax = 5043108 /*0x4cf3a4*/;
    // 004a789b  8915dccc4d00           -mov dword ptr [0x4dccdc], edx
    app->getMemory<x86::reg32>(x86::reg32(5098716) /* 0x4dccdc */) = cpu.edx;
    // 004a78a1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a78a3  7530                   -jne 0x4a78d5
    if (!cpu.flags.zf)
    {
        goto L_0x004a78d5;
    }
L_0x004a78a5:
    // 004a78a5  a3e0cc4d00             -mov dword ptr [0x4dcce0], eax
    app->getMemory<x86::reg32>(x86::reg32(5098720) /* 0x4dcce0 */) = cpu.eax;
    // 004a78aa  e87d90fdff             -call 0x48092c
    cpu.esp -= 4;
    sub_48092c(app, cpu);
    if (cpu.terminate) return;
    // 004a78af  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004a78b1  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a78b3  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a78b5  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a78b7  e8948dfdff             -call 0x480650
    cpu.esp -= 4;
    sub_480650(app, cpu);
    if (cpu.terminate) return;
    // 004a78bc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a78be  740a                   -je 0x4a78ca
    if (cpu.flags.zf)
    {
        goto L_0x004a78ca;
    }
    // 004a78c0  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x004a78c2:
    // 004a78c2  3b2ddccc4d00           +cmp ebp, dword ptr [0x4dccdc]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5098716) /* 0x4dccdc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a78c8  7512                   -jne 0x4a78dc
    if (!cpu.flags.zf)
    {
        goto L_0x004a78dc;
    }
L_0x004a78ca:
    // 004a78ca  a1e0cc4d00             -mov eax, dword ptr [0x4dcce0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5098720) /* 0x4dcce0 */);
    // 004a78cf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a78d0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a78d1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a78d2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a78d3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a78d4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a78d5:
    // 004a78d5  b898f34c00             -mov eax, 0x4cf398
    cpu.eax = 5043096 /*0x4cf398*/;
    // 004a78da  ebc9                   -jmp 0x4a78a5
    goto L_0x004a78a5;
L_0x004a78dc:
    // 004a78dc  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a78e1  e82607feff             -call 0x48800c
    cpu.esp -= 4;
    sub_48800c(app, cpu);
    if (cpu.terminate) return;
    // 004a78e6  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004a78e8  e86b07feff             -call 0x488058
    cpu.esp -= 4;
    sub_488058(app, cpu);
    if (cpu.terminate) return;
    // 004a78ed  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a78ef  7407                   -je 0x4a78f8
    if (cpu.flags.zf)
    {
        goto L_0x004a78f8;
    }
    // 004a78f1  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004a78f3  e828aafdff             -call 0x482320
    cpu.esp -= 4;
    sub_482320(app, cpu);
    if (cpu.terminate) return;
L_0x004a78f8:
    // 004a78f8  3b2ddccc4d00           +cmp ebp, dword ptr [0x4dccdc]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5098716) /* 0x4dccdc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a78fe  7ec2                   -jle 0x4a78c2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a78c2;
    }
    // 004a7900  b864000000             -mov eax, 0x64
    cpu.eax = 100 /*0x64*/;
    // 004a7905  e80207feff             -call 0x48800c
    cpu.esp -= 4;
    sub_48800c(app, cpu);
    if (cpu.terminate) return;
    // 004a790a  e869abfdff             -call 0x482478
    cpu.esp -= 4;
    sub_482478(app, cpu);
    if (cpu.terminate) return;
    // 004a790f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a7911  74af                   -je 0x4a78c2
    if (cpu.flags.zf)
    {
        goto L_0x004a78c2;
    }
    // 004a7913  8b15241b5600           -mov edx, dword ptr [0x561b24]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5643044) /* 0x561b24 */);
    // 004a7919  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a791e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a791f  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 004a7921  a3dccc4d00             -mov dword ptr [0x4dccdc], eax
    app->getMemory<x86::reg32>(x86::reg32(5098716) /* 0x4dccdc */) = cpu.eax;
    // 004a7926  2eff15fc434c00         -call dword ptr cs:[0x4c43fc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998140) /* 0x4c43fc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a792d  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004a792f  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004a7931  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a7933  e8188dfdff             -call 0x480650
    cpu.esp -= 4;
    sub_480650(app, cpu);
    if (cpu.terminate) return;
    // 004a7938  eb88                   -jmp 0x4a78c2
    goto L_0x004a78c2;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a793c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a793c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a793d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a793e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a793f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a7941  e81207feff             -call 0x488058
    cpu.esp -= 4;
    sub_488058(app, cpu);
    if (cpu.terminate) return;
    // 004a7946  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a7948  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a794a  7527                   -jne 0x4a7973
    if (!cpu.flags.zf)
    {
        goto L_0x004a7973;
    }
    // 004a794c  8b15bc944d00           -mov edx, dword ptr [0x4d94bc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5084348) /* 0x4d94bc */);
    // 004a7952  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a7954  740d                   -je 0x4a7963
    if (cpu.flags.zf)
    {
        goto L_0x004a7963;
    }
    // 004a7956  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a7958  e85b0afeff             -call 0x4883b8
    cpu.esp -= 4;
    sub_4883b8(app, cpu);
    if (cpu.terminate) return;
    // 004a795d  8b1dbc944d00           -mov ebx, dword ptr [0x4d94bc]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5084348) /* 0x4d94bc */);
L_0x004a7963:
    // 004a7963  8b0d241b5600           -mov ecx, dword ptr [0x561b24]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5643044) /* 0x561b24 */);
    // 004a7969  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004a796b  751b                   -jne 0x4a7988
    if (!cpu.flags.zf)
    {
        goto L_0x004a7988;
    }
    // 004a796d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a796f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7970  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7971  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7972  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a7973:
    // 004a7973  e8b48ffdff             -call 0x48092c
    cpu.esp -= 4;
    sub_48092c(app, cpu);
    if (cpu.terminate) return;
    // 004a7978  8b0d241b5600           -mov ecx, dword ptr [0x561b24]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5643044) /* 0x561b24 */);
    // 004a797e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004a7980  7506                   -jne 0x4a7988
    if (!cpu.flags.zf)
    {
        goto L_0x004a7988;
    }
    // 004a7982  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a7984  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7985  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7986  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7987  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a7988:
    // 004a7988  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a798a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a798b  2eff150c444c00         -call dword ptr cs:[0x4c440c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998156) /* 0x4c440c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a7992  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a7994  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7995  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7996  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7997  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a7998(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a7998  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a7999  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a799a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a799b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a799c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a799d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a799e  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004a79a1  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004a79a3  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a79a5  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
L_0x004a79a9:
    // 004a79a9  80bf5d04000000         +cmp byte ptr [edi + 0x45d], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1117) /* 0x45d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a79b0  0f8413010000           -je 0x4a7ac9
    if (cpu.flags.zf)
    {
        goto L_0x004a7ac9;
    }
    // 004a79b6  8b4718                 -mov eax, dword ptr [edi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    // 004a79b9  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a79bd  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004a79c1  8b471c                 -mov eax, dword ptr [edi + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */);
    // 004a79c4  8b5f14                 -mov ebx, dword ptr [edi + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */);
    // 004a79c7  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004a79ca  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004a79cc  0f8579000000           -jne 0x4a7a4b
    if (!cpu.flags.zf)
    {
        goto L_0x004a7a4b;
    }
L_0x004a79d2:
    // 004a79d2  bea0860100             -mov esi, 0x186a0
    cpu.esi = 100000 /*0x186a0*/;
    // 004a79d7  8b6f08                 -mov ebp, dword ptr [edi + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 004a79da  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a79dc  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004a79de  7e37                   -jle 0x4a7a17
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a7a17;
    }
    // 004a79e0  8b4710                 -mov eax, dword ptr [edi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */);
L_0x004a79e3:
    // 004a79e3  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a79e5  8a4812                 -mov cl, byte ptr [eax + 0x12]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(18) /* 0x12 */);
    // 004a79e8  3b0c24                 +cmp ecx, dword ptr [esp]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a79eb  751f                   -jne 0x4a7a0c
    if (!cpu.flags.zf)
    {
        goto L_0x004a7a0c;
    }
    // 004a79ed  f6400f80               +test byte ptr [eax + 0xf], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(15) /* 0xf */) & 128 /*0x80*/));
    // 004a79f1  7519                   -jne 0x4a7a0c
    if (!cpu.flags.zf)
    {
        goto L_0x004a7a0c;
    }
    // 004a79f3  3b18                   +cmp ebx, dword ptr [eax]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a79f5  7715                   -ja 0x4a7a0c
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004a7a0c;
    }
    // 004a79f7  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a79fb  3b4804                 +cmp ecx, dword ptr [eax + 4]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a79fe  770c                   -ja 0x4a7a0c
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004a7a0c;
    }
    // 004a7a00  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004a7a02  29d9                   -sub ecx, ebx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a7a04  39f1                   +cmp ecx, esi
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
    // 004a7a06  7304                   -jae 0x4a7a0c
    if (!cpu.flags.cf)
    {
        goto L_0x004a7a0c;
    }
    // 004a7a08  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004a7a0a  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
L_0x004a7a0c:
    // 004a7a0c  42                     -inc edx
    (cpu.edx)++;
    // 004a7a0d  8b4f08                 -mov ecx, dword ptr [edi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 004a7a10  83c014                 -add eax, 0x14
    (cpu.eax) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004a7a13  39ca                   +cmp edx, ecx
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
    // 004a7a15  7ccc                   -jl 0x4a79e3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a79e3;
    }
L_0x004a7a17:
    // 004a7a17  3b6f08                 +cmp ebp, dword ptr [edi + 8]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a7a1a  7d4f                   -jge 0x4a7a6b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a7a6b;
    }
    // 004a7a1c  b865040000             -mov eax, 0x465
    cpu.eax = 1125 /*0x465*/;
    // 004a7a21  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004a7a23  e860feffff             -call 0x4a7888
    cpu.esp -= 4;
    sub_4a7888(app, cpu);
    if (cpu.terminate) return;
    // 004a7a28  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a7a2a  753b                   -jne 0x4a7a67
    if (!cpu.flags.zf)
    {
        goto L_0x004a7a67;
    }
    // 004a7a2c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004a7a31:
    // 004a7a31  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004a7a35  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a7a37  750b                   -jne 0x4a7a44
    if (!cpu.flags.zf)
    {
        goto L_0x004a7a44;
    }
    // 004a7a39  6bed14                 -imul ebp, ebp, 0x14
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(20 /*0x14*/)));
    // 004a7a3c  8b4710                 -mov eax, dword ptr [edi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 004a7a3f  804c280f80             -or byte ptr [eax + ebp + 0xf], 0x80
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(15) /* 0xf */ + cpu.ebp * 1) |= x86::reg8(x86::sreg8(128 /*0x80*/));
L_0x004a7a44:
    // 004a7a44  837c240400             +cmp dword ptr [esp + 4], 0
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
    // 004a7a49  7487                   -je 0x4a79d2
    if (cpu.flags.zf)
    {
        goto L_0x004a79d2;
    }
L_0x004a7a4b:
    // 004a7a4b  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a7a4f  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a7a51  7406                   -je 0x4a7a59
    if (cpu.flags.zf)
    {
        goto L_0x004a7a59;
    }
    // 004a7a53  0f8450ffffff           -je 0x4a79a9
    if (cpu.flags.zf)
    {
        goto L_0x004a79a9;
    }
L_0x004a7a59:
    // 004a7a59  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a7a5d  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004a7a60  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7a61  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7a62  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7a63  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7a64  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7a65  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7a66  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a7a67:
    // 004a7a67  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004a7a69  ebc6                   -jmp 0x4a7a31
    goto L_0x004a7a31;
L_0x004a7a6b:
    // 004a7a6b  81fb40010000           +cmp ebx, 0x140
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(320 /*0x140*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a7a71  7616                   -jbe 0x4a7a89
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a7a89;
    }
    // 004a7a73  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a7a77  81eac8000000           -sub edx, 0xc8
    (cpu.edx) -= x86::reg32(x86::sreg32(200 /*0xc8*/));
    // 004a7a7d  81ebc8000000           +sub ebx, 0xc8
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(200 /*0xc8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a7a83  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004a7a87  ebbb                   -jmp 0x4a7a44
    goto L_0x004a7a44;
L_0x004a7a89:
    // 004a7a89  833c2408               +cmp dword ptr [esp], 8
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a7a8d  7414                   -je 0x4a7aa3
    if (cpu.flags.zf)
    {
        goto L_0x004a7aa3;
    }
    // 004a7a8f  8b4718                 -mov eax, dword ptr [edi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    // 004a7a92  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004a7a96  b808000000             -mov eax, 8
    cpu.eax = 8 /*0x8*/;
    // 004a7a9b  8b5f14                 -mov ebx, dword ptr [edi + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */);
    // 004a7a9e  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004a7aa1  eba1                   -jmp 0x4a7a44
    goto L_0x004a7a44;
L_0x004a7aa3:
    // 004a7aa3  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 004a7aa8  b865040000             -mov eax, 0x465
    cpu.eax = 1125 /*0x465*/;
    // 004a7aad  e8d6fdffff             -call 0x4a7888
    cpu.esp -= 4;
    sub_4a7888(app, cpu);
    if (cpu.terminate) return;
    // 004a7ab2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a7ab4  750b                   -jne 0x4a7ac1
    if (!cpu.flags.zf)
    {
        goto L_0x004a7ac1;
    }
    // 004a7ab6  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a7abb  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004a7abf  eb8a                   -jmp 0x4a7a4b
    goto L_0x004a7a4b;
L_0x004a7ac1:
    // 004a7ac1  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004a7ac3  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004a7ac7  eb82                   -jmp 0x4a7a4b
    goto L_0x004a7a4b;
L_0x004a7ac9:
    // 004a7ac9  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 004a7ace  b865040000             -mov eax, 0x465
    cpu.eax = 1125 /*0x465*/;
    // 004a7ad3  e8b0fdffff             -call 0x4a7888
    cpu.esp -= 4;
    sub_4a7888(app, cpu);
    if (cpu.terminate) return;
    // 004a7ad8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a7ada  750e                   -jne 0x4a7aea
    if (!cpu.flags.zf)
    {
        goto L_0x004a7aea;
    }
    // 004a7adc  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a7ae1  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004a7ae5  e961ffffff             -jmp 0x4a7a4b
    goto L_0x004a7a4b;
L_0x004a7aea:
    // 004a7aea  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004a7aec  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004a7af0  e956ffffff             -jmp 0x4a7a4b
    goto L_0x004a7a4b;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a7af8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a7af8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a7af9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a7afa  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a7afb  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a7afd  8a25a4894d00           -mov ah, byte ptr [0x4d89a4]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5081508) /* 0x4d89a4 */);
    // 004a7b03  8a152d1b5600           -mov dl, byte ptr [0x561b2d]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5643053) /* 0x561b2d */);
    // 004a7b09  f6c401                 +test ah, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 1 /*0x1*/));
    // 004a7b0c  0f8499000000           -je 0x4a7bab
    if (cpu.flags.zf)
    {
        goto L_0x004a7bab;
    }
    // 004a7b12  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
L_0x004a7b14:
    // 004a7b14  8a1da4894d00           -mov bl, byte ptr [0x4d89a4]
    cpu.bl = app->getMemory<x86::reg8>(x86::reg32(5081508) /* 0x4d89a4 */);
    // 004a7b1a  a22d1b5600             -mov byte ptr [0x561b2d], al
    app->getMemory<x86::reg8>(x86::reg32(5643053) /* 0x561b2d */) = cpu.al;
    // 004a7b1f  f6c310                 +test bl, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 16 /*0x10*/));
    // 004a7b22  0f848a000000           -je 0x4a7bb2
    if (cpu.flags.zf)
    {
        goto L_0x004a7bb2;
    }
    // 004a7b28  b401                   -mov ah, 1
    cpu.ah = 1 /*0x1*/;
    // 004a7b2a  30c9                   -xor cl, cl
    cpu.cl ^= x86::reg8(x86::sreg8(cpu.cl));
    // 004a7b2c  b302                   -mov bl, 2
    cpu.bl = 2 /*0x2*/;
    // 004a7b2e  880d061b5600           -mov byte ptr [0x561b06], cl
    app->getMemory<x86::reg8>(x86::reg32(5643014) /* 0x561b06 */) = cpu.cl;
    // 004a7b34  880d051b5600           -mov byte ptr [0x561b05], cl
    app->getMemory<x86::reg8>(x86::reg32(5643013) /* 0x561b05 */) = cpu.cl;
    // 004a7b3a  880d041b5600           -mov byte ptr [0x561b04], cl
    app->getMemory<x86::reg8>(x86::reg32(5643012) /* 0x561b04 */) = cpu.cl;
    // 004a7b40  88252e1b5600           -mov byte ptr [0x561b2e], ah
    app->getMemory<x86::reg8>(x86::reg32(5643054) /* 0x561b2e */) = cpu.ah;
    // 004a7b46  881d071b5600           -mov byte ptr [0x561b07], bl
    app->getMemory<x86::reg8>(x86::reg32(5643015) /* 0x561b07 */) = cpu.bl;
    // 004a7b4c  881d331b5600           -mov byte ptr [0x561b33], bl
    app->getMemory<x86::reg8>(x86::reg32(5643059) /* 0x561b33 */) = cpu.bl;
L_0x004a7b52:
    // 004a7b52  a1048a4d00             -mov eax, dword ptr [0x4d8a04]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5081604) /* 0x4d8a04 */);
    // 004a7b57  8b0d78894d00           -mov ecx, dword ptr [0x4d8978]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5081464) /* 0x4d8978 */);
    // 004a7b5d  a3f0165600             -mov dword ptr [0x5616f0], eax
    app->getMemory<x86::reg32>(x86::reg32(5641968) /* 0x5616f0 */) = cpu.eax;
    // 004a7b62  83f907                 +cmp ecx, 7
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
    // 004a7b65  7427                   -je 0x4a7b8e
    if (cpu.flags.zf)
    {
        goto L_0x004a7b8e;
    }
    // 004a7b67  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a7b68  e8c3e4feff             -call 0x496030
    cpu.esp -= 4;
    sub_496030(app, cpu);
    if (cpu.terminate) return;
    // 004a7b6d  b8f07d4a00             -mov eax, 0x4a7df0
    cpu.eax = 4881904 /*0x4a7df0*/;
    // 004a7b72  bb07000000             -mov ebx, 7
    cpu.ebx = 7 /*0x7*/;
    // 004a7b77  be3c794a00             -mov esi, 0x4a793c
    cpu.esi = 4880700 /*0x4a793c*/;
    // 004a7b7c  e85fe1feff             -call 0x495ce0
    cpu.esp -= 4;
    sub_495ce0(app, cpu);
    if (cpu.terminate) return;
    // 004a7b81  891d78894d00           -mov dword ptr [0x4d8978], ebx
    app->getMemory<x86::reg32>(x86::reg32(5081464) /* 0x4d8978 */) = cpu.ebx;
    // 004a7b87  8935208a4d00           -mov dword ptr [0x4d8a20], esi
    app->getMemory<x86::reg32>(x86::reg32(5081632) /* 0x4d8a20 */) = cpu.esi;
    // 004a7b8d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004a7b8e:
    // 004a7b8e  e8998dfdff             -call 0x48092c
    cpu.esp -= 4;
    sub_48092c(app, cpu);
    if (cpu.terminate) return;
    // 004a7b93  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a7b95  a02d1b5600             -mov al, byte ptr [0x561b2d]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5643053) /* 0x561b2d */);
    // 004a7b9a  39c2                   +cmp edx, eax
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
    // 004a7b9c  0f8485000000           -je 0x4a7c27
    if (cpu.flags.zf)
    {
        goto L_0x004a7c27;
    }
    // 004a7ba2  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a7ba7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7ba8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7ba9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7baa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a7bab:
    // 004a7bab  30c0                   +xor al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al ^= x86::reg8(x86::sreg8(cpu.al))));
    // 004a7bad  e962ffffff             -jmp 0x4a7b14
    goto L_0x004a7b14;
L_0x004a7bb2:
    // 004a7bb2  f6c308                 +test bl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 8 /*0x8*/));
    // 004a7bb5  7451                   -je 0x4a7c08
    if (cpu.flags.zf)
    {
        goto L_0x004a7c08;
    }
    // 004a7bb7  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
L_0x004a7bb9:
    // 004a7bb9  8a0da4894d00           -mov cl, byte ptr [0x4d89a4]
    cpu.cl = app->getMemory<x86::reg8>(x86::reg32(5081508) /* 0x4d89a4 */);
    // 004a7bbf  a2061b5600             -mov byte ptr [0x561b06], al
    app->getMemory<x86::reg8>(x86::reg32(5643014) /* 0x561b06 */) = cpu.al;
    // 004a7bc4  f6c102                 +test cl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 2 /*0x2*/));
    // 004a7bc7  7443                   -je 0x4a7c0c
    if (cpu.flags.zf)
    {
        goto L_0x004a7c0c;
    }
    // 004a7bc9  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
L_0x004a7bcb:
    // 004a7bcb  8a2da4894d00           -mov ch, byte ptr [0x4d89a4]
    cpu.ch = app->getMemory<x86::reg8>(x86::reg32(5081508) /* 0x4d89a4 */);
    // 004a7bd1  a2051b5600             -mov byte ptr [0x561b05], al
    app->getMemory<x86::reg8>(x86::reg32(5643013) /* 0x561b05 */) = cpu.al;
    // 004a7bd6  f6c504                 +test ch, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 4 /*0x4*/));
    // 004a7bd9  7435                   -je 0x4a7c10
    if (cpu.flags.zf)
    {
        goto L_0x004a7c10;
    }
    // 004a7bdb  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
L_0x004a7bdd:
    // 004a7bdd  a2041b5600             -mov byte ptr [0x561b04], al
    app->getMemory<x86::reg8>(x86::reg32(5643012) /* 0x561b04 */) = cpu.al;
    // 004a7be2  30c0                   -xor al, al
    cpu.al ^= x86::reg8(x86::sreg8(cpu.al));
    // 004a7be4  a22e1b5600             -mov byte ptr [0x561b2e], al
    app->getMemory<x86::reg8>(x86::reg32(5643054) /* 0x561b2e */) = cpu.al;
    // 004a7be9  a0a8894d00             -mov al, byte ptr [0x4d89a8]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5081512) /* 0x4d89a8 */);
    // 004a7bee  a2071b5600             -mov byte ptr [0x561b07], al
    app->getMemory<x86::reg8>(x86::reg32(5643015) /* 0x561b07 */) = cpu.al;
    // 004a7bf3  f605a4894d0040         +test byte ptr [0x4d89a4], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5081508) /* 0x4d89a4 */) & 64 /*0x40*/));
    // 004a7bfa  7418                   -je 0x4a7c14
    if (cpu.flags.zf)
    {
        goto L_0x004a7c14;
    }
L_0x004a7bfc:
    // 004a7bfc  c605331b560001         -mov byte ptr [0x561b33], 1
    app->getMemory<x86::reg8>(x86::reg32(5643059) /* 0x561b33 */) = 1 /*0x1*/;
    // 004a7c03  e94affffff             -jmp 0x4a7b52
    goto L_0x004a7b52;
L_0x004a7c08:
    // 004a7c08  30c0                   +xor al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al ^= x86::reg8(x86::sreg8(cpu.al))));
    // 004a7c0a  ebad                   -jmp 0x4a7bb9
    goto L_0x004a7bb9;
L_0x004a7c0c:
    // 004a7c0c  30c0                   +xor al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al ^= x86::reg8(x86::sreg8(cpu.al))));
    // 004a7c0e  ebbb                   -jmp 0x4a7bcb
    goto L_0x004a7bcb;
L_0x004a7c10:
    // 004a7c10  30c0                   +xor al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al ^= x86::reg8(x86::sreg8(cpu.al))));
    // 004a7c12  ebc9                   -jmp 0x4a7bdd
    goto L_0x004a7bdd;
L_0x004a7c14:
    // 004a7c14  803d061b560000         +cmp byte ptr [0x561b06], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5643014) /* 0x561b06 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a7c1b  75df                   -jne 0x4a7bfc
    if (!cpu.flags.zf)
    {
        goto L_0x004a7bfc;
    }
    // 004a7c1d  a2331b5600             -mov byte ptr [0x561b33], al
    app->getMemory<x86::reg8>(x86::reg32(5643059) /* 0x561b33 */) = cpu.al;
    // 004a7c22  e92bffffff             -jmp 0x4a7b52
    goto L_0x004a7b52;
L_0x004a7c27:
    // 004a7c27  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a7c29  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7c2a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7c2b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7c2c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a7c30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a7c30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a7c31  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a7c32  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a7c33  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a7c35  a02c1b5600             -mov al, byte ptr [0x561b2c]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5643052) /* 0x561b2c */);
    // 004a7c3a  8b151c1b5600           -mov edx, dword ptr [0x561b1c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5643036) /* 0x561b1c */);
    // 004a7c40  a3a0894d00             -mov dword ptr [0x4d89a0], eax
    app->getMemory<x86::reg32>(x86::reg32(5081504) /* 0x4d89a0 */) = cpu.eax;
    // 004a7c45  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a7c47  7405                   -je 0x4a7c4e
    if (cpu.flags.zf)
    {
        goto L_0x004a7c4e;
    }
    // 004a7c49  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x004a7c4e:
    // 004a7c4e  833d201b560000         +cmp dword ptr [0x561b20], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5643040) /* 0x561b20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a7c55  7470                   -je 0x4a7cc7
    if (cpu.flags.zf)
    {
        goto L_0x004a7cc7;
    }
    // 004a7c57  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004a7c5c:
    // 004a7c5c  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a7c5e  a1e4165600             -mov eax, dword ptr [0x5616e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5641956) /* 0x5616e4 */);
    // 004a7c63  a398894d00             -mov dword ptr [0x4d8998], eax
    app->getMemory<x86::reg32>(x86::reg32(5081496) /* 0x4d8998 */) = cpu.eax;
    // 004a7c68  a1e8165600             -mov eax, dword ptr [0x5616e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5641960) /* 0x5616e8 */);
    // 004a7c6d  a39c894d00             -mov dword ptr [0x4d899c], eax
    app->getMemory<x86::reg32>(x86::reg32(5081500) /* 0x4d899c */) = cpu.eax;
    // 004a7c72  a1dc165600             -mov eax, dword ptr [0x5616dc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5641948) /* 0x5616dc */);
    // 004a7c77  8b1db0894d00           -mov ebx, dword ptr [0x4d89b0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5081520) /* 0x4d89b0 */);
    // 004a7c7d  a3ac894d00             -mov dword ptr [0x4d89ac], eax
    app->getMemory<x86::reg32>(x86::reg32(5081516) /* 0x4d89ac */) = cpu.eax;
    // 004a7c82  a198894d00             -mov eax, dword ptr [0x4d8998]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5081496) /* 0x4d8998 */);
    // 004a7c87  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a7c89  8b35b4894d00           -mov esi, dword ptr [0x4d89b4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5081524) /* 0x4d89b4 */);
    // 004a7c8f  a3b8894d00             -mov dword ptr [0x4d89b8], eax
    app->getMemory<x86::reg32>(x86::reg32(5081528) /* 0x4d89b8 */) = cpu.eax;
    // 004a7c94  a19c894d00             -mov eax, dword ptr [0x4d899c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5081500) /* 0x4d899c */);
    // 004a7c99  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004a7c9b  a3bc894d00             -mov dword ptr [0x4d89bc], eax
    app->getMemory<x86::reg32>(x86::reg32(5081532) /* 0x4d89bc */) = cpu.eax;
    // 004a7ca0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a7ca2  a0331b5600             -mov al, byte ptr [0x561b33]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5643059) /* 0x561b33 */);
    // 004a7ca7  a3d4cc4d00             -mov dword ptr [0x4dccd4], eax
    app->getMemory<x86::reg32>(x86::reg32(5098708) /* 0x4dccd4 */) = cpu.eax;
    // 004a7cac  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a7cae  a0321b5600             -mov al, byte ptr [0x561b32]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5643058) /* 0x561b32 */);
    // 004a7cb3  8915a8894d00           -mov dword ptr [0x4d89a8], edx
    app->getMemory<x86::reg32>(x86::reg32(5081512) /* 0x4d89a8 */) = cpu.edx;
    // 004a7cb9  a3d8cc4d00             -mov dword ptr [0x4dccd8], eax
    app->getMemory<x86::reg32>(x86::reg32(5098712) /* 0x4dccd8 */) = cpu.eax;
    // 004a7cbe  e8698cfdff             -call 0x48092c
    cpu.esp -= 4;
    sub_48092c(app, cpu);
    if (cpu.terminate) return;
    // 004a7cc3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7cc4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7cc5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7cc6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a7cc7:
    // 004a7cc7  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004a7cc9  eb91                   -jmp 0x4a7c5c
    goto L_0x004a7c5c;
}

/* align: skip 0x90 */
void Application::sub_4a7ccc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a7ccc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a7ccd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a7cce  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a7ccf  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a7cd0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a7cd1  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a7cd3  8b15d0165600           -mov edx, dword ptr [0x5616d0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5641936) /* 0x5616d0 */);
    // 004a7cd9  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004a7cdb  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a7cdd  0f85c7000000           -jne 0x4a7daa
    if (!cpu.flags.zf)
    {
        goto L_0x004a7daa;
    }
    // 004a7ce3  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004a7ce8:
    // 004a7ce8  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004a7cea  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a7cec  0f84bf000000           -je 0x4a7db1
    if (cpu.flags.zf)
    {
        goto L_0x004a7db1;
    }
L_0x004a7cf2:
    // 004a7cf2  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004a7cf7:
    // 004a7cf7  6800774a00             -push 0x4a7700
    app->getMemory<x86::reg32>(cpu.esp-4) = 4880128 /*0x4a7700*/;
    cpu.esp -= 4;
    // 004a7cfc  6864040000             -push 0x464
    app->getMemory<x86::reg32>(cpu.esp-4) = 1124 /*0x464*/;
    cpu.esp -= 4;
    // 004a7d01  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a7d03  e8d889fdff             -call 0x4806e0
    cpu.esp -= 4;
    sub_4806e0(app, cpu);
    if (cpu.terminate) return;
    // 004a7d08  6894774a00             -push 0x4a7794
    app->getMemory<x86::reg32>(cpu.esp-4) = 4880276 /*0x4a7794*/;
    cpu.esp -= 4;
    // 004a7d0d  6865040000             -push 0x465
    app->getMemory<x86::reg32>(cpu.esp-4) = 1125 /*0x465*/;
    cpu.esp -= 4;
    // 004a7d12  e8c989fdff             -call 0x4806e0
    cpu.esp -= 4;
    sub_4806e0(app, cpu);
    if (cpu.terminate) return;
    // 004a7d17  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a7d19  742f                   -je 0x4a7d4a
    if (cpu.flags.zf)
    {
        goto L_0x004a7d4a;
    }
    // 004a7d1b  803d2d1b560000         +cmp byte ptr [0x561b2d], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5643053) /* 0x561b2d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a7d22  7426                   -je 0x4a7d4a
    if (cpu.flags.zf)
    {
        goto L_0x004a7d4a;
    }
    // 004a7d24  833de416560000         +cmp dword ptr [0x5616e4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5641956) /* 0x5616e4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a7d2b  750a                   -jne 0x4a7d37
    if (!cpu.flags.zf)
    {
        goto L_0x004a7d37;
    }
    // 004a7d2d  c705e416560080020000   -mov dword ptr [0x5616e4], 0x280
    app->getMemory<x86::reg32>(x86::reg32(5641956) /* 0x5616e4 */) = 640 /*0x280*/;
L_0x004a7d37:
    // 004a7d37  833de816560000         +cmp dword ptr [0x5616e8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5641960) /* 0x5616e8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a7d3e  750a                   -jne 0x4a7d4a
    if (!cpu.flags.zf)
    {
        goto L_0x004a7d4a;
    }
    // 004a7d40  c705e8165600e0010000   -mov dword ptr [0x5616e8], 0x1e0
    app->getMemory<x86::reg32>(x86::reg32(5641960) /* 0x5616e8 */) = 480 /*0x1e0*/;
L_0x004a7d4a:
    // 004a7d4a  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a7d4c  7438                   -je 0x4a7d86
    if (cpu.flags.zf)
    {
        goto L_0x004a7d86;
    }
    // 004a7d4e  8b15e8165600           -mov edx, dword ptr [0x5616e8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5641960) /* 0x5616e8 */);
    // 004a7d54  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a7d56  a1e4165600             -mov eax, dword ptr [0x5616e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5641956) /* 0x5616e4 */);
    // 004a7d5b  8a1d2d1b5600           -mov bl, byte ptr [0x561b2d]
    cpu.bl = app->getMemory<x86::reg8>(x86::reg32(5643053) /* 0x561b2d */);
    // 004a7d61  e86a73fdff             -call 0x47f0d0
    cpu.esp -= 4;
    sub_47f0d0(app, cpu);
    if (cpu.terminate) return;
    // 004a7d66  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a7d68  7454                   -je 0x4a7dbe
    if (cpu.flags.zf)
    {
        goto L_0x004a7dbe;
    }
    // 004a7d6a  b864040000             -mov eax, 0x464
    cpu.eax = 1124 /*0x464*/;
    // 004a7d6f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a7d71  e812fbffff             -call 0x4a7888
    cpu.esp -= 4;
    sub_4a7888(app, cpu);
    if (cpu.terminate) return;
    // 004a7d76  8b0d241b5600           -mov ecx, dword ptr [0x561b24]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5643044) /* 0x561b24 */);
    // 004a7d7c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a7d7d  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a7d7f  2eff15fc434c00         -call dword ptr cs:[0x4c43fc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998140) /* 0x4c43fc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004a7d86:
    // 004a7d86  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a7d88  7411                   -je 0x4a7d9b
    if (cpu.flags.zf)
    {
        goto L_0x004a7d9b;
    }
    // 004a7d8a  bb40ce4d00             -mov ebx, 0x4dce40
    cpu.ebx = 5099072 /*0x4dce40*/;
    // 004a7d8f  ba00010000             -mov edx, 0x100
    cpu.edx = 256 /*0x100*/;
    // 004a7d94  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a7d96  e8bd40ffff             -call 0x49be58
    cpu.esp -= 4;
    sub_49be58(app, cpu);
    if (cpu.terminate) return;
L_0x004a7d9b:
    // 004a7d9b  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a7d9d  7526                   -jne 0x4a7dc5
    if (!cpu.flags.zf)
    {
        goto L_0x004a7dc5;
    }
    // 004a7d9f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a7da4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7da5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7da6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7da7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7da8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7da9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a7daa:
    // 004a7daa  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004a7dac  e937ffffff             -jmp 0x4a7ce8
    goto L_0x004a7ce8;
L_0x004a7db1:
    // 004a7db1  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a7db3  0f8539ffffff           -jne 0x4a7cf2
    if (!cpu.flags.zf)
    {
        goto L_0x004a7cf2;
    }
    // 004a7db9  e939ffffff             -jmp 0x4a7cf7
    goto L_0x004a7cf7;
L_0x004a7dbe:
    // 004a7dbe  be20f44c00             -mov esi, 0x4cf420
    cpu.esi = 5043232 /*0x4cf420*/;
    // 004a7dc3  ebc1                   -jmp 0x4a7d86
    goto L_0x004a7d86;
L_0x004a7dc5:
    // 004a7dc5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a7dc7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7dc8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7dc9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7dca  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7dcb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7dcc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a7dd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a7dd0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a7dd1  8b15dc165600           -mov edx, dword ptr [0x5616dc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5641948) /* 0x5616dc */);
    // 004a7dd7  e83472fdff             -call 0x47f010
    cpu.esp -= 4;
    sub_47f010(app, cpu);
    if (cpu.terminate) return;
    // 004a7ddc  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a7dde  e835040000             -call 0x4a8218
    cpu.esp -= 4;
    sub_4a8218(app, cpu);
    if (cpu.terminate) return;
    // 004a7de3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7de4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a7de8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a7de8  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a7ded  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a7df0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a7df0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a7df1  e8368bfdff             -call 0x48092c
    cpu.esp -= 4;
    sub_48092c(app, cpu);
    if (cpu.terminate) return;
    // 004a7df6  833d60b54d0000         +cmp dword ptr [0x4db560], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5092704) /* 0x4db560 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a7dfd  7544                   -jne 0x4a7e43
    if (!cpu.flags.zf)
    {
        goto L_0x004a7e43;
    }
    // 004a7dff  833d241b560000         +cmp dword ptr [0x561b24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5643044) /* 0x561b24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a7e06  7543                   -jne 0x4a7e4b
    if (!cpu.flags.zf)
    {
        goto L_0x004a7e4b;
    }
L_0x004a7e08:
    // 004a7e08  833d78894d0007         +cmp dword ptr [0x4d8978], 7
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5081464) /* 0x4d8978 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a7e0f  7530                   -jne 0x4a7e41
    if (!cpu.flags.zf)
    {
        goto L_0x004a7e41;
    }
    // 004a7e11  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a7e12  8b35008a4d00           -mov esi, dword ptr [0x4d8a00]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5081600) /* 0x4d8a00 */);
    // 004a7e18  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a7e1a  7411                   -je 0x4a7e2d
    if (cpu.flags.zf)
    {
        goto L_0x004a7e2d;
    }
    // 004a7e1c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a7e1d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a7e1f  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004a7e21  e8ea93fdff             -call 0x481210
    cpu.esp -= 4;
    sub_481210(app, cpu);
    if (cpu.terminate) return;
    // 004a7e26  893d008a4d00           -mov dword ptr [0x4d8a00], edi
    app->getMemory<x86::reg32>(x86::reg32(5081600) /* 0x4d8a00 */) = cpu.edi;
    // 004a7e2c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004a7e2d:
    // 004a7e2d  31ed                   +xor ebp, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp))));
    // 004a7e2f  e854e2feff             -call 0x496088
    cpu.esp -= 4;
    sub_496088(app, cpu);
    if (cpu.terminate) return;
    // 004a7e34  892d78894d00           -mov dword ptr [0x4d8978], ebp
    app->getMemory<x86::reg32>(x86::reg32(5081464) /* 0x4d8978 */) = cpu.ebp;
    // 004a7e3a  892d208a4d00           -mov dword ptr [0x4d8a20], ebp
    app->getMemory<x86::reg32>(x86::reg32(5081632) /* 0x4d8a20 */) = cpu.ebp;
    // 004a7e40  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004a7e41:
    // 004a7e41  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7e42  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a7e43:
    // 004a7e43  ff1560b54d00           -call dword ptr [0x4db560]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5092704) /* 0x4db560 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a7e49  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a7e4a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a7e4b:
    // 004a7e4b  e8c071fdff             -call 0x47f010
    cpu.esp -= 4;
    sub_47f010(app, cpu);
    if (cpu.terminate) return;
    // 004a7e50  ebb6                   -jmp 0x4a7e08
    goto L_0x004a7e08;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a7e54(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a7e54  833dd016560000         +cmp dword ptr [0x5616d0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5641936) /* 0x5616d0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a7e5b  7406                   -je 0x4a7e63
    if (cpu.flags.zf)
    {
        goto L_0x004a7e63;
    }
    // 004a7e5d  a1d8165600             -mov eax, dword ptr [0x5616d8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5641944) /* 0x5616d8 */);
    // 004a7e62  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a7e63:
    // 004a7e63  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004a7e68  e8ab030000             -call 0x4a8218
    cpu.esp -= 4;
    sub_4a8218(app, cpu);
    if (cpu.terminate) return;
    // 004a7e6d  a1d8165600             -mov eax, dword ptr [0x5616d8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5641944) /* 0x5616d8 */);
    // 004a7e72  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a7e74(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a7e74  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a7e75  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a7e76  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a7e77  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a7e78  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a7e7a  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a7e7c  833dd016560000         +cmp dword ptr [0x5616d0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5641936) /* 0x5616d0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a7e83  750a                   -jne 0x4a7e8f
    if (!cpu.flags.zf)
    {
        goto L_0x004a7e8f;
    }
    // 004a7e85  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004a7e8a  e889030000             -call 0x4a8218
    cpu.esp -= 4;
    sub_4a8218(app, cpu);
    if (cpu.terminate) return;
L_0x004a7e8f:
    // 004a7e8f  ba14000000             -mov edx, 0x14
    cpu.edx = 20 /*0x14*/;
    // 004a7e94  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a7e96  e8f105feff             -call 0x48848c
    cpu.esp -= 4;
    sub_48848c(app, cpu);
    if (cpu.terminate) return;
    // 004a7e9b  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a7e9d  0f8cbe020000           -jl 0x4a8161
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a8161;
    }
    // 004a7ea3  3b1dd8165600           +cmp ebx, dword ptr [0x5616d8]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5641944) /* 0x5616d8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a7ea9  0f8db2020000           -jge 0x4a8161
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a8161;
    }
    // 004a7eaf  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a7eb0  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 004a7eb7  8d1403                 -lea edx, [ebx + eax]
    cpu.edx = x86::reg32(cpu.ebx + cpu.eax * 1);
    // 004a7eba  a1e0165600             -mov eax, dword ptr [0x5616e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5641952) /* 0x5616e0 */);
    // 004a7ebf  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 004a7ec2  8b3402                 -mov esi, dword ptr [edx + eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 1);
    // 004a7ec5  8931                   -mov dword ptr [ecx], esi
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.esi;
    // 004a7ec7  8b740204               -mov esi, dword ptr [edx + eax + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */ + cpu.eax * 1);
    // 004a7ecb  897104                 -mov dword ptr [ecx + 4], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 004a7ece  0fb6740213             -movzx esi, byte ptr [edx + eax + 0x13]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(19) /* 0x13 */ + cpu.eax * 1));
    // 004a7ed3  897108                 -mov dword ptr [ecx + 8], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 004a7ed6  8a440212               -mov al, byte ptr [edx + eax + 0x12]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(18) /* 0x12 */ + cpu.eax * 1);
    // 004a7eda  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a7edf  e85c080000             -call 0x4a8740
    cpu.esp -= 4;
    sub_4a8740(app, cpu);
    if (cpu.terminate) return;
    // 004a7ee4  89410c                 -mov dword ptr [ecx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004a7ee7  a1e0165600             -mov eax, dword ptr [0x5616e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5641952) /* 0x5616e0 */);
    // 004a7eec  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a7eee  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004a7ef1  f6420c08               +test byte ptr [edx + 0xc], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) & 8 /*0x8*/));
    // 004a7ef5  0f841c020000           -je 0x4a8117
    if (cpu.flags.zf)
    {
        goto L_0x004a8117;
    }
    // 004a7efb  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x004a7f00:
    // 004a7f00  8020fd                 -and byte ptr [eax], 0xfd
    app->getMemory<x86::reg8>(cpu.eax) &= x86::reg8(x86::sreg8(253 /*0xfd*/));
    // 004a7f03  83e201                 -and edx, 1
    cpu.edx &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 004a7f06  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 004a7f08  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a7f0a  09d6                   -or esi, edx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.edx));
    // 004a7f0c  8930                   -mov dword ptr [eax], esi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
    // 004a7f0e  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 004a7f15  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004a7f17  8b15e0165600           -mov edx, dword ptr [0x5616e0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5641952) /* 0x5616e0 */);
    // 004a7f1d  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004a7f20  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a7f22  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004a7f25  f6420c04               +test byte ptr [edx + 0xc], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) & 4 /*0x4*/));
    // 004a7f29  0f84ef010000           -je 0x4a811e
    if (cpu.flags.zf)
    {
        goto L_0x004a811e;
    }
    // 004a7f2f  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x004a7f34:
    // 004a7f34  83e201                 -and edx, 1
    cpu.edx &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 004a7f37  8020fb                 -and byte ptr [eax], 0xfb
    app->getMemory<x86::reg8>(cpu.eax) &= x86::reg8(x86::sreg8(251 /*0xfb*/));
    // 004a7f3a  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 004a7f3d  0910                   -or dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) |= x86::reg32(x86::sreg32(cpu.edx));
    // 004a7f3f  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 004a7f46  8d1403                 -lea edx, [ebx + eax]
    cpu.edx = x86::reg32(cpu.ebx + cpu.eax * 1);
    // 004a7f49  a1e0165600             -mov eax, dword ptr [0x5616e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5641952) /* 0x5616e0 */);
    // 004a7f4e  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 004a7f51  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a7f53  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004a7f56  f6420c10               +test byte ptr [edx + 0xc], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) & 16 /*0x10*/));
    // 004a7f5a  0f84c5010000           -je 0x4a8125
    if (cpu.flags.zf)
    {
        goto L_0x004a8125;
    }
    // 004a7f60  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x004a7f65:
    // 004a7f65  83e201                 -and edx, 1
    cpu.edx &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 004a7f68  8020f7                 -and byte ptr [eax], 0xf7
    app->getMemory<x86::reg8>(cpu.eax) &= x86::reg8(x86::sreg8(247 /*0xf7*/));
    // 004a7f6b  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 004a7f6e  0910                   -or dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) |= x86::reg32(x86::sreg32(cpu.edx));
    // 004a7f70  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 004a7f77  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004a7f79  8b15e0165600           -mov edx, dword ptr [0x5616e0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5641952) /* 0x5616e0 */);
    // 004a7f7f  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004a7f82  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a7f84  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004a7f87  f6420c02               +test byte ptr [edx + 0xc], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) & 2 /*0x2*/));
    // 004a7f8b  0f849b010000           -je 0x4a812c
    if (cpu.flags.zf)
    {
        goto L_0x004a812c;
    }
    // 004a7f91  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x004a7f96:
    // 004a7f96  83e201                 -and edx, 1
    cpu.edx &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 004a7f99  8020ef                 -and byte ptr [eax], 0xef
    app->getMemory<x86::reg8>(cpu.eax) &= x86::reg8(x86::sreg8(239 /*0xef*/));
    // 004a7f9c  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 004a7f9f  0910                   -or dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) |= x86::reg32(x86::sreg32(cpu.edx));
    // 004a7fa1  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 004a7fa8  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004a7faa  8b15e0165600           -mov edx, dword ptr [0x5616e0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5641952) /* 0x5616e0 */);
    // 004a7fb0  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004a7fb3  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a7fb5  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004a7fb8  f6420d08               +test byte ptr [edx + 0xd], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) & 8 /*0x8*/));
    // 004a7fbc  0f8471010000           -je 0x4a8133
    if (cpu.flags.zf)
    {
        goto L_0x004a8133;
    }
    // 004a7fc2  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x004a7fc7:
    // 004a7fc7  83e201                 -and edx, 1
    cpu.edx &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 004a7fca  806001f7               -and byte ptr [eax + 1], 0xf7
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) &= x86::reg8(x86::sreg8(247 /*0xf7*/));
    // 004a7fce  c1e20b                 -shl edx, 0xb
    cpu.edx <<= 11 /*0xb*/ % 32;
    // 004a7fd1  0910                   -or dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) |= x86::reg32(x86::sreg32(cpu.edx));
    // 004a7fd3  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004a7fd6  c1e01d                 -shl eax, 0x1d
    cpu.eax <<= 29 /*0x1d*/ % 32;
    // 004a7fd9  c1f81f                 -sar eax, 0x1f
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (31 /*0x1f*/ % 32));
    // 004a7fdc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a7fde  0f8528010000           -jne 0x4a810c
    if (!cpu.flags.zf)
    {
        goto L_0x004a810c;
    }
    // 004a7fe4  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 004a7feb  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004a7fed  8b15e0165600           -mov edx, dword ptr [0x5616e0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5641952) /* 0x5616e0 */);
    // 004a7ff3  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004a7ff6  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a7ff8  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004a7ffb  f6420d04               +test byte ptr [edx + 0xd], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) & 4 /*0x4*/));
    // 004a7fff  0f8435010000           -je 0x4a813a
    if (cpu.flags.zf)
    {
        goto L_0x004a813a;
    }
    // 004a8005  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x004a800a:
    // 004a800a  83e201                 -and edx, 1
    cpu.edx &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 004a800d  8020df                 -and byte ptr [eax], 0xdf
    app->getMemory<x86::reg8>(cpu.eax) &= x86::reg8(x86::sreg8(223 /*0xdf*/));
    // 004a8010  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 004a8013  0910                   -or dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) |= x86::reg32(x86::sreg32(cpu.edx));
    // 004a8015  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 004a801c  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004a801e  8b15e0165600           -mov edx, dword ptr [0x5616e0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5641952) /* 0x5616e0 */);
    // 004a8024  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004a8027  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a8029  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004a802c  f6420c40               +test byte ptr [edx + 0xc], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) & 64 /*0x40*/));
    // 004a8030  0f840b010000           -je 0x4a8141
    if (cpu.flags.zf)
    {
        goto L_0x004a8141;
    }
    // 004a8036  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x004a803b:
    // 004a803b  83e201                 -and edx, 1
    cpu.edx &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 004a803e  8020bf                 -and byte ptr [eax], 0xbf
    app->getMemory<x86::reg8>(cpu.eax) &= x86::reg8(x86::sreg8(191 /*0xbf*/));
    // 004a8041  c1e206                 -shl edx, 6
    cpu.edx <<= 6 /*0x6*/ % 32;
    // 004a8044  0910                   -or dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) |= x86::reg32(x86::sreg32(cpu.edx));
    // 004a8046  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 004a804d  8d1403                 -lea edx, [ebx + eax]
    cpu.edx = x86::reg32(cpu.ebx + cpu.eax * 1);
    // 004a8050  a1e0165600             -mov eax, dword ptr [0x5616e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5641952) /* 0x5616e0 */);
    // 004a8055  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 004a8058  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a805a  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004a805d  f6420c80               +test byte ptr [edx + 0xc], 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */) & 128 /*0x80*/));
    // 004a8061  0f84e1000000           -je 0x4a8148
    if (cpu.flags.zf)
    {
        goto L_0x004a8148;
    }
    // 004a8067  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x004a806c:
    // 004a806c  83e201                 -and edx, 1
    cpu.edx &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 004a806f  80207f                 -and byte ptr [eax], 0x7f
    app->getMemory<x86::reg8>(cpu.eax) &= x86::reg8(x86::sreg8(127 /*0x7f*/));
    // 004a8072  c1e207                 -shl edx, 7
    cpu.edx <<= 7 /*0x7*/ % 32;
    // 004a8075  0910                   -or dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) |= x86::reg32(x86::sreg32(cpu.edx));
    // 004a8077  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 004a807e  8d1403                 -lea edx, [ebx + eax]
    cpu.edx = x86::reg32(cpu.ebx + cpu.eax * 1);
    // 004a8081  a1e0165600             -mov eax, dword ptr [0x5616e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5641952) /* 0x5616e0 */);
    // 004a8086  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 004a8089  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a808b  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004a808e  f6420d01               +test byte ptr [edx + 0xd], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) & 1 /*0x1*/));
    // 004a8092  0f84b7000000           -je 0x4a814f
    if (cpu.flags.zf)
    {
        goto L_0x004a814f;
    }
    // 004a8098  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x004a809d:
    // 004a809d  83e201                 -and edx, 1
    cpu.edx &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 004a80a0  806001fe               -and byte ptr [eax + 1], 0xfe
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 004a80a4  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004a80a7  0910                   -or dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) |= x86::reg32(x86::sreg32(cpu.edx));
    // 004a80a9  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 004a80b0  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004a80b2  8b15e0165600           -mov edx, dword ptr [0x5616e0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5641952) /* 0x5616e0 */);
    // 004a80b8  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004a80bb  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a80bd  8d4110                 -lea eax, [ecx + 0x10]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004a80c0  f6420d02               +test byte ptr [edx + 0xd], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(13) /* 0xd */) & 2 /*0x2*/));
    // 004a80c4  0f848c000000           -je 0x4a8156
    if (cpu.flags.zf)
    {
        goto L_0x004a8156;
    }
    // 004a80ca  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x004a80cf:
    // 004a80cf  83e201                 -and edx, 1
    cpu.edx &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 004a80d2  806001fd               -and byte ptr [eax + 1], 0xfd
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) &= x86::reg8(x86::sreg8(253 /*0xfd*/));
    // 004a80d6  c1e209                 -shl edx, 9
    cpu.edx <<= 9 /*0x9*/ % 32;
    // 004a80d9  0910                   -or dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) |= x86::reg32(x86::sreg32(cpu.edx));
    // 004a80db  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 004a80e2  8b15e0165600           -mov edx, dword ptr [0x5616e0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5641952) /* 0x5616e0 */);
    // 004a80e8  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004a80ea  8a5c820c               -mov bl, byte ptr [edx + eax*4 + 0xc]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(12) /* 0xc */ + cpu.eax * 4);
    // 004a80ee  83c110                 -add ecx, 0x10
    (cpu.ecx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a80f1  f6c320                 +test bl, 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 32 /*0x20*/));
    // 004a80f4  7467                   -je 0x4a815d
    if (cpu.flags.zf)
    {
        goto L_0x004a815d;
    }
    // 004a80f6  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004a80fb:
    // 004a80fb  8a7901                 -mov bh, byte ptr [ecx + 1]
    cpu.bh = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 004a80fe  80e7fb                 -and bh, 0xfb
    cpu.bh &= x86::reg8(x86::sreg8(251 /*0xfb*/));
    // 004a8101  83e001                 -and eax, 1
    cpu.eax &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 004a8104  887901                 -mov byte ptr [ecx + 1], bh
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */) = cpu.bh;
    // 004a8107  c1e00a                 -shl eax, 0xa
    cpu.eax <<= 10 /*0xa*/ % 32;
    // 004a810a  0901                   -or dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) |= x86::reg32(x86::sreg32(cpu.eax));
L_0x004a810c:
    // 004a810c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a8111  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8112  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8113  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8114  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8115  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8116  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a8117:
    // 004a8117  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004a8119  e9e2fdffff             -jmp 0x4a7f00
    goto L_0x004a7f00;
L_0x004a811e:
    // 004a811e  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004a8120  e90ffeffff             -jmp 0x4a7f34
    goto L_0x004a7f34;
L_0x004a8125:
    // 004a8125  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004a8127  e939feffff             -jmp 0x4a7f65
    goto L_0x004a7f65;
L_0x004a812c:
    // 004a812c  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004a812e  e963feffff             -jmp 0x4a7f96
    goto L_0x004a7f96;
L_0x004a8133:
    // 004a8133  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004a8135  e98dfeffff             -jmp 0x4a7fc7
    goto L_0x004a7fc7;
L_0x004a813a:
    // 004a813a  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004a813c  e9c9feffff             -jmp 0x4a800a
    goto L_0x004a800a;
L_0x004a8141:
    // 004a8141  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004a8143  e9f3feffff             -jmp 0x4a803b
    goto L_0x004a803b;
L_0x004a8148:
    // 004a8148  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004a814a  e91dffffff             -jmp 0x4a806c
    goto L_0x004a806c;
L_0x004a814f:
    // 004a814f  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004a8151  e947ffffff             -jmp 0x4a809d
    goto L_0x004a809d;
L_0x004a8156:
    // 004a8156  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004a8158  e972ffffff             -jmp 0x4a80cf
    goto L_0x004a80cf;
L_0x004a815d:
    // 004a815d  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004a815f  eb9a                   -jmp 0x4a80fb
    goto L_0x004a80fb;
L_0x004a8161:
    // 004a8161  83fbff                 +cmp ebx, -1
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
    // 004a8164  0f85a7000000           -jne 0x4a8211
    if (!cpu.flags.zf)
    {
        goto L_0x004a8211;
    }
    // 004a816a  803d2d1b560000         +cmp byte ptr [0x561b2d], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5643053) /* 0x561b2d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a8171  0f859a000000           -jne 0x4a8211
    if (!cpu.flags.zf)
    {
        goto L_0x004a8211;
    }
    // 004a8177  a1e4165600             -mov eax, dword ptr [0x5616e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5641956) /* 0x5616e4 */);
    // 004a817c  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 004a817e  a1e8165600             -mov eax, dword ptr [0x5616e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5641960) /* 0x5616e8 */);
    // 004a8183  894104                 -mov dword ptr [ecx + 4], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004a8186  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a8188  a02c1b5600             -mov al, byte ptr [0x561b2c]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5643052) /* 0x561b2c */);
    // 004a818d  894108                 -mov dword ptr [ecx + 8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004a8190  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a8192  a0b1904d00             -mov al, byte ptr [0x4d90b1]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5083313) /* 0x4d90b1 */);
    // 004a8197  8a5110                 -mov dl, byte ptr [ecx + 0x10]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004a819a  89410c                 -mov dword ptr [ecx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004a819d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a819f  80e2fd                 -and dl, 0xfd
    cpu.dl &= x86::reg8(x86::sreg8(253 /*0xfd*/));
    // 004a81a2  a0321b5600             -mov al, byte ptr [0x561b32]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5643058) /* 0x561b32 */);
    // 004a81a7  885110                 -mov byte ptr [ecx + 0x10], dl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.dl;
    // 004a81aa  83e001                 -and eax, 1
    cpu.eax &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 004a81ad  8b7910                 -mov edi, dword ptr [ecx + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004a81b0  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a81b2  09c7                   -or edi, eax
    cpu.edi |= x86::reg32(x86::sreg32(cpu.eax));
    // 004a81b4  897910                 -mov dword ptr [ecx + 0x10], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.edi;
    // 004a81b7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a81b9  8a7110                 -mov dh, byte ptr [ecx + 0x10]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004a81bc  a02f1b5600             -mov al, byte ptr [0x561b2f]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5643055) /* 0x561b2f */);
    // 004a81c1  80e6fb                 -and dh, 0xfb
    cpu.dh &= x86::reg8(x86::sreg8(251 /*0xfb*/));
    // 004a81c4  83e001                 -and eax, 1
    cpu.eax &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 004a81c7  887110                 -mov byte ptr [ecx + 0x10], dh
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.dh;
    // 004a81ca  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004a81cd  8b6910                 -mov ebp, dword ptr [ecx + 0x10]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 004a81d0  83c110                 -add ecx, 0x10
    (cpu.ecx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a81d3  09c5                   -or ebp, eax
    cpu.ebp |= x86::reg32(x86::sreg32(cpu.eax));
    // 004a81d5  8a1d331b5600           -mov bl, byte ptr [0x561b33]
    cpu.bl = app->getMemory<x86::reg8>(x86::reg32(5643059) /* 0x561b33 */);
    // 004a81db  8929                   -mov dword ptr [ecx], ebp
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.ebp;
    // 004a81dd  80fb01                 +cmp bl, 1
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
    // 004a81e0  762b                   -jbe 0x4a820d
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a820d;
    }
    // 004a81e2  803d301b560000         +cmp byte ptr [0x561b30], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5643056) /* 0x561b30 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a81e9  7422                   -je 0x4a820d
    if (cpu.flags.zf)
    {
        goto L_0x004a820d;
    }
    // 004a81eb  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004a81f0:
    // 004a81f0  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 004a81f2  80e2f7                 -and dl, 0xf7
    cpu.dl &= x86::reg8(x86::sreg8(247 /*0xf7*/));
    // 004a81f5  83e001                 -and eax, 1
    cpu.eax &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 004a81f8  8811                   -mov byte ptr [ecx], dl
    app->getMemory<x86::reg8>(cpu.ecx) = cpu.dl;
    // 004a81fa  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004a81fd  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004a81ff  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004a8201  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a8206  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 004a8208  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8209  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a820a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a820b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a820c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a820d:
    // 004a820d  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004a820f  ebdf                   -jmp 0x4a81f0
    goto L_0x004a81f0;
L_0x004a8211:
    // 004a8211  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a8213  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8214  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8215  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8216  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8217  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a8218(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a8218  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a8219  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a821b  e8d8f8ffff             -call 0x4a7af8
    cpu.esp -= 4;
    sub_4a7af8(app, cpu);
    if (cpu.terminate) return;
    // 004a8220  e8a7faffff             -call 0x4a7ccc
    cpu.esp -= 4;
    sub_4a7ccc(app, cpu);
    if (cpu.terminate) return;
    // 004a8225  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a8227  7441                   -je 0x4a826a
    if (cpu.flags.zf)
    {
        goto L_0x004a826a;
    }
    // 004a8229  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a822b  7c08                   -jl 0x4a8235
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a8235;
    }
    // 004a822d  3b15d8165600           +cmp edx, dword ptr [0x5616d8]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5641944) /* 0x5616d8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a8233  7c05                   -jl 0x4a823a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a823a;
    }
L_0x004a8235:
    // 004a8235  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
L_0x004a823a:
    // 004a823a  b865040000             -mov eax, 0x465
    cpu.eax = 1125 /*0x465*/;
    // 004a823f  e844f6ffff             -call 0x4a7888
    cpu.esp -= 4;
    sub_4a7888(app, cpu);
    if (cpu.terminate) return;
    // 004a8244  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a8246  751e                   -jne 0x4a8266
    if (!cpu.flags.zf)
    {
        goto L_0x004a8266;
    }
    // 004a8248  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x004a824d:
    // 004a824d  e8def9ffff             -call 0x4a7c30
    cpu.esp -= 4;
    sub_4a7c30(app, cpu);
    if (cpu.terminate) return;
    // 004a8252  833d78894d0007         +cmp dword ptr [0x4d8978], 7
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5081464) /* 0x4d8978 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a8259  7514                   -jne 0x4a826f
    if (!cpu.flags.zf)
    {
        goto L_0x004a826f;
    }
    // 004a825b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a825d  7410                   -je 0x4a826f
    if (cpu.flags.zf)
    {
        goto L_0x004a826f;
    }
    // 004a825f  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a8264  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8265  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a8266:
    // 004a8266  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004a8268  ebe3                   -jmp 0x4a824d
    goto L_0x004a824d;
L_0x004a826a:
    // 004a826a  a378894d00             -mov dword ptr [0x4d8978], eax
    app->getMemory<x86::reg32>(x86::reg32(5081464) /* 0x4d8978 */) = cpu.eax;
L_0x004a826f:
    // 004a826f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a8271  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8272  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a8274(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a8274  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a8275  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a8276  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a8277  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a8278  8b3da4894d00           -mov edi, dword ptr [0x4d89a4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5081508) /* 0x4d89a4 */);
    // 004a827e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a8280  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004a8282  8b2d64b54d00           -mov ebp, dword ptr [0x4db564]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5092708) /* 0x4db564 */);
    // 004a8288  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a828a  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004a828c  7530                   -jne 0x4a82be
    if (!cpu.flags.zf)
    {
        goto L_0x004a82be;
    }
    // 004a828e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a8290  7536                   -jne 0x4a82c8
    if (!cpu.flags.zf)
    {
        goto L_0x004a82c8;
    }
    // 004a8292  b980020000             -mov ecx, 0x280
    cpu.ecx = 640 /*0x280*/;
L_0x004a8297:
    // 004a8297  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a8299  7539                   -jne 0x4a82d4
    if (!cpu.flags.zf)
    {
        goto L_0x004a82d4;
    }
    // 004a829b  bee0010000             -mov esi, 0x1e0
    cpu.esi = 480 /*0x1e0*/;
L_0x004a82a0:
    // 004a82a0  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a82a2  753c                   -jne 0x4a82e0
    if (!cpu.flags.zf)
    {
        goto L_0x004a82e0;
    }
L_0x004a82a4:
    // 004a82a4  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
L_0x004a82a9:
    // 004a82a9  893da4894d00           -mov dword ptr [0x4d89a4], edi
    app->getMemory<x86::reg32>(x86::reg32(5081508) /* 0x4d89a4 */) = cpu.edi;
    // 004a82af  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a82b1  7439                   -je 0x4a82ec
    if (cpu.flags.zf)
    {
        goto L_0x004a82ec;
    }
L_0x004a82b3:
    // 004a82b3  8b3da4894d00           -mov edi, dword ptr [0x4d89a4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5081508) /* 0x4d89a4 */);
    // 004a82b9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a82ba  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a82bb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a82bc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a82bd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a82be:
    // 004a82be  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004a82c0  ff1564b54d00           -call dword ptr [0x4db564]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5092708) /* 0x4db564 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a82c6  ebeb                   -jmp 0x4a82b3
    goto L_0x004a82b3;
L_0x004a82c8:
    // 004a82c8  83f8ff                 +cmp eax, -1
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
    // 004a82cb  75ca                   -jne 0x4a8297
    if (!cpu.flags.zf)
    {
        goto L_0x004a8297;
    }
    // 004a82cd  b900040000             -mov ecx, 0x400
    cpu.ecx = 1024 /*0x400*/;
    // 004a82d2  ebc3                   -jmp 0x4a8297
    goto L_0x004a8297;
L_0x004a82d4:
    // 004a82d4  83feff                 +cmp esi, -1
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
    // 004a82d7  75c7                   -jne 0x4a82a0
    if (!cpu.flags.zf)
    {
        goto L_0x004a82a0;
    }
    // 004a82d9  be00030000             -mov esi, 0x300
    cpu.esi = 768 /*0x300*/;
    // 004a82de  ebc0                   -jmp 0x4a82a0
    goto L_0x004a82a0;
L_0x004a82e0:
    // 004a82e0  83fbff                 +cmp ebx, -1
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
    // 004a82e3  74bf                   -je 0x4a82a4
    if (cpu.flags.zf)
    {
        goto L_0x004a82a4;
    }
    // 004a82e5  83fb0f                 +cmp ebx, 0xf
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
    // 004a82e8  75bf                   -jne 0x4a82a9
    if (!cpu.flags.zf)
    {
        goto L_0x004a82a9;
    }
    // 004a82ea  ebb8                   -jmp 0x4a82a4
    goto L_0x004a82a4;
L_0x004a82ec:
    // 004a82ec  e807f8ffff             -call 0x4a7af8
    cpu.esp -= 4;
    sub_4a7af8(app, cpu);
    if (cpu.terminate) return;
    // 004a82f1  890de4165600           -mov dword ptr [0x5616e4], ecx
    app->getMemory<x86::reg32>(x86::reg32(5641956) /* 0x5616e4 */) = cpu.ecx;
    // 004a82f7  8935e8165600           -mov dword ptr [0x5616e8], esi
    app->getMemory<x86::reg32>(x86::reg32(5641960) /* 0x5616e8 */) = cpu.esi;
    // 004a82fd  891dec165600           -mov dword ptr [0x5616ec], ebx
    app->getMemory<x86::reg32>(x86::reg32(5641964) /* 0x5616ec */) = cpu.ebx;
    // 004a8303  881d2c1b5600           -mov byte ptr [0x561b2c], bl
    app->getMemory<x86::reg8>(x86::reg32(5643052) /* 0x561b2c */) = cpu.bl;
    // 004a8309  e8bef9ffff             -call 0x4a7ccc
    cpu.esp -= 4;
    sub_4a7ccc(app, cpu);
    if (cpu.terminate) return;
    // 004a830e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a8310  7511                   -jne 0x4a8323
    if (!cpu.flags.zf)
    {
        goto L_0x004a8323;
    }
    // 004a8312  891578894d00           -mov dword ptr [0x4d8978], edx
    app->getMemory<x86::reg32>(x86::reg32(5081464) /* 0x4d8978 */) = cpu.edx;
    // 004a8318  8b3da4894d00           -mov edi, dword ptr [0x4d89a4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5081508) /* 0x4d89a4 */);
    // 004a831e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a831f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8320  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8321  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8322  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a8323:
    // 004a8323  b8d0165600             -mov eax, 0x5616d0
    cpu.eax = 5641936 /*0x5616d0*/;
    // 004a8328  e86bf6ffff             -call 0x4a7998
    cpu.esp -= 4;
    sub_4a7998(app, cpu);
    if (cpu.terminate) return;
    // 004a832d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a832f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a8331  7527                   -jne 0x4a835a
    if (!cpu.flags.zf)
    {
        goto L_0x004a835a;
    }
    // 004a8333  8b3da4894d00           -mov edi, dword ptr [0x4d89a4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5081508) /* 0x4d89a4 */);
    // 004a8339  66f7c78000             +test di, 0x80
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.di & 128 /*0x80*/));
    // 004a833e  750a                   -jne 0x4a834a
    if (!cpu.flags.zf)
    {
        goto L_0x004a834a;
    }
    // 004a8340  6681cf8000             +or di, 0x80
    cpu.clear_co();
    cpu.set_szp((cpu.di |= x86::reg16(x86::sreg16(128 /*0x80*/))));
    // 004a8345  e95fffffff             -jmp 0x4a82a9
    goto L_0x004a82a9;
L_0x004a834a:
    // 004a834a  a378894d00             -mov dword ptr [0x4d8978], eax
    app->getMemory<x86::reg32>(x86::reg32(5081464) /* 0x4d8978 */) = cpu.eax;
    // 004a834f  8b3da4894d00           -mov edi, dword ptr [0x4d89a4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5081508) /* 0x4d89a4 */);
    // 004a8355  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8356  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8357  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8358  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8359  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a835a:
    // 004a835a  e8d1f8ffff             -call 0x4a7c30
    cpu.esp -= 4;
    sub_4a7c30(app, cpu);
    if (cpu.terminate) return;
    // 004a835f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a8361  7489                   -je 0x4a82ec
    if (cpu.flags.zf)
    {
        goto L_0x004a82ec;
    }
    // 004a8363  8b3da4894d00           -mov edi, dword ptr [0x4d89a4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5081508) /* 0x4d89a4 */);
    // 004a8369  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a836a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a836b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a836c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a836d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a8370(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a8370  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a8371  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a8372  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a8373  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a8374  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a8377  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a8379  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a837b  8b35d0165600           -mov esi, dword ptr [0x5616d0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5641936) /* 0x5616d0 */);
    // 004a8381  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 004a8384  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a8386  7419                   -je 0x4a83a1
    if (cpu.flags.zf)
    {
        goto L_0x004a83a1;
    }
L_0x004a8388:
    // 004a8388  833d78894d0000         +cmp dword ptr [0x4d8978], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5081464) /* 0x4d8978 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a838f  751c                   -jne 0x4a83ad
    if (!cpu.flags.zf)
    {
        goto L_0x004a83ad;
    }
L_0x004a8391:
    // 004a8391  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004a8393  892c24                 -mov dword ptr [esp], ebp
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 004a8396  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004a8399  83c404                 +add esp, 4
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
    // 004a839c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a839d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a839e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a839f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a83a0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a83a1:
    // 004a83a1  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004a83a6  e86dfeffff             -call 0x4a8218
    cpu.esp -= 4;
    sub_4a8218(app, cpu);
    if (cpu.terminate) return;
    // 004a83ab  ebdb                   -jmp 0x4a8388
    goto L_0x004a8388;
L_0x004a83ad:
    // 004a83ad  b8d0165600             -mov eax, 0x5616d0
    cpu.eax = 5641936 /*0x5616d0*/;
    // 004a83b2  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a83b3  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a83b5  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a83b7  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a83bb  e8ac38feff             -call 0x48bc6c
    cpu.esp -= 4;
    sub_48bc6c(app, cpu);
    if (cpu.terminate) return;
    // 004a83c0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a83c2  74cd                   -je 0x4a8391
    if (cpu.flags.zf)
    {
        goto L_0x004a8391;
    }
    // 004a83c4  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004a83c7  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a83ca  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a83cb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a83cc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a83cd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a83ce  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4a83d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a83d0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a83d1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a83d2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a83d3  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a83d6  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a83d8  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004a83da  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 004a83dc  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a83e0  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004a83e2  7506                   -jne 0x4a83ea
    if (!cpu.flags.zf)
    {
        goto L_0x004a83ea;
    }
    // 004a83e4  8b0da0894d00           -mov ecx, dword ptr [0x4d89a0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5081504) /* 0x4d89a0 */);
L_0x004a83ea:
    // 004a83ea  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004a83ec  7505                   -jne 0x4a83f3
    if (!cpu.flags.zf)
    {
        goto L_0x004a83f3;
    }
    // 004a83ee  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
L_0x004a83f3:
    // 004a83f3  8d4101                 -lea eax, [ecx + 1]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 004a83f6  24fe                   -and al, 0xfe
    cpu.al &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 004a83f8  ba38000000             -mov edx, 0x38
    cpu.edx = 56 /*0x38*/;
    // 004a83fd  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004a8400  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a8402  e88500feff             -call 0x48848c
    cpu.esp -= 4;
    sub_48848c(app, cpu);
    if (cpu.terminate) return;
    // 004a8407  c706444e4957           -mov dword ptr [esi], 0x57494e44
    app->getMemory<x86::reg32>(cpu.esi) = 1464421956 /*0x57494e44*/;
    // 004a840d  c6461eff               -mov byte ptr [esi + 0x1e], 0xff
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(30) /* 0x1e */) = 255 /*0xff*/;
    // 004a8411  896e28                 -mov dword ptr [esi + 0x28], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.ebp;
    // 004a8414  897e04                 -mov dword ptr [esi + 4], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 004a8417  895e08                 -mov dword ptr [esi + 8], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004a841a  897e14                 -mov dword ptr [esi + 0x14], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.edi;
    // 004a841d  895e18                 -mov dword ptr [esi + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 004a8420  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a8422  884e1c                 -mov byte ptr [esi + 0x1c], cl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.cl;
    // 004a8425  e816030000             -call 0x4a8740
    cpu.esp -= 4;
    sub_4a8740(app, cpu);
    if (cpu.terminate) return;
    // 004a842a  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004a842c  88461d                 -mov byte ptr [esi + 0x1d], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(29) /* 0x1d */) = cpu.al;
    // 004a842f  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a8433  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004a8435  894620                 -mov dword ptr [esi + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 004a8438  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a843c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a843e  894634                 -mov dword ptr [esi + 0x34], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 004a8441  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a8443  e86cdcfeff             -call 0x4960b4
    cpu.esp -= 4;
    sub_4960b4(app, cpu);
    if (cpu.terminate) return;
    // 004a8448  bb03000000             -mov ebx, 3
    cpu.ebx = 3 /*0x3*/;
    // 004a844d  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004a8450  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004a8452  89462c                 -mov dword ptr [esi + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 004a8455  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a8457  e858dcfeff             -call 0x4960b4
    cpu.esp -= 4;
    sub_4960b4(app, cpu);
    if (cpu.terminate) return;
    // 004a845c  894630                 -mov dword ptr [esi + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 004a845f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a8462  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8463  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8464  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8465  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_4a8468(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a8468  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a8469  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a846a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a846b  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a846e  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004a8470  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004a8472  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 004a8475  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a8479  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a847b  7c26                   -jl 0x4a84a3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a84a3;
    }
    // 004a847d  3d00050000             +cmp eax, 0x500
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1280 /*0x500*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a8482  7f1f                   -jg 0x4a84a3
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a84a3;
    }
    // 004a8484  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a8486  7c1b                   -jl 0x4a84a3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a84a3;
    }
    // 004a8488  81fa00040000           +cmp edx, 0x400
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1024 /*0x400*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a848e  7f13                   -jg 0x4a84a3
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a84a3;
    }
    // 004a8490  83fbff                 +cmp ebx, -1
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
    // 004a8493  7519                   -jne 0x4a84ae
    if (!cpu.flags.zf)
    {
        goto L_0x004a84ae;
    }
    // 004a8495  be94904d00             -mov esi, 0x4d9094
    cpu.esi = 5083284 /*0x4d9094*/;
L_0x004a849a:
    // 004a849a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a849c  752f                   -jne 0x4a84cd
    if (!cpu.flags.zf)
    {
        goto L_0x004a84cd;
    }
    // 004a849e  e809abfdff             -call 0x482fac
    cpu.esp -= 4;
    sub_482fac(app, cpu);
    if (cpu.terminate) return;
L_0x004a84a3:
    // 004a84a3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a84a5  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a84a8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a84a9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a84aa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a84ab  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x004a84ae:
    // 004a84ae  83fbfe                 +cmp ebx, -2
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-2 /*-0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a84b1  7507                   -jne 0x4a84ba
    if (!cpu.flags.zf)
    {
        goto L_0x004a84ba;
    }
    // 004a84b3  becc904d00             -mov esi, 0x4d90cc
    cpu.esi = 5083340 /*0x4d90cc*/;
    // 004a84b8  ebe0                   -jmp 0x4a849a
    goto L_0x004a849a;
L_0x004a84ba:
    // 004a84ba  ba38000000             -mov edx, 0x38
    cpu.edx = 56 /*0x38*/;
    // 004a84bf  b8b0f44c00             -mov eax, 0x4cf4b0
    cpu.eax = 5043376 /*0x4cf4b0*/;
    // 004a84c4  e83fa4fdff             -call 0x482908
    cpu.esp -= 4;
    sub_482908(app, cpu);
    if (cpu.terminate) return;
    // 004a84c9  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a84cb  ebcd                   -jmp 0x4a849a
    goto L_0x004a849a;
L_0x004a84cd:
    // 004a84cd  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a84d1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a84d2  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a84d6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a84d7  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a84d9  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004a84db  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a84dc  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 004a84de  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a84e2  e8e9feffff             -call 0x4a83d0
    cpu.esp -= 4;
    sub_4a83d0(app, cpu);
    if (cpu.terminate) return;
    // 004a84e7  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a84e9  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a84ec  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a84ed  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a84ee  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a84ef  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a84f4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a84f4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a84f5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a84f6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a84f7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a84f8  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a84fa  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a84fc  7505                   -jne 0x4a8503
    if (!cpu.flags.zf)
    {
        goto L_0x004a8503;
    }
    // 004a84fe  be5c904d00             -mov esi, 0x4d905c
    cpu.esi = 5083228 /*0x4d905c*/;
L_0x004a8503:
    // 004a8503  8b4e28                 -mov ecx, dword ptr [esi + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */);
    // 004a8506  895e20                 -mov dword ptr [esi + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 004a8509  39ca                   +cmp edx, ecx
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
    // 004a850b  7420                   -je 0x4a852d
    if (cpu.flags.zf)
    {
        goto L_0x004a852d;
    }
    // 004a850d  8b5e2c                 -mov ebx, dword ptr [esi + 0x2c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */);
    // 004a8510  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a8512  7407                   -je 0x4a851b
    if (cpu.flags.zf)
    {
        goto L_0x004a851b;
    }
    // 004a8514  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a8516  e871dcfeff             -call 0x49618c
    cpu.esp -= 4;
    sub_49618c(app, cpu);
    if (cpu.terminate) return;
L_0x004a851b:
    // 004a851b  8b4e08                 -mov ecx, dword ptr [esi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004a851e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a8520  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a8522  895628                 -mov dword ptr [esi + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 004a8525  e88adbfeff             -call 0x4960b4
    cpu.esp -= 4;
    sub_4960b4(app, cpu);
    if (cpu.terminate) return;
    // 004a852a  89462c                 -mov dword ptr [esi + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */) = cpu.eax;
L_0x004a852d:
    // 004a852d  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004a8530  8b7e04                 -mov edi, dword ptr [esi + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004a8533  39f8                   +cmp eax, edi
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
    // 004a8535  7e03                   -jle 0x4a853a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a853a;
    }
    // 004a8537  897e0c                 -mov dword ptr [esi + 0xc], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edi;
L_0x004a853a:
    // 004a853a  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004a853d  8b6e08                 -mov ebp, dword ptr [esi + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004a8540  39e8                   +cmp eax, ebp
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
    // 004a8542  7e03                   -jle 0x4a8547
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a8547;
    }
    // 004a8544  896e10                 -mov dword ptr [esi + 0x10], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.ebp;
L_0x004a8547:
    // 004a8547  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004a854a  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004a854d  39d0                   +cmp eax, edx
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
    // 004a854f  7e19                   -jle 0x4a856a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a856a;
    }
    // 004a8551  895614                 -mov dword ptr [esi + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.edx;
L_0x004a8554:
    // 004a8554  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004a8557  8b5e08                 -mov ebx, dword ptr [esi + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004a855a  39d8                   +cmp eax, ebx
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
    // 004a855c  7f18                   -jg 0x4a8576
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a8576;
    }
    // 004a855e  8b7e10                 -mov edi, dword ptr [esi + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004a8561  39f8                   +cmp eax, edi
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
    // 004a8563  7c19                   -jl 0x4a857e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a857e;
    }
    // 004a8565  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8566  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8567  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8568  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8569  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a856a:
    // 004a856a  8b4e0c                 -mov ecx, dword ptr [esi + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004a856d  39c8                   +cmp eax, ecx
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
    // 004a856f  7de3                   -jge 0x4a8554
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a8554;
    }
    // 004a8571  894e14                 -mov dword ptr [esi + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 004a8574  ebde                   -jmp 0x4a8554
    goto L_0x004a8554;
L_0x004a8576:
    // 004a8576  895e18                 -mov dword ptr [esi + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 004a8579  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a857a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a857b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a857c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a857d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a857e:
    // 004a857e  897e18                 -mov dword ptr [esi + 0x18], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 004a8581  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8582  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8583  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8584  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8585  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a8588(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a8588  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a8589  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a858a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a858b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a858d  8b482c                 -mov ecx, dword ptr [eax + 0x2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */);
    // 004a8590  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004a8592  7529                   -jne 0x4a85bd
    if (!cpu.flags.zf)
    {
        goto L_0x004a85bd;
    }
L_0x004a8594:
    // 004a8594  8b5a30                 -mov ebx, dword ptr [edx + 0x30]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(48) /* 0x30 */);
    // 004a8597  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a8599  740e                   -je 0x4a85a9
    if (cpu.flags.zf)
    {
        goto L_0x004a85a9;
    }
    // 004a859b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a859d  e8eadbfeff             -call 0x49618c
    cpu.esp -= 4;
    sub_49618c(app, cpu);
    if (cpu.terminate) return;
    // 004a85a2  c7423000000000         -mov dword ptr [edx + 0x30], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(48) /* 0x30 */) = 0 /*0x0*/;
L_0x004a85a9:
    // 004a85a9  81fa94904d00           +cmp edx, 0x4d9094
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5083284 /*0x4d9094*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a85af  7408                   -je 0x4a85b9
    if (cpu.flags.zf)
    {
        goto L_0x004a85b9;
    }
    // 004a85b1  81facc904d00           +cmp edx, 0x4d90cc
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5083340 /*0x4d90cc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a85b7  7514                   -jne 0x4a85cd
    if (!cpu.flags.zf)
    {
        goto L_0x004a85cd;
    }
L_0x004a85b9:
    // 004a85b9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a85ba  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a85bb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a85bc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a85bd:
    // 004a85bd  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a85bf  e8c8dbfeff             -call 0x49618c
    cpu.esp -= 4;
    sub_49618c(app, cpu);
    if (cpu.terminate) return;
    // 004a85c4  c7422c00000000         -mov dword ptr [edx + 0x2c], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(44) /* 0x2c */) = 0 /*0x0*/;
    // 004a85cb  ebc7                   -jmp 0x4a8594
    goto L_0x004a8594;
L_0x004a85cd:
    // 004a85cd  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a85cf  e898a7fdff             -call 0x482d6c
    cpu.esp -= 4;
    sub_482d6c(app, cpu);
    if (cpu.terminate) return;
    // 004a85d4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a85d5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a85d6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a85d7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a85d8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a85d8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a85d9  8b5034                 -mov edx, dword ptr [eax + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 004a85dc  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a85de  7502                   -jne 0x4a85e2
    if (!cpu.flags.zf)
    {
        goto L_0x004a85e2;
    }
    // 004a85e0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a85e1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a85e2:
    // 004a85e2  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a85e4  e80b4cfeff             -call 0x48d1f4
    cpu.esp -= 4;
    sub_48d1f4(app, cpu);
    if (cpu.terminate) return;
    // 004a85e9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a85ea  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a85ec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a85ec  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a85ed  8b5034                 -mov edx, dword ptr [eax + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    // 004a85f0  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a85f2  7502                   -jne 0x4a85f6
    if (!cpu.flags.zf)
    {
        goto L_0x004a85f6;
    }
    // 004a85f4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a85f5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a85f6:
    // 004a85f6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a85f8  e8374cfeff             -call 0x48d234
    cpu.esp -= 4;
    sub_48d234(app, cpu);
    if (cpu.terminate) return;
    // 004a85fd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a85fe  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a8600(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a8600  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a8601  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a8602  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a8603  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004a8606  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 004a8608  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004a860a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a860b  8b4c2428               -mov ecx, dword ptr [esp + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004a860f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a8610  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a8611  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004a8613  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a8614  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004a8616  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a8618  b8d0165600             -mov eax, 0x5616d0
    cpu.eax = 5641936 /*0x5616d0*/;
    // 004a861d  e82248feff             -call 0x48ce44
    cpu.esp -= 4;
    sub_48ce44(app, cpu);
    if (cpu.terminate) return;
    // 004a8622  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a8624  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a8626  750b                   -jne 0x4a8633
    if (!cpu.flags.zf)
    {
        goto L_0x004a8633;
    }
L_0x004a8628:
    // 004a8628  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a862a  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004a862d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a862e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a862f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8630  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004a8633:
    // 004a8633  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004a8635  8d4c2410               -lea ecx, [esp + 0x10]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a8639  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a863a  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a863e  8d5c2410               -lea ebx, [esp + 0x10]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a8642  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a8643  8d542410               -lea edx, [esp + 0x10]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a8647  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a8649  e8c24afeff             -call 0x48d110
    cpu.esp -= 4;
    sub_48d110(app, cpu);
    if (cpu.terminate) return;
    // 004a864e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a864f  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a8653  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a8654  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a8658  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a865c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a865d  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a8661  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a8665  e8fefdffff             -call 0x4a8468
    cpu.esp -= 4;
    sub_4a8468(app, cpu);
    if (cpu.terminate) return;
    // 004a866a  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004a866c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a866e  75b8                   -jne 0x4a8628
    if (!cpu.flags.zf)
    {
        goto L_0x004a8628;
    }
    // 004a8670  b8d0165600             -mov eax, 0x5616d0
    cpu.eax = 5641936 /*0x5616d0*/;
    // 004a8675  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004a8677  e8bc49feff             -call 0x48d038
    cpu.esp -= 4;
    sub_48d038(app, cpu);
    if (cpu.terminate) return;
    // 004a867c  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a867e  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004a8681  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8682  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8683  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8684  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a8690(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a8690  09c9                   +or ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004a8692  742c                   -je 0x4a86c0
    if (cpu.flags.zf)
    {
        goto L_0x004a86c0;
    }
    // 004a8694  3810                   -cmp byte ptr [eax], dl
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.dl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
L_0x004a8696:
    // 004a8696  a803                   +test al, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 3 /*0x3*/));
    // 004a8698  7409                   -je 0x4a86a3
    if (cpu.flags.zf)
    {
        goto L_0x004a86a3;
    }
    // 004a869a  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 004a869c  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004a869d  c1ca08                 +ror edx, 8
    {
        x86::reg32& op = cpu.edx;
        x86::reg32 count = 8 /*0x8*/ % 32;
        if (count) {
            op = (op >> count) | (op << (32 - count));
            cpu.flags.cf = (op >> (32 - 1)) & 1;
            if (count == 1) {
                cpu.flags.of = ((op >> (32 - 1)) ^ (op >> (32 - 2))) & 1;
            }
        }
    }
    // 004a86a0  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a86a1  75f3                   -jne 0x4a8696
    if (!cpu.flags.zf)
    {
        goto L_0x004a8696;
    }
L_0x004a86a3:
    // 004a86a3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a86a4  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004a86a7  e81b000000             -call 0x4a86c7
    cpu.esp -= 4;
    sub_4a86c7(app, cpu);
    if (cpu.terminate) return;
    // 004a86ac  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a86ad  83e103                 +and ecx, 3
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/))));
    // 004a86b0  740e                   -je 0x4a86c0
    if (cpu.flags.zf)
    {
        goto L_0x004a86c0;
    }
    // 004a86b2  8810                   -mov byte ptr [eax], dl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.dl;
    // 004a86b4  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a86b5  7409                   -je 0x4a86c0
    if (cpu.flags.zf)
    {
        goto L_0x004a86c0;
    }
    // 004a86b7  887001                 -mov byte ptr [eax + 1], dh
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = cpu.dh;
    // 004a86ba  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a86bb  7403                   -je 0x4a86c0
    if (cpu.flags.zf)
    {
        goto L_0x004a86c0;
    }
    // 004a86bd  885002                 -mov byte ptr [eax + 2], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */) = cpu.dl;
L_0x004a86c0:
    // 004a86c0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a86c2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a86c2  90                     -nop 
    ;
    // 004a86c3  90                     -nop 
    ;
    // 004a86c4  90                     -nop 
    ;
    // 004a86c5  90                     -nop 
    ;
    // 004a86c6  90                     -nop 
    ;
    // 004a86c7  09c9                   +or ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004a86c9  7467                   -je 0x4a8732
    if (cpu.flags.zf)
    {
        goto L_0x004a8732;
    }
L_0x004a86cb:
    // 004a86cb  a81f                   +test al, 0x1f
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 31 /*0x1f*/));
    // 004a86cd  7408                   -je 0x4a86d7
    if (cpu.flags.zf)
    {
        goto L_0x004a86d7;
    }
    // 004a86cf  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004a86d1  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004a86d4  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a86d5  75f4                   -jne 0x4a86cb
    if (!cpu.flags.zf)
    {
        goto L_0x004a86cb;
    }
L_0x004a86d7:
    // 004a86d7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a86d8  c1e902                 +shr ecx, 2
    {
        x86::reg8 tmp = 2 /*0x2*/ % 32;
        x86::reg32& op = cpu.ecx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 004a86db  743a                   -je 0x4a8717
    if (cpu.flags.zf)
    {
        goto L_0x004a8717;
    }
    // 004a86dd  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a86de  7429                   -je 0x4a8709
    if (cpu.flags.zf)
    {
        goto L_0x004a8709;
    }
L_0x004a86e0:
    // 004a86e0  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004a86e2  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004a86e5  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a86e6  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004a86e9  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004a86ec  7418                   -je 0x4a8706
    if (cpu.flags.zf)
    {
        goto L_0x004a8706;
    }
    // 004a86ee  385020                 +cmp byte ptr [eax + 0x20], dl
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(32) /* 0x20 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.dl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a86f1  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004a86f4  895014                 -mov dword ptr [eax + 0x14], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004a86f7  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a86f8  895018                 -mov dword ptr [eax + 0x18], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004a86fb  89501c                 -mov dword ptr [eax + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004a86fe  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004a8701  75dd                   -jne 0x4a86e0
    if (!cpu.flags.zf)
    {
        goto L_0x004a86e0;
    }
    // 004a8703  8d40f0                 -lea eax, [eax - 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(-16) /* -0x10 */);
L_0x004a8706:
    // 004a8706  8d4010                 -lea eax, [eax + 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
L_0x004a8709:
    // 004a8709  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004a870b  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004a870e  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004a8711  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004a8714  8d4010                 -lea eax, [eax + 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
L_0x004a8717:
    // 004a8717  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8718  83e103                 +and ecx, 3
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/))));
    // 004a871b  7415                   -je 0x4a8732
    if (cpu.flags.zf)
    {
        goto L_0x004a8732;
    }
    // 004a871d  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004a871f  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004a8722  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a8723  740d                   -je 0x4a8732
    if (cpu.flags.zf)
    {
        goto L_0x004a8732;
    }
    // 004a8725  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004a8727  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004a872a  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a872b  7405                   -je 0x4a8732
    if (cpu.flags.zf)
    {
        goto L_0x004a8732;
    }
    // 004a872d  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004a872f  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
L_0x004a8732:
    // 004a8732  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a86c7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004a86c7;
    // 004a86c2  90                     -nop 
    ;
    // 004a86c3  90                     -nop 
    ;
    // 004a86c4  90                     -nop 
    ;
    // 004a86c5  90                     -nop 
    ;
    // 004a86c6  90                     -nop 
    ;
L_entry_0x004a86c7:
    // 004a86c7  09c9                   +or ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004a86c9  7467                   -je 0x4a8732
    if (cpu.flags.zf)
    {
        goto L_0x004a8732;
    }
L_0x004a86cb:
    // 004a86cb  a81f                   +test al, 0x1f
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 31 /*0x1f*/));
    // 004a86cd  7408                   -je 0x4a86d7
    if (cpu.flags.zf)
    {
        goto L_0x004a86d7;
    }
    // 004a86cf  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004a86d1  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004a86d4  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a86d5  75f4                   -jne 0x4a86cb
    if (!cpu.flags.zf)
    {
        goto L_0x004a86cb;
    }
L_0x004a86d7:
    // 004a86d7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a86d8  c1e902                 +shr ecx, 2
    {
        x86::reg8 tmp = 2 /*0x2*/ % 32;
        x86::reg32& op = cpu.ecx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 004a86db  743a                   -je 0x4a8717
    if (cpu.flags.zf)
    {
        goto L_0x004a8717;
    }
    // 004a86dd  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a86de  7429                   -je 0x4a8709
    if (cpu.flags.zf)
    {
        goto L_0x004a8709;
    }
L_0x004a86e0:
    // 004a86e0  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004a86e2  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004a86e5  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a86e6  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004a86e9  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004a86ec  7418                   -je 0x4a8706
    if (cpu.flags.zf)
    {
        goto L_0x004a8706;
    }
    // 004a86ee  385020                 +cmp byte ptr [eax + 0x20], dl
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(32) /* 0x20 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(cpu.dl));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a86f1  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004a86f4  895014                 -mov dword ptr [eax + 0x14], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004a86f7  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a86f8  895018                 -mov dword ptr [eax + 0x18], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004a86fb  89501c                 -mov dword ptr [eax + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004a86fe  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004a8701  75dd                   -jne 0x4a86e0
    if (!cpu.flags.zf)
    {
        goto L_0x004a86e0;
    }
    // 004a8703  8d40f0                 -lea eax, [eax - 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(-16) /* -0x10 */);
L_0x004a8706:
    // 004a8706  8d4010                 -lea eax, [eax + 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
L_0x004a8709:
    // 004a8709  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004a870b  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004a870e  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004a8711  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004a8714  8d4010                 -lea eax, [eax + 0x10]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(16) /* 0x10 */);
L_0x004a8717:
    // 004a8717  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8718  83e103                 +and ecx, 3
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/))));
    // 004a871b  7415                   -je 0x4a8732
    if (cpu.flags.zf)
    {
        goto L_0x004a8732;
    }
    // 004a871d  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004a871f  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004a8722  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a8723  740d                   -je 0x4a8732
    if (cpu.flags.zf)
    {
        goto L_0x004a8732;
    }
    // 004a8725  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004a8727  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004a872a  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a872b  7405                   -je 0x4a8732
    if (cpu.flags.zf)
    {
        goto L_0x004a8732;
    }
    // 004a872d  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004a872f  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
L_0x004a8732:
    // 004a8732  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a8740(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a8740  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a8741  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a8743  83f80f                 +cmp eax, 0xf
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
    // 004a8746  7313                   -jae 0x4a875b
    if (!cpu.flags.cf)
    {
        goto L_0x004a875b;
    }
    // 004a8748  83f804                 +cmp eax, 4
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
    // 004a874b  7333                   -jae 0x4a8780
    if (!cpu.flags.cf)
    {
        goto L_0x004a8780;
    }
    // 004a874d  83f801                 +cmp eax, 1
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
    // 004a8750  7505                   -jne 0x4a8757
    if (!cpu.flags.zf)
    {
        goto L_0x004a8757;
    }
    // 004a8752  ba79000000             -mov edx, 0x79
    cpu.edx = 121 /*0x79*/;
L_0x004a8757:
    // 004a8757  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a8759  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a875a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a875b:
    // 004a875b  763c                   -jbe 0x4a8799
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a8799;
    }
    // 004a875d  83f818                 +cmp eax, 0x18
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
    // 004a8760  730e                   -jae 0x4a8770
    if (!cpu.flags.cf)
    {
        goto L_0x004a8770;
    }
    // 004a8762  83f810                 +cmp eax, 0x10
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
    // 004a8765  75f0                   -jne 0x4a8757
    if (!cpu.flags.zf)
    {
        goto L_0x004a8757;
    }
    // 004a8767  ba78000000             -mov edx, 0x78
    cpu.edx = 120 /*0x78*/;
    // 004a876c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a876e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a876f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a8770:
    // 004a8770  7630                   -jbe 0x4a87a2
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a87a2;
    }
    // 004a8772  83f820                 +cmp eax, 0x20
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
    // 004a8775  75e0                   -jne 0x4a8757
    if (!cpu.flags.zf)
    {
        goto L_0x004a8757;
    }
    // 004a8777  ba7d000000             -mov edx, 0x7d
    cpu.edx = 125 /*0x7d*/;
    // 004a877c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a877e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a877f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a8780:
    // 004a8780  760e                   -jbe 0x4a8790
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a8790;
    }
    // 004a8782  83f808                 +cmp eax, 8
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
    // 004a8785  75d0                   -jne 0x4a8757
    if (!cpu.flags.zf)
    {
        goto L_0x004a8757;
    }
    // 004a8787  ba7b000000             -mov edx, 0x7b
    cpu.edx = 123 /*0x7b*/;
    // 004a878c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a878e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a878f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a8790:
    // 004a8790  ba7a000000             -mov edx, 0x7a
    cpu.edx = 122 /*0x7a*/;
    // 004a8795  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a8797  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8798  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a8799:
    // 004a8799  ba7e000000             -mov edx, 0x7e
    cpu.edx = 126 /*0x7e*/;
    // 004a879e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a87a0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a87a1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a87a2:
    // 004a87a2  ba7f000000             -mov edx, 0x7f
    cpu.edx = 127 /*0x7f*/;
    // 004a87a7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a87a9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a87aa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4a87ac(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a87ac  8b5e14                 -mov ebx, dword ptr [esi + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004a87af  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004a87b2  8b4e04                 -mov ecx, dword ptr [esi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004a87b5  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004a87b8  09d9                   -or ecx, ebx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a87ba  09c2                   -or edx, eax
    cpu.edx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004a87bc  8b7e08                 -mov edi, dword ptr [esi + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004a87bf  8b6e18                 -mov ebp, dword ptr [esi + 0x18]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004a87c2  09ca                   -or edx, ecx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a87c4  09ef                   -or edi, ebp
    cpu.edi |= x86::reg32(x86::sreg32(cpu.ebp));
    // 004a87c6  8b4e10                 -mov ecx, dword ptr [esi + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004a87c9  09fa                   -or edx, edi
    cpu.edx |= x86::reg32(x86::sreg32(cpu.edi));
    // 004a87cb  09ca                   +or edx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.edx |= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004a87cd  0f8410010000           -je 0x4a88e3
    if (cpu.flags.zf)
    {
        goto L_0x004a88e3;
    }
    // 004a87d3  8b4e04                 -mov ecx, dword ptr [esi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004a87d6  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004a87d9  8d3c03                 -lea edi, [ebx + eax]
    cpu.edi = x86::reg32(cpu.ebx + cpu.eax * 1);
    // 004a87dc  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004a87de  8d0411                 -lea eax, [ecx + edx]
    cpu.eax = x86::reg32(cpu.ecx + cpu.edx * 1);
    // 004a87e1  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a87e3  891dd8064e00           -mov dword ptr [0x4e06d8], ebx
    app->getMemory<x86::reg32>(x86::reg32(5113560) /* 0x4e06d8 */) = cpu.ebx;
    // 004a87e9  890ddc064e00           -mov dword ptr [0x4e06dc], ecx
    app->getMemory<x86::reg32>(x86::reg32(5113564) /* 0x4e06dc */) = cpu.ecx;
    // 004a87ef  8d2c38                 -lea ebp, [eax + edi]
    cpu.ebp = x86::reg32(cpu.eax + cpu.edi * 1);
    // 004a87f2  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004a87f4  db05d8064e00           -fild dword ptr [0x4e06d8]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5113560) /* 0x4e06d8 */))));
    // 004a87fa  db05dc064e00           -fild dword ptr [0x4e06dc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5113564) /* 0x4e06dc */))));
    // 004a8800  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004a8802  d80df0064e00           -fmul dword ptr [0x4e06f0]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5113584) /* 0x4e06f0 */));
    // 004a8808  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004a880a  dcc1                   -fadd st(1), st(0)
    cpu.fpu.st(1) += x86::Float(cpu.fpu.st(0));
    // 004a880c  d80dec064e00           -fmul dword ptr [0x4e06ec]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5113580) /* 0x4e06ec */));
    // 004a8812  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a8814  d80df4064e00           -fmul dword ptr [0x4e06f4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5113588) /* 0x4e06f4 */));
    // 004a881a  f72de8064e00           -imul dword ptr [0x4e06e8]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5113576) /* 0x4e06e8 */))));
    // 004a8820  dcc1                   -fadd st(1), st(0)
    cpu.fpu.st(1) += x86::Float(cpu.fpu.st(0));
    // 004a8822  deea                   -fsubp st(2)
    cpu.fpu.st(2) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004a8824  d805f8064e00           -fadd dword ptr [0x4e06f8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5113592) /* 0x4e06f8 */));
    // 004a882a  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a882c  d805f8064e00           -fadd dword ptr [0x4e06f8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5113592) /* 0x4e06f8 */));
    // 004a8832  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004a8835  8b5e18                 -mov ebx, dword ptr [esi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004a8838  d1e2                   -shl edx, 1
    cpu.edx <<= 1 /*0x1*/ % 32;
    // 004a883a  dd1de0064e00           -fstp qword ptr [0x4e06e0]
    app->getMemory<double>(x86::reg32(5113568) /* 0x4e06e0 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a8840  dd1dd8064e00           -fstp qword ptr [0x4e06d8]
    app->getMemory<double>(x86::reg32(5113560) /* 0x4e06d8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a8846  8b0dd8064e00           -mov ecx, dword ptr [0x4e06d8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5113560) /* 0x4e06d8 */);
    // 004a884c  8b3de0064e00           -mov edi, dword ptr [0x4e06e0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5113568) /* 0x4e06e0 */);
    // 004a8852  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a8854  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004a8856  01ef                   -add edi, ebp
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004a8858  890ddc064e00           -mov dword ptr [0x4e06dc], ecx
    app->getMemory<x86::reg32>(x86::reg32(5113564) /* 0x4e06dc */) = cpu.ecx;
    // 004a885e  8915e0064e00           -mov dword ptr [0x4e06e0], edx
    app->getMemory<x86::reg32>(x86::reg32(5113568) /* 0x4e06e0 */) = cpu.edx;
    // 004a8864  893de4064e00           -mov dword ptr [0x4e06e4], edi
    app->getMemory<x86::reg32>(x86::reg32(5113572) /* 0x4e06e4 */) = cpu.edi;
    // 004a886a  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 004a886c  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004a886f  8d3418                 -lea esi, [eax + ebx]
    cpu.esi = x86::reg32(cpu.eax + cpu.ebx * 1);
    // 004a8872  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a8874  8d1c11                 -lea ebx, [ecx + edx]
    cpu.ebx = x86::reg32(cpu.ecx + cpu.edx * 1);
    // 004a8877  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a8879  f72de8064e00           -imul dword ptr [0x4e06e8]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5113576) /* 0x4e06e8 */))));
    // 004a887f  d1e2                   -shl edx, 1
    cpu.edx <<= 1 /*0x1*/ % 32;
    // 004a8881  8b3dd4064e00           -mov edi, dword ptr [0x4e06d4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5113556) /* 0x4e06d4 */);
    // 004a8887  01d6                   -add esi, edx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a8889  8b2ddc064e00           -mov ebp, dword ptr [0x4e06dc]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5113564) /* 0x4e06dc */);
    // 004a888f  8d0411                 -lea eax, [ecx + edx]
    cpu.eax = x86::reg32(cpu.ecx + cpu.edx * 1);
    // 004a8892  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a8894  8d1433                 -lea edx, [ebx + esi]
    cpu.edx = x86::reg32(cpu.ebx + cpu.esi * 1);
    // 004a8897  29f3                   -sub ebx, esi
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004a8899  8d3429                 -lea esi, [ecx + ebp]
    cpu.esi = x86::reg32(cpu.ecx + cpu.ebp * 1);
    // 004a889c  29e9                   -sub ecx, ebp
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004a889e  8b2dd8064e00           -mov ebp, dword ptr [0x4e06d8]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5113560) /* 0x4e06d8 */);
    // 004a88a4  897748                 -mov dword ptr [edi + 0x48], esi
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(72) /* 0x48 */) = cpu.esi;
    // 004a88a7  8b35e0064e00           -mov esi, dword ptr [0x4e06e0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5113568) /* 0x4e06e0 */);
    // 004a88ad  898fb4000000           -mov dword ptr [edi + 0xb4], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(180) /* 0xb4 */) = cpu.ecx;
    // 004a88b3  8d0c2b                 -lea ecx, [ebx + ebp]
    cpu.ecx = x86::reg32(cpu.ebx + cpu.ebp * 1);
    // 004a88b6  29eb                   -sub ebx, ebp
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004a88b8  8b2de4064e00           -mov ebp, dword ptr [0x4e06e4]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5113572) /* 0x4e06e4 */);
    // 004a88be  894f6c                 -mov dword ptr [edi + 0x6c], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(108) /* 0x6c */) = cpu.ecx;
    // 004a88c1  899f90000000           -mov dword ptr [edi + 0x90], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(144) /* 0x90 */) = cpu.ebx;
    // 004a88c7  8d1c30                 -lea ebx, [eax + esi]
    cpu.ebx = x86::reg32(cpu.eax + cpu.esi * 1);
    // 004a88ca  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004a88cc  8d0c2a                 -lea ecx, [edx + ebp]
    cpu.ecx = x86::reg32(cpu.edx + cpu.ebp * 1);
    // 004a88cf  29ea                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004a88d1  890f                   -mov dword ptr [edi], ecx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.ecx;
    // 004a88d3  895f24                 -mov dword ptr [edi + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 004a88d6  8987d8000000           -mov dword ptr [edi + 0xd8], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(216) /* 0xd8 */) = cpu.eax;
    // 004a88dc  8997fc000000           -mov dword ptr [edi + 0xfc], edx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(252) /* 0xfc */) = cpu.edx;
    // 004a88e2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a88e3:
    // 004a88e3  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004a88e5  8b3dd4064e00           -mov edi, dword ptr [0x4e06d4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5113556) /* 0x4e06d4 */);
    // 004a88eb  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 004a88ed  894724                 -mov dword ptr [edi + 0x24], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 004a88f0  894748                 -mov dword ptr [edi + 0x48], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(72) /* 0x48 */) = cpu.eax;
    // 004a88f3  89476c                 -mov dword ptr [edi + 0x6c], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(108) /* 0x6c */) = cpu.eax;
    // 004a88f6  898790000000           -mov dword ptr [edi + 0x90], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(144) /* 0x90 */) = cpu.eax;
    // 004a88fc  8987b4000000           -mov dword ptr [edi + 0xb4], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(180) /* 0xb4 */) = cpu.eax;
    // 004a8902  8987d8000000           -mov dword ptr [edi + 0xd8], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(216) /* 0xd8 */) = cpu.eax;
    // 004a8908  8987fc000000           -mov dword ptr [edi + 0xfc], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(252) /* 0xfc */) = cpu.eax;
    // 004a890e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a890f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a890f  8b5e14                 -mov ebx, dword ptr [esi + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004a8912  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004a8915  8b4e04                 -mov ecx, dword ptr [esi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004a8918  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004a891b  8d3c03                 -lea edi, [ebx + eax]
    cpu.edi = x86::reg32(cpu.ebx + cpu.eax * 1);
    // 004a891e  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004a8920  8d0411                 -lea eax, [ecx + edx]
    cpu.eax = x86::reg32(cpu.ecx + cpu.edx * 1);
    // 004a8923  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a8925  891dd8064e00           -mov dword ptr [0x4e06d8], ebx
    app->getMemory<x86::reg32>(x86::reg32(5113560) /* 0x4e06d8 */) = cpu.ebx;
    // 004a892b  890ddc064e00           -mov dword ptr [0x4e06dc], ecx
    app->getMemory<x86::reg32>(x86::reg32(5113564) /* 0x4e06dc */) = cpu.ecx;
    // 004a8931  8d2c38                 -lea ebp, [eax + edi]
    cpu.ebp = x86::reg32(cpu.eax + cpu.edi * 1);
    // 004a8934  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004a8936  db05d8064e00           -fild dword ptr [0x4e06d8]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5113560) /* 0x4e06d8 */))));
    // 004a893c  db05dc064e00           -fild dword ptr [0x4e06dc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5113564) /* 0x4e06dc */))));
    // 004a8942  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004a8944  d80df0064e00           -fmul dword ptr [0x4e06f0]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5113584) /* 0x4e06f0 */));
    // 004a894a  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004a894c  dcc1                   -fadd st(1), st(0)
    cpu.fpu.st(1) += x86::Float(cpu.fpu.st(0));
    // 004a894e  d80dec064e00           -fmul dword ptr [0x4e06ec]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5113580) /* 0x4e06ec */));
    // 004a8954  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a8956  d80df4064e00           -fmul dword ptr [0x4e06f4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5113588) /* 0x4e06f4 */));
    // 004a895c  f72de8064e00           -imul dword ptr [0x4e06e8]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5113576) /* 0x4e06e8 */))));
    // 004a8962  dcc1                   -fadd st(1), st(0)
    cpu.fpu.st(1) += x86::Float(cpu.fpu.st(0));
    // 004a8964  deea                   -fsubp st(2)
    cpu.fpu.st(2) -= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004a8966  d805f8064e00           -fadd dword ptr [0x4e06f8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5113592) /* 0x4e06f8 */));
    // 004a896c  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a896e  d805f8064e00           -fadd dword ptr [0x4e06f8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(x86::reg32(5113592) /* 0x4e06f8 */));
    // 004a8974  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004a8977  8b5e18                 -mov ebx, dword ptr [esi + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004a897a  d1e2                   -shl edx, 1
    cpu.edx <<= 1 /*0x1*/ % 32;
    // 004a897c  dd1de0064e00           -fstp qword ptr [0x4e06e0]
    app->getMemory<double>(x86::reg32(5113568) /* 0x4e06e0 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a8982  dd1dd8064e00           -fstp qword ptr [0x4e06d8]
    app->getMemory<double>(x86::reg32(5113560) /* 0x4e06d8 */) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a8988  8b0dd8064e00           -mov ecx, dword ptr [0x4e06d8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5113560) /* 0x4e06d8 */);
    // 004a898e  8b3de0064e00           -mov edi, dword ptr [0x4e06e0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5113568) /* 0x4e06e0 */);
    // 004a8994  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a8996  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004a8998  01ef                   -add edi, ebp
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004a899a  890ddc064e00           -mov dword ptr [0x4e06dc], ecx
    app->getMemory<x86::reg32>(x86::reg32(5113564) /* 0x4e06dc */) = cpu.ecx;
    // 004a89a0  8915e0064e00           -mov dword ptr [0x4e06e0], edx
    app->getMemory<x86::reg32>(x86::reg32(5113568) /* 0x4e06e0 */) = cpu.edx;
    // 004a89a6  893de4064e00           -mov dword ptr [0x4e06e4], edi
    app->getMemory<x86::reg32>(x86::reg32(5113572) /* 0x4e06e4 */) = cpu.edi;
    // 004a89ac  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 004a89ae  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004a89b1  8d3418                 -lea esi, [eax + ebx]
    cpu.esi = x86::reg32(cpu.eax + cpu.ebx * 1);
    // 004a89b4  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a89b6  8d1c11                 -lea ebx, [ecx + edx]
    cpu.ebx = x86::reg32(cpu.ecx + cpu.edx * 1);
    // 004a89b9  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a89bb  f72de8064e00           -imul dword ptr [0x4e06e8]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5113576) /* 0x4e06e8 */))));
    // 004a89c1  d1e2                   -shl edx, 1
    cpu.edx <<= 1 /*0x1*/ % 32;
    // 004a89c3  8b3dd4064e00           -mov edi, dword ptr [0x4e06d4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5113556) /* 0x4e06d4 */);
    // 004a89c9  01d6                   -add esi, edx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a89cb  8b2ddc064e00           -mov ebp, dword ptr [0x4e06dc]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5113564) /* 0x4e06dc */);
    // 004a89d1  8d0411                 -lea eax, [ecx + edx]
    cpu.eax = x86::reg32(cpu.ecx + cpu.edx * 1);
    // 004a89d4  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a89d6  8d1433                 -lea edx, [ebx + esi]
    cpu.edx = x86::reg32(cpu.ebx + cpu.esi * 1);
    // 004a89d9  29f3                   -sub ebx, esi
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004a89db  8d3429                 -lea esi, [ecx + ebp]
    cpu.esi = x86::reg32(cpu.ecx + cpu.ebp * 1);
    // 004a89de  29e9                   -sub ecx, ebp
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004a89e0  8b2dd8064e00           -mov ebp, dword ptr [0x4e06d8]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5113560) /* 0x4e06d8 */);
    // 004a89e6  897708                 -mov dword ptr [edi + 8], esi
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 004a89e9  8b35e0064e00           -mov esi, dword ptr [0x4e06e0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5113568) /* 0x4e06e0 */);
    // 004a89ef  894f14                 -mov dword ptr [edi + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 004a89f2  8d0c2b                 -lea ecx, [ebx + ebp]
    cpu.ecx = x86::reg32(cpu.ebx + cpu.ebp * 1);
    // 004a89f5  29eb                   -sub ebx, ebp
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004a89f7  8b2de4064e00           -mov ebp, dword ptr [0x4e06e4]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5113572) /* 0x4e06e4 */);
    // 004a89fd  894f0c                 -mov dword ptr [edi + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004a8a00  895f10                 -mov dword ptr [edi + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 004a8a03  8d1c30                 -lea ebx, [eax + esi]
    cpu.ebx = x86::reg32(cpu.eax + cpu.esi * 1);
    // 004a8a06  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004a8a08  8d0c2a                 -lea ecx, [edx + ebp]
    cpu.ecx = x86::reg32(cpu.edx + cpu.ebp * 1);
    // 004a8a0b  29ea                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004a8a0d  890f                   -mov dword ptr [edi], ecx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.ecx;
    // 004a8a0f  895f04                 -mov dword ptr [edi + 4], ebx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004a8a12  894718                 -mov dword ptr [edi + 0x18], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004a8a15  89571c                 -mov dword ptr [edi + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004a8a18  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a8a19(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a8a19  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a8a1a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a8a1b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a8a1c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a8a1d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a8a1e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a8a1f  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 004a8a22  8915d0064e00           -mov dword ptr [0x4e06d0], edx
    app->getMemory<x86::reg32>(x86::reg32(5113552) /* 0x4e06d0 */) = cpu.edx;
    // 004a8a28  be1c084e00             -mov esi, 0x4e081c
    cpu.esi = 5113884 /*0x4e081c*/;
    // 004a8a2d  c705d4064e00fc064e00   -mov dword ptr [0x4e06d4], 0x4e06fc
    app->getMemory<x86::reg32>(x86::reg32(5113556) /* 0x4e06d4 */) = 5113596 /*0x4e06fc*/;
    // 004a8a37  e870fdffff             -call 0x4a87ac
    cpu.esp -= 4;
    sub_4a87ac(app, cpu);
    if (cpu.terminate) return;
    // 004a8a3c  be3c084e00             -mov esi, 0x4e083c
    cpu.esi = 5113916 /*0x4e083c*/;
    // 004a8a41  c705d4064e0000074e00   -mov dword ptr [0x4e06d4], 0x4e0700
    app->getMemory<x86::reg32>(x86::reg32(5113556) /* 0x4e06d4 */) = 5113600 /*0x4e0700*/;
    // 004a8a4b  e85cfdffff             -call 0x4a87ac
    cpu.esp -= 4;
    sub_4a87ac(app, cpu);
    if (cpu.terminate) return;
    // 004a8a50  be5c084e00             -mov esi, 0x4e085c
    cpu.esi = 5113948 /*0x4e085c*/;
    // 004a8a55  c705d4064e0004074e00   -mov dword ptr [0x4e06d4], 0x4e0704
    app->getMemory<x86::reg32>(x86::reg32(5113556) /* 0x4e06d4 */) = 5113604 /*0x4e0704*/;
    // 004a8a5f  e848fdffff             -call 0x4a87ac
    cpu.esp -= 4;
    sub_4a87ac(app, cpu);
    if (cpu.terminate) return;
    // 004a8a64  be7c084e00             -mov esi, 0x4e087c
    cpu.esi = 5113980 /*0x4e087c*/;
    // 004a8a69  c705d4064e0008074e00   -mov dword ptr [0x4e06d4], 0x4e0708
    app->getMemory<x86::reg32>(x86::reg32(5113556) /* 0x4e06d4 */) = 5113608 /*0x4e0708*/;
    // 004a8a73  e834fdffff             -call 0x4a87ac
    cpu.esp -= 4;
    sub_4a87ac(app, cpu);
    if (cpu.terminate) return;
    // 004a8a78  be9c084e00             -mov esi, 0x4e089c
    cpu.esi = 5114012 /*0x4e089c*/;
    // 004a8a7d  c705d4064e000c074e00   -mov dword ptr [0x4e06d4], 0x4e070c
    app->getMemory<x86::reg32>(x86::reg32(5113556) /* 0x4e06d4 */) = 5113612 /*0x4e070c*/;
    // 004a8a87  e820fdffff             -call 0x4a87ac
    cpu.esp -= 4;
    sub_4a87ac(app, cpu);
    if (cpu.terminate) return;
    // 004a8a8c  bebc084e00             -mov esi, 0x4e08bc
    cpu.esi = 5114044 /*0x4e08bc*/;
    // 004a8a91  c705d4064e0010074e00   -mov dword ptr [0x4e06d4], 0x4e0710
    app->getMemory<x86::reg32>(x86::reg32(5113556) /* 0x4e06d4 */) = 5113616 /*0x4e0710*/;
    // 004a8a9b  e80cfdffff             -call 0x4a87ac
    cpu.esp -= 4;
    sub_4a87ac(app, cpu);
    if (cpu.terminate) return;
    // 004a8aa0  bedc084e00             -mov esi, 0x4e08dc
    cpu.esi = 5114076 /*0x4e08dc*/;
    // 004a8aa5  c705d4064e0014074e00   -mov dword ptr [0x4e06d4], 0x4e0714
    app->getMemory<x86::reg32>(x86::reg32(5113556) /* 0x4e06d4 */) = 5113620 /*0x4e0714*/;
    // 004a8aaf  e8f8fcffff             -call 0x4a87ac
    cpu.esp -= 4;
    sub_4a87ac(app, cpu);
    if (cpu.terminate) return;
    // 004a8ab4  befc084e00             -mov esi, 0x4e08fc
    cpu.esi = 5114108 /*0x4e08fc*/;
    // 004a8ab9  c705d4064e0018074e00   -mov dword ptr [0x4e06d4], 0x4e0718
    app->getMemory<x86::reg32>(x86::reg32(5113556) /* 0x4e06d4 */) = 5113624 /*0x4e0718*/;
    // 004a8ac3  e8e4fcffff             -call 0x4a87ac
    cpu.esp -= 4;
    sub_4a87ac(app, cpu);
    if (cpu.terminate) return;
    // 004a8ac8  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8ac9  befc064e00             -mov esi, 0x4e06fc
    cpu.esi = 5113596 /*0x4e06fc*/;
    // 004a8ace  a3d4064e00             -mov dword ptr [0x4e06d4], eax
    app->getMemory<x86::reg32>(x86::reg32(5113556) /* 0x4e06d4 */) = cpu.eax;
    // 004a8ad3  e837feffff             -call 0x4a890f
    cpu.esp -= 4;
    sub_4a890f(app, cpu);
    if (cpu.terminate) return;
    // 004a8ad8  a1d4064e00             -mov eax, dword ptr [0x4e06d4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5113556) /* 0x4e06d4 */);
    // 004a8add  8b15d0064e00           -mov edx, dword ptr [0x4e06d0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5113552) /* 0x4e06d0 */);
    // 004a8ae3  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a8ae5  be20074e00             -mov esi, 0x4e0720
    cpu.esi = 5113632 /*0x4e0720*/;
    // 004a8aea  a3d4064e00             -mov dword ptr [0x4e06d4], eax
    app->getMemory<x86::reg32>(x86::reg32(5113556) /* 0x4e06d4 */) = cpu.eax;
    // 004a8aef  e81bfeffff             -call 0x4a890f
    cpu.esp -= 4;
    sub_4a890f(app, cpu);
    if (cpu.terminate) return;
    // 004a8af4  a1d4064e00             -mov eax, dword ptr [0x4e06d4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5113556) /* 0x4e06d4 */);
    // 004a8af9  8b15d0064e00           -mov edx, dword ptr [0x4e06d0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5113552) /* 0x4e06d0 */);
    // 004a8aff  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a8b01  be44074e00             -mov esi, 0x4e0744
    cpu.esi = 5113668 /*0x4e0744*/;
    // 004a8b06  a3d4064e00             -mov dword ptr [0x4e06d4], eax
    app->getMemory<x86::reg32>(x86::reg32(5113556) /* 0x4e06d4 */) = cpu.eax;
    // 004a8b0b  e8fffdffff             -call 0x4a890f
    cpu.esp -= 4;
    sub_4a890f(app, cpu);
    if (cpu.terminate) return;
    // 004a8b10  a1d4064e00             -mov eax, dword ptr [0x4e06d4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5113556) /* 0x4e06d4 */);
    // 004a8b15  8b15d0064e00           -mov edx, dword ptr [0x4e06d0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5113552) /* 0x4e06d0 */);
    // 004a8b1b  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a8b1d  be68074e00             -mov esi, 0x4e0768
    cpu.esi = 5113704 /*0x4e0768*/;
    // 004a8b22  a3d4064e00             -mov dword ptr [0x4e06d4], eax
    app->getMemory<x86::reg32>(x86::reg32(5113556) /* 0x4e06d4 */) = cpu.eax;
    // 004a8b27  e8e3fdffff             -call 0x4a890f
    cpu.esp -= 4;
    sub_4a890f(app, cpu);
    if (cpu.terminate) return;
    // 004a8b2c  a1d4064e00             -mov eax, dword ptr [0x4e06d4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5113556) /* 0x4e06d4 */);
    // 004a8b31  8b15d0064e00           -mov edx, dword ptr [0x4e06d0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5113552) /* 0x4e06d0 */);
    // 004a8b37  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a8b39  be8c074e00             -mov esi, 0x4e078c
    cpu.esi = 5113740 /*0x4e078c*/;
    // 004a8b3e  a3d4064e00             -mov dword ptr [0x4e06d4], eax
    app->getMemory<x86::reg32>(x86::reg32(5113556) /* 0x4e06d4 */) = cpu.eax;
    // 004a8b43  e8c7fdffff             -call 0x4a890f
    cpu.esp -= 4;
    sub_4a890f(app, cpu);
    if (cpu.terminate) return;
    // 004a8b48  a1d4064e00             -mov eax, dword ptr [0x4e06d4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5113556) /* 0x4e06d4 */);
    // 004a8b4d  8b15d0064e00           -mov edx, dword ptr [0x4e06d0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5113552) /* 0x4e06d0 */);
    // 004a8b53  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a8b55  beb0074e00             -mov esi, 0x4e07b0
    cpu.esi = 5113776 /*0x4e07b0*/;
    // 004a8b5a  a3d4064e00             -mov dword ptr [0x4e06d4], eax
    app->getMemory<x86::reg32>(x86::reg32(5113556) /* 0x4e06d4 */) = cpu.eax;
    // 004a8b5f  e8abfdffff             -call 0x4a890f
    cpu.esp -= 4;
    sub_4a890f(app, cpu);
    if (cpu.terminate) return;
    // 004a8b64  a1d4064e00             -mov eax, dword ptr [0x4e06d4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5113556) /* 0x4e06d4 */);
    // 004a8b69  8b15d0064e00           -mov edx, dword ptr [0x4e06d0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5113552) /* 0x4e06d0 */);
    // 004a8b6f  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a8b71  bed4074e00             -mov esi, 0x4e07d4
    cpu.esi = 5113812 /*0x4e07d4*/;
    // 004a8b76  a3d4064e00             -mov dword ptr [0x4e06d4], eax
    app->getMemory<x86::reg32>(x86::reg32(5113556) /* 0x4e06d4 */) = cpu.eax;
    // 004a8b7b  e88ffdffff             -call 0x4a890f
    cpu.esp -= 4;
    sub_4a890f(app, cpu);
    if (cpu.terminate) return;
    // 004a8b80  a1d4064e00             -mov eax, dword ptr [0x4e06d4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5113556) /* 0x4e06d4 */);
    // 004a8b85  8b15d0064e00           -mov edx, dword ptr [0x4e06d0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5113552) /* 0x4e06d0 */);
    // 004a8b8b  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a8b8d  bef8074e00             -mov esi, 0x4e07f8
    cpu.esi = 5113848 /*0x4e07f8*/;
    // 004a8b92  a3d4064e00             -mov dword ptr [0x4e06d4], eax
    app->getMemory<x86::reg32>(x86::reg32(5113556) /* 0x4e06d4 */) = cpu.eax;
    // 004a8b97  e873fdffff             -call 0x4a890f
    cpu.esp -= 4;
    sub_4a890f(app, cpu);
    if (cpu.terminate) return;
    // 004a8b9c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8b9d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8b9e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8b9f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8ba0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8ba1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4a8ba4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a8ba4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a8ba5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a8ba6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a8ba7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a8ba8  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a8baa  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a8bac  668b18                 -mov bx, word ptr [eax]
    cpu.bx = app->getMemory<x86::reg16>(cpu.eax);
    // 004a8baf  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004a8bb1  c1e310                 -shl ebx, 0x10
    cpu.ebx <<= 16 /*0x10*/ % 32;
    // 004a8bb4  bd10000000             -mov ebp, 0x10
    cpu.ebp = 16 /*0x10*/;
    // 004a8bb9  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004a8bbc  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x004a8bbe:
    // 004a8bbe  c1e816                 -shr eax, 0x16
    cpu.eax >>= 22 /*0x16*/ % 32;
    // 004a8bc1  3dff010000             +cmp eax, 0x1ff
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(511 /*0x1ff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a8bc6  0f84de000000           -je 0x4a8caa
    if (cpu.flags.zf)
    {
        goto L_0x004a8caa;
    }
    // 004a8bcc  668907                 -mov word ptr [edi], ax
    app->getMemory<x86::reg16>(cpu.edi) = cpu.ax;
    // 004a8bcf  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004a8bd2  c1e30a                 -shl ebx, 0xa
    cpu.ebx <<= 10 /*0xa*/ % 32;
    // 004a8bd5  83ed0a                 -sub ebp, 0xa
    (cpu.ebp) -= x86::reg32(x86::sreg32(10 /*0xa*/));
    // 004a8bd8  83fd10                 +cmp ebp, 0x10
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a8bdb  7d16                   -jge 0x4a8bf3
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a8bf3;
    }
    // 004a8bdd  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a8bdf  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 004a8be4  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 004a8be7  29e9                   -sub ecx, ebp
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004a8be9  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004a8beb  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004a8bee  09c3                   -or ebx, eax
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004a8bf0  83c510                 -add ebp, 0x10
    (cpu.ebp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x004a8bf3:
    // 004a8bf3  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
L_0x004a8bf5:
    // 004a8bf5  c1ea13                 -shr edx, 0x13
    cpu.edx >>= 19 /*0x13*/ % 32;
    // 004a8bf8  8b04953c235600         -mov eax, dword ptr [edx*4 + 0x56233c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5645116) /* 0x56233c */ + cpu.edx * 4);
    // 004a8bff  a900002000             +test eax, 0x200000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2097152 /*0x200000*/));
    // 004a8c04  7461                   -je 0x4a8c67
    if (cpu.flags.zf)
    {
        goto L_0x004a8c67;
    }
    // 004a8c06  a900000100             +test eax, 0x10000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 65536 /*0x10000*/));
    // 004a8c0b  742d                   -je 0x4a8c3a
    if (cpu.flags.zf)
    {
        goto L_0x004a8c3a;
    }
    // 004a8c0d  c1e306                 -shl ebx, 6
    cpu.ebx <<= 6 /*0x6*/ % 32;
    // 004a8c10  83ed06                 -sub ebp, 6
    (cpu.ebp) -= x86::reg32(x86::sreg32(6 /*0x6*/));
    // 004a8c13  83fd10                 +cmp ebp, 0x10
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a8c16  7d16                   -jge 0x4a8c2e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a8c2e;
    }
    // 004a8c18  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a8c1a  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 004a8c1f  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 004a8c22  29e9                   -sub ecx, ebp
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004a8c24  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004a8c26  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004a8c29  09c3                   -or ebx, eax
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004a8c2b  83c510                 -add ebp, 0x10
    (cpu.ebp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x004a8c2e:
    // 004a8c2e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a8c30  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a8c33  0d00001000             +or eax, 0x100000
    cpu.clear_co();
    cpu.set_szp((cpu.eax |= x86::reg32(x86::sreg32(1048576 /*0x100000*/))));
    // 004a8c38  eb2d                   -jmp 0x4a8c67
    goto L_0x004a8c67;
L_0x004a8c3a:
    // 004a8c3a  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 004a8c3d  83ed08                 -sub ebp, 8
    (cpu.ebp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a8c40  83fd10                 +cmp ebp, 0x10
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a8c43  7d16                   -jge 0x4a8c5b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a8c5b;
    }
    // 004a8c45  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a8c47  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 004a8c4c  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 004a8c4f  29e9                   -sub ecx, ebp
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004a8c51  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004a8c53  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004a8c56  09c3                   -or ebx, eax
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.eax));
    // 004a8c58  83c510                 -add ebp, 0x10
    (cpu.ebp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x004a8c5b:
    // 004a8c5b  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004a8c5d  c1ea17                 -shr edx, 0x17
    cpu.edx >>= 23 /*0x17*/ % 32;
    // 004a8c60  8b04953ca35600         -mov eax, dword ptr [edx*4 + 0x56a33c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5677884) /* 0x56a33c */ + cpu.edx * 4);
L_0x004a8c67:
    // 004a8c67  668907                 -mov word ptr [edi], ax
    app->getMemory<x86::reg16>(cpu.edi) = cpu.ax;
    // 004a8c6a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a8c6c  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004a8c6f  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004a8c72  d3e3                   -shl ebx, cl
    cpu.ebx <<= cpu.cl % 32;
    // 004a8c74  29cd                   -sub ebp, ecx
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a8c76  83fd10                 +cmp ebp, 0x10
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a8c79  7d16                   -jge 0x4a8c91
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a8c91;
    }
    // 004a8c7b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a8c7d  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 004a8c82  668b16                 -mov dx, word ptr [esi]
    cpu.dx = app->getMemory<x86::reg16>(cpu.esi);
    // 004a8c85  29e9                   -sub ecx, ebp
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004a8c87  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 004a8c89  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004a8c8c  09d3                   -or ebx, edx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.edx));
    // 004a8c8e  83c510                 -add ebp, 0x10
    (cpu.ebp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x004a8c91:
    // 004a8c91  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004a8c96  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004a8c98  3d00fe0000             +cmp eax, 0xfe00
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65024 /*0xfe00*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a8c9d  0f8552ffffff           -jne 0x4a8bf5
    if (!cpu.flags.zf)
    {
        goto L_0x004a8bf5;
    }
    // 004a8ca3  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a8ca5  e914ffffff             -jmp 0x4a8bbe
    goto L_0x004a8bbe;
L_0x004a8caa:
    // 004a8caa  66c70700fe             -mov word ptr [edi], 0xfe00
    app->getMemory<x86::reg16>(cpu.edi) = 65024 /*0xfe00*/;
    // 004a8caf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8cb0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8cb1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8cb2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8cb3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a8cb4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a8cb4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a8cb5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a8cb6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a8cb7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a8cb8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a8cb9  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a8cba  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a8cbc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a8cbe  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 004a8cc1  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a8cc3  c1e016                 -shl eax, 0x16
    cpu.eax <<= 22 /*0x16*/ % 32;
    // 004a8cc6  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004a8ccb  c1f816                 -sar eax, 0x16
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (22 /*0x16*/ % 32));
    // 004a8cce  bf3f000000             -mov edi, 0x3f
    cpu.edi = 63 /*0x3f*/;
    // 004a8cd3  f72d3cab5600           -imul dword ptr [0x56ab3c]
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5679932) /* 0x56ab3c */))));
    // 004a8cd9  a31c084e00             -mov dword ptr [0x4e081c], eax
    app->getMemory<x86::reg32>(x86::reg32(5113884) /* 0x4e081c */) = cpu.eax;
    // 004a8cde  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x004a8ce0:
    // 004a8ce0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a8ce2  668b044e               -mov ax, word ptr [esi + ecx*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.ecx * 2);
    // 004a8ce6  41                     -inc ecx
    (cpu.ecx)++;
    // 004a8ce7  3d00fe0000             +cmp eax, 0xfe00
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65024 /*0xfe00*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a8cec  7436                   -je 0x4a8d24
    if (cpu.flags.zf)
    {
        goto L_0x004a8d24;
    }
    // 004a8cee  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a8cf0  8a9fe4cc4d00           -mov bl, byte ptr [edi + 0x4dcce4]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(5098724) /* 0x4dcce4 */);
    // 004a8cf6  c1ea0a                 +shr edx, 0xa
    {
        x86::reg8 tmp = 10 /*0xa*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 004a8cf9  7412                   -je 0x4a8d0d
    if (cpu.flags.zf)
    {
        goto L_0x004a8d0d;
    }
L_0x004a8cfb:
    // 004a8cfb  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a8cfc  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a8cfd  892c9d1c084e00         -mov dword ptr [ebx*4 + 0x4e081c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5113884) /* 0x4e081c */ + cpu.ebx * 4) = cpu.ebp;
    // 004a8d04  90                     -nop 
    ;
    // 004a8d05  8a9fe4cc4d00           -mov bl, byte ptr [edi + 0x4dcce4]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(5098724) /* 0x4dcce4 */);
    // 004a8d0b  75ee                   -jne 0x4a8cfb
    if (!cpu.flags.zf)
    {
        goto L_0x004a8cfb;
    }
L_0x004a8d0d:
    // 004a8d0d  c1e016                 -shl eax, 0x16
    cpu.eax <<= 22 /*0x16*/ % 32;
    // 004a8d10  c1f816                 -sar eax, 0x16
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (22 /*0x16*/ % 32));
    // 004a8d13  4f                     -dec edi
    (cpu.edi)--;
    // 004a8d14  f72c9d3cab5600         +imul dword ptr [ebx*4 + 0x56ab3c]
    {
        cpu.edx_eax = x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5679932) /* 0x56ab3c */ + cpu.ebx * 4)));
        cpu.flags.of = cpu.flags.cf = (static_cast<x86::sreg64>(cpu.edx_eax) != x86::sreg64(static_cast<x86::sreg32>(cpu.eax)));
    }
    // 004a8d1b  89049d1c084e00         -mov dword ptr [ebx*4 + 0x4e081c], eax
    app->getMemory<x86::reg32>(x86::reg32(5113884) /* 0x4e081c */ + cpu.ebx * 4) = cpu.eax;
    // 004a8d22  ebbc                   -jmp 0x4a8ce0
    goto L_0x004a8ce0;
L_0x004a8d24:
    // 004a8d24  8a9fe4cc4d00           -mov bl, byte ptr [edi + 0x4dcce4]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(5098724) /* 0x4dcce4 */);
L_0x004a8d2a:
    // 004a8d2a  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a8d2b  7810                   -js 0x4a8d3d
    if (cpu.flags.sf)
    {
        goto L_0x004a8d3d;
    }
    // 004a8d2d  892c9d1c084e00         -mov dword ptr [ebx*4 + 0x4e081c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5113884) /* 0x4e081c */ + cpu.ebx * 4) = cpu.ebp;
    // 004a8d34  90                     -nop 
    ;
    // 004a8d35  8a9fe4cc4d00           -mov bl, byte ptr [edi + 0x4dcce4]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(5098724) /* 0x4dcce4 */);
    // 004a8d3b  ebed                   -jmp 0x4a8d2a
    goto L_0x004a8d2a;
L_0x004a8d3d:
    // 004a8d3d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a8d3f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8d40  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8d41  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8d42  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8d43  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8d44  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8d45  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a8d46(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a8d46  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a8d47  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a8d48  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a8d49  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a8d4a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a8d4c  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004a8d4e  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004a8d50  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a8d52  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a8d54  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a8d56  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a8d58  8a4602                 -mov al, byte ptr [esi + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 004a8d5b  8a9f02010000           -mov bl, byte ptr [edi + 0x102]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(258) /* 0x102 */);
    // 004a8d61  8a4e06                 -mov cl, byte ptr [esi + 6]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 004a8d64  8a5702                 -mov dl, byte ptr [edi + 2]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */);
    // 004a8d67  8a803cac5600           -mov al, byte ptr [eax + 0x56ac3c]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5680188) /* 0x56ac3c */);
    // 004a8d6d  8a9b3cac5600           -mov bl, byte ptr [ebx + 0x56ac3c]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5680188) /* 0x56ac3c */);
    // 004a8d73  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004a8d76  8a893cac5600           -mov cl, byte ptr [ecx + 0x56ac3c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5680188) /* 0x56ac3c */);
    // 004a8d7c  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 004a8d7f  8a923cac5600           -mov dl, byte ptr [edx + 0x56ac3c]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5680188) /* 0x56ac3c */);
    // 004a8d85  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a8d87  09d3                   -or ebx, edx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.edx));
    // 004a8d89  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004a8d8c  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a8d8e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a8d90  894500                 -mov dword ptr [ebp], eax
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
    // 004a8d93  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a8d95  8a460a                 -mov al, byte ptr [esi + 0xa]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(10) /* 0xa */);
    // 004a8d98  8a9f06010000           -mov bl, byte ptr [edi + 0x106]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(262) /* 0x106 */);
    // 004a8d9e  8a4e0e                 -mov cl, byte ptr [esi + 0xe]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(14) /* 0xe */);
    // 004a8da1  8a5706                 -mov dl, byte ptr [edi + 6]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(6) /* 0x6 */);
    // 004a8da4  8a803cac5600           -mov al, byte ptr [eax + 0x56ac3c]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5680188) /* 0x56ac3c */);
    // 004a8daa  8a9b3cac5600           -mov bl, byte ptr [ebx + 0x56ac3c]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5680188) /* 0x56ac3c */);
    // 004a8db0  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004a8db3  8a893cac5600           -mov cl, byte ptr [ecx + 0x56ac3c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5680188) /* 0x56ac3c */);
    // 004a8db9  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 004a8dbc  8a923cac5600           -mov dl, byte ptr [edx + 0x56ac3c]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5680188) /* 0x56ac3c */);
    // 004a8dc2  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a8dc4  09d3                   -or ebx, edx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.edx));
    // 004a8dc6  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004a8dc9  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a8dcb  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a8dcd  894504                 -mov dword ptr [ebp + 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004a8dd0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a8dd2  8a4612                 -mov al, byte ptr [esi + 0x12]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(18) /* 0x12 */);
    // 004a8dd5  8a9f0a010000           -mov bl, byte ptr [edi + 0x10a]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(266) /* 0x10a */);
    // 004a8ddb  8a4e16                 -mov cl, byte ptr [esi + 0x16]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(22) /* 0x16 */);
    // 004a8dde  8a570a                 -mov dl, byte ptr [edi + 0xa]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(10) /* 0xa */);
    // 004a8de1  8a803cac5600           -mov al, byte ptr [eax + 0x56ac3c]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5680188) /* 0x56ac3c */);
    // 004a8de7  8a9b3cac5600           -mov bl, byte ptr [ebx + 0x56ac3c]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5680188) /* 0x56ac3c */);
    // 004a8ded  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004a8df0  8a893cac5600           -mov cl, byte ptr [ecx + 0x56ac3c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5680188) /* 0x56ac3c */);
    // 004a8df6  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 004a8df9  8a923cac5600           -mov dl, byte ptr [edx + 0x56ac3c]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5680188) /* 0x56ac3c */);
    // 004a8dff  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a8e01  09d3                   -or ebx, edx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.edx));
    // 004a8e03  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004a8e06  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a8e08  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a8e0a  894508                 -mov dword ptr [ebp + 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004a8e0d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a8e0f  8a461a                 -mov al, byte ptr [esi + 0x1a]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(26) /* 0x1a */);
    // 004a8e12  8a9f0e010000           -mov bl, byte ptr [edi + 0x10e]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(270) /* 0x10e */);
    // 004a8e18  8a4e1e                 -mov cl, byte ptr [esi + 0x1e]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(30) /* 0x1e */);
    // 004a8e1b  8a570e                 -mov dl, byte ptr [edi + 0xe]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(14) /* 0xe */);
    // 004a8e1e  8a803cac5600           -mov al, byte ptr [eax + 0x56ac3c]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5680188) /* 0x56ac3c */);
    // 004a8e24  8a9b3cac5600           -mov bl, byte ptr [ebx + 0x56ac3c]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5680188) /* 0x56ac3c */);
    // 004a8e2a  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004a8e2d  8a893cac5600           -mov cl, byte ptr [ecx + 0x56ac3c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5680188) /* 0x56ac3c */);
    // 004a8e33  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 004a8e36  8a923cac5600           -mov dl, byte ptr [edx + 0x56ac3c]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5680188) /* 0x56ac3c */);
    // 004a8e3c  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a8e3e  09d3                   -or ebx, edx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.edx));
    // 004a8e40  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004a8e43  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a8e45  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a8e47  89450c                 -mov dword ptr [ebp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004a8e4a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a8e4c  8a4622                 -mov al, byte ptr [esi + 0x22]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(34) /* 0x22 */);
    // 004a8e4f  8a9f12010000           -mov bl, byte ptr [edi + 0x112]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(274) /* 0x112 */);
    // 004a8e55  8a4e26                 -mov cl, byte ptr [esi + 0x26]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(38) /* 0x26 */);
    // 004a8e58  8a5712                 -mov dl, byte ptr [edi + 0x12]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(18) /* 0x12 */);
    // 004a8e5b  8a803cac5600           -mov al, byte ptr [eax + 0x56ac3c]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5680188) /* 0x56ac3c */);
    // 004a8e61  8a9b3cac5600           -mov bl, byte ptr [ebx + 0x56ac3c]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5680188) /* 0x56ac3c */);
    // 004a8e67  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004a8e6a  8a893cac5600           -mov cl, byte ptr [ecx + 0x56ac3c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5680188) /* 0x56ac3c */);
    // 004a8e70  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 004a8e73  8a923cac5600           -mov dl, byte ptr [edx + 0x56ac3c]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5680188) /* 0x56ac3c */);
    // 004a8e79  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a8e7b  09d3                   -or ebx, edx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.edx));
    // 004a8e7d  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004a8e80  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a8e82  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a8e84  894510                 -mov dword ptr [ebp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004a8e87  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a8e89  8a462a                 -mov al, byte ptr [esi + 0x2a]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(42) /* 0x2a */);
    // 004a8e8c  8a9f16010000           -mov bl, byte ptr [edi + 0x116]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(278) /* 0x116 */);
    // 004a8e92  8a4e2e                 -mov cl, byte ptr [esi + 0x2e]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(46) /* 0x2e */);
    // 004a8e95  8a5716                 -mov dl, byte ptr [edi + 0x16]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(22) /* 0x16 */);
    // 004a8e98  8a803cac5600           -mov al, byte ptr [eax + 0x56ac3c]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5680188) /* 0x56ac3c */);
    // 004a8e9e  8a9b3cac5600           -mov bl, byte ptr [ebx + 0x56ac3c]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5680188) /* 0x56ac3c */);
    // 004a8ea4  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004a8ea7  8a893cac5600           -mov cl, byte ptr [ecx + 0x56ac3c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5680188) /* 0x56ac3c */);
    // 004a8ead  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 004a8eb0  8a923cac5600           -mov dl, byte ptr [edx + 0x56ac3c]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5680188) /* 0x56ac3c */);
    // 004a8eb6  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a8eb8  09d3                   -or ebx, edx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.edx));
    // 004a8eba  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004a8ebd  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a8ebf  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a8ec1  894514                 -mov dword ptr [ebp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004a8ec4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a8ec6  8a4632                 -mov al, byte ptr [esi + 0x32]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(50) /* 0x32 */);
    // 004a8ec9  8a9f1a010000           -mov bl, byte ptr [edi + 0x11a]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(282) /* 0x11a */);
    // 004a8ecf  8a4e36                 -mov cl, byte ptr [esi + 0x36]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(54) /* 0x36 */);
    // 004a8ed2  8a571a                 -mov dl, byte ptr [edi + 0x1a]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(26) /* 0x1a */);
    // 004a8ed5  8a803cac5600           -mov al, byte ptr [eax + 0x56ac3c]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5680188) /* 0x56ac3c */);
    // 004a8edb  8a9b3cac5600           -mov bl, byte ptr [ebx + 0x56ac3c]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5680188) /* 0x56ac3c */);
    // 004a8ee1  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004a8ee4  8a893cac5600           -mov cl, byte ptr [ecx + 0x56ac3c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5680188) /* 0x56ac3c */);
    // 004a8eea  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 004a8eed  8a923cac5600           -mov dl, byte ptr [edx + 0x56ac3c]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5680188) /* 0x56ac3c */);
    // 004a8ef3  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a8ef5  09d3                   -or ebx, edx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.edx));
    // 004a8ef7  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004a8efa  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a8efc  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a8efe  894518                 -mov dword ptr [ebp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004a8f01  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a8f03  8a463a                 -mov al, byte ptr [esi + 0x3a]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(58) /* 0x3a */);
    // 004a8f06  8a9f1e010000           -mov bl, byte ptr [edi + 0x11e]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(286) /* 0x11e */);
    // 004a8f0c  8a4e3e                 -mov cl, byte ptr [esi + 0x3e]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(62) /* 0x3e */);
    // 004a8f0f  8a571e                 -mov dl, byte ptr [edi + 0x1e]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(30) /* 0x1e */);
    // 004a8f12  8a803cac5600           -mov al, byte ptr [eax + 0x56ac3c]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5680188) /* 0x56ac3c */);
    // 004a8f18  8a9b3cac5600           -mov bl, byte ptr [ebx + 0x56ac3c]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(5680188) /* 0x56ac3c */);
    // 004a8f1e  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004a8f21  8a893cac5600           -mov cl, byte ptr [ecx + 0x56ac3c]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5680188) /* 0x56ac3c */);
    // 004a8f27  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 004a8f2a  8a923cac5600           -mov dl, byte ptr [edx + 0x56ac3c]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5680188) /* 0x56ac3c */);
    // 004a8f30  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a8f32  09d3                   -or ebx, edx
    cpu.ebx |= x86::reg32(x86::sreg32(cpu.edx));
    // 004a8f34  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004a8f37  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a8f39  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a8f3b  89451c                 -mov dword ptr [ebp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004a8f3e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a8f40  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8f41  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8f42  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8f43  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8f44  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a8f50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a8f50  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a8f51  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a8f52  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a8f53  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a8f56  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004a8f58  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004a8f5a  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 004a8f5d  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 004a8f5f  e88cf1feff             -call 0x4980f0
    cpu.esp -= 4;
    sub_4980f0(app, cpu);
    if (cpu.terminate) return;
    // 004a8f64  e8aff1feff             -call 0x498118
    cpu.esp -= 4;
    sub_498118(app, cpu);
    if (cpu.terminate) return;
    // 004a8f69  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a8f6b  7428                   -je 0x4a8f95
    if (cpu.flags.zf)
    {
        goto L_0x004a8f95;
    }
    // 004a8f6d  833d24cd4d0000         +cmp dword ptr [0x4dcd24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5098788) /* 0x4dcd24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a8f74  741f                   -je 0x4a8f95
    if (cpu.flags.zf)
    {
        goto L_0x004a8f95;
    }
    // 004a8f76  ba01120000             -mov edx, 0x1201
    cpu.edx = 4609 /*0x1201*/;
L_0x004a8f7b:
    // 004a8f7b  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004a8f7d  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a8f7f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a8f81  e8eafafaff             -call 0x458a70
    cpu.esp -= 4;
    sub_458a70(app, cpu);
    if (cpu.terminate) return;
    // 004a8f86  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a8f88  7512                   -jne 0x4a8f9c
    if (!cpu.flags.zf)
    {
        goto L_0x004a8f9c;
    }
    // 004a8f8a  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 004a8f8c  83c404                 +add esp, 4
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
    // 004a8f8f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8f90  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8f91  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8f92  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004a8f95:
    // 004a8f95  ba05020000             -mov edx, 0x205
    cpu.edx = 517 /*0x205*/;
    // 004a8f9a  ebdf                   -jmp 0x4a8f7b
    goto L_0x004a8f7b;
L_0x004a8f9c:
    // 004a8f9c  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a8f9e  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a8fa2  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004a8fa4  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004a8fa6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a8fa8  e883f9faff             -call 0x458930
    cpu.esp -= 4;
    sub_458930(app, cpu);
    if (cpu.terminate) return;
    // 004a8fad  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a8faf  7417                   -je 0x4a8fc8
    if (cpu.flags.zf)
    {
        goto L_0x004a8fc8;
    }
    // 004a8fb1  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004a8fb4  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004a8fba  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a8fbf  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a8fc2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8fc3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8fc4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8fc5  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004a8fc8:
    // 004a8fc8  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004a8fca  e8c1f0faff             -call 0x458090
    cpu.esp -= 4;
    sub_458090(app, cpu);
    if (cpu.terminate) return;
    // 004a8fcf  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 004a8fd5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a8fd7  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a8fda  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8fdb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8fdc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8fdd  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_4a8fe0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a8fe0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a8fe1  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004a8fe3  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a8fe7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a8fe8  e863ffffff             -call 0x4a8f50
    cpu.esp -= 4;
    sub_4a8f50(app, cpu);
    if (cpu.terminate) return;
    // 004a8fed  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a8fee  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a8ff4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a8ff4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a8ff5  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a8ff7  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a8ffb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a8ffc  e84fffffff             -call 0x4a8f50
    cpu.esp -= 4;
    sub_4a8f50(app, cpu);
    if (cpu.terminate) return;
    // 004a9001  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9002  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a9008(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9008  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a900a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a900c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a900c  e97ff0faff             -jmp 0x458090
    return sub_458090(app, cpu);
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a9014(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9014  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a9015  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a9016  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a9017  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004a901a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a901c  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004a9020  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004a9022  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004a9026  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004a9028  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004a902a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a902b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a902d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a902f  e8fcf8faff             -call 0x458930
    cpu.esp -= 4;
    sub_458930(app, cpu);
    if (cpu.terminate) return;
    // 004a9034  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a9036  7509                   -jne 0x4a9041
    if (!cpu.flags.zf)
    {
        goto L_0x004a9041;
    }
L_0x004a9038:
    // 004a9038  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a903a  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004a903d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a903e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a903f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9040  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a9041:
    // 004a9041  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 004a9044  0fafdd                 -imul ebx, ebp
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 004a9047  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a904b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a904d  e82ef5faff             -call 0x458580
    cpu.esp -= 4;
    sub_458580(app, cpu);
    if (cpu.terminate) return;
    // 004a9052  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a9056  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004a9058  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a905a  74dc                   -je 0x4a9038
    if (cpu.flags.zf)
    {
        goto L_0x004a9038;
    }
    // 004a905c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a905e  75d8                   -jne 0x4a9038
    if (!cpu.flags.zf)
    {
        goto L_0x004a9038;
    }
    // 004a9060  85ed                   -test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004a9062  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a9064  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004a9067  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9068  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9069  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a906a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a906c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a906c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a906d  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004a9072  e89dffffff             -call 0x4a9014
    cpu.esp -= 4;
    sub_4a9014(app, cpu);
    if (cpu.terminate) return;
    // 004a9077  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9078  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a907c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a907c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a907d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a907f  e890ffffff             -call 0x4a9014
    cpu.esp -= 4;
    sub_4a9014(app, cpu);
    if (cpu.terminate) return;
    // 004a9084  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9085  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a9088(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9088  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a9089  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a908b  e8e0f1faff             -call 0x458270
    cpu.esp -= 4;
    sub_458270(app, cpu);
    if (cpu.terminate) return;
    // 004a9090  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a9092  e829f1faff             -call 0x4581c0
    cpu.esp -= 4;
    sub_4581c0(app, cpu);
    if (cpu.terminate) return;
    // 004a9097  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9098  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a909c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a909c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a909d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a909f  e8ccf1faff             -call 0x458270
    cpu.esp -= 4;
    sub_458270(app, cpu);
    if (cpu.terminate) return;
    // 004a90a4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a90a6  e815f1faff             -call 0x4581c0
    cpu.esp -= 4;
    sub_4581c0(app, cpu);
    if (cpu.terminate) return;
    // 004a90ab  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a90ac  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a90b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a90b0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a90b1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a90b3  e8b8f1faff             -call 0x458270
    cpu.esp -= 4;
    sub_458270(app, cpu);
    if (cpu.terminate) return;
    // 004a90b8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a90ba  e801f1faff             -call 0x4581c0
    cpu.esp -= 4;
    sub_4581c0(app, cpu);
    if (cpu.terminate) return;
    // 004a90bf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a90c0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a90d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a90d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a90d1  8d480c                 -lea ecx, [eax + 0xc]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004a90d4  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004a90d7  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a90d9  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
    // 004a90dc  8a482d                 -mov cl, byte ptr [eax + 0x2d]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(45) /* 0x2d */);
    // 004a90df  884a01                 -mov byte ptr [edx + 1], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */) = cpu.cl;
    // 004a90e2  8a482f                 -mov cl, byte ptr [eax + 0x2f]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(47) /* 0x2f */);
    // 004a90e5  884a02                 -mov byte ptr [edx + 2], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */) = cpu.cl;
    // 004a90e8  8a482e                 -mov cl, byte ptr [eax + 0x2e]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(46) /* 0x2e */);
    // 004a90eb  884a03                 -mov byte ptr [edx + 3], cl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(3) /* 0x3 */) = cpu.cl;
    // 004a90ee  668b4032               -mov ax, word ptr [eax + 0x32]
    cpu.ax = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(50) /* 0x32 */);
    // 004a90f2  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004a90f7  894204                 -mov dword ptr [edx + 4], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004a90fa  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a90fc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a90fd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a9100(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9100  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a9101  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a9102  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004a9104  81385041546c           +cmp dword ptr [eax], 0x6c544150
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1817461072 /*0x6c544150*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a910a  7445                   -je 0x4a9151
    if (cpu.flags.zf)
    {
        goto L_0x004a9151;
    }
    // 004a910c  f6400302               +test byte ptr [eax + 3], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */) & 2 /*0x2*/));
    // 004a9110  7449                   -je 0x4a915b
    if (cpu.flags.zf)
    {
        goto L_0x004a915b;
    }
    // 004a9112  8d4808                 -lea ecx, [eax + 8]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
L_0x004a9115:
    // 004a9115  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a9116  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a9117  c60700                 -mov byte ptr [edi], 0
    app->getMemory<x86::reg8>(cpu.edi) = 0 /*0x0*/;
    // 004a911a  c6470100               -mov byte ptr [edi + 1], 0
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = 0 /*0x0*/;
    // 004a911e  c6470200               -mov byte ptr [edi + 2], 0
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */) = 0 /*0x0*/;
    // 004a9122  c6470300               -mov byte ptr [edi + 3], 0
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */) = 0 /*0x0*/;
    // 004a9126  c7470400000000         -mov dword ptr [edi + 4], 0
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004a912d  8039ff                 +cmp byte ptr [ecx], 0xff
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
    // 004a9130  7418                   -je 0x4a914a
    if (cpu.flags.zf)
    {
        goto L_0x004a914a;
    }
L_0x004a9132:
    // 004a9132  8a39                   -mov bh, byte ptr [ecx]
    cpu.bh = app->getMemory<x86::reg8>(cpu.ecx);
    // 004a9134  80fffe                 +cmp bh, 0xfe
    {
        x86::reg8 tmp1 = cpu.bh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(254 /*0xfe*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a9137  7411                   -je 0x4a914a
    if (cpu.flags.zf)
    {
        goto L_0x004a914a;
    }
    // 004a9139  0fb6f7                 -movzx esi, bh
    cpu.esi = x86::reg32(cpu.bh);
    // 004a913c  41                     -inc ecx
    (cpu.ecx)++;
    // 004a913d  81fefd000000           +cmp esi, 0xfd
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(253 /*0xfd*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a9143  751b                   -jne 0x4a9160
    if (!cpu.flags.zf)
    {
        goto L_0x004a9160;
    }
L_0x004a9145:
    // 004a9145  8039ff                 +cmp byte ptr [ecx], 0xff
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
    // 004a9148  75e8                   -jne 0x4a9132
    if (!cpu.flags.zf)
    {
        goto L_0x004a9132;
    }
L_0x004a914a:
    // 004a914a  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004a914c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a914d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a914e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a914f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9150  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a9151:
    // 004a9151  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004a9153  e878ffffff             -call 0x4a90d0
    cpu.esp -= 4;
    sub_4a90d0(app, cpu);
    if (cpu.terminate) return;
    // 004a9158  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9159  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a915a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a915b:
    // 004a915b  8d4804                 -lea ecx, [eax + 4]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004a915e  ebb5                   -jmp 0x4a9115
    goto L_0x004a9115;
L_0x004a9160:
    // 004a9160  81fefc000000           +cmp esi, 0xfc
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
    // 004a9166  74dd                   -je 0x4a9145
    if (cpu.flags.zf)
    {
        goto L_0x004a9145;
    }
    // 004a9168  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a916a  8a19                   -mov bl, byte ptr [ecx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx);
    // 004a916c  81fbff000000           +cmp ebx, 0xff
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
    // 004a9172  7512                   -jne 0x4a9186
    if (!cpu.flags.zf)
    {
        goto L_0x004a9186;
    }
    // 004a9174  41                     -inc ecx
    (cpu.ecx)++;
    // 004a9175  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 004a917a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a917c  e8cfa8ffff             -call 0x4a3a50
    cpu.esp -= 4;
    sub_4a3a50(app, cpu);
    if (cpu.terminate) return;
    // 004a9181  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a9183  83c103                 -add ecx, 3
    (cpu.ecx) += x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x004a9186:
    // 004a9186  41                     -inc ecx
    (cpu.ecx)++;
    // 004a9187  81fe82000000           +cmp esi, 0x82
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(130 /*0x82*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a918d  7313                   -jae 0x4a91a2
    if (!cpu.flags.cf)
    {
        goto L_0x004a91a2;
    }
    // 004a918f  83fe13                 +cmp esi, 0x13
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(19 /*0x13*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a9192  7332                   -jae 0x4a91c6
    if (!cpu.flags.cf)
    {
        goto L_0x004a91c6;
    }
L_0x004a9194:
    // 004a9194  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004a9196  8039ff                 +cmp byte ptr [ecx], 0xff
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
    // 004a9199  7597                   -jne 0x4a9132
    if (!cpu.flags.zf)
    {
        goto L_0x004a9132;
    }
    // 004a919b  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004a919d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a919e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a919f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a91a0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a91a1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a91a2:
    // 004a91a2  7667                   -jbe 0x4a920b
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a920b;
    }
    // 004a91a4  81fe83000000           +cmp esi, 0x83
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(131 /*0x83*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a91aa  0f8679000000           -jbe 0x4a9229
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a9229;
    }
    // 004a91b0  81fe84000000           +cmp esi, 0x84
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(132 /*0x84*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a91b6  75dc                   -jne 0x4a9194
    if (!cpu.flags.zf)
    {
        goto L_0x004a9194;
    }
    // 004a91b8  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004a91ba  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a91bc  e88fa8ffff             -call 0x4a3a50
    cpu.esp -= 4;
    sub_4a3a50(app, cpu);
    if (cpu.terminate) return;
    // 004a91c1  894704                 -mov dword ptr [edi + 4], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004a91c4  ebce                   -jmp 0x4a9194
    goto L_0x004a9194;
L_0x004a91c6:
    // 004a91c6  7626                   -jbe 0x4a91ee
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a91ee;
    }
    // 004a91c8  81fe81000000           +cmp esi, 0x81
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(129 /*0x81*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a91ce  75c4                   -jne 0x4a9194
    if (!cpu.flags.zf)
    {
        goto L_0x004a9194;
    }
    // 004a91d0  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004a91d2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a91d4  e877a8ffff             -call 0x4a3a50
    cpu.esp -= 4;
    sub_4a3a50(app, cpu);
    if (cpu.terminate) return;
    // 004a91d9  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004a91dc  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004a91de  8039ff                 +cmp byte ptr [ecx], 0xff
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
    // 004a91e1  0f854bffffff           -jne 0x4a9132
    if (!cpu.flags.zf)
    {
        goto L_0x004a9132;
    }
    // 004a91e7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a91e9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a91ea  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a91eb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a91ec  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a91ed  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a91ee:
    // 004a91ee  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004a91f0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a91f2  e859a8ffff             -call 0x4a3a50
    cpu.esp -= 4;
    sub_4a3a50(app, cpu);
    if (cpu.terminate) return;
    // 004a91f7  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004a91f9  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004a91fb  8039ff                 +cmp byte ptr [ecx], 0xff
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
    // 004a91fe  0f852effffff           -jne 0x4a9132
    if (!cpu.flags.zf)
    {
        goto L_0x004a9132;
    }
    // 004a9204  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a9206  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9207  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9208  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9209  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a920a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a920b:
    // 004a920b  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004a920d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a920f  e83ca8ffff             -call 0x4a3a50
    cpu.esp -= 4;
    sub_4a3a50(app, cpu);
    if (cpu.terminate) return;
    // 004a9214  884703                 -mov byte ptr [edi + 3], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(3) /* 0x3 */) = cpu.al;
    // 004a9217  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004a9219  8039ff                 +cmp byte ptr [ecx], 0xff
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
    // 004a921c  0f8510ffffff           -jne 0x4a9132
    if (!cpu.flags.zf)
    {
        goto L_0x004a9132;
    }
    // 004a9222  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a9224  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9225  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9226  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9227  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9228  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a9229:
    // 004a9229  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004a922b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a922d  e81ea8ffff             -call 0x4a3a50
    cpu.esp -= 4;
    sub_4a3a50(app, cpu);
    if (cpu.terminate) return;
    // 004a9232  884702                 -mov byte ptr [edi + 2], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 004a9235  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004a9237  8039ff                 +cmp byte ptr [ecx], 0xff
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
    // 004a923a  0f85f2feffff           -jne 0x4a9132
    if (!cpu.flags.zf)
    {
        goto L_0x004a9132;
    }
    // 004a9240  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a9242  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9243  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9244  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9245  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9246  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a9250(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9250  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a9251  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a9252  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a9253  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004a9256  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004a9258  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004a925c  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004a9260  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004a9263  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a9267  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 004a926a  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 004a926c  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004a926e  8b1568904d00           -mov edx, dword ptr [0x4d9068]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5083240) /* 0x4d9068 */);
    // 004a9274  8b36                   -mov esi, dword ptr [esi]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi);
    // 004a9276  8b3f                   -mov edi, dword ptr [edi]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi);
    // 004a9278  39d3                   +cmp ebx, edx
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
    // 004a927a  7c3c                   -jl 0x4a92b8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a92b8;
    }
    // 004a927c  3b1d70904d00           +cmp ebx, dword ptr [0x4d9070]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5083248) /* 0x4d9070 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a9282  7d34                   -jge 0x4a92b8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a92b8;
    }
    // 004a9284  3b0d6c904d00           +cmp ecx, dword ptr [0x4d906c]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5083244) /* 0x4d906c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a928a  7c2c                   -jl 0x4a92b8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a92b8;
    }
    // 004a928c  3b0d74904d00           +cmp ecx, dword ptr [0x4d9074]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5083252) /* 0x4d9074 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a9292  7d24                   -jge 0x4a92b8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a92b8;
    }
    // 004a9294  3b3568904d00           +cmp esi, dword ptr [0x4d9068]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5083240) /* 0x4d9068 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a929a  7c1c                   -jl 0x4a92b8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a92b8;
    }
    // 004a929c  3b3570904d00           +cmp esi, dword ptr [0x4d9070]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5083248) /* 0x4d9070 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a92a2  7d14                   -jge 0x4a92b8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a92b8;
    }
    // 004a92a4  3b3d6c904d00           +cmp edi, dword ptr [0x4d906c]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5083244) /* 0x4d906c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a92aa  7c0c                   -jl 0x4a92b8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a92b8;
    }
    // 004a92ac  3b3d74904d00           +cmp edi, dword ptr [0x4d9074]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5083252) /* 0x4d9074 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a92b2  0f8c60010000           -jl 0x4a9418
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a9418;
    }
L_0x004a92b8:
    // 004a92b8  8b1570904d00           -mov edx, dword ptr [0x4d9070]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5083248) /* 0x4d9070 */);
    // 004a92be  39d3                   +cmp ebx, edx
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
    // 004a92c0  7c08                   -jl 0x4a92ca
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a92ca;
    }
    // 004a92c2  39d6                   +cmp esi, edx
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
    // 004a92c4  0f8d5a010000           -jge 0x4a9424
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a9424;
    }
L_0x004a92ca:
    // 004a92ca  8b1568904d00           -mov edx, dword ptr [0x4d9068]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5083240) /* 0x4d9068 */);
    // 004a92d0  39d3                   +cmp ebx, edx
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
    // 004a92d2  7d08                   -jge 0x4a92dc
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a92dc;
    }
    // 004a92d4  39d6                   +cmp esi, edx
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
    // 004a92d6  0f8c48010000           -jl 0x4a9424
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a9424;
    }
L_0x004a92dc:
    // 004a92dc  8b1574904d00           -mov edx, dword ptr [0x4d9074]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5083252) /* 0x4d9074 */);
    // 004a92e2  39d1                   +cmp ecx, edx
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
    // 004a92e4  7c08                   -jl 0x4a92ee
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a92ee;
    }
    // 004a92e6  39d7                   +cmp edi, edx
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
    // 004a92e8  0f8d36010000           -jge 0x4a9424
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a9424;
    }
L_0x004a92ee:
    // 004a92ee  8b156c904d00           -mov edx, dword ptr [0x4d906c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5083244) /* 0x4d906c */);
    // 004a92f4  39d1                   +cmp ecx, edx
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
    // 004a92f6  7d08                   -jge 0x4a9300
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a9300;
    }
    // 004a92f8  39d7                   +cmp edi, edx
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
    // 004a92fa  0f8c24010000           -jl 0x4a9424
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a9424;
    }
L_0x004a9300:
    // 004a9300  39f3                   +cmp ebx, esi
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
    // 004a9302  7e0c                   -jle 0x4a9310
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a9310;
    }
    // 004a9304  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a9306  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004a9308  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a930a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a930c  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004a930e  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x004a9310:
    // 004a9310  8b1568904d00           -mov edx, dword ptr [0x4d9068]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5083240) /* 0x4d9068 */);
    // 004a9316  39d3                   +cmp ebx, edx
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
    // 004a9318  7d24                   -jge 0x4a933e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a933e;
    }
    // 004a931a  39f3                   +cmp ebx, esi
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
    // 004a931c  7420                   -je 0x4a933e
    if (cpu.flags.zf)
    {
        goto L_0x004a933e;
    }
    // 004a931e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a9320  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004a9322  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a9324  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a9326  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 004a9329  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a932b  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a932d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a932f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a9331  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a9334  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a9336  8b1d68904d00           -mov ebx, dword ptr [0x4d9068]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5083240) /* 0x4d9068 */);
    // 004a933c  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x004a933e:
    // 004a933e  8b1570904d00           -mov edx, dword ptr [0x4d9070]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5083248) /* 0x4d9070 */);
    // 004a9344  39d6                   +cmp esi, edx
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
    // 004a9346  7c22                   -jl 0x4a936a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a936a;
    }
    // 004a9348  39f3                   +cmp ebx, esi
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
    // 004a934a  741e                   -je 0x4a936a
    if (cpu.flags.zf)
    {
        goto L_0x004a936a;
    }
    // 004a934c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a934e  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004a9350  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a9352  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a9354  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 004a9357  29de                   -sub esi, ebx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a9359  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a935b  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a935e  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a9360  8b3570904d00           -mov esi, dword ptr [0x4d9070]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5083248) /* 0x4d9070 */);
    // 004a9366  8d3c08                 -lea edi, [eax + ecx]
    cpu.edi = x86::reg32(cpu.eax + cpu.ecx * 1);
    // 004a9369  4e                     -dec esi
    (cpu.esi)--;
L_0x004a936a:
    // 004a936a  39f9                   +cmp ecx, edi
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
    // 004a936c  7e0c                   -jle 0x4a937a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a937a;
    }
    // 004a936e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a9370  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004a9372  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a9374  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a9376  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004a9378  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x004a937a:
    // 004a937a  a16c904d00             -mov eax, dword ptr [0x4d906c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5083244) /* 0x4d906c */);
    // 004a937f  39c1                   +cmp ecx, eax
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
    // 004a9381  7d22                   -jge 0x4a93a5
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a93a5;
    }
    // 004a9383  39f9                   +cmp ecx, edi
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
    // 004a9385  741e                   -je 0x4a93a5
    if (cpu.flags.zf)
    {
        goto L_0x004a93a5;
    }
    // 004a9387  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004a9389  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a938b  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a938d  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 004a9390  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a9392  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a9394  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a9396  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a9398  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a939b  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a939d  8b0d6c904d00           -mov ecx, dword ptr [0x4d906c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5083244) /* 0x4d906c */);
    // 004a93a3  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x004a93a5:
    // 004a93a5  8b1574904d00           -mov edx, dword ptr [0x4d9074]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5083252) /* 0x4d9074 */);
    // 004a93ab  39d7                   +cmp edi, edx
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
    // 004a93ad  7c1e                   -jl 0x4a93cd
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a93cd;
    }
    // 004a93af  39f9                   +cmp ecx, edi
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
    // 004a93b1  741a                   -je 0x4a93cd
    if (cpu.flags.zf)
    {
        goto L_0x004a93cd;
    }
    // 004a93b3  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a93b5  29de                   -sub esi, ebx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a93b7  0fafd6                 -imul edx, esi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 004a93ba  29cf                   -sub edi, ecx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a93bc  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a93be  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a93c1  f7ff                   -idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a93c3  8b3d74904d00           -mov edi, dword ptr [0x4d9074]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5083252) /* 0x4d9074 */);
    // 004a93c9  8d3418                 -lea esi, [eax + ebx]
    cpu.esi = x86::reg32(cpu.eax + cpu.ebx * 1);
    // 004a93cc  4f                     -dec edi
    (cpu.edi)--;
L_0x004a93cd:
    // 004a93cd  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a93d1  895d00                 -mov dword ptr [ebp], ebx
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.ebx;
    // 004a93d4  8930                   -mov dword ptr [eax], esi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.esi;
    // 004a93d6  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a93da  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 004a93dc  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004a93df  8b2d68904d00           -mov ebp, dword ptr [0x4d9068]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5083240) /* 0x4d9068 */);
    // 004a93e5  8938                   -mov dword ptr [eax], edi
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edi;
    // 004a93e7  39eb                   +cmp ebx, ebp
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
    // 004a93e9  7c39                   -jl 0x4a9424
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a9424;
    }
    // 004a93eb  a170904d00             -mov eax, dword ptr [0x4d9070]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5083248) /* 0x4d9070 */);
    // 004a93f0  39c3                   +cmp ebx, eax
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
    // 004a93f2  7d30                   -jge 0x4a9424
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a9424;
    }
    // 004a93f4  8b156c904d00           -mov edx, dword ptr [0x4d906c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5083244) /* 0x4d906c */);
    // 004a93fa  39d1                   +cmp ecx, edx
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
    // 004a93fc  7c26                   -jl 0x4a9424
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a9424;
    }
    // 004a93fe  8b1d74904d00           -mov ebx, dword ptr [0x4d9074]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5083252) /* 0x4d9074 */);
    // 004a9404  39d9                   +cmp ecx, ebx
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
    // 004a9406  7d1c                   -jge 0x4a9424
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a9424;
    }
    // 004a9408  39ee                   +cmp esi, ebp
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
    // 004a940a  7c18                   -jl 0x4a9424
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a9424;
    }
    // 004a940c  39c6                   +cmp esi, eax
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
    // 004a940e  7d14                   -jge 0x4a9424
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a9424;
    }
    // 004a9410  39d7                   +cmp edi, edx
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
    // 004a9412  7c10                   -jl 0x4a9424
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a9424;
    }
    // 004a9414  39df                   +cmp edi, ebx
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
    // 004a9416  7d0c                   -jge 0x4a9424
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a9424;
    }
L_0x004a9418:
    // 004a9418  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a941d  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004a9420  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9421  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9422  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9423  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a9424:
    // 004a9424  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a9426  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004a9429  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a942a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a942b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a942c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_4a9430(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9430  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a9431  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a9432  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a9435  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004a9438  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a943a  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004a943c  3b0568904d00           +cmp eax, dword ptr [0x4d9068]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5083240) /* 0x4d9068 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a9442  7c5c                   -jl 0x4a94a0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a94a0;
    }
    // 004a9444  3b0570904d00           +cmp eax, dword ptr [0x4d9070]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5083248) /* 0x4d9070 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a944a  7d54                   -jge 0x4a94a0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a94a0;
    }
    // 004a944c  3b0d6c904d00           +cmp ecx, dword ptr [0x4d906c]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5083244) /* 0x4d906c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a9452  7c4c                   -jl 0x4a94a0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a94a0;
    }
    // 004a9454  3b0d74904d00           +cmp ecx, dword ptr [0x4d9074]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5083252) /* 0x4d9074 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a945a  7d44                   -jge 0x4a94a0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a94a0;
    }
    // 004a945c  a188904d00             -mov eax, dword ptr [0x4d9088]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5083272) /* 0x4d9088 */);
    // 004a9461  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 004a9464  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a9466  8b1d8c904d00           -mov ebx, dword ptr [0x4d908c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5083276) /* 0x4d908c */);
    // 004a946c  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004a946f  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004a9471  8b3483                 -mov esi, dword ptr [ebx + eax*4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + cpu.eax * 4);
    // 004a9474  a17c904d00             -mov eax, dword ptr [0x4d907c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5083260) /* 0x4d907c */);
    // 004a9479  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004a947b  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a947d  a078904d00             -mov al, byte ptr [0x4d9078]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5083256) /* 0x4d9078 */);
    // 004a9482  3c0f                   +cmp al, 0xf
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(15 /*0xf*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a9484  7320                   -jae 0x4a94a6
    if (!cpu.flags.cf)
    {
        goto L_0x004a94a6;
    }
    // 004a9486  3c04                   +cmp al, 4
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(4 /*0x4*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a9488  7216                   -jb 0x4a94a0
    if (cpu.flags.cf)
    {
        goto L_0x004a94a0;
    }
    // 004a948a  7733                   -ja 0x4a94bf
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004a94bf;
    }
    // 004a948c  f6042401               +test byte ptr [esp], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp) & 1 /*0x1*/));
    // 004a9490  7435                   -je 0x4a94c7
    if (cpu.flags.zf)
    {
        goto L_0x004a94c7;
    }
    // 004a9492  8a31                   -mov dh, byte ptr [ecx]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ecx);
    // 004a9494  80e60f                 -and dh, 0xf
    cpu.dh &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 004a9497  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 004a9499  c0e004                 -shl al, 4
    cpu.al <<= 4 /*0x4*/ % 32;
    // 004a949c  08c6                   -or dh, al
    cpu.dh |= x86::reg8(x86::sreg8(cpu.al));
    // 004a949e  8831                   -mov byte ptr [ecx], dh
    app->getMemory<x86::reg8>(cpu.ecx) = cpu.dh;
L_0x004a94a0:
    // 004a94a0  83c404                 +add esp, 4
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
    // 004a94a3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a94a4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a94a5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a94a6:
    // 004a94a6  7608                   -jbe 0x4a94b0
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a94b0;
    }
    // 004a94a8  3c18                   +cmp al, 0x18
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(24 /*0x18*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a94aa  7309                   -jae 0x4a94b5
    if (!cpu.flags.cf)
    {
        goto L_0x004a94b5;
    }
    // 004a94ac  3c10                   +cmp al, 0x10
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(16 /*0x10*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a94ae  75f0                   -jne 0x4a94a0
    if (!cpu.flags.zf)
    {
        goto L_0x004a94a0;
    }
L_0x004a94b0:
    // 004a94b0  668911                 -mov word ptr [ecx], dx
    app->getMemory<x86::reg16>(cpu.ecx) = cpu.dx;
    // 004a94b3  ebeb                   -jmp 0x4a94a0
    goto L_0x004a94a0;
L_0x004a94b5:
    // 004a94b5  761e                   -jbe 0x4a94d5
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a94d5;
    }
    // 004a94b7  3c20                   +cmp al, 0x20
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(32 /*0x20*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a94b9  75e5                   -jne 0x4a94a0
    if (!cpu.flags.zf)
    {
        goto L_0x004a94a0;
    }
    // 004a94bb  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 004a94bd  ebe1                   -jmp 0x4a94a0
    goto L_0x004a94a0;
L_0x004a94bf:
    // 004a94bf  3c08                   +cmp al, 8
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(8 /*0x8*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a94c1  75dd                   -jne 0x4a94a0
    if (!cpu.flags.zf)
    {
        goto L_0x004a94a0;
    }
    // 004a94c3  8811                   -mov byte ptr [ecx], dl
    app->getMemory<x86::reg8>(cpu.ecx) = cpu.dl;
    // 004a94c5  ebd9                   -jmp 0x4a94a0
    goto L_0x004a94a0;
L_0x004a94c7:
    // 004a94c7  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 004a94c9  24f0                   -and al, 0xf0
    cpu.al &= x86::reg8(x86::sreg8(240 /*0xf0*/));
    // 004a94cb  08d0                   -or al, dl
    cpu.al |= x86::reg8(x86::sreg8(cpu.dl));
    // 004a94cd  8801                   -mov byte ptr [ecx], al
    app->getMemory<x86::reg8>(cpu.ecx) = cpu.al;
    // 004a94cf  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a94d2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a94d3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a94d4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a94d5:
    // 004a94d5  bb03000000             -mov ebx, 3
    cpu.ebx = 3 /*0x3*/;
    // 004a94da  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a94dc  e85a90ffff             -call 0x4a253b
    cpu.esp -= 4;
    sub_4a253b(app, cpu);
    if (cpu.terminate) return;
    // 004a94e1  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a94e4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a94e5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a94e6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a94e7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a94e7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a94e8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a94e9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a94ea  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a94ec  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a94ee  bb20000000             -mov ebx, 0x20
    cpu.ebx = 32 /*0x20*/;
    // 004a94f3  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004a94f5  e87540feff             -call 0x48d56f
    cpu.esp -= 4;
    sub_48d56f(app, cpu);
    if (cpu.terminate) return;
    // 004a94fa  eb1f                   -jmp 0x4a951b
    goto L_0x004a951b;
L_0x004a94fc:
    // 004a94fc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a94fe  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 004a9500  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 004a9503  80e207                 -and dl, 7
    cpu.dl &= x86::reg8(x86::sreg8(7 /*0x7*/));
    // 004a9506  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a950c  8a92b0fe4c00           -mov dl, byte ptr [edx + 0x4cfeb0]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5045936) /* 0x4cfeb0 */);
    // 004a9512  8a3406                 -mov dh, byte ptr [esi + eax]
    cpu.dh = app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1);
    // 004a9515  08d6                   -or dh, dl
    cpu.dh |= x86::reg8(x86::sreg8(cpu.dl));
    // 004a9517  41                     -inc ecx
    (cpu.ecx)++;
    // 004a9518  883406                 -mov byte ptr [esi + eax], dh
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = cpu.dh;
L_0x004a951b:
    // 004a951b  8a11                   -mov dl, byte ptr [ecx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx);
    // 004a951d  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 004a951f  75db                   -jne 0x4a94fc
    if (!cpu.flags.zf)
    {
        goto L_0x004a94fc;
    }
    // 004a9521  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9522  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9523  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9524  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4a9526(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9526  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a9527  dd442408               -fld qword ptr [esp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 004a952b  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004a952d  e86eb4fdff             -call 0x4849a0
    cpu.esp -= 4;
    sub_4849a0(app, cpu);
    if (cpu.terminate) return;
    // 004a9532  dce9                   -fsub st(1), st(0)
    cpu.fpu.st(1) -= x86::Float(cpu.fpu.st(0));
    // 004a9534  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a9538  dd18                   -fstp qword ptr [eax]
    app->getMemory<double>(cpu.eax) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a953a  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a953b  9b                     -wait 
    /*nothing*/;
    // 004a953c  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_4a953f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a953f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a9540  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a9541  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a9543  8b1580445b00           -mov edx, dword ptr [0x5b4480]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5981312) /* 0x5b4480 */);
    // 004a9549  83fa20                 +cmp edx, 0x20
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
    // 004a954c  7d15                   -jge 0x4a9563
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a9563;
    }
    // 004a954e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a9550  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a9552  42                     -inc edx
    (cpu.edx)++;
    // 004a9553  891c95fc435b00         -mov dword ptr [edx*4 + 0x5b43fc], ebx
    app->getMemory<x86::reg32>(x86::reg32(5981180) /* 0x5b43fc */ + cpu.edx * 4) = cpu.ebx;
    // 004a955a  891580445b00           -mov dword ptr [0x5b4480], edx
    app->getMemory<x86::reg32>(x86::reg32(5981312) /* 0x5b4480 */) = cpu.edx;
    // 004a9560  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9561  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9562  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a9563:
    // 004a9563  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004a9568  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9569  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a956a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a956b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a956b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a956c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a956d  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004a956e  0fa0                   -push fs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.fs;
    cpu.esp -= 4;
    // 004a9570  0fa8                   -push gs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.gs;
    cpu.esp -= 4;
    // 004a9572  8b1d80445b00           -mov ebx, dword ptr [0x5b4480]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5981312) /* 0x5b4480 */);
    // 004a9578  83fb21                 +cmp ebx, 0x21
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(33 /*0x21*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a957b  7421                   -je 0x4a959e
    if (cpu.flags.zf)
    {
        goto L_0x004a959e;
    }
    // 004a957d  c70580445b0021000000   -mov dword ptr [0x5b4480], 0x21
    app->getMemory<x86::reg32>(x86::reg32(5981312) /* 0x5b4480 */) = 33 /*0x21*/;
    // 004a9587  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004a9589  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
L_0x004a958c:
    // 004a958c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a958e  740e                   -je 0x4a959e
    if (cpu.flags.zf)
    {
        goto L_0x004a959e;
    }
    // 004a9590  8b82fc435b00           -mov eax, dword ptr [edx + 0x5b43fc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5981180) /* 0x5b43fc */);
    // 004a9596  83ea04                 +sub edx, 4
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
    // 004a9599  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a959a  ffd0                   -call eax
    cpu.ip = cpu.eax;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a959c  ebee                   -jmp 0x4a958c
    goto L_0x004a958c;
L_0x004a959e:
    // 004a959e  0fa9                   -pop gs
    cpu.gs = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004a95a0  0fa1                   -pop fs
    cpu.fs = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004a95a2  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004a95a3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a95a4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a95a5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a95b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a95b0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a95b1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a95b2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a95b4  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a95b6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a95b8  7c3f                   -jl 0x4a95f9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a95f9;
    }
L_0x004a95ba:
    // 004a95ba  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a95bc  743f                   -je 0x4a95fd
    if (cpu.flags.zf)
    {
        goto L_0x004a95fd;
    }
    // 004a95be  3d00000100             +cmp eax, 0x10000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a95c3  7c06                   -jl 0x4a95cb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a95cb;
    }
    // 004a95c5  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004a95c8  83c210                 -add edx, 0x10
    (cpu.edx) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x004a95cb:
    // 004a95cb  3d00010000             +cmp eax, 0x100
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
    // 004a95d0  7c06                   -jl 0x4a95d8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a95d8;
    }
    // 004a95d2  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 004a95d5  83c208                 -add edx, 8
    (cpu.edx) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x004a95d8:
    // 004a95d8  83f810                 +cmp eax, 0x10
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
    // 004a95db  7c06                   -jl 0x4a95e3
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a95e3;
    }
    // 004a95dd  c1f804                 -sar eax, 4
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (4 /*0x4*/ % 32));
    // 004a95e0  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004a95e3:
    // 004a95e3  83f804                 +cmp eax, 4
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
    // 004a95e6  7c06                   -jl 0x4a95ee
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a95ee;
    }
    // 004a95e8  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 004a95eb  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x004a95ee:
    // 004a95ee  83f802                 +cmp eax, 2
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
    // 004a95f1  7c01                   -jl 0x4a95f4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a95f4;
    }
    // 004a95f3  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
L_0x004a95f4:
    // 004a95f4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a95f6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a95f7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a95f8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a95f9:
    // 004a95f9  f7d0                   -not eax
    cpu.eax = ~cpu.eax;
    // 004a95fb  ebbd                   -jmp 0x4a95ba
    goto L_0x004a95ba;
L_0x004a95fd:
    // 004a95fd  ba3f000000             -mov edx, 0x3f
    cpu.edx = 63 /*0x3f*/;
    // 004a9602  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a9604  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9605  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9606  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a9610(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9610  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a9611  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a9612  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a9613  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a9614  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004a9616  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a9618  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004a961a  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004a961c  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a961e  7e58                   -jle 0x4a9678
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a9678;
    }
    // 004a9620  bd3f000000             -mov ebp, 0x3f
    cpu.ebp = 63 /*0x3f*/;
    // 004a9625  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x004a9627:
    // 004a9627  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a9629  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 004a962b  69c0ff000000           -imul eax, eax, 0xff
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(255 /*0xff*/)));
    // 004a9631  8d5020                 -lea edx, [eax + 0x20]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004a9634  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a9636  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a9639  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a963b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a963d  8803                   -mov byte ptr [ebx], al
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.al;
    // 004a963f  8a5101                 -mov dl, byte ptr [ecx + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 004a9642  69d2ff000000           -imul edx, edx, 0xff
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(255 /*0xff*/)));
    // 004a9648  83c220                 -add edx, 0x20
    (cpu.edx) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004a964b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a964d  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a9650  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a9652  884301                 -mov byte ptr [ebx + 1], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004a9655  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a9657  8a4102                 -mov al, byte ptr [ecx + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 004a965a  69c0ff000000           -imul eax, eax, 0xff
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(255 /*0xff*/)));
    // 004a9660  8d5020                 -lea edx, [eax + 0x20]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004a9663  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a9665  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a9668  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a966a  83c303                 -add ebx, 3
    (cpu.ebx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004a966d  83c103                 -add ecx, 3
    (cpu.ecx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004a9670  46                     -inc esi
    (cpu.esi)++;
    // 004a9671  8843ff                 -mov byte ptr [ebx - 1], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 004a9674  39fe                   +cmp esi, edi
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
    // 004a9676  7caf                   -jl 0x4a9627
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a9627;
    }
L_0x004a9678:
    // 004a9678  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9679  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a967a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a967b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a967c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a9680(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9680  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a9681  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a9682  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a9683  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a9684  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004a9686  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a9688  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004a968a  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a968c  7e68                   -jle 0x4a96f6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a96f6;
    }
    // 004a968e  bd3f000000             -mov ebp, 0x3f
    cpu.ebp = 63 /*0x3f*/;
    // 004a9693  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004a9695  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x004a9697:
    // 004a9697  81feff000000           +cmp esi, 0xff
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a969d  755c                   -jne 0x4a96fb
    if (!cpu.flags.zf)
    {
        goto L_0x004a96fb;
    }
    // 004a969f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004a96a1:
    // 004a96a1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a96a3  884103                 -mov byte ptr [ecx + 3], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(3) /* 0x3 */) = cpu.al;
    // 004a96a6  8a13                   -mov dl, byte ptr [ebx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx);
    // 004a96a8  69d2ff000000           -imul edx, edx, 0xff
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(255 /*0xff*/)));
    // 004a96ae  83c220                 -add edx, 0x20
    (cpu.edx) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004a96b1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a96b3  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a96b6  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a96b8  884102                 -mov byte ptr [ecx + 2], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 004a96bb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a96bd  8a4301                 -mov al, byte ptr [ebx + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004a96c0  69c0ff000000           -imul eax, eax, 0xff
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(255 /*0xff*/)));
    // 004a96c6  8d5020                 -lea edx, [eax + 0x20]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004a96c9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a96cb  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a96ce  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a96d0  884101                 -mov byte ptr [ecx + 1], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004a96d3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a96d5  8a4302                 -mov al, byte ptr [ebx + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 004a96d8  69c0ff000000           -imul eax, eax, 0xff
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(255 /*0xff*/)));
    // 004a96de  8d5020                 -lea edx, [eax + 0x20]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004a96e1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a96e3  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a96e6  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a96e8  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a96eb  83c303                 -add ebx, 3
    (cpu.ebx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004a96ee  46                     -inc esi
    (cpu.esi)++;
    // 004a96ef  8841fc                 -mov byte ptr [ecx - 4], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-4) /* -0x4 */) = cpu.al;
    // 004a96f2  39fe                   +cmp esi, edi
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
    // 004a96f4  7ca1                   -jl 0x4a9697
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a9697;
    }
L_0x004a96f6:
    // 004a96f6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a96f7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a96f8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a96f9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a96fa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a96fb:
    // 004a96fb  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
    // 004a9700  eb9f                   -jmp 0x4a96a1
    goto L_0x004a96a1;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a9704(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9704  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a9705  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a9706  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a9707  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a9708  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004a970a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a970c  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004a970e  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004a9710  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a9712  7e58                   -jle 0x4a976c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a976c;
    }
    // 004a9714  bdff000000             -mov ebp, 0xff
    cpu.ebp = 255 /*0xff*/;
    // 004a9719  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x004a971b:
    // 004a971b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a971d  8a01                   -mov al, byte ptr [ecx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx);
    // 004a971f  6bc03f                 -imul eax, eax, 0x3f
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(63 /*0x3f*/)));
    // 004a9722  8d9080000000           -lea edx, [eax + 0x80]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(128) /* 0x80 */);
    // 004a9728  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a972a  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a972d  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a972f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a9731  8803                   -mov byte ptr [ebx], al
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.al;
    // 004a9733  8a5101                 -mov dl, byte ptr [ecx + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 004a9736  6bd23f                 -imul edx, edx, 0x3f
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(63 /*0x3f*/)));
    // 004a9739  81c280000000           -add edx, 0x80
    (cpu.edx) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 004a973f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a9741  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a9744  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a9746  884301                 -mov byte ptr [ebx + 1], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004a9749  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a974b  8a4102                 -mov al, byte ptr [ecx + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 004a974e  6bc03f                 -imul eax, eax, 0x3f
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(63 /*0x3f*/)));
    // 004a9751  8d9080000000           -lea edx, [eax + 0x80]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(128) /* 0x80 */);
    // 004a9757  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a9759  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a975c  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a975e  83c303                 -add ebx, 3
    (cpu.ebx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004a9761  83c103                 -add ecx, 3
    (cpu.ecx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004a9764  46                     -inc esi
    (cpu.esi)++;
    // 004a9765  8843ff                 -mov byte ptr [ebx - 1], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 004a9768  39fe                   +cmp esi, edi
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
    // 004a976a  7caf                   -jl 0x4a971b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a971b;
    }
L_0x004a976c:
    // 004a976c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a976d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a976e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a976f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9770  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a9774(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9774  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a9775  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a9776  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a9777  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a977a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a977c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a977e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a9780  7e33                   -jle 0x4a97b5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a97b5;
    }
    // 004a9782  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x004a9784:
    // 004a9784  81f9ff000000           +cmp ecx, 0xff
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
    // 004a978a  7430                   -je 0x4a97bc
    if (cpu.flags.zf)
    {
        goto L_0x004a97bc;
    }
    // 004a978c  c70424ff000000         -mov dword ptr [esp], 0xff
    app->getMemory<x86::reg32>(cpu.esp) = 255 /*0xff*/;
L_0x004a9793:
    // 004a9793  8a1c24                 -mov bl, byte ptr [esp]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp);
    // 004a9796  885803                 -mov byte ptr [eax + 3], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(3) /* 0x3 */) = cpu.bl;
    // 004a9799  8a1a                   -mov bl, byte ptr [edx]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx);
    // 004a979b  885802                 -mov byte ptr [eax + 2], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(2) /* 0x2 */) = cpu.bl;
    // 004a979e  8a5a01                 -mov bl, byte ptr [edx + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004a97a1  83c203                 -add edx, 3
    (cpu.edx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004a97a4  885801                 -mov byte ptr [eax + 1], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = cpu.bl;
    // 004a97a7  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a97aa  8a5aff                 -mov bl, byte ptr [edx - 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 004a97ad  41                     -inc ecx
    (cpu.ecx)++;
    // 004a97ae  8858fc                 -mov byte ptr [eax - 4], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.bl;
    // 004a97b1  39f1                   +cmp ecx, esi
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
    // 004a97b3  7ccf                   -jl 0x4a9784
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a9784;
    }
L_0x004a97b5:
    // 004a97b5  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a97b8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a97b9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a97ba  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a97bb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a97bc:
    // 004a97bc  31ff                   +xor edi, edi
    cpu.clear_co();
    cpu.set_szp((cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi))));
    // 004a97be  893c24                 -mov dword ptr [esp], edi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edi;
    // 004a97c1  ebd0                   -jmp 0x4a9793
    goto L_0x004a9793;
}

/* align: skip 0x90 */
void Application::sub_4a97c4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a97c4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a97c5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a97c6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a97c7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a97c8  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004a97ca  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a97cc  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004a97ce  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004a97d0  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a97d2  7e5c                   -jle 0x4a9830
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a9830;
    }
    // 004a97d4  bdff000000             -mov ebp, 0xff
    cpu.ebp = 255 /*0xff*/;
    // 004a97d9  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004a97db  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x004a97dd:
    // 004a97dd  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a97df  8a5302                 -mov dl, byte ptr [ebx + 2]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 004a97e2  6bd23f                 -imul edx, edx, 0x3f
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(63 /*0x3f*/)));
    // 004a97e5  81c280000000           -add edx, 0x80
    (cpu.edx) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 004a97eb  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a97ed  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a97f0  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a97f2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a97f4  8801                   -mov byte ptr [ecx], al
    app->getMemory<x86::reg8>(cpu.ecx) = cpu.al;
    // 004a97f6  8a5301                 -mov dl, byte ptr [ebx + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004a97f9  6bd23f                 -imul edx, edx, 0x3f
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(63 /*0x3f*/)));
    // 004a97fc  81c280000000           -add edx, 0x80
    (cpu.edx) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 004a9802  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a9804  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a9807  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a9809  884101                 -mov byte ptr [ecx + 1], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004a980c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a980e  8a03                   -mov al, byte ptr [ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx);
    // 004a9810  6bc03f                 -imul eax, eax, 0x3f
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(63 /*0x3f*/)));
    // 004a9813  8d9080000000           -lea edx, [eax + 0x80]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(128) /* 0x80 */);
    // 004a9819  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a981b  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a981e  f7fd                   -idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a9820  83c103                 -add ecx, 3
    (cpu.ecx) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004a9823  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a9826  46                     -inc esi
    (cpu.esi)++;
    // 004a9827  8841ff                 -mov byte ptr [ecx - 1], al
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 004a982a  39fe                   +cmp esi, edi
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
    // 004a982c  7caf                   -jl 0x4a97dd
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a97dd;
    }
    // 004a982e  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x004a9830:
    // 004a9830  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9831  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9832  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9833  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9834  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a9838(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9838  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a9839  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a983a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a983c  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a983e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a9840  7e1e                   -jle 0x4a9860
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a9860;
    }
    // 004a9842  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x004a9844:
    // 004a9844  8a5a02                 -mov bl, byte ptr [edx + 2]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 004a9847  8818                   -mov byte ptr [eax], bl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.bl;
    // 004a9849  8a5a01                 -mov bl, byte ptr [edx + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004a984c  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a984f  885801                 -mov byte ptr [eax + 1], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = cpu.bl;
    // 004a9852  83c003                 -add eax, 3
    (cpu.eax) += x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004a9855  8a5afc                 -mov bl, byte ptr [edx - 4]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 004a9858  41                     -inc ecx
    (cpu.ecx)++;
    // 004a9859  8858ff                 -mov byte ptr [eax - 1], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(-1) /* -0x1 */) = cpu.bl;
    // 004a985c  39f1                   +cmp ecx, esi
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
    // 004a985e  7ce4                   -jl 0x4a9844
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a9844;
    }
L_0x004a9860:
    // 004a9860  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9861  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9862  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a9863(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9863  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a9864  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a9866  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a9868  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a986a  e836540000             -call 0x4aeca5
    cpu.esp -= 4;
    sub_4aeca5(app, cpu);
    if (cpu.terminate) return;
    // 004a986f  ff4310                 -inc dword ptr [ebx + 0x10]
    (app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */))++;
    // 004a9872  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9873  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a9874(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9874  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a9875  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a9876  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a9877  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a9878  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a987a  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004a987d  ff1520cb4d00           -call dword ptr [0x4dcb20]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098272) /* 0x4dcb20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a9883  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004a9886  8b480c                 -mov ecx, dword ptr [eax + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004a9889  83f901                 +cmp ecx, 1
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
    // 004a988c  741b                   -je 0x4a98a9
    if (cpu.flags.zf)
    {
        goto L_0x004a98a9;
    }
    // 004a988e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004a9890  7410                   -je 0x4a98a2
    if (cpu.flags.zf)
    {
        goto L_0x004a98a2;
    }
    // 004a9892  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004a9895  ff1524cb4d00           -call dword ptr [0x4dcb24]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098276) /* 0x4dcb24 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a989b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a989d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a989e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a989f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a98a0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a98a1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a98a2:
    // 004a98a2  c7400c01000000         -mov dword ptr [eax + 0xc], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = 1 /*0x1*/;
L_0x004a98a9:
    // 004a98a9  8a660c                 -mov ah, byte ptr [esi + 0xc]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004a98ac  80e4cf                 -and ah, 0xcf
    cpu.ah &= x86::reg8(x86::sreg8(207 /*0xcf*/));
    // 004a98af  8b6e0c                 -mov ebp, dword ptr [esi + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004a98b2  88660c                 -mov byte ptr [esi + 0xc], ah
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.ah;
    // 004a98b5  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004a98b8  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004a98bb  83e530                 -and ebp, 0x30
    cpu.ebp &= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 004a98be  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004a98c0  7507                   -jne 0x4a98c9
    if (!cpu.flags.zf)
    {
        goto L_0x004a98c9;
    }
    // 004a98c2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a98c4  e802250000             -call 0x4abdcb
    cpu.esp -= 4;
    sub_4abdcb(app, cpu);
    if (cpu.terminate) return;
L_0x004a98c9:
    // 004a98c9  8a4e0d                 -mov cl, byte ptr [esi + 0xd]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(13) /* 0xd */);
    // 004a98cc  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004a98ce  f6c104                 +test cl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 4 /*0x4*/));
    // 004a98d1  7414                   -je 0x4a98e7
    if (cpu.flags.zf)
    {
        goto L_0x004a98e7;
    }
    // 004a98d3  88cd                   -mov ch, cl
    cpu.ch = cpu.cl;
    // 004a98d5  80e5fa                 -and ch, 0xfa
    cpu.ch &= x86::reg8(x86::sreg8(250 /*0xfa*/));
    // 004a98d8  88e8                   -mov al, ch
    cpu.al = cpu.ch;
    // 004a98da  886e0d                 -mov byte ptr [esi + 0xd], ch
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(13) /* 0xd */) = cpu.ch;
    // 004a98dd  0c01                   -or al, 1
    cpu.al |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004a98df  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 004a98e4  88460d                 -mov byte ptr [esi + 0xd], al
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(13) /* 0xd */) = cpu.al;
L_0x004a98e7:
    // 004a98e7  b963984a00             -mov ecx, 0x4a9863
    cpu.ecx = 4888675 /*0x4a9863*/;
    // 004a98ec  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a98ee  e864790000             -call 0x4b1257
    cpu.esp -= 4;
    sub_4b1257(app, cpu);
    if (cpu.terminate) return;
    // 004a98f3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a98f5  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a98f7  7418                   -je 0x4a9911
    if (cpu.flags.zf)
    {
        goto L_0x004a9911;
    }
    // 004a98f9  8a660d                 -mov ah, byte ptr [esi + 0xd]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(13) /* 0xd */);
    // 004a98fc  80e4fa                 -and ah, 0xfa
    cpu.ah &= x86::reg8(x86::sreg8(250 /*0xfa*/));
    // 004a98ff  88e3                   -mov bl, ah
    cpu.bl = cpu.ah;
    // 004a9901  88660d                 -mov byte ptr [esi + 0xd], ah
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(13) /* 0xd */) = cpu.ah;
    // 004a9904  80cb04                 -or bl, 4
    cpu.bl |= x86::reg8(x86::sreg8(4 /*0x4*/));
    // 004a9907  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a9909  885e0d                 -mov byte ptr [esi + 0xd], bl
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(13) /* 0xd */) = cpu.bl;
    // 004a990c  e83ed5ffff             -call 0x4a6e4f
    cpu.esp -= 4;
    sub_4a6e4f(app, cpu);
    if (cpu.terminate) return;
L_0x004a9911:
    // 004a9911  f6460c20               +test byte ptr [esi + 0xc], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(12) /* 0xc */) & 32 /*0x20*/));
    // 004a9915  7405                   -je 0x4a991c
    if (cpu.flags.zf)
    {
        goto L_0x004a991c;
    }
    // 004a9917  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
L_0x004a991c:
    // 004a991c  8b7e0c                 -mov edi, dword ptr [esi + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004a991f  09ef                   -or edi, ebp
    cpu.edi |= x86::reg32(x86::sreg32(cpu.ebp));
    // 004a9921  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004a9924  897e0c                 -mov dword ptr [esi + 0xc], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 004a9927  ff1524cb4d00           -call dword ptr [0x4dcb24]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098276) /* 0x4dcb24 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a992d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a992f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9930  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9931  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9932  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9933  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a9934(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9934  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a9935  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a9936  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a9937  8b35540a4e00           -mov esi, dword ptr [0x4e0a54]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5114452) /* 0x4e0a54 */);
    // 004a993d  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004a993f  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004a9941  83f90c                 +cmp ecx, 0xc
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a9944  7336                   -jae 0x4a997c
    if (!cpu.flags.cf)
    {
        goto L_0x004a997c;
    }
L_0x004a9946:
    // 004a9946  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a9948  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004a994a  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a994d  8b35500a4e00           -mov esi, dword ptr [0x4e0a50]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5114448) /* 0x4e0a50 */);
    // 004a9953  c1ef10                 -shr edi, 0x10
    cpu.edi >>= 16 /*0x10*/ % 32;
    // 004a9956  43                     -inc ebx
    (cpu.ebx)++;
    // 004a9957  033c85580a4e00         -add edi, dword ptr [eax*4 + 0x4e0a58]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5114456) /* 0x4e0a58 */ + cpu.eax * 4)));
    // 004a995e  a1480a4e00             -mov eax, dword ptr [0x4e0a48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5114440) /* 0x4e0a48 */);
    // 004a9963  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a9965  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a9967  8a043e                 -mov al, byte ptr [esi + edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.edi * 1);
    // 004a996a  8b3d400a4e00           -mov edi, dword ptr [0x4e0a40]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5114432) /* 0x4e0a40 */);
    // 004a9970  8843ff                 -mov byte ptr [ebx - 1], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 004a9973  01fd                   +add ebp, edi
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
    // 004a9975  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a9976  75ce                   -jne 0x4a9946
    if (!cpu.flags.zf)
    {
        goto L_0x004a9946;
    }
    // 004a9978  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9979  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a997a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a997b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a997c:
    // 004a997c  891d200a4e00           -mov dword ptr [0x4e0a20], ebx
    app->getMemory<x86::reg32>(x86::reg32(5114400) /* 0x4e0a20 */) = cpu.ebx;
    // 004a9982  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a9984  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a9986  8b35540a4e00           -mov esi, dword ptr [0x4e0a54]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5114452) /* 0x4e0a54 */);
    // 004a998c  c1ee0e                 -shr esi, 0xe
    cpu.esi >>= 14 /*0xe*/ % 32;
    // 004a998f  83e003                 -and eax, 3
    cpu.eax &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004a9992  a3240a4e00             -mov dword ptr [0x4e0a24], eax
    app->getMemory<x86::reg32>(x86::reg32(5114404) /* 0x4e0a24 */) = cpu.eax;
    // 004a9997  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004a9999  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a999b  83e0fc                 -and eax, 0xfffffffc
    cpu.eax &= x86::reg32(x86::sreg32(4294967292 /*0xfffffffc*/));
    // 004a999e  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004a99a1  a3280a4e00             -mov dword ptr [0x4e0a28], eax
    app->getMemory<x86::reg32>(x86::reg32(5114408) /* 0x4e0a28 */) = cpu.eax;
    // 004a99a6  890d2c0a4e00           -mov dword ptr [0x4e0a2c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5114412) /* 0x4e0a2c */) = cpu.ecx;
    // 004a99ac  a1480a4e00             -mov eax, dword ptr [0x4e0a48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5114440) /* 0x4e0a48 */);
    // 004a99b1  8b0d400a4e00           -mov ecx, dword ptr [0x4e0a40]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5114432) /* 0x4e0a40 */);
    // 004a99b7  c1f810                 +sar eax, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 004a99ba  7809                   -js 0x4a99c5
    if (cpu.flags.sf)
    {
        goto L_0x004a99c5;
    }
    // 004a99bc  8b8486580a4e00         -mov eax, dword ptr [esi + eax*4 + 0x4e0a58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5114456) /* 0x4e0a58 */ + cpu.eax * 4);
    // 004a99c3  eb0b                   -jmp 0x4a99d0
    goto L_0x004a99d0;
L_0x004a99c5:
    // 004a99c5  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 004a99c7  8b8486580a4e00         -mov eax, dword ptr [esi + eax*4 + 0x4e0a58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5114456) /* 0x4e0a58 */ + cpu.eax * 4);
    // 004a99ce  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
L_0x004a99d0:
    // 004a99d0  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004a99d3  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a99d5  a3340a4e00             -mov dword ptr [0x4e0a34], eax
    app->getMemory<x86::reg32>(x86::reg32(5114420) /* 0x4e0a34 */) = cpu.eax;
    // 004a99da  03865c0a4e00           -add eax, dword ptr [esi + 0x4e0a5c]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5114460) /* 0x4e0a5c */)));
    // 004a99e0  a3300a4e00             -mov dword ptr [0x4e0a30], eax
    app->getMemory<x86::reg32>(x86::reg32(5114416) /* 0x4e0a30 */) = cpu.eax;
    // 004a99e5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a99e7  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004a99e9  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a99ec  8b35500a4e00           -mov esi, dword ptr [0x4e0a50]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5114448) /* 0x4e0a50 */);
    // 004a99f2  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004a99f5  033485580a4e00         -add esi, dword ptr [eax*4 + 0x4e0a58]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5114456) /* 0x4e0a58 */ + cpu.eax * 4)));
    // 004a99fc  01ce                   -add esi, ecx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a99fe  c1e510                 -shl ebp, 0x10
    cpu.ebp <<= 16 /*0x10*/ % 32;
    // 004a9a01  8b3d400a4e00           -mov edi, dword ptr [0x4e0a40]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5114432) /* 0x4e0a40 */);
    // 004a9a07  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004a9a0a  8b0d480a4e00           -mov ecx, dword ptr [0x4e0a48]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5114440) /* 0x4e0a48 */);
    // 004a9a10  c1e710                 -shl edi, 0x10
    cpu.edi <<= 16 /*0x10*/ % 32;
    // 004a9a13  c1e110                 +shl ecx, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.ecx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
L_0x004a9a16:
    // 004a9a16  ff0d240a4e00           +dec dword ptr [0x4e0a24]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5114404) /* 0x4e0a24 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a9a1c  781d                   -js 0x4a9a3b
    if (cpu.flags.sf)
    {
        goto L_0x004a9a3b;
    }
    // 004a9a1e  43                     -inc ebx
    (cpu.ebx)++;
    // 004a9a1f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a9a21  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004a9a23  891d200a4e00           -mov dword ptr [0x4e0a20], ebx
    app->getMemory<x86::reg32>(x86::reg32(5114400) /* 0x4e0a20 */) = cpu.ebx;
    // 004a9a29  8843ff                 -mov byte ptr [ebx - 1], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 004a9a2c  01ca                   +add edx, ecx
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
    // 004a9a2e  19c0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 004a9a30  01fd                   +add ebp, edi
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
    // 004a9a32  133485340a4e00         +adc esi, dword ptr [eax*4 + 0x4e0a34]
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5114420) /* 0x4e0a34 */ + cpu.eax * 4))) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a9a39  ebdb                   -jmp 0x4a9a16
    goto L_0x004a9a16;
L_0x004a9a3b:
    // 004a9a3b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a9a3d  01ca                   +add edx, ecx
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
    // 004a9a3f  19db                   -sbb ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx) + cpu.flags.cf);
    // 004a9a41  01fd                   +add ebp, edi
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
    // 004a9a43  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004a9a45  13349d340a4e00         -adc esi, dword ptr [ebx*4 + 0x4e0a34]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5114420) /* 0x4e0a34 */ + cpu.ebx * 4)) + cpu.flags.cf);
    // 004a9a4c  a2380a4e00             -mov byte ptr [0x4e0a38], al
    app->getMemory<x86::reg8>(x86::reg32(5114424) /* 0x4e0a38 */) = cpu.al;
    // 004a9a51  01ca                   +add edx, ecx
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
    // 004a9a53  19db                   -sbb ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx) + cpu.flags.cf);
    // 004a9a55  01fd                   +add ebp, edi
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
    // 004a9a57  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004a9a59  13349d340a4e00         -adc esi, dword ptr [ebx*4 + 0x4e0a34]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5114420) /* 0x4e0a34 */ + cpu.ebx * 4)) + cpu.flags.cf);
    // 004a9a60  a2390a4e00             -mov byte ptr [0x4e0a39], al
    app->getMemory<x86::reg8>(x86::reg32(5114425) /* 0x4e0a39 */) = cpu.al;
    // 004a9a65  01ca                   +add edx, ecx
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
    // 004a9a67  19db                   -sbb ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx) + cpu.flags.cf);
    // 004a9a69  01fd                   +add ebp, edi
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
    // 004a9a6b  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004a9a6d  13349d340a4e00         -adc esi, dword ptr [ebx*4 + 0x4e0a34]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5114420) /* 0x4e0a34 */ + cpu.ebx * 4)) + cpu.flags.cf);
    // 004a9a74  a23a0a4e00             -mov byte ptr [0x4e0a3a], al
    app->getMemory<x86::reg8>(x86::reg32(5114426) /* 0x4e0a3a */) = cpu.al;
    // 004a9a79  01ca                   +add edx, ecx
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
    // 004a9a7b  19db                   -sbb ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx) + cpu.flags.cf);
    // 004a9a7d  01fd                   +add ebp, edi
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
    // 004a9a7f  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004a9a81  13349d340a4e00         -adc esi, dword ptr [ebx*4 + 0x4e0a34]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5114420) /* 0x4e0a34 */ + cpu.ebx * 4)) + cpu.flags.cf);
    // 004a9a88  a23b0a4e00             -mov byte ptr [0x4e0a3b], al
    app->getMemory<x86::reg8>(x86::reg32(5114427) /* 0x4e0a3b */) = cpu.al;
    // 004a9a8d  8b1d200a4e00           -mov ebx, dword ptr [0x4e0a20]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5114400) /* 0x4e0a20 */);
    // 004a9a93  a1280a4e00             -mov eax, dword ptr [0x4e0a28]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5114408) /* 0x4e0a28 */);
    // 004a9a98  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a9a9b  83e804                 +sub eax, 4
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a9a9e  891d200a4e00           -mov dword ptr [0x4e0a20], ebx
    app->getMemory<x86::reg32>(x86::reg32(5114400) /* 0x4e0a20 */) = cpu.ebx;
    // 004a9aa4  a3280a4e00             -mov dword ptr [0x4e0a28], eax
    app->getMemory<x86::reg32>(x86::reg32(5114408) /* 0x4e0a28 */) = cpu.eax;
    // 004a9aa9  a1380a4e00             -mov eax, dword ptr [0x4e0a38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5114424) /* 0x4e0a38 */);
    // 004a9aae  8943fc                 -mov dword ptr [ebx - 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004a9ab1  7588                   -jne 0x4a9a3b
    if (!cpu.flags.zf)
    {
        goto L_0x004a9a3b;
    }
L_0x004a9ab3:
    // 004a9ab3  ff0d2c0a4e00           +dec dword ptr [0x4e0a2c]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5114412) /* 0x4e0a2c */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a9ab9  781d                   -js 0x4a9ad8
    if (cpu.flags.sf)
    {
        goto L_0x004a9ad8;
    }
    // 004a9abb  43                     -inc ebx
    (cpu.ebx)++;
    // 004a9abc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a9abe  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004a9ac0  891d200a4e00           -mov dword ptr [0x4e0a20], ebx
    app->getMemory<x86::reg32>(x86::reg32(5114400) /* 0x4e0a20 */) = cpu.ebx;
    // 004a9ac6  8843ff                 -mov byte ptr [ebx - 1], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 004a9ac9  01ca                   +add edx, ecx
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
    // 004a9acb  19c0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 004a9acd  01fd                   +add ebp, edi
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
    // 004a9acf  133485340a4e00         +adc esi, dword ptr [eax*4 + 0x4e0a34]
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5114420) /* 0x4e0a34 */ + cpu.eax * 4))) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a9ad6  ebdb                   -jmp 0x4a9ab3
    goto L_0x004a9ab3;
L_0x004a9ad8:
    // 004a9ad8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9ad9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9ada  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9adb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a9adc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9adc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a9add  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a9ade  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a9adf  8b35540a4e00           -mov esi, dword ptr [0x4e0a54]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5114452) /* 0x4e0a54 */);
    // 004a9ae5  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004a9ae7  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
L_0x004a9ae9:
    // 004a9ae9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a9aeb  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004a9aed  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a9af0  8b35500a4e00           -mov esi, dword ptr [0x4e0a50]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5114448) /* 0x4e0a50 */);
    // 004a9af6  c1ef10                 -shr edi, 0x10
    cpu.edi >>= 16 /*0x10*/ % 32;
    // 004a9af9  83c302                 -add ebx, 2
    (cpu.ebx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004a9afc  033485580a4e00         -add esi, dword ptr [eax*4 + 0x4e0a58]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5114456) /* 0x4e0a58 */ + cpu.eax * 4)));
    // 004a9b03  a1480a4e00             -mov eax, dword ptr [0x4e0a48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5114440) /* 0x4e0a48 */);
    // 004a9b08  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a9b0a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a9b0c  668b047e               -mov ax, word ptr [esi + edi*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.edi * 2);
    // 004a9b10  8b3d400a4e00           -mov edi, dword ptr [0x4e0a40]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5114432) /* 0x4e0a40 */);
    // 004a9b16  668943fe               -mov word ptr [ebx - 2], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(-2) /* -0x2 */) = cpu.ax;
    // 004a9b1a  01fd                   +add ebp, edi
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
    // 004a9b1c  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a9b1d  75ca                   -jne 0x4a9ae9
    if (!cpu.flags.zf)
    {
        goto L_0x004a9ae9;
    }
    // 004a9b1f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9b20  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9b21  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9b22  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4a9b24(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9b24  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a9b25  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a9b26  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a9b27  8b35540a4e00           -mov esi, dword ptr [0x4e0a54]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5114452) /* 0x4e0a54 */);
    // 004a9b2d  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004a9b2f  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004a9b31  83f90c                 +cmp ecx, 0xc
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a9b34  733a                   -jae 0x4a9b70
    if (!cpu.flags.cf)
    {
        goto L_0x004a9b70;
    }
L_0x004a9b36:
    // 004a9b36  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a9b38  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004a9b3a  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a9b3d  8b35500a4e00           -mov esi, dword ptr [0x4e0a50]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5114448) /* 0x4e0a50 */);
    // 004a9b43  c1ef10                 -shr edi, 0x10
    cpu.edi >>= 16 /*0x10*/ % 32;
    // 004a9b46  43                     -inc ebx
    (cpu.ebx)++;
    // 004a9b47  033c85580a4e00         -add edi, dword ptr [eax*4 + 0x4e0a58]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5114456) /* 0x4e0a58 */ + cpu.eax * 4)));
    // 004a9b4e  a1480a4e00             -mov eax, dword ptr [0x4e0a48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5114440) /* 0x4e0a48 */);
    // 004a9b53  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a9b55  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a9b57  8a043e                 -mov al, byte ptr [esi + edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.edi * 1);
    // 004a9b5a  8b3d400a4e00           -mov edi, dword ptr [0x4e0a40]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5114432) /* 0x4e0a40 */);
    // 004a9b60  3cff                   +cmp al, 0xff
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a9b62  7403                   -je 0x4a9b67
    if (cpu.flags.zf)
    {
        goto L_0x004a9b67;
    }
    // 004a9b64  8843ff                 -mov byte ptr [ebx - 1], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.al;
L_0x004a9b67:
    // 004a9b67  01fd                   +add ebp, edi
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
    // 004a9b69  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a9b6a  75ca                   -jne 0x4a9b36
    if (!cpu.flags.zf)
    {
        goto L_0x004a9b36;
    }
    // 004a9b6c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9b6d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9b6e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9b6f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a9b70:
    // 004a9b70  891d200a4e00           -mov dword ptr [0x4e0a20], ebx
    app->getMemory<x86::reg32>(x86::reg32(5114400) /* 0x4e0a20 */) = cpu.ebx;
    // 004a9b76  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a9b78  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a9b7a  8b35540a4e00           -mov esi, dword ptr [0x4e0a54]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5114452) /* 0x4e0a54 */);
    // 004a9b80  c1ee0e                 -shr esi, 0xe
    cpu.esi >>= 14 /*0xe*/ % 32;
    // 004a9b83  83e003                 -and eax, 3
    cpu.eax &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004a9b86  a3240a4e00             -mov dword ptr [0x4e0a24], eax
    app->getMemory<x86::reg32>(x86::reg32(5114404) /* 0x4e0a24 */) = cpu.eax;
    // 004a9b8b  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004a9b8d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a9b8f  83e0fc                 -and eax, 0xfffffffc
    cpu.eax &= x86::reg32(x86::sreg32(4294967292 /*0xfffffffc*/));
    // 004a9b92  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004a9b95  a3280a4e00             -mov dword ptr [0x4e0a28], eax
    app->getMemory<x86::reg32>(x86::reg32(5114408) /* 0x4e0a28 */) = cpu.eax;
    // 004a9b9a  890d2c0a4e00           -mov dword ptr [0x4e0a2c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5114412) /* 0x4e0a2c */) = cpu.ecx;
    // 004a9ba0  a1480a4e00             -mov eax, dword ptr [0x4e0a48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5114440) /* 0x4e0a48 */);
    // 004a9ba5  8b0d400a4e00           -mov ecx, dword ptr [0x4e0a40]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5114432) /* 0x4e0a40 */);
    // 004a9bab  c1f810                 +sar eax, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 004a9bae  7809                   -js 0x4a9bb9
    if (cpu.flags.sf)
    {
        goto L_0x004a9bb9;
    }
    // 004a9bb0  8b8486580a4e00         -mov eax, dword ptr [esi + eax*4 + 0x4e0a58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5114456) /* 0x4e0a58 */ + cpu.eax * 4);
    // 004a9bb7  eb0b                   -jmp 0x4a9bc4
    goto L_0x004a9bc4;
L_0x004a9bb9:
    // 004a9bb9  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 004a9bbb  8b8486580a4e00         -mov eax, dword ptr [esi + eax*4 + 0x4e0a58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5114456) /* 0x4e0a58 */ + cpu.eax * 4);
    // 004a9bc2  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
L_0x004a9bc4:
    // 004a9bc4  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004a9bc7  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a9bc9  a3340a4e00             -mov dword ptr [0x4e0a34], eax
    app->getMemory<x86::reg32>(x86::reg32(5114420) /* 0x4e0a34 */) = cpu.eax;
    // 004a9bce  03865c0a4e00           -add eax, dword ptr [esi + 0x4e0a5c]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5114460) /* 0x4e0a5c */)));
    // 004a9bd4  a3300a4e00             -mov dword ptr [0x4e0a30], eax
    app->getMemory<x86::reg32>(x86::reg32(5114416) /* 0x4e0a30 */) = cpu.eax;
    // 004a9bd9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a9bdb  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004a9bdd  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a9be0  8b35500a4e00           -mov esi, dword ptr [0x4e0a50]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5114448) /* 0x4e0a50 */);
    // 004a9be6  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004a9be9  033485580a4e00         -add esi, dword ptr [eax*4 + 0x4e0a58]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5114456) /* 0x4e0a58 */ + cpu.eax * 4)));
    // 004a9bf0  01ce                   -add esi, ecx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a9bf2  c1e510                 -shl ebp, 0x10
    cpu.ebp <<= 16 /*0x10*/ % 32;
    // 004a9bf5  8b3d400a4e00           -mov edi, dword ptr [0x4e0a40]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5114432) /* 0x4e0a40 */);
    // 004a9bfb  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004a9bfe  8b0d480a4e00           -mov ecx, dword ptr [0x4e0a48]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5114440) /* 0x4e0a48 */);
    // 004a9c04  c1e710                 -shl edi, 0x10
    cpu.edi <<= 16 /*0x10*/ % 32;
    // 004a9c07  c1e110                 +shl ecx, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.ecx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
L_0x004a9c0a:
    // 004a9c0a  ff0d240a4e00           +dec dword ptr [0x4e0a24]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5114404) /* 0x4e0a24 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a9c10  7821                   -js 0x4a9c33
    if (cpu.flags.sf)
    {
        goto L_0x004a9c33;
    }
    // 004a9c12  43                     -inc ebx
    (cpu.ebx)++;
    // 004a9c13  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a9c15  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004a9c17  891d200a4e00           -mov dword ptr [0x4e0a20], ebx
    app->getMemory<x86::reg32>(x86::reg32(5114400) /* 0x4e0a20 */) = cpu.ebx;
    // 004a9c1d  3cff                   +cmp al, 0xff
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a9c1f  7403                   -je 0x4a9c24
    if (cpu.flags.zf)
    {
        goto L_0x004a9c24;
    }
    // 004a9c21  8843ff                 -mov byte ptr [ebx - 1], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.al;
L_0x004a9c24:
    // 004a9c24  01ca                   +add edx, ecx
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
    // 004a9c26  19c0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 004a9c28  01fd                   +add ebp, edi
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
    // 004a9c2a  133485340a4e00         +adc esi, dword ptr [eax*4 + 0x4e0a34]
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5114420) /* 0x4e0a34 */ + cpu.eax * 4))) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a9c31  ebd7                   -jmp 0x4a9c0a
    goto L_0x004a9c0a;
L_0x004a9c33:
    // 004a9c33  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a9c35  01ca                   +add edx, ecx
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
    // 004a9c37  19db                   -sbb ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx) + cpu.flags.cf);
    // 004a9c39  01fd                   +add ebp, edi
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
    // 004a9c3b  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004a9c3d  13349d340a4e00         -adc esi, dword ptr [ebx*4 + 0x4e0a34]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5114420) /* 0x4e0a34 */ + cpu.ebx * 4)) + cpu.flags.cf);
    // 004a9c44  a2380a4e00             -mov byte ptr [0x4e0a38], al
    app->getMemory<x86::reg8>(x86::reg32(5114424) /* 0x4e0a38 */) = cpu.al;
    // 004a9c49  01ca                   +add edx, ecx
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
    // 004a9c4b  19db                   -sbb ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx) + cpu.flags.cf);
    // 004a9c4d  01fd                   +add ebp, edi
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
    // 004a9c4f  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004a9c51  13349d340a4e00         -adc esi, dword ptr [ebx*4 + 0x4e0a34]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5114420) /* 0x4e0a34 */ + cpu.ebx * 4)) + cpu.flags.cf);
    // 004a9c58  a2390a4e00             -mov byte ptr [0x4e0a39], al
    app->getMemory<x86::reg8>(x86::reg32(5114425) /* 0x4e0a39 */) = cpu.al;
    // 004a9c5d  01ca                   +add edx, ecx
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
    // 004a9c5f  19db                   -sbb ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx) + cpu.flags.cf);
    // 004a9c61  01fd                   +add ebp, edi
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
    // 004a9c63  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004a9c65  13349d340a4e00         -adc esi, dword ptr [ebx*4 + 0x4e0a34]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5114420) /* 0x4e0a34 */ + cpu.ebx * 4)) + cpu.flags.cf);
    // 004a9c6c  a23a0a4e00             -mov byte ptr [0x4e0a3a], al
    app->getMemory<x86::reg8>(x86::reg32(5114426) /* 0x4e0a3a */) = cpu.al;
    // 004a9c71  01ca                   +add edx, ecx
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
    // 004a9c73  19db                   -sbb ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx) + cpu.flags.cf);
    // 004a9c75  01fd                   +add ebp, edi
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
    // 004a9c77  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004a9c79  13349d340a4e00         -adc esi, dword ptr [ebx*4 + 0x4e0a34]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5114420) /* 0x4e0a34 */ + cpu.ebx * 4)) + cpu.flags.cf);
    // 004a9c80  a23b0a4e00             -mov byte ptr [0x4e0a3b], al
    app->getMemory<x86::reg8>(x86::reg32(5114427) /* 0x4e0a3b */) = cpu.al;
    // 004a9c85  a1380a4e00             -mov eax, dword ptr [0x4e0a38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5114424) /* 0x4e0a38 */);
    // 004a9c8a  8b1d200a4e00           -mov ebx, dword ptr [0x4e0a20]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5114400) /* 0x4e0a20 */);
    // 004a9c90  3cff                   +cmp al, 0xff
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a9c92  7434                   -je 0x4a9cc8
    if (cpu.flags.zf)
    {
        goto L_0x004a9cc8;
    }
    // 004a9c94  80fcff                 +cmp ah, 0xff
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
    // 004a9c97  742a                   -je 0x4a9cc3
    if (cpu.flags.zf)
    {
        goto L_0x004a9cc3;
    }
    // 004a9c99  c1c810                 -ror eax, 0x10
    {
        x86::reg32& op = cpu.eax;
        x86::reg32 shift = 16 /*0x10*/ % 32;
        while (shift)
        {
            x86::reg32 cf = op & 1;
            op = op >> 1 | cf << 31;
            shift--;
        }
    }
    // 004a9c9c  3cff                   +cmp al, 0xff
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a9c9e  7412                   -je 0x4a9cb2
    if (cpu.flags.zf)
    {
        goto L_0x004a9cb2;
    }
    // 004a9ca0  80fcff                 +cmp ah, 0xff
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
    // 004a9ca3  7407                   -je 0x4a9cac
    if (cpu.flags.zf)
    {
        goto L_0x004a9cac;
    }
    // 004a9ca5  c1c810                 +ror eax, 0x10
    {
        x86::reg32& op = cpu.eax;
        x86::reg32 count = 16 /*0x10*/ % 32;
        if (count) {
            op = (op >> count) | (op << (32 - count));
            cpu.flags.cf = (op >> (32 - 1)) & 1;
            if (count == 1) {
                cpu.flags.of = ((op >> (32 - 1)) ^ (op >> (32 - 2))) & 1;
            }
        }
    }
    // 004a9ca8  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004a9caa  eb44                   -jmp 0x4a9cf0
    goto L_0x004a9cf0;
L_0x004a9cac:
    // 004a9cac  90                     -nop 
    ;
    // 004a9cad  884302                 -mov byte ptr [ebx + 2], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 004a9cb0  eb09                   -jmp 0x4a9cbb
    goto L_0x004a9cbb;
L_0x004a9cb2:
    // 004a9cb2  80fcff                 +cmp ah, 0xff
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
    // 004a9cb5  7404                   -je 0x4a9cbb
    if (cpu.flags.zf)
    {
        goto L_0x004a9cbb;
    }
    // 004a9cb7  90                     -nop 
    ;
    // 004a9cb8  886303                 -mov byte ptr [ebx + 3], ah
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(3) /* 0x3 */) = cpu.ah;
L_0x004a9cbb:
    // 004a9cbb  c1c810                 +ror eax, 0x10
    {
        x86::reg32& op = cpu.eax;
        x86::reg32 count = 16 /*0x10*/ % 32;
        if (count) {
            op = (op >> count) | (op << (32 - count));
            cpu.flags.cf = (op >> (32 - 1)) & 1;
            if (count == 1) {
                cpu.flags.of = ((op >> (32 - 1)) ^ (op >> (32 - 2))) & 1;
            }
        }
    }
    // 004a9cbe  668903                 -mov word ptr [ebx], ax
    app->getMemory<x86::reg16>(cpu.ebx) = cpu.ax;
    // 004a9cc1  eb2d                   -jmp 0x4a9cf0
    goto L_0x004a9cf0;
L_0x004a9cc3:
    // 004a9cc3  90                     -nop 
    ;
    // 004a9cc4  8803                   -mov byte ptr [ebx], al
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.al;
    // 004a9cc6  eb09                   -jmp 0x4a9cd1
    goto L_0x004a9cd1;
L_0x004a9cc8:
    // 004a9cc8  80fcff                 +cmp ah, 0xff
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
    // 004a9ccb  7404                   -je 0x4a9cd1
    if (cpu.flags.zf)
    {
        goto L_0x004a9cd1;
    }
    // 004a9ccd  90                     -nop 
    ;
    // 004a9cce  886301                 -mov byte ptr [ebx + 1], ah
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */) = cpu.ah;
L_0x004a9cd1:
    // 004a9cd1  c1c810                 -ror eax, 0x10
    {
        x86::reg32& op = cpu.eax;
        x86::reg32 shift = 16 /*0x10*/ % 32;
        while (shift)
        {
            x86::reg32 cf = op & 1;
            op = op >> 1 | cf << 31;
            shift--;
        }
    }
    // 004a9cd4  3cff                   +cmp al, 0xff
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a9cd6  7410                   -je 0x4a9ce8
    if (cpu.flags.zf)
    {
        goto L_0x004a9ce8;
    }
    // 004a9cd8  80fcff                 +cmp ah, 0xff
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
    // 004a9cdb  7406                   -je 0x4a9ce3
    if (cpu.flags.zf)
    {
        goto L_0x004a9ce3;
    }
    // 004a9cdd  66894302               -mov word ptr [ebx + 2], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(2) /* 0x2 */) = cpu.ax;
    // 004a9ce1  eb0d                   -jmp 0x4a9cf0
    goto L_0x004a9cf0;
L_0x004a9ce3:
    // 004a9ce3  884302                 -mov byte ptr [ebx + 2], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 004a9ce6  eb08                   -jmp 0x4a9cf0
    goto L_0x004a9cf0;
L_0x004a9ce8:
    // 004a9ce8  80fcff                 +cmp ah, 0xff
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
    // 004a9ceb  7403                   -je 0x4a9cf0
    if (cpu.flags.zf)
    {
        goto L_0x004a9cf0;
    }
    // 004a9ced  886303                 -mov byte ptr [ebx + 3], ah
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(3) /* 0x3 */) = cpu.ah;
L_0x004a9cf0:
    // 004a9cf0  a1280a4e00             -mov eax, dword ptr [0x4e0a28]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5114408) /* 0x4e0a28 */);
    // 004a9cf5  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a9cf8  83e804                 +sub eax, 4
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a9cfb  891d200a4e00           -mov dword ptr [0x4e0a20], ebx
    app->getMemory<x86::reg32>(x86::reg32(5114400) /* 0x4e0a20 */) = cpu.ebx;
    // 004a9d01  a3280a4e00             -mov dword ptr [0x4e0a28], eax
    app->getMemory<x86::reg32>(x86::reg32(5114408) /* 0x4e0a28 */) = cpu.eax;
    // 004a9d06  0f8527ffffff           -jne 0x4a9c33
    if (!cpu.flags.zf)
    {
        goto L_0x004a9c33;
    }
L_0x004a9d0c:
    // 004a9d0c  ff0d2c0a4e00           +dec dword ptr [0x4e0a2c]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5114412) /* 0x4e0a2c */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a9d12  7821                   -js 0x4a9d35
    if (cpu.flags.sf)
    {
        goto L_0x004a9d35;
    }
    // 004a9d14  43                     -inc ebx
    (cpu.ebx)++;
    // 004a9d15  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a9d17  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004a9d19  891d200a4e00           -mov dword ptr [0x4e0a20], ebx
    app->getMemory<x86::reg32>(x86::reg32(5114400) /* 0x4e0a20 */) = cpu.ebx;
    // 004a9d1f  3cff                   +cmp al, 0xff
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a9d21  7403                   -je 0x4a9d26
    if (cpu.flags.zf)
    {
        goto L_0x004a9d26;
    }
    // 004a9d23  8843ff                 -mov byte ptr [ebx - 1], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.al;
L_0x004a9d26:
    // 004a9d26  01ca                   +add edx, ecx
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
    // 004a9d28  19c0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 004a9d2a  01fd                   +add ebp, edi
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
    // 004a9d2c  133485340a4e00         +adc esi, dword ptr [eax*4 + 0x4e0a34]
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5114420) /* 0x4e0a34 */ + cpu.eax * 4))) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a9d33  ebd7                   -jmp 0x4a9d0c
    goto L_0x004a9d0c;
L_0x004a9d35:
    // 004a9d35  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9d36  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9d37  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9d38  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a9d39(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9d39  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a9d3a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a9d3b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a9d3c  8b35540a4e00           -mov esi, dword ptr [0x4e0a54]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5114452) /* 0x4e0a54 */);
    // 004a9d42  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004a9d44  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
L_0x004a9d46:
    // 004a9d46  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a9d48  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004a9d4a  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a9d4d  8b35500a4e00           -mov esi, dword ptr [0x4e0a50]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5114448) /* 0x4e0a50 */);
    // 004a9d53  c1ef10                 -shr edi, 0x10
    cpu.edi >>= 16 /*0x10*/ % 32;
    // 004a9d56  83c302                 -add ebx, 2
    (cpu.ebx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004a9d59  033485580a4e00         -add esi, dword ptr [eax*4 + 0x4e0a58]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5114456) /* 0x4e0a58 */ + cpu.eax * 4)));
    // 004a9d60  a1480a4e00             -mov eax, dword ptr [0x4e0a48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5114440) /* 0x4e0a48 */);
    // 004a9d65  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a9d67  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a9d69  668b047e               -mov ax, word ptr [esi + edi*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.edi * 2);
    // 004a9d6d  8b3d400a4e00           -mov edi, dword ptr [0x4e0a40]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5114432) /* 0x4e0a40 */);
    // 004a9d73  6683f800               +cmp ax, 0
    {
        x86::reg16 tmp1 = cpu.ax;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 004a9d77  7404                   -je 0x4a9d7d
    if (cpu.flags.zf)
    {
        goto L_0x004a9d7d;
    }
    // 004a9d79  668943fe               -mov word ptr [ebx - 2], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(-2) /* -0x2 */) = cpu.ax;
L_0x004a9d7d:
    // 004a9d7d  01fd                   +add ebp, edi
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
    // 004a9d7f  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a9d80  75c4                   -jne 0x4a9d46
    if (!cpu.flags.zf)
    {
        goto L_0x004a9d46;
    }
    // 004a9d82  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9d83  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9d84  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9d85  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4a9d88(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a9d88  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a9d89  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a9d8a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a9d8b  8b35540a4e00           -mov esi, dword ptr [0x4e0a54]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5114452) /* 0x4e0a54 */);
    // 004a9d91  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004a9d93  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004a9d95  83f90c                 +cmp ecx, 0xc
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a9d98  7345                   -jae 0x4a9ddf
    if (!cpu.flags.cf)
    {
        goto L_0x004a9ddf;
    }
L_0x004a9d9a:
    // 004a9d9a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a9d9c  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004a9d9e  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a9da1  8b35500a4e00           -mov esi, dword ptr [0x4e0a50]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5114448) /* 0x4e0a50 */);
    // 004a9da7  c1ef10                 -shr edi, 0x10
    cpu.edi >>= 16 /*0x10*/ % 32;
    // 004a9daa  43                     -inc ebx
    (cpu.ebx)++;
    // 004a9dab  033c85580a4e00         -add edi, dword ptr [eax*4 + 0x4e0a58]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5114456) /* 0x4e0a58 */ + cpu.eax * 4)));
    // 004a9db2  a1480a4e00             -mov eax, dword ptr [0x4e0a48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5114440) /* 0x4e0a48 */);
    // 004a9db7  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a9db9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a9dbb  8a043e                 -mov al, byte ptr [esi + edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.edi * 1);
    // 004a9dbe  8b3d400a4e00           -mov edi, dword ptr [0x4e0a40]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5114432) /* 0x4e0a40 */);
    // 004a9dc4  3cfe                   +cmp al, 0xfe
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(254 /*0xfe*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a9dc6  7509                   -jne 0x4a9dd1
    if (!cpu.flags.zf)
    {
        goto L_0x004a9dd1;
    }
    // 004a9dc8  8a43ff                 -mov al, byte ptr [ebx - 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */);
    // 004a9dcb  8a80d8e34d00           -mov al, byte ptr [eax + 0x4de3d8]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5104600) /* 0x4de3d8 */);
L_0x004a9dd1:
    // 004a9dd1  7703                   -ja 0x4a9dd6
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004a9dd6;
    }
    // 004a9dd3  8843ff                 -mov byte ptr [ebx - 1], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.al;
L_0x004a9dd6:
    // 004a9dd6  01fd                   +add ebp, edi
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
    // 004a9dd8  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a9dd9  75bf                   -jne 0x4a9d9a
    if (!cpu.flags.zf)
    {
        goto L_0x004a9d9a;
    }
    // 004a9ddb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9ddc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9ddd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9dde  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a9ddf:
    // 004a9ddf  891d200a4e00           -mov dword ptr [0x4e0a20], ebx
    app->getMemory<x86::reg32>(x86::reg32(5114400) /* 0x4e0a20 */) = cpu.ebx;
    // 004a9de5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a9de7  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a9de9  8b35540a4e00           -mov esi, dword ptr [0x4e0a54]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5114452) /* 0x4e0a54 */);
    // 004a9def  c1ee0e                 -shr esi, 0xe
    cpu.esi >>= 14 /*0xe*/ % 32;
    // 004a9df2  83e003                 -and eax, 3
    cpu.eax &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004a9df5  a3240a4e00             -mov dword ptr [0x4e0a24], eax
    app->getMemory<x86::reg32>(x86::reg32(5114404) /* 0x4e0a24 */) = cpu.eax;
    // 004a9dfa  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004a9dfc  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a9dfe  83e0fc                 -and eax, 0xfffffffc
    cpu.eax &= x86::reg32(x86::sreg32(4294967292 /*0xfffffffc*/));
    // 004a9e01  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004a9e04  a3280a4e00             -mov dword ptr [0x4e0a28], eax
    app->getMemory<x86::reg32>(x86::reg32(5114408) /* 0x4e0a28 */) = cpu.eax;
    // 004a9e09  890d2c0a4e00           -mov dword ptr [0x4e0a2c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5114412) /* 0x4e0a2c */) = cpu.ecx;
    // 004a9e0f  a1480a4e00             -mov eax, dword ptr [0x4e0a48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5114440) /* 0x4e0a48 */);
    // 004a9e14  8b0d400a4e00           -mov ecx, dword ptr [0x4e0a40]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5114432) /* 0x4e0a40 */);
    // 004a9e1a  c1f810                 +sar eax, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 004a9e1d  7809                   -js 0x4a9e28
    if (cpu.flags.sf)
    {
        goto L_0x004a9e28;
    }
    // 004a9e1f  8b8486580a4e00         -mov eax, dword ptr [esi + eax*4 + 0x4e0a58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5114456) /* 0x4e0a58 */ + cpu.eax * 4);
    // 004a9e26  eb0b                   -jmp 0x4a9e33
    goto L_0x004a9e33;
L_0x004a9e28:
    // 004a9e28  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 004a9e2a  8b8486580a4e00         -mov eax, dword ptr [esi + eax*4 + 0x4e0a58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5114456) /* 0x4e0a58 */ + cpu.eax * 4);
    // 004a9e31  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
L_0x004a9e33:
    // 004a9e33  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004a9e36  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a9e38  a3340a4e00             -mov dword ptr [0x4e0a34], eax
    app->getMemory<x86::reg32>(x86::reg32(5114420) /* 0x4e0a34 */) = cpu.eax;
    // 004a9e3d  03865c0a4e00           -add eax, dword ptr [esi + 0x4e0a5c]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5114460) /* 0x4e0a5c */)));
    // 004a9e43  a3300a4e00             -mov dword ptr [0x4e0a30], eax
    app->getMemory<x86::reg32>(x86::reg32(5114416) /* 0x4e0a30 */) = cpu.eax;
    // 004a9e48  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a9e4a  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004a9e4c  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004a9e4f  8b35500a4e00           -mov esi, dword ptr [0x4e0a50]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5114448) /* 0x4e0a50 */);
    // 004a9e55  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004a9e58  033485580a4e00         -add esi, dword ptr [eax*4 + 0x4e0a58]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5114456) /* 0x4e0a58 */ + cpu.eax * 4)));
    // 004a9e5f  01ce                   -add esi, ecx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004a9e61  c1e510                 -shl ebp, 0x10
    cpu.ebp <<= 16 /*0x10*/ % 32;
    // 004a9e64  8b3d400a4e00           -mov edi, dword ptr [0x4e0a40]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5114432) /* 0x4e0a40 */);
    // 004a9e6a  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004a9e6d  8b0d480a4e00           -mov ecx, dword ptr [0x4e0a48]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5114440) /* 0x4e0a48 */);
    // 004a9e73  c1e710                 -shl edi, 0x10
    cpu.edi <<= 16 /*0x10*/ % 32;
    // 004a9e76  c1e110                 +shl ecx, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.ecx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
L_0x004a9e79:
    // 004a9e79  ff0d240a4e00           +dec dword ptr [0x4e0a24]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5114404) /* 0x4e0a24 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a9e7f  782c                   -js 0x4a9ead
    if (cpu.flags.sf)
    {
        goto L_0x004a9ead;
    }
    // 004a9e81  43                     -inc ebx
    (cpu.ebx)++;
    // 004a9e82  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a9e84  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004a9e86  891d200a4e00           -mov dword ptr [0x4e0a20], ebx
    app->getMemory<x86::reg32>(x86::reg32(5114400) /* 0x4e0a20 */) = cpu.ebx;
    // 004a9e8c  3cfe                   +cmp al, 0xfe
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(254 /*0xfe*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a9e8e  7509                   -jne 0x4a9e99
    if (!cpu.flags.zf)
    {
        goto L_0x004a9e99;
    }
    // 004a9e90  8a43ff                 -mov al, byte ptr [ebx - 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */);
    // 004a9e93  8a80d8e34d00           -mov al, byte ptr [eax + 0x4de3d8]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5104600) /* 0x4de3d8 */);
L_0x004a9e99:
    // 004a9e99  7703                   -ja 0x4a9e9e
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004a9e9e;
    }
    // 004a9e9b  8843ff                 -mov byte ptr [ebx - 1], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.al;
L_0x004a9e9e:
    // 004a9e9e  01ca                   +add edx, ecx
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
    // 004a9ea0  19c0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 004a9ea2  01fd                   +add ebp, edi
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
    // 004a9ea4  133485340a4e00         +adc esi, dword ptr [eax*4 + 0x4e0a34]
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5114420) /* 0x4e0a34 */ + cpu.eax * 4))) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a9eab  ebcc                   -jmp 0x4a9e79
    goto L_0x004a9e79;
L_0x004a9ead:
    // 004a9ead  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a9eaf  01ca                   +add edx, ecx
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
    // 004a9eb1  19db                   -sbb ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx) + cpu.flags.cf);
    // 004a9eb3  01fd                   +add ebp, edi
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
    // 004a9eb5  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004a9eb7  13349d340a4e00         -adc esi, dword ptr [ebx*4 + 0x4e0a34]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5114420) /* 0x4e0a34 */ + cpu.ebx * 4)) + cpu.flags.cf);
    // 004a9ebe  a2380a4e00             -mov byte ptr [0x4e0a38], al
    app->getMemory<x86::reg8>(x86::reg32(5114424) /* 0x4e0a38 */) = cpu.al;
    // 004a9ec3  01ca                   +add edx, ecx
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
    // 004a9ec5  19db                   -sbb ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx) + cpu.flags.cf);
    // 004a9ec7  01fd                   +add ebp, edi
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
    // 004a9ec9  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004a9ecb  13349d340a4e00         -adc esi, dword ptr [ebx*4 + 0x4e0a34]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5114420) /* 0x4e0a34 */ + cpu.ebx * 4)) + cpu.flags.cf);
    // 004a9ed2  a2390a4e00             -mov byte ptr [0x4e0a39], al
    app->getMemory<x86::reg8>(x86::reg32(5114425) /* 0x4e0a39 */) = cpu.al;
    // 004a9ed7  01ca                   +add edx, ecx
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
    // 004a9ed9  19db                   -sbb ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx) + cpu.flags.cf);
    // 004a9edb  01fd                   +add ebp, edi
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
    // 004a9edd  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004a9edf  13349d340a4e00         -adc esi, dword ptr [ebx*4 + 0x4e0a34]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5114420) /* 0x4e0a34 */ + cpu.ebx * 4)) + cpu.flags.cf);
    // 004a9ee6  a23a0a4e00             -mov byte ptr [0x4e0a3a], al
    app->getMemory<x86::reg8>(x86::reg32(5114426) /* 0x4e0a3a */) = cpu.al;
    // 004a9eeb  01ca                   +add edx, ecx
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
    // 004a9eed  19db                   -sbb ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx) + cpu.flags.cf);
    // 004a9eef  01fd                   +add ebp, edi
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
    // 004a9ef1  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004a9ef3  13349d340a4e00         -adc esi, dword ptr [ebx*4 + 0x4e0a34]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5114420) /* 0x4e0a34 */ + cpu.ebx * 4)) + cpu.flags.cf);
    // 004a9efa  a23b0a4e00             -mov byte ptr [0x4e0a3b], al
    app->getMemory<x86::reg8>(x86::reg32(5114427) /* 0x4e0a3b */) = cpu.al;
    // 004a9eff  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a9f00  a1380a4e00             -mov eax, dword ptr [0x4e0a38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5114424) /* 0x4e0a38 */);
    // 004a9f05  8b1d200a4e00           -mov ebx, dword ptr [0x4e0a20]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5114400) /* 0x4e0a20 */);
    // 004a9f0b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a9f0d  3cfe                   +cmp al, 0xfe
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(254 /*0xfe*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a9f0f  7508                   -jne 0x4a9f19
    if (!cpu.flags.zf)
    {
        goto L_0x004a9f19;
    }
    // 004a9f11  8a13                   -mov dl, byte ptr [ebx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx);
    // 004a9f13  8a82d8e34d00           -mov al, byte ptr [edx + 0x4de3d8]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5104600) /* 0x4de3d8 */);
L_0x004a9f19:
    // 004a9f19  7760                   -ja 0x4a9f7b
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004a9f7b;
    }
    // 004a9f1b  80fcfe                 +cmp ah, 0xfe
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
    // 004a9f1e  7509                   -jne 0x4a9f29
    if (!cpu.flags.zf)
    {
        goto L_0x004a9f29;
    }
    // 004a9f20  8a5301                 -mov dl, byte ptr [ebx + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004a9f23  8aa2d8e34d00           -mov ah, byte ptr [edx + 0x4de3d8]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5104600) /* 0x4de3d8 */);
L_0x004a9f29:
    // 004a9f29  774b                   -ja 0x4a9f76
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004a9f76;
    }
    // 004a9f2b  c1c810                 -ror eax, 0x10
    {
        x86::reg32& op = cpu.eax;
        x86::reg32 shift = 16 /*0x10*/ % 32;
        while (shift)
        {
            x86::reg32 cf = op & 1;
            op = op >> 1 | cf << 31;
            shift--;
        }
    }
    // 004a9f2e  3cfe                   +cmp al, 0xfe
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(254 /*0xfe*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a9f30  7509                   -jne 0x4a9f3b
    if (!cpu.flags.zf)
    {
        goto L_0x004a9f3b;
    }
    // 004a9f32  8a5302                 -mov dl, byte ptr [ebx + 2]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 004a9f35  8a82d8e34d00           -mov al, byte ptr [edx + 0x4de3d8]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5104600) /* 0x4de3d8 */);
L_0x004a9f3b:
    // 004a9f3b  771d                   -ja 0x4a9f5a
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004a9f5a;
    }
    // 004a9f3d  80fcfe                 +cmp ah, 0xfe
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
    // 004a9f40  7509                   -jne 0x4a9f4b
    if (!cpu.flags.zf)
    {
        goto L_0x004a9f4b;
    }
    // 004a9f42  8a5303                 -mov dl, byte ptr [ebx + 3]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(3) /* 0x3 */);
    // 004a9f45  8aa2d8e34d00           -mov ah, byte ptr [edx + 0x4de3d8]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5104600) /* 0x4de3d8 */);
L_0x004a9f4b:
    // 004a9f4b  7707                   -ja 0x4a9f54
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004a9f54;
    }
    // 004a9f4d  c1c810                 +ror eax, 0x10
    {
        x86::reg32& op = cpu.eax;
        x86::reg32 count = 16 /*0x10*/ % 32;
        if (count) {
            op = (op >> count) | (op << (32 - count));
            cpu.flags.cf = (op >> (32 - 1)) & 1;
            if (count == 1) {
                cpu.flags.of = ((op >> (32 - 1)) ^ (op >> (32 - 2))) & 1;
            }
        }
    }
    // 004a9f50  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004a9f52  eb7b                   -jmp 0x4a9fcf
    goto L_0x004a9fcf;
L_0x004a9f54:
    // 004a9f54  90                     -nop 
    ;
    // 004a9f55  884302                 -mov byte ptr [ebx + 2], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 004a9f58  eb14                   -jmp 0x4a9f6e
    goto L_0x004a9f6e;
L_0x004a9f5a:
    // 004a9f5a  80fcfe                 +cmp ah, 0xfe
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
    // 004a9f5d  7509                   -jne 0x4a9f68
    if (!cpu.flags.zf)
    {
        goto L_0x004a9f68;
    }
    // 004a9f5f  8a5303                 -mov dl, byte ptr [ebx + 3]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(3) /* 0x3 */);
    // 004a9f62  8aa2d8e34d00           -mov ah, byte ptr [edx + 0x4de3d8]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5104600) /* 0x4de3d8 */);
L_0x004a9f68:
    // 004a9f68  7704                   -ja 0x4a9f6e
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004a9f6e;
    }
    // 004a9f6a  90                     -nop 
    ;
    // 004a9f6b  886303                 -mov byte ptr [ebx + 3], ah
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(3) /* 0x3 */) = cpu.ah;
L_0x004a9f6e:
    // 004a9f6e  c1c810                 +ror eax, 0x10
    {
        x86::reg32& op = cpu.eax;
        x86::reg32 count = 16 /*0x10*/ % 32;
        if (count) {
            op = (op >> count) | (op << (32 - count));
            cpu.flags.cf = (op >> (32 - 1)) & 1;
            if (count == 1) {
                cpu.flags.of = ((op >> (32 - 1)) ^ (op >> (32 - 2))) & 1;
            }
        }
    }
    // 004a9f71  668903                 -mov word ptr [ebx], ax
    app->getMemory<x86::reg16>(cpu.ebx) = cpu.ax;
    // 004a9f74  eb59                   -jmp 0x4a9fcf
    goto L_0x004a9fcf;
L_0x004a9f76:
    // 004a9f76  90                     -nop 
    ;
    // 004a9f77  8803                   -mov byte ptr [ebx], al
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.al;
    // 004a9f79  eb14                   -jmp 0x4a9f8f
    goto L_0x004a9f8f;
L_0x004a9f7b:
    // 004a9f7b  80fcfe                 +cmp ah, 0xfe
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
    // 004a9f7e  7509                   -jne 0x4a9f89
    if (!cpu.flags.zf)
    {
        goto L_0x004a9f89;
    }
    // 004a9f80  8a5301                 -mov dl, byte ptr [ebx + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004a9f83  8aa2d8e34d00           -mov ah, byte ptr [edx + 0x4de3d8]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5104600) /* 0x4de3d8 */);
L_0x004a9f89:
    // 004a9f89  7704                   -ja 0x4a9f8f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004a9f8f;
    }
    // 004a9f8b  90                     -nop 
    ;
    // 004a9f8c  886301                 -mov byte ptr [ebx + 1], ah
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */) = cpu.ah;
L_0x004a9f8f:
    // 004a9f8f  c1c810                 -ror eax, 0x10
    {
        x86::reg32& op = cpu.eax;
        x86::reg32 shift = 16 /*0x10*/ % 32;
        while (shift)
        {
            x86::reg32 cf = op & 1;
            op = op >> 1 | cf << 31;
            shift--;
        }
    }
    // 004a9f92  3cfe                   +cmp al, 0xfe
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(254 /*0xfe*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a9f94  7509                   -jne 0x4a9f9f
    if (!cpu.flags.zf)
    {
        goto L_0x004a9f9f;
    }
    // 004a9f96  8a5302                 -mov dl, byte ptr [ebx + 2]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 004a9f99  8a82d8e34d00           -mov al, byte ptr [edx + 0x4de3d8]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5104600) /* 0x4de3d8 */);
L_0x004a9f9f:
    // 004a9f9f  771b                   -ja 0x4a9fbc
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004a9fbc;
    }
    // 004a9fa1  80fcfe                 +cmp ah, 0xfe
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
    // 004a9fa4  7509                   -jne 0x4a9faf
    if (!cpu.flags.zf)
    {
        goto L_0x004a9faf;
    }
    // 004a9fa6  8a5303                 -mov dl, byte ptr [ebx + 3]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(3) /* 0x3 */);
    // 004a9fa9  8aa2d8e34d00           -mov ah, byte ptr [edx + 0x4de3d8]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5104600) /* 0x4de3d8 */);
L_0x004a9faf:
    // 004a9faf  7706                   -ja 0x4a9fb7
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004a9fb7;
    }
    // 004a9fb1  66894302               -mov word ptr [ebx + 2], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(2) /* 0x2 */) = cpu.ax;
    // 004a9fb5  eb18                   -jmp 0x4a9fcf
    goto L_0x004a9fcf;
L_0x004a9fb7:
    // 004a9fb7  884302                 -mov byte ptr [ebx + 2], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 004a9fba  eb13                   -jmp 0x4a9fcf
    goto L_0x004a9fcf;
L_0x004a9fbc:
    // 004a9fbc  80fcfe                 +cmp ah, 0xfe
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
    // 004a9fbf  7509                   -jne 0x4a9fca
    if (!cpu.flags.zf)
    {
        goto L_0x004a9fca;
    }
    // 004a9fc1  8a5303                 -mov dl, byte ptr [ebx + 3]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(3) /* 0x3 */);
    // 004a9fc4  8aa2d8e34d00           -mov ah, byte ptr [edx + 0x4de3d8]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5104600) /* 0x4de3d8 */);
L_0x004a9fca:
    // 004a9fca  7703                   -ja 0x4a9fcf
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004a9fcf;
    }
    // 004a9fcc  886303                 -mov byte ptr [ebx + 3], ah
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(3) /* 0x3 */) = cpu.ah;
L_0x004a9fcf:
    // 004a9fcf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a9fd0  a1280a4e00             -mov eax, dword ptr [0x4e0a28]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5114408) /* 0x4e0a28 */);
    // 004a9fd5  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a9fd8  83e804                 +sub eax, 4
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a9fdb  891d200a4e00           -mov dword ptr [0x4e0a20], ebx
    app->getMemory<x86::reg32>(x86::reg32(5114400) /* 0x4e0a20 */) = cpu.ebx;
    // 004a9fe1  a3280a4e00             -mov dword ptr [0x4e0a28], eax
    app->getMemory<x86::reg32>(x86::reg32(5114408) /* 0x4e0a28 */) = cpu.eax;
    // 004a9fe6  0f85c1feffff           -jne 0x4a9ead
    if (!cpu.flags.zf)
    {
        goto L_0x004a9ead;
    }
L_0x004a9fec:
    // 004a9fec  ff0d2c0a4e00           +dec dword ptr [0x4e0a2c]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5114412) /* 0x4e0a2c */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a9ff2  782c                   -js 0x4aa020
    if (cpu.flags.sf)
    {
        goto L_0x004aa020;
    }
    // 004a9ff4  43                     -inc ebx
    (cpu.ebx)++;
    // 004a9ff5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a9ff7  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004a9ff9  891d200a4e00           -mov dword ptr [0x4e0a20], ebx
    app->getMemory<x86::reg32>(x86::reg32(5114400) /* 0x4e0a20 */) = cpu.ebx;
    // 004a9fff  3cfe                   +cmp al, 0xfe
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(254 /*0xfe*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004aa001  7509                   -jne 0x4aa00c
    if (!cpu.flags.zf)
    {
        goto L_0x004aa00c;
    }
    // 004aa003  8a43ff                 -mov al, byte ptr [ebx - 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */);
    // 004aa006  8a80d8e34d00           -mov al, byte ptr [eax + 0x4de3d8]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5104600) /* 0x4de3d8 */);
L_0x004aa00c:
    // 004aa00c  7703                   -ja 0x4aa011
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004aa011;
    }
    // 004aa00e  8843ff                 -mov byte ptr [ebx - 1], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.al;
L_0x004aa011:
    // 004aa011  01ca                   +add edx, ecx
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
    // 004aa013  19c0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 004aa015  01fd                   +add ebp, edi
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
    // 004aa017  133485340a4e00         +adc esi, dword ptr [eax*4 + 0x4e0a34]
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5114420) /* 0x4e0a34 */ + cpu.eax * 4))) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004aa01e  ebcc                   -jmp 0x4a9fec
    goto L_0x004a9fec;
L_0x004aa020:
    // 004aa020  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa021  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa022  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa023  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4aa024(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa024  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004aa025  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004aa026  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004aa027  8b35540a4e00           -mov esi, dword ptr [0x4e0a54]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5114452) /* 0x4e0a54 */);
    // 004aa02d  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004aa02f  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004aa031  83f90c                 +cmp ecx, 0xc
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aa034  733c                   -jae 0x4aa072
    if (!cpu.flags.cf)
    {
        goto L_0x004aa072;
    }
L_0x004aa036:
    // 004aa036  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004aa038  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004aa03a  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004aa03d  8b35500a4e00           -mov esi, dword ptr [0x4e0a50]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5114448) /* 0x4e0a50 */);
    // 004aa043  c1ef10                 -shr edi, 0x10
    cpu.edi >>= 16 /*0x10*/ % 32;
    // 004aa046  43                     -inc ebx
    (cpu.ebx)++;
    // 004aa047  033c85580a4e00         -add edi, dword ptr [eax*4 + 0x4e0a58]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5114456) /* 0x4e0a58 */ + cpu.eax * 4)));
    // 004aa04e  a1480a4e00             -mov eax, dword ptr [0x4e0a48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5114440) /* 0x4e0a48 */);
    // 004aa053  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004aa055  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004aa057  8a043e                 -mov al, byte ptr [esi + edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.edi * 1);
    // 004aa05a  8b3d400a4e00           -mov edi, dword ptr [0x4e0a40]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5114432) /* 0x4e0a40 */);
    // 004aa060  01fd                   +add ebp, edi
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
    // 004aa062  8a80acb34d00           -mov al, byte ptr [eax + 0x4db3ac]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5092268) /* 0x4db3ac */);
    // 004aa068  8843ff                 -mov byte ptr [ebx - 1], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 004aa06b  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004aa06c  75c8                   -jne 0x4aa036
    if (!cpu.flags.zf)
    {
        goto L_0x004aa036;
    }
    // 004aa06e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa06f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa070  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa071  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004aa072:
    // 004aa072  891d200a4e00           -mov dword ptr [0x4e0a20], ebx
    app->getMemory<x86::reg32>(x86::reg32(5114400) /* 0x4e0a20 */) = cpu.ebx;
    // 004aa078  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004aa07a  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa07c  8b35540a4e00           -mov esi, dword ptr [0x4e0a54]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5114452) /* 0x4e0a54 */);
    // 004aa082  c1ee0e                 -shr esi, 0xe
    cpu.esi >>= 14 /*0xe*/ % 32;
    // 004aa085  83e003                 -and eax, 3
    cpu.eax &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004aa088  a3240a4e00             -mov dword ptr [0x4e0a24], eax
    app->getMemory<x86::reg32>(x86::reg32(5114404) /* 0x4e0a24 */) = cpu.eax;
    // 004aa08d  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004aa08f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004aa091  83e0fc                 -and eax, 0xfffffffc
    cpu.eax &= x86::reg32(x86::sreg32(4294967292 /*0xfffffffc*/));
    // 004aa094  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004aa097  a3280a4e00             -mov dword ptr [0x4e0a28], eax
    app->getMemory<x86::reg32>(x86::reg32(5114408) /* 0x4e0a28 */) = cpu.eax;
    // 004aa09c  890d2c0a4e00           -mov dword ptr [0x4e0a2c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5114412) /* 0x4e0a2c */) = cpu.ecx;
    // 004aa0a2  a1480a4e00             -mov eax, dword ptr [0x4e0a48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5114440) /* 0x4e0a48 */);
    // 004aa0a7  8b0d400a4e00           -mov ecx, dword ptr [0x4e0a40]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5114432) /* 0x4e0a40 */);
    // 004aa0ad  c1f810                 +sar eax, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 004aa0b0  7809                   -js 0x4aa0bb
    if (cpu.flags.sf)
    {
        goto L_0x004aa0bb;
    }
    // 004aa0b2  8b8486580a4e00         -mov eax, dword ptr [esi + eax*4 + 0x4e0a58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5114456) /* 0x4e0a58 */ + cpu.eax * 4);
    // 004aa0b9  eb0b                   -jmp 0x4aa0c6
    goto L_0x004aa0c6;
L_0x004aa0bb:
    // 004aa0bb  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 004aa0bd  8b8486580a4e00         -mov eax, dword ptr [esi + eax*4 + 0x4e0a58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5114456) /* 0x4e0a58 */ + cpu.eax * 4);
    // 004aa0c4  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
L_0x004aa0c6:
    // 004aa0c6  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004aa0c9  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004aa0cb  a3340a4e00             -mov dword ptr [0x4e0a34], eax
    app->getMemory<x86::reg32>(x86::reg32(5114420) /* 0x4e0a34 */) = cpu.eax;
    // 004aa0d0  03865c0a4e00           -add eax, dword ptr [esi + 0x4e0a5c]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5114460) /* 0x4e0a5c */)));
    // 004aa0d6  a3300a4e00             -mov dword ptr [0x4e0a30], eax
    app->getMemory<x86::reg32>(x86::reg32(5114416) /* 0x4e0a30 */) = cpu.eax;
    // 004aa0db  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004aa0dd  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004aa0df  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004aa0e2  8b35500a4e00           -mov esi, dword ptr [0x4e0a50]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5114448) /* 0x4e0a50 */);
    // 004aa0e8  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004aa0eb  033485580a4e00         -add esi, dword ptr [eax*4 + 0x4e0a58]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5114456) /* 0x4e0a58 */ + cpu.eax * 4)));
    // 004aa0f2  01ce                   -add esi, ecx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004aa0f4  c1e510                 -shl ebp, 0x10
    cpu.ebp <<= 16 /*0x10*/ % 32;
    // 004aa0f7  8b3d400a4e00           -mov edi, dword ptr [0x4e0a40]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5114432) /* 0x4e0a40 */);
    // 004aa0fd  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004aa100  8b0d480a4e00           -mov ecx, dword ptr [0x4e0a48]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5114440) /* 0x4e0a48 */);
    // 004aa106  c1e710                 -shl edi, 0x10
    cpu.edi <<= 16 /*0x10*/ % 32;
    // 004aa109  c1e110                 +shl ecx, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.ecx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
L_0x004aa10c:
    // 004aa10c  ff0d240a4e00           +dec dword ptr [0x4e0a24]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5114404) /* 0x4e0a24 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004aa112  7823                   -js 0x4aa137
    if (cpu.flags.sf)
    {
        goto L_0x004aa137;
    }
    // 004aa114  43                     -inc ebx
    (cpu.ebx)++;
    // 004aa115  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004aa117  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004aa119  891d200a4e00           -mov dword ptr [0x4e0a20], ebx
    app->getMemory<x86::reg32>(x86::reg32(5114400) /* 0x4e0a20 */) = cpu.ebx;
    // 004aa11f  8a80acb34d00           -mov al, byte ptr [eax + 0x4db3ac]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5092268) /* 0x4db3ac */);
    // 004aa125  8843ff                 -mov byte ptr [ebx - 1], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 004aa128  01ca                   +add edx, ecx
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
    // 004aa12a  19c0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 004aa12c  01fd                   +add ebp, edi
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
    // 004aa12e  133485340a4e00         +adc esi, dword ptr [eax*4 + 0x4e0a34]
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5114420) /* 0x4e0a34 */ + cpu.eax * 4))) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004aa135  ebd5                   -jmp 0x4aa10c
    goto L_0x004aa10c;
L_0x004aa137:
    // 004aa137  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004aa139  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004aa13b  01ca                   +add edx, ecx
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
    // 004aa13d  19db                   -sbb ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx) + cpu.flags.cf);
    // 004aa13f  01fd                   +add ebp, edi
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
    // 004aa141  8a80acb34d00           -mov al, byte ptr [eax + 0x4db3ac]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5092268) /* 0x4db3ac */);
    // 004aa147  13349d340a4e00         -adc esi, dword ptr [ebx*4 + 0x4e0a34]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5114420) /* 0x4e0a34 */ + cpu.ebx * 4)) + cpu.flags.cf);
    // 004aa14e  a2380a4e00             -mov byte ptr [0x4e0a38], al
    app->getMemory<x86::reg8>(x86::reg32(5114424) /* 0x4e0a38 */) = cpu.al;
    // 004aa153  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004aa155  01ca                   +add edx, ecx
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
    // 004aa157  19db                   -sbb ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx) + cpu.flags.cf);
    // 004aa159  01fd                   +add ebp, edi
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
    // 004aa15b  8a80acb34d00           -mov al, byte ptr [eax + 0x4db3ac]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5092268) /* 0x4db3ac */);
    // 004aa161  13349d340a4e00         -adc esi, dword ptr [ebx*4 + 0x4e0a34]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5114420) /* 0x4e0a34 */ + cpu.ebx * 4)) + cpu.flags.cf);
    // 004aa168  a2390a4e00             -mov byte ptr [0x4e0a39], al
    app->getMemory<x86::reg8>(x86::reg32(5114425) /* 0x4e0a39 */) = cpu.al;
    // 004aa16d  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004aa16f  01ca                   +add edx, ecx
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
    // 004aa171  19db                   -sbb ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx) + cpu.flags.cf);
    // 004aa173  01fd                   +add ebp, edi
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
    // 004aa175  8a80acb34d00           -mov al, byte ptr [eax + 0x4db3ac]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5092268) /* 0x4db3ac */);
    // 004aa17b  13349d340a4e00         -adc esi, dword ptr [ebx*4 + 0x4e0a34]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5114420) /* 0x4e0a34 */ + cpu.ebx * 4)) + cpu.flags.cf);
    // 004aa182  a23a0a4e00             -mov byte ptr [0x4e0a3a], al
    app->getMemory<x86::reg8>(x86::reg32(5114426) /* 0x4e0a3a */) = cpu.al;
    // 004aa187  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004aa189  01ca                   +add edx, ecx
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
    // 004aa18b  19db                   -sbb ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx) + cpu.flags.cf);
    // 004aa18d  01fd                   +add ebp, edi
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
    // 004aa18f  8a80acb34d00           -mov al, byte ptr [eax + 0x4db3ac]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5092268) /* 0x4db3ac */);
    // 004aa195  13349d340a4e00         -adc esi, dword ptr [ebx*4 + 0x4e0a34]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5114420) /* 0x4e0a34 */ + cpu.ebx * 4)) + cpu.flags.cf);
    // 004aa19c  a23b0a4e00             -mov byte ptr [0x4e0a3b], al
    app->getMemory<x86::reg8>(x86::reg32(5114427) /* 0x4e0a3b */) = cpu.al;
    // 004aa1a1  8b1d200a4e00           -mov ebx, dword ptr [0x4e0a20]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5114400) /* 0x4e0a20 */);
    // 004aa1a7  a1280a4e00             -mov eax, dword ptr [0x4e0a28]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5114408) /* 0x4e0a28 */);
    // 004aa1ac  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004aa1af  83e804                 +sub eax, 4
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004aa1b2  891d200a4e00           -mov dword ptr [0x4e0a20], ebx
    app->getMemory<x86::reg32>(x86::reg32(5114400) /* 0x4e0a20 */) = cpu.ebx;
    // 004aa1b8  a3280a4e00             -mov dword ptr [0x4e0a28], eax
    app->getMemory<x86::reg32>(x86::reg32(5114408) /* 0x4e0a28 */) = cpu.eax;
    // 004aa1bd  a1380a4e00             -mov eax, dword ptr [0x4e0a38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5114424) /* 0x4e0a38 */);
    // 004aa1c2  8943fc                 -mov dword ptr [ebx - 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004aa1c5  0f856cffffff           -jne 0x4aa137
    if (!cpu.flags.zf)
    {
        goto L_0x004aa137;
    }
L_0x004aa1cb:
    // 004aa1cb  ff0d2c0a4e00           +dec dword ptr [0x4e0a2c]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5114412) /* 0x4e0a2c */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004aa1d1  7823                   -js 0x4aa1f6
    if (cpu.flags.sf)
    {
        goto L_0x004aa1f6;
    }
    // 004aa1d3  43                     -inc ebx
    (cpu.ebx)++;
    // 004aa1d4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004aa1d6  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004aa1d8  891d200a4e00           -mov dword ptr [0x4e0a20], ebx
    app->getMemory<x86::reg32>(x86::reg32(5114400) /* 0x4e0a20 */) = cpu.ebx;
    // 004aa1de  8a80acb34d00           -mov al, byte ptr [eax + 0x4db3ac]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5092268) /* 0x4db3ac */);
    // 004aa1e4  8843ff                 -mov byte ptr [ebx - 1], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 004aa1e7  01ca                   +add edx, ecx
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
    // 004aa1e9  19c0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 004aa1eb  01fd                   +add ebp, edi
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
    // 004aa1ed  133485340a4e00         +adc esi, dword ptr [eax*4 + 0x4e0a34]
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5114420) /* 0x4e0a34 */ + cpu.eax * 4))) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004aa1f4  ebd5                   -jmp 0x4aa1cb
    goto L_0x004aa1cb;
L_0x004aa1f6:
    // 004aa1f6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa1f7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa1f8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa1f9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4aa1fc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa1fc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004aa1fd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004aa1fe  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004aa1ff  8b35540a4e00           -mov esi, dword ptr [0x4e0a54]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5114452) /* 0x4e0a54 */);
    // 004aa205  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004aa207  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004aa209  83f90c                 +cmp ecx, 0xc
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aa20c  7340                   -jae 0x4aa24e
    if (!cpu.flags.cf)
    {
        goto L_0x004aa24e;
    }
L_0x004aa20e:
    // 004aa20e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004aa210  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004aa212  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004aa215  8b35500a4e00           -mov esi, dword ptr [0x4e0a50]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5114448) /* 0x4e0a50 */);
    // 004aa21b  c1ef10                 -shr edi, 0x10
    cpu.edi >>= 16 /*0x10*/ % 32;
    // 004aa21e  43                     -inc ebx
    (cpu.ebx)++;
    // 004aa21f  033c85580a4e00         -add edi, dword ptr [eax*4 + 0x4e0a58]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5114456) /* 0x4e0a58 */ + cpu.eax * 4)));
    // 004aa226  a1480a4e00             -mov eax, dword ptr [0x4e0a48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5114440) /* 0x4e0a48 */);
    // 004aa22b  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004aa22d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004aa22f  8a043e                 -mov al, byte ptr [esi + edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.edi * 1);
    // 004aa232  8b3d400a4e00           -mov edi, dword ptr [0x4e0a40]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5114432) /* 0x4e0a40 */);
    // 004aa238  01fd                   -add ebp, edi
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edi));
    // 004aa23a  8a80acb34d00           -mov al, byte ptr [eax + 0x4db3ac]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5092268) /* 0x4db3ac */);
    // 004aa240  3cff                   +cmp al, 0xff
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004aa242  7403                   -je 0x4aa247
    if (cpu.flags.zf)
    {
        goto L_0x004aa247;
    }
    // 004aa244  8843ff                 -mov byte ptr [ebx - 1], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.al;
L_0x004aa247:
    // 004aa247  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004aa248  75c4                   -jne 0x4aa20e
    if (!cpu.flags.zf)
    {
        goto L_0x004aa20e;
    }
    // 004aa24a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa24b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa24c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa24d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004aa24e:
    // 004aa24e  891d200a4e00           -mov dword ptr [0x4e0a20], ebx
    app->getMemory<x86::reg32>(x86::reg32(5114400) /* 0x4e0a20 */) = cpu.ebx;
    // 004aa254  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004aa256  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa258  8b35540a4e00           -mov esi, dword ptr [0x4e0a54]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5114452) /* 0x4e0a54 */);
    // 004aa25e  c1ee0e                 -shr esi, 0xe
    cpu.esi >>= 14 /*0xe*/ % 32;
    // 004aa261  83e003                 -and eax, 3
    cpu.eax &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004aa264  a3240a4e00             -mov dword ptr [0x4e0a24], eax
    app->getMemory<x86::reg32>(x86::reg32(5114404) /* 0x4e0a24 */) = cpu.eax;
    // 004aa269  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004aa26b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004aa26d  83e0fc                 -and eax, 0xfffffffc
    cpu.eax &= x86::reg32(x86::sreg32(4294967292 /*0xfffffffc*/));
    // 004aa270  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004aa273  a3280a4e00             -mov dword ptr [0x4e0a28], eax
    app->getMemory<x86::reg32>(x86::reg32(5114408) /* 0x4e0a28 */) = cpu.eax;
    // 004aa278  890d2c0a4e00           -mov dword ptr [0x4e0a2c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5114412) /* 0x4e0a2c */) = cpu.ecx;
    // 004aa27e  a1480a4e00             -mov eax, dword ptr [0x4e0a48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5114440) /* 0x4e0a48 */);
    // 004aa283  8b0d400a4e00           -mov ecx, dword ptr [0x4e0a40]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5114432) /* 0x4e0a40 */);
    // 004aa289  c1f810                 +sar eax, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 004aa28c  7809                   -js 0x4aa297
    if (cpu.flags.sf)
    {
        goto L_0x004aa297;
    }
    // 004aa28e  8b8486580a4e00         -mov eax, dword ptr [esi + eax*4 + 0x4e0a58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5114456) /* 0x4e0a58 */ + cpu.eax * 4);
    // 004aa295  eb0b                   -jmp 0x4aa2a2
    goto L_0x004aa2a2;
L_0x004aa297:
    // 004aa297  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 004aa299  8b8486580a4e00         -mov eax, dword ptr [esi + eax*4 + 0x4e0a58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5114456) /* 0x4e0a58 */ + cpu.eax * 4);
    // 004aa2a0  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
L_0x004aa2a2:
    // 004aa2a2  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004aa2a5  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004aa2a7  a3340a4e00             -mov dword ptr [0x4e0a34], eax
    app->getMemory<x86::reg32>(x86::reg32(5114420) /* 0x4e0a34 */) = cpu.eax;
    // 004aa2ac  03865c0a4e00           -add eax, dword ptr [esi + 0x4e0a5c]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5114460) /* 0x4e0a5c */)));
    // 004aa2b2  a3300a4e00             -mov dword ptr [0x4e0a30], eax
    app->getMemory<x86::reg32>(x86::reg32(5114416) /* 0x4e0a30 */) = cpu.eax;
    // 004aa2b7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004aa2b9  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004aa2bb  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004aa2be  8b35500a4e00           -mov esi, dword ptr [0x4e0a50]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5114448) /* 0x4e0a50 */);
    // 004aa2c4  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004aa2c7  033485580a4e00         -add esi, dword ptr [eax*4 + 0x4e0a58]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5114456) /* 0x4e0a58 */ + cpu.eax * 4)));
    // 004aa2ce  01ce                   -add esi, ecx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004aa2d0  c1e510                 -shl ebp, 0x10
    cpu.ebp <<= 16 /*0x10*/ % 32;
    // 004aa2d3  8b3d400a4e00           -mov edi, dword ptr [0x4e0a40]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5114432) /* 0x4e0a40 */);
    // 004aa2d9  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004aa2dc  8b0d480a4e00           -mov ecx, dword ptr [0x4e0a48]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5114440) /* 0x4e0a48 */);
    // 004aa2e2  c1e710                 -shl edi, 0x10
    cpu.edi <<= 16 /*0x10*/ % 32;
    // 004aa2e5  c1e110                 +shl ecx, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.ecx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
L_0x004aa2e8:
    // 004aa2e8  ff0d240a4e00           +dec dword ptr [0x4e0a24]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5114404) /* 0x4e0a24 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004aa2ee  7827                   -js 0x4aa317
    if (cpu.flags.sf)
    {
        goto L_0x004aa317;
    }
    // 004aa2f0  43                     -inc ebx
    (cpu.ebx)++;
    // 004aa2f1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004aa2f3  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004aa2f5  891d200a4e00           -mov dword ptr [0x4e0a20], ebx
    app->getMemory<x86::reg32>(x86::reg32(5114400) /* 0x4e0a20 */) = cpu.ebx;
    // 004aa2fb  8a80acb34d00           -mov al, byte ptr [eax + 0x4db3ac]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5092268) /* 0x4db3ac */);
    // 004aa301  3cff                   +cmp al, 0xff
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004aa303  7403                   -je 0x4aa308
    if (cpu.flags.zf)
    {
        goto L_0x004aa308;
    }
    // 004aa305  8843ff                 -mov byte ptr [ebx - 1], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.al;
L_0x004aa308:
    // 004aa308  01ca                   +add edx, ecx
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
    // 004aa30a  19c0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 004aa30c  01fd                   +add ebp, edi
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
    // 004aa30e  133485340a4e00         +adc esi, dword ptr [eax*4 + 0x4e0a34]
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5114420) /* 0x4e0a34 */ + cpu.eax * 4))) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004aa315  ebd1                   -jmp 0x4aa2e8
    goto L_0x004aa2e8;
L_0x004aa317:
    // 004aa317  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004aa319  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004aa31b  01ca                   +add edx, ecx
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
    // 004aa31d  19db                   -sbb ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx) + cpu.flags.cf);
    // 004aa31f  01fd                   +add ebp, edi
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
    // 004aa321  8a80acb34d00           -mov al, byte ptr [eax + 0x4db3ac]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5092268) /* 0x4db3ac */);
    // 004aa327  13349d340a4e00         -adc esi, dword ptr [ebx*4 + 0x4e0a34]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5114420) /* 0x4e0a34 */ + cpu.ebx * 4)) + cpu.flags.cf);
    // 004aa32e  a2380a4e00             -mov byte ptr [0x4e0a38], al
    app->getMemory<x86::reg8>(x86::reg32(5114424) /* 0x4e0a38 */) = cpu.al;
    // 004aa333  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004aa335  01ca                   +add edx, ecx
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
    // 004aa337  19db                   -sbb ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx) + cpu.flags.cf);
    // 004aa339  01fd                   +add ebp, edi
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
    // 004aa33b  8a80acb34d00           -mov al, byte ptr [eax + 0x4db3ac]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5092268) /* 0x4db3ac */);
    // 004aa341  13349d340a4e00         -adc esi, dword ptr [ebx*4 + 0x4e0a34]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5114420) /* 0x4e0a34 */ + cpu.ebx * 4)) + cpu.flags.cf);
    // 004aa348  a2390a4e00             -mov byte ptr [0x4e0a39], al
    app->getMemory<x86::reg8>(x86::reg32(5114425) /* 0x4e0a39 */) = cpu.al;
    // 004aa34d  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004aa34f  01ca                   +add edx, ecx
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
    // 004aa351  19db                   -sbb ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx) + cpu.flags.cf);
    // 004aa353  01fd                   +add ebp, edi
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
    // 004aa355  8a80acb34d00           -mov al, byte ptr [eax + 0x4db3ac]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5092268) /* 0x4db3ac */);
    // 004aa35b  13349d340a4e00         -adc esi, dword ptr [ebx*4 + 0x4e0a34]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5114420) /* 0x4e0a34 */ + cpu.ebx * 4)) + cpu.flags.cf);
    // 004aa362  a23a0a4e00             -mov byte ptr [0x4e0a3a], al
    app->getMemory<x86::reg8>(x86::reg32(5114426) /* 0x4e0a3a */) = cpu.al;
    // 004aa367  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004aa369  01ca                   +add edx, ecx
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
    // 004aa36b  19db                   -sbb ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx) + cpu.flags.cf);
    // 004aa36d  01fd                   +add ebp, edi
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
    // 004aa36f  8a80acb34d00           -mov al, byte ptr [eax + 0x4db3ac]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5092268) /* 0x4db3ac */);
    // 004aa375  13349d340a4e00         -adc esi, dword ptr [ebx*4 + 0x4e0a34]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5114420) /* 0x4e0a34 */ + cpu.ebx * 4)) + cpu.flags.cf);
    // 004aa37c  a23b0a4e00             -mov byte ptr [0x4e0a3b], al
    app->getMemory<x86::reg8>(x86::reg32(5114427) /* 0x4e0a3b */) = cpu.al;
    // 004aa381  a1380a4e00             -mov eax, dword ptr [0x4e0a38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5114424) /* 0x4e0a38 */);
    // 004aa386  8b1d200a4e00           -mov ebx, dword ptr [0x4e0a20]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5114400) /* 0x4e0a20 */);
    // 004aa38c  3cff                   +cmp al, 0xff
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004aa38e  7434                   -je 0x4aa3c4
    if (cpu.flags.zf)
    {
        goto L_0x004aa3c4;
    }
    // 004aa390  80fcff                 +cmp ah, 0xff
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
    // 004aa393  742a                   -je 0x4aa3bf
    if (cpu.flags.zf)
    {
        goto L_0x004aa3bf;
    }
    // 004aa395  c1c810                 -ror eax, 0x10
    {
        x86::reg32& op = cpu.eax;
        x86::reg32 shift = 16 /*0x10*/ % 32;
        while (shift)
        {
            x86::reg32 cf = op & 1;
            op = op >> 1 | cf << 31;
            shift--;
        }
    }
    // 004aa398  3cff                   +cmp al, 0xff
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004aa39a  7412                   -je 0x4aa3ae
    if (cpu.flags.zf)
    {
        goto L_0x004aa3ae;
    }
    // 004aa39c  80fcff                 +cmp ah, 0xff
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
    // 004aa39f  7407                   -je 0x4aa3a8
    if (cpu.flags.zf)
    {
        goto L_0x004aa3a8;
    }
    // 004aa3a1  c1c810                 +ror eax, 0x10
    {
        x86::reg32& op = cpu.eax;
        x86::reg32 count = 16 /*0x10*/ % 32;
        if (count) {
            op = (op >> count) | (op << (32 - count));
            cpu.flags.cf = (op >> (32 - 1)) & 1;
            if (count == 1) {
                cpu.flags.of = ((op >> (32 - 1)) ^ (op >> (32 - 2))) & 1;
            }
        }
    }
    // 004aa3a4  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004aa3a6  eb44                   -jmp 0x4aa3ec
    goto L_0x004aa3ec;
L_0x004aa3a8:
    // 004aa3a8  90                     -nop 
    ;
    // 004aa3a9  884302                 -mov byte ptr [ebx + 2], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 004aa3ac  eb09                   -jmp 0x4aa3b7
    goto L_0x004aa3b7;
L_0x004aa3ae:
    // 004aa3ae  80fcff                 +cmp ah, 0xff
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
    // 004aa3b1  7404                   -je 0x4aa3b7
    if (cpu.flags.zf)
    {
        goto L_0x004aa3b7;
    }
    // 004aa3b3  90                     -nop 
    ;
    // 004aa3b4  886303                 -mov byte ptr [ebx + 3], ah
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(3) /* 0x3 */) = cpu.ah;
L_0x004aa3b7:
    // 004aa3b7  c1c810                 +ror eax, 0x10
    {
        x86::reg32& op = cpu.eax;
        x86::reg32 count = 16 /*0x10*/ % 32;
        if (count) {
            op = (op >> count) | (op << (32 - count));
            cpu.flags.cf = (op >> (32 - 1)) & 1;
            if (count == 1) {
                cpu.flags.of = ((op >> (32 - 1)) ^ (op >> (32 - 2))) & 1;
            }
        }
    }
    // 004aa3ba  668903                 -mov word ptr [ebx], ax
    app->getMemory<x86::reg16>(cpu.ebx) = cpu.ax;
    // 004aa3bd  eb2d                   -jmp 0x4aa3ec
    goto L_0x004aa3ec;
L_0x004aa3bf:
    // 004aa3bf  90                     -nop 
    ;
    // 004aa3c0  8803                   -mov byte ptr [ebx], al
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.al;
    // 004aa3c2  eb09                   -jmp 0x4aa3cd
    goto L_0x004aa3cd;
L_0x004aa3c4:
    // 004aa3c4  80fcff                 +cmp ah, 0xff
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
    // 004aa3c7  7404                   -je 0x4aa3cd
    if (cpu.flags.zf)
    {
        goto L_0x004aa3cd;
    }
    // 004aa3c9  90                     -nop 
    ;
    // 004aa3ca  886301                 -mov byte ptr [ebx + 1], ah
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */) = cpu.ah;
L_0x004aa3cd:
    // 004aa3cd  c1c810                 -ror eax, 0x10
    {
        x86::reg32& op = cpu.eax;
        x86::reg32 shift = 16 /*0x10*/ % 32;
        while (shift)
        {
            x86::reg32 cf = op & 1;
            op = op >> 1 | cf << 31;
            shift--;
        }
    }
    // 004aa3d0  3cff                   +cmp al, 0xff
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004aa3d2  7410                   -je 0x4aa3e4
    if (cpu.flags.zf)
    {
        goto L_0x004aa3e4;
    }
    // 004aa3d4  80fcff                 +cmp ah, 0xff
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
    // 004aa3d7  7406                   -je 0x4aa3df
    if (cpu.flags.zf)
    {
        goto L_0x004aa3df;
    }
    // 004aa3d9  66894302               -mov word ptr [ebx + 2], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(2) /* 0x2 */) = cpu.ax;
    // 004aa3dd  eb0d                   -jmp 0x4aa3ec
    goto L_0x004aa3ec;
L_0x004aa3df:
    // 004aa3df  884302                 -mov byte ptr [ebx + 2], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 004aa3e2  eb08                   -jmp 0x4aa3ec
    goto L_0x004aa3ec;
L_0x004aa3e4:
    // 004aa3e4  80fcff                 +cmp ah, 0xff
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
    // 004aa3e7  7403                   -je 0x4aa3ec
    if (cpu.flags.zf)
    {
        goto L_0x004aa3ec;
    }
    // 004aa3e9  886303                 -mov byte ptr [ebx + 3], ah
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(3) /* 0x3 */) = cpu.ah;
L_0x004aa3ec:
    // 004aa3ec  a1280a4e00             -mov eax, dword ptr [0x4e0a28]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5114408) /* 0x4e0a28 */);
    // 004aa3f1  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004aa3f4  83e804                 +sub eax, 4
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004aa3f7  891d200a4e00           -mov dword ptr [0x4e0a20], ebx
    app->getMemory<x86::reg32>(x86::reg32(5114400) /* 0x4e0a20 */) = cpu.ebx;
    // 004aa3fd  a3280a4e00             -mov dword ptr [0x4e0a28], eax
    app->getMemory<x86::reg32>(x86::reg32(5114408) /* 0x4e0a28 */) = cpu.eax;
    // 004aa402  0f850fffffff           -jne 0x4aa317
    if (!cpu.flags.zf)
    {
        goto L_0x004aa317;
    }
L_0x004aa408:
    // 004aa408  ff0d2c0a4e00           +dec dword ptr [0x4e0a2c]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5114412) /* 0x4e0a2c */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004aa40e  7827                   -js 0x4aa437
    if (cpu.flags.sf)
    {
        goto L_0x004aa437;
    }
    // 004aa410  43                     -inc ebx
    (cpu.ebx)++;
    // 004aa411  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004aa413  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004aa415  891d200a4e00           -mov dword ptr [0x4e0a20], ebx
    app->getMemory<x86::reg32>(x86::reg32(5114400) /* 0x4e0a20 */) = cpu.ebx;
    // 004aa41b  8a80acb34d00           -mov al, byte ptr [eax + 0x4db3ac]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5092268) /* 0x4db3ac */);
    // 004aa421  3cff                   +cmp al, 0xff
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(255 /*0xff*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004aa423  7403                   -je 0x4aa428
    if (cpu.flags.zf)
    {
        goto L_0x004aa428;
    }
    // 004aa425  8843ff                 -mov byte ptr [ebx - 1], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.al;
L_0x004aa428:
    // 004aa428  01ca                   +add edx, ecx
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
    // 004aa42a  19c0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 004aa42c  01fd                   +add ebp, edi
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
    // 004aa42e  133485340a4e00         +adc esi, dword ptr [eax*4 + 0x4e0a34]
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5114420) /* 0x4e0a34 */ + cpu.eax * 4))) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004aa435  ebd1                   -jmp 0x4aa408
    goto L_0x004aa408;
L_0x004aa437:
    // 004aa437  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa438  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa439  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa43a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4aa43c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa43c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004aa43d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004aa43e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004aa43f  8b35540a4e00           -mov esi, dword ptr [0x4e0a54]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5114452) /* 0x4e0a54 */);
    // 004aa445  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004aa447  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004aa449  83f90c                 +cmp ecx, 0xc
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aa44c  734b                   -jae 0x4aa499
    if (!cpu.flags.cf)
    {
        goto L_0x004aa499;
    }
L_0x004aa44e:
    // 004aa44e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004aa450  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004aa452  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004aa455  8b35500a4e00           -mov esi, dword ptr [0x4e0a50]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5114448) /* 0x4e0a50 */);
    // 004aa45b  c1ef10                 -shr edi, 0x10
    cpu.edi >>= 16 /*0x10*/ % 32;
    // 004aa45e  43                     -inc ebx
    (cpu.ebx)++;
    // 004aa45f  033c85580a4e00         -add edi, dword ptr [eax*4 + 0x4e0a58]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5114456) /* 0x4e0a58 */ + cpu.eax * 4)));
    // 004aa466  a1480a4e00             -mov eax, dword ptr [0x4e0a48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5114440) /* 0x4e0a48 */);
    // 004aa46b  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004aa46d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004aa46f  8a043e                 -mov al, byte ptr [esi + edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.edi * 1);
    // 004aa472  8b3d400a4e00           -mov edi, dword ptr [0x4e0a40]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5114432) /* 0x4e0a40 */);
    // 004aa478  01fd                   -add ebp, edi
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edi));
    // 004aa47a  8a80acb34d00           -mov al, byte ptr [eax + 0x4db3ac]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5092268) /* 0x4db3ac */);
    // 004aa480  3cfe                   +cmp al, 0xfe
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(254 /*0xfe*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004aa482  7509                   -jne 0x4aa48d
    if (!cpu.flags.zf)
    {
        goto L_0x004aa48d;
    }
    // 004aa484  8a43ff                 -mov al, byte ptr [ebx - 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */);
    // 004aa487  8a80d8e34d00           -mov al, byte ptr [eax + 0x4de3d8]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5104600) /* 0x4de3d8 */);
L_0x004aa48d:
    // 004aa48d  7703                   -ja 0x4aa492
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004aa492;
    }
    // 004aa48f  8843ff                 -mov byte ptr [ebx - 1], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.al;
L_0x004aa492:
    // 004aa492  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004aa493  75b9                   -jne 0x4aa44e
    if (!cpu.flags.zf)
    {
        goto L_0x004aa44e;
    }
    // 004aa495  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa496  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa497  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa498  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004aa499:
    // 004aa499  891d200a4e00           -mov dword ptr [0x4e0a20], ebx
    app->getMemory<x86::reg32>(x86::reg32(5114400) /* 0x4e0a20 */) = cpu.ebx;
    // 004aa49f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004aa4a1  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa4a3  8b35540a4e00           -mov esi, dword ptr [0x4e0a54]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5114452) /* 0x4e0a54 */);
    // 004aa4a9  c1ee0e                 -shr esi, 0xe
    cpu.esi >>= 14 /*0xe*/ % 32;
    // 004aa4ac  83e003                 -and eax, 3
    cpu.eax &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004aa4af  a3240a4e00             -mov dword ptr [0x4e0a24], eax
    app->getMemory<x86::reg32>(x86::reg32(5114404) /* 0x4e0a24 */) = cpu.eax;
    // 004aa4b4  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004aa4b6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004aa4b8  83e0fc                 -and eax, 0xfffffffc
    cpu.eax &= x86::reg32(x86::sreg32(4294967292 /*0xfffffffc*/));
    // 004aa4bb  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004aa4be  a3280a4e00             -mov dword ptr [0x4e0a28], eax
    app->getMemory<x86::reg32>(x86::reg32(5114408) /* 0x4e0a28 */) = cpu.eax;
    // 004aa4c3  890d2c0a4e00           -mov dword ptr [0x4e0a2c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5114412) /* 0x4e0a2c */) = cpu.ecx;
    // 004aa4c9  a1480a4e00             -mov eax, dword ptr [0x4e0a48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5114440) /* 0x4e0a48 */);
    // 004aa4ce  8b0d400a4e00           -mov ecx, dword ptr [0x4e0a40]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5114432) /* 0x4e0a40 */);
    // 004aa4d4  c1f810                 +sar eax, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 004aa4d7  7809                   -js 0x4aa4e2
    if (cpu.flags.sf)
    {
        goto L_0x004aa4e2;
    }
    // 004aa4d9  8b8486580a4e00         -mov eax, dword ptr [esi + eax*4 + 0x4e0a58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5114456) /* 0x4e0a58 */ + cpu.eax * 4);
    // 004aa4e0  eb0b                   -jmp 0x4aa4ed
    goto L_0x004aa4ed;
L_0x004aa4e2:
    // 004aa4e2  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 004aa4e4  8b8486580a4e00         -mov eax, dword ptr [esi + eax*4 + 0x4e0a58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5114456) /* 0x4e0a58 */ + cpu.eax * 4);
    // 004aa4eb  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
L_0x004aa4ed:
    // 004aa4ed  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004aa4f0  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004aa4f2  a3340a4e00             -mov dword ptr [0x4e0a34], eax
    app->getMemory<x86::reg32>(x86::reg32(5114420) /* 0x4e0a34 */) = cpu.eax;
    // 004aa4f7  03865c0a4e00           -add eax, dword ptr [esi + 0x4e0a5c]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5114460) /* 0x4e0a5c */)));
    // 004aa4fd  a3300a4e00             -mov dword ptr [0x4e0a30], eax
    app->getMemory<x86::reg32>(x86::reg32(5114416) /* 0x4e0a30 */) = cpu.eax;
    // 004aa502  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004aa504  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004aa506  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004aa509  8b35500a4e00           -mov esi, dword ptr [0x4e0a50]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5114448) /* 0x4e0a50 */);
    // 004aa50f  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004aa512  033485580a4e00         -add esi, dword ptr [eax*4 + 0x4e0a58]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5114456) /* 0x4e0a58 */ + cpu.eax * 4)));
    // 004aa519  01ce                   -add esi, ecx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004aa51b  c1e510                 -shl ebp, 0x10
    cpu.ebp <<= 16 /*0x10*/ % 32;
    // 004aa51e  8b3d400a4e00           -mov edi, dword ptr [0x4e0a40]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5114432) /* 0x4e0a40 */);
    // 004aa524  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004aa527  8b0d480a4e00           -mov ecx, dword ptr [0x4e0a48]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5114440) /* 0x4e0a48 */);
    // 004aa52d  c1e710                 -shl edi, 0x10
    cpu.edi <<= 16 /*0x10*/ % 32;
    // 004aa530  c1e110                 +shl ecx, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.ecx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
L_0x004aa533:
    // 004aa533  ff0d240a4e00           +dec dword ptr [0x4e0a24]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5114404) /* 0x4e0a24 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004aa539  7832                   -js 0x4aa56d
    if (cpu.flags.sf)
    {
        goto L_0x004aa56d;
    }
    // 004aa53b  43                     -inc ebx
    (cpu.ebx)++;
    // 004aa53c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004aa53e  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004aa540  891d200a4e00           -mov dword ptr [0x4e0a20], ebx
    app->getMemory<x86::reg32>(x86::reg32(5114400) /* 0x4e0a20 */) = cpu.ebx;
    // 004aa546  8a80acb34d00           -mov al, byte ptr [eax + 0x4db3ac]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5092268) /* 0x4db3ac */);
    // 004aa54c  3cfe                   +cmp al, 0xfe
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(254 /*0xfe*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004aa54e  7509                   -jne 0x4aa559
    if (!cpu.flags.zf)
    {
        goto L_0x004aa559;
    }
    // 004aa550  8a43ff                 -mov al, byte ptr [ebx - 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */);
    // 004aa553  8a80d8e34d00           -mov al, byte ptr [eax + 0x4de3d8]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5104600) /* 0x4de3d8 */);
L_0x004aa559:
    // 004aa559  7703                   -ja 0x4aa55e
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004aa55e;
    }
    // 004aa55b  8843ff                 -mov byte ptr [ebx - 1], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.al;
L_0x004aa55e:
    // 004aa55e  01ca                   +add edx, ecx
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
    // 004aa560  19c0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 004aa562  01fd                   +add ebp, edi
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
    // 004aa564  133485340a4e00         +adc esi, dword ptr [eax*4 + 0x4e0a34]
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5114420) /* 0x4e0a34 */ + cpu.eax * 4))) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004aa56b  ebc6                   -jmp 0x4aa533
    goto L_0x004aa533;
L_0x004aa56d:
    // 004aa56d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004aa56f  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004aa571  01ca                   +add edx, ecx
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
    // 004aa573  19db                   -sbb ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx) + cpu.flags.cf);
    // 004aa575  01fd                   +add ebp, edi
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
    // 004aa577  8a80acb34d00           -mov al, byte ptr [eax + 0x4db3ac]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5092268) /* 0x4db3ac */);
    // 004aa57d  13349d340a4e00         -adc esi, dword ptr [ebx*4 + 0x4e0a34]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5114420) /* 0x4e0a34 */ + cpu.ebx * 4)) + cpu.flags.cf);
    // 004aa584  a2380a4e00             -mov byte ptr [0x4e0a38], al
    app->getMemory<x86::reg8>(x86::reg32(5114424) /* 0x4e0a38 */) = cpu.al;
    // 004aa589  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004aa58b  01ca                   +add edx, ecx
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
    // 004aa58d  19db                   -sbb ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx) + cpu.flags.cf);
    // 004aa58f  01fd                   +add ebp, edi
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
    // 004aa591  8a80acb34d00           -mov al, byte ptr [eax + 0x4db3ac]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5092268) /* 0x4db3ac */);
    // 004aa597  13349d340a4e00         -adc esi, dword ptr [ebx*4 + 0x4e0a34]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5114420) /* 0x4e0a34 */ + cpu.ebx * 4)) + cpu.flags.cf);
    // 004aa59e  a2390a4e00             -mov byte ptr [0x4e0a39], al
    app->getMemory<x86::reg8>(x86::reg32(5114425) /* 0x4e0a39 */) = cpu.al;
    // 004aa5a3  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004aa5a5  01ca                   +add edx, ecx
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
    // 004aa5a7  19db                   -sbb ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx) + cpu.flags.cf);
    // 004aa5a9  01fd                   +add ebp, edi
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
    // 004aa5ab  8a80acb34d00           -mov al, byte ptr [eax + 0x4db3ac]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5092268) /* 0x4db3ac */);
    // 004aa5b1  13349d340a4e00         -adc esi, dword ptr [ebx*4 + 0x4e0a34]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5114420) /* 0x4e0a34 */ + cpu.ebx * 4)) + cpu.flags.cf);
    // 004aa5b8  a23a0a4e00             -mov byte ptr [0x4e0a3a], al
    app->getMemory<x86::reg8>(x86::reg32(5114426) /* 0x4e0a3a */) = cpu.al;
    // 004aa5bd  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004aa5bf  01ca                   +add edx, ecx
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
    // 004aa5c1  19db                   -sbb ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx) + cpu.flags.cf);
    // 004aa5c3  01fd                   +add ebp, edi
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
    // 004aa5c5  8a80acb34d00           -mov al, byte ptr [eax + 0x4db3ac]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5092268) /* 0x4db3ac */);
    // 004aa5cb  13349d340a4e00         -adc esi, dword ptr [ebx*4 + 0x4e0a34]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5114420) /* 0x4e0a34 */ + cpu.ebx * 4)) + cpu.flags.cf);
    // 004aa5d2  a23b0a4e00             -mov byte ptr [0x4e0a3b], al
    app->getMemory<x86::reg8>(x86::reg32(5114427) /* 0x4e0a3b */) = cpu.al;
    // 004aa5d7  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004aa5d8  a1380a4e00             -mov eax, dword ptr [0x4e0a38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5114424) /* 0x4e0a38 */);
    // 004aa5dd  8b1d200a4e00           -mov ebx, dword ptr [0x4e0a20]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5114400) /* 0x4e0a20 */);
    // 004aa5e3  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004aa5e5  3cfe                   +cmp al, 0xfe
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(254 /*0xfe*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004aa5e7  7508                   -jne 0x4aa5f1
    if (!cpu.flags.zf)
    {
        goto L_0x004aa5f1;
    }
    // 004aa5e9  8a13                   -mov dl, byte ptr [ebx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx);
    // 004aa5eb  8a82d8e34d00           -mov al, byte ptr [edx + 0x4de3d8]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5104600) /* 0x4de3d8 */);
L_0x004aa5f1:
    // 004aa5f1  7760                   -ja 0x4aa653
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004aa653;
    }
    // 004aa5f3  80fcfe                 +cmp ah, 0xfe
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
    // 004aa5f6  7509                   -jne 0x4aa601
    if (!cpu.flags.zf)
    {
        goto L_0x004aa601;
    }
    // 004aa5f8  8a5301                 -mov dl, byte ptr [ebx + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004aa5fb  8aa2d8e34d00           -mov ah, byte ptr [edx + 0x4de3d8]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5104600) /* 0x4de3d8 */);
L_0x004aa601:
    // 004aa601  774b                   -ja 0x4aa64e
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004aa64e;
    }
    // 004aa603  c1c810                 -ror eax, 0x10
    {
        x86::reg32& op = cpu.eax;
        x86::reg32 shift = 16 /*0x10*/ % 32;
        while (shift)
        {
            x86::reg32 cf = op & 1;
            op = op >> 1 | cf << 31;
            shift--;
        }
    }
    // 004aa606  3cfe                   +cmp al, 0xfe
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(254 /*0xfe*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004aa608  7509                   -jne 0x4aa613
    if (!cpu.flags.zf)
    {
        goto L_0x004aa613;
    }
    // 004aa60a  8a5302                 -mov dl, byte ptr [ebx + 2]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 004aa60d  8a82d8e34d00           -mov al, byte ptr [edx + 0x4de3d8]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5104600) /* 0x4de3d8 */);
L_0x004aa613:
    // 004aa613  771d                   -ja 0x4aa632
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004aa632;
    }
    // 004aa615  80fcfe                 +cmp ah, 0xfe
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
    // 004aa618  7509                   -jne 0x4aa623
    if (!cpu.flags.zf)
    {
        goto L_0x004aa623;
    }
    // 004aa61a  8a5303                 -mov dl, byte ptr [ebx + 3]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(3) /* 0x3 */);
    // 004aa61d  8aa2d8e34d00           -mov ah, byte ptr [edx + 0x4de3d8]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5104600) /* 0x4de3d8 */);
L_0x004aa623:
    // 004aa623  7707                   -ja 0x4aa62c
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004aa62c;
    }
    // 004aa625  c1c810                 +ror eax, 0x10
    {
        x86::reg32& op = cpu.eax;
        x86::reg32 count = 16 /*0x10*/ % 32;
        if (count) {
            op = (op >> count) | (op << (32 - count));
            cpu.flags.cf = (op >> (32 - 1)) & 1;
            if (count == 1) {
                cpu.flags.of = ((op >> (32 - 1)) ^ (op >> (32 - 2))) & 1;
            }
        }
    }
    // 004aa628  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004aa62a  eb7b                   -jmp 0x4aa6a7
    goto L_0x004aa6a7;
L_0x004aa62c:
    // 004aa62c  90                     -nop 
    ;
    // 004aa62d  884302                 -mov byte ptr [ebx + 2], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 004aa630  eb14                   -jmp 0x4aa646
    goto L_0x004aa646;
L_0x004aa632:
    // 004aa632  80fcfe                 +cmp ah, 0xfe
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
    // 004aa635  7509                   -jne 0x4aa640
    if (!cpu.flags.zf)
    {
        goto L_0x004aa640;
    }
    // 004aa637  8a5303                 -mov dl, byte ptr [ebx + 3]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(3) /* 0x3 */);
    // 004aa63a  8aa2d8e34d00           -mov ah, byte ptr [edx + 0x4de3d8]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5104600) /* 0x4de3d8 */);
L_0x004aa640:
    // 004aa640  7704                   -ja 0x4aa646
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004aa646;
    }
    // 004aa642  90                     -nop 
    ;
    // 004aa643  886303                 -mov byte ptr [ebx + 3], ah
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(3) /* 0x3 */) = cpu.ah;
L_0x004aa646:
    // 004aa646  c1c810                 +ror eax, 0x10
    {
        x86::reg32& op = cpu.eax;
        x86::reg32 count = 16 /*0x10*/ % 32;
        if (count) {
            op = (op >> count) | (op << (32 - count));
            cpu.flags.cf = (op >> (32 - 1)) & 1;
            if (count == 1) {
                cpu.flags.of = ((op >> (32 - 1)) ^ (op >> (32 - 2))) & 1;
            }
        }
    }
    // 004aa649  668903                 -mov word ptr [ebx], ax
    app->getMemory<x86::reg16>(cpu.ebx) = cpu.ax;
    // 004aa64c  eb59                   -jmp 0x4aa6a7
    goto L_0x004aa6a7;
L_0x004aa64e:
    // 004aa64e  90                     -nop 
    ;
    // 004aa64f  8803                   -mov byte ptr [ebx], al
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.al;
    // 004aa651  eb14                   -jmp 0x4aa667
    goto L_0x004aa667;
L_0x004aa653:
    // 004aa653  80fcfe                 +cmp ah, 0xfe
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
    // 004aa656  7509                   -jne 0x4aa661
    if (!cpu.flags.zf)
    {
        goto L_0x004aa661;
    }
    // 004aa658  8a5301                 -mov dl, byte ptr [ebx + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004aa65b  8aa2d8e34d00           -mov ah, byte ptr [edx + 0x4de3d8]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5104600) /* 0x4de3d8 */);
L_0x004aa661:
    // 004aa661  7704                   -ja 0x4aa667
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004aa667;
    }
    // 004aa663  90                     -nop 
    ;
    // 004aa664  886301                 -mov byte ptr [ebx + 1], ah
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */) = cpu.ah;
L_0x004aa667:
    // 004aa667  c1c810                 -ror eax, 0x10
    {
        x86::reg32& op = cpu.eax;
        x86::reg32 shift = 16 /*0x10*/ % 32;
        while (shift)
        {
            x86::reg32 cf = op & 1;
            op = op >> 1 | cf << 31;
            shift--;
        }
    }
    // 004aa66a  3cfe                   +cmp al, 0xfe
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(254 /*0xfe*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004aa66c  7509                   -jne 0x4aa677
    if (!cpu.flags.zf)
    {
        goto L_0x004aa677;
    }
    // 004aa66e  8a5302                 -mov dl, byte ptr [ebx + 2]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 004aa671  8a82d8e34d00           -mov al, byte ptr [edx + 0x4de3d8]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5104600) /* 0x4de3d8 */);
L_0x004aa677:
    // 004aa677  771b                   -ja 0x4aa694
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004aa694;
    }
    // 004aa679  80fcfe                 +cmp ah, 0xfe
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
    // 004aa67c  7509                   -jne 0x4aa687
    if (!cpu.flags.zf)
    {
        goto L_0x004aa687;
    }
    // 004aa67e  8a5303                 -mov dl, byte ptr [ebx + 3]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(3) /* 0x3 */);
    // 004aa681  8aa2d8e34d00           -mov ah, byte ptr [edx + 0x4de3d8]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5104600) /* 0x4de3d8 */);
L_0x004aa687:
    // 004aa687  7706                   -ja 0x4aa68f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004aa68f;
    }
    // 004aa689  66894302               -mov word ptr [ebx + 2], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(2) /* 0x2 */) = cpu.ax;
    // 004aa68d  eb18                   -jmp 0x4aa6a7
    goto L_0x004aa6a7;
L_0x004aa68f:
    // 004aa68f  884302                 -mov byte ptr [ebx + 2], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(2) /* 0x2 */) = cpu.al;
    // 004aa692  eb13                   -jmp 0x4aa6a7
    goto L_0x004aa6a7;
L_0x004aa694:
    // 004aa694  80fcfe                 +cmp ah, 0xfe
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
    // 004aa697  7509                   -jne 0x4aa6a2
    if (!cpu.flags.zf)
    {
        goto L_0x004aa6a2;
    }
    // 004aa699  8a5303                 -mov dl, byte ptr [ebx + 3]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(3) /* 0x3 */);
    // 004aa69c  8aa2d8e34d00           -mov ah, byte ptr [edx + 0x4de3d8]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5104600) /* 0x4de3d8 */);
L_0x004aa6a2:
    // 004aa6a2  7703                   -ja 0x4aa6a7
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004aa6a7;
    }
    // 004aa6a4  886303                 -mov byte ptr [ebx + 3], ah
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(3) /* 0x3 */) = cpu.ah;
L_0x004aa6a7:
    // 004aa6a7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa6a8  a1280a4e00             -mov eax, dword ptr [0x4e0a28]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5114408) /* 0x4e0a28 */);
    // 004aa6ad  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004aa6b0  83e804                 +sub eax, 4
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004aa6b3  891d200a4e00           -mov dword ptr [0x4e0a20], ebx
    app->getMemory<x86::reg32>(x86::reg32(5114400) /* 0x4e0a20 */) = cpu.ebx;
    // 004aa6b9  a3280a4e00             -mov dword ptr [0x4e0a28], eax
    app->getMemory<x86::reg32>(x86::reg32(5114408) /* 0x4e0a28 */) = cpu.eax;
    // 004aa6be  0f85a9feffff           -jne 0x4aa56d
    if (!cpu.flags.zf)
    {
        goto L_0x004aa56d;
    }
L_0x004aa6c4:
    // 004aa6c4  ff0d2c0a4e00           +dec dword ptr [0x4e0a2c]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5114412) /* 0x4e0a2c */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004aa6ca  7832                   -js 0x4aa6fe
    if (cpu.flags.sf)
    {
        goto L_0x004aa6fe;
    }
    // 004aa6cc  43                     -inc ebx
    (cpu.ebx)++;
    // 004aa6cd  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004aa6cf  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004aa6d1  891d200a4e00           -mov dword ptr [0x4e0a20], ebx
    app->getMemory<x86::reg32>(x86::reg32(5114400) /* 0x4e0a20 */) = cpu.ebx;
    // 004aa6d7  8a80acb34d00           -mov al, byte ptr [eax + 0x4db3ac]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5092268) /* 0x4db3ac */);
    // 004aa6dd  3cfe                   +cmp al, 0xfe
    {
        x86::reg8 tmp1 = cpu.al;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(254 /*0xfe*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004aa6df  7509                   -jne 0x4aa6ea
    if (!cpu.flags.zf)
    {
        goto L_0x004aa6ea;
    }
    // 004aa6e1  8a43ff                 -mov al, byte ptr [ebx - 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */);
    // 004aa6e4  8a80d8e34d00           -mov al, byte ptr [eax + 0x4de3d8]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5104600) /* 0x4de3d8 */);
L_0x004aa6ea:
    // 004aa6ea  7703                   -ja 0x4aa6ef
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004aa6ef;
    }
    // 004aa6ec  8843ff                 -mov byte ptr [ebx - 1], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.al;
L_0x004aa6ef:
    // 004aa6ef  01ca                   +add edx, ecx
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
    // 004aa6f1  19c0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 004aa6f3  01fd                   +add ebp, edi
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
    // 004aa6f5  133485340a4e00         +adc esi, dword ptr [eax*4 + 0x4e0a34]
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5114420) /* 0x4e0a34 */ + cpu.eax * 4))) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004aa6fc  ebc6                   -jmp 0x4aa6c4
    goto L_0x004aa6c4;
L_0x004aa6fe:
    // 004aa6fe  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa6ff  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa700  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa701  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4aa704(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa704  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004aa705  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004aa706  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004aa707  8b35540a4e00           -mov esi, dword ptr [0x4e0a54]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5114452) /* 0x4e0a54 */);
    // 004aa70d  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004aa70f  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004aa711  83f90c                 +cmp ecx, 0xc
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aa714  7345                   -jae 0x4aa75b
    if (!cpu.flags.cf)
    {
        goto L_0x004aa75b;
    }
L_0x004aa716:
    // 004aa716  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004aa718  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004aa71a  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004aa71d  8b35500a4e00           -mov esi, dword ptr [0x4e0a50]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5114448) /* 0x4e0a50 */);
    // 004aa723  c1ef10                 -shr edi, 0x10
    cpu.edi >>= 16 /*0x10*/ % 32;
    // 004aa726  43                     -inc ebx
    (cpu.ebx)++;
    // 004aa727  033c85580a4e00         -add edi, dword ptr [eax*4 + 0x4e0a58]
    (cpu.edi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5114456) /* 0x4e0a58 */ + cpu.eax * 4)));
    // 004aa72e  a1480a4e00             -mov eax, dword ptr [0x4e0a48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5114440) /* 0x4e0a48 */);
    // 004aa733  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004aa735  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004aa737  8a043e                 -mov al, byte ptr [esi + edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.edi * 1);
    // 004aa73a  8b3df8c84d00           -mov edi, dword ptr [0x4dc8f8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5097720) /* 0x4dc8f8 */);
    // 004aa740  8b3c87                 -mov edi, dword ptr [edi + eax*4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + cpu.eax * 4);
    // 004aa743  8a43ff                 -mov al, byte ptr [ebx - 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */);
    // 004aa746  8a0407                 -mov al, byte ptr [edi + eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + cpu.eax * 1);
    // 004aa749  8b3d400a4e00           -mov edi, dword ptr [0x4e0a40]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5114432) /* 0x4e0a40 */);
    // 004aa74f  8843ff                 -mov byte ptr [ebx - 1], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 004aa752  01fd                   +add ebp, edi
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
    // 004aa754  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004aa755  75bf                   -jne 0x4aa716
    if (!cpu.flags.zf)
    {
        goto L_0x004aa716;
    }
    // 004aa757  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa758  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa759  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa75a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004aa75b:
    // 004aa75b  891d200a4e00           -mov dword ptr [0x4e0a20], ebx
    app->getMemory<x86::reg32>(x86::reg32(5114400) /* 0x4e0a20 */) = cpu.ebx;
    // 004aa761  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004aa763  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004aa765  8b35540a4e00           -mov esi, dword ptr [0x4e0a54]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5114452) /* 0x4e0a54 */);
    // 004aa76b  c1ee0e                 -shr esi, 0xe
    cpu.esi >>= 14 /*0xe*/ % 32;
    // 004aa76e  83e003                 -and eax, 3
    cpu.eax &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004aa771  a3240a4e00             -mov dword ptr [0x4e0a24], eax
    app->getMemory<x86::reg32>(x86::reg32(5114404) /* 0x4e0a24 */) = cpu.eax;
    // 004aa776  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004aa778  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004aa77a  83e0fc                 -and eax, 0xfffffffc
    cpu.eax &= x86::reg32(x86::sreg32(4294967292 /*0xfffffffc*/));
    // 004aa77d  83e103                 -and ecx, 3
    cpu.ecx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004aa780  a3280a4e00             -mov dword ptr [0x4e0a28], eax
    app->getMemory<x86::reg32>(x86::reg32(5114408) /* 0x4e0a28 */) = cpu.eax;
    // 004aa785  890d2c0a4e00           -mov dword ptr [0x4e0a2c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5114412) /* 0x4e0a2c */) = cpu.ecx;
    // 004aa78b  a1480a4e00             -mov eax, dword ptr [0x4e0a48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5114440) /* 0x4e0a48 */);
    // 004aa790  8b0d400a4e00           -mov ecx, dword ptr [0x4e0a40]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5114432) /* 0x4e0a40 */);
    // 004aa796  c1f810                 +sar eax, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 004aa799  7809                   -js 0x4aa7a4
    if (cpu.flags.sf)
    {
        goto L_0x004aa7a4;
    }
    // 004aa79b  8b8486580a4e00         -mov eax, dword ptr [esi + eax*4 + 0x4e0a58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5114456) /* 0x4e0a58 */ + cpu.eax * 4);
    // 004aa7a2  eb0b                   -jmp 0x4aa7af
    goto L_0x004aa7af;
L_0x004aa7a4:
    // 004aa7a4  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 004aa7a6  8b8486580a4e00         -mov eax, dword ptr [esi + eax*4 + 0x4e0a58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5114456) /* 0x4e0a58 */ + cpu.eax * 4);
    // 004aa7ad  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
L_0x004aa7af:
    // 004aa7af  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004aa7b2  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004aa7b4  a3340a4e00             -mov dword ptr [0x4e0a34], eax
    app->getMemory<x86::reg32>(x86::reg32(5114420) /* 0x4e0a34 */) = cpu.eax;
    // 004aa7b9  03865c0a4e00           -add eax, dword ptr [esi + 0x4e0a5c]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(5114460) /* 0x4e0a5c */)));
    // 004aa7bf  a3300a4e00             -mov dword ptr [0x4e0a30], eax
    app->getMemory<x86::reg32>(x86::reg32(5114416) /* 0x4e0a30 */) = cpu.eax;
    // 004aa7c4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004aa7c6  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004aa7c8  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004aa7cb  8b35500a4e00           -mov esi, dword ptr [0x4e0a50]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5114448) /* 0x4e0a50 */);
    // 004aa7d1  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004aa7d4  033485580a4e00         -add esi, dword ptr [eax*4 + 0x4e0a58]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5114456) /* 0x4e0a58 */ + cpu.eax * 4)));
    // 004aa7db  01ce                   -add esi, ecx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004aa7dd  c1e510                 -shl ebp, 0x10
    cpu.ebp <<= 16 /*0x10*/ % 32;
    // 004aa7e0  8b3d400a4e00           -mov edi, dword ptr [0x4e0a40]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5114432) /* 0x4e0a40 */);
    // 004aa7e6  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004aa7e9  8b0d480a4e00           -mov ecx, dword ptr [0x4e0a48]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5114440) /* 0x4e0a48 */);
    // 004aa7ef  c1e710                 -shl edi, 0x10
    cpu.edi <<= 16 /*0x10*/ % 32;
    // 004aa7f2  c1e110                 +shl ecx, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.ecx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
L_0x004aa7f5:
    // 004aa7f5  ff0d240a4e00           +dec dword ptr [0x4e0a24]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5114404) /* 0x4e0a24 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004aa7fb  782e                   -js 0x4aa82b
    if (cpu.flags.sf)
    {
        goto L_0x004aa82b;
    }
    // 004aa7fd  43                     -inc ebx
    (cpu.ebx)++;
    // 004aa7fe  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004aa800  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004aa802  891d200a4e00           -mov dword ptr [0x4e0a20], ebx
    app->getMemory<x86::reg32>(x86::reg32(5114400) /* 0x4e0a20 */) = cpu.ebx;
    // 004aa808  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004aa809  8b35f8c84d00           -mov esi, dword ptr [0x4dc8f8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5097720) /* 0x4dc8f8 */);
    // 004aa80f  8b3486                 -mov esi, dword ptr [esi + eax*4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + cpu.eax * 4);
    // 004aa812  8a43ff                 -mov al, byte ptr [ebx - 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */);
    // 004aa815  8a0406                 -mov al, byte ptr [esi + eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1);
    // 004aa818  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa819  8843ff                 -mov byte ptr [ebx - 1], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 004aa81c  01ca                   +add edx, ecx
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
    // 004aa81e  19c0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 004aa820  01fd                   +add ebp, edi
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
    // 004aa822  133485340a4e00         +adc esi, dword ptr [eax*4 + 0x4e0a34]
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5114420) /* 0x4e0a34 */ + cpu.eax * 4))) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004aa829  ebca                   -jmp 0x4aa7f5
    goto L_0x004aa7f5;
L_0x004aa82b:
    // 004aa82b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004aa82d  01ca                   +add edx, ecx
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
    // 004aa82f  19db                   -sbb ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx) + cpu.flags.cf);
    // 004aa831  01fd                   +add ebp, edi
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
    // 004aa833  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004aa835  13349d340a4e00         -adc esi, dword ptr [ebx*4 + 0x4e0a34]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5114420) /* 0x4e0a34 */ + cpu.ebx * 4)) + cpu.flags.cf);
    // 004aa83c  a2380a4e00             -mov byte ptr [0x4e0a38], al
    app->getMemory<x86::reg8>(x86::reg32(5114424) /* 0x4e0a38 */) = cpu.al;
    // 004aa841  01ca                   +add edx, ecx
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
    // 004aa843  19db                   -sbb ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx) + cpu.flags.cf);
    // 004aa845  01fd                   +add ebp, edi
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
    // 004aa847  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004aa849  13349d340a4e00         -adc esi, dword ptr [ebx*4 + 0x4e0a34]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5114420) /* 0x4e0a34 */ + cpu.ebx * 4)) + cpu.flags.cf);
    // 004aa850  a2390a4e00             -mov byte ptr [0x4e0a39], al
    app->getMemory<x86::reg8>(x86::reg32(5114425) /* 0x4e0a39 */) = cpu.al;
    // 004aa855  01ca                   +add edx, ecx
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
    // 004aa857  19db                   -sbb ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx) + cpu.flags.cf);
    // 004aa859  01fd                   +add ebp, edi
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
    // 004aa85b  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004aa85d  13349d340a4e00         -adc esi, dword ptr [ebx*4 + 0x4e0a34]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5114420) /* 0x4e0a34 */ + cpu.ebx * 4)) + cpu.flags.cf);
    // 004aa864  a23a0a4e00             -mov byte ptr [0x4e0a3a], al
    app->getMemory<x86::reg8>(x86::reg32(5114426) /* 0x4e0a3a */) = cpu.al;
    // 004aa869  01ca                   +add edx, ecx
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
    // 004aa86b  19db                   -sbb ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx) + cpu.flags.cf);
    // 004aa86d  01fd                   +add ebp, edi
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
    // 004aa86f  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004aa871  13349d340a4e00         -adc esi, dword ptr [ebx*4 + 0x4e0a34]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5114420) /* 0x4e0a34 */ + cpu.ebx * 4)) + cpu.flags.cf);
    // 004aa878  a23b0a4e00             -mov byte ptr [0x4e0a3b], al
    app->getMemory<x86::reg8>(x86::reg32(5114427) /* 0x4e0a3b */) = cpu.al;
    // 004aa87d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004aa87e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004aa87f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004aa880  8b1d200a4e00           -mov ebx, dword ptr [0x4e0a20]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5114400) /* 0x4e0a20 */);
    // 004aa886  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004aa888  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004aa88a  a0380a4e00             -mov al, byte ptr [0x4e0a38]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5114424) /* 0x4e0a38 */);
    // 004aa88f  8b35f8c84d00           -mov esi, dword ptr [0x4dc8f8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5097720) /* 0x4dc8f8 */);
    // 004aa895  8a15390a4e00           -mov dl, byte ptr [0x4e0a39]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5114425) /* 0x4e0a39 */);
    // 004aa89b  8b3df8c84d00           -mov edi, dword ptr [0x4dc8f8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5097720) /* 0x4dc8f8 */);
    // 004aa8a1  8b3486                 -mov esi, dword ptr [esi + eax*4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + cpu.eax * 4);
    // 004aa8a4  8a03                   -mov al, byte ptr [ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx);
    // 004aa8a6  8b3c97                 -mov edi, dword ptr [edi + edx*4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + cpu.edx * 4);
    // 004aa8a9  8a5301                 -mov dl, byte ptr [ebx + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004aa8ac  8a0406                 -mov al, byte ptr [esi + eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1);
    // 004aa8af  8a1417                 -mov dl, byte ptr [edi + edx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + cpu.edx * 1);
    // 004aa8b2  a2380a4e00             -mov byte ptr [0x4e0a38], al
    app->getMemory<x86::reg8>(x86::reg32(5114424) /* 0x4e0a38 */) = cpu.al;
    // 004aa8b7  8815390a4e00           -mov byte ptr [0x4e0a39], dl
    app->getMemory<x86::reg8>(x86::reg32(5114425) /* 0x4e0a39 */) = cpu.dl;
    // 004aa8bd  a03a0a4e00             -mov al, byte ptr [0x4e0a3a]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5114426) /* 0x4e0a3a */);
    // 004aa8c2  8b35f8c84d00           -mov esi, dword ptr [0x4dc8f8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5097720) /* 0x4dc8f8 */);
    // 004aa8c8  8a153b0a4e00           -mov dl, byte ptr [0x4e0a3b]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5114427) /* 0x4e0a3b */);
    // 004aa8ce  8b3df8c84d00           -mov edi, dword ptr [0x4dc8f8]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5097720) /* 0x4dc8f8 */);
    // 004aa8d4  8b3486                 -mov esi, dword ptr [esi + eax*4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + cpu.eax * 4);
    // 004aa8d7  8a4302                 -mov al, byte ptr [ebx + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(2) /* 0x2 */);
    // 004aa8da  8b3c97                 -mov edi, dword ptr [edi + edx*4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + cpu.edx * 4);
    // 004aa8dd  8a5303                 -mov dl, byte ptr [ebx + 3]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(3) /* 0x3 */);
    // 004aa8e0  8a0406                 -mov al, byte ptr [esi + eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1);
    // 004aa8e3  8a1417                 -mov dl, byte ptr [edi + edx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edi + cpu.edx * 1);
    // 004aa8e6  a23a0a4e00             -mov byte ptr [0x4e0a3a], al
    app->getMemory<x86::reg8>(x86::reg32(5114426) /* 0x4e0a3a */) = cpu.al;
    // 004aa8eb  88153b0a4e00           -mov byte ptr [0x4e0a3b], dl
    app->getMemory<x86::reg8>(x86::reg32(5114427) /* 0x4e0a3b */) = cpu.dl;
    // 004aa8f1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa8f2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa8f3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa8f4  a1280a4e00             -mov eax, dword ptr [0x4e0a28]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5114408) /* 0x4e0a28 */);
    // 004aa8f9  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004aa8fc  83e804                 +sub eax, 4
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004aa8ff  891d200a4e00           -mov dword ptr [0x4e0a20], ebx
    app->getMemory<x86::reg32>(x86::reg32(5114400) /* 0x4e0a20 */) = cpu.ebx;
    // 004aa905  a3280a4e00             -mov dword ptr [0x4e0a28], eax
    app->getMemory<x86::reg32>(x86::reg32(5114408) /* 0x4e0a28 */) = cpu.eax;
    // 004aa90a  a1380a4e00             -mov eax, dword ptr [0x4e0a38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5114424) /* 0x4e0a38 */);
    // 004aa90f  8943fc                 -mov dword ptr [ebx - 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004aa912  0f8513ffffff           -jne 0x4aa82b
    if (!cpu.flags.zf)
    {
        goto L_0x004aa82b;
    }
L_0x004aa918:
    // 004aa918  ff0d2c0a4e00           +dec dword ptr [0x4e0a2c]
    {
        auto tmp = app->getMemory<x86::reg32>(x86::reg32(5114412) /* 0x4e0a2c */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004aa91e  782e                   -js 0x4aa94e
    if (cpu.flags.sf)
    {
        goto L_0x004aa94e;
    }
    // 004aa920  43                     -inc ebx
    (cpu.ebx)++;
    // 004aa921  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004aa923  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004aa925  891d200a4e00           -mov dword ptr [0x4e0a20], ebx
    app->getMemory<x86::reg32>(x86::reg32(5114400) /* 0x4e0a20 */) = cpu.ebx;
    // 004aa92b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004aa92c  8b35f8c84d00           -mov esi, dword ptr [0x4dc8f8]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5097720) /* 0x4dc8f8 */);
    // 004aa932  8b3486                 -mov esi, dword ptr [esi + eax*4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + cpu.eax * 4);
    // 004aa935  8a43ff                 -mov al, byte ptr [ebx - 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */);
    // 004aa938  8a0406                 -mov al, byte ptr [esi + eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1);
    // 004aa93b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa93c  8843ff                 -mov byte ptr [ebx - 1], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(-1) /* -0x1 */) = cpu.al;
    // 004aa93f  01ca                   +add edx, ecx
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
    // 004aa941  19c0                   -sbb eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax) + cpu.flags.cf);
    // 004aa943  01fd                   +add ebp, edi
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
    // 004aa945  133485340a4e00         +adc esi, dword ptr [eax*4 + 0x4e0a34]
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5114420) /* 0x4e0a34 */ + cpu.eax * 4))) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004aa94c  ebca                   -jmp 0x4aa918
    goto L_0x004aa918;
L_0x004aa94e:
    // 004aa94e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa94f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa950  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa951  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4aa960(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa960  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004aa961  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004aa964  833d2cce4d0000         +cmp dword ptr [0x4dce2c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5099052) /* 0x4dce2c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aa96b  7538                   -jne 0x4aa9a5
    if (!cpu.flags.zf)
    {
        goto L_0x004aa9a5;
    }
    // 004aa96d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004aa96e  b90000803f             -mov ecx, 0x3f800000
    cpu.ecx = 1065353216 /*0x3f800000*/;
    // 004aa973  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004aa978  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 004aa97d  890d90445b00           -mov dword ptr [0x5b4490], ecx
    app->getMemory<x86::reg32>(x86::reg32(5981328) /* 0x5b4490 */) = cpu.ecx;
    // 004aa983  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004aa984:
    // 004aa984  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004aa987  db0424                 -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 004aa98a  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 004aa98c  def1                   -fdivrp st(1)
    cpu.fpu.st(1) = cpu.fpu.st(0) / x86::Float(cpu.fpu.st(1));
    cpu.fpu.pop();
    // 004aa98e  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004aa991  40                     -inc eax
    (cpu.eax)++;
    // 004aa992  d99a8c445b00           -fstp dword ptr [edx + 0x5b448c]
    app->getMemory<float>(cpu.edx + x86::reg32(5981324) /* 0x5b448c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004aa998  3d00040000             +cmp eax, 0x400
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1024 /*0x400*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aa99d  7ce5                   -jl 0x4aa984
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004aa984;
    }
    // 004aa99f  ff052cce4d00           -inc dword ptr [0x4dce2c]
    (app->getMemory<x86::reg32>(x86::reg32(5099052) /* 0x4dce2c */))++;
L_0x004aa9a5:
    // 004aa9a5  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004aa9a8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aa9a9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4aa9b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aa9b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004aa9b1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004aa9b2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004aa9b3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004aa9b4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004aa9b5  8b3560605b00           -mov esi, dword ptr [0x5b6060]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5988448) /* 0x5b6060 */);
    // 004aa9bb  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004aa9bd  e89ea8ffff             -call 0x4a5260
    cpu.esp -= 4;
    sub_4a5260(app, cpu);
    if (cpu.terminate) return;
    // 004aa9c2  8b1d64605b00           -mov ebx, dword ptr [0x5b6064]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5988452) /* 0x5b6064 */);
    // 004aa9c8  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004aa9ca  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004aa9cc  39d8                   +cmp eax, ebx
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
    // 004aa9ce  7554                   -jne 0x4aaa24
    if (!cpu.flags.zf)
    {
        goto L_0x004aaa24;
    }
    // 004aa9d0  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004aa9d3  8b3560605b00           -mov esi, dword ptr [0x5b6060]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5988448) /* 0x5b6060 */);
    // 004aa9d9  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004aa9dc  39f2                   +cmp edx, esi
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
    // 004aa9de  7e38                   -jle 0x4aaa18
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004aaa18;
    }
    // 004aa9e0  0fafc6                 -imul eax, esi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 004aa9e3  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004aa9e5  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
L_0x004aa9e7:
    // 004aa9e7  8d149d00000000         -lea edx, [ebx*4]
    cpu.edx = x86::reg32(cpu.ebx * 4);
    // 004aa9ee  81c290545b00           -add edx, 0x5b5490
    (cpu.edx) += x86::reg32(x86::sreg32(5985424 /*0x5b5490*/));
    // 004aa9f4  39f3                   +cmp ebx, esi
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
    // 004aa9f6  7d20                   -jge 0x4aaa18
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004aaa18;
    }
L_0x004aa9f8:
    // 004aa9f8  83c210                 -add edx, 0x10
    (cpu.edx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004aa9fb  8942f0                 -mov dword ptr [edx - 0x10], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 004aa9fe  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004aaa00  8942f4                 -mov dword ptr [edx - 0xc], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 004aaa03  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004aaa05  8942f8                 -mov dword ptr [edx - 8], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 004aaa08  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004aaa0a  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004aaa0d  8942fc                 -mov dword ptr [edx - 4], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004aaa10  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004aaa12  39f3                   +cmp ebx, esi
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
    // 004aaa14  7ce2                   -jl 0x4aa9f8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004aa9f8;
    }
    // 004aaa16  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_0x004aaa18:
    // 004aaa18  893560605b00           -mov dword ptr [0x5b6060], esi
    app->getMemory<x86::reg32>(x86::reg32(5988448) /* 0x5b6060 */) = cpu.esi;
    // 004aaa1e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aaa1f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aaa20  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aaa21  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aaa22  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aaa23  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004aaa24:
    // 004aaa24  893d64605b00           -mov dword ptr [0x5b6064], edi
    app->getMemory<x86::reg32>(x86::reg32(5988452) /* 0x5b6064 */) = cpu.edi;
    // 004aaa2a  8b7204                 -mov esi, dword ptr [edx + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004aaa2d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004aaa2f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004aaa31  c1fe10                 +sar esi, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.esi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 004aaa34  ebb1                   -jmp 0x4aa9e7
    goto L_0x004aa9e7;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4aaa40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aaa40  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004aaa41  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004aaa42  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004aaa45  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004aaa47  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004aaa49  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004aaa4b  c1e918                 -shr ecx, 0x18
    cpu.ecx >>= 24 /*0x18*/ % 32;
    // 004aaa4e  81e1ff000000           +and ecx, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004aaa54  0f8444010000           -je 0x4aab9e
    if (cpu.flags.zf)
    {
        goto L_0x004aab9e;
    }
    // 004aaa5a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004aaa5b  81f9ff000000           +cmp ecx, 0xff
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
    // 004aaa61  0f84f1000000           -je 0x4aab58
    if (cpu.flags.zf)
    {
        goto L_0x004aab58;
    }
    // 004aaa67  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004aaa68  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004aaa69  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004aaa6b  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 004aaa6e  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004aaa73  09d9                   -or ecx, ebx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004aaa75  bb00000100             -mov ebx, 0x10000
    cpu.ebx = 65536 /*0x10000*/;
    // 004aaa7a  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004aaa7e  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004aaa80  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004aaa82  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004aaa84  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004aaa86  8a4500                 -mov al, byte ptr [ebp]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp);
    // 004aaa89  c1eb10                 -shr ebx, 0x10
    cpu.ebx >>= 16 /*0x10*/ % 32;
    // 004aaa8c  8b3485a0ea5600         -mov esi, dword ptr [eax*4 + 0x56eaa0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5696160) /* 0x56eaa0 */ + cpu.eax * 4);
    // 004aaa93  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004aaa99  8b3c85a0ea5600         -mov edi, dword ptr [eax*4 + 0x56eaa0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5696160) /* 0x56eaa0 */ + cpu.eax * 4);
    // 004aaaa0  895c2414               -mov dword ptr [esp + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 004aaaa4  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004aaaa6  c1ee10                 -shr esi, 0x10
    cpu.esi >>= 16 /*0x10*/ % 32;
    // 004aaaa9  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 004aaaac  81e6ff000000           -and esi, 0xff
    cpu.esi &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004aaab2  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004aaab8  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004aaaba  895c2418               -mov dword ptr [esp + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 004aaabe  8b1c85a0ea5600         -mov ebx, dword ptr [eax*4 + 0x56eaa0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5696160) /* 0x56eaa0 */ + cpu.eax * 4);
    // 004aaac5  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004aaac7  81e7ff000000           -and edi, 0xff
    cpu.edi &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004aaacd  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004aaacf  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004aaad2  c1e810                 +shr eax, 0x10
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
    // 004aaad5  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004aaad7  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004aaadb  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 004aaade  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004aaae0  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004aaae6  3dff000000             +cmp eax, 0xff
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aaaeb  0f86b3000000           -jbe 0x4aaba4
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004aaba4;
    }
    // 004aaaf1  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
L_0x004aaaf6:
    // 004aaaf6  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004aaaf8  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004aaafa  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004aaafc  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004aaafe  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004aab01  c1e810                 +shr eax, 0x10
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
    // 004aab04  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004aab06  03442418               -add eax, dword ptr [esp + 0x18]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */)));
    // 004aab0a  3dff000000             +cmp eax, 0xff
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aab0f  0f86a8000000           -jbe 0x4aabbd
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004aabbd;
    }
    // 004aab15  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
L_0x004aab1a:
    // 004aab1a  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004aab1e  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004aab20  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004aab22  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004aab24  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004aab27  c1e810                 +shr eax, 0x10
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
    // 004aab2a  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004aab2c  03442410               -add eax, dword ptr [esp + 0x10]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */)));
    // 004aab30  3dff000000             +cmp eax, 0xff
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(255 /*0xff*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aab35  0f869b000000           -jbe 0x4aabd6
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004aabd6;
    }
    // 004aab3b  b8ff000000             -mov eax, 0xff
    cpu.eax = 255 /*0xff*/;
L_0x004aab40:
    // 004aab40  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004aab42  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004aab46  c1e310                 -shl ebx, 0x10
    cpu.ebx <<= 16 /*0x10*/ % 32;
    // 004aab49  c1e108                 -shl ecx, 8
    cpu.ecx <<= 8 /*0x8*/ % 32;
    // 004aab4c  81cb000000ff           -or ebx, 0xff000000
    cpu.ebx |= x86::reg32(x86::sreg32(4278190080 /*0xff000000*/));
    // 004aab52  09d9                   -or ecx, ebx
    cpu.ecx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004aab54  09c8                   -or eax, ecx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ecx));
    // 004aab56  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aab57  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004aab58:
    // 004aab58  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004aab5a  8b0d7c8a4d00           -mov ecx, dword ptr [0x4d8a7c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5081724) /* 0x4d8a7c */);
    // 004aab60  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004aab62  7427                   -je 0x4aab8b
    if (cpu.flags.zf)
    {
        goto L_0x004aab8b;
    }
    // 004aab64  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004aab66  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 004aab6c  c1eb09                 -shr ebx, 9
    cpu.ebx >>= 9 /*0x9*/ % 32;
    // 004aab6f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004aab71  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004aab74  81e200f80000           -and edx, 0xf800
    cpu.edx &= x86::reg32(x86::sreg32(63488 /*0xf800*/));
    // 004aab7a  c1ea06                 -shr edx, 6
    cpu.edx >>= 6 /*0x6*/ % 32;
    // 004aab7d  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004aab80  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004aab82  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004aab84  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 004aab86  8a1c01                 -mov bl, byte ptr [ecx + eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.ecx + cpu.eax * 1);
    // 004aab89  eb0f                   -jmp 0x4aab9a
    goto L_0x004aab9a;
L_0x004aab8b:
    // 004aab8b  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004aab8d  8d05a0ea5600           -lea eax, [0x56eaa0]
    cpu.eax = x86::reg32(x86::reg32(5696160) /* 0x56eaa0 */);
    // 004aab93  e8a85efdff             -call 0x480a40
    cpu.esp -= 4;
    sub_480a40(app, cpu);
    if (cpu.terminate) return;
    // 004aab98  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x004aab9a:
    // 004aab9a  885d00                 -mov byte ptr [ebp], bl
    app->getMemory<x86::reg8>(cpu.ebp) = cpu.bl;
    // 004aab9d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004aab9e:
    // 004aab9e  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004aaba1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aaba2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aaba3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004aaba4:
    // 004aaba4  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004aaba6  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004aaba8  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004aabac  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004aabae  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004aabb1  c1e810                 +shr eax, 0x10
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
    // 004aabb4  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004aabb6  01f0                   +add eax, esi
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004aabb8  e939ffffff             -jmp 0x4aaaf6
    goto L_0x004aaaf6;
L_0x004aabbd:
    // 004aabbd  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004aabbf  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004aabc1  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004aabc5  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004aabc7  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004aabca  c1e810                 +shr eax, 0x10
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
    // 004aabcd  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004aabcf  01d8                   +add eax, ebx
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004aabd1  e944ffffff             -jmp 0x4aab1a
    goto L_0x004aab1a;
L_0x004aabd6:
    // 004aabd6  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004aabd8  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004aabda  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004aabde  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004aabe0  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004aabe3  c1e810                 +shr eax, 0x10
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
    // 004aabe6  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004aabe8  01c8                   +add eax, ecx
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
    // 004aabea  e951ffffff             -jmp 0x4aab40
    goto L_0x004aab40;
}

/* align: skip 0x90 */
void Application::sub_4aabf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aabf0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004aabf1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004aabf2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004aabf3  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004aabf6  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004aabf9  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004aabfb  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004aabfd  894c2418               -mov dword ptr [esp + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 004aac01  837c243c00             +cmp dword ptr [esp + 0x3c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aac06  7f09                   -jg 0x4aac11
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004aac11;
    }
    // 004aac08  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004aac0b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aac0c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aac0d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aac0e  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x004aac11:
    // 004aac11  8b5c2438               -mov ebx, dword ptr [esp + 0x38]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 004aac15  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004aac19  0fb63578904d00         -movzx esi, byte ptr [0x4d9078]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(x86::reg32(5083256) /* 0x4d9078 */));
    // 004aac20  8b158c904d00           -mov edx, dword ptr [0x4d908c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5083276) /* 0x4d908c */);
    // 004aac26  8b0482                 -mov eax, dword ptr [edx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 004aac29  8b1588904d00           -mov edx, dword ptr [0x4d9088]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5083272) /* 0x4d9088 */);
    // 004aac2f  03049a                 -add eax, dword ptr [edx + ebx*4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + cpu.ebx * 4)));
    // 004aac32  03057c904d00           -add eax, dword ptr [0x4d907c]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5083260) /* 0x4d907c */)));
    // 004aac38  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004aac3c  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004aac3f  8b4002                 -mov eax, dword ptr [eax + 2]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 004aac42  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004aac45  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004aac48  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004aac4c  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004aac4f  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004aac52  83fe10                 +cmp esi, 0x10
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
    // 004aac55  0f85e9000000           -jne 0x4aad44
    if (!cpu.flags.zf)
    {
        goto L_0x004aad44;
    }
    // 004aac5b  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x004aac5f:
    // 004aac5f  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004aac63  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004aac67  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 004aac69  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004aac6b  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 004aac6e  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004aac71  8b1cb590545b00         -mov ebx, dword ptr [esi*4 + 0x5b5490]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5985424) /* 0x5b5490 */ + cpu.esi * 4);
    // 004aac78  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004aac7b  8d341a                 -lea esi, [edx + ebx]
    cpu.esi = x86::reg32(cpu.edx + cpu.ebx * 1);
    // 004aac7e  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004aac80  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004aac82  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004aac84  c1ea0d                 -shr edx, 0xd
    cpu.edx >>= 13 /*0xd*/ % 32;
    // 004aac87  81e300e00000           -and ebx, 0xe000
    cpu.ebx &= x86::reg32(x86::sreg32(57344 /*0xe000*/));
    // 004aac8d  c1eb0a                 -shr ebx, 0xa
    cpu.ebx >>= 10 /*0xa*/ % 32;
    // 004aac90  83e207                 -and edx, 7
    cpu.edx &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004aac93  09da                   -or edx, ebx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004aac95  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004aac97  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004aac99  ff149570e54d00         -call dword ptr [edx*4 + 0x4de570]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5105008) /* 0x4de570 */ + cpu.edx * 4);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004aaca0  8b74241c               -mov esi, dword ptr [esp + 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004aaca4  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004aaca6  81fb00000010           +cmp ebx, 0x10000000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(268435456 /*0x10000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aacac  726b                   -jb 0x4aad19
    if (cpu.flags.cf)
    {
        goto L_0x004aad19;
    }
    // 004aacae  81fb000000fc           +cmp ebx, 0xfc000000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4227858432 /*0xfc000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aacb4  7340                   -jae 0x4aacf6
    if (!cpu.flags.cf)
    {
        goto L_0x004aacf6;
    }
    // 004aacb6  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 004aacb9  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004aacbb  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004aacbd  83f1ff                 -xor ecx, 0xffffffff
    cpu.ecx ^= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 004aacc0  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004aacc3  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 004aacc5  81e2e0070000           -and edx, 0x7e0
    cpu.edx &= x86::reg32(x86::sreg32(2016 /*0x7e0*/));
    // 004aaccb  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004aacce  251f0000f8             -and eax, 0xf800001f
    cpu.eax &= x86::reg32(x86::sreg32(4160749599 /*0xf800001f*/));
    // 004aacd3  c1e918                 -shr ecx, 0x18
    cpu.ecx >>= 24 /*0x18*/ % 32;
    // 004aacd6  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004aacd8  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 004aacda  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004aacdd  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004aacdf  c1e905                 -shr ecx, 5
    cpu.ecx >>= 5 /*0x5*/ % 32;
    // 004aace2  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004aace4  c1e80b                 -shr eax, 0xb
    cpu.eax >>= 11 /*0xb*/ % 32;
    // 004aace7  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004aaced  2500ff0000             -and eax, 0xff00
    cpu.eax &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 004aacf2  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004aacf4  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x004aacf6:
    // 004aacf6  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004aacf8  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 004aacfe  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 004aad01  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004aad03  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004aad06  81e200fc0000           -and edx, 0xfc00
    cpu.edx &= x86::reg32(x86::sreg32(64512 /*0xfc00*/));
    // 004aad0c  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 004aad0f  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004aad12  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004aad14  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004aad16  66891e                 -mov word ptr [esi], bx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.bx;
L_0x004aad19:
    // 004aad19  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 004aad1c  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004aad20  8b54243c               -mov edx, dword ptr [esp + 0x3c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 004aad24  8974241c               -mov dword ptr [esp + 0x1c], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.esi;
    // 004aad28  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004aad2c  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004aad2e  01f5                   +add ebp, esi
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004aad30  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004aad31  8954243c               -mov dword ptr [esp + 0x3c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.edx;
    // 004aad35  0f8524ffffff           -jne 0x4aac5f
    if (!cpu.flags.zf)
    {
        goto L_0x004aac5f;
    }
    // 004aad3b  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004aad3e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aad3f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aad40  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aad41  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x004aad44:
    // 004aad44  83fe0f                 +cmp esi, 0xf
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(15 /*0xf*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aad47  0f85f1000000           -jne 0x4aae3e
    if (!cpu.flags.zf)
    {
        goto L_0x004aae3e;
    }
    // 004aad4d  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x004aad51:
    // 004aad51  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004aad55  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004aad59  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 004aad5b  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004aad5d  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 004aad60  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004aad63  8b1cb590545b00         -mov ebx, dword ptr [esi*4 + 0x5b5490]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5985424) /* 0x5b5490 */ + cpu.esi * 4);
    // 004aad6a  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004aad6d  8d341a                 -lea esi, [edx + ebx]
    cpu.esi = x86::reg32(cpu.edx + cpu.ebx * 1);
    // 004aad70  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004aad72  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004aad74  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004aad76  c1ea0d                 -shr edx, 0xd
    cpu.edx >>= 13 /*0xd*/ % 32;
    // 004aad79  81e300e00000           -and ebx, 0xe000
    cpu.ebx &= x86::reg32(x86::sreg32(57344 /*0xe000*/));
    // 004aad7f  c1eb0a                 -shr ebx, 0xa
    cpu.ebx >>= 10 /*0xa*/ % 32;
    // 004aad82  83e207                 -and edx, 7
    cpu.edx &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004aad85  09da                   -or edx, ebx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004aad87  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004aad89  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004aad8b  ff149570e54d00         -call dword ptr [edx*4 + 0x4de570]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5105008) /* 0x4de570 */ + cpu.edx * 4);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004aad92  8b74241c               -mov esi, dword ptr [esp + 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004aad96  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004aad98  81fb00000010           +cmp ebx, 0x10000000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(268435456 /*0x10000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aad9e  7273                   -jb 0x4aae13
    if (cpu.flags.cf)
    {
        goto L_0x004aae13;
    }
    // 004aada0  81fb000000fc           +cmp ebx, 0xfc000000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4227858432 /*0xfc000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aada6  7348                   -jae 0x4aadf0
    if (!cpu.flags.cf)
    {
        goto L_0x004aadf0;
    }
    // 004aada8  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 004aadab  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004aadad  25007c0000             -and eax, 0x7c00
    cpu.eax &= x86::reg32(x86::sreg32(31744 /*0x7c00*/));
    // 004aadb2  c1e011                 -shl eax, 0x11
    cpu.eax <<= 17 /*0x11*/ % 32;
    // 004aadb5  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004aadb7  81e2e0030000           -and edx, 0x3e0
    cpu.edx &= x86::reg32(x86::sreg32(992 /*0x3e0*/));
    // 004aadbd  c1e209                 -shl edx, 9
    cpu.edx <<= 9 /*0x9*/ % 32;
    // 004aadc0  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004aadc2  83e11f                 -and ecx, 0x1f
    cpu.ecx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004aadc5  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004aadc7  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004aadc9  c1e918                 -shr ecx, 0x18
    cpu.ecx >>= 24 /*0x18*/ % 32;
    // 004aadcc  81f1ff000000           -xor ecx, 0xff
    cpu.ecx ^= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004aadd2  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 004aadd4  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004aadd7  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004aadd9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004aaddb  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 004aadde  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004aade4  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004aade6  c1e80b                 -shr eax, 0xb
    cpu.eax >>= 11 /*0xb*/ % 32;
    // 004aade9  2500ff0000             -and eax, 0xff00
    cpu.eax &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 004aadee  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x004aadf0:
    // 004aadf0  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004aadf2  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 004aadf8  c1eb09                 -shr ebx, 9
    cpu.ebx >>= 9 /*0x9*/ % 32;
    // 004aadfb  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004aadfd  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004aae00  81e200f80000           -and edx, 0xf800
    cpu.edx &= x86::reg32(x86::sreg32(63488 /*0xf800*/));
    // 004aae06  c1ea06                 -shr edx, 6
    cpu.edx >>= 6 /*0x6*/ % 32;
    // 004aae09  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004aae0c  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004aae0e  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004aae10  66891e                 -mov word ptr [esi], bx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.bx;
L_0x004aae13:
    // 004aae13  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 004aae16  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004aae1a  8b54243c               -mov edx, dword ptr [esp + 0x3c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 004aae1e  8974241c               -mov dword ptr [esp + 0x1c], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.esi;
    // 004aae22  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004aae26  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004aae28  01f5                   +add ebp, esi
    {
        x86::reg32& tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004aae2a  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004aae2b  8954243c               -mov dword ptr [esp + 0x3c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.edx;
    // 004aae2f  0f851cffffff           -jne 0x4aad51
    if (!cpu.flags.zf)
    {
        goto L_0x004aad51;
    }
    // 004aae35  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004aae38  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aae39  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aae3a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aae3b  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x004aae3e:
    // 004aae3e  83fe08                 +cmp esi, 8
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
    // 004aae41  7579                   -jne 0x4aaebc
    if (!cpu.flags.zf)
    {
        goto L_0x004aaebc;
    }
    // 004aae43  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
L_0x004aae47:
    // 004aae47  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004aae4b  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
    // 004aae4d  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004aae4f  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004aae51  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004aae54  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 004aae57  8b0c8590545b00         -mov ecx, dword ptr [eax*4 + 0x5b5490]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5985424) /* 0x5b5490 */ + cpu.eax * 4);
    // 004aae5e  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 004aae61  8d040a                 -lea eax, [edx + ecx]
    cpu.eax = x86::reg32(cpu.edx + cpu.ecx * 1);
    // 004aae64  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004aae68  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004aae6a  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004aae6c  c1ea0d                 -shr edx, 0xd
    cpu.edx >>= 13 /*0xd*/ % 32;
    // 004aae6f  81e300e00000           -and ebx, 0xe000
    cpu.ebx &= x86::reg32(x86::sreg32(57344 /*0xe000*/));
    // 004aae75  c1eb0a                 -shr ebx, 0xa
    cpu.ebx >>= 10 /*0xa*/ % 32;
    // 004aae78  83e207                 -and edx, 7
    cpu.edx &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004aae7b  09da                   -or edx, ebx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004aae7d  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004aae7f  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004aae81  ff149570e54d00         -call dword ptr [edx*4 + 0x4de570]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5105008) /* 0x4de570 */ + cpu.edx * 4);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004aae88  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004aae8c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004aae8e  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004aae92  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004aae96  e8a5fbffff             -call 0x4aaa40
    cpu.esp -= 4;
    sub_4aaa40(app, cpu);
    if (cpu.terminate) return;
    // 004aae9b  43                     -inc ebx
    (cpu.ebx)++;
    // 004aae9c  01f5                   -add ebp, esi
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.esi));
    // 004aae9e  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004aaea2  8b54243c               -mov edx, dword ptr [esp + 0x3c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 004aaea6  895c241c               -mov dword ptr [esp + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 004aaeaa  01c7                   +add edi, eax
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
    // 004aaeac  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004aaead  8954243c               -mov dword ptr [esp + 0x3c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.edx;
    // 004aaeb1  7594                   -jne 0x4aae47
    if (!cpu.flags.zf)
    {
        goto L_0x004aae47;
    }
    // 004aaeb3  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004aaeb6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aaeb7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aaeb8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aaeb9  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x004aaebc:
    // 004aaebc  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
L_0x004aaec0:
    // 004aaec0  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004aaec4  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
    // 004aaec6  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004aaec8  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004aaeca  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004aaecd  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 004aaed0  8b0c8590545b00         -mov ecx, dword ptr [eax*4 + 0x5b5490]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5985424) /* 0x5b5490 */ + cpu.eax * 4);
    // 004aaed7  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 004aaede  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004aaee0  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004aaee4  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004aaee6  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004aaee8  c1ea0d                 -shr edx, 0xd
    cpu.edx >>= 13 /*0xd*/ % 32;
    // 004aaeeb  81e300e00000           -and ebx, 0xe000
    cpu.ebx &= x86::reg32(x86::sreg32(57344 /*0xe000*/));
    // 004aaef1  c1eb0a                 -shr ebx, 0xa
    cpu.ebx >>= 10 /*0xa*/ % 32;
    // 004aaef4  83e207                 -and edx, 7
    cpu.edx &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004aaef7  09da                   -or edx, ebx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004aaef9  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004aaefb  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004aaefd  ff149570e54d00         -call dword ptr [edx*4 + 0x4de570]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5105008) /* 0x4de570 */ + cpu.edx * 4);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004aaf04  8b542438               -mov edx, dword ptr [esp + 0x38]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 004aaf08  8b74241c               -mov esi, dword ptr [esp + 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004aaf0c  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004aaf0e  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004aaf12  8b4c243c               -mov ecx, dword ptr [esp + 0x3c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 004aaf16  e825700000             -call 0x4b1f40
    cpu.esp -= 4;
    sub_4b1f40(app, cpu);
    if (cpu.terminate) return;
    // 004aaf1b  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004aaf1e  8b5c2434               -mov ebx, dword ptr [esp + 0x34]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004aaf22  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004aaf26  8b542430               -mov edx, dword ptr [esp + 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004aaf2a  8974241c               -mov dword ptr [esp + 0x1c], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.esi;
    // 004aaf2e  43                     -inc ebx
    (cpu.ebx)++;
    // 004aaf2f  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 004aaf31  01d7                   +add edi, edx
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004aaf33  895c2434               -mov dword ptr [esp + 0x34], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.ebx;
    // 004aaf37  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004aaf38  894c243c               -mov dword ptr [esp + 0x3c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.ecx;
    // 004aaf3c  7582                   -jne 0x4aaec0
    if (!cpu.flags.zf)
    {
        goto L_0x004aaec0;
    }
    // 004aaf3e  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004aaf41  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aaf42  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aaf43  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aaf44  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x90 */
void Application::sub_4aaf48(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004aaf48  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004aaf49  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004aaf4a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004aaf4b  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004aaf4e  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004aaf52  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004aaf54  895c241c               -mov dword ptr [esp + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 004aaf58  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004aaf5c  837c243c00             +cmp dword ptr [esp + 0x3c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aaf61  7f09                   -jg 0x4aaf6c
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004aaf6c;
    }
    // 004aaf63  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004aaf66  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aaf67  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aaf68  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004aaf69  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x004aaf6c:
    // 004aaf6c  8b5c2438               -mov ebx, dword ptr [esp + 0x38]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 004aaf70  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004aaf72  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004aaf76  8a0d78904d00           -mov cl, byte ptr [0x4d9078]
    cpu.cl = app->getMemory<x86::reg8>(x86::reg32(5083256) /* 0x4d9078 */);
    // 004aaf7c  8b158c904d00           -mov edx, dword ptr [0x4d908c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5083276) /* 0x4d908c */);
    // 004aaf82  8b0482                 -mov eax, dword ptr [edx + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + cpu.eax * 4);
    // 004aaf85  8b1588904d00           -mov edx, dword ptr [0x4d9088]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5083272) /* 0x4d9088 */);
    // 004aaf8b  03049a                 -add eax, dword ptr [edx + ebx*4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + cpu.ebx * 4)));
    // 004aaf8e  03057c904d00           -add eax, dword ptr [0x4d907c]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5083260) /* 0x4d907c */)));
    // 004aaf94  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004aaf98  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004aaf9c  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004aaf9f  83f908                 +cmp ecx, 8
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004aafa2  0f8598000000           -jne 0x4ab040
    if (!cpu.flags.zf)
    {
        goto L_0x004ab040;
    }
    // 004aafa8  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
L_0x004aafab:
    // 004aafab  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004aafaf  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004aafb3  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004aafb6  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 004aafb9  8b3c8590545b00         -mov edi, dword ptr [eax*4 + 0x5b5490]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5985424) /* 0x5b5490 */ + cpu.eax * 4);
    // 004aafc0  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004aafc4  8d043e                 -lea eax, [esi + edi]
    cpu.eax = x86::reg32(cpu.esi + cpu.edi * 1);
    // 004aafc7  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004aafc9  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
    // 004aafcb  8b4902                 -mov ecx, dword ptr [ecx + 2]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 004aafce  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 004aafd1  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004aafd4  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004aafd6  c1ea0d                 -shr edx, 0xd
    cpu.edx >>= 13 /*0xd*/ % 32;
    // 004aafd9  81e300e00000           -and ebx, 0xe000
    cpu.ebx &= x86::reg32(x86::sreg32(57344 /*0xe000*/));
    // 004aafdf  c1eb0a                 -shr ebx, 0xa
    cpu.ebx >>= 10 /*0xa*/ % 32;
    // 004aafe2  83e207                 -and edx, 7
    cpu.edx &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004aafe5  8b3d30ce4d00           -mov edi, dword ptr [0x4dce30]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5099056) /* 0x4dce30 */);
    // 004aafeb  09da                   -or edx, ebx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004aafed  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004aafef  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004aaff1  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004aaff6  8b0487                 -mov eax, dword ptr [edi + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + cpu.eax * 4);
    // 004aaff9  ff149570e64d00         -call dword ptr [edx*4 + 0x4de670]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5105264) /* 0x4de670 */ + cpu.edx * 4);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ab000  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004ab004  8d5101                 -lea edx, [ecx + 1]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 004ab007  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004ab00b  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004ab00f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004ab011  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004ab013  8b74243c               -mov esi, dword ptr [esp + 0x3c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 004ab017  e824faffff             -call 0x4aaa40
    cpu.esp -= 4;
    sub_4aaa40(app, cpu);
    if (cpu.terminate) return;
    // 004ab01c  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004ab020  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004ab024  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ab026  01cd                   +add ebp, ecx
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
    // 004ab028  895c241c               -mov dword ptr [esp + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 004ab02c  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004ab02d  8974243c               -mov dword ptr [esp + 0x3c], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.esi;
    // 004ab031  0f8574ffffff           -jne 0x4aafab
    if (!cpu.flags.zf)
    {
        goto L_0x004aafab;
    }
    // 004ab037  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004ab03a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab03b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab03c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab03d  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x004ab040:
    // 004ab040  83f910                 +cmp ecx, 0x10
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
    // 004ab043  0f8505010000           -jne 0x4ab14e
    if (!cpu.flags.zf)
    {
        goto L_0x004ab14e;
    }
    // 004ab049  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x004ab04d:
    // 004ab04d  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004ab051  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004ab055  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004ab059  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004ab05d  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004ab05f  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004ab062  8b4902                 -mov ecx, dword ptr [ecx + 2]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 004ab065  8b3c8590545b00         -mov edi, dword ptr [eax*4 + 0x5b5490]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5985424) /* 0x5b5490 */ + cpu.eax * 4);
    // 004ab06c  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004ab06e  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 004ab070  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004ab073  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004ab076  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004ab078  c1ea0d                 -shr edx, 0xd
    cpu.edx >>= 13 /*0xd*/ % 32;
    // 004ab07b  81e300e00000           -and ebx, 0xe000
    cpu.ebx &= x86::reg32(x86::sreg32(57344 /*0xe000*/));
    // 004ab081  c1eb0a                 -shr ebx, 0xa
    cpu.ebx >>= 10 /*0xa*/ % 32;
    // 004ab084  83e207                 -and edx, 7
    cpu.edx &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004ab087  8b3d30ce4d00           -mov edi, dword ptr [0x4dce30]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5099056) /* 0x4dce30 */);
    // 004ab08d  09da                   -or edx, ebx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab08f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004ab091  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004ab093  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab098  8b0487                 -mov eax, dword ptr [edi + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + cpu.eax * 4);
    // 004ab09b  ff149570e64d00         -call dword ptr [edx*4 + 0x4de670]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5105264) /* 0x4de670 */ + cpu.edx * 4);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ab0a2  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004ab0a6  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ab0a8  81fb00000010           +cmp ebx, 0x10000000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(268435456 /*0x10000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ab0ae  726b                   -jb 0x4ab11b
    if (cpu.flags.cf)
    {
        goto L_0x004ab11b;
    }
    // 004ab0b0  81fb000000fc           +cmp ebx, 0xfc000000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4227858432 /*0xfc000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ab0b6  7340                   -jae 0x4ab0f8
    if (!cpu.flags.cf)
    {
        goto L_0x004ab0f8;
    }
    // 004ab0b8  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 004ab0bb  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004ab0bd  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004ab0bf  83f1ff                 -xor ecx, 0xffffffff
    cpu.ecx ^= x86::reg32(x86::sreg32(4294967295 /*0xffffffff*/));
    // 004ab0c2  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004ab0c5  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 004ab0c7  81e2e0070000           -and edx, 0x7e0
    cpu.edx &= x86::reg32(x86::sreg32(2016 /*0x7e0*/));
    // 004ab0cd  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004ab0d0  251f0000f8             -and eax, 0xf800001f
    cpu.eax &= x86::reg32(x86::sreg32(4160749599 /*0xf800001f*/));
    // 004ab0d5  c1e918                 -shr ecx, 0x18
    cpu.ecx >>= 24 /*0x18*/ % 32;
    // 004ab0d8  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004ab0da  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 004ab0dc  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004ab0df  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004ab0e1  c1e905                 -shr ecx, 5
    cpu.ecx >>= 5 /*0x5*/ % 32;
    // 004ab0e4  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004ab0e6  c1e80b                 -shr eax, 0xb
    cpu.eax >>= 11 /*0xb*/ % 32;
    // 004ab0e9  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab0ef  2500ff0000             -and eax, 0xff00
    cpu.eax &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 004ab0f4  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004ab0f6  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x004ab0f8:
    // 004ab0f8  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004ab0fa  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 004ab100  c1eb08                 -shr ebx, 8
    cpu.ebx >>= 8 /*0x8*/ % 32;
    // 004ab103  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004ab105  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004ab108  81e200fc0000           -and edx, 0xfc00
    cpu.edx &= x86::reg32(x86::sreg32(64512 /*0xfc00*/));
    // 004ab10e  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 004ab111  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004ab114  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ab116  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004ab118  66891e                 -mov word ptr [esi], bx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.bx;
L_0x004ab11b:
    // 004ab11b  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 004ab11e  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004ab122  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004ab126  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ab128  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004ab12c  8b4c243c               -mov ecx, dword ptr [esp + 0x3c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 004ab130  01c2                   +add edx, eax
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
    // 004ab132  89742418               -mov dword ptr [esp + 0x18], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 004ab136  8954241c               -mov dword ptr [esp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004ab13a  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004ab13b  894c243c               -mov dword ptr [esp + 0x3c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.ecx;
    // 004ab13f  0f8508ffffff           -jne 0x4ab04d
    if (!cpu.flags.zf)
    {
        goto L_0x004ab04d;
    }
    // 004ab145  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004ab148  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab149  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab14a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab14b  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x004ab14e:
    // 004ab14e  83f90f                 +cmp ecx, 0xf
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
    // 004ab151  0f850d010000           -jne 0x4ab264
    if (!cpu.flags.zf)
    {
        goto L_0x004ab264;
    }
    // 004ab157  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x004ab15b:
    // 004ab15b  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004ab15f  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004ab163  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004ab167  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004ab16b  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004ab16d  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004ab170  8b4902                 -mov ecx, dword ptr [ecx + 2]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 004ab173  8b3c8590545b00         -mov edi, dword ptr [eax*4 + 0x5b5490]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5985424) /* 0x5b5490 */ + cpu.eax * 4);
    // 004ab17a  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004ab17c  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 004ab17e  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004ab181  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004ab184  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004ab186  c1ea0d                 -shr edx, 0xd
    cpu.edx >>= 13 /*0xd*/ % 32;
    // 004ab189  81e300e00000           -and ebx, 0xe000
    cpu.ebx &= x86::reg32(x86::sreg32(57344 /*0xe000*/));
    // 004ab18f  c1eb0a                 -shr ebx, 0xa
    cpu.ebx >>= 10 /*0xa*/ % 32;
    // 004ab192  83e207                 -and edx, 7
    cpu.edx &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004ab195  8b3d30ce4d00           -mov edi, dword ptr [0x4dce30]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5099056) /* 0x4dce30 */);
    // 004ab19b  09da                   -or edx, ebx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab19d  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004ab19f  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004ab1a1  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab1a6  8b0487                 -mov eax, dword ptr [edi + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + cpu.eax * 4);
    // 004ab1a9  ff149570e64d00         -call dword ptr [edx*4 + 0x4de670]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5105264) /* 0x4de670 */ + cpu.edx * 4);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ab1b0  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004ab1b4  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ab1b6  81fb00000010           +cmp ebx, 0x10000000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(268435456 /*0x10000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ab1bc  7273                   -jb 0x4ab231
    if (cpu.flags.cf)
    {
        goto L_0x004ab231;
    }
    // 004ab1be  81fb000000fc           +cmp ebx, 0xfc000000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4227858432 /*0xfc000000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ab1c4  7348                   -jae 0x4ab20e
    if (!cpu.flags.cf)
    {
        goto L_0x004ab20e;
    }
    // 004ab1c6  668b06                 -mov ax, word ptr [esi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi);
    // 004ab1c9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004ab1cb  25007c0000             -and eax, 0x7c00
    cpu.eax &= x86::reg32(x86::sreg32(31744 /*0x7c00*/));
    // 004ab1d0  c1e011                 -shl eax, 0x11
    cpu.eax <<= 17 /*0x11*/ % 32;
    // 004ab1d3  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004ab1d5  81e2e0030000           -and edx, 0x3e0
    cpu.edx &= x86::reg32(x86::sreg32(992 /*0x3e0*/));
    // 004ab1db  c1e209                 -shl edx, 9
    cpu.edx <<= 9 /*0x9*/ % 32;
    // 004ab1de  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004ab1e0  83e11f                 -and ecx, 0x1f
    cpu.ecx &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004ab1e3  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004ab1e5  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004ab1e7  c1e918                 -shr ecx, 0x18
    cpu.ecx >>= 24 /*0x18*/ % 32;
    // 004ab1ea  81f1ff000000           -xor ecx, 0xff
    cpu.ecx ^= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab1f0  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 004ab1f2  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004ab1f5  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004ab1f7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004ab1f9  c1ea05                 -shr edx, 5
    cpu.edx >>= 5 /*0x5*/ % 32;
    // 004ab1fc  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab202  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004ab204  c1e80b                 -shr eax, 0xb
    cpu.eax >>= 11 /*0xb*/ % 32;
    // 004ab207  2500ff0000             -and eax, 0xff00
    cpu.eax &= x86::reg32(x86::sreg32(65280 /*0xff00*/));
    // 004ab20c  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
L_0x004ab20e:
    // 004ab20e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004ab210  81e30000f800           -and ebx, 0xf80000
    cpu.ebx &= x86::reg32(x86::sreg32(16252928 /*0xf80000*/));
    // 004ab216  c1eb09                 -shr ebx, 9
    cpu.ebx >>= 9 /*0x9*/ % 32;
    // 004ab219  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004ab21b  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004ab21e  81e200f80000           -and edx, 0xf800
    cpu.edx &= x86::reg32(x86::sreg32(63488 /*0xf800*/));
    // 004ab224  c1ea06                 -shr edx, 6
    cpu.edx >>= 6 /*0x6*/ % 32;
    // 004ab227  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004ab22a  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ab22c  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004ab22e  66891e                 -mov word ptr [esi], bx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.bx;
L_0x004ab231:
    // 004ab231  8d7602                 -lea esi, [esi + 2]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 004ab234  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004ab238  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004ab23c  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ab23e  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004ab242  8b4c243c               -mov ecx, dword ptr [esp + 0x3c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 004ab246  01c2                   +add edx, eax
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
    // 004ab248  89742418               -mov dword ptr [esp + 0x18], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 004ab24c  8954241c               -mov dword ptr [esp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004ab250  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004ab251  894c243c               -mov dword ptr [esp + 0x3c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.ecx;
    // 004ab255  0f8500ffffff           -jne 0x4ab15b
    if (!cpu.flags.zf)
    {
        goto L_0x004ab15b;
    }
    // 004ab25b  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004ab25e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab25f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab260  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab261  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x004ab264:
    // 004ab264  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
L_0x004ab268:
    // 004ab268  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004ab26c  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004ab270  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004ab273  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004ab277  8b1c8590545b00         -mov ebx, dword ptr [eax*4 + 0x5b5490]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5985424) /* 0x5b5490 */ + cpu.eax * 4);
    // 004ab27e  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004ab280  8d041e                 -lea eax, [esi + ebx]
    cpu.eax = x86::reg32(cpu.esi + cpu.ebx * 1);
    // 004ab283  8b4902                 -mov ecx, dword ptr [ecx + 2]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(2) /* 0x2 */);
    // 004ab286  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
    // 004ab288  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004ab28b  c1fe10                 -sar esi, 0x10
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (16 /*0x10*/ % 32));
    // 004ab28e  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004ab292  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004ab294  c1ea0d                 -shr edx, 0xd
    cpu.edx >>= 13 /*0xd*/ % 32;
    // 004ab297  81e300e00000           -and ebx, 0xe000
    cpu.ebx &= x86::reg32(x86::sreg32(57344 /*0xe000*/));
    // 004ab29d  c1eb0a                 -shr ebx, 0xa
    cpu.ebx >>= 10 /*0xa*/ % 32;
    // 004ab2a0  83e207                 -and edx, 7
    cpu.edx &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004ab2a3  8b3d30ce4d00           -mov edi, dword ptr [0x4dce30]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5099056) /* 0x4dce30 */);
    // 004ab2a9  09da                   -or edx, ebx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab2ab  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004ab2ad  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004ab2af  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ab2b4  8b0487                 -mov eax, dword ptr [edi + eax*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + cpu.eax * 4);
    // 004ab2b7  ff149570e64d00         -call dword ptr [edx*4 + 0x4de670]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5105264) /* 0x4de670 */ + cpu.edx * 4);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004ab2be  8b542438               -mov edx, dword ptr [esp + 0x38]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 004ab2c2  8b742434               -mov esi, dword ptr [esp + 0x34]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004ab2c6  8b7c2410               -mov edi, dword ptr [esp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004ab2ca  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ab2cc  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004ab2d0  8b4c243c               -mov ecx, dword ptr [esp + 0x3c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 004ab2d4  e8676c0000             -call 0x4b1f40
    cpu.esp -= 4;
    sub_4b1f40(app, cpu);
    if (cpu.terminate) return;
    // 004ab2d9  46                     -inc esi
    (cpu.esi)++;
    // 004ab2da  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004ab2de  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004ab2e2  01fd                   -add ebp, edi
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edi));
    // 004ab2e4  01c2                   +add edx, eax
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
    // 004ab2e6  89742434               -mov dword ptr [esp + 0x34], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.esi;
    // 004ab2ea  8954241c               -mov dword ptr [esp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004ab2ee  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004ab2ef  894c243c               -mov dword ptr [esp + 0x3c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.ecx;
    // 004ab2f3  0f856fffffff           -jne 0x4ab268
    if (!cpu.flags.zf)
    {
        goto L_0x004ab268;
    }
    // 004ab2f9  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004ab2fc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab2fd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab2fe  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab2ff  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4ab304(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab304  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ab305  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ab306  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ab307  83ec28                 -sub esp, 0x28
    (cpu.esp) -= x86::reg32(x86::sreg32(40 /*0x28*/));
    // 004ab30a  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 004ab30e  8954241c               -mov dword ptr [esp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004ab312  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004ab314  894c2424               -mov dword ptr [esp + 0x24], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ecx;
    // 004ab318  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004ab31a  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004ab31c  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 004ab31f  8a8074b54d00           -mov al, byte ptr [eax + 0x4db574]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5092724) /* 0x4db574 */);
    // 004ab325  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004ab329  83f820                 +cmp eax, 0x20
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
    // 004ab32c  0f85af010000           -jne 0x4ab4e1
    if (!cpu.flags.zf)
    {
        goto L_0x004ab4e1;
    }
L_0x004ab332:
    // 004ab332  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004ab336  8b4002                 -mov eax, dword ptr [eax + 2]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 004ab339  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004ab33c  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004ab340  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004ab344  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004ab348  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004ab34b  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004ab34e  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004ab351  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004ab355  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004ab358  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ab35a  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004ab35d  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004ab35f  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004ab361  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ab363  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ab365  0f8c91010000           -jl 0x4ab4fc
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ab4fc;
    }
L_0x004ab36b:
    // 004ab36b  837c242402             +cmp dword ptr [esp + 0x24], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ab370  7d08                   -jge 0x4ab37a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ab37a;
    }
    // 004ab372  c744242402000000       -mov dword ptr [esp + 0x24], 2
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = 2 /*0x2*/;
L_0x004ab37a:
    // 004ab37a  837c243802             +cmp dword ptr [esp + 0x38], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ab37f  7d08                   -jge 0x4ab389
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004ab389;
    }
    // 004ab381  c744243802000000       -mov dword ptr [esp + 0x38], 2
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = 2 /*0x2*/;
L_0x004ab389:
    // 004ab389  81fb8f020000           +cmp ebx, 0x28f
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(655 /*0x28f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ab38f  0f8e3b010000           -jle 0x4ab4d0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ab4d0;
    }
    // 004ab395  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004ab399  e812f6ffff             -call 0x4aa9b0
    cpu.esp -= 4;
    sub_4aa9b0(app, cpu);
    if (cpu.terminate) return;
    // 004ab39e  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004ab3a3  b800000000             -mov eax, 0
    cpu.eax = 0 /*0x0*/;
    // 004ab3a8  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004ab3aa  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004ab3ac  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004ab3af  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004ab3b1  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004ab3b3  8db00080ffff           -lea esi, [eax - 0x8000]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(-32768) /* -0x8000 */);
    // 004ab3b9  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004ab3bb  0f8c42010000           -jl 0x4ab503
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ab503;
    }
L_0x004ab3c1:
    // 004ab3c1  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004ab3c5  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004ab3c8  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004ab3ca  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004ab3cc  48                     -dec eax
    (cpu.eax)--;
    // 004ab3cd  4a                     -dec edx
    (cpu.edx)--;
    // 004ab3ce  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004ab3d1  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004ab3d4  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004ab3d6  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004ab3d8  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004ab3dc  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004ab3de  0f8c26010000           -jl 0x4ab50a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ab50a;
    }
L_0x004ab3e4:
    // 004ab3e4  8b742424               -mov esi, dword ptr [esp + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004ab3e8  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004ab3ea  4e                     -dec esi
    (cpu.esi)--;
    // 004ab3eb  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ab3ed  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004ab3f0  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004ab3f2  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004ab3f6  8b742438               -mov esi, dword ptr [esp + 0x38]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 004ab3fa  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004ab3fe  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab400  4e                     -dec esi
    (cpu.esi)--;
    // 004ab401  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004ab403  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004ab406  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004ab408  8b1568904d00           -mov edx, dword ptr [0x4d9068]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5083240) /* 0x4d9068 */);
    // 004ab40e  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004ab410  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004ab414  894c2414               -mov dword ptr [esp + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 004ab418  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab41a  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004ab41e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004ab420  7e1e                   -jle 0x4ab440
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ab440;
    }
    // 004ab422  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004ab426  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004ab429  8d2c13                 -lea ebp, [ebx + edx]
    cpu.ebp = x86::reg32(cpu.ebx + cpu.edx * 1);
    // 004ab42c  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004ab42e  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004ab432  896c241c               -mov dword ptr [esp + 0x1c], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ebp;
    // 004ab436  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004ab438  894c2414               -mov dword ptr [esp + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 004ab43c  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
L_0x004ab440:
    // 004ab440  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004ab444  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004ab448  8b0d70904d00           -mov ecx, dword ptr [0x4d9070]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5083248) /* 0x4d9070 */);
    // 004ab44e  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004ab450  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004ab452  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ab454  7e08                   -jle 0x4ab45e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ab45e;
    }
    // 004ab456  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004ab458  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004ab45a  895c2424               -mov dword ptr [esp + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
L_0x004ab45e:
    // 004ab45e  8b156c904d00           -mov edx, dword ptr [0x4d906c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5083244) /* 0x4d906c */);
    // 004ab464  29fa                   -sub edx, edi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004ab466  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004ab468  7e15                   -jle 0x4ab47f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ab47f;
    }
    // 004ab46a  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004ab46e  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004ab471  8b6c2438               -mov ebp, dword ptr [esp + 0x38]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 004ab475  29d5                   -sub ebp, edx
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004ab477  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 004ab479  896c2438               -mov dword ptr [esp + 0x38], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.ebp;
    // 004ab47d  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
L_0x004ab47f:
    // 004ab47f  8b442438               -mov eax, dword ptr [esp + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 004ab483  8b1574904d00           -mov edx, dword ptr [0x4d9074]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5083252) /* 0x4d9074 */);
    // 004ab489  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 004ab48b  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004ab48d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ab48f  7e04                   -jle 0x4ab495
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ab495;
    }
    // 004ab491  29442438               -sub dword ptr [esp + 0x38], eax
    (app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */)) -= x86::reg32(x86::sreg32(cpu.eax));
L_0x004ab495:
    // 004ab495  8b5c2438               -mov ebx, dword ptr [esp + 0x38]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 004ab499  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004ab49b  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004ab49d  7e31                   -jle 0x4ab4d0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ab4d0;
    }
L_0x004ab49f:
    // 004ab49f  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004ab4a3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004ab4a4  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004ab4a8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ab4a9  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004ab4ad  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004ab4af  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ab4b0  45                     -inc ebp
    (cpu.ebp)++;
    // 004ab4b1  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004ab4b5  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004ab4b7  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004ab4bb  47                     -inc edi
    (cpu.edi)++;
    // 004ab4bc  e82ff7ffff             -call 0x4aabf0
    cpu.esp -= 4;
    sub_4aabf0(app, cpu);
    if (cpu.terminate) return;
    // 004ab4c1  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004ab4c5  8b5c2438               -mov ebx, dword ptr [esp + 0x38]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 004ab4c9  01ce                   -add esi, ecx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004ab4cb  39dd                   +cmp ebp, ebx
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
    // 004ab4cd  7cd0                   -jl 0x4ab49f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004ab49f;
    }
    // 004ab4cf  90                     -nop 
    ;
L_0x004ab4d0:
    // 004ab4d0  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004ab4d4  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004ab4d6  7541                   -jne 0x4ab519
    if (!cpu.flags.zf)
    {
        goto L_0x004ab519;
    }
    // 004ab4d8  83c428                 +add esp, 0x28
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(40 /*0x28*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ab4db  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab4dc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab4dd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab4de  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004ab4e1:
    // 004ab4e1  ba20000000             -mov edx, 0x20
    cpu.edx = 32 /*0x20*/;
    // 004ab4e6  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004ab4ea  e8cd9efeff             -call 0x4953bc
    cpu.esp -= 4;
    sub_4953bc(app, cpu);
    if (cpu.terminate) return;
    // 004ab4ef  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004ab4f3  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 004ab4f7  e936feffff             -jmp 0x4ab332
    goto L_0x004ab332;
L_0x004ab4fc:
    // 004ab4fc  f7db                   +neg ebx
    {
        x86::reg32 tmp1 = 0;
        x86::reg32& tmp2 = cpu.ebx;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 004ab4fe  e968feffff             -jmp 0x4ab36b
    goto L_0x004ab36b;
L_0x004ab503:
    // 004ab503  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 004ab505  e9b7feffff             -jmp 0x4ab3c1
    goto L_0x004ab3c1;
L_0x004ab50a:
    // 004ab50a  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004ab50c  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ab50e  89742408               -mov dword ptr [esp + 8], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 004ab512  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004ab514  e9cbfeffff             -jmp 0x4ab3e4
    goto L_0x004ab3e4;
L_0x004ab519:
    // 004ab519  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004ab51b  e84c78fdff             -call 0x482d6c
    cpu.esp -= 4;
    sub_482d6c(app, cpu);
    if (cpu.terminate) return;
    // 004ab520  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 004ab523  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab524  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab525  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab526  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4ab530(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab530  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ab531  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ab532  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ab533  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004ab536  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004ab538  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004ab53c  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004ab53e  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 004ab540  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 004ab542  8b0f                   -mov ecx, dword ptr [edi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi);
    // 004ab544  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004ab546  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004ab54a  29d3                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004ab54c  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004ab54e  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 004ab54f  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004ab551  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004ab553  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ab555  0facd010               -shrd eax, edx, 0x10
    {
        x86::reg32& destination = cpu.eax;
        destination >>= (16 /*0x10*/ % 32);
        destination |= cpu.edx  << (32 - (16 /*0x10*/ % 32));
    }
    // 004ab559  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004ab55c  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004ab55e  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 004ab561  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004ab563  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004ab567  8b5f04                 -mov ebx, dword ptr [edi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 004ab56a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004ab56c  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 004ab56f  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004ab572  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ab574  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004ab577  e824d60000             -call 0x4b8ba0
    cpu.esp -= 4;
    sub_4b8ba0(app, cpu);
    if (cpu.terminate) return;
    // 004ab57c  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004ab580  894204                 -mov dword ptr [edx + 4], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004ab583  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004ab587  3b07                   +cmp eax, dword ptr [edi]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ab589  750a                   -jne 0x4ab595
    if (!cpu.flags.zf)
    {
        goto L_0x004ab595;
    }
    // 004ab58b  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004ab58e  8b5704                 -mov edx, dword ptr [edi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 004ab591  39d0                   +cmp eax, edx
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
    // 004ab593  744a                   -je 0x4ab5df
    if (cpu.flags.zf)
    {
        goto L_0x004ab5df;
    }
L_0x004ab595:
    // 004ab595  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004ab599  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004ab59d  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004ab59f  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004ab5a1  8b5d00                 -mov ebx, dword ptr [ebp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp);
    // 004ab5a4  39d8                   +cmp eax, ebx
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
    // 004ab5a6  743b                   -je 0x4ab5e3
    if (cpu.flags.zf)
    {
        goto L_0x004ab5e3;
    }
    // 004ab5a8  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004ab5aa  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004ab5ac  e8efd50000             -call 0x4b8ba0
    cpu.esp -= 4;
    sub_4b8ba0(app, cpu);
    if (cpu.terminate) return;
    // 004ab5b1  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
L_0x004ab5b5:
    // 004ab5b5  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004ab5b7  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004ab5ba  8b7d04                 -mov edi, dword ptr [ebp + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 004ab5bd  39f8                   +cmp eax, edi
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
    // 004ab5bf  742a                   -je 0x4ab5eb
    if (cpu.flags.zf)
    {
        goto L_0x004ab5eb;
    }
    // 004ab5c1  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004ab5c3  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004ab5c5  e8d6d50000             -call 0x4b8ba0
    cpu.esp -= 4;
    sub_4b8ba0(app, cpu);
    if (cpu.terminate) return;
    // 004ab5ca  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004ab5ce  894204                 -mov dword ptr [edx + 4], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004ab5d1  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004ab5d6:
    // 004ab5d6  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004ab5d9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab5da  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab5db  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab5dc  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x004ab5df:
    // 004ab5df  31d0                   +xor eax, edx
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004ab5e1  ebf3                   -jmp 0x4ab5d6
    goto L_0x004ab5d6;
L_0x004ab5e3:
    // 004ab5e3  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004ab5e7  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004ab5e9  ebca                   -jmp 0x4ab5b5
    goto L_0x004ab5b5;
L_0x004ab5eb:
    // 004ab5eb  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004ab5ef  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004ab5f2  894204                 -mov dword ptr [edx + 4], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004ab5f5  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004ab5fa  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004ab5fd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab5fe  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab5ff  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab600  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x90 */
void Application::sub_4ab604(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab604  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ab605  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ab606  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ab607  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004ab60a  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004ab60c  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004ab610  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004ab612  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 004ab614  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004ab617  8b4f04                 -mov ecx, dword ptr [edi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 004ab61a  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004ab61d  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004ab621  29d3                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004ab623  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004ab625  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 004ab626  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004ab628  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004ab62a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ab62c  0facd010               -shrd eax, edx, 0x10
    {
        x86::reg32& destination = cpu.eax;
        destination >>= (16 /*0x10*/ % 32);
        destination |= cpu.edx  << (32 - (16 /*0x10*/ % 32));
    }
    // 004ab630  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004ab633  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004ab635  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 004ab638  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004ab63a  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004ab63e  8b1f                   -mov ebx, dword ptr [edi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi);
    // 004ab640  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004ab642  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 004ab645  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 004ab647  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ab649  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004ab64c  e84fd50000             -call 0x4b8ba0
    cpu.esp -= 4;
    sub_4b8ba0(app, cpu);
    if (cpu.terminate) return;
    // 004ab651  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004ab655  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004ab657  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004ab65b  3b4704                 +cmp eax, dword ptr [edi + 4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ab65e  7508                   -jne 0x4ab668
    if (!cpu.flags.zf)
    {
        goto L_0x004ab668;
    }
    // 004ab660  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004ab662  8b17                   -mov edx, dword ptr [edi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi);
    // 004ab664  39d0                   +cmp eax, edx
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
    // 004ab666  744b                   -je 0x4ab6b3
    if (cpu.flags.zf)
    {
        goto L_0x004ab6b3;
    }
L_0x004ab668:
    // 004ab668  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004ab66c  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004ab670  894204                 -mov dword ptr [edx + 4], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004ab673  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004ab675  8b5d00                 -mov ebx, dword ptr [ebp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp);
    // 004ab678  39d8                   +cmp eax, ebx
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
    // 004ab67a  743b                   -je 0x4ab6b7
    if (cpu.flags.zf)
    {
        goto L_0x004ab6b7;
    }
    // 004ab67c  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004ab67e  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004ab680  e81bd50000             -call 0x4b8ba0
    cpu.esp -= 4;
    sub_4b8ba0(app, cpu);
    if (cpu.terminate) return;
    // 004ab685  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
L_0x004ab689:
    // 004ab689  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004ab68b  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004ab68e  8b7d04                 -mov edi, dword ptr [ebp + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 004ab691  39f8                   +cmp eax, edi
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
    // 004ab693  742a                   -je 0x4ab6bf
    if (cpu.flags.zf)
    {
        goto L_0x004ab6bf;
    }
    // 004ab695  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004ab697  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004ab699  e802d50000             -call 0x4b8ba0
    cpu.esp -= 4;
    sub_4b8ba0(app, cpu);
    if (cpu.terminate) return;
    // 004ab69e  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004ab6a2  894204                 -mov dword ptr [edx + 4], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004ab6a5  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004ab6aa:
    // 004ab6aa  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004ab6ad  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab6ae  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab6af  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab6b0  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x004ab6b3:
    // 004ab6b3  31d0                   +xor eax, edx
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004ab6b5  ebf3                   -jmp 0x4ab6aa
    goto L_0x004ab6aa;
L_0x004ab6b7:
    // 004ab6b7  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004ab6bb  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004ab6bd  ebca                   -jmp 0x4ab689
    goto L_0x004ab689;
L_0x004ab6bf:
    // 004ab6bf  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004ab6c3  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004ab6c6  894204                 -mov dword ptr [edx + 4], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004ab6c9  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004ab6ce  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004ab6d1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab6d2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab6d3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab6d4  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x90 */
void Application::sub_4ab6d8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ab6d8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ab6d9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ab6da  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ab6db  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ab6dc  83ec1c                 -sub esp, 0x1c
    (cpu.esp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004ab6df  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004ab6e3  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004ab6e5  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab6e7  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004ab6e9  895c2414               -mov dword ptr [esp + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 004ab6ed  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004ab6f1  8d5808                 -lea ebx, [eax + 8]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004ab6f4  895c2410               -mov dword ptr [esp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 004ab6f8  8b19                   -mov ebx, dword ptr [ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004ab6fa  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 004ab6fd  8d6b08                 -lea ebp, [ebx + 8]
    cpu.ebp = x86::reg32(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004ab700  c70270645b00           -mov dword ptr [edx], 0x5b6470
    app->getMemory<x86::reg32>(cpu.edx) = 5989488 /*0x5b6470*/;
    // 004ab706  896c240c               -mov dword ptr [esp + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 004ab70a  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx);
    // 004ab70c  c701706c5b00           -mov dword ptr [ecx], 0x5b6c70
    app->getMemory<x86::reg32>(cpu.ecx) = 5991536 /*0x5b6c70*/;
    // 004ab712  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004ab714  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
L_0x004ab718:
    // 004ab718  8b3568904d00           -mov esi, dword ptr [0x4d9068]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5083240) /* 0x4d9068 */);
    // 004ab71e  3b30                   +cmp esi, dword ptr [eax]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ab720  0f8e70000000           -jle 0x4ab796
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ab796;
    }
    // 004ab726  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004ab72a  3b32                   +cmp esi, dword ptr [edx]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ab72c  7e33                   -jle 0x4ab761
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ab761;
    }
L_0x004ab72e:
    // 004ab72e  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004ab732  4e                     -dec esi
    (cpu.esi)--;
    // 004ab733  89742408               -mov dword ptr [esp + 8], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 004ab737  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004ab739  0f8ef5000000           -jle 0x4ab834
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ab834;
    }
    // 004ab73f  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004ab743  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004ab747  83fe01                 +cmp esi, 1
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
    // 004ab74a  0f85d1000000           -jne 0x4ab821
    if (!cpu.flags.zf)
    {
        goto L_0x004ab821;
    }
    // 004ab750  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004ab754  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004ab758  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004ab75b  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004ab75f  ebb7                   -jmp 0x4ab718
    goto L_0x004ab718;
L_0x004ab761:
    // 004ab761  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ab762  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004ab766  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ab767  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004ab769  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004ab76d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ab76e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004ab770  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004ab774  e8b7fdffff             -call 0x4ab530
    cpu.esp -= 4;
    sub_4ab530(app, cpu);
    if (cpu.terminate) return;
    // 004ab779  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ab77b  74b1                   -je 0x4ab72e
    if (cpu.flags.zf)
    {
        goto L_0x004ab72e;
    }
    // 004ab77d  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004ab781  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004ab785  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004ab788  41                     -inc ecx
    (cpu.ecx)++;
    // 004ab789  83c308                 +add ebx, 8
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ab78c  894c2414               -mov dword ptr [esp + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 004ab790  895c2418               -mov dword ptr [esp + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 004ab794  eb98                   -jmp 0x4ab72e
    goto L_0x004ab72e;
L_0x004ab796:
    // 004ab796  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004ab79a  3b32                   +cmp esi, dword ptr [edx]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ab79c  7f2a                   -jg 0x4ab7c8
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004ab7c8;
    }
    // 004ab79e  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004ab7a2  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004ab7a4  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004ab7a6  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004ab7aa  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004ab7ad  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004ab7ae  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004ab7af  42                     -inc edx
    (cpu.edx)++;
    // 004ab7b0  8b7c2418               -mov edi, dword ptr [esp + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004ab7b4  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004ab7b6  83c008                 +add eax, 8
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
    // 004ab7b9  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004ab7bd  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004ab7c1  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004ab7c2  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004ab7c3  e966ffffff             -jmp 0x4ab72e
    goto L_0x004ab72e;
L_0x004ab7c8:
    // 004ab7c8  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004ab7ca  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004ab7cc  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004ab7cd  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004ab7ce  8b7c2418               -mov edi, dword ptr [esp + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004ab7d2  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004ab7d4  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004ab7d5  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004ab7d6  8b0d68904d00           -mov ecx, dword ptr [0x4d9068]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5083240) /* 0x4d9068 */);
    // 004ab7dc  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004ab7e0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ab7e1  83c608                 -add esi, 8
    (cpu.esi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004ab7e4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ab7e5  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004ab7e8  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004ab7ec  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ab7ed  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004ab7f1  89742424               -mov dword ptr [esp + 0x24], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.esi;
    // 004ab7f5  e836fdffff             -call 0x4ab530
    cpu.esp -= 4;
    sub_4ab530(app, cpu);
    if (cpu.terminate) return;
    // 004ab7fa  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ab7fc  741a                   -je 0x4ab818
    if (cpu.flags.zf)
    {
        goto L_0x004ab818;
    }
    // 004ab7fe  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004ab802  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004ab805  8d4e08                 -lea ecx, [esi + 8]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004ab808  83c202                 +add edx, 2
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
    // 004ab80b  894c2418               -mov dword ptr [esp + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 004ab80f  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004ab813  e916ffffff             -jmp 0x4ab72e
    goto L_0x004ab72e;
L_0x004ab818:
    // 004ab818  ff442414               +inc dword ptr [esp + 0x14]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004ab81c  e90dffffff             -jmp 0x4ab72e
    goto L_0x004ab72e;
L_0x004ab821:
    // 004ab821  8d4808                 -lea ecx, [eax + 8]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004ab824  8d7308                 -lea esi, [ebx + 8]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004ab827  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004ab82b  8974240c               -mov dword ptr [esp + 0xc], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 004ab82f  e9e4feffff             -jmp 0x4ab718
    goto L_0x004ab718;
L_0x004ab834:
    // 004ab834  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004ab838  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004ab83b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab83c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab83d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab83e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab83f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ab834(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004ab834;
    // 004ab6d8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ab6d9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ab6da  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004ab6db  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ab6dc  83ec1c                 -sub esp, 0x1c
    (cpu.esp) -= x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004ab6df  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004ab6e3  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004ab6e5  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004ab6e7  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004ab6e9  895c2414               -mov dword ptr [esp + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 004ab6ed  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004ab6f1  8d5808                 -lea ebx, [eax + 8]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004ab6f4  895c2410               -mov dword ptr [esp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 004ab6f8  8b19                   -mov ebx, dword ptr [ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004ab6fa  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 004ab6fd  8d6b08                 -lea ebp, [ebx + 8]
    cpu.ebp = x86::reg32(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004ab700  c70270645b00           -mov dword ptr [edx], 0x5b6470
    app->getMemory<x86::reg32>(cpu.edx) = 5989488 /*0x5b6470*/;
    // 004ab706  896c240c               -mov dword ptr [esp + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 004ab70a  8b2a                   -mov ebp, dword ptr [edx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx);
    // 004ab70c  c701706c5b00           -mov dword ptr [ecx], 0x5b6c70
    app->getMemory<x86::reg32>(cpu.ecx) = 5991536 /*0x5b6c70*/;
    // 004ab712  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004ab714  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
L_0x004ab718:
    // 004ab718  8b3568904d00           -mov esi, dword ptr [0x4d9068]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5083240) /* 0x4d9068 */);
    // 004ab71e  3b30                   +cmp esi, dword ptr [eax]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ab720  0f8e70000000           -jle 0x4ab796
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ab796;
    }
    // 004ab726  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004ab72a  3b32                   +cmp esi, dword ptr [edx]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ab72c  7e33                   -jle 0x4ab761
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ab761;
    }
L_0x004ab72e:
    // 004ab72e  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004ab732  4e                     -dec esi
    (cpu.esi)--;
    // 004ab733  89742408               -mov dword ptr [esp + 8], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 004ab737  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004ab739  0f8ef5000000           -jle 0x4ab834
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004ab834;
    }
    // 004ab73f  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004ab743  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004ab747  83fe01                 +cmp esi, 1
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
    // 004ab74a  0f85d1000000           -jne 0x4ab821
    if (!cpu.flags.zf)
    {
        goto L_0x004ab821;
    }
    // 004ab750  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004ab754  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004ab758  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004ab75b  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004ab75f  ebb7                   -jmp 0x4ab718
    goto L_0x004ab718;
L_0x004ab761:
    // 004ab761  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ab762  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004ab766  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004ab767  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004ab769  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004ab76d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ab76e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004ab770  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004ab774  e8b7fdffff             -call 0x4ab530
    cpu.esp -= 4;
    sub_4ab530(app, cpu);
    if (cpu.terminate) return;
    // 004ab779  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ab77b  74b1                   -je 0x4ab72e
    if (cpu.flags.zf)
    {
        goto L_0x004ab72e;
    }
    // 004ab77d  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004ab781  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004ab785  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004ab788  41                     -inc ecx
    (cpu.ecx)++;
    // 004ab789  83c308                 +add ebx, 8
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004ab78c  894c2414               -mov dword ptr [esp + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 004ab790  895c2418               -mov dword ptr [esp + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 004ab794  eb98                   -jmp 0x4ab72e
    goto L_0x004ab72e;
L_0x004ab796:
    // 004ab796  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004ab79a  3b32                   +cmp esi, dword ptr [edx]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004ab79c  7f2a                   -jg 0x4ab7c8
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004ab7c8;
    }
    // 004ab79e  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004ab7a2  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004ab7a4  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004ab7a6  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004ab7aa  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004ab7ad  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004ab7ae  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004ab7af  42                     -inc edx
    (cpu.edx)++;
    // 004ab7b0  8b7c2418               -mov edi, dword ptr [esp + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004ab7b4  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004ab7b6  83c008                 +add eax, 8
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
    // 004ab7b9  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004ab7bd  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004ab7c1  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004ab7c2  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004ab7c3  e966ffffff             -jmp 0x4ab72e
    goto L_0x004ab72e;
L_0x004ab7c8:
    // 004ab7c8  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004ab7ca  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004ab7cc  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004ab7cd  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004ab7ce  8b7c2418               -mov edi, dword ptr [esp + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004ab7d2  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004ab7d4  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004ab7d5  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004ab7d6  8b0d68904d00           -mov ecx, dword ptr [0x4d9068]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5083240) /* 0x4d9068 */);
    // 004ab7dc  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004ab7e0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004ab7e1  83c608                 -add esi, 8
    (cpu.esi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004ab7e4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004ab7e5  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004ab7e8  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004ab7ec  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004ab7ed  8b4c2418               -mov ecx, dword ptr [esp + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004ab7f1  89742424               -mov dword ptr [esp + 0x24], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.esi;
    // 004ab7f5  e836fdffff             -call 0x4ab530
    cpu.esp -= 4;
    sub_4ab530(app, cpu);
    if (cpu.terminate) return;
    // 004ab7fa  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004ab7fc  741a                   -je 0x4ab818
    if (cpu.flags.zf)
    {
        goto L_0x004ab818;
    }
    // 004ab7fe  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004ab802  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004ab805  8d4e08                 -lea ecx, [esi + 8]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004ab808  83c202                 +add edx, 2
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
    // 004ab80b  894c2418               -mov dword ptr [esp + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 004ab80f  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004ab813  e916ffffff             -jmp 0x4ab72e
    goto L_0x004ab72e;
L_0x004ab818:
    // 004ab818  ff442414               +inc dword ptr [esp + 0x14]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004ab81c  e90dffffff             -jmp 0x4ab72e
    goto L_0x004ab72e;
L_0x004ab821:
    // 004ab821  8d4808                 -lea ecx, [eax + 8]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004ab824  8d7308                 -lea esi, [ebx + 8]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004ab827  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004ab82b  8974240c               -mov dword ptr [esp + 0xc], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 004ab82f  e9e4feffff             -jmp 0x4ab718
    goto L_0x004ab718;
L_0x004ab834:
L_entry_0x004ab834:
    // 004ab834  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004ab838  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004ab83b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab83c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab83d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab83e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004ab83f  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
