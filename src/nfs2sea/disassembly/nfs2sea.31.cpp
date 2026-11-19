#include "nfs2sea.h"
#include <lib/thread.h>

namespace nfs2sea
{

/* align: skip  */
void Application::sub_4b4c7c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b4c7c);
    // 004b4c7c  b814184d00             -mov eax, 0x4d1814
    cpu.eax = 5052436 /*0x4d1814*/;
    // 004b4c81  e847b7ffff             -call 0x4b03cd
    cpu.esp -= 4;
    sub_4b03cd(app, cpu);
    if (cpu.terminate) return;
    // 004b4c86  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b4c88  0f84f8feffff           -je 0x4b4b86
    if (cpu.flags.zf)
    {
        return sub_4b4b86(app, cpu);
    }
    // 004b4c8e  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b4c8f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b4c90  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b4c91  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b4c92  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b4c93  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b4c94  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b4c97  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b4c99  bb06054e00             -mov ebx, 0x4e0506
    cpu.ebx = 5113094 /*0x4e0506*/;
    // 004b4c9e  89150a054e00           -mov dword ptr [0x4e050a], edx
    app->getMemory<x86::reg32>(x86::reg32(5113098) /* 0x4e050a */) = cpu.edx;
    // 004b4ca4  bafc034e00             -mov edx, 0x4e03fc
    cpu.edx = 5112828 /*0x4e03fc*/;
    // 004b4ca9  e83d000000             -call 0x4b4ceb
    cpu.esp -= 4;
    sub_4b4ceb(app, cpu);
    if (cpu.terminate) return;
    // 004b4cae  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004b4cb0  8a20                   -mov ah, byte ptr [eax]
    cpu.ah = app->getMemory<x86::reg8>(cpu.eax);
    // 004b4cb2  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 004b4cb4  0f8534020000           -jne 0x4b4eee
    if (!cpu.flags.zf)
    {
        return sub_4b4eee(app, cpu);
    }
    // 004b4cba  88257d044e00           -mov byte ptr [0x4e047d], ah
    app->getMemory<x86::reg8>(x86::reg32(5112957) /* 0x4e047d */) = cpu.ah;
    // 004b4cc0  e9e7020000             -jmp 0x4b4fac
    return sub_4b4fac(app, cpu);
}

/* align: skip  */
void Application::sub_4b4cc5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b4cc5);
    // 004b4cc5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b4cc6  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b4cc7  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b4cc9  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004b4ccb:
    // 004b4ccb  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 004b4ccd  80fb30                 +cmp bl, 0x30
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b4cd0  7214                   -jb 0x4b4ce6
    if (cpu.flags.cf)
    {
        goto L_0x004b4ce6;
    }
    // 004b4cd2  80fb39                 +cmp bl, 0x39
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(57 /*0x39*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b4cd5  770f                   -ja 0x4b4ce6
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004b4ce6;
    }
    // 004b4cd7  6bd20a                 -imul edx, edx, 0xa
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(10 /*0xa*/)));
    // 004b4cda  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b4cdc  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 004b4cde  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b4ce0  40                     -inc eax
    (cpu.eax)++;
    // 004b4ce1  83ea30                 +sub edx, 0x30
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(48 /*0x30*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004b4ce4  ebe5                   -jmp 0x4b4ccb
    goto L_0x004b4ccb;
L_0x004b4ce6:
    // 004b4ce6  8911                   -mov dword ptr [ecx], edx
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.edx;
    // 004b4ce8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4ce9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4cea  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b4ceb(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b4ceb);
    // 004b4ceb  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b4cec  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b4ced  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b4cee  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b4cef  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004b4cf2  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004b4cf4  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004b4cf7  80383a                 +cmp byte ptr [eax], 0x3a
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(58 /*0x3a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b4cfa  7501                   -jne 0x4b4cfd
    if (!cpu.flags.zf)
    {
        goto L_0x004b4cfd;
    }
    // 004b4cfc  45                     -inc ebp
    (cpu.ebp)++;
L_0x004b4cfd:
    // 004b4cfd  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
L_0x004b4cff:
    // 004b4cff  8a5500                 -mov dl, byte ptr [ebp]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebp);
    // 004b4d02  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 004b4d04  741c                   -je 0x4b4d22
    if (cpu.flags.zf)
    {
        goto L_0x004b4d22;
    }
    // 004b4d06  80fa2c                 +cmp dl, 0x2c
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(44 /*0x2c*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b4d09  7417                   -je 0x4b4d22
    if (cpu.flags.zf)
    {
        goto L_0x004b4d22;
    }
    // 004b4d0b  80fa2d                 +cmp dl, 0x2d
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(45 /*0x2d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b4d0e  7412                   -je 0x4b4d22
    if (cpu.flags.zf)
    {
        goto L_0x004b4d22;
    }
    // 004b4d10  80fa2b                 +cmp dl, 0x2b
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(43 /*0x2b*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b4d13  740d                   -je 0x4b4d22
    if (cpu.flags.zf)
    {
        goto L_0x004b4d22;
    }
    // 004b4d15  80fa30                 +cmp dl, 0x30
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(48 /*0x30*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b4d18  7205                   -jb 0x4b4d1f
    if (cpu.flags.cf)
    {
        goto L_0x004b4d1f;
    }
    // 004b4d1a  80fa39                 +cmp dl, 0x39
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(57 /*0x39*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b4d1d  7603                   -jbe 0x4b4d22
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b4d22;
    }
L_0x004b4d1f:
    // 004b4d1f  45                     +inc ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004b4d20  ebdd                   -jmp 0x4b4cff
    goto L_0x004b4cff;
L_0x004b4d22:
    // 004b4d22  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004b4d24  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004b4d26  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004b4d2a  3d80000000             +cmp eax, 0x80
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(128 /*0x80*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b4d2f  7e08                   -jle 0x4b4d39
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b4d39;
    }
    // 004b4d31  c744241080000000       -mov dword ptr [esp + 0x10], 0x80
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = 128 /*0x80*/;
L_0x004b4d39:
    // 004b4d39  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b4d3d  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 004b4d40  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004b4d41  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004b4d43  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004b4d45  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b4d46  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b4d48  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004b4d4b  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b4d4d  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004b4d4f  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004b4d52  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004b4d54  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4d55  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004b4d56  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b4d5a  8d040f                 -lea eax, [edi + ecx]
    cpu.eax = x86::reg32(cpu.edi + cpu.ecx * 1);
    // 004b4d5d  c60000                 -mov byte ptr [eax], 0
    app->getMemory<x86::reg8>(cpu.eax) = 0 /*0x0*/;
    // 004b4d60  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b4d62  8d4501                 -lea eax, [ebp + 1]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(1) /* 0x1 */);
    // 004b4d65  80fa2d                 +cmp dl, 0x2d
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(45 /*0x2d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b4d68  7507                   -jne 0x4b4d71
    if (!cpu.flags.zf)
    {
        goto L_0x004b4d71;
    }
    // 004b4d6a  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004b4d6f  eb05                   -jmp 0x4b4d76
    goto L_0x004b4d76;
L_0x004b4d71:
    // 004b4d71  80fa2b                 +cmp dl, 0x2b
    {
        x86::reg8 tmp1 = cpu.dl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(43 /*0x2b*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b4d74  7502                   -jne 0x4b4d78
    if (!cpu.flags.zf)
    {
        goto L_0x004b4d78;
    }
L_0x004b4d76:
    // 004b4d76  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
L_0x004b4d78:
    // 004b4d78  8a4500                 -mov al, byte ptr [ebp]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebp);
    // 004b4d7b  3c30                   +cmp al, 0x30
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
    // 004b4d7d  0f8273000000           -jb 0x4b4df6
    if (cpu.flags.cf)
    {
        goto L_0x004b4df6;
    }
    // 004b4d83  3c39                   +cmp al, 0x39
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
    // 004b4d85  776f                   -ja 0x4b4df6
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004b4df6;
    }
    // 004b4d87  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b4d8b  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004b4d8d  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004b4d8f  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 004b4d93  89742408               -mov dword ptr [esp + 8], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 004b4d97  8974240c               -mov dword ptr [esp + 0xc], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 004b4d9b  e825ffffff             -call 0x4b4cc5
    cpu.esp -= 4;
    sub_4b4cc5(app, cpu);
    if (cpu.terminate) return;
    // 004b4da0  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004b4da2  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004b4da4  80fa3a                 +cmp dl, 0x3a
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
    // 004b4da7  751f                   -jne 0x4b4dc8
    if (!cpu.flags.zf)
    {
        goto L_0x004b4dc8;
    }
    // 004b4da9  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b4dad  40                     -inc eax
    (cpu.eax)++;
    // 004b4dae  e812ffffff             -call 0x4b4cc5
    cpu.esp -= 4;
    sub_4b4cc5(app, cpu);
    if (cpu.terminate) return;
    // 004b4db3  8a30                   -mov dh, byte ptr [eax]
    cpu.dh = app->getMemory<x86::reg8>(cpu.eax);
    // 004b4db5  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004b4db7  80fe3a                 +cmp dh, 0x3a
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(58 /*0x3a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b4dba  750c                   -jne 0x4b4dc8
    if (!cpu.flags.zf)
    {
        goto L_0x004b4dc8;
    }
    // 004b4dbc  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b4dc0  40                     -inc eax
    (cpu.eax)++;
    // 004b4dc1  e8fffeffff             -call 0x4b4cc5
    cpu.esp -= 4;
    sub_4b4cc5(app, cpu);
    if (cpu.terminate) return;
    // 004b4dc6  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
L_0x004b4dc8:
    // 004b4dc8  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b4dcc  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b4dce  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004b4dd1  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004b4dd3  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b4dd7  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004b4dda  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b4ddc  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b4dde  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004b4de1  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b4de3  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b4de7  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004b4dea  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b4dec  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 004b4dee  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004b4df0  7404                   -je 0x4b4df6
    if (cpu.flags.zf)
    {
        goto L_0x004b4df6;
    }
    // 004b4df2  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 004b4df4  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
L_0x004b4df6:
    // 004b4df6  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004b4df8  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004b4dfb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4dfc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4dfd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4dfe  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4dff  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b4e00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b4e00);
    // 004b4e00  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b4e01  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b4e02  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b4e03  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b4e06  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b4e08  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b4e0a  8a20                   -mov ah, byte ptr [eax]
    cpu.ah = app->getMemory<x86::reg8>(cpu.eax);
    // 004b4e0c  beffffffff             -mov esi, 0xffffffff
    cpu.esi = 4294967295 /*0xffffffff*/;
    // 004b4e11  80fc4a                 +cmp ah, 0x4a
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(74 /*0x4a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b4e14  7507                   -jne 0x4b4e1d
    if (!cpu.flags.zf)
    {
        goto L_0x004b4e1d;
    }
    // 004b4e16  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 004b4e1b  01f3                   -add ebx, esi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.esi));
L_0x004b4e1d:
    // 004b4e1d  803b4d                 +cmp byte ptr [ebx], 0x4d
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(77 /*0x4d*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b4e20  7503                   -jne 0x4b4e25
    if (!cpu.flags.zf)
    {
        goto L_0x004b4e25;
    }
    // 004b4e22  43                     -inc ebx
    (cpu.ebx)++;
    // 004b4e23  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x004b4e25:
    // 004b4e25  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b4e29  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b4e2b  897120                 -mov dword ptr [ecx + 0x20], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.esi;
    // 004b4e2e  e892feffff             -call 0x4b4cc5
    cpu.esp -= 4;
    sub_4b4cc5(app, cpu);
    if (cpu.terminate) return;
    // 004b4e33  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b4e35  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b4e37  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004b4e39  7409                   -je 0x4b4e44
    if (cpu.flags.zf)
    {
        goto L_0x004b4e44;
    }
    // 004b4e3b  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b4e3f  89411c                 -mov dword ptr [ecx + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004b4e42  eb45                   -jmp 0x4b4e89
    goto L_0x004b4e89;
L_0x004b4e44:
    // 004b4e44  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b4e48  48                     -dec eax
    (cpu.eax)--;
    // 004b4e49  894110                 -mov dword ptr [ecx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004b4e4c  803a2e                 +cmp byte ptr [edx], 0x2e
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(46 /*0x2e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b4e4f  7531                   -jne 0x4b4e82
    if (!cpu.flags.zf)
    {
        goto L_0x004b4e82;
    }
    // 004b4e51  8d4201                 -lea eax, [edx + 1]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004b4e54  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b4e58  e868feffff             -call 0x4b4cc5
    cpu.esp -= 4;
    sub_4b4cc5(app, cpu);
    if (cpu.terminate) return;
    // 004b4e5d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b4e5f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b4e61  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b4e65  89410c                 -mov dword ptr [ecx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004b4e68  803a2e                 +cmp byte ptr [edx], 0x2e
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(46 /*0x2e*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b4e6b  7515                   -jne 0x4b4e82
    if (!cpu.flags.zf)
    {
        goto L_0x004b4e82;
    }
    // 004b4e6d  8d4201                 -lea eax, [edx + 1]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004b4e70  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b4e74  e84cfeffff             -call 0x4b4cc5
    cpu.esp -= 4;
    sub_4b4cc5(app, cpu);
    if (cpu.terminate) return;
    // 004b4e79  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b4e7b  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b4e7f  894118                 -mov dword ptr [ecx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = cpu.eax;
L_0x004b4e82:
    // 004b4e82  c7411c00000000         -mov dword ptr [ecx + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
L_0x004b4e89:
    // 004b4e89  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 004b4e8e  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004b4e90  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004b4e94  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 004b4e97  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 004b4e9b  803b2f                 +cmp byte ptr [ebx], 0x2f
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(47 /*0x2f*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b4e9e  7532                   -jne 0x4b4ed2
    if (!cpu.flags.zf)
    {
        goto L_0x004b4ed2;
    }
    // 004b4ea0  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b4ea4  8d4301                 -lea eax, [ebx + 1]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 004b4ea7  e819feffff             -call 0x4b4cc5
    cpu.esp -= 4;
    sub_4b4cc5(app, cpu);
    if (cpu.terminate) return;
    // 004b4eac  8a30                   -mov dh, byte ptr [eax]
    cpu.dh = app->getMemory<x86::reg8>(cpu.eax);
    // 004b4eae  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b4eb0  80fe3a                 +cmp dh, 0x3a
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(58 /*0x3a*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b4eb3  751d                   -jne 0x4b4ed2
    if (!cpu.flags.zf)
    {
        goto L_0x004b4ed2;
    }
    // 004b4eb5  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b4eb9  40                     -inc eax
    (cpu.eax)++;
    // 004b4eba  e806feffff             -call 0x4b4cc5
    cpu.esp -= 4;
    sub_4b4cc5(app, cpu);
    if (cpu.terminate) return;
    // 004b4ebf  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004b4ec1  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b4ec3  80fa3a                 +cmp dl, 0x3a
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
    // 004b4ec6  750a                   -jne 0x4b4ed2
    if (!cpu.flags.zf)
    {
        goto L_0x004b4ed2;
    }
    // 004b4ec8  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004b4eca  40                     -inc eax
    (cpu.eax)++;
    // 004b4ecb  e8f5fdffff             -call 0x4b4cc5
    cpu.esp -= 4;
    sub_4b4cc5(app, cpu);
    if (cpu.terminate) return;
    // 004b4ed0  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x004b4ed2:
    // 004b4ed2  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004b4ed5  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 004b4ed7  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b4edb  894104                 -mov dword ptr [ecx + 4], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004b4ede  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b4ee2  894108                 -mov dword ptr [ecx + 8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b4ee5  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b4ee7  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b4eea  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4eeb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4eec  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4eed  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b4eee(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b4eee);
    // 004b4eee  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004b4ef3  ba7d044e00             -mov edx, 0x4e047d
    cpu.edx = 5112957 /*0x4e047d*/;
    // 004b4ef8  a106054e00             -mov eax, dword ptr [0x4e0506]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5113094) /* 0x4e0506 */);
    // 004b4efd  891d0a054e00           -mov dword ptr [0x4e050a], ebx
    app->getMemory<x86::reg32>(x86::reg32(5113098) /* 0x4e050a */) = cpu.ebx;
    // 004b4f03  2d100e0000             -sub eax, 0xe10
    (cpu.eax) -= x86::reg32(x86::sreg32(3600 /*0xe10*/));
    // 004b4f08  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004b4f0a  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004b4f0d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b4f0f  e8d7fdffff             -call 0x4b4ceb
    cpu.esp -= 4;
    sub_4b4ceb(app, cpu);
    if (cpu.terminate) return;
    // 004b4f14  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 004b4f17  8b1d06054e00           -mov ebx, dword ptr [0x4e0506]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5113094) /* 0x4e0506 */);
    // 004b4f1d  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b4f1f  891d0e054e00           -mov dword ptr [0x4e050e], ebx
    app->getMemory<x86::reg32>(x86::reg32(5113102) /* 0x4e050e */) = cpu.ebx;
    // 004b4f25  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 004b4f27  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b4f29  80fb2c                 +cmp bl, 0x2c
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(44 /*0x2c*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b4f2c  750d                   -jne 0x4b4f3b
    if (!cpu.flags.zf)
    {
        goto L_0x004b4f3b;
    }
    // 004b4f2e  bab4034e00             -mov edx, 0x4e03b4
    cpu.edx = 5112756 /*0x4e03b4*/;
    // 004b4f33  40                     -inc eax
    (cpu.eax)++;
    // 004b4f34  e8c7feffff             -call 0x4b4e00
    cpu.esp -= 4;
    sub_4b4e00(app, cpu);
    if (cpu.terminate) return;
    // 004b4f39  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x004b4f3b:
    // 004b4f3b  803a2c                 +cmp byte ptr [edx], 0x2c
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(44 /*0x2c*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b4f3e  756c                   -jne 0x4b4fac
    if (!cpu.flags.zf)
    {
        goto L_0x004b4fac;
    }
    // 004b4f40  8d4201                 -lea eax, [edx + 1]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004b4f43  bad8034e00             -mov edx, 0x4e03d8
    cpu.edx = 5112792 /*0x4e03d8*/;
    // 004b4f48  e8b3feffff             -call 0x4b4e00
    cpu.esp -= 4;
    sub_4b4e00(app, cpu);
    if (cpu.terminate) return;
    // 004b4f4d  a10e054e00             -mov eax, dword ptr [0x4e050e]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5113102) /* 0x4e050e */);
    // 004b4f52  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b4f54  bb100e0000             -mov ebx, 0xe10
    cpu.ebx = 3600 /*0xe10*/;
    // 004b4f59  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004b4f5c  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004b4f5e  8b35e0034e00           -mov esi, dword ptr [0x4e03e0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5112800) /* 0x4e03e0 */);
    // 004b4f64  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004b4f66  a10e054e00             -mov eax, dword ptr [0x4e050e]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5113102) /* 0x4e050e */);
    // 004b4f6b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b4f6d  bb3c000000             -mov ebx, 0x3c
    cpu.ebx = 60 /*0x3c*/;
    // 004b4f72  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004b4f75  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004b4f77  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b4f79  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004b4f7c  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004b4f7e  8b3ddc034e00           -mov edi, dword ptr [0x4e03dc]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5112796) /* 0x4e03dc */);
    // 004b4f84  a10e054e00             -mov eax, dword ptr [0x4e050e]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5113102) /* 0x4e050e */);
    // 004b4f89  29d7                   -sub edi, edx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b4f8b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b4f8d  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004b4f90  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004b4f92  8b2dd8034e00           -mov ebp, dword ptr [0x4e03d8]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5112792) /* 0x4e03d8 */);
    // 004b4f98  8935e0034e00           -mov dword ptr [0x4e03e0], esi
    app->getMemory<x86::reg32>(x86::reg32(5112800) /* 0x4e03e0 */) = cpu.esi;
    // 004b4f9e  29d5                   -sub ebp, edx
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b4fa0  893ddc034e00           -mov dword ptr [0x4e03dc], edi
    app->getMemory<x86::reg32>(x86::reg32(5112796) /* 0x4e03dc */) = cpu.edi;
    // 004b4fa6  892dd8034e00           -mov dword ptr [0x4e03d8], ebp
    app->getMemory<x86::reg32>(x86::reg32(5112792) /* 0x4e03d8 */) = cpu.ebp;
L_0x004b4fac:
    // 004b4fac  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b4faf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4fb0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4fb1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4fb2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4fb3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4fb4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4fb5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b4fac(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b4fac);
    goto L_entry_0x004b4fac;
    // 004b4eee  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004b4ef3  ba7d044e00             -mov edx, 0x4e047d
    cpu.edx = 5112957 /*0x4e047d*/;
    // 004b4ef8  a106054e00             -mov eax, dword ptr [0x4e0506]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5113094) /* 0x4e0506 */);
    // 004b4efd  891d0a054e00           -mov dword ptr [0x4e050a], ebx
    app->getMemory<x86::reg32>(x86::reg32(5113098) /* 0x4e050a */) = cpu.ebx;
    // 004b4f03  2d100e0000             -sub eax, 0xe10
    (cpu.eax) -= x86::reg32(x86::sreg32(3600 /*0xe10*/));
    // 004b4f08  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004b4f0a  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004b4f0d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b4f0f  e8d7fdffff             -call 0x4b4ceb
    cpu.esp -= 4;
    sub_4b4ceb(app, cpu);
    if (cpu.terminate) return;
    // 004b4f14  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 004b4f17  8b1d06054e00           -mov ebx, dword ptr [0x4e0506]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5113094) /* 0x4e0506 */);
    // 004b4f1d  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b4f1f  891d0e054e00           -mov dword ptr [0x4e050e], ebx
    app->getMemory<x86::reg32>(x86::reg32(5113102) /* 0x4e050e */) = cpu.ebx;
    // 004b4f25  8a18                   -mov bl, byte ptr [eax]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax);
    // 004b4f27  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b4f29  80fb2c                 +cmp bl, 0x2c
    {
        x86::reg8 tmp1 = cpu.bl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(44 /*0x2c*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b4f2c  750d                   -jne 0x4b4f3b
    if (!cpu.flags.zf)
    {
        goto L_0x004b4f3b;
    }
    // 004b4f2e  bab4034e00             -mov edx, 0x4e03b4
    cpu.edx = 5112756 /*0x4e03b4*/;
    // 004b4f33  40                     -inc eax
    (cpu.eax)++;
    // 004b4f34  e8c7feffff             -call 0x4b4e00
    cpu.esp -= 4;
    sub_4b4e00(app, cpu);
    if (cpu.terminate) return;
    // 004b4f39  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x004b4f3b:
    // 004b4f3b  803a2c                 +cmp byte ptr [edx], 0x2c
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edx);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(44 /*0x2c*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b4f3e  756c                   -jne 0x4b4fac
    if (!cpu.flags.zf)
    {
        goto L_0x004b4fac;
    }
    // 004b4f40  8d4201                 -lea eax, [edx + 1]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004b4f43  bad8034e00             -mov edx, 0x4e03d8
    cpu.edx = 5112792 /*0x4e03d8*/;
    // 004b4f48  e8b3feffff             -call 0x4b4e00
    cpu.esp -= 4;
    sub_4b4e00(app, cpu);
    if (cpu.terminate) return;
    // 004b4f4d  a10e054e00             -mov eax, dword ptr [0x4e050e]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5113102) /* 0x4e050e */);
    // 004b4f52  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b4f54  bb100e0000             -mov ebx, 0xe10
    cpu.ebx = 3600 /*0xe10*/;
    // 004b4f59  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004b4f5c  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004b4f5e  8b35e0034e00           -mov esi, dword ptr [0x4e03e0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5112800) /* 0x4e03e0 */);
    // 004b4f64  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004b4f66  a10e054e00             -mov eax, dword ptr [0x4e050e]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5113102) /* 0x4e050e */);
    // 004b4f6b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b4f6d  bb3c000000             -mov ebx, 0x3c
    cpu.ebx = 60 /*0x3c*/;
    // 004b4f72  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004b4f75  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004b4f77  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b4f79  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004b4f7c  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004b4f7e  8b3ddc034e00           -mov edi, dword ptr [0x4e03dc]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5112796) /* 0x4e03dc */);
    // 004b4f84  a10e054e00             -mov eax, dword ptr [0x4e050e]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5113102) /* 0x4e050e */);
    // 004b4f89  29d7                   -sub edi, edx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b4f8b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b4f8d  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004b4f90  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004b4f92  8b2dd8034e00           -mov ebp, dword ptr [0x4e03d8]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5112792) /* 0x4e03d8 */);
    // 004b4f98  8935e0034e00           -mov dword ptr [0x4e03e0], esi
    app->getMemory<x86::reg32>(x86::reg32(5112800) /* 0x4e03e0 */) = cpu.esi;
    // 004b4f9e  29d5                   -sub ebp, edx
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b4fa0  893ddc034e00           -mov dword ptr [0x4e03dc], edi
    app->getMemory<x86::reg32>(x86::reg32(5112796) /* 0x4e03dc */) = cpu.edi;
    // 004b4fa6  892dd8034e00           -mov dword ptr [0x4e03d8], ebp
    app->getMemory<x86::reg32>(x86::reg32(5112792) /* 0x4e03d8 */) = cpu.ebp;
L_0x004b4fac:
L_entry_0x004b4fac:
    // 004b4fac  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b4faf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4fb0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4fb1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4fb2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4fb3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4fb4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4fb5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4b4fb8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b4fb8);
    // 004b4fb8  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b4fb9  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b4fbb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b4fbc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b4fbd  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b4fc0  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b4fc3  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b4fc6  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b4fc9  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004b4fcc  c700d64f4b00           -mov dword ptr [eax], 0x4b4fd6
    app->getMemory<x86::reg32>(cpu.eax) = 4935638 /*0x4b4fd6*/;
    // 004b4fd2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4fd3  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4fd4  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b4fd5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b4fd6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b4fd6);
    // 004b4fd6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b4fd7  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b4fd9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b4fda  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b4fdb  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b4fdc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b4fdd  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b4fe0  8b4e08                 -mov ecx, dword ptr [esi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004b4fe3  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b4fe6  8b5d10                 -mov ebx, dword ptr [ebp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b4fe9  db450c                 -fild dword ptr [ebp + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */))));
    // 004b4fec  db4510                 -fild dword ptr [ebp + 0x10]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */))));
    // 004b4fef  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b4ff1  d80d18054e00           -fmul dword ptr [0x4e0518]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5113112) /* 0x4e0518 */));
    // 004b4ff7  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b4ff9  d80d18054e00           -fmul dword ptr [0x4e0518]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5113112) /* 0x4e0518 */));
    // 004b4fff  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b5001  d91e                   -fstp dword ptr [esi]
    app->getMemory<float>(cpu.esi) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b5003  d95e04                 -fstp dword ptr [esi + 4]
    app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b5006  83f800                 +cmp eax, 0
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
    // 004b5009  7417                   -je 0x4b5022
    if (cpu.flags.zf)
    {
        goto L_0x004b5022;
    }
    // 004b500b  83fb00                 +cmp ebx, 0
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b500e  7448                   -je 0x4b5058
    if (cpu.flags.zf)
    {
        goto L_0x004b5058;
    }
    // 004b5010  83f87f                 +cmp eax, 0x7f
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
    // 004b5013  7414                   -je 0x4b5029
    if (cpu.flags.zf)
    {
        goto L_0x004b5029;
    }
    // 004b5015  83fb7f                 +cmp ebx, 0x7f
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
    // 004b5018  742e                   -je 0x4b5048
    if (cpu.flags.zf)
    {
        goto L_0x004b5048;
    }
    // 004b501a  c70166504b00           -mov dword ptr [ecx], 0x4b5066
    app->getMemory<x86::reg32>(cpu.ecx) = 4935782 /*0x4b5066*/;
    // 004b5020  eb3e                   -jmp 0x4b5060
    goto L_0x004b5060;
L_0x004b5022:
    // 004b5022  83fb00                 +cmp ebx, 0
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b5025  7409                   -je 0x4b5030
    if (cpu.flags.zf)
    {
        goto L_0x004b5030;
    }
    // 004b5027  eb27                   -jmp 0x4b5050
    goto L_0x004b5050;
L_0x004b5029:
    // 004b5029  83fb7f                 +cmp ebx, 0x7f
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
    // 004b502c  740a                   -je 0x4b5038
    if (cpu.flags.zf)
    {
        goto L_0x004b5038;
    }
    // 004b502e  eb10                   -jmp 0x4b5040
    goto L_0x004b5040;
L_0x004b5030:
    // 004b5030  c70169534b00           -mov dword ptr [ecx], 0x4b5369
    app->getMemory<x86::reg32>(cpu.ecx) = 4936553 /*0x4b5369*/;
    // 004b5036  eb28                   -jmp 0x4b5060
    goto L_0x004b5060;
L_0x004b5038:
    // 004b5038  c701f6504b00           -mov dword ptr [ecx], 0x4b50f6
    app->getMemory<x86::reg32>(cpu.ecx) = 4935926 /*0x4b50f6*/;
    // 004b503e  eb20                   -jmp 0x4b5060
    goto L_0x004b5060;
L_0x004b5040:
    // 004b5040  c701e3524b00           -mov dword ptr [ecx], 0x4b52e3
    app->getMemory<x86::reg32>(cpu.ecx) = 4936419 /*0x4b52e3*/;
    // 004b5046  eb18                   -jmp 0x4b5060
    goto L_0x004b5060;
L_0x004b5048:
    // 004b5048  c7015e524b00           -mov dword ptr [ecx], 0x4b525e
    app->getMemory<x86::reg32>(cpu.ecx) = 4936286 /*0x4b525e*/;
    // 004b504e  eb10                   -jmp 0x4b5060
    goto L_0x004b5060;
L_0x004b5050:
    // 004b5050  c701e1514b00           -mov dword ptr [ecx], 0x4b51e1
    app->getMemory<x86::reg32>(cpu.ecx) = 4936161 /*0x4b51e1*/;
    // 004b5056  eb08                   -jmp 0x4b5060
    goto L_0x004b5060;
L_0x004b5058:
    // 004b5058  c70165514b00           -mov dword ptr [ecx], 0x4b5165
    app->getMemory<x86::reg32>(cpu.ecx) = 4936037 /*0x4b5165*/;
    // 004b505e  eb00                   -jmp 0x4b5060
    goto L_0x004b5060;
L_0x004b5060:
    // 004b5060  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5061  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5062  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5063  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5064  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5065  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b5066(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b5066);
    // 004b5066  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b5067  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b5069  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004b506a  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b506d  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b5070  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b5073  d94604                 -fld dword ptr [esi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 004b5076  d906                   -fld dword ptr [esi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi)));
    // 004b5078  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004b507b  83f901                 +cmp ecx, 1
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
    // 004b507e  7e45                   -jle 0x4b50c5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b50c5;
    }
    // 004b5080  83e901                 -sub ecx, 1
    (cpu.ecx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004b5083:
    // 004b5083  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004b5085  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004b5087  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004b5089  d8cb                   -fmul st(3)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(3));
    // 004b508b  d94704                 -fld dword ptr [edi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 004b508e  d8cb                   -fmul st(3)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(3));
    // 004b5090  d94704                 -fld dword ptr [edi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 004b5093  d8cd                   -fmul st(5)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(5));
    // 004b5095  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004b5097  d84500                 -fadd dword ptr [ebp]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp));
    // 004b509a  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004b509c  d84504                 -fadd dword ptr [ebp + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */));
    // 004b509f  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b50a1  d84508                 -fadd dword ptr [ebp + 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */));
    // 004b50a4  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004b50a6  d8450c                 -fadd dword ptr [ebp + 0xc]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */));
    // 004b50a9  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004b50ab  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b50ae  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b50b1  d95d0c                 -fstp dword ptr [ebp + 0xc]
    app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b50b4  d95d08                 -fstp dword ptr [ebp + 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b50b7  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b50ba  83c510                 -add ebp, 0x10
    (cpu.ebp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b50bd  83e902                 +sub ecx, 2
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
    // 004b50c0  7fc1                   -jg 0x4b5083
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b5083;
    }
    // 004b50c2  83c101                 -add ecx, 1
    (cpu.ecx) += x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004b50c5:
    // 004b50c5  83f900                 +cmp ecx, 0
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
    // 004b50c8  7e25                   -jle 0x4b50ef
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b50ef;
    }
    // 004b50ca  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004b50cc  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004b50ce  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004b50d0  d8cb                   -fmul st(3)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(3));
    // 004b50d2  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b50d4  d84500                 -fadd dword ptr [ebp]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp));
    // 004b50d7  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b50d9  d84504                 -fadd dword ptr [ebp + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */));
    // 004b50dc  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b50de  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b50e1  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b50e4  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b50e7  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b50ea  83e901                 +sub ecx, 1
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
    // 004b50ed  7fd6                   -jg 0x4b50c5
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b50c5;
    }
L_0x004b50ef:
    // 004b50ef  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b50f1  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b50f3  61                     -popal 
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
    // 004b50f4  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b50f5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b50f6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b50f6);
    // 004b50f6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b50f7  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b50f9  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004b50fa  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b50fd  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b5100  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b5103  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004b5106  83f901                 +cmp ecx, 1
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
    // 004b5109  7e35                   -jle 0x4b5140
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b5140;
    }
    // 004b510b  83e901                 -sub ecx, 1
    (cpu.ecx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004b510e:
    // 004b510e  d94500                 -fld dword ptr [ebp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp)));
    // 004b5111  d807                   -fadd dword ptr [edi]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edi));
    // 004b5113  d94504                 -fld dword ptr [ebp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */)));
    // 004b5116  d807                   -fadd dword ptr [edi]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edi));
    // 004b5118  d94508                 -fld dword ptr [ebp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */)));
    // 004b511b  d84704                 -fadd dword ptr [edi + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */));
    // 004b511e  d9450c                 -fld dword ptr [ebp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */)));
    // 004b5121  d84704                 -fadd dword ptr [edi + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */));
    // 004b5124  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004b5126  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b5129  d95d08                 -fstp dword ptr [ebp + 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b512c  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b512f  d95d0c                 -fstp dword ptr [ebp + 0xc]
    app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b5132  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b5135  83c510                 -add ebp, 0x10
    (cpu.ebp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b5138  83e902                 +sub ecx, 2
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
    // 004b513b  7fd1                   -jg 0x4b510e
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b510e;
    }
    // 004b513d  83c101                 -add ecx, 1
    (cpu.ecx) += x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004b5140:
    // 004b5140  83f900                 +cmp ecx, 0
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
    // 004b5143  7e1d                   -jle 0x4b5162
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b5162;
    }
    // 004b5145  d94500                 -fld dword ptr [ebp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp)));
    // 004b5148  d807                   -fadd dword ptr [edi]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edi));
    // 004b514a  d94504                 -fld dword ptr [ebp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */)));
    // 004b514d  d807                   -fadd dword ptr [edi]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edi));
    // 004b514f  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b5151  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b5154  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b5157  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b515a  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b515d  83e901                 +sub ecx, 1
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
    // 004b5160  7fde                   -jg 0x4b5140
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b5140;
    }
L_0x004b5162:
    // 004b5162  61                     -popal 
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
    // 004b5163  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5164  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b5165(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b5165);
    // 004b5165  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b5166  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b5168  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004b5169  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b516c  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b516f  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b5172  d906                   -fld dword ptr [esi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi)));
    // 004b5174  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004b5177  83f903                 +cmp ecx, 3
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
    // 004b517a  7e46                   -jle 0x4b51c2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b51c2;
    }
    // 004b517c  83e903                 -sub ecx, 3
    (cpu.ecx) -= x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x004b517f:
    // 004b517f  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004b5181  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004b5183  d94704                 -fld dword ptr [edi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 004b5186  d8ca                   -fmul st(2)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(2));
    // 004b5188  d94708                 -fld dword ptr [edi + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(8) /* 0x8 */)));
    // 004b518b  d8cb                   -fmul st(3)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(3));
    // 004b518d  d9470c                 -fld dword ptr [edi + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(12) /* 0xc */)));
    // 004b5190  d8cc                   -fmul st(4)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(4));
    // 004b5192  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004b5194  d84500                 -fadd dword ptr [ebp]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp));
    // 004b5197  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004b5199  d84508                 -fadd dword ptr [ebp + 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */));
    // 004b519c  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b519e  d84510                 -fadd dword ptr [ebp + 0x10]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(16) /* 0x10 */));
    // 004b51a1  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004b51a3  d84518                 -fadd dword ptr [ebp + 0x18]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(24) /* 0x18 */));
    // 004b51a6  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004b51a8  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b51ab  d95d08                 -fstp dword ptr [ebp + 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b51ae  d95d18                 -fstp dword ptr [ebp + 0x18]
    app->getMemory<float>(cpu.ebp + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b51b1  d95d10                 -fstp dword ptr [ebp + 0x10]
    app->getMemory<float>(cpu.ebp + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b51b4  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b51b7  83c520                 -add ebp, 0x20
    (cpu.ebp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004b51ba  83e904                 +sub ecx, 4
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
    // 004b51bd  7fc0                   -jg 0x4b517f
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b517f;
    }
    // 004b51bf  83c103                 -add ecx, 3
    (cpu.ecx) += x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x004b51c2:
    // 004b51c2  83f900                 +cmp ecx, 0
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
    // 004b51c5  7e15                   -jle 0x4b51dc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b51dc;
    }
    // 004b51c7  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004b51c9  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004b51cb  d84500                 -fadd dword ptr [ebp]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp));
    // 004b51ce  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b51d1  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b51d4  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b51d7  83e901                 +sub ecx, 1
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
    // 004b51da  7fe6                   -jg 0x4b51c2
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b51c2;
    }
L_0x004b51dc:
    // 004b51dc  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b51de  61                     -popal 
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
    // 004b51df  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b51e0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b51e1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b51e1);
    // 004b51e1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b51e2  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b51e4  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004b51e5  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b51e8  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b51eb  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b51ee  d94604                 -fld dword ptr [esi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 004b51f1  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004b51f4  83f903                 +cmp ecx, 3
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
    // 004b51f7  7e46                   -jle 0x4b523f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b523f;
    }
    // 004b51f9  83e903                 -sub ecx, 3
    (cpu.ecx) -= x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x004b51fc:
    // 004b51fc  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004b51fe  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004b5200  d94704                 -fld dword ptr [edi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 004b5203  d8ca                   -fmul st(2)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(2));
    // 004b5205  d94708                 -fld dword ptr [edi + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(8) /* 0x8 */)));
    // 004b5208  d8cb                   -fmul st(3)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(3));
    // 004b520a  d9470c                 -fld dword ptr [edi + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(12) /* 0xc */)));
    // 004b520d  d8cc                   -fmul st(4)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(4));
    // 004b520f  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004b5211  d84504                 -fadd dword ptr [ebp + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */));
    // 004b5214  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004b5216  d8450c                 -fadd dword ptr [ebp + 0xc]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */));
    // 004b5219  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b521b  d84514                 -fadd dword ptr [ebp + 0x14]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(20) /* 0x14 */));
    // 004b521e  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004b5220  d8451c                 -fadd dword ptr [ebp + 0x1c]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(28) /* 0x1c */));
    // 004b5223  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004b5225  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b5228  d95d0c                 -fstp dword ptr [ebp + 0xc]
    app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b522b  d95d1c                 -fstp dword ptr [ebp + 0x1c]
    app->getMemory<float>(cpu.ebp + x86::reg32(28) /* 0x1c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b522e  d95d14                 -fstp dword ptr [ebp + 0x14]
    app->getMemory<float>(cpu.ebp + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b5231  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b5234  83c520                 -add ebp, 0x20
    (cpu.ebp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004b5237  83e904                 +sub ecx, 4
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
    // 004b523a  7fc0                   -jg 0x4b51fc
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b51fc;
    }
    // 004b523c  83c103                 -add ecx, 3
    (cpu.ecx) += x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x004b523f:
    // 004b523f  83f900                 +cmp ecx, 0
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
    // 004b5242  7e15                   -jle 0x4b5259
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b5259;
    }
    // 004b5244  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004b5246  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004b5248  d84504                 -fadd dword ptr [ebp + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */));
    // 004b524b  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b524e  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b5251  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b5254  83e901                 +sub ecx, 1
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
    // 004b5257  7fe6                   -jg 0x4b523f
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b523f;
    }
L_0x004b5259:
    // 004b5259  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b525b  61                     -popal 
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
    // 004b525c  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b525d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b525e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b525e);
    // 004b525e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b525f  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b5261  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004b5262  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b5265  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b5268  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b526b  d906                   -fld dword ptr [esi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi)));
    // 004b526d  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004b5270  83f901                 +cmp ecx, 1
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
    // 004b5273  7e41                   -jle 0x4b52b6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b52b6;
    }
    // 004b5275  83e901                 -sub ecx, 1
    (cpu.ecx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004b5278:
    // 004b5278  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004b527a  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004b527c  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004b527e  d94704                 -fld dword ptr [edi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 004b5281  d8cb                   -fmul st(3)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(3));
    // 004b5283  d94704                 -fld dword ptr [edi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 004b5286  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004b5288  d84500                 -fadd dword ptr [ebp]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp));
    // 004b528b  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004b528d  d84504                 -fadd dword ptr [ebp + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */));
    // 004b5290  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b5292  d84508                 -fadd dword ptr [ebp + 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */));
    // 004b5295  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004b5297  d8450c                 -fadd dword ptr [ebp + 0xc]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */));
    // 004b529a  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004b529c  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b529f  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b52a2  d95d0c                 -fstp dword ptr [ebp + 0xc]
    app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b52a5  d95d08                 -fstp dword ptr [ebp + 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b52a8  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b52ab  83c510                 -add ebp, 0x10
    (cpu.ebp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b52ae  83e902                 +sub ecx, 2
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
    // 004b52b1  7fc5                   -jg 0x4b5278
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b5278;
    }
    // 004b52b3  83c101                 -add ecx, 1
    (cpu.ecx) += x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004b52b6:
    // 004b52b6  83f900                 +cmp ecx, 0
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
    // 004b52b9  7e23                   -jle 0x4b52de
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b52de;
    }
    // 004b52bb  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004b52bd  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004b52bf  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004b52c1  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b52c3  d84500                 -fadd dword ptr [ebp]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp));
    // 004b52c6  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b52c8  d84504                 -fadd dword ptr [ebp + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */));
    // 004b52cb  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b52cd  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b52d0  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b52d3  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b52d6  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b52d9  83e901                 +sub ecx, 1
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
    // 004b52dc  7fd8                   -jg 0x4b52b6
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b52b6;
    }
L_0x004b52de:
    // 004b52de  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b52e0  61                     -popal 
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
    // 004b52e1  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b52e2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b52e3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b52e3);
    // 004b52e3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b52e4  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b52e6  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004b52e7  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b52ea  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b52ed  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b52f0  d94604                 -fld dword ptr [esi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 004b52f3  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004b52f6  83f901                 +cmp ecx, 1
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
    // 004b52f9  7e41                   -jle 0x4b533c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b533c;
    }
    // 004b52fb  83e901                 -sub ecx, 1
    (cpu.ecx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004b52fe:
    // 004b52fe  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004b5300  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004b5302  d8ca                   -fmul st(2)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(2));
    // 004b5304  d94704                 -fld dword ptr [edi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 004b5307  d94704                 -fld dword ptr [edi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 004b530a  d8cc                   -fmul st(4)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(4));
    // 004b530c  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004b530e  d84500                 -fadd dword ptr [ebp]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp));
    // 004b5311  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004b5313  d84504                 -fadd dword ptr [ebp + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */));
    // 004b5316  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b5318  d84508                 -fadd dword ptr [ebp + 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */));
    // 004b531b  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004b531d  d8450c                 -fadd dword ptr [ebp + 0xc]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */));
    // 004b5320  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004b5322  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b5325  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b5328  d95d0c                 -fstp dword ptr [ebp + 0xc]
    app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b532b  d95d08                 -fstp dword ptr [ebp + 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b532e  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b5331  83c510                 -add ebp, 0x10
    (cpu.ebp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b5334  83e902                 +sub ecx, 2
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
    // 004b5337  7fc5                   -jg 0x4b52fe
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b52fe;
    }
    // 004b5339  83c101                 -add ecx, 1
    (cpu.ecx) += x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004b533c:
    // 004b533c  83f900                 +cmp ecx, 0
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
    // 004b533f  7e23                   -jle 0x4b5364
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b5364;
    }
    // 004b5341  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004b5343  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004b5345  d8ca                   -fmul st(2)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(2));
    // 004b5347  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b5349  d84500                 -fadd dword ptr [ebp]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp));
    // 004b534c  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b534e  d84504                 -fadd dword ptr [ebp + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */));
    // 004b5351  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b5353  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b5356  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b5359  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b535c  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b535f  83e901                 +sub ecx, 1
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
    // 004b5362  7fd8                   -jg 0x4b533c
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b533c;
    }
L_0x004b5364:
    // 004b5364  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b5366  61                     -popal 
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
    // 004b5367  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5368  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b5369(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b5369);
    // 004b5369  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b536a  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b536c  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b536d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4b5370(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b5370);
    // 004b5370  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b5371  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b5373  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b5374  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b5375  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b5378  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b537b  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b537e  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b5381  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004b5384  c7008e534b00           -mov dword ptr [eax], 0x4b538e
    app->getMemory<x86::reg32>(cpu.eax) = 4936590 /*0x4b538e*/;
    // 004b538a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b538b  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b538c  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b538d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b538e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b538e);
    // 004b538e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b538f  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b5391  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b5392  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b5393  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b5394  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b5395  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b5398  8b4e08                 -mov ecx, dword ptr [esi + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004b539b  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b539e  8b5d10                 -mov ebx, dword ptr [ebp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b53a1  db450c                 -fild dword ptr [ebp + 0xc]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */))));
    // 004b53a4  db4510                 -fild dword ptr [ebp + 0x10]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */))));
    // 004b53a7  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b53a9  d80d1c054e00           -fmul dword ptr [0x4e051c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5113116) /* 0x4e051c */));
    // 004b53af  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b53b1  d80d1c054e00           -fmul dword ptr [0x4e051c]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(x86::reg32(5113116) /* 0x4e051c */));
    // 004b53b7  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b53b9  d91e                   -fstp dword ptr [esi]
    app->getMemory<float>(cpu.esi) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b53bb  d95e04                 -fstp dword ptr [esi + 4]
    app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b53be  83f800                 +cmp eax, 0
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
    // 004b53c1  7417                   -je 0x4b53da
    if (cpu.flags.zf)
    {
        goto L_0x004b53da;
    }
    // 004b53c3  83fb00                 +cmp ebx, 0
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b53c6  7448                   -je 0x4b5410
    if (cpu.flags.zf)
    {
        goto L_0x004b5410;
    }
    // 004b53c8  83f87f                 +cmp eax, 0x7f
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
    // 004b53cb  7414                   -je 0x4b53e1
    if (cpu.flags.zf)
    {
        goto L_0x004b53e1;
    }
    // 004b53cd  83fb7f                 +cmp ebx, 0x7f
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
    // 004b53d0  742e                   -je 0x4b5400
    if (cpu.flags.zf)
    {
        goto L_0x004b5400;
    }
    // 004b53d2  c7011e544b00           -mov dword ptr [ecx], 0x4b541e
    app->getMemory<x86::reg32>(cpu.ecx) = 4936734 /*0x4b541e*/;
    // 004b53d8  eb3e                   -jmp 0x4b5418
    goto L_0x004b5418;
L_0x004b53da:
    // 004b53da  83fb00                 +cmp ebx, 0
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b53dd  7409                   -je 0x4b53e8
    if (cpu.flags.zf)
    {
        goto L_0x004b53e8;
    }
    // 004b53df  eb27                   -jmp 0x4b5408
    goto L_0x004b5408;
L_0x004b53e1:
    // 004b53e1  83fb7f                 +cmp ebx, 0x7f
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
    // 004b53e4  740a                   -je 0x4b53f0
    if (cpu.flags.zf)
    {
        goto L_0x004b53f0;
    }
    // 004b53e6  eb10                   -jmp 0x4b53f8
    goto L_0x004b53f8;
L_0x004b53e8:
    // 004b53e8  c7012b574b00           -mov dword ptr [ecx], 0x4b572b
    app->getMemory<x86::reg32>(cpu.ecx) = 4937515 /*0x4b572b*/;
    // 004b53ee  eb28                   -jmp 0x4b5418
    goto L_0x004b5418;
L_0x004b53f0:
    // 004b53f0  c701b0544b00           -mov dword ptr [ecx], 0x4b54b0
    app->getMemory<x86::reg32>(cpu.ecx) = 4936880 /*0x4b54b0*/;
    // 004b53f6  eb20                   -jmp 0x4b5418
    goto L_0x004b5418;
L_0x004b53f8:
    // 004b53f8  c701a3564b00           -mov dword ptr [ecx], 0x4b56a3
    app->getMemory<x86::reg32>(cpu.ecx) = 4937379 /*0x4b56a3*/;
    // 004b53fe  eb18                   -jmp 0x4b5418
    goto L_0x004b5418;
L_0x004b5400:
    // 004b5400  c7011c564b00           -mov dword ptr [ecx], 0x4b561c
    app->getMemory<x86::reg32>(cpu.ecx) = 4937244 /*0x4b561c*/;
    // 004b5406  eb10                   -jmp 0x4b5418
    goto L_0x004b5418;
L_0x004b5408:
    // 004b5408  c7019d554b00           -mov dword ptr [ecx], 0x4b559d
    app->getMemory<x86::reg32>(cpu.ecx) = 4937117 /*0x4b559d*/;
    // 004b540e  eb08                   -jmp 0x4b5418
    goto L_0x004b5418;
L_0x004b5410:
    // 004b5410  c70121554b00           -mov dword ptr [ecx], 0x4b5521
    app->getMemory<x86::reg32>(cpu.ecx) = 4936993 /*0x4b5521*/;
    // 004b5416  eb00                   -jmp 0x4b5418
    goto L_0x004b5418;
L_0x004b5418:
    // 004b5418  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5419  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b541a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b541b  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b541c  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b541d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b541e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b541e);
    // 004b541e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b541f  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b5421  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004b5422  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b5425  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b5428  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b542b  d94604                 -fld dword ptr [esi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 004b542e  d906                   -fld dword ptr [esi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi)));
    // 004b5430  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004b5433  83f901                 +cmp ecx, 1
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
    // 004b5436  7e46                   -jle 0x4b547e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b547e;
    }
    // 004b5438  83e901                 -sub ecx, 1
    (cpu.ecx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004b543b:
    // 004b543b  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004b543d  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004b543f  d94704                 -fld dword ptr [edi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 004b5442  d8cb                   -fmul st(3)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(3));
    // 004b5444  d94708                 -fld dword ptr [edi + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(8) /* 0x8 */)));
    // 004b5447  d8cb                   -fmul st(3)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(3));
    // 004b5449  d9470c                 -fld dword ptr [edi + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(12) /* 0xc */)));
    // 004b544c  d8cd                   -fmul st(5)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(5));
    // 004b544e  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004b5450  d84500                 -fadd dword ptr [ebp]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp));
    // 004b5453  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004b5455  d84504                 -fadd dword ptr [ebp + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */));
    // 004b5458  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b545a  d84508                 -fadd dword ptr [ebp + 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */));
    // 004b545d  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004b545f  d8450c                 -fadd dword ptr [ebp + 0xc]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */));
    // 004b5462  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004b5464  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b5467  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b546a  d95d0c                 -fstp dword ptr [ebp + 0xc]
    app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b546d  d95d08                 -fstp dword ptr [ebp + 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b5470  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b5473  83c510                 -add ebp, 0x10
    (cpu.ebp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b5476  83e902                 +sub ecx, 2
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
    // 004b5479  7fc0                   -jg 0x4b543b
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b543b;
    }
    // 004b547b  83c101                 -add ecx, 1
    (cpu.ecx) += x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004b547e:
    // 004b547e  83f900                 +cmp ecx, 0
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
    // 004b5481  7e26                   -jle 0x4b54a9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b54a9;
    }
    // 004b5483  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004b5485  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004b5487  d94704                 -fld dword ptr [edi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 004b548a  d8cb                   -fmul st(3)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(3));
    // 004b548c  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b548e  d84500                 -fadd dword ptr [ebp]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp));
    // 004b5491  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b5493  d84504                 -fadd dword ptr [ebp + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */));
    // 004b5496  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b5498  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b549b  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b549e  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b54a1  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b54a4  83e901                 +sub ecx, 1
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
    // 004b54a7  7fd5                   -jg 0x4b547e
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b547e;
    }
L_0x004b54a9:
    // 004b54a9  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b54ab  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b54ad  61                     -popal 
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
    // 004b54ae  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b54af  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b54b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b54b0);
    // 004b54b0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b54b1  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b54b3  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004b54b4  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b54b7  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b54ba  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b54bd  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004b54c0  83f901                 +cmp ecx, 1
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
    // 004b54c3  7e36                   -jle 0x4b54fb
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b54fb;
    }
    // 004b54c5  83e901                 -sub ecx, 1
    (cpu.ecx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004b54c8:
    // 004b54c8  d94500                 -fld dword ptr [ebp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp)));
    // 004b54cb  d807                   -fadd dword ptr [edi]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edi));
    // 004b54cd  d94504                 -fld dword ptr [ebp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */)));
    // 004b54d0  d84704                 -fadd dword ptr [edi + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */));
    // 004b54d3  d94508                 -fld dword ptr [ebp + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */)));
    // 004b54d6  d84708                 -fadd dword ptr [edi + 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(8) /* 0x8 */));
    // 004b54d9  d9450c                 -fld dword ptr [ebp + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */)));
    // 004b54dc  d8470c                 -fadd dword ptr [edi + 0xc]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(12) /* 0xc */));
    // 004b54df  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004b54e1  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b54e4  d95d08                 -fstp dword ptr [ebp + 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b54e7  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b54ea  d95d0c                 -fstp dword ptr [ebp + 0xc]
    app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b54ed  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b54f0  83c510                 -add ebp, 0x10
    (cpu.ebp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b54f3  83e902                 +sub ecx, 2
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
    // 004b54f6  7fd0                   -jg 0x4b54c8
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b54c8;
    }
    // 004b54f8  83c101                 -add ecx, 1
    (cpu.ecx) += x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004b54fb:
    // 004b54fb  83f900                 +cmp ecx, 0
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
    // 004b54fe  7e1e                   -jle 0x4b551e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b551e;
    }
    // 004b5500  d94500                 -fld dword ptr [ebp]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp)));
    // 004b5503  d807                   -fadd dword ptr [edi]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edi));
    // 004b5505  d94504                 -fld dword ptr [ebp + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */)));
    // 004b5508  d84704                 -fadd dword ptr [edi + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */));
    // 004b550b  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b550d  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b5510  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b5513  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b5516  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b5519  83e901                 +sub ecx, 1
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
    // 004b551c  7fdd                   -jg 0x4b54fb
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b54fb;
    }
L_0x004b551e:
    // 004b551e  61                     -popal 
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
    // 004b551f  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5520  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b5521(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b5521);
    // 004b5521  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b5522  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b5524  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004b5525  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b5528  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b552b  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b552e  d906                   -fld dword ptr [esi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi)));
    // 004b5530  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004b5533  83f903                 +cmp ecx, 3
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
    // 004b5536  7e46                   -jle 0x4b557e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b557e;
    }
    // 004b5538  83e903                 -sub ecx, 3
    (cpu.ecx) -= x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x004b553b:
    // 004b553b  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004b553d  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004b553f  d94708                 -fld dword ptr [edi + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(8) /* 0x8 */)));
    // 004b5542  d8ca                   -fmul st(2)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(2));
    // 004b5544  d94710                 -fld dword ptr [edi + 0x10]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(16) /* 0x10 */)));
    // 004b5547  d8cb                   -fmul st(3)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(3));
    // 004b5549  d94718                 -fld dword ptr [edi + 0x18]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(24) /* 0x18 */)));
    // 004b554c  d8cc                   -fmul st(4)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(4));
    // 004b554e  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004b5550  d84500                 -fadd dword ptr [ebp]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp));
    // 004b5553  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004b5555  d84508                 -fadd dword ptr [ebp + 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */));
    // 004b5558  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b555a  d84510                 -fadd dword ptr [ebp + 0x10]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(16) /* 0x10 */));
    // 004b555d  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004b555f  d84518                 -fadd dword ptr [ebp + 0x18]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(24) /* 0x18 */));
    // 004b5562  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004b5564  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b5567  d95d08                 -fstp dword ptr [ebp + 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b556a  d95d18                 -fstp dword ptr [ebp + 0x18]
    app->getMemory<float>(cpu.ebp + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b556d  d95d10                 -fstp dword ptr [ebp + 0x10]
    app->getMemory<float>(cpu.ebp + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b5570  83c720                 -add edi, 0x20
    (cpu.edi) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004b5573  83c520                 -add ebp, 0x20
    (cpu.ebp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004b5576  83e904                 +sub ecx, 4
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
    // 004b5579  7fc0                   -jg 0x4b553b
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b553b;
    }
    // 004b557b  83c103                 -add ecx, 3
    (cpu.ecx) += x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x004b557e:
    // 004b557e  83f900                 +cmp ecx, 0
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
    // 004b5581  7e15                   -jle 0x4b5598
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b5598;
    }
    // 004b5583  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004b5585  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004b5587  d84500                 -fadd dword ptr [ebp]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp));
    // 004b558a  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b558d  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b5590  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b5593  83e901                 +sub ecx, 1
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
    // 004b5596  7fe6                   -jg 0x4b557e
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b557e;
    }
L_0x004b5598:
    // 004b5598  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b559a  61                     -popal 
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
    // 004b559b  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b559c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b559d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b559d);
    // 004b559d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b559e  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b55a0  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004b55a1  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b55a4  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b55a7  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b55aa  d94604                 -fld dword ptr [esi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 004b55ad  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004b55b0  83f903                 +cmp ecx, 3
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
    // 004b55b3  7e47                   -jle 0x4b55fc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b55fc;
    }
    // 004b55b5  83e903                 -sub ecx, 3
    (cpu.ecx) -= x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x004b55b8:
    // 004b55b8  d94704                 -fld dword ptr [edi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 004b55bb  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004b55bd  d9470c                 -fld dword ptr [edi + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(12) /* 0xc */)));
    // 004b55c0  d8ca                   -fmul st(2)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(2));
    // 004b55c2  d94714                 -fld dword ptr [edi + 0x14]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(20) /* 0x14 */)));
    // 004b55c5  d8cb                   -fmul st(3)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(3));
    // 004b55c7  d9471c                 -fld dword ptr [edi + 0x1c]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(28) /* 0x1c */)));
    // 004b55ca  d8cc                   -fmul st(4)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(4));
    // 004b55cc  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004b55ce  d84504                 -fadd dword ptr [ebp + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */));
    // 004b55d1  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004b55d3  d8450c                 -fadd dword ptr [ebp + 0xc]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */));
    // 004b55d6  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b55d8  d84514                 -fadd dword ptr [ebp + 0x14]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(20) /* 0x14 */));
    // 004b55db  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004b55dd  d8451c                 -fadd dword ptr [ebp + 0x1c]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(28) /* 0x1c */));
    // 004b55e0  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004b55e2  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b55e5  d95d0c                 -fstp dword ptr [ebp + 0xc]
    app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b55e8  d95d1c                 -fstp dword ptr [ebp + 0x1c]
    app->getMemory<float>(cpu.ebp + x86::reg32(28) /* 0x1c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b55eb  d95d14                 -fstp dword ptr [ebp + 0x14]
    app->getMemory<float>(cpu.ebp + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b55ee  83c720                 -add edi, 0x20
    (cpu.edi) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004b55f1  83c520                 -add ebp, 0x20
    (cpu.ebp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004b55f4  83e904                 +sub ecx, 4
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
    // 004b55f7  7fbf                   -jg 0x4b55b8
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b55b8;
    }
    // 004b55f9  83c103                 -add ecx, 3
    (cpu.ecx) += x86::reg32(x86::sreg32(3 /*0x3*/));
L_0x004b55fc:
    // 004b55fc  83f900                 +cmp ecx, 0
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
    // 004b55ff  7e16                   -jle 0x4b5617
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b5617;
    }
    // 004b5601  d94704                 -fld dword ptr [edi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 004b5604  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004b5606  d84504                 -fadd dword ptr [ebp + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */));
    // 004b5609  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b560c  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b560f  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b5612  83e901                 +sub ecx, 1
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
    // 004b5615  7fe5                   -jg 0x4b55fc
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b55fc;
    }
L_0x004b5617:
    // 004b5617  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b5619  61                     -popal 
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
    // 004b561a  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b561b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b561c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b561c);
    // 004b561c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b561d  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b561f  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004b5620  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b5623  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b5626  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b5629  d906                   -fld dword ptr [esi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi)));
    // 004b562b  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004b562e  83f901                 +cmp ecx, 1
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
    // 004b5631  7e42                   -jle 0x4b5675
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b5675;
    }
    // 004b5633  83e901                 -sub ecx, 1
    (cpu.ecx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004b5636:
    // 004b5636  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004b5638  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004b563a  d94704                 -fld dword ptr [edi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 004b563d  d94708                 -fld dword ptr [edi + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(8) /* 0x8 */)));
    // 004b5640  d8cb                   -fmul st(3)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(3));
    // 004b5642  d9470c                 -fld dword ptr [edi + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(12) /* 0xc */)));
    // 004b5645  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004b5647  d84500                 -fadd dword ptr [ebp]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp));
    // 004b564a  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004b564c  d84504                 -fadd dword ptr [ebp + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */));
    // 004b564f  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b5651  d84508                 -fadd dword ptr [ebp + 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */));
    // 004b5654  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004b5656  d8450c                 -fadd dword ptr [ebp + 0xc]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */));
    // 004b5659  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004b565b  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b565e  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b5661  d95d0c                 -fstp dword ptr [ebp + 0xc]
    app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b5664  d95d08                 -fstp dword ptr [ebp + 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b5667  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b566a  83c510                 -add ebp, 0x10
    (cpu.ebp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b566d  83e902                 +sub ecx, 2
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
    // 004b5670  7fc4                   -jg 0x4b5636
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b5636;
    }
    // 004b5672  83c101                 -add ecx, 1
    (cpu.ecx) += x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004b5675:
    // 004b5675  83f900                 +cmp ecx, 0
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
    // 004b5678  7e24                   -jle 0x4b569e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b569e;
    }
    // 004b567a  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004b567c  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004b567e  d94704                 -fld dword ptr [edi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 004b5681  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b5683  d84500                 -fadd dword ptr [ebp]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp));
    // 004b5686  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b5688  d84504                 -fadd dword ptr [ebp + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */));
    // 004b568b  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b568d  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b5690  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b5693  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b5696  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b5699  83e901                 +sub ecx, 1
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
    // 004b569c  7fd7                   -jg 0x4b5675
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b5675;
    }
L_0x004b569e:
    // 004b569e  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b56a0  61                     -popal 
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
    // 004b56a1  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b56a2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b56a3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b56a3);
    // 004b56a3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b56a4  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b56a6  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004b56a7  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b56aa  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b56ad  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b56b0  d94604                 -fld dword ptr [esi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */)));
    // 004b56b3  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004b56b6  83f901                 +cmp ecx, 1
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
    // 004b56b9  7e42                   -jle 0x4b56fd
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b56fd;
    }
    // 004b56bb  83e901                 -sub ecx, 1
    (cpu.ecx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004b56be:
    // 004b56be  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004b56c0  d94704                 -fld dword ptr [edi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 004b56c3  d8ca                   -fmul st(2)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(2));
    // 004b56c5  d94708                 -fld dword ptr [edi + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(8) /* 0x8 */)));
    // 004b56c8  d9470c                 -fld dword ptr [edi + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(12) /* 0xc */)));
    // 004b56cb  d8cc                   -fmul st(4)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(4));
    // 004b56cd  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004b56cf  d84500                 -fadd dword ptr [ebp]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp));
    // 004b56d2  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004b56d4  d84504                 -fadd dword ptr [ebp + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */));
    // 004b56d7  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b56d9  d84508                 -fadd dword ptr [ebp + 8]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */));
    // 004b56dc  d9cb                   -fxch st(3)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(3);
        cpu.fpu.st(3) = tmp;
    }
    // 004b56de  d8450c                 -fadd dword ptr [ebp + 0xc]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */));
    // 004b56e1  d9ca                   -fxch st(2)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(2);
        cpu.fpu.st(2) = tmp;
    }
    // 004b56e3  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b56e6  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b56e9  d95d0c                 -fstp dword ptr [ebp + 0xc]
    app->getMemory<float>(cpu.ebp + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b56ec  d95d08                 -fstp dword ptr [ebp + 8]
    app->getMemory<float>(cpu.ebp + x86::reg32(8) /* 0x8 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b56ef  83c710                 -add edi, 0x10
    (cpu.edi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b56f2  83c510                 -add ebp, 0x10
    (cpu.ebp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b56f5  83e902                 +sub ecx, 2
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
    // 004b56f8  7fc4                   -jg 0x4b56be
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b56be;
    }
    // 004b56fa  83c101                 -add ecx, 1
    (cpu.ecx) += x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004b56fd:
    // 004b56fd  83f900                 +cmp ecx, 0
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
    // 004b5700  7e24                   -jle 0x4b5726
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b5726;
    }
    // 004b5702  d907                   -fld dword ptr [edi]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi)));
    // 004b5704  d94704                 -fld dword ptr [edi + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 004b5707  d8ca                   -fmul st(2)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(2));
    // 004b5709  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b570b  d84500                 -fadd dword ptr [ebp]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp));
    // 004b570e  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b5710  d84504                 -fadd dword ptr [ebp + 4]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */));
    // 004b5713  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004b5715  d95d00                 -fstp dword ptr [ebp]
    app->getMemory<float>(cpu.ebp) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b5718  d95d04                 -fstp dword ptr [ebp + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b571b  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b571e  83c508                 -add ebp, 8
    (cpu.ebp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b5721  83e901                 +sub ecx, 1
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
    // 004b5724  7fd7                   -jg 0x4b56fd
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b56fd;
    }
L_0x004b5726:
    // 004b5726  ddd8                   -fstp st(0)
    cpu.fpu.st(0) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b5728  61                     -popal 
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
    // 004b5729  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b572a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b572b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b572b);
    // 004b572b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b572c  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b572e  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b572f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b5730(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b5730);
    // 004b5730  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b5731  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b5733  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b5734  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b5737  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 004b573d  c7460c00000000         -mov dword ptr [esi + 0xc], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 004b5744  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b5747  c70070574b00           -mov dword ptr [eax], 0x4b5770
    app->getMemory<x86::reg32>(cpu.eax) = 4937584 /*0x4b5770*/;
    // 004b574d  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004b5750  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b5753  c70085574b00           -mov dword ptr [eax], 0x4b5785
    app->getMemory<x86::reg32>(cpu.eax) = 4937605 /*0x4b5785*/;
    // 004b5759  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004b575c  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004b575f  c700cb574b00           -mov dword ptr [eax], 0x4b57cb
    app->getMemory<x86::reg32>(cpu.eax) = 4937675 /*0x4b57cb*/;
    // 004b5765  894618                 -mov dword ptr [esi + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004b5768  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5769  b800000000             -mov eax, 0
    cpu.eax = 0 /*0x0*/;
    // 004b576e  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b576f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b5770(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b5770);
    // 004b5770  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b5771  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b5773  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b5774  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b5777  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b577a  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004b577d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b577e  b800000000             -mov eax, 0
    cpu.eax = 0 /*0x0*/;
    // 004b5783  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5784  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b5785(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b5785);
    // 004b5785  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b5786  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b5788  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b5789  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b578c  817e0400000100         +cmp dword ptr [esi + 4], 0x10000
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
    // 004b5793  7c08                   -jl 0x4b579d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b579d;
    }
    // 004b5795  7f1e                   -jg 0x4b57b5
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b57b5;
    }
    // 004b5797  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5798  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b579b  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b579c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b579d:
    // 004b579d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b579e  8b550c                 -mov edx, dword ptr [ebp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b57a1  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b57a4  4a                     -dec edx
    (cpu.edx)--;
    // 004b57a5  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004b57a8  0306                   -add eax, dword ptr [esi]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi)));
    // 004b57aa  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b57ab  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b57ae  40                     -inc eax
    (cpu.eax)++;
    // 004b57af  2b460c                 -sub eax, dword ptr [esi + 0xc]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */)));
    // 004b57b2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b57b3  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b57b4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b57b5:
    // 004b57b5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b57b6  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b57b9  8b550c                 -mov edx, dword ptr [ebp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b57bc  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004b57bf  0306                   -add eax, dword ptr [esi]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi)));
    // 004b57c1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b57c2  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b57c5  2b460c                 -sub eax, dword ptr [esi + 0xc]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */)));
    // 004b57c8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b57c9  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b57ca  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b57cb(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b57cb);
    // 004b57cb  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b57cc  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b57ce  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b57cf  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b57d2  817e0400000100         +cmp dword ptr [esi + 4], 0x10000
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
    // 004b57d9  750f                   -jne 0x4b57ea
    if (!cpu.flags.zf)
    {
        goto L_0x004b57ea;
    }
    // 004b57db  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b57dc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b57dd  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004b57e0  8b5d10                 -mov ebx, dword ptr [ebp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b57e3  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 004b57e5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b57e6  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b57e7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b57e8  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b57e9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b57ea:
    // 004b57ea  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004b57eb  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004b57ed  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004b57f0  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b57f3  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b57f6  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004b57f9  8b38                   -mov edi, dword ptr [eax]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax);
    // 004b57fb  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 004b57fe  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004b5801  03cf                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004b5803  a320054e00             -mov dword ptr [0x4e0520], eax
    app->getMemory<x86::reg32>(x86::reg32(5113120) /* 0x4e0520 */) = cpu.eax;
    // 004b5808  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004b580b  8b7510                 -mov esi, dword ptr [ebp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b580e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b580f  c1ee02                 -shr esi, 2
    cpu.esi >>= 2 /*0x2*/ % 32;
    // 004b5812  8beb                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004b5814  c1eb10                 -shr ebx, 0x10
    cpu.ebx >>= 16 /*0x10*/ % 32;
    // 004b5817  c1e510                 -shl ebp, 0x10
    cpu.ebp <<= 16 /*0x10*/ % 32;
    // 004b581a  83f801                 +cmp eax, 1
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
    // 004b581d  751c                   -jne 0x4b583b
    if (!cpu.flags.zf)
    {
        goto L_0x004b583b;
    }
    // 004b581f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b5820  be00000000             -mov esi, 0
    cpu.esi = 0 /*0x0*/;
L_0x004b5825:
    // 004b5825  a120054e00             -mov eax, dword ptr [0x4e0520]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5113120) /* 0x4e0520 */);
    // 004b582a  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 004b582c  03d5                   +add edx, ebp
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
    // 004b582e  13f3                   -adc esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx) + cpu.flags.cf);
    // 004b5830  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b5833  83fe00                 +cmp esi, 0
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
    // 004b5836  74ed                   -je 0x4b5825
    if (cpu.flags.zf)
    {
        goto L_0x004b5825;
    }
    // 004b5838  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5839  90                     -nop 
    ;
    // 004b583a  90                     -nop 
    ;
L_0x004b583b:
    // 004b583b  8b04b500000000         -mov eax, dword ptr [esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi * 4);
    // 004b5842  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 004b5844  03d5                   +add edx, ebp
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
    // 004b5846  13f3                   -adc esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx) + cpu.flags.cf);
    // 004b5848  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b584b  3bf9                   +cmp edi, ecx
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
    // 004b584d  7cec                   -jl 0x4b583b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b583b;
    }
    // 004b584f  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004b5852  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5853  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b5856  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 004b5858  3b5e04                 +cmp ebx, dword ptr [esi + 4]
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
    // 004b585b  7c11                   -jl 0x4b586e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b586e;
    }
    // 004b585d  8b47fc                 -mov eax, dword ptr [edi - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-4) /* -0x4 */);
    // 004b5860  c7460c01000000         -mov dword ptr [esi + 0xc], 1
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = 1 /*0x1*/;
    // 004b5867  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b586a  61                     -popal 
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
    // 004b586b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b586c  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b586d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b586e:
    // 004b586e  c7460c00000000         -mov dword ptr [esi + 0xc], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = 0 /*0x0*/;
    // 004b5875  61                     -popal 
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
    // 004b5876  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5877  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5878  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_4b587c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b587c);
    // 004b587c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b587d  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b587f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b5880  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b5883  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
    // 004b5889  c7461000000000         -mov dword ptr [esi + 0x10], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 004b5890  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b5893  c700bc584b00           -mov dword ptr [eax], 0x4b58bc
    app->getMemory<x86::reg32>(cpu.eax) = 4937916 /*0x4b58bc*/;
    // 004b5899  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004b589c  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b589f  c700d1584b00           -mov dword ptr [eax], 0x4b58d1
    app->getMemory<x86::reg32>(cpu.eax) = 4937937 /*0x4b58d1*/;
    // 004b58a5  894618                 -mov dword ptr [esi + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004b58a8  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004b58ab  c70017594b00           -mov dword ptr [eax], 0x4b5917
    app->getMemory<x86::reg32>(cpu.eax) = 4938007 /*0x4b5917*/;
    // 004b58b1  89461c                 -mov dword ptr [esi + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004b58b4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b58b5  b800000000             -mov eax, 0
    cpu.eax = 0 /*0x0*/;
    // 004b58ba  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b58bb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b58bc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b58bc);
    // 004b58bc  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b58bd  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b58bf  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b58c0  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b58c3  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b58c6  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004b58c9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b58ca  b800000000             -mov eax, 0
    cpu.eax = 0 /*0x0*/;
    // 004b58cf  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b58d0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b58d1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b58d1);
    // 004b58d1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b58d2  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b58d4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b58d5  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b58d8  817e0400000100         +cmp dword ptr [esi + 4], 0x10000
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
    // 004b58df  7c08                   -jl 0x4b58e9
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b58e9;
    }
    // 004b58e1  7f1e                   -jg 0x4b5901
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b5901;
    }
    // 004b58e3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b58e4  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b58e7  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b58e8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b58e9:
    // 004b58e9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b58ea  8b550c                 -mov edx, dword ptr [ebp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b58ed  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b58f0  4a                     -dec edx
    (cpu.edx)--;
    // 004b58f1  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004b58f4  0306                   -add eax, dword ptr [esi]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi)));
    // 004b58f6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b58f7  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b58fa  40                     -inc eax
    (cpu.eax)++;
    // 004b58fb  2b4610                 -sub eax, dword ptr [esi + 0x10]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */)));
    // 004b58fe  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b58ff  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5900  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b5901:
    // 004b5901  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b5902  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b5905  8b550c                 -mov edx, dword ptr [ebp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b5908  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004b590b  0306                   -add eax, dword ptr [esi]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi)));
    // 004b590d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b590e  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b5911  2b4610                 -sub eax, dword ptr [esi + 0x10]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */)));
    // 004b5914  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5915  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5916  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b5917(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b5917);
    // 004b5917  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b5918  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b591a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b591b  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b591e  817e0400000100         +cmp dword ptr [esi + 4], 0x10000
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
    // 004b5925  750f                   -jne 0x4b5936
    if (!cpu.flags.zf)
    {
        goto L_0x004b5936;
    }
    // 004b5927  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b5928  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b5929  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004b592c  8b5d10                 -mov ebx, dword ptr [ebp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b592f  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 004b5931  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5932  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5933  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5934  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5935  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b5936:
    // 004b5936  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004b5937  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004b5939  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004b593c  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b593f  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b5942  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004b5945  8b38                   -mov edi, dword ptr [eax]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax);
    // 004b5947  c1e103                 -shl ecx, 3
    cpu.ecx <<= 3 /*0x3*/ % 32;
    // 004b594a  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004b594d  03cf                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004b594f  a328054e00             -mov dword ptr [0x4e0528], eax
    app->getMemory<x86::reg32>(x86::reg32(5113128) /* 0x4e0528 */) = cpu.eax;
    // 004b5954  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004b5957  a32c054e00             -mov dword ptr [0x4e052c], eax
    app->getMemory<x86::reg32>(x86::reg32(5113132) /* 0x4e052c */) = cpu.eax;
    // 004b595c  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004b595f  8b7510                 -mov esi, dword ptr [ebp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b5962  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b5963  c1ee03                 -shr esi, 3
    cpu.esi >>= 3 /*0x3*/ % 32;
    // 004b5966  8beb                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004b5968  c1eb10                 -shr ebx, 0x10
    cpu.ebx >>= 16 /*0x10*/ % 32;
    // 004b596b  c1e510                 -shl ebp, 0x10
    cpu.ebp <<= 16 /*0x10*/ % 32;
    // 004b596e  83f801                 +cmp eax, 1
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
    // 004b5971  7522                   -jne 0x4b5995
    if (!cpu.flags.zf)
    {
        goto L_0x004b5995;
    }
    // 004b5973  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b5974  be00000000             -mov esi, 0
    cpu.esi = 0 /*0x0*/;
L_0x004b5979:
    // 004b5979  a128054e00             -mov eax, dword ptr [0x4e0528]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5113128) /* 0x4e0528 */);
    // 004b597e  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 004b5980  a12c054e00             -mov eax, dword ptr [0x4e052c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5113132) /* 0x4e052c */);
    // 004b5985  894704                 -mov dword ptr [edi + 4], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004b5988  03d5                   +add edx, ebp
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
    // 004b598a  13f3                   -adc esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx) + cpu.flags.cf);
    // 004b598c  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b598f  83fe00                 +cmp esi, 0
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
    // 004b5992  74e5                   -je 0x4b5979
    if (cpu.flags.zf)
    {
        goto L_0x004b5979;
    }
    // 004b5994  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004b5995:
    // 004b5995  892524054e00           -mov dword ptr [0x4e0524], esp
    app->getMemory<x86::reg32>(x86::reg32(5113124) /* 0x4e0524 */) = cpu.esp;
    // 004b599b  90                     -nop 
    ;
L_0x004b599c:
    // 004b599c  8b04f500000000         -mov eax, dword ptr [esi*8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi * 8);
    // 004b59a3  8b24f504000000         -mov esp, dword ptr [esi*8 + 4]
    cpu.esp = app->getMemory<x86::reg32>(x86::reg32(4) /* 0x4 */ + cpu.esi * 8);
    // 004b59aa  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 004b59ac  896704                 -mov dword ptr [edi + 4], esp
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.esp;
    // 004b59af  03d5                   +add edx, ebp
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
    // 004b59b1  13f3                   -adc esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx) + cpu.flags.cf);
    // 004b59b3  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b59b6  3bf9                   +cmp edi, ecx
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
    // 004b59b8  7ce2                   -jl 0x4b599c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b599c;
    }
    // 004b59ba  8b2524054e00           -mov esp, dword ptr [0x4e0524]
    cpu.esp = app->getMemory<x86::reg32>(x86::reg32(5113124) /* 0x4e0524 */);
    // 004b59c0  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004b59c3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b59c4  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b59c7  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 004b59c9  3b5e04                 +cmp ebx, dword ptr [esi + 4]
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
    // 004b59cc  7c17                   -jl 0x4b59e5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b59e5;
    }
    // 004b59ce  8b47f8                 -mov eax, dword ptr [edi - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-8) /* -0x8 */);
    // 004b59d1  c7461001000000         -mov dword ptr [esi + 0x10], 1
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = 1 /*0x1*/;
    // 004b59d8  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b59db  8b47fc                 -mov eax, dword ptr [edi - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(-4) /* -0x4 */);
    // 004b59de  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004b59e1  61                     -popal 
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
    // 004b59e2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b59e3  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b59e4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b59e5:
    // 004b59e5  c7461000000000         -mov dword ptr [esi + 0x10], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 004b59ec  61                     -popal 
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
    // 004b59ed  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b59ee  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b59ef  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b59f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b59f0);
    // 004b59f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b59f1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b59f2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b59f3  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b59f7  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004b59fb  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004b59fe  48                     -dec eax
    (cpu.eax)--;
    // 004b59ff  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004b5a02  034204                 -add eax, dword ptr [edx + 4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 004b5a05  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b5a08  8b5a13                 -mov ebx, dword ptr [edx + 0x13]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 004b5a0b  40                     -inc eax
    (cpu.eax)++;
    // 004b5a0c  c1fb18                 -sar ebx, 0x18
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (24 /*0x18*/ % 32));
    // 004b5a0f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b5a11  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b5a13  8a5a15                 -mov bl, byte ptr [edx + 0x15]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(21) /* 0x15 */);
    // 004b5a16  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b5a18  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 004b5a1a  7501                   -jne 0x4b5a1d
    if (!cpu.flags.zf)
    {
        goto L_0x004b5a1d;
    }
    // 004b5a1c  40                     -inc eax
    (cpu.eax)++;
L_0x004b5a1d:
    // 004b5a1d  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004b5a21  8b5108                 -mov edx, dword ptr [ecx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004b5a24  0fafd7                 -imul edx, edi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 004b5a27  035104                 -add edx, dword ptr [ecx + 4]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
    // 004b5a2a  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004b5a2d  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004b5a2f  885116                 -mov byte ptr [ecx + 0x16], dl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(22) /* 0x16 */) = cpu.dl;
    // 004b5a32  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5a33  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5a34  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5a35  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4b5a38(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b5a38);
    // 004b5a38  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b5a3c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4b5a40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b5a40);
    // 004b5a40  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b5a41  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b5a45  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b5a49  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004b5a4c  48                     -dec eax
    (cpu.eax)--;
    // 004b5a4d  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004b5a50  034204                 -add eax, dword ptr [edx + 4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 004b5a53  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b5a55  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b5a58  8a5a15                 -mov bl, byte ptr [edx + 0x15]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(21) /* 0x15 */);
    // 004b5a5b  40                     -inc eax
    (cpu.eax)++;
    // 004b5a5c  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 004b5a5e  7501                   -jne 0x4b5a61
    if (!cpu.flags.zf)
    {
        goto L_0x004b5a61;
    }
    // 004b5a60  40                     -inc eax
    (cpu.eax)++;
L_0x004b5a61:
    // 004b5a61  8b5111                 -mov edx, dword ptr [ecx + 0x11]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(17) /* 0x11 */);
    // 004b5a64  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004b5a67  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b5a69  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5a6a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4b5a6c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b5a6c);
    // 004b5a6c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b5a6d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b5a6e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b5a6f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b5a70  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004b5a73  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004b5a77  8b7c242c               -mov edi, dword ptr [esp + 0x2c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004b5a7b  8b542430               -mov edx, dword ptr [esp + 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004b5a7f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b5a81  8a4815                 -mov cl, byte ptr [eax + 0x15]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(21) /* 0x15 */);
    // 004b5a84  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004b5a86  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 004b5a88  7571                   -jne 0x4b5afb
    if (!cpu.flags.zf)
    {
        goto L_0x004b5afb;
    }
L_0x004b5a8a:
    // 004b5a8a  8b6c2434               -mov ebp, dword ptr [esp + 0x34]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004b5a8e  4f                     -dec edi
    (cpu.edi)--;
    // 004b5a8f  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp);
    // 004b5a92  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004b5a94  7f6f                   -jg 0x4b5b05
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b5b05;
    }
L_0x004b5a96:
    // 004b5a96  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b5a98  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b5a9b  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004b5a9f  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004b5aa2  df2c24                 -fild qword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.esp))));
    // 004b5aa5  dc0d18184d00           -fmul qword ptr [0x4d1818]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5052440) /* 0x4d1818 */));
    // 004b5aab  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004b5aad  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 004b5aaf  dee1                   -fsubrp st(1)
    cpu.fpu.st(1) = cpu.fpu.st(0) - x86::Float(cpu.fpu.st(1));
    cpu.fpu.pop();
    // 004b5ab1  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b5ab3  d9448604               -fld dword ptr [esi + eax*4 + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.eax * 4)));
    // 004b5ab7  deca                   -fmulp st(2)
    cpu.fpu.st(2) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b5ab9  d80c86                 -fmul dword ptr [esi + eax*4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + cpu.eax * 4));
    // 004b5abc  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b5abe  d95cbd00               -fstp dword ptr [ebp + edi*4]
    app->getMemory<float>(cpu.ebp + cpu.edi * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b5ac2  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b5ac4  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b5ac7  d9448604               -fld dword ptr [esi + eax*4 + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.eax * 4)));
    // 004b5acb  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b5ace  d95b10                 -fstp dword ptr [ebx + 0x10]
    app->getMemory<float>(cpu.ebx + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b5ad1  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b5ad3  8b33                   -mov esi, dword ptr [ebx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b5ad5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b5ad7  894b04                 -mov dword ptr [ebx + 4], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004b5ada  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b5add  66c743060000           -mov word ptr [ebx + 6], 0
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 004b5ae3  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b5ae5  8b4313                 -mov eax, dword ptr [ebx + 0x13]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(19) /* 0x13 */);
    // 004b5ae8  8933                   -mov dword ptr [ebx], esi
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.esi;
    // 004b5aea  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004b5aed  c6431501               -mov byte ptr [ebx + 0x15], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(21) /* 0x15 */) = 1 /*0x1*/;
    // 004b5af1  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004b5af3  83c414                 +add esp, 0x14
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
    // 004b5af6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5af7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5af8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5af9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5afa  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b5afb:
    // 004b5afb  8d72fc                 -lea esi, [edx - 4]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 004b5afe  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004b5b01  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 004b5b03  eb85                   -jmp 0x4b5a8a
    goto L_0x004b5a8a;
L_0x004b5b05:
    // 004b5b05  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b5b08  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b5b0b  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b5b0e  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004b5b11  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004b5b14  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b5b15  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004b5b18  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b5b19  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004b5b1d  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004b5b21  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b5b22  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b5b23  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b5b24  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b5b25  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b5b26  e889620000             -call 0x4bbdb4
    cpu.esp -= 4;
    sub_4bbdb4(app, cpu);
    if (cpu.terminate) return;
    // 004b5b2b  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004b5b2e  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b5b32  c1e810                 +shr eax, 0x10
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
    // 004b5b35  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004b5b38  e959ffffff             -jmp 0x4b5a96
    goto L_0x004b5a96;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4b5b40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b5b40);
    // 004b5b40  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b5b44  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b5b48  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004b5b4a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4b5b4c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b5b4c);
    // 004b5b4c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b5b4d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b5b4e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b5b4f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b5b50  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004b5b53  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004b5b57  8b7c242c               -mov edi, dword ptr [esp + 0x2c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004b5b5b  8b542430               -mov edx, dword ptr [esp + 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004b5b5f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b5b61  8a4815                 -mov cl, byte ptr [eax + 0x15]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(21) /* 0x15 */);
    // 004b5b64  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004b5b66  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 004b5b68  0f85c5000000           -jne 0x4b5c33
    if (!cpu.flags.zf)
    {
        goto L_0x004b5c33;
    }
L_0x004b5b6e:
    // 004b5b6e  807b1400               +cmp byte ptr [ebx + 0x14], 0
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
    // 004b5b72  7409                   -je 0x4b5b7d
    if (cpu.flags.zf)
    {
        goto L_0x004b5b7d;
    }
    // 004b5b74  8b430c                 -mov eax, dword ptr [ebx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004b5b77  8946fc                 -mov dword ptr [esi - 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004b5b7a  83ee04                 +sub esi, 4
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
L_0x004b5b7d:
    // 004b5b7d  8b6c2434               -mov ebp, dword ptr [esp + 0x34]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004b5b81  c70300000000           -mov dword ptr [ebx], 0
    app->getMemory<x86::reg32>(cpu.ebx) = 0 /*0x0*/;
    // 004b5b87  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp);
    // 004b5b8a  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004b5b8b  7433                   -je 0x4b5bc0
    if (cpu.flags.zf)
    {
        goto L_0x004b5bc0;
    }
    // 004b5b8d  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b5b90  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b5b93  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b5b96  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004b5b99  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004b5b9c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b5b9d  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004b5ba0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b5ba1  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004b5ba5  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004b5ba9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b5baa  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b5bab  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b5bac  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b5bad  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b5bae  e801620000             -call 0x4bbdb4
    cpu.esp -= 4;
    sub_4bbdb4(app, cpu);
    if (cpu.terminate) return;
    // 004b5bb3  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004b5bb6  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b5bba  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b5bbd  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x004b5bc0:
    // 004b5bc0  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b5bc2  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b5bc5  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004b5bc9  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004b5bcc  df2c24                 -fild qword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.esp))));
    // 004b5bcf  dc0d20184d00           -fmul qword ptr [0x4d1820]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5052448) /* 0x4d1820 */));
    // 004b5bd5  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004b5bd7  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 004b5bd9  dee1                   -fsubrp st(1)
    cpu.fpu.st(1) = cpu.fpu.st(0) - x86::Float(cpu.fpu.st(1));
    cpu.fpu.pop();
    // 004b5bdb  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b5bdd  d9448604               -fld dword ptr [esi + eax*4 + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.eax * 4)));
    // 004b5be1  deca                   -fmulp st(2)
    cpu.fpu.st(2) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b5be3  d80c86                 -fmul dword ptr [esi + eax*4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + cpu.eax * 4));
    // 004b5be6  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b5be8  d95cbd00               -fstp dword ptr [ebp + edi*4]
    app->getMemory<float>(cpu.ebp + cpu.edi * 4) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b5bec  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b5bee  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b5bf1  8b3b                   -mov edi, dword ptr [ebx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b5bf3  d9448604               -fld dword ptr [esi + eax*4 + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.eax * 4)));
    // 004b5bf7  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b5bfa  8b6b08                 -mov ebp, dword ptr [ebx + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b5bfd  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b5bff  d95b10                 -fstp dword ptr [ebx + 0x10]
    app->getMemory<float>(cpu.ebx + x86::reg32(16) /* 0x10 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b5c02  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b5c04  894b04                 -mov dword ptr [ebx + 4], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004b5c07  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b5c0a  66c743060000           -mov word ptr [ebx + 6], 0
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 004b5c10  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b5c12  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b5c15  893b                   -mov dword ptr [ebx], edi
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edi;
    // 004b5c17  39e8                   +cmp eax, ebp
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
    // 004b5c19  7225                   -jb 0x4b5c40
    if (cpu.flags.cf)
    {
        goto L_0x004b5c40;
    }
    // 004b5c1b  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b5c1d  c6431401               -mov byte ptr [ebx + 0x14], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(20) /* 0x14 */) = 1 /*0x1*/;
    // 004b5c21  8b1486                 -mov edx, dword ptr [esi + eax*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + cpu.eax * 4);
    // 004b5c24  89530c                 -mov dword ptr [ebx + 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004b5c27  c6431501               -mov byte ptr [ebx + 0x15], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(21) /* 0x15 */) = 1 /*0x1*/;
    // 004b5c2b  83c414                 +add esp, 0x14
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
    // 004b5c2e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5c2f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5c30  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5c31  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5c32  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b5c33:
    // 004b5c33  8d72fc                 -lea esi, [edx - 4]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 004b5c36  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004b5c39  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 004b5c3b  e92effffff             -jmp 0x4b5b6e
    goto L_0x004b5b6e;
L_0x004b5c40:
    // 004b5c40  c6431400               -mov byte ptr [ebx + 0x14], 0
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 004b5c44  c6431501               -mov byte ptr [ebx + 0x15], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(21) /* 0x15 */) = 1 /*0x1*/;
    // 004b5c48  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004b5c4b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5c4c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5c4d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5c4e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5c4f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b5c50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b5c50);
    // 004b5c50  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b5c51  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b5c52  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b5c56  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b5c5a  8b5908                 -mov ebx, dword ptr [ecx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004b5c5d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b5c5f  81fb00000100           +cmp ebx, 0x10000
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
    // 004b5c65  732c                   -jae 0x4b5c93
    if (!cpu.flags.cf)
    {
        goto L_0x004b5c93;
    }
    // 004b5c67  81fa00000100           +cmp edx, 0x10000
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
    // 004b5c6d  7324                   -jae 0x4b5c93
    if (!cpu.flags.cf)
    {
        goto L_0x004b5c93;
    }
L_0x004b5c6f:
    // 004b5c6f  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004b5c72  81fa00000100           +cmp edx, 0x10000
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
    // 004b5c78  724b                   -jb 0x4b5cc5
    if (cpu.flags.cf)
    {
        goto L_0x004b5cc5;
    }
    // 004b5c7a  7660                   -jbe 0x4b5cdc
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b5cdc;
    }
    // 004b5c7c  8b501c                 -mov edx, dword ptr [eax + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004b5c7f  c702f0594b00           -mov dword ptr [edx], 0x4b59f0
    app->getMemory<x86::reg32>(cpu.edx) = 4938224 /*0x4b59f0*/;
    // 004b5c85  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004b5c88  c7006c5a4b00           -mov dword ptr [eax], 0x4b5a6c
    app->getMemory<x86::reg32>(cpu.eax) = 4938348 /*0x4b5a6c*/;
    // 004b5c8e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b5c90  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5c91  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5c92  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b5c93:
    // 004b5c93  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004b5c96  39f2                   +cmp edx, esi
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
    // 004b5c98  74d5                   -je 0x4b5c6f
    if (cpu.flags.zf)
    {
        goto L_0x004b5c6f;
    }
    // 004b5c9a  81fe00000100           +cmp esi, 0x10000
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
    // 004b5ca0  7608                   -jbe 0x4b5caa
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b5caa;
    }
    // 004b5ca2  81fa00000100           +cmp edx, 0x10000
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
    // 004b5ca8  77c5                   -ja 0x4b5c6f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004b5c6f;
    }
L_0x004b5caa:
    // 004b5caa  c6401400               -mov byte ptr [eax + 0x14], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 004b5cae  c6401500               -mov byte ptr [eax + 0x15], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(21) /* 0x15 */) = 0 /*0x0*/;
    // 004b5cb2  c6401600               -mov byte ptr [eax + 0x16], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(22) /* 0x16 */) = 0 /*0x0*/;
    // 004b5cb6  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004b5cbd  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004b5cc3  ebaa                   -jmp 0x4b5c6f
    goto L_0x004b5c6f;
L_0x004b5cc5:
    // 004b5cc5  8b501c                 -mov edx, dword ptr [eax + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004b5cc8  c702405a4b00           -mov dword ptr [edx], 0x4b5a40
    app->getMemory<x86::reg32>(cpu.edx) = 4938304 /*0x4b5a40*/;
    // 004b5cce  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004b5cd1  c7004c5b4b00           -mov dword ptr [eax], 0x4b5b4c
    app->getMemory<x86::reg32>(cpu.eax) = 4938572 /*0x4b5b4c*/;
    // 004b5cd7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b5cd9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5cda  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5cdb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b5cdc:
    // 004b5cdc  8b501c                 -mov edx, dword ptr [eax + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004b5cdf  c702385a4b00           -mov dword ptr [edx], 0x4b5a38
    app->getMemory<x86::reg32>(cpu.edx) = 4938296 /*0x4b5a38*/;
    // 004b5ce5  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004b5ce8  c700405b4b00           -mov dword ptr [eax], 0x4b5b40
    app->getMemory<x86::reg32>(cpu.eax) = 4938560 /*0x4b5b40*/;
    // 004b5cee  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b5cf0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5cf1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5cf2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4b5cf4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b5cf4);
    // 004b5cf4  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b5cf8  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004b5cfe  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004b5d05  c6401400               -mov byte ptr [eax + 0x14], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 004b5d09  c7401000000000         -mov dword ptr [eax + 0x10], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 004b5d10  c6401500               -mov byte ptr [eax + 0x15], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(21) /* 0x15 */) = 0 /*0x0*/;
    // 004b5d14  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b5d18  c6401601               -mov byte ptr [eax + 0x16], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(22) /* 0x16 */) = 1 /*0x1*/;
    // 004b5d1c  895018                 -mov dword ptr [eax + 0x18], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004b5d1f  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b5d23  89501c                 -mov dword ptr [eax + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004b5d26  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b5d2a  895020                 -mov dword ptr [eax + 0x20], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 004b5d2d  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004b5d30  c700505c4b00           -mov dword ptr [eax], 0x4b5c50
    app->getMemory<x86::reg32>(cpu.eax) = 4938832 /*0x4b5c50*/;
    // 004b5d36  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b5d38  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4b5d40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b5d40);
    // 004b5d40  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b5d41  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b5d42  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b5d43  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b5d47  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004b5d4b  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004b5d4e  48                     -dec eax
    (cpu.eax)--;
    // 004b5d4f  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004b5d52  034204                 -add eax, dword ptr [edx + 4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 004b5d55  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b5d58  8b5a1b                 -mov ebx, dword ptr [edx + 0x1b]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(27) /* 0x1b */);
    // 004b5d5b  40                     -inc eax
    (cpu.eax)++;
    // 004b5d5c  c1fb18                 -sar ebx, 0x18
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (24 /*0x18*/ % 32));
    // 004b5d5f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b5d61  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b5d63  8a5a1d                 -mov bl, byte ptr [edx + 0x1d]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(29) /* 0x1d */);
    // 004b5d66  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b5d68  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 004b5d6a  7501                   -jne 0x4b5d6d
    if (!cpu.flags.zf)
    {
        goto L_0x004b5d6d;
    }
    // 004b5d6c  40                     -inc eax
    (cpu.eax)++;
L_0x004b5d6d:
    // 004b5d6d  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004b5d71  8b5108                 -mov edx, dword ptr [ecx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004b5d74  0fafd7                 -imul edx, edi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 004b5d77  035104                 -add edx, dword ptr [ecx + 4]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
    // 004b5d7a  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004b5d7d  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004b5d7f  88511e                 -mov byte ptr [ecx + 0x1e], dl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) = cpu.dl;
    // 004b5d82  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5d83  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5d84  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5d85  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4b5d88(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b5d88);
    // 004b5d88  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b5d8c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4b5d90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b5d90);
    // 004b5d90  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b5d91  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b5d95  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b5d99  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004b5d9c  48                     -dec eax
    (cpu.eax)--;
    // 004b5d9d  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004b5da0  034204                 -add eax, dword ptr [edx + 4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 004b5da3  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b5da5  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b5da8  8a5a1d                 -mov bl, byte ptr [edx + 0x1d]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(29) /* 0x1d */);
    // 004b5dab  40                     -inc eax
    (cpu.eax)++;
    // 004b5dac  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 004b5dae  7501                   -jne 0x4b5db1
    if (!cpu.flags.zf)
    {
        goto L_0x004b5db1;
    }
    // 004b5db0  40                     -inc eax
    (cpu.eax)++;
L_0x004b5db1:
    // 004b5db1  8b5119                 -mov edx, dword ptr [ecx + 0x19]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(25) /* 0x19 */);
    // 004b5db4  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004b5db7  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b5db9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5dba  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4b5dbc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b5dbc);
    // 004b5dbc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b5dbd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b5dbe  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b5dbf  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b5dc0  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004b5dc3  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004b5dc7  8b7c242c               -mov edi, dword ptr [esp + 0x2c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004b5dcb  8b542430               -mov edx, dword ptr [esp + 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004b5dcf  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b5dd1  8a481d                 -mov cl, byte ptr [eax + 0x1d]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(29) /* 0x1d */);
    // 004b5dd4  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004b5dd6  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 004b5dd8  0f8598000000           -jne 0x4b5e76
    if (!cpu.flags.zf)
    {
        goto L_0x004b5e76;
    }
L_0x004b5dde:
    // 004b5dde  8b6c2434               -mov ebp, dword ptr [esp + 0x34]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004b5de2  4f                     -dec edi
    (cpu.edi)--;
    // 004b5de3  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp);
    // 004b5de6  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004b5de8  0f8f9d000000           -jg 0x4b5e8b
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b5e8b;
    }
L_0x004b5dee:
    // 004b5dee  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b5df0  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b5df3  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004b5df7  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004b5dfa  df2c24                 -fild qword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.esp))));
    // 004b5dfd  dc0d28184d00           -fmul qword ptr [0x4d1828]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5052456) /* 0x4d1828 */));
    // 004b5e03  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004b5e05  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 004b5e07  dee1                   -fsubrp st(1)
    cpu.fpu.st(1) = cpu.fpu.st(0) - x86::Float(cpu.fpu.st(1));
    cpu.fpu.pop();
    // 004b5e09  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b5e0b  d944c608               -fld dword ptr [esi + eax*8 + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(8) /* 0x8 */ + cpu.eax * 8)));
    // 004b5e0f  d8ca                   -fmul st(2)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(2));
    // 004b5e11  d904c6                 -fld dword ptr [esi + eax*8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + cpu.eax * 8)));
    // 004b5e14  d8ca                   -fmul st(2)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(2));
    // 004b5e16  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b5e18  8d04fd00000000         -lea eax, [edi*8]
    cpu.eax = x86::reg32(cpu.edi * 8);
    // 004b5e1f  d91c28                 -fstp dword ptr [eax + ebp]
    app->getMemory<float>(cpu.eax + cpu.ebp * 1) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b5e22  8b3b                   -mov edi, dword ptr [ebx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b5e24  d84cfe04               -fmul dword ptr [esi + edi*8 + 4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.edi * 8));
    // 004b5e28  d944fe0c               -fld dword ptr [esi + edi*8 + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(12) /* 0xc */ + cpu.edi * 8)));
    // 004b5e2c  deca                   -fmulp st(2)
    cpu.fpu.st(2) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b5e2e  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b5e30  d95c2804               -fstp dword ptr [eax + ebp + 4]
    app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */ + cpu.ebp * 1) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b5e34  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b5e36  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b5e39  d944c608               -fld dword ptr [esi + eax*8 + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(8) /* 0x8 */ + cpu.eax * 8)));
    // 004b5e3d  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b5e3f  d95b14                 -fstp dword ptr [ebx + 0x14]
    app->getMemory<float>(cpu.ebx + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b5e42  d944c60c               -fld dword ptr [esi + eax*8 + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(12) /* 0xc */ + cpu.eax * 8)));
    // 004b5e46  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b5e49  d95b18                 -fstp dword ptr [ebx + 0x18]
    app->getMemory<float>(cpu.ebx + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b5e4c  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b5e4e  8b33                   -mov esi, dword ptr [ebx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b5e50  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b5e52  894b04                 -mov dword ptr [ebx + 4], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004b5e55  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b5e58  66c743060000           -mov word ptr [ebx + 6], 0
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 004b5e5e  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b5e60  8b431b                 -mov eax, dword ptr [ebx + 0x1b]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(27) /* 0x1b */);
    // 004b5e63  8933                   -mov dword ptr [ebx], esi
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.esi;
    // 004b5e65  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004b5e68  c6431d01               -mov byte ptr [ebx + 0x1d], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(29) /* 0x1d */) = 1 /*0x1*/;
    // 004b5e6c  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004b5e6e  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004b5e71  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5e72  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5e73  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5e74  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5e75  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b5e76:
    // 004b5e76  8d72fc                 -lea esi, [edx - 4]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 004b5e79  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004b5e7c  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 004b5e7e  83ee04                 +sub esi, 4
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
    // 004b5e81  8b5014                 -mov edx, dword ptr [eax + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004b5e84  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 004b5e86  e953ffffff             -jmp 0x4b5dde
    goto L_0x004b5dde;
L_0x004b5e8b:
    // 004b5e8b  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b5e8e  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b5e91  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b5e94  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 004b5e97  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004b5e9a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b5e9b  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004b5e9e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b5e9f  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004b5ea3  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004b5ea7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b5ea8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b5ea9  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b5eaa  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b5eab  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b5eac  e8f35f0000             -call 0x4bbea4
    cpu.esp -= 4;
    sub_4bbea4(app, cpu);
    if (cpu.terminate) return;
    // 004b5eb1  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004b5eb4  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b5eb8  c1e810                 +shr eax, 0x10
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
    // 004b5ebb  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004b5ebe  e92bffffff             -jmp 0x4b5dee
    goto L_0x004b5dee;
}

/* align: skip 0x90 */
void Application::sub_4b5ec4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b5ec4);
    // 004b5ec4  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b5ec8  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b5ecc  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004b5ece  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4b5ed0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b5ed0);
    // 004b5ed0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b5ed1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b5ed2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b5ed3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b5ed4  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004b5ed7  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004b5edb  8b7c242c               -mov edi, dword ptr [esp + 0x2c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004b5edf  8b542430               -mov edx, dword ptr [esp + 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004b5ee3  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b5ee5  8a481d                 -mov cl, byte ptr [eax + 0x1d]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(29) /* 0x1d */);
    // 004b5ee8  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004b5eea  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 004b5eec  0f85f2000000           -jne 0x4b5fe4
    if (!cpu.flags.zf)
    {
        goto L_0x004b5fe4;
    }
L_0x004b5ef2:
    // 004b5ef2  807b1c00               +cmp byte ptr [ebx + 0x1c], 0
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
    // 004b5ef6  7412                   -je 0x4b5f0a
    if (cpu.flags.zf)
    {
        goto L_0x004b5f0a;
    }
    // 004b5ef8  8b4310                 -mov eax, dword ptr [ebx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 004b5efb  8946fc                 -mov dword ptr [esi - 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004b5efe  83ee04                 -sub esi, 4
    (cpu.esi) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b5f01  8b430c                 -mov eax, dword ptr [ebx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004b5f04  8946fc                 -mov dword ptr [esi - 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004b5f07  83ee04                 -sub esi, 4
    (cpu.esi) -= x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004b5f0a:
    // 004b5f0a  8b6c2434               -mov ebp, dword ptr [esp + 0x34]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004b5f0e  c70300000000           -mov dword ptr [ebx], 0
    app->getMemory<x86::reg32>(cpu.ebx) = 0 /*0x0*/;
    // 004b5f14  4f                     -dec edi
    (cpu.edi)--;
    // 004b5f15  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp);
    // 004b5f18  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004b5f1a  7e33                   -jle 0x4b5f4f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b5f4f;
    }
    // 004b5f1c  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b5f1f  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b5f22  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b5f25  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004b5f28  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004b5f2b  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b5f2c  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004b5f2f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b5f30  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004b5f34  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004b5f38  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b5f39  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b5f3a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b5f3b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b5f3c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b5f3d  e8625f0000             -call 0x4bbea4
    cpu.esp -= 4;
    sub_4bbea4(app, cpu);
    if (cpu.terminate) return;
    // 004b5f42  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004b5f45  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b5f49  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b5f4c  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x004b5f4f:
    // 004b5f4f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b5f51  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b5f54  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004b5f58  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004b5f5b  df2c24                 -fild qword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg64(app->getMemory<x86::reg64>(cpu.esp))));
    // 004b5f5e  dc0d30184d00           -fmul qword ptr [0x4d1830]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5052464) /* 0x4d1830 */));
    // 004b5f64  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b5f66  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004b5f68  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 004b5f6a  dee1                   -fsubrp st(1)
    cpu.fpu.st(1) = cpu.fpu.st(0) - x86::Float(cpu.fpu.st(1));
    cpu.fpu.pop();
    // 004b5f6c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b5f6e  d944c608               -fld dword ptr [esi + eax*8 + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(8) /* 0x8 */ + cpu.eax * 8)));
    // 004b5f72  d8ca                   -fmul st(2)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(2));
    // 004b5f74  d904c6                 -fld dword ptr [esi + eax*8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + cpu.eax * 8)));
    // 004b5f77  d8ca                   -fmul st(2)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(2));
    // 004b5f79  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b5f7b  d95cfd00               -fstp dword ptr [ebp + edi*8]
    app->getMemory<float>(cpu.ebp + cpu.edi * 8) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b5f7f  d84cd604               -fmul dword ptr [esi + edx*8 + 4]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.edx * 8));
    // 004b5f83  d944d60c               -fld dword ptr [esi + edx*8 + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(12) /* 0xc */ + cpu.edx * 8)));
    // 004b5f87  deca                   -fmulp st(2)
    cpu.fpu.st(2) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b5f89  dec1                   -faddp st(1)
    cpu.fpu.st(1) += cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004b5f8b  d95cfd04               -fstp dword ptr [ebp + edi*8 + 4]
    app->getMemory<float>(cpu.ebp + x86::reg32(4) /* 0x4 */ + cpu.edi * 8) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b5f8f  d944d608               -fld dword ptr [esi + edx*8 + 8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(8) /* 0x8 */ + cpu.edx * 8)));
    // 004b5f93  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b5f96  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b5f99  8b3b                   -mov edi, dword ptr [ebx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b5f9b  8b6b08                 -mov ebp, dword ptr [ebx + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b5f9e  d95b14                 -fstp dword ptr [ebx + 0x14]
    app->getMemory<float>(cpu.ebx + x86::reg32(20) /* 0x14 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b5fa1  d944d60c               -fld dword ptr [esi + edx*8 + 0xc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + x86::reg32(12) /* 0xc */ + cpu.edx * 8)));
    // 004b5fa5  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b5fa7  d95b18                 -fstp dword ptr [ebx + 0x18]
    app->getMemory<float>(cpu.ebx + x86::reg32(24) /* 0x18 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b5faa  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b5fac  894b04                 -mov dword ptr [ebx + 4], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004b5faf  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b5fb2  66c743060000           -mov word ptr [ebx + 6], 0
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 004b5fb8  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b5fba  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b5fbd  893b                   -mov dword ptr [ebx], edi
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edi;
    // 004b5fbf  39e8                   +cmp eax, ebp
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
    // 004b5fc1  7236                   -jb 0x4b5ff9
    if (cpu.flags.cf)
    {
        goto L_0x004b5ff9;
    }
    // 004b5fc3  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b5fc5  c6431c01               -mov byte ptr [ebx + 0x1c], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(28) /* 0x1c */) = 1 /*0x1*/;
    // 004b5fc9  d904c6                 -fld dword ptr [esi + eax*8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.esi + cpu.eax * 8)));
    // 004b5fcc  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b5fce  d95b0c                 -fstp dword ptr [ebx + 0xc]
    app->getMemory<float>(cpu.ebx + x86::reg32(12) /* 0xc */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b5fd1  8b54c604               -mov edx, dword ptr [esi + eax*8 + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.eax * 8);
    // 004b5fd5  895310                 -mov dword ptr [ebx + 0x10], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004b5fd8  c6431d01               -mov byte ptr [ebx + 0x1d], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(29) /* 0x1d */) = 1 /*0x1*/;
    // 004b5fdc  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004b5fdf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5fe0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5fe1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5fe2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b5fe3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b5fe4:
    // 004b5fe4  8d72fc                 -lea esi, [edx - 4]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 004b5fe7  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004b5fea  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 004b5fec  83ee04                 +sub esi, 4
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
    // 004b5fef  8b5014                 -mov edx, dword ptr [eax + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004b5ff2  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 004b5ff4  e9f9feffff             -jmp 0x4b5ef2
    goto L_0x004b5ef2;
L_0x004b5ff9:
    // 004b5ff9  c6431c00               -mov byte ptr [ebx + 0x1c], 0
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 004b5ffd  c6431d01               -mov byte ptr [ebx + 0x1d], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(29) /* 0x1d */) = 1 /*0x1*/;
    // 004b6001  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004b6004  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6005  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6006  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6007  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6008  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4b600c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b600c);
    // 004b600c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b600d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b600e  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b6012  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b6016  8b5908                 -mov ebx, dword ptr [ecx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004b6019  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b601b  81fb00000100           +cmp ebx, 0x10000
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
    // 004b6021  732c                   -jae 0x4b604f
    if (!cpu.flags.cf)
    {
        goto L_0x004b604f;
    }
    // 004b6023  81fa00000100           +cmp edx, 0x10000
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
    // 004b6029  7324                   -jae 0x4b604f
    if (!cpu.flags.cf)
    {
        goto L_0x004b604f;
    }
L_0x004b602b:
    // 004b602b  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004b602e  81fa00000100           +cmp edx, 0x10000
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
    // 004b6034  724b                   -jb 0x4b6081
    if (cpu.flags.cf)
    {
        goto L_0x004b6081;
    }
    // 004b6036  7660                   -jbe 0x4b6098
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b6098;
    }
    // 004b6038  8b5024                 -mov edx, dword ptr [eax + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 004b603b  c702405d4b00           -mov dword ptr [edx], 0x4b5d40
    app->getMemory<x86::reg32>(cpu.edx) = 4939072 /*0x4b5d40*/;
    // 004b6041  8b4028                 -mov eax, dword ptr [eax + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 004b6044  c700bc5d4b00           -mov dword ptr [eax], 0x4b5dbc
    app->getMemory<x86::reg32>(cpu.eax) = 4939196 /*0x4b5dbc*/;
    // 004b604a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b604c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b604d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b604e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b604f:
    // 004b604f  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004b6052  39f2                   +cmp edx, esi
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
    // 004b6054  74d5                   -je 0x4b602b
    if (cpu.flags.zf)
    {
        goto L_0x004b602b;
    }
    // 004b6056  81fe00000100           +cmp esi, 0x10000
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
    // 004b605c  7608                   -jbe 0x4b6066
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b6066;
    }
    // 004b605e  81fa00000100           +cmp edx, 0x10000
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
    // 004b6064  77c5                   -ja 0x4b602b
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004b602b;
    }
L_0x004b6066:
    // 004b6066  c6401c00               -mov byte ptr [eax + 0x1c], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 004b606a  c6401d00               -mov byte ptr [eax + 0x1d], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(29) /* 0x1d */) = 0 /*0x0*/;
    // 004b606e  c6401e00               -mov byte ptr [eax + 0x1e], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(30) /* 0x1e */) = 0 /*0x0*/;
    // 004b6072  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004b6079  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004b607f  ebaa                   -jmp 0x4b602b
    goto L_0x004b602b;
L_0x004b6081:
    // 004b6081  8b5024                 -mov edx, dword ptr [eax + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 004b6084  c702905d4b00           -mov dword ptr [edx], 0x4b5d90
    app->getMemory<x86::reg32>(cpu.edx) = 4939152 /*0x4b5d90*/;
    // 004b608a  8b4028                 -mov eax, dword ptr [eax + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 004b608d  c700d05e4b00           -mov dword ptr [eax], 0x4b5ed0
    app->getMemory<x86::reg32>(cpu.eax) = 4939472 /*0x4b5ed0*/;
    // 004b6093  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b6095  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6096  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6097  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b6098:
    // 004b6098  8b5024                 -mov edx, dword ptr [eax + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 004b609b  c702885d4b00           -mov dword ptr [edx], 0x4b5d88
    app->getMemory<x86::reg32>(cpu.edx) = 4939144 /*0x4b5d88*/;
    // 004b60a1  8b4028                 -mov eax, dword ptr [eax + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */);
    // 004b60a4  c700c45e4b00           -mov dword ptr [eax], 0x4b5ec4
    app->getMemory<x86::reg32>(cpu.eax) = 4939460 /*0x4b5ec4*/;
    // 004b60aa  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b60ac  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b60ad  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b60ae  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4b60b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b60b0);
    // 004b60b0  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b60b4  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004b60ba  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004b60c1  c6401c00               -mov byte ptr [eax + 0x1c], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 004b60c5  c6401d00               -mov byte ptr [eax + 0x1d], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(29) /* 0x1d */) = 0 /*0x0*/;
    // 004b60c9  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b60cd  c6401e00               -mov byte ptr [eax + 0x1e], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(30) /* 0x1e */) = 0 /*0x0*/;
    // 004b60d1  895020                 -mov dword ptr [eax + 0x20], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 004b60d4  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b60d8  895024                 -mov dword ptr [eax + 0x24], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 004b60db  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b60df  895028                 -mov dword ptr [eax + 0x28], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 004b60e2  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004b60e5  c7000c604b00           -mov dword ptr [eax], 0x4b600c
    app->getMemory<x86::reg32>(cpu.eax) = 4939788 /*0x4b600c*/;
    // 004b60eb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b60ed  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4b60f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b60f0);
    // 004b60f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b60f1  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b60f4  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004b60f8  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b60fc  c1e303                 -shl ebx, 3
    cpu.ebx <<= 3 /*0x3*/ % 32;
    // 004b60ff  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004b6103  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004b6105  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b6107  39d9                   +cmp ecx, ebx
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
    // 004b6109  7341                   -jae 0x4b614c
    if (!cpu.flags.cf)
    {
        goto L_0x004b614c;
    }
L_0x004b610b:
    // 004b610b  d94004                 -fld dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */)));
    // 004b610e  d800                   -fadd dword ptr [eax]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax));
    // 004b6110  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004b6112  dc0d38184d00           -fmul qword ptr [0x4d1838]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5052472) /* 0x4d1838 */));
    // 004b6118  ddd1                   -fst st(1)
    cpu.fpu.st(1) = x86::Float(cpu.fpu.st(0));
    // 004b611a  dc0540184d00           -fadd qword ptr [0x4d1840]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(5052480) /* 0x4d1840 */));
    // 004b6120  ddd9                   -fstp st(1)
    cpu.fpu.st(1) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b6122  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b6124  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004b6126  81e1ffff0f00           -and ecx, 0xfffff
    cpu.ecx &= x86::reg32(x86::sreg32(1048575 /*0xfffff*/));
    // 004b612c  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b612f  83f97f                 +cmp ecx, 0x7f
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
    // 004b6132  7622                   -jbe 0x4b6156
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b6156;
    }
    // 004b6134  81f980ff0f00           +cmp ecx, 0xfff80
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
    // 004b613a  731a                   -jae 0x4b6156
    if (!cpu.flags.cf)
    {
        goto L_0x004b6156;
    }
    // 004b613c  81f900000800           +cmp ecx, 0x80000
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
    // 004b6142  730d                   -jae 0x4b6151
    if (!cpu.flags.cf)
    {
        goto L_0x004b6151;
    }
    // 004b6144  c602ff                 -mov byte ptr [edx], 0xff
    app->getMemory<x86::reg8>(cpu.edx) = 255 /*0xff*/;
L_0x004b6147:
    // 004b6147  42                     -inc edx
    (cpu.edx)++;
    // 004b6148  39d8                   +cmp eax, ebx
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
    // 004b614a  72bf                   -jb 0x4b610b
    if (cpu.flags.cf)
    {
        goto L_0x004b610b;
    }
L_0x004b614c:
    // 004b614c  83c408                 +add esp, 8
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
    // 004b614f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6150  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b6151:
    // 004b6151  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
    // 004b6154  ebf1                   -jmp 0x4b6147
    goto L_0x004b6147;
L_0x004b6156:
    // 004b6156  80c180                 -add cl, 0x80
    (cpu.cl) += x86::reg8(x86::sreg8(128 /*0x80*/));
    // 004b6159  880a                   -mov byte ptr [edx], cl
    app->getMemory<x86::reg8>(cpu.edx) = cpu.cl;
    // 004b615b  42                     -inc edx
    (cpu.edx)++;
    // 004b615c  39d8                   +cmp eax, ebx
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
    // 004b615e  72ab                   -jb 0x4b610b
    if (cpu.flags.cf)
    {
        goto L_0x004b610b;
    }
    // 004b6160  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b6163  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6164  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4b6170(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b6170);
    // 004b6170  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b6171  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b6174  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004b6178  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b617c  c1e303                 -shl ebx, 3
    cpu.ebx <<= 3 /*0x3*/ % 32;
    // 004b617f  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004b6183  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004b6185  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b6187  39d9                   +cmp ecx, ebx
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
    // 004b6189  7339                   -jae 0x4b61c4
    if (!cpu.flags.cf)
    {
        goto L_0x004b61c4;
    }
L_0x004b618b:
    // 004b618b  d900                   -fld dword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax)));
    // 004b618d  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004b618f  dc0548184d00           -fadd qword ptr [0x4d1848]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(5052488) /* 0x4d1848 */));
    // 004b6195  ddd9                   -fstp st(1)
    cpu.fpu.st(1) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b6197  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b6199  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004b619b  81e1ffff0f00           -and ecx, 0xfffff
    cpu.ecx &= x86::reg32(x86::sreg32(1048575 /*0xfffff*/));
    // 004b61a1  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b61a4  81f9ff7f0000           +cmp ecx, 0x7fff
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
    // 004b61aa  7622                   -jbe 0x4b61ce
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b61ce;
    }
    // 004b61ac  81f900800f00           +cmp ecx, 0xf8000
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
    // 004b61b2  731a                   -jae 0x4b61ce
    if (!cpu.flags.cf)
    {
        goto L_0x004b61ce;
    }
    // 004b61b4  81f900000800           +cmp ecx, 0x80000
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
    // 004b61ba  730d                   -jae 0x4b61c9
    if (!cpu.flags.cf)
    {
        goto L_0x004b61c9;
    }
    // 004b61bc  c602ff                 -mov byte ptr [edx], 0xff
    app->getMemory<x86::reg8>(cpu.edx) = 255 /*0xff*/;
L_0x004b61bf:
    // 004b61bf  42                     -inc edx
    (cpu.edx)++;
    // 004b61c0  39d8                   +cmp eax, ebx
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
    // 004b61c2  72c7                   -jb 0x4b618b
    if (cpu.flags.cf)
    {
        goto L_0x004b618b;
    }
L_0x004b61c4:
    // 004b61c4  83c408                 +add esp, 8
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
    // 004b61c7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b61c8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b61c9:
    // 004b61c9  c60200                 -mov byte ptr [edx], 0
    app->getMemory<x86::reg8>(cpu.edx) = 0 /*0x0*/;
    // 004b61cc  ebf1                   -jmp 0x4b61bf
    goto L_0x004b61bf;
L_0x004b61ce:
    // 004b61ce  c1e908                 -shr ecx, 8
    cpu.ecx >>= 8 /*0x8*/ % 32;
    // 004b61d1  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b61d7  81c180000000           -add ecx, 0x80
    (cpu.ecx) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 004b61dd  880a                   -mov byte ptr [edx], cl
    app->getMemory<x86::reg8>(cpu.edx) = cpu.cl;
    // 004b61df  42                     -inc edx
    (cpu.edx)++;
    // 004b61e0  39d8                   +cmp eax, ebx
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
    // 004b61e2  72a7                   -jb 0x4b618b
    if (cpu.flags.cf)
    {
        goto L_0x004b618b;
    }
    // 004b61e4  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b61e7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b61e8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4b61f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b61f0);
    // 004b61f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b61f1  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b61f4  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004b61f8  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b61fc  c1e303                 -shl ebx, 3
    cpu.ebx <<= 3 /*0x3*/ % 32;
    // 004b61ff  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004b6203  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004b6205  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b6207  39d9                   +cmp ecx, ebx
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
    // 004b6209  7348                   -jae 0x4b6253
    if (!cpu.flags.cf)
    {
        goto L_0x004b6253;
    }
L_0x004b620b:
    // 004b620b  d94004                 -fld dword ptr [eax + 4]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax + x86::reg32(4) /* 0x4 */)));
    // 004b620e  d800                   -fadd dword ptr [eax]
    cpu.fpu.st(0) += x86::Float(app->getMemory<float>(cpu.eax));
    // 004b6210  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004b6212  dc0d50184d00           -fmul qword ptr [0x4d1850]
    cpu.fpu.st(0) *= x86::Float(app->getMemory<double>(x86::reg32(5052496) /* 0x4d1850 */));
    // 004b6218  ddd1                   -fst st(1)
    cpu.fpu.st(1) = x86::Float(cpu.fpu.st(0));
    // 004b621a  dc0558184d00           -fadd qword ptr [0x4d1858]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(5052504) /* 0x4d1858 */));
    // 004b6220  ddd9                   -fstp st(1)
    cpu.fpu.st(1) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b6222  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b6224  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004b6226  81e1ffff0f00           -and ecx, 0xfffff
    cpu.ecx &= x86::reg32(x86::sreg32(1048575 /*0xfffff*/));
    // 004b622c  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b622f  81f9ff7f0000           +cmp ecx, 0x7fff
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
    // 004b6235  7628                   -jbe 0x4b625f
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b625f;
    }
    // 004b6237  81f900800f00           +cmp ecx, 0xf8000
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
    // 004b623d  7320                   -jae 0x4b625f
    if (!cpu.flags.cf)
    {
        goto L_0x004b625f;
    }
    // 004b623f  81f900000800           +cmp ecx, 0x80000
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
    // 004b6245  7311                   -jae 0x4b6258
    if (!cpu.flags.cf)
    {
        goto L_0x004b6258;
    }
    // 004b6247  66c702ff7f             -mov word ptr [edx], 0x7fff
    app->getMemory<x86::reg16>(cpu.edx) = 32767 /*0x7fff*/;
L_0x004b624c:
    // 004b624c  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004b624f  39d8                   +cmp eax, ebx
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
    // 004b6251  72b8                   -jb 0x4b620b
    if (cpu.flags.cf)
    {
        goto L_0x004b620b;
    }
L_0x004b6253:
    // 004b6253  83c408                 +add esp, 8
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
    // 004b6256  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6257  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b6258:
    // 004b6258  66c7020080             -mov word ptr [edx], 0x8000
    app->getMemory<x86::reg16>(cpu.edx) = 32768 /*0x8000*/;
    // 004b625d  ebed                   -jmp 0x4b624c
    goto L_0x004b624c;
L_0x004b625f:
    // 004b625f  66890a                 -mov word ptr [edx], cx
    app->getMemory<x86::reg16>(cpu.edx) = cpu.cx;
    // 004b6262  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004b6265  39d8                   +cmp eax, ebx
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
    // 004b6267  72a2                   -jb 0x4b620b
    if (cpu.flags.cf)
    {
        goto L_0x004b620b;
    }
    // 004b6269  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b626c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b626d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4b6270(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b6270);
    // 004b6270  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b6271  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b6274  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004b6278  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b627c  c1e303                 -shl ebx, 3
    cpu.ebx <<= 3 /*0x3*/ % 32;
    // 004b627f  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004b6283  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004b6285  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b6287  39d9                   +cmp ecx, ebx
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
    // 004b6289  733d                   -jae 0x4b62c8
    if (!cpu.flags.cf)
    {
        goto L_0x004b62c8;
    }
L_0x004b628b:
    // 004b628b  d900                   -fld dword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<float>(cpu.eax)));
    // 004b628d  d9c0                   -fld st(0)
    cpu.fpu.push(x86::Float(cpu.fpu.st(0)));
    // 004b628f  dc0560184d00           -fadd qword ptr [0x4d1860]
    cpu.fpu.st(0) += x86::Float(app->getMemory<double>(x86::reg32(5052512) /* 0x4d1860 */));
    // 004b6295  ddd9                   -fstp st(1)
    cpu.fpu.st(1) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b6297  d918                   -fstp dword ptr [eax]
    app->getMemory<float>(cpu.eax) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b6299  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004b629b  81e1ffff0f00           -and ecx, 0xfffff
    cpu.ecx &= x86::reg32(x86::sreg32(1048575 /*0xfffff*/));
    // 004b62a1  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b62a4  81f9ff7f0000           +cmp ecx, 0x7fff
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
    // 004b62aa  7628                   -jbe 0x4b62d4
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b62d4;
    }
    // 004b62ac  81f900800f00           +cmp ecx, 0xf8000
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
    // 004b62b2  7320                   -jae 0x4b62d4
    if (!cpu.flags.cf)
    {
        goto L_0x004b62d4;
    }
    // 004b62b4  81f900000800           +cmp ecx, 0x80000
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
    // 004b62ba  7311                   -jae 0x4b62cd
    if (!cpu.flags.cf)
    {
        goto L_0x004b62cd;
    }
    // 004b62bc  66c702ff7f             -mov word ptr [edx], 0x7fff
    app->getMemory<x86::reg16>(cpu.edx) = 32767 /*0x7fff*/;
L_0x004b62c1:
    // 004b62c1  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004b62c4  39d8                   +cmp eax, ebx
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
    // 004b62c6  72c3                   -jb 0x4b628b
    if (cpu.flags.cf)
    {
        goto L_0x004b628b;
    }
L_0x004b62c8:
    // 004b62c8  83c408                 +add esp, 8
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
    // 004b62cb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b62cc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b62cd:
    // 004b62cd  66c7020080             -mov word ptr [edx], 0x8000
    app->getMemory<x86::reg16>(cpu.edx) = 32768 /*0x8000*/;
    // 004b62d2  ebed                   -jmp 0x4b62c1
    goto L_0x004b62c1;
L_0x004b62d4:
    // 004b62d4  66890a                 -mov word ptr [edx], cx
    app->getMemory<x86::reg16>(cpu.edx) = cpu.cx;
    // 004b62d7  83c202                 -add edx, 2
    (cpu.edx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004b62da  39d8                   +cmp eax, ebx
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
    // 004b62dc  72ad                   -jb 0x4b628b
    if (cpu.flags.cf)
    {
        goto L_0x004b628b;
    }
    // 004b62de  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b62e1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b62e2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4b62e4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b62e4);
    // 004b62e4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b62e5  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b62e7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b62e8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b62e9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b62ea  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b62ed  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b62f0  b800000000             -mov eax, 0
    cpu.eax = 0 /*0x0*/;
    // 004b62f5  83f90f                 +cmp ecx, 0xf
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
    // 004b62f8  7e3d                   -jle 0x4b6337
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b6337;
    }
    // 004b62fa  83e90f                 -sub ecx, 0xf
    (cpu.ecx) -= x86::reg32(x86::sreg32(15 /*0xf*/));
L_0x004b62fd:
    // 004b62fd  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 004b62ff  894704                 -mov dword ptr [edi + 4], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004b6302  894708                 -mov dword ptr [edi + 8], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b6305  89470c                 -mov dword ptr [edi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004b6308  894710                 -mov dword ptr [edi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004b630b  894714                 -mov dword ptr [edi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004b630e  894718                 -mov dword ptr [edi + 0x18], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004b6311  89471c                 -mov dword ptr [edi + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004b6314  894720                 -mov dword ptr [edi + 0x20], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 004b6317  894724                 -mov dword ptr [edi + 0x24], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 004b631a  894728                 -mov dword ptr [edi + 0x28], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 004b631d  89472c                 -mov dword ptr [edi + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 004b6320  894730                 -mov dword ptr [edi + 0x30], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 004b6323  894734                 -mov dword ptr [edi + 0x34], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 004b6326  894738                 -mov dword ptr [edi + 0x38], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 004b6329  89473c                 -mov dword ptr [edi + 0x3c], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(60) /* 0x3c */) = cpu.eax;
    // 004b632c  83c740                 -add edi, 0x40
    (cpu.edi) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004b632f  83e910                 +sub ecx, 0x10
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
    // 004b6332  7fc9                   -jg 0x4b62fd
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b62fd;
    }
    // 004b6334  83c10f                 -add ecx, 0xf
    (cpu.ecx) += x86::reg32(x86::sreg32(15 /*0xf*/));
L_0x004b6337:
    // 004b6337  83f900                 +cmp ecx, 0
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
    // 004b633a  7e0a                   -jle 0x4b6346
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b6346;
    }
    // 004b633c  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 004b633e  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b6341  83e901                 +sub ecx, 1
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
    // 004b6344  7ff1                   -jg 0x4b6337
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b6337;
    }
L_0x004b6346:
    // 004b6346  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6347  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6348  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6349  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b634a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4b634c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b634c);
    // 004b634c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b634d  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b634f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b6350  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b6351  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b6354  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b6357  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004b635a  c700a9634b00           -mov dword ptr [eax], 0x4b63a9
    app->getMemory<x86::reg32>(cpu.eax) = 4940713 /*0x4b63a9*/;
    // 004b6360  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b6363  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004b6366  c70070634b00           -mov dword ptr [eax], 0x4b6370
    app->getMemory<x86::reg32>(cpu.eax) = 4940656 /*0x4b6370*/;
    // 004b636c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b636d  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b636e  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b636f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b6370(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b6370);
    // 004b6370  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b6371  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b6373  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b6374  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b6375  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b6376  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b6379  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b637c  c1e018                 -shl eax, 0x18
    cpu.eax <<= 24 /*0x18*/ % 32;
    // 004b637f  8b5d0c                 -mov ebx, dword ptr [ebp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b6382  668bc3                 -mov ax, bx
    cpu.ax = cpu.bx;
    // 004b6385  66c1e008               -shl ax, 8
    cpu.ax <<= 8 /*0x8*/ % 32;
    // 004b6389  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 004b638b  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004b638e  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b6391  c1e018                 -shl eax, 0x18
    cpu.eax <<= 24 /*0x18*/ % 32;
    // 004b6394  8b5d10                 -mov ebx, dword ptr [ebp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b6397  668bc3                 -mov ax, bx
    cpu.ax = cpu.bx;
    // 004b639a  66c1e008               -shl ax, 8
    cpu.ax <<= 8 /*0x8*/ % 32;
    // 004b639e  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b63a1  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004b63a4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b63a5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b63a6  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b63a7  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b63a8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b63a9(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b63a9);
    // 004b63a9  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b63aa  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b63ac  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004b63ad  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b63b0  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b63b3  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b63b6  0f6f06                 -movq mm0, qword ptr [esi]
    cpu.mmx.mm0 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.esi));
    // 004b63b9  0f6f4e08               -movq mm1, qword ptr [esi + 8]
    cpu.mmx.mm1 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.esi + x86::reg32(8) /* 0x8 */));
    // 004b63bd  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004b63c0  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b63c2  83e003                 -and eax, 3
    cpu.eax &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004b63c5  83f800                 +cmp eax, 0
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
    // 004b63c8  7405                   -je 0x4b63cf
    if (cpu.flags.zf)
    {
        goto L_0x004b63cf;
    }
    // 004b63ca  83e904                 +sub ecx, 4
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
    // 004b63cd  7c3e                   -jl 0x4b640d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b640d;
    }
L_0x004b63cf:
    // 004b63cf  0f6fd0                 -movq mm2, mm0
    cpu.mmx.mm2 = cpu.mmx.mm0;
    // 004b63d2  0f6fe1                 -movq mm4, mm1
    cpu.mmx.mm4 = cpu.mmx.mm1;
    // 004b63d5  0f6e2f                 -movd mm5, dword ptr [edi]
    cpu.mmx.mm5 = { _mm_loadu_si32(&app->getMemory<x86::reg32>(cpu.edi)) };
    // 004b63d8  0f60f5                 -punpcklbw mm6, mm5
    cpu.mmx.mm6 = { _mm_unpacklo_epi8(cpu.mmx.mm6, cpu.mmx.mm5) };
    // 004b63db  0fe5d6                 -pmulhw mm2, mm6
    cpu.mmx.mm2 = { _mm_mulhi_epi16(cpu.mmx.mm2, cpu.mmx.mm6) };
    // 004b63de  0fe5e6                 -pmulhw mm4, mm6
    cpu.mmx.mm4 = { _mm_mulhi_epi16(cpu.mmx.mm4, cpu.mmx.mm6) };
    // 004b63e1  0f6fda                 -movq mm3, mm2
    cpu.mmx.mm3 = cpu.mmx.mm2;
    // 004b63e4  0f69dc                 -punpckhwd mm3, mm4
    cpu.mmx.mm3 = { _mm_unpacklo_epi16(_mm_srli_epi64(cpu.mmx.mm3, 32), _mm_srli_epi64(cpu.mmx.mm4, 32)) };
    // 004b63e7  0f61d4                 -punpcklwd mm2, mm4
    cpu.mmx.mm2 = { _mm_unpacklo_epi16(cpu.mmx.mm2, cpu.mmx.mm4) };
    // 004b63ea  0fed5500               -paddsw mm2, qword ptr [ebp]
    cpu.mmx.mm2 = { _mm_adds_epi16(cpu.mmx.mm2, x86::from_reg64(app->getMemory<x86::reg64>(cpu.ebp))) };
    // 004b63ee  0fed5d08               -paddsw mm3, qword ptr [ebp + 8]
    cpu.mmx.mm3 = { _mm_adds_epi16(cpu.mmx.mm3, x86::from_reg64(app->getMemory<x86::reg64>(cpu.ebp + x86::reg32(8) /* 0x8 */))) };
    // 004b63f2  0f7f5500               -movq qword ptr [ebp], mm2
    app->getMemory<x86::reg64>(cpu.ebp) = cpu.mmx.mm2;
    // 004b63f6  0f7f5d08               -movq qword ptr [ebp + 8], mm3
    app->getMemory<x86::reg64>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.mmx.mm3;
    // 004b63fa  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b63fd  83c510                 -add ebp, 0x10
    (cpu.ebp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b6400  83e904                 +sub ecx, 4
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
    // 004b6403  7fca                   -jg 0x4b63cf
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b63cf;
    }
    // 004b6405  83f900                 +cmp ecx, 0
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
    // 004b6408  7503                   -jne 0x4b640d
    if (!cpu.flags.zf)
    {
        goto L_0x004b640d;
    }
    // 004b640a  61                     -popal 
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
    // 004b640b  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b640c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b640d:
    // 004b640d  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b6410  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004b6412  b800000000             -mov eax, 0
    cpu.eax = 0 /*0x0*/;
L_0x004b6417:
    // 004b6417  0f6fd0                 -movq mm2, mm0
    cpu.mmx.mm2 = cpu.mmx.mm0;
    // 004b641a  0f6fe1                 -movq mm4, mm1
    cpu.mmx.mm4 = cpu.mmx.mm1;
    // 004b641d  8a27                   -mov ah, byte ptr [edi]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edi);
    // 004b641f  0f6ef0                 -movd mm6, eax
    cpu.mmx.mm6 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004b6422  0fe5d6                 -pmulhw mm2, mm6
    cpu.mmx.mm2 = { _mm_mulhi_epi16(cpu.mmx.mm2, cpu.mmx.mm6) };
    // 004b6425  0fe5e6                 -pmulhw mm4, mm6
    cpu.mmx.mm4 = { _mm_mulhi_epi16(cpu.mmx.mm4, cpu.mmx.mm6) };
    // 004b6428  0f6fda                 -movq mm3, mm2
    cpu.mmx.mm3 = cpu.mmx.mm2;
    // 004b642b  0f69dc                 -punpckhwd mm3, mm4
    cpu.mmx.mm3 = { _mm_unpacklo_epi16(_mm_srli_epi64(cpu.mmx.mm3, 32), _mm_srli_epi64(cpu.mmx.mm4, 32)) };
    // 004b642e  0f61d4                 -punpcklwd mm2, mm4
    cpu.mmx.mm2 = { _mm_unpacklo_epi16(cpu.mmx.mm2, cpu.mmx.mm4) };
    // 004b6431  0f6e5d00               -movd mm3, dword ptr [ebp]
    cpu.mmx.mm3 = { _mm_loadu_si32(&app->getMemory<x86::reg32>(cpu.ebp)) };
    // 004b6435  0fedda                 -paddsw mm3, mm2
    cpu.mmx.mm3 = { _mm_adds_epi16(cpu.mmx.mm3, cpu.mmx.mm2) };
    // 004b6438  0f7e5d00               -movd dword ptr [ebp], mm3
    _mm_storeu_si32(&app->getMemory<x86::reg32>(cpu.ebp), cpu.mmx.mm3);
    // 004b643c  83c701                 -add edi, 1
    (cpu.edi) += x86::reg32(x86::sreg32(1 /*0x1*/));
    // 004b643f  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b6442  83c101                 +add ecx, 1
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
    // 004b6445  7cd0                   -jl 0x4b6417
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b6417;
    }
    // 004b6447  61                     -popal 
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
    // 004b6448  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6449  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4b644c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b644c);
    // 004b644c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b644d  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b644f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b6450  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b6451  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b6454  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b6457  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b645a  c70093644b00           -mov dword ptr [eax], 0x4b6493
    app->getMemory<x86::reg32>(cpu.eax) = 4940947 /*0x4b6493*/;
    // 004b6460  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b6463  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004b6466  c70070644b00           -mov dword ptr [eax], 0x4b6470
    app->getMemory<x86::reg32>(cpu.eax) = 4940912 /*0x4b6470*/;
    // 004b646c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b646d  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b646e  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b646f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b6470(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b6470);
    // 004b6470  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b6471  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b6473  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b6474  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b6475  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b6476  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b6479  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b647c  c1e018                 -shl eax, 0x18
    cpu.eax <<= 24 /*0x18*/ % 32;
    // 004b647f  8b5d0c                 -mov ebx, dword ptr [ebp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b6482  668bc3                 -mov ax, bx
    cpu.ax = cpu.bx;
    // 004b6485  66c1e008               -shl ax, 8
    cpu.ax <<= 8 /*0x8*/ % 32;
    // 004b6489  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 004b648b  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004b648e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b648f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6490  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6491  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6492  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b6493(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b6493);
    // 004b6493  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b6494  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b6496  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004b6497  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b649a  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b649d  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b64a0  0f6f06                 -movq mm0, qword ptr [esi]
    cpu.mmx.mm0 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.esi));
    // 004b64a3  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004b64a6  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b64a8  83e003                 -and eax, 3
    cpu.eax &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004b64ab  83f800                 +cmp eax, 0
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
    // 004b64ae  7405                   -je 0x4b64b5
    if (cpu.flags.zf)
    {
        goto L_0x004b64b5;
    }
    // 004b64b0  83e904                 +sub ecx, 4
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
    // 004b64b3  7c38                   -jl 0x4b64ed
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b64ed;
    }
L_0x004b64b5:
    // 004b64b5  0f6f1f                 -movq mm3, qword ptr [edi]
    cpu.mmx.mm3 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edi));
    // 004b64b8  0f6fc8                 -movq mm1, mm0
    cpu.mmx.mm1 = cpu.mmx.mm0;
    // 004b64bb  0f6fd0                 -movq mm2, mm0
    cpu.mmx.mm2 = cpu.mmx.mm0;
    // 004b64be  0f60e3                 -punpcklbw mm4, mm3
    cpu.mmx.mm4 = { _mm_unpacklo_epi8(cpu.mmx.mm4, cpu.mmx.mm3) };
    // 004b64c1  0f68eb                 -punpckhbw mm5, mm3
    cpu.mmx.mm5 = { _mm_unpacklo_epi8(_mm_srli_epi64(cpu.mmx.mm5, 32), _mm_srli_epi64(cpu.mmx.mm3, 32)) };
    // 004b64c4  0fe5cc                 -pmulhw mm1, mm4
    cpu.mmx.mm1 = { _mm_mulhi_epi16(cpu.mmx.mm1, cpu.mmx.mm4) };
    // 004b64c7  0fe5d5                 -pmulhw mm2, mm5
    cpu.mmx.mm2 = { _mm_mulhi_epi16(cpu.mmx.mm2, cpu.mmx.mm5) };
    // 004b64ca  0fed4d00               -paddsw mm1, qword ptr [ebp]
    cpu.mmx.mm1 = { _mm_adds_epi16(cpu.mmx.mm1, x86::from_reg64(app->getMemory<x86::reg64>(cpu.ebp))) };
    // 004b64ce  0fed5508               -paddsw mm2, qword ptr [ebp + 8]
    cpu.mmx.mm2 = { _mm_adds_epi16(cpu.mmx.mm2, x86::from_reg64(app->getMemory<x86::reg64>(cpu.ebp + x86::reg32(8) /* 0x8 */))) };
    // 004b64d2  0f7f4d00               -movq qword ptr [ebp], mm1
    app->getMemory<x86::reg64>(cpu.ebp) = cpu.mmx.mm1;
    // 004b64d6  0f7f5508               -movq qword ptr [ebp + 8], mm2
    app->getMemory<x86::reg64>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.mmx.mm2;
    // 004b64da  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b64dd  83c510                 -add ebp, 0x10
    (cpu.ebp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b64e0  83e904                 +sub ecx, 4
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
    // 004b64e3  7fd0                   -jg 0x4b64b5
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b64b5;
    }
    // 004b64e5  83f900                 +cmp ecx, 0
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
    // 004b64e8  7503                   -jne 0x4b64ed
    if (!cpu.flags.zf)
    {
        goto L_0x004b64ed;
    }
    // 004b64ea  61                     -popal 
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
    // 004b64eb  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b64ec  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b64ed:
    // 004b64ed  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b64f0  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
L_0x004b64f2:
    // 004b64f2  8a4701                 -mov al, byte ptr [edi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 004b64f5  c1e018                 -shl eax, 0x18
    cpu.eax <<= 24 /*0x18*/ % 32;
    // 004b64f8  8a27                   -mov ah, byte ptr [edi]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edi);
    // 004b64fa  0f6ec8                 -movd mm1, eax
    cpu.mmx.mm1 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004b64fd  0fe5c8                 -pmulhw mm1, mm0
    cpu.mmx.mm1 = { _mm_mulhi_epi16(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 004b6500  0f6e5500               -movd mm2, dword ptr [ebp]
    cpu.mmx.mm2 = { _mm_loadu_si32(&app->getMemory<x86::reg32>(cpu.ebp)) };
    // 004b6504  0fedca                 -paddsw mm1, mm2
    cpu.mmx.mm1 = { _mm_adds_epi16(cpu.mmx.mm1, cpu.mmx.mm2) };
    // 004b6507  0f7e4d00               -movd dword ptr [ebp], mm1
    _mm_storeu_si32(&app->getMemory<x86::reg32>(cpu.ebp), cpu.mmx.mm1);
    // 004b650b  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004b650e  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b6511  83c101                 +add ecx, 1
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
    // 004b6514  7cdc                   -jl 0x4b64f2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b64f2;
    }
    // 004b6516  61                     -popal 
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
    // 004b6517  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6518  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_4b651c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b651c);
    // 004b651c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b651d  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b651f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b6520  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b6521  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b6524  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b6527  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004b652a  c70079654b00           -mov dword ptr [eax], 0x4b6579
    app->getMemory<x86::reg32>(cpu.eax) = 4941177 /*0x4b6579*/;
    // 004b6530  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b6533  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004b6536  c70040654b00           -mov dword ptr [eax], 0x4b6540
    app->getMemory<x86::reg32>(cpu.eax) = 4941120 /*0x4b6540*/;
    // 004b653c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b653d  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b653e  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b653f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b6540(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b6540);
    // 004b6540  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b6541  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b6543  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b6544  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b6545  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b6546  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b6549  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b654c  c1e018                 -shl eax, 0x18
    cpu.eax <<= 24 /*0x18*/ % 32;
    // 004b654f  8b5d0c                 -mov ebx, dword ptr [ebp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b6552  668bc3                 -mov ax, bx
    cpu.ax = cpu.bx;
    // 004b6555  66c1e008               -shl ax, 8
    cpu.ax <<= 8 /*0x8*/ % 32;
    // 004b6559  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 004b655b  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004b655e  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b6561  c1e018                 -shl eax, 0x18
    cpu.eax <<= 24 /*0x18*/ % 32;
    // 004b6564  8b5d10                 -mov ebx, dword ptr [ebp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b6567  668bc3                 -mov ax, bx
    cpu.ax = cpu.bx;
    // 004b656a  66c1e008               -shl ax, 8
    cpu.ax <<= 8 /*0x8*/ % 32;
    // 004b656e  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b6571  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004b6574  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6575  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6576  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6577  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6578  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b6579(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b6579);
    // 004b6579  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b657a  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b657c  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004b657d  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b6580  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b6583  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b6586  0f6f06                 -movq mm0, qword ptr [esi]
    cpu.mmx.mm0 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.esi));
    // 004b6589  0f6f4e08               -movq mm1, qword ptr [esi + 8]
    cpu.mmx.mm1 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.esi + x86::reg32(8) /* 0x8 */));
    // 004b658d  8b5d14                 -mov ebx, dword ptr [ebp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004b6590  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b6592  83e003                 -and eax, 3
    cpu.eax &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004b6595  83f800                 +cmp eax, 0
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
    // 004b6598  7405                   -je 0x4b659f
    if (cpu.flags.zf)
    {
        goto L_0x004b659f;
    }
    // 004b659a  83e904                 +sub ecx, 4
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
    // 004b659d  7c39                   -jl 0x4b65d8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b65d8;
    }
L_0x004b659f:
    // 004b659f  0f6fd0                 -movq mm2, mm0
    cpu.mmx.mm2 = cpu.mmx.mm0;
    // 004b65a2  0f6fe1                 -movq mm4, mm1
    cpu.mmx.mm4 = cpu.mmx.mm1;
    // 004b65a5  0f6f37                 -movq mm6, qword ptr [edi]
    cpu.mmx.mm6 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.edi));
    // 004b65a8  0fe5d6                 -pmulhw mm2, mm6
    cpu.mmx.mm2 = { _mm_mulhi_epi16(cpu.mmx.mm2, cpu.mmx.mm6) };
    // 004b65ab  0fe5e6                 -pmulhw mm4, mm6
    cpu.mmx.mm4 = { _mm_mulhi_epi16(cpu.mmx.mm4, cpu.mmx.mm6) };
    // 004b65ae  0f6fda                 -movq mm3, mm2
    cpu.mmx.mm3 = cpu.mmx.mm2;
    // 004b65b1  0f69dc                 -punpckhwd mm3, mm4
    cpu.mmx.mm3 = { _mm_unpacklo_epi16(_mm_srli_epi64(cpu.mmx.mm3, 32), _mm_srli_epi64(cpu.mmx.mm4, 32)) };
    // 004b65b4  0f61d4                 -punpcklwd mm2, mm4
    cpu.mmx.mm2 = { _mm_unpacklo_epi16(cpu.mmx.mm2, cpu.mmx.mm4) };
    // 004b65b7  0fed13                 -paddsw mm2, qword ptr [ebx]
    cpu.mmx.mm2 = { _mm_adds_epi16(cpu.mmx.mm2, x86::from_reg64(app->getMemory<x86::reg64>(cpu.ebx))) };
    // 004b65ba  0fed5b08               -paddsw mm3, qword ptr [ebx + 8]
    cpu.mmx.mm3 = { _mm_adds_epi16(cpu.mmx.mm3, x86::from_reg64(app->getMemory<x86::reg64>(cpu.ebx + x86::reg32(8) /* 0x8 */))) };
    // 004b65be  0f7f13                 -movq qword ptr [ebx], mm2
    app->getMemory<x86::reg64>(cpu.ebx) = cpu.mmx.mm2;
    // 004b65c1  0f7f5b08               -movq qword ptr [ebx + 8], mm3
    app->getMemory<x86::reg64>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.mmx.mm3;
    // 004b65c5  83c708                 -add edi, 8
    (cpu.edi) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b65c8  83c310                 -add ebx, 0x10
    (cpu.ebx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b65cb  83e904                 +sub ecx, 4
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
    // 004b65ce  7fcf                   -jg 0x4b659f
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b659f;
    }
    // 004b65d0  83f900                 +cmp ecx, 0
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
    // 004b65d3  7503                   -jne 0x4b65d8
    if (!cpu.flags.zf)
    {
        goto L_0x004b65d8;
    }
    // 004b65d5  61                     -popal 
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
    // 004b65d6  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b65d7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b65d8:
    // 004b65d8  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b65db  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
L_0x004b65dd:
    // 004b65dd  0f6fd0                 -movq mm2, mm0
    cpu.mmx.mm2 = cpu.mmx.mm0;
    // 004b65e0  0f6fe1                 -movq mm4, mm1
    cpu.mmx.mm4 = cpu.mmx.mm1;
    // 004b65e3  668b07                 -mov ax, word ptr [edi]
    cpu.ax = app->getMemory<x86::reg16>(cpu.edi);
    // 004b65e6  0f6ef0                 -movd mm6, eax
    cpu.mmx.mm6 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004b65e9  0fe5d6                 -pmulhw mm2, mm6
    cpu.mmx.mm2 = { _mm_mulhi_epi16(cpu.mmx.mm2, cpu.mmx.mm6) };
    // 004b65ec  0fe5e6                 -pmulhw mm4, mm6
    cpu.mmx.mm4 = { _mm_mulhi_epi16(cpu.mmx.mm4, cpu.mmx.mm6) };
    // 004b65ef  0f6fda                 -movq mm3, mm2
    cpu.mmx.mm3 = cpu.mmx.mm2;
    // 004b65f2  0f69dc                 -punpckhwd mm3, mm4
    cpu.mmx.mm3 = { _mm_unpacklo_epi16(_mm_srli_epi64(cpu.mmx.mm3, 32), _mm_srli_epi64(cpu.mmx.mm4, 32)) };
    // 004b65f5  0f61d4                 -punpcklwd mm2, mm4
    cpu.mmx.mm2 = { _mm_unpacklo_epi16(cpu.mmx.mm2, cpu.mmx.mm4) };
    // 004b65f8  0f6e1b                 -movd mm3, dword ptr [ebx]
    cpu.mmx.mm3 = { _mm_loadu_si32(&app->getMemory<x86::reg32>(cpu.ebx)) };
    // 004b65fb  0fedda                 -paddsw mm3, mm2
    cpu.mmx.mm3 = { _mm_adds_epi16(cpu.mmx.mm3, cpu.mmx.mm2) };
    // 004b65fe  0f7e1b                 -movd dword ptr [ebx], mm3
    _mm_storeu_si32(&app->getMemory<x86::reg32>(cpu.ebx), cpu.mmx.mm3);
    // 004b6601  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004b6604  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b6607  83c101                 +add ecx, 1
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
    // 004b660a  7cd1                   -jl 0x4b65dd
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b65dd;
    }
    // 004b660c  61                     -popal 
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
    // 004b660d  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b660e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4b6610(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b6610);
    // 004b6610  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b6611  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b6613  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b6614  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b6615  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b6618  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b661b  894608                 -mov dword ptr [esi + 8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b661e  c70057664b00           -mov dword ptr [eax], 0x4b6657
    app->getMemory<x86::reg32>(cpu.eax) = 4941399 /*0x4b6657*/;
    // 004b6624  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b6627  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004b662a  c70034664b00           -mov dword ptr [eax], 0x4b6634
    app->getMemory<x86::reg32>(cpu.eax) = 4941364 /*0x4b6634*/;
    // 004b6630  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6631  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6632  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6633  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b6634(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b6634);
    // 004b6634  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b6635  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b6637  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b6638  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b6639  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b663a  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b663d  8b4510                 -mov eax, dword ptr [ebp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b6640  c1e018                 -shl eax, 0x18
    cpu.eax <<= 24 /*0x18*/ % 32;
    // 004b6643  8b5d0c                 -mov ebx, dword ptr [ebp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b6646  668bc3                 -mov ax, bx
    cpu.ax = cpu.bx;
    // 004b6649  66c1e008               -shl ax, 8
    cpu.ax <<= 8 /*0x8*/ % 32;
    // 004b664d  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 004b664f  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004b6652  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6653  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6654  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6655  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6656  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b6657(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b6657);
    // 004b6657  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b6658  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b665a  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004b665b  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b665e  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b6661  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b6664  0f6f06                 -movq mm0, qword ptr [esi]
    cpu.mmx.mm0 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.esi));
    // 004b6667  8b6d14                 -mov ebp, dword ptr [ebp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004b666a  8bc1                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b666c  83e007                 -and eax, 7
    cpu.eax &= x86::reg32(x86::sreg32(7 /*0x7*/));
    // 004b666f  83f800                 +cmp eax, 0
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
    // 004b6672  7405                   -je 0x4b6679
    if (cpu.flags.zf)
    {
        goto L_0x004b6679;
    }
    // 004b6674  83e908                 +sub ecx, 8
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
    // 004b6677  7c4e                   -jl 0x4b66c7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b66c7;
    }
L_0x004b6679:
    // 004b6679  0f6fc8                 -movq mm1, mm0
    cpu.mmx.mm1 = cpu.mmx.mm0;
    // 004b667c  0f6fd0                 -movq mm2, mm0
    cpu.mmx.mm2 = cpu.mmx.mm0;
    // 004b667f  0f6fd8                 -movq mm3, mm0
    cpu.mmx.mm3 = cpu.mmx.mm0;
    // 004b6682  0f6fe0                 -movq mm4, mm0
    cpu.mmx.mm4 = cpu.mmx.mm0;
    // 004b6685  0fe50f                 -pmulhw mm1, qword ptr [edi]
    cpu.mmx.mm1 = { _mm_mulhi_epi16(cpu.mmx.mm1, x86::from_reg64(app->getMemory<x86::reg64>(cpu.edi))) };
    // 004b6688  0fe55708               -pmulhw mm2, qword ptr [edi + 8]
    cpu.mmx.mm2 = { _mm_mulhi_epi16(cpu.mmx.mm2, x86::from_reg64(app->getMemory<x86::reg64>(cpu.edi + x86::reg32(8) /* 0x8 */))) };
    // 004b668c  0fe55f10               -pmulhw mm3, qword ptr [edi + 0x10]
    cpu.mmx.mm3 = { _mm_mulhi_epi16(cpu.mmx.mm3, x86::from_reg64(app->getMemory<x86::reg64>(cpu.edi + x86::reg32(16) /* 0x10 */))) };
    // 004b6690  0fe56718               -pmulhw mm4, qword ptr [edi + 0x18]
    cpu.mmx.mm4 = { _mm_mulhi_epi16(cpu.mmx.mm4, x86::from_reg64(app->getMemory<x86::reg64>(cpu.edi + x86::reg32(24) /* 0x18 */))) };
    // 004b6694  0fed4d00               -paddsw mm1, qword ptr [ebp]
    cpu.mmx.mm1 = { _mm_adds_epi16(cpu.mmx.mm1, x86::from_reg64(app->getMemory<x86::reg64>(cpu.ebp))) };
    // 004b6698  0fed5508               -paddsw mm2, qword ptr [ebp + 8]
    cpu.mmx.mm2 = { _mm_adds_epi16(cpu.mmx.mm2, x86::from_reg64(app->getMemory<x86::reg64>(cpu.ebp + x86::reg32(8) /* 0x8 */))) };
    // 004b669c  0fed5d10               -paddsw mm3, qword ptr [ebp + 0x10]
    cpu.mmx.mm3 = { _mm_adds_epi16(cpu.mmx.mm3, x86::from_reg64(app->getMemory<x86::reg64>(cpu.ebp + x86::reg32(16) /* 0x10 */))) };
    // 004b66a0  0fed6518               -paddsw mm4, qword ptr [ebp + 0x18]
    cpu.mmx.mm4 = { _mm_adds_epi16(cpu.mmx.mm4, x86::from_reg64(app->getMemory<x86::reg64>(cpu.ebp + x86::reg32(24) /* 0x18 */))) };
    // 004b66a4  0f7f4d00               -movq qword ptr [ebp], mm1
    app->getMemory<x86::reg64>(cpu.ebp) = cpu.mmx.mm1;
    // 004b66a8  0f7f5508               -movq qword ptr [ebp + 8], mm2
    app->getMemory<x86::reg64>(cpu.ebp + x86::reg32(8) /* 0x8 */) = cpu.mmx.mm2;
    // 004b66ac  0f7f5d10               -movq qword ptr [ebp + 0x10], mm3
    app->getMemory<x86::reg64>(cpu.ebp + x86::reg32(16) /* 0x10 */) = cpu.mmx.mm3;
    // 004b66b0  0f7f6518               -movq qword ptr [ebp + 0x18], mm4
    app->getMemory<x86::reg64>(cpu.ebp + x86::reg32(24) /* 0x18 */) = cpu.mmx.mm4;
    // 004b66b4  83c720                 -add edi, 0x20
    (cpu.edi) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004b66b7  83c520                 -add ebp, 0x20
    (cpu.ebp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004b66ba  83e908                 +sub ecx, 8
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
    // 004b66bd  7fba                   -jg 0x4b6679
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b6679;
    }
    // 004b66bf  83f900                 +cmp ecx, 0
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
    // 004b66c2  7503                   -jne 0x4b66c7
    if (!cpu.flags.zf)
    {
        goto L_0x004b66c7;
    }
    // 004b66c4  61                     -popal 
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
    // 004b66c5  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b66c6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b66c7:
    // 004b66c7  83c108                 -add ecx, 8
    (cpu.ecx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b66ca  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004b66cc  0f6fc8                 -movq mm1, mm0
    cpu.mmx.mm1 = cpu.mmx.mm0;
L_0x004b66cf:
    // 004b66cf  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 004b66d1  0f6ec8                 -movd mm1, eax
    cpu.mmx.mm1 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004b66d4  0fe5c8                 -pmulhw mm1, mm0
    cpu.mmx.mm1 = { _mm_mulhi_epi16(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 004b66d7  0f6e5500               -movd mm2, dword ptr [ebp]
    cpu.mmx.mm2 = { _mm_loadu_si32(&app->getMemory<x86::reg32>(cpu.ebp)) };
    // 004b66db  0fedca                 -paddsw mm1, mm2
    cpu.mmx.mm1 = { _mm_adds_epi16(cpu.mmx.mm1, cpu.mmx.mm2) };
    // 004b66de  0f7e4d00               -movd dword ptr [ebp], mm1
    _mm_storeu_si32(&app->getMemory<x86::reg32>(cpu.ebp), cpu.mmx.mm1);
    // 004b66e2  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b66e5  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b66e8  83c101                 +add ecx, 1
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
    // 004b66eb  7ce2                   -jl 0x4b66cf
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b66cf;
    }
    // 004b66ed  61                     -popal 
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
    // 004b66ee  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b66ef  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b66f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b66f0);
    // 004b66f0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b66f1  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b66f3  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004b66f4  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b66f7  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b66fa  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
L_0x004b66fd:
    // 004b66fd  668b448efc             -mov ax, word ptr [esi + ecx*4 - 4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(-4) /* -0x4 */ + cpu.ecx * 4);
    // 004b6702  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004b6705  668b448efe             -mov ax, word ptr [esi + ecx*4 - 2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(-2) /* -0x2 */ + cpu.ecx * 4);
    // 004b670a  0f6ec8                 -movd mm1, eax
    cpu.mmx.mm1 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004b670d  0fedc1                 -paddsw mm0, mm1
    cpu.mmx.mm0 = { _mm_adds_epi16(cpu.mmx.mm0, cpu.mmx.mm1) };
    // 004b6710  0f7ec0                 -movd eax, mm0
    cpu.eax = _mm_cvtsi128_si32(cpu.mmx.mm0);
    // 004b6713  3500800000             -xor eax, 0x8000
    cpu.eax ^= x86::reg32(x86::sreg32(32768 /*0x8000*/));
    // 004b6718  886439ff               -mov byte ptr [ecx + edi - 1], ah
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(-1) /* -0x1 */ + cpu.edi * 1) = cpu.ah;
    // 004b671c  83e901                 +sub ecx, 1
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
    // 004b671f  7fdc                   -jg 0x4b66fd
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b66fd;
    }
    // 004b6721  61                     -popal 
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
    // 004b6722  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6723  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b6724(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b6724);
    // 004b6724  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b6725  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b6727  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004b6728  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b672b  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b672e  d1e1                   -shl ecx, 1
    cpu.ecx <<= 1 /*0x1*/ % 32;
    // 004b6730  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b6733  bb30054e00             -mov ebx, 0x4e0530
    cpu.ebx = 5113136 /*0x4e0530*/;
L_0x004b6738:
    // 004b6738  0f6f444ef8             -movq mm0, qword ptr [esi + ecx*2 - 8]
    cpu.mmx.mm0 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.esi + x86::reg32(-8) /* -0x8 */ + cpu.ecx * 2));
    // 004b673d  0f6f4c4ef0             -movq mm1, qword ptr [esi + ecx*2 - 0x10]
    cpu.mmx.mm1 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.esi + x86::reg32(-16) /* -0x10 */ + cpu.ecx * 2));
    // 004b6742  0f6f544ee8             -movq mm2, qword ptr [esi + ecx*2 - 0x18]
    cpu.mmx.mm2 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.esi + x86::reg32(-24) /* -0x18 */ + cpu.ecx * 2));
    // 004b6747  0f6f5c4ee0             -movq mm3, qword ptr [esi + ecx*2 - 0x20]
    cpu.mmx.mm3 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.esi + x86::reg32(-32) /* -0x20 */ + cpu.ecx * 2));
    // 004b674c  0f6f644ed8             -movq mm4, qword ptr [esi + ecx*2 - 0x28]
    cpu.mmx.mm4 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.esi + x86::reg32(-40) /* -0x28 */ + cpu.ecx * 2));
    // 004b6751  0f6f6c4ed0             -movq mm5, qword ptr [esi + ecx*2 - 0x30]
    cpu.mmx.mm5 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.esi + x86::reg32(-48) /* -0x30 */ + cpu.ecx * 2));
    // 004b6756  0f6f744ec8             -movq mm6, qword ptr [esi + ecx*2 - 0x38]
    cpu.mmx.mm6 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.esi + x86::reg32(-56) /* -0x38 */ + cpu.ecx * 2));
    // 004b675b  0f6f7c4ec0             -movq mm7, qword ptr [esi + ecx*2 - 0x40]
    cpu.mmx.mm7 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.esi + x86::reg32(-64) /* -0x40 */ + cpu.ecx * 2));
    // 004b6760  0fedc0                 -paddsw mm0, mm0
    cpu.mmx.mm0 = { _mm_adds_epi16(cpu.mmx.mm0, cpu.mmx.mm0) };
    // 004b6763  0fedc9                 -paddsw mm1, mm1
    cpu.mmx.mm1 = { _mm_adds_epi16(cpu.mmx.mm1, cpu.mmx.mm1) };
    // 004b6766  0fedd2                 -paddsw mm2, mm2
    cpu.mmx.mm2 = { _mm_adds_epi16(cpu.mmx.mm2, cpu.mmx.mm2) };
    // 004b6769  0feddb                 -paddsw mm3, mm3
    cpu.mmx.mm3 = { _mm_adds_epi16(cpu.mmx.mm3, cpu.mmx.mm3) };
    // 004b676c  0fede4                 -paddsw mm4, mm4
    cpu.mmx.mm4 = { _mm_adds_epi16(cpu.mmx.mm4, cpu.mmx.mm4) };
    // 004b676f  0feded                 -paddsw mm5, mm5
    cpu.mmx.mm5 = { _mm_adds_epi16(cpu.mmx.mm5, cpu.mmx.mm5) };
    // 004b6772  0fedf6                 -paddsw mm6, mm6
    cpu.mmx.mm6 = { _mm_adds_epi16(cpu.mmx.mm6, cpu.mmx.mm6) };
    // 004b6775  0fedff                 -paddsw mm7, mm7
    cpu.mmx.mm7 = { _mm_adds_epi16(cpu.mmx.mm7, cpu.mmx.mm7) };
    // 004b6778  0f71d008               -psrlw mm0, 8
    cpu.mmx.mm0 = { _mm_srli_epi16(cpu.mmx.mm0, 8 /*0x8*/) };
    // 004b677c  0f71d108               -psrlw mm1, 8
    cpu.mmx.mm1 = { _mm_srli_epi16(cpu.mmx.mm1, 8 /*0x8*/) };
    // 004b6780  0f71d208               -psrlw mm2, 8
    cpu.mmx.mm2 = { _mm_srli_epi16(cpu.mmx.mm2, 8 /*0x8*/) };
    // 004b6784  0f71d308               -psrlw mm3, 8
    cpu.mmx.mm3 = { _mm_srli_epi16(cpu.mmx.mm3, 8 /*0x8*/) };
    // 004b6788  0f71d408               -psrlw mm4, 8
    cpu.mmx.mm4 = { _mm_srli_epi16(cpu.mmx.mm4, 8 /*0x8*/) };
    // 004b678c  0f71d508               -psrlw mm5, 8
    cpu.mmx.mm5 = { _mm_srli_epi16(cpu.mmx.mm5, 8 /*0x8*/) };
    // 004b6790  0f71d608               -psrlw mm6, 8
    cpu.mmx.mm6 = { _mm_srli_epi16(cpu.mmx.mm6, 8 /*0x8*/) };
    // 004b6794  0f71d708               -psrlw mm7, 8
    cpu.mmx.mm7 = { _mm_srli_epi16(cpu.mmx.mm7, 8 /*0x8*/) };
    // 004b6798  0f67c8                 -packuswb mm1, mm0
    { __m128i _packed = _mm_packus_epi16(cpu.mmx.mm1, cpu.mmx.mm0); cpu.mmx.mm1 = {_mm_unpacklo_epi32(_packed, _mm_srli_si128(_packed, 8))}; }
    // 004b679b  0f67da                 -packuswb mm3, mm2
    { __m128i _packed = _mm_packus_epi16(cpu.mmx.mm3, cpu.mmx.mm2); cpu.mmx.mm3 = {_mm_unpacklo_epi32(_packed, _mm_srli_si128(_packed, 8))}; }
    // 004b679e  0f67ec                 -packuswb mm5, mm4
    { __m128i _packed = _mm_packus_epi16(cpu.mmx.mm5, cpu.mmx.mm4); cpu.mmx.mm5 = {_mm_unpacklo_epi32(_packed, _mm_srli_si128(_packed, 8))}; }
    // 004b67a1  0f67fe                 -packuswb mm7, mm6
    { __m128i _packed = _mm_packus_epi16(cpu.mmx.mm7, cpu.mmx.mm6); cpu.mmx.mm7 = {_mm_unpacklo_epi32(_packed, _mm_srli_si128(_packed, 8))}; }
    // 004b67a4  0f6f03                 -movq mm0, qword ptr [ebx]
    cpu.mmx.mm0 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.ebx));
    // 004b67a7  0fefc8                 -pxor mm1, mm0
    cpu.mmx.mm1 = { _mm_xor_si128(cpu.mmx.mm1, cpu.mmx.mm0) };
    // 004b67aa  0fefd8                 -pxor mm3, mm0
    cpu.mmx.mm3 = { _mm_xor_si128(cpu.mmx.mm3, cpu.mmx.mm0) };
    // 004b67ad  0fefe8                 -pxor mm5, mm0
    cpu.mmx.mm5 = { _mm_xor_si128(cpu.mmx.mm5, cpu.mmx.mm0) };
    // 004b67b0  0feff8                 -pxor mm7, mm0
    cpu.mmx.mm7 = { _mm_xor_si128(cpu.mmx.mm7, cpu.mmx.mm0) };
    // 004b67b3  0f7f4c39f8             -movq qword ptr [ecx + edi - 8], mm1
    app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-8) /* -0x8 */ + cpu.edi * 1) = cpu.mmx.mm1;
    // 004b67b8  0f7f5c39f0             -movq qword ptr [ecx + edi - 0x10], mm3
    app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-16) /* -0x10 */ + cpu.edi * 1) = cpu.mmx.mm3;
    // 004b67bd  0f7f6c39e8             -movq qword ptr [ecx + edi - 0x18], mm5
    app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-24) /* -0x18 */ + cpu.edi * 1) = cpu.mmx.mm5;
    // 004b67c2  0f7f7c39e0             -movq qword ptr [ecx + edi - 0x20], mm7
    app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-32) /* -0x20 */ + cpu.edi * 1) = cpu.mmx.mm7;
    // 004b67c7  83e920                 +sub ecx, 0x20
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
    // 004b67ca  0f8f68ffffff           -jg 0x4b6738
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b6738;
    }
    // 004b67d0  61                     -popal 
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
    // 004b67d1  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b67d2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4b67d4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b67d4);
    // 004b67d4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b67d5  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b67d7  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004b67d8  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b67db  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b67de  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
L_0x004b67e1:
    // 004b67e1  668b448efc             -mov ax, word ptr [esi + ecx*4 - 4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(-4) /* -0x4 */ + cpu.ecx * 4);
    // 004b67e6  0f6ec0                 -movd mm0, eax
    cpu.mmx.mm0 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004b67e9  668b448efe             -mov ax, word ptr [esi + ecx*4 - 2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(-2) /* -0x2 */ + cpu.ecx * 4);
    // 004b67ee  0f6ec8                 -movd mm1, eax
    cpu.mmx.mm1 = { _mm_cvtsi32_si128(cpu.eax) };
    // 004b67f1  0fedc1                 -paddsw mm0, mm1
    cpu.mmx.mm0 = { _mm_adds_epi16(cpu.mmx.mm0, cpu.mmx.mm1) };
    // 004b67f4  0f7ec0                 -movd eax, mm0
    cpu.eax = _mm_cvtsi128_si32(cpu.mmx.mm0);
    // 004b67f7  6689444ffe             -mov word ptr [edi + ecx*2 - 2], ax
    app->getMemory<x86::reg16>(cpu.edi + x86::reg32(-2) /* -0x2 */ + cpu.ecx * 2) = cpu.ax;
    // 004b67fc  83e901                 +sub ecx, 1
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
    // 004b67ff  7fe0                   -jg 0x4b67e1
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b67e1;
    }
    // 004b6801  61                     -popal 
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
    // 004b6802  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6803  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b6804(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b6804);
    // 004b6804  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b6805  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b6807  60                     -pushal 
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    app->getMemory<x86::reg32>(cpu.esp-8) = cpu.ecx;
    app->getMemory<x86::reg32>(cpu.esp-12) = cpu.edx;
    app->getMemory<x86::reg32>(cpu.esp-16) = cpu.ebx;
    app->getMemory<x86::reg32>(cpu.esp-20) = cpu.esp;
    app->getMemory<x86::reg32>(cpu.esp-24) = cpu.ebp;
    app->getMemory<x86::reg32>(cpu.esp-28) = cpu.esi;
    app->getMemory<x86::reg32>(cpu.esp-32) = cpu.edi;
    cpu.esp -= 32;
    // 004b6808  8b4d08                 -mov ecx, dword ptr [ebp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b680b  8b7d10                 -mov edi, dword ptr [ebp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(16) /* 0x10 */);
    // 004b680e  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 004b6811  8b750c                 -mov esi, dword ptr [ebp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
L_0x004b6814:
    // 004b6814  0f6f4431f8             -movq mm0, qword ptr [ecx + esi - 8]
    cpu.mmx.mm0 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-8) /* -0x8 */ + cpu.esi * 1));
    // 004b6819  0f6f4c31f0             -movq mm1, qword ptr [ecx + esi - 0x10]
    cpu.mmx.mm1 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-16) /* -0x10 */ + cpu.esi * 1));
    // 004b681e  0f6f5431e8             -movq mm2, qword ptr [ecx + esi - 0x18]
    cpu.mmx.mm2 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-24) /* -0x18 */ + cpu.esi * 1));
    // 004b6823  0f6f5c31e0             -movq mm3, qword ptr [ecx + esi - 0x20]
    cpu.mmx.mm3 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-32) /* -0x20 */ + cpu.esi * 1));
    // 004b6828  0f6f6431d8             -movq mm4, qword ptr [ecx + esi - 0x28]
    cpu.mmx.mm4 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-40) /* -0x28 */ + cpu.esi * 1));
    // 004b682d  0f6f6c31d0             -movq mm5, qword ptr [ecx + esi - 0x30]
    cpu.mmx.mm5 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-48) /* -0x30 */ + cpu.esi * 1));
    // 004b6832  0f6f7431c8             -movq mm6, qword ptr [ecx + esi - 0x38]
    cpu.mmx.mm6 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-56) /* -0x38 */ + cpu.esi * 1));
    // 004b6837  0f6f7c31c0             -movq mm7, qword ptr [ecx + esi - 0x40]
    cpu.mmx.mm7 = x86::from_reg64(app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-64) /* -0x40 */ + cpu.esi * 1));
    // 004b683c  0fedc0                 -paddsw mm0, mm0
    cpu.mmx.mm0 = { _mm_adds_epi16(cpu.mmx.mm0, cpu.mmx.mm0) };
    // 004b683f  0fedc9                 -paddsw mm1, mm1
    cpu.mmx.mm1 = { _mm_adds_epi16(cpu.mmx.mm1, cpu.mmx.mm1) };
    // 004b6842  0fedd2                 -paddsw mm2, mm2
    cpu.mmx.mm2 = { _mm_adds_epi16(cpu.mmx.mm2, cpu.mmx.mm2) };
    // 004b6845  0feddb                 -paddsw mm3, mm3
    cpu.mmx.mm3 = { _mm_adds_epi16(cpu.mmx.mm3, cpu.mmx.mm3) };
    // 004b6848  0fede4                 -paddsw mm4, mm4
    cpu.mmx.mm4 = { _mm_adds_epi16(cpu.mmx.mm4, cpu.mmx.mm4) };
    // 004b684b  0feded                 -paddsw mm5, mm5
    cpu.mmx.mm5 = { _mm_adds_epi16(cpu.mmx.mm5, cpu.mmx.mm5) };
    // 004b684e  0fedf6                 -paddsw mm6, mm6
    cpu.mmx.mm6 = { _mm_adds_epi16(cpu.mmx.mm6, cpu.mmx.mm6) };
    // 004b6851  0fedff                 -paddsw mm7, mm7
    cpu.mmx.mm7 = { _mm_adds_epi16(cpu.mmx.mm7, cpu.mmx.mm7) };
    // 004b6854  0f7f4439f8             -movq qword ptr [ecx + edi - 8], mm0
    app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-8) /* -0x8 */ + cpu.edi * 1) = cpu.mmx.mm0;
    // 004b6859  0f7f4c39f0             -movq qword ptr [ecx + edi - 0x10], mm1
    app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-16) /* -0x10 */ + cpu.edi * 1) = cpu.mmx.mm1;
    // 004b685e  0f7f5439e8             -movq qword ptr [ecx + edi - 0x18], mm2
    app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-24) /* -0x18 */ + cpu.edi * 1) = cpu.mmx.mm2;
    // 004b6863  0f7f5c39e0             -movq qword ptr [ecx + edi - 0x20], mm3
    app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-32) /* -0x20 */ + cpu.edi * 1) = cpu.mmx.mm3;
    // 004b6868  0f7f6439d8             -movq qword ptr [ecx + edi - 0x28], mm4
    app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-40) /* -0x28 */ + cpu.edi * 1) = cpu.mmx.mm4;
    // 004b686d  0f7f6c39d0             -movq qword ptr [ecx + edi - 0x30], mm5
    app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-48) /* -0x30 */ + cpu.edi * 1) = cpu.mmx.mm5;
    // 004b6872  0f7f7439c8             -movq qword ptr [ecx + edi - 0x38], mm6
    app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-56) /* -0x38 */ + cpu.edi * 1) = cpu.mmx.mm6;
    // 004b6877  0f7f7c39c0             -movq qword ptr [ecx + edi - 0x40], mm7
    app->getMemory<x86::reg64>(cpu.ecx + x86::reg32(-64) /* -0x40 */ + cpu.edi * 1) = cpu.mmx.mm7;
    // 004b687c  83e940                 +sub ecx, 0x40
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
    // 004b687f  7f93                   -jg 0x4b6814
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b6814;
    }
    // 004b6881  61                     -popal 
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
    // 004b6882  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6883  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b6884(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b6884);
    // 004b6884  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b6885  8bec                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b6887  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b6888  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b6889  8b4d0c                 -mov ecx, dword ptr [ebp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 004b688c  8b7d08                 -mov edi, dword ptr [ebp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 004b688f  0fefc0                 -pxor mm0, mm0
    cpu.mmx.mm0 = { _mm_xor_si128(cpu.mmx.mm0, cpu.mmx.mm0) };
    // 004b6892  83f90f                 +cmp ecx, 0xf
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
    // 004b6895  7e2d                   -jle 0x4b68c4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b68c4;
    }
    // 004b6897  83e90f                 -sub ecx, 0xf
    (cpu.ecx) -= x86::reg32(x86::sreg32(15 /*0xf*/));
L_0x004b689a:
    // 004b689a  0f7f07                 -movq qword ptr [edi], mm0
    app->getMemory<x86::reg64>(cpu.edi) = cpu.mmx.mm0;
    // 004b689d  0f7f4708               -movq qword ptr [edi + 8], mm0
    app->getMemory<x86::reg64>(cpu.edi + x86::reg32(8) /* 0x8 */) = cpu.mmx.mm0;
    // 004b68a1  0f7f4710               -movq qword ptr [edi + 0x10], mm0
    app->getMemory<x86::reg64>(cpu.edi + x86::reg32(16) /* 0x10 */) = cpu.mmx.mm0;
    // 004b68a5  0f7f4718               -movq qword ptr [edi + 0x18], mm0
    app->getMemory<x86::reg64>(cpu.edi + x86::reg32(24) /* 0x18 */) = cpu.mmx.mm0;
    // 004b68a9  0f7f4720               -movq qword ptr [edi + 0x20], mm0
    app->getMemory<x86::reg64>(cpu.edi + x86::reg32(32) /* 0x20 */) = cpu.mmx.mm0;
    // 004b68ad  0f7f4728               -movq qword ptr [edi + 0x28], mm0
    app->getMemory<x86::reg64>(cpu.edi + x86::reg32(40) /* 0x28 */) = cpu.mmx.mm0;
    // 004b68b1  0f7f4730               -movq qword ptr [edi + 0x30], mm0
    app->getMemory<x86::reg64>(cpu.edi + x86::reg32(48) /* 0x30 */) = cpu.mmx.mm0;
    // 004b68b5  0f7f4738               -movq qword ptr [edi + 0x38], mm0
    app->getMemory<x86::reg64>(cpu.edi + x86::reg32(56) /* 0x38 */) = cpu.mmx.mm0;
    // 004b68b9  83c740                 -add edi, 0x40
    (cpu.edi) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004b68bc  83e910                 +sub ecx, 0x10
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
    // 004b68bf  7fd9                   -jg 0x4b689a
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b689a;
    }
    // 004b68c1  83c10f                 -add ecx, 0xf
    (cpu.ecx) += x86::reg32(x86::sreg32(15 /*0xf*/));
L_0x004b68c4:
    // 004b68c4  83f900                 +cmp ecx, 0
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
    // 004b68c7  7e0b                   -jle 0x4b68d4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b68d4;
    }
    // 004b68c9  0f7e07                 -movd dword ptr [edi], mm0
    _mm_storeu_si32(&app->getMemory<x86::reg32>(cpu.edi), cpu.mmx.mm0);
    // 004b68cc  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b68cf  83e901                 +sub ecx, 1
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
    // 004b68d2  7ff0                   -jg 0x4b68c4
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004b68c4;
    }
L_0x004b68d4:
    // 004b68d4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b68d5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b68d6  0f77                   -emms 
    cpu.mmx.init();
    // 004b68d8  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b68d9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4b68e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b68e0);
    // 004b68e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b68e1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b68e2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b68e3  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b68e7  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004b68eb  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004b68ee  48                     -dec eax
    (cpu.eax)--;
    // 004b68ef  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004b68f2  034204                 -add eax, dword ptr [edx + 4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 004b68f5  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b68f8  8b5a0d                 -mov ebx, dword ptr [edx + 0xd]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(13) /* 0xd */);
    // 004b68fb  40                     -inc eax
    (cpu.eax)++;
    // 004b68fc  c1fb18                 -sar ebx, 0x18
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (24 /*0x18*/ % 32));
    // 004b68ff  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b6901  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b6903  8a5a0f                 -mov bl, byte ptr [edx + 0xf]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(15) /* 0xf */);
    // 004b6906  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b6908  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 004b690a  7501                   -jne 0x4b690d
    if (!cpu.flags.zf)
    {
        goto L_0x004b690d;
    }
    // 004b690c  40                     -inc eax
    (cpu.eax)++;
L_0x004b690d:
    // 004b690d  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004b6911  8b5108                 -mov edx, dword ptr [ecx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004b6914  0fafd7                 -imul edx, edi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 004b6917  035104                 -add edx, dword ptr [ecx + 4]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
    // 004b691a  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004b691d  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004b691f  885110                 -mov byte ptr [ecx + 0x10], dl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.dl;
    // 004b6922  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6923  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6924  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6925  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4b6928(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b6928);
    // 004b6928  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b692c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4b6930(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b6930);
    // 004b6930  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b6931  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b6935  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b6939  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004b693c  48                     -dec eax
    (cpu.eax)--;
    // 004b693d  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004b6940  034204                 -add eax, dword ptr [edx + 4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 004b6943  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b6945  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b6948  8a5a0f                 -mov bl, byte ptr [edx + 0xf]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(15) /* 0xf */);
    // 004b694b  40                     -inc eax
    (cpu.eax)++;
    // 004b694c  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 004b694e  7501                   -jne 0x4b6951
    if (!cpu.flags.zf)
    {
        goto L_0x004b6951;
    }
    // 004b6950  40                     -inc eax
    (cpu.eax)++;
L_0x004b6951:
    // 004b6951  8b510b                 -mov edx, dword ptr [ecx + 0xb]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(11) /* 0xb */);
    // 004b6954  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004b6957  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b6959  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b695a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4b695c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b695c);
    // 004b695c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b695d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b695e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b695f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b6960  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b6963  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004b6967  8b7c241c               -mov edi, dword ptr [esp + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004b696b  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004b696f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b6971  8a480f                 -mov cl, byte ptr [eax + 0xf]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(15) /* 0xf */);
    // 004b6974  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004b6976  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 004b6978  7572                   -jne 0x4b69ec
    if (!cpu.flags.zf)
    {
        goto L_0x004b69ec;
    }
L_0x004b697a:
    // 004b697a  8b6c2424               -mov ebp, dword ptr [esp + 0x24]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004b697e  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp);
    // 004b6981  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004b6982  7572                   -jne 0x4b69f6
    if (!cpu.flags.zf)
    {
        goto L_0x004b69f6;
    }
L_0x004b6984:
    // 004b6984  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b6986  baffff0000             -mov edx, 0xffff
    cpu.edx = 65535 /*0xffff*/;
    // 004b698b  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b698e  0fbe0406               -movsx eax, byte ptr [esi + eax]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1)));
    // 004b6992  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b6994  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004b6997  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004b699a  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b699c  0fbe543201             -movsx edx, byte ptr [edx + esi + 1]
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */ + cpu.esi * 1)));
    // 004b69a1  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004b69a4  0fafd1                 -imul edx, ecx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004b69a7  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b69aa  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004b69ad  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b69af  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 004b69b2  88042f                 -mov byte ptr [edi + ebp], al
    app->getMemory<x86::reg8>(cpu.edi + cpu.ebp * 1) = cpu.al;
    // 004b69b5  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b69b7  8a440601               -mov al, byte ptr [esi + eax + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.eax * 1);
    // 004b69bb  88430d                 -mov byte ptr [ebx + 0xd], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(13) /* 0xd */) = cpu.al;
    // 004b69be  8b7304                 -mov esi, dword ptr [ebx + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b69c1  037308                 -add esi, dword ptr [ebx + 8]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */)));
    // 004b69c4  8b3b                   -mov edi, dword ptr [ebx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b69c6  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b69c8  897304                 -mov dword ptr [ebx + 4], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 004b69cb  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b69ce  66c743060000           -mov word ptr [ebx + 6], 0
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 004b69d4  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b69d6  8b430d                 -mov eax, dword ptr [ebx + 0xd]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(13) /* 0xd */);
    // 004b69d9  893b                   -mov dword ptr [ebx], edi
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edi;
    // 004b69db  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004b69de  c6430f01               -mov byte ptr [ebx + 0xf], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(15) /* 0xf */) = 1 /*0x1*/;
    // 004b69e2  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004b69e4  83c404                 +add esp, 4
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
    // 004b69e7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b69e8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b69e9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b69ea  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b69eb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b69ec:
    // 004b69ec  8d72ff                 -lea esi, [edx - 1]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 004b69ef  8a400d                 -mov al, byte ptr [eax + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */);
    // 004b69f2  8806                   -mov byte ptr [esi], al
    app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
    // 004b69f4  eb84                   -jmp 0x4b697a
    goto L_0x004b697a;
L_0x004b69f6:
    // 004b69f6  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b69f9  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b69fc  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b69ff  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004b6a02  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004b6a05  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b6a06  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004b6a09  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b6a0a  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b6a0e  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b6a12  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b6a13  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b6a14  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b6a15  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b6a16  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b6a17  e818550000             -call 0x4bbf34
    cpu.esp -= 4;
    sub_4bbf34(app, cpu);
    if (cpu.terminate) return;
    // 004b6a1c  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004b6a1f  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004b6a22  c1e810                 +shr eax, 0x10
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
    // 004b6a25  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004b6a28  e957ffffff             -jmp 0x4b6984
    goto L_0x004b6984;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4b6a30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b6a30);
    // 004b6a30  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b6a34  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b6a38  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004b6a3a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4b6a3c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b6a3c);
    // 004b6a3c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b6a3d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b6a3e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b6a3f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b6a40  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b6a43  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004b6a47  8b7c241c               -mov edi, dword ptr [esp + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004b6a4b  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004b6a4f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b6a51  8a480f                 -mov cl, byte ptr [eax + 0xf]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(15) /* 0xf */);
    // 004b6a54  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004b6a56  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 004b6a58  0f85c7000000           -jne 0x4b6b25
    if (!cpu.flags.zf)
    {
        goto L_0x004b6b25;
    }
L_0x004b6a5e:
    // 004b6a5e  807b0e00               +cmp byte ptr [ebx + 0xe], 0
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
    // 004b6a62  7406                   -je 0x4b6a6a
    if (cpu.flags.zf)
    {
        goto L_0x004b6a6a;
    }
    // 004b6a64  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004b6a65  8a430c                 -mov al, byte ptr [ebx + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004b6a68  8806                   -mov byte ptr [esi], al
    app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
L_0x004b6a6a:
    // 004b6a6a  8b6c2424               -mov ebp, dword ptr [esp + 0x24]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004b6a6e  c70300000000           -mov dword ptr [ebx], 0
    app->getMemory<x86::reg32>(cpu.ebx) = 0 /*0x0*/;
    // 004b6a74  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp);
    // 004b6a77  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004b6a78  7432                   -je 0x4b6aac
    if (cpu.flags.zf)
    {
        goto L_0x004b6aac;
    }
    // 004b6a7a  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b6a7d  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b6a80  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b6a83  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004b6a86  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004b6a89  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b6a8a  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004b6a8d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b6a8e  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b6a92  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b6a96  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b6a97  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b6a98  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b6a99  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b6a9a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b6a9b  e894540000             -call 0x4bbf34
    cpu.esp -= 4;
    sub_4bbf34(app, cpu);
    if (cpu.terminate) return;
    // 004b6aa0  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004b6aa3  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004b6aa6  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b6aa9  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x004b6aac:
    // 004b6aac  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b6aae  0fbe0406               -movsx eax, byte ptr [esi + eax]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1)));
    // 004b6ab2  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b6ab5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b6ab7  b8ffff0000             -mov eax, 0xffff
    cpu.eax = 65535 /*0xffff*/;
    // 004b6abc  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004b6abf  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b6ac1  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004b6ac4  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b6ac6  0fbe543201             -movsx edx, byte ptr [edx + esi + 1]
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */ + cpu.esi * 1)));
    // 004b6acb  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004b6ace  0fafd1                 -imul edx, ecx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004b6ad1  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b6ad4  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004b6ad7  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b6ad9  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 004b6adc  88042f                 -mov byte ptr [edi + ebp], al
    app->getMemory<x86::reg8>(cpu.edi + cpu.ebp * 1) = cpu.al;
    // 004b6adf  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b6ae1  8a440601               -mov al, byte ptr [esi + eax + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.eax * 1);
    // 004b6ae5  88430d                 -mov byte ptr [ebx + 0xd], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(13) /* 0xd */) = cpu.al;
    // 004b6ae8  8b7b04                 -mov edi, dword ptr [ebx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b6aeb  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b6aee  8b2b                   -mov ebp, dword ptr [ebx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b6af0  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b6af2  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b6af5  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004b6af7  897b04                 -mov dword ptr [ebx + 4], edi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 004b6afa  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b6afd  66c743060000           -mov word ptr [ebx + 6], 0
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 004b6b03  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b6b05  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b6b08  892b                   -mov dword ptr [ebx], ebp
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.ebp;
    // 004b6b0a  39d0                   +cmp eax, edx
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
    // 004b6b0c  7224                   -jb 0x4b6b32
    if (cpu.flags.cf)
    {
        goto L_0x004b6b32;
    }
    // 004b6b0e  0333                   -add esi, dword ptr [ebx]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx)));
    // 004b6b10  c6430e01               -mov byte ptr [ebx + 0xe], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(14) /* 0xe */) = 1 /*0x1*/;
    // 004b6b14  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004b6b16  88430c                 -mov byte ptr [ebx + 0xc], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.al;
    // 004b6b19  c6430f01               -mov byte ptr [ebx + 0xf], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(15) /* 0xf */) = 1 /*0x1*/;
    // 004b6b1d  83c404                 +add esp, 4
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
    // 004b6b20  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6b21  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6b22  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6b23  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6b24  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b6b25:
    // 004b6b25  8d72ff                 -lea esi, [edx - 1]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 004b6b28  8a400d                 -mov al, byte ptr [eax + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */);
    // 004b6b2b  8806                   -mov byte ptr [esi], al
    app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
    // 004b6b2d  e92cffffff             -jmp 0x4b6a5e
    goto L_0x004b6a5e;
L_0x004b6b32:
    // 004b6b32  c6430e00               -mov byte ptr [ebx + 0xe], 0
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(14) /* 0xe */) = 0 /*0x0*/;
    // 004b6b36  c6430f01               -mov byte ptr [ebx + 0xf], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(15) /* 0xf */) = 1 /*0x1*/;
    // 004b6b3a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b6b3d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6b3e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6b3f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6b40  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6b41  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4b6b44(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b6b44);
    // 004b6b44  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b6b45  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b6b46  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b6b4a  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b6b4e  8b5908                 -mov ebx, dword ptr [ecx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004b6b51  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b6b53  81fb00000100           +cmp ebx, 0x10000
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
    // 004b6b59  732c                   -jae 0x4b6b87
    if (!cpu.flags.cf)
    {
        goto L_0x004b6b87;
    }
    // 004b6b5b  81fa00000100           +cmp edx, 0x10000
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
    // 004b6b61  7324                   -jae 0x4b6b87
    if (!cpu.flags.cf)
    {
        goto L_0x004b6b87;
    }
L_0x004b6b63:
    // 004b6b63  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004b6b66  81fa00000100           +cmp edx, 0x10000
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
    // 004b6b6c  724b                   -jb 0x4b6bb9
    if (cpu.flags.cf)
    {
        goto L_0x004b6bb9;
    }
    // 004b6b6e  7660                   -jbe 0x4b6bd0
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b6bd0;
    }
    // 004b6b70  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004b6b73  c702e0684b00           -mov dword ptr [edx], 0x4b68e0
    app->getMemory<x86::reg32>(cpu.edx) = 4942048 /*0x4b68e0*/;
    // 004b6b79  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004b6b7c  c7005c694b00           -mov dword ptr [eax], 0x4b695c
    app->getMemory<x86::reg32>(cpu.eax) = 4942172 /*0x4b695c*/;
    // 004b6b82  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b6b84  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6b85  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6b86  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b6b87:
    // 004b6b87  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004b6b8a  39f2                   +cmp edx, esi
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
    // 004b6b8c  74d5                   -je 0x4b6b63
    if (cpu.flags.zf)
    {
        goto L_0x004b6b63;
    }
    // 004b6b8e  81fe00000100           +cmp esi, 0x10000
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
    // 004b6b94  7608                   -jbe 0x4b6b9e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b6b9e;
    }
    // 004b6b96  81fa00000100           +cmp edx, 0x10000
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
    // 004b6b9c  77c5                   -ja 0x4b6b63
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004b6b63;
    }
L_0x004b6b9e:
    // 004b6b9e  c6400e00               -mov byte ptr [eax + 0xe], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(14) /* 0xe */) = 0 /*0x0*/;
    // 004b6ba2  c6400f00               -mov byte ptr [eax + 0xf], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(15) /* 0xf */) = 0 /*0x0*/;
    // 004b6ba6  c6401000               -mov byte ptr [eax + 0x10], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 004b6baa  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004b6bb1  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004b6bb7  ebaa                   -jmp 0x4b6b63
    goto L_0x004b6b63;
L_0x004b6bb9:
    // 004b6bb9  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004b6bbc  c70230694b00           -mov dword ptr [edx], 0x4b6930
    app->getMemory<x86::reg32>(cpu.edx) = 4942128 /*0x4b6930*/;
    // 004b6bc2  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004b6bc5  c7003c6a4b00           -mov dword ptr [eax], 0x4b6a3c
    app->getMemory<x86::reg32>(cpu.eax) = 4942396 /*0x4b6a3c*/;
    // 004b6bcb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b6bcd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6bce  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6bcf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b6bd0:
    // 004b6bd0  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004b6bd3  c70228694b00           -mov dword ptr [edx], 0x4b6928
    app->getMemory<x86::reg32>(cpu.edx) = 4942120 /*0x4b6928*/;
    // 004b6bd9  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004b6bdc  c700306a4b00           -mov dword ptr [eax], 0x4b6a30
    app->getMemory<x86::reg32>(cpu.eax) = 4942384 /*0x4b6a30*/;
    // 004b6be2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b6be4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6be5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6be6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4b6be8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b6be8);
    // 004b6be8  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b6bec  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004b6bf2  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004b6bf9  c6400e00               -mov byte ptr [eax + 0xe], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(14) /* 0xe */) = 0 /*0x0*/;
    // 004b6bfd  c6400d00               -mov byte ptr [eax + 0xd], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */) = 0 /*0x0*/;
    // 004b6c01  c6400f00               -mov byte ptr [eax + 0xf], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(15) /* 0xf */) = 0 /*0x0*/;
    // 004b6c05  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b6c09  c6401001               -mov byte ptr [eax + 0x10], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(16) /* 0x10 */) = 1 /*0x1*/;
    // 004b6c0d  895014                 -mov dword ptr [eax + 0x14], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004b6c10  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b6c14  895018                 -mov dword ptr [eax + 0x18], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004b6c17  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b6c1b  89501c                 -mov dword ptr [eax + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004b6c1e  8b4014                 -mov eax, dword ptr [eax + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004b6c21  c700446b4b00           -mov dword ptr [eax], 0x4b6b44
    app->getMemory<x86::reg32>(cpu.eax) = 4942660 /*0x4b6b44*/;
    // 004b6c27  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b6c29  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4b6c30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b6c30);
    // 004b6c30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b6c31  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b6c32  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b6c33  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b6c37  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004b6c3b  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004b6c3e  48                     -dec eax
    (cpu.eax)--;
    // 004b6c3f  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004b6c42  034204                 -add eax, dword ptr [edx + 4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 004b6c45  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b6c48  8b5a0f                 -mov ebx, dword ptr [edx + 0xf]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(15) /* 0xf */);
    // 004b6c4b  40                     -inc eax
    (cpu.eax)++;
    // 004b6c4c  c1fb18                 -sar ebx, 0x18
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (24 /*0x18*/ % 32));
    // 004b6c4f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b6c51  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b6c53  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 004b6c56  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b6c58  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 004b6c5a  7501                   -jne 0x4b6c5d
    if (!cpu.flags.zf)
    {
        goto L_0x004b6c5d;
    }
    // 004b6c5c  40                     -inc eax
    (cpu.eax)++;
L_0x004b6c5d:
    // 004b6c5d  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004b6c61  8b5108                 -mov edx, dword ptr [ecx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004b6c64  0fafd7                 -imul edx, edi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 004b6c67  035104                 -add edx, dword ptr [ecx + 4]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
    // 004b6c6a  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004b6c6d  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004b6c6f  885112                 -mov byte ptr [ecx + 0x12], dl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(18) /* 0x12 */) = cpu.dl;
    // 004b6c72  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6c73  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6c74  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6c75  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4b6c78(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b6c78);
    // 004b6c78  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b6c7c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4b6c80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b6c80);
    // 004b6c80  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b6c81  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b6c85  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b6c89  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004b6c8c  48                     -dec eax
    (cpu.eax)--;
    // 004b6c8d  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004b6c90  034204                 -add eax, dword ptr [edx + 4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 004b6c93  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b6c95  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b6c98  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 004b6c9b  40                     -inc eax
    (cpu.eax)++;
    // 004b6c9c  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 004b6c9e  7501                   -jne 0x4b6ca1
    if (!cpu.flags.zf)
    {
        goto L_0x004b6ca1;
    }
    // 004b6ca0  40                     -inc eax
    (cpu.eax)++;
L_0x004b6ca1:
    // 004b6ca1  8b510d                 -mov edx, dword ptr [ecx + 0xd]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(13) /* 0xd */);
    // 004b6ca4  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004b6ca7  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b6ca9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6caa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4b6cac(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b6cac);
    // 004b6cac  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b6cad  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b6cae  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b6caf  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b6cb0  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b6cb3  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004b6cb7  8b7c2420               -mov edi, dword ptr [esp + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004b6cbb  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004b6cbf  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b6cc1  8a4811                 -mov cl, byte ptr [eax + 0x11]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(17) /* 0x11 */);
    // 004b6cc4  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004b6cc6  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 004b6cc8  0f85b9000000           -jne 0x4b6d87
    if (!cpu.flags.zf)
    {
        goto L_0x004b6d87;
    }
L_0x004b6cce:
    // 004b6cce  8b6c2428               -mov ebp, dword ptr [esp + 0x28]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004b6cd2  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp);
    // 004b6cd5  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004b6cd6  0f85be000000           -jne 0x4b6d9a
    if (!cpu.flags.zf)
    {
        goto L_0x004b6d9a;
    }
L_0x004b6cdc:
    // 004b6cdc  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b6cde  0fbe0456               -movsx eax, byte ptr [esi + edx*2]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.esi + cpu.edx * 2)));
    // 004b6ce2  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004b6ce5  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b6ce8  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004b6cec  b8ffff0000             -mov eax, 0xffff
    cpu.eax = 65535 /*0xffff*/;
    // 004b6cf1  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b6cf3  0faf442404             -imul eax, dword ptr [esp + 4]
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */))));
    // 004b6cf8  0fbe545602             -movsx edx, byte ptr [esi + edx*2 + 2]
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */ + cpu.edx * 2)));
    // 004b6cfd  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004b6d00  0faf5304               -imul edx, dword ptr [ebx + 4]
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */))));
    // 004b6d04  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b6d07  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004b6d0a  01ff                   -add edi, edi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edi));
    // 004b6d0c  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b6d0e  01fd                   -add ebp, edi
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edi));
    // 004b6d10  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 004b6d13  884500                 -mov byte ptr [ebp], al
    app->getMemory<x86::reg8>(cpu.ebp) = cpu.al;
    // 004b6d16  8b3b                   -mov edi, dword ptr [ebx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b6d18  b8ffff0000             -mov eax, 0xffff
    cpu.eax = 65535 /*0xffff*/;
    // 004b6d1d  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b6d20  0fbe547e01             -movsx edx, byte ptr [esi + edi*2 + 1]
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.edi * 2)));
    // 004b6d25  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b6d27  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004b6d2a  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004b6d2d  8b147e                 -mov edx, dword ptr [esi + edi*2]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + cpu.edi * 2);
    // 004b6d30  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004b6d33  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004b6d36  0fafd1                 -imul edx, ecx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004b6d39  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b6d3c  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004b6d3f  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b6d41  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 004b6d44  884501                 -mov byte ptr [ebp + 1], al
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004b6d47  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b6d49  8a444602               -mov al, byte ptr [esi + eax*2 + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */ + cpu.eax * 2);
    // 004b6d4d  88430e                 -mov byte ptr [ebx + 0xe], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(14) /* 0xe */) = cpu.al;
    // 004b6d50  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b6d52  8a444603               -mov al, byte ptr [esi + eax*2 + 3]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */ + cpu.eax * 2);
    // 004b6d56  88430f                 -mov byte ptr [ebx + 0xf], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(15) /* 0xf */) = cpu.al;
    // 004b6d59  8b6b04                 -mov ebp, dword ptr [ebx + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b6d5c  036b08                 -add ebp, dword ptr [ebx + 8]
    (cpu.ebp) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */)));
    // 004b6d5f  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b6d61  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004b6d63  896b04                 -mov dword ptr [ebx + 4], ebp
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 004b6d66  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b6d69  66c743060000           -mov word ptr [ebx + 6], 0
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 004b6d6f  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b6d71  8b430f                 -mov eax, dword ptr [ebx + 0xf]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(15) /* 0xf */);
    // 004b6d74  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 004b6d76  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004b6d79  c6431101               -mov byte ptr [ebx + 0x11], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(17) /* 0x11 */) = 1 /*0x1*/;
    // 004b6d7d  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004b6d7f  83c408                 +add esp, 8
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
    // 004b6d82  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6d83  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6d84  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6d85  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6d86  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b6d87:
    // 004b6d87  8d72ff                 -lea esi, [edx - 1]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 004b6d8a  8a500f                 -mov dl, byte ptr [eax + 0xf]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(15) /* 0xf */);
    // 004b6d8d  8816                   -mov byte ptr [esi], dl
    app->getMemory<x86::reg8>(cpu.esi) = cpu.dl;
    // 004b6d8f  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004b6d90  8a400e                 -mov al, byte ptr [eax + 0xe]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(14) /* 0xe */);
    // 004b6d93  8806                   -mov byte ptr [esi], al
    app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
    // 004b6d95  e934ffffff             -jmp 0x4b6cce
    goto L_0x004b6cce;
L_0x004b6d9a:
    // 004b6d9a  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b6d9d  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b6da0  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b6da3  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004b6da6  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004b6da9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b6daa  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004b6dad  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b6dae  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b6db2  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b6db6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b6db7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b6db8  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b6db9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b6dba  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b6dbb  e8f4510000             -call 0x4bbfb4
    cpu.esp -= 4;
    sub_4bbfb4(app, cpu);
    if (cpu.terminate) return;
    // 004b6dc0  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004b6dc3  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004b6dc6  c1e810                 +shr eax, 0x10
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
    // 004b6dc9  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004b6dcc  e90bffffff             -jmp 0x4b6cdc
    goto L_0x004b6cdc;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4b6dd4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b6dd4);
    // 004b6dd4  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b6dd8  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b6ddc  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004b6dde  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4b6de0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b6de0);
    // 004b6de0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b6de1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b6de2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b6de3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b6de4  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b6de7  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004b6deb  8b7c241c               -mov edi, dword ptr [esp + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004b6def  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004b6df3  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b6df5  8a4811                 -mov cl, byte ptr [eax + 0x11]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(17) /* 0x11 */);
    // 004b6df8  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004b6dfa  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 004b6dfc  0f8510010000           -jne 0x4b6f12
    if (!cpu.flags.zf)
    {
        goto L_0x004b6f12;
    }
L_0x004b6e02:
    // 004b6e02  807b1000               +cmp byte ptr [ebx + 0x10], 0
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
    // 004b6e06  740c                   -je 0x4b6e14
    if (cpu.flags.zf)
    {
        goto L_0x004b6e14;
    }
    // 004b6e08  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004b6e09  8a430d                 -mov al, byte ptr [ebx + 0xd]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(13) /* 0xd */);
    // 004b6e0c  8806                   -mov byte ptr [esi], al
    app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
    // 004b6e0e  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004b6e0f  8a430c                 -mov al, byte ptr [ebx + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004b6e12  8806                   -mov byte ptr [esi], al
    app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
L_0x004b6e14:
    // 004b6e14  8b6c2424               -mov ebp, dword ptr [esp + 0x24]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004b6e18  c70300000000           -mov dword ptr [ebx], 0
    app->getMemory<x86::reg32>(cpu.ebx) = 0 /*0x0*/;
    // 004b6e1e  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp);
    // 004b6e21  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004b6e22  7432                   -je 0x4b6e56
    if (cpu.flags.zf)
    {
        goto L_0x004b6e56;
    }
    // 004b6e24  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b6e27  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b6e2a  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b6e2d  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004b6e30  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004b6e33  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b6e34  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004b6e37  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b6e38  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b6e3c  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b6e40  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b6e41  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b6e42  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b6e43  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b6e44  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b6e45  e86a510000             -call 0x4bbfb4
    cpu.esp -= 4;
    sub_4bbfb4(app, cpu);
    if (cpu.terminate) return;
    // 004b6e4a  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004b6e4d  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004b6e50  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b6e53  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x004b6e56:
    // 004b6e56  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b6e58  b9ffff0000             -mov ecx, 0xffff
    cpu.ecx = 65535 /*0xffff*/;
    // 004b6e5d  0fbe0456               -movsx eax, byte ptr [esi + edx*2]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.esi + cpu.edx * 2)));
    // 004b6e61  2b4b04                 -sub ecx, dword ptr [ebx + 4]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */)));
    // 004b6e64  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 004b6e67  0fafc1                 -imul eax, ecx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004b6e6a  0fbe545602             -movsx edx, byte ptr [esi + edx*2 + 2]
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */ + cpu.edx * 2)));
    // 004b6e6f  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004b6e72  0faf5304               -imul edx, dword ptr [ebx + 4]
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */))));
    // 004b6e76  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b6e79  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004b6e7c  01ff                   -add edi, edi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edi));
    // 004b6e7e  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b6e80  01fd                   -add ebp, edi
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edi));
    // 004b6e82  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 004b6e85  884500                 -mov byte ptr [ebp], al
    app->getMemory<x86::reg8>(cpu.ebp) = cpu.al;
    // 004b6e88  8b3b                   -mov edi, dword ptr [ebx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b6e8a  b8ffff0000             -mov eax, 0xffff
    cpu.eax = 65535 /*0xffff*/;
    // 004b6e8f  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b6e92  0fbe547e01             -movsx edx, byte ptr [esi + edi*2 + 1]
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.edi * 2)));
    // 004b6e97  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b6e99  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004b6e9c  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004b6e9f  8b147e                 -mov edx, dword ptr [esi + edi*2]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + cpu.edi * 2);
    // 004b6ea2  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004b6ea5  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004b6ea8  0fafd1                 -imul edx, ecx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004b6eab  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b6eae  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004b6eb1  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b6eb3  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 004b6eb6  884501                 -mov byte ptr [ebp + 1], al
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004b6eb9  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b6ebb  8a444602               -mov al, byte ptr [esi + eax*2 + 2]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(2) /* 0x2 */ + cpu.eax * 2);
    // 004b6ebf  88430e                 -mov byte ptr [ebx + 0xe], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(14) /* 0xe */) = cpu.al;
    // 004b6ec2  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b6ec4  8a444603               -mov al, byte ptr [esi + eax*2 + 3]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(3) /* 0x3 */ + cpu.eax * 2);
    // 004b6ec8  88430f                 -mov byte ptr [ebx + 0xf], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(15) /* 0xf */) = cpu.al;
    // 004b6ecb  8b6b04                 -mov ebp, dword ptr [ebx + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b6ece  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b6ed1  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b6ed3  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b6ed5  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b6ed8  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004b6eda  896b04                 -mov dword ptr [ebx + 4], ebp
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 004b6edd  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b6ee0  66c743060000           -mov word ptr [ebx + 6], 0
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 004b6ee6  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b6ee8  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b6eeb  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 004b6eed  39c8                   +cmp eax, ecx
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
    // 004b6eef  7234                   -jb 0x4b6f25
    if (cpu.flags.cf)
    {
        goto L_0x004b6f25;
    }
    // 004b6ef1  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b6ef3  c6431001               -mov byte ptr [ebx + 0x10], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */) = 1 /*0x1*/;
    // 004b6ef7  8a0446                 -mov al, byte ptr [esi + eax*2]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 2);
    // 004b6efa  88430c                 -mov byte ptr [ebx + 0xc], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.al;
    // 004b6efd  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b6eff  8a444601               -mov al, byte ptr [esi + eax*2 + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.eax * 2);
    // 004b6f03  88430d                 -mov byte ptr [ebx + 0xd], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(13) /* 0xd */) = cpu.al;
    // 004b6f06  c6431101               -mov byte ptr [ebx + 0x11], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(17) /* 0x11 */) = 1 /*0x1*/;
    // 004b6f0a  83c404                 +add esp, 4
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
    // 004b6f0d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6f0e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6f0f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6f10  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6f11  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b6f12:
    // 004b6f12  8d72ff                 -lea esi, [edx - 1]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 004b6f15  8a500f                 -mov dl, byte ptr [eax + 0xf]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(15) /* 0xf */);
    // 004b6f18  8816                   -mov byte ptr [esi], dl
    app->getMemory<x86::reg8>(cpu.esi) = cpu.dl;
    // 004b6f1a  4e                     +dec esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004b6f1b  8a400e                 -mov al, byte ptr [eax + 0xe]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(14) /* 0xe */);
    // 004b6f1e  8806                   -mov byte ptr [esi], al
    app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
    // 004b6f20  e9ddfeffff             -jmp 0x4b6e02
    goto L_0x004b6e02;
L_0x004b6f25:
    // 004b6f25  c6431000               -mov byte ptr [ebx + 0x10], 0
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 004b6f29  c6431101               -mov byte ptr [ebx + 0x11], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(17) /* 0x11 */) = 1 /*0x1*/;
    // 004b6f2d  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b6f30  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6f31  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6f32  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6f33  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6f34  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4b6f38(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b6f38);
    // 004b6f38  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b6f39  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b6f3a  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b6f3e  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b6f42  8b5908                 -mov ebx, dword ptr [ecx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004b6f45  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b6f47  81fb00000100           +cmp ebx, 0x10000
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
    // 004b6f4d  732c                   -jae 0x4b6f7b
    if (!cpu.flags.cf)
    {
        goto L_0x004b6f7b;
    }
    // 004b6f4f  81fa00000100           +cmp edx, 0x10000
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
    // 004b6f55  7324                   -jae 0x4b6f7b
    if (!cpu.flags.cf)
    {
        goto L_0x004b6f7b;
    }
L_0x004b6f57:
    // 004b6f57  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004b6f5a  81fa00000100           +cmp edx, 0x10000
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
    // 004b6f60  724b                   -jb 0x4b6fad
    if (cpu.flags.cf)
    {
        goto L_0x004b6fad;
    }
    // 004b6f62  7660                   -jbe 0x4b6fc4
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b6fc4;
    }
    // 004b6f64  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004b6f67  c702306c4b00           -mov dword ptr [edx], 0x4b6c30
    app->getMemory<x86::reg32>(cpu.edx) = 4942896 /*0x4b6c30*/;
    // 004b6f6d  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004b6f70  c700ac6c4b00           -mov dword ptr [eax], 0x4b6cac
    app->getMemory<x86::reg32>(cpu.eax) = 4943020 /*0x4b6cac*/;
    // 004b6f76  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b6f78  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6f79  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6f7a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b6f7b:
    // 004b6f7b  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004b6f7e  39f2                   +cmp edx, esi
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
    // 004b6f80  74d5                   -je 0x4b6f57
    if (cpu.flags.zf)
    {
        goto L_0x004b6f57;
    }
    // 004b6f82  81fe00000100           +cmp esi, 0x10000
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
    // 004b6f88  7608                   -jbe 0x4b6f92
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b6f92;
    }
    // 004b6f8a  81fa00000100           +cmp edx, 0x10000
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
    // 004b6f90  77c5                   -ja 0x4b6f57
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004b6f57;
    }
L_0x004b6f92:
    // 004b6f92  c6401000               -mov byte ptr [eax + 0x10], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 004b6f96  c6401100               -mov byte ptr [eax + 0x11], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(17) /* 0x11 */) = 0 /*0x0*/;
    // 004b6f9a  c6401200               -mov byte ptr [eax + 0x12], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(18) /* 0x12 */) = 0 /*0x0*/;
    // 004b6f9e  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004b6fa5  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004b6fab  ebaa                   -jmp 0x4b6f57
    goto L_0x004b6f57;
L_0x004b6fad:
    // 004b6fad  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004b6fb0  c702806c4b00           -mov dword ptr [edx], 0x4b6c80
    app->getMemory<x86::reg32>(cpu.edx) = 4942976 /*0x4b6c80*/;
    // 004b6fb6  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004b6fb9  c700e06d4b00           -mov dword ptr [eax], 0x4b6de0
    app->getMemory<x86::reg32>(cpu.eax) = 4943328 /*0x4b6de0*/;
    // 004b6fbf  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b6fc1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6fc2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6fc3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b6fc4:
    // 004b6fc4  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004b6fc7  c702786c4b00           -mov dword ptr [edx], 0x4b6c78
    app->getMemory<x86::reg32>(cpu.edx) = 4942968 /*0x4b6c78*/;
    // 004b6fcd  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004b6fd0  c700d46d4b00           -mov dword ptr [eax], 0x4b6dd4
    app->getMemory<x86::reg32>(cpu.eax) = 4943316 /*0x4b6dd4*/;
    // 004b6fd6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b6fd8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6fd9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6fda  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4b6fdc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b6fdc);
    // 004b6fdc  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b6fe0  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004b6fe6  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004b6fed  c6401000               -mov byte ptr [eax + 0x10], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 004b6ff1  c6401100               -mov byte ptr [eax + 0x11], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(17) /* 0x11 */) = 0 /*0x0*/;
    // 004b6ff5  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b6ff9  c6401200               -mov byte ptr [eax + 0x12], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(18) /* 0x12 */) = 0 /*0x0*/;
    // 004b6ffd  895014                 -mov dword ptr [eax + 0x14], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004b7000  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b7004  895018                 -mov dword ptr [eax + 0x18], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004b7007  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b700b  89501c                 -mov dword ptr [eax + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004b700e  8b4014                 -mov eax, dword ptr [eax + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004b7011  c700386f4b00           -mov dword ptr [eax], 0x4b6f38
    app->getMemory<x86::reg32>(cpu.eax) = 4943672 /*0x4b6f38*/;
    // 004b7017  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b7019  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4b7020(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b7020);
    // 004b7020  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b7021  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b7022  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b7023  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b7027  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004b702b  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004b702e  48                     -dec eax
    (cpu.eax)--;
    // 004b702f  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004b7032  034204                 -add eax, dword ptr [edx + 4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 004b7035  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b7038  8b5a0f                 -mov ebx, dword ptr [edx + 0xf]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(15) /* 0xf */);
    // 004b703b  40                     -inc eax
    (cpu.eax)++;
    // 004b703c  c1fb18                 -sar ebx, 0x18
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (24 /*0x18*/ % 32));
    // 004b703f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b7041  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b7043  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 004b7046  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b7048  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 004b704a  7501                   -jne 0x4b704d
    if (!cpu.flags.zf)
    {
        goto L_0x004b704d;
    }
    // 004b704c  40                     -inc eax
    (cpu.eax)++;
L_0x004b704d:
    // 004b704d  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004b7051  8b5108                 -mov edx, dword ptr [ecx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004b7054  0fafd7                 -imul edx, edi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 004b7057  035104                 -add edx, dword ptr [ecx + 4]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
    // 004b705a  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004b705d  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004b705f  885112                 -mov byte ptr [ecx + 0x12], dl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(18) /* 0x12 */) = cpu.dl;
    // 004b7062  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7063  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7064  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7065  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4b7068(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b7068);
    // 004b7068  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b706c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4b7070(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b7070);
    // 004b7070  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b7071  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b7075  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b7079  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004b707c  48                     -dec eax
    (cpu.eax)--;
    // 004b707d  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004b7080  034204                 -add eax, dword ptr [edx + 4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 004b7083  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b7085  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b7088  8a5a11                 -mov bl, byte ptr [edx + 0x11]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(17) /* 0x11 */);
    // 004b708b  40                     -inc eax
    (cpu.eax)++;
    // 004b708c  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 004b708e  7501                   -jne 0x4b7091
    if (!cpu.flags.zf)
    {
        goto L_0x004b7091;
    }
    // 004b7090  40                     -inc eax
    (cpu.eax)++;
L_0x004b7091:
    // 004b7091  8b510d                 -mov edx, dword ptr [ecx + 0xd]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(13) /* 0xd */);
    // 004b7094  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004b7097  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b7099  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b709a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4b709c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b709c);
    // 004b709c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b709d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b709e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b709f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b70a0  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b70a3  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004b70a7  8b7c241c               -mov edi, dword ptr [esp + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004b70ab  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004b70af  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b70b1  8a4811                 -mov cl, byte ptr [eax + 0x11]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(17) /* 0x11 */);
    // 004b70b4  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004b70b6  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 004b70b8  0f8581000000           -jne 0x4b713f
    if (!cpu.flags.zf)
    {
        goto L_0x004b713f;
    }
L_0x004b70be:
    // 004b70be  8b6c2424               -mov ebp, dword ptr [esp + 0x24]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004b70c2  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp);
    // 004b70c5  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004b70c6  0f8582000000           -jne 0x4b714e
    if (!cpu.flags.zf)
    {
        goto L_0x004b714e;
    }
L_0x004b70cc:
    // 004b70cc  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b70ce  baffff0000             -mov edx, 0xffff
    cpu.edx = 65535 /*0xffff*/;
    // 004b70d3  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b70d6  0fbf0446               -movsx eax, word ptr [esi + eax*2]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.esi + cpu.eax * 2)));
    // 004b70da  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b70dc  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004b70df  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b70e2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b70e4  8d043f                 -lea eax, [edi + edi]
    cpu.eax = x86::reg32(cpu.edi + cpu.edi * 1);
    // 004b70e7  66891428               -mov word ptr [eax + ebp], dx
    app->getMemory<x86::reg16>(cpu.eax + cpu.ebp * 1) = cpu.dx;
    // 004b70eb  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b70ed  8b1456                 -mov edx, dword ptr [esi + edx*2]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + cpu.edx * 2);
    // 004b70f0  8b7b04                 -mov edi, dword ptr [ebx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b70f3  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004b70f6  0faffa                 -imul edi, edx
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004b70f9  c1ef10                 -shr edi, 0x10
    cpu.edi >>= 16 /*0x10*/ % 32;
    // 004b70fc  0fbf1428               -movsx edx, word ptr [eax + ebp]
    cpu.edx = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.eax + cpu.ebp * 1)));
    // 004b7100  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004b7102  66891428               -mov word ptr [eax + ebp], dx
    app->getMemory<x86::reg16>(cpu.eax + cpu.ebp * 1) = cpu.dx;
    // 004b7106  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b7108  668b444602             -mov ax, word ptr [esi + eax*2 + 2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(2) /* 0x2 */ + cpu.eax * 2);
    // 004b710d  6689430e               -mov word ptr [ebx + 0xe], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(14) /* 0xe */) = cpu.ax;
    // 004b7111  8b6b04                 -mov ebp, dword ptr [ebx + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b7114  036b08                 -add ebp, dword ptr [ebx + 8]
    (cpu.ebp) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */)));
    // 004b7117  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b7119  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004b711b  896b04                 -mov dword ptr [ebx + 4], ebp
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 004b711e  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b7121  66c743060000           -mov word ptr [ebx + 6], 0
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 004b7127  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b7129  8b430f                 -mov eax, dword ptr [ebx + 0xf]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(15) /* 0xf */);
    // 004b712c  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 004b712e  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004b7131  c6431101               -mov byte ptr [ebx + 0x11], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(17) /* 0x11 */) = 1 /*0x1*/;
    // 004b7135  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004b7137  83c404                 +add esp, 4
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
    // 004b713a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b713b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b713c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b713d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b713e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b713f:
    // 004b713f  8d72fe                 -lea esi, [edx - 2]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(-2) /* -0x2 */);
    // 004b7142  668b400e               -mov ax, word ptr [eax + 0xe]
    cpu.ax = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(14) /* 0xe */);
    // 004b7146  668906                 -mov word ptr [esi], ax
    app->getMemory<x86::reg16>(cpu.esi) = cpu.ax;
    // 004b7149  e970ffffff             -jmp 0x4b70be
    goto L_0x004b70be;
L_0x004b714e:
    // 004b714e  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b7151  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b7154  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b7157  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004b715a  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004b715d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b715e  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004b7161  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b7162  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b7166  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b716a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b716b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b716c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b716d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b716e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b716f  e8e04e0000             -call 0x4bc054
    cpu.esp -= 4;
    sub_4bc054(app, cpu);
    if (cpu.terminate) return;
    // 004b7174  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004b7177  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004b717a  c1e810                 +shr eax, 0x10
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
    // 004b717d  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004b7180  e947ffffff             -jmp 0x4b70cc
    goto L_0x004b70cc;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4b7188(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b7188);
    // 004b7188  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b718c  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b7190  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004b7192  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4b7194(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b7194);
    // 004b7194  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b7195  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b7196  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b7197  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b7198  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b719b  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004b719f  8b7c241c               -mov edi, dword ptr [esp + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004b71a3  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004b71a7  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b71a9  8a4811                 -mov cl, byte ptr [eax + 0x11]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(17) /* 0x11 */);
    // 004b71ac  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004b71ae  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 004b71b0  0f85d5000000           -jne 0x4b728b
    if (!cpu.flags.zf)
    {
        goto L_0x004b728b;
    }
L_0x004b71b6:
    // 004b71b6  807b1000               +cmp byte ptr [ebx + 0x10], 0
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
    // 004b71ba  740a                   -je 0x4b71c6
    if (cpu.flags.zf)
    {
        goto L_0x004b71c6;
    }
    // 004b71bc  83ee02                 +sub esi, 2
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
    // 004b71bf  668b430c               -mov ax, word ptr [ebx + 0xc]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004b71c3  668906                 -mov word ptr [esi], ax
    app->getMemory<x86::reg16>(cpu.esi) = cpu.ax;
L_0x004b71c6:
    // 004b71c6  8b6c2424               -mov ebp, dword ptr [esp + 0x24]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004b71ca  c70300000000           -mov dword ptr [ebx], 0
    app->getMemory<x86::reg32>(cpu.ebx) = 0 /*0x0*/;
    // 004b71d0  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp);
    // 004b71d3  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004b71d4  7432                   -je 0x4b7208
    if (cpu.flags.zf)
    {
        goto L_0x004b7208;
    }
    // 004b71d6  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b71d9  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b71dc  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b71df  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004b71e2  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004b71e5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b71e6  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004b71e9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b71ea  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b71ee  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b71f2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b71f3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b71f4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b71f5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b71f6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b71f7  e8584e0000             -call 0x4bc054
    cpu.esp -= 4;
    sub_4bc054(app, cpu);
    if (cpu.terminate) return;
    // 004b71fc  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004b71ff  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004b7202  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b7205  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x004b7208:
    // 004b7208  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b720a  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b720d  0fbf1446               -movsx edx, word ptr [esi + eax*2]
    cpu.edx = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.esi + cpu.eax * 2)));
    // 004b7211  b8ffff0000             -mov eax, 0xffff
    cpu.eax = 65535 /*0xffff*/;
    // 004b7216  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b7218  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004b721b  8d143f                 -lea edx, [edi + edi]
    cpu.edx = x86::reg32(cpu.edi + cpu.edi * 1);
    // 004b721e  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b7221  6689042a               -mov word ptr [edx + ebp], ax
    app->getMemory<x86::reg16>(cpu.edx + cpu.ebp * 1) = cpu.ax;
    // 004b7225  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b7227  8b0446                 -mov eax, dword ptr [esi + eax*2]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + cpu.eax * 2);
    // 004b722a  8b7b04                 -mov edi, dword ptr [ebx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b722d  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004b7230  0faff8                 -imul edi, eax
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 004b7233  c1ef10                 -shr edi, 0x10
    cpu.edi >>= 16 /*0x10*/ % 32;
    // 004b7236  0fbf042a               -movsx eax, word ptr [edx + ebp]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.edx + cpu.ebp * 1)));
    // 004b723a  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 004b723c  6689042a               -mov word ptr [edx + ebp], ax
    app->getMemory<x86::reg16>(cpu.edx + cpu.ebp * 1) = cpu.ax;
    // 004b7240  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b7242  668b444602             -mov ax, word ptr [esi + eax*2 + 2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(2) /* 0x2 */ + cpu.eax * 2);
    // 004b7247  6689430e               -mov word ptr [ebx + 0xe], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(14) /* 0xe */) = cpu.ax;
    // 004b724b  8b6b04                 -mov ebp, dword ptr [ebx + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b724e  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b7251  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b7253  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b7255  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b7258  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004b725a  896b04                 -mov dword ptr [ebx + 4], ebp
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 004b725d  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b7260  66c743060000           -mov word ptr [ebx + 6], 0
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 004b7266  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b7268  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b726b  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 004b726d  39c8                   +cmp eax, ecx
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
    // 004b726f  7229                   -jb 0x4b729a
    if (cpu.flags.cf)
    {
        goto L_0x004b729a;
    }
    // 004b7271  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b7273  c6431001               -mov byte ptr [ebx + 0x10], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */) = 1 /*0x1*/;
    // 004b7277  668b0446               -mov ax, word ptr [esi + eax*2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.eax * 2);
    // 004b727b  6689430c               -mov word ptr [ebx + 0xc], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.ax;
    // 004b727f  c6431101               -mov byte ptr [ebx + 0x11], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(17) /* 0x11 */) = 1 /*0x1*/;
    // 004b7283  83c404                 +add esp, 4
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
    // 004b7286  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7287  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7288  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7289  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b728a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b728b:
    // 004b728b  8d72fe                 -lea esi, [edx - 2]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(-2) /* -0x2 */);
    // 004b728e  668b400e               -mov ax, word ptr [eax + 0xe]
    cpu.ax = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(14) /* 0xe */);
    // 004b7292  668906                 -mov word ptr [esi], ax
    app->getMemory<x86::reg16>(cpu.esi) = cpu.ax;
    // 004b7295  e91cffffff             -jmp 0x4b71b6
    goto L_0x004b71b6;
L_0x004b729a:
    // 004b729a  c6431000               -mov byte ptr [ebx + 0x10], 0
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 004b729e  c6431101               -mov byte ptr [ebx + 0x11], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(17) /* 0x11 */) = 1 /*0x1*/;
    // 004b72a2  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b72a5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b72a6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b72a7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b72a8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b72a9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4b72ac(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b72ac);
    // 004b72ac  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b72ad  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b72ae  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b72b2  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b72b6  8b5908                 -mov ebx, dword ptr [ecx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004b72b9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b72bb  81fb00000100           +cmp ebx, 0x10000
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
    // 004b72c1  732c                   -jae 0x4b72ef
    if (!cpu.flags.cf)
    {
        goto L_0x004b72ef;
    }
    // 004b72c3  81fa00000100           +cmp edx, 0x10000
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
    // 004b72c9  7324                   -jae 0x4b72ef
    if (!cpu.flags.cf)
    {
        goto L_0x004b72ef;
    }
L_0x004b72cb:
    // 004b72cb  895008                 -mov dword ptr [eax + 8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004b72ce  81fa00000100           +cmp edx, 0x10000
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
    // 004b72d4  724b                   -jb 0x4b7321
    if (cpu.flags.cf)
    {
        goto L_0x004b7321;
    }
    // 004b72d6  7660                   -jbe 0x4b7338
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b7338;
    }
    // 004b72d8  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004b72db  c70220704b00           -mov dword ptr [edx], 0x4b7020
    app->getMemory<x86::reg32>(cpu.edx) = 4943904 /*0x4b7020*/;
    // 004b72e1  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004b72e4  c7009c704b00           -mov dword ptr [eax], 0x4b709c
    app->getMemory<x86::reg32>(cpu.eax) = 4944028 /*0x4b709c*/;
    // 004b72ea  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b72ec  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b72ed  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b72ee  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b72ef:
    // 004b72ef  8b7008                 -mov esi, dword ptr [eax + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004b72f2  39f2                   +cmp edx, esi
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
    // 004b72f4  74d5                   -je 0x4b72cb
    if (cpu.flags.zf)
    {
        goto L_0x004b72cb;
    }
    // 004b72f6  81fe00000100           +cmp esi, 0x10000
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
    // 004b72fc  7608                   -jbe 0x4b7306
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b7306;
    }
    // 004b72fe  81fa00000100           +cmp edx, 0x10000
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
    // 004b7304  77c5                   -ja 0x4b72cb
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004b72cb;
    }
L_0x004b7306:
    // 004b7306  c6401000               -mov byte ptr [eax + 0x10], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 004b730a  c6401100               -mov byte ptr [eax + 0x11], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(17) /* 0x11 */) = 0 /*0x0*/;
    // 004b730e  c6401200               -mov byte ptr [eax + 0x12], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(18) /* 0x12 */) = 0 /*0x0*/;
    // 004b7312  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004b7319  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004b731f  ebaa                   -jmp 0x4b72cb
    goto L_0x004b72cb;
L_0x004b7321:
    // 004b7321  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004b7324  c70270704b00           -mov dword ptr [edx], 0x4b7070
    app->getMemory<x86::reg32>(cpu.edx) = 4943984 /*0x4b7070*/;
    // 004b732a  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004b732d  c70094714b00           -mov dword ptr [eax], 0x4b7194
    app->getMemory<x86::reg32>(cpu.eax) = 4944276 /*0x4b7194*/;
    // 004b7333  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b7335  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7336  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7337  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b7338:
    // 004b7338  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004b733b  c70268704b00           -mov dword ptr [edx], 0x4b7068
    app->getMemory<x86::reg32>(cpu.edx) = 4943976 /*0x4b7068*/;
    // 004b7341  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004b7344  c70088714b00           -mov dword ptr [eax], 0x4b7188
    app->getMemory<x86::reg32>(cpu.eax) = 4944264 /*0x4b7188*/;
    // 004b734a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b734c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b734d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b734e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4b7350(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b7350);
    // 004b7350  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b7354  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004b735a  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004b7361  c6401000               -mov byte ptr [eax + 0x10], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 004b7365  66c7400e0000           -mov word ptr [eax + 0xe], 0
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(14) /* 0xe */) = 0 /*0x0*/;
    // 004b736b  c6401100               -mov byte ptr [eax + 0x11], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(17) /* 0x11 */) = 0 /*0x0*/;
    // 004b736f  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b7373  c6401201               -mov byte ptr [eax + 0x12], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(18) /* 0x12 */) = 1 /*0x1*/;
    // 004b7377  895014                 -mov dword ptr [eax + 0x14], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004b737a  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b737e  895018                 -mov dword ptr [eax + 0x18], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004b7381  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b7385  89501c                 -mov dword ptr [eax + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004b7388  8b4014                 -mov eax, dword ptr [eax + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004b738b  c700ac724b00           -mov dword ptr [eax], 0x4b72ac
    app->getMemory<x86::reg32>(cpu.eax) = 4944556 /*0x4b72ac*/;
    // 004b7391  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b7393  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4b73a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b73a0);
    // 004b73a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b73a1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b73a2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b73a3  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b73a7  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004b73ab  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004b73ae  48                     -dec eax
    (cpu.eax)--;
    // 004b73af  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004b73b2  034204                 -add eax, dword ptr [edx + 4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 004b73b5  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b73b8  8b5a13                 -mov ebx, dword ptr [edx + 0x13]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(19) /* 0x13 */);
    // 004b73bb  40                     -inc eax
    (cpu.eax)++;
    // 004b73bc  c1fb18                 -sar ebx, 0x18
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (24 /*0x18*/ % 32));
    // 004b73bf  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b73c1  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b73c3  8a5a15                 -mov bl, byte ptr [edx + 0x15]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(21) /* 0x15 */);
    // 004b73c6  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b73c8  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 004b73ca  7501                   -jne 0x4b73cd
    if (!cpu.flags.zf)
    {
        goto L_0x004b73cd;
    }
    // 004b73cc  40                     -inc eax
    (cpu.eax)++;
L_0x004b73cd:
    // 004b73cd  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004b73d1  8b5108                 -mov edx, dword ptr [ecx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004b73d4  0fafd7                 -imul edx, edi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 004b73d7  035104                 -add edx, dword ptr [ecx + 4]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */)));
    // 004b73da  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004b73dd  29f2                   -sub edx, esi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004b73df  885116                 -mov byte ptr [ecx + 0x16], dl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(22) /* 0x16 */) = cpu.dl;
    // 004b73e2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b73e3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b73e4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b73e5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4b73e8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b73e8);
    // 004b73e8  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b73ec  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4b73f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b73f0);
    // 004b73f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b73f1  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b73f5  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b73f9  8b5a08                 -mov ebx, dword ptr [edx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004b73fc  48                     -dec eax
    (cpu.eax)--;
    // 004b73fd  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004b7400  034204                 -add eax, dword ptr [edx + 4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 004b7403  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b7405  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b7408  8a5a15                 -mov bl, byte ptr [edx + 0x15]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(21) /* 0x15 */);
    // 004b740b  40                     -inc eax
    (cpu.eax)++;
    // 004b740c  84db                   +test bl, bl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & cpu.bl));
    // 004b740e  7501                   -jne 0x4b7411
    if (!cpu.flags.zf)
    {
        goto L_0x004b7411;
    }
    // 004b7410  40                     -inc eax
    (cpu.eax)++;
L_0x004b7411:
    // 004b7411  8b5111                 -mov edx, dword ptr [ecx + 0x11]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(17) /* 0x11 */);
    // 004b7414  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004b7417  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b7419  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b741a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4b741c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b741c);
    // 004b741c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b741d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b741e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b741f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b7420  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b7423  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004b7427  8b7c241c               -mov edi, dword ptr [esp + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004b742b  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004b742f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b7431  8a4815                 -mov cl, byte ptr [eax + 0x15]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(21) /* 0x15 */);
    // 004b7434  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004b7436  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 004b7438  0f85d1000000           -jne 0x4b750f
    if (!cpu.flags.zf)
    {
        goto L_0x004b750f;
    }
L_0x004b743e:
    // 004b743e  8b6c2424               -mov ebp, dword ptr [esp + 0x24]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004b7442  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp);
    // 004b7445  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004b7446  0f85dc000000           -jne 0x4b7528
    if (!cpu.flags.zf)
    {
        goto L_0x004b7528;
    }
L_0x004b744c:
    // 004b744c  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b744e  baffff0000             -mov edx, 0xffff
    cpu.edx = 65535 /*0xffff*/;
    // 004b7453  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b7456  0fbf0486               -movsx eax, word ptr [esi + eax*4]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.esi + cpu.eax * 4)));
    // 004b745a  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b745c  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004b745f  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b7462  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b7464  8d04bd00000000         -lea eax, [edi*4]
    cpu.eax = x86::reg32(cpu.edi * 4);
    // 004b746b  66891428               -mov word ptr [eax + ebp], dx
    app->getMemory<x86::reg16>(cpu.eax + cpu.ebp * 1) = cpu.dx;
    // 004b746f  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b7471  8b549602               -mov edx, dword ptr [esi + edx*4 + 2]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(2) /* 0x2 */ + cpu.edx * 4);
    // 004b7475  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b7477  8b7b04                 -mov edi, dword ptr [ebx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b747a  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004b747d  0fafcf                 -imul ecx, edi
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ecx)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 004b7480  0fbf1428               -movsx edx, word ptr [eax + ebp]
    cpu.edx = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.eax + cpu.ebp * 1)));
    // 004b7484  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004b7487  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004b7489  66891428               -mov word ptr [eax + ebp], dx
    app->getMemory<x86::reg16>(cpu.eax + cpu.ebp * 1) = cpu.dx;
    // 004b748d  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b748f  b9ffff0000             -mov ecx, 0xffff
    cpu.ecx = 65535 /*0xffff*/;
    // 004b7494  8b7b04                 -mov edi, dword ptr [ebx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b7497  8b1496                 -mov edx, dword ptr [esi + edx*4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + cpu.edx * 4);
    // 004b749a  29f9                   -sub ecx, edi
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004b749c  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004b749f  0fafd1                 -imul edx, ecx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004b74a2  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004b74a5  6689542802             -mov word ptr [eax + ebp + 2], dx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */ + cpu.ebp * 1) = cpu.dx;
    // 004b74aa  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b74ac  8b549604               -mov edx, dword ptr [esi + edx*4 + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.edx * 4);
    // 004b74b0  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004b74b2  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b74b5  c1ff10                 -sar edi, 0x10
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (16 /*0x10*/ % 32));
    // 004b74b8  0faff9                 -imul edi, ecx
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 004b74bb  8b1428                 -mov edx, dword ptr [eax + ebp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + cpu.ebp * 1);
    // 004b74be  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004b74c1  c1ef10                 -shr edi, 0x10
    cpu.edi >>= 16 /*0x10*/ % 32;
    // 004b74c4  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004b74c6  6689542802             -mov word ptr [eax + ebp + 2], dx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */ + cpu.ebp * 1) = cpu.dx;
    // 004b74cb  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b74cd  668b448604             -mov ax, word ptr [esi + eax*4 + 4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.eax * 4);
    // 004b74d2  66894310               -mov word ptr [ebx + 0x10], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.ax;
    // 004b74d6  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b74d8  668b448606             -mov ax, word ptr [esi + eax*4 + 6]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */ + cpu.eax * 4);
    // 004b74dd  66894312               -mov word ptr [ebx + 0x12], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(18) /* 0x12 */) = cpu.ax;
    // 004b74e1  8b7304                 -mov esi, dword ptr [ebx + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b74e4  037308                 -add esi, dword ptr [ebx + 8]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */)));
    // 004b74e7  8b3b                   -mov edi, dword ptr [ebx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b74e9  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b74eb  897304                 -mov dword ptr [ebx + 4], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 004b74ee  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b74f1  66c743060000           -mov word ptr [ebx + 6], 0
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 004b74f7  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b74f9  8b4313                 -mov eax, dword ptr [ebx + 0x13]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(19) /* 0x13 */);
    // 004b74fc  893b                   -mov dword ptr [ebx], edi
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edi;
    // 004b74fe  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 004b7501  c6431501               -mov byte ptr [ebx + 0x15], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(21) /* 0x15 */) = 1 /*0x1*/;
    // 004b7505  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004b7507  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b750a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b750b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b750c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b750d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b750e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b750f:
    // 004b750f  8d72fe                 -lea esi, [edx - 2]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(-2) /* -0x2 */);
    // 004b7512  668b5012               -mov dx, word ptr [eax + 0x12]
    cpu.dx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(18) /* 0x12 */);
    // 004b7516  668916                 -mov word ptr [esi], dx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.dx;
    // 004b7519  83ee02                 +sub esi, 2
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
    // 004b751c  668b4010               -mov ax, word ptr [eax + 0x10]
    cpu.ax = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004b7520  668906                 -mov word ptr [esi], ax
    app->getMemory<x86::reg16>(cpu.esi) = cpu.ax;
    // 004b7523  e916ffffff             -jmp 0x4b743e
    goto L_0x004b743e;
L_0x004b7528:
    // 004b7528  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b752b  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b752e  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b7531  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004b7534  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004b7537  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b7538  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004b753b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b753c  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b7540  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b7544  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b7545  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b7546  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b7547  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b7548  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b7549  e8864b0000             -call 0x4bc0d4
    cpu.esp -= 4;
    sub_4bc0d4(app, cpu);
    if (cpu.terminate) return;
    // 004b754e  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004b7551  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004b7554  c1e810                 +shr eax, 0x10
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
    // 004b7557  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004b755a  e9edfeffff             -jmp 0x4b744c
    goto L_0x004b744c;
}

/* align: skip 0x90 */
void Application::sub_4b7560(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b7560);
    // 004b7560  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004b7564  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b7568  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004b756a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4b756c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b756c);
    // 004b756c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b756d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b756e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b756f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b7570  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b7573  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004b7577  8b7c241c               -mov edi, dword ptr [esp + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004b757b  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004b757f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b7581  8a4815                 -mov cl, byte ptr [eax + 0x15]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(21) /* 0x15 */);
    // 004b7584  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004b7586  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 004b7588  0f8538010000           -jne 0x4b76c6
    if (!cpu.flags.zf)
    {
        goto L_0x004b76c6;
    }
L_0x004b758e:
    // 004b758e  807b1400               +cmp byte ptr [ebx + 0x14], 0
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
    // 004b7592  7414                   -je 0x4b75a8
    if (cpu.flags.zf)
    {
        goto L_0x004b75a8;
    }
    // 004b7594  83ee02                 -sub esi, 2
    (cpu.esi) -= x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004b7597  668b430e               -mov ax, word ptr [ebx + 0xe]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(14) /* 0xe */);
    // 004b759b  668906                 -mov word ptr [esi], ax
    app->getMemory<x86::reg16>(cpu.esi) = cpu.ax;
    // 004b759e  83ee02                 +sub esi, 2
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
    // 004b75a1  668b430c               -mov ax, word ptr [ebx + 0xc]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004b75a5  668906                 -mov word ptr [esi], ax
    app->getMemory<x86::reg16>(cpu.esi) = cpu.ax;
L_0x004b75a8:
    // 004b75a8  8b6c2424               -mov ebp, dword ptr [esp + 0x24]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004b75ac  c70300000000           -mov dword ptr [ebx], 0
    app->getMemory<x86::reg32>(cpu.ebx) = 0 /*0x0*/;
    // 004b75b2  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp);
    // 004b75b5  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004b75b6  7432                   -je 0x4b75ea
    if (cpu.flags.zf)
    {
        goto L_0x004b75ea;
    }
    // 004b75b8  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b75bb  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b75be  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b75c1  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004b75c4  c1e910                 -shr ecx, 0x10
    cpu.ecx >>= 16 /*0x10*/ % 32;
    // 004b75c7  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b75c8  c1e010                 -shl eax, 0x10
    cpu.eax <<= 16 /*0x10*/ % 32;
    // 004b75cb  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b75cc  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004b75d0  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b75d4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b75d5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b75d6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b75d7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b75d8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b75d9  e8f64a0000             -call 0x4bc0d4
    cpu.esp -= 4;
    sub_4bc0d4(app, cpu);
    if (cpu.terminate) return;
    // 004b75de  83c41c                 -add esp, 0x1c
    (cpu.esp) += x86::reg32(x86::sreg32(28 /*0x1c*/));
    // 004b75e1  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004b75e4  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b75e7  894304                 -mov dword ptr [ebx + 4], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x004b75ea:
    // 004b75ea  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b75ec  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b75ef  0fbf1486               -movsx edx, word ptr [esi + eax*4]
    cpu.edx = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.esi + cpu.eax * 4)));
    // 004b75f3  b8ffff0000             -mov eax, 0xffff
    cpu.eax = 65535 /*0xffff*/;
    // 004b75f8  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b75fa  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004b75fd  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b7600  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b7602  8d04bd00000000         -lea eax, [edi*4]
    cpu.eax = x86::reg32(cpu.edi * 4);
    // 004b7609  66891428               -mov word ptr [eax + ebp], dx
    app->getMemory<x86::reg16>(cpu.eax + cpu.ebp * 1) = cpu.dx;
    // 004b760d  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b760f  8b549602               -mov edx, dword ptr [esi + edx*4 + 2]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(2) /* 0x2 */ + cpu.edx * 4);
    // 004b7613  8b7b04                 -mov edi, dword ptr [ebx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b7616  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004b7619  0fafd7                 -imul edx, edi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 004b761c  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004b761f  0fbf3c28               -movsx edi, word ptr [eax + ebp]
    cpu.edi = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.eax + cpu.ebp * 1)));
    // 004b7623  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b7625  66893c28               -mov word ptr [eax + ebp], di
    app->getMemory<x86::reg16>(cpu.eax + cpu.ebp * 1) = cpu.di;
    // 004b7629  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b762b  8b4b04                 -mov ecx, dword ptr [ebx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b762e  8b3c96                 -mov edi, dword ptr [esi + edx*4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + cpu.edx * 4);
    // 004b7631  baffff0000             -mov edx, 0xffff
    cpu.edx = 65535 /*0xffff*/;
    // 004b7636  c1ff10                 -sar edi, 0x10
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (16 /*0x10*/ % 32));
    // 004b7639  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b763b  0faffa                 -imul edi, edx
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004b763e  c1ef10                 -shr edi, 0x10
    cpu.edi >>= 16 /*0x10*/ % 32;
    // 004b7641  66897c2802             -mov word ptr [eax + ebp + 2], di
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */ + cpu.ebp * 1) = cpu.di;
    // 004b7646  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b7648  8b549604               -mov edx, dword ptr [esi + edx*4 + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.edx * 4);
    // 004b764c  8b7b04                 -mov edi, dword ptr [ebx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b764f  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004b7652  0fafd7                 -imul edx, edi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 004b7655  8b3c28                 -mov edi, dword ptr [eax + ebp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + cpu.ebp * 1);
    // 004b7658  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 004b765b  c1ff10                 -sar edi, 0x10
    cpu.edi = x86::reg32(x86::sreg32(cpu.edi) >> (16 /*0x10*/ % 32));
    // 004b765e  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b7660  66897c2802             -mov word ptr [eax + ebp + 2], di
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(2) /* 0x2 */ + cpu.ebp * 1) = cpu.di;
    // 004b7665  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b7667  668b448604             -mov ax, word ptr [esi + eax*4 + 4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.eax * 4);
    // 004b766c  66894310               -mov word ptr [ebx + 0x10], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(16) /* 0x10 */) = cpu.ax;
    // 004b7670  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b7672  668b448606             -mov ax, word ptr [esi + eax*4 + 6]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */ + cpu.eax * 4);
    // 004b7677  66894312               -mov word ptr [ebx + 0x12], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(18) /* 0x12 */) = cpu.ax;
    // 004b767b  8b6b04                 -mov ebp, dword ptr [ebx + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b767e  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b7681  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b7683  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b7685  8b4b08                 -mov ecx, dword ptr [ebx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b7688  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004b768a  896b04                 -mov dword ptr [ebx + 4], ebp
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 004b768d  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b7690  66c743060000           -mov word ptr [ebx + 6], 0
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(6) /* 0x6 */) = 0 /*0x0*/;
    // 004b7696  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b7698  8b4304                 -mov eax, dword ptr [ebx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b769b  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 004b769d  39c8                   +cmp eax, ecx
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
    // 004b769f  723e                   -jb 0x4b76df
    if (cpu.flags.cf)
    {
        goto L_0x004b76df;
    }
    // 004b76a1  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b76a3  c6431401               -mov byte ptr [ebx + 0x14], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(20) /* 0x14 */) = 1 /*0x1*/;
    // 004b76a7  668b0486               -mov ax, word ptr [esi + eax*4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + cpu.eax * 4);
    // 004b76ab  6689430c               -mov word ptr [ebx + 0xc], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(12) /* 0xc */) = cpu.ax;
    // 004b76af  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b76b1  668b448602             -mov ax, word ptr [esi + eax*4 + 2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(2) /* 0x2 */ + cpu.eax * 4);
    // 004b76b6  6689430e               -mov word ptr [ebx + 0xe], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(14) /* 0xe */) = cpu.ax;
    // 004b76ba  c6431501               -mov byte ptr [ebx + 0x15], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(21) /* 0x15 */) = 1 /*0x1*/;
    // 004b76be  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b76c1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b76c2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b76c3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b76c4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b76c5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b76c6:
    // 004b76c6  8d72fe                 -lea esi, [edx - 2]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(-2) /* -0x2 */);
    // 004b76c9  668b5012               -mov dx, word ptr [eax + 0x12]
    cpu.dx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(18) /* 0x12 */);
    // 004b76cd  668916                 -mov word ptr [esi], dx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.dx;
    // 004b76d0  83ee02                 +sub esi, 2
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
    // 004b76d3  668b4010               -mov ax, word ptr [eax + 0x10]
    cpu.ax = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004b76d7  668906                 -mov word ptr [esi], ax
    app->getMemory<x86::reg16>(cpu.esi) = cpu.ax;
    // 004b76da  e9affeffff             -jmp 0x4b758e
    goto L_0x004b758e;
L_0x004b76df:
    // 004b76df  c6431400               -mov byte ptr [ebx + 0x14], 0
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(20) /* 0x14 */) = 0 /*0x0*/;
    // 004b76e3  c6431501               -mov byte ptr [ebx + 0x15], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(21) /* 0x15 */) = 1 /*0x1*/;
    // 004b76e7  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b76ea  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b76eb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b76ec  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b76ed  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b76ee  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
