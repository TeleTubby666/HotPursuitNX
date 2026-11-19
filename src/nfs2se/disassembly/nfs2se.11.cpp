#include "nfs2se.h"
#include <lib/thread.h>

namespace nfs2se
{

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_460300(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00460300  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00460301  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00460302  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00460303  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00460304  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00460305  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00460306  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00460309  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0046030b  a12c0c5000             -mov eax, dword ptr [0x500c2c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5245996) /* 0x500c2c */);
    // 00460310  48                     -dec eax
    (cpu.eax)--;
    // 00460311  8b1584f54d00           -mov edx, dword ptr [0x4df584]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5109124) /* 0x4df584 */);
    // 00460317  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 0046031a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046031c  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00460320  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00460322  0f8ecf000000           -jle 0x4603f7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004603f7;
    }
    // 00460328  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046032c  4a                     -dec edx
    (cpu.edx)--;
    // 0046032d  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00460330  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00460333  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00460337  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0046033b  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0046033f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00460341  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00460343  81c228f84f00           -add edx, 0x4ff828
    (cpu.edx) += x86::reg32(x86::sreg32(5240872 /*0x4ff828*/));
L_0x00460349:
    // 00460349  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046034d  80b82808500000         +cmp byte ptr [eax + 0x500828], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5244968) /* 0x500828 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00460354  7556                   -jne 0x4603ac
    if (!cpu.flags.zf)
    {
        goto L_0x004603ac;
    }
    // 00460356  ff049d2c0c5000         -inc dword ptr [ebx*4 + 0x500c2c]
    (app->getMemory<x86::reg32>(x86::reg32(5245996) /* 0x500c2c */ + cpu.ebx * 4))++;
    // 0046035d  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00460361  b501                   -mov ch, 1
    cpu.ch = 1 /*0x1*/;
    // 00460363  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00460367  88a828085000           -mov byte ptr [eax + 0x500828], ch
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5244968) /* 0x500828 */) = cpu.ch;
    // 0046036d  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 00460372  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00460374  0f848d000000           -je 0x460407
    if (cpu.flags.zf)
    {
        goto L_0x00460407;
    }
    // 0046037a  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
L_0x0046037d:
    // 0046037d  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 00460380  8d348500000000         -lea esi, [eax*4]
    cpu.esi = x86::reg32(cpu.eax * 4);
    // 00460387  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00460389  c1e009                 -shl eax, 9
    cpu.eax <<= 9 /*0x9*/ % 32;
    // 0046038c  0528f84f00             -add eax, 0x4ff828
    (cpu.eax) += x86::reg32(x86::sreg32(5240872 /*0x4ff828*/));
    // 00460391  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00460393  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00460395  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00460396  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00460398  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0046039b  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046039d  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0046039f  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004603a2  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004603a4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004603a5  80a52bf84f00bc         -and byte ptr [ebp + 0x4ff82b], 0xbc
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(5240875) /* 0x4ff82b */) &= x86::reg8(x86::sreg8(188 /*0xbc*/));
L_0x004603ac:
    // 004603ac  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 004603b1  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004603b5  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004603b7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004603b8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004603ba  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004603bd  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004603bf  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004603c1  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004603c4  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004603c6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004603c7  81c500020000           -add ebp, 0x200
    (cpu.ebp) += x86::reg32(x86::sreg32(512 /*0x200*/));
    // 004603cd  43                     -inc ebx
    (cpu.ebx)++;
    // 004603ce  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004603d2  8d7704                 -lea esi, [edi + 4]
    cpu.esi = x86::reg32(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 004603d5  81c200020000           -add edx, 0x200
    (cpu.edx) += x86::reg32(x86::sreg32(512 /*0x200*/));
    // 004603db  8b3d84f54d00           -mov edi, dword ptr [0x4df584]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5109124) /* 0x4df584 */);
    // 004603e1  81c180000000           -add ecx, 0x80
    (cpu.ecx) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 004603e7  89742408               -mov dword ptr [esp + 8], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 004603eb  894c240c               -mov dword ptr [esp + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004603ef  39fb                   +cmp ebx, edi
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
    // 004603f1  0f8c52ffffff           -jl 0x460349
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00460349;
    }
L_0x004603f7:
    // 004603f7  ff05f48c4c00           -inc dword ptr [0x4c8cf4]
    (app->getMemory<x86::reg32>(x86::reg32(5016820) /* 0x4c8cf4 */))++;
    // 004603fd  83c410                 +add esp, 0x10
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
    // 00460400  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460401  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460402  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460403  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460404  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460405  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460406  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00460407:
    // 00460407  b87f000000             -mov eax, 0x7f
    cpu.eax = 127 /*0x7f*/;
    // 0046040c  e96cffffff             -jmp 0x46037d
    goto L_0x0046037d;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_460420(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00460420  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00460421  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00460422  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00460423  befcf74f00             -mov esi, 0x4ff7fc
    cpu.esi = 5240828 /*0x4ff7fc*/;
    // 00460428  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0046042d  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00460430  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00460432  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00460434  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00460435  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00460437  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0046043a  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046043c  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0046043e  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00460441  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00460443  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460444  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460445  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460446  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460447  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_460450(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00460450  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00460451  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00460452  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00460455  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 00460458  8b1534f54d00           -mov edx, dword ptr [0x4df534]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5109044) /* 0x4df534 */);
    // 0046045e  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00460461  83fa01                 +cmp edx, 1
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
    // 00460464  0f8f88000000           -jg 0x4604f2
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004604f2;
    }
    // 0046046a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046046b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046046c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046046d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046046e  8b0d84f54d00           -mov ecx, dword ptr [0x4df584]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5109124) /* 0x4df584 */);
    // 00460474  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00460476  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00460478  7e42                   -jle 0x4604bc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004604bc;
    }
    // 0046047a  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 00460481  bbfcf74f00             -mov ebx, 0x4ff7fc
    cpu.ebx = 5240828 /*0x4ff7fc*/;
    // 00460486  81c228f84f00           -add edx, 0x4ff828
    (cpu.edx) += x86::reg32(x86::sreg32(5240872 /*0x4ff828*/));
L_0x0046048c:
    // 0046048c  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 00460491  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00460493  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00460495  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00460496  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00460498  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0046049b  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046049d  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0046049f  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004604a2  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004604a4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004604a5  45                     -inc ebp
    (cpu.ebp)++;
    // 004604a6  8b3584f54d00           -mov esi, dword ptr [0x4df584]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5109124) /* 0x4df584 */);
    // 004604ac  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004604af  81c200020000           -add edx, 0x200
    (cpu.edx) += x86::reg32(x86::sreg32(512 /*0x200*/));
    // 004604b5  39f5                   +cmp ebp, esi
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
    // 004604b7  7cd3                   -jl 0x46048c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046048c;
    }
    // 004604b9  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x004604bc:
    // 004604bc  8b3d84f54d00           -mov edi, dword ptr [0x4df584]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5109124) /* 0x4df584 */);
    // 004604c2  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004604c4  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004604c6  7e20                   -jle 0x4604e8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004604e8;
    }
    // 004604c8  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004604cc  8b2d84f54d00           -mov ebp, dword ptr [0x4df584]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5109124) /* 0x4df584 */);
L_0x004604d2:
    // 004604d2  81c280000000           -add edx, 0x80
    (cpu.edx) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 004604d8  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 004604da  43                     -inc ebx
    (cpu.ebx)++;
    // 004604db  88a2a8075000           -mov byte ptr [edx + 0x5007a8], ah
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5244840) /* 0x5007a8 */) = cpu.ah;
    // 004604e1  39eb                   +cmp ebx, ebp
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
    // 004604e3  7ced                   -jl 0x4604d2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004604d2;
    }
    // 004604e5  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x004604e8:
    // 004604e8  ff05280c5000           -inc dword ptr [0x500c28]
    (app->getMemory<x86::reg32>(x86::reg32(5245992) /* 0x500c28 */))++;
    // 004604ee  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004604ef  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004604f0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004604f1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004604f2:
    // 004604f2  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004604f5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004604f6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004604f7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_460500(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00460500  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00460501  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00460504  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00460507  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0046050b  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 00460512  8baa2c0c5000           -mov ebp, dword ptr [edx + 0x500c2c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5245996) /* 0x500c2c */);
    // 00460518  e827fbffff             -call 0x460044
    cpu.esp -= 4;
    sub_460044(app, cpu);
    if (cpu.terminate) return;
    // 0046051d  83e57f                 -and ebp, 0x7f
    cpu.ebp &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 00460520  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00460522  0f85e5000000           -jne 0x46060d
    if (!cpu.flags.zf)
    {
        goto L_0x0046060d;
    }
    // 00460528  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0046052b  c1e007                 -shl eax, 7
    cpu.eax <<= 7 /*0x7*/ % 32;
    // 0046052e  8a842828085000         -mov al, byte ptr [eax + ebp + 0x500828]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5244968) /* 0x500828 */ + cpu.ebp * 1);
    // 00460535  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 00460537  0f85d0000000           -jne 0x46060d
    if (!cpu.flags.zf)
    {
        goto L_0x0046060d;
    }
    // 0046053d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046053e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046053f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00460540  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00460541  8b1d1cf84f00           -mov ebx, dword ptr [0x4ff81c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5240860) /* 0x4ff81c */);
    // 00460547  8b0d2c0c5000           -mov ecx, dword ptr [0x500c2c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5245996) /* 0x500c2c */);
    // 0046054d  8bb22c0c5000           -mov esi, dword ptr [edx + 0x500c2c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5245996) /* 0x500c2c */);
    // 00460553  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00460555  39f1                   +cmp ecx, esi
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
    // 00460557  7d68                   -jge 0x4605c1
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004605c1;
    }
    // 00460559  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046055d  8d7eff                 -lea edi, [esi - 1]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(-1) /* -0x1 */);
    // 00460560  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00460562  89ba2c0c5000           -mov dword ptr [edx + 0x500c2c], edi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5245996) /* 0x500c2c */) = cpu.edi;
    // 00460568  c1e309                 -shl ebx, 9
    cpu.ebx <<= 9 /*0x9*/ % 32;
    // 0046056b  8b0d2c0c5000           -mov ecx, dword ptr [0x500c2c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5245996) /* 0x500c2c */);
    // 00460571  81c328f84f00           -add ebx, 0x4ff828
    (cpu.ebx) += x86::reg32(x86::sreg32(5240872 /*0x4ff828*/));
    // 00460577  39f9                   +cmp ecx, edi
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
    // 00460579  7d3d                   -jge 0x4605b8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004605b8;
    }
L_0x0046057b:
    // 0046057b  8d5101                 -lea edx, [ecx + 1]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(1) /* 0x1 */);
    // 0046057e  83e17f                 -and ecx, 0x7f
    cpu.ecx &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 00460581  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00460583  8d3c8d00000000         -lea edi, [ecx*4]
    cpu.edi = x86::reg32(cpu.ecx * 4);
    // 0046058a  83e67f                 -and esi, 0x7f
    cpu.esi &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 0046058d  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 00460592  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 00460595  01df                   -add edi, ebx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00460597  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00460599  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046059a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046059c  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0046059f  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004605a1  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004605a3  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004605a6  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004605a8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004605a9  8bb52c0c5000           -mov esi, dword ptr [ebp + 0x500c2c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(5245996) /* 0x500c2c */);
    // 004605af  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004605b1  39f2                   +cmp edx, esi
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
    // 004605b3  7cc6                   -jl 0x46057b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046057b;
    }
    // 004605b5  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x004605b8:
    // 004605b8  8bad2c0c5000           -mov ebp, dword ptr [ebp + 0x500c2c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(5245996) /* 0x500c2c */);
    // 004605be  83e57f                 -and ebp, 0x7f
    cpu.ebp &= x86::reg32(x86::sreg32(127 /*0x7f*/));
L_0x004605c1:
    // 004605c1  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004605c5  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 004605ca  c1e009                 -shl eax, 9
    cpu.eax <<= 9 /*0x9*/ % 32;
    // 004605cd  8d3cad00000000         -lea edi, [ebp*4]
    cpu.edi = x86::reg32(cpu.ebp * 4);
    // 004605d4  0528f84f00             -add eax, 0x4ff828
    (cpu.eax) += x86::reg32(x86::sreg32(5240872 /*0x4ff828*/));
    // 004605d9  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004605dd  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004605df  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004605e0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004605e2  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004605e5  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004605e7  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004605e9  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004605ec  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004605ee  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004605ef  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004605f3  c1e007                 -shl eax, 7
    cpu.eax <<= 7 /*0x7*/ % 32;
    // 004605f6  c684282808500001       -mov byte ptr [eax + ebp + 0x500828], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5244968) /* 0x500828 */ + cpu.ebp * 1) = 1 /*0x1*/;
    // 004605fe  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00460602  ff04852c0c5000         -inc dword ptr [eax*4 + 0x500c2c]
    (app->getMemory<x86::reg32>(x86::reg32(5245996) /* 0x500c2c */ + cpu.eax * 4))++;
    // 00460609  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046060a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046060b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046060c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0046060d:
    // 0046060d  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00460610  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460611  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_460634(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00460634  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00460635  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00460636  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00460637  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00460638  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00460639  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0046063b  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0046063d  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 00460644  8bba2c0c5000           -mov edi, dword ptr [edx + 0x500c2c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5245996) /* 0x500c2c */);
    // 0046064a  668b0d7a074e00         -mov cx, word ptr [0x4e077a]
    cpu.cx = app->getMemory<x86::reg16>(x86::reg32(5113722) /* 0x4e077a */);
    // 00460651  83e77f                 -and edi, 0x7f
    cpu.edi &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 00460654  6685c9                 +test cx, cx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.cx & cpu.cx));
    // 00460657  7414                   -je 0x46066d
    if (cpu.flags.zf)
    {
        goto L_0x0046066d;
    }
    // 00460659  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0046065e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00460660  a3f88c4c00             -mov dword ptr [0x4c8cf8], eax
    app->getMemory<x86::reg32>(x86::reg32(5016824) /* 0x4c8cf8 */) = cpu.eax;
    // 00460665  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00460667  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460668  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460669  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046066a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046066b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046066c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046066d:
    // 0046066d  e8d2f9ffff             -call 0x460044
    cpu.esp -= 4;
    sub_460044(app, cpu);
    if (cpu.terminate) return;
    // 00460672  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00460674  752c                   -jne 0x4606a2
    if (!cpu.flags.zf)
    {
        goto L_0x004606a2;
    }
    // 00460676  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00460678  c1e507                 -shl ebp, 7
    cpu.ebp <<= 7 /*0x7*/ % 32;
    // 0046067b  01fd                   -add ebp, edi
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edi));
    // 0046067d  80bd2808500000         +cmp byte ptr [ebp + 0x500828], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(5244968) /* 0x500828 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00460684  7426                   -je 0x4606ac
    if (cpu.flags.zf)
    {
        goto L_0x004606ac;
    }
    // 00460686  833d28f54d0001         +cmp dword ptr [0x4df528], 1
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
    // 0046068d  7e13                   -jle 0x4606a2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004606a2;
    }
    // 0046068f  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 00460694  6689357c074e00         -mov word ptr [0x4e077c], si
    app->getMemory<x86::reg16>(x86::reg32(5113724) /* 0x4e077c */) = cpu.si;
    // 0046069b  6689357a074e00         -mov word ptr [0x4e077a], si
    app->getMemory<x86::reg16>(x86::reg32(5113722) /* 0x4e077a */) = cpu.si;
L_0x004606a2:
    // 004606a2  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004606a4  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004606a6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004606a7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004606a8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004606a9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004606aa  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004606ab  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004606ac:
    // 004606ac  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004606ae  c1e009                 -shl eax, 9
    cpu.eax <<= 9 /*0x9*/ % 32;
    // 004606b1  c1e702                 -shl edi, 2
    cpu.edi <<= 2 /*0x2*/ % 32;
    // 004606b4  0528f84f00             -add eax, 0x4ff828
    (cpu.eax) += x86::reg32(x86::sreg32(5240872 /*0x4ff828*/));
    // 004606b9  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 004606be  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004606c0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004606c1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004606c3  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004606c6  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004606c8  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004606ca  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004606cd  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004606cf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004606d0  c6852808500001         -mov byte ptr [ebp + 0x500828], 1
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(5244968) /* 0x500828 */) = 1 /*0x1*/;
    // 004606d7  8b8a2c0c5000           -mov ecx, dword ptr [edx + 0x500c2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5245996) /* 0x500c2c */);
    // 004606dd  41                     -inc ecx
    (cpu.ecx)++;
    // 004606de  a128f54d00             -mov eax, dword ptr [0x4df528]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5109032) /* 0x4df528 */);
    // 004606e3  898a2c0c5000           -mov dword ptr [edx + 0x500c2c], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5245996) /* 0x500c2c */) = cpu.ecx;
    // 004606e9  83f804                 +cmp eax, 4
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
    // 004606ec  770d                   -ja 0x4606fb
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004606fb;
    }
    // 004606ee  ff248520064600         -jmp dword ptr [eax*4 + 0x460620]
    cpu.ip = app->getMemory<x86::reg32>(4589088 + cpu.eax * 4); goto dynamic_jump;
  case 0x004606f5:
    // 004606f5  ff05f48c4c00           -inc dword ptr [0x4c8cf4]
    (app->getMemory<x86::reg32>(x86::reg32(5016820) /* 0x4c8cf4 */))++;
L_0x004606fb:
    // 004606fb  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00460700  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00460702  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460703  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460704  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460705  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460706  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460707  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00460708:
    // 00460708  803d7f074e0001         +cmp byte ptr [0x4e077f], 1
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
    // 0046070f  7520                   -jne 0x460731
    if (!cpu.flags.zf)
    {
        goto L_0x00460731;
    }
    // 00460711  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00460713  75e6                   -jne 0x4606fb
    if (!cpu.flags.zf)
    {
        goto L_0x004606fb;
    }
    // 00460715  833d2cf54d0000         +cmp dword ptr [0x4df52c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5109036) /* 0x4df52c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046071c  74dd                   -je 0x4606fb
    if (cpu.flags.zf)
    {
        goto L_0x004606fb;
    }
    // 0046071e  ff05f48c4c00           -inc dword ptr [0x4c8cf4]
    (app->getMemory<x86::reg32>(x86::reg32(5016820) /* 0x4c8cf4 */))++;
    // 00460724  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00460729  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0046072b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046072c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046072d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046072e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046072f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460730  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00460731:
    // 00460731  8b15300c5000           -mov edx, dword ptr [0x500c30]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5246000) /* 0x500c30 */);
    // 00460737  a12c0c5000             -mov eax, dword ptr [0x500c2c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5245996) /* 0x500c2c */);
    // 0046073c  39d0                   +cmp eax, edx
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
    // 0046073e  7d02                   -jge 0x460742
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00460742;
    }
    // 00460740  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x00460742:
    // 00460742  4a                     -dec edx
    (cpu.edx)--;
    // 00460743  8915f48c4c00           -mov dword ptr [0x4c8cf4], edx
    app->getMemory<x86::reg32>(x86::reg32(5016820) /* 0x4c8cf4 */) = cpu.edx;
    // 00460749  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0046074e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00460750  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460751  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460752  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460753  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460754  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460755  c3                     -ret 
    cpu.esp += 4;
    return;
  case 0x00460756:
    // 00460756  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00460758  74a1                   -je 0x4606fb
    if (cpu.flags.zf)
    {
        goto L_0x004606fb;
    }
    // 0046075a  ff05f48c4c00           -inc dword ptr [0x4c8cf4]
    (app->getMemory<x86::reg32>(x86::reg32(5016820) /* 0x4c8cf4 */))++;
    // 00460760  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00460765  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00460767  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460768  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460769  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046076a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046076b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046076c  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_460770(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00460770  833d34f54d0001         +cmp dword ptr [0x4df534], 1
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
    // 00460777  7e01                   -jle 0x46077a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046077a;
    }
    // 00460779  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046077a:
    // 0046077a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046077b  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00460780  890df88c4c00           -mov dword ptr [0x4c8cf8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5016824) /* 0x4c8cf8 */) = cpu.ecx;
    // 00460786  890dfc8c4c00           -mov dword ptr [0x4c8cfc], ecx
    app->getMemory<x86::reg32>(x86::reg32(5016828) /* 0x4c8cfc */) = cpu.ecx;
    // 0046078c  e81ff8ffff             -call 0x45ffb0
    cpu.esp -= 4;
    sub_45ffb0(app, cpu);
    if (cpu.terminate) return;
    // 00460791  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460792  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4607a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004607a0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004607a1  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004607a4  833d34f54d0001         +cmp dword ptr [0x4df534], 1
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
    // 004607ab  0f8f7b000000           -jg 0x46082c
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0046082c;
    }
    // 004607b1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004607b2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004607b3  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004607b4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004607b5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004607b6  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004607bb  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004607bd  890dfc8c4c00           -mov dword ptr [0x4c8cfc], ecx
    app->getMemory<x86::reg32>(x86::reg32(5016828) /* 0x4c8cfc */) = cpu.ecx;
    // 004607c3  8974241c               -mov dword ptr [esp + 0x1c], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.esi;
    // 004607c7  89742414               -mov dword ptr [esp + 0x14], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.esi;
    // 004607cb  89742418               -mov dword ptr [esp + 0x18], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 004607cf  890df88c4c00           -mov dword ptr [0x4c8cf8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5016824) /* 0x4c8cf8 */) = cpu.ecx;
    // 004607d5  b701                   -mov bh, 1
    cpu.bh = 1 /*0x1*/;
L_0x004607d7:
    // 004607d7  8b6c241c               -mov ebp, dword ptr [esp + 0x1c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004607db  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004607df  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004607e1  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 004607e3  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
L_0x004607e5:
    // 004607e5  8d043a                 -lea eax, [edx + edi]
    cpu.eax = x86::reg32(cpu.edx + cpu.edi * 1);
    // 004607e8  88b828085000           -mov byte ptr [eax + 0x500828], bh
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5244968) /* 0x500828 */) = cpu.bh;
    // 004607ee  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004607f5  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004607f7  8d0c2a                 -lea ecx, [edx + ebp]
    cpu.ecx = x86::reg32(cpu.edx + cpu.ebp * 1);
L_0x004607fa:
    // 004607fa  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004607fd  889825f84f00           -mov byte ptr [eax + 0x4ff825], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5240869) /* 0x4ff825 */) = cpu.bl;
    // 00460803  889826f84f00           -mov byte ptr [eax + 0x4ff826], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5240870) /* 0x4ff826 */) = cpu.bl;
    // 00460809  41                     -inc ecx
    (cpu.ecx)++;
    // 0046080a  889827f84f00           -mov byte ptr [eax + 0x4ff827], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5240871) /* 0x4ff827 */) = cpu.bl;
    // 00460810  42                     -inc edx
    (cpu.edx)++;
    // 00460811  889824f84f00           -mov byte ptr [eax + 0x4ff824], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5240868) /* 0x4ff824 */) = cpu.bl;
    // 00460817  81fa80000000           +cmp edx, 0x80
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
    // 0046081d  7d19                   -jge 0x460838
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00460838;
    }
    // 0046081f  83fa04                 +cmp edx, 4
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
    // 00460822  7cc1                   -jl 0x4607e5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004607e5;
    }
    // 00460824  889928085000           -mov byte ptr [ecx + 0x500828], bl
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5244968) /* 0x500828 */) = cpu.bl;
    // 0046082a  ebce                   -jmp 0x4607fa
    goto L_0x004607fa;
L_0x0046082c:
    // 0046082c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046082e  a3f48c4c00             -mov dword ptr [0x4c8cf4], eax
    app->getMemory<x86::reg32>(x86::reg32(5016820) /* 0x4c8cf4 */) = cpu.eax;
    // 00460833  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00460836  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460837  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00460838:
    // 00460838  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0046083c  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00460840  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00460844  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 00460849  81c180000000           -add ecx, 0x80
    (cpu.ecx) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 0046084f  81c600020000           -add esi, 0x200
    (cpu.esi) += x86::reg32(x86::sreg32(512 /*0x200*/));
    // 00460855  8d3c10                 -lea edi, [eax + edx]
    cpu.edi = x86::reg32(cpu.eax + cpu.edx * 1);
    // 00460858  89902c0c5000           -mov dword ptr [eax + 0x500c2c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5245996) /* 0x500c2c */) = cpu.edx;
    // 0046085e  894c241c               -mov dword ptr [esp + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 00460862  89742414               -mov dword ptr [esp + 0x14], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.esi;
    // 00460866  897c2418               -mov dword ptr [esp + 0x18], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edi;
    // 0046086a  83ff20                 +cmp edi, 0x20
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
    // 0046086d  0f8564ffffff           -jne 0x4607d7
    if (!cpu.flags.zf)
    {
        goto L_0x004607d7;
    }
    // 00460873  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 00460878  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046087a  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046087c  a3280c5000             -mov dword ptr [0x500c28], eax
    app->getMemory<x86::reg32>(x86::reg32(5245992) /* 0x500c28 */) = cpu.eax;
    // 00460881  8915f48c4c00           -mov dword ptr [0x4c8cf4], edx
    app->getMemory<x86::reg32>(x86::reg32(5016820) /* 0x4c8cf4 */) = cpu.edx;
    // 00460887  e864f7ffff             -call 0x45fff0
    cpu.esp -= 4;
    sub_45fff0(app, cpu);
    if (cpu.terminate) return;
    // 0046088c  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 0046088e  ba0f000000             -mov edx, 0xf
    cpu.edx = 15 /*0xf*/;
    // 00460893  88254c0c5000           -mov byte ptr [0x500c4c], ah
    app->getMemory<x86::reg8>(x86::reg32(5246028) /* 0x500c4c */) = cpu.ah;
    // 00460899  b8001e0000             -mov eax, 0x1e00
    cpu.eax = 7680 /*0x1e00*/;
    // 0046089e  890dfc8c4c00           -mov dword ptr [0x4c8cfc], ecx
    app->getMemory<x86::reg32>(x86::reg32(5016828) /* 0x4c8cfc */) = cpu.ecx;
    // 004608a4  e8e707ffff             -call 0x451090
    cpu.esp -= 4;
    sub_451090(app, cpu);
    if (cpu.terminate) return;
    // 004608a9  890df88c4c00           -mov dword ptr [0x4c8cf8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5016824) /* 0x4c8cf8 */) = cpu.ecx;
    // 004608af  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004608b0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004608b1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004608b2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004608b3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004608b4  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004608b7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004608b8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4608c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004608c0  833d34f54d0001         +cmp dword ptr [0x4df534], 1
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
    // 004608c7  7e01                   -jle 0x4608ca
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004608ca;
    }
    // 004608c9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004608ca:
    // 004608ca  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004608cb  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004608d0  890df88c4c00           -mov dword ptr [0x4c8cf8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5016824) /* 0x4c8cf8 */) = cpu.ecx;
    // 004608d6  890dfc8c4c00           -mov dword ptr [0x4c8cfc], ecx
    app->getMemory<x86::reg32>(x86::reg32(5016828) /* 0x4c8cfc */) = cpu.ecx;
    // 004608dc  e82ff7ffff             -call 0x460010
    cpu.esp -= 4;
    sub_460010(app, cpu);
    if (cpu.terminate) return;
    // 004608e1  e8cef8ffff             -call 0x4601b4
    cpu.esp -= 4;
    sub_4601b4(app, cpu);
    if (cpu.terminate) return;
    // 004608e6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004608e7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4608f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004608f0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_460900(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00460900  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00460901  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00460902  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00460903  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00460904  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00460905  b8d0d54b00             -mov eax, 0x4bd5d0
    cpu.eax = 4969936 /*0x4bd5d0*/;
    // 0046090a  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0046090f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00460911  e82a010000             -call 0x460a40
    cpu.esp -= 4;
    sub_460a40(app, cpu);
    if (cpu.terminate) return;
    // 00460916  e805200000             -call 0x462920
    cpu.esp -= 4;
    sub_462920(app, cpu);
    if (cpu.terminate) return;
    // 0046091b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046091d  e87e1f0000             -call 0x4628a0
    cpu.esp -= 4;
    sub_4628a0(app, cpu);
    if (cpu.terminate) return;
    // 00460922  8b0d10fa4d00           -mov ecx, dword ptr [0x4dfa10]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5110288) /* 0x4dfa10 */);
    // 00460928  39c8                   +cmp eax, ecx
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
    // 0046092a  7e02                   -jle 0x46092e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046092e;
    }
    // 0046092c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x0046092e:
    // 0046092e  a310fa4d00             -mov dword ptr [0x4dfa10], eax
    app->getMemory<x86::reg32>(x86::reg32(5110288) /* 0x4dfa10 */) = cpu.eax;
    // 00460933  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00460935  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00460937  7e77                   -jle 0x4609b0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004609b0;
    }
    // 00460939  be10000000             -mov esi, 0x10
    cpu.esi = 16 /*0x10*/;
    // 0046093e  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00460940:
    // 00460940  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00460942  e8591f0000             -call 0x4628a0
    cpu.esp -= 4;
    sub_4628a0(app, cpu);
    if (cpu.terminate) return;
    // 00460947  89816c0c5000           -mov dword ptr [ecx + 0x500c6c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5246060) /* 0x500c6c */) = cpu.eax;
    // 0046094d  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0046094f  89b1700c5000           -mov dword ptr [ecx + 0x500c70], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5246064) /* 0x500c70 */) = cpu.esi;
    // 00460955  89b9740c5000           -mov dword ptr [ecx + 0x500c74], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5246068) /* 0x500c74 */) = cpu.edi;
    // 0046095b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046095d  89b9780c5000           -mov dword ptr [ecx + 0x500c78], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5246072) /* 0x500c78 */) = cpu.edi;
    // 00460963  e8381f0000             -call 0x4628a0
    cpu.esp -= 4;
    sub_4628a0(app, cpu);
    if (cpu.terminate) return;
    // 00460968  8981ac0c5000           -mov dword ptr [ecx + 0x500cac], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5246124) /* 0x500cac */) = cpu.eax;
    // 0046096e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00460970  e82b1f0000             -call 0x4628a0
    cpu.esp -= 4;
    sub_4628a0(app, cpu);
    if (cpu.terminate) return;
    // 00460975  8981b00c5000           -mov dword ptr [ecx + 0x500cb0], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5246128) /* 0x500cb0 */) = cpu.eax;
    // 0046097b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046097d  e81e1f0000             -call 0x4628a0
    cpu.esp -= 4;
    sub_4628a0(app, cpu);
    if (cpu.terminate) return;
    // 00460982  8981b40c5000           -mov dword ptr [ecx + 0x500cb4], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5246132) /* 0x500cb4 */) = cpu.eax;
    // 00460988  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046098a  e8111f0000             -call 0x4628a0
    cpu.esp -= 4;
    sub_4628a0(app, cpu);
    if (cpu.terminate) return;
    // 0046098f  8981b80c5000           -mov dword ptr [ecx + 0x500cb8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5246136) /* 0x500cb8 */) = cpu.eax;
    // 00460995  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00460997  43                     -inc ebx
    (cpu.ebx)++;
    // 00460998  e8031f0000             -call 0x4628a0
    cpu.esp -= 4;
    sub_4628a0(app, cpu);
    if (cpu.terminate) return;
    // 0046099d  8981bc0c5000           -mov dword ptr [ecx + 0x500cbc], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5246140) /* 0x500cbc */) = cpu.eax;
    // 004609a3  a110fa4d00             -mov eax, dword ptr [0x4dfa10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5110288) /* 0x4dfa10 */);
    // 004609a8  83c154                 -add ecx, 0x54
    (cpu.ecx) += x86::reg32(x86::sreg32(84 /*0x54*/));
    // 004609ab  39c3                   +cmp ebx, eax
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
    // 004609ad  7c91                   -jl 0x460940
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00460940;
    }
    // 004609af  90                     -nop 
    ;
L_0x004609b0:
    // 004609b0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004609b2  e8391f0000             -call 0x4628f0
    cpu.esp -= 4;
    sub_4628f0(app, cpu);
    if (cpu.terminate) return;
    // 004609b7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004609b8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004609b9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004609ba  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004609bb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004609bc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_4609c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004609c0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004609c1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004609c2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004609c4  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004609c6  8b1580f54d00           -mov edx, dword ptr [0x4df580]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5109120) /* 0x4df580 */);
    // 004609cc  83e01f                 -and eax, 0x1f
    cpu.eax &= x86::reg32(x86::sreg32(31 /*0x1f*/));
    // 004609cf  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004609d1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004609d3  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004609d6  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004609d8  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004609db  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004609dd  8b1485ac0c5000         -mov edx, dword ptr [eax*4 + 0x500cac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5246124) /* 0x500cac */ + cpu.eax * 4);
    // 004609e4  895114                 -mov dword ptr [ecx + 0x14], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004609e7  8b1485b00c5000         -mov edx, dword ptr [eax*4 + 0x500cb0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5246128) /* 0x500cb0 */ + cpu.eax * 4);
    // 004609ee  89919c000000           -mov dword ptr [ecx + 0x9c], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(156) /* 0x9c */) = cpu.edx;
    // 004609f4  8b1485b40c5000         -mov edx, dword ptr [eax*4 + 0x500cb4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5246132) /* 0x500cb4 */ + cpu.eax * 4);
    // 004609fb  8991a0000000           -mov dword ptr [ecx + 0xa0], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(160) /* 0xa0 */) = cpu.edx;
    // 00460a01  8b1485b80c5000         -mov edx, dword ptr [eax*4 + 0x500cb8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5246136) /* 0x500cb8 */ + cpu.eax * 4);
    // 00460a08  c6818c00000001         -mov byte ptr [ecx + 0x8c], 1
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(140) /* 0x8c */) = 1 /*0x1*/;
    // 00460a0f  8991a4000000           -mov dword ptr [ecx + 0xa4], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(164) /* 0xa4 */) = cpu.edx;
    // 00460a15  8b1485bc0c5000         -mov edx, dword ptr [eax*4 + 0x500cbc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5246140) /* 0x500cbc */ + cpu.eax * 4);
    // 00460a1c  8d81c4000000           -lea eax, [ecx + 0xc4]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(196) /* 0xc4 */);
    // 00460a22  e849e50200             -call 0x48ef70
    cpu.esp -= 4;
    sub_48ef70(app, cpu);
    if (cpu.terminate) return;
    // 00460a27  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00460a29  e892f6feff             -call 0x4500c0
    cpu.esp -= 4;
    sub_4500c0(app, cpu);
    if (cpu.terminate) return;
    // 00460a2e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460a2f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460a30  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_460a40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00460a40  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00460a41  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00460a42  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00460a43  8b153cf54d00           -mov edx, dword ptr [0x4df53c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5109052) /* 0x4df53c */);
    // 00460a49  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00460a4a  8b0da8074e00           -mov ecx, dword ptr [0x4e07a8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5113768) /* 0x4e07a8 */);
    // 00460a50  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00460a51  68c4d54b00             -push 0x4bd5c4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4969924 /*0x4bd5c4*/;
    cpu.esp -= 4;
    // 00460a56  68100e5000             -push 0x500e10
    app->getMemory<x86::reg32>(cpu.esp-4) = 5246480 /*0x500e10*/;
    cpu.esp -= 4;
    // 00460a5b  e881b50100             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 00460a60  b8100e5000             -mov eax, 0x500e10
    cpu.eax = 5246480 /*0x500e10*/;
    // 00460a65  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00460a68  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460a69  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460a6a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_460a70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00460a70  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_460a80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00460a80  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00460a81  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00460a82  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00460a83  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00460a84  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00460a86  80b88c00000000         +cmp byte ptr [eax + 0x8c], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(140) /* 0x8c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00460a8d  756c                   -jne 0x460afb
    if (!cpu.flags.zf)
    {
        goto L_0x00460afb;
    }
    // 00460a8f  6683b94c01000000       +cmp word ptr [ecx + 0x14c], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(332) /* 0x14c */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00460a97  7667                   -jbe 0x460b00
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00460b00;
    }
    // 00460a99  81b95c01000000800000   +cmp dword ptr [ecx + 0x15c], 0x8000
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(348) /* 0x15c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32768 /*0x8000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00460aa3  0f8c0e010000           -jl 0x460bb7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00460bb7;
    }
L_0x00460aa9:
    // 00460aa9  8b1524f54d00           -mov edx, dword ptr [0x4df524]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5109028) /* 0x4df524 */);
    // 00460aaf  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 00460ab6  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00460ab8  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00460abb  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00460abd  8b9160010000           -mov edx, dword ptr [ecx + 0x160]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(352) /* 0x160 */);
    // 00460ac3  3b1485a8f04d00         +cmp edx, dword ptr [eax*4 + 0x4df0a8]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5107880) /* 0x4df0a8 */ + cpu.eax * 4)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00460aca  0f8fbe010000           -jg 0x460c8e
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00460c8e;
    }
    // 00460ad0  83b97805000000         +cmp dword ptr [ecx + 0x578], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1400) /* 0x578 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00460ad7  7e15                   -jle 0x460aee
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00460aee;
    }
L_0x00460ad9:
    // 00460ad9  8ba978050000           -mov ebp, dword ptr [ecx + 0x578]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1400) /* 0x578 */);
    // 00460adf  4d                     -dec ebp
    (cpu.ebp)--;
    // 00460ae0  89a978050000           -mov dword ptr [ecx + 0x578], ebp
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1400) /* 0x578 */) = cpu.ebp;
    // 00460ae6  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00460ae8  0f8eb6010000           -jle 0x460ca4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00460ca4;
    }
L_0x00460aee:
    // 00460aee  83b97805000000         +cmp dword ptr [ecx + 0x578], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1400) /* 0x578 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00460af5  0f8eba010000           -jle 0x460cb5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00460cb5;
    }
L_0x00460afb:
    // 00460afb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460afc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460afd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460afe  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460aff  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00460b00:
    // 00460b00  8b99a8000000           -mov ebx, dword ptr [ecx + 0xa8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(168) /* 0xa8 */);
    // 00460b06  69d3e6000000           -imul edx, ebx, 0xe6
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(230 /*0xe6*/)));
    // 00460b0c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00460b0e  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00460b11  c1e208                 +shl edx, 8
    {
        x86::reg8 tmp = 8 /*0x8*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 00460b14  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00460b16  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 00460b19  6991ac000000e6000000   -imul edx, dword ptr [ecx + 0xac], 0xe6
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(172) /* 0xac */))) * x86::sreg64(x86::sreg32(230 /*0xe6*/)));
    // 00460b23  8981a8000000           -mov dword ptr [ecx + 0xa8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(168) /* 0xa8 */) = cpu.eax;
    // 00460b29  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00460b2b  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00460b2e  c1e208                 +shl edx, 8
    {
        x86::reg8 tmp = 8 /*0x8*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 00460b31  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00460b33  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 00460b36  6991b0000000e6000000   -imul edx, dword ptr [ecx + 0xb0], 0xe6
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(176) /* 0xb0 */))) * x86::sreg64(x86::sreg32(230 /*0xe6*/)));
    // 00460b40  8981ac000000           -mov dword ptr [ecx + 0xac], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(172) /* 0xac */) = cpu.eax;
    // 00460b46  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00460b48  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00460b4b  c1e208                 +shl edx, 8
    {
        x86::reg8 tmp = 8 /*0x8*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 00460b4e  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00460b50  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 00460b53  6991e8000000e6000000   -imul edx, dword ptr [ecx + 0xe8], 0xe6
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(232) /* 0xe8 */))) * x86::sreg64(x86::sreg32(230 /*0xe6*/)));
    // 00460b5d  8981b0000000           -mov dword ptr [ecx + 0xb0], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(176) /* 0xb0 */) = cpu.eax;
    // 00460b63  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00460b65  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00460b68  c1e208                 +shl edx, 8
    {
        x86::reg8 tmp = 8 /*0x8*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 00460b6b  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00460b6d  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 00460b70  8981e8000000           -mov dword ptr [ecx + 0xe8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(232) /* 0xe8 */) = cpu.eax;
    // 00460b76  8b81ec000000           -mov eax, dword ptr [ecx + 0xec]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(236) /* 0xec */);
    // 00460b7c  69d0e6000000           -imul edx, eax, 0xe6
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(230 /*0xe6*/)));
    // 00460b82  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00460b84  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00460b87  c1e208                 +shl edx, 8
    {
        x86::reg8 tmp = 8 /*0x8*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 00460b8a  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00460b8c  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 00460b8f  6991f0000000e6000000   -imul edx, dword ptr [ecx + 0xf0], 0xe6
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(240) /* 0xf0 */))) * x86::sreg64(x86::sreg32(230 /*0xe6*/)));
    // 00460b99  8981ec000000           -mov dword ptr [ecx + 0xec], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(236) /* 0xec */) = cpu.eax;
    // 00460b9f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00460ba1  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00460ba4  c1e208                 +shl edx, 8
    {
        x86::reg8 tmp = 8 /*0x8*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 00460ba7  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00460ba9  c1f808                 +sar eax, 8
    {
        x86::reg8 tmp = 8 /*0x8*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 00460bac  8981f0000000           -mov dword ptr [ecx + 0xf0], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(240) /* 0xf0 */) = cpu.eax;
    // 00460bb2  e9f2feffff             -jmp 0x460aa9
    goto L_0x00460aa9;
L_0x00460bb7:
    // 00460bb7  8b81a8000000           -mov eax, dword ptr [ecx + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(168) /* 0xa8 */);
    // 00460bbd  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00460bc0  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00460bc2  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00460bc5  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00460bc7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00460bc9  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00460bcc  c1e208                 +shl edx, 8
    {
        x86::reg8 tmp = 8 /*0x8*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 00460bcf  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00460bd1  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 00460bd4  8981a8000000           -mov dword ptr [ecx + 0xa8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(168) /* 0xa8 */) = cpu.eax;
    // 00460bda  8b81ac000000           -mov eax, dword ptr [ecx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(172) /* 0xac */);
    // 00460be0  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00460be3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00460be5  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00460be8  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00460bea  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00460bec  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00460bef  c1e208                 +shl edx, 8
    {
        x86::reg8 tmp = 8 /*0x8*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 00460bf2  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00460bf4  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 00460bf7  8981ac000000           -mov dword ptr [ecx + 0xac], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(172) /* 0xac */) = cpu.eax;
    // 00460bfd  8b81b0000000           -mov eax, dword ptr [ecx + 0xb0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(176) /* 0xb0 */);
    // 00460c03  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00460c06  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00460c08  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00460c0b  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00460c0d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00460c0f  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00460c12  c1e208                 +shl edx, 8
    {
        x86::reg8 tmp = 8 /*0x8*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 00460c15  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00460c17  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 00460c1a  8981b0000000           -mov dword ptr [ecx + 0xb0], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(176) /* 0xb0 */) = cpu.eax;
    // 00460c20  8b81e8000000           -mov eax, dword ptr [ecx + 0xe8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(232) /* 0xe8 */);
    // 00460c26  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00460c29  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00460c2b  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00460c2e  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00460c30  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00460c32  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00460c35  c1e208                 +shl edx, 8
    {
        x86::reg8 tmp = 8 /*0x8*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 00460c38  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00460c3a  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 00460c3d  8981e8000000           -mov dword ptr [ecx + 0xe8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(232) /* 0xe8 */) = cpu.eax;
    // 00460c43  8b81ec000000           -mov eax, dword ptr [ecx + 0xec]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(236) /* 0xec */);
    // 00460c49  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00460c4c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00460c4e  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00460c51  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00460c53  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00460c55  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00460c58  c1e208                 +shl edx, 8
    {
        x86::reg8 tmp = 8 /*0x8*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 00460c5b  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00460c5d  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 00460c60  8981ec000000           -mov dword ptr [ecx + 0xec], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(236) /* 0xec */) = cpu.eax;
    // 00460c66  8b81f0000000           -mov eax, dword ptr [ecx + 0xf0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(240) /* 0xf0 */);
    // 00460c6c  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00460c6f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00460c71  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 00460c74  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00460c76  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00460c78  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00460c7b  c1e208                 +shl edx, 8
    {
        x86::reg8 tmp = 8 /*0x8*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 00460c7e  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00460c80  c1f808                 +sar eax, 8
    {
        x86::reg8 tmp = 8 /*0x8*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 00460c83  8981f0000000           -mov dword ptr [ecx + 0xf0], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(240) /* 0xf0 */) = cpu.eax;
    // 00460c89  e91bfeffff             -jmp 0x460aa9
    goto L_0x00460aa9;
L_0x00460c8e:
    // 00460c8e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00460c90  e86b1afeff             -call 0x442700
    cpu.esp -= 4;
    sub_442700(app, cpu);
    if (cpu.terminate) return;
    // 00460c95  c78178050000c0010000   -mov dword ptr [ecx + 0x578], 0x1c0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1400) /* 0x578 */) = 448 /*0x1c0*/;
    // 00460c9f  e935feffff             -jmp 0x460ad9
    goto L_0x00460ad9;
L_0x00460ca4:
    // 00460ca4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00460ca6  e835010000             -call 0x460de0
    cpu.esp -= 4;
    sub_460de0(app, cpu);
    if (cpu.terminate) return;
    // 00460cab  c7817805000000000000   -mov dword ptr [ecx + 0x578], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1400) /* 0x578 */) = 0 /*0x0*/;
L_0x00460cb5:
    // 00460cb5  8b9984010000           -mov ebx, dword ptr [ecx + 0x184]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(388) /* 0x184 */);
    // 00460cbb  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00460cbd  7412                   -je 0x460cd1
    if (cpu.flags.zf)
    {
        goto L_0x00460cd1;
    }
    // 00460cbf  83fb0e                 +cmp ebx, 0xe
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(14 /*0xe*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00460cc2  740d                   -je 0x460cd1
    if (cpu.flags.zf)
    {
        goto L_0x00460cd1;
    }
    // 00460cc4  83b97c01000000         +cmp dword ptr [ecx + 0x17c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(380) /* 0x17c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00460ccb  0f842afeffff           -je 0x460afb
    if (cpu.flags.zf)
    {
        goto L_0x00460afb;
    }
L_0x00460cd1:
    // 00460cd1  c78178050000c0010000   -mov dword ptr [ecx + 0x578], 0x1c0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1400) /* 0x578 */) = 448 /*0x1c0*/;
    // 00460cdb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460cdc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460cdd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460cde  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460cdf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_460ce0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00460ce0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00460ce1  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00460ce3  80b88c00000000         +cmp byte ptr [eax + 0x8c], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(140) /* 0x8c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00460cea  7402                   -je 0x460cee
    if (cpu.flags.zf)
    {
        goto L_0x00460cee;
    }
    // 00460cec  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460ced  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00460cee:
    // 00460cee  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00460cef  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00460cf0  8b91c4000000           -mov edx, dword ptr [ecx + 0xc4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(196) /* 0xc4 */);
    // 00460cf6  8b81a8000000           -mov eax, dword ptr [ecx + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(168) /* 0xa8 */);
    // 00460cfc  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00460cfe  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00460d01  c1e810                 +shr eax, 0x10
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
    // 00460d04  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00460d06  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00460d08  8b91c8000000           -mov edx, dword ptr [ecx + 0xc8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(200) /* 0xc8 */);
    // 00460d0e  8b81ac000000           -mov eax, dword ptr [ecx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(172) /* 0xac */);
    // 00460d14  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00460d16  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00460d19  c1e810                 +shr eax, 0x10
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
    // 00460d1c  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00460d1e  8b91cc000000           -mov edx, dword ptr [ecx + 0xcc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(204) /* 0xcc */);
    // 00460d24  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00460d26  8b81b0000000           -mov eax, dword ptr [ecx + 0xb0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(176) /* 0xb0 */);
    // 00460d2c  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00460d2e  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00460d31  c1e810                 +shr eax, 0x10
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
    // 00460d34  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00460d36  8b91d0000000           -mov edx, dword ptr [ecx + 0xd0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(208) /* 0xd0 */);
    // 00460d3c  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00460d3e  8b81a8000000           -mov eax, dword ptr [ecx + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(168) /* 0xa8 */);
    // 00460d44  8999b0020000           -mov dword ptr [ecx + 0x2b0], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(688) /* 0x2b0 */) = cpu.ebx;
    // 00460d4a  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00460d4c  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00460d4f  c1e810                 +shr eax, 0x10
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
    // 00460d52  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00460d54  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00460d56  8b91d4000000           -mov edx, dword ptr [ecx + 0xd4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(212) /* 0xd4 */);
    // 00460d5c  8b81ac000000           -mov eax, dword ptr [ecx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(172) /* 0xac */);
    // 00460d62  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00460d64  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00460d67  c1e810                 +shr eax, 0x10
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
    // 00460d6a  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00460d6c  8b91d8000000           -mov edx, dword ptr [ecx + 0xd8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(216) /* 0xd8 */);
    // 00460d72  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00460d74  8b81b0000000           -mov eax, dword ptr [ecx + 0xb0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(176) /* 0xb0 */);
    // 00460d7a  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00460d7c  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00460d7f  c1e810                 +shr eax, 0x10
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
    // 00460d82  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00460d84  8b91dc000000           -mov edx, dword ptr [ecx + 0xdc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(220) /* 0xdc */);
    // 00460d8a  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00460d8c  8b81a8000000           -mov eax, dword ptr [ecx + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(168) /* 0xa8 */);
    // 00460d92  8999b4020000           -mov dword ptr [ecx + 0x2b4], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(692) /* 0x2b4 */) = cpu.ebx;
    // 00460d98  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00460d9a  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00460d9d  c1e810                 +shr eax, 0x10
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
    // 00460da0  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00460da2  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00460da4  8b91e0000000           -mov edx, dword ptr [ecx + 0xe0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(224) /* 0xe0 */);
    // 00460daa  8b81ac000000           -mov eax, dword ptr [ecx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(172) /* 0xac */);
    // 00460db0  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00460db2  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00460db5  c1e810                 +shr eax, 0x10
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
    // 00460db8  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00460dba  8b91e4000000           -mov edx, dword ptr [ecx + 0xe4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(228) /* 0xe4 */);
    // 00460dc0  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00460dc2  8b81b0000000           -mov eax, dword ptr [ecx + 0xb0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(176) /* 0xb0 */);
    // 00460dc8  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00460dca  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00460dcd  c1e810                 +shr eax, 0x10
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
    // 00460dd0  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00460dd2  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00460dd4  8999b8020000           -mov dword ptr [ecx + 0x2b8], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(696) /* 0x2b8 */) = cpu.ebx;
    // 00460dda  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460ddb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460ddc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460ddd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_460de0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00460de0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00460de1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00460de2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00460de3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00460de4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00460de5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00460de7  c780a800000000000000   -mov dword ptr [eax + 0xa8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */) = 0 /*0x0*/;
    // 00460df1  c780ac00000000000000   -mov dword ptr [eax + 0xac], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */) = 0 /*0x0*/;
    // 00460dfb  c780b000000000000000   -mov dword ptr [eax + 0xb0], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(176) /* 0xb0 */) = 0 /*0x0*/;
    // 00460e05  8db83c010000           -lea edi, [eax + 0x13c]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(316) /* 0x13c */);
    // 00460e0b  c780e800000000000000   -mov dword ptr [eax + 0xe8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(232) /* 0xe8 */) = 0 /*0x0*/;
    // 00460e15  8db024010000           -lea esi, [eax + 0x124]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(292) /* 0x124 */);
    // 00460e1b  c780ec00000000000000   -mov dword ptr [eax + 0xec], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(236) /* 0xec */) = 0 /*0x0*/;
    // 00460e25  059c000000             -add eax, 0x9c
    (cpu.eax) += x86::reg32(x86::sreg32(156 /*0x9c*/));
    // 00460e2a  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00460e2c  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00460e2e  c7405400000000         -mov dword ptr [eax + 0x54], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */) = 0 /*0x0*/;
    // 00460e35  e8c6f8feff             -call 0x450700
    cpu.esp -= 4;
    sub_450700(app, cpu);
    if (cpu.terminate) return;
    // 00460e3a  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00460e3c  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00460e3e  8981a0000000           -mov dword ptr [ecx + 0xa0], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(160) /* 0xa0 */) = cpu.eax;
    // 00460e44  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00460e46  e835f6feff             -call 0x450480
    cpu.esp -= 4;
    sub_450480(app, cpu);
    if (cpu.terminate) return;
    // 00460e4b  89815c010000           -mov dword ptr [ecx + 0x15c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(348) /* 0x15c */) = cpu.eax;
    // 00460e51  8b91a0000000           -mov edx, dword ptr [ecx + 0xa0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(160) /* 0xa0 */);
    // 00460e57  c7815c01000000000000   -mov dword ptr [ecx + 0x15c], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(348) /* 0x15c */) = 0 /*0x0*/;
    // 00460e61  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00460e63  8991a0000000           -mov dword ptr [ecx + 0xa0], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(160) /* 0xa0 */) = cpu.edx;
    // 00460e69  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460e6a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460e6b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460e6c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460e6d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460e6e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_460e70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00460e70  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_460e80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00460e80  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00460e81  a1c4f74f00             -mov eax, dword ptr [0x4ff7c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5240772) /* 0x4ff7c4 */);
    // 00460e86  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00460e88  a328205000             -mov dword ptr [0x502028], eax
    app->getMemory<x86::reg32>(x86::reg32(5251112) /* 0x502028 */) = cpu.eax;
    // 00460e8d  891520205000           -mov dword ptr [0x502020], edx
    app->getMemory<x86::reg32>(x86::reg32(5251104) /* 0x502020 */) = cpu.edx;
    // 00460e93  891524205000           -mov dword ptr [0x502024], edx
    app->getMemory<x86::reg32>(x86::reg32(5251108) /* 0x502024 */) = cpu.edx;
    // 00460e99  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460e9a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_460ea0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00460ea0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00460ea1  a1c4f74f00             -mov eax, dword ptr [0x4ff7c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5240772) /* 0x4ff7c4 */);
    // 00460ea6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00460ea8  a328205000             -mov dword ptr [0x502028], eax
    app->getMemory<x86::reg32>(x86::reg32(5251112) /* 0x502028 */) = cpu.eax;
    // 00460ead  891520205000           -mov dword ptr [0x502020], edx
    app->getMemory<x86::reg32>(x86::reg32(5251104) /* 0x502020 */) = cpu.edx;
    // 00460eb3  891524205000           -mov dword ptr [0x502024], edx
    app->getMemory<x86::reg32>(x86::reg32(5251108) /* 0x502024 */) = cpu.edx;
    // 00460eb9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460eba  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_460ec0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00460ec0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00460ec1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00460ec2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00460ec3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00460ec4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00460ec5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00460ec6  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00460ec9  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00460ecd  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 00460ed2  a124205000             -mov eax, dword ptr [0x502024]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5251108) /* 0x502024 */);
    // 00460ed7  e8641b0100             -call 0x472a40
    cpu.esp -= 4;
    sub_472a40(app, cpu);
    if (cpu.terminate) return;
    // 00460edc  8b1524205000           -mov edx, dword ptr [0x502024]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5251108) /* 0x502024 */);
    // 00460ee2  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00460ee4  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00460ee6  7e53                   -jle 0x460f3b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00460f3b;
    }
    // 00460ee8  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00460eec  83c038                 -add eax, 0x38
    (cpu.eax) += x86::reg32(x86::sreg32(56 /*0x38*/));
    // 00460eef  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00460ef2  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00460ef6  83c044                 -add eax, 0x44
    (cpu.eax) += x86::reg32(x86::sreg32(68 /*0x44*/));
    // 00460ef9  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00460efd  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00460f01  be500e5000             -mov esi, 0x500e50
    cpu.esi = 5246544 /*0x500e50*/;
    // 00460f06  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00460f09  83c610                 -add esi, 0x10
    (cpu.esi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00460f0c  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
L_0x00460f10:
    // 00460f10  6bfd4c                 -imul edi, ebp, 0x4c
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(76 /*0x4c*/)));
    // 00460f13  bb00003200             -mov ebx, 0x320000
    cpu.ebx = 3276800 /*0x320000*/;
    // 00460f18  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00460f1c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00460f1e  e8edcdffff             -call 0x45dd10
    cpu.esp -= 4;
    sub_45dd10(app, cpu);
    if (cpu.terminate) return;
    // 00460f23  81c7500e5000           -add edi, 0x500e50
    (cpu.edi) += x86::reg32(x86::sreg32(5246544 /*0x500e50*/));
    // 00460f29  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00460f2b  7518                   -jne 0x460f45
    if (!cpu.flags.zf)
    {
        goto L_0x00460f45;
    }
L_0x00460f2d:
    // 00460f2d  8b0d24205000           -mov ecx, dword ptr [0x502024]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5251108) /* 0x502024 */);
    // 00460f33  45                     -inc ebp
    (cpu.ebp)++;
    // 00460f34  83c64c                 -add esi, 0x4c
    (cpu.esi) += x86::reg32(x86::sreg32(76 /*0x4c*/));
    // 00460f37  39cd                   +cmp ebp, ecx
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00460f39  7cd5                   -jl 0x460f10
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00460f10;
    }
L_0x00460f3b:
    // 00460f3b  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00460f3e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460f3f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460f40  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460f41  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460f42  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460f43  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00460f44  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00460f45:
    // 00460f45  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00460f4a  8d4728                 -lea eax, [edi + 0x28]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(40) /* 0x28 */);
    // 00460f4d  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00460f50  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00460f51  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00460f53  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00460f57  e8c4ea0000             -call 0x46fa20
    cpu.esp -= 4;
    sub_46fa20(app, cpu);
    if (cpu.terminate) return;
    // 00460f5c  803f00                 +cmp byte ptr [edi], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.edi);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00460f5f  74cc                   -je 0x460f2d
    if (cpu.flags.zf)
    {
        goto L_0x00460f2d;
    }
    // 00460f61  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00460f65  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00460f67  e8c8320100             -call 0x474234
    cpu.esp -= 4;
    sub_474234(app, cpu);
    if (cpu.terminate) return;
    // 00460f6c  ebbf                   -jmp 0x460f2d
    goto L_0x00460f2d;
}

/* align: skip 0x00 0x00 */
void Application::sub_460f70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00460f70  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00460f71  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00460f72  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00460f73  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00460f74  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00460f75  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00460f76  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00460f79  8b2d24205000           -mov ebp, dword ptr [0x502024]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5251108) /* 0x502024 */);
    // 00460f7f  8b1528205000           -mov edx, dword ptr [0x502028]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5251112) /* 0x502028 */);
    // 00460f85  a1c4f74f00             -mov eax, dword ptr [0x4ff7c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5240772) /* 0x4ff7c4 */);
    // 00460f8a  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00460f8c  83f803                 +cmp eax, 3
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
    // 00460f8f  0f8ea4000000           -jle 0x461039
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00461039;
    }
    // 00460f95  a1c4f74f00             -mov eax, dword ptr [0x4ff7c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5240772) /* 0x4ff7c4 */);
    // 00460f9a  a328205000             -mov dword ptr [0x502028], eax
    app->getMemory<x86::reg32>(x86::reg32(5251112) /* 0x502028 */) = cpu.eax;
    // 00460f9f  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00460fa1  0f85a2000000           -jne 0x461049
    if (!cpu.flags.zf)
    {
        goto L_0x00461049;
    }
L_0x00460fa7:
    // 00460fa7  8b2d24205000           -mov ebp, dword ptr [0x502024]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5251108) /* 0x502024 */);
    // 00460fad  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00460faf  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00460fb1  7e6b                   -jle 0x46101e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046101e;
    }
    // 00460fb3  ba500e5000             -mov edx, 0x500e50
    cpu.edx = 5246544 /*0x500e50*/;
L_0x00460fb8:
    // 00460fb8  8a6202                 -mov ah, byte ptr [edx + 2]
    cpu.ah = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 00460fbb  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00460fbd  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 00460fbf  0f840a010000           -je 0x4610cf
    if (cpu.flags.zf)
    {
        goto L_0x004610cf;
    }
    // 00460fc5  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 00460fc8  8b421c                 -mov eax, dword ptr [edx + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 00460fcb  8b7210                 -mov esi, dword ptr [edx + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 00460fce  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 00460fd0  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00460fd2  897210                 -mov dword ptr [edx + 0x10], esi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */) = cpu.esi;
    // 00460fd5  8b7c2404               -mov edi, dword ptr [esp + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00460fd9  8b4220                 -mov eax, dword ptr [edx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 00460fdc  8b7214                 -mov esi, dword ptr [edx + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 00460fdf  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 00460fe1  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00460fe3  897214                 -mov dword ptr [edx + 0x14], esi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = cpu.esi;
    // 00460fe6  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00460fea  8b4224                 -mov eax, dword ptr [edx + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */);
    // 00460fed  8b7218                 -mov esi, dword ptr [edx + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 00460ff0  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
L_0x00460ff2:
    // 00460ff2  01c6                   +add esi, eax
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
    // 00460ff4  892d24205000           -mov dword ptr [0x502024], ebp
    app->getMemory<x86::reg32>(x86::reg32(5251108) /* 0x502024 */) = cpu.ebp;
    // 00460ffa  897218                 -mov dword ptr [edx + 0x18], esi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 00460ffd  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00460fff  e84c020000             -call 0x461250
    cpu.esp -= 4;
    sub_461250(app, cpu);
    if (cpu.terminate) return;
    // 00461004  8b7904                 -mov edi, dword ptr [ecx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00461007  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00461008  897904                 -mov dword ptr [ecx + 4], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 0046100b  7503                   -jne 0x461010
    if (!cpu.flags.zf)
    {
        goto L_0x00461010;
    }
    // 0046100d  c60100                 -mov byte ptr [ecx], 0
    app->getMemory<x86::reg8>(cpu.ecx) = 0 /*0x0*/;
L_0x00461010:
    // 00461010  8b2d24205000           -mov ebp, dword ptr [0x502024]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5251108) /* 0x502024 */);
    // 00461016  43                     -inc ebx
    (cpu.ebx)++;
    // 00461017  83c24c                 -add edx, 0x4c
    (cpu.edx) += x86::reg32(x86::sreg32(76 /*0x4c*/));
    // 0046101a  39eb                   +cmp ebx, ebp
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
    // 0046101c  7c9a                   -jl 0x460fb8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00460fb8;
    }
L_0x0046101e:
    // 0046101e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00461020  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00461022  7e15                   -jle 0x461039
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00461039;
    }
L_0x00461024:
    // 00461024  6bf04c                 -imul esi, eax, 0x4c
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(76 /*0x4c*/)));
    // 00461027  80be500e500000         +cmp byte ptr [esi + 0x500e50], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(5246544) /* 0x500e50 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0046102e  0f84bc000000           -je 0x4610f0
    if (cpu.flags.zf)
    {
        goto L_0x004610f0;
    }
L_0x00461034:
    // 00461034  40                     -inc eax
    (cpu.eax)++;
    // 00461035  39e8                   +cmp eax, ebp
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
    // 00461037  7ceb                   -jl 0x461024
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00461024;
    }
L_0x00461039:
    // 00461039  892d24205000           -mov dword ptr [0x502024], ebp
    app->getMemory<x86::reg32>(x86::reg32(5251108) /* 0x502024 */) = cpu.ebp;
    // 0046103f  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00461042  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461043  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461044  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461045  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461046  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461047  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461048  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00461049:
    // 00461049  8b0d20205000           -mov ecx, dword ptr [0x502020]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5251104) /* 0x502020 */);
    // 0046104f  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00461052  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00461054  890d20205000           -mov dword ptr [0x502020], ecx
    app->getMemory<x86::reg32>(x86::reg32(5251104) /* 0x502020 */) = cpu.ecx;
    // 0046105a  8d8800010000           -lea ecx, [eax + 0x100]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(256) /* 0x100 */);
    // 00461060  c0e507                 +shl ch, 7
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
    // 00461063  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00461065  00ed                   +add ch, ch
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
    // 00461067  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 00461069  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046106b  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00461070  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00461072  8b048500ab4c00         -mov eax, dword ptr [eax*4 + 0x4cab00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5024512) /* 0x4cab00 */ + cpu.eax * 4);
    // 00461079  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046107b  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0046107d  bacc0c0000             -mov edx, 0xccc
    cpu.edx = 3276 /*0xccc*/;
    // 00461082  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00461084  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00461087  c1e810                 +shr eax, 0x10
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
    // 0046108a  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0046108c  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0046108f  a120205000             -mov eax, dword ptr [0x502020]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5251104) /* 0x502020 */);
    // 00461094  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00461096  c0e407                 +shl ah, 7
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
    // 00461099  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0046109b  00e4                   +add ah, ah
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
    // 0046109d  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 0046109f  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004610a1  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004610a6  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004610a8  8b048500ab4c00         -mov eax, dword ptr [eax*4 + 0x4cab00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5024512) /* 0x4cab00 */ + cpu.eax * 4);
    // 004610af  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004610b1  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004610b3  bacc0c0000             -mov edx, 0xccc
    cpu.edx = 3276 /*0xccc*/;
    // 004610b8  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004610bc  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004610be  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004610c1  c1e810                 +shr eax, 0x10
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
    // 004610c4  11d0                   +adc eax, edx
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004610c6  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004610ca  e9d8feffff             -jmp 0x460fa7
    goto L_0x00460fa7;
L_0x004610cf:
    // 004610cf  8b7210                 -mov esi, dword ptr [edx + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004610d2  8b421c                 -mov eax, dword ptr [edx + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 004610d5  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004610d7  897210                 -mov dword ptr [edx + 0x10], esi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */) = cpu.esi;
    // 004610da  8b7a14                 -mov edi, dword ptr [edx + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 004610dd  8b4220                 -mov eax, dword ptr [edx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 004610e0  8b7218                 -mov esi, dword ptr [edx + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 004610e3  01c7                   +add edi, eax
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
    // 004610e5  8b4224                 -mov eax, dword ptr [edx + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */);
    // 004610e8  897a14                 -mov dword ptr [edx + 0x14], edi
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = cpu.edi;
    // 004610eb  e902ffffff             -jmp 0x460ff2
    goto L_0x00460ff2;
L_0x004610f0:
    // 004610f0  8d55ff                 -lea edx, [ebp - 1]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-1) /* -0x1 */);
    // 004610f3  6bda4c                 +imul ebx, edx, 0x4c
    {
        x86::sreg64 tmp = x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(76 /*0x4c*/));
        cpu.ebx = static_cast<x86::reg32>(static_cast<x86::sreg32>(tmp));
        cpu.flags.of = cpu.flags.cf = (tmp != x86::sreg64(x86::sreg32(cpu.ebx)));
    }
    // 004610f6  b913000000             -mov ecx, 0x13
    cpu.ecx = 19 /*0x13*/;
    // 004610fb  8dbe500e5000           -lea edi, [esi + 0x500e50]
    cpu.edi = x86::reg32(cpu.esi + x86::reg32(5246544) /* 0x500e50 */);
    // 00461101  8db3500e5000           -lea esi, [ebx + 0x500e50]
    cpu.esi = x86::reg32(cpu.ebx + x86::reg32(5246544) /* 0x500e50 */);
    // 00461107  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00461108  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0046110a  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046110c  e923ffffff             -jmp 0x461034
    goto L_0x00461034;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_461144(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 00461144  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00461145  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00461146  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00461147  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00461148  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0046114b  8b2d24205000           -mov ebp, dword ptr [0x502024]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5251108) /* 0x502024 */);
    // 00461151  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00461153  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00461157  895c2410               -mov dword ptr [esp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
    // 0046115b  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046115d  83fd3c                 +cmp ebp, 0x3c
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(60 /*0x3c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00461160  0f85b3000000           -jne 0x461219
    if (!cpu.flags.zf)
    {
        goto L_0x00461219;
    }
    // 00461166  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0046116b  8b0d540e5000           -mov ecx, dword ptr [0x500e54]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5246548) /* 0x500e54 */);
    // 00461171  39c5                   +cmp ebp, eax
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
    // 00461173  7e1b                   -jle 0x461190
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00461190;
    }
    // 00461175  ba4c000000             -mov edx, 0x4c
    cpu.edx = 76 /*0x4c*/;
L_0x0046117a:
    // 0046117a  8bba540e5000           -mov edi, dword ptr [edx + 0x500e54]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5246548) /* 0x500e54 */);
    // 00461180  39f9                   +cmp ecx, edi
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
    // 00461182  7e04                   -jle 0x461188
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00461188;
    }
    // 00461184  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00461186  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x00461188:
    // 00461188  40                     -inc eax
    (cpu.eax)++;
    // 00461189  83c24c                 -add edx, 0x4c
    (cpu.edx) += x86::reg32(x86::sreg32(76 /*0x4c*/));
    // 0046118c  39e8                   +cmp eax, ebp
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
    // 0046118e  7cea                   -jl 0x46117a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046117a;
    }
L_0x00461190:
    // 00461190  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 00461197  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00461199  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046119c  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046119e  ba500e5000             -mov edx, 0x500e50
    cpu.edx = 5246544 /*0x500e50*/;
    // 004611a3  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004611a6  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004611a8  8d7a10                 -lea edi, [edx + 0x10]
    cpu.edi = x86::reg32(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004611ab  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004611ac  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004611ad  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004611ae  8a44240c               -mov al, byte ptr [esp + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004611b2  c7420400000000         -mov dword ptr [edx + 4], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004611b9  8802                   -mov byte ptr [edx], al
    app->getMemory<x86::reg8>(cpu.edx) = cpu.al;
    // 004611bb  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004611bf  885a01                 -mov byte ptr [edx + 1], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(1) /* 0x1 */) = cpu.bl;
    // 004611c2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004611c4  7513                   -jne 0x4611d9
    if (!cpu.flags.zf)
    {
        goto L_0x004611d9;
    }
    // 004611c6  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004611c8  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004611ca  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004611ce  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004611d1  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004611d5  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
L_0x004611d9:
    // 004611d9  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004611dd  48                     -dec eax
    (cpu.eax)--;
    // 004611de  892d24205000           -mov dword ptr [0x502024], ebp
    app->getMemory<x86::reg32>(x86::reg32(5251108) /* 0x502024 */) = cpu.ebp;
    // 004611e4  83f808                 +cmp eax, 8
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
    // 004611e7  7719                   -ja 0x461202
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00461202;
    }
    // 004611e9  ff248520114600         -jmp dword ptr [eax*4 + 0x461120]
    cpu.ip = app->getMemory<x86::reg32>(4591904 + cpu.eax * 4); goto dynamic_jump;
  case 0x004611f0:
    // 004611f0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004611f2  e8b9000000             -call 0x4612b0
    cpu.esp -= 4;
    sub_4612b0(app, cpu);
    if (cpu.terminate) return;
    // 004611f7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004611f9  c6420201               -mov byte ptr [edx + 2], 1
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */) = 1 /*0x1*/;
L_0x004611fd:
    // 004611fd  e88e000000             -call 0x461290
    cpu.esp -= 4;
    sub_461290(app, cpu);
    if (cpu.terminate) return;
L_0x00461202:
    // 00461202  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00461204  e8bb2f0100             -call 0x4741c4
    cpu.esp -= 4;
    sub_4741c4(app, cpu);
    if (cpu.terminate) return;
    // 00461209  8b2d24205000           -mov ebp, dword ptr [0x502024]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5251108) /* 0x502024 */);
    // 0046120f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00461211  83c414                 +add esp, 0x14
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
    // 00461214  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461215  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461216  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461217  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461218  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00461219:
    // 00461219  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0046121b  45                     +inc ebp
    {
        x86::reg32& tmp = cpu.ebp;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 0046121c  e96fffffff             -jmp 0x461190
    goto L_0x00461190;
  case 0x00461221:
    // 00461221  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00461225  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00461227  c1f805                 -sar eax, 5
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (5 /*0x5*/ % 32));
    // 0046122a  89421c                 -mov dword ptr [edx + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0046122d  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00461231  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00461234  c1f805                 -sar eax, 5
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (5 /*0x5*/ % 32));
    // 00461237  894220                 -mov dword ptr [edx + 0x20], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0046123a  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046123e  8b4008                 -mov eax, dword ptr [eax + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00461241  c1f805                 +sar eax, 5
    {
        x86::reg8 tmp = 5 /*0x5*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 00461244  894224                 -mov dword ptr [edx + 0x24], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 00461247  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00461249  c6420200               -mov byte ptr [edx + 2], 0
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(2) /* 0x2 */) = 0 /*0x0*/;
    // 0046124d  ebae                   -jmp 0x4611fd
    goto L_0x004611fd;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x00 */
void Application::sub_461250(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00461250  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00461251  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00461252  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00461253  8b4808                 -mov ecx, dword ptr [eax + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 00461256  03480c                 -add ecx, dword ptr [eax + 0xc]
    (cpu.ecx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */)));
    // 00461259  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0046125c  894808                 -mov dword ptr [eax + 8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0046125f  83fbfd                 +cmp ebx, -3
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-3 /*-0x3*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00461262  7c09                   -jl 0x46126d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046126d;
    }
    // 00461264  83fb03                 +cmp ebx, 3
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
    // 00461267  7f0e                   -jg 0x461277
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00461277;
    }
    // 00461269  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046126a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046126b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046126c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046126d:
    // 0046126d  8d6b01                 -lea ebp, [ebx + 1]
    cpu.ebp = x86::reg32(cpu.ebx + x86::reg32(1) /* 0x1 */);
    // 00461270  89680c                 -mov dword ptr [eax + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 00461273  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461274  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461275  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461276  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00461277:
    // 00461277  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00461278  8d7bff                 -lea edi, [ebx - 1]
    cpu.edi = x86::reg32(cpu.ebx + x86::reg32(-1) /* -0x1 */);
    // 0046127b  89780c                 -mov dword ptr [eax + 0xc], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 0046127e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046127f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461280  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461281  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461282  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_461290(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00461290  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00461291  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00461293  e898d50100             -call 0x47e830
    cpu.esp -= 4;
    sub_47e830(app, cpu);
    if (cpu.terminate) return;
    // 00461298  894208                 -mov dword ptr [edx + 8], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0046129b  e890d50100             -call 0x47e830
    cpu.esp -= 4;
    sub_47e830(app, cpu);
    if (cpu.terminate) return;
    // 004612a0  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 004612a3  83e83f                 -sub eax, 0x3f
    (cpu.eax) -= x86::reg32(x86::sreg32(63 /*0x3f*/));
    // 004612a6  89420c                 -mov dword ptr [edx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004612a9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004612aa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4612b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004612b0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004612b1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004612b3  e878d50100             -call 0x47e830
    cpu.esp -= 4;
    sub_47e830(app, cpu);
    if (cpu.terminate) return;
    // 004612b8  25ff030000             -and eax, 0x3ff
    cpu.eax &= x86::reg32(x86::sreg32(1023 /*0x3ff*/));
    // 004612bd  89421c                 -mov dword ptr [edx + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004612c0  e86bd50100             -call 0x47e830
    cpu.esp -= 4;
    sub_47e830(app, cpu);
    if (cpu.terminate) return;
    // 004612c5  25ff030000             -and eax, 0x3ff
    cpu.eax &= x86::reg32(x86::sreg32(1023 /*0x3ff*/));
    // 004612ca  894224                 -mov dword ptr [edx + 0x24], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 004612cd  e85ed50100             -call 0x47e830
    cpu.esp -= 4;
    sub_47e830(app, cpu);
    if (cpu.terminate) return;
    // 004612d2  25ff030000             -and eax, 0x3ff
    cpu.eax &= x86::reg32(x86::sreg32(1023 /*0x3ff*/));
    // 004612d7  05ff070000             -add eax, 0x7ff
    (cpu.eax) += x86::reg32(x86::sreg32(2047 /*0x7ff*/));
    // 004612dc  894220                 -mov dword ptr [edx + 0x20], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 004612df  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004612e0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4612f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004612f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004612f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004612f2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004612f3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004612f4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004612f5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004612f6  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004612f9  8b15a4f74f00           -mov edx, dword ptr [0x4ff7a4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5240740) /* 0x4ff7a4 */);
    // 004612ff  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00461301  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00461303  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00461305  0f8565000000           -jne 0x461370
    if (!cpu.flags.zf)
    {
        goto L_0x00461370;
    }
    // 0046130b  833da0f14d0000         +cmp dword ptr [0x4df1a0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5108128) /* 0x4df1a0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00461312  7e4d                   -jle 0x461361
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00461361;
    }
    // 00461314  8b15a0f14d00           -mov edx, dword ptr [0x4df1a0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5108128) /* 0x4df1a0 */);
    // 0046131a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046131c  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0046131e  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00461320  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
L_0x00461323:
    // 00461323  8b9128f04d00           -mov edx, dword ptr [ecx + 0x4df028]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5107752) /* 0x4df028 */);
    // 00461329  8bba1c020000           -mov edi, dword ptr [edx + 0x21c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(540) /* 0x21c */);
    // 0046132f  833f24                 +cmp dword ptr [edi], 0x24
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(36 /*0x24*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00461332  745b                   -je 0x46138f
    if (cpu.flags.zf)
    {
        goto L_0x0046138f;
    }
    // 00461334  83ba8002000002         +cmp dword ptr [edx + 0x280], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(640) /* 0x280 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046133b  753d                   -jne 0x46137a
    if (!cpu.flags.zf)
    {
        goto L_0x0046137a;
    }
    // 0046133d  8b9224020000           -mov edx, dword ptr [edx + 0x224]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(548) /* 0x224 */);
    // 00461343  8b2dc4f74f00           -mov ebp, dword ptr [0x4ff7c4]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5240772) /* 0x4ff7c4 */);
    // 00461349  81c240010000           -add edx, 0x140
    (cpu.edx) += x86::reg32(x86::sreg32(320 /*0x140*/));
    // 0046134f  39ea                   +cmp edx, ebp
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
    // 00461351  7d27                   -jge 0x46137a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0046137a;
    }
L_0x00461353:
    // 00461353  43                     -inc ebx
    (cpu.ebx)++;
L_0x00461354:
    // 00461354  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 00461357  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0046135a  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0046135d  39f8                   +cmp eax, edi
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
    // 0046135f  7cc2                   -jl 0x461323
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00461323;
    }
L_0x00461361:
    // 00461361  a1a0f14d00             -mov eax, dword ptr [0x4df1a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5108128) /* 0x4df1a0 */);
    // 00461366  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 00461368  39c3                   +cmp ebx, eax
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
    // 0046136a  7504                   -jne 0x461370
    if (!cpu.flags.zf)
    {
        goto L_0x00461370;
    }
    // 0046136c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0046136e  7f22                   -jg 0x461392
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00461392;
    }
L_0x00461370:
    // 00461370  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00461373  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461374  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461375  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461376  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461377  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461378  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461379  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046137a:
    // 0046137a  833d28f54d0004         +cmp dword ptr [0x4df528], 4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5109032) /* 0x4df528 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00461381  75d1                   -jne 0x461354
    if (!cpu.flags.zf)
    {
        goto L_0x00461354;
    }
    // 00461383  6683b868074e0000       +cmp word ptr [eax + 0x4e0768], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(5113704) /* 0x4e0768 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0046138b  75c6                   -jne 0x461353
    if (!cpu.flags.zf)
    {
        goto L_0x00461353;
    }
    // 0046138d  ebc5                   -jmp 0x461354
    goto L_0x00461354;
L_0x0046138f:
    // 0046138f  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00461390  ebc2                   -jmp 0x461354
    goto L_0x00461354;
L_0x00461392:
    // 00461392  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 00461397  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0046139c  892da4f74f00           -mov dword ptr [0x4ff7a4], ebp
    app->getMemory<x86::reg32>(x86::reg32(5240740) /* 0x4ff7a4 */) = cpu.ebp;
    // 004613a2  e819000000             -call 0x4613c0
    cpu.esp -= 4;
    sub_4613c0(app, cpu);
    if (cpu.terminate) return;
    // 004613a7  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004613aa  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004613ab  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004613ac  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004613ad  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004613ae  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004613af  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004613b0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4613c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004613c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004613c1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004613c2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004613c3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004613c4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004613c5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004613c6  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004613c9  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004613cb  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004613d0  8b0da0f14d00           -mov ecx, dword ptr [0x4df1a0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5108128) /* 0x4df1a0 */);
    // 004613d6  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004613d8  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004613db  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004613dd  0f8e7b000000           -jle 0x46145e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046145e;
    }
    // 004613e3  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004613e5:
    // 004613e5  8b1510ec4d00           -mov edx, dword ptr [0x4dec10]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5106704) /* 0x4dec10 */);
    // 004613eb  0faf151cf54d00         -imul edx, dword ptr [0x4df51c]
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5109020) /* 0x4df51c */))));
    // 004613f2  8b9928f04d00           -mov ebx, dword ptr [ecx + 0x4df028]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5107752) /* 0x4df028 */);
    // 004613f8  8b831c020000           -mov eax, dword ptr [ebx + 0x21c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(540) /* 0x21c */);
    // 004613fe  833824                 +cmp dword ptr [eax], 0x24
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(36 /*0x24*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00461401  0f85ec000000           -jne 0x4614f3
    if (!cpu.flags.zf)
    {
        goto L_0x004614f3;
    }
    // 00461407  8bab20020000           -mov ebp, dword ptr [ebx + 0x220]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(544) /* 0x220 */);
    // 0046140d  39ea                   +cmp edx, ebp
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
    // 0046140f  7e16                   -jle 0x461427
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00461427;
    }
    // 00461411  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00461413  0f85c0000000           -jne 0x4614d9
    if (!cpu.flags.zf)
    {
        goto L_0x004614d9;
    }
    // 00461419  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0046141b:
    // 0046141b  8b9128f04d00           -mov edx, dword ptr [ecx + 0x4df028]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5107752) /* 0x4df028 */);
    // 00461421  898234020000           -mov dword ptr [edx + 0x234], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(564) /* 0x234 */) = cpu.eax;
L_0x00461427:
    // 00461427  8b8128f04d00           -mov eax, dword ptr [ecx + 0x4df028]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5107752) /* 0x4df028 */);
    // 0046142d  89b880020000           -mov dword ptr [eax + 0x280], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(640) /* 0x280 */) = cpu.edi;
L_0x00461433:
    // 00461433  83ff01                 +cmp edi, 1
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
    // 00461436  7518                   -jne 0x461450
    if (!cpu.flags.zf)
    {
        goto L_0x00461450;
    }
    // 00461438  3b3d18f54d00           +cmp edi, dword ptr [0x4df518]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5109016) /* 0x4df518 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046143e  0f8418010000           -je 0x46155c
    if (cpu.flags.zf)
    {
        goto L_0x0046155c;
    }
    // 00461444  8b8128f04d00           -mov eax, dword ptr [ecx + 0x4df028]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5107752) /* 0x4df028 */);
L_0x0046144a:
    // 0046144a  89b880020000           -mov dword ptr [eax + 0x280], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(640) /* 0x280 */) = cpu.edi;
L_0x00461450:
    // 00461450  8b1da0f14d00           -mov ebx, dword ptr [0x4df1a0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5108128) /* 0x4df1a0 */);
    // 00461456  46                     -inc esi
    (cpu.esi)++;
    // 00461457  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0046145a  39de                   +cmp esi, ebx
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046145c  7c87                   -jl 0x4613e5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004613e5;
    }
L_0x0046145e:
    // 0046145e  8b2d90f14d00           -mov ebp, dword ptr [0x4df190]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5108112) /* 0x4df190 */);
    // 00461464  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00461466  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00461468  7e65                   -jle 0x4614cf
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004614cf;
    }
    // 0046146a  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x0046146c:
    // 0046146c  8b99e8ee4d00           -mov ebx, dword ptr [ecx + 0x4deee8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5107432) /* 0x4deee8 */);
    // 00461472  83bb8002000002         +cmp dword ptr [ebx + 0x280], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(640) /* 0x280 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00461479  7435                   -je 0x4614b0
    if (cpu.flags.zf)
    {
        goto L_0x004614b0;
    }
    // 0046147b  83bb2002000000         +cmp dword ptr [ebx + 0x220], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(544) /* 0x220 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00461482  0f85f8000000           -jne 0x461580
    if (!cpu.flags.zf)
    {
        goto L_0x00461580;
    }
    // 00461488  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0046148a:
    // 0046148a  8b91e8ee4d00           -mov edx, dword ptr [ecx + 0x4deee8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5107432) /* 0x4deee8 */);
    // 00461490  898234020000           -mov dword ptr [edx + 0x234], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(564) /* 0x234 */) = cpu.eax;
    // 00461496  833c2400               +cmp dword ptr [esp], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046149a  0f840d010000           -je 0x4615ad
    if (cpu.flags.zf)
    {
        goto L_0x004615ad;
    }
    // 004614a0  8b81e8ee4d00           -mov eax, dword ptr [ecx + 0x4deee8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5107432) /* 0x4deee8 */);
    // 004614a6  c7808002000002000000   -mov dword ptr [eax + 0x280], 2
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(640) /* 0x280 */) = 2 /*0x2*/;
L_0x004614b0:
    // 004614b0  83ff01                 +cmp edi, 1
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
    // 004614b3  750c                   -jne 0x4614c1
    if (!cpu.flags.zf)
    {
        goto L_0x004614c1;
    }
    // 004614b5  8b81e8ee4d00           -mov eax, dword ptr [ecx + 0x4deee8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5107432) /* 0x4deee8 */);
    // 004614bb  89b880020000           -mov dword ptr [eax + 0x280], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(640) /* 0x280 */) = cpu.edi;
L_0x004614c1:
    // 004614c1  8b2d90f14d00           -mov ebp, dword ptr [0x4df190]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5108112) /* 0x4df190 */);
    // 004614c7  46                     -inc esi
    (cpu.esi)++;
    // 004614c8  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004614cb  39ee                   +cmp esi, ebp
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
    // 004614cd  7c9d                   -jl 0x46146c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046146c;
    }
L_0x004614cf:
    // 004614cf  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004614d2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004614d3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004614d4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004614d5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004614d6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004614d7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004614d8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004614d9:
    // 004614d9  8b8324020000           -mov eax, dword ptr [ebx + 0x224]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(548) /* 0x224 */);
    // 004614df  2d00020000             -sub eax, 0x200
    (cpu.eax) -= x86::reg32(x86::sreg32(512 /*0x200*/));
    // 004614e4  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 004614e7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004614e9  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004614ec  f7fd                   +idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004614ee  e928ffffff             -jmp 0x46141b
    goto L_0x0046141b;
L_0x004614f3:
    // 004614f3  83bb8002000002         +cmp dword ptr [ebx + 0x280], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(640) /* 0x280 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004614fa  0f8433ffffff           -je 0x461433
    if (cpu.flags.zf)
    {
        goto L_0x00461433;
    }
    // 00461500  8bab20020000           -mov ebp, dword ptr [ebx + 0x220]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(544) /* 0x220 */);
    // 00461506  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00461508  7531                   -jne 0x46153b
    if (!cpu.flags.zf)
    {
        goto L_0x0046153b;
    }
    // 0046150a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0046150c:
    // 0046150c  8b9128f04d00           -mov edx, dword ptr [ecx + 0x4df028]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5107752) /* 0x4df028 */);
    // 00461512  898234020000           -mov dword ptr [edx + 0x234], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(564) /* 0x234 */) = cpu.eax;
    // 00461518  833d18f54d0001         +cmp dword ptr [0x4df518], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5109016) /* 0x4df518 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046151f  7431                   -je 0x461552
    if (cpu.flags.zf)
    {
        goto L_0x00461552;
    }
L_0x00461521:
    // 00461521  8b8128f04d00           -mov eax, dword ptr [ecx + 0x4df028]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5107752) /* 0x4df028 */);
    // 00461527  c7808002000001000000   -mov dword ptr [eax + 0x280], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(640) /* 0x280 */) = 1 /*0x1*/;
L_0x00461531:
    // 00461531  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00461533  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 00461536  e9f8feffff             -jmp 0x461433
    goto L_0x00461433;
L_0x0046153b:
    // 0046153b  8b8324020000           -mov eax, dword ptr [ebx + 0x224]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(548) /* 0x224 */);
    // 00461541  2d00020000             -sub eax, 0x200
    (cpu.eax) -= x86::reg32(x86::sreg32(512 /*0x200*/));
    // 00461546  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 00461549  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046154b  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0046154e  f7fd                   +idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00461550  ebba                   -jmp 0x46150c
    goto L_0x0046150c;
L_0x00461552:
    // 00461552  3b352cf54d00           +cmp esi, dword ptr [0x4df52c]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5109036) /* 0x4df52c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00461558  75d7                   -jne 0x461531
    if (!cpu.flags.zf)
    {
        goto L_0x00461531;
    }
    // 0046155a  ebc5                   -jmp 0x461521
    goto L_0x00461521;
L_0x0046155c:
    // 0046155c  8b8128f04d00           -mov eax, dword ptr [ecx + 0x4df028]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5107752) /* 0x4df028 */);
    // 00461562  83b88002000002         +cmp dword ptr [eax + 0x280], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(640) /* 0x280 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00461569  0f84e1feffff           -je 0x461450
    if (cpu.flags.zf)
    {
        goto L_0x00461450;
    }
    // 0046156f  3b352cf54d00           +cmp esi, dword ptr [0x4df52c]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5109036) /* 0x4df52c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00461575  0f85d5feffff           -jne 0x461450
    if (!cpu.flags.zf)
    {
        goto L_0x00461450;
    }
    // 0046157b  e9cafeffff             -jmp 0x46144a
    goto L_0x0046144a;
L_0x00461580:
    // 00461580  8b1510ec4d00           -mov edx, dword ptr [0x4dec10]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5106704) /* 0x4dec10 */);
    // 00461586  0faf151cf54d00         -imul edx, dword ptr [0x4df51c]
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5109020) /* 0x4df51c */))));
    // 0046158d  8b8324020000           -mov eax, dword ptr [ebx + 0x224]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(548) /* 0x224 */);
    // 00461593  2d00020000             -sub eax, 0x200
    (cpu.eax) -= x86::reg32(x86::sreg32(512 /*0x200*/));
    // 00461598  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0046159b  8bab20020000           -mov ebp, dword ptr [ebx + 0x220]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(544) /* 0x220 */);
    // 004615a1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004615a3  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004615a6  f7fd                   +idiv ebp
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebp);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004615a8  e9ddfeffff             -jmp 0x46148a
    goto L_0x0046148a;
L_0x004615ad:
    // 004615ad  8b81e8ee4d00           -mov eax, dword ptr [ecx + 0x4deee8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5107432) /* 0x4deee8 */);
    // 004615b3  89b880020000           -mov dword ptr [eax + 0x280], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(640) /* 0x280 */) = cpu.edi;
    // 004615b9  e9f2feffff             -jmp 0x4614b0
    goto L_0x004614b0;
}

/* align: skip 0x00 0x00 */
void Application::sub_4615c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004615c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004615c1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004615c2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004615c3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004615c4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004615c5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004615c6  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004615c9  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004615cb  8b9030020000           -mov edx, dword ptr [eax + 0x230]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(560) /* 0x230 */);
    // 004615d1  83fa08                 +cmp edx, 8
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004615d4  7d73                   -jge 0x461649
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00461649;
    }
    // 004615d6  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004615dd  8d1428                 -lea edx, [eax + ebp]
    cpu.edx = x86::reg32(cpu.eax + cpu.ebp * 1);
    // 004615e0  8b85b8020000           -mov eax, dword ptr [ebp + 0x2b8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(696) /* 0x2b8 */);
    // 004615e6  3b8258020000           +cmp eax, dword ptr [edx + 0x258]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(600) /* 0x258 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004615ec  7e5b                   -jle 0x461649
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00461649;
    }
    // 004615ee  f685f401000008         +test byte ptr [ebp + 0x1f4], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(500) /* 0x1f4 */) & 8 /*0x8*/));
    // 004615f5  0f8494020000           -je 0x46188f
    if (cpu.flags.zf)
    {
        goto L_0x0046188f;
    }
    // 004615fb  8b851c020000           -mov eax, dword ptr [ebp + 0x21c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(540) /* 0x21c */);
    // 00461601  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 00461603  83fb0f                 +cmp ebx, 0xf
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
    // 00461606  0f8d83020000           -jge 0x46188f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0046188f;
    }
    // 0046160c  833d28f54d0002         +cmp dword ptr [0x4df528], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5109032) /* 0x4df528 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00461613  0f8c2c020000           -jl 0x461845
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00461845;
    }
    // 00461619  6985e801000099190000   -imul eax, dword ptr [ebp + 0x1e8], 0x1999
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(488) /* 0x1e8 */))) * x86::sreg64(x86::sreg32(6553 /*0x1999*/)));
    // 00461623  8b149dcc544c00         -mov edx, dword ptr [ebx*4 + 0x4c54cc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5002444) /* 0x4c54cc */ + cpu.ebx * 4);
    // 0046162a  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0046162c  8b9db8020000           -mov ebx, dword ptr [ebp + 0x2b8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(696) /* 0x2b8 */);
    // 00461632  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00461634  39da                   +cmp edx, ebx
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
    // 00461636  0f8d02020000           -jge 0x46183e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0046183e;
    }
L_0x0046163c:
    // 0046163c  8b9530020000           -mov edx, dword ptr [ebp + 0x230]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(560) /* 0x230 */);
    // 00461642  89849558020000         -mov dword ptr [ebp + edx*4 + 0x258], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(600) /* 0x258 */ + cpu.edx * 4) = cpu.eax;
L_0x00461649:
    // 00461649  8bb5f8010000           -mov esi, dword ptr [ebp + 0x1f8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(504) /* 0x1f8 */);
    // 0046164f  3bb530020000           +cmp esi, dword ptr [ebp + 0x230]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(560) /* 0x230 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00461655  0f8491000000           -je 0x4616ec
    if (cpu.flags.zf)
    {
        goto L_0x004616ec;
    }
    // 0046165b  83bd8002000002         +cmp dword ptr [ebp + 0x280], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(640) /* 0x280 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00461662  0f8484000000           -je 0x4616ec
    if (cpu.flags.zf)
    {
        goto L_0x004616ec;
    }
    // 00461668  a1c4f74f00             -mov eax, dword ptr [0x4ff7c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5240772) /* 0x4ff7c4 */);
    // 0046166d  8b9534020000           -mov edx, dword ptr [ebp + 0x234]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(564) /* 0x234 */);
    // 00461673  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00461675  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00461677  8b8530020000           -mov eax, dword ptr [ebp + 0x230]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(560) /* 0x230 */);
    // 0046167d  89948538020000         -mov dword ptr [ebp + eax*4 + 0x238], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(568) /* 0x238 */ + cpu.eax * 4) = cpu.edx;
    // 00461684  a1c4f74f00             -mov eax, dword ptr [0x4ff7c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5240772) /* 0x4ff7c4 */);
    // 00461689  898534020000           -mov dword ptr [ebp + 0x234], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(564) /* 0x234 */) = cpu.eax;
    // 0046168f  8b85f8010000           -mov eax, dword ptr [ebp + 0x1f8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(504) /* 0x1f8 */);
    // 00461695  8b0d1cf54d00           -mov ecx, dword ptr [0x4df51c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5109020) /* 0x4df51c */);
    // 0046169b  898530020000           -mov dword ptr [ebp + 0x230], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(560) /* 0x230 */) = cpu.eax;
    // 004616a1  39c8                   +cmp eax, ecx
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
    // 004616a3  7547                   -jne 0x4616ec
    if (!cpu.flags.zf)
    {
        goto L_0x004616ec;
    }
    // 004616a5  8b851c020000           -mov eax, dword ptr [ebp + 0x21c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(540) /* 0x21c */);
    // 004616ab  833824                 +cmp dword ptr [eax], 0x24
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(36 /*0x24*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004616ae  743c                   -je 0x4616ec
    if (cpu.flags.zf)
    {
        goto L_0x004616ec;
    }
    // 004616b0  8b9530020000           -mov edx, dword ptr [ebp + 0x230]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(560) /* 0x230 */);
    // 004616b6  a1c4f74f00             -mov eax, dword ptr [0x4ff7c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5240772) /* 0x4ff7c4 */);
    // 004616bb  42                     -inc edx
    (cpu.edx)++;
    // 004616bc  898524020000           -mov dword ptr [ebp + 0x224], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(548) /* 0x224 */) = cpu.eax;
    // 004616c2  a110ec4d00             -mov eax, dword ptr [0x4dec10]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5106704) /* 0x4dec10 */);
    // 004616c7  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 004616ca  8bb534020000           -mov esi, dword ptr [ebp + 0x234]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(564) /* 0x234 */);
    // 004616d0  c7858002000002000000   -mov dword ptr [ebp + 0x280], 2
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(640) /* 0x280 */) = 2 /*0x2*/;
    // 004616da  81ee00020000           -sub esi, 0x200
    (cpu.esi) -= x86::reg32(x86::sreg32(512 /*0x200*/));
    // 004616e0  89b534020000           -mov dword ptr [ebp + 0x234], esi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(564) /* 0x234 */) = cpu.esi;
    // 004616e6  899520020000           -mov dword ptr [ebp + 0x220], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(544) /* 0x220 */) = cpu.edx;
L_0x004616ec:
    // 004616ec  8b7d14                 -mov edi, dword ptr [ebp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004616ef  3bbd28020000           +cmp edi, dword ptr [ebp + 0x228]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(552) /* 0x228 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004616f5  7455                   -je 0x46174c
    if (cpu.flags.zf)
    {
        goto L_0x0046174c;
    }
    // 004616f7  8b8580020000           -mov eax, dword ptr [ebp + 0x280]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(640) /* 0x280 */);
    // 004616fd  89bd28020000           -mov dword ptr [ebp + 0x228], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(552) /* 0x228 */) = cpu.edi;
    // 00461703  83f802                 +cmp eax, 2
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
    // 00461706  7444                   -je 0x46174c
    if (cpu.flags.zf)
    {
        goto L_0x0046174c;
    }
    // 00461708  a1c4f74f00             -mov eax, dword ptr [0x4ff7c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5240772) /* 0x4ff7c4 */);
    // 0046170d  8b1548f54d00           -mov edx, dword ptr [0x4df548]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5109064) /* 0x4df548 */);
    // 00461713  898524020000           -mov dword ptr [ebp + 0x224], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(548) /* 0x224 */) = cpu.eax;
    // 00461719  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0046171b  0f848b010000           -je 0x4618ac
    if (cpu.flags.zf)
    {
        goto L_0x004618ac;
    }
    // 00461721  8b1510ec4d00           -mov edx, dword ptr [0x4dec10]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5106704) /* 0x4dec10 */);
    // 00461727  2b9528020000           -sub edx, dword ptr [ebp + 0x228]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(552) /* 0x228 */)));
L_0x0046172d:
    // 0046172d  8b9dfc010000           -mov ebx, dword ptr [ebp + 0x1fc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(508) /* 0x1fc */);
    // 00461733  8b8530020000           -mov eax, dword ptr [ebp + 0x230]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(560) /* 0x230 */);
    // 00461739  8b3510ec4d00           -mov esi, dword ptr [0x4dec10]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5106704) /* 0x4dec10 */);
    // 0046173f  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00461741  0fafc6                 -imul eax, esi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 00461744  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00461746  898520020000           -mov dword ptr [ebp + 0x220], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(544) /* 0x220 */) = cpu.eax;
L_0x0046174c:
    // 0046174c  8b851c020000           -mov eax, dword ptr [ebp + 0x21c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(540) /* 0x21c */);
    // 00461752  833824                 +cmp dword ptr [eax], 0x24
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(36 /*0x24*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00461755  0f84d9000000           -je 0x461834
    if (cpu.flags.zf)
    {
        goto L_0x00461834;
    }
    // 0046175b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046175d  8b15a4f14d00           -mov edx, dword ptr [0x4df1a4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5108132) /* 0x4df1a4 */);
    // 00461763  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00461767  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00461769  0f8ec5000000           -jle 0x461834
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00461834;
    }
    // 0046176f  8d42fe                 -lea eax, [edx - 2]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(-2) /* -0x2 */);
    // 00461772  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
L_0x00461775:
    // 00461775  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00461779  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0046177c  8b9520020000           -mov edx, dword ptr [ebp + 0x220]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(544) /* 0x220 */);
    // 00461782  8bb030205000           -mov esi, dword ptr [eax + 0x502030]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5251120) /* 0x502030 */);
    // 00461788  39f2                   +cmp edx, esi
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
    // 0046178a  0f8e27010000           -jle 0x4618b7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004618b7;
    }
L_0x00461790:
    // 00461790  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00461793  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00461797  39d8                   +cmp eax, ebx
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
    // 00461799  7c3f                   -jl 0x4617da
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004617da;
    }
    // 0046179b  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 0046179d  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004617a0  c1e704                 -shl edi, 4
    cpu.edi <<= 4 /*0x4*/ % 32;
L_0x004617a3:
    // 004617a3  83e810                 -sub eax, 0x10
    (cpu.eax) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004617a6  8bb03c205000           -mov esi, dword ptr [eax + 0x50203c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5251132) /* 0x50203c */);
    // 004617ac  8b9040205000           -mov edx, dword ptr [eax + 0x502040]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5251136) /* 0x502040 */);
    // 004617b2  89b04c205000           -mov dword ptr [eax + 0x50204c], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5251148) /* 0x50204c */) = cpu.esi;
    // 004617b8  899050205000           -mov dword ptr [eax + 0x502050], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5251152) /* 0x502050 */) = cpu.edx;
    // 004617be  8b9844205000           -mov ebx, dword ptr [eax + 0x502044]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5251140) /* 0x502044 */);
    // 004617c4  8b8848205000           -mov ecx, dword ptr [eax + 0x502048]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5251144) /* 0x502048 */);
    // 004617ca  899854205000           -mov dword ptr [eax + 0x502054], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5251156) /* 0x502054 */) = cpu.ebx;
    // 004617d0  898858205000           -mov dword ptr [eax + 0x502058], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5251160) /* 0x502058 */) = cpu.ecx;
    // 004617d6  39f8                   +cmp eax, edi
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
    // 004617d8  7dc9                   -jge 0x4617a3
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004617a3;
    }
L_0x004617da:
    // 004617da  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004617de  8b9520020000           -mov edx, dword ptr [ebp + 0x220]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(544) /* 0x220 */);
    // 004617e4  8b8d24020000           -mov ecx, dword ptr [ebp + 0x224]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(548) /* 0x224 */);
    // 004617ea  8bb5e8010000           -mov esi, dword ptr [ebp + 0x1e8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(488) /* 0x1e8 */);
    // 004617f0  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004617f3  8b9df4010000           -mov ebx, dword ptr [ebp + 0x1f4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(500) /* 0x1f4 */);
    // 004617f9  89b02c205000           -mov dword ptr [eax + 0x50202c], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5251116) /* 0x50202c */) = cpu.esi;
    // 004617ff  899030205000           -mov dword ptr [eax + 0x502030], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5251120) /* 0x502030 */) = cpu.edx;
    // 00461805  83e304                 -and ebx, 4
    cpu.ebx &= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00461808  898834205000           -mov dword ptr [eax + 0x502034], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5251124) /* 0x502034 */) = cpu.ecx;
    // 0046180e  be14000000             -mov esi, 0x14
    cpu.esi = 20 /*0x14*/;
    // 00461813  899838205000           -mov dword ptr [eax + 0x502038], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5251128) /* 0x502038 */) = cpu.ebx;
    // 00461819  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
L_0x0046181d:
    // 0046181d  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00461821  41                     -inc ecx
    (cpu.ecx)++;
    // 00461822  8b1da4f14d00           -mov ebx, dword ptr [0x4df1a4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5108132) /* 0x4df1a4 */);
    // 00461828  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0046182c  39d9                   +cmp ecx, ebx
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
    // 0046182e  0f8c41ffffff           -jl 0x461775
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00461775;
    }
L_0x00461834:
    // 00461834  83c408                 +add esp, 8
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
    // 00461837  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461838  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461839  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046183a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046183b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046183c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046183d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046183e:
    // 0046183e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00461840  e9f7fdffff             -jmp 0x46163c
    goto L_0x0046163c;
L_0x00461845:
    // 00461845  e815df0200             -call 0x48f75f
    cpu.esp -= 4;
    sub_48f75f(app, cpu);
    if (cpu.terminate) return;
    // 0046184a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0046184c  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046184f  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00461851  8b149dcc544c00         -mov edx, dword ptr [ebx*4 + 0x4c54cc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5002444) /* 0x4c54cc */ + cpu.ebx * 4);
    // 00461858  8bbdb8020000           -mov edi, dword ptr [ebp + 0x2b8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(696) /* 0x2b8 */);
    // 0046185e  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00461860  39fa                   +cmp edx, edi
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
    // 00461862  7d24                   -jge 0x461888
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00461888;
    }
    // 00461864  8b851c020000           -mov eax, dword ptr [ebp + 0x21c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(540) /* 0x21c */);
    // 0046186a  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0046186c  e8eede0200             -call 0x48f75f
    cpu.esp -= 4;
    sub_48f75f(app, cpu);
    if (cpu.terminate) return;
    // 00461871  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00461873  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00461876  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00461878  8b148dcc544c00         -mov edx, dword ptr [ecx*4 + 0x4c54cc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5002444) /* 0x4c54cc */ + cpu.ecx * 4);
    // 0046187f  29c2                   +sub edx, eax
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00461881  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00461883  e9b4fdffff             -jmp 0x46163c
    goto L_0x0046163c;
L_0x00461888:
    // 00461888  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0046188a  e9adfdffff             -jmp 0x46163c
    goto L_0x0046163c;
L_0x0046188f:
    // 0046188f  8b8530020000           -mov eax, dword ptr [ebp + 0x230]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(560) /* 0x230 */);
    // 00461895  c1e002                 +shl eax, 2
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
    // 00461898  8d1428                 -lea edx, [eax + ebp]
    cpu.edx = x86::reg32(cpu.eax + cpu.ebp * 1);
    // 0046189b  8b85b8020000           -mov eax, dword ptr [ebp + 0x2b8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(696) /* 0x2b8 */);
    // 004618a1  898258020000           -mov dword ptr [edx + 0x258], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(600) /* 0x258 */) = cpu.eax;
    // 004618a7  e99dfdffff             -jmp 0x461649
    goto L_0x00461649;
L_0x004618ac:
    // 004618ac  8b9528020000           -mov edx, dword ptr [ebp + 0x228]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(552) /* 0x228 */);
    // 004618b2  e976feffff             -jmp 0x46172d
    goto L_0x0046172d;
L_0x004618b7:
    // 004618b7  0f8560ffffff           -jne 0x46181d
    if (!cpu.flags.zf)
    {
        goto L_0x0046181d;
    }
    // 004618bd  8b8834205000           -mov ecx, dword ptr [eax + 0x502034]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5251124) /* 0x502034 */);
    // 004618c3  3b8d24020000           +cmp ecx, dword ptr [ebp + 0x224]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(548) /* 0x224 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004618c9  0f8fc1feffff           -jg 0x461790
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00461790;
    }
    // 004618cf  e949ffffff             -jmp 0x46181d
    goto L_0x0046181d;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4618e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004618e0  83f801                 +cmp eax, 1
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
    // 004618e3  7e11                   -jle 0x4618f6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004618f6;
    }
    // 004618e5  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004618e8  8b800c205000           -mov eax, dword ptr [eax + 0x50200c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5251084) /* 0x50200c */);
    // 004618ee  8b048528ee4d00         -mov eax, dword ptr [eax*4 + 0x4dee28]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5107240) /* 0x4dee28 */ + cpu.eax * 4);
    // 004618f5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004618f6:
    // 004618f6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004618f8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_461900(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00461900  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00461901  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00461902  8b0da4f14d00           -mov ecx, dword ptr [0x4df1a4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5108132) /* 0x4df1a4 */);
    // 00461908  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046190a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0046190c  7e16                   -jle 0x461924
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00461924;
    }
    // 0046190e  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
    // 00461911  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00461913:
    // 00461913  83b82c205000ff         +cmp dword ptr [eax + 0x50202c], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5251116) /* 0x50202c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046191a  7401                   -je 0x46191d
    if (cpu.flags.zf)
    {
        goto L_0x0046191d;
    }
    // 0046191c  42                     -inc edx
    (cpu.edx)++;
L_0x0046191d:
    // 0046191d  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00461920  39c8                   +cmp eax, ecx
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
    // 00461922  7cef                   -jl 0x461913
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00461913;
    }
L_0x00461924:
    // 00461924  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00461926  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461927  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461928  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_461930(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00461930  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00461931  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00461932  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00461933  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00461934  8b35a4f14d00           -mov esi, dword ptr [0x4df1a4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5108132) /* 0x4df1a4 */);
    // 0046193a  8b98e8010000           -mov ebx, dword ptr [eax + 0x1e8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(488) /* 0x1e8 */);
    // 00461940  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00461942  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00461944  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00461946  7e15                   -jle 0x46195d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046195d;
    }
    // 00461948  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0046194a:
    // 0046194a  3b9a2c205000           +cmp ebx, dword ptr [edx + 0x50202c]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5251116) /* 0x50202c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00461950  7503                   -jne 0x461955
    if (!cpu.flags.zf)
    {
        goto L_0x00461955;
    }
    // 00461952  8d4801                 -lea ecx, [eax + 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
L_0x00461955:
    // 00461955  40                     -inc eax
    (cpu.eax)++;
    // 00461956  83c210                 -add edx, 0x10
    (cpu.edx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00461959  39f0                   +cmp eax, esi
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
    // 0046195b  7ced                   -jl 0x46194a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046194a;
    }
L_0x0046195d:
    // 0046195d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046195f  8935a4f14d00           -mov dword ptr [0x4df1a4], esi
    app->getMemory<x86::reg32>(x86::reg32(5108132) /* 0x4df1a4 */) = cpu.esi;
    // 00461965  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461966  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461967  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461968  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461969  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_461970(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00461970  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00461971  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00461972  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00461973  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 00461978  b96179feff             -mov ecx, 0xfffe7961
    cpu.ecx = 4294867297 /*0xfffe7961*/;
    // 0046197d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0046197f:
    // 0046197f  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00461982  898820205000           -mov dword ptr [eax + 0x502020], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5251104) /* 0x502020 */) = cpu.ecx;
    // 00461988  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046198a  89901c205000           -mov dword ptr [eax + 0x50201c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5251100) /* 0x50201c */) = cpu.edx;
    // 00461990  899824205000           -mov dword ptr [eax + 0x502024], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5251108) /* 0x502024 */) = cpu.ebx;
    // 00461996  899828205000           -mov dword ptr [eax + 0x502028], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5251112) /* 0x502028 */) = cpu.ebx;
    // 0046199c  3dc0000000             +cmp eax, 0xc0
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(192 /*0xc0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004619a1  75dc                   -jne 0x46197f
    if (!cpu.flags.zf)
    {
        goto L_0x0046197f;
    }
    // 004619a3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004619a4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004619a5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004619a6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4619b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004619b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004619b1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004619b2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004619b3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004619b4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004619b5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004619b6  8b2da0f14d00           -mov ebp, dword ptr [0x4df1a0]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5108128) /* 0x4df1a0 */);
    // 004619bc  bf63000000             -mov edi, 0x63
    cpu.edi = 99 /*0x63*/;
    // 004619c1  8b0da4f14d00           -mov ecx, dword ptr [0x4df1a4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5108132) /* 0x4df1a4 */);
    // 004619c7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004619c9  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004619cb  7e54                   -jle 0x461a21
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00461a21;
    }
    // 004619cd  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004619cf  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x004619d1:
    // 004619d1  8b8368ef4d00           -mov eax, dword ptr [ebx + 0x4def68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5107560) /* 0x4def68 */);
    // 004619d7  e854ffffff             -call 0x461930
    cpu.esp -= 4;
    sub_461930(app, cpu);
    if (cpu.terminate) return;
    // 004619dc  8bb368ef4d00           -mov esi, dword ptr [ebx + 0x4def68]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5107560) /* 0x4def68 */);
    // 004619e2  898678020000           -mov dword ptr [esi + 0x278], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(632) /* 0x278 */) = cpu.eax;
    // 004619e8  83b93820500000         +cmp dword ptr [ecx + 0x502038], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5251128) /* 0x502038 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004619ef  741f                   -je 0x461a10
    if (cpu.flags.zf)
    {
        goto L_0x00461a10;
    }
    // 004619f1  83ff63                 +cmp edi, 0x63
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(99 /*0x63*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004619f4  751a                   -jne 0x461a10
    if (!cpu.flags.zf)
    {
        goto L_0x00461a10;
    }
    // 004619f6  8b812c205000           -mov eax, dword ptr [ecx + 0x50202c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5251116) /* 0x50202c */);
    // 004619fc  8b048568ef4d00         -mov eax, dword ptr [eax*4 + 0x4def68]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5107560) /* 0x4def68 */ + cpu.eax * 4);
    // 00461a03  8b801c020000           -mov eax, dword ptr [eax + 0x21c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(540) /* 0x21c */);
    // 00461a09  833824                 +cmp dword ptr [eax], 0x24
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(36 /*0x24*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00461a0c  7402                   -je 0x461a10
    if (cpu.flags.zf)
    {
        goto L_0x00461a10;
    }
    // 00461a0e  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
L_0x00461a10:
    // 00461a10  8b35a4f14d00           -mov esi, dword ptr [0x4df1a4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5108132) /* 0x4df1a4 */);
    // 00461a16  83c110                 -add ecx, 0x10
    (cpu.ecx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00461a19  42                     -inc edx
    (cpu.edx)++;
    // 00461a1a  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00461a1d  39f2                   +cmp edx, esi
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
    // 00461a1f  7cb0                   -jl 0x4619d1
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004619d1;
    }
L_0x00461a21:
    // 00461a21  a130f54d00             -mov eax, dword ptr [0x4df530]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5109040) /* 0x4df530 */);
    // 00461a26  8b2da0f14d00           -mov ebp, dword ptr [0x4df1a0]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5108128) /* 0x4df1a0 */);
    // 00461a2c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00461a2e  744b                   -je 0x461a7b
    if (cpu.flags.zf)
    {
        goto L_0x00461a7b;
    }
    // 00461a30  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00461a32  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00461a34  7e45                   -jle 0x461a7b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00461a7b;
    }
    // 00461a36  c1e704                 -shl edi, 4
    cpu.edi <<= 4 /*0x4*/ % 32;
    // 00461a39  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00461a3b:
    // 00461a3b  8b8328f04d00           -mov eax, dword ptr [ebx + 0x4df028]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5107752) /* 0x4df028 */);
    // 00461a41  8b901c020000           -mov edx, dword ptr [eax + 0x21c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(540) /* 0x21c */);
    // 00461a47  833a24                 +cmp dword ptr [edx], 0x24
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(36 /*0x24*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00461a4a  741d                   -je 0x461a69
    if (cpu.flags.zf)
    {
        goto L_0x00461a69;
    }
    // 00461a4c  8b9020020000           -mov edx, dword ptr [eax + 0x220]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(544) /* 0x220 */);
    // 00461a52  8b8f30205000           -mov ecx, dword ptr [edi + 0x502030]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5251120) /* 0x502030 */);
    // 00461a58  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00461a5a  6b1524f54d0074         -imul edx, dword ptr [0x4df524], 0x74
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5109028) /* 0x4df524 */))) * x86::sreg64(x86::sreg32(116 /*0x74*/)));
    // 00461a61  3b8afcf04d00           +cmp ecx, dword ptr [edx + 0x4df0fc]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5107964) /* 0x4df0fc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00461a67  7d1f                   -jge 0x461a88
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00461a88;
    }
L_0x00461a69:
    // 00461a69  c7801802000000000100   -mov dword ptr [eax + 0x218], 0x10000
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(536) /* 0x218 */) = 65536 /*0x10000*/;
L_0x00461a73:
    // 00461a73  46                     -inc esi
    (cpu.esi)++;
    // 00461a74  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00461a77  39ee                   +cmp esi, ebp
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
    // 00461a79  7cc0                   -jl 0x461a3b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00461a3b;
    }
L_0x00461a7b:
    // 00461a7b  892da0f14d00           -mov dword ptr [0x4df1a0], ebp
    app->getMemory<x86::reg32>(x86::reg32(5108128) /* 0x4df1a0 */) = cpu.ebp;
    // 00461a81  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461a82  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461a83  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461a84  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461a85  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461a86  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461a87  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00461a88:
    // 00461a88  3b8a00f14d00           +cmp ecx, dword ptr [edx + 0x4df100]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5107968) /* 0x4df100 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00461a8e  7d0e                   -jge 0x461a9e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00461a9e;
    }
    // 00461a90  8b920cf14d00           -mov edx, dword ptr [edx + 0x4df10c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5107980) /* 0x4df10c */);
    // 00461a96  899018020000           -mov dword ptr [eax + 0x218], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(536) /* 0x218 */) = cpu.edx;
    // 00461a9c  ebd5                   -jmp 0x461a73
    goto L_0x00461a73;
L_0x00461a9e:
    // 00461a9e  3b8a04f14d00           +cmp ecx, dword ptr [edx + 0x4df104]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5107972) /* 0x4df104 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00461aa4  7d0e                   -jge 0x461ab4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00461ab4;
    }
    // 00461aa6  8b9210f14d00           -mov edx, dword ptr [edx + 0x4df110]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5107984) /* 0x4df110 */);
    // 00461aac  899018020000           -mov dword ptr [eax + 0x218], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(536) /* 0x218 */) = cpu.edx;
    // 00461ab2  ebbf                   -jmp 0x461a73
    goto L_0x00461a73;
L_0x00461ab4:
    // 00461ab4  3b8a08f14d00           +cmp ecx, dword ptr [edx + 0x4df108]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5107976) /* 0x4df108 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00461aba  7d0e                   -jge 0x461aca
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00461aca;
    }
    // 00461abc  8b9214f14d00           -mov edx, dword ptr [edx + 0x4df114]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5107988) /* 0x4df114 */);
    // 00461ac2  899018020000           -mov dword ptr [eax + 0x218], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(536) /* 0x218 */) = cpu.edx;
    // 00461ac8  eba9                   -jmp 0x461a73
    goto L_0x00461a73;
L_0x00461aca:
    // 00461aca  8b9218f14d00           -mov edx, dword ptr [edx + 0x4df118]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5107992) /* 0x4df118 */);
    // 00461ad0  899018020000           -mov dword ptr [eax + 0x218], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(536) /* 0x218 */) = cpu.edx;
    // 00461ad6  eb9b                   -jmp 0x461a73
    goto L_0x00461a73;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
/* data blob: 04000000080000000a0000000c00000010000000400000001800000000000000 */
void Application::sub_461b00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00461b00  0305f01a4600           -add eax, dword ptr [0x461af0]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4594416) /* 0x461af0 */)));
    // 00461b06  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_461b10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00461b10  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00461b11  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00461b12  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00461b13  8b0dec1a4600           -mov ecx, dword ptr [0x461aec]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4594412) /* 0x461aec */);
    // 00461b19  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00461b1b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00461b1d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00461b1f  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00461b22  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00461b24  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00461b26  0fbf0443               -movsx eax, word ptr [ebx + eax*2]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.ebx + cpu.eax * 2)));
    // 00461b2a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461b2b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461b2c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461b2d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_461b30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00461b30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00461b31  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00461b32  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00461b33  8b0de81a4600           -mov ecx, dword ptr [0x461ae8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4594408) /* 0x461ae8 */);
    // 00461b39  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00461b3b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00461b3d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00461b3f  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00461b42  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00461b44  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00461b46  0fbf0443               -movsx eax, word ptr [ebx + eax*2]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.ebx + cpu.eax * 2)));
    // 00461b4a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461b4b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461b4c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461b4d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_461b50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00461b50  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00461b51  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00461b52  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00461b53  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00461b54  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00461b55  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00461b58  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00461b5a  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00461b5c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00461b5e  a1e41a4600             -mov eax, dword ptr [0x461ae4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4594404) /* 0x461ae4 */);
    // 00461b63  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00461b66  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00461b68  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00461b6b  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00461b6d  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00461b6f  0fbf3c46               -movsx edi, word ptr [esi + eax*2]
    cpu.edi = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.esi + cpu.eax * 2)));
    // 00461b73  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00461b75  7427                   -je 0x461b9e
    if (cpu.flags.zf)
    {
        goto L_0x00461b9e;
    }
    // 00461b77  a1f41a4600             -mov eax, dword ptr [0x461af4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4594420) /* 0x461af4 */);
    // 00461b7c  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00461b7e  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00461b80  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00461b82  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00461b84  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00461b86  7e16                   -jle 0x461b9e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00461b9e;
    }
L_0x00461b88:
    // 00461b88  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00461b8a  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 00461b8c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00461b8e  668b5904               -mov bx, word ptr [ecx + 4]
    cpu.bx = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00461b92  39eb                   +cmp ebx, ebp
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
    // 00461b94  7414                   -je 0x461baa
    if (cpu.flags.zf)
    {
        goto L_0x00461baa;
    }
    // 00461b96  40                     -inc eax
    (cpu.eax)++;
    // 00461b97  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00461b9a  39f8                   +cmp eax, edi
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
    // 00461b9c  7cea                   -jl 0x461b88
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00461b88;
    }
L_0x00461b9e:
    // 00461b9e  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00461ba1  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00461ba4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461ba5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461ba6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461ba7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461ba8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461ba9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00461baa:
    // 00461baa  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 00461bad  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00461bb0  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00461bb3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461bb4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461bb5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461bb6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461bb7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461bb8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_461bc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00461bc0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00461bc1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00461bc2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00461bc4  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00461bc6  668b480a               -mov cx, word ptr [eax + 0xa]
    cpu.cx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(10) /* 0xa */);
    // 00461bca  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 00461bd1  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00461bd3  8b0df81a4600           -mov ecx, dword ptr [0x461af8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(4594424) /* 0x461af8 */);
    // 00461bd9  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 00461bdb  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00461bdd  668b5204               -mov dx, word ptr [edx + 4]
    cpu.dx = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00461be1  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00461be3  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00461be9  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00461bf0  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00461bf2  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 00461bf4  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00461bf6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461bf7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461bf8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_461c00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00461c00  0305f81a4600           -add eax, dword ptr [0x461af8]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4594424) /* 0x461af8 */)));
    // 00461c06  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_461c10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00461c10  0305f41a4600           -add eax, dword ptr [0x461af4]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(4594420) /* 0x461af4 */)));
    // 00461c16  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_461c20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00461c20  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00461c21  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00461c23  3b0508215000           +cmp eax, dword ptr [0x502108]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5251336) /* 0x502108 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00461c29  730b                   -jae 0x461c36
    if (!cpu.flags.cf)
    {
        goto L_0x00461c36;
    }
    // 00461c2b  a1088d4c00             -mov eax, dword ptr [0x4c8d08]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5016840) /* 0x4c8d08 */);
    // 00461c30  0fbf0448               -movsx eax, word ptr [eax + ecx*2]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.eax + cpu.ecx * 2)));
    // 00461c34  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461c35  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00461c36:
    // 00461c36  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00461c37  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00461c38  bb08010000             -mov ebx, 0x108
    cpu.ebx = 264 /*0x108*/;
    // 00461c3d  bad8d54b00             -mov edx, 0x4bd5d8
    cpu.edx = 4969944 /*0x4bd5d8*/;
    // 00461c42  b838d64b00             -mov eax, 0x4bd638
    cpu.eax = 4970040 /*0x4bd638*/;
    // 00461c47  e847db0200             -call 0x48f793
    cpu.esp -= 4;
    sub_48f793(app, cpu);
    if (cpu.terminate) return;
    // 00461c4c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461c4d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461c4e  a1088d4c00             -mov eax, dword ptr [0x4c8d08]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5016840) /* 0x4c8d08 */);
    // 00461c53  0fbf0448               -movsx eax, word ptr [eax + ecx*2]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.eax + cpu.ecx * 2)));
    // 00461c57  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461c58  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_461c60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00461c60  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00461c61  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00461c62  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00461c64  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00461c66  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00461c68  668b4104               -mov ax, word ptr [ecx + 4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00461c6c  39c2                   +cmp edx, eax
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
    // 00461c6e  7d0b                   -jge 0x461c7b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00461c7b;
    }
    // 00461c70  8d410c                 -lea eax, [ecx + 0xc]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00461c73  8b04b0                 -mov eax, dword ptr [eax + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
    // 00461c76  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00461c78  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461c79  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461c7a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00461c7b:
    // 00461c7b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00461c7c  bbf7000000             -mov ebx, 0xf7
    cpu.ebx = 247 /*0xf7*/;
    // 00461c81  bad8d54b00             -mov edx, 0x4bd5d8
    cpu.edx = 4969944 /*0x4bd5d8*/;
    // 00461c86  b814d64b00             -mov eax, 0x4bd614
    cpu.eax = 4970004 /*0x4bd614*/;
    // 00461c8b  e803db0200             -call 0x48f793
    cpu.esp -= 4;
    sub_48f793(app, cpu);
    if (cpu.terminate) return;
    // 00461c90  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461c91  8d410c                 -lea eax, [ecx + 0xc]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00461c94  8b04b0                 -mov eax, dword ptr [eax + esi*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.esi * 4);
    // 00461c97  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00461c99  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461c9a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461c9b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_461ca0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00461ca0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00461ca1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00461ca3  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00461ca6  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00461ca8  8b15048d4c00           -mov edx, dword ptr [0x4c8d04]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5016836) /* 0x4c8d04 */);
    // 00461cae  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00461cb1  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00461cb3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461cb4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_461cc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00461cc0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00461cc1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00461cc2  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00461cc9  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00461ccb  8b35048d4c00           -mov esi, dword ptr [0x4c8d04]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5016836) /* 0x4c8d04 */);
    // 00461cd1  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00461cd4  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00461cd6  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00461cd8  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00461cd9  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00461cda  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00461cdb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461cdc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461cdd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_461ce0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00461ce0  3b050c215000           +cmp eax, dword ptr [0x50210c]
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
    // 00461ce6  7506                   -jne 0x461cee
    if (!cpu.flags.zf)
    {
        goto L_0x00461cee;
    }
    // 00461ce8  a1f8205000             -mov eax, dword ptr [0x5020f8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5251320) /* 0x5020f8 */);
    // 00461ced  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00461cee:
    // 00461cee  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00461cef  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00461cf0  bb94000000             -mov ebx, 0x94
    cpu.ebx = 148 /*0x94*/;
    // 00461cf5  bad8d54b00             -mov edx, 0x4bd5d8
    cpu.edx = 4969944 /*0x4bd5d8*/;
    // 00461cfa  b8f8d54b00             -mov eax, 0x4bd5f8
    cpu.eax = 4969976 /*0x4bd5f8*/;
    // 00461cff  e88fda0200             -call 0x48f793
    cpu.esp -= 4;
    sub_48f793(app, cpu);
    if (cpu.terminate) return;
    // 00461d04  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461d05  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461d06  a1f8205000             -mov eax, dword ptr [0x5020f8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5251320) /* 0x5020f8 */);
    // 00461d0b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_461d10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00461d10  3b050c215000           +cmp eax, dword ptr [0x50210c]
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
    // 00461d16  7506                   -jne 0x461d1e
    if (!cpu.flags.zf)
    {
        goto L_0x00461d1e;
    }
    // 00461d18  a1f4205000             -mov eax, dword ptr [0x5020f4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5251316) /* 0x5020f4 */);
    // 00461d1d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00461d1e:
    // 00461d1e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00461d1f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00461d20  bb85000000             -mov ebx, 0x85
    cpu.ebx = 133 /*0x85*/;
    // 00461d25  bad8d54b00             -mov edx, 0x4bd5d8
    cpu.edx = 4969944 /*0x4bd5d8*/;
    // 00461d2a  b8f8d54b00             -mov eax, 0x4bd5f8
    cpu.eax = 4969976 /*0x4bd5f8*/;
    // 00461d2f  e85fda0200             -call 0x48f793
    cpu.esp -= 4;
    sub_48f793(app, cpu);
    if (cpu.terminate) return;
    // 00461d34  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461d35  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461d36  a1f4205000             -mov eax, dword ptr [0x5020f4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5251316) /* 0x5020f4 */);
    // 00461d3b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_461d40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00461d40  3b050c215000           +cmp eax, dword ptr [0x50210c]
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
    // 00461d46  7506                   -jne 0x461d4e
    if (!cpu.flags.zf)
    {
        goto L_0x00461d4e;
    }
    // 00461d48  a104215000             -mov eax, dword ptr [0x502104]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5251332) /* 0x502104 */);
    // 00461d4d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00461d4e:
    // 00461d4e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00461d4f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00461d50  bb76000000             -mov ebx, 0x76
    cpu.ebx = 118 /*0x76*/;
    // 00461d55  bad8d54b00             -mov edx, 0x4bd5d8
    cpu.edx = 4969944 /*0x4bd5d8*/;
    // 00461d5a  b8f8d54b00             -mov eax, 0x4bd5f8
    cpu.eax = 4969976 /*0x4bd5f8*/;
    // 00461d5f  e82fda0200             -call 0x48f793
    cpu.esp -= 4;
    sub_48f793(app, cpu);
    if (cpu.terminate) return;
    // 00461d64  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461d65  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461d66  a104215000             -mov eax, dword ptr [0x502104]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5251332) /* 0x502104 */);
    // 00461d6b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_461d70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00461d70  3b050c215000           +cmp eax, dword ptr [0x50210c]
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
    // 00461d76  7506                   -jne 0x461d7e
    if (!cpu.flags.zf)
    {
        goto L_0x00461d7e;
    }
    // 00461d78  a108215000             -mov eax, dword ptr [0x502108]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5251336) /* 0x502108 */);
    // 00461d7d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00461d7e:
    // 00461d7e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00461d7f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00461d80  bb67000000             -mov ebx, 0x67
    cpu.ebx = 103 /*0x67*/;
    // 00461d85  bad8d54b00             -mov edx, 0x4bd5d8
    cpu.edx = 4969944 /*0x4bd5d8*/;
    // 00461d8a  b8f8d54b00             -mov eax, 0x4bd5f8
    cpu.eax = 4969976 /*0x4bd5f8*/;
    // 00461d8f  e8ffd90200             -call 0x48f793
    cpu.esp -= 4;
    sub_48f793(app, cpu);
    if (cpu.terminate) return;
    // 00461d94  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461d95  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461d96  a108215000             -mov eax, dword ptr [0x502108]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5251336) /* 0x502108 */);
    // 00461d9b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_461da0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00461da0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00461da1  8b150c215000           -mov edx, dword ptr [0x50210c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5251340) /* 0x50210c */);
    // 00461da7  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00461da9  7502                   -jne 0x461dad
    if (!cpu.flags.zf)
    {
        goto L_0x00461dad;
    }
    // 00461dab  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461dac  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00461dad:
    // 00461dad  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00461daf  e83cd50000             -call 0x46f2f0
    cpu.esp -= 4;
    sub_46f2f0(app, cpu);
    if (cpu.terminate) return;
    // 00461db4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461db5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_461dc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00461dc0  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00461dc5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_461dd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00461dd0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00461dd1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00461dd2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00461dd3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00461dd4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00461dd5  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00461dd8  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00461dda  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00461ddc:
    // 00461ddc  8b9a5c215000           -mov ebx, dword ptr [edx + 0x50215c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5251420) /* 0x50215c */);
    // 00461de2  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00461de3  8bb258215000           -mov esi, dword ptr [edx + 0x502158]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5251416) /* 0x502158 */);
    // 00461de9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00461dea  8b7904                 -mov edi, dword ptr [ecx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00461ded  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00461dee  8b29                   -mov ebp, dword ptr [ecx]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx);
    // 00461df0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00461df1  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00461df5  e876aaffff             -call 0x45c870
    cpu.esp -= 4;
    sub_45c870(app, cpu);
    if (cpu.terminate) return;
    // 00461dfa  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00461dfc  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00461dfe  83c208                 -add edx, 8
    (cpu.edx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00461e01  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00461e02  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00461e03  81fa00010000           +cmp edx, 0x100
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(256 /*0x100*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00461e09  75d1                   -jne 0x461ddc
    if (!cpu.flags.zf)
    {
        goto L_0x00461ddc;
    }
    // 00461e0b  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00461e0e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461e0f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461e10  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461e11  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461e12  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461e13  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_461e20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00461e20  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00461e21  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00461e22  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00461e23  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00461e26  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00461e28:
    // 00461e28  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00461e2a  e8f1aaffff             -call 0x45c920
    cpu.esp -= 4;
    sub_45c920(app, cpu);
    if (cpu.terminate) return;
    // 00461e2f  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00461e31  8dba58215000           -lea edi, [edx + 0x502158]
    cpu.edi = x86::reg32(cpu.edx + x86::reg32(5251416) /* 0x502158 */);
    // 00461e37  83c208                 -add edx, 8
    (cpu.edx) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00461e3a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00461e3b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00461e3c  81fa00010000           +cmp edx, 0x100
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(256 /*0x100*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00461e42  75e4                   -jne 0x461e28
    if (!cpu.flags.zf)
    {
        goto L_0x00461e28;
    }
    // 00461e44  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00461e47  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461e48  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461e49  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461e4a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_461e50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00461e50  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00461e51  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00461e52  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00461e53  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00461e54  83ec70                 -sub esp, 0x70
    (cpu.esp) -= x86::reg32(x86::sreg32(112 /*0x70*/));
    // 00461e57  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00461e59  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00461e5b  895c2464               -mov dword ptr [esp + 0x64], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */) = cpu.ebx;
    // 00461e5f  83b8bc00000000         +cmp dword ptr [eax + 0xbc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(188) /* 0xbc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00461e66  0f85b4000000           -jne 0x461f20
    if (!cpu.flags.zf)
    {
        goto L_0x00461f20;
    }
L_0x00461e6c:
    // 00461e6c  8b4e04                 -mov ecx, dword ptr [esi + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00461e6f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00461e71  747b                   -je 0x461eee
    if (cpu.flags.zf)
    {
        goto L_0x00461eee;
    }
    // 00461e73  8d5e50                 -lea ebx, [esi + 0x50]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(80) /* 0x50 */);
    // 00461e76  8d5150                 -lea edx, [ecx + 0x50]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(80) /* 0x50 */);
    // 00461e79  8d4620                 -lea eax, [esi + 0x20]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 00461e7c  e8afd10200             -call 0x48f030
    cpu.esp -= 4;
    sub_48f030(app, cpu);
    if (cpu.terminate) return;
    // 00461e81  8b4644                 -mov eax, dword ptr [esi + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(68) /* 0x44 */);
    // 00461e84  8b9e80000000           -mov ebx, dword ptr [esi + 0x80]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(128) /* 0x80 */);
    // 00461e8a  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00461e8c  89442448               -mov dword ptr [esp + 0x48], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */) = cpu.eax;
    // 00461e90  8b4648                 -mov eax, dword ptr [esi + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(72) /* 0x48 */);
    // 00461e93  8bae84000000           -mov ebp, dword ptr [esi + 0x84]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(132) /* 0x84 */);
    // 00461e99  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00461e9b  8944244c               -mov dword ptr [esp + 0x4c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */) = cpu.eax;
    // 00461e9f  8b464c                 -mov eax, dword ptr [esi + 0x4c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(76) /* 0x4c */);
    // 00461ea2  8b9688000000           -mov edx, dword ptr [esi + 0x88]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(136) /* 0x88 */);
    // 00461ea8  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00461eaa  89442450               -mov dword ptr [esp + 0x50], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */) = cpu.eax;
    // 00461eae  8d5c243c               -lea ebx, [esp + 0x3c]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00461eb2  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00461eb5  8d442448               -lea eax, [esp + 0x48]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 00461eb9  83c250                 -add edx, 0x50
    (cpu.edx) += x86::reg32(x86::sreg32(80 /*0x50*/));
    // 00461ebc  e87fdc0000             -call 0x46fb40
    cpu.esp -= 4;
    sub_46fb40(app, cpu);
    if (cpu.terminate) return;
    // 00461ec1  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00461ec4  8b54243c               -mov edx, dword ptr [esp + 0x3c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 00461ec8  8b4074                 -mov eax, dword ptr [eax + 0x74]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(116) /* 0x74 */);
    // 00461ecb  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00461ecd  895674                 -mov dword ptr [esi + 0x74], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(116) /* 0x74 */) = cpu.edx;
    // 00461ed0  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00461ed3  8b542440               -mov edx, dword ptr [esp + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00461ed7  8b4078                 -mov eax, dword ptr [eax + 0x78]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(120) /* 0x78 */);
    // 00461eda  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00461edc  895678                 -mov dword ptr [esi + 0x78], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(120) /* 0x78 */) = cpu.edx;
    // 00461edf  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00461ee2  8b542444               -mov edx, dword ptr [esp + 0x44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 00461ee6  8b407c                 -mov eax, dword ptr [eax + 0x7c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(124) /* 0x7c */);
    // 00461ee9  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00461eeb  89567c                 -mov dword ptr [esi + 0x7c], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(124) /* 0x7c */) = cpu.edx;
L_0x00461eee:
    // 00461eee  833e01                 +cmp dword ptr [esi], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00461ef1  7544                   -jne 0x461f37
    if (!cpu.flags.zf)
    {
        goto L_0x00461f37;
    }
    // 00461ef3  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00461ef6  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00461ef8  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00461efa  7e1c                   -jle 0x461f18
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00461f18;
    }
    // 00461efc  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
L_0x00461efe:
    // 00461efe  8b5c2464               -mov ebx, dword ptr [esp + 0x64]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 00461f02  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00461f04  8b450c                 -mov eax, dword ptr [ebp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(12) /* 0xc */);
    // 00461f07  e844ffffff             -call 0x461e50
    cpu.esp -= 4;
    sub_461e50(app, cpu);
    if (cpu.terminate) return;
    // 00461f0c  41                     -inc ecx
    (cpu.ecx)++;
    // 00461f0d  8b5e08                 -mov ebx, dword ptr [esi + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 00461f10  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00461f13  39d9                   +cmp ecx, ebx
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
    // 00461f15  7ce7                   -jl 0x461efe
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00461efe;
    }
    // 00461f17  90                     -nop 
    ;
L_0x00461f18:
    // 00461f18  83c470                 +add esp, 0x70
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(112 /*0x70*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00461f1b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461f1c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461f1d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461f1e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00461f1f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00461f20:
    // 00461f20  8b90c4000000           -mov edx, dword ptr [eax + 0xc4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(196) /* 0xc4 */);
    // 00461f26  8b80c0000000           -mov eax, dword ptr [eax + 0xc0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(192) /* 0xc0 */);
    // 00461f2c  ff96bc000000           -call dword ptr [esi + 0xbc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(188) /* 0xbc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00461f32  e935ffffff             -jmp 0x461e6c
    goto L_0x00461e6c;
L_0x00461f37:
    // 00461f37  8b9e8c000000           -mov ebx, dword ptr [esi + 0x8c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(140) /* 0x8c */);
    // 00461f3d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00461f3f  74d7                   -je 0x461f18
    if (cpu.flags.zf)
    {
        goto L_0x00461f18;
    }
    // 00461f41  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00461f43  896c246c               -mov dword ptr [esp + 0x6c], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */) = cpu.ebp;
    // 00461f47  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00461f49  7ecd                   -jle 0x461f18
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00461f18;
    }
    // 00461f4b  8d4650                 -lea eax, [esi + 0x50]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(80) /* 0x50 */);
    // 00461f4e  89442468               -mov dword ptr [esp + 0x68], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */) = cpu.eax;
    // 00461f52  8d4744                 -lea eax, [edi + 0x44]
    cpu.eax = x86::reg32(cpu.edi + x86::reg32(68) /* 0x44 */);
    // 00461f55  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 00461f57  89442460               -mov dword ptr [esp + 0x60], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */) = cpu.eax;
L_0x00461f5b:
    // 00461f5b  8b8590000000           -mov eax, dword ptr [ebp + 0x90]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(144) /* 0x90 */);
    // 00461f61  833800                 +cmp dword ptr [eax], 0
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
    // 00461f64  742f                   -je 0x461f95
    if (cpu.flags.zf)
    {
        goto L_0x00461f95;
    }
    // 00461f66  8b4824                 -mov ecx, dword ptr [eax + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 00461f69  81f900000200           +cmp ecx, 0x20000
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(131072 /*0x20000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00461f6f  0f855f010000           -jne 0x4620d4
    if (!cpu.flags.zf)
    {
        goto L_0x004620d4;
    }
    // 00461f75  8b1d54215000           -mov ebx, dword ptr [0x502154]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5251412) /* 0x502154 */);
    // 00461f7b  81fb008bffff           +cmp ebx, 0xffff8b00
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294937344 /*0xffff8b00*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00461f81  7d2e                   -jge 0x461fb1
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00461fb1;
    }
L_0x00461f83:
    // 00461f83  8b1550215000           -mov edx, dword ptr [0x502150]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5251408) /* 0x502150 */);
    // 00461f89  81fa006e0000           +cmp edx, 0x6e00
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(28160 /*0x6e00*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00461f8f  0f8e2e010000           -jle 0x4620c3
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004620c3;
    }
L_0x00461f95:
    // 00461f95  8b4c246c               -mov ecx, dword ptr [esp + 0x6c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */);
    // 00461f99  83c504                 -add ebp, 4
    (cpu.ebp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00461f9c  41                     -inc ecx
    (cpu.ecx)++;
    // 00461f9d  8b9e8c000000           -mov ebx, dword ptr [esi + 0x8c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(140) /* 0x8c */);
    // 00461fa3  894c246c               -mov dword ptr [esp + 0x6c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */) = cpu.ecx;
    // 00461fa7  39d9                   +cmp ecx, ebx
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
    // 00461fa9  0f8d69ffffff           -jge 0x461f18
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00461f18;
    }
    // 00461faf  ebaa                   -jmp 0x461f5b
    goto L_0x00461f5b;
L_0x00461fb1:
    // 00461fb1  81fb00200000           +cmp ebx, 0x2000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8192 /*0x2000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00461fb7  7fca                   -jg 0x461f83
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00461f83;
    }
L_0x00461fb9:
    // 00461fb9  813d5421500000200000   +cmp dword ptr [0x502154], 0x2000
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5251412) /* 0x502154 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8192 /*0x2000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00461fc3  7fd0                   -jg 0x461f95
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00461f95;
    }
L_0x00461fc5:
    // 00461fc5  8b4674                 -mov eax, dword ptr [esi + 0x74]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(116) /* 0x74 */);
    // 00461fc8  8b5708                 -mov edx, dword ptr [edi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 00461fcb  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00461fcd  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 00461fd1  8b4678                 -mov eax, dword ptr [esi + 0x78]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(120) /* 0x78 */);
    // 00461fd4  8b4f0c                 -mov ecx, dword ptr [edi + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 00461fd7  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00461fd9  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 00461fdd  8b467c                 -mov eax, dword ptr [esi + 0x7c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(124) /* 0x7c */);
    // 00461fe0  8b5f10                 -mov ebx, dword ptr [edi + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 00461fe3  8b542460               -mov edx, dword ptr [esp + 0x60]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 00461fe7  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00461fe9  8d5c2454               -lea ebx, [esp + 0x54]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 00461fed  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 00461ff1  8d442424               -lea eax, [esp + 0x24]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00461ff5  e846db0000             -call 0x46fb40
    cpu.esp -= 4;
    sub_46fb40(app, cpu);
    if (cpu.terminate) return;
    // 00461ffa  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00461ffc  8b542460               -mov edx, dword ptr [esp + 0x60]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 00462000  8b442468               -mov eax, dword ptr [esp + 0x68]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 00462004  e827d00200             -call 0x48f030
    cpu.esp -= 4;
    sub_48f030(app, cpu);
    if (cpu.terminate) return;
    // 00462009  8b8590000000           -mov eax, dword ptr [ebp + 0x90]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(144) /* 0x90 */);
    // 0046200f  8b1514894c00           -mov edx, dword ptr [0x4c8914]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5015828) /* 0x4c8914 */);
    // 00462015  8b4020                 -mov eax, dword ptr [eax + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 00462018  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0046201a  7447                   -je 0x462063
    if (cpu.flags.zf)
    {
        goto L_0x00462063;
    }
    // 0046201c  83f806                 +cmp eax, 6
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
    // 0046201f  0f85e3000000           -jne 0x462108
    if (!cpu.flags.zf)
    {
        goto L_0x00462108;
    }
L_0x00462025:
    // 00462025  8b0d50215000           -mov ecx, dword ptr [0x502150]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5251408) /* 0x502150 */);
    // 0046202b  81f900a0ffff           +cmp ecx, 0xffffa000
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294942720 /*0xffffa000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00462031  0f8e22010000           -jle 0x462159
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00462159;
    }
    // 00462037  81f900600000           +cmp ecx, 0x6000
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24576 /*0x6000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046203d  0f8d16010000           -jge 0x462159
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00462159;
    }
    // 00462043  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00462045  0f8edd000000           -jle 0x462128
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00462128;
    }
    // 0046204b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
L_0x0046204d:
    // 0046204d  81fa002e0000           +cmp edx, 0x2e00
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(11776 /*0x2e00*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00462053  7e0e                   -jle 0x462063
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00462063;
    }
    // 00462055  83f806                 +cmp eax, 6
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
    // 00462058  0f85d3000000           -jne 0x462131
    if (!cpu.flags.zf)
    {
        goto L_0x00462131;
    }
L_0x0046205e:
    // 0046205e  b808000000             -mov eax, 8
    cpu.eax = 8 /*0x8*/;
L_0x00462063:
    // 00462063  833d10894c0000         +cmp dword ptr [0x4c8910], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5015824) /* 0x4c8910 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046206a  740c                   -je 0x462078
    if (cpu.flags.zf)
    {
        goto L_0x00462078;
    }
    // 0046206c  83f805                 +cmp eax, 5
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
    // 0046206f  7d07                   -jge 0x462078
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00462078;
    }
    // 00462071  8b0485e80a4e00         -mov eax, dword ptr [eax*4 + 0x4e0ae8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5114600) /* 0x4e0ae8 */ + cpu.eax * 4);
L_0x00462078:
    // 00462078  8b5674                 -mov edx, dword ptr [esi + 0x74]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(116) /* 0x74 */);
    // 0046207b  8b5f08                 -mov ebx, dword ptr [edi + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0046207e  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00462080  89542430               -mov dword ptr [esp + 0x30], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.edx;
    // 00462084  8b5678                 -mov edx, dword ptr [esi + 0x78]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(120) /* 0x78 */);
    // 00462087  8b4f0c                 -mov ecx, dword ptr [edi + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 0046208a  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0046208c  89542434               -mov dword ptr [esp + 0x34], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.edx;
    // 00462090  8b567c                 -mov edx, dword ptr [esi + 0x7c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(124) /* 0x7c */);
    // 00462093  8b5f10                 -mov ebx, dword ptr [edi + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 00462096  29da                   +sub edx, ebx
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ebx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00462098  89542438               -mov dword ptr [esp + 0x38], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.edx;
    // 0046209c  8b542464               -mov edx, dword ptr [esp + 0x64]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 004620a0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004620a1  8d4c2434               -lea ecx, [esp + 0x34]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004620a5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004620a6  8d44245c               -lea eax, [esp + 0x5c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 004620aa  8b5c2470               -mov ebx, dword ptr [esp + 0x70]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */);
    // 004620ae  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004620af  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004620b3  8b8590000000           -mov eax, dword ptr [ebp + 0x90]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(144) /* 0x90 */);
    // 004620b9  e8b2d40000             -call 0x46f570
    cpu.esp -= 4;
    sub_46f570(app, cpu);
    if (cpu.terminate) return;
    // 004620be  e9d2feffff             -jmp 0x461f95
    goto L_0x00461f95;
L_0x004620c3:
    // 004620c3  81fa0092ffff           +cmp edx, 0xffff9200
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294939136 /*0xffff9200*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004620c9  0f8cc6feffff           -jl 0x461f95
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00461f95;
    }
    // 004620cf  e9e5feffff             -jmp 0x461fb9
    goto L_0x00461fb9;
L_0x004620d4:
    // 004620d4  8b1550215000           -mov edx, dword ptr [0x502150]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5251408) /* 0x502150 */);
    // 004620da  39ca                   +cmp edx, ecx
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
    // 004620dc  0f8ee3feffff           -jle 0x461fc5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00461fc5;
    }
    // 004620e2  3b5028                 +cmp edx, dword ptr [eax + 0x28]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004620e5  0f8ddafeffff           -jge 0x461fc5
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00461fc5;
    }
    // 004620eb  8b1554215000           -mov edx, dword ptr [0x502154]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5251412) /* 0x502154 */);
    // 004620f1  3b502c                 +cmp edx, dword ptr [eax + 0x2c]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004620f4  0f8ecbfeffff           -jle 0x461fc5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00461fc5;
    }
    // 004620fa  3b5030                 +cmp edx, dword ptr [eax + 0x30]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004620fd  0f8c92feffff           -jl 0x461f95
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00461f95;
    }
    // 00462103  e9bdfeffff             -jmp 0x461fc5
    goto L_0x00461fc5;
L_0x00462108:
    // 00462108  83f807                 +cmp eax, 7
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
    // 0046210b  0f8414ffffff           -je 0x462025
    if (cpu.flags.zf)
    {
        goto L_0x00462025;
    }
    // 00462111  83f808                 +cmp eax, 8
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
    // 00462114  0f840bffffff           -je 0x462025
    if (cpu.flags.zf)
    {
        goto L_0x00462025;
    }
    // 0046211a  83f809                 +cmp eax, 9
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
    // 0046211d  0f8402ffffff           -je 0x462025
    if (cpu.flags.zf)
    {
        goto L_0x00462025;
    }
    // 00462123  e93bffffff             -jmp 0x462063
    goto L_0x00462063;
L_0x00462128:
    // 00462128  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0046212a  f7da                   +neg edx
    {
        x86::reg32 tmp1 = 0;
        x86::reg32& tmp2 = cpu.edx;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 0046212c  e91cffffff             -jmp 0x46204d
    goto L_0x0046204d;
L_0x00462131:
    // 00462131  83f807                 +cmp eax, 7
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
    // 00462134  750a                   -jne 0x462140
    if (!cpu.flags.zf)
    {
        goto L_0x00462140;
    }
    // 00462136  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 0046213b  e923ffffff             -jmp 0x462063
    goto L_0x00462063;
L_0x00462140:
    // 00462140  83f808                 +cmp eax, 8
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
    // 00462143  750a                   -jne 0x46214f
    if (!cpu.flags.zf)
    {
        goto L_0x0046214f;
    }
L_0x00462145:
    // 00462145  b806000000             -mov eax, 6
    cpu.eax = 6 /*0x6*/;
    // 0046214a  e914ffffff             -jmp 0x462063
    goto L_0x00462063;
L_0x0046214f:
    // 0046214f  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 00462154  e90affffff             -jmp 0x462063
    goto L_0x00462063;
L_0x00462159:
    // 00462159  83f806                 +cmp eax, 6
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
    // 0046215c  750a                   -jne 0x462168
    if (!cpu.flags.zf)
    {
        goto L_0x00462168;
    }
    // 0046215e  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 00462163  e9fbfeffff             -jmp 0x462063
    goto L_0x00462063;
L_0x00462168:
    // 00462168  83f807                 +cmp eax, 7
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
    // 0046216b  0f84edfeffff           -je 0x46205e
    if (cpu.flags.zf)
    {
        goto L_0x0046205e;
    }
    // 00462171  83f808                 +cmp eax, 8
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
    // 00462174  75cf                   -jne 0x462145
    if (!cpu.flags.zf)
    {
        goto L_0x00462145;
    }
    // 00462176  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 0046217b  e9e3feffff             -jmp 0x462063
    goto L_0x00462063;
}

/* align: skip  */
void Application::sub_462180(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00462180  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00462181  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00462182  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00462185  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00462187  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00462189  ba80000000             -mov edx, 0x80
    cpu.edx = 128 /*0x80*/;
    // 0046218e  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00462190  e8dba7ffff             -call 0x45c970
    cpu.esp -= 4;
    sub_45c970(app, cpu);
    if (cpu.terminate) return;
    // 00462195  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00462197  7508                   -jne 0x4621a1
    if (!cpu.flags.zf)
    {
        goto L_0x004621a1;
    }
L_0x00462199:
    // 00462199  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046219b  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046219e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046219f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004621a0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004621a1:
    // 004621a1  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004621a4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004621a5  8d5138                 -lea edx, [ecx + 0x38]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(56) /* 0x38 */);
    // 004621a8  8d4144                 -lea eax, [ecx + 0x44]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(68) /* 0x44 */);
    // 004621ab  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004621ad  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 004621b2  e869d80000             -call 0x46fa20
    cpu.esp -= 4;
    sub_46fa20(app, cpu);
    if (cpu.terminate) return;
    // 004621b7  ba24000000             -mov edx, 0x24
    cpu.edx = 36 /*0x24*/;
    // 004621bc  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004621c0  e8aba7ffff             -call 0x45c970
    cpu.esp -= 4;
    sub_45c970(app, cpu);
    if (cpu.terminate) return;
    // 004621c5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004621c7  74d0                   -je 0x462199
    if (cpu.flags.zf)
    {
        goto L_0x00462199;
    }
    // 004621c9  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004621cd  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004621d3  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004621d7  c740040a000000         -mov dword ptr [eax + 4], 0xa
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 10 /*0xa*/;
    // 004621de  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004621e2  8b1580bb5100           -mov edx, dword ptr [0x51bb80]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5356416) /* 0x51bb80 */);
    // 004621e8  89501c                 -mov dword ptr [eax + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 004621eb  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004621ef  66c74020ffff           -mov word ptr [eax + 0x20], 0xffff
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(32) /* 0x20 */) = 65535 /*0xffff*/;
    // 004621f5  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004621f9  66c7400a0100           -mov word ptr [eax + 0xa], 1
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(10) /* 0xa */) = 1 /*0x1*/;
    // 004621ff  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00462203  66c740080300           -mov word ptr [eax + 8], 3
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(8) /* 0x8 */) = 3 /*0x3*/;
    // 00462209  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046220d  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00462210  89420c                 -mov dword ptr [edx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00462213  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00462217  83c020                 -add eax, 0x20
    (cpu.eax) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 0046221a  894210                 -mov dword ptr [edx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0046221d  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00462220  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00462224  83c060                 -add eax, 0x60
    (cpu.eax) += x86::reg32(x86::sreg32(96 /*0x60*/));
    // 00462227  894214                 -mov dword ptr [edx + 0x14], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0046222a  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0046222d  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00462231  83c040                 -add eax, 0x40
    (cpu.eax) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00462234  894218                 -mov dword ptr [edx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00462237  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0046223b  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0046223e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046223f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462240  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_462250(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00462250  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00462251  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00462253  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 00462258  e893000000             -call 0x4622f0
    cpu.esp -= 4;
    sub_4622f0(app, cpu);
    if (cpu.terminate) return;
    // 0046225d  894804                 -mov dword ptr [eax + 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00462260  8990bc000000           -mov dword ptr [eax + 0xbc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(188) /* 0xbc */) = cpu.edx;
    // 00462266  8980c0000000           -mov dword ptr [eax + 0xc0], eax
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(192) /* 0xc0 */) = cpu.eax;
    // 0046226c  8998c4000000           -mov dword ptr [eax + 0xc4], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(196) /* 0xc4 */) = cpu.ebx;
    // 00462272  8b5108                 -mov edx, dword ptr [ecx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00462275  8944910c               -mov dword ptr [ecx + edx*4 + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */ + cpu.edx * 4) = cpu.eax;
    // 00462279  ff4108                 -inc dword ptr [ecx + 8]
    (app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */))++;
    // 0046227c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046227d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_462280(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00462280  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00462281  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00462283  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00462288  e863000000             -call 0x4622f0
    cpu.esp -= 4;
    sub_4622f0(app, cpu);
    if (cpu.terminate) return;
    // 0046228d  894804                 -mov dword ptr [eax + 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 00462290  8990bc000000           -mov dword ptr [eax + 0xbc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(188) /* 0xbc */) = cpu.edx;
    // 00462296  8980c0000000           -mov dword ptr [eax + 0xc0], eax
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(192) /* 0xc0 */) = cpu.eax;
    // 0046229c  8998c4000000           -mov dword ptr [eax + 0xc4], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(196) /* 0xc4 */) = cpu.ebx;
    // 004622a2  8b5108                 -mov edx, dword ptr [ecx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004622a5  8944910c               -mov dword ptr [ecx + edx*4 + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */ + cpu.edx * 4) = cpu.eax;
    // 004622a9  ff4108                 -inc dword ptr [ecx + 8]
    (app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */))++;
    // 004622ac  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004622ad  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4622b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004622b0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004622b1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004622b2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004622b4  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004622b6  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004622b8  8b808c000000           -mov eax, dword ptr [eax + 0x8c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(140) /* 0x8c */);
    // 004622be  89b48190000000         -mov dword ptr [ecx + eax*4 + 0x90], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(144) /* 0x90 */ + cpu.eax * 4) = cpu.esi;
    // 004622c5  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004622c7  e86495ffff             -call 0x45b830
    cpu.esp -= 4;
    sub_45b830(app, cpu);
    if (cpu.terminate) return;
    // 004622cc  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004622cf  894144                 -mov dword ptr [ecx + 0x44], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(68) /* 0x44 */) = cpu.eax;
    // 004622d2  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004622d5  894148                 -mov dword ptr [ecx + 0x48], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(72) /* 0x48 */) = cpu.eax;
    // 004622d8  8b5610                 -mov edx, dword ptr [esi + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004622db  89514c                 -mov dword ptr [ecx + 0x4c], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(76) /* 0x4c */) = cpu.edx;
    // 004622de  ff818c000000           -inc dword ptr [ecx + 0x8c]
    (app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(140) /* 0x8c */))++;
    // 004622e4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004622e5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004622e6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4622f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004622f0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004622f1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004622f3  b88cd64b00             -mov eax, 0x4bd68c
    cpu.eax = 4970124 /*0x4bd68c*/;
    // 004622f8  e813000000             -call 0x462310
    cpu.esp -= 4;
    sub_462310(app, cpu);
    if (cpu.terminate) return;
    // 004622fd  c7400800000000         -mov dword ptr [eax + 8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 0 /*0x0*/;
    // 00462304  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00462306  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462307  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_462310(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00462310  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00462311  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00462312  bac8000000             -mov edx, 0xc8
    cpu.edx = 200 /*0xc8*/;
    // 00462317  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00462319  e8f2000000             -call 0x462410
    cpu.esp -= 4;
    sub_462410(app, cpu);
    if (cpu.terminate) return;
    // 0046231e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00462320  83c020                 -add eax, 0x20
    (cpu.eax) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00462323  c740e400000000         -mov dword ptr [eax - 0x1c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-28) /* -0x1c */) = 0 /*0x0*/;
    // 0046232a  c740e800000000         -mov dword ptr [eax - 0x18], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-24) /* -0x18 */) = 0 /*0x0*/;
    // 00462331  c7406c00000000         -mov dword ptr [eax + 0x6c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(108) /* 0x6c */) = 0 /*0x0*/;
    // 00462338  c7809c00000000000000   -mov dword ptr [eax + 0x9c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(156) /* 0x9c */) = 0 /*0x0*/;
    // 00462342  c780a000000000000000   -mov dword ptr [eax + 0xa0], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(160) /* 0xa0 */) = 0 /*0x0*/;
    // 0046234c  c780a400000000000000   -mov dword ptr [eax + 0xa4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(164) /* 0xa4 */) = 0 /*0x0*/;
    // 00462356  e8d5a0feff             -call 0x44c430
    cpu.esp -= 4;
    sub_44c430(app, cpu);
    if (cpu.terminate) return;
    // 0046235b  8d4250                 -lea eax, [edx + 0x50]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(80) /* 0x50 */);
    // 0046235e  e8cda0feff             -call 0x44c430
    cpu.esp -= 4;
    sub_44c430(app, cpu);
    if (cpu.terminate) return;
    // 00462363  c7424400000000         -mov dword ptr [edx + 0x44], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(68) /* 0x44 */) = 0 /*0x0*/;
    // 0046236a  c7424800000000         -mov dword ptr [edx + 0x48], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(72) /* 0x48 */) = 0 /*0x0*/;
    // 00462371  c7424c00000000         -mov dword ptr [edx + 0x4c], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(76) /* 0x4c */) = 0 /*0x0*/;
    // 00462378  c7828000000000000000   -mov dword ptr [edx + 0x80], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(128) /* 0x80 */) = 0 /*0x0*/;
    // 00462382  c7828400000000000000   -mov dword ptr [edx + 0x84], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(132) /* 0x84 */) = 0 /*0x0*/;
    // 0046238c  c7828800000000000000   -mov dword ptr [edx + 0x88], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(136) /* 0x88 */) = 0 /*0x0*/;
    // 00462396  c7427400000000         -mov dword ptr [edx + 0x74], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(116) /* 0x74 */) = 0 /*0x0*/;
    // 0046239d  c7427800000000         -mov dword ptr [edx + 0x78], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(120) /* 0x78 */) = 0 /*0x0*/;
    // 004623a4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004623a6  c7427c00000000         -mov dword ptr [edx + 0x7c], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(124) /* 0x7c */) = 0 /*0x0*/;
    // 004623ad  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004623ae  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004623af  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4623b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004623b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004623b1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004623b2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004623b3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004623b4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004623b5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004623b6  8b150c8d4c00           -mov edx, dword ptr [0x4c8d0c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5016844) /* 0x4c8d0c */);
    // 004623bc  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004623be  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004623c0  7e22                   -jle 0x4623e4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004623e4;
    }
    // 004623c2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004623c4:
    // 004623c4  8bba10215000           -mov edi, dword ptr [edx + 0x502110]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5251344) /* 0x502110 */);
    // 004623ca  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004623cc  752b                   -jne 0x4623f9
    if (!cpu.flags.zf)
    {
        goto L_0x004623f9;
    }
L_0x004623ce:
    // 004623ce  8b350c8d4c00           -mov esi, dword ptr [0x4c8d0c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5016844) /* 0x4c8d0c */);
    // 004623d4  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004623d7  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004623d9  41                     -inc ecx
    (cpu.ecx)++;
    // 004623da  899a0c215000           -mov dword ptr [edx + 0x50210c], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5251340) /* 0x50210c */) = cpu.ebx;
    // 004623e0  39f1                   +cmp ecx, esi
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
    // 004623e2  7ce0                   -jl 0x4623c4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004623c4;
    }
L_0x004623e4:
    // 004623e4  31ed                   +xor ebp, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp))));
    // 004623e6  892d0c8d4c00           -mov dword ptr [0x4c8d0c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5016844) /* 0x4c8d0c */) = cpu.ebp;
    // 004623ec  892d108d4c00           -mov dword ptr [0x4c8d10], ebp
    app->getMemory<x86::reg32>(x86::reg32(5016848) /* 0x4c8d10 */) = cpu.ebp;
    // 004623f2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004623f3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004623f4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004623f5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004623f6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004623f7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004623f8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004623f9:
    // 004623f9  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004623fb  e88c820100             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
    // 00462400  ebcc                   -jmp 0x4623ce
    goto L_0x004623ce;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_462410(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00462410  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00462411  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00462412  8b0d108d4c00           -mov ecx, dword ptr [0x4c8d10]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5016848) /* 0x4c8d10 */);
    // 00462418  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0046241a  7442                   -je 0x46245e
    if (cpu.flags.zf)
    {
        goto L_0x0046245e;
    }
    // 0046241c  a10c8d4c00             -mov eax, dword ptr [0x4c8d0c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5016844) /* 0x4c8d0c */);
    // 00462421  8d1c8500000000         -lea ebx, [eax*4]
    cpu.ebx = x86::reg32(cpu.eax * 4);
    // 00462428  8d048d00000000         -lea eax, [ecx*4]
    cpu.eax = x86::reg32(cpu.ecx * 4);
    // 0046242f  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00462431  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00462434  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00462436  8b930c215000           -mov edx, dword ptr [ebx + 0x50210c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5251340) /* 0x50210c */);
    // 0046243c  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0046243f  41                     -inc ecx
    (cpu.ecx)++;
    // 00462440  8d3402                 -lea esi, [edx + eax]
    cpu.esi = x86::reg32(cpu.edx + cpu.eax * 1);
    // 00462443  bb0a000000             -mov ebx, 0xa
    cpu.ebx = 10 /*0xa*/;
    // 00462448  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0046244a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046244c  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0046244f  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00462451  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00462453  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00462455  890d108d4c00           -mov dword ptr [0x4c8d10], ecx
    app->getMemory<x86::reg32>(x86::reg32(5016848) /* 0x4c8d10 */) = cpu.ecx;
    // 0046245b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046245c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046245d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046245e:
    // 0046245e  ba60d64b00             -mov edx, 0x4bd660
    cpu.edx = 4970080 /*0x4bd660*/;
    // 00462463  bb4f000000             -mov ebx, 0x4f
    cpu.ebx = 79 /*0x4f*/;
    // 00462468  b884d64b00             -mov eax, 0x4bd684
    cpu.eax = 4970116 /*0x4bd684*/;
    // 0046246d  891578a64c00           -mov dword ptr [0x4ca678], edx
    app->getMemory<x86::reg32>(x86::reg32(5023352) /* 0x4ca678 */) = cpu.edx;
    // 00462473  891d7ca64c00           -mov dword ptr [0x4ca67c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5023356) /* 0x4ca67c */) = cpu.ebx;
    // 00462479  bad0070000             -mov edx, 0x7d0
    cpu.edx = 2000 /*0x7d0*/;
    // 0046247e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00462480  e8a37d0100             -call 0x47a228
    cpu.esp -= 4;
    sub_47a228(app, cpu);
    if (cpu.terminate) return;
    // 00462485  8b150c8d4c00           -mov edx, dword ptr [0x4c8d0c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5016844) /* 0x4c8d0c */);
    // 0046248b  8b0d108d4c00           -mov ecx, dword ptr [0x4c8d10]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5016848) /* 0x4c8d10 */);
    // 00462491  8d7201                 -lea esi, [edx + 1]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00462494  41                     -inc ecx
    (cpu.ecx)++;
    // 00462495  89049510215000         -mov dword ptr [edx*4 + 0x502110], eax
    app->getMemory<x86::reg32>(x86::reg32(5251344) /* 0x502110 */ + cpu.edx * 4) = cpu.eax;
    // 0046249c  89350c8d4c00           -mov dword ptr [0x4c8d0c], esi
    app->getMemory<x86::reg32>(x86::reg32(5016844) /* 0x4c8d0c */) = cpu.esi;
    // 004624a2  8b04b50c215000         -mov eax, dword ptr [esi*4 + 0x50210c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5251340) /* 0x50210c */ + cpu.esi * 4);
    // 004624a9  890d108d4c00           -mov dword ptr [0x4c8d10], ecx
    app->getMemory<x86::reg32>(x86::reg32(5016848) /* 0x4c8d10 */) = cpu.ecx;
    // 004624af  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004624b0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004624b1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4624c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004624c0  a3148d4c00             -mov dword ptr [0x4c8d14], eax
    app->getMemory<x86::reg32>(x86::reg32(5016852) /* 0x4c8d14 */) = cpu.eax;
    // 004624c5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4624d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004624d0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4624e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004624e0  e90b000000             -jmp 0x4624f0
    return sub_4624f0(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4624f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004624f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004624f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004624f2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004624f3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004624f4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004624f5  be10000000             -mov esi, 0x10
    cpu.esi = 16 /*0x10*/;
    // 004624fa  8b15c4f74f00           -mov edx, dword ptr [0x4ff7c4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5240772) /* 0x4ff7c4 */);
    // 00462500  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00462502  891558285000           -mov dword ptr [0x502858], edx
    app->getMemory<x86::reg32>(x86::reg32(5253208) /* 0x502858 */) = cpu.edx;
    // 00462508  89155c285000           -mov dword ptr [0x50285c], edx
    app->getMemory<x86::reg32>(x86::reg32(5253212) /* 0x50285c */) = cpu.edx;
    // 0046250e  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x00462510:
    // 00462510  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00462512  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00462514  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
L_0x00462517:
    // 00462517  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0046251a  899054255000           -mov dword ptr [eax + 0x502554], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5252436) /* 0x502554 */) = cpu.edx;
    // 00462520  89b854265000           -mov dword ptr [eax + 0x502654], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5252692) /* 0x502654 */) = cpu.edi;
    // 00462526  899054275000           -mov dword ptr [eax + 0x502754], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5252948) /* 0x502754 */) = cpu.edx;
    // 0046252c  39c8                   +cmp eax, ecx
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
    // 0046252e  75e7                   -jne 0x462517
    if (!cpu.flags.zf)
    {
        goto L_0x00462517;
    }
    // 00462530  43                     -inc ebx
    (cpu.ebx)++;
    // 00462531  83c610                 -add esi, 0x10
    (cpu.esi) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00462534  83fb10                 +cmp ebx, 0x10
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
    // 00462537  7cd7                   -jl 0x462510
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00462510;
    }
    // 00462539  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046253a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046253b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046253c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046253d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046253e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_462540(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00462540  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00462541  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00462542  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00462543  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00462546  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00462548  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0046254a  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0046254c  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0046254e  83e70f                 -and edi, 0xf
    cpu.edi &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00462551  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00462553  751d                   -jne 0x462572
    if (!cpu.flags.zf)
    {
        goto L_0x00462572;
    }
    // 00462555  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00462557  8d0cad00000000         -lea ecx, [ebp*4]
    cpu.ecx = x86::reg32(cpu.ebp * 4);
    // 0046255e  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 00462561  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00462563  a1c4f74f00             -mov eax, dword ptr [0x4ff7c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5240772) /* 0x4ff7c4 */);
    // 00462568  2b8158255000           -sub eax, dword ptr [ecx + 0x502558]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5252440) /* 0x502558 */)));
    // 0046256e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00462570  7e50                   -jle 0x4625c2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004625c2;
    }
L_0x00462572:
    // 00462572  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 00462574  8d04ad00000000         -lea eax, [ebp*4]
    cpu.eax = x86::reg32(cpu.ebp * 4);
    // 0046257b  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
    // 0046257e  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00462580  a1c4f74f00             -mov eax, dword ptr [0x4ff7c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5240772) /* 0x4ff7c4 */);
    // 00462585  898158255000           -mov dword ptr [ecx + 0x502558], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5252440) /* 0x502558 */) = cpu.eax;
    // 0046258b  8d04ad00000000         -lea eax, [ebp*4]
    cpu.eax = x86::reg32(cpu.ebp * 4);
    // 00462592  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00462594  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00462598  8d0c8500000000         -lea ecx, [eax*4]
    cpu.ecx = x86::reg32(cpu.eax * 4);
    // 0046259f  8d04bd00000000         -lea eax, [edi*4]
    cpu.eax = x86::reg32(cpu.edi * 4);
    // 004625a6  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004625a8  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004625ab  8d1c08                 -lea ebx, [eax + ecx]
    cpu.ebx = x86::reg32(cpu.eax + cpu.ecx * 1);
    // 004625ae  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 004625b1  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004625b5  83bb5826500000         +cmp dword ptr [ebx + 0x502658], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5252696) /* 0x502658 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004625bc  7524                   -jne 0x4625e2
    if (!cpu.flags.zf)
    {
        goto L_0x004625e2;
    }
    // 004625be  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004625c0  7407                   -je 0x4625c9
    if (cpu.flags.zf)
    {
        goto L_0x004625c9;
    }
L_0x004625c2:
    // 004625c2  83c40c                 +add esp, 0xc
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
    // 004625c5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004625c6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004625c7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004625c8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004625c9:
    // 004625c9  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 004625cc  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004625d1  8dbf58225000           -lea edi, [edi + 0x502258]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(5251672) /* 0x502258 */);
    // 004625d7  899358265000           -mov dword ptr [ebx + 0x502658], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5252696) /* 0x502658 */) = cpu.edx;
    // 004625dd  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004625de  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004625df  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004625e0  ebe0                   -jmp 0x4625c2
    goto L_0x004625c2;
L_0x004625e2:
    // 004625e2  0558225000             -add eax, 0x502258
    (cpu.eax) += x86::reg32(x86::sreg32(5251672 /*0x502258*/));
    // 004625e7  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004625e9  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004625ed  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004625ef  7435                   -je 0x462626
    if (cpu.flags.zf)
    {
        goto L_0x00462626;
    }
    // 004625f1  bb33330000             -mov ebx, 0x3333
    cpu.ebx = 13107 /*0x3333*/;
    // 004625f6  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004625f8  e813b7ffff             -call 0x45dd10
    cpu.esp -= 4;
    sub_45dd10(app, cpu);
    if (cpu.terminate) return;
    // 004625fd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004625ff  7512                   -jne 0x462613
    if (!cpu.flags.zf)
    {
        goto L_0x00462613;
    }
    // 00462601  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00462602  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00462606  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 00462608  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 0046260a  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0046260c  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0046260e  e85d000000             -call 0x462670
    cpu.esp -= 4;
    sub_462670(app, cpu);
    if (cpu.terminate) return;
L_0x00462613:
    // 00462613  c1e704                 -shl edi, 4
    cpu.edi <<= 4 /*0x4*/ % 32;
    // 00462616  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00462618  8984af58265000         -mov dword ptr [edi + ebp*4 + 0x502658], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5252696) /* 0x502658 */ + cpu.ebp * 4) = cpu.eax;
    // 0046261f  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00462622  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462623  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462624  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462625  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00462626:
    // 00462626  bb00800000             -mov ebx, 0x8000
    cpu.ebx = 32768 /*0x8000*/;
    // 0046262b  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0046262d  e8deb6ffff             -call 0x45dd10
    cpu.esp -= 4;
    sub_45dd10(app, cpu);
    if (cpu.terminate) return;
    // 00462632  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00462634  758c                   -jne 0x4625c2
    if (!cpu.flags.zf)
    {
        goto L_0x004625c2;
    }
    // 00462636  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00462637  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046263b  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0046263d  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0046263f  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00462641  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00462643  e828000000             -call 0x462670
    cpu.esp -= 4;
    sub_462670(app, cpu);
    if (cpu.terminate) return;
    // 00462648  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046264c  c7805826500001000000   -mov dword ptr [eax + 0x502658], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5252696) /* 0x502658 */) = 1 /*0x1*/;
    // 00462656  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 00462659  8dbf58225000           -lea edi, [edi + 0x502258]
    cpu.edi = x86::reg32(cpu.edi + x86::reg32(5251672) /* 0x502258 */);
    // 0046265f  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00462660  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00462661  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00462662  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00462665  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462666  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462667  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462668  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_462670(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00462670  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00462671  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00462672  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00462673  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00462676  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00462678  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0046267c  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 0046267e  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 00462680  8b4c2428               -mov ecx, dword ptr [esp + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00462684  bb00000e00             -mov ebx, 0xe0000
    cpu.ebx = 917504 /*0xe0000*/;
    // 00462689  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0046268b  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0046268d  e87eb6ffff             -call 0x45dd10
    cpu.esp -= 4;
    sub_45dd10(app, cpu);
    if (cpu.terminate) return;
    // 00462692  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00462694  0f857e000000           -jne 0x462718
    if (!cpu.flags.zf)
    {
        goto L_0x00462718;
    }
    // 0046269a  83f903                 +cmp ecx, 3
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
    // 0046269d  7d5c                   -jge 0x4626fb
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004626fb;
    }
    // 0046269f  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004626a1  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004626a3  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004626a5  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004626a8  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004626ab  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004626af  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004626b1  41                     -inc ecx
    (cpu.ecx)++;
    // 004626b2  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004626b4  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 004626b6  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004626ba  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004626bb  8b4608                 -mov eax, dword ptr [esi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 004626be  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004626c2  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004626c4  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004626c6  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004626c8  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004626cc  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004626d0  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004626d2  e899ffffff             -call 0x462670
    cpu.esp -= 4;
    sub_462670(app, cpu);
    if (cpu.terminate) return;
    // 004626d7  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004626db  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004626df  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004626e0  8d5c2404               -lea ebx, [esp + 4]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004626e4  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004626e6  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004626e7  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004626eb  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004626ed  e87effffff             -call 0x462670
    cpu.esp -= 4;
    sub_462670(app, cpu);
    if (cpu.terminate) return;
    // 004626f2  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004626f5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004626f6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004626f7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004626f8  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004626fb:
    // 004626fb  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004626ff  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00462703  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 00462705  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00462706  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00462708  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0046270a  e8d1c80000             -call 0x46efe0
    cpu.esp -= 4;
    sub_46efe0(app, cpu);
    if (cpu.terminate) return;
    // 0046270f  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00462712  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462713  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462714  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462715  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00462718:
    // 00462718  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0046271c  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0046271e  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 00462720  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00462721  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00462723  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00462727  e8b4c80000             -call 0x46efe0
    cpu.esp -= 4;
    sub_46efe0(app, cpu);
    if (cpu.terminate) return;
    // 0046272c  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0046272f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462730  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462731  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462732  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_462740(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00462740  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00462741  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00462742  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00462744  8b1558285000           -mov edx, dword ptr [0x502858]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5253208) /* 0x502858 */);
    // 0046274a  a1c4f74f00             -mov eax, dword ptr [0x4ff7c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5240772) /* 0x4ff7c4 */);
    // 0046274f  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00462751  83f808                 +cmp eax, 8
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
    // 00462754  7f03                   -jg 0x462759
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00462759;
    }
    // 00462756  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462757  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462758  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00462759:
    // 00462759  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046275a  a1c4f74f00             -mov eax, dword ptr [0x4ff7c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5240772) /* 0x4ff7c4 */);
    // 0046275f  a358285000             -mov dword ptr [0x502858], eax
    app->getMemory<x86::reg32>(x86::reg32(5253208) /* 0x502858 */) = cpu.eax;
    // 00462764  e8c7c00100             -call 0x47e830
    cpu.esp -= 4;
    sub_47e830(app, cpu);
    if (cpu.terminate) return;
    // 00462769  a80f                   +test al, 0xf
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 15 /*0xf*/));
    // 0046276b  7415                   -je 0x462782
    if (cpu.flags.zf)
    {
        goto L_0x00462782;
    }
    // 0046276d  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00462772  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00462774  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00462776  e8c9e9ffff             -call 0x461144
    cpu.esp -= 4;
    sub_461144(app, cpu);
    if (cpu.terminate) return;
    // 0046277b  8140205c0f0000         -add dword ptr [eax + 0x20], 0xf5c
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */)) += x86::reg32(x86::sreg32(3932 /*0xf5c*/));
L_0x00462782:
    // 00462782  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 00462787  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00462789  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046278b  e8b4e9ffff             -call 0x461144
    cpu.esp -= 4;
    sub_461144(app, cpu);
    if (cpu.terminate) return;
    // 00462790  8140205c0f0000         -add dword ptr [eax + 0x20], 0xf5c
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */)) += x86::reg32(x86::sreg32(3932 /*0xf5c*/));
    // 00462797  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462798  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462799  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046279a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4627a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004627a0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004627a1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004627a2  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004627a4  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004627a6  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004627a8  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004627aa  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004627ae  83e60f                 -and esi, 0xf
    cpu.esi &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004627b1  83f908                 +cmp ecx, 8
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
    // 004627b4  751e                   -jne 0x4627d4
    if (!cpu.flags.zf)
    {
        goto L_0x004627d4;
    }
L_0x004627b6:
    // 004627b6  c1e702                 -shl edi, 2
    cpu.edi <<= 2 /*0x2*/ % 32;
    // 004627b9  c1e604                 -shl esi, 4
    cpu.esi <<= 4 /*0x4*/ % 32;
    // 004627bc  01f7                   -add edi, esi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.esi));
    // 004627be  8b35c4f74f00           -mov esi, dword ptr [0x4ff7c4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5240772) /* 0x4ff7c4 */);
    // 004627c4  2bb758275000           -sub esi, dword ptr [edi + 0x502758]
    (cpu.esi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5252952) /* 0x502758 */)));
    // 004627ca  83fe02                 +cmp esi, 2
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
    // 004627cd  7f28                   -jg 0x4627f7
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004627f7;
    }
L_0x004627cf:
    // 004627cf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004627d0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004627d1  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004627d4:
    // 004627d4  83f907                 +cmp ecx, 7
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
    // 004627d7  74dd                   -je 0x4627b6
    if (cpu.flags.zf)
    {
        goto L_0x004627b6;
    }
    // 004627d9  83f909                 +cmp ecx, 9
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004627dc  74d8                   -je 0x4627b6
    if (cpu.flags.zf)
    {
        goto L_0x004627b6;
    }
    // 004627de  c1e702                 -shl edi, 2
    cpu.edi <<= 2 /*0x2*/ % 32;
    // 004627e1  c1e604                 -shl esi, 4
    cpu.esi <<= 4 /*0x4*/ % 32;
    // 004627e4  01f7                   -add edi, esi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.esi));
    // 004627e6  8b35c4f74f00           -mov esi, dword ptr [0x4ff7c4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5240772) /* 0x4ff7c4 */);
    // 004627ec  2bb758275000           -sub esi, dword ptr [edi + 0x502758]
    (cpu.esi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5252952) /* 0x502758 */)));
    // 004627f2  83fe0a                 +cmp esi, 0xa
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10 /*0xa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004627f5  7ed8                   -jle 0x4627cf
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004627cf;
    }
L_0x004627f7:
    // 004627f7  8b35c4f74f00           -mov esi, dword ptr [0x4ff7c4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5240772) /* 0x4ff7c4 */);
    // 004627fd  89b758275000           -mov dword ptr [edi + 0x502758], esi
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5252952) /* 0x502758 */) = cpu.esi;
    // 00462803  e83ce9ffff             -call 0x461144
    cpu.esp -= 4;
    sub_461144(app, cpu);
    if (cpu.terminate) return;
    // 00462808  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462809  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046280a  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_462810(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00462810  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00462811  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00462813  803800                 +cmp byte ptr [eax], 0
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
    // 00462816  7515                   -jne 0x46282d
    if (!cpu.flags.zf)
    {
        goto L_0x0046282d;
    }
    // 00462818  8b4504                 -mov eax, dword ptr [ebp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0046281b  e858aa0100             -call 0x47d278
    cpu.esp -= 4;
    sub_47d278(app, cpu);
    if (cpu.terminate) return;
    // 00462820  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00462822  7402                   -je 0x462826
    if (cpu.flags.zf)
    {
        goto L_0x00462826;
    }
    // 00462824  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462825  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00462826:
    // 00462826  e8b6de0200             -call 0x4906e1
    cpu.esp -= 4;
    sub_4906e1(app, cpu);
    if (cpu.terminate) return;
    // 0046282b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046282c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046282d:
    // 0046282d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046282e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046282f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00462830  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00462832  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00462834  8b7508                 -mov esi, dword ptr [ebp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */);
    // 00462837  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00462838  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046283a  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0046283d  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046283f  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 00462841  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 00462844  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 00462846  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462847  015d08                 -add dword ptr [ebp + 8], ebx
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(8) /* 0x8 */)) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0046284a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046284b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046284c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046284d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046284e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_462850(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00462850  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00462851  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00462852  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00462855  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00462857  803800                 +cmp byte ptr [eax], 0
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
    // 0046285a  7414                   -je 0x462870
    if (cpu.flags.zf)
    {
        goto L_0x00462870;
    }
    // 0046285c  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0046285f  8a00                   -mov al, byte ptr [eax]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax);
    // 00462861  880424                 -mov byte ptr [esp], al
    app->getMemory<x86::reg8>(cpu.esp) = cpu.al;
    // 00462864  ff4208                 -inc dword ptr [edx + 8]
    (app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */))++;
L_0x00462867:
    // 00462867  8a0424                 -mov al, byte ptr [esp]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp);
    // 0046286a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0046286d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046286e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046286f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00462870:
    // 00462870  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00462875  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00462878  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0046287a  e8f9a90100             -call 0x47d278
    cpu.esp -= 4;
    sub_47d278(app, cpu);
    if (cpu.terminate) return;
    // 0046287f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00462881  75e4                   -jne 0x462867
    if (!cpu.flags.zf)
    {
        goto L_0x00462867;
    }
    // 00462883  e859de0200             -call 0x4906e1
    cpu.esp -= 4;
    sub_4906e1(app, cpu);
    if (cpu.terminate) return;
    // 00462888  8a0424                 -mov al, byte ptr [esp]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp);
    // 0046288b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0046288e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046288f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462890  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4628a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004628a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004628a1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004628a2  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004628a5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004628a7  803800                 +cmp byte ptr [eax], 0
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
    // 004628aa  7415                   -je 0x4628c1
    if (cpu.flags.zf)
    {
        goto L_0x004628c1;
    }
    // 004628ac  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004628af  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004628b1  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004628b4  83420804               -add dword ptr [edx + 8], 4
    (app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */)) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004628b8:
    // 004628b8  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004628bb  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004628be  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004628bf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004628c0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004628c1:
    // 004628c1  bb04000000             -mov ebx, 4
    cpu.ebx = 4 /*0x4*/;
    // 004628c6  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004628c9  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004628cb  e8a8a90100             -call 0x47d278
    cpu.esp -= 4;
    sub_47d278(app, cpu);
    if (cpu.terminate) return;
    // 004628d0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004628d2  75e4                   -jne 0x4628b8
    if (!cpu.flags.zf)
    {
        goto L_0x004628b8;
    }
    // 004628d4  e808de0200             -call 0x4906e1
    cpu.esp -= 4;
    sub_4906e1(app, cpu);
    if (cpu.terminate) return;
    // 004628d9  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004628dc  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004628df  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004628e0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004628e1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4628f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004628f0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004628f1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004628f3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004628f5  741c                   -je 0x462913
    if (cpu.flags.zf)
    {
        goto L_0x00462913;
    }
    // 004628f7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004628f8  803800                 +cmp byte ptr [eax], 0
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
    // 004628fb  750e                   -jne 0x46290b
    if (!cpu.flags.zf)
    {
        goto L_0x0046290b;
    }
    // 004628fd  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00462900  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00462902  7407                   -je 0x46290b
    if (cpu.flags.zf)
    {
        goto L_0x0046290b;
    }
    // 00462904  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00462906  e865a90100             -call 0x47d270
    cpu.esp -= 4;
    sub_47d270(app, cpu);
    if (cpu.terminate) return;
L_0x0046290b:
    // 0046290b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0046290d  e87a7d0100             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
    // 00462912  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00462913:
    // 00462913  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462914  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_462920(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00462920  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00462921  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00462922  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00462923  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00462924  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00462927  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00462929  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0046292b  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 0046292f  ba9cd64b00             -mov edx, 0x4bd69c
    cpu.edx = 4970140 /*0x4bd69c*/;
    // 00462934  b90c000000             -mov ecx, 0xc
    cpu.ecx = 12 /*0xc*/;
    // 00462939  bb20000000             -mov ebx, 0x20
    cpu.ebx = 32 /*0x20*/;
    // 0046293e  b8bcd64b00             -mov eax, 0x4bd6bc
    cpu.eax = 4970172 /*0x4bd6bc*/;
    // 00462943  891578a64c00           -mov dword ptr [0x4ca678], edx
    app->getMemory<x86::reg32>(x86::reg32(5023352) /* 0x4ca678 */) = cpu.edx;
    // 00462949  890d7ca64c00           -mov dword ptr [0x4ca67c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5023356) /* 0x4ca67c */) = cpu.ecx;
    // 0046294f  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00462954  ba0c000000             -mov edx, 0xc
    cpu.edx = 12 /*0xc*/;
    // 00462959  e8f6780100             -call 0x47a254
    cpu.esp -= 4;
    sub_47a254(app, cpu);
    if (cpu.terminate) return;
    // 0046295e  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00462960  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00462962  7533                   -jne 0x462997
    if (!cpu.flags.zf)
    {
        goto L_0x00462997;
    }
    // 00462964  837c240800             +cmp dword ptr [esp + 8], 0
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
    // 00462969  7422                   -je 0x46298d
    if (cpu.flags.zf)
    {
        goto L_0x0046298d;
    }
    // 0046296b  bd9cd64b00             -mov ebp, 0x4bd69c
    cpu.ebp = 4970140 /*0x4bd69c*/;
    // 00462970  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 00462975  68c8d64b00             -push 0x4bd6c8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4970184 /*0x4bd6c8*/;
    cpu.esp -= 4;
    // 0046297a  892d78a64c00           -mov dword ptr [0x4ca678], ebp
    app->getMemory<x86::reg32>(x86::reg32(5023352) /* 0x4ca678 */) = cpu.ebp;
    // 00462980  a37ca64c00             -mov dword ptr [0x4ca67c], eax
    app->getMemory<x86::reg32>(x86::reg32(5023356) /* 0x4ca67c */) = cpu.eax;
    // 00462985  e8f6740100             -call 0x479e80
    cpu.esp -= 4;
    crt_exit(app, cpu);
    if (cpu.terminate) return;
    // 0046298a  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x0046298d:
    // 0046298d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046298f  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00462992  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462993  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462994  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462995  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462996  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00462997:
    // 00462997  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00462999  7543                   -jne 0x4629de
    if (!cpu.flags.zf)
    {
        goto L_0x004629de;
    }
    // 0046299b  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0046299d  753f                   -jne 0x4629de
    if (!cpu.flags.zf)
    {
        goto L_0x004629de;
    }
L_0x0046299f:
    // 0046299f  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004629a1  7407                   -je 0x4629aa
    if (cpu.flags.zf)
    {
        goto L_0x004629aa;
    }
    // 004629a3  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004629a5  e8e27c0100             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
L_0x004629aa:
    // 004629aa  837c240800             +cmp dword ptr [esp + 8], 0
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
    // 004629af  74dc                   -je 0x46298d
    if (cpu.flags.zf)
    {
        goto L_0x0046298d;
    }
    // 004629b1  bb9cd64b00             -mov ebx, 0x4bd69c
    cpu.ebx = 4970140 /*0x4bd69c*/;
    // 004629b6  be18000000             -mov esi, 0x18
    cpu.esi = 24 /*0x18*/;
    // 004629bb  68e8d64b00             -push 0x4bd6e8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4970216 /*0x4bd6e8*/;
    cpu.esp -= 4;
    // 004629c0  891d78a64c00           -mov dword ptr [0x4ca678], ebx
    app->getMemory<x86::reg32>(x86::reg32(5023352) /* 0x4ca678 */) = cpu.ebx;
    // 004629c6  89357ca64c00           -mov dword ptr [0x4ca67c], esi
    app->getMemory<x86::reg32>(x86::reg32(5023356) /* 0x4ca67c */) = cpu.esi;
    // 004629cc  e8af740100             -call 0x479e80
    cpu.esp -= 4;
    crt_exit(app, cpu);
    if (cpu.terminate) return;
    // 004629d1  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004629d4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004629d6  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004629d9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004629da  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004629db  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004629dc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004629dd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004629de:
    // 004629de  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004629e0  7404                   -je 0x4629e6
    if (cpu.flags.zf)
    {
        goto L_0x004629e6;
    }
    // 004629e2  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004629e4  75b9                   -jne 0x46299f
    if (!cpu.flags.zf)
    {
        goto L_0x0046299f;
    }
L_0x004629e6:
    // 004629e6  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004629e8  7417                   -je 0x462a01
    if (cpu.flags.zf)
    {
        goto L_0x00462a01;
    }
    // 004629ea  c7460400000000         -mov dword ptr [esi + 4], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 004629f1  c60601                 -mov byte ptr [esi], 1
    app->getMemory<x86::reg8>(cpu.esi) = 1 /*0x1*/;
    // 004629f4  896e08                 -mov dword ptr [esi + 8], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.ebp;
L_0x004629f7:
    // 004629f7  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004629f9  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004629fc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004629fd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004629fe  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004629ff  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462a00  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00462a01:
    // 00462a01  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00462a05  8d4c2404               -lea ecx, [esp + 4]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00462a09  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00462a0b  892c24                 -mov dword ptr [esp], ebp
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
    // 00462a0e  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 00462a12  8d5604                 -lea edx, [esi + 4]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00462a15  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00462a16  c60600                 -mov byte ptr [esi], 0
    app->getMemory<x86::reg8>(cpu.esi) = 0 /*0x0*/;
    // 00462a19  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00462a1b  896e08                 -mov dword ptr [esi + 8], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.ebp;
    // 00462a1e  e865a50100             -call 0x47cf88
    cpu.esp -= 4;
    sub_47cf88(app, cpu);
    if (cpu.terminate) return;
    // 00462a23  837e0400               +cmp dword ptr [esi + 4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00462a27  75ce                   -jne 0x4629f7
    if (!cpu.flags.zf)
    {
        goto L_0x004629f7;
    }
    // 00462a29  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00462a2b  e85c7c0100             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
    // 00462a30  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00462a32  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00462a35  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462a36  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462a37  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462a38  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462a39  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
/* data blob: 09000000000000000b000000020000000d000000040000000e000000050000000c000000030000000f0000000600000010000000070000001100000008000000 */
void Application::sub_462a80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00462a80  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_462a90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00462a90  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00462a91  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00462a92  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00462a93  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00462a94  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00462a95  81ec04010000           -sub esp, 0x104
    (cpu.esp) -= x86::reg32(x86::sreg32(260 /*0x104*/));
    // 00462a9b  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00462a9d  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00462a9f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00462aa1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00462aa2:
    // 00462aa2  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00462aa4  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00462aa6  3c00                   +cmp al, 0
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
    // 00462aa8  7410                   -je 0x462aba
    if (cpu.flags.zf)
    {
        goto L_0x00462aba;
    }
    // 00462aaa  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00462aad  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00462ab0  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00462ab3  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00462ab6  3c00                   +cmp al, 0
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
    // 00462ab8  75e8                   -jne 0x462aa2
    if (!cpu.flags.zf)
    {
        goto L_0x00462aa2;
    }
L_0x00462aba:
    // 00462aba  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462abb  bed0d84b00             -mov esi, 0x4bd8d0
    cpu.esi = 4970704 /*0x4bd8d0*/;
    // 00462ac0  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00462ac2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00462ac4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00462ac5  2bc9                   +sub ecx, ecx
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
    // 00462ac7  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00462ac8  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 00462aca  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00462acc  4f                     -dec edi
    (cpu.edi)--;
L_0x00462acd:
    // 00462acd  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00462acf  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00462ad1  3c00                   +cmp al, 0
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
    // 00462ad3  7410                   -je 0x462ae5
    if (cpu.flags.zf)
    {
        goto L_0x00462ae5;
    }
    // 00462ad5  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00462ad8  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00462adb  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00462ade  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00462ae1  3c00                   +cmp al, 0
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
    // 00462ae3  75e8                   -jne 0x462acd
    if (!cpu.flags.zf)
    {
        goto L_0x00462acd;
    }
L_0x00462ae5:
    // 00462ae5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462ae6  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00462ae8  e8839d0100             -call 0x47c870
    cpu.esp -= 4;
    sub_47c870(app, cpu);
    if (cpu.terminate) return;
    // 00462aed  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00462aef  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00462af1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00462af3  8d842400010000         -lea eax, [esp + 0x100]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00462afa  e845830100             -call 0x47ae44
    cpu.esp -= 4;
    sub_47ae44(app, cpu);
    if (cpu.terminate) return;
    // 00462aff  83f807                 +cmp eax, 7
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
    // 00462b02  742f                   -je 0x462b33
    if (cpu.flags.zf)
    {
        goto L_0x00462b33;
    }
L_0x00462b04:
    // 00462b04  8d04ad00000000         -lea eax, [ebp*4]
    cpu.eax = x86::reg32(cpu.ebp * 4);
    // 00462b0b  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00462b0d  8d0c8500000000         -lea ecx, [eax*4]
    cpu.ecx = x86::reg32(cpu.eax * 4);
    // 00462b14  8b842400010000         -mov eax, dword ptr [esp + 0x100]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00462b1b  899944874d00           -mov dword ptr [ecx + 0x4d8744], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5080900) /* 0x4d8744 */) = cpu.ebx;
    // 00462b21  89813c874d00           -mov dword ptr [ecx + 0x4d873c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5080892) /* 0x4d873c */) = cpu.eax;
    // 00462b27  81c404010000           -add esp, 0x104
    (cpu.esp) += x86::reg32(x86::sreg32(260 /*0x104*/));
    // 00462b2d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462b2e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462b2f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462b30  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462b31  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462b32  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00462b33:
    // 00462b33  bae0d74b00             -mov edx, 0x4bd7e0
    cpu.edx = 4970464 /*0x4bd7e0*/;
    // 00462b38  bb10030000             -mov ebx, 0x310
    cpu.ebx = 784 /*0x310*/;
    // 00462b3d  8b842400010000         -mov eax, dword ptr [esp + 0x100]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00462b44  891578a64c00           -mov dword ptr [0x4ca678], edx
    app->getMemory<x86::reg32>(x86::reg32(5023352) /* 0x4ca678 */) = cpu.edx;
    // 00462b4a  891d7ca64c00           -mov dword ptr [0x4ca67c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5023356) /* 0x4ca67c */) = cpu.ebx;
    // 00462b50  e8eb800100             -call 0x47ac40
    cpu.esp -= 4;
    sub_47ac40(app, cpu);
    if (cpu.terminate) return;
    // 00462b55  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00462b57  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00462b59  b8d8d84b00             -mov eax, 0x4bd8d8
    cpu.eax = 4970712 /*0x4bd8d8*/;
    // 00462b5e  e8c5760100             -call 0x47a228
    cpu.esp -= 4;
    sub_47a228(app, cpu);
    if (cpu.terminate) return;
    // 00462b63  8b942400010000         -mov edx, dword ptr [esp + 0x100]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00462b6a  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00462b6c  e887810100             -call 0x47acf8
    cpu.esp -= 4;
    sub_47acf8(app, cpu);
    if (cpu.terminate) return;
    // 00462b71  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00462b73  e8147b0100             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
    // 00462b78  eb8a                   -jmp 0x462b04
    goto L_0x00462b04;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_462b80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00462b80  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00462b81  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00462b86  e859930100             -call 0x47bee4
    cpu.esp -= 4;
    sub_47bee4(app, cpu);
    if (cpu.terminate) return;
    // 00462b8b  8b1544874d00           -mov edx, dword ptr [0x4d8744]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5080900) /* 0x4d8744 */);
    // 00462b91  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00462b93  7502                   -jne 0x462b97
    if (!cpu.flags.zf)
    {
        goto L_0x00462b97;
    }
    // 00462b95  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462b96  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00462b97:
    // 00462b97  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00462b98  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00462b9a  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00462b9c  e8eb7a0100             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
    // 00462ba1  890d44874d00           -mov dword ptr [0x4d8744], ecx
    app->getMemory<x86::reg32>(x86::reg32(5080900) /* 0x4d8744 */) = cpu.ecx;
    // 00462ba7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462ba8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462ba9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_462bb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00462bb0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00462bb1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00462bb2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00462bb3  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00462bb5:
    // 00462bb5  8b8a44874d00           -mov ecx, dword ptr [edx + 0x4d8744]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5080900) /* 0x4d8744 */);
    // 00462bbb  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00462bbd  750c                   -jne 0x462bcb
    if (!cpu.flags.zf)
    {
        goto L_0x00462bcb;
    }
    // 00462bbf  83c20c                 -add edx, 0xc
    (cpu.edx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00462bc2  83fa6c                 +cmp edx, 0x6c
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(108 /*0x6c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00462bc5  75ee                   -jne 0x462bb5
    if (!cpu.flags.zf)
    {
        goto L_0x00462bb5;
    }
    // 00462bc7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462bc8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462bc9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462bca  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00462bcb:
    // 00462bcb  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00462bcd  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00462bcf  e8b87a0100             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
    // 00462bd4  899a44874d00           -mov dword ptr [edx + 0x4d8744], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5080900) /* 0x4d8744 */) = cpu.ebx;
    // 00462bda  83c20c                 -add edx, 0xc
    (cpu.edx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00462bdd  83fa6c                 +cmp edx, 0x6c
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(108 /*0x6c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00462be0  75d3                   -jne 0x462bb5
    if (!cpu.flags.zf)
    {
        goto L_0x00462bb5;
    }
    // 00462be2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462be3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462be4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462be5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_462bf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00462bf0  803dec014e0000         +cmp byte ptr [0x4e01ec], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5112300) /* 0x4e01ec */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00462bf7  7509                   -jne 0x462c02
    if (!cpu.flags.zf)
    {
        goto L_0x00462c02;
    }
    // 00462bf9  833d804f4c0000         +cmp dword ptr [0x4c4f80], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5001088) /* 0x4c4f80 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00462c00  7501                   -jne 0x462c03
    if (!cpu.flags.zf)
    {
        goto L_0x00462c03;
    }
L_0x00462c02:
    // 00462c02  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00462c03:
    // 00462c03  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00462c04  e867900200             -call 0x48bc70
    cpu.esp -= 4;
    sub_48bc70(app, cpu);
    if (cpu.terminate) return;
    // 00462c09  a1248d4c00             -mov eax, dword ptr [0x4c8d24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5016868) /* 0x4c8d24 */);
    // 00462c0e  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00462c10  e877700200             -call 0x489c8c
    cpu.esp -= 4;
    sub_489c8c(app, cpu);
    if (cpu.terminate) return;
    // 00462c15  890d248d4c00           -mov dword ptr [0x4c8d24], ecx
    app->getMemory<x86::reg32>(x86::reg32(5016868) /* 0x4c8d24 */) = cpu.ecx;
    // 00462c1b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462c1c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_462c20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00462c20  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00462c21  803dec014e0000         +cmp byte ptr [0x4e01ec], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5112300) /* 0x4e01ec */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00462c28  7509                   -jne 0x462c33
    if (!cpu.flags.zf)
    {
        goto L_0x00462c33;
    }
    // 00462c2a  833d804f4c0000         +cmp dword ptr [0x4c4f80], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5001088) /* 0x4c4f80 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00462c31  7502                   -jne 0x462c35
    if (!cpu.flags.zf)
    {
        goto L_0x00462c35;
    }
L_0x00462c33:
    // 00462c33  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462c34  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00462c35:
    // 00462c35  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00462c37  e844d80100             -call 0x480480
    cpu.esp -= 4;
    sub_480480(app, cpu);
    if (cpu.terminate) return;
    // 00462c3c  e8cb910200             -call 0x48be0c
    cpu.esp -= 4;
    sub_48be0c(app, cpu);
    if (cpu.terminate) return;
    // 00462c41  803d208d4c0000         +cmp byte ptr [0x4c8d20], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5016864) /* 0x4c8d20 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00462c48  7422                   -je 0x462c6c
    if (cpu.flags.zf)
    {
        goto L_0x00462c6c;
    }
    // 00462c4a  e821900200             -call 0x48bc70
    cpu.esp -= 4;
    sub_48bc70(app, cpu);
    if (cpu.terminate) return;
L_0x00462c4f:
    // 00462c4f  8b0d60285000           -mov ecx, dword ptr [0x502860]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5253216) /* 0x502860 */);
    // 00462c55  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00462c57  74da                   -je 0x462c33
    if (cpu.flags.zf)
    {
        goto L_0x00462c33;
    }
    // 00462c59  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00462c5a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00462c5c  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00462c5e  e8297a0100             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
    // 00462c63  891d60285000           -mov dword ptr [0x502860], ebx
    app->getMemory<x86::reg32>(x86::reg32(5253216) /* 0x502860 */) = cpu.ebx;
    // 00462c69  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462c6a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462c6b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00462c6c:
    // 00462c6c  e85bbc0200             -call 0x48e8cc
    cpu.esp -= 4;
    sub_48e8cc(app, cpu);
    if (cpu.terminate) return;
    // 00462c71  ebdc                   -jmp 0x462c4f
    goto L_0x00462c4f;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_462c80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00462c80  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00462c81  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00462c82  803dec014e0000         +cmp byte ptr [0x4e01ec], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5112300) /* 0x4e01ec */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00462c89  7509                   -jne 0x462c94
    if (!cpu.flags.zf)
    {
        goto L_0x00462c94;
    }
    // 00462c8b  833d804f4c0000         +cmp dword ptr [0x4c4f80], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5001088) /* 0x4c4f80 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00462c92  7503                   -jne 0x462c97
    if (!cpu.flags.zf)
    {
        goto L_0x00462c97;
    }
L_0x00462c94:
    // 00462c94  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462c95  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462c96  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00462c97:
    // 00462c97  b864000000             -mov eax, 0x64
    cpu.eax = 100 /*0x64*/;
    // 00462c9c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00462c9e  e8dd920100             -call 0x47bf80
    cpu.esp -= 4;
    sub_47bf80(app, cpu);
    if (cpu.terminate) return;
L_0x00462ca3:
    // 00462ca3  e838dc0200             -call 0x4908e0
    cpu.esp -= 4;
    sub_4908e0(app, cpu);
    if (cpu.terminate) return;
    // 00462ca8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00462caa  7e09                   -jle 0x462cb5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00462cb5;
    }
    // 00462cac  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00462cae  e88d6f0100             -call 0x479c40
    cpu.esp -= 4;
    sub_479c40(app, cpu);
    if (cpu.terminate) return;
    // 00462cb3  ebee                   -jmp 0x462ca3
    goto L_0x00462ca3;
L_0x00462cb5:
    // 00462cb5  e852910200             -call 0x48be0c
    cpu.esp -= 4;
    sub_48be0c(app, cpu);
    if (cpu.terminate) return;
    // 00462cba  803d208d4c0000         +cmp byte ptr [0x4c8d20], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5016864) /* 0x4c8d20 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00462cc1  7423                   -je 0x462ce6
    if (cpu.flags.zf)
    {
        goto L_0x00462ce6;
    }
    // 00462cc3  e8a88f0200             -call 0x48bc70
    cpu.esp -= 4;
    sub_48bc70(app, cpu);
    if (cpu.terminate) return;
L_0x00462cc8:
    // 00462cc8  8b0d60285000           -mov ecx, dword ptr [0x502860]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5253216) /* 0x502860 */);
    // 00462cce  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00462cd0  74c2                   -je 0x462c94
    if (cpu.flags.zf)
    {
        goto L_0x00462c94;
    }
    // 00462cd2  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00462cd3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00462cd5  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00462cd7  e8b0790100             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
    // 00462cdc  891d60285000           -mov dword ptr [0x502860], ebx
    app->getMemory<x86::reg32>(x86::reg32(5253216) /* 0x502860 */) = cpu.ebx;
    // 00462ce2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462ce3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462ce4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462ce5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00462ce6:
    // 00462ce6  e8e1bb0200             -call 0x48e8cc
    cpu.esp -= 4;
    sub_48e8cc(app, cpu);
    if (cpu.terminate) return;
    // 00462ceb  ebdb                   -jmp 0x462cc8
    goto L_0x00462cc8;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_462cf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00462cf0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00462cf1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00462cf2  81ec10010000           -sub esp, 0x110
    (cpu.esp) -= x86::reg32(x86::sreg32(272 /*0x110*/));
    // 00462cf8  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 00462cfa  83f863                 +cmp eax, 0x63
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(99 /*0x63*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00462cfd  7502                   -jne 0x462d01
    if (!cpu.flags.zf)
    {
        goto L_0x00462d01;
    }
    // 00462cff  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00462d01:
    // 00462d01  803dec014e0000         +cmp byte ptr [0x4e01ec], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5112300) /* 0x4e01ec */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00462d08  0f85d5000000           -jne 0x462de3
    if (!cpu.flags.zf)
    {
        goto L_0x00462de3;
    }
    // 00462d0e  833d804f4c0000         +cmp dword ptr [0x4c4f80], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5001088) /* 0x4c4f80 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00462d15  0f84c8000000           -je 0x462de3
    if (cpu.flags.zf)
    {
        goto L_0x00462de3;
    }
    // 00462d1b  83f813                 +cmp eax, 0x13
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(19 /*0x13*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00462d1e  0f8fbf000000           -jg 0x462de3
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00462de3;
    }
    // 00462d24  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00462d26  0f85c0000000           -jne 0x462dec
    if (!cpu.flags.zf)
    {
        goto L_0x00462dec;
    }
    // 00462d2c  a3984f4c00             -mov dword ptr [0x4c4f98], eax
    app->getMemory<x86::reg32>(x86::reg32(5001112) /* 0x4c4f98 */) = cpu.eax;
L_0x00462d31:
    // 00462d31  833d684f4c0001         +cmp dword ptr [0x4c4f68], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5001064) /* 0x4c4f68 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00462d38  7511                   -jne 0x462d4b
    if (!cpu.flags.zf)
    {
        goto L_0x00462d4b;
    }
    // 00462d3a  83f809                 +cmp eax, 9
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
    // 00462d3d  7d0c                   -jge 0x462d4b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00462d4b;
    }
    // 00462d3f  803d5f024e0000         +cmp byte ptr [0x4e025f], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5112415) /* 0x4e025f */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00462d46  7403                   -je 0x462d4b
    if (cpu.flags.zf)
    {
        goto L_0x00462d4b;
    }
    // 00462d48  83c009                 -add eax, 9
    (cpu.eax) += x86::reg32(x86::sreg32(9 /*0x9*/));
L_0x00462d4b:
    // 00462d4b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00462d4c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00462d4d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00462d4e  83f812                 +cmp eax, 0x12
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(18 /*0x12*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00462d51  0f84a4000000           -je 0x462dfb
    if (cpu.flags.zf)
    {
        goto L_0x00462dfb;
    }
    // 00462d57  8b1485d48d4c00         -mov edx, dword ptr [eax*4 + 0x4c8dd4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5017044) /* 0x4c8dd4 */ + cpu.eax * 4);
    // 00462d5e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00462d5f  8b0dc0074e00           -mov ecx, dword ptr [0x4e07c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5113792) /* 0x4e07c0 */);
    // 00462d65  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00462d66  6828d84b00             -push 0x4bd828
    app->getMemory<x86::reg32>(cpu.esp-4) = 4970536 /*0x4bd828*/;
    cpu.esp -= 4;
    // 00462d6b  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00462d6f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00462d70  e86c920100             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 00462d75  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x00462d78:
    // 00462d78  beacd84b00             -mov esi, 0x4bd8ac
    cpu.esi = 4970668 /*0x4bd8ac*/;
    // 00462d7d  8d7c240c               -lea edi, [esp + 0xc]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00462d81  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00462d82  2bc9                   +sub ecx, ecx
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
    // 00462d84  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00462d85  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 00462d87  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00462d89  4f                     -dec edi
    (cpu.edi)--;
L_0x00462d8a:
    // 00462d8a  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00462d8c  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00462d8e  3c00                   +cmp al, 0
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
    // 00462d90  7410                   -je 0x462da2
    if (cpu.flags.zf)
    {
        goto L_0x00462da2;
    }
    // 00462d92  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00462d95  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00462d98  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00462d9b  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00462d9e  3c00                   +cmp al, 0
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
    // 00462da0  75e8                   -jne 0x462d8a
    if (!cpu.flags.zf)
    {
        goto L_0x00462d8a;
    }
L_0x00462da2:
    // 00462da2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462da3  8d84240c010000         -lea eax, [esp + 0x10c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 00462daa  e8b1800100             -call 0x47ae60
    cpu.esp -= 4;
    sub_47ae60(app, cpu);
    if (cpu.terminate) return;
    // 00462daf  30c0                   -xor al, al
    cpu.al ^= x86::reg8(x86::sreg8(cpu.al));
    // 00462db1  8d94240c010000         -lea edx, [esp + 0x10c]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 00462db8  88842414010000         -mov byte ptr [esp + 0x114], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(276) /* 0x114 */) = cpu.al;
    // 00462dbf  a1248d4c00             -mov eax, dword ptr [0x4c8d24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5016868) /* 0x4c8d24 */);
    // 00462dc4  e8e78d0200             -call 0x48bbb0
    cpu.esp -= 4;
    sub_48bbb0(app, cpu);
    if (cpu.terminate) return;
    // 00462dc9  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00462dcd  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00462dcf  e8f88e0200             -call 0x48bccc
    cpu.esp -= 4;
    sub_48bccc(app, cpu);
    if (cpu.terminate) return;
    // 00462dd4  b864000000             -mov eax, 0x64
    cpu.eax = 100 /*0x64*/;
    // 00462dd9  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00462ddb  e8a0910100             -call 0x47bf80
    cpu.esp -= 4;
    sub_47bf80(app, cpu);
    if (cpu.terminate) return;
    // 00462de0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462de1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462de2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00462de3:
    // 00462de3  81c410010000           +add esp, 0x110
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(272 /*0x110*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00462de9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462dea  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462deb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00462dec:
    // 00462dec  c705984f4c0001000000   -mov dword ptr [0x4c4f98], 1
    app->getMemory<x86::reg32>(x86::reg32(5001112) /* 0x4c4f98 */) = 1 /*0x1*/;
    // 00462df6  e936ffffff             -jmp 0x462d31
    goto L_0x00462d31;
L_0x00462dfb:
    // 00462dfb  803d268e4c0000         +cmp byte ptr [0x4c8e26], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5017126) /* 0x4c8e26 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00462e02  742d                   -je 0x462e31
    if (cpu.flags.zf)
    {
        goto L_0x00462e31;
    }
    // 00462e04  a1c0074e00             -mov eax, dword ptr [0x4e07c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5113792) /* 0x4e07c0 */);
    // 00462e09  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00462e0a  6830d84b00             -push 0x4bd830
    app->getMemory<x86::reg32>(cpu.esp-4) = 4970544 /*0x4bd830*/;
    cpu.esp -= 4;
L_0x00462e0f:
    // 00462e0f  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00462e13  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00462e14  e8c8910100             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 00462e19  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00462e1c  803d268e4c0000         +cmp byte ptr [0x4c8e26], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5017126) /* 0x4c8e26 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00462e23  751a                   -jne 0x462e3f
    if (!cpu.flags.zf)
    {
        goto L_0x00462e3f;
    }
    // 00462e25  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
    // 00462e27  a2268e4c00             -mov byte ptr [0x4c8e26], al
    app->getMemory<x86::reg8>(x86::reg32(5017126) /* 0x4c8e26 */) = cpu.al;
    // 00462e2c  e947ffffff             -jmp 0x462d78
    goto L_0x00462d78;
L_0x00462e31:
    // 00462e31  8b2dc0074e00           -mov ebp, dword ptr [0x4e07c0]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5113792) /* 0x4e07c0 */);
    // 00462e37  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00462e38  6838d84b00             -push 0x4bd838
    app->getMemory<x86::reg32>(cpu.esp-4) = 4970552 /*0x4bd838*/;
    cpu.esp -= 4;
    // 00462e3d  ebd0                   -jmp 0x462e0f
    goto L_0x00462e0f;
L_0x00462e3f:
    // 00462e3f  30c0                   +xor al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al ^= x86::reg8(x86::sreg8(cpu.al))));
    // 00462e41  a2268e4c00             -mov byte ptr [0x4c8e26], al
    app->getMemory<x86::reg8>(x86::reg32(5017126) /* 0x4c8e26 */) = cpu.al;
    // 00462e46  e92dffffff             -jmp 0x462d78
    goto L_0x00462d78;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_462e50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00462e50  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00462e51  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00462e52  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00462e53  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00462e54  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00462e55  81ec04010000           -sub esp, 0x104
    (cpu.esp) -= x86::reg32(x86::sreg32(260 /*0x104*/));
    // 00462e5b  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00462e5d  89942400010000         -mov dword ptr [esp + 0x100], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */) = cpu.edx;
    // 00462e64  bbdc050000             -mov ebx, 0x5dc
    cpu.ebx = 1500 /*0x5dc*/;
    // 00462e69  83f863                 +cmp eax, 0x63
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(99 /*0x63*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00462e6c  7502                   -jne 0x462e70
    if (!cpu.flags.zf)
    {
        goto L_0x00462e70;
    }
    // 00462e6e  31c5                   -xor ebp, eax
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00462e70:
    // 00462e70  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 00462e72  8a15ec014e00           -mov dl, byte ptr [0x4e01ec]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5112300) /* 0x4e01ec */);
    // 00462e78  8825208d4c00           -mov byte ptr [0x4c8d20], ah
    app->getMemory<x86::reg8>(x86::reg32(5016864) /* 0x4c8d20 */) = cpu.ah;
    // 00462e7e  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 00462e80  7543                   -jne 0x462ec5
    if (!cpu.flags.zf)
    {
        goto L_0x00462ec5;
    }
    // 00462e82  833d804f4c0000         +cmp dword ptr [0x4c4f80], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5001088) /* 0x4c4f80 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00462e89  743a                   -je 0x462ec5
    if (cpu.flags.zf)
    {
        goto L_0x00462ec5;
    }
    // 00462e8b  83fd13                 +cmp ebp, 0x13
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(19 /*0x13*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00462e8e  7f35                   -jg 0x462ec5
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00462ec5;
    }
    // 00462e90  803d5f024e0000         +cmp byte ptr [0x4e025f], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5112415) /* 0x4e025f */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00462e97  7538                   -jne 0x462ed1
    if (!cpu.flags.zf)
    {
        goto L_0x00462ed1;
    }
    // 00462e99  83fd09                 +cmp ebp, 9
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00462e9c  7d33                   -jge 0x462ed1
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00462ed1;
    }
    // 00462e9e  803d60024e0000         +cmp byte ptr [0x4e0260], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5112416) /* 0x4e0260 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00462ea5  7609                   -jbe 0x462eb0
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x00462eb0;
    }
    // 00462ea7  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00462ea9  e8c2010000             -call 0x463070
    cpu.esp -= 4;
    sub_463070(app, cpu);
    if (cpu.terminate) return;
    // 00462eae  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
L_0x00462eb0:
    // 00462eb0  8b942400010000         -mov edx, dword ptr [esp + 0x100]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00462eb7  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00462eb9  e832feffff             -call 0x462cf0
    cpu.esp -= 4;
    sub_462cf0(app, cpu);
    if (cpu.terminate) return;
    // 00462ebe  c605208d4c0001         -mov byte ptr [0x4c8d20], 1
    app->getMemory<x86::reg8>(x86::reg32(5016864) /* 0x4c8d20 */) = 1 /*0x1*/;
L_0x00462ec5:
    // 00462ec5  81c404010000           -add esp, 0x104
    (cpu.esp) += x86::reg32(x86::sreg32(260 /*0x104*/));
    // 00462ecb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462ecc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462ecd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462ece  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462ecf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462ed0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00462ed1:
    // 00462ed1  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00462ed3  0f852f010000           -jne 0x463008
    if (!cpu.flags.zf)
    {
        goto L_0x00463008;
    }
    // 00462ed9  892d984f4c00           -mov dword ptr [0x4c4f98], ebp
    app->getMemory<x86::reg32>(x86::reg32(5001112) /* 0x4c4f98 */) = cpu.ebp;
L_0x00462edf:
    // 00462edf  833d684f4c0001         +cmp dword ptr [0x4c4f68], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5001064) /* 0x4c4f68 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00462ee6  7508                   -jne 0x462ef0
    if (!cpu.flags.zf)
    {
        goto L_0x00462ef0;
    }
    // 00462ee8  83fd09                 +cmp ebp, 9
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00462eeb  7d03                   -jge 0x462ef0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00462ef0;
    }
    // 00462eed  83c509                 -add ebp, 9
    (cpu.ebp) += x86::reg32(x86::sreg32(9 /*0x9*/));
L_0x00462ef0:
    // 00462ef0  83fd12                 +cmp ebp, 0x12
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(18 /*0x12*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00462ef3  0f841e010000           -je 0x463017
    if (cpu.flags.zf)
    {
        goto L_0x00463017;
    }
    // 00462ef9  8b0cadd48d4c00         -mov ecx, dword ptr [ebp*4 + 0x4c8dd4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5017044) /* 0x4c8dd4 */ + cpu.ebp * 4);
    // 00462f00  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00462f01  8b35c0074e00           -mov esi, dword ptr [0x4e07c0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5113792) /* 0x4e07c0 */);
    // 00462f07  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00462f08  6828d84b00             -push 0x4bd828
    app->getMemory<x86::reg32>(cpu.esp-4) = 4970536 /*0x4bd828*/;
    cpu.esp -= 4;
    // 00462f0d  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00462f11  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00462f12  e8ca900100             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 00462f17  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x00462f1a:
    // 00462f1a  be60d84b00             -mov esi, 0x4bd860
    cpu.esi = 4970592 /*0x4bd860*/;
    // 00462f1f  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00462f21  ba20000000             -mov edx, 0x20
    cpu.edx = 32 /*0x20*/;
    // 00462f26  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00462f27  2bc9                   +sub ecx, ecx
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
    // 00462f29  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00462f2a  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 00462f2c  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00462f2e  4f                     -dec edi
    (cpu.edi)--;
L_0x00462f2f:
    // 00462f2f  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00462f31  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00462f33  3c00                   +cmp al, 0
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
    // 00462f35  7410                   -je 0x462f47
    if (cpu.flags.zf)
    {
        goto L_0x00462f47;
    }
    // 00462f37  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00462f3a  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00462f3d  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00462f40  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00462f43  3c00                   +cmp al, 0
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
    // 00462f45  75e8                   -jne 0x462f2f
    if (!cpu.flags.zf)
    {
        goto L_0x00462f2f;
    }
L_0x00462f47:
    // 00462f47  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462f48  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00462f4a  e811990100             -call 0x47c860
    cpu.esp -= 4;
    sub_47c860(app, cpu);
    if (cpu.terminate) return;
    // 00462f4f  a360285000             -mov dword ptr [0x502860], eax
    app->getMemory<x86::reg32>(x86::reg32(5253216) /* 0x502860 */) = cpu.eax;
    // 00462f54  e85bb70200             -call 0x48e6b4
    cpu.esp -= 4;
    sub_48e6b4(app, cpu);
    if (cpu.terminate) return;
    // 00462f59  8b3da4074e00           -mov edi, dword ptr [0x4e07a4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5113764) /* 0x4e07a4 */);
    // 00462f5f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00462f60  68a4d84b00             -push 0x4bd8a4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4970660 /*0x4bd8a4*/;
    cpu.esp -= 4;
    // 00462f65  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00462f69  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00462f6a  be7cd84b00             -mov esi, 0x4bd87c
    cpu.esi = 4970620 /*0x4bd87c*/;
    // 00462f6f  e86d900100             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 00462f74  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00462f77  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00462f79  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00462f7b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00462f7c  2bc9                   +sub ecx, ecx
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
    // 00462f7e  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00462f7f  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 00462f81  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 00462f83  4f                     -dec edi
    (cpu.edi)--;
L_0x00462f84:
    // 00462f84  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00462f86  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00462f88  3c00                   +cmp al, 0
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
    // 00462f8a  7410                   -je 0x462f9c
    if (cpu.flags.zf)
    {
        goto L_0x00462f9c;
    }
    // 00462f8c  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00462f8f  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00462f92  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00462f95  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00462f98  3c00                   +cmp al, 0
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
    // 00462f9a  75e8                   -jne 0x462f84
    if (!cpu.flags.zf)
    {
        goto L_0x00462f84;
    }
L_0x00462f9c:
    // 00462f9c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00462f9d  a1248d4c00             -mov eax, dword ptr [0x4c8d24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5016868) /* 0x4c8d24 */);
    // 00462fa2  e8a9b70200             -call 0x48e750
    cpu.esp -= 4;
    sub_48e750(app, cpu);
    if (cpu.terminate) return;
    // 00462fa7  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00462fac  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00462fae  e8cd8f0100             -call 0x47bf80
    cpu.esp -= 4;
    sub_47bf80(app, cpu);
    if (cpu.terminate) return;
    // 00462fb3  8b942400010000         -mov edx, dword ptr [esp + 0x100]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */);
    // 00462fba  b864000000             -mov eax, 0x64
    cpu.eax = 100 /*0x64*/;
    // 00462fbf  e8bc8f0100             -call 0x47bf80
    cpu.esp -= 4;
    sub_47bf80(app, cpu);
    if (cpu.terminate) return;
    // 00462fc4  833d48f54d0000         +cmp dword ptr [0x4df548], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5109064) /* 0x4df548 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00462fcb  0f84f4feffff           -je 0x462ec5
    if (cpu.flags.zf)
    {
        goto L_0x00462ec5;
    }
    // 00462fd1  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00462fd3  0f84ecfeffff           -je 0x462ec5
    if (cpu.flags.zf)
    {
        goto L_0x00462ec5;
    }
    // 00462fd9  83fd09                 +cmp ebp, 9
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00462fdc  0f84e3feffff           -je 0x462ec5
    if (cpu.flags.zf)
    {
        goto L_0x00462ec5;
    }
    // 00462fe2  8a04ad348d4c00         -mov al, byte ptr [ebp*4 + 0x4c8d34]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5016884) /* 0x4c8d34 */ + cpu.ebp * 4);
    // 00462fe9  a2644f4c00             -mov byte ptr [0x4c4f64], al
    app->getMemory<x86::reg8>(x86::reg32(5001060) /* 0x4c4f64 */) = cpu.al;
    // 00462fee  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00462ff0  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00462ff2  a0644f4c00             -mov al, byte ptr [0x4c4f64]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5001060) /* 0x4c4f64 */);
    // 00462ff7  e848b80200             -call 0x48e844
    cpu.esp -= 4;
    sub_48e844(app, cpu);
    if (cpu.terminate) return;
    // 00462ffc  81c404010000           +add esp, 0x104
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(260 /*0x104*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00463002  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463003  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463004  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463005  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463006  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463007  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00463008:
    // 00463008  c705984f4c0001000000   -mov dword ptr [0x4c4f98], 1
    app->getMemory<x86::reg32>(x86::reg32(5001112) /* 0x4c4f98 */) = 1 /*0x1*/;
    // 00463012  e9c8feffff             -jmp 0x462edf
    goto L_0x00462edf;
L_0x00463017:
    // 00463017  803d258e4c0000         +cmp byte ptr [0x4c8e25], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5017125) /* 0x4c8e25 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0046301e  742e                   -je 0x46304e
    if (cpu.flags.zf)
    {
        goto L_0x0046304e;
    }
    // 00463020  8b15c0074e00           -mov edx, dword ptr [0x4e07c0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5113792) /* 0x4e07c0 */);
    // 00463026  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00463027  6830d84b00             -push 0x4bd830
    app->getMemory<x86::reg32>(cpu.esp-4) = 4970544 /*0x4bd830*/;
    cpu.esp -= 4;
L_0x0046302c:
    // 0046302c  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00463030  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00463031  e8ab8f0100             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 00463036  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00463039  803d258e4c0000         +cmp byte ptr [0x4c8e25], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5017125) /* 0x4c8e25 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00463040  7519                   -jne 0x46305b
    if (!cpu.flags.zf)
    {
        goto L_0x0046305b;
    }
    // 00463042  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
    // 00463044  a2258e4c00             -mov byte ptr [0x4c8e25], al
    app->getMemory<x86::reg8>(x86::reg32(5017125) /* 0x4c8e25 */) = cpu.al;
    // 00463049  e9ccfeffff             -jmp 0x462f1a
    goto L_0x00462f1a;
L_0x0046304e:
    // 0046304e  a1c0074e00             -mov eax, dword ptr [0x4e07c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5113792) /* 0x4e07c0 */);
    // 00463053  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00463054  6838d84b00             -push 0x4bd838
    app->getMemory<x86::reg32>(cpu.esp-4) = 4970552 /*0x4bd838*/;
    cpu.esp -= 4;
    // 00463059  ebd1                   -jmp 0x46302c
    goto L_0x0046302c;
L_0x0046305b:
    // 0046305b  30c0                   +xor al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al ^= x86::reg8(x86::sreg8(cpu.al))));
    // 0046305d  a2258e4c00             -mov byte ptr [0x4c8e25], al
    app->getMemory<x86::reg8>(x86::reg32(5017125) /* 0x4c8e25 */) = cpu.al;
    // 00463062  e9b3feffff             -jmp 0x462f1a
    goto L_0x00462f1a;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_463070(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00463070  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00463071  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00463072  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00463073  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00463074  83ec40                 -sub esp, 0x40
    (cpu.esp) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00463077  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 0046307c  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0046307e  be402a4600             -mov esi, 0x462a40
    cpu.esi = 4598336 /*0x462a40*/;
    // 00463083  8a155f024e00           -mov dl, byte ptr [0x4e025f]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5112415) /* 0x4e025f */);
    // 00463089  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0046308b  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 0046308d  7513                   -jne 0x4630a2
    if (!cpu.flags.zf)
    {
        goto L_0x004630a2;
    }
    // 0046308f  8a3560024e00           -mov dh, byte ptr [0x4e0260]
    cpu.dh = app->getMemory<x86::reg8>(x86::reg32(5112416) /* 0x4e0260 */);
    // 00463095  80fe11                 +cmp dh, 0x11
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(17 /*0x11*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00463098  7410                   -je 0x4630aa
    if (cpu.flags.zf)
    {
        goto L_0x004630aa;
    }
    // 0046309a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046309c  88f0                   -mov al, dh
    cpu.al = cpu.dh;
    // 0046309e  8b4484fc               -mov eax, dword ptr [esp + eax*4 - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(-4) /* -0x4 */ + cpu.eax * 4);
L_0x004630a2:
    // 004630a2  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004630a5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004630a6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004630a7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004630a8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004630a9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004630aa:
    // 004630aa  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004630ab  8a1db4874d00           -mov bl, byte ptr [0x4d87b4]
    cpu.bl = app->getMemory<x86::reg8>(x86::reg32(5081012) /* 0x4d87b4 */);
    // 004630b1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004630b3  88da                   -mov dl, bl
    cpu.dl = cpu.bl;
    // 004630b5  8a92a94f4c00           -mov dl, byte ptr [edx + 0x4c4fa9]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5001129) /* 0x4c4fa9 */);
    // 004630bb  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004630c1  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 004630c6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004630c8  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004630cb  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004630cd  fec3                   -inc bl
    (cpu.bl)++;
    // 004630cf  881db4874d00           -mov byte ptr [0x4d87b4], bl
    app->getMemory<x86::reg8>(x86::reg32(5081012) /* 0x4d87b4 */) = cpu.bl;
    // 004630d5  8b449404               -mov eax, dword ptr [esp + edx*4 + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */ + cpu.edx * 4);
    // 004630d9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004630da  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004630dd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004630de  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004630df  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004630e0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004630e1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4630f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004630f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004630f1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004630f2  81ec04010000           -sub esp, 0x104
    (cpu.esp) -= x86::reg32(x86::sreg32(260 /*0x104*/));
    // 004630f8  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004630fa  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004630fc  c7842400010000dc050000 -mov dword ptr [esp + 0x100], 0x5dc
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(256) /* 0x100 */) = 1500 /*0x5dc*/;
    // 00463107  83f863                 +cmp eax, 0x63
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(99 /*0x63*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046310a  7502                   -jne 0x46310e
    if (!cpu.flags.zf)
    {
        goto L_0x0046310e;
    }
    // 0046310c  31c3                   -xor ebx, eax
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0046310e:
    // 0046310e  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 00463110  8a15ec014e00           -mov dl, byte ptr [0x4e01ec]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5112300) /* 0x4e01ec */);
    // 00463116  8825208d4c00           -mov byte ptr [0x4c8d20], ah
    app->getMemory<x86::reg8>(x86::reg32(5016864) /* 0x4c8d20 */) = cpu.ah;
    // 0046311c  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 0046311e  0f854d010000           -jne 0x463271
    if (!cpu.flags.zf)
    {
        goto L_0x00463271;
    }
    // 00463124  833d804f4c0000         +cmp dword ptr [0x4c4f80], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5001088) /* 0x4c4f80 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046312b  0f8440010000           -je 0x463271
    if (cpu.flags.zf)
    {
        goto L_0x00463271;
    }
    // 00463131  83fb13                 +cmp ebx, 0x13
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(19 /*0x13*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00463134  0f8f37010000           -jg 0x463271
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00463271;
    }
    // 0046313a  803d5f024e0000         +cmp byte ptr [0x4e025f], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5112415) /* 0x4e025f */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00463141  7509                   -jne 0x46314c
    if (!cpu.flags.zf)
    {
        goto L_0x0046314c;
    }
    // 00463143  83fb09                 +cmp ebx, 9
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00463146  0f8c2e010000           -jl 0x46327a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046327a;
    }
L_0x0046314c:
    // 0046314c  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0046314e  0f853f010000           -jne 0x463293
    if (!cpu.flags.zf)
    {
        goto L_0x00463293;
    }
    // 00463154  891d984f4c00           -mov dword ptr [0x4c4f98], ebx
    app->getMemory<x86::reg32>(x86::reg32(5001112) /* 0x4c4f98 */) = cpu.ebx;
L_0x0046315a:
    // 0046315a  833d684f4c0001         +cmp dword ptr [0x4c4f68], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5001064) /* 0x4c4f68 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00463161  7508                   -jne 0x46316b
    if (!cpu.flags.zf)
    {
        goto L_0x0046316b;
    }
    // 00463163  83fb09                 +cmp ebx, 9
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00463166  7d03                   -jge 0x46316b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0046316b;
    }
    // 00463168  83c309                 -add ebx, 9
    (cpu.ebx) += x86::reg32(x86::sreg32(9 /*0x9*/));
L_0x0046316b:
    // 0046316b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046316c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046316d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046316e  83fb12                 +cmp ebx, 0x12
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(18 /*0x12*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00463171  0f842b010000           -je 0x4632a2
    if (cpu.flags.zf)
    {
        goto L_0x004632a2;
    }
    // 00463177  8b349dd48d4c00         -mov esi, dword ptr [ebx*4 + 0x4c8dd4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5017044) /* 0x4c8dd4 */ + cpu.ebx * 4);
    // 0046317e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0046317f  8b3dc0074e00           -mov edi, dword ptr [0x4e07c0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5113792) /* 0x4e07c0 */);
    // 00463185  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00463186  6828d84b00             -push 0x4bd828
    app->getMemory<x86::reg32>(cpu.esp-4) = 4970536 /*0x4bd828*/;
    cpu.esp -= 4;
    // 0046318b  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0046318f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00463190  e84c8e0100             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 00463195  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x00463198:
    // 00463198  be60d84b00             -mov esi, 0x4bd860
    cpu.esi = 4970592 /*0x4bd860*/;
    // 0046319d  8d7c240c               -lea edi, [esp + 0xc]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004631a1  ba20000000             -mov edx, 0x20
    cpu.edx = 32 /*0x20*/;
    // 004631a6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004631a7  2bc9                   +sub ecx, ecx
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
    // 004631a9  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004631aa  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 004631ac  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004631ae  4f                     -dec edi
    (cpu.edi)--;
L_0x004631af:
    // 004631af  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004631b1  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004631b3  3c00                   +cmp al, 0
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
    // 004631b5  7410                   -je 0x4631c7
    if (cpu.flags.zf)
    {
        goto L_0x004631c7;
    }
    // 004631b7  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004631ba  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004631bd  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004631c0  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004631c3  3c00                   +cmp al, 0
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
    // 004631c5  75e8                   -jne 0x4631af
    if (!cpu.flags.zf)
    {
        goto L_0x004631af;
    }
L_0x004631c7:
    // 004631c7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004631c8  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004631cc  e88f960100             -call 0x47c860
    cpu.esp -= 4;
    sub_47c860(app, cpu);
    if (cpu.terminate) return;
    // 004631d1  a360285000             -mov dword ptr [0x502860], eax
    app->getMemory<x86::reg32>(x86::reg32(5253216) /* 0x502860 */) = cpu.eax;
    // 004631d6  e8d9b40200             -call 0x48e6b4
    cpu.esp -= 4;
    sub_48e6b4(app, cpu);
    if (cpu.terminate) return;
    // 004631db  83fb12                 +cmp ebx, 0x12
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(18 /*0x12*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004631de  0f8412010000           -je 0x4632f6
    if (cpu.flags.zf)
    {
        goto L_0x004632f6;
    }
    // 004631e4  8b0c9d848d4c00         -mov ecx, dword ptr [ebx*4 + 0x4c8d84]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5016964) /* 0x4c8d84 */ + cpu.ebx * 4);
    // 004631eb  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004631ec  8b1dc0074e00           -mov ebx, dword ptr [0x4e07c0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5113792) /* 0x4e07c0 */);
    // 004631f2  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004631f3  6828d84b00             -push 0x4bd828
    app->getMemory<x86::reg32>(cpu.esp-4) = 4970536 /*0x4bd828*/;
    cpu.esp -= 4;
    // 004631f8  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004631fc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004631fd  e8df8d0100             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 00463202  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x00463205:
    // 00463205  be7cd84b00             -mov esi, 0x4bd87c
    cpu.esi = 4970620 /*0x4bd87c*/;
    // 0046320a  8d7c240c               -lea edi, [esp + 0xc]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046320e  8b9c240c010000         -mov ebx, dword ptr [esp + 0x10c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 00463215  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00463216  2bc9                   +sub ecx, ecx
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
    // 00463218  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00463219  b000                   -mov al, 0
    cpu.al = 0 /*0x0*/;
    // 0046321b  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 0046321d  4f                     -dec edi
    (cpu.edi)--;
L_0x0046321e:
    // 0046321e  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00463220  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00463222  3c00                   +cmp al, 0
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
    // 00463224  7410                   -je 0x463236
    if (cpu.flags.zf)
    {
        goto L_0x00463236;
    }
    // 00463226  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00463229  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0046322c  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0046322f  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00463232  3c00                   +cmp al, 0
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
    // 00463234  75e8                   -jne 0x46321e
    if (!cpu.flags.zf)
    {
        goto L_0x0046321e;
    }
L_0x00463236:
    // 00463236  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463237  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00463239  8d54240c               -lea edx, [esp + 0xc]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046323d  e84eb10200             -call 0x48e390
    cpu.esp -= 4;
    sub_48e390(app, cpu);
    if (cpu.terminate) return;
    // 00463242  a1248d4c00             -mov eax, dword ptr [0x4c8d24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5016868) /* 0x4c8d24 */);
    // 00463247  e804b50200             -call 0x48e750
    cpu.esp -= 4;
    sub_48e750(app, cpu);
    if (cpu.terminate) return;
    // 0046324c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00463251  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00463253  e8288d0100             -call 0x47bf80
    cpu.esp -= 4;
    sub_47bf80(app, cpu);
    if (cpu.terminate) return;
    // 00463258  b87f000000             -mov eax, 0x7f
    cpu.eax = 127 /*0x7f*/;
    // 0046325d  e82eb10200             -call 0x48e390
    cpu.esp -= 4;
    sub_48e390(app, cpu);
    if (cpu.terminate) return;
    // 00463262  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00463264  b864000000             -mov eax, 0x64
    cpu.eax = 100 /*0x64*/;
    // 00463269  e8128d0100             -call 0x47bf80
    cpu.esp -= 4;
    sub_47bf80(app, cpu);
    if (cpu.terminate) return;
    // 0046326e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046326f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463270  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00463271:
    // 00463271  81c404010000           -add esp, 0x104
    (cpu.esp) += x86::reg32(x86::sreg32(260 /*0x104*/));
    // 00463277  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463278  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463279  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046327a:
    // 0046327a  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0046327c  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0046327e  e86dfaffff             -call 0x462cf0
    cpu.esp -= 4;
    sub_462cf0(app, cpu);
    if (cpu.terminate) return;
    // 00463283  c605208d4c0001         -mov byte ptr [0x4c8d20], 1
    app->getMemory<x86::reg8>(x86::reg32(5016864) /* 0x4c8d20 */) = 1 /*0x1*/;
    // 0046328a  81c404010000           +add esp, 0x104
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(260 /*0x104*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00463290  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463291  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463292  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00463293:
    // 00463293  c705984f4c0001000000   -mov dword ptr [0x4c4f98], 1
    app->getMemory<x86::reg32>(x86::reg32(5001112) /* 0x4c4f98 */) = 1 /*0x1*/;
    // 0046329d  e9b8feffff             -jmp 0x46315a
    goto L_0x0046315a;
L_0x004632a2:
    // 004632a2  803d248e4c0000         +cmp byte ptr [0x4c8e24], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5017124) /* 0x4c8e24 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004632a9  7529                   -jne 0x4632d4
    if (!cpu.flags.zf)
    {
        goto L_0x004632d4;
    }
    // 004632ab  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
L_0x004632ad:
    // 004632ad  a2248e4c00             -mov byte ptr [0x4c8e24], al
    app->getMemory<x86::reg8>(x86::reg32(5017124) /* 0x4c8e24 */) = cpu.al;
    // 004632b2  84c0                   +test al, al
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & cpu.al));
    // 004632b4  7422                   -je 0x4632d8
    if (cpu.flags.zf)
    {
        goto L_0x004632d8;
    }
    // 004632b6  8b0dc0074e00           -mov ecx, dword ptr [0x4e07c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5113792) /* 0x4e07c0 */);
    // 004632bc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004632bd  6830d84b00             -push 0x4bd830
    app->getMemory<x86::reg32>(cpu.esp-4) = 4970544 /*0x4bd830*/;
    cpu.esp -= 4;
    // 004632c2  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004632c6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004632c7  e8158d0100             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 004632cc  83c40c                 +add esp, 0xc
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
    // 004632cf  e9c4feffff             -jmp 0x463198
    goto L_0x00463198;
L_0x004632d4:
    // 004632d4  30c0                   +xor al, al
    cpu.clear_co();
    cpu.set_szp((cpu.al ^= x86::reg8(x86::sreg8(cpu.al))));
    // 004632d6  ebd5                   -jmp 0x4632ad
    goto L_0x004632ad;
L_0x004632d8:
    // 004632d8  8b15c0074e00           -mov edx, dword ptr [0x4e07c0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5113792) /* 0x4e07c0 */);
    // 004632de  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004632df  6838d84b00             -push 0x4bd838
    app->getMemory<x86::reg32>(cpu.esp-4) = 4970552 /*0x4bd838*/;
    cpu.esp -= 4;
    // 004632e4  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004632e8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004632e9  e8f38c0100             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 004632ee  83c40c                 +add esp, 0xc
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
    // 004632f1  e9a2feffff             -jmp 0x463198
    goto L_0x00463198;
L_0x004632f6:
    // 004632f6  803d248e4c0000         +cmp byte ptr [0x4c8e24], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5017124) /* 0x4c8e24 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004632fd  741e                   -je 0x46331d
    if (cpu.flags.zf)
    {
        goto L_0x0046331d;
    }
    // 004632ff  8b15c0074e00           -mov edx, dword ptr [0x4e07c0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5113792) /* 0x4e07c0 */);
    // 00463305  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00463306  6830d84b00             -push 0x4bd830
    app->getMemory<x86::reg32>(cpu.esp-4) = 4970544 /*0x4bd830*/;
    cpu.esp -= 4;
    // 0046330b  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046330f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00463310  e8cc8c0100             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 00463315  83c40c                 +add esp, 0xc
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
    // 00463318  e9e8feffff             -jmp 0x463205
    goto L_0x00463205;
L_0x0046331d:
    // 0046331d  a1c0074e00             -mov eax, dword ptr [0x4e07c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5113792) /* 0x4e07c0 */);
    // 00463322  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00463323  6838d84b00             -push 0x4bd838
    app->getMemory<x86::reg32>(cpu.esp-4) = 4970552 /*0x4bd838*/;
    cpu.esp -= 4;
    // 00463328  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046332c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046332d  e8af8c0100             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 00463332  83c40c                 +add esp, 0xc
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
    // 00463335  e9cbfeffff             -jmp 0x463205
    goto L_0x00463205;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_463340(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00463340  803dec014e0000         +cmp byte ptr [0x4e01ec], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5112300) /* 0x4e01ec */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00463347  7509                   -jne 0x463352
    if (!cpu.flags.zf)
    {
        goto L_0x00463352;
    }
    // 00463349  833d804f4c0000         +cmp dword ptr [0x4c4f80], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5001088) /* 0x4c4f80 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00463350  7501                   -jne 0x463353
    if (!cpu.flags.zf)
    {
        goto L_0x00463353;
    }
L_0x00463352:
    // 00463352  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00463353:
    // 00463353  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00463354  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00463355  ba00400000             -mov edx, 0x4000
    cpu.edx = 16384 /*0x4000*/;
    // 0046335a  c1e00a                 -shl eax, 0xa
    cpu.eax <<= 10 /*0xa*/ % 32;
    // 0046335d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0046335f  e894660200             -call 0x4899f8
    cpu.esp -= 4;
    sub_4899f8(app, cpu);
    if (cpu.terminate) return;
    // 00463364  a3248d4c00             -mov dword ptr [0x4c8d24], eax
    app->getMemory<x86::reg32>(x86::reg32(5016868) /* 0x4c8d24 */) = cpu.eax;
    // 00463369  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046336a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046336b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_463370(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00463370  803dec014e0000         +cmp byte ptr [0x4e01ec], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5112300) /* 0x4e01ec */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00463377  7509                   -jne 0x463382
    if (!cpu.flags.zf)
    {
        goto L_0x00463382;
    }
    // 00463379  833d804f4c0000         +cmp dword ptr [0x4c4f80], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5001088) /* 0x4c4f80 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00463380  7501                   -jne 0x463383
    if (!cpu.flags.zf)
    {
        goto L_0x00463383;
    }
L_0x00463382:
    // 00463382  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00463383:
    // 00463383  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00463384  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00463385  ba00400000             -mov edx, 0x4000
    cpu.edx = 16384 /*0x4000*/;
    // 0046338a  b800b00400             -mov eax, 0x4b000
    cpu.eax = 307200 /*0x4b000*/;
    // 0046338f  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00463391  e862660200             -call 0x4899f8
    cpu.esp -= 4;
    sub_4899f8(app, cpu);
    if (cpu.terminate) return;
    // 00463396  a3248d4c00             -mov dword ptr [0x4c8d24], eax
    app->getMemory<x86::reg32>(x86::reg32(5016868) /* 0x4c8d24 */) = cpu.eax;
    // 0046339b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046339c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046339d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4633a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004633a0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004633a1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004633a2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004633a3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004633a4  81ec20010000           -sub esp, 0x120
    (cpu.esp) -= x86::reg32(x86::sreg32(288 /*0x120*/));
    // 004633aa  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004633ac  be00000800             -mov esi, 0x80000
    cpu.esi = 524288 /*0x80000*/;
    // 004633b1  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004633b3  8a255f024e00           -mov ah, byte ptr [0x4e025f]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5112415) /* 0x4e025f */);
    // 004633b9  89bc241c010000         -mov dword ptr [esp + 0x11c], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(284) /* 0x11c */) = cpu.edi;
    // 004633c0  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 004633c2  0f845b010000           -je 0x463523
    if (cpu.flags.zf)
    {
        goto L_0x00463523;
    }
    // 004633c8  803dec014e0000         +cmp byte ptr [0x4e01ec], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5112300) /* 0x4e01ec */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004633cf  0f854e010000           -jne 0x463523
    if (!cpu.flags.zf)
    {
        goto L_0x00463523;
    }
    // 004633d5  833d684f4c0001         +cmp dword ptr [0x4c4f68], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5001064) /* 0x4c4f68 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004633dc  7508                   -jne 0x4633e6
    if (!cpu.flags.zf)
    {
        goto L_0x004633e6;
    }
    // 004633de  83f909                 +cmp ecx, 9
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004633e1  7d03                   -jge 0x4633e6
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004633e6;
    }
    // 004633e3  83c109                 -add ecx, 9
    (cpu.ecx) += x86::reg32(x86::sreg32(9 /*0x9*/));
L_0x004633e6:
    // 004633e6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004633e7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004633e8  bde0d74b00             -mov ebp, 0x4bd7e0
    cpu.ebp = 4970464 /*0x4bd7e0*/;
    // 004633ed  b85a010000             -mov eax, 0x15a
    cpu.eax = 346 /*0x15a*/;
    // 004633f2  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004633f4  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004633f6  a37ca64c00             -mov dword ptr [0x4ca67c], eax
    app->getMemory<x86::reg32>(x86::reg32(5023356) /* 0x4ca67c */) = cpu.eax;
    // 004633fb  b8fcd74b00             -mov eax, 0x4bd7fc
    cpu.eax = 4970492 /*0x4bd7fc*/;
    // 00463400  892d78a64c00           -mov dword ptr [0x4ca678], ebp
    app->getMemory<x86::reg32>(x86::reg32(5023352) /* 0x4ca678 */) = cpu.ebp;
    // 00463406  e81d6e0100             -call 0x47a228
    cpu.esp -= 4;
    sub_47a228(app, cpu);
    if (cpu.terminate) return;
    // 0046340b  8b148d848d4c00         -mov edx, dword ptr [ecx*4 + 0x4c8d84]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5016964) /* 0x4c8d84 */ + cpu.ecx * 4);
    // 00463412  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00463413  8b0dc0074e00           -mov ecx, dword ptr [0x4e07c0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5113792) /* 0x4e07c0 */);
    // 00463419  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046341a  6804d84b00             -push 0x4bd804
    app->getMemory<x86::reg32>(cpu.esp-4) = 4970500 /*0x4bd804*/;
    cpu.esp -= 4;
    // 0046341f  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00463421  8d442414               -lea eax, [esp + 0x14]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00463425  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00463426  e8b68b0100             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 0046342b  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0046342e  8b1da4074e00           -mov ebx, dword ptr [0x4e07a4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5113764) /* 0x4e07a4 */);
    // 00463434  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00463435  68b8d74b00             -push 0x4bd7b8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4970424 /*0x4bd7b8*/;
    cpu.esp -= 4;
    // 0046343a  8d842490000000         -lea eax, [esp + 0x90]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(144) /* 0x90 */);
    // 00463441  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00463442  e89a8b0100             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 00463447  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0046344a  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046344e  e80db80200             -call 0x48ec60
    cpu.esp -= 4;
    sub_48ec60(app, cpu);
    if (cpu.terminate) return;
    // 00463453  89842420010000         -mov dword ptr [esp + 0x120], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(288) /* 0x120 */) = cpu.eax;
    // 0046345a  8d842488000000         -lea eax, [esp + 0x88]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(136) /* 0x88 */);
    // 00463461  e8cab80100             -call 0x47ed30
    cpu.esp -= 4;
    sub_47ed30(app, cpu);
    if (cpu.terminate) return;
    // 00463466  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00463468  0f85c0000000           -jne 0x46352e
    if (!cpu.flags.zf)
    {
        goto L_0x0046352e;
    }
L_0x0046346e:
    // 0046346e  8d8c2418010000         -lea ecx, [esp + 0x118]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(280) /* 0x118 */);
    // 00463475  8d9c2408010000         -lea ebx, [esp + 0x108]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(264) /* 0x108 */);
    // 0046347c  8d942410010000         -lea edx, [esp + 0x110]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(272) /* 0x110 */);
    // 00463483  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00463487  e8489c0100             -call 0x47d0d4
    cpu.esp -= 4;
    sub_47d0d4(app, cpu);
    if (cpu.terminate) return;
    // 0046348c  8d8c241c010000         -lea ecx, [esp + 0x11c]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(284) /* 0x11c */);
    // 00463493  8d9c240c010000         -lea ebx, [esp + 0x10c]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(268) /* 0x10c */);
    // 0046349a  8d942414010000         -lea edx, [esp + 0x114]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 004634a1  8d842488000000         -lea eax, [esp + 0x88]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(136) /* 0x88 */);
    // 004634a8  e8379c0100             -call 0x47d0e4
    cpu.esp -= 4;
    sub_47d0e4(app, cpu);
    if (cpu.terminate) return;
L_0x004634ad:
    // 004634ad  8b842420010000         -mov eax, dword ptr [esp + 0x120]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(288) /* 0x120 */);
    // 004634b4  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004634b6  39f0                   +cmp eax, esi
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
    // 004634b8  7d0d                   -jge 0x4634c7
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004634c7;
    }
    // 004634ba  c784242401000001000000 -mov dword ptr [esp + 0x124], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(292) /* 0x124 */) = 1 /*0x1*/;
    // 004634c5  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x004634c7:
    // 004634c7  8b842410010000         -mov eax, dword ptr [esp + 0x110]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(272) /* 0x110 */);
    // 004634ce  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004634d0  e8b39d0100             -call 0x47d288
    cpu.esp -= 4;
    sub_47d288(app, cpu);
    if (cpu.terminate) return;
    // 004634d5  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004634d7  8b842410010000         -mov eax, dword ptr [esp + 0x110]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(272) /* 0x110 */);
    // 004634de  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004634e0  e8939d0100             -call 0x47d278
    cpu.esp -= 4;
    sub_47d278(app, cpu);
    if (cpu.terminate) return;
    // 004634e5  8b842414010000         -mov eax, dword ptr [esp + 0x114]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 004634ec  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004634ee  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004634f0  e88b9d0100             -call 0x47d280
    cpu.esp -= 4;
    sub_47d280(app, cpu);
    if (cpu.terminate) return;
    // 004634f5  8b842424010000         -mov eax, dword ptr [esp + 0x124]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(292) /* 0x124 */);
    // 004634fc  01f7                   -add edi, esi
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.esi));
    // 004634fe  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00463500  74ab                   -je 0x4634ad
    if (cpu.flags.zf)
    {
        goto L_0x004634ad;
    }
    // 00463502  8b842410010000         -mov eax, dword ptr [esp + 0x110]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(272) /* 0x110 */);
    // 00463509  e8629d0100             -call 0x47d270
    cpu.esp -= 4;
    sub_47d270(app, cpu);
    if (cpu.terminate) return;
    // 0046350e  8b842414010000         -mov eax, dword ptr [esp + 0x114]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(276) /* 0x114 */);
    // 00463515  e8569d0100             -call 0x47d270
    cpu.esp -= 4;
    sub_47d270(app, cpu);
    if (cpu.terminate) return;
    // 0046351a  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0046351c  e86b710100             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
    // 00463521  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463522  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00463523:
    // 00463523  81c420010000           +add esp, 0x120
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(288 /*0x120*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00463529  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046352a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046352b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046352c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046352d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046352e:
    // 0046352e  6a20                   -push 0x20
    app->getMemory<x86::reg32>(cpu.esp-4) = 32 /*0x20*/;
    cpu.esp -= 4;
    // 00463530  8d84248c000000         -lea eax, [esp + 0x8c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 00463537  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00463538  2eff1588754b00         -call dword ptr cs:[0x4b7588]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945288) /* 0x4b7588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0046353f  e92affffff             -jmp 0x46346e
    goto L_0x0046346e;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_463550(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00463550  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00463551  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00463552  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00463553  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00463554  81ec8c000000           -sub esp, 0x8c
    (cpu.esp) -= x86::reg32(x86::sreg32(140 /*0x8c*/));
    // 0046355a  8b15a4074e00           -mov edx, dword ptr [0x4e07a4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5113764) /* 0x4e07a4 */);
    // 00463560  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00463561  68b8d74b00             -push 0x4bd7b8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4970424 /*0x4bd7b8*/;
    cpu.esp -= 4;
    // 00463566  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046356a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046356b  e8718a0100             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 00463570  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00463573  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00463575  be0000f000             -mov esi, 0xf00000
    cpu.esi = 15728640 /*0xf00000*/;
    // 0046357a  e8b1b70100             -call 0x47ed30
    cpu.esp -= 4;
    sub_47ed30(app, cpu);
    if (cpu.terminate) return;
    // 0046357f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00463581  7545                   -jne 0x4635c8
    if (!cpu.flags.zf)
    {
        goto L_0x004635c8;
    }
L_0x00463583:
    // 00463583  8d8c2484000000         -lea ecx, [esp + 0x84]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(132) /* 0x84 */);
    // 0046358a  8d9c2488000000         -lea ebx, [esp + 0x88]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(136) /* 0x88 */);
    // 00463591  8d942480000000         -lea edx, [esp + 0x80]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 00463598  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0046359a  e8459b0100             -call 0x47d0e4
    cpu.esp -= 4;
    sub_47d0e4(app, cpu);
    if (cpu.terminate) return;
    // 0046359f  8b842480000000         -mov eax, dword ptr [esp + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 004635a6  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004635a8  e8034cfeff             -call 0x4481b0
    cpu.esp -= 4;
    sub_4481b0(app, cpu);
    if (cpu.terminate) return;
    // 004635ad  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004635af  8b842480000000         -mov eax, dword ptr [esp + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 004635b6  e8b59c0100             -call 0x47d270
    cpu.esp -= 4;
    sub_47d270(app, cpu);
    if (cpu.terminate) return;
    // 004635bb  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004635bd  81c48c000000           +add esp, 0x8c
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(140 /*0x8c*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004635c3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004635c4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004635c5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004635c6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004635c7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004635c8:
    // 004635c8  6a20                   -push 0x20
    app->getMemory<x86::reg32>(cpu.esp-4) = 32 /*0x20*/;
    cpu.esp -= 4;
    // 004635ca  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004635ce  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004635cf  2eff1588754b00         -call dword ptr cs:[0x4b7588]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945288) /* 0x4b7588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004635d6  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004635d8  e8f19c0100             -call 0x47d2ce
    cpu.esp -= 4;
    sub_47d2ce(app, cpu);
    if (cpu.terminate) return;
    // 004635dd  eba4                   -jmp 0x463583
    goto L_0x00463583;
}

/* align: skip 0x00 */
void Application::sub_4635e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004635e0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004635e1  81ec80000000           -sub esp, 0x80
    (cpu.esp) -= x86::reg32(x86::sreg32(128 /*0x80*/));
    // 004635e7  8b15a4074e00           -mov edx, dword ptr [0x4e07a4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5113764) /* 0x4e07a4 */);
    // 004635ed  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004635ee  68b8d74b00             -push 0x4bd7b8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4970424 /*0x4bd7b8*/;
    cpu.esp -= 4;
    // 004635f3  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004635f7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004635f8  e8e4890100             -call 0x47bfe1
    cpu.esp -= 4;
    sub_47bfe1(app, cpu);
    if (cpu.terminate) return;
    // 004635fd  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00463600  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00463602  e829b70100             -call 0x47ed30
    cpu.esp -= 4;
    sub_47ed30(app, cpu);
    if (cpu.terminate) return;
    // 00463607  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00463609  7508                   -jne 0x463613
    if (!cpu.flags.zf)
    {
        goto L_0x00463613;
    }
    // 0046360b  81c480000000           -add esp, 0x80
    (cpu.esp) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 00463611  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463612  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00463613:
    // 00463613  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00463614  6a20                   -push 0x20
    app->getMemory<x86::reg32>(cpu.esp-4) = 32 /*0x20*/;
    cpu.esp -= 4;
    // 00463616  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0046361a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0046361b  2eff1588754b00         -call dword ptr cs:[0x4b7588]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945288) /* 0x4b7588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00463622  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00463626  e8a39c0100             -call 0x47d2ce
    cpu.esp -= 4;
    sub_47d2ce(app, cpu);
    if (cpu.terminate) return;
    // 0046362b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046362c  81c480000000           -add esp, 0x80
    (cpu.esp) += x86::reg32(x86::sreg32(128 /*0x80*/));
    // 00463632  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463633  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_463640(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00463640  833d7c4f4c0000         +cmp dword ptr [0x4c4f7c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5001084) /* 0x4c4f7c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00463647  0f85f3d00200           -jne 0x490740
    if (!cpu.flags.zf)
    {
        return sub_490740(app, cpu);
    }
    // 0046364d  833d804f4c0000         +cmp dword ptr [0x4c4f80], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5001088) /* 0x4c4f80 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00463654  0f85e6d00200           -jne 0x490740
    if (!cpu.flags.zf)
    {
        return sub_490740(app, cpu);
    }
    // 0046365a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_463660(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00463660  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00463661  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00463662  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00463663  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00463664  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00463666  8b3d7c4f4c00           -mov edi, dword ptr [0x4c4f7c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5001084) /* 0x4c4f7c */);
    // 0046366c  89352c8d4c00           -mov dword ptr [0x4c8d2c], esi
    app->getMemory<x86::reg32>(x86::reg32(5016876) /* 0x4c8d2c */) = cpu.esi;
    // 00463672  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00463674  7445                   -je 0x4636bb
    if (cpu.flags.zf)
    {
        goto L_0x004636bb;
    }
L_0x00463676:
    // 00463676  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00463678  7558                   -jne 0x4636d2
    if (!cpu.flags.zf)
    {
        goto L_0x004636d2;
    }
    // 0046367a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0046367c  7554                   -jne 0x4636d2
    if (!cpu.flags.zf)
    {
        goto L_0x004636d2;
    }
    // 0046367e  81e308080000           -and ebx, 0x808
    cpu.ebx &= x86::reg32(x86::sreg32(2056 /*0x808*/));
    // 00463684  81fb08080000           +cmp ebx, 0x808
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2056 /*0x808*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046368a  743d                   -je 0x4636c9
    if (cpu.flags.zf)
    {
        goto L_0x004636c9;
    }
L_0x0046368c:
    // 0046368c  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 00463691  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x00463693:
    // 00463693  e858d00200             -call 0x4906f0
    cpu.esp -= 4;
    sub_4906f0(app, cpu);
    if (cpu.terminate) return;
    // 00463698  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x0046369a:
    // 0046369a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0046369c  0f8d9b000000           -jge 0x46373d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0046373d;
    }
    // 004636a2  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004636a4  890d804f4c00           -mov dword ptr [0x4c4f80], ecx
    app->getMemory<x86::reg32>(x86::reg32(5001088) /* 0x4c4f80 */) = cpu.ecx;
    // 004636aa  890d9c4f4c00           -mov dword ptr [0x4c4f9c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5001116) /* 0x4c4f9c */) = cpu.ecx;
    // 004636b0  890d7c4f4c00           -mov dword ptr [0x4c4f7c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5001084) /* 0x4c4f7c */) = cpu.ecx;
    // 004636b6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004636b7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004636b8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004636b9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004636ba  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004636bb:
    // 004636bb  833d804f4c0000         +cmp dword ptr [0x4c4f80], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5001088) /* 0x4c4f80 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004636c2  75b2                   -jne 0x463676
    if (!cpu.flags.zf)
    {
        goto L_0x00463676;
    }
    // 004636c4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004636c5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004636c6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004636c7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004636c8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004636c9:
    // 004636c9  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 004636ce  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004636d0  ebc1                   -jmp 0x463693
    goto L_0x00463693;
L_0x004636d2:
    // 004636d2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004636d4  751c                   -jne 0x4636f2
    if (!cpu.flags.zf)
    {
        goto L_0x004636f2;
    }
    // 004636d6  83fa01                 +cmp edx, 1
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
    // 004636d9  7517                   -jne 0x4636f2
    if (!cpu.flags.zf)
    {
        goto L_0x004636f2;
    }
    // 004636db  81e304080000           -and ebx, 0x804
    cpu.ebx &= x86::reg32(x86::sreg32(2052 /*0x804*/));
    // 004636e1  81fb04080000           +cmp ebx, 0x804
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2052 /*0x804*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004636e7  75a3                   -jne 0x46368c
    if (!cpu.flags.zf)
    {
        goto L_0x0046368c;
    }
    // 004636e9  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 004636ee  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004636f0  eba1                   -jmp 0x463693
    goto L_0x00463693;
L_0x004636f2:
    // 004636f2  83f801                 +cmp eax, 1
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
    // 004636f5  751b                   -jne 0x463712
    if (!cpu.flags.zf)
    {
        goto L_0x00463712;
    }
    // 004636f7  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004636f9  7517                   -jne 0x463712
    if (!cpu.flags.zf)
    {
        goto L_0x00463712;
    }
    // 004636fb  81e302080000           -and ebx, 0x802
    cpu.ebx &= x86::reg32(x86::sreg32(2050 /*0x802*/));
    // 00463701  81fb02080000           +cmp ebx, 0x802
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2050 /*0x802*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00463707  7583                   -jne 0x46368c
    if (!cpu.flags.zf)
    {
        goto L_0x0046368c;
    }
    // 00463709  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 0046370e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00463710  eb81                   -jmp 0x463693
    goto L_0x00463693;
L_0x00463712:
    // 00463712  83f801                 +cmp eax, 1
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
    // 00463715  7583                   -jne 0x46369a
    if (!cpu.flags.zf)
    {
        goto L_0x0046369a;
    }
    // 00463717  39c2                   +cmp edx, eax
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
    // 00463719  0f857bffffff           -jne 0x46369a
    if (!cpu.flags.zf)
    {
        goto L_0x0046369a;
    }
    // 0046371f  81e301080000           -and ebx, 0x801
    cpu.ebx &= x86::reg32(x86::sreg32(2049 /*0x801*/));
    // 00463725  81fb01080000           +cmp ebx, 0x801
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2049 /*0x801*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046372b  0f855bffffff           -jne 0x46368c
    if (!cpu.flags.zf)
    {
        goto L_0x0046368c;
    }
    // 00463731  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 00463736  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00463738  e956ffffff             -jmp 0x463693
    goto L_0x00463693;
L_0x0046373d:
    // 0046373d  e83ed6fcff             -call 0x430d80
    cpu.esp -= 4;
    sub_430d80(app, cpu);
    if (cpu.terminate) return;
    // 00463742  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00463747  e870bd0100             -call 0x47f4bc
    cpu.esp -= 4;
    sub_47f4bc(app, cpu);
    if (cpu.terminate) return;
    // 0046374c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0046374e  a3308d4c00             -mov dword ptr [0x4c8d30], eax
    app->getMemory<x86::reg32>(x86::reg32(5016880) /* 0x4c8d30 */) = cpu.eax;
    // 00463753  a32c8d4c00             -mov dword ptr [0x4c8d2c], eax
    app->getMemory<x86::reg32>(x86::reg32(5016876) /* 0x4c8d2c */) = cpu.eax;
    // 00463758  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463759  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046375a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046375b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046375c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_463760(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00463760  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00463761  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00463762  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00463763  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00463764  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00463765  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00463767  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00463769:
    // 00463769  89823c874d00           -mov dword ptr [edx + 0x4d873c], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5080892) /* 0x4d873c */) = cpu.eax;
    // 0046376f  40                     -inc eax
    (cpu.eax)++;
    // 00463770  83c20c                 -add edx, 0xc
    (cpu.edx) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00463773  83f809                 +cmp eax, 9
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
    // 00463776  7cf1                   -jl 0x463769
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00463769;
    }
    // 00463778  0fb63d5e024e00         -movzx edi, byte ptr [0x4e025e]
    cpu.edi = x86::reg32(app->getMemory<x86::reg8>(x86::reg32(5112414) /* 0x4e025e */));
    // 0046377f  8b357c4f4c00           -mov esi, dword ptr [0x4c4f7c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5001084) /* 0x4c4f7c */);
    // 00463785  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00463787  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00463789  8a1d1f014e00           -mov bl, byte ptr [0x4e011f]
    cpu.bl = app->getMemory<x86::reg8>(x86::reg32(5112095) /* 0x4e011f */);
    // 0046378f  89152c8d4c00           -mov dword ptr [0x4c8d2c], edx
    app->getMemory<x86::reg32>(x86::reg32(5016876) /* 0x4c8d2c */) = cpu.edx;
    // 00463795  8a1561024e00           -mov dl, byte ptr [0x4e0261]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5112417) /* 0x4e0261 */);
    // 0046379b  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0046379d  7509                   -jne 0x4637a8
    if (!cpu.flags.zf)
    {
        goto L_0x004637a8;
    }
    // 0046379f  833d804f4c0000         +cmp dword ptr [0x4c4f80], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5001088) /* 0x4c4f80 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004637a6  7458                   -je 0x463800
    if (cpu.flags.zf)
    {
        goto L_0x00463800;
    }
L_0x004637a8:
    // 004637a8  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004637ad  e80abd0100             -call 0x47f4bc
    cpu.esp -= 4;
    sub_47f4bc(app, cpu);
    if (cpu.terminate) return;
    // 004637b2  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004637b4  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004637b6  7557                   -jne 0x46380f
    if (!cpu.flags.zf)
    {
        goto L_0x0046380f;
    }
    // 004637b8  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004637ba  7553                   -jne 0x46380f
    if (!cpu.flags.zf)
    {
        goto L_0x0046380f;
    }
    // 004637bc  81e608080000           -and esi, 0x808
    cpu.esi &= x86::reg32(x86::sreg32(2056 /*0x808*/));
    // 004637c2  81fe08080000           +cmp esi, 0x808
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2056 /*0x808*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004637c8  743c                   -je 0x463806
    if (cpu.flags.zf)
    {
        goto L_0x00463806;
    }
L_0x004637ca:
    // 004637ca  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 004637cf  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x004637d1:
    // 004637d1  e81acf0200             -call 0x4906f0
    cpu.esp -= 4;
    sub_4906f0(app, cpu);
    if (cpu.terminate) return;
    // 004637d6  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x004637d8:
    // 004637d8  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004637da  0f8c8a000000           -jl 0x46386a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046386a;
    }
    // 004637e0  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004637e2  0f849c000000           -je 0x463884
    if (cpu.flags.zf)
    {
        goto L_0x00463884;
    }
    // 004637e8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004637ea:
    // 004637ea  e829bd0100             -call 0x47f518
    cpu.esp -= 4;
    sub_47f518(app, cpu);
    if (cpu.terminate) return;
    // 004637ef  e88cd5fcff             -call 0x430d80
    cpu.esp -= 4;
    sub_430d80(app, cpu);
    if (cpu.terminate) return;
    // 004637f4  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004637f6  a3308d4c00             -mov dword ptr [0x4c8d30], eax
    app->getMemory<x86::reg32>(x86::reg32(5016880) /* 0x4c8d30 */) = cpu.eax;
    // 004637fb  a32c8d4c00             -mov dword ptr [0x4c8d2c], eax
    app->getMemory<x86::reg32>(x86::reg32(5016876) /* 0x4c8d2c */) = cpu.eax;
L_0x00463800:
    // 00463800  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463801  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463802  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463803  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463804  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463805  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00463806:
    // 00463806  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 0046380b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0046380d  ebc2                   -jmp 0x4637d1
    goto L_0x004637d1;
L_0x0046380f:
    // 0046380f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00463811  7518                   -jne 0x46382b
    if (!cpu.flags.zf)
    {
        goto L_0x0046382b;
    }
    // 00463813  83fb01                 +cmp ebx, 1
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
    // 00463816  7513                   -jne 0x46382b
    if (!cpu.flags.zf)
    {
        goto L_0x0046382b;
    }
    // 00463818  2504080000             -and eax, 0x804
    cpu.eax &= x86::reg32(x86::sreg32(2052 /*0x804*/));
    // 0046381d  3d04080000             +cmp eax, 0x804
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2052 /*0x804*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00463822  75a6                   -jne 0x4637ca
    if (!cpu.flags.zf)
    {
        goto L_0x004637ca;
    }
    // 00463824  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 00463829  eba6                   -jmp 0x4637d1
    goto L_0x004637d1;
L_0x0046382b:
    // 0046382b  83fa01                 +cmp edx, 1
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
    // 0046382e  7517                   -jne 0x463847
    if (!cpu.flags.zf)
    {
        goto L_0x00463847;
    }
    // 00463830  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00463832  7513                   -jne 0x463847
    if (!cpu.flags.zf)
    {
        goto L_0x00463847;
    }
    // 00463834  2502080000             -and eax, 0x802
    cpu.eax &= x86::reg32(x86::sreg32(2050 /*0x802*/));
    // 00463839  3d02080000             +cmp eax, 0x802
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2050 /*0x802*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046383e  758a                   -jne 0x4637ca
    if (!cpu.flags.zf)
    {
        goto L_0x004637ca;
    }
    // 00463840  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 00463845  eb8a                   -jmp 0x4637d1
    goto L_0x004637d1;
L_0x00463847:
    // 00463847  83fa01                 +cmp edx, 1
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
    // 0046384a  758c                   -jne 0x4637d8
    if (!cpu.flags.zf)
    {
        goto L_0x004637d8;
    }
    // 0046384c  39d3                   +cmp ebx, edx
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
    // 0046384e  7588                   -jne 0x4637d8
    if (!cpu.flags.zf)
    {
        goto L_0x004637d8;
    }
    // 00463850  2501080000             -and eax, 0x801
    cpu.eax &= x86::reg32(x86::sreg32(2049 /*0x801*/));
    // 00463855  3d01080000             +cmp eax, 0x801
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2049 /*0x801*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0046385a  0f856affffff           -jne 0x4637ca
    if (!cpu.flags.zf)
    {
        goto L_0x004637ca;
    }
    // 00463860  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 00463865  e967ffffff             -jmp 0x4637d1
    goto L_0x004637d1;
L_0x0046386a:
    // 0046386a  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 0046386c  890d804f4c00           -mov dword ptr [0x4c4f80], ecx
    app->getMemory<x86::reg32>(x86::reg32(5001088) /* 0x4c4f80 */) = cpu.ecx;
    // 00463872  890d9c4f4c00           -mov dword ptr [0x4c4f9c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5001116) /* 0x4c4f9c */) = cpu.ecx;
    // 00463878  890d7c4f4c00           -mov dword ptr [0x4c4f7c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5001084) /* 0x4c4f7c */) = cpu.ecx;
    // 0046387e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046387f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463880  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463881  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463882  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463883  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00463884:
    // 00463884  b8ceffffff             -mov eax, 0xffffffce
    cpu.eax = 4294967246 /*0xffffffce*/;
    // 00463889  e95cffffff             -jmp 0x4637ea
    goto L_0x004637ea;
}

/* align: skip 0x00 0x00 */
void Application::sub_463890(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00463890  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00463891  8b15288e4c00           -mov edx, dword ptr [0x4c8e28]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5017128) /* 0x4c8e28 */);
    // 00463897  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00463899  7502                   -jne 0x46389d
    if (!cpu.flags.zf)
    {
        goto L_0x0046389d;
    }
    // 0046389b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046389c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0046389d:
    // 0046389d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0046389e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004638a0  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004638a2  e8e56d0100             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
    // 004638a7  890d288e4c00           -mov dword ptr [0x4c8e28], ecx
    app->getMemory<x86::reg32>(x86::reg32(5017128) /* 0x4c8e28 */) = cpu.ecx;
    // 004638ad  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004638ae  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004638af  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4638b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004638b0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004638b1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004638b2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004638b4  8b0d288e4c00           -mov ecx, dword ptr [0x4c8e28]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5017128) /* 0x4c8e28 */);
    // 004638ba  89152c8e4c00           -mov dword ptr [0x4c8e2c], edx
    app->getMemory<x86::reg32>(x86::reg32(5017132) /* 0x4c8e2c */) = cpu.edx;
    // 004638c0  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004638c2  7403                   -je 0x4638c7
    if (cpu.flags.zf)
    {
        goto L_0x004638c7;
    }
    // 004638c4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004638c5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004638c6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004638c7:
    // 004638c7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004638c8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004638c9  bbe4d84b00             -mov ebx, 0x4bd8e4
    cpu.ebx = 4970724 /*0x4bd8e4*/;
    // 004638ce  beec020000             -mov esi, 0x2ec
    cpu.esi = 748 /*0x2ec*/;
    // 004638d3  baa08c0000             -mov edx, 0x8ca0
    cpu.edx = 36000 /*0x8ca0*/;
    // 004638d8  b800d94b00             -mov eax, 0x4bd900
    cpu.eax = 4970752 /*0x4bd900*/;
    // 004638dd  891d78a64c00           -mov dword ptr [0x4ca678], ebx
    app->getMemory<x86::reg32>(x86::reg32(5023352) /* 0x4ca678 */) = cpu.ebx;
    // 004638e3  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004638e5  89357ca64c00           -mov dword ptr [0x4ca67c], esi
    app->getMemory<x86::reg32>(x86::reg32(5023356) /* 0x4ca67c */) = cpu.esi;
    // 004638eb  e850690100             -call 0x47a240
    cpu.esp -= 4;
    sub_47a240(app, cpu);
    if (cpu.terminate) return;
    // 004638f0  a3288e4c00             -mov dword ptr [0x4c8e28], eax
    app->getMemory<x86::reg32>(x86::reg32(5017128) /* 0x4c8e28 */) = cpu.eax;
    // 004638f5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004638f6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004638f7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004638f8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004638f9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_463900(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00463900  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00463901  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00463902  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00463903  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00463904  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00463905  83ec4c                 -sub esp, 0x4c
    (cpu.esp) -= x86::reg32(x86::sreg32(76 /*0x4c*/));
    // 00463908  89442444               -mov dword ptr [esp + 0x44], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */) = cpu.eax;
    // 0046390c  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0046390e  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00463910  83e00f                 -and eax, 0xf
    cpu.eax &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00463913  8b048568f04d00         -mov eax, dword ptr [eax*4 + 0x4df068]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5107816) /* 0x4df068 */ + cpu.eax * 4);
    // 0046391a  898210060000           -mov dword ptr [edx + 0x610], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1552) /* 0x610 */) = cpu.eax;
    // 00463920  8b542444               -mov edx, dword ptr [esp + 0x44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 00463924  898288000000           -mov dword ptr [edx + 0x88], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(136) /* 0x88 */) = cpu.eax;
    // 0046392a  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 0046392c  83e20f                 -and edx, 0xf
    cpu.edx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0046392f  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00463936  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00463938  8b048528ed4d00         -mov eax, dword ptr [eax*4 + 0x4ded28]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5106984) /* 0x4ded28 */ + cpu.eax * 4);
    // 0046393f  898614060000           -mov dword ptr [esi + 0x614], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1556) /* 0x614 */) = cpu.eax;
    // 00463945  a12c8e4c00             -mov eax, dword ptr [0x4c8e2c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5017132) /* 0x4c8e2c */);
    // 0046394a  8b542444               -mov edx, dword ptr [esp + 0x44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0046394e  898618060000           -mov dword ptr [esi + 0x618], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1560) /* 0x618 */) = cpu.eax;
    // 00463954  898284000000           -mov dword ptr [edx + 0x84], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(132) /* 0x84 */) = cpu.eax;
    // 0046395a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0046395c  89861c060000           -mov dword ptr [esi + 0x61c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1564) /* 0x61c */) = cpu.eax;
    // 00463962  8b442444               -mov eax, dword ptr [esp + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 00463966  89542434               -mov dword ptr [esp + 0x34], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.edx;
    // 0046396a  89442438               -mov dword ptr [esp + 0x38], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
L_0x0046396e:
    // 0046396e  8b542438               -mov edx, dword ptr [esp + 0x38]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 00463972  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00463975  8b442434               -mov eax, dword ptr [esp + 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00463979  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0046397c  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046397f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00463981  7522                   -jne 0x4639a5
    if (!cpu.flags.zf)
    {
        goto L_0x004639a5;
    }
L_0x00463983:
    // 00463983  8b4c2434               -mov ecx, dword ptr [esp + 0x34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00463987  8b542438               -mov edx, dword ptr [esp + 0x38]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0046398b  41                     -inc ecx
    (cpu.ecx)++;
    // 0046398c  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0046398f  894c2434               -mov dword ptr [esp + 0x34], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.ecx;
    // 00463993  89542438               -mov dword ptr [esp + 0x38], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.edx;
    // 00463997  83f920                 +cmp ecx, 0x20
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
    // 0046399a  7cd2                   -jl 0x46396e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0046396e;
    }
    // 0046399c  83c44c                 -add esp, 0x4c
    (cpu.esp) += x86::reg32(x86::sreg32(76 /*0x4c*/));
    // 0046399f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004639a0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004639a1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004639a2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004639a3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004639a4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004639a5:
    // 004639a5  8b542438               -mov edx, dword ptr [esp + 0x38]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 004639a9  8944243c               -mov dword ptr [esp + 0x3c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.eax;
    // 004639ad  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004639af  89542424               -mov dword ptr [esp + 0x24], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 004639b3  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004639b5  895c242c               -mov dword ptr [esp + 0x2c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.ebx;
    // 004639b9  895c2440               -mov dword ptr [esp + 0x40], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.ebx;
L_0x004639bd:
    // 004639bd  8b442444               -mov eax, dword ptr [esp + 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 004639c1  0344243c               -add eax, dword ptr [esp + 0x3c]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */)));
    // 004639c5  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004639c8  8b542440               -mov edx, dword ptr [esp + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 004639cc  3b5004                 +cmp edx, dword ptr [eax + 4]
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
    // 004639cf  7db2                   -jge 0x463983
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00463983;
    }
    // 004639d1  8b5c242c               -mov ebx, dword ptr [esp + 0x2c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004639d5  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004639d8  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004639da  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 004639dc  f6c2e0                 +test dl, 0xe0
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 224 /*0xe0*/));
    // 004639df  0f843d010000           -je 0x463b22
    if (cpu.flags.zf)
    {
        goto L_0x00463b22;
    }
    // 004639e5  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 004639e7  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004639ec  c1f805                 -sar eax, 5
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (5 /*0x5*/ % 32));
    // 004639ef  89442448               -mov dword ptr [esp + 0x48], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */) = cpu.eax;
L_0x004639f3:
    // 004639f3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004639f5  8b542448               -mov edx, dword ptr [esp + 0x48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 004639f9  89442430               -mov dword ptr [esp + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 004639fd  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004639ff  0f8e04010000           -jle 0x463b09
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00463b09;
    }
    // 00463a05  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00463a09  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00463a0b  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
L_0x00463a0f:
    // 00463a0f  8b4504                 -mov eax, dword ptr [ebp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 00463a12  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00463a15  8a440708               -mov al, byte ptr [edi + eax + 8]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(8) /* 0x8 */ + cpu.eax * 1);
    // 00463a19  88442418               -mov byte ptr [esp + 0x18], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.al;
    // 00463a1d  8b4504                 -mov eax, dword ptr [ebp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 00463a20  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00463a23  8a440709               -mov al, byte ptr [edi + eax + 9]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(9) /* 0x9 */ + cpu.eax * 1);
    // 00463a27  88442419               -mov byte ptr [esp + 0x19], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(25) /* 0x19 */) = cpu.al;
    // 00463a2b  8b4504                 -mov eax, dword ptr [ebp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 00463a2e  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00463a31  8a44070a               -mov al, byte ptr [edi + eax + 0xa]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(10) /* 0xa */ + cpu.eax * 1);
    // 00463a35  8844241a               -mov byte ptr [esp + 0x1a], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(26) /* 0x1a */) = cpu.al;
    // 00463a39  8b4504                 -mov eax, dword ptr [ebp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 00463a3c  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00463a3f  8a44070b               -mov al, byte ptr [edi + eax + 0xb]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi + x86::reg32(11) /* 0xb */ + cpu.eax * 1);
    // 00463a43  8a5c2419               -mov bl, byte ptr [esp + 0x19]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(25) /* 0x19 */);
    // 00463a47  8844241b               -mov byte ptr [esp + 0x1b], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(27) /* 0x1b */) = cpu.al;
    // 00463a4b  8a442430               -mov al, byte ptr [esp + 0x30]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00463a4f  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 00463a51  00c3                   -add bl, al
    (cpu.bl) += x86::reg8(x86::sreg8(cpu.al));
    // 00463a53  8874241c               -mov byte ptr [esp + 0x1c], dh
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.dh;
    // 00463a57  885c2419               -mov byte ptr [esp + 0x19], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(25) /* 0x19 */) = cpu.bl;
    // 00463a5b  8b4504                 -mov eax, dword ptr [ebp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 00463a5e  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00463a61  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 00463a63  8a38                   -mov bh, byte ptr [eax]
    cpu.bh = app->getMemory<x86::reg8>(cpu.eax);
    // 00463a65  f6c704                 +test bh, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 4 /*0x4*/));
    // 00463a68  0f84f1000000           -je 0x463b5f
    if (cpu.flags.zf)
    {
        goto L_0x00463b5f;
    }
    // 00463a6e  f6c701                 +test bh, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 1 /*0x1*/));
    // 00463a71  0f84b8000000           -je 0x463b2f
    if (cpu.flags.zf)
    {
        goto L_0x00463b2f;
    }
    // 00463a77  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00463a7b  8d542418               -lea edx, [esp + 0x18]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00463a7f  8b9e14060000           -mov ebx, dword ptr [esi + 0x614]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1556) /* 0x614 */);
    // 00463a85  8b8610060000           -mov eax, dword ptr [esi + 0x610]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1552) /* 0x610 */);
    // 00463a8b  e8d0170100             -call 0x475260
    cpu.esp -= 4;
    sub_475260(app, cpu);
    if (cpu.terminate) return;
    // 00463a90  6b1d2c8e4c000c         -imul ebx, dword ptr [0x4c8e2c], 0xc
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5017132) /* 0x4c8e2c */))) * x86::sreg64(x86::sreg32(12 /*0xc*/)));
    // 00463a97  a1288e4c00             -mov eax, dword ptr [0x4c8e28]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5017128) /* 0x4c8e28 */);
    // 00463a9c  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
L_0x00463aa1:
    // 00463aa1  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00463aa3  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
L_0x00463aa7:
    // 00463aa7  e808160100             -call 0x4750b4
    cpu.esp -= 4;
    sub_4750b4(app, cpu);
    if (cpu.terminate) return;
    // 00463aac  8b542444               -mov edx, dword ptr [esp + 0x44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 00463ab0  66a12c8e4c00           -mov ax, word ptr [0x4c8e2c]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5017132) /* 0x4c8e2c */);
    // 00463ab6  668b9a84000000         -mov bx, word ptr [edx + 0x84]
    cpu.bx = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(132) /* 0x84 */);
    // 00463abd  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00463ac1  8b4c2430               -mov ecx, dword ptr [esp + 0x30]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00463ac5  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00463ac7  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00463aca  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00463acc  8b4c2428               -mov ecx, dword ptr [esp + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00463ad0  8b5218                 -mov edx, dword ptr [edx + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 00463ad3  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00463ad5  66894202               -mov word ptr [edx + 2], ax
    app->getMemory<x86::reg16>(cpu.edx + x86::reg32(2) /* 0x2 */) = cpu.ax;
    // 00463ad9  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00463add  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00463ae0  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00463ae3  8b542430               -mov edx, dword ptr [esp + 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00463ae7  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00463ae9  42                     -inc edx
    (cpu.edx)++;
    // 00463aea  c6400100               -mov byte ptr [eax + 1], 0
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */) = 0 /*0x0*/;
    // 00463aee  a12c8e4c00             -mov eax, dword ptr [0x4c8e2c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5017132) /* 0x4c8e2c */);
    // 00463af3  89542430               -mov dword ptr [esp + 0x30], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.edx;
    // 00463af7  40                     -inc eax
    (cpu.eax)++;
    // 00463af8  8b4c2448               -mov ecx, dword ptr [esp + 0x48]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 00463afc  a32c8e4c00             -mov dword ptr [0x4c8e2c], eax
    app->getMemory<x86::reg32>(x86::reg32(5017132) /* 0x4c8e2c */) = cpu.eax;
    // 00463b01  39ca                   +cmp edx, ecx
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
    // 00463b03  0f8c06ffffff           -jl 0x463a0f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00463a0f;
    }
L_0x00463b09:
    // 00463b09  8b7c2440               -mov edi, dword ptr [esp + 0x40]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 00463b0d  8b5c242c               -mov ebx, dword ptr [esp + 0x2c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 00463b11  47                     -inc edi
    (cpu.edi)++;
    // 00463b12  83c30c                 +add ebx, 0xc
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00463b15  897c2440               -mov dword ptr [esp + 0x40], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.edi;
    // 00463b19  895c242c               -mov dword ptr [esp + 0x2c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.ebx;
    // 00463b1d  e99bfeffff             -jmp 0x4639bd
    goto L_0x004639bd;
L_0x00463b22:
    // 00463b22  c744244801000000       -mov dword ptr [esp + 0x48], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */) = 1 /*0x1*/;
    // 00463b2a  e9c4feffff             -jmp 0x4639f3
    goto L_0x004639f3;
L_0x00463b2f:
    // 00463b2f  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00463b33  8d542418               -lea edx, [esp + 0x18]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00463b37  8b9e14060000           -mov ebx, dword ptr [esi + 0x614]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1556) /* 0x614 */);
    // 00463b3d  8b8610060000           -mov eax, dword ptr [esi + 0x610]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1552) /* 0x610 */);
    // 00463b43  e818170100             -call 0x475260
    cpu.esp -= 4;
    sub_475260(app, cpu);
    if (cpu.terminate) return;
    // 00463b48  6b052c8e4c000c         +imul eax, dword ptr [0x4c8e2c], 0xc
    {
        x86::sreg64 tmp = x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5017132) /* 0x4c8e2c */))) * x86::sreg64(x86::sreg32(12 /*0xc*/));
        cpu.eax = static_cast<x86::reg32>(static_cast<x86::sreg32>(tmp));
        cpu.flags.of = cpu.flags.cf = (tmp != x86::sreg64(x86::sreg32(cpu.eax)));
    }
    // 00463b4f  8b1d288e4c00           -mov ebx, dword ptr [0x4c8e28]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5017128) /* 0x4c8e28 */);
    // 00463b55  ba02000000             -mov edx, 2
    cpu.edx = 2 /*0x2*/;
    // 00463b5a  e942ffffff             -jmp 0x463aa1
    goto L_0x00463aa1;
L_0x00463b5f:
    // 00463b5f  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00463b63  8d542418               -lea edx, [esp + 0x18]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00463b67  8b9e14060000           -mov ebx, dword ptr [esi + 0x614]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1556) /* 0x614 */);
    // 00463b6d  8b8610060000           -mov eax, dword ptr [esi + 0x610]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1552) /* 0x610 */);
    // 00463b73  e8e8160100             -call 0x475260
    cpu.esp -= 4;
    sub_475260(app, cpu);
    if (cpu.terminate) return;
    // 00463b78  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00463b7a  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00463b7f  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00463b83  e82c150100             -call 0x4750b4
    cpu.esp -= 4;
    sub_4750b4(app, cpu);
    if (cpu.terminate) return;
    // 00463b88  6b052c8e4c000c         -imul eax, dword ptr [0x4c8e2c], 0xc
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5017132) /* 0x4c8e2c */))) * x86::sreg64(x86::sreg32(12 /*0xc*/)));
    // 00463b8f  8b1d288e4c00           -mov ebx, dword ptr [0x4c8e28]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5017128) /* 0x4c8e28 */);
    // 00463b95  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 00463b9a  01c3                   +add ebx, eax
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
    // 00463b9c  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00463b9e  e904ffffff             -jmp 0x463aa7
    goto L_0x00463aa7;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_463bb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00463bb0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00463bb1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00463bb2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00463bb3  83ec24                 -sub esp, 0x24
    (cpu.esp) -= x86::reg32(x86::sreg32(36 /*0x24*/));
    // 00463bb6  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 00463bba  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00463bbe  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00463bc0  83e20f                 -and edx, 0xf
    cpu.edx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00463bc3  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00463bca  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00463bcc  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 00463bcf  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00463bd3  8b848328ed4d00         -mov eax, dword ptr [ebx + eax*4 + 0x4ded28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5106984) /* 0x4ded28 */ + cpu.eax * 4);
    // 00463bda  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00463bdc  898214060000           -mov dword ptr [edx + 0x614], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1556) /* 0x614 */) = cpu.eax;
    // 00463be2  a12c8e4c00             -mov eax, dword ptr [0x4c8e2c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5017132) /* 0x4c8e2c */);
    // 00463be7  89831c060000           -mov dword ptr [ebx + 0x61c], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1564) /* 0x61c */) = cpu.eax;
    // 00463bed  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00463bef  898218060000           -mov dword ptr [edx + 0x618], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1560) /* 0x618 */) = cpu.eax;
    // 00463bf5  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00463bf9  894c2410               -mov dword ptr [esp + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 00463bfd  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x00463c01:
    // 00463c01  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00463c05  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00463c08  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00463c0c  8b5a04                 -mov ebx, dword ptr [edx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00463c0f  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00463c12  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00463c14  7534                   -jne 0x463c4a
    if (!cpu.flags.zf)
    {
        goto L_0x00463c4a;
    }
L_0x00463c16:
    // 00463c16  8b7c2410               -mov edi, dword ptr [esp + 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00463c1a  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00463c1e  47                     -inc edi
    (cpu.edi)++;
    // 00463c1f  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00463c22  897c2410               -mov dword ptr [esp + 0x10], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edi;
    // 00463c26  8974240c               -mov dword ptr [esp + 0xc], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 00463c2a  83ff20                 +cmp edi, 0x20
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
    // 00463c2d  7cd2                   -jl 0x463c01
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00463c01;
    }
    // 00463c2f  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00463c33  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00463c37  8b801c060000           -mov eax, dword ptr [eax + 0x61c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1564) /* 0x61c */);
    // 00463c3d  898218060000           -mov dword ptr [edx + 0x618], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1560) /* 0x618 */) = cpu.eax;
    // 00463c43  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 00463c46  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463c47  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463c48  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463c49  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00463c4a:
    // 00463c4a  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00463c4e  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00463c50  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00463c54  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 00463c57  89742418               -mov dword ptr [esp + 0x18], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.esi;
L_0x00463c5b:
    // 00463c5b  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00463c5f  03442414               -add eax, dword ptr [esp + 0x14]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 00463c63  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 00463c66  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00463c6a  3b5004                 +cmp edx, dword ptr [eax + 4]
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
    // 00463c6d  7da7                   -jge 0x463c16
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00463c16;
    }
    // 00463c6f  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 00463c72  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00463c75  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00463c77  8a10                   -mov dl, byte ptr [eax]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax);
    // 00463c79  f6c2e0                 +test dl, 0xe0
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & 224 /*0xe0*/));
    // 00463c7c  0f84bf000000           -je 0x463d41
    if (cpu.flags.zf)
    {
        goto L_0x00463d41;
    }
    // 00463c82  88d0                   -mov al, dl
    cpu.al = cpu.dl;
    // 00463c84  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00463c89  c1f805                 -sar eax, 5
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (5 /*0x5*/ % 32));
    // 00463c8c  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
L_0x00463c90:
    // 00463c90  8b6c241c               -mov ebp, dword ptr [esp + 0x1c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00463c94  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00463c96  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00463c98  0f8e8c000000           -jle 0x463d2a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00463d2a;
    }
    // 00463c9e  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
L_0x00463ca1:
    // 00463ca1  6b1d2c8e4c000c         -imul ebx, dword ptr [0x4c8e2c], 0xc
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5017132) /* 0x4c8e2c */))) * x86::sreg64(x86::sreg32(12 /*0xc*/)));
    // 00463ca8  a1288e4c00             -mov eax, dword ptr [0x4c8e28]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5017128) /* 0x4c8e28 */);
    // 00463cad  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00463cb1  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00463cb3  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00463cb6  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00463cba  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00463cbd  8b9214060000           -mov edx, dword ptr [edx + 0x614]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1556) /* 0x614 */);
    // 00463cc3  668b440602             -mov ax, word ptr [esi + eax + 2]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(2) /* 0x2 */ + cpu.eax * 1);
    // 00463cc8  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00463ccd  8b6c2404               -mov ebp, dword ptr [esp + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00463cd1  038584000000           -add eax, dword ptr [ebp + 0x84]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(132) /* 0x84 */)));
    // 00463cd7  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00463cd9  6bc00c                 -imul eax, eax, 0xc
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(12 /*0xc*/)));
    // 00463cdc  03442408               -add eax, dword ptr [esp + 8]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */)));
    // 00463ce0  e85b150100             -call 0x475240
    cpu.esp -= 4;
    sub_475240(app, cpu);
    if (cpu.terminate) return;
    // 00463ce5  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00463ce9  66a12c8e4c00           -mov ax, word ptr [0x4c8e2c]
    cpu.ax = app->getMemory<x86::reg16>(x86::reg32(5017132) /* 0x4c8e2c */);
    // 00463cef  668b9a18060000         -mov bx, word ptr [edx + 0x618]
    cpu.bx = app->getMemory<x86::reg16>(cpu.edx + x86::reg32(1560) /* 0x618 */);
    // 00463cf6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00463cf8  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00463cfb  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00463cfd  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00463d00  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00463d02  6689540602             -mov word ptr [esi + eax + 2], dx
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(2) /* 0x2 */ + cpu.eax * 1) = cpu.dx;
    // 00463d07  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00463d0a  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 00463d0d  c644060100             -mov byte ptr [esi + eax + 1], 0
    app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.eax * 1) = 0 /*0x0*/;
    // 00463d12  a12c8e4c00             -mov eax, dword ptr [0x4c8e2c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5017132) /* 0x4c8e2c */);
    // 00463d17  41                     -inc ecx
    (cpu.ecx)++;
    // 00463d18  40                     -inc eax
    (cpu.eax)++;
    // 00463d19  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00463d1d  a32c8e4c00             -mov dword ptr [0x4c8e2c], eax
    app->getMemory<x86::reg32>(x86::reg32(5017132) /* 0x4c8e2c */) = cpu.eax;
    // 00463d22  39d1                   +cmp ecx, edx
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
    // 00463d24  0f8c77ffffff           -jl 0x463ca1
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00463ca1;
    }
L_0x00463d2a:
    // 00463d2a  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00463d2e  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 00463d31  43                     -inc ebx
    (cpu.ebx)++;
    // 00463d32  83c10c                 +add ecx, 0xc
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00463d35  895c2418               -mov dword ptr [esp + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 00463d39  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 00463d3c  e91affffff             -jmp 0x463c5b
    goto L_0x00463c5b;
L_0x00463d41:
    // 00463d41  c744241c01000000       -mov dword ptr [esp + 0x1c], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = 1 /*0x1*/;
    // 00463d49  e942ffffff             -jmp 0x463c90
    goto L_0x00463c90;
}

/* align: skip 0x00 0x00 */
/* data blob: 30346377000000003132637700000000313863770000000032376377000000003338637700000000303463630000000031326363000000003138636300000000323763630000000033386363000000003030636300000000ffffffff0000000000000000ffffffff010000000000000000000000010000000000000000000000ffffffff0000000000000000ffffffff0100000000000000000000000100000000000000000000000000000000000000 */
void Application::sub_463e00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00463e00  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00463e01  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00463e02  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00463e03  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00463e04  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00463e05  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00463e08  89f5                   -mov ebp, esi
    cpu.ebp = cpu.esi;
    // 00463e0a  8b35388e4c00           -mov esi, dword ptr [0x4c8e38]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5017144) /* 0x4c8e38 */);
    // 00463e10  8d04f500000000         -lea eax, [esi*8]
    cpu.eax = x86::reg32(cpu.esi * 8);
    // 00463e17  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00463e19  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00463e1b  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00463e1e  b913000000             -mov ecx, 0x13
    cpu.ecx = 19 /*0x13*/;
    // 00463e23  8990f42b5100           -mov dword ptr [eax + 0x512bf4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5319668) /* 0x512bf4 */) = cpu.edx;
    // 00463e29  bb402b5100             -mov ebx, 0x512b40
    cpu.ebx = 5319488 /*0x512b40*/;
    // 00463e2e  8988f82b5100           -mov dword ptr [eax + 0x512bf8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5319672) /* 0x512bf8 */) = cpu.ecx;
    // 00463e34  8998142c5100           -mov dword ptr [eax + 0x512c14], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5319700) /* 0x512c14 */) = cpu.ebx;
    // 00463e3a  bef42b5100             -mov esi, 0x512bf4
    cpu.esi = 5319668 /*0x512bf4*/;
    // 00463e3f  8990fc2b5100           -mov dword ptr [eax + 0x512bfc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5319676) /* 0x512bfc */) = cpu.edx;
    // 00463e45  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00463e47  8990002c5100           -mov dword ptr [eax + 0x512c00], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5319680) /* 0x512c00 */) = cpu.edx;
    // 00463e4d  a1388e4c00             -mov eax, dword ptr [0x4c8e38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5017144) /* 0x4c8e38 */);
    // 00463e52  89742410               -mov dword ptr [esp + 0x10], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.esi;
    // 00463e56  83f84f                 +cmp eax, 0x4f
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(79 /*0x4f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00463e59  0f8caf000000           -jl 0x463f0e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00463f0e;
    }
    // 00463e5f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00463e61:
    // 00463e61  a3388e4c00             -mov dword ptr [0x4c8e38], eax
    app->getMemory<x86::reg32>(x86::reg32(5017144) /* 0x4c8e38 */) = cpu.eax;
    // 00463e66  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00463e68  0f8ea6000000           -jle 0x463f14
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00463f14;
    }
    // 00463e6e  8d70ff                 -lea esi, [eax - 1]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
L_0x00463e71:
    // 00463e71  68c4295100             -push 0x5129c4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5319108 /*0x5129c4*/;
    cpu.esp -= 4;
    // 00463e76  8d04f500000000         -lea eax, [esi*8]
    cpu.eax = x86::reg32(cpu.esi * 8);
    // 00463e7d  b987000000             -mov ecx, 0x87
    cpu.ecx = 135 /*0x87*/;
    // 00463e82  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 00463e84  bef42b5100             -mov esi, 0x512bf4
    cpu.esi = 5319668 /*0x512bf4*/;
    // 00463e89  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00463e8c  bb6c000000             -mov ebx, 0x6c
    cpu.ebx = 108 /*0x6c*/;
    // 00463e91  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00463e93  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00463e95  89742418               -mov dword ptr [esp + 0x18], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 00463e99  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00463e9b  8d742404               -lea esi, [esp + 4]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00463e9f  e82c4a0000             -call 0x4688d0
    cpu.esp -= 4;
    sub_4688d0(app, cpu);
    if (cpu.terminate) return;
    // 00463ea4  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00463ea8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00463ea9  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00463ead  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00463eae  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00463eb2  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00463eb6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00463eb7  ba05000000             -mov edx, 5
    cpu.edx = 5 /*0x5*/;
    // 00463ebc  b97f000000             -mov ecx, 0x7f
    cpu.ecx = 127 /*0x7f*/;
    // 00463ec1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00463ec2  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00463ec6  bb61000000             -mov ebx, 0x61
    cpu.ebx = 97 /*0x61*/;
    // 00463ecb  e8a089ffff             -call 0x45c870
    cpu.esp -= 4;
    sub_45c870(app, cpu);
    if (cpu.terminate) return;
    // 00463ed0  68b4295100             -push 0x5129b4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5319092 /*0x5129b4*/;
    cpu.esp -= 4;
    // 00463ed5  8d74240c               -lea esi, [esp + 0xc]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00463ed9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00463edb  e8f0490000             -call 0x4688d0
    cpu.esp -= 4;
    sub_4688d0(app, cpu);
    if (cpu.terminate) return;
    // 00463ee0  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00463ee4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00463ee5  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00463ee9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00463eea  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00463eee  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00463eef  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00463ef3  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00463ef4  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00463ef8  89ef                   -mov edi, ebp
    cpu.edi = cpu.ebp;
    // 00463efa  e87189ffff             -call 0x45c870
    cpu.esp -= 4;
    sub_45c870(app, cpu);
    if (cpu.terminate) return;
    // 00463eff  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00463f01  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00463f02  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00463f03  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00463f05  83c418                 +add esp, 0x18
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00463f08  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463f09  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463f0a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463f0b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463f0c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00463f0d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00463f0e:
    // 00463f0e  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00463f0f  e94dffffff             -jmp 0x463e61
    goto L_0x00463e61;
L_0x00463f14:
    // 00463f14  be4f000000             -mov esi, 0x4f
    cpu.esi = 79 /*0x4f*/;
    // 00463f19  e953ffffff             -jmp 0x463e71
    goto L_0x00463e71;
}

/* align: skip 0x00 0x00 */
void Application::sub_463f20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00463f20  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00463f21  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00463f22  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00463f23  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00463f24  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00463f25  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00463f28  8b15388e4c00           -mov edx, dword ptr [0x4c8e38]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5017144) /* 0x4c8e38 */);
    // 00463f2e  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00463f30  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 00463f37  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00463f39  b9f42b5100             -mov ecx, 0x512bf4
    cpu.ecx = 5319668 /*0x512bf4*/;
    // 00463f3e  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00463f41  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00463f43  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 00463f46  8b0dbcf34d00           -mov ecx, dword ptr [0x4df3bc]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5108668) /* 0x4df3bc */);
    // 00463f4c  83f903                 +cmp ecx, 3
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
    // 00463f4f  0f84f7000000           -je 0x46404c
    if (cpu.flags.zf)
    {
        goto L_0x0046404c;
    }
    // 00463f55  83f904                 +cmp ecx, 4
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
    // 00463f58  0f84ee000000           -je 0x46404c
    if (cpu.flags.zf)
    {
        goto L_0x0046404c;
    }
    // 00463f5e  83fa4f                 +cmp edx, 0x4f
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(79 /*0x4f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00463f61  0f8c86010000           -jl 0x4640ed
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004640ed;
    }
    // 00463f67  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00463f69:
    // 00463f69  8d04cd00000000         -lea eax, [ecx*8]
    cpu.eax = x86::reg32(cpu.ecx * 8);
    // 00463f70  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00463f72  bef42b5100             -mov esi, 0x512bf4
    cpu.esi = 5319668 /*0x512bf4*/;
    // 00463f77  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00463f7a  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00463f7c  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 00463f83  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00463f85  bf14000000             -mov edi, 0x14
    cpu.edi = 20 /*0x14*/;
    // 00463f8a  893485f42b5100         -mov dword ptr [eax*4 + 0x512bf4], esi
    app->getMemory<x86::reg32>(x86::reg32(5319668) /* 0x512bf4 */ + cpu.eax * 4) = cpu.esi;
    // 00463f91  bd282b5100             -mov ebp, 0x512b28
    cpu.ebp = 5319464 /*0x512b28*/;
    // 00463f96  893c85f82b5100         -mov dword ptr [eax*4 + 0x512bf8], edi
    app->getMemory<x86::reg32>(x86::reg32(5319672) /* 0x512bf8 */ + cpu.eax * 4) = cpu.edi;
    // 00463f9d  8b0d282b5100           -mov ecx, dword ptr [0x512b28]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5319464) /* 0x512b28 */);
    // 00463fa3  892c85142c5100         -mov dword ptr [eax*4 + 0x512c14], ebp
    app->getMemory<x86::reg32>(x86::reg32(5319700) /* 0x512c14 */ + cpu.eax * 4) = cpu.ebp;
    // 00463faa  8b710c                 -mov esi, dword ptr [ecx + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00463fad  c1e614                 -shl esi, 0x14
    cpu.esi <<= 20 /*0x14*/ % 32;
    // 00463fb0  c1fe14                 -sar esi, 0x14
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (20 /*0x14*/ % 32));
    // 00463fb3  893485fc2b5100         -mov dword ptr [eax*4 + 0x512bfc], esi
    app->getMemory<x86::reg32>(x86::reg32(5319676) /* 0x512bfc */ + cpu.eax * 4) = cpu.esi;
    // 00463fba  8b490c                 -mov ecx, dword ptr [ecx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00463fbd  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
    // 00463fc0  c1f914                 -sar ecx, 0x14
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (20 /*0x14*/ % 32));
    // 00463fc3  890c85002c5100         -mov dword ptr [eax*4 + 0x512c00], ecx
    app->getMemory<x86::reg32>(x86::reg32(5319680) /* 0x512c00 */ + cpu.eax * 4) = cpu.ecx;
    // 00463fca  83fa4f                 +cmp edx, 0x4f
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(79 /*0x4f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00463fcd  0f8c22010000           -jl 0x4640f5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004640f5;
    }
    // 00463fd3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00463fd5:
    // 00463fd5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00463fd7  83f84f                 +cmp eax, 0x4f
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(79 /*0x4f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00463fda  0f8c1d010000           -jl 0x4640fd
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004640fd;
    }
    // 00463fe0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00463fe2:
    // 00463fe2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00463fe4  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00463fe7  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00463fe9  bef42b5100             -mov esi, 0x512bf4
    cpu.esi = 5319668 /*0x512bf4*/;
    // 00463fee  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00463ff1  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00463ff3  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 00463ffa  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00463ffc  b914000000             -mov ecx, 0x14
    cpu.ecx = 20 /*0x14*/;
    // 00464001  893485f42b5100         -mov dword ptr [eax*4 + 0x512bf4], esi
    app->getMemory<x86::reg32>(x86::reg32(5319668) /* 0x512bf4 */ + cpu.eax * 4) = cpu.esi;
    // 00464008  890c85f82b5100         -mov dword ptr [eax*4 + 0x512bf8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5319672) /* 0x512bf8 */ + cpu.eax * 4) = cpu.ecx;
    // 0046400f  be342b5100             -mov esi, 0x512b34
    cpu.esi = 5319476 /*0x512b34*/;
    // 00464014  8b0d342b5100           -mov ecx, dword ptr [0x512b34]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5319476) /* 0x512b34 */);
    // 0046401a  893485142c5100         -mov dword ptr [eax*4 + 0x512c14], esi
    app->getMemory<x86::reg32>(x86::reg32(5319700) /* 0x512c14 */ + cpu.eax * 4) = cpu.esi;
    // 00464021  8b710c                 -mov esi, dword ptr [ecx + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00464024  c1e614                 -shl esi, 0x14
    cpu.esi <<= 20 /*0x14*/ % 32;
    // 00464027  c1fe14                 -sar esi, 0x14
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (20 /*0x14*/ % 32));
    // 0046402a  893485fc2b5100         -mov dword ptr [eax*4 + 0x512bfc], esi
    app->getMemory<x86::reg32>(x86::reg32(5319676) /* 0x512bfc */ + cpu.eax * 4) = cpu.esi;
    // 00464031  8b490c                 -mov ecx, dword ptr [ecx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00464034  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
    // 00464037  c1f914                 -sar ecx, 0x14
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (20 /*0x14*/ % 32));
    // 0046403a  890c85002c5100         -mov dword ptr [eax*4 + 0x512c00], ecx
    app->getMemory<x86::reg32>(x86::reg32(5319680) /* 0x512c00 */ + cpu.eax * 4) = cpu.ecx;
    // 00464041  83fa4f                 +cmp edx, 0x4f
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(79 /*0x4f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00464044  0f8cb9000000           -jl 0x464103
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00464103;
    }
    // 0046404a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0046404c:
    // 0046404c  bd14000000             -mov ebp, 0x14
    cpu.ebp = 20 /*0x14*/;
    // 00464051  8b35c0f34d00           -mov esi, dword ptr [0x4df3c0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5108672) /* 0x4df3c0 */);
    // 00464057  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 0046405e  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00464060  8d0c02                 -lea ecx, [edx + eax]
    cpu.ecx = x86::reg32(cpu.edx + cpu.eax * 1);
    // 00464063  8d04b500000000         -lea eax, [esi*4]
    cpu.eax = x86::reg32(cpu.esi * 4);
    // 0046406a  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 0046406d  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0046406f  89b9f42b5100           -mov dword ptr [ecx + 0x512bf4], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5319668) /* 0x512bf4 */) = cpu.edi;
    // 00464075  be8c2a5100             -mov esi, 0x512a8c
    cpu.esi = 5319308 /*0x512a8c*/;
    // 0046407a  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0046407d  89a9f82b5100           -mov dword ptr [ecx + 0x512bf8], ebp
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5319672) /* 0x512bf8 */) = cpu.ebp;
    // 00464083  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00464085  8b808c2a5100           -mov eax, dword ptr [eax + 0x512a8c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5319308) /* 0x512a8c */);
    // 0046408b  89b1142c5100           -mov dword ptr [ecx + 0x512c14], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5319700) /* 0x512c14 */) = cpu.esi;
    // 00464091  8b700c                 -mov esi, dword ptr [eax + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00464094  c1e614                 -shl esi, 0x14
    cpu.esi <<= 20 /*0x14*/ % 32;
    // 00464097  c1fe14                 -sar esi, 0x14
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (20 /*0x14*/ % 32));
    // 0046409a  89b1fc2b5100           -mov dword ptr [ecx + 0x512bfc], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5319676) /* 0x512bfc */) = cpu.esi;
    // 004640a0  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004640a3  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004640a6  c1f814                 -sar eax, 0x14
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (20 /*0x14*/ % 32));
    // 004640a9  8981002c5100           -mov dword ptr [ecx + 0x512c00], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5319680) /* 0x512c00 */) = cpu.eax;
    // 004640af  83fa4f                 +cmp edx, 0x4f
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(79 /*0x4f*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004640b2  7c55                   -jl 0x464109
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00464109;
    }
    // 004640b4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004640b6:
    // 004640b6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004640b8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004640ba  7e52                   -jle 0x46410e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0046410e;
    }
    // 004640bc  8d48ff                 -lea ecx, [eax - 1]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
L_0x004640bf:
    // 004640bf  8d04cd00000000         -lea eax, [ecx*8]
    cpu.eax = x86::reg32(cpu.ecx * 8);
    // 004640c6  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004640c8  b9f42b5100             -mov ecx, 0x512bf4
    cpu.ecx = 5319668 /*0x512bf4*/;
    // 004640cd  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004640d0  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 004640d2  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004640d4  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004640d6  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004640da  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004640db  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 004640dc  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004640de  8915388e4c00           -mov dword ptr [0x4c8e38], edx
    app->getMemory<x86::reg32>(x86::reg32(5017144) /* 0x4c8e38 */) = cpu.edx;
    // 004640e4  83c408                 +add esp, 8
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
    // 004640e7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004640e8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004640e9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004640ea  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004640eb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004640ec  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004640ed:
    // 004640ed  8d4a01                 -lea ecx, [edx + 1]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004640f0  e974feffff             -jmp 0x463f69
    goto L_0x00463f69;
L_0x004640f5:
    // 004640f5  8d4201                 -lea eax, [edx + 1]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004640f8  e9d8feffff             -jmp 0x463fd5
    goto L_0x00463fd5;
L_0x004640fd:
    // 004640fd  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004640fe  e9dffeffff             -jmp 0x463fe2
    goto L_0x00463fe2;
L_0x00464103:
    // 00464103  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 00464104  e943ffffff             -jmp 0x46404c
    goto L_0x0046404c;
L_0x00464109:
    // 00464109  8d4201                 -lea eax, [edx + 1]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 0046410c  eba8                   -jmp 0x4640b6
    goto L_0x004640b6;
L_0x0046410e:
    // 0046410e  b94f000000             -mov ecx, 0x4f
    cpu.ecx = 79 /*0x4f*/;
    // 00464113  ebaa                   -jmp 0x4640bf
    goto L_0x004640bf;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_464120(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00464120  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00464121  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00464122  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00464123  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00464124  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00464125  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00464128  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 0046412a  bab4295100             -mov edx, 0x5129b4
    cpu.edx = 5319092 /*0x5129b4*/;
    // 0046412f  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00464131  a1a42a5100             -mov eax, dword ptr [0x512aa4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5319332) /* 0x512aa4 */);
    // 00464136  e8150d0000             -call 0x464e50
    cpu.esp -= 4;
    sub_464e50(app, cpu);
    if (cpu.terminate) return;
    // 0046413b  b814000000             -mov eax, 0x14
    cpu.eax = 20 /*0x14*/;
    // 00464140  8d742408               -lea esi, [esp + 8]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00464144  bac4295100             -mov edx, 0x5129c4
    cpu.edx = 5319108 /*0x5129c4*/;
    // 00464149  e8120b0000             -call 0x464c60
    cpu.esp -= 4;
    sub_464c60(app, cpu);
    if (cpu.terminate) return;
    // 0046414e  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00464152  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00464154  e8f70c0000             -call 0x464e50
    cpu.esp -= 4;
    sub_464e50(app, cpu);
    if (cpu.terminate) return;
    // 00464159  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046415d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0046415e  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00464162  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00464163  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00464167  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00464168  8b7c240c               -mov edi, dword ptr [esp + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0046416c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0046416d  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00464171  e8fa86ffff             -call 0x45c870
    cpu.esp -= 4;
    sub_45c870(app, cpu);
    if (cpu.terminate) return;
    // 00464176  8b6c2414               -mov ebp, dword ptr [esp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046417a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0046417b  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0046417f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00464180  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00464184  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00464185  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00464189  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0046418a  8d742410               -lea esi, [esp + 0x10]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0046418e  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00464190  e8db86ffff             -call 0x45c870
    cpu.esp -= 4;
    sub_45c870(app, cpu);
    if (cpu.terminate) return;
    // 00464195  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 00464197  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00464198  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = app->getMemory<x86::reg32>(cpu.esi);
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
        cpu.esi -= 4;
    }
    else
    {
        cpu.edi += 4;
        cpu.esi += 4;
    }
    // 00464199  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0046419b  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0046419e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0046419f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004641a0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004641a1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004641a2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004641a3  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
